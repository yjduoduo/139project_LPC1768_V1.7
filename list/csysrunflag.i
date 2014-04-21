#line 1 "..\\src\\CRunCtrl\\CSysRunFlag.c"












 
#line 1 "..\\src\\CRunCtrl\\CSysRunFlag.h"











 





#line 1 "..\\src\\APP\\Config.h"












 




 


 


 













enum emTxResult{
	U_TxError = 1,
	U_TxSucc = 0,	
};
	
	
enum emErrorDef{
	U_Error = 1,
	U_Fault = 1,
	U_Usual = 0,	
	
};








 




 
typedef  unsigned  char  tBoolean;
typedef  unsigned char   uchar;                    
typedef  unsigned char   uint8;                    
typedef  signed   char   int8;                     
typedef  unsigned short  uint16;                   
typedef  signed   short  int16;                    
typedef  unsigned int    uint32;                   
typedef  signed   int    int32;                    
typedef  float           fp32;                     
typedef  double          fp64;                     	  
typedef  unsigned long   ulong;



 


#line 19 "..\\src\\CRunCtrl\\CSysRunFlag.h"








 
 
 






 
 
 


typedef union type_tSysRunFlag{	   

    uint32   Word;
    uint16   UByte[4>>1];
    uint8    Byte[4];
    struct
    {
        uint32 b20ms:1;	          
        uint32 b40ms:1;            
        uint32 b50ms:1;	          
        uint32 b100ms:1;
        uint32 b1s:1;
        uint32 b5s:1;
        uint32 b1m:1;             
        uint32 bReset:1;
        uint32 bReg:1;
        uint32 bAlarm:1;	        
        uint32 bDisHis:1;	        

    }Bit;
}tSysRunFlag;
 
 
 


  void  InitC_CSysRunFlag(void);

  void  Clr20ms_CSysRunFlag(void);
  void  Set20ms_CSysRunFlag(void);
  uint8 Get20ms_CSysRunFlag(void);

  void  Clr50ms_CSysRunFlag(void);
  void  Set50ms_CSysRunFlag(void);
  uint8 Get50ms_CSysRunFlag(void);

  void  ClrReset_CSysRunFlag(void);
  void  SetReset_CSysRunFlag(void);
  uint8 GetReset_CSysRunFlag(void);

  void  ClrReg_CSysRunFlag(void);
  void  SetReg_CSysRunFlag(void);
  uint8 GetReg_CSysRunFlag(void);

  void  ClrAlarm_CSysRunFlag(void);
  void  SetAlarm_CSysRunFlag(void);
  uint8 GetAlarm_CSysRunFlag(void);

  void  ClrDisHis_CSysRunFlag(void);
  void  SetDisHis_CSysRunFlag(void);
  uint8 GetDisHis_CSysRunFlag(void);

  void  Clr5s_CSysRunFlag(void);
  void  Set5s_CSysRunFlag(void);
  uint8 Get5s_CSysRunFlag(void);

  void  Clr1s_CSysRunFlag(void);
  void  Set1s_CSysRunFlag(void);
  uint8 Get1s_CSysRunFlag(void);

  void  Clr1m_CSysRunFlag(void);
  void  Set1m_CSysRunFlag(void);
  uint8 Get1m_CSysRunFlag(void);

  void  Clr100ms_CSysRunFlag(void);
  void  Set100ms_CSysRunFlag(void);
  uint8 Get100ms_CSysRunFlag(void);

 void  Clr40ms_CSysRunFlag(void);
 void  Set40ms_CSysRunFlag(void);
 uint8 Get40ms_CSysRunFlag(void);
 
 
 



tSysRunFlag	m_SysRunFlag; 










#line 16 "..\\src\\CRunCtrl\\CSysRunFlag.c"
 

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
