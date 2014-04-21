/*
*********************************************************************************************************
*
*                            对象:	CLpCkCtrl
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpScanCtrl.H
* By   : 蒋雪梅
*********************************************************************************************************
*/
//#include  "CLpScanCtrl.h"

#ifndef CLpScanCtrl_H
#define CLpScanCtrl_H

#include  "Config.h"
#include  "CLpInfoDef.h"

#ifdef  CLpScanCtrl_C
#define Ex_CLpScanCtrl
#else
#define Ex_CLpScanCtrl extern
#endif

/*******************************************************************/
/******************       全局常量定义?    *********************/
/*******************************************************************/
//constant/
/***************************************
//回路巡检处理,记录当前巡检的地址号  巡检周期状态

*****************************************/

#define  cLpScanFlag_ExtF   2  //下降沿中断
#define  cLpScanFlag_ExtR   1  //上升沿中断

#define  cLpScanPer_Rcv    1  //接收命令周期
#define  cLpScanPer_Ans    0  //反馈处理周期

#define  cLpScanComm_NewSys  0xff  //新同步周期

/*******************************************************************/
/******************       数据结构定义?    *********************/
/*******************************************************************/
#define  cMaxLpScanFlagLen    4

typedef union type_tLpScanFlag{	   //时钟标识

   uint32   Word;
     uint16   UByte[cMaxLpScanFlagLen>>1];
     uint8    Byte[cMaxLpScanFlagLen];
   struct
     {
        uint32 bSys:1;	            //同步状态,为1时，进行正常巡检，否则等待同步信息,用于回路出现异常时，防止跑地址
                                        //命令脉宽>22ms时，清除同步标识
            uint32 bAddr:8;	            //当前巡检地址

            uint32 bComm:2;	            //当前巡检命令，根据高电平脉宽读取回路下发的命令类型
            uint32 bState:1;            //状态电流输出标识
            uint32 bRec0:4;             //未使用的  4

//串行反馈数据控制
            uint32 bAnsFlag:1;          //反馈需要
            uint32 bAnsStar:1;          //反馈开始标识
            uint32 bAnsStep:4;          //反馈数据步骤计数   0～9  共10步
            uint32 bAnsTId:3;           //反馈数据输出Bit位定时 600us/100us
            uint32 bReset:1;            //回路复位标志
    }Bit;
}tLpScanFlag;
/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:

Ex_CLpScanCtrl  void   Init_CLpScanCtrl(void);

Ex_CLpScanCtrl  void   NewNode_CLpScanCtrl(void);

Ex_CLpScanCtrl  void   ClrComm_CLpScanCtrl(void);
Ex_CLpScanCtrl  void   SetComm_CLpScanCtrl(uint8 vComm);
Ex_CLpScanCtrl  uint8  GetComm_CLpScanCtrl(void);

Ex_CLpScanCtrl  void   ClrAddr_CLpScanCtrl(void);
Ex_CLpScanCtrl  void   IncAddr_CLpScanCtrl(void);
Ex_CLpScanCtrl  void   SetAddr_CLpScanCtrl(uint8 vAddr);
Ex_CLpScanCtrl  uint8  GetAddr_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrSys_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetSys_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetSys_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrState_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetState_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetState_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrAnsFlag_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetAnsFlag_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetAnsFlag_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrAnsStar_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetAnsStar_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetAnsStar_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrAnsStep_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetAnsStep_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetAnsStep_CLpScanCtrl(void);

Ex_CLpScanCtrl  void    ClrAnsTId_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    SetAnsTId_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8   GetAnsTId_CLpScanCtrl(void);
Ex_CLpScanCtrl  void    DecAnsTId_CLpScanCtrl(void);



Ex_CLpScanCtrl  void  SetReset_CLpScanCtrl(void);
Ex_CLpScanCtrl  uint8 GetReset_CLpScanCtrl(void);
Ex_CLpScanCtrl  void  ClrReset_CLpScanCtrl(void);

/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpScanCtrl_C

tLpScanFlag	m_LpScanFlag;



#endif
#endif







