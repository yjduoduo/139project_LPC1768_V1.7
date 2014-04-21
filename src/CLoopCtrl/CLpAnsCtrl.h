/*
*********************************************************************************************************
*                                                
*                            对象:	CLpAnsCtrl
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpAnsCtrl.H
* By   : 蒋雪梅
*********************************************************************************************************
*/
//#include  "CLpAnsCtrl.h" 

#ifndef CLpAnsCtrl_H
#define CLpAnsCtrl_H

#include  "Config.h"
#include  "CLpInfoDef.h" 

#ifdef  CLpAnsCtrl_C
#define Ex_CLpAnsCtrl
#else
#define Ex_CLpAnsCtrl extern 
#endif

/*******************************************************************/
/******************       全局常量定义�     *********************/
/*******************************************************************/
//constant/
/*************************************** 
应答回路反馈数据控制，10Bit输出
*****************************************/ 
 

/*******************************************************************/
/******************       数据结构定义�     *********************/
/*******************************************************************/
#define  cMaxLpAnsFlagLen    4 
#define  cMaxLpAnsOutBit     cMaxLpScanAnsStep
//采用2Bit控制输出
// 00  同步   输出0mA
// 01  逻辑0  输出6mA
// 10  逻辑1  输出20mA    
#define  cLpAnsLogo0   1
#define  cLpAnsLogo1   2 




/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:

Ex_CLpAnsCtrl  void  Init_CLpAnsCtrl(void); 

//根据命令类型，当前节点状态反馈对应的数据
Ex_CLpAnsCtrl  uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState); 

//准备当前地址的反馈数据
Ex_CLpAnsCtrl  void  SetData_CLpAnsCtrl(uint8 vSndData);

//根据当前的输出位，输出串行数据
Ex_CLpAnsCtrl  void  OutData_CLpAnsCtrl(uint8 vId); 

//输出当前节点的状态电流值
Ex_CLpAnsCtrl  void  OutState_CLpAnsCtrl(uint8 vId);  


/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpAnsCtrl_C      

uint8	  m_LpAnsFlag[cMaxLpScanAnsStep];  

//数据查询反馈信息 
#define  cLpAnsD4_Normal   0x0b     //状态类型
#define  cLpAnsD4_Alarm    0xeb     //状态类型
#define  cLpAnsD4_Fault    0x00     //状态类型

#define  cLpAnsD8_Normal   0x23     //正常的模拟量
#define  cLpAnsD8_Alarm    0x54     //报警时的模拟量
#define  cLpAnsD8_Fault    0x00     //故障模拟量

// #define  cNodeState_Normal  0
// #define  cNodeState_Fault   1
// #define  cNodeState_Alarm   2 
//查询状态类型反馈数据
static uint8 m_LpAnsD4[]={cLpAnsD4_Normal,cLpAnsD4_Fault,cLpAnsD4_Alarm};

//查询模拟量反馈数据
static uint8 m_LpAnsD8[]={cLpAnsD8_Normal,cLpAnsD8_Fault,cLpAnsD8_Alarm};

//数据查询反馈数据
static uint8 m_LpAnsD12[]={0xfa,0x20,0x01,0x0b,0x01,0x03,0x09,0x04,0x05,0x06};

#endif   
#endif







