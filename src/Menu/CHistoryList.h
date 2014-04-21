/*
;*********************************************************************************************************
;*                                                
;*                            对象: CHistoryList
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CHistoryList.h
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/
// #include  "Config.h"
// #include  "CHistoryList.h"

/****************************************************************
  ****************[设备类型定义]*******************************
  ***************************************************************/
#define DEVTYPE_GANYAN      (0x30)
#define DEVTYPE_GANWEN      (0x31)
#define DEVTYPE_SHOUBAO     (0x32)
#define DEVTYPE_XIAOBAO     (0x33)
#define DEVTYPE_INPUT       (0x34)
#define DEVTYPE_OUTPUT      (0x35)
#define DEVTYPE_SHENGGUANG  (0x36)





void History_Menu(uint8 num1,uint8 address,uint8 type,uint8 alarmType,uint8 part,PCF8563_DATE* TimeAndDate);
void menu_nohistory(void);
void menu_history_over(void);



