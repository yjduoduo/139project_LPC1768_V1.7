/*

*********************************************************************************************************
*                                                
*                              ����:	CLpScanCtrl
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpScanCtrl.C
* By   : ��ѩ÷
*********************************************************************************************************
*/
#define    CLpScanCtrl_C
#include   "CLpScanCtrl.h"


void  Init_CLpScanCtrl(void)
{
    m_LpScanFlag.Word=0;
}

void  NewNode_CLpScanCtrl(void)
{
    m_LpScanFlag.Word &= (0x1ff);  //����ڵ�����б�ʶ
}   
//ͬ����־
void  SetSys_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bSys=1;
} 

//ͬ����־
uint8  GetSys_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bSys;
}
//��ͬ����־
void  ClrSys_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bSys=0;
}


void  SetAddr_CLpScanCtrl(uint8 vType)
{
    m_LpScanFlag.Bit.bAddr=vType;
} 

//��ȡ��·��ַ���˺����Ŀ�����������
//_ǰ����Ǻ�����_������Ǵ��ļ�������
uint8  GetAddr_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bAddr;
}

void  ClrAddr_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bAddr=0;
}

void   IncAddr_CLpScanCtrl(void)
{
    if(m_LpScanFlag.Bit.bAddr < 255)
    {
        m_LpScanFlag.Bit.bAddr++;
    }
    NewNode_CLpScanCtrl();
}

void  SetComm_CLpScanCtrl(uint8 vType)
{
    m_LpScanFlag.Bit.bComm=vType;
} 

uint8  GetComm_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bComm;
}

void  ClrComm_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bComm=0;
}


void  SetState_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bState=1;
} 

uint8  GetState_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bState;
}

void  ClrState_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bState=0;
}

void  SetAnsFlag_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bAnsFlag=1;
} 

uint8  GetAnsFlag_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bAnsFlag;
}

void  ClrAnsFlag_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bAnsFlag=0;
} 

void  SetAnsStar_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bAnsStar=1;
} 

uint8  GetAnsStar_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bAnsStar;
}

void  ClrAnsStar_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bAnsStar=0;
} 

void  SetAnsStep_CLpScanCtrl(void)
{
    if(m_LpScanFlag.Bit.bAnsStep < cMaxLpScanAnsStep)
    {
        m_LpScanFlag.Bit.bAnsStep++;
    }
    else
    {
        m_LpScanFlag.Bit.bAnsStep=0;
    }
} 

uint8  GetAnsStep_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bAnsStep;
}

void  ClrAnsStep_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bAnsStep=0;
} 

void  SetAnsTId_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bAnsTId=cMaxLpScanAnsTId;
} 

uint8  GetAnsTId_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bAnsTId;
}

void  ClrAnsTId_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bAnsTId=0;
} 

void  DecAnsTId_CLpScanCtrl(void)
{
    if(m_LpScanFlag.Bit.bAnsTId)
    {
        m_LpScanFlag.Bit.bAnsTId--;
    }
}



void  SetReset_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bReset=1;
}

uint8  GetReset_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bReset;
}

void  ClrReset_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bReset=0;
}


