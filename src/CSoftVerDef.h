   /*
;*********************************************************************************************************
;*                               ����:  CSoftVerDef
;*                        (c) Copyright 2000-2004, jxm
;*                              All Rights Reserved
;*                                    
;* File : CSoftVerDef.h
;* Ver1.0
;* ʱ�� : 2013-1-9.
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
/******************       ȫ�ֳ��������     *********************/
/*******************************************************************/
#define CSoftVer_A    1
#define CSoftVer_B    8
#define CSoftVer_C    0 
#define CSoftVer_D    0

#define CSoftVer_E    0     //�ڲ����԰汾
#define CSoftVer_F    1     //�ڲ�ģ��汾
#define CSoftVer_G    5    //�ڲ�ģ�鹦������
 
 
#define cMaxSoftVerInfoLen  7
#define cMaxSoftVerOutLen   4

static  uint8 mSoftVerInfo[cMaxSoftVerInfoLen]={CSoftVer_A,CSoftVer_B,CSoftVer_C,CSoftVer_D,CSoftVer_E,CSoftVer_F,CSoftVer_G};

//////////////////////////////////////////////////////////////////////////////////////////
//��������汾�޸�ʱ��
#define cMaxSoftVerTimeLen  6
static  uint8 m_SoftVerTime[cMaxSoftVerTimeLen]={14,5,7,17,30,51}; 

//////////////////////////////////////////////////////////////////////////////////////////
//���11s ��׼ϵͳ�������ʶ
#define  c11S_SoftMainVer  8
#define  c11S_SoftSubVer   0

/*******************************************************************/
/******************       ���ݽṹ�����     *********************/
/*******************************************************************/

/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
/*******************************************************************/
//public:
EX_CSoftVerDef   void   Init_CSoftVerDef(void);   //��ʼ��
 

 


/*******************************************************************/
/********************* ˽�г�Ա����,����������   *******************/
/*******************************************************************/
//Private:
#ifdef  CSoftVerDef_C  

 

#endif
#endif

