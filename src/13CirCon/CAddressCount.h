/*
;*********************************************************************************************************
;*                                                
;*                            对象: CComPara
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CAddressCount.h
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CAddressCount.h"

void AddCirCounter(void);
uint32 GetCirCounter(void);
//void Reset_Alarm(void);
void Clr_Alarm(void);
//void CirAddrCounter(void);
//void Check_Addr(uint8 Current_Addr);
//void Sel_Addr_fire(uint8 Current_Addr);
//void CirSendAlarmInfo(void);
//void CirSendFireInfo(void);
//uint8 Compare_Address(uint8 addr);
void SetAlarm_Circuit_Flag(uint8 tmp);

//sync flag
void SetSync(void);
uint8 GetSync(void);
void ClrSync(void);

//
uint32 SyncFlagCounter(void);
void ClrCirCounter(void);
void addxialasignal(void);
uint8 getxialasignal(void);
void add_weixialasignal(void);

void clr_weixialasignal(void);
void clr_xialasignal(void);
