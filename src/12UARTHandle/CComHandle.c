/*
;*********************************************************************************************************
;*                                                
;*                            对象: CComHandle
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CComHandle.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
#define COMHANDLE_C
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include  "include.h"
#include  "CComHandle.h"
#include  "CComPara.h"
#include  "CFlashParam.h"
#include  "CComAnn.h"
#include  "CKeyCounter.h"
#include  "CSendToFlash.h"
#include  "CSendTo195.h"
#include  "CTaskSure.h"
#include  "CMaDefine.h"
#include "CLED.h"
#include  "CGetCompSum.h"
#include  "CAddressCount.h"
#include  "CLpScanCtrl.h"
#include  "componentinfo.h"
#include  "store_addr.h"
#include  "CNodeInfo.h"
#include  "CGrapParam.h"
#include  "CTimeCtrl.h"
#include  "CRunCtrl.h"


//宏定义


#define	CONVERT(X)	((X&0x00ff)*256+(X&0xff00)/256)//高低位转换
#define	ASC_HEX(X,Y)	((X-0x30)<<4+(Y-0x30))



//变量定义
extern PCF8563_DATE    timedate;
static PdUartMsgUnion pdUartSend;//结构体定义
//PdUartMsgUnion uart0_rev_data;
static PdUartMsgUnion pdUartRcv;
tFlashinfoDef  FlashInfo;


history_st  histinfo;

static compent  compreg;
//函数声明
void AddHeartFaultFlag(void);



//函数定义

void SetFirstAlarm_Flag(uint8 tmp)
{
    FirstAlarm_Flag=tmp;
}
void SetDisplay_alarm_flag(uint8 tmp)
{
    vDispaly_alarm_flag=tmp;
}
uint8 GetDisplay_alarm_flag(void)
{
    return vDispaly_alarm_flag;
}
void Setdisplay_alarm(uint8 row,uint8 tmp)
{
    vdisplay_alarm[row]=tmp;
}
uint8 Getdisplay_alarm(uint8 row)
{
    return 	vdisplay_alarm[row];
}
PCF8563_DATE Getalarmtime(void)
{
    return valarmtime;
}
//13601377913
void SetSum(uint8 row,uint8 tmp)
{
    AlarmSum[row]=tmp;
}
uint8 GetSum(uint8 row)
{
    return AlarmSum[row];
}
void SetConvertdata(uint8 col,uint8 tmp)
{
    Convertdata[col]=tmp;
}
//uint8 GetConvertdata(uint8 col)
//{
//    return Convertdata[col];
//}
//回路之后再发送信息
void check_lp_running(void)
{
    while(GetSys_CLpScanCtrl());
}

/*******************数据组包*************************/
//组合数据并发送
void UartBindSend(uint8 cmd,uint8 len)
{
    uint8 num;
    uint8 dat =0;

    pdUartSend = (PdUartMsgUnion)UartTxbuf;
    PUSEND.header = CMD_HEAD;
    PUSEND.cmd = cmd;

    if(UART_MESSAGE_LEN == len){
        memcpy(PUSEND_DETAIL.addr, Convertdata, 6);  //此处的内容，通过ConvertData在串口接收到数据反馈回去。
        for(num = 0; num < 7; num++)					//checksum calculate[2]~[7]
            dat += PUSEND_ARRAY[num+1];
        PUSEND.cs = dat;

        UartSendLen = UART_MESSAGE_LEN;
        pTxbuf = PUSEND_ARRAY;
    }else{

    }
//    check_lp_running();
    UARTSend(1,PUSEND_ARRAY,len);//串口号，数据指针，长度
}
/********************end*************************/
//######################################################################################################
// 函数名称 wireless_data_check()
//------------------------------------------------------------------------------------------------------
// 函数功能 ：校验
//------------------------------------------------------------------------------------------------------
// 输入参数 ：
//------------------------------------------------------------------------------------------------------
// 输出参数 ：校验通过无线模块收到的数据
//######################################################################################################
uint8 wireless_data_check(void)
{
    uint8 num;
    uint8 dat = 0;

    if(PURCV.header != CMD_HEAD)//判断头对不对
    {
//        Debug("uart PURCV.header:%d err\n",PURCV.header);
        UartClrflag = CLR_FLAG;
        UartClrLen = 0x01;
        return FAIL;
    }
    if(PURCV.cmd == CMD_139W)//0x38-[139w]
    {
        return SUC;
    }

    for(num = 1; num < UART_MESSAGE_LEN-1; num++)				//checksum calculate
        dat += PURCV_ARRAY[num];
    dat = (dat&0xff);
    if(dat == PURCV.cs)			//checksum and tail check
    {
        UartClrflag = CLR_FLAG;
        UartClrLen = UART_MESSAGE_LEN;
        return SUC;
    }

    UartClrflag = CLR_FLAG;
    UartClrLen = 0x01;
    return FAIL;
}
/*************查找防区部件******************/
//防区数和和部件数都相等时，不注册
static uint8 find_zone_comp(uint8 inzone,uint8 partnumber)
{
    uint8 i;
//    Debug("searching inzone:%d,partnumber:%d\n",inzone,partnumber);
    for(i=COMP_START;i<=MAX_COMP;i++)
        if((get_comp_partnumber(i) == partnumber)&&
                (INITVAL !=get_comp_partnumber(i)))
        {
//            Debug("->>same inzone:%d,partnumber:%d\n",inzone,partnumber);
            return 1;
        }
    return 0;
}
// //打印注册内容信息
// static void printf_zone_comp_info(void)
// {
//     uint8 i;
//     for(i=COMP_START;i<=MAX_COMP;i++)
//         Debug("->info::%d:inzone:%d,partnumber:%d\n",i,get_comp_inzone(i),get_comp_partnumber(i));

// }
//选择数自动加1显示
static void autoadd_compreg(void)
{
    AddCompRegNum();
    if(GetCompRegNum() >MAX_COMP)
        SetCompRegNum(COMP_START);
}


/*************部件注册  处理******************/
static void comp_reg_deal(void)
{
    uint16 ciraddr,partnumber,total_nums;
    int16 com_num=-1;
//    compent compreg;
    memset(&compreg,0,sizeof(compent));
//    history_st histinfo;
    memset(&histinfo,0,sizeof(history_st));


    OnLCD();
    Debug("GetComRegFlag:%d\n",GetComRegFlag());


    total_nums=get_basic_nums();//部件总数
    ciraddr=get_basic_localaddr();//回路地址
    partnumber=GetCompRegNum();//部件数按键取

    Debug("===comp regging info......\n");
    Debug("total_nums:%d\n",total_nums);
    Debug("partnumber:%d\n",partnumber);
    Debug("ciraddr:%d\n",ciraddr);

//中断前获取时间，否则i2c中断后错误
    getcurrent_date(&histinfo.dateyear);

    //禁止中断并清回路，清回路与保存有关,禁止再接收信息，不能禁止串口
//    Eint_DisAll_Exuart();
//    ClrSys_CLpScanCtrl();
    EndInt();/*禁止后uart0 not print*/


    //检测psn码是否已经注册，0表示已注册
    if(find_zone_comp(0,partnumber))
    {
//        Debug("==finding same and partnumber!!\n");
        CompReg_menu(0,partnumber,REGD_COMP,GetCompRegAddr(),GetCompRegParaSel(),0);
        goto END;
//        return;
    }
    else if(CompareAddr(PURCV_DETAIL.addr[3],PURCV_DETAIL.addr[2],PURCV_DETAIL.addr[1],PURCV_DETAIL.addr[0],&com_num)==0)
    {//设备已经注册
//        Debug("==device been reged!!\n");
        CompReg_menu(0,partnumber,REGD_DEV,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;
//        return;

    }
    else if(INVALID_ADDR_COMP == CompareAddr(PURCV_DETAIL.addr[3],PURCV_DETAIL.addr[2],PURCV_DETAIL.addr[1],PURCV_DETAIL.addr[0],&com_num))
    {//非法部件，psn码为全0xff
//        Debug("==invalid component!,psn all 0xff\n");
        CompReg_menu(0,partnumber,REG_INVALID_COMP,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;
//        return;
    }
    else//部件未注册
    {
        if(total_nums > MAX_COMP){//部件总数越界
            //显示已经超过数量！！，不允许注册了，请删除！！！
//            Debug("!error::comp nums overflow!\n");
            CompReg_menu(0,partnumber,REG_COMP_OVERFLOW,GetCompRegAddr(),GetCompRegParaSel(),0);
            goto END;
//            return;
        }
        if(ciraddr > MAX_LOOP)//回路越界
        {
            CompReg_menu(0,partnumber,REG_CIR_OVERFLOW,GetCompRegAddr(),GetCompRegParaSel(),0);
//            Debug("!error::ciraddr overflow!\n");

            goto END;
//            return;
        }


//        //禁止中断并清回路，清回路与保存有关,禁止再接收信息，不能禁止串口
//        Eint_DisAll_Exuart();
//        ClrSys_CLpScanCtrl();
//        EndInt();
        //正在注册
        CompReg_menu(0,partnumber,REG_REGING,GetCompRegAddr(),GetCompRegParaSel(),0);

        //设置

        compreg.inzone = histinfo.inzone = 0;
        compreg.part   = histinfo.part   =partnumber;
        compreg.ciraddr =histinfo.circleaddr = ciraddr;
        compreg.psn0    = PURCV_DETAIL.addr[3];
        compreg.psn1    = PURCV_DETAIL.addr[2];
        compreg.psn2    = PURCV_DETAIL.addr[1];
        compreg.psn3    = PURCV_DETAIL.addr[0];
        compreg.devtype =histinfo.devtype = PURCV_DETAIL.attr;


//        Debug("devtype:%d\n",compreg.devtype);

        histinfo.attr    = OPSTYPE_START;
        histinfo.opstype = INITVAL;
        histinfo.order = GetHistConter();
        histinfo.lastnum   = INITVAL;
        histinfo.vAnnRow = INITVAL;

        Debug("-->>save hist:\n");
        Debug("year:%d\n",histinfo.dateyear.year);
        Debug("month:%d\n",histinfo.dateyear.month);
        Debug("day:%d\n",histinfo.dateyear.day);
        Debug("hour:%d\n",histinfo.dateyear.hour);
        Debug("minute:%d\n",histinfo.dateyear.minute);
        Debug("second:%d\n",histinfo.dateyear.second);

        //保存到历史记录中
        set_comp_all(partnumber,&compreg);
        set_mask_info(partnumber,OPSTYPE_START);
        set_hist_allinfo(GetHistConter(),&histinfo);


        //添加回路注册信息
        SetReg_CNodeInfo(ciraddr);
        //保存部件与历史

        save_comp_info();
        save_mask_info();
        save_hist_all();

        Debug("->>save reg info save to flash\n");

        autoadd_compreg();
        CompReg_menu(0,GetCompRegNum(),REG_SUC,GetCompRegAddr(),GetCompRegParaSel(),0);
    }
//    //开中断,因为有串口打印信息，所以不能禁止串口

END:
    StartInt();
    Eint_EnAll_Exuart();




}

/*************查询信号强度******************/
static void inquiry_signal_strength(void)
{
    int16 com_num=-1;
    int8 ret;
    Debug("===>>>signal strength test\n");
    OnLCD();
    ret=CompareAddr(PURCV_DETAIL.addr[3],PURCV_DETAIL.addr[2],PURCV_DETAIL.addr[1],PURCV_DETAIL.addr[0],&com_num);
    if(!ret&&com_num>=0)
    {
        Debug("comp num:%d\n",com_num);

        CompInten_Menu(get_comp_inzone(com_num),
                       get_comp_partnumber(com_num),
                       PURCV_DETAIL.attr,
                       PURCV_DETAIL.detail);
    }else{
        CompInten_Menu(0,0,INITVAL,0);
    }
}
static uint8 is_0xff(uint8 psn)
{
    return (INITVAL == psn);
}


uint8 check_psn_all0xff(void)
{
    if(is_0xff(COM_PSN(3))
            &&is_0xff(COM_PSN(2))
            &&is_0xff(COM_PSN(1))
            &&is_0xff(COM_PSN(0)))
        return TRUE;
    else
        return FALSE;
}

/*************是否为已经注册的psn码******************/
static uint8 is_my_psn(int16* com_num)
{
    *com_num=-1;
    if(0 == CompareAddr(COM_PSN(3),COM_PSN(2),COM_PSN(1),COM_PSN(0),com_num))
        return TRUE;
    else
        return FALSE;

}
static void led_relay_deal(void)
{
    Fire_Relay_On();
    Led_Fire_On();
    Led_Silence_Off();

}
//通知回路
//设置回路地址，火警
void set_firealarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);  //set alarm node info
    SetState_CNodeInfo(cir_addr,cNodeState_Alarm); //set state of node

}
//设置回路地址，故障
void set_faultalarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);
    SetState_CNodeInfo(cir_addr,cNodeState_Fault);
}
//设置回路地址，正常
void set_normalalarm_ciraddr(uint8 cir_addr)
{
//    SetAlarm_CNodeInfo(cir_addr);
    Debug("normal ciraddr:%d\n",cir_addr);
    ClrAlarm_CNodeInfo(cir_addr);
    SetState_CNodeInfo(cir_addr,cNodeState_Normal);
}
//uint8 Get_firealarm_nums(void)
//{
//    return AlarmSum[2];
//}

/*************首警界面处理******************/
static void menu_firealarm_face(alarminfo* alarm1_info)
{
    memset(&histinfo,0,sizeof(history_st));

    histinfo.part = alarm1_info->part;
    histinfo.circleaddr = alarm1_info->ciraddr;
    histinfo.attr       = alarm1_info->attr;
    histinfo.devtype    = alarm1_info->type;
    histinfo.dateyear   = alarm1_info->dateyear;
    histinfo.vAnnRow    = alarm1_info->vAnnRow;

    Debug("=====>>alarm1_info\n");
    Debug("part: %d\n",alarm1_info->part);
    Debug("ciraddr: %d\n",alarm1_info->ciraddr);
    Debug("attr: %d\n",alarm1_info->attr);
    Debug("devtype: %d\n",alarm1_info->type);
    Debug("vAnnRow: %d\n",alarm1_info->vAnnRow);


    Flag195 = 1;

    SetAlarmFlag(POS_ALARM_BIT,ALARM_FIRE);
    //灯处理
    led_relay_deal();

    //    SetAlarm_Circuit_Flag(1);

    //设置火警回路
    set_firealarm_ciraddr(alarm1_info->ciraddr);//通知回路处理
    //进入火警界面——用
    SetMenuFlag(MENU_FIREALARM);
    SetDisplay_alarm_flag(PAGE_AT_FIRE);

    set_menu_alarm_info(*alarm1_info);
    //    Alarm_Menu(get_alarm_first_part(),
    //               alarm1_info->part,
    //               alarm1_info->ciraddr,
    //               get_firealarm_nums(),
    //               alarm1_info->type,
    //               &alarm1_info->dateyear);
    SetReleaseFlag(1);
    //保存历史记录
    set_hist_allinfo(GetHistConter(),&histinfo);
    save_hist_all();


    //    FirstAlarm_Flag++;//not first alarm again
    //    //    SetFirstAlarm_Addr(0,GetPSNFormFlash(num,POS_INZONE));
    //    //    SetFirstAlarm_Addr(1,GetPSNFormFlash(num,POS_PARTNUMBER));
    //    //save inzone partnumber
    //    SetFirstAlarm_Addr(0,get_comp_inzone(num));
    //    SetFirstAlarm_Addr(1,get_comp_partnumber(num));
    //alarm nums
    //    AlarmSum[2] = 1;
    //设置菜单显示标志

    //    SetDisplay_alarm_flag(PAGE_AT_FIRE);
    //set for sound and uart
    //    SetAlarmFlag(POS_ALARM_BIT,ALARM_FIRE);
    //    SetAlarmFlag(POS_INQUIRY_BIT,ALARM_FIRE);
    //save to flash

    //    getcurrent_date(&alarm_date);
    //    CSave_HistoryInfo_toFlash(num,get_comp_inzone(num),
    //                              get_comp_partnumber(num),cir_addr,&alarm_date);//火警信息保存到flash中
    //    //保存最新报警界面
    //    //save to var,for menu show at first
    //    //depart,uint8 partnumber,uint8 cirAddr,uint16 sum,uint8 type
    //    Setdisplay_alarm(0,get_comp_inzone(num));
    //    Setdisplay_alarm(1,get_comp_partnumber(num));
    //    Setdisplay_alarm(2,cir_addr);
    //    Setdisplay_alarm(3,AlarmSum[2]);
    //    Setdisplay_alarm(4,get_comp_devtype(num));
    //    valarmtime=timedate;
}
///*************其他火警界面处理******************/
//void menu_orther_firealarm_deal(alarminfo* alarm1_info)
//{
//    //    if(JudgeCompAlarmType(num)==1)
//    //    {
//    led_relay_deal();

//    AlarmSum[2] += 1;//record alarm total nums

//    CheckInfoFlag[0]=1;
//    SetAlarmFlag(POS_ALARM_BIT,ALARM_FIRE);
//    SetAlarmFlag(POS_INQUIRY_BIT,ALARM_FIRE);

//    set_firealarm_ciraddr(cir_addr);
//    {
//        SetReleaseFlag(2);
//        SetMenuFlag(MENU_FIREALARM);
//        SetAlarm_Circuit_Flag(1);

//        Alarm_Menu(GetFirstAlarm_Addr(0),GetFirstAlarm_Addr(1),cir_addr,AlarmSum[2],get_comp_devtype(num),&timedate);
//    }
////    SetCirAlarmData(get_comp_ciraddr(num),ATTR_FIRE);

//    getcurrent_date(&alarm_date);

//    CSave_HistoryInfo_toFlash(num,get_comp_inzone(num),
//                              get_comp_partnumber(num),cir_addr,&alarm_date);
//    Setdisplay_alarm(0,get_comp_inzone(num));
//    Setdisplay_alarm(1,get_comp_partnumber(num));
//    Setdisplay_alarm(2,cir_addr);
//    Setdisplay_alarm(3,AlarmSum[2]);
//    Setdisplay_alarm(4,get_comp_devtype(num));
//    valarmtime=timedate;
//    SetDisplay_alarm_flag(PAGE_AT_FIRE);

//}


//void battery_low_deal(uint8 num,uint8 cir_addr)
//{
//    Led_Fault_On();//fault led
//    Fault_Relay_On();//fault relay

//    //    if(JudgeCompAlarmType(num))
//    //    {
//    AlarmSum[0] += 1;

//    if(GetAlarmFlag(POS_ALARM_BIT) != ALARM_FIRE)
//        SetAlarmFlag(POS_ALARM_BIT,ALARM_BAT_LOW);
//    if(GetReleaseFlag()==0)
//    {
//        set_faultalarm_ciraddr(cir_addr);
//        SetReleaseFlag(3);
//        SetMenuFlag(MENU_FIREALARM);
//        ClearScreen(0);
//        Battery_Low(get_comp_inzone(num),get_comp_partnumber(num),AlarmSum[0],get_comp_devtype(num),timedate);

//    }
////    SetCirAlarmData(get_comp_ciraddr(num),ATTR_BAT_LOW);
//    getcurrent_date(&alarm_date);
//    CSave_HistoryInfo_toFlash(num,get_comp_inzone(num),
//                              get_comp_partnumber(num),cir_addr,&alarm_date);
//    //    }

//    // 							Query_ByUart0(0x0b,0x00,GetPSNFormFlash(num,7));

//    Flag195 = 1;
//    //CheckInfoFlag[1]=1;
//    SetAlarmFlag(POS_INQUIRY_BIT,ALARM_BAT_LOW);
//    //    BJNum[AlarmSum[0]][1]=num;


//    reset_batt_flag=1;
//    if(GetDisplay_alarm_flag()!=PAGE_AT_FIRE)
//    {
//        SetDisplay_alarm_flag(PAGE_AT_BATLOW);
//        Setdisplay_alarm(0,get_comp_inzone(num));
//        Setdisplay_alarm(1,get_comp_partnumber(num));
//        Setdisplay_alarm(3,AlarmSum[0]);
//        Setdisplay_alarm(4,get_comp_devtype(num));
//        valarmtime=timedate;
//    }

//}
void menu_fault_deal(alarminfo* alarm_info)
{
//    history_st histinfo;
    memset(&histinfo,0,sizeof(history_st));

    histinfo.part = alarm_info->part;
    histinfo.circleaddr = alarm_info->ciraddr;
    histinfo.attr       = alarm_info->attr;
    histinfo.devtype    = alarm_info->type;
    histinfo.dateyear   = alarm_info->dateyear;
    histinfo.vAnnRow    = alarm_info->vAnnRow;

    Flag195 = 1;
    reset_fault_flag = 1;

    Debug("=====>>fault alarm_info\n");
    Debug("part: %d\n",alarm_info->part);
    Debug("ciraddr: %d\n",alarm_info->ciraddr);
    Debug("attr: %d\n",alarm_info->attr);
    Debug("devtype: %d\n",alarm_info->type);
    Debug("vAnnRow: %d\n",alarm_info->vAnnRow);

    Led_Fault_On();
    Fault_Relay_On();


    if(GetAlarmFlag(POS_ALARM_BIT) !=ALARM_FIRE){
        Debug("-->>set fault bit\n");
        SetAlarmFlag(POS_ALARM_BIT,ALARM_FAULT);
    }
    if(GetReleaseFlag()==0)//只有在复位后才显示出来
    {
        Debug("-->>GetReleaseFlag is 0\n");
        set_faultalarm_ciraddr(alarm_info->ciraddr);//通知回路——故障
        SetReleaseFlag(4);
        //进入故障界面——使用
        SetMenuFlag(MENU_FAULTALARM);
        SetDisplay_alarm_flag(PAGE_AT_FAULT);
        //设置内容到另外一个存储中
        set_menu_faultalarm_info(*alarm_info);
    }

    set_hist_allinfo(GetHistConter(),&histinfo);
    save_hist_all();
}
static const uint8 fault_restore_cfg[2]={0x0b,0x01};

static void normal_deal(uint8 num,uint8 cir_addr)
{
    Debug("normal,ciraddr:%d\n",cir_addr);
    if(Flag195)
    {//故障恢复

        set_normalalarm_ciraddr(cir_addr);
        Query_ByUart0(fault_restore_cfg[0],fault_restore_cfg[1],cir_addr);
        Flag195 = 0;
    }

    if(reset_fault_flag)
    {
        reset_fault_flag=0;
        Led_Fault_Off();
        Fault_Relay_Off();
        //清除故障报警
        if((ATTR_FAULT == get_alarm_attr(num) )||
                (ATTR_BAT_LOW == get_alarm_attr(num)))
        {
            set_alarm_attr(num,ATTR_NORMAL);
        }
        SetAlarmFlag(POS_ALARM_BIT,ALARM_NORMAL);
        SetDisplay_alarm_flag(PAGE_AT_NORMAL);
        SetMenuFlag(MENU_MAIN);
    }
}

static alarminfo  alarm_info;

response_atfire respfire_val={INITVAL,INITVAL,INITVAL,INITVAL,INITVAL};

/*************接收处理******************/
void HandleInfo_Uart1(void)//主循环中
{
    uint8 rcvcmd;
//    uint8 num;
    uint8 cir_addr=0;

    int16 num;//模块位置
    //处理无线模块收到的数据，无线模块与部件，139之间通讯协议，长度9字节
    pdUartRcv = GetComData(com1Count);//(PdUartMsgUnion)data;

    if(wireless_data_check() == SUC)//如果有串口1有数据为真
    {
//        //清空data0数组
        ClrCom1Data0();

        rcvcmd = PURCV.cmd;
//        Debug("uart1 cmd:%d\n",rcvcmd);
        switch(rcvcmd)
        {
        case	CMD_SMOKE:		//心跳	  30
        case	CMD_TEMP:		//心跳	  31
        case	CMD_HAND:		//心跳	  32
        case	CMD_HYDRANT:		//心跳	  33
        case	CMD_INMODEL:		//心跳	  34
        case	CMD_INOUT:		//心跳	  35
        case	CMD_VOILIG:		//心跳	  36
            break;
        case	CMD_139W:		//心跳	  38
            ClrHeartFaultFlag();//清标志
            Debug("CMD_139W\n");
            break;
        case	CMD_TRANSIT:		//心跳	  39
            clr_tp();
            break;
        case	CMD_COMPENET:		//	  40报警

            Debug("-->>CMD_ALARM!!!\n");
            DebugOnce("-->>CMD_ALARM!!!\n");
            if(check_psn_all0xff())
            {
                Debug("psn all 0xff\n");
                break;
            }
            if(is_my_psn(&num))//0表示已经注册
            {
                if(num < 0)
                    return;
                OnLCD();
                SetFlagLed(1);
//                UartBindSend(CMD_COMPENET,9);
//3hour故障处理
                clr_alarm_f_recvmess3h(num);
                clr_3h_counter(num);
                clr_faultnum_3h_(num);
                if((GetAlarmFlag(POS_ALARM_BIT) != ALARM_FAULT)
                        &&(GetAlarmFlag(POS_ALARM_BIT) != ALARM_FIRE)){
                    SetMenuFlag(MENU_MAIN);
                    Led_Fault_Off();
                    Fault_Relay_Off();
                }

                respfire_val.num = num;
                respfire_val.psn3 = get_comp_psn3(num);
                respfire_val.psn2 = get_comp_psn2(num);
                respfire_val.psn1 = get_comp_psn1(num);
                respfire_val.psn0 = get_comp_psn0(num);

                if(ATTR_FIRE == alarm_info.attr)//fire
                {//is fire?
                    check_response_atfire();
                }

                //屏蔽否？
                if(get_mask_info(num) == OPSTYPE_STOP)//已经屏蔽了，不报警了
                {
                    Debug("num is masked:%d\n",num);
                    DebugOnce("num is masked:%d\n",num);

                    break;
                }
                else
                {
                    //通过PSN找到位置
    //                num = GetNum(COM_PSN(3),COM_PSN(2),COM_PSN(1),COM_PSN(0));//地址所在数组的序号
                    Debug("num:%d\n",num);
                    DebugOnce("num:%d\n",num);
                    alarm_info.part = num;
                    alarm_info.ciraddr = get_comp_ciraddr(num);
                    alarm_info.type    = get_comp_devtype(num);
                    alarm_info.attr    = PURCV.attr/*devtype——PURCV_DETAIL.attr*/;
                    alarm_info.alarmed = ALARM_HAVE;//标记已经有报警
                    alarm_info.vAnnRow = GetAnnRow(num);
                    PCF8563_Read(&alarm_info.dateyear);//get date, time

                    Debug("alarm ciraddr:%d\n",alarm_info.ciraddr);
                    if(ATTR_FIRE == alarm_info.attr)//fire
                    {//is fire?
//                        check_response_atfire();
                        //处理首警
//                        Debug("at firer response num:%d\n",num);
//                        uart1_stop_reponse_atfire(get_comp_psn3(num),
//                                                 get_comp_psn2(num),
//                                                 get_comp_psn1(num),
//                                                 get_comp_psn0(num));
                        if((!judge_alarm_first())&&JudgeAlarmType())//首警
                        {
                            Debug("--->>>first alarm\n");
                            set_alarm_allinfo_andsave(num,&alarm_info);
                            set_alarm_first(&alarm_info);
                            //first alarm menu
                            menu_firealarm_face(&alarm_info);
                        }else{
                            //判断是否已经报警
                            if(judge_alarm_firealarmed(num))
                            {
                                //                                Debug("num:%d haved fire alarmed\n",num);
                                break;
                            }
                            Debug("num:%d haved fire alarmed first\n",num);
                            set_alarm_allinfo_andsave(num,&alarm_info);
                            menu_firealarm_face(&alarm_info);
                        }
                    }
                    else if((ATTR_FAULT == alarm_info.attr)||//broken
                            (ATTR_BAT_LOW == alarm_info.attr))//battery_low
                    {
                        if(judge_alarm_faultalarmed(num))
                        {
                            Debug("num:%d haved fault alarmed\n",num);
                            break;
                        }
                        Debug("num:%d haved fault alarmed\n",num);
                        set_alarm_allinfo_andsave(num,&alarm_info);
                        menu_fault_deal(&alarm_info);
                    }
                    Led_Silence_Off();
                    if(ATTR_NORMAL == PURCV.attr)
                    {
                        Debug("normal state\n");
                        normal_deal(num,cir_addr);
                    }
                }
            }else{
                //                Debug("not my psn\n");
                //                Debug("psn0:%d\n",COM_PSN(3));
                //                Debug("psn1:%d\n",COM_PSN(2));
                //                Debug("psn2:%d\n",COM_PSN(1));
                //                Debug("psn3:%d\n",COM_PSN(0));
                break;
            }

            SetFlagLed(0);
            break;
        case	CMD_COMREG:		//	  41//部件注册
            Debug("CMD_COMREG\n");

            if(CGetIntenFlag())//查询信号强度
            {
                inquiry_signal_strength();
            }
            else if(GetComRegFlag())//注册
            {
                ClrComRegFlag();//立即清除，防止再次接收数据

                comp_reg_deal();

            }else{
                OnLCD();
            }
            SetFlagLed(0);
            break;
        case	CMD_CONTROL:		//	  42
            if(PURCV.attr == 0x30)//silence
            {

            }
            else if(PURCV.attr == 0x31)//static status
            {

            }
            else if(PURCV.attr == 0x32)//param
            {

            }
            else if(PURCV.attr == 0x33)//CompSetup
            {

            }
            break;
        case	CMD_BROADCAST:		//广播	  51
            break;
        default:
            break;
        }
        memset(PURCV_ARRAY, 0 , UART_BUF_LEN);

    }else{
//        Debug("wirless check failed\n");
    }

    /********************reset the data*****************/
#if 0
    ClrComData(get_dataCount());

#else
    //从头至尾扫描
    ClrComData(com1Count);
    com1Count++;
    if(com1Count== RCV_SIZE)
        com1Count=0;
#endif
    if(UartClrflag == CLR_FLAG)
    {
        // 		BufferClear(pUartbuf , UartClrLen);
        UartClrLen = 0x00;
        UartClrflag = 0x00;
    }
}
//void savetoData(uint8 num)
//{


//    SetDatatoFlash(num,COM_POS_DEVSTATE,PURCV_DETAIL.attr);
//    SetDatatoFlash(num,COM_POS_HIYEAR,(uint8)CONVERT(timedate.year));
//    SetDatatoFlash(num,COM_POS_LOWYEAR,(uint8)timedate.year);
//    SetDatatoFlash(num,COM_POS_MONTH,timedate.month);
//    SetDatatoFlash(num,COM_POS_DAY,timedate.day);
//    SetDatatoFlash(num,COM_POS_HOUR,timedate.hour);
//    SetDatatoFlash(num,COM_POS_MIN,timedate.minute);
//    SetDatatoFlash(num,COM_POS_SEC,timedate.second);
//    SetDatatoFlash(num,COM_POS_SIGSTREN,PURCV_DETAIL.detail);	//信号强度

//}
//void savetohistory_single(uint8 num,uint8 inzone,uint8 partnumber,uint8 ciraddr,PCF8563_DATE *timedate)
//{
//    uint8 vAnnRow;
//    vAnnRow = get_node_row(get_comp_inzone(num),get_comp_partnumber(num));//存储注释的函数

//    SetHistoryList(GetHistConter(),0,num);
//    SetHistoryList(GetHistConter(),1,GetDatatoFlash(num,COM_POS_DEVTYPE));
//    SetHistoryList(GetHistConter(),2,GetDatatoFlash(num,COM_POS_COMSEL));
//    SetHistoryList(GetHistConter(),3,PURCV_DETAIL.attr);
//    SetHistoryList(GetHistConter(),4,(uint8)CONVERT(timedate->year));
//    SetHistoryList(GetHistConter(),5,(uint8)timedate->year);
//    SetHistoryList(GetHistConter(),6,timedate->month);
//    SetHistoryList(GetHistConter(),7,timedate->day);
//    SetHistoryList(GetHistConter(),8,timedate->hour);
//    SetHistoryList(GetHistConter(),9,timedate->minute);
//    SetHistoryList(GetHistConter(),10,timedate->second);
//    SetHistoryList(GetHistConter(),11,vAnnRow);
//    SetHistoryList(GetHistConter(),12,inzone);
//    SetHistoryList(GetHistConter(),13,partnumber);
//    SetHistoryList(GetHistConter(),14,ciraddr);



//    Debug("year:%d\n",timedate->year);
//    Debug("month:%d\n",timedate->month);
//    Debug("day:%d\n",timedate->day);
//    Debug("hour:%d\n",timedate->hour);
//    Debug("minute:%d\n",timedate->minute);
//    Debug("second:%d\n",timedate->second);


//}
//void flash_save_historyinfo(void)
//{
//    check_lp_running();
//    M25P80_Section_Erase(FLS_HIST_ADR);//存储历史记录内容
//}

//void flash_save_historycounter(void)
//{
//    uint8 i,k;
//    uint8 vHisC[3];//0:/10,1:%10,2:>1000 flag

//    vHisC[0]=(uint8)(GetHistConter() / 10); //calc history lists
//    vHisC[1]=(uint8)(GetHistConter()%10);

//    if(GetHistConter()>=MAX_HIST_NUMS){ //calc history nums
//        SetHistConter(MAX_HIST_NUMS);
//        vHisC[2]=HISTNUMOVER1000;//the counter num is MAX_HIST_NUMS
//    }
//    check_lp_running();
//    M25P80_Section_Erase(FLS_HISTNUMS_ADR);//存储历史记录条数
//    for(i=0;i<3;i++)
//    {
//        check_lp_running();
//        M25P80_Write_1Byte((FLS_HISTNUMS_ADR+i),vHisC[i]);
//        for(k=0;k<10;k++);
//    }
//}

////save data to history
//void CSave_HistoryInfo_toFlash(uint8 num,uint8 inzone,uint8 partnumber,uint8 ciraddr,PCF8563_DATE *date)
//{
//    savetoData(num);
//    //存储历史记录
//    save_hist_all();
//    //    savetohistory_single(num,inzone,partnumber,ciraddr,date);
//    //    AddHistConter();    //add history list

//    //    flash_save_historycounter();

//    //    check_lp_running();//存储到flash


//    //    SendHistToFlash();
//    //    save_hist_info();
//}
/*判断psn码，
如果已经注册，则返回0，
未注册，返回1
  */
uint8 CompareAddr(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3,int16 *com_num)
{
    uint8 j;
    uint8 Regflag=1;
    if((0xff == psn0)&&
            (0xff == psn1)&&
            (0xff == psn2)&&
            (0xff == psn3))
    {
        return INVALID_ADDR_COMP;
    }

    for(j= COMP_START;j<= MAX_COMP;j++)
    {
        if((get_comp_psn0(j)==psn0)&&
                (get_comp_psn1(j)==psn1)&&
                (get_comp_psn2(j)==psn2)&&
                (get_comp_psn3(j)==psn3))
        {

            if(com_num){
                *com_num=j;
                Regflag=0;
            }
            break;
        }
    }
    return Regflag;
}



