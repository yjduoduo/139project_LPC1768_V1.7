/*
;*********************************************************************************************************
;*                                                
;*                            对象: CTaskReturn
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskReturn.c
;* By   : 尹海星
;* 时间 : 2013-06-28
;*********************************************************************************************************
;*/


#include  "include.h"
#include  "CTaskReturn.h"
#include  "CGetGrap.h"
#include  "tasklist.h"
#include  "CKeyCounter.h"
#include "CLED.h"
#include  "CTaskDown.h"
#include  "CTaskSure.h"
#include  "CComPara.h"
void CLevel1_Return(void)
{
    //switch(vCounter[0])
    switch(GetCounter1())
    {
    case 1:
        clr_enter_flag();

        Main_Menu(1);
        NVIC_EnableIRQ(EINT3_IRQn);//中断使能
        NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //中断优先级
        Clr_Note_Flag();
        break;
    case 2:

        Main_Menu(2);
        break;
    case 3:

        Main_Menu(3);
        break;
    case 4:

        Main_Menu(4);
        break;
    case 5:

        Main_Menu(5);
        break;
    case 6:

        Main_Menu(6);
        break;
    default:break;
    }
    SetCounter2(1);//vCounter[1] = 1;
}
void CLevel21_Return(void)
{
    switch(GetCounter2())
    {
    case 1:
        Set_Menu(1);
        SetLocalParaSel(1);//光标位置参数
        break;
    case 2:
        Set_Menu(2);
        SetCompRegParaSel(2);
        ClrComRegFlag();

        // 			NVIC_EnableIRQ(EINT3_IRQn);//中断使能
        // 			NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //中断优先级
        break;
    case 3:
        Set_Menu(3);
        SetComSet_seltab(2);
        break;
    case 4:
        Set_Menu(4);
        SetSelTime(1);
        break;
//    case 5:
//
//        Set_Menu(5);
//        break;
    default:break;
    }
    SetCounter3(1);
}
void CLevel22_Return(void)
{
    switch(GetCounter2())
    {
    case 1:
        ClearScreen(0);
        Check_Menu(1);
        break;
    case 2:
        ClearScreen(0);
        Check_Menu(2);
        ClrHisCountDown();
        ClrHistCount();
        break;
    case 3:
        ClearScreen(0);
        Check_Menu(3);
        break;
    default:break;
    }
    SetCounter3(1);
}
void CLevel23_Return(void)
{
    switch(GetCounter2())
    {
    case 1://自检 返回 检测蜂鸣器标志是否已经打开 ，如果已经打开，则开启
        Led_Off();
        //            SetAlarmFlag(0,0);//0标志在定时器0中自检时，会停止的。


        SetZjFlag(0);//中断里打开喇叭响检测
        PWM1_Stop();
        clr_PWM1_Started();

        Test_Menu(1);

        break;
    case 2:
        CSetIntenFlag(0);
        Test_Menu(2);
        break;
    default:break;
    }
    SetCounter3(1);
}
void CLevel3_Return(void)
{
    switch(GetCounter3())
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        ClrHisCountDown();
        break;
    case 4:
        break;
    default:break;
    }
    SetCounter3(1);
}
