/*
;*********************************************************************************************************
;*                                                
;*                            对象: extint
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : extint.c
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CAddressCount.h"
#include  "CTimeDef.h"
#include  "CSetCurrent.h"
#include  "CFlashParam.h"

#include  "CLpCkCtrl.h"


uint8 Extint1_flag=0;
uint8 Extint3_flag=0;

volatile uint32_t fallingcount=0;
volatile uint32_t vriseingcount=0;

void extint3_enable(void)
{
    NVIC_EnableIRQ(EINT3_IRQn);//中断使能
    NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //中断优先级
}
void extint3_disable(void)
{
    NVIC_DisableIRQ(EINT3_IRQn);
}


/*********************************************************************************************************
** Function name:       Eint3_Init
** Descriptions:        外部中断3初始化，上升沿触发 
** input parameters:    无
** Output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void Eint3_Init(void)
{    
    //回路
    //    PINSEL1 &=~(0x03<<14);//p0.23选择为GPIO
    //    FIO0DIR  &= (~ (0x01<<23)) ;  // P0.23方向为输入
    PINSEL1 &=~(0x03<<16);//p0.24选择为GPIO
    FIO0DIR  &= (~ (0x01<<24)) ;  // P0.24方向为输入

    IO0IntEnR |=  (0x01<<24);    //上升沿中断P0.24
    //     IO0IntEnF |=  (0x01<<24);    //下降沿中断P0.24
    //    IO0IntEnF |=  (0x01<<23);    //下降沿中断P0.23

    extint3_enable();
}


void Eint_Dis(void)
{
    uart_all_disable();
    extint3_disable();
    timern_disable(0);
    timern_disable(1);
    timern_disable(2);
    i2c0_disable();
    IO0IntClr = 0xffff;
    pwm1_disable();

}



void Eint_En(void)
{
    uart_all_enable();
    extint3_enable();
    timern_enable(0);
    timern_enable(1);
    timern_enable(2);
    i2c0_enable();
    IO0IntEnR =  (0x01<<24);    //上升沿中断P0.24
    IO0IntEnF =  (0x01<<24);    //同时下降沿
    pwm1_enable();
}


void Eint_DisAll_Exuart(void)
{
    extint3_disable();
    timern_disable(0);
    timern_disable(1);
    timern_disable(2);
    i2c0_disable();
    IO0IntClr = 0xffff;
    pwm1_disable();

}



void Eint_EnAll_Exuart(void)
{
    extint3_enable();
    timern_enable(0);
    timern_enable(1);
    timern_enable(2);
    i2c0_enable();
    IO0IntEnR =  (0x01<<24);    //上升沿中断P0.24
    IO0IntEnF =  (0x01<<24);    //同时下降沿
    pwm1_enable();
}


/*********************************************************************************************************
** Function name:       SetE1_flag，ClrE1_flag，GetE1_flag
** Descriptions:        外部中断1标志位函数
** input parameters:    无
** Output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void SetE1_flag(void)
{
    Extint1_flag   = 1;
}
void ClrE1_flag(void)
{
    Extint1_flag   = 0;
}
uint8 GetE1_flag(void)
{
    return Extint1_flag;
}
void SetE3_flag(void)
{
    Extint3_flag   = 1;
}
void ClrE3_flag(void)
{
    Extint3_flag   = 0;
}
uint8 GetE3_flag(void)
{
    return Extint3_flag;
}
/*********************************************************************************************************
** Function name:       cExt3IntFlow，cExt3IntRise
** Descriptions:        外部中断3边沿切换函数
** input parameters:    无
** Output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void cExt3IntFlow(void)
{
    IO0IntEnF = (0x01<<24);    //下降沿中断P0.24
}
void cExt3IntRise(void)
{
    IO0IntEnR = (0x01<<24);    //上升沿中断P0.24
}
/*********************************************************************************************************
** Function name:       cExt3IntClrFlow，cExt3IntClrRise
** Descriptions:        外部中断3清中断函数
** input parameters:    无
** Output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void cExt3IntClrFlow(void)
{
    IO0IntClr |= IO0IntStatF;
}
void cExt3IntClrRise(void)
{
    IO0IntClr |= IO0IntStatR;
}


void extint1_enable(void)
{
    NVIC_EnableIRQ(EINT1_IRQn);//中断使能
    NVIC_SetPriority(EINT1_IRQn, PRIO_FIVE); //中断优先级
}
void extint1_disable(void)
{
    NVIC_DisableIRQ(EINT1_IRQn);
}

///*********************************************************************************************************
//** Function name:       Eint1_Init
//** Descriptions:        外部中断1初始化，下降沿触发
//** input parameters:    无
//** Output parameters:   无
//** Returned value:      无
//中断1用来对RTC_INT
//*********************************************************************************************************/
//void  Eint1_Init(void)
//{
//    PINSEL4 |= (1 << 22);//设置p2.11 外部中断1

//    EXTMODE  |= 1 << 0;          /* 设置触发方式     ENIT1边沿触发  */
//    //    EXTMODE &= ~(1<<1);            /* 设置触发方式     ENIT1电平触发  */
//    EXTPOLAR &= ~(1 << 1);	///* EINT1 is falling edge

//    extint1_enable();
//    // 	 EXTINT    = 2;//1 << 1;
//}


/*********************************************************************************************************
** Function name:       EINT1_IRQHandler
** Descriptions:        外部中断1服务函数
** input parameters:    无
** Output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void EINT1_IRQHandler (void)
{
    Eint_Dis();
    //    Debug("ext1\n");
    EXTINT = 2;//1 << 1;//清中断标志
    SetE1_flag();
    Eint_En();
}
