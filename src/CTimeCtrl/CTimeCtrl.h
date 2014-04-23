/*
;*********************************************************************************************************
;*                                                
;*                            ����: CTimeCtrl
;*
;*                        (c) Copyright 2013-2018, ��ѩ÷
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CTimeCtrl.h
;* By   : ��ѩ÷
;* ʱ�� : 2013-8-23
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
/******************       ȫ�ֳ��������     *********************/
/*******************************************************************/
//constant 
   
 
/*******************************************************************/
/******************       ���ݽṹ�����     *********************/
/*******************************************************************/
 
/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
/*******************************************************************/
//public:
EX_CTimeCtrl   void   Init_CTimeCtrl(void);    //��ʼ��

EX_CTimeCtrl   void   T0Int_CTimeCtrl(void);    //��ʼ�� 

EX_CTimeCtrl   void   T1Int_CTimeCtrl(void);
 
 
/*******************************************************************/
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CTimeCtrl_C  

#define cTime1_Base 20

#define  cTime1_20ms_Count      (20/cTime1_Base)
#define  cTime1_40ms_Count      (40/cTime1_Base)
#define  cTime1_100ms_Count     (100/cTime1_Base)
#define  cTime1_160ms_Count     (160/cTime1_Base)
#define  cTime1_200ms_Count     (200/cTime1_Base)
#define  cTime1_500ms_Count     (500/cTime1_Base)
#define  cTime1_1s_Count        (1000/cTime1_Base)
#define  cTime1_5s_Count        (5000/cTime1_Base)
#define  cTime1_1m_Count        (60000/cTime1_Base)



uint8    vRun1s;   

uint16   vRunTime0;  
uint16   vRunTime1; 

//pwm1 control start and stop
uint16 vPWM1Time = 0;
uint8  vPWM1StopFlag = 0;
 
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

