/*
*********************************************************************************************************
*                                                
*                            ����:	CLpAnsCtrl
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpAnsCtrl.H
* By   : ��ѩ÷
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
/******************       ȫ�ֳ��������     *********************/
/*******************************************************************/
//constant/
/*************************************** 
Ӧ���·�������ݿ��ƣ�10Bit���
*****************************************/ 
 

/*******************************************************************/
/******************       ���ݽṹ�����     *********************/
/*******************************************************************/
#define  cMaxLpAnsFlagLen    4 
#define  cMaxLpAnsOutBit     cMaxLpScanAnsStep
//����2Bit�������
// 00  ͬ��   ���0mA
// 01  �߼�0  ���6mA
// 10  �߼�1  ���20mA    
#define  cLpAnsLogo0   1
#define  cLpAnsLogo1   2 




/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
/*******************************************************************/
//public:

Ex_CLpAnsCtrl  void  Init_CLpAnsCtrl(void); 

//�����������ͣ���ǰ�ڵ�״̬������Ӧ������
Ex_CLpAnsCtrl  uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState); 

//׼����ǰ��ַ�ķ�������
Ex_CLpAnsCtrl  void  SetData_CLpAnsCtrl(uint8 vSndData);

//���ݵ�ǰ�����λ�������������
Ex_CLpAnsCtrl  void  OutData_CLpAnsCtrl(uint8 vId); 

//�����ǰ�ڵ��״̬����ֵ
Ex_CLpAnsCtrl  void  OutState_CLpAnsCtrl(uint8 vId);  


/*******************************************************************/
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpAnsCtrl_C      

uint8	  m_LpAnsFlag[cMaxLpScanAnsStep];  

//���ݲ�ѯ������Ϣ 
#define  cLpAnsD4_Normal   0x0b     //״̬����
#define  cLpAnsD4_Alarm    0xeb     //״̬����
#define  cLpAnsD4_Fault    0x00     //״̬����

#define  cLpAnsD8_Normal   0x23     //������ģ����
#define  cLpAnsD8_Alarm    0x54     //����ʱ��ģ����
#define  cLpAnsD8_Fault    0x00     //����ģ����

// #define  cNodeState_Normal  0
// #define  cNodeState_Fault   1
// #define  cNodeState_Alarm   2 
//��ѯ״̬���ͷ�������
static uint8 m_LpAnsD4[]={cLpAnsD4_Normal,cLpAnsD4_Fault,cLpAnsD4_Alarm};

//��ѯģ������������
static uint8 m_LpAnsD8[]={cLpAnsD8_Normal,cLpAnsD8_Fault,cLpAnsD8_Alarm};

//���ݲ�ѯ��������
static uint8 m_LpAnsD12[]={0xfa,0x20,0x01,0x0b,0x01,0x03,0x09,0x04,0x05,0x06};

#endif   
#endif







