   /*
;*********************************************************************************************************
;*                               对象:  CSoftVerDef
;*                        (c) Copyright 2000-2004, jxm
;*                              All Rights Reserved
;*                                    
;* File : CSoftVerDef.h
;* Ver1.0
;* 时间 : 2013-1-9.
;*********************************************************************************************************
;*/  
//#include  "CSoftVerDef.h"
#ifndef CSoftVerDef_H
#define CSoftVerDef_H

#include  "Config.h"
 
 
#ifdef  CSoftVerDef_C
#define EX_CSoftVerDef
#else
#define EX_CSoftVerDef extern 
#endif

/*******************************************************************/
/******************       全局常量定义�     *********************/
/*******************************************************************/
#define CSoftVer_A    1
#define CSoftVer_B    8
#define CSoftVer_C    0 
#define CSoftVer_D    0

#define CSoftVer_E    0     //内部测试版本
#define CSoftVer_F    1     //内部模块版本
#define CSoftVer_G    5    //内部模块功能修正
 
 
#define cMaxSoftVerInfoLen  7
#define cMaxSoftVerOutLen   4

static  uint8 mSoftVerInfo[cMaxSoftVerInfoLen]={CSoftVer_A,CSoftVer_B,CSoftVer_C,CSoftVer_D,CSoftVer_E,CSoftVer_F,CSoftVer_G};

//////////////////////////////////////////////////////////////////////////////////////////
//定义软件版本修改时间
#define cMaxSoftVerTimeLen  6
static  uint8 m_SoftVerTime[cMaxSoftVerTimeLen]={14,5,7,17,30,51}; 

//////////////////////////////////////////////////////////////////////////////////////////
//配接11s 标准系统的软件标识
#define  c11S_SoftMainVer  8
#define  c11S_SoftSubVer   0

/*******************************************************************/
/******************       数据结构定义�     *********************/
/*******************************************************************/

/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:
EX_CSoftVerDef   void   Init_CSoftVerDef(void);   //初始化
 

 


/*******************************************************************/
/********************* 私有成员变量,函数及常量   *******************/
/*******************************************************************/
//Private:
#ifdef  CSoftVerDef_C  

 

#endif
#endif

