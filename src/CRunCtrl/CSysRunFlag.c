/*

*********************************************************************************************************
*                                                
*                              ∂‘œÛ:	CSysRunFlag
*
*                        (c) Copyright 2000-2006, ΩØ—©√∑
*                              All Rights Reserved
*                                    Ver1.5
* File : CSysRunFlag.C
* By   : ΩØ—©√∑
*********************************************************************************************************
*/
#define    CSysRunFlag_C
#include  "CSysRunFlag.h"
 

void  InitC_CSysRunFlag(void)
{
    m_SysRunFlag.Word=0; 
}  

void  ClrReset_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.bReset=0;
}

void  SetReset_CSysRunFlag(void)
{
	  m_SysRunFlag.Bit.bReset=1; 
}

uint8 GetReset_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.bReset;	
} 

void  ClrAlarm_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.bAlarm=0;
}

void  SetAlarm_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.bAlarm=1; 
}

uint8 GetAlarm_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.bAlarm;	
} 
 

void  Clr50ms_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.b50ms=0;
}

void  Set50ms_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.b50ms=1; 
}

uint8 Get50ms_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.b50ms;	
} 

void  Clr20ms_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.b20ms=0;
}

void  Set20ms_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.b20ms=1; 
}

uint8 Get20ms_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.b20ms;	
}


void  Clr1s_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.b1s=0;
}

void  Set1s_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.b1s=1; 
}

uint8 Get1s_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.b1s;	
}


void  Clr5s_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.b5s=0;
}

void  Set5s_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.b5s=5; 
}

uint8 Get5s_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.b5s;	
}

void  ClrDisHis_CSysRunFlag(void) 
{
	  m_SysRunFlag.Bit.bDisHis=0;
}

void  SetDisHis_CSysRunFlag(void)
{
	   m_SysRunFlag.Bit.bDisHis=1; 
}

uint8 GetDisHis_CSysRunFlag(void)
{
	 return m_SysRunFlag.Bit.bDisHis;	
}  

void  Clr1m_CSysRunFlag(void)
{
      m_SysRunFlag.Bit.b1m=0;
}

void  Set1m_CSysRunFlag(void)
{
       m_SysRunFlag.Bit.b1m=1;
}

uint8 Get1m_CSysRunFlag(void)
{
     return m_SysRunFlag.Bit.b1m;
}

void  Clr100ms_CSysRunFlag(void)
{
      m_SysRunFlag.Bit.b100ms=0;
}

void  Set100ms_CSysRunFlag(void)
{
       m_SysRunFlag.Bit.b100ms=1;
}

uint8 Get100ms_CSysRunFlag(void)
{
     return m_SysRunFlag.Bit.b100ms;
}

//40ms
void  Clr40ms_CSysRunFlag(void)
{
      m_SysRunFlag.Bit.b40ms=0;
}

void  Set40ms_CSysRunFlag(void)
{
       m_SysRunFlag.Bit.b40ms=1;
}

uint8 Get40ms_CSysRunFlag(void)
{
     return m_SysRunFlag.Bit.b40ms;
}
