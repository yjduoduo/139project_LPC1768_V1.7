/*
*********************************************************************************************************
*                                                
*                            对象:	CLpInfoDef
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpInfoDef.H
* By   : 蒋雪梅
*********************************************************************************************************
*/
//#include  "CLpInfoDef.h" 

#ifndef CLpInfoDef_H
#define CLpInfoDef_H

#include  "Config.h"
 

#ifdef  CLpInfoDef_C
#define Ex_CLpInfoDef
#else
#define Ex_CLpInfoDef extern 
#endif

/*******************************************************************/
/******************       全局常量定义�     *********************/
/*******************************************************************/
//constant/
#define  cLpScanComm_D0	  0  //正常巡检命令
#define  cLpScanComm_D4   1  //状态类型查询
#define  cLpScanComm_D8   2  //模拟量数据查询
#define  cLpScanComm_D12  3  //数据查询
#define  cMaxLpScanComm   4  

 
#define  cNodeState_Normal  0
#define  cNodeState_Fault   1
#define  cNodeState_Alarm   2
#define  cMaxNodeStateNum   3 

#define  cMaxNodeD12Num     9 

#define  cMaxLpScanAnsStep      10    //数据查询反馈数据
#define  cMaxLpScanAnsTId       6    //反馈步骤计数
/*******************************************************************/
/******************       数据结构定义�     *********************/
/*******************************************************************/
 
/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:

Ex_CLpInfoDef  void   Init_CLpInfoDef(void);

 

 

/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpInfoDef_C      

 



#endif   
#endif







