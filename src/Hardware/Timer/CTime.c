/*
*********************************************************************************************************
*                                                
*                              对象:	CTime0
*
*                        (c) Copyright 2000-2006, jxm
*                              All Rights Reserved
*                                    Ver1.5
* File : CTime0.C
* By   : jxm
*********************************************************************************************************
*/
#define    CTime_C	  
#include  "CTime.h" 
#include  "LPC17xx.H" 
#include  "CTimeDef.h"
#include "include.h"
#include  "key.h"
#include  "CAddressCount.h"
#include  "runfunction.h"
#include "CLED.h"
#include  "CComPara.h"
#include  "CTaskSure.h"
#include "SysCtrl.h"
#include "CSetCurrent.h"
#include  "CTimeCtrl.h"

void timern_enable(uint8 timern)
{
    switch(timern)
    {
    case 0://timer 0
        NVIC_EnableIRQ(TIMER0_IRQn);
        NVIC_SetPriority(TIMER0_IRQn, PRIO_TWO); //中断优先级
        break;
    case 1://timer 1
        NVIC_EnableIRQ(TIMER1_IRQn);
        NVIC_SetPriority(TIMER1_IRQn, PRIO_SIX); //中断优先级
        break;
    case 2://timer 2
        NVIC_EnableIRQ(TIMER2_IRQn);
        NVIC_SetPriority(TIMER2_IRQn, PRIO_NINE); //中断优先级
        break;
    case 3://timer 3
        NVIC_EnableIRQ(TIMER3_IRQn);
        NVIC_SetPriority(TIMER3_IRQn, PRIO_TEN); //中断优先级
        break;
    default:
        break;
    }
}

void timern_disable(uint8 timern)
{
    switch(timern)
    {
    case 0:
        NVIC_DisableIRQ(TIMER0_IRQn);
        break;
    case 1:
        NVIC_DisableIRQ(TIMER1_IRQn);
        break;
    case 2:
        NVIC_DisableIRQ(TIMER2_IRQn);
        break;
    case 3:
        NVIC_DisableIRQ(TIMER3_IRQn);
        break;
    default:
        break;
    }
}


void init_timer(uint8 timer_num, uint32 TimerInterval)  
{
    if ( timer_num == 0 )
    {
        PCONP |= (0x01<<1);
        T0CTCR = 0x00;
        T0TCR  = 0x02;
        T0IR   = 1;
        T0TC   = 0;
        T0PR   = 0;
        T0MR0 = TimerInterval;//cTime0V_2ms;	//100us
        T0MCR = 3;				/* Interrupt and Reset on MR0 */
        T0TCR = 1;
        timern_enable(0);

    }
    if ( timer_num == 1 )
    {
        PCONP |= (0x1<<2);
        T1CTCR = 0x00;
        T1TCR  = 0x02;
        T1IR   = 1;
        T1TC   = 0;
        T1PR   = 0;
        T1MR0 = TimerInterval;//SystemFrequency/40000;//100us
        T1MCR = 3;				/* Interrupt and Reset on MR0 */

        timern_enable(1);
        T1TCR = 1;
    }
    if ( timer_num == 2 )
    {
        PCONP |= (0x1<<22);
        T2CTCR = 0x00;
        T2TCR  = 0x02;
        T2IR   = 1;
        T2TC   = 0;
        T2PR   = 0;
        T2MR0 = TimerInterval;//cTime0V_2ms;	//100us
        T2MCR = 3;				/* Interrupt and Reset on MR0 */
        timern_enable(2);
        T2TCR = 1;
    }
    if ( timer_num == 3 )
    {
        PCONP |= (0x1<<23);
        T3CTCR = 0x00;
        T3TCR  = 0x02;
        T3IR   = 1;
        T3TC   = 0;
        T3PR   = 0;
        T3MR0 = TimerInterval;//cTime0V_2ms;	//100us
        T3MCR = 3;				/* Interrupt and Reset on MR0 */
        timern_enable(3);
        T3TCR = 1;
    }
}

//time tick counter
void SetTimeTickCounter(uint8 tmp)
{
    vTimeTickCounter =tmp;
}
void AddTimeTickCounter(void)
{
    vTimeTickCounter++;
}
uint8 GetTimeTickCounter(void)
{
    return vTimeTickCounter;
}
//heart tick
void SetHeartTick(uint32 tmp)
{
    vHeartTick = tmp;
}
void AddHeartTick(void)
{
    vHeartTick++;
}
uint32 GetHeartTick(void)
{
    return vHeartTick;
}
//speaker tick
void AddSpeakerTick(void)
{
    vSpeakerTick++;
}
void SetSpeakerTick(uint16 tmp)
{
    vSpeakerTick=tmp;
}
uint16 GetSpeakerTick(void)
{
    return vSpeakerTick;
}


//static uint8_t syncorder=0;
// static uint8_t synconce=0;
//T0::定时100us，计数,回路火警，上位机查询信息回复，运行灯指示，
//100us中断
//回路处理的优先级最高，因此，处理期间，其它内容不作处理，关其它中断
void  TIMER0_IRQHandler (void)
{
    Eint_Dis();
    T0Int_CTimeCtrl();
    T0IR = 1;
    Eint_En();
}




//T1::lcd关屏、PWM1
//定时20ms
void  TIMER1_IRQHandler (void)
{
    Eint_Dis();
    T1Int_CTimeCtrl();
    T1IR   = 0x0f;
    Eint_En();
}


void  TIMER2_IRQHandler (void)
{
    Scan_Key();
    T2IR   = 0x0f;
}
void vAddLedFlag(void)
{
    vLedFlag++;
}
void vClrLedFlag(void)
{
    vLedFlag=0;
}
uint32 vGetLedFlag(void)
{
    return vLedFlag;
}

void vAddScreenMask(void)
{
    vScreenMaskFlag++;
}
uint32 vGetScreenMask(void)
{
    return vScreenMaskFlag;
}
void vClrScreenMask(void)
{
    vScreenMaskFlag=0;
}
void OffLcd(void)
{
    if(FIO0PIN&0x66000c00)
    {
        FIO2CLR |= (1<<9); //关显示
        vClrScreenMask();
    }
}

void OnLCD(void)
{
    FIO2SET |= (1<<9); //开显示
    vScreenMaskFlag=0;
}
/******************************************************************************
** Function name:		enable_timer
**
** Descriptions:		Enable timer
**
** parameters:			timer number: 0 or 1 or 2 or 3
** Returned value:		None
** 
******************************************************************************/
void enable_timer( uint8 timer_num )
{
    if ( timer_num == 0 )
    {
        T0TCR = 1;
    }
    else if ( timer_num == 1 )
    {
        T1TCR = 1;
    }
    else if ( timer_num == 2 )
    {
        T2TCR = 1;
    }
    else if ( timer_num == 3 )
    {
        T3TCR = 1;
    }
    return;
}

/******************************************************************************
** Function name:		disable_timer
**
** Descriptions:		Disable timer
**
** parameters:			timer number: 0 or 1 oe 2 or 3
** Returned value:		None
** 
******************************************************************************/
void disable_timer( uint8 timer_num )
{
    if ( timer_num == 0 )
    {
        T0TCR = 0;
    }
    else if ( timer_num == 1 )
    {
        T1TCR = 0;
    }
    else if ( timer_num == 2 )
    {
        T2TCR = 0;
    }
    else if ( timer_num == 3 )
    {
        T3TCR = 0;
    }
    return;
}

/******************************************************************************
** Function name:		reset_timer
**
** Descriptions:		Reset timer
**
** parameters:			timer number: 0 or 1 or 2 or 3
** Returned value:		None
** 
******************************************************************************/
void reset_timer( uint8 timer_num )
{
    uint32 regVal;

    if ( timer_num == 0 )
    {
        regVal = T0TCR;
        regVal |= 0x02;
        T0TCR = regVal;
    }
    else if ( timer_num == 1 )
    {
        regVal = T1TCR;
        regVal |= 0x02;
        T1TCR = regVal;
    }
    else if ( timer_num == 2 )
    {
        regVal = T2TCR;
        regVal |= 0x02;
        T2TCR = regVal;
    }
    else if ( timer_num == 3 )
    {
        regVal = T3TCR;
        regVal |= 0x02;
        T3TCR = regVal;
    }
    return;
}
//led灯显示，无线和运行灯
void CLedShow(void)
{
    if(vGetLedFlag()==50)
    {
        Led_Wireless_On();
    }
    else if(vGetLedFlag()==100)
    {
        Led_Wireless_Off();
        vClrLedFlag();
    }
}
void CSpeakerPWM(void)
{
//    不在此处理 蜂鸣器

//    if(GetAlarmFlag(POS_ALARM_BIT)== ALARM_FIRE)//1代表什么报警类型
//    {
//        PWM1_Start();
//    }
//    else if(GetAlarmFlag(POS_ALARM_BIT)== ALARM_BAT_LOW)
//    {
//        PWM1_Start();
//    }
//    else if(GetAlarmFlag(POS_ALARM_BIT)== ALARM_FAULT)
//    {
//        PWM1_Start();
//    }
//    else
//    {
//        PWM1_Stop();
//    }
}



////定时器3中断处理函数
//void TIMER3_IRQHandler()
//{
//    AddTimer3Counter();//同步计数

////    if(GetSyncFlag()){//同步开始计数
////        AddSyncTime();//记录同步周期
////        if(0 == synconce){//记录同步开始数
////            SetStartSyncms(GetStoreOrder(),GetTimer3Counter());
////            synconce++;
////            AddStoreSyncOrder();
////        }
////    }else{
////        SetSyncTime(0);
////        synconce=0;
////    }

////    if(getstartsync())
////        CirAddrCounter();


//    T3IR   = 0x0f;
//}


//void   Init_CTime0(void)
//{
//	PCONP |= (0x01<<1);
//	T0CTCR = 0x00;
//	T0TCR  = 0x02;
//	T0IR   = 0x0f;
//	T0TC   = 0;
//	T0PR   = 0;
//	T0MR0 = SystemFrequency/40000;//100us
//	T0MCR = 3;				/* Interrupt and Reset on MR0 */
//	NVIC_EnableIRQ(TIMER0_IRQn);
//	NVIC_SetPriority(TIMER0_IRQn, PRIO_TWO); //中断优先级
//  T0TCR = 1;
//}
//void   Init_CTime1(void)
//{
//	PCONP |= (0x1<<2);
//	T1CTCR = 0x00;
//	T1TCR  = 0x02;
//	T1IR   = 0x0f;
//	T1TC   = 0;
//	T1PR   = 0;
//	T1MR0 = 200*(SystemFrequency/40000);//20ms
//	T1MCR = 3;				/* Interrupt and Reset on MR0 */

//	NVIC_EnableIRQ(TIMER1_IRQn);
//	NVIC_SetPriority(TIMER1_IRQn, PRIO_SIX); //中断优先级
//	T1TCR = 1;
//}

// #define cTime0Test
#ifdef cTime0Test
uint8 vTime0Test;
#endif


//static uint8 ledonflag=0;
//void LedOn_Off(void)//for test
//{
//    if(ledonflag%2)
//        Led_On();
//    else
//        Led_Off();
//    ledonflag++;
//}
