/*
*********************************************************************************************************
*                                                
*                            ����:	CLpInfoDef
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpInfoDef.H
* By   : ��ѩ÷
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
/******************       ȫ�ֳ��������     *********************/
/*******************************************************************/
//constant/
#define  cLpScanComm_D0	  0  //����Ѳ������
#define  cLpScanComm_D4   1  //״̬���Ͳ�ѯ
#define  cLpScanComm_D8   2  //ģ�������ݲ�ѯ
#define  cLpScanComm_D12  3  //���ݲ�ѯ
#define  cMaxLpScanComm   4  

 
#define  cNodeState_Normal  0
#define  cNodeState_Fault   1
#define  cNodeState_Alarm   2
#define  cMaxNodeStateNum   3 

#define  cMaxNodeD12Num     9 

#define  cMaxLpScanAnsStep      10    //���ݲ�ѯ��������
#define  cMaxLpScanAnsTId       6    //�����������
/*******************************************************************/
/******************       ���ݽṹ�����     *********************/
/*******************************************************************/
 
/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
/*******************************************************************/
//public:

Ex_CLpInfoDef  void   Init_CLpInfoDef(void);

 

 

/*******************************************************************/
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpInfoDef_C      

 



#endif   
#endif







