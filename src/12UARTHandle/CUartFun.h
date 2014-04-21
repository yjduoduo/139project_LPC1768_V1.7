/*
;*********************************************************************************************************
;*                                                
;*                            ����: CUartFun
;*
;*                        (c) Copyright 2010-2018, ��ѩ÷
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CUartFun.h
;* By   : ��ѩ÷
;* ʱ�� : 2012-6-14
;*********************************************************************************************************
;*/
//#include  "CUartFun.h"

#ifndef CUartFun_H
#define CUartFun_H	  

#include "include.h"

#ifdef  CUartFun_C
#define EX_CUartFun
#else
#define EX_CUartFun extern 
#endif


/*******************************************************************/
/******************       ȫ�ֳ�������?    *********************/
/*******************************************************************/
//constant
#define UART_TEST_NUM			0
#if (UART_TEST_NUM == 0)
#define	_LPC_UART				(LPC_UART_TypeDef *)LPC_UART0
#define _GPDMA_CONN_UART_Tx		GPDMA_CONN_UART0_Tx
#define _GPDMA_CONN_UART_Rx		GPDMA_CONN_UART0_Rx
#elif (UART_TEST_NUM == 1)
#define _LPC_UART				(LPC_UART_TypeDef *)LPC_UART1
#define _GPDMA_CONN_UART_Tx		GPDMA_CONN_UART1_Tx
#define _GPDMA_CONN_UART_Rx		GPDMA_CONN_UART1_Rx
#elif (UART_TEST_NUM == 2)
#define _LPC_UART				LPC_UART2
#define _GPDMA_CONN_UART_Tx		GPDMA_CONN_UART2_Tx
#define _GPDMA_CONN_UART_Rx		GPDMA_CONN_UART2_Rx
#endif


/*******************************************************************/
/******************       ȫ�ֳ�������?    *********************/
/*******************************************************************/
//constant
//50M��Ƶ   ����10ms ʱ��
 
//#define cMaxUartRcvBuffNum  (0x001F47A0)
#define cMaxHzkNum  (0x00045080)
#define cMaxUartRcvBuffNum  0x100 //(0x00045100)

/*******************************************************************/
/******************       ���ݽṹ����?    *********************/
/*******************************************************************/

/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
/*******************************************************************/
//public:
EX_CUartFun   void   Init_CUartFun(void);    //��ʼ��

 
EX_CUartFun   void   do_CUartFun(void);
EX_CUartFun   void   Save_CUartFun(void);


EX_CUartFun   void   InitBuff_CUartFun(void);          //��ʼ��
EX_CUartFun   void   AddBuff_CUartFun(uint8 vData);    //��ʼ��

EX_CUartFun   uint32  vUartRcvBuffRcv;
EX_CUartFun   uint32  vUartRcvBuffCtrl;
EX_CUartFun   uint8   vUart0SaveFlag;
/*******************************************************************/
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CUartFun_C

uint32 vUartSaveAddr; 

uint8   vUartRcvBuff[cMaxUartRcvBuffNum] __attribute__ ((section ("Uart_RcvRAM"), zero_init));
uint32  vUartRcvBuffCtrl;
uint32  vUartRcvBuffRcv;


//void  SaveBuff_CUartFun(uint32 vSaveAddr,uint32 vSaveLen);    //��ʼ��

#endif
#endif

