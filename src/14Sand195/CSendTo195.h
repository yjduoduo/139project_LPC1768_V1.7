/*
;*********************************************************************************************************
;*                                                
;*                            对象: CSendTo195
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CSendTo195.h
;* By   : 尹海星
;* 时间 : 2013-09-22
;*********************************************************************************************************
;*/
// #include  "CSendTo195.h"


void SaveData195(uint8 col,uint8 tmp);
uint8 GetData195(uint8 col);
void Query_ByUart0(uint8 data3,uint8 data9,uint8 ciraddr);
void uart1_stop_reponse_atfire(uint8 PSN3,uint8 PSN2,uint8 PSN1,uint8 PSN0);
void uart1_offsound_reponse_atfire(uint8 PSN3,uint8 PSN2,uint8 PSN1,uint8 PSN0);


