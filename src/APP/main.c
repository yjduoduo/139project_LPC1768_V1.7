/*
;*********************************************************************************************************
;*                                                
;*                            ����: main
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : main.c
;* By   : ������
;* ʱ�� : 2013-06-8
;*********************************************************************************************************
;*/
#include "LPC17xx.H"                        /* LPC23xx/LPC24xx definitions */
#include <stdio.H>    					   	//kk
#include "type.h"

#include "main.h"
#include  "include.h"
#include  "CRunCtrl.h"  


#define PORT_NUM			1
#define LOCATION_NUM		0

#ifndef _PREFIX_STR
#define _PREFIX_STR ""
#endif
#define VERSION(A) _PREFIX_STR #A

const char version_139[] = VERSION(v2.0.0.8);

int main (void) 
{
    SystemClockUpdate();
    Init_CRunCtrl();
//    DebugOnce("-->>CMD_ALARM!!!\n");
    DebugOnce("=====hello 139 wireless mod==========\n");
    DebugOnce("=====version[%s]==========\n",version_139);
    while ( 1 )
    {
        do_CRunCtrl();
    }
}
