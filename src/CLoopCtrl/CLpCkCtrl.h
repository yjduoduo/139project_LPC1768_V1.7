/*
*********************************************************************************************************
*
*                            ??:	CLpCkCtrl
*
*                        (c) Copyright 2000-2006, ???
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpCkCtrl.H
* By   : ???
*********************************************************************************************************
*/
//#include  "CLpCkCtrl.h"

#ifndef CLpCkCtrl_H
#define CLpCkCtrl_H

#include  "Config.h"


#ifdef  CLpCkCtrl_C
#define Ex_CLpCkCtrl
#else
#define Ex_CLpCkCtrl extern
#endif

/*******************************************************************/
/******************       ???????    *********************/
/*******************************************************************/
//constant
#define  cLpCkFlag_ExtF   2  //下降沿中断
#define  cLpCkFlag_ExtR   1  //上升沿中断 
 

#define  cLpCkPer_Rcv    1  //接收命令周期
#define  cLpCkPer_Ans   0  //反馈处理周期


#define  cLpCkComm_Null   0  //下降沿中断
#define  cLpCkComm_Rcv    1  //下降沿中断
#define  cLpCkComm_Send   2  //上升沿中断

/*******************************************************************/
/******************       数据结构定义?    *********************/
/*******************************************************************/

#define  cMaxLpCkFlagLen    4

typedef union type_tLpCkFlag{	   //????

    uint32   Word;
    uint16   UByte[cMaxLpCkFlagLen>>1];
    uint8    Byte[cMaxLpCkFlagLen];
    struct
    {
	    uint32 bExtint:2;	          //有边沿触发标识
			uint32 bPer:1;	            //巡检周期  1，命令接收段    0：信息反馈段 
			uint32 bComm:2;	            //命令接收状态
			


//Inspection status
        uint32 b10ms:1;	          //10ms ????
        uint32 b50ms:1;	          //50ms ????
        uint32 b1s:1;
        uint32 b5s:1;
        uint32 bReset:1;
        uint32 bReg:1;
        uint32 bAlarm:1;	        //????

    }Bit;
}tLpCkFlag;
/*******************************************************************/
/****************     ??????,?????     ******************/
/*******************************************************************/
//public:

Ex_CLpCkCtrl  void  Init_CLpCkCtrl(void);

Ex_CLpCkCtrl  void   SetExtint_CLpCkCtrl(uint8 vType);
Ex_CLpCkCtrl  uint8  GetExtint_CLpCkCtrl(void);
Ex_CLpCkCtrl  void   ClrExtint_CLpCkCtrl(void);

Ex_CLpCkCtrl  void   ClrPer_CLpCkCtrl(void); 
Ex_CLpCkCtrl  void   SetPer_CLpCkCtrl(uint8 vType); 
Ex_CLpCkCtrl  uint8  GetPer_CLpCkCtrl(void); 

Ex_CLpCkCtrl  void  Clr10ms_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  Set10ms_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 Get10ms_CLpCkCtrl(void);

Ex_CLpCkCtrl  void  Clr50ms_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  Set50ms_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 Get50ms_CLpCkCtrl(void);

Ex_CLpCkCtrl  void  ClrReset_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  SetReset_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 GetReset_CLpCkCtrl(void);

Ex_CLpCkCtrl  void  ClrReg_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  SetReg_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 GetReg_CLpCkCtrl(void);

Ex_CLpCkCtrl  void  ClrAlarm_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  SetAlarm_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 GetAlarm_CLpCkCtrl(void);


Ex_CLpCkCtrl  void  Clr5s_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  Set5s_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 Get5s_CLpCkCtrl(void);


Ex_CLpCkCtrl  void  Clr1s_CLpCkCtrl(void);
Ex_CLpCkCtrl  void  Set1s_CLpCkCtrl(void);
Ex_CLpCkCtrl  uint8 Get1s_CLpCkCtrl(void);



/*******************************************************************/
/********************* ??????,?????    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpCkCtrl_C

tLpCkFlag	m_LpCkFlag; //????

#endif
#endif







