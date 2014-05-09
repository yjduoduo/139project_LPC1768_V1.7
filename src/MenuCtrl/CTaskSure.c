/*
;*********************************************************************************************************
;*                                                
;*                            ����: CTaskSure
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskSure.c
;* By   : ������
;* ʱ�� : 2013-06-28
;*********************************************************************************************************
;*/
#define TaskSure_C

#include  "include.h"
#include  "CTaskSure.h"
#include  "CGetGrap.h"
#include  "tasklist.h"
#include  "CKeyCounter.h"
// #include  "CFlashParam.h"
#include  "CComHandle.h"
#include  "CSendToFlash.h"
// #include "CLED.h"
#include  "CGetCompSum.h"
// #include  "CMaDefine.h"
// #include  "CComHandle.h"
#include  "CComPara.h"
#include  "CSysReset.h"
#include  "CTaskDown.h"
#include  "CComPara.h"
#include  "CLpScanCtrl.h"
#include  "componentinfo.h"
#include  "store_addr.h"
#include  "CFlash_ADDR_Def.h"
#include  "CTaskReturn.h"
#include  "CNodeInfo.h"
#include  "key.h"
#include  "CTimeCtrl.h"
#include  "about139.h"
#include  "CSoftVerDef.h"


//��������Ϊʵ�ʴ洢λ�ã����1
#define NUM_TOPOS(A) (A-1)



static uint8 menu_in_setuplocaladdr =0 ;

extern tFlashinfoDef  FlashInfo;
PCF8563_DATE    timedate;
extern uint8 vMaskPSN[MASKSUM];
volatile static uint8 vMaskCount=0;
volatile static uint8 vmaskflag = 0;
static uint8 vAnnUartFlag=0;//����ע�ͱ�־
static uint8 vZjFlag=0;//�Լ��־
static uint8 vSpeaker_Counter=1; //Ĭ�Ϸ�������
void SetZjFlag(uint8 tmp)
{
    vZjFlag=tmp;
}
uint8 GetZjFlag(void)
{
    return vZjFlag;
}
void Set_Note_Flag(void)
{
    Debug("set note flag!\n");
    vAnnUartFlag=1;
}
void Clr_Note_Flag(void)
{
    vAnnUartFlag=0;
}

uint8 Get_Note_Flag(void)
{
    return vAnnUartFlag;
}
//void MaskPSNInit(void)
//{
//    //    �洢�������;;(0x20000);
//    uint8 i;
//    for(i=0;i<MASKSUM;i++)
//        vMaskPSN[i] = M25P80_Read_1Byte(0x20000+i);//vMaskPSN[i] =0xff;
//}
//void GetMaskPSN(void)
//{
//    uint8 i;
//    for(i=0;i<MASKSUM;i++)
//        vMaskPSN[i] = M25P80_Read_1Byte(0x20000+i);
//}
//void SaveMaskPSN(void)
//{
//    uint8 i;
//    check_lp_running();
//    M25P80_Section_Erase(0x20000);
//    // 					M25P80_Read_Bytes(0x20000,vMaskPSN,sizeof(vMaskPSN));
//    for(i=0;i<MASKSUM;i++)
//        M25P80_Write_1Byte((0x20000+i),vMaskPSN[i]);
//}
////1��ʾ���Σ�����Ϊ����
//uint8 CGetMaskPSN(uint8 row)
//{
//    return vMaskPSN[row];
//}

static void setup_ok(void)
{
    GetSetGrap(GetCounter2());
    Set_Note_Flag();
}
static void query_ok(void)
{
    GetCheckGrap(GetCounter2());
}
static void test_ok(void)
{
    GetTestGrap(GetCounter2());
}
void reset_ok(void)
{
    Eint_Dis();//���ж�
    ClrSys_CLpScanCtrl();//���·��־

    ClearScreen(0);

    UartBindSend(CMD_139W,2);	   //������������
    UartBindSend(CMD_139W,2);
    Led_Fault_Off();
    Led_Fire_Off();
    Fire_Relay_Off();
    Fault_Relay_Off();
    SetAlarmFlag(POS_ALARM_BIT,ALARM_NORMAL);
    SetAlarmFlag(POS_INQUIRY_BIT,ALARM_NORMAL);
    SetReleaseFlag(0);


    //    SetMenuFlag(MENU_RUN);
    //    Main_Menu(1);
//[n]��λʱĬ��Ϊ��һ������
    SetMenuFlag(MENU_MAIN);
    SetCounter1(1);
    SetCounter1(1);


    SetDisplay_alarm_flag(PAGE_AT_NORMAL);
    //�屨����·
    clr_alarm_allinfo();

    clr_PWM1_Started();
    PWM1_Stop();
    BEEPOff();


    //�����
    clr_weixialasignal();
    clr_xialasignal();

    //�����߼��
    reset_timer1_3h_counter();

    Menu_complete();
    Eint_En();//���ж�
    DelayMs(3000);



}

static void factory_ok(void)
{
    uint32 delflag=1;


    ClearScreen(0);
    menu_press_ok_complete(2);

    DelayMs(2000);

    while(1)
    {
        if(!KEY_RETURN)//���ؼ�
        {
            delflag=0;
            SetMenuFlag(MENU_RUN);
            SubGrapCount();
            SetCounter1(1);
            break;
        }
        if(KEY_OK)
            break;
    }
    while(KEY_OK)//�͵�ƽ��һֱΪ��
    {
        if(!KEY_RETURN)//���ؼ�
        {
            delflag=0;
            SetMenuFlag(MENU_RUN);
            SubGrapCount();
            SetCounter1(1);
            break;
        }
        delflag++;
        if(!KEY_OK)
            break;
    }

    if(delflag>30)
    {
        ClearScreen(0);
        menu_waiting();
        EndInt();
        //        Eint_DisAll_Exuart();
        //        ClrSys_CLpScanCtrl();

        //���·��Ϣ
        clr_comp_loop_all();

        M25P80_Section_Erase(FLS_BASEINFO_ADR);
        M25P80_Section_Erase(FLS_COMPINFO_ADR);
        M25P80_Section_Erase(FLS_MASKINFO_ADR);
        M25P80_Section_Erase(FLS_ALARMINFO_ADR);
        M25P80_Section_Erase(FLS_NODE_ADR);
        M25P80_Section_Erase(FLS_NODENUMS_ADR);
#ifdef ERASE_DEBUG
        M25P80_Section_Erase(FLS_HIST_ADR);
        M25P80_Section_Erase(FLS_HISTNUMS_ADR);
        M25P80_Section_Erase(FLS_HIST_SUFIX_ADR);
#endif
        M25P80_Section_Erase(0x90000);
        M25P80_Section_Erase(0xa0000);
        M25P80_Section_Erase(0xb0000);
        M25P80_Section_Erase(0xc0000);
        M25P80_Section_Erase(0xd0000);
        M25P80_Section_Erase(0xe0000);
        M25P80_Section_Erase(0xf0000);


        init_flash_all();

        StartInt();//���ж�


        ClearScreen(0);
        menu_complete();
        menu_press_return_toreturn();

    }

}
static void speaker_ok(void)
{
    CLevel27_Sure();
}

//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//�������ƣ�CLevel1_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//�������ܣ�ȷ�ϼ��ĵ�һ������
//--------------------------------------------------------------------------------------------------------------------------------
//���������	tmpΪ�ڼ���������ֵ
//--------------------------------------------------------------------------------------------------------------------------------
//���������	null
//--------------------------------------------------------------------------------------------------------------------------------
//˵   ������һ��˵�ok������ִ������
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void CLevel1_Sure(uint8 tmp)//��һ������
{

    switch(tmp)
    {
    case 1://����
        setup_ok();

        break;
    case 2://��ѯ
        query_ok();

        break;
    case 3://����
        test_ok();

        break;

    case 4://�ָ���������
        factory_ok();


        break;

    case 5://���÷�����
        speaker_ok();
        break;
    case 6://��λ
        reset_ok();

        break;
    default:
        break;
    }
}
static void get_local_addr(void)
{
    if(0xff == get_basic_localaddr()){//����Ѿ�������ˣ�Ĭ��ֵΪDEFAULT_LOCALADDR
        set_basic_localaddr(DEFAULT_LOCALADDR);
    }
    SetBaseAddr(0,BAIWEI(get_basic_localaddr()));
    SetBaseAddr(1,SHIWEI(get_basic_localaddr()));
    SetBaseAddr(2,GEWEI(get_basic_localaddr()));

}

//����·�Ϸ�
static void detect_circuirt(void)
{
    if(local_addr_value() > MAX_LOOP)
    {
        set_BaseAddr_default();
    }
}
////�������Ϸ�
//void detect_department(void)
//{
//    if(department_val() > DEPART)
//    {
//        set_depart_allzero();
//    }
//}
//ȷ������������ɡ����ڱ���

void set_entry_localaddr_flag(void)
{
    menu_in_setuplocaladdr =1;
}
uint8 get_entry_localaddr_flag(void)
{
    return menu_in_setuplocaladdr;
}
void clr_entry_localaddr_flag(void)
{
    menu_in_setuplocaladdr =0;
}
static void menu_setup_localaddr_ok(void)
{
    set_entry_localaddr_flag();//�������ñ�־
    get_local_addr();
    detect_circuirt();
    Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
               Get_zone_bit(1),Get_zone_bit(2),1,MENU_SAVE_NONE);

}
static void menu_setup_compreg_ok(void)
{
    if(GetCompRegNum()>MAX_COMP)//��������󲿼���
        SetCompRegDep(0);
    CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),0);
    SetComRegFlag();
    //    NVIC_DisableIRQ(EINT3_IRQn);

}
static void menu_setup_setcomp_ok(void)
{//Ĭ��ѡ��ڶ���
    CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),0);

}
static void menu_setup_datetime_ok(void)
{
    PCF8563_DATE    timeAndDate;

    PCF8563_Read(&timeAndDate);
    SetYear(timeAndDate.year);
    SetMonth(timeAndDate.month);
    SetDay(timeAndDate.day);
    SetHour(timeAndDate.hour);
    SetMintue(timeAndDate.minute);
    SetSecond(timeAndDate.second);

    DateMod_Menu(GetYear(),GetMonth(),GetDay(),GetHour(),GetMintue(),GetSecond(),1,MENU_DATA_NONE);

}
////�������ò���
//void menu_setup_save_ok(void)
//{

//    menu_waiting();
//    EndInt();
//    ClrSys_CLpScanCtrl();

//    //    SendDataToFlash();
//    save_basic_info();

//    //    CSendPSNToFlash();
//    //    SaveMaskPSN();
//    save_mask_info();
//    //    CSaveAnn();
//    save_node_and_nodenums();
//    CSaveInfo();

//    StartInt();
//}

//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//�������ƣ�setup_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//�������ܣ�ȷ�ϼ��ĵڶ����һ������
//--------------------------------------------------------------------------------------------------------------------------------
//���������	tmpΪ�ڼ���������ֵ
//--------------------------------------------------------------------------------------------------------------------------------
//���������	null
//--------------------------------------------------------------------------------------------------------------------------------
//˵   ���������µ��Ӳ˵���
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void setup_Sure(uint8 tmp)
{
    
    switch(tmp)
    {
    case 1://��������
        menu_setup_localaddr_ok();
        break;
    case 2://����ע��
        menu_setup_compreg_ok();

        break;
    case 3://���ò���
        menu_setup_setcomp_ok();
        break;
    case 4://����/ ʱ��
        menu_setup_datetime_ok();
        break;
    default:
        break;
    }
}

static uint8 enter_flag=EXIT_MENU;
void set_enter_flag(void)
{
    enter_flag = ENTER_MENU;
}
uint8 get_enter_falg(void)
{
    return enter_flag;
}
void clr_enter_flag(void)
{
    enter_flag = EXIT_MENU;
}




static void query_system_ok(void)
{
    set_enter_flag();
    ClearScreen(0);
    SysCheck_Menu(get_basic_zones(),get_basic_nums(),GetSysCheckDep(),0);

}
void query_compstatus_ok(void)
{

    if(CheckDepComp(GetStatusDep(),GetStatusComp()))
    {
        int8 row = GetRow(GetStatusDep(),GetStatusComp());
        CompStat_Menu(GetStatusDep(),GetStatusComp(),
                      get_comp_devtype(row),
                      0,
                      get_comp_ciraddr(row),GetStatusFlag());
    }else{
        CompStat_Menu(GetStatusDep(),GetStatusComp(),
                      0,
                      0,
                      0,MENU_COMPSTATUS_INVALID);
    }

    ////     CompStat_Menu(GetStatusDep(),GetStatusComp(),get_comp_devtype(row),GetDatatoFlash(row,COM_POS_DEVSTATE),get_comp_ciraddr_zp(GetStatusDep(),GetStatusComp()),GetStatusFlag());
    //   CompStat_Menu(GetStatusDep(),GetStatusComp(),0,0,0,1);
}

static void query_historyrecord_ok(void)
{
    int32 row;
    history_st histinfo;
    //    uint8 num,address,type,alarmtype,part;
    //    PCF8563_DATE TimeAndDate;


    Debug("-->>history record!\n");
    ClearScreen(0);
    ClrHisCountDown();
    ClrHistCount();
    if(0 == GetHistConter())
    {
        menu_nohistory();
        return;
    }
    row=NUM_TOPOS(GetHistConter());
    if(row >= 0)
    {
        get_hist_allinfo(row, &histinfo);
    }

    Debug("part:%d\n",histinfo.part);
    Debug("circleaddr:%d\n",histinfo.circleaddr);
    Debug("devtype:%d\n",histinfo.devtype);
    Debug("attr:%d\n",histinfo.attr);
    Debug("year:%d\n",histinfo.dateyear.year);
    Debug("month:%d\n",histinfo.dateyear.month);
    Debug("day:%d\n",histinfo.dateyear.day);
    Debug("hour:%d\n",histinfo.dateyear.hour);
    Debug("minute:%d\n",histinfo.dateyear.minute);
    Debug("second:%d\n",histinfo.dateyear.second);


    History_Menu(hist_item(row),histinfo.circleaddr,
                 histinfo.devtype,histinfo.attr,
                 histinfo.part,&histinfo.dateyear);//��һ�����������

}


//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//�������ƣ�query_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//�������ܣ�ȷ�ϼ��ĵڶ���ڶ�������
//--------------------------------------------------------------------------------------------------------------------------------
//���������	tmpΪ�ڼ���������ֵ
//--------------------------------------------------------------------------------------------------------------------------------
//���������	null
//--------------------------------------------------------------------------------------------------------------------------------
//˵   ������ѯ���Ӳ˵���
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void query_Sure(uint8 tmp)
{

    switch(tmp)
    {
    case 1://ϵͳ��ѯ
        query_system_ok();
        break;
    case 2://����״̬
        query_compstatus_ok();
        break;
    case 3://��ʷ��¼www
        query_historyrecord_ok();
        break;
    case 4://���ڣ��汾��Ϣ
        about_version_Menu(CSoftVer_A,
                           CSoftVer_B,
                           CSoftVer_C,
                           CSoftVer_D);

    default:
        break;
    }
}

static void selftest_ok(void)
{
    ClearScreen(0);
    UartBindSend(CMD_139W,2);	   //������������
    //������
    Led_ALL_On();
    if((GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FIRE)
            ||(GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FAULT))
    {
    }else{
        SetZjFlag(1);
        PWM1_Start();
        set_PWM1_Started();
    }

    //��ʱ
    DelayMs(15000);
    TestSelf_Menu();

    DelayMs(2000);
    //�Լ�����˳�
    SetGrapCount(3);
    SetCounter1(3);
    SetCounter2(1);
    Return_Task();

    if((GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FIRE)
            ||(GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FAULT))
    {
    }else{
        PWM1_Stop();
        clr_PWM1_Started();
    }


}
static void sigstrength_ok(void)
{
    CompInten_Menu(0,0,0,0);
    CSetIntenFlag(1);
}


//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//�������ƣ�test_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//�������ܣ�ȷ�ϼ��ĵڶ����3������
//--------------------------------------------------------------------------------------------------------------------------------
//���������	tmpΪ�ڼ���������ֵ
//--------------------------------------------------------------------------------------------------------------------------------
//���������	null
//--------------------------------------------------------------------------------------------------------------------------------
//˵   �����������Ӳ˵���
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void test_Sure(uint8 tmp)//
{
    switch(tmp)
    {
    case 1://�Լ�
        selftest_ok();

        break;
    case 2://�����ź�ǿ��
        sigstrength_ok();
        break;
    default:break;
    }
}
void SetSpeaker_ON(void)
{
    vSpeaker_Counter=1;
}
void SetSpeaker_OFF(void)
{
    vSpeaker_Counter=0;
}
//0��off,1:on
uint8 GetSpeaker_Flag(void)
{
    return vSpeaker_Counter;
}
void CLevel27_Sure(void)//�򿪹رշ�����
{

    if(GetSpeaker_Flag())
    {
        menu_Speaker_Open_Close(1);//��
    }
    else
    {
        vSpeaker_Counter=0;
        menu_Speaker_Open_Close(0);//show
    }
}




//����ֵַ
uint16 local_addr_value(void)
{
    return (100*GetBaseAddr(0)+10*GetBaseAddr(1)+GetBaseAddr(2));
}
//uint8 department_val(void)
//{
//    return (100*Get_zone_bit(0)+10*Get_zone_bit(1)+Get_zone_bit(2));
//}

static void menu_set_localaddr_ok(void)
{
    if(local_addr_value() > MAX_LOOP)
    {
        set_BaseAddr_default();
    }
    if(get_basic_localaddr() == local_addr_value())
    {
        Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                   Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_LOCALADDR_NOCHANGE);
        return;
    }


    //֮ǰ��� ���ڱ���
    Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
               Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVING);

    set_basic_localaddr(local_addr_value());
    save_basic_info();
    Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
               Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVE_DONE);

}
// #define HZ_SHOW(A) ((hz[A]<<8)+(hz[A+1]))
//show compoent tips info if not registed
void menu_comp_noreg(void)
{
    uint8 hz[]="����δע��";
    uint8 line = 6;
    DisplayJBHZK(1,line,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,8));

}
void menu_press_ok_complete(uint8 line)
{
    uint8 hz[]="�밴ȷ��ɾ��";

    DisplayJBHZK(1,line,16, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,16, HZ_SHOW(hz,8));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,10));
}
void menu_setup_done(void)
{
    uint8 hz[]="�������";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
}

void menu_press_ok_save(void)
{
    uint8 hz[]="�밴ȷ��������";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0, HZ_SHOW(hz,8));
    DisplayJBHZK(2,line,16,HZ_SHOW(hz,10));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,12));
}
void menu_deling(void)
{
    uint8 hz[]="����ɾ��";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));

}

void menu_opsing(void)
{
    uint8 hz[]="���ڲ���";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));

}
void menu_ops_done(void)
{
    uint8 hz[]="�������";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
}
void menu_comp_masked(void)
{
    uint8 hz[]="����������";
    int line=6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0, HZ_SHOW(hz,8));
}
void menu_comp_started(void)
{
    uint8 hz[]="����������";
    uint8 line=6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0, HZ_SHOW(hz,8));
}

// static void menu_colon(void)
// {
//     Displaynumber(2,0,16,0x0A);
// }
void menu_compset(void)
{
    uint8 hz[]="��������";
    uint8 line = 0;
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,6));
}


static uint8 opstype_deleted(void)
{
    return (GetComSetSelSet()==OPSTYPE_DEL);
}

static history_st setupinfo;

static void setup_menu_deal(void)
{
    int16 row;
    uint8 /*i,*/j=1;
    uint8 delflag=1;


    switch(GetCounter2())
    {
    case 1://��������
        menu_set_localaddr_ok();
        break;
    case 2://����ע��
        //���͵�����
        SetDepCompSum(GetCompRegDep(),GetCompRegNum());//���������Ĳ�������
        SetComRegFlag();//��ȷ�Ϻ��ٴν������ݽ���
        CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),1);

        break;
    case 3://��������
        Debug("component  setup\n");
        row = GetCompSetNum();
        Debug("partnumber:%d\n",row);


        row = GetRow(GetCompSetDep(),GetCompSetNum());//��ȡ�����Ͳ�����
        if(row <0 || 0xff == row){
            Debug("row err!:%d\n",row);
            CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_ERR);
            return;
        }
        Debug("row:%d\n",row);

        if(row > MAX_COMP){
            return;
        }
        /*
        GetComSetSelSet()ǡ����OPSTYPE_START��ֵ���Ӧ
*/
        switch(GetComSetSelSet())
        {
        case OPSTYPE_START:// 		0x 34  ����  CMD_BOOT
            Debug("maskinfo:%d\n",get_mask_info(row));
            if(get_mask_info(row) == OPSTYPE_START)
            {
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_STARTED);
                return;
            }else{
                //�ӵǼǡ���
                SetReg_CNodeInfo(get_comp_ciraddr(row));
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OK_DEL);
                set_mask_info(row,OPSTYPE_START);
            }
            break;

        case OPSTYPE_STOP://0x 33  ����
            if(get_mask_info(row) == OPSTYPE_STOP)
            {
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_STOPED);
                return;
            }else{

                if(!judge_same_ciraddr(row,get_comp_ciraddr(row)))
                {//û��ͬ��·��������Ǽ�
                    ClrReg_CNodeInfo(get_comp_ciraddr(row));
                }
                //                ����ֱ���壬������������һ����·�ϣ�������еĶ������ε���
                //                //��Ǽ�
                //                ClrReg_CNodeInfo(get_comp_ciraddr(row));
                set_mask_info(row,OPSTYPE_STOP);
            }
            break;
        case OPSTYPE_DEL://ɾ��
            Debug("->>preparing to delete component\n");
            while(FIO0PIN&(1 << 10))//ȷ����
            {
                if(j==1)
                {
                    ClearScreen(0);
                    j=0;
                }
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OK_DEL);

                if(!(FIO0PIN&(1 << 25)))//���ؼ�
                {
                    delflag=0;
                    j=1;
                    Debug("delflag :%d\n",delflag);
                    break;
                }
                Debug("delflag :%d\n",delflag);
            }
            if(delflag==1)
            {//��Ǽ�
                if(!judge_same_ciraddr(row,get_comp_ciraddr(row)))
                {//û��ͬ��·��������Ǽ�
                    ClrReg_CNodeInfo(get_comp_ciraddr(row));
                }

                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_DELING);
                Debug("row %d deleted!\n",row);

            }else{
                return;
            }

            break;
            //        case 3://0x 30 ����
            //            SetConvertdata(4,0x30);
            //            SetConvertdata(5,0);
            //            UartBindSend(CMD_CONTROL,9);
            //            break;
            //            // 			case 2://0x 35 ��λ
            //            // 				SetConvertdata(4,0x35);
            //            // 				SetConvertdata(5,0);
            //            // 				UartBindSend(CMD_CONTROL,9);
            //            // 				break;
        default:
            break;
        }
        CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OPSING);


        //�����ʷ��¼
        setupinfo.attr   = GetComSetSelSet();
        setupinfo.inzone = INZONE_DEFAULT;
        setupinfo.part   = row;
        setupinfo.circleaddr = get_comp_ciraddr(row);
        setupinfo.opstype    = INITVAL;
        setupinfo.devtype    = get_comp_devtype(row);
        getcurrent_date(&setupinfo.dateyear);
        set_hist_allinfo(GetHistConter(),&setupinfo);

        Debug("GetHistConter:%d\n",GetHistConter());
        Debug("inzone:%d\n",setupinfo.inzone);
        Debug("part:%d\n",setupinfo.part);
        Debug("ciraddr:%d\n",setupinfo.circleaddr);
        Debug("attr:%d\n",setupinfo.attr);
        Debug("devtype:%d\n",setupinfo.devtype);

        if((1 == delflag)&&opstype_deleted())
        {
            //ɾ��ʱ�����Ϣ����Ҫ������Ϣ
            clr_store_comp_info(row);
            save_comp_info();
        }
        //����Ϊ������Ϣ����ʷ��¼
        save_mask_info();//�����Ǳ���������Ϣ
        save_hist_all();

        CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OPS_DONE);

        break;
    case 4://ʱ��
        PCF8563_Set(&timedate);

        DateMod_Menu(GetYear(),GetMonth(),GetDay(),GetHour(),GetMintue(),GetSecond(),GetSelTime(),MENU_DATA_DONE);

        break;
    case 5://ע��
        // 		row=GetAnnRow(GetAnnDep(),GetAnnCompNum());
        // 		ClearScreen(0);
        // 		Annotate_Menu(GetAnnDep(),GetAnnCompNum(),GetAnnSel());
        break;
    case 6:
        break;
    default:
        break;
    }
}

static void query_menu_deal(void)
{

    switch(GetCounter2())
    {
    case 1:
        if(GetSysCheckDep()>=get_basic_zones())
            SetSysCheckDep(0);
        ClearScreen(0);
        SysCheck_Menu(get_basic_zones(),get_basic_nums(),GetSysCheckDep(),1);

        break;
    case 2:

        //        if(CheckDepComp(GetStatusDep(),GetStatusComp()))
        //        {
        //            int8 row = GetRow(GetStatusDep(),GetStatusComp());
        //            ClearScreen(0);
        //            CompStat_Menu(GetStatusDep(),GetStatusComp(),
        //                          get_comp_devtype(row),
        //                          0,
        //                          get_comp_ciraddr(row),GetStatusFlag());
        //        }
        break;
    case 3:
        break;
    case 4:
        break;

    default:
        break;

    }

}

static void test_menu_deal(void)
{
    switch(GetCounter2())
    {
    case 1:
        break;
    case 2://�ź�ǿ��
        CompInten_Menu(0,0,0,0);
        break;
    case 3:
        break;
    default:
        break;
    }

}

static void speaker_menu_deal(void)
{

}


//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//�������ƣ�setup_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//�������ܣ�ȷ�ϼ��ĵ�3������
//--------------------------------------------------------------------------------------------------------------------------------
//���������	tmpΪ�ڼ���������ֵ
//--------------------------------------------------------------------------------------------------------------------------------
//���������	null
//--------------------------------------------------------------------------------------------------------------------------------
//˵   ����CLevel3_Sure ȷ�ϼ���ִ��
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void CLevel3_Sure(uint8 tmp)//�������ò�
{
    switch(GetCounter1())
    {
    case 1:
        setup_menu_deal();
        break;
    case 2:
        query_menu_deal();
        break;
    case 3:
        test_menu_deal();
        break;
    case 7:
        speaker_menu_deal();
    default:
        break;

    }
}





