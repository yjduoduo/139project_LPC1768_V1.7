/*
*********************************************************************************************************
*                                                
*                            对象:	CTime0 
*
*                        (c) Copyright 2010-2016, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.0
* File : CTime0 .H
* By   : 
*********************************************************************************************************
*/
//#include  "CTime.h"

#ifndef CTime0_H
#define CTime0_H

#include  "Config.h"   
 

#ifdef  CTime0_C
#define Ex_CTime0 
#else
#define Ex_CTime0  extern 
#endif

/*******************************************************************/
/******************       全局常量定义?    *********************/
/*******************************************************************/
//constant
  

/*******************************************************************/
/******************       数据结构定义?    *********************/
/*******************************************************************/ 
 
 
 	

/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
extern  void     SetHeartTick(uint32 tmp);
extern  void AddHeartTick(void);
extern  uint32   GetHeartTick(void);
extern  void     Init_CTime0(void);  
extern  void     Init_CTime1(void);
extern  void     init_timer (uint8 timer_num, uint32 TimerInterval); 
extern  void     SetTimeTickCounter(uint8 tmp);
extern  uint8    GetTimeTickCounter(void);
extern  void     AddSpeakerTick(void);
extern  void     SetSpeakerTick(uint16 tmp);
extern  uint16   GetSpeakerTick(void);
extern  void     TIMER0_IRQHandler (void);  
extern  void     TIMER1_IRQHandler (void);
extern  void     enable_timer( uint8 timer_num );
extern  void     disable_timer( uint8 timer_num );
extern  void     reset_timer( uint8 timer_num );
extern  void     CLedShow(void);
extern  void     CSpeakerPWM(void);
extern  void     OnLCD(void);
extern  void vAddLedFlag(void);
extern  void vClrLedFlag(void);
extern  uint32 vGetLedFlag(void);
extern  void OffLcd(void);
extern  void vAddScreenMask(void);
extern  uint32 vGetScreenMask(void);

void timern_disable(uint8 timern);
void timern_enable(uint8 timern);
 /*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CTime_C    
static uint16  vSysTimeCtrl;
 
uint8 vTimeTickCounter=0;
uint32 vHeartTick=0;
uint16 vSpeakerTick=0;

uint32 vLedFlag=0;
//uint32 vPWMFlag=0;
uint32 vScreenMaskFlag=0;
#endif   
#endif


