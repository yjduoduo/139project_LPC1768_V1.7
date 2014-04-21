/*
*********************************************************************************************************
*
*                            ??:	CNodeInfo
*
*                        (c) Copyright 2000-2006, ???
*                              All Rights Reserved
*                                    Ver1.5
* File : CNodeInfo.H
* By   : ???
*********************************************************************************************************
*/
//#include  "CNodeInfo.h"

#ifndef CNodeInfo_H
#define CNodeInfo_H

#include  "Config.h"
#include  "CLpInfoDef.h"

#ifdef  CNodeInfo_C
#define Ex_CNodeInfo
#else
#define Ex_CNodeInfo extern
#endif

/*******************************************************************/
/******************       ???????    *********************/
/*******************************************************************/
//constant
#define  cMaxNodeNum    255

#define  cMinNodeAddrNum    1
#define  cMaxNodeAddrNum    216


#define  cMaxNodeAddrRegNum   253
#define  cMinNodeAddrBkNum    216
#define  cMaxNodeAddrBkNum    218



/*******************************************************************/
/******************       ???????    *********************/
/*******************************************************************/
#define  cMaxNodeInfoLen    4

typedef union type_tNodeInfo{	   //????

    uint32   Word;
    uint16   UByte[cMaxNodeInfoLen>>1];
    uint8    Byte[cMaxNodeInfoLen];
    struct
    {
        uint32 bReset:1;
        uint32 bCkCyc:4;	       //????????
        uint32 bResetCyc:2;	     //????????
        uint32 bComm:2;	         //????
        ///////////////////////////////////////////////////////////////
        uint32 bFault:1;	           //????
        uint32 bFaultCyc:3;	         //??????
        uint32 bReg:1;	         //?????
        uint32 bState:2;	       //????
        uint32 bAlarm:1;	       //??????

    }Bit;
}tNodeInfo;
/*******************************************************************/
/****************     ??????,?????     ******************/
/*******************************************************************/
//public:

Ex_CNodeInfo  void  Init_CNodeInfo(void);

Ex_CNodeInfo  void    SetState_CNodeInfo(uint8 vAddr,uint8 vType);
Ex_CNodeInfo  uint8   GetState_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    ClrState_CNodeInfo(uint8 vAddr);

Ex_CNodeInfo  void    ClrReset_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    SetReset_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  uint8   GetReset_CNodeInfo(uint8 vAddr);

Ex_CNodeInfo  void    ClrReg_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    SetReg_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  uint8   GetReg_CNodeInfo(uint8 vAddr);

Ex_CNodeInfo  void    ClrAlarm_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    SetAlarm_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  uint8   GetAlarm_CNodeInfo(uint8 vAddr);

Ex_CNodeInfo  void    ClrMax_CNodeInfo(void);
Ex_CNodeInfo  void    SetMax_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  uint8   GetMax_CNodeInfo(void);

//?????????
Ex_CNodeInfo  void    SetComm_CNodeInfo(uint8 vAddr,uint8 vType);
Ex_CNodeInfo  uint8   GetComm_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    ClrComm_CNodeInfo(uint8 vAddr);

//???????????
Ex_CNodeInfo  void    SetCkCyc_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  uint8   GetCkCyc_CNodeInfo(uint8 vAddr);
Ex_CNodeInfo  void    ClrCkCyc_CNodeInfo(uint8 vAddr);



/*******************************************************************/
/********************* ??????,?????    *******************/
/*******************************************************************/
//Private:
#ifdef  CNodeInfo_C

static  uint8 m_MaxNodeAddr;   //?????????

tNodeInfo	m_NodeInfo[cMaxNodeNum]; //

#endif
#endif







