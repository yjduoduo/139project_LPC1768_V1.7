/*
*********************************************************************************************************
*
*                               对象: CTimeCtrl
*                        (c) Copyright 2013-2018, jxm
*                              All Rights Reserved
*                                    Ver1.0
* File : CTimeCtrl.C
* By   : jxm
* Date : 2013-8-23
*********************************************************************************************************
*/
#include <string.h>
#define   CTimeCtrl_C
#include  "CTimeCtrl.h"
#include  "CSysRunFlag.h"
#include  "CLpCkCtrl.h"
#include  "CLpAnsCtrl.h"
#include  "CSetCurrent.h"
#include  "CLpScanCtrl.h"
#include  "CLED.h"
#include  "CNodeInfo.h"
#include  "CTime.h"
#include  "uart.h"
#include  "CAddressCount.h"
#include  "CFlashParam.h"
#include  "include.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"
#include  "CSendTo195.h"
#include  "CModelFault.h"
#include  "CComPara.h"



void  Init_CTimeCtrl(void)
{
    Init_CLpScanCtrl();
    Init_CLpCkCtrl();
    Init_CNodeInfo();
    ClrDisHis_CSysRunFlag(); //进入同步周期，禁止写历史记录
}

void  IncT0Count_CTimeCtrl(void)
{
    if(vRunTime0 < cTime800ms)
    {
        vRunTime0++;
    }

    if(vRunTime0 > cTime50ms)
    {
        if(GetSys_CLpScanCtrl())   //关闭同步标识，开启允许写历史记录标识
        {
            ClrSys_CLpScanCtrl();
        }

        if(GetDisHis_CSysRunFlag())
        {
            ClrDisHis_CSysRunFlag(); //允许写历史记录
        }
    }
}

//下降沿，根据计数判断命令，
void  SetCommT0_CTimeCtrl(void)
{
    if(vRunTime0 > cTime380ms)  //新的同步周期开始
    {
        Init_CLpScanCtrl();
        SetSys_CLpScanCtrl();
        SetDisHis_CSysRunFlag(); //进入同步周期，禁止写历史记录
        return ;
    }

    if(!GetSys_CLpScanCtrl())   //没有正常的通周期
    {
        return ;
    }

    if(vRunTime0 < cTime10ms)  //正常巡检周期
    {
        SaveComm_CTimeCtrl(cLpScanComm_D0);
        //处理复位信号，读取IO口状态


        return ;
    }

    if(vRunTime0 < cTime14ms)  //状态类型查询
    {
        SaveComm_CTimeCtrl(cLpScanComm_D4);
        return ;
    }

    if(vRunTime0 < cTime18ms)  //14~18ms  模拟量查询
    {
        SaveComm_CTimeCtrl(cLpScanComm_D8);
        return ;
    }

    if(vRunTime0 < cTime22ms)  //18~22ms 数据查询功能
    {
        SaveComm_CTimeCtrl(cLpScanComm_D12);
        return ;
    }

    //宽度异常，需要重新寻找同步周期
    Init_CLpScanCtrl();

}

void  SaveComm_CTimeCtrl(uint8 vComm)
{
    uint8 vAddr=GetAddr_CLpScanCtrl();

    SetComm_CLpScanCtrl(vComm);
    if(!GetReg_CNodeInfo(vAddr))
    {
        return ;
    }
    SetComm_CNodeInfo(vAddr,vComm);
    //准备串行数据发送
    if(vComm)
    {
        uint8 vState=GetState_CNodeInfo(vAddr);  //读取当前节点状态
        uint8 vSendData=GetData_CLpAnsCtrl(vComm,vState);  //读取当前节点状态
        //数据查询反馈数据处理
        SetAnsFlag_CLpScanCtrl();   //设置需要反馈标识
        if(vComm == cLpScanComm_D12)
        {
            uint8 vCkCyc=GetCkCyc_CNodeInfo(vAddr);   //读取查询周期
            if(vCkCyc==2) //第2个反馈周期，反馈当前地址
            {
                vSendData=vAddr;
            }
            else if(vCkCyc==4) //第4个反馈周期，反馈当前状态
            {
                vSendData=GetData_CLpAnsCtrl(cLpScanComm_D4,vAddr);
            }
            else
            {
                vSendData=GetData_CLpAnsCtrl(vComm,vCkCyc);
            }
        }
        SetData_CLpAnsCtrl(vSendData);
    }
}
static volatile uint8 bufcounter=0;
// static uint8 loopldbuf[10] = {0,};


//槽脉宽段处理
void  AnsCommT0_CTimeCtrl(void)
{
    //判断当前地址是否合法
    uint8  vAddr=GetAddr_CLpScanCtrl();
    if(GetReg_CNodeInfo(vAddr))     //状态电流已输出
    {
        if(GetState_CLpScanCtrl())  //状态电流已输出
        {
            return ;
        }
        //火警后采集信号，判断，LOOP_LD是否有输出，即回路上有下拉
        if(vRunTime0 <= cTime1ms)
        {//火警，拉低为原理图上为低电平
            if(!get_loopLD_state())//低电平
            {
                //                Debug("addr:%d\n",vAddr);
                addxialasignal();
            }else{//高电平
                if(getxialasignal()>30)
                    add_weixialasignal();
            }

        }

        if(vRunTime0 < m_AnsStatTime[GetComm_CLpScanCtrl()])
        {

#if 0
            //火警后采集信号，判断，LOOP_LD是否有输出，即回路上有下拉
            if(vRunTime0 <= cTime1ms)
            {
                Led_Silence_On();
#if 1
                if(get_loopLD_state())
                {
                    Led_Silence_On();
                }else{
                    Led_Silence_Off();
                }
#else
                loopldbuf[bufcounter++] = get_loopLD_state();
#endif
            }
            if(vRunTime0 >cTime1ms && vRunTime0 < cTime2ms)
            {
                //                uint8 i;
                //                uint8 times = 0;
                //                for(i=0;i<10;i++)
                //                {
                //                    if(loopldbuf[i]>0)
                //                        times++;
                //                    if(times >3 )
                //                    {
                //                        SetReset_CLpCkCtrl();
                //                    }
                //                    break;
                //                }
            }
#endif


            //判断下拉脉宽 T0段
            if(vRunTime0 < cTime2ms)
            {
                return ;
            }

            if(GetComm_CLpScanCtrl())   //串行数据输出控制
            {
                if(GetAnsTId_CLpScanCtrl())  //保持输出600US
                {
                    DecAnsTId_CLpScanCtrl();
                }
                else if(GetAnsStep_CLpScanCtrl() < cMaxLpScanAnsStep)  //AN BIT 为输出控制
                {
                    uint8  vOutStep=GetAnsStep_CLpScanCtrl();
                    OutData_CLpAnsCtrl(vOutStep);
                    SetAnsTId_CLpScanCtrl();
                    SetAnsStep_CLpScanCtrl();
                }
                else
                {
                    OutState_CLpAnsCtrl(GetState_CNodeInfo(vAddr));
                    SetState_CLpScanCtrl();
                }
            }
        }
        else
        {
            OutState_CLpAnsCtrl(GetState_CNodeInfo(vAddr));
            SetState_CLpScanCtrl();
        }
    }
    else
    {

    }
}


//产生回路波型中断   100us定时
void   T0Int_CTimeCtrl(void)
{
    if(GetExtint_CLpCkCtrl())  //有边沿触发
    {
        if(GetExtint_CLpCkCtrl()==cLpCkFlag_ExtF)  //下降沿触发，读取当前的命令
        {
            SetCommT0_CTimeCtrl();
        }
        else   //上升沿，地址加1处理，清除回路命令
        {
            IncAddr_CLpScanCtrl();
            //当前巡检地址大于139模块的监听范围，开启历史记录写
            if(GetAddr_CLpScanCtrl() > GetMax_CNodeInfo())
            {
                if(GetDisHis_CSysRunFlag())
                {
                    ClrDisHis_CSysRunFlag(); //允许写历史记录
                }
            }
            ClrComm_CLpScanCtrl();
            ClrState_CLpScanCtrl();

            //             clr_loopldbuf();

            //loop ld清
            //            clr_loop_LD_counter();
        }
        vRunTime0=0;
        ClrExtint_CLpCkCtrl();
    }
    IncT0Count_CTimeCtrl();  //计时加1
    if(cLpCkPer_Ans==GetPer_CLpCkCtrl())   //处于命令反馈周期
    {
        //信息反馈段
        if(!GetSys_CLpScanCtrl())   //没有正常的通周期
        {
            return ;
        }
        AnsCommT0_CTimeCtrl();
    }
}
static void set_speark_ss_time(uint16 startT,uint16 stopT)
{
    vPWM1Time++;
    if((vPWM1Time >= startT) && !vPWM1StopFlag)
    {
        PWM1_Stop();
        vPWM1StopFlag =1;
        vPWM1Time = 0;
    }
    if(vPWM1StopFlag && vPWM1Time >= stopT)
    {
        vPWM1StopFlag = 0;
        PWM1_Start();
        vPWM1Time = 0;
    }
}
/***********************************************************
********************[6小时检测部件是否存在]*********************
**********************************************************/
#if 1//normal
#define vTimer1_Base (1UL)  /*(1 minute)*/
#define vTimer1_3H   ((60*3)/vTimer1_Base)
#define vTimer1_6H   ((60*6)/vTimer1_Base)
#else//test
#define vTimer1_Base 1UL  /*(1 minute)*/
#define vTimer1_3H   1*3/vTimer1_Base
#define vTimer1_6H   1*6/vTimer1_Base
#endif

typedef struct _CompNotExist
{
    uint32 vTime1_3h_counter;
    uint8 faultnums;

}CompNotExist;


static CompNotExist vTime1_3h_exist[MAX_COMP+1]={0,};
//每分钟为每个部件添加一次
void add_timer1_3h_counter(void)
{
    uint8 i=0;
    for(i=1;i<=MAX_LOOP;i++)
    {
        vTime1_3h_exist[i].vTime1_3h_counter++;
    }
}
//复位计时
void reset_timer1_3h_counter(void)
{
    uint8 i=0;
    for(i=1;i<=MAX_LOOP;i++)
    {
        vTime1_3h_exist[i].faultnums = 0;
        vTime1_3h_exist[i].vTime1_3h_counter =0;
    }
}

//获取计时数
uint32 get_3h_counter(uint8 part)
{
    if(part>MAX_COMP)
        return 0;
    return vTime1_3h_exist[part].vTime1_3h_counter;
}
//清计时，重新计时
void clr_3h_counter(uint8 part)
{
    if(part>MAX_COMP)
        return;
    vTime1_3h_exist[part].vTime1_3h_counter = 0;
}
//通讯时，判断时间是否在正常范围内，小于6个小时就可以清空
void clr_faultnum_3h_(uint8 part)
{
    if(get_3h_counter(part) < vTimer1_6H )
    {
        vTime1_3h_exist[part].faultnums = 0;
    }
}

//主循环处理6小时故障
void judge_3h_over(uint8 part)
{
//    Debug("p-c part:%d,counter:%d\n",part,get_3h_counter(part));
    DebugOnce("p-c part:%d,counter:%d\n",part,get_3h_counter(part));
    if(get_3h_counter(part) > vTimer1_6H + 5)
    {
        vTime1_3h_exist[part].faultnums = 2;
    }
    else if(get_3h_counter(part) > vTimer1_3H + 5)
    {
        vTime1_3h_exist[part].faultnums++;
    }

    if(vTime1_3h_exist[part].faultnums >= 2)
    {
        //        menu_fault_deal(&alarm_info);
        //故障菜单
//        SetMenuFlag(MENU_OFFLINE);
        menu_vh75_connect_fault(part);
//        if(GetAlarmFlag(POS_ALARM_BIT) != ALARM_FIRE)
//            SetAlarmFlag(POS_ALARM_BIT,ALARM_FAULT);
    }
}


//20ms 定时处理
void   T1Int_CTimeCtrl(void)
{  //time share ctrl
    vRunTime1++;
    if(vRunTime1 > cTime1_3h_Count)
    {
        vRunTime1=0;
    }

    if(vRunTime1 %  cTime1_40ms_Count == 0)
    {
        Set40ms_CSysRunFlag();
    }
    if(vRunTime1 % cTime1_100ms_Count == 0)
    {
        Set100ms_CSysRunFlag();
    }
    if(vRunTime1 % cTime1_1s_Count == 0)
    {
        Set1s_CSysRunFlag();
    }
    //界面轮显时间控制
    if(vRunTime1 % cTime1_3s_Count == 0)
    {
        set_alarm_loop_show();
    }
    if(vRunTime1 % cTime1_5s_Count == 0)
    {
        Set5s_CSysRunFlag();
    }
    if(vRunTime1 % cTime1_1m_Count == 0)
    {
        add_timer1_3h_counter();
        Set1m_CSysRunFlag();
    }
    Set20ms_CSysRunFlag();
    vAddScreenMask();

    //control pwm1 start and stop periodicity
    if(get_PWM1_Started())
    {
        if(MENU_FIREALARM == GetMenuFlag())//火警声
        {
            set_speark_ss_time(cTime1_500ms_Count,cTime1_500ms_Count);
        }
        else if(MENU_FAULTALARM == GetMenuFlag())//故障声
        {
            set_speark_ss_time(cTime1_100ms_Count,cTime1_1s_Count);
        }
        else{
            set_speark_ss_time(cTime1_1s_Count,cTime1_500ms_Count);
        }

    }else{
        vPWM1Time = 0;
        vPWM1StopFlag = 0;
    }


}





