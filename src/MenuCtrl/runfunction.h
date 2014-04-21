/*
;*********************************************************************************************************
;*                                                
;*                            ����: runfunction
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : runfunction.c
;* By   : ������
;* ʱ�� : 2013-06-8
;*********************************************************************************************************
;*/
//#include  "runfunction.h"
#include  "CFlashParam.h"

//main:��ҳ�棬firealarm:��ҳ�棬run:����ҳ��
#define MENU_MAIN       (0)
#define MENU_FIREALARM  (1)
#define MENU_RUN    (2)
#define MENU_FAULTALARM (0x03)

//wireless fault interface
#define MENU_WIRELESS_FAULT (3)



//�������Ͷ���
#define ALARM_FIRE 1//��
#define ALARM_BAT_LOW 2//���Ƿѹ
#define ALARM_FAULT 3//����
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
//��ʾ��ҳ
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
//����ʱ������
static uint8 time_sendheart;

#endif
