/*
;*********************************************************************************************************
;*                                                
;*                            ����: CComHandle
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CComHandle.c
;* By   : ������
;* ʱ�� : 2013-06-24
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


//�궨��


#define	CONVERT(X)	((X&0x00ff)*256+(X&0xff00)/256)//�ߵ�λת��
#define	ASC_HEX(X,Y)	((X-0x30)<<4+(Y-0x30))



//��������
extern PCF8563_DATE    timedate;
static PdUartMsgUnion pdUartSend;//�ṹ�嶨��
//PdUartMsgUnion uart0_rev_data;
static PdUartMsgUnion pdUartRcv;
tFlashinfoDef  FlashInfo;


history_st  histinfo;

static compent  compreg;
//��������
void AddHeartFaultFlag(void);



//��������

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
//��·֮���ٷ�����Ϣ
void check_lp_running(void)
{
    while(GetSys_CLpScanCtrl());
}

/*******************�������*************************/
//������ݲ�����
void UartBindSend(uint8 cmd,uint8 len)
{
    uint8 num;
    uint8 dat =0;

    pdUartSend = (PdUartMsgUnion)UartTxbuf;
    PUSEND.header = CMD_HEAD;
    PUSEND.cmd = cmd;

    if(UART_MESSAGE_LEN == len){
        memcpy(PUSEND_DETAIL.addr, Convertdata, 6);  //�˴������ݣ�ͨ��ConvertData�ڴ��ڽ��յ����ݷ�����ȥ��
        for(num = 0; num < 7; num++)					//checksum calculate[2]~[7]
            dat += PUSEND_ARRAY[num+1];
        PUSEND.cs = dat;

        UartSendLen = UART_MESSAGE_LEN;
        pTxbuf = PUSEND_ARRAY;
    }else{

    }
//    check_lp_running();
    UARTSend(1,PUSEND_ARRAY,len);//���ںţ�����ָ�룬����
}
/********************end*************************/
//######################################################################################################
// �������� wireless_data_check()
//------------------------------------------------------------------------------------------------------
// �������� ��У��
//------------------------------------------------------------------------------------------------------
// ������� ��
//------------------------------------------------------------------------------------------------------
// ������� ��У��ͨ������ģ���յ�������
//######################################################################################################
uint8 wireless_data_check(void)
{
    uint8 num;
    uint8 dat = 0;

    if(PURCV.header != CMD_HEAD)//�ж�ͷ�Բ���
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
/*************���ҷ�������******************/
//�������ͺͲ����������ʱ����ע��
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
// //��ӡע��������Ϣ
// static void printf_zone_comp_info(void)
// {
//     uint8 i;
//     for(i=COMP_START;i<=MAX_COMP;i++)
//         Debug("->info::%d:inzone:%d,partnumber:%d\n",i,get_comp_inzone(i),get_comp_partnumber(i));

// }
//ѡ�����Զ���1��ʾ
static void autoadd_compreg(void)
{
    AddCompRegNum();
    if(GetCompRegNum() >MAX_COMP)
        SetCompRegNum(COMP_START);
}


/*************����ע��  ����******************/
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


    total_nums=get_basic_nums();//��������
    ciraddr=get_basic_localaddr();//��·��ַ
    partnumber=GetCompRegNum();//����������ȡ

    Debug("===comp regging info......\n");
    Debug("total_nums:%d\n",total_nums);
    Debug("partnumber:%d\n",partnumber);
    Debug("ciraddr:%d\n",ciraddr);

//�ж�ǰ��ȡʱ�䣬����i2c�жϺ����
    getcurrent_date(&histinfo.dateyear);

    //��ֹ�жϲ����·�����·�뱣���й�,��ֹ�ٽ�����Ϣ�����ܽ�ֹ����
//    Eint_DisAll_Exuart();
//    ClrSys_CLpScanCtrl();
    EndInt();/*��ֹ��uart0 not print*/


    //���psn���Ƿ��Ѿ�ע�ᣬ0��ʾ��ע��
    if(find_zone_comp(0,partnumber))
    {
//        Debug("==finding same and partnumber!!\n");
        CompReg_menu(0,partnumber,REGD_COMP,GetCompRegAddr(),GetCompRegParaSel(),0);
        goto END;
//        return;
    }
    else if(CompareAddr(PURCV_DETAIL.addr[3],PURCV_DETAIL.addr[2],PURCV_DETAIL.addr[1],PURCV_DETAIL.addr[0],&com_num)==0)
    {//�豸�Ѿ�ע��
//        Debug("==device been reged!!\n");
        CompReg_menu(0,partnumber,REGD_DEV,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;
//        return;

    }
    else if(INVALID_ADDR_COMP == CompareAddr(PURCV_DETAIL.addr[3],PURCV_DETAIL.addr[2],PURCV_DETAIL.addr[1],PURCV_DETAIL.addr[0],&com_num))
    {//�Ƿ�������psn��Ϊȫ0xff
//        Debug("==invalid component!,psn all 0xff\n");
        CompReg_menu(0,partnumber,REG_INVALID_COMP,GetCompRegAddr(),GetCompRegParaSel(),0);

        goto END;
//        return;
    }
    else//����δע��
    {
        if(total_nums > MAX_COMP){//��������Խ��
            //��ʾ�Ѿ���������������������ע���ˣ���ɾ��������
//            Debug("!error::comp nums overflow!\n");
            CompReg_menu(0,partnumber,REG_COMP_OVERFLOW,GetCompRegAddr(),GetCompRegParaSel(),0);
            goto END;
//            return;
        }
        if(ciraddr > MAX_LOOP)//��·Խ��
        {
            CompReg_menu(0,partnumber,REG_CIR_OVERFLOW,GetCompRegAddr(),GetCompRegParaSel(),0);
//            Debug("!error::ciraddr overflow!\n");

            goto END;
//            return;
        }


//        //��ֹ�жϲ����·�����·�뱣���й�,��ֹ�ٽ�����Ϣ�����ܽ�ֹ����
//        Eint_DisAll_Exuart();
//        ClrSys_CLpScanCtrl();
//        EndInt();
        //����ע��
        CompReg_menu(0,partnumber,REG_REGING,GetCompRegAddr(),GetCompRegParaSel(),0);

        //����

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

        //���浽��ʷ��¼��
        set_comp_all(partnumber,&compreg);
        set_mask_info(partnumber,OPSTYPE_START);
        set_hist_allinfo(GetHistConter(),&histinfo);


        //��ӻ�·ע����Ϣ
        SetReg_CNodeInfo(ciraddr);
        //���沿������ʷ

        save_comp_info();
        save_mask_info();
        save_hist_all();

        Debug("->>save reg info save to flash\n");

        autoadd_compreg();
        CompReg_menu(0,GetCompRegNum(),REG_SUC,GetCompRegAddr(),GetCompRegParaSel(),0);
    }
//    //���ж�,��Ϊ�д��ڴ�ӡ��Ϣ�����Բ��ܽ�ֹ����

END:
    StartInt();
    Eint_EnAll_Exuart();




}

/*************��ѯ�ź�ǿ��******************/
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

/*************�Ƿ�Ϊ�Ѿ�ע���psn��******************/
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
//֪ͨ��·
//���û�·��ַ����
void set_firealarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);  //set alarm node info
    SetState_CNodeInfo(cir_addr,cNodeState_Alarm); //set state of node

}
//���û�·��ַ������
void set_faultalarm_ciraddr(uint8 cir_addr)
{
    SetAlarm_CNodeInfo(cir_addr);
    SetState_CNodeInfo(cir_addr,cNodeState_Fault);
}
//���û�·��ַ������
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

/*************�׾����洦��******************/
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
    //�ƴ���
    led_relay_deal();

    //    SetAlarm_Circuit_Flag(1);

    //���û𾯻�·
    set_firealarm_ciraddr(alarm1_info->ciraddr);//֪ͨ��·����
    //����𾯽��桪����
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
    //������ʷ��¼
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
    //���ò˵���ʾ��־

    //    SetDisplay_alarm_flag(PAGE_AT_FIRE);
    //set for sound and uart
    //    SetAlarmFlag(POS_ALARM_BIT,ALARM_FIRE);
    //    SetAlarmFlag(POS_INQUIRY_BIT,ALARM_FIRE);
    //save to flash

    //    getcurrent_date(&alarm_date);
    //    CSave_HistoryInfo_toFlash(num,get_comp_inzone(num),
    //                              get_comp_partnumber(num),cir_addr,&alarm_date);//����Ϣ���浽flash��
    //    //�������±�������
    //    //save to var,for menu show at first
    //    //depart,uint8 partnumber,uint8 cirAddr,uint16 sum,uint8 type
    //    Setdisplay_alarm(0,get_comp_inzone(num));
    //    Setdisplay_alarm(1,get_comp_partnumber(num));
    //    Setdisplay_alarm(2,cir_addr);
    //    Setdisplay_alarm(3,AlarmSum[2]);
    //    Setdisplay_alarm(4,get_comp_devtype(num));
    //    valarmtime=timedate;
}
///*************�����𾯽��洦��******************/
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
    if(GetReleaseFlag()==0)//ֻ���ڸ�λ�����ʾ����
    {
        Debug("-->>GetReleaseFlag is 0\n");
        set_faultalarm_ciraddr(alarm_info->ciraddr);//֪ͨ��·��������
        SetReleaseFlag(4);
        //������Ͻ��桪��ʹ��
        SetMenuFlag(MENU_FAULTALARM);
        SetDisplay_alarm_flag(PAGE_AT_FAULT);
        //�������ݵ�����һ���洢��
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
    {//���ϻָ�

        set_normalalarm_ciraddr(cir_addr);
        Query_ByUart0(fault_restore_cfg[0],fault_restore_cfg[1],cir_addr);
        Flag195 = 0;
    }

    if(reset_fault_flag)
    {
        reset_fault_flag=0;
        Led_Fault_Off();
        Fault_Relay_Off();
        //������ϱ���
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

/*************���մ���******************/
void HandleInfo_Uart1(void)//��ѭ����
{
    uint8 rcvcmd;
//    uint8 num;
    uint8 cir_addr=0;

    int16 num;//ģ��λ��
    //��������ģ���յ������ݣ�����ģ���벿����139֮��ͨѶЭ�飬����9�ֽ�
    pdUartRcv = GetComData(com1Count);//(PdUartMsgUnion)data;

    if(wireless_data_check() == SUC)//����д���1������Ϊ��
    {
//        //���data0����
        ClrCom1Data0();

        rcvcmd = PURCV.cmd;
//        Debug("uart1 cmd:%d\n",rcvcmd);
        switch(rcvcmd)
        {
        case	CMD_SMOKE:		//����	  30
        case	CMD_TEMP:		//����	  31
        case	CMD_HAND:		//����	  32
        case	CMD_HYDRANT:		//����	  33
        case	CMD_INMODEL:		//����	  34
        case	CMD_INOUT:		//����	  35
        case	CMD_VOILIG:		//����	  36
            break;
        case	CMD_139W:		//����	  38
            ClrHeartFaultFlag();//���־
            Debug("CMD_139W\n");
            break;
        case	CMD_TRANSIT:		//����	  39
            clr_tp();
            break;
        case	CMD_COMPENET:		//	  40����

            Debug("-->>CMD_ALARM!!!\n");
            DebugOnce("-->>CMD_ALARM!!!\n");
            if(check_psn_all0xff())
            {
                Debug("psn all 0xff\n");
                break;
            }
            if(is_my_psn(&num))//0��ʾ�Ѿ�ע��
            {
                if(num < 0)
                    return;
                OnLCD();
                SetFlagLed(1);
//                UartBindSend(CMD_COMPENET,9);
//3hour���ϴ���
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

                //���η�
                if(get_mask_info(num) == OPSTYPE_STOP)//�Ѿ������ˣ���������
                {
                    Debug("num is masked:%d\n",num);
                    DebugOnce("num is masked:%d\n",num);

                    break;
                }
                else
                {
                    //ͨ��PSN�ҵ�λ��
    //                num = GetNum(COM_PSN(3),COM_PSN(2),COM_PSN(1),COM_PSN(0));//��ַ������������
                    Debug("num:%d\n",num);
                    DebugOnce("num:%d\n",num);
                    alarm_info.part = num;
                    alarm_info.ciraddr = get_comp_ciraddr(num);
                    alarm_info.type    = get_comp_devtype(num);
                    alarm_info.attr    = PURCV.attr/*devtype����PURCV_DETAIL.attr*/;
                    alarm_info.alarmed = ALARM_HAVE;//����Ѿ��б���
                    alarm_info.vAnnRow = GetAnnRow(num);
                    PCF8563_Read(&alarm_info.dateyear);//get date, time

                    Debug("alarm ciraddr:%d\n",alarm_info.ciraddr);
                    if(ATTR_FIRE == alarm_info.attr)//fire
                    {//is fire?
//                        check_response_atfire();
                        //�����׾�
//                        Debug("at firer response num:%d\n",num);
//                        uart1_stop_reponse_atfire(get_comp_psn3(num),
//                                                 get_comp_psn2(num),
//                                                 get_comp_psn1(num),
//                                                 get_comp_psn0(num));
                        if((!judge_alarm_first())&&JudgeAlarmType())//�׾�
                        {
                            Debug("--->>>first alarm\n");
                            set_alarm_allinfo_andsave(num,&alarm_info);
                            set_alarm_first(&alarm_info);
                            //first alarm menu
                            menu_firealarm_face(&alarm_info);
                        }else{
                            //�ж��Ƿ��Ѿ�����
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
        case	CMD_COMREG:		//	  41//����ע��
            Debug("CMD_COMREG\n");

            if(CGetIntenFlag())//��ѯ�ź�ǿ��
            {
                inquiry_signal_strength();
            }
            else if(GetComRegFlag())//ע��
            {
                ClrComRegFlag();//�����������ֹ�ٴν�������

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
        case	CMD_BROADCAST:		//�㲥	  51
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
    //��ͷ��βɨ��
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
//    SetDatatoFlash(num,COM_POS_SIGSTREN,PURCV_DETAIL.detail);	//�ź�ǿ��

//}
//void savetohistory_single(uint8 num,uint8 inzone,uint8 partnumber,uint8 ciraddr,PCF8563_DATE *timedate)
//{
//    uint8 vAnnRow;
//    vAnnRow = get_node_row(get_comp_inzone(num),get_comp_partnumber(num));//�洢ע�͵ĺ���

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
//    M25P80_Section_Erase(FLS_HIST_ADR);//�洢��ʷ��¼����
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
//    M25P80_Section_Erase(FLS_HISTNUMS_ADR);//�洢��ʷ��¼����
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
//    //�洢��ʷ��¼
//    save_hist_all();
//    //    savetohistory_single(num,inzone,partnumber,ciraddr,date);
//    //    AddHistConter();    //add history list

//    //    flash_save_historycounter();

//    //    check_lp_running();//�洢��flash


//    //    SendHistToFlash();
//    //    save_hist_info();
//}
/*�ж�psn�룬
����Ѿ�ע�ᣬ�򷵻�0��
δע�ᣬ����1
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



