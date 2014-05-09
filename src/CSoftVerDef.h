   /*
;*********************************************************************************************************
;*                               ¶ÔÏó:  CSoftVerDef
;*                        (c) Copyright 2000-2004, jxm
;*                              All Rights Reserved
;*                                    
;* File : CSoftVerDef.h
;* Ver1.0
;* Ê±¼ä : 2013-1-9.
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
/******************       È«¾Ö³£Á¿¶¨Òåý     *********************/
/*******************************************************************/
#define CSoftVer_A    1
#define CSoftVer_B    8
#define CSoftVer_C    0 
#define CSoftVer_D    0

#define CSoftVer_E    0     //ÄÚ²¿²âÊÔ°æ±¾
#define CSoftVer_F    1     //ÄÚ²¿Ä£¿é°æ±¾
#define CSoftVer_G    5    //ÄÚ²¿Ä£¿é¹¦ÄÜÐÞÕý
 
 
#define cMaxSoftVerInfoLen  7
#define cMaxSoftVerOutLen   4

static  uint8 mSoftVerInfo[cMaxSoftVerInfoLen]={CSoftVer_A,CSoftVer_B,CSoftVer_C,CSoftVer_D,CSoftVer_E,CSoftVer_F,CSoftVer_G};

//////////////////////////////////////////////////////////////////////////////////////////
//¶¨ÒåÈí¼þ°æ±¾ÐÞ¸ÄÊ±¼ä
#define cMaxSoftVerTimeLen  6
static  uint8 m_SoftVerTime[cMaxSoftVerTimeLen]={14,5,7,17,30,51}; 

//////////////////////////////////////////////////////////////////////////////////////////
//Åä½Ó11s ±ê×¼ÏµÍ³µÄÈí¼þ±êÊ¶
#define  c11S_SoftMainVer  8
#define  c11S_SoftSubVer   0

/*******************************************************************/
/******************       Êý¾Ý½á¹¹¶¨Òåý     *********************/
/*******************************************************************/

/*******************************************************************/
/****************     ¹«ÓÐ³ÉÔ±±äÁ¿,º¯Êý¼°³£Á¿     ******************/
/*******************************************************************/
//public:
EX_CSoftVerDef   void   Init_CSoftVerDef(void);   //³õÊ¼»¯
 

 


/*******************************************************************/
/********************* Ë½ÓÐ³ÉÔ±±äÁ¿,º¯Êý¼°³£Á¿   *******************/
/*******************************************************************/
//Private:
#ifdef  CSoftVerDef_C  

 

#endif
#endif

