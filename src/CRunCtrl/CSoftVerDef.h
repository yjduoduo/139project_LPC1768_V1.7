   /*
;*********************************************************************************************************
;*                               ¶ÔÏó:  CSoftVerDef
;*                        (c) Copyright 2000-2004, jxm
;*                              All Rights Reserved
;*                                    
;* File : CSoftVerDef.h
;* Ver1.0
;* Ê±¼ä : 2013-10-30
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
#define CSoftVer_A    0      
#define CSoftVer_B    0 
#define CSoftVer_C    0 
#define CSoftVer_D    1  

#define CSoftVer_E    0     //ÄÚ²¿²âÊÔ°æ±¾
#define CSoftVer_F    0     //ÄÚ²¿Ä£¿é°æ±¾
#define CSoftVer_G    4   //ÄÚ²¿Ä£¿é¹¦ÄÜÐÞÕý
 
 
#define cMaxSoftVerInfoLen  7
#define cMaxSoftVerOutLen   4

static  uint8 mSoftVerInfo[cMaxSoftVerInfoLen]={CSoftVer_A,CSoftVer_B,CSoftVer_C,CSoftVer_D,CSoftVer_E,CSoftVer_F,CSoftVer_G};

//¶¨ÒåÈí¼þ°æ±¾ÐÞ¸ÄÊ±¼ä
#define cMaxSoftVerTimeLen  6
static  uint8   m_SoftVerTime[cMaxSoftVerTimeLen]={14,2,28,8,30,21};
//////////////////////////////////////////////////////////////////////////////////////////
 

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

