/*
;*********************************************************************************************************
;*                                                
;*                            对象: main
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : main.c
;* By   : 尹海星
;* 时间 : 2013-06-8
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

int main (void) 
{
    SystemClockUpdate();
    Init_CRunCtrl();
//    DebugOnce("-->>CMD_ALARM!!!\n");
    DebugOnce("=====hello 139 wireless mod==========\n");
    while ( 1 )
    {
        do_CRunCtrl();
    }
}
