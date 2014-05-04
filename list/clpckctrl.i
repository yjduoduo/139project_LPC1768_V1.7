#line 1 "..\\src\\CLoopCtrl\\CLpCkCtrl.c"












 
#line 1 "..\\src\\CLoopCtrl\\CLpCkCtrl.h"











 





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



 


#line 19 "..\\src\\CLoopCtrl\\CLpCkCtrl.h"








 
 
 



 









 
 
 



typedef union type_tLpCkFlag{	   

    uint32   Word;
    uint16   UByte[4>>1];
    uint8    Byte[4];
    struct
    {
	    uint32 bExtint:2;	          
			uint32 bPer:1;	            
			uint32 bComm:2;	            
			



        uint32 b10ms:1;	          
        uint32 b50ms:1;	          
        uint32 b1s:1;
        uint32 b5s:1;
        uint32 bReset:1;
        uint32 bReg:1;
        uint32 bAlarm:1;	        

    }Bit;
}tLpCkFlag;
 
 
 


  void  Init_CLpCkCtrl(void);

  void   SetExtint_CLpCkCtrl(uint8 vType);
  uint8  GetExtint_CLpCkCtrl(void);
  void   ClrExtint_CLpCkCtrl(void);

  void   ClrPer_CLpCkCtrl(void); 
  void   SetPer_CLpCkCtrl(uint8 vType); 
  uint8  GetPer_CLpCkCtrl(void); 

  void  Clr10ms_CLpCkCtrl(void);
  void  Set10ms_CLpCkCtrl(void);
  uint8 Get10ms_CLpCkCtrl(void);

  void  Clr50ms_CLpCkCtrl(void);
  void  Set50ms_CLpCkCtrl(void);
  uint8 Get50ms_CLpCkCtrl(void);

  void  ClrReset_CLpCkCtrl(void);
  void  SetReset_CLpCkCtrl(void);
  uint8 GetReset_CLpCkCtrl(void);

  void  ClrReg_CLpCkCtrl(void);
  void  SetReg_CLpCkCtrl(void);
  uint8 GetReg_CLpCkCtrl(void);

  void  ClrAlarm_CLpCkCtrl(void);
  void  SetAlarm_CLpCkCtrl(void);
  uint8 GetAlarm_CLpCkCtrl(void);


  void  Clr5s_CLpCkCtrl(void);
  void  Set5s_CLpCkCtrl(void);
  uint8 Get5s_CLpCkCtrl(void);


  void  Clr1s_CLpCkCtrl(void);
  void  Set1s_CLpCkCtrl(void);
  uint8 Get1s_CLpCkCtrl(void);



 
 
 



tLpCkFlag	m_LpCkFlag; 










#line 16 "..\\src\\CLoopCtrl\\CLpCkCtrl.c"
 

void  Init_CLpCkCtrl(void)
{
    m_LpCkFlag.Word=0; 
}  


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

 



