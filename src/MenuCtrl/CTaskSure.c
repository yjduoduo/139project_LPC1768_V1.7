/*
;*********************************************************************************************************
;*                                                
;*                            对象: CTaskSure
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskSure.c
;* By   : 尹海星
;* 时间 : 2013-06-28
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


//数据量变为实际存储位置，相关1
#define NUM_TOPOS(A) (A-1)



static uint8 menu_in_setuplocaladdr =0 ;

extern tFlashinfoDef  FlashInfo;
PCF8563_DATE    timedate;
extern uint8 vMaskPSN[MASKSUM];
volatile static uint8 vMaskCount=0;
volatile static uint8 vmaskflag = 0;
static uint8 vAnnUartFlag=0;//汉字注释标志
static uint8 vZjFlag=0;//自检标志
static uint8 vSpeaker_Counter=1; //默认蜂鸣器开
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
//    //    存储屏蔽序号;;(0x20000);
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
////1表示屏蔽，其他为启用
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
    Eint_Dis();//清中断
    ClrSys_CLpScanCtrl();//清回路标志

    ClearScreen(0);

    UartBindSend(CMD_139W,2);	   //发送心跳命令
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
//[n]复位时默认为第一个界面
    SetMenuFlag(MENU_MAIN);
    SetCounter1(1);
    SetCounter1(1);


    SetDisplay_alarm_flag(PAGE_AT_NORMAL);
    //清报警回路
    clr_alarm_allinfo();

    clr_PWM1_Started();
    PWM1_Stop();
    BEEPOff();


    //清计数
    clr_weixialasignal();
    clr_xialasignal();

    //清离线检测
    reset_timer1_3h_counter();

    Menu_complete();
    Eint_En();//开中断
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
        if(!KEY_RETURN)//返回键
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
    while(KEY_OK)//低电平，一直为低
    {
        if(!KEY_RETURN)//返回键
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

        //清回路信息
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

        StartInt();//开中断


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
//函数名称：CLevel1_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//函数功能：确认键的第一层任务
//--------------------------------------------------------------------------------------------------------------------------------
//输入参数：	tmp为第几个按键的值
//--------------------------------------------------------------------------------------------------------------------------------
//输出参数：	null
//--------------------------------------------------------------------------------------------------------------------------------
//说   明：第一层菜单ok按键后执行任务
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void CLevel1_Sure(uint8 tmp)//第一层任务
{

    switch(tmp)
    {
    case 1://设置
        setup_ok();

        break;
    case 2://查询
        query_ok();

        break;
    case 3://测试
        test_ok();

        break;

    case 4://恢复出厂设置
        factory_ok();


        break;

    case 5://设置蜂鸣器
        speaker_ok();
        break;
    case 6://复位
        reset_ok();

        break;
    default:
        break;
    }
}
static void get_local_addr(void)
{
    if(0xff == get_basic_localaddr()){//如果已经被清除了，默认值为DEFAULT_LOCALADDR
        set_basic_localaddr(DEFAULT_LOCALADDR);
    }
    SetBaseAddr(0,BAIWEI(get_basic_localaddr()));
    SetBaseAddr(1,SHIWEI(get_basic_localaddr()));
    SetBaseAddr(2,GEWEI(get_basic_localaddr()));

}

//检测回路合法
static void detect_circuirt(void)
{
    if(local_addr_value() > MAX_LOOP)
    {
        set_BaseAddr_default();
    }
}
////检测防区合法
//void detect_department(void)
//{
//    if(department_val() > DEPART)
//    {
//        set_depart_allzero();
//    }
//}
//确定键：保存完成、正在保存

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
    set_entry_localaddr_flag();//进入设置标志
    get_local_addr();
    detect_circuirt();
    Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
               Get_zone_bit(1),Get_zone_bit(2),1,MENU_SAVE_NONE);

}
static void menu_setup_compreg_ok(void)
{
    if(GetCompRegNum()>MAX_COMP)//单防区最大部件数
        SetCompRegDep(0);
    CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),0);
    SetComRegFlag();
    //    NVIC_DisableIRQ(EINT3_IRQn);

}
static void menu_setup_setcomp_ok(void)
{//默认选择第二项
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
////保存设置操作
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
//函数名称：setup_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//函数功能：确认键的第二层第一个任务
//--------------------------------------------------------------------------------------------------------------------------------
//输入参数：	tmp为第几个按键的值
//--------------------------------------------------------------------------------------------------------------------------------
//输出参数：	null
//--------------------------------------------------------------------------------------------------------------------------------
//说   明：设置下的子菜单项
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void setup_Sure(uint8 tmp)
{
    
    switch(tmp)
    {
    case 1://本机设置
        menu_setup_localaddr_ok();
        break;
    case 2://部件注册
        menu_setup_compreg_ok();

        break;
    case 3://设置部件
        menu_setup_setcomp_ok();
        break;
    case 4://日期/ 时间
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
                 histinfo.part,&histinfo.dateyear);//第一个报警的序号

}


//################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------
//函数名称：query_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//函数功能：确认键的第二层第二个任务
//--------------------------------------------------------------------------------------------------------------------------------
//输入参数：	tmp为第几个按键的值
//--------------------------------------------------------------------------------------------------------------------------------
//输出参数：	null
//--------------------------------------------------------------------------------------------------------------------------------
//说   明：查询下子菜单项
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void query_Sure(uint8 tmp)
{

    switch(tmp)
    {
    case 1://系统查询
        query_system_ok();
        break;
    case 2://部件状态
        query_compstatus_ok();
        break;
    case 3://历史记录www
        query_historyrecord_ok();
        break;
    case 4://关于：版本信息
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
    UartBindSend(CMD_139W,2);	   //发送心跳命令
    //加声光
    Led_ALL_On();
    if((GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FIRE)
            ||(GetAlarmFlag(POS_ALARM_BIT) ==ALARM_FAULT))
    {
    }else{
        SetZjFlag(1);
        PWM1_Start();
        set_PWM1_Started();
    }

    //延时
    DelayMs(15000);
    TestSelf_Menu();

    DelayMs(2000);
    //自检完成退出
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
//函数名称：test_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//函数功能：确认键的第二层第3个任务
//--------------------------------------------------------------------------------------------------------------------------------
//输入参数：	tmp为第几个按键的值
//--------------------------------------------------------------------------------------------------------------------------------
//输出参数：	null
//--------------------------------------------------------------------------------------------------------------------------------
//说   明：测试下子菜单项
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void test_Sure(uint8 tmp)//
{
    switch(tmp)
    {
    case 1://自检
        selftest_ok();

        break;
    case 2://部件信号强度
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
//0：off,1:on
uint8 GetSpeaker_Flag(void)
{
    return vSpeaker_Counter;
}
void CLevel27_Sure(void)//打开关闭蜂鸣器
{

    if(GetSpeaker_Flag())
    {
        menu_Speaker_Open_Close(1);//开
    }
    else
    {
        vSpeaker_Counter=0;
        menu_Speaker_Open_Close(0);//show
    }
}




//基地址值
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


    //之前添加 正在保存
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
    uint8 hz[]="部件未注册";
    uint8 line = 6;
    DisplayJBHZK(1,line,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,8));

}
void menu_press_ok_complete(uint8 line)
{
    uint8 hz[]="请按确定删除";

    DisplayJBHZK(1,line,16, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,16, HZ_SHOW(hz,8));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,10));
}
void menu_setup_done(void)
{
    uint8 hz[]="设置完成";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
}

void menu_press_ok_save(void)
{
    uint8 hz[]="请按确定键保存";
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
    uint8 hz[]="正在删除";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));

}

void menu_opsing(void)
{
    uint8 hz[]="正在操作";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));

}
void menu_ops_done(void)
{
    uint8 hz[]="操作完成";
    uint8 line = 6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
}
void menu_comp_masked(void)
{
    uint8 hz[]="部件已屏蔽";
    int line=6;
    DisplayJBHZK(1,line,0, HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0, HZ_SHOW(hz,8));
}
void menu_comp_started(void)
{
    uint8 hz[]="部件已启用";
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
    uint8 hz[]="部件设置";
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
    case 1://本机设置
        menu_set_localaddr_ok();
        break;
    case 2://部件注册
        //发送到部件
        SetDepCompSum(GetCompRegDep(),GetCompRegNum());//单个防区的部件总数
        SetComRegFlag();//按确认后，再次进行数据接收
        CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),1);

        break;
    case 3://部件设置
        Debug("component  setup\n");
        row = GetCompSetNum();
        Debug("partnumber:%d\n",row);


        row = GetRow(GetCompSetDep(),GetCompSetNum());//获取防区和部件号
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
        GetComSetSelSet()恰好与OPSTYPE_START的值相呼应
*/
        switch(GetComSetSelSet())
        {
        case OPSTYPE_START:// 		0x 34  启用  CMD_BOOT
            Debug("maskinfo:%d\n",get_mask_info(row));
            if(get_mask_info(row) == OPSTYPE_START)
            {
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_STARTED);
                return;
            }else{
                //加登记——
                SetReg_CNodeInfo(get_comp_ciraddr(row));
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OK_DEL);
                set_mask_info(row,OPSTYPE_START);
            }
            break;

        case OPSTYPE_STOP://0x 33  屏蔽
            if(get_mask_info(row) == OPSTYPE_STOP)
            {
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_STOPED);
                return;
            }else{

                if(!judge_same_ciraddr(row,get_comp_ciraddr(row)))
                {//没有同回路部件，清登记
                    ClrReg_CNodeInfo(get_comp_ciraddr(row));
                }
                //                不能直接清，如果多个部件在一个回路上，造成所有的都被屏蔽掉了
                //                //清登记
                //                ClrReg_CNodeInfo(get_comp_ciraddr(row));
                set_mask_info(row,OPSTYPE_STOP);
            }
            break;
        case OPSTYPE_DEL://删除
            Debug("->>preparing to delete component\n");
            while(FIO0PIN&(1 << 10))//确定键
            {
                if(j==1)
                {
                    ClearScreen(0);
                    j=0;
                }
                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OK_DEL);

                if(!(FIO0PIN&(1 << 25)))//返回键
                {
                    delflag=0;
                    j=1;
                    Debug("delflag :%d\n",delflag);
                    break;
                }
                Debug("delflag :%d\n",delflag);
            }
            if(delflag==1)
            {//清登记
                if(!judge_same_ciraddr(row,get_comp_ciraddr(row)))
                {//没有同回路部件，清登记
                    ClrReg_CNodeInfo(get_comp_ciraddr(row));
                }

                CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_DELING);
                Debug("row %d deleted!\n",row);

            }else{
                return;
            }

            break;
            //        case 3://0x 30 消音
            //            SetConvertdata(4,0x30);
            //            SetConvertdata(5,0);
            //            UartBindSend(CMD_CONTROL,9);
            //            break;
            //            // 			case 2://0x 35 复位
            //            // 				SetConvertdata(4,0x35);
            //            // 				SetConvertdata(5,0);
            //            // 				UartBindSend(CMD_CONTROL,9);
            //            // 				break;
        default:
            break;
        }
        CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OPSING);


        //添加历史记录
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
            //删除时清空信息，需要保存信息
            clr_store_comp_info(row);
            save_comp_info();
        }
        //其它为屏蔽信息和历史记录
        save_mask_info();//别忘记保存屏蔽信息
        save_hist_all();

        CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_OPS_DONE);

        break;
    case 4://时间
        PCF8563_Set(&timedate);

        DateMod_Menu(GetYear(),GetMonth(),GetDay(),GetHour(),GetMintue(),GetSecond(),GetSelTime(),MENU_DATA_DONE);

        break;
    case 5://注释
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
    case 2://信号强度
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
//函数名称：setup_Sure()
//--------------------------------------------------------------------------------------------------------------------------------
//函数功能：确认键的第3层任务
//--------------------------------------------------------------------------------------------------------------------------------
//输入参数：	tmp为第几个按键的值
//--------------------------------------------------------------------------------------------------------------------------------
//输出参数：	null
//--------------------------------------------------------------------------------------------------------------------------------
//说   明：CLevel3_Sure 确认键后执行
//--------------------------------------------------------------------------------------------------------------------------------
//################################################################################################################################
void CLevel3_Sure(uint8 tmp)//具体设置层
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





