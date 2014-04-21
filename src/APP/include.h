/*
;*********************************************************************************************************
;*                                                
;*                            对象: Config
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : Config.h
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
//#include  "include.h"
#ifndef include_H
#define include_H

#include "LPC17xx.h"			/* LPC17xx Peripheral Registers */
#include  "Config.h"
#include "buffer.h"
#include  "CMaDefine.h"
/////////////Hardware////////////////////
//ssp flash
#include  "ssp.h"
// #include "m25p80.h"
//I2C
#include "i2c.h"
//时钟芯片
#include    "pcf8563.h"

//GPIO
#include "GPIOInit.h"
//UART
#include "uart.h"
//E_Int
#include  "extint.h"
//
#include  "PWM.h"
///////////////////board///////////////////////////
//lcd
#include "lcd.h"
//timer
#include  "CTime.h"
//Speaker
#include  "CSpeaker.h"
//
#include  "CRelay.h"
//
#include "CIntStEnd.h" 
/////////////////////////////////////////////////
//参数
 #include  "CGrapParam.h"
//delay
#include "Delay.h"

//运行函数
#include  "runfunction.h"
//共用参数，结构
#include  "publicparam.h"
//界面
#include  "startmenu.h"
#include "mainmenu.h"
#include  "setmenu.h"
#include  "checkmenu.h"
#include  "testmenu.h"
#include  "batteryLow.h"
#include  "breakdown.h"
#include  "CLocalSet.h"
#include  "CCompReg.h"
#include  "CCompSet.h"
#include  "CDateMod.h"
#include  "CAnnotate.h"
#include  "CSysCheck.h"
#include  "CCompStat.h"
#include  "CHistoryList.h"
#include  "CCompInten.h"
#include  "CTestSelf.h"
#include  "alarmenu.h"
// #include  "CSysReset.h"
//function
#include  "CTimerTask.h"

//
#include "CLED.h"

#include "CAddressCount.h"

#include "CFlash_ADDR_Def.h"



//控制串口0的波特率
#define UART0_BPS 2400/*2400*/

#define BAIWEI(A)  (A/100)
#define SHIWEI(A)  (A%100/10)
#define GEWEI(A)   (A%100%10)


//目前为DEBUG_SOFT,正式版本的时候去年

#define Debug lcd_printf

//历史记录不擦除
//#define ERASE_DEBUG

//按键不带锁
//[n]按键加锁
#define KEYNOTLOCK

/*******************************************************************/
/********************* END *****************************************/
/*******************************************************************/
#endif

