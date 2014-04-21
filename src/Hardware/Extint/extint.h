/*
;*********************************************************************************************************
;*                                                
;*                            对象: extint
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : extint.h
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
#ifndef __EXTINT__H
#define __EXTINT__H
// #include  "extint.h"
//void  Eint1_Init(void);
void  Eint3_Init(void);
void  SetE1_flag(void);
void  ClrE1_flag(void);
uint8 GetE1_flag(void);
void  SetE3_flag(void);
void  ClrE3_flag(void);
uint8 GetE3_flag(void);
void  cExt3IntFlow(void);
void  cExt3IntRise(void);
void cExt3IntClrFlow(void);
void cExt3IntClrRise(void);
void Eint_Dis(void);
void Eint_En(void);
void Eint_DisAll_Exuart(void);
void Eint_EnAll_Exuart(void);


uint8_t GetSyncFlag(void);
void SyncTimeInit(void);

//void SetSyncTime(uint16_t time);
//uint16_t GetSyncTime(void);
void SetStartSyncms(uint8_t order,uint32_t val);
void PrintP023TiggerInfo(void);//打印pin0.23引脚触发信息



//void setstartsync(void);
//void clrstartsync(void);
//uint8_t getstartsync(void);
//拷贝两次下降沿时长
void vSetFallingCount(uint32_t count);
//uint32_t vGetFallingCount(void);
void vClrFallingCount(void);
//拷贝上升沿时长
void vSetRiseingCount(uint32_t count);
//uint32_t vGetRiseingCount(void);
void vClrRiseingCount(void);

void extint1_disable(void);
void extint1_enable(void);

void extint3_enable(void);
void extint3_disable(void);
#endif /*end __EXTINT__H*/


