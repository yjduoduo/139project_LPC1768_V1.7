/*
;*********************************************************************************************************
;*                                                
;*                            ����: batteryLow
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CSysReset.c
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CSysReset.h"

void Menu_complete(void)
{
    uint8 hz[]="��λ���";
	//���
    DisplayJBHZK(1,2,32,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,2,48,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(2,2,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,2,16,((hz[6]<<8)+hz[7]));
	//�˳�
// 	Display(2,6,32,1382);
// 	Display(2,6,48,294);
//    menu_press_return_toreturn();
}

