/*
;*********************************************************************************************************
;*                                                
;*                            对象: runfunction
;*
;*                        (c) Copyright 2013-2023, xiaoweilai
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : runfunction.c
;* By   : xiaoweilai
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
#ifndef __RUNFUNCTION__H
#define __RUNFUNCTION__H
//#include  "runfunction.h"
#include  "CFlashParam.h"

//main:首页面，firealarm:火警页面，run:正常页面
#define MENU_MAIN       (0)
#define MENU_FIREALARM  (1)
#define MENU_RUN    (2)
#define MENU_FAULTALARM (0x03)

//wireless fault interface
#define MENU_WIRELESS_FAULT (0x04)
#define MENU_OFFLINE   (0x05)


//报警类型定义
#define ALARM_NORMAL 0//正常
#define ALARM_FIRE 1//火警
#define ALARM_BAT_LOW 2//电池欠压
#define ALARM_FAULT 3//故障
#define ALARM_WIRELESS_FAULT 4

#define PAGE_AT_NORMAL   (0)
#define PAGE_AT_FIRE     (1)
#define PAGE_AT_BATLOW   (2)
#define PAGE_AT_FAULT    (3)



//void Run_Task(void);
//void CSaveHist(void);
void DisplayKeyMenu(void);
void Systemp_Task(void);
void SendHeart(void);
//void BreezeAlarm(void);
void CS0Setup(uint8 tmp);
void inqury_state__byuart0(void);
//void DisplayAlarmInfo(void);
//显示首页
void show_head_menu(void);
void set_history_alarm_pos(uint16 pos);

void set_menu_alarm_info(alarminfo alarm_info);
void set_menu_faultalarm_info(alarminfo alarm_info);

void clr_alarm_loop_show(void);
void set_alarm_loop_show(void);
uint8 get_alarm_loop_show(void);

#ifdef _VAR_RUNFUNCTION
//Get5s_CSysRunFlag
#define TIME_ONE 1  //one time
#define TIME_TWO 2  //two time
#define TIME_THR 3  //three time

//heart lost times
#define HEARTLOSTTIMES 3
//心跳时间设置
static uint8 time_sendheart;
volatile uint8 loopflag=0; //火警时界面轮显循环显示
volatile uint8 loopflag_fault=0; //故障时界面轮显循环显示
#endif

#endif
