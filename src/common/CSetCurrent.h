/*
;*********************************************************************************************************
;*                                                
;*                            ����: CSetCurrent
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CSetCurrent.h
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CSetCurrent.h"

extern void State_6mA(void);
extern void State_20mA(void);
extern void State_0mA(void);

//��ȡLOOP_LD��״̬
//extern uint8 get_loopLD_state(void);
extern void clr_loop_LD_counter(void);
extern void loop_LD_state(void);
//��ӡ״̬��Ϣ
void state_loopld_printf(void);

//�Ƿ��ӡ��־
void set_print(void);

uint32 get_loopLD_state(void);
void set_loopldbuf(uint8 bufcounter,uint8 val);
void add_bufcounter(void);
uint8 get_bufcounter(void);
void printbuf(uint8* buf,uint8 size);
// void info_loopldbuf(void);
// void clr_loopldbuf(void);
void clrbuf(uint8* buf,uint8 size);
