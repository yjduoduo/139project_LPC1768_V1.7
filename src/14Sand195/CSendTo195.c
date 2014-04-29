/*
;*********************************************************************************************************
;*                                                
;*                            对象: CSendTo195
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CSendTo195.c
;* By   : 尹海星
;* 时间 : 2013-09-22
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CSendTo195.h"
#include  "CComHandle.h"

#define	CONVERT195(X)	((X&0x00ff)*256+(X&0xff00)/256)//高低位转换
#define  SEND195LEN   15
uint8 Send195[15]={0};

/******************************
  ******反馈给模块**************/
#define  SENDV75LEN   9
uint8 SendVH75[SENDV75LEN]={0};




void SaveData195(uint8 col,uint8 tmp)
{
	Send195[col]=tmp;
}
uint8 GetData195(uint8 col)
{
	return Send195[col];
}
/*******************数据组包*************************/
//串口0查询命令后回复
void Query_ByUart0(uint8 data3,uint8 data9,uint8 ciraddr)
{
	uint8 num;
	uint16 dat;
	dat = 0;
//FF FF FF CMD 00 00 DSTADDR SRCADDR LEN DATA
	Send195[0]=0xff;
	Send195[1]=0xff;
    Send195[2]=0xff;//HEADER
    Send195[3]=data3;//CMD
	Send195[4]=0x00;
	Send195[5]=0x00;
    Send195[7]=0x01;//DSTADDR
    Send195[6]=0x6e;//SRCADDR
    Send195[8]=0x04;//LEN
    Send195[9]=data9;//FLAG 标志
    Send195[10]=0x01;//控制器地址
    Send195[11]=0x01;//回路
//    Send195[12]=data12;//报警地址
    Send195[12]=ciraddr;//ADDR //地址改为固定0x01
	for(num = 0; num < 10; num++)					//checksum calculate 
		dat += Send195[num+3];
    Send195[13]=(uint8)CONVERT195((dat&0xff00));//HIGH CS
    Send195[14]=(uint8)(dat&0x00ff);//LOW CS
//    check_lp_running();
 	UARTSend(0,Send195,SEND195LEN);
}
//火警状态下给vh75探头的反馈使之停发
void uart1_stop_reponse_atfire(uint8 PSN3,uint8 PSN2,uint8 PSN1,uint8 PSN0)
{
    uint8 num;
    uint16 dat;
    dat = 0;
//    Debug("send response:%d,%d,%d,%d\n",PSN3,PSN2,PSN1,PSN0);
//0x82 0x40 psn3 psn2 psn1 psn0 status val cs
    SendVH75[0]=0x82;
    SendVH75[1]=0x40;
    SendVH75[2]=PSN3;
    SendVH75[3]=PSN2;
    SendVH75[4]=PSN1;
    SendVH75[5]=PSN0;
    SendVH75[6]=ATTR_FIRE;//
    SendVH75[7]=0x00;//
    for(num = 1; num < 8; num++)					//checksum calculate
        dat += SendVH75[num];
    SendVH75[8]=(uint8)(dat&0xff);//CS
    UARTSend(1,SendVH75,SENDV75LEN);
}

//火警状态下给vh75探头的反馈消音
void uart1_offsound_reponse_atfire(uint8 PSN3,uint8 PSN2,uint8 PSN1,uint8 PSN0)
{
    uint8 num;
    uint16 dat;
    dat = 0;
//    Debug("send response:%d,%d,%d,%d\n",PSN3,PSN2,PSN1,PSN0);
//0x82 0x42 psn3 psn2 psn1 psn0 status val cs
    SendVH75[0]=0x82;
    SendVH75[1]=0x42;
    SendVH75[2]=PSN3;
    SendVH75[3]=PSN2;
    SendVH75[4]=PSN1;
    SendVH75[5]=PSN0;
    SendVH75[6]=0x30;//
    SendVH75[7]=0x00;//
    for(num = 1; num < 8; num++)					//checksum calculate
        dat += SendVH75[num];
    SendVH75[8]=(uint8)(dat&0xff);//CS
    UARTSend(1,SendVH75,SENDV75LEN);
}
