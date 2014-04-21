/*

*********************************************************************************************************
*                                                
*                              对象:	CLpCkCtrl
*
*                        (c) Copyright 2000-2006, 蒋雪梅
*                              All Rights Reserved
*                                    Ver1.5
* File : CLpCkCtrl.C
* By   : 蒋雪梅
*********************************************************************************************************
*/
#define    CLpCkCtrl_C
#include  "CLpCkCtrl.h"
 

void  Init_CLpCkCtrl(void)
{
    m_LpCkFlag.Word=0; 
}  

//时钟中断处理
void  SetExtint_CLpCkCtrl(uint8 vType)
{
     m_LpCkFlag.Bit.bExtint=vType; 
} 

uint8  GetExtint_CLpCkCtrl(void)
{
   return  m_LpCkFlag.Bit.bExtint; 
}

void  ClrExtint_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.bExtint=0;
}

 
void  SetPer_CLpCkCtrl(uint8 vType)
{
     m_LpCkFlag.Bit.bPer=vType; 
} 

uint8  GetPer_CLpCkCtrl(void)
{
   return  m_LpCkFlag.Bit.bPer; 
}

void  ClrPer_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.bPer=0;
}

void  ClrReset_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.bReset=0;
}

void  SetReset_CLpCkCtrl(void)
{
	  m_LpCkFlag.Bit.bReset=1; 
}

uint8 GetReset_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.bReset;	
} 

void  ClrAlarm_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.bAlarm=0;
}

void  SetAlarm_CLpCkCtrl(void)
{
	   m_LpCkFlag.Bit.bAlarm=1; 
}

uint8 GetAlarm_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.bAlarm;	
} 
 

void  Clr50ms_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.b50ms=0;
}

void  Set50ms_CLpCkCtrl(void)
{
	   m_LpCkFlag.Bit.b50ms=1; 
}

uint8 Get50ms_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.b50ms;	
} 

void  Clr10ms_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.b10ms=0;
}

void  Set10ms_CLpCkCtrl(void)
{
	   m_LpCkFlag.Bit.b10ms=1; 
}

uint8 Get10ms_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.b10ms;	
}


void  Clr1s_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.b1s=0;
}

void  Set1s_CLpCkCtrl(void)
{
	   m_LpCkFlag.Bit.b1s=1; 
}

uint8 Get1s_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.b1s;	
}


void  Clr5s_CLpCkCtrl(void) 
{
	  m_LpCkFlag.Bit.b5s=0;
}

void  Set5s_CLpCkCtrl(void)
{
	   m_LpCkFlag.Bit.b5s=5; 
}

uint8 Get5s_CLpCkCtrl(void)
{
	 return m_LpCkFlag.Bit.b5s;	
}

 



