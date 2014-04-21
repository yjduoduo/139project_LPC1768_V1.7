/*
*********************************************************************************************************
*
*                            ����:	CLpCkCtrl
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpScanCtrl.H
* By   : ��ѩ÷
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
/******************       ȫ�ֳ�������?    *********************/
/*******************************************************************/
//constant/
/***************************************
//��·Ѳ�촦��,��¼��ǰѲ��ĵ�ַ��  Ѳ������״̬

*****************************************/

#define  cLpScanFlag_ExtF   2  //�½����ж�
#define  cLpScanFlag_ExtR   1  //�������ж�

#define  cLpScanPer_Rcv    1  //������������
#define  cLpScanPer_Ans    0  //������������

#define  cLpScanComm_NewSys  0xff  //��ͬ������

/*******************************************************************/
/******************       ���ݽṹ����?    *********************/
/*******************************************************************/
#define  cMaxLpScanFlagLen    4

typedef union type_tLpScanFlag{	   //ʱ�ӱ�ʶ

   uint32   Word;
     uint16   UByte[cMaxLpScanFlagLen>>1];
     uint8    Byte[cMaxLpScanFlagLen];
   struct
     {
        uint32 bSys:1;	            //ͬ��״̬,Ϊ1ʱ����������Ѳ�죬����ȴ�ͬ����Ϣ,���ڻ�·�����쳣ʱ����ֹ�ܵ�ַ
                                        //��������>22msʱ�����ͬ����ʶ
            uint32 bAddr:8;	            //��ǰѲ���ַ

            uint32 bComm:2;	            //��ǰѲ��������ݸߵ�ƽ�����ȡ��·�·�����������
            uint32 bState:1;            //״̬���������ʶ
            uint32 bRec0:4;             //δʹ�õ�  4

//���з������ݿ���
            uint32 bAnsFlag:1;          //������Ҫ
            uint32 bAnsStar:1;          //������ʼ��ʶ
            uint32 bAnsStep:4;          //�������ݲ������   0��9  ��10��
            uint32 bAnsTId:3;           //�����������Bitλ��ʱ 600us/100us
            uint32 bReset:1;            //��·��λ��־
    }Bit;
}tLpScanFlag;
/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
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
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CLpScanCtrl_C

tLpScanFlag	m_LpScanFlag;



#endif
#endif







