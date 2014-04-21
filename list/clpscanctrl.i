#line 1 "..\\src\\CLoopCtrl\\CLpScanCtrl.c"












 
#line 1 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"











 





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



 


#line 19 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"
#line 1 "..\\src\\CLoopCtrl\\CLpInfoDef.h"











 





#line 19 "..\\src\\CLoopCtrl\\CLpInfoDef.h"
 







 
 
 







 









 
 
 
 
 
 
 


extern  void   Init_CLpInfoDef(void);

 

 

 
 
 

#line 74 "..\\src\\CLoopCtrl\\CLpInfoDef.h"







#line 20 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"







 
 
 




 









 
 
 


typedef union type_tLpScanFlag{	   

   uint32   Word;
     uint16   UByte[4>>1];
     uint8    Byte[4];
   struct
     {
        uint32 bSys:1;	            
                                        
            uint32 bAddr:8;	            

            uint32 bComm:2;	            
            uint32 bState:1;            
            uint32 bRec0:4;             


            uint32 bAnsFlag:1;          
            uint32 bAnsStar:1;          
            uint32 bAnsStep:4;          
            uint32 bAnsTId:3;           
            uint32 bReset:1;            
    }Bit;
}tLpScanFlag;
 
 
 


  void   Init_CLpScanCtrl(void);

  void   NewNode_CLpScanCtrl(void);

  void   ClrComm_CLpScanCtrl(void);
  void   SetComm_CLpScanCtrl(uint8 vComm);
  uint8  GetComm_CLpScanCtrl(void);

  void   ClrAddr_CLpScanCtrl(void);
  void   IncAddr_CLpScanCtrl(void);
  void   SetAddr_CLpScanCtrl(uint8 vAddr);
  uint8  GetAddr_CLpScanCtrl(void);

  void    ClrSys_CLpScanCtrl(void);
  void    SetSys_CLpScanCtrl(void);
  uint8   GetSys_CLpScanCtrl(void);

  void    ClrState_CLpScanCtrl(void);
  void    SetState_CLpScanCtrl(void);
  uint8   GetState_CLpScanCtrl(void);

  void    ClrAnsFlag_CLpScanCtrl(void);
  void    SetAnsFlag_CLpScanCtrl(void);
  uint8   GetAnsFlag_CLpScanCtrl(void);

  void    ClrAnsStar_CLpScanCtrl(void);
  void    SetAnsStar_CLpScanCtrl(void);
  uint8   GetAnsStar_CLpScanCtrl(void);

  void    ClrAnsStep_CLpScanCtrl(void);
  void    SetAnsStep_CLpScanCtrl(void);
  uint8   GetAnsStep_CLpScanCtrl(void);

  void    ClrAnsTId_CLpScanCtrl(void);
  void    SetAnsTId_CLpScanCtrl(void);
  uint8   GetAnsTId_CLpScanCtrl(void);
  void    DecAnsTId_CLpScanCtrl(void);



  void  SetReset_CLpScanCtrl(void);
  uint8 GetReset_CLpScanCtrl(void);
  void  ClrReset_CLpScanCtrl(void);

 
 
 



tLpScanFlag	m_LpScanFlag;












#line 16 "..\\src\\CLoopCtrl\\CLpScanCtrl.c"


void  Init_CLpScanCtrl(void)
{
    m_LpScanFlag.Word=0;
}

void  NewNode_CLpScanCtrl(void)
{
    m_LpScanFlag.Word &= (0x1ff);  
}   

void  SetSys_CLpScanCtrl(void)
{
    m_LpScanFlag.Bit.bSys=1;
} 


uint8  GetSys_CLpScanCtrl(void)
{
    return  m_LpScanFlag.Bit.bSys;
}

void  ClrSys_CLpScanCtrl(void) 
{
    m_LpScanFlag.Bit.bSys=0;
}


void  SetAddr_CLpScanCtrl(uint8 vType)
{
    m_LpScanFlag.Bit.bAddr=vType;
} 



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
    if(m_LpScanFlag.Bit.bAnsStep < 10)
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
    m_LpScanFlag.Bit.bAnsTId=6;
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


