/*
;*********************************************************************************************************
;*                                                
;*                            ����: CIntStEnd
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CIntStEnd.c
;* By   : ������
;* ʱ�� : 2013-06-28
;*********************************************************************************************************
;*/
#include "include.h"
#include "CIntStEnd.h" 
#include  "CLpScanCtrl.h"

void EndInt(void)//��ȫ���ж�
{
//	UartIntEnd();
//	I2CIntEnd();
//	disable_timer(0);
//	disable_timer(1);
//    disable_timer(2);

    Eint_Dis();
    ClrSys_CLpScanCtrl();

// 	 EXTINT    = 2;
// 	 EXTINT    = 8;
}
void StartInt(void)//��ȫ���ж�
{
//	UartIntStart();
//	I2CIntStart();
//	enable_timer(0);
//	enable_timer(1);
//    enable_timer(2);

    Eint_En();
// 	EXTINT    = ~(1<<1);
// 	EXTINT    = ~(1 << 3);
}








