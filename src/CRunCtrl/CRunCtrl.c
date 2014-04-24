/*
*********************************************************************************************************
*                                                
*                               对象: CRunCtrl
*                        (c) Copyright 2013-2018, jxm
*                              All Rights Reserved
*                                    Ver1.0
* File : CRunCtrl.C
* By   : jxm
* Date : 2013-8-23
*********************************************************************************************************
*/ 
#define   CRunCtrl_C   
#include  "CRunCtrl.h"  
#include  "CSysRunFlag.h"  
#include  "CTime.h" 
#include  "CTimeDef.h"
#include  "CLED.h" 
#include  "include.h"
#include  "CGpioIrq.h" 
#include  "CTimeCtrl.h"  
#include  "CFlashParam.h"
#include  "CSendToFlash.h"
#include  "CComHandle.h"
#include  "CTaskSure.h"
#include  "CComPara.h"
#include  "key.h"
#include  "store_addr.h"
#include  "CKeyCounter.h"
#include  "CSetCurrent.h"


void hardware_init(void)
{
    GPIOinit();
    InitC_CSysRunFlag();
    Init_CTimeCtrl();
    Init_CGpioIrq();
    init_timer(0,Get_Timer_100us());   //定时器0，回路计数
    init_timer(1,Get_Timer_20ms());    //定时器1，系统运行
    init_timer(2,Get_Timer_20ms());    //定时器2，键盘扫描
    Led_Init();
    UARTInit(0,UART0_BPS);
    UARTInit(1,9600);
    InitLCD();
    I2C0_Init(400000);
    SSP1_Init();
    Led_Init();
    Relay_Init();
    PWM_Init();
    //  PWM1_Set(PWM_CYCLE,PWM_OFFSET);
    PWM1_Set(50000,200);
}
void ctrl_init(void)
{
    Start_Menu();

    init_flash_all();

    UartBindSend(CMD_139W,2);	   //发送心跳命令
    UartBindSend(CMD_139W,2);
    //    MaskPSNInit();
    //    Com0Data_Init();
    //    AlarmInfoInit();
    //    GetHistory();//获取历史记录
    //    CompareCirAddr();
    //初始化回路信息
    Init_CirAddrInfo();;
    CirAlarmDataInit();
    //    AnnCounterInit();
    //    InitHistInfo();


    init_store();////初始化回路信息
}


void  Init_CRunCtrl(void)
{   
    hardware_init();//hardware init
    ctrl_init();/*    task iniet list*/
}

void  Reset_CRunCtrl(void)
{   
    InitC_CSysRunFlag();
    Init_CTimeCtrl();
    Led_Init();
}  
void deal_lcd(void)
{
    if(vGetScreenMask()>3000)
    {
        OffLcd();
    }
}
void deal_speaker(void)
{
    //非自检且打开时
    if(GetSpeaker_Flag()&&!GetZjFlag())
        CSpeakerPWM();
}
void deal_all_led(void)
{
    if(!GetZjFlag())
        RunLed_CRunCtrl();
}
//测试消音功能
void pwm1_test_start_stop()
{
    static uint8 startflag = 1;
    if(startflag)
    {
        PWM1_Start();
        set_PWM1_Started();
        startflag = 0;
    }
}
//检测是否在线
void detect_online(void)
{
    uint8 i;
    for(i =COMP_START;i<=MAX_COMP;i++)
    {
        if(get_comp_partnumber(i) != INITVAL)
            judge_3h_over(i);
    }
}

void   do_CRunCtrl(void)
{   
//        pwm1_test_start_stop();
#if 1
    //    if(GetReset_CSysRunFlag())
    //    {
    //        Reset_CRunCtrl();
    //        return;
    //    }
    //    if(Get1m_CSysRunFlag())
    //    {
    //        Clr1m_CSysRunFlag();

    //        return;
    //    }

    if(Get5s_CSysRunFlag())
    {
        Clr5s_CSysRunFlag();

        SendHeart();
        detect_online();
        return;
    }
    if(Get1s_CSysRunFlag())
    {
        Clr1s_CSysRunFlag();

        deal_all_led();
        HandleNote();
        show_head_menu();//显示首页
        inqury_state__byuart0();

        return;
    }
    if(Get100ms_CSysRunFlag())
    {
        Clr100ms_CSysRunFlag();


        //显示页面
        DisplayKeyMenu();
        Clr_Alarm(); //reset for alarm


        //        无线发送与接收，串口1
        HandleInfo_Uart1();

        return;
    }

    if(Get40ms_CSysRunFlag())
    {
        Clr40ms_CSysRunFlag();
//        state_loopld_printf();

        //无线发送与接收，串口1
        //        HandleInfo_Uart1();

        //         info_loopldbuf();


        return;
    }

    if(Get20ms_CSysRunFlag())
    {
        Clr20ms_CSysRunFlag();

        deal_lcd();

        //        Scan_Key();//循环扫描，非定时器来扫描


        deal_speaker();

        return;
    }
#else
    //    if(GetReset_CSysRunFlag())
    //    {
    //        Reset_CRunCtrl();
    //        return;
    //    }
    //    if(Get1m_CSysRunFlag())
    //    {
    //        Clr1m_CSysRunFlag();

    //        return;
    //    }
    //    if(Get5s_CSysRunFlag())
    //    {
    //        Clr5s_CSysRunFlag();
    //        SendHeart();
    //        return;
    //    }

    //    if(Get1s_CSysRunFlag())
    //    {
    //        Clr1s_CSysRunFlag();
    //        if(!GetZjFlag())
    //            RunLed_CRunCtrl();
    //        HandleAnnFun();


    //        show_head_menu();//显示首页
    //        return;
    //    }
    //    if(Get100ms_CSysRunFlag())
    //    {
    //        Clr100ms_CSysRunFlag();
    //        DisplayKeyMenu();

    //        inqury_state__byuart0();
    //        Clr_Alarm();

    //        if(GetZjFlag())
    //            zijian_speaker();

    //        return;
    //    }

    //    if(Get40ms_CSysRunFlag())
    //    {
    //        Clr40ms_CSysRunFlag();
    //        HandleInfo_Uart1();//串口信息处理
    //        return;
    //    }

    //    if(Get20ms_CSysRunFlag())
    //    {
    //        Clr20ms_CSysRunFlag();

    //        if(vGetScreenMask()>3000)
    //        {
    //            ShutdownLcd();
    //        }
    //        return;
    //    }
#endif
}


void  RunLed_CRunCtrl(void)
{
    vRunLedCount++;
    vRunLedCount&=0x7f;
    if(vRunLedCount&1)
    {
        Led_Run_On();
        if(GetMenuFlag() != MENU_WIRELESS_FAULT)
            Led_Wireless_Off();
    }
    else
    {
        Led_Run_Off();
        if(GetMenuFlag() != MENU_WIRELESS_FAULT)
            Led_Wireless_On();
    }
}

void zijian_speaker(void)
{

}




