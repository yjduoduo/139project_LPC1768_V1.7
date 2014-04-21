/*
*********************************************************************************************************
*                                                
*                            ¶ÔÏó:	CLpAnsCtrl
*
*                        (c) Copyright 2000-2006, ½¯Ñ©Ã·
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpAnsCtrl.H
* By   : ½¯Ñ©Ã·
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
/******************       È«¾Ö³£Á¿¶¨Òåý     *********************/
/*******************************************************************/
//constant/
/*************************************** 
Ó¦´ð»ØÂ··´À¡Êý¾Ý¿ØÖÆ£¬10BitÊä³ö
*****************************************/ 
 

/*******************************************************************/
/******************       Êý¾Ý½á¹¹¶¨Òåý     *********************/
/*******************************************************************/
#define  cMaxLpAnsFlagLen    4 
#define  cMaxLpAnsOutBit     cMaxLpScanAnsStep
//²ÉÓÃ2Bit¿ØÖÆÊä³ö
// 00  Í¬²½   Êä³ö0mA
// 01  Âß¼­0  Êä³ö6mA
// 10  Âß¼­1  Êä³ö20mA    
#define  cLpAnsLogo0   1
#define  cLpAnsLogo1   2 




/*******************************************************************/
/****************     ¹«ÓÐ³ÉÔ±±äÁ¿,º¯Êý¼°³£Á¿     ******************/
/*******************************************************************/
//public:

Ex_CLpAnsCtrl  void  Init_CLpAnsCtrl(void); 

//¸ù¾ÝÃüÁîÀàÐÍ£¬µ±Ç°½Úµã×´Ì¬·´À¡¶ÔÓ¦µÄÊý¾Ý
Ex_CLpAnsCtrl  uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState); 

//×¼±¸µ±Ç°µØÖ·µÄ·´À¡Êý¾Ý
Ex_CLpAnsCtrl  void  SetData_CLpAnsCtrl(uint8 vSndData);

//¸ù¾Ýµ±Ç°µÄÊä³öÎ»£¬Êä³ö´®ÐÐÊý¾Ý
Ex_CLpAnsCtrl  void  OutData_CLpAnsCtrl(uint8 vId); 

//Êä³öµ±Ç°½ÚµãµÄ×´Ì¬µçÁ÷Öµ
Ex_CLpAnsCtrl  void  OutState_CLpAnsCtrl(uint8 vId);  


/*******************************************************************/
/********************* Ë½ÓÐ³ÉÔ±±äÁ¿,º¯Êý¼°³£Á¿    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpAnsCtrl_C      

uint8	  m_LpAnsFlag[cMaxLpScanAnsStep];  

//Êý¾Ý²éÑ¯·´À¡ÐÅÏ¢ 
#define  cLpAnsD4_Normal   0x0b     //×´Ì¬ÀàÐÍ
#define  cLpAnsD4_Alarm    0xeb     //×´Ì¬ÀàÐÍ
#define  cLpAnsD4_Fault    0x00     //×´Ì¬ÀàÐÍ

#define  cLpAnsD8_Normal   0x23     //Õý³£µÄÄ£ÄâÁ¿
#define  cLpAnsD8_Alarm    0x54     //±¨¾¯Ê±µÄÄ£ÄâÁ¿
#define  cLpAnsD8_Fault    0x00     //¹ÊÕÏÄ£ÄâÁ¿

// #define  cNodeState_Normal  0
// #define  cNodeState_Fault   1
// #define  cNodeState_Alarm   2 
//²éÑ¯×´Ì¬ÀàÐÍ·´À¡Êý¾Ý
static uint8 m_LpAnsD4[]={cLpAnsD4_Normal,cLpAnsD4_Fault,cLpAnsD4_Alarm};

//²éÑ¯Ä£ÄâÁ¿·´À¡Êý¾Ý
static uint8 m_LpAnsD8[]={cLpAnsD8_Normal,cLpAnsD8_Fault,cLpAnsD8_Alarm};

//Êý¾Ý²éÑ¯·´À¡Êý¾Ý
static uint8 m_LpAnsD12[]={0xfa,0x20,0x01,0x0b,0x01,0x03,0x09,0x04,0x05,0x06};

#endif   
#endif







