/*
;*********************************************************************************************************
;*                                                
;*                            ����: CMaDefine
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CMaDefine.h
;* By   : ������
;* ʱ�� : 2013-06-28
;*********************************************************************************************************
;*/
// #include  "CMaDefine.h"

#define  MAX_LOOP   200  //����·��
#define  DEPART    200  //��������
#define  MAX_COMP    50  //���������
#define  COMP_START  (1)
//#define  CIRADDRESS    100  //��·��ַ���ֵ
#define  MASKSUM    50  //��������

/////////////////////////////////////////////////////////////////////////////
//��������������
#define BEEPOn() 		FIO2SET |= 1<<3    //��������
#define BEEPOff() 	FIO2CLR |= 1<<3     //�ط�����
/////////////////////////////////////////////////////////////////////////////
//LED
#define LED_FireOn() 		FIO2SET |= 1<<6   
#define LED_FireOff() 	FIO2CLR |= 1<<6 
#define LED_WirelessOn() 		FIO2SET |= 1<<4   
#define LED_WirelessOff() 	FIO2CLR |= 1<<4 
#define LED_faultOn() 		FIO2SET |= 1<<5   
#define LED_FaultOff() 	FIO2CLR |= 1<<5 

#define LED_SilenceOn() 		FIO0SET |= 1<<16  //p0.16
#define LED_SilenceOff() 		FIO0CLR |= 1<<16 
/////////////////////////////////////////////////////////////////////////////
