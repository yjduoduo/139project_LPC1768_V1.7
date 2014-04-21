/*
;*********************************************************************************************************
;*                                                
;*                            对象: key
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : key.h
;* By   : 尹海星
;* 时间 : 2013-06-25
;*********************************************************************************************************
;*/
// #include  "key.h"
#ifndef CKEYDef_H
#define CKEYDef_H

#include 	"config.h"



/*******************************************************************/
/******************       数据结构定义    *********************/
/*******************************************************************/
#define  KEY_Back	   1  //回退键
#define  KEY_Up      2  //向上键
#define  KEY_Down    3  //向下键
#define  KEY_Sure    4  //确认键
#define  KEY_Return  5  //返回键
#define  KEY_Silence 6  //消音键



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
//去抖time
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
    uint8	key_back;    //回退键
    uint8 key_up;      //向上键
    uint8 key_down;    //向下键
    uint8 key_sure;    //确认键
    uint8 key_return;  //返回键
    uint8 key_silence; //消音键
}TdKeyValue,*PdKeyValue;

uint32 vKeyCounter[6] = {0};
uint8 vBackValue=0;



#endif


#endif
