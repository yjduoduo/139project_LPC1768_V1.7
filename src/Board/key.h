/*
;*********************************************************************************************************
;*                                                
;*                            ����: key
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : key.h
;* By   : ������
;* ʱ�� : 2013-06-25
;*********************************************************************************************************
;*/
// #include  "key.h"
#ifndef CKEYDef_H
#define CKEYDef_H

#include 	"config.h"



/*******************************************************************/
/******************       ���ݽṹ����    *********************/
/*******************************************************************/
#define  KEY_Back	   1  //���˼�
#define  KEY_Up      2  //���ϼ�
#define  KEY_Down    3  //���¼�
#define  KEY_Sure    4  //ȷ�ϼ�
#define  KEY_Return  5  //���ؼ�
#define  KEY_Silence 6  //������



#define KEY_P10  (FIO0PIN&(1 << 10))//up
#define KEY_P11  (FIO0PIN&(1 << 11))//down
#define KEY_P25  (FIO0PIN&(1 << 25))//back
#define KEY_P26  (FIO0PIN&(1 << 26))//silence
#define KEY_P29  (FIO0PIN&(1 << 29))//sure
#define KEY_P30  (FIO0PIN&(1 << 30))//return



#define KEY_UP          KEY_P30
#define KEY_DOWN        KEY_P29
#define KEY_SILENCE     KEY_P11
#define KEY_BACK        KEY_P26
#define KEY_OK          KEY_P10
#define KEY_RETURN      KEY_P25
//ȥ��time
#define KEYDELAYTIME 60 //40--10ms  40/3 /2=13.3/2=7






uint8 GetBackValue(void);
void ClrBackValue(void);
void Scan_Key(void);
uint16 Get_KeyValue(void);


void set_up_tkeyflag(void);
void clr_up_tkeyflag(void);
uint8 get_up_tkeyflag(void);

void set_down_tkeyflag(void);
void clr_down_tkeyflag(void);
uint8 get_down_tkeyflag(void);

void set_back_tkeyflag(void);
void clr_back_tkeyflag(void);
uint8 get_back_tkeyflag(void);

void set_silence_tkeyflag(void);
void clr_silence_tkeyflag(void);
uint8 get_silence_tkeyflag(void);

void set_return_tkeyflag(void);
void clr_return_tkeyflag(void);
uint8 get_return_tkeyflag(void);

void set_ok_tkeyflag(void);
void clr_ok_tkeyflag(void);
uint8 get_ok_tkeyflag(void);


//private
#ifdef _KEY_VAR_C

typedef struct KeyValue
{
    uint8	key_back;    //���˼�
    uint8 key_up;      //���ϼ�
    uint8 key_down;    //���¼�
    uint8 key_sure;    //ȷ�ϼ�
    uint8 key_return;  //���ؼ�
    uint8 key_silence; //������
}TdKeyValue,*PdKeyValue;

uint32 vKeyCounter[6] = {0};
uint8 vBackValue=0;



#endif


#endif
