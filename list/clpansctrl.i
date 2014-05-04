#line 1 "..\\src\\CLoopCtrl\\CLpAnsCtrl.c"












 
#line 1 "..\\src\\CLoopCtrl\\CLpAnsCtrl.h"











 





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



 


#line 19 "..\\src\\CLoopCtrl\\CLpAnsCtrl.h"
#line 1 "..\\src\\CLoopCtrl\\CLpInfoDef.h"











 





#line 19 "..\\src\\CLoopCtrl\\CLpInfoDef.h"
 







 
 
 







 









 
 
 
 
 
 
 


extern  void   Init_CLpInfoDef(void);

 

 

 
 
 

#line 74 "..\\src\\CLoopCtrl\\CLpInfoDef.h"







#line 20 "..\\src\\CLoopCtrl\\CLpAnsCtrl.h"







 
 
 



  
 

 
 
 












 
 
 


  void  Init_CLpAnsCtrl(void); 


  uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState); 


  void  SetData_CLpAnsCtrl(uint8 vSndData);


  void  OutData_CLpAnsCtrl(uint8 vId); 


  void  OutState_CLpAnsCtrl(uint8 vId);  


 
 
 



uint8	  m_LpAnsFlag[10];  














static uint8 m_LpAnsD4[]={0x0b,0x00,0xeb};


static uint8 m_LpAnsD8[]={0x23,0x00,0x54};


static uint8 m_LpAnsD12[]={0xfa,0x20,0x01,0x0b,0x01,0x03,0x09,0x04,0x05,0x06};










#line 16 "..\\src\\CLoopCtrl\\CLpAnsCtrl.c"
#line 1 "..\\src\\common\\CSetCurrent.h"












 


extern void State_6mA(void);
extern void State_20mA(void);
extern void State_0mA(void);



extern void clr_loop_LD_counter(void);
extern void loop_LD_state(void);

void state_loopld_printf(void);


void set_print(void);

uint32 get_loopLD_state(void);
void set_loopldbuf(uint8 bufcounter,uint8 val);
void add_bufcounter(void);
uint8 get_bufcounter(void);
void printbuf(uint8* buf,uint8 size);


void clrbuf(uint8* buf,uint8 size);
#line 17 "..\\src\\CLoopCtrl\\CLpAnsCtrl.c"
#line 1 "..\\src\\CNodeInfo\\CNodeInfo.h"











 





#line 19 "..\\src\\CNodeInfo\\CNodeInfo.h"
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
 
 
 


extern  void  Init_CNodeInfo(void);

extern  void    SetState_CNodeInfo(uint8 vAddr,uint8 vType);
extern  uint8   GetState_CNodeInfo(uint8 vAddr);
extern  void    ClrState_CNodeInfo(uint8 vAddr);

extern  void    ClrReset_CNodeInfo(uint8 vAddr);
extern  void    SetReset_CNodeInfo(uint8 vAddr);
extern  uint8   GetReset_CNodeInfo(uint8 vAddr);

extern  void    ClrReg_CNodeInfo(uint8 vAddr);
extern  void    SetReg_CNodeInfo(uint8 vAddr);
extern  uint8   GetReg_CNodeInfo(uint8 vAddr);

extern  void    ClrAlarm_CNodeInfo(uint8 vAddr);
extern  void    SetAlarm_CNodeInfo(uint8 vAddr);
extern  uint8   GetAlarm_CNodeInfo(uint8 vAddr);

extern  void    ClrMax_CNodeInfo(void);
extern  void    SetMax_CNodeInfo(uint8 vAddr);
extern  uint8   GetMax_CNodeInfo(void);


extern  void    SetComm_CNodeInfo(uint8 vAddr,uint8 vType);
extern  uint8   GetComm_CNodeInfo(uint8 vAddr);
extern  void    ClrComm_CNodeInfo(uint8 vAddr);


extern  void    SetCkCyc_CNodeInfo(uint8 vAddr);
extern  uint8   GetCkCyc_CNodeInfo(uint8 vAddr);
extern  void    ClrCkCyc_CNodeInfo(uint8 vAddr);



 
 
 

#line 119 "..\\src\\CNodeInfo\\CNodeInfo.h"







#line 18 "..\\src\\CLoopCtrl\\CLpAnsCtrl.c"
#line 19 "..\\src\\CLoopCtrl\\CLpAnsCtrl.c"


void  Init_CLpAnsCtrl(void)
{

}  

uint8 GetData_CLpAnsCtrl(uint8 vComm,uint8 vState)
{
    uint8  vData=0;
    if(vComm == 1)
    {
        if(vState < 3)
        {
            vData=m_LpAnsD4[vState];
        }
    }
    else if(vComm == 2)
    {
        if(vState < 3)
        {
            vData=m_LpAnsD8[vState];
        }
    }
    else if(vComm == 3)
    {
        if(vState < 9)
        {
            vData=m_LpAnsD12[vState];
        }
    }
    return vData;
} 


void  SetData_CLpAnsCtrl(uint8 vSndData)
{
    uint8  i;
    uint8  j;
    uint8  vData=vSndData;
    for(i=0;i<10;i++)
    {
        m_LpAnsFlag[i]=0;
    }
    j=1;
    for(i=0;i<8;i++)
    {
        if(vData & 0x01)
        {
            m_LpAnsFlag[j]=2;
        }
        else
        {
            m_LpAnsFlag[j]=1;
        }
        j++;
        vData=vData>>1;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
} 

void  OutData_CLpAnsCtrl(uint8 vId)
{
    if(vId < 10)
    {
        uint8 vData= m_LpAnsFlag[vId];
        if(vData == 1)
        {
            State_6mA();
        }
        else if(vData == 2)
        {
            State_20mA();
        }
        else
        {
            State_0mA();
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
} 

void  OutState_CLpAnsCtrl(uint8 vData) 
{ 	
    if(vData == 0)
    {
        State_6mA();
    }
    else if(vData == 2)
    {
        State_20mA();
    }
    else
    {
        State_0mA();
    }
} 


