/*

*********************************************************************************************************
*                                                
*                              ����:	CNodeInfo
*
*                        (c) Copyright 2000-2006, ��ѩ÷
*                              All Rights Reserved
*                                    Ver1.5
* File : CNodeInfo.C
* By   : ��ѩ÷
*********************************************************************************************************
*/
#define    CNodeInfo_C
#include  "CNodeInfo.h"
#include  <string.h> 
#include   "CMaDefine.h"

void  Init_CNodeInfo(void)   
{
    memset(&m_NodeInfo,0,sizeof m_NodeInfo);
    ClrMax_CNodeInfo();     //139ģ��Ǽǵ����е�ַ������ַλ
    SetMax_CNodeInfo(MAX_LOOP);

#if 0
	   SetReg_CNodeInfo(1);
//     {
//         uint8 vAddr;
//         for(vAddr=cMinNodeAddrNum;vAddr<cMaxNodeAddrNum;vAddr++)
//         {
//             SetReg_CNodeInfo(vAddr);
//         }
//        SetMax_CNodeInfo(210);
//     }
#endif
}  

//״̬���������𾯣����ϣ�Ƿѹ
void  SetState_CNodeInfo(uint8 vAddr,uint8 vType)
{
    m_NodeInfo[vAddr].Bit.bState=vType;
} 

uint8  GetState_CNodeInfo(uint8 vAddr)
{
    return  m_NodeInfo[vAddr].Bit.bState;
}

void  ClrState_CNodeInfo(uint8 vAddr) 
{
    m_NodeInfo[vAddr].Bit.bState=0;
} 

void  ClrReset_CNodeInfo(uint8 vAddr)   
{
    m_NodeInfo[vAddr].Bit.bReset=0;
}

void  SetReset_CNodeInfo(uint8 vAddr)   
{
    m_NodeInfo[vAddr].Bit.bReset=1;
}

uint8 GetReset_CNodeInfo(uint8 vAddr)  
{
    return m_NodeInfo[vAddr].Bit.bReset;
} 

void  ClrAlarm_CNodeInfo(uint8 vAddr)   
{
    m_NodeInfo[vAddr].Bit.bAlarm=0;
}

void  SetAlarm_CNodeInfo(uint8 vAddr)   
{
    //��ֹ������������Ч��ַ���Ǽǵ��ж�
    if((!vAddr)||
            ((vAddr >= cMinNodeAddrBkNum)&&(vAddr <= cMaxNodeAddrBkNum))||
            (vAddr>=cMaxNodeAddrRegNum))
    {
        ClrReg_CNodeInfo(vAddr);
        return ;
    }
    m_NodeInfo[vAddr].Bit.bAlarm=1;
}

uint8 GetAlarm_CNodeInfo(uint8 vAddr)  
{
    return m_NodeInfo[vAddr].Bit.bAlarm;
} 
//���·��Ϣ
void  ClrReg_CNodeInfo(uint8 vAddr)   
{
    m_NodeInfo[vAddr].Bit.bReg=0;
}

void  SetReg_CNodeInfo(uint8 vAddr)   
{
    //��ֹ������������Ч��ַ���Ǽǵ��ж�
    if((!vAddr)||
            ((vAddr >= cMinNodeAddrBkNum)&&
             (vAddr <= cMaxNodeAddrBkNum))||
            (vAddr>=cMaxNodeAddrRegNum))
    {
        ClrReg_CNodeInfo(vAddr);
        return ;
    }
//#if 0
//    if(vAddr == 170)
//    {
//        SetReg_CNodeInfo(vAddr);
//        return ;
//    }
//#endif
    m_NodeInfo[vAddr].Bit.bReg=1;
#if 0 //debug ���ⱨ��
    set_firealarm_ciraddr(vAddr);
#endif
}
//��·�Ƿ��Ѿ�ע�ᣬ1��ע�ᣬ0��δע��
uint8 GetReg_CNodeInfo(uint8 vAddr)  
{
    return m_NodeInfo[vAddr].Bit.bReg;
} 

void  ClrMax_CNodeInfo(void)   
{
    m_MaxNodeAddr=0;
}

void  SetMax_CNodeInfo(uint8 vAddr)
{
    if(vAddr < cMaxNodeAddrNum)
    {
        m_MaxNodeAddr=vAddr;
    }else{
        m_MaxNodeAddr=cMaxNodeAddrNum;
    }
}

uint8 GetMax_CNodeInfo(void)
{
    return  m_MaxNodeAddr;
}  

void  SetComm_CNodeInfo(uint8 vAddr,uint8 vType)
{
    if((vType == cLpScanComm_D12)&&
            (m_NodeInfo[vAddr].Bit.bComm == vType)) //��������һ��
    {
        SetCkCyc_CNodeInfo(vAddr);
    }
    else
    {
        ClrCkCyc_CNodeInfo(vAddr);
    }
    m_NodeInfo[vAddr].Bit.bComm=vType;
} 

uint8  GetComm_CNodeInfo(uint8 vAddr)
{
    return  m_NodeInfo[vAddr].Bit.bComm;
}

void  ClrComm_CNodeInfo(uint8 vAddr)
{
    m_NodeInfo[vAddr].Bit.bComm=0;
} 

void  SetCkCyc_CNodeInfo(uint8 vAddr)
{
    if(m_NodeInfo[vAddr].Bit.bCkCyc < cMaxNodeD12Num)
    {
        m_NodeInfo[vAddr].Bit.bCkCyc++;
    }
    else
    {
        m_NodeInfo[vAddr].Bit.bCkCyc=0;
    }
} 

uint8  GetCkCyc_CNodeInfo(uint8 vAddr)
{
    return  m_NodeInfo[vAddr].Bit.bCkCyc;
}

void  ClrCkCyc_CNodeInfo(uint8 vAddr) 
{
    m_NodeInfo[vAddr].Bit.bCkCyc=0;
} 
