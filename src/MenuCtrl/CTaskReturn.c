/*
;*********************************************************************************************************
;*                                                
;*                            ����: CTaskReturn
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskReturn.c
;* By   : ������
;* ʱ�� : 2013-06-28
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
        NVIC_EnableIRQ(EINT3_IRQn);//�ж�ʹ��
        NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //�ж����ȼ�
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
        SetLocalParaSel(1);//���λ�ò���
        break;
    case 2:
        Set_Menu(2);
        SetCompRegParaSel(2);
        ClrComRegFlag();

        // 			NVIC_EnableIRQ(EINT3_IRQn);//�ж�ʹ��
        // 			NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //�ж����ȼ�
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
    case 1://�Լ� ���� ����������־�Ƿ��Ѿ��� ������Ѿ��򿪣�����
        Led_Off();
        //            SetAlarmFlag(0,0);//0��־�ڶ�ʱ��0���Լ�ʱ����ֹͣ�ġ�


        SetZjFlag(0);//�ж������������
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
