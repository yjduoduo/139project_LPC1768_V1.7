/*
*********************************************************************************************************
*
*                               ����: CTimeCtrl
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
    ClrDisHis_CSysRunFlag(); //����ͬ�����ڣ���ֹд��ʷ��¼
}

void  IncT0Count_CTimeCtrl(void)
{
    if(vRunTime0 < cTime800ms)
    {
        vRunTime0++;
    }

    if(vRunTime0 > cTime50ms)
    {
        if(GetSys_CLpScanCtrl())   //�ر�ͬ����ʶ����������д��ʷ��¼��ʶ
        {
            ClrSys_CLpScanCtrl();
        }

        if(GetDisHis_CSysRunFlag())
        {
            ClrDisHis_CSysRunFlag(); //����д��ʷ��¼
        }
    }
}

//�½��أ����ݼ����ж����
void  SetCommT0_CTimeCtrl(void)
{
    if(vRunTime0 > cTime380ms)  //�µ�ͬ�����ڿ�ʼ
    {
        Init_CLpScanCtrl();
        SetSys_CLpScanCtrl();
        SetDisHis_CSysRunFlag(); //����ͬ�����ڣ���ֹд��ʷ��¼
        return ;
    }

    if(!GetSys_CLpScanCtrl())   //û��������ͨ����
    {
        return ;
    }

    if(vRunTime0 < cTime10ms)  //����Ѳ������
    {
        SaveComm_CTimeCtrl(cLpScanComm_D0);
        //����λ�źţ���ȡIO��״̬


        return ;
    }

    if(vRunTime0 < cTime14ms)  //״̬���Ͳ�ѯ
    {
        SaveComm_CTimeCtrl(cLpScanComm_D4);
        return ;
    }

    if(vRunTime0 < cTime18ms)  //14~18ms  ģ������ѯ
    {
        SaveComm_CTimeCtrl(cLpScanComm_D8);
        return ;
    }

    if(vRunTime0 < cTime22ms)  //18~22ms ���ݲ�ѯ����
    {
        SaveComm_CTimeCtrl(cLpScanComm_D12);
        return ;
    }

    //����쳣����Ҫ����Ѱ��ͬ������
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
    //׼���������ݷ���
    if(vComm)
    {
        uint8 vState=GetState_CNodeInfo(vAddr);  //��ȡ��ǰ�ڵ�״̬
        uint8 vSendData=GetData_CLpAnsCtrl(vComm,vState);  //��ȡ��ǰ�ڵ�״̬
        //���ݲ�ѯ�������ݴ���
        SetAnsFlag_CLpScanCtrl();   //������Ҫ������ʶ
        if(vComm == cLpScanComm_D12)
        {
            uint8 vCkCyc=GetCkCyc_CNodeInfo(vAddr);   //��ȡ��ѯ����
            if(vCkCyc==2) //��2���������ڣ�������ǰ��ַ
            {
                vSendData=vAddr;
            }
            else if(vCkCyc==4) //��4���������ڣ�������ǰ״̬
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


//������δ���
void  AnsCommT0_CTimeCtrl(void)
{
    //�жϵ�ǰ��ַ�Ƿ�Ϸ�
    uint8  vAddr=GetAddr_CLpScanCtrl();
    if(GetReg_CNodeInfo(vAddr))     //״̬���������
    {
        if(GetState_CLpScanCtrl())  //״̬���������
        {
            return ;
        }
        //�𾯺�ɼ��źţ��жϣ�LOOP_LD�Ƿ������������·��������
        if(vRunTime0 <= cTime1ms)
        {//�𾯣�����Ϊԭ��ͼ��Ϊ�͵�ƽ
            if(!get_loopLD_state())//�͵�ƽ
            {
                //                Debug("addr:%d\n",vAddr);
                addxialasignal();
            }else{//�ߵ�ƽ
                if(getxialasignal()>30)
                    add_weixialasignal();
            }

        }

        if(vRunTime0 < m_AnsStatTime[GetComm_CLpScanCtrl()])
        {

#if 0
            //�𾯺�ɼ��źţ��жϣ�LOOP_LD�Ƿ������������·��������
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


            //�ж��������� T0��
            if(vRunTime0 < cTime2ms)
            {
                return ;
            }

            if(GetComm_CLpScanCtrl())   //���������������
            {
                if(GetAnsTId_CLpScanCtrl())  //�������600US
                {
                    DecAnsTId_CLpScanCtrl();
                }
                else if(GetAnsStep_CLpScanCtrl() < cMaxLpScanAnsStep)  //AN BIT Ϊ�������
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


//������·�����ж�   100us��ʱ
void   T0Int_CTimeCtrl(void)
{
    if(GetExtint_CLpCkCtrl())  //�б��ش���
    {
        if(GetExtint_CLpCkCtrl()==cLpCkFlag_ExtF)  //�½��ش�������ȡ��ǰ������
        {
            SetCommT0_CTimeCtrl();
        }
        else   //�����أ���ַ��1���������·����
        {
            IncAddr_CLpScanCtrl();
            //��ǰѲ���ַ����139ģ��ļ�����Χ��������ʷ��¼д
            if(GetAddr_CLpScanCtrl() > GetMax_CNodeInfo())
            {
                if(GetDisHis_CSysRunFlag())
                {
                    ClrDisHis_CSysRunFlag(); //����д��ʷ��¼
                }
            }
            ClrComm_CLpScanCtrl();
            ClrState_CLpScanCtrl();

            //             clr_loopldbuf();

            //loop ld��
            //            clr_loop_LD_counter();
        }
        vRunTime0=0;
        ClrExtint_CLpCkCtrl();
    }
    IncT0Count_CTimeCtrl();  //��ʱ��1
    if(cLpCkPer_Ans==GetPer_CLpCkCtrl())   //�������������
    {
        //��Ϣ������
        if(!GetSys_CLpScanCtrl())   //û��������ͨ����
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
********************[6Сʱ��ⲿ���Ƿ����]*********************
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
//ÿ����Ϊÿ���������һ��
void add_timer1_3h_counter(void)
{
    uint8 i=0;
    for(i=1;i<=MAX_LOOP;i++)
    {
        vTime1_3h_exist[i].vTime1_3h_counter++;
    }
}
//��λ��ʱ
void reset_timer1_3h_counter(void)
{
    uint8 i=0;
    for(i=1;i<=MAX_LOOP;i++)
    {
        vTime1_3h_exist[i].faultnums = 0;
        vTime1_3h_exist[i].vTime1_3h_counter =0;
    }
}

//��ȡ��ʱ��
uint32 get_3h_counter(uint8 part)
{
    if(part>MAX_COMP)
        return 0;
    return vTime1_3h_exist[part].vTime1_3h_counter;
}
//���ʱ�����¼�ʱ
void clr_3h_counter(uint8 part)
{
    if(part>MAX_COMP)
        return;
    vTime1_3h_exist[part].vTime1_3h_counter = 0;
}
//ͨѶʱ���ж�ʱ���Ƿ���������Χ�ڣ�С��6��Сʱ�Ϳ������
void clr_faultnum_3h_(uint8 part)
{
    if(get_3h_counter(part) < vTimer1_6H )
    {
        vTime1_3h_exist[part].faultnums = 0;
    }
}

//��ѭ������6Сʱ����
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
        //���ϲ˵�
//        SetMenuFlag(MENU_OFFLINE);
        menu_vh75_connect_fault(part);
//        if(GetAlarmFlag(POS_ALARM_BIT) != ALARM_FIRE)
//            SetAlarmFlag(POS_ALARM_BIT,ALARM_FAULT);
    }
}


//20ms ��ʱ����
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
    //��������ʱ�����
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
        if(MENU_FIREALARM == GetMenuFlag())//����
        {
            set_speark_ss_time(cTime1_500ms_Count,cTime1_500ms_Count);
        }
        else if(MENU_FAULTALARM == GetMenuFlag())//������
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





