/*
;*********************************************************************************************************
;*                                                
;*                            对象: runfunction
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : runfunction.c
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
//#include  "runfunction.h"
#include  "CFlashParam.h"

//main:首页面，firealarm:火警页面，run:正常页面
#define MENU_MAIN       (0)
#define MENU_FIREALARM  (1)
#define MENU_RUN    (2)
#define MENU_FAULTALARM (0x03)

//wireless fault interface
#define MENU_WIRELESS_FAULT (3)



//报警类型定义
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

#ifdef _VAR_RUNFUNCTION
//Get5s_CSysRunFlag
#define TIME_ONE 1  //one time
#define TIME_TWO 2  //two time
#define TIME_THR 3  //three time

//heart lost times
#define HEARTLOSTTIMES 3
//心跳时间设置
static uint8 time_sendheart;

#endif
