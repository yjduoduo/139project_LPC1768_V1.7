/*
;*********************************************************************************************************
;*                                                
;*                            ����: CComPara
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CComPara.h
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CComPara.h"
#include "config.h"
#ifndef __UARTPara_H 
#define __UARTPara_H


#pragma pack(1)	
typedef struct{
	uint8 	header;	//�ļ�ͷ
	uint8	  cmd;   //����
	uint32  addr; //��ַ
	uint8   attr;//����  0x30 ����0x31 ����0x32 �ֱ�0x33 ����0x34 ����ģ��0x35 �������0x36 ���ⱨ��
	uint8   detail;//��������	
	uint8	cs;	//У���
}TdUartMsg,*PdUartMsg;
typedef struct{
	uint8 	header;	//�ļ�ͷ
	uint8	  cmd;   //����
	uint8 	addr[4]; //��ַ
	uint8   attr;//����
	uint8   detail;//��������	
	uint8	cs;	//У���
}TdUartMsgDetail,*PdUartMsgDetail;
#pragma pack()
typedef union{
	TdUartMsg	UartMsg;
	TdUartMsgDetail	UartMsgDetail;
	uint8	UartMsgArray[sizeof(TdUartMsg)];
}TdUartMsgUnion,*PdUartMsgUnion;


#define POS_ALARM_BIT 0  //pos 0:intent for alarm(fire,fault,batt low)
#define POS_INQUIRY_BIT 1 //pos 1:intent for uart inquiry data(uart 0)

#define RCV_SIZE 20

#ifdef ComPara_C
uint8 dataHeart[2]={0};
uint8 data[RCV_SIZE][9]={0};//������Ϣ����
uint8 dataCount=0;//���ݼ���
uint8 data1[10]={0};//�жϽ��ջ���
uint8 temp = 0;

uint32 vBattLowSum = 0;
uint32 vBrokenSum = 0;

uint8 vCom0Data[20]={0};//����0����
uint8 vCom0Count=0;//����0����

uint8 vHeartFaultFlag=0;
uint8 vAlarmFlag[2]={0};//one for alarm sound,the orther for uart inquiry
uint8 FirstAlarm_Addr[2]={0};
// extern uint8 AlarmInfo[ALARM_LLEN][ALARM_RLEN];
//extern uint8 AlarmInfo[20][13];
uint8 vAlarmInfoFlag=0;
uint8 AlarmFlag[4]={0};
uint8 vReleaseFlag=0;
uint8 vFlag_195=0;
uint8 vCirAddrCurrent=0;
uint8 vCirAlarmData[MAX_COMP]={0};
uint8 vFlagLed=0;
//uint8 SpeakerFlag=FALSE;
#endif

uint8 GetHeart(uint8 row);
void ReadHeart(void);
void data_from_data0(void);//������1����
//void ReadCom0Data(uint8 tmp);
void ClrComData(uint8 row);//����������
// PdUartMsgUnion GetComData(void);
PdUartMsgUnion GetComData(uint8 row);
uint8 get_dataCount(void);
void AddBattLowSum(void);
uint32 GetBattLowSum(void);

void AddBrokenSum(void);
uint32 GetBrokenSum(void);


//����3����������
void MergeData(void);
void Com0DataUnzip(void);
void Com0Handle(void);

void SetHeartFaultFlag(void);
void ClrHeartFaultFlag(void);
uint8 GetHeartFaultFlag(void);

void SetAlarmFlag(uint8 row,uint8 tmp);
uint8 GetAlarmFlag(uint8 row);

//void SetFirstAlarm_Addr(uint8 row,uint8 tmp);
uint8 GetFirstAlarm_Addr(uint8 row);

//void AlarmInfoInit(void);
//uint8 GetAlarmInfo(uint8 row,uint8 col);
//void SetAlarmInfo(uint8 row,uint8 col,uint8 tmp);
void AddAlarmInfoFlag(void);
void SubAlarmInfoFlag(void);
void SetAlarmInfoFlag(uint8 tmp);
uint8 GetAlarmInfoFlag(void);


void SetReleaseFlag(uint8 tmp);
uint8 GetReleaseFlag(void);

void SetFlag_195(uint8 tmp);
uint8 GetFlag_195(void);

void SetCirAddrCurrent(uint8 tmp);
uint8 GetCirAddrCurrent(void);
void CompareCirAddr(void);
void Init_CirAddrInfo(void);
void ClrCirAlarmData(void);
//void SetCirAlarmData(uint8 row,uint8 tmp);
//uint8 GetCirAlarmData(uint8 row);
void CirAlarmDataInit(void);

void SetFlagLed(uint8 tmp);
uint8 GetFlagLed(void);
////set and get speaker blank
//void SetSpeakerClick(uint8 val);
//uint8 GetSpeakerClick(void);


#endif /* end __UARTPara_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/


