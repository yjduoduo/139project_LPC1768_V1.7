/*
;*********************************************************************************************************
;*                               对象:  CUartRcv
;*                        (c) Copyright 2000-2004, 蒋雪梅
;*                              All Rights Reserved
;*                                    
;* File : CUartRcv.h
;* Ver1.0
;* 时间 : 2012-12-08
;*********************************************************************************************************
;*/
//#include  "CUartRcv.h"

#ifndef CUartRcv_H
#define CUartRcv_H

#include  "Config.h"
#include  "CCircleBuf.h"
#include  "CCircleBufDef.h"

#ifdef  CUartRcv_C
#define EX_CUartRcv
#else
#define EX_CUartRcv extern 
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
EX_CUartRcv   void   Init_CUartRcv(void);   //初始化 

EX_CUartRcv   void   Add_CUartRcv(uint8 vRcvData);   //初始化 

EX_CUartRcv   void   Read_CUartRcv(void);   //读取UART数据
EX_CUartRcv   void   ChkPro_CUartRcv(void); 
EX_CUartRcv   void   ChkBusPro_CUartRcv(void);

EX_CUartRcv   uint8  UartRcvCkFlag_CUartRcv(void);
EX_CUartRcv   uint8  UartAddr_CUartRcv(uint8 vId);

/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CUartRcv_C

#define cMaxUartRcvNum  280
#define cChgUartRcvNum  200

uint8 vUartRcvBuf[cMaxUartRcvNum]; 

#define cMaxUartOldRcvNum  3
uint8 vUartOldRcvBuf[cMaxUartOldRcvNum];

tCircleBufCtrl  vUartRcvBufCtrl;

void ClrUartRcvBuff(void);

uint8    vUartRcvHead; 
uint16   vUartRcvEndLen; 
uint8    vUartRcvRdFlag; 

uint8    vUartRcvCkFlag; 

void   ClrBuff_CUartRcv(void);   //读取UART数据

void   RcvAct_CUartRcv(void);    
void   RcvInsul_CUartRcv(void);    

void   SetPro_CUartRcv(void);   


void   SetNote_CUartRcv(void);   
void   ChkNote_CUartRcv(void); 

void   SetBusPro_CUartRcv(void);   


#endif
#endif

