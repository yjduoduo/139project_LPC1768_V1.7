#line 1 "..\\src\\CNodeInfo\\CNodeInfo.c"












 
#line 1 "..\\src\\CNodeInfo\\CNodeInfo.h"











 





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



 


#line 19 "..\\src\\CNodeInfo\\CNodeInfo.h"
#line 1 "..\\src\\CLoopCtrl\\CLpInfoDef.h"











 





#line 19 "..\\src\\CLoopCtrl\\CLpInfoDef.h"
 







 
 
 







 









 
 
 
 
 
 
 


extern  void   Init_CLpInfoDef(void);

 

 

 
 
 

#line 74 "..\\src\\CLoopCtrl\\CLpInfoDef.h"







#line 20 "..\\src\\CNodeInfo\\CNodeInfo.h"







 
 
 













 
 
 


typedef union type_tNodeInfo{	   

    uint32   Word;
    uint16   UByte[4>>1];
    uint8    Byte[4];
    struct
    {
        uint32 bReset:1;
        uint32 bCkCyc:4;	       
        uint32 bResetCyc:2;	     
        uint32 bComm:2;	         
        
        uint32 bFault:1;	           
        uint32 bFaultCyc:3;	         
        uint32 bReg:1;	         
        uint32 bState:2;	       
        uint32 bAlarm:1;	       

    }Bit;
}tNodeInfo;
 
 
 


  void  Init_CNodeInfo(void);

  void    SetState_CNodeInfo(uint8 vAddr,uint8 vType);
  uint8   GetState_CNodeInfo(uint8 vAddr);
  void    ClrState_CNodeInfo(uint8 vAddr);

  void    ClrReset_CNodeInfo(uint8 vAddr);
  void    SetReset_CNodeInfo(uint8 vAddr);
  uint8   GetReset_CNodeInfo(uint8 vAddr);

  void    ClrReg_CNodeInfo(uint8 vAddr);
  void    SetReg_CNodeInfo(uint8 vAddr);
  uint8   GetReg_CNodeInfo(uint8 vAddr);

  void    ClrAlarm_CNodeInfo(uint8 vAddr);
  void    SetAlarm_CNodeInfo(uint8 vAddr);
  uint8   GetAlarm_CNodeInfo(uint8 vAddr);

  void    ClrMax_CNodeInfo(void);
  void    SetMax_CNodeInfo(uint8 vAddr);
  uint8   GetMax_CNodeInfo(void);


  void    SetComm_CNodeInfo(uint8 vAddr,uint8 vType);
  uint8   GetComm_CNodeInfo(uint8 vAddr);
  void    ClrComm_CNodeInfo(uint8 vAddr);


  void    SetCkCyc_CNodeInfo(uint8 vAddr);
  uint8   GetCkCyc_CNodeInfo(uint8 vAddr);
  void    ClrCkCyc_CNodeInfo(uint8 vAddr);



 
 
 



static  uint8 m_MaxNodeAddr;   

tNodeInfo	m_NodeInfo[255]; 










#line 16 "..\\src\\CNodeInfo\\CNodeInfo.c"
#line 1 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
 
 
 
 




 








 











#line 37 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"


  
  typedef unsigned int size_t;








extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 184 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 200 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 223 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 238 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 261 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 493 "C:\\Keil\\ARM\\RV31\\Inc\\string.h"



 
#line 17 "..\\src\\CNodeInfo\\CNodeInfo.c"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 18 "..\\src\\CNodeInfo\\CNodeInfo.c"

void  Init_CNodeInfo(void)   
{
    memset(&m_NodeInfo,0,sizeof m_NodeInfo);
    ClrMax_CNodeInfo();     
    SetMax_CNodeInfo(200);

#line 36 "..\\src\\CNodeInfo\\CNodeInfo.c"
}  


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
    
    if((!vAddr)||
            ((vAddr >= 216)&&(vAddr <= 218))||
            (vAddr>=253))
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

void  ClrReg_CNodeInfo(uint8 vAddr)   
{
    m_NodeInfo[vAddr].Bit.bReg=0;
}

void  SetReg_CNodeInfo(uint8 vAddr)   
{
    
    if((!vAddr)||
            ((vAddr >= 216)&&
             (vAddr <= 218))||
            (vAddr>=253))
    {
        ClrReg_CNodeInfo(vAddr);
        return ;
    }







    m_NodeInfo[vAddr].Bit.bReg=1;



}

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
    if(vAddr < 216)
    {
        m_MaxNodeAddr=vAddr;
    }else{
        m_MaxNodeAddr=216;
    }
}

uint8 GetMax_CNodeInfo(void)
{
    return  m_MaxNodeAddr;
}  

void  SetComm_CNodeInfo(uint8 vAddr,uint8 vType)
{
    if((vType == 3)&&
            (m_NodeInfo[vAddr].Bit.bComm == vType)) 
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
    if(m_NodeInfo[vAddr].Bit.bCkCyc < 9)
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
