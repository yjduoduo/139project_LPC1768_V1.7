/*
;*********************************************************************************************************
;*                                                
;*                            对象: CTimeCtrl
;*
;*                        (c) Copyright 2013-2018, 蒋雪梅
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CTimeCtrl.h
;* By   : 蒋雪梅
;* 时间 : 2013-8-23
;*********************************************************************************************************
;*/
//#include  "CTimeCtrl.h"

#ifndef CTimeCtrl_H
#define CTimeCtrl_H	  

#include  "Config.h" 
#include  "CTimeDef.h"


#ifdef  CTimeCtrl_C
#define EX_CTimeCtrl
#else
#define EX_CTimeCtrl extern 
#endif

/*******************************************************************/
/******************       全局常量定义�     *********************/
/*******************************************************************/
//constant 
   
 
/*******************************************************************/
/******************       数据结构定义�     *********************/
/*******************************************************************/
 
/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:
EX_CTimeCtrl   void   Init_CTimeCtrl(void);    //初始化

EX_CTimeCtrl   void   T0Int_CTimeCtrl(void);    //初始化 

EX_CTimeCtrl   void   T1Int_CTimeCtrl(void);
 
 
/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CTimeCtrl_C  

#define cTime1_Base 20

#define  cTime1_40ms_Count      (40/cTime1_Base)
#define  cTime1_100ms_Count     (100/cTime1_Base)
#define  cTime1_1s_Count        (1000/cTime1_Base)
#define  cTime1_5s_Count        (5000/cTime1_Base)
#define  cTime1_1m_Count        (60000/cTime1_Base)

uint8    vRun1s;   

uint16   vRunTime0;  
uint16   vRunTime1; 
 
uint16   mRunTime0;  
uint8    vPIT0Run; 
uint8    vPIT1Run;   
uint32   vRunValue;   
uint8    vRunToIap;  

void  SetCommT0_CTimeCtrl(void); 
void  AnsCommT0_CTimeCtrl(void); 

void  IncT0Count_CTimeCtrl(void); 
void  SaveComm_CTimeCtrl(uint8 vComm); 


static  uint16  m_AnsStatTime[]={cTime2ms,cTime9ms,cTime9ms,cTime9ms};
static  uint16  m_AnsDataTime[]={cTime2ms,cTime2ms,cTime9ms,cTime9ms};

#endif
#endif

