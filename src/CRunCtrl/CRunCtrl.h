/*
;*********************************************************************************************************
;*                                                
;*                            对象: CRunCtrl
;*
;*                        (c) Copyright 2013-2018, 蒋雪梅
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CRunCtrl.h
;* By   : 蒋雪梅
;* 时间 : 2013-8-23
;*********************************************************************************************************
;*/
//#include  "CRunCtrl.h"

#ifndef CRunCtrl_H
#define CRunCtrl_H	  

#include  "Config.h" 
 
#ifdef  CRunCtrl_C
#define EX_CRunCtrl
#else
#define EX_CRunCtrl extern 
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
EX_CRunCtrl   void   Init_CRunCtrl(void);    //初始化

EX_CRunCtrl   void   Reset_CRunCtrl(void);    //初始化 

EX_CRunCtrl   void   do_CRunCtrl(void);    //初始化  

EX_CRunCtrl   void   LpCk_CRunCtrl(void); 
 
/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CRunCtrl_C  
uint8 vRunLedCount;
void  RunLed_CRunCtrl(void); 
void zijian_speaker(void);
#endif
#endif

