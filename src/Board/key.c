/*
;*********************************************************************************************************
;*                                                
;*                            对象: key
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : key.c
;* By   : 尹海星
;* 时间 : 2013-06-25
;*********************************************************************************************************
;*/
#define KEY_C
#include  "include.h"
#include  "key.h"
#include  "CTime.h"
#include  "CComPara.h"
#include "CLED.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"

#define KEY_P10  (FIO0PIN&(1 << 10))
#define KEY_P11  (FIO0PIN&(1 << 11))
#define KEY_P25  (FIO0PIN&(1 << 25))
#define KEY_P26  (FIO0PIN&(1 << 26))
#define KEY_P29  (FIO0PIN&(1 << 29))
#define KEY_P30  (FIO0PIN&(1 << 30))

#define SW4  KEY_P10
#define SW5  KEY_P11
#define SW2  KEY_P25
#define SW3  KEY_P26
#define SW6  KEY_P29
#define SW7  KEY_P30

PdKeyValue vKeyValue;
// uint16 Key_Read(void)
uint8 GetBackValue(void)
{
	return vBackValue;
}
void ClrBackValue(void)
{
	vBackValue=0;
}
void Scan_Key(void)
{ 
	
	if(!KEY_P10) //确定键
	{  	
		vKeyCounter[0]++;
		if(vKeyCounter[0] == 3)
		{
			disable_timer(1);
		}
		OpenLCD();
	}
	else
	{
		vKeyCounter[0] = 0;
	}
	if(!KEY_P11)//静音键
	{
		vKeyCounter[1]++;
		if(vKeyCounter[1] == 3)
		{
			disable_timer(1);
		}
// 		BEEPOff();
		SetAlarmFlag(0,0);
		if(GetDisplay_alarm_flag())
			Led_Silence_On();
		OpenLCD();
	}
	else
	{
		vKeyCounter[1] = 0;
	}
	if(!KEY_P25)//返回键
	{
		vKeyCounter[2]++;
		if(vKeyCounter[2] == 3)
		{
			disable_timer(1);
		}
		if(!GetDisplay_alarm_flag())
			Led_Silence_Off();
		OpenLCD();
	}
	else
	{
		vKeyCounter[2] = 0;
	}
	if(!KEY_P26)//回退键
	{
		
		vKeyCounter[3]++;
		if(vKeyCounter[3] == 3)
		{
			disable_timer(1);
		}
		OpenLCD();
	}
	else
	{
		vKeyCounter[3] = 0;
	}
	if(!KEY_P30)//向上键
	{
		vKeyCounter[4]++;
		if(vKeyCounter[4] == 3)
		{
			disable_timer(1);
		}
		OpenLCD();
	}
	else
	{
		vKeyCounter[4] = 0;
	}
	if(!KEY_P29)//向下键
	{
		vKeyCounter[5]++;
		if(vKeyCounter[5] == 3)
		{
			disable_timer(1);
		}
		OpenLCD();
	}
	else
	{
		vKeyCounter[5] = 0;
	}
}
uint16 CGet_KeyValue(void)
{
	uint8 temp=0;
	
	if(vKeyCounter[0] == 3)
	{
		if(KEY_P10)
		{
			vKeyCounter[0] = 0;
			enable_timer(1);
// 			vKeyValue->key_sure = 1;
// 			temp=vKeyValue->key_sure;	
 			temp = KEY_Sure;
		}
	}
	if(vKeyCounter[1] == 3)
	{
		if(KEY_P11)
		{
			vKeyCounter[1] = 0;
			enable_timer(1);
// 			vKeyValue->key_silence = 1;
// 			temp=vKeyValue->key_silence;
 			temp = KEY_Silence;
			BEEPOff();
			PWM1_Stop();
			CSetAlarmFlag(0,0);
		}
	}
	if(vKeyCounter[2] == 3)
	{
		if(KEY_P25)
		{
			vKeyCounter[2] = 0;
			enable_timer(1);
// 			vKeyValue->key_return = 1;
// 			temp=vKeyValue->key_return;
 			temp = KEY_Return;
		}
	}
	if(vKeyCounter[3] == 3)
	{
		if(KEY_P26)
		{
			vKeyCounter[3] = 0;
			enable_timer(1);
			if(GetPasswordFlag())
				ClrBackValue();
			else
				vBackValue++;
// 			vKeyValue->key_back = 1;
// 			temp=vKeyValue->key_back;
			temp = KEY_Back;
		}
	}
	if(vKeyCounter[4] == 3)
	{
		if(KEY_P30)
		{
			vKeyCounter[4] = 0;
			enable_timer(1);
// 			vKeyValue->key_up = 1;
// 			temp=vKeyValue->key_up;
 			temp = KEY_Up;
		}
	}
	if(vKeyCounter[5] == 3)
	{
		if(KEY_P29)
		{
			vKeyCounter[5] = 0;
			enable_timer(1);
// 			vKeyValue->key_down = 1;
// 			temp=vKeyValue->key_down;
 			temp = KEY_Down;
		}
	}
	return temp;
}



