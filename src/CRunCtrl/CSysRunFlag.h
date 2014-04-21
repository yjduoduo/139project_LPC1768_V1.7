/*
*********************************************************************************************************
*
*                            对象:	CSysRunFlag
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CSysRunFlag.H
* By   : 蒋雪梅
*********************************************************************************************************
*/
//#include  "CSysRunFlag.h"

#ifndef CSysRunFlag_H
#define CSysRunFlag_H

#include  "Config.h"


#ifdef  CSysRunFlag_C
#define Ex_CSysRunFlag
#else
#define Ex_CSysRunFlag extern
#endif

/*******************************************************************/
/******************       全局常量定义�     *********************/
/*******************************************************************/
//constant
#define  cNdSampleTest      0


#define  cMaxSysAlarm       63

/*******************************************************************/
/******************       数据结构定义�     *********************/
/*******************************************************************/
#define  cMaxSysRunFlagLen    4

typedef union type_tSysRunFlag{	   //时钟标识

    uint32   Word;
    uint16   UByte[cMaxSysRunFlagLen>>1];
    uint8    Byte[cMaxSysRunFlagLen];
    struct
    {
        uint32 b20ms:1;	          //10ms 定时标识
        uint32 b40ms:1;            //40ms
        uint32 b50ms:1;	          //50ms 定时标识
        uint32 b100ms:1;
        uint32 b1s:1;
        uint32 b5s:1;
        uint32 b1m:1;             //1min
        uint32 bReset:1;
        uint32 bReg:1;
        uint32 bAlarm:1;	        //报警标识
        uint32 bDisHis:1;	        //禁止写历史记录标识,防止漏数地址

    }Bit;
}tSysRunFlag;
/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:

Ex_CSysRunFlag  void  InitC_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr20ms_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set20ms_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get20ms_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr50ms_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set50ms_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get50ms_CSysRunFlag(void);

Ex_CSysRunFlag  void  ClrReset_CSysRunFlag(void);
Ex_CSysRunFlag  void  SetReset_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 GetReset_CSysRunFlag(void);

Ex_CSysRunFlag  void  ClrReg_CSysRunFlag(void);
Ex_CSysRunFlag  void  SetReg_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 GetReg_CSysRunFlag(void);

Ex_CSysRunFlag  void  ClrAlarm_CSysRunFlag(void);
Ex_CSysRunFlag  void  SetAlarm_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 GetAlarm_CSysRunFlag(void);

Ex_CSysRunFlag  void  ClrDisHis_CSysRunFlag(void);
Ex_CSysRunFlag  void  SetDisHis_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 GetDisHis_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr5s_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set5s_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get5s_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr1s_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set1s_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get1s_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr1m_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set1m_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get1m_CSysRunFlag(void);

Ex_CSysRunFlag  void  Clr100ms_CSysRunFlag(void);
Ex_CSysRunFlag  void  Set100ms_CSysRunFlag(void);
Ex_CSysRunFlag  uint8 Get100ms_CSysRunFlag(void);

Ex_CSysRunFlag void  Clr40ms_CSysRunFlag(void);
Ex_CSysRunFlag void  Set40ms_CSysRunFlag(void);
Ex_CSysRunFlag uint8 Get40ms_CSysRunFlag(void);
/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
#ifdef  CSysRunFlag_C

tSysRunFlag	m_SysRunFlag; //当前时钟

#endif
#endif







