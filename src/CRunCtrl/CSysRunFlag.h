/*
*********************************************************************************************************
*
*                            ����:	CSysRunFlag
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CSysRunFlag.H
* By   : ��ѩ÷
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
/******************       ȫ�ֳ��������     *********************/
/*******************************************************************/
//constant
#define  cNdSampleTest      0


#define  cMaxSysAlarm       63

/*******************************************************************/
/******************       ���ݽṹ�����     *********************/
/*******************************************************************/
#define  cMaxSysRunFlagLen    4

typedef union type_tSysRunFlag{	   //ʱ�ӱ�ʶ

    uint32   Word;
    uint16   UByte[cMaxSysRunFlagLen>>1];
    uint8    Byte[cMaxSysRunFlagLen];
    struct
    {
        uint32 b20ms:1;	          //10ms ��ʱ��ʶ
        uint32 b40ms:1;            //40ms
        uint32 b50ms:1;	          //50ms ��ʱ��ʶ
        uint32 b100ms:1;
        uint32 b1s:1;
        uint32 b5s:1;
        uint32 b1m:1;             //1min
        uint32 bReset:1;
        uint32 bReg:1;
        uint32 bAlarm:1;	        //������ʶ
        uint32 bDisHis:1;	        //��ֹд��ʷ��¼��ʶ,��ֹ©����ַ

    }Bit;
}tSysRunFlag;
/*******************************************************************/
/****************     ���г�Ա����,����������     ******************/
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
/********************* ˽�г�Ա����,����������    *******************/
/*******************************************************************/
//Private:
#ifdef  CSysRunFlag_C

tSysRunFlag	m_SysRunFlag; //��ǰʱ��

#endif
#endif







