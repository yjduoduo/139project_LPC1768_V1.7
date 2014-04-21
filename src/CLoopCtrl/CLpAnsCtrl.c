/*

*********************************************************************************************************
*                                                
*                              对象:	CLpAnsCtrl
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpAnsCtrl.C
* By   : 蒋雪梅
*********************************************************************************************************
*/
#define    CLpAnsCtrl_C
#include   "CLpAnsCtrl.h"
#include   "CSetCurrent.h"
#include   "CNodeInfo.h"
#include   "CLpInfoDef.h" 


void  Init_CLpAnsCtrl(void)
{

}  

uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState)
{
    uint8  vData=0;
    if(vComm == cLpScanComm_D4)
    {
        if(vState < cMaxNodeStateNum)
        {
            vData=m_LpAnsD4[vState];
        }
    }
    else if(vComm == cLpScanComm_D8)
    {
        if(vState < cMaxNodeStateNum)
        {
            vData=m_LpAnsD8[vState];
        }
    }
    else if(vComm == cLpScanComm_D12)
    {
        if(vState < cMaxNodeD12Num)
        {
            vData=m_LpAnsD12[vState];
        }
    }
    return vData;
} 

//转换输出数据，从高位开始转出   
void  SetData_CLpAnsCtrl(uint8 vSndData)
{
    uint8  i;
    uint8  j;
    uint8  vData=vSndData;
    for(i=0;i<cMaxLpScanAnsStep;i++)
    {
        m_LpAnsFlag[i]=0;
    }
    j=1;
    for(i=0;i<8;i++)
    {
        if(vData & 0x01)
        {
            m_LpAnsFlag[j]=cLpAnsLogo1;
        }
        else
        {
            m_LpAnsFlag[j]=cLpAnsLogo0;
        }
        j++;
        vData=vData>>1;
    }
    // 		for(i=0;i<8;i++)
    // 		{
    // 			 if(vData & 0x80)
    // 			 {
    // 			     m_LpAnsFlag|=cLpAnsLogo1;
    // 			 }
    // 		   else
    // 			 {
    // 			     m_LpAnsFlag|=cLpAnsLogo0;
    // 			 }
    // 			 vData=vData<<1;
    // 			 m_LpAnsFlag=m_LpAnsFlag<<2;
    // 		}
    // //     m_LpAnsFlag=m_LpAnsFlag<<2;   //同步电平
    //     m_LpAnsFlag=m_LpAnsFlag<<2;   //状态电平
    //     m_LpAnsFlag|=cLpAnsLogo0;
} 

void  OutData_CLpAnsCtrl(uint8 vId)
{
    if(vId < cMaxLpAnsOutBit)
    {
        uint8 vData= m_LpAnsFlag[vId];
        if(vData == cLpAnsLogo0)
        {
            State_6mA();
        }
        else if(vData == cLpAnsLogo1)
        {
            State_20mA();
        }
        else
        {
            State_0mA();
        }
        // 		    uint16 vMoveBit=vId*2;
        // 		    uint16 vData=(m_LpAnsFlag>>vMoveBit)&3;
        //
        // 				if(vData == cLpAnsLogo0)
        // 				{
        // 				    State_6mA();
        // 				}
        // 				else if(vData == cLpAnsLogo1)
        // 				{
        // 				    State_20mA();
        // 				}
        // 				else
        // 				{
        // 				    State_0mA();
        // 				}
    }
} 

void  OutState_CLpAnsCtrl(uint8 vData) 
{ 	
    if(vData == cNodeState_Normal)
    {
        State_6mA();
    }
    else if(vData == cNodeState_Alarm)
    {
        State_20mA();
    }
    else
    {
        State_0mA();
    }
} 


