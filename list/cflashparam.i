#line 1 "..\\src\\common\\CFlashParam.c"







































 
#line 1 "..\\src\\APP\\include.h"












 




#line 1 "..\\inc\\LPC17xx.h"








 
 
 
 
#line 20 "..\\inc\\LPC17xx.h"






 



 

 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn           = -14,       
  MemoryManagement_IRQn         = -12,       
  BusFault_IRQn                 = -11,       
  UsageFault_IRQn               = -10,       
  SVCall_IRQn                   = -5,        
  DebugMonitor_IRQn             = -4,        
  PendSV_IRQn                   = -2,        
  SysTick_IRQn                  = -1,        

 
  WDT_IRQn                      = 0,         
  TIMER0_IRQn                   = 1,         
  TIMER1_IRQn                   = 2,         
  TIMER2_IRQn                   = 3,         
  TIMER3_IRQn                   = 4,         
  UART0_IRQn                    = 5,         
  UART1_IRQn                    = 6,         
  UART2_IRQn                    = 7,         
  UART3_IRQn                    = 8,         
  PWM1_IRQn                     = 9,         
  I2C0_IRQn                     = 10,        
  I2C1_IRQn                     = 11,        
  I2C2_IRQn                     = 12,        
  SPI_IRQn                      = 13,        
  SSP0_IRQn                     = 14,        
  SSP1_IRQn                     = 15,        
  PLL0_IRQn                     = 16,        
  RTC_IRQn                      = 17,        
  EINT0_IRQn                    = 18,        
  EINT1_IRQn                    = 19,        
  EINT2_IRQn                    = 20,        
  EINT3_IRQn                    = 21,        
  ADC_IRQn                      = 22,        
  BOD_IRQn                      = 23,        
  USB_IRQn                      = 24,        
  CAN_IRQn                      = 25,        
  DMA_IRQn                      = 26,        
  I2S_IRQn                      = 27,        
  ENET_IRQn                     = 28,        
  RIT_IRQn                      = 29,        
  MCPWM_IRQn                    = 30,        
  QEI_IRQn                      = 31,        
  PLL1_IRQn                     = 32,        
  USBActivity_IRQn              = 33,        
  CANActivity_IRQn              = 34         
} IRQn_Type;




 

 





#line 1 "..\\inc\\core_cm3.h"



















 




















































 

 
 
 
 
 
 
 
 


#line 1 "C:\\Keil\\ARM\\RV31\\Inc\\stdint.h"
 
 





 









#line 25 "C:\\Keil\\ARM\\RV31\\Inc\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 196 "C:\\Keil\\ARM\\RV31\\Inc\\stdint.h"

     







     










     











#line 260 "C:\\Keil\\ARM\\RV31\\Inc\\stdint.h"



 


#line 86 "..\\inc\\core_cm3.h"

















 

#line 112 "..\\inc\\core_cm3.h"





 


 





 






 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];
  volatile  uint32_t STIR;                          
}  NVIC_Type;


 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;


 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;


 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;
  volatile const  uint32_t PID6;
  volatile const  uint32_t PID7;
  volatile const  uint32_t PID0;
  volatile const  uint32_t PID1;
  volatile const  uint32_t PID2;
  volatile const  uint32_t PID3;
  volatile const  uint32_t CID0;
  volatile const  uint32_t CID1;
  volatile const  uint32_t CID2;
  volatile const  uint32_t CID3;
} ITM_Type;


 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;


 

typedef struct
{
  volatile const  uint32_t TYPE;                          
  volatile uint32_t CTRL;                          
  volatile uint32_t RNR;                           
  volatile uint32_t RBAR;                          
  volatile uint32_t RASR;                          
  volatile uint32_t RBAR_A1;                       
  volatile uint32_t RASR_A1;                       
  volatile uint32_t RBAR_A2;                       
  volatile uint32_t RASR_A2;                       
  volatile uint32_t RBAR_A3;                       
  volatile uint32_t RASR_A3;                       
} MPU_Type;



 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;


 
#line 274 "..\\inc\\core_cm3.h"

#line 281 "..\\inc\\core_cm3.h"










 






#line 311 "..\\inc\\core_cm3.h"


 


 




#line 336 "..\\inc\\core_cm3.h"


 
 
 
 









 
extern uint32_t __get_PSP(void);









 
extern void __set_PSP(uint32_t topOfProcStack);









 
extern uint32_t __get_MSP(void);











 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 504 "..\\inc\\core_cm3.h"









 









 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}








 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0x1ff);
}









 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}








 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}








 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}








 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}








 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}








 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1046 "..\\inc\\core_cm3.h"



 













 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  = ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                     
  reg_value &= ~((0xFFFFU << 16) | (0x0F << 8));                               
  reg_value  = ((reg_value | (0x5FA << 16) | (PriorityGroupTmp << 8)));   
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR = reg_value;
}









 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR >> 8) & 0x07);                                           
}









 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}









 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}













 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 5)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 5)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 5)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 5)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 5) ? 5 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 5) < 7) ? 0 : PriorityGroupTmp - 7 + 5;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}

















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 5) ? 5 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 5) < 7) ? 0 : PriorityGroupTmp - 7 + 5;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 



 














 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > ((1<<24) -1))  return (1);                                              

  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  =  (ticks & ((1<<24) -1)) - 1;                                       
  NVIC_SetPriority (SysTick_IRQn, (1<<5) - 1);                             
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   =  (0x00);                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL = (1 << 2) | (1<<0) | (1<<1);  
  return (0);                                                                             
}







 








 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16) | (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (0x700)) | (1<<2));  
  __dsb(0);                                                                                            
  while(1);                                                                             
}


 











 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (ch == '\n') ITM_SendChar('\r');
  
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1 << 24))  &&
      (((ITM_Type *) (0xE0000000))->TCR & 1)                  &&
      (((ITM_Type *) (0xE0000000))->TER & (1UL << 0))  ) 
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}







 
#line 95 "..\\inc\\LPC17xx.h"
#line 1 "..\\inc\\system_LPC17xx.h"




















 










#line 1 "..\\inc\\LPC17xx.h"
#line 33 "..\\inc\\system_LPC17xx.h"

extern uint32_t SystemFrequency;     










 
extern void SystemInit (void);










 
extern void SystemClockUpdate (void);





#line 96 "..\\inc\\LPC17xx.h"


 
 
 


#pragma anon_unions



 
#line 120 "..\\inc\\LPC17xx.h"

#line 136 "..\\inc\\LPC17xx.h"


 

#line 146 "..\\inc\\LPC17xx.h"

























 

























































































































































































 

 




 




				 
 





 



 
#line 387 "..\\inc\\LPC17xx.h"
    
 




 


 
 






 
#line 411 "..\\inc\\LPC17xx.h"










 
#line 440 "..\\inc\\LPC17xx.h"

 
#line 460 "..\\inc\\LPC17xx.h"

 
#line 480 "..\\inc\\LPC17xx.h"

 
#line 500 "..\\inc\\LPC17xx.h"


 
#line 525 "..\\inc\\LPC17xx.h"


 
#line 544 "..\\inc\\LPC17xx.h"

 
#line 565 "..\\inc\\LPC17xx.h"

 
#line 583 "..\\inc\\LPC17xx.h"

 
#line 602 "..\\inc\\LPC17xx.h"


 
#line 611 "..\\inc\\LPC17xx.h"

 
#line 624 "..\\inc\\LPC17xx.h"

 
#line 637 "..\\inc\\LPC17xx.h"


 
#line 657 "..\\inc\\LPC17xx.h"

 
#line 676 "..\\inc\\LPC17xx.h"

 
#line 695 "..\\inc\\LPC17xx.h"


 
#line 713 "..\\inc\\LPC17xx.h"


 







 
#line 756 "..\\inc\\LPC17xx.h"


 
#line 765 "..\\inc\\LPC17xx.h"


 
#line 782 "..\\inc\\LPC17xx.h"


 






 
#line 823 "..\\inc\\LPC17xx.h"


 


 




 
#line 847 "..\\inc\\LPC17xx.h"

 
#line 855 "..\\inc\\LPC17xx.h"


 

 
#line 872 "..\\inc\\LPC17xx.h"

 





 
#line 905 "..\\inc\\LPC17xx.h"

 
#line 932 "..\\inc\\LPC17xx.h"


 
#line 950 "..\\inc\\LPC17xx.h"

 






 






 






 






 






 






 






 







 





 

 



 






 






 




 



 






 
#line 1069 "..\\inc\\LPC17xx.h"


 
#line 1095 "..\\inc\\LPC17xx.h"


 

 









 
#line 1116 "..\\inc\\LPC17xx.h"

 



 


 


 
#line 1145 "..\\inc\\LPC17xx.h"

 
#line 1164 "..\\inc\\LPC17xx.h"

 






 










 
#line 1216 "..\\inc\\LPC17xx.h"

















 
typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[7];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED2[7];
  volatile uint8_t  SCR;
       uint8_t  RESERVED3[3];
  volatile uint32_t ACR;
  volatile uint8_t  ICR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  FDR;
       uint8_t  RESERVED5[7];
  volatile uint8_t  TER;
       uint8_t  RESERVED6[39];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART_TypeDef;

typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[7];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED2[7];
  volatile uint8_t  SCR;
       uint8_t  RESERVED3[3];
  volatile uint32_t ACR;
  volatile uint8_t  ICR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  FDR;
       uint8_t  RESERVED5[7];
  volatile uint8_t  TER;
       uint8_t  RESERVED6[39];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART0_TypeDef;

typedef struct
{
  union {
  volatile const  uint8_t  RBR;
  volatile  uint8_t  THR;
  volatile uint8_t  DLL;
       uint32_t RESERVED0;
  };
  union {
  volatile uint8_t  DLM;
  volatile uint32_t IER;
  };
  union {
  volatile const  uint32_t IIR;
  volatile  uint8_t  FCR;
  };
  volatile uint8_t  LCR;
       uint8_t  RESERVED1[3];
  volatile uint8_t  MCR;
       uint8_t  RESERVED2[3];
  volatile const  uint8_t  LSR;
       uint8_t  RESERVED3[3];
  volatile const  uint8_t  MSR;
       uint8_t  RESERVED4[3];
  volatile uint8_t  SCR;
       uint8_t  RESERVED5[3];
  volatile uint32_t ACR;
       uint32_t RESERVED6;
  volatile uint32_t FDR;
       uint32_t RESERVED7;
  volatile uint8_t  TER;
       uint8_t  RESERVED8[27];
  volatile uint8_t  RS485CTRL;
       uint8_t  RESERVED9[3];
  volatile uint8_t  ADRMATCH;
       uint8_t  RESERVED10[3];
  volatile uint8_t  RS485DLY;
       uint8_t  RESERVED11[3];
  volatile const  uint8_t  FIFOLVL;
} LPC_UART1_TypeDef;




#line 19 "..\\src\\APP\\include.h"
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



 


#line 20 "..\\src\\APP\\include.h"
#line 1 "..\\src\\common\\buffer.h"
                                  























 



typedef struct{
unsigned char read;	
unsigned char  write;	
unsigned char  len;	
unsigned char *buffer;	
unsigned char  overflue;	
}TBuffer;
extern TBuffer	Uartbuf;
extern TBuffer	Wirelessbuf;
extern TBuffer* pUartbuf;
extern TBuffer* pWirelessbuf;




extern unsigned char  BufferInit(TBuffer* pbuf,unsigned char * pdata,unsigned short len);
extern unsigned char  BufferReset(TBuffer* pbuf);
extern unsigned char  BufferWrite(TBuffer* pbuf ,unsigned char * pdata ,unsigned short len);
extern unsigned char  BufferRead(TBuffer* pbuf ,unsigned char * pdata ,unsigned short len ,unsigned char offset);
extern unsigned char  BufferClear(TBuffer* pbuf ,unsigned short len);




 
#line 21 "..\\src\\APP\\include.h"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 22 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\CSSP\\ssp.h"












 

#line 18 "..\\src\\Hardware\\CSSP\\ssp.h"




	
 






 






 





 





 





 





 



#line 71 "..\\src\\Hardware\\CSSP\\ssp.h"

 



#line 87 "..\\src\\Hardware\\CSSP\\ssp.h"



extern void  SSP1_Init(void);
extern uint8 SPI_FLASH_SendByte (uint8 tmp);
extern void SSPSend( uint32_t portnum, uint8_t *Buf, uint32_t Length );
extern void SSPReceive( uint32_t portnum, uint8_t *buf, uint32_t Length );
extern void M25P80_Section_Erase(uint32 addr);
extern void M25P80_Bulk_Erase(void);
extern void M25P80_Write_1Byte(uint32 addr , uint8 data);
extern void M25P80_Write_Bytes(uint32 addr , uint8* wr_buf_p , uint16 no);
extern uint8 M25P80_Read_1Byte(uint32 addr );
extern uint8 M25P80_ReadFast_1Byte(uint32 addr );
extern void M25P80_Read_Bytes(uint32 addr , uint8* re_buf_p , uint16 no);
void SSP1_Write_En(void);
void SSP1_Write_Dis(void);
void SSP1_Write_CMD(uint8 cmd,uint32 addr);
void SSP1_Write_1Byte(uint32 addr , uint8 data);
void MDelay(uint8 tmp);
void M25P80_WP_En(void);
void SSP1_Write_Bytes(uint32 addr , uint8 *data , uint16 no);
uint8 SSP1_Read_1Byte(uint32 addr );
void SSP1_Section_Erase(uint32 addr);
void SSP1_Bulk_Erase(void);
void SSP1_Read_Bytes(uint32 addr , uint8* data , uint16 no);
void SSP_Busy(void);



 

#line 25 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\I2C\\i2c.h"















 
#line 18 "..\\src\\Hardware\\I2C\\i2c.h"




















extern void  I2C0_Init(uint32 ulFi2c);
void I2CIntEnd(void);
void I2CIntStart(void);
extern uint8 IRcvByte(uint8 sla, uint8 *dat);
extern uint8 ISendByte(uint8 sla, uint8 dat);
extern uint8 I2C_ReadNByte (uint8 sla, uint32 suba_type, uint32 suba, uint8 *s, uint32 num);
extern uint8 I2C_WriteNByte(uint8 sla, uint8 suba_type, uint32 suba, uint8 *s, uint32 num);

extern void i2c0_enable(void);
extern void i2c0_disable(void);
#line 28 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Board\\pcf8563.h"















 

#line 19 "..\\src\\Board\\pcf8563.h"





typedef struct _PCF8563_DATE{
   uint8	second;
   uint8	minute;
   uint8	hour;
   uint8	day;
   uint8	week;
   uint8	month;
   uint16	year;
}PCF8563_DATE;





 
#line 46 "..\\src\\Board\\pcf8563.h"


 




 
#line 60 "..\\src\\Board\\pcf8563.h"


 




 
#line 74 "..\\src\\Board\\pcf8563.h"


 







 



 uint8 PCF8563_Set(PCF8563_DATE *tp);
 uint8 PCF8563_Read(PCF8563_DATE *tp);
 uint8 PCF8563_SS(uint8 cmd);
 uint8 PCF8563_Set_TD(uint8 cmd, uint16 TD);
 uint16 PCF8563_Get_TD(uint8 cmd);
 uint8 PCF8563_Set_ClkOut(uint8 cmd);
 uint8 PCF8563_Set_Alarm(uint8 cmd, uint8 tm);
 uint8 PCF8563_Set_Timer(uint8 cmd, uint8 cnt);
 uint8 PCF8563_INT_State(uint8 cmd);
 void PCF8563_Init(void);

void getcurrent_date(PCF8563_DATE *date);




 
#line 30 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Hardware\\GPIO\\GPIOInit.h"












 

 


void GPIOinit(void);

#line 33 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\UART\\uart.h"


















 
#line 21 "..\\src\\Hardware\\UART\\uart.h"

















#line 46 "..\\src\\Hardware\\UART\\uart.h"





 




 

typedef struct note_info_t
{
    uint8 frame1;
    uint8 frame2;
    uint8 frame3;
    uint8 cmd1;
    uint8 cmd_rw;
    uint8 devtype;
    uint8 targetaddr;
    uint8 controllernum;
    uint8 datelen;
    uint8 loop;
    uint8 addr;
    uint8 hz[32];
    uint8 cs[2];
}note_info_t;


 















void ClrData3(void);

extern void NoteData_Init(void);
extern uint8 GetCom0Ann(uint8 row,uint8 cow);
extern uint8 GetAnnRow( uint8 comp);
extern void ClrCom1Data0(void);
extern void clr_tp(void);
extern uint8 GetCom1Data0(uint8 row);
void CSaveAnn(void);
void AnnCounterInit(void);
extern uint32 UARTInit( uint32 portNum, uint32 Baudrate );
extern void UartIntEnd(void);
extern void UartIntStart(void);
extern void UART0_IRQHandler( void );
extern void UART1_IRQHandler( void );
extern void UARTSend(uint32 portNum, uint8 *Ptr, uint32 Length);
extern uint32 uart1GetByte (void);
extern void uart1GetStr (uint32 *pucStr, uint32 ulNum);

static int Uart0SendByte(int buf, uint8 flag) ;

extern uint32 Uart1SendByte(uint32 buf) ;
extern void UART0_SendString (uint8 *s);
extern void UART1_SendString (uint8 *s);
uint8 GetAnnFlag(void);
void HandleNote(void);
void SaveAnnFun(void);
void puts__(char *s);
void lcd_printf(char *str,...);

void uart_all_disable(void);
void uart_all_enable(void);

void SetConvertdataAll(void);

void set_note_info(note_info_t *info);







void add_note_nums(void);
void add_note_size(void);
void check_note_nums(void);
void check_note_size(void);
void reset_note_buf(uint8 notenum);
void set_note_buf(uint8 notenum, uint8 note_size, uint8 val);
void print_note_buf(void);





 
 
 
 
 
 










 

#line 172 "..\\src\\Hardware\\UART\\uart.h"





 


 



 




 

 


 

 



 
 

 
 


 

 
 


 

 
 

 


 

 
 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 




 

 
 

 

 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 


 

 
 

 

 


 

 
 

 


 

 
 

 

 

 

 


 


 


 

 


 

 
 


 

 
 

 

 





 



 




 


 

 

 

 

 





typedef struct
{
    volatile uint32 tx_head;                 
    volatile uint32 tx_tail;                 
    volatile uint32 rx_head;                 
    volatile uint32 rx_tail;                 
    volatile uint8  tx[256];   
    volatile uint8  rx[256];   
} UART_RING_BUFFER_T;
















typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;





















 
typedef struct{
    unsigned short len;									 
    unsigned short num;									 
    unsigned char senden;
    unsigned char datarray[0x100];			 
}TdUartSend;

typedef struct{
    unsigned char clrlen;								 
    unsigned char datarray[0x100];			 
}TdUartRcv;







 
#line 35 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Extint\\extint.h"












 




void  Eint3_Init(void);
void  SetE1_flag(void);
void  ClrE1_flag(void);
uint8 GetE1_flag(void);
void  SetE3_flag(void);
void  ClrE3_flag(void);
uint8 GetE3_flag(void);
void  cExt3IntFlow(void);
void  cExt3IntRise(void);
void cExt3IntClrFlow(void);
void cExt3IntClrRise(void);
void Eint_Dis(void);
void Eint_En(void);
void Eint_DisAll_Exuart(void);
void Eint_EnAll_Exuart(void);


uint8_t GetSyncFlag(void);
void SyncTimeInit(void);



void SetStartSyncms(uint8_t order,uint32_t val);
void PrintP023TiggerInfo(void);







void vSetFallingCount(uint32_t count);

void vClrFallingCount(void);

void vSetRiseingCount(uint32_t count);

void vClrRiseingCount(void);

void extint1_disable(void);
void extint1_enable(void);

void extint3_enable(void);
void extint3_disable(void);



#line 37 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\PWM.h"












 










#line 31 "..\\src\\Hardware\\PWM.h"





#line 57 "..\\src\\Hardware\\PWM.h"

#line 69 "..\\src\\Hardware\\PWM.h"

#line 77 "..\\src\\Hardware\\PWM.h"

void PWM1_IRQHandler (void) ;
void PWM_Init(void);
void PWM1_Set(uint32 cycle, uint32 offset );
void PWM1_Start( void );
void PWM1_Stop( void );


void pwm1_enable(void);
void pwm1_disable(void);




#line 39 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Board\\lcd.h"












 
#line 15 "..\\src\\Board\\lcd.h"

 








#line 31 "..\\src\\Board\\lcd.h"






void DelayMs(uint32 Time);    
void DATAout(uint8 j);
void CheckState(void);   
void SendCommandToLCD(uint8 com);  
void SetLine(uint8 page);	 
  
void SetStartLine(uint8 startline);
 
void SetColumn(uint8 column);
  
void SetOnOff(uint8 onoff);
 
void WriteByte(uint8 dat);
 
void SelectScreen(uint8 screen);
  
void ClearScreen(uint8  screen);
void Clear16Screen(uint8  screen);
 
void delay(uint8  z);
 
void delay_long (uint32 ulTime);
 
void InitLCD(void );
 
void Display(uint8  ss,uint8  page,uint8  column,uint32  number);
void DisplayBlack(uint8  ss,uint8  page,uint8  column,uint32  number);
void Display12by12(uint8  ss,uint8  page,uint8  column,uint8  number);

void Display1(uint8  ss,uint8  page,uint8  column,uint8  number);	

void Displaynumber(uint8  ss,uint8  page,uint8  column,uint8  number);	
void IOint(void);

void DisplaynumberBlack(uint8  ss,uint8 page,uint8  column,uint8  number);
void WriteBlackByte(uint8 dat);
void WriteBlue(uint8 screen,uint8 line,uint8 col,uint8 row);

void DisplayJBHZK(uint8  ss,uint8  page,uint8  column,uint16 xHZcode);
void DisplayJBHZKBlack(uint8  ss,uint8  page,uint8  column,uint16 xHZcode);

#line 42 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Timer\\CTime.h"











 





#line 19 "..\\src\\Hardware\\Timer\\CTime.h"
 







 
 
 

  

 
 
  
 
 
 	

 
 
 
extern  void     SetHeartTick(uint32 tmp);
extern  void AddHeartTick(void);
extern  uint32   GetHeartTick(void);
extern  void     Init_CTime0(void);  
extern  void     Init_CTime1(void);
extern  void     init_timer (uint8 timer_num, uint32 TimerInterval); 
extern  void     SetTimeTickCounter(uint8 tmp);
extern  uint8    GetTimeTickCounter(void);
extern  void     AddSpeakerTick(void);
extern  void     SetSpeakerTick(uint16 tmp);
extern  uint16   GetSpeakerTick(void);
extern  void     TIMER0_IRQHandler (void);  
extern  void     TIMER1_IRQHandler (void);
extern  void     enable_timer( uint8 timer_num );
extern  void     disable_timer( uint8 timer_num );
extern  void     reset_timer( uint8 timer_num );
extern  void     CLedShow(void);
extern  void     CSpeakerPWM(void);
extern  void     OnLCD(void);
extern  void vAddLedFlag(void);
extern  void vClrLedFlag(void);
extern  uint32 vGetLedFlag(void);
extern  void OffLcd(void);
extern  void vAddScreenMask(void);
extern  uint32 vGetScreenMask(void);

void timern_disable(uint8 timern);
void timern_enable(uint8 timern);
  
 
 

#line 87 "..\\src\\Hardware\\Timer\\CTime.h"


#line 44 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CSpeaker.h"












 




void Breeze_Controll(int Breeze_time,int Stoptime_add);

#line 46 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Board\\CRelay.h"












 


void Relay_Init(void);
void Fire_Relay_On(void);
void Fire_Relay_Off(void);
void Fault_Relay_On(void);
void Fault_Relay_Off(void);


#line 48 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CIntStEnd.h"












 

void EndInt(void);
void StartInt(void);

#line 50 "..\\src\\APP\\include.h"


#line 1 "..\\src\\common\\CGrapParam.h"












 

#line 16 "..\\src\\common\\CGrapParam.h"



#line 71 "..\\src\\common\\CGrapParam.h"

void SetBaseAddr(uint8 row,uint8 tmp);
void AddBaseAddr(uint8 row);
void SubBaseAddr(uint8 row);
uint8 GetBaseAddr(uint8 row);

void set_BaseAddr_default(void);

void AddLocalParaSel(void);
void SetLocalParaSel(uint8 tmp);
uint8 GetLocalParaSel(void);


void Set_department(uint8 row,uint8 tmp);

void Add_department(uint8 row);
void Sub_department(uint8 row);
uint8 Get_zone_bit(uint8 row);

void Add_department_sel(void);
void Set_department_sel(uint8 tmp);
uint8 Get_zone_bit_sel(void);
void check_localaddr(void);







void SetComRegFlag(void);
uint8 GetComRegFlag(void);
void ClrComRegFlag(void);

void AddCompRegParaSel(void);
void SetCompRegParaSel(uint8 tmp);
uint8 GetCompRegParaSel(void);

void SetCompRegDep(uint16 tmp);
void AddCompRegDep(void);
void SubCompRegDep(void);
uint16 GetCompRegDep(void);

void SetCompRegAddr(uint8 tmp);
void AddCompRegAddr(void);
void SubCompRegAddr(void);
uint8 GetCompRegAddr(void);

void SetCompRegNum(uint16 tmp);
void AddCompRegNum(void);
void SubCompRegNum(void);
uint16 GetCompRegNum(void);

void AddCompSetDep(void);
void SubCompSetDep(void);
uint16 GetCompSetDep(void);
void SetCompSetDep(uint16 tmp);

void AddCompSetNum(void);
void SubCompSetNum(void);
uint16 GetCompSetNum(void);
void SetCompSetNum(uint16 tmp);

void SetComSetSelSet(uint8 tmp);
void AddComSetSelSet(void);
void SubComSetSelSet(void);
uint8 GetComSetSelSet(void);

void AddComSet_seltab(void);
void SubComSet_seltab(void);
uint8 GetComSet_seltab(void);
void SetComSet_seltab(uint8 tmp);

void SetYear(uint16 tmp);
void AddYear(void);
void SubYear(void);
uint16 GetYear(void);

void SetMonth(uint16 tmp);
void AddMonth(void);
void SubMonth(void);
uint16 GetMonth(void);

void AddDay(void);
void SubDay(void);
uint16 GetDay(void);
void SetDay(uint16 tmp);

void SetHour(uint16 tmp);
void AddHour(void);
void SubHour(void);
uint16 GetHour(void);

void SetMintue(uint16 tmp);
void AddMintue(void);
void SubMintue(void);
uint16 GetMintue(void);

void SetSecond(uint16 tmp);
void AddSecond(void);
void SubSecond(void);
uint16 GetSecond(void);

void SetSelTime(uint8 tmp);
void AddSelTime(void);
uint8 GetSelTime(void);

void SetAnnDep(uint16 tmp);
void AddAnnDep(void);
void SubAnnDep(void);
uint16 GetAnnDep(void);

void SetAnnCompNum(uint16 tmp);
void AddAnnCompNum(void);
void SubAnnCompNum(void);
uint16 GetAnnCompNum(void);

void SetAnnSel(uint8 tmp);
void AddAnnSel(void);
uint8 GetAnnSel(void);

void AddSysCheckDep(void);
void SubSysCheckDep(void);
void SetSysCheckDep(uint8 tmp);
uint8 GetSysCheckDep(void);

void AddStatusDep(void);
void SubStatusDep(void);
void SetStatusDep(uint8 tmp);
uint8 GetStatusDep(void);

void AddStatusComp(void);
void SubStatusComp(void);
void SetStatusComp(uint8 tmp);
uint8 GetStatusComp(void);

void AddStatusFlag(void);
void SetStatusFlag(uint8 tmp);
uint8 GetStatusFlag(void);


void AddIntenDep(void);
void SubIntenDep(void);
void SetIntenDep(uint8 tmp);
uint8 GetIntenDep(void);

void AddIntenComp(void);
void SubIntenComp(void);
void SetIntenComp(uint8 tmp);
uint8 GetIntenComp(void);

void AddIntenFlag(void);
void SetIntenFlag(uint8 tmp);
uint8 GetIntenFlag(void);



#line 53 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Hardware\\Delay.h"












 






void SysTick_Handler(void);   

void delay1(void);
void Delay1Ms(uint32 t);




 


#line 55 "..\\src\\APP\\include.h"


#line 1 "..\\src\\MenuCtrl\\runfunction.h"












 

#line 1 "..\\src\\common\\CFlashParam.h"












 

#line 16 "..\\src\\common\\CFlashParam.h"




#line 1 "..\\src\\Board\\pcf8563.h"















 

#line 19 "..\\src\\Board\\pcf8563.h"
#line 101 "..\\src\\Board\\pcf8563.h"



 
#line 21 "..\\src\\common\\CFlashParam.h"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 22 "..\\src\\common\\CFlashParam.h"
#line 1 "..\\src\\Hardware\\UART\\uart.h"


















 
#line 21 "..\\src\\Hardware\\UART\\uart.h"

#line 580 "..\\src\\Hardware\\UART\\uart.h"


 
#line 23 "..\\src\\common\\CFlashParam.h"









#line 40 "..\\src\\common\\CFlashParam.h"


#line 54 "..\\src\\common\\CFlashParam.h"









uint8 vGetDatatoFlash[50 +1][13]={0};
uint8 vGetDepNum[50 +1]={0};
uint8 vReadFlashData[16]={0};

uint8 vGetPsn[50 +1][8]={0};

uint8 vCirCounter=0;



 
uint16 vHisCounter=0;


uint8 FlashData[50 +1][15]={0};
uint16 vGetCom0Ann[100][8]={0};
uint8  vHistFlag=0;
uint8 vPageCounter=0;

static PCF8563_DATE history_alarmtime;





 
 
 
 
 

#line 103 "..\\src\\common\\CFlashParam.h"





 
 
 
 
 







typedef	union FlashInfoDef
{
    
    uint8    row;  
    uint8 	 type;	
    uint8	   setup;	
    uint8    alarmtype;
    
    
    uint16  year;
    uint8   month;
    uint8   day;
    uint8   hour;
    uint8   minute;
    uint8   second;
    
    uint8    signal;
    uint8    compann;
}tFlashinfoDef,*PFlashinfoDef;






 
 
 
 
 

typedef void (void_fnc_t) (void);
typedef struct Flash_Record{
    uint32 addr;
    uint8 (*buf)[(1)];
    uint8 (*bigbuf)[(8)];
    uint8 (*alarmbuf)[(18)];
    uint8 (*nodebuf)[(2)]; 
    uint8 (*histbuf)[(17)]; 
    uint32 llen;
    uint32 rlen;
    void_fnc_t *initfun;
    void_fnc_t *savefun;
}Flash_Record;



 
 
 
 
 






 
 
 
 
 








typedef struct alarminfo{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 alarmsum;
    uint8 type;
    uint8 alarmed;
    PCF8563_DATE dateyear;
    uint8 firstalarm;
    uint8 attr;
    uint8 vAnnRow;
    uint8 reserve;
}alarminfo;

 
 
 
 
 
typedef struct history_st{
    uint8 order;
    uint8 inzone;
    uint8 part;
    uint8 circleaddr;
    uint8 vAnnRow;
    uint8 attr;
    uint8 opstype;
    uint8 devtype;
    uint8 lastnum;
    PCF8563_DATE dateyear;
}history_st;



typedef struct
{
    uint32 firesum;
    uint32 faultsum;
    uint32 battlowsum;
}tSum;

 
 
 
 
 






typedef struct compent{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 psn0;
    uint8 psn1;
    uint8 psn2;
    uint8 psn3;
    uint8 devtype;
}compent;







 
void SetHistFlag(uint8 tmp);
uint8 GetHistFlag(void);

uint8 gethistory_isfirealarm(uint32 row);

uint8 gethistory_isbatlow(uint32 row);

uint8 gethistory_isfault(uint32 row);
void AddPageConter(void);
void SetPageConter(uint8 tmp);
uint8 GetPageConter(void);
void AddHistConter(void);
uint16 GetHistConter(void);
void SetHistConter(uint16 tmp);

void setHistFullFlag(uint8 flag);
uint8 getHistFullFlag(void);

uint8 getHistFull(void);
static void init_record(Flash_Record * flash_record);
static void save_record(Flash_Record * flash_record);

static void set_array(Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp);

static uint8 get_array(Flash_Record * flash_record,uint32 row,uint32 col);
void init_basic_info(void);
void set_basic_info(uint32 row,uint8 tmp);
uint8 get_basic_info(uint32 row);

void save_basic_info(void);

void set_basic_nums(uint8 compnums);

void add_basic_nums(void);

void sub_basic_nums(void);
void set_basic_localaddr(uint8 localaddr);
void set_basic_zones(uint8 departallnums);
uint32 get_basic_localaddr(void);
uint32 get_basic_zones(void);
uint32 get_basic_nums(void);
void init_comp_info(void);
void save_comp_info(void);

static void set_comp_info(uint32 row,uint32 col,uint8 tmp);

static uint8 get_comp_info(uint32 row,uint32 col);

void set_comp_inzone(uint8 item,uint8 inzone);

void set_comp_partnumber(uint8 item,uint8 partnumber);
void set_comp_ciraddr(uint8 item,uint8 ciraddr);
void set_comp_psn0(uint8 item,uint8 psn0);
void set_comp_psn1(uint8 item,uint8 psn1);
void set_comp_psn2(uint8 item,uint8 psn2);
void set_comp_psn3(uint8 item,uint8 psn3);
void set_comp_devtype(uint8 item,uint8 devtype);

void set_comp_all(uint8 item,compent *compinfo);

void clr_comp_all(uint8 item);

void clr_comp_loop_all(void);

void set_comp_all_and_save(uint8 item,compent *compinfo);

uint8 get_comp_inzone(uint8 item);
uint8 get_comp_partnumber(uint8 item);
uint8 get_comp_ciraddr(uint8 item);

uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr);
uint8 get_comp_psn0(uint8 item);
uint8 get_comp_psn1(uint8 item);
uint8 get_comp_psn2(uint8 item);
uint8 get_comp_psn3(uint8 item);
uint8 get_comp_devtype(uint8 item);

void get_comp_all(uint8 item, compent *compinfo);
void init_mask_info(void) ;
void save_mask_info(void) ;
void set_mask_info(uint32 row,uint8 tmp);
uint8 get_mask_info(uint32 row) ;

void init_alarm_info(void);

void save_alarm_info(void) ;
static void set_alarm(uint32 row,uint32 col, uint8 tmp);
static uint8 get_alarm_info(uint32 row,uint32 col) ;

uint8 get_alarm_attr(uint32 row);
uint8 get_alarm_alarmed(uint32 row);

uint8 judge_alarm_firealarmed(uint32 row);

uint8 judge_alarm_faultalarmed(uint32 row);
uint8 get_alarm_firstalarm(uint32 row);

void set_alarm_inzone(uint32 item, uint8 tmp);
void set_alarm_part(uint32 item, uint8 tmp);
void set_alarm_ciraddr(uint32 item, uint8 tmp);
void set_alarm_alarmsum(uint32 item, uint8 tmp);
void set_alarm_type(uint32 item, uint8 tmp);
void set_alarm_alarmed(uint32 item, uint8 tmp);
void set_alarm_firstalarm(uint32 item, uint8 tmp);
void set_alarm_allinfo(uint32 item,alarminfo *info);

void clr_alarm_allinfo(void);
void set_alarm_allinfo_andsave(uint32 item,alarminfo *info);
uint8 get_alarm_part(uint32 item);
uint8 get_alarm_ciraddr(uint32 item);
uint8 get_alarm_type(uint32 item);
void get_alarm_allinfo(uint32 item, alarminfo *info);

void set_alarm_first(alarminfo *info);

void get_alarm_first(alarminfo *info);

uint8 get_alarm_firstflag(void);

uint8 get_alarm_first_part(void);

uint8 get_firealarm_nums(void);
void clr_firealarm(void);

uint8 get_alarm_item_bypart(uint8 part);

uint8 get_faultalarm_nums(void);

uint8 judge_alarm_first(void);
void init_node_info(void) ;
void save_node_info(void);

void set_node_info(uint32 row,uint32 col,uint8 tmp);

uint8 get_node_info(uint32 row,uint32 col);

int8 get_node_row( uint8 comp);
void save_node_and_nodenums(void) ;

void init_nodenums_info(void) ;

void save_nodenums_info(void);
void set_nodenums(uint8 tmp);
uint8 get_nodenums(void);
void add_nodenums(void);
void init_hist_info(void) ;
void save_hist_info(void) ;

static uint8 get_hist_info(uint32 row,uint8 col) ;
void set_hist_info(uint32 row,uint8 col,uint8 tmp) ;
void clr_hist_info(void)  ;
uint8 get_hist_order(uint32 row) ;
uint8 get_hist_inzone(uint32 row) ;
uint8 get_hist_part(uint32 row) ;
uint8 get_hist_circleaddr(uint32 row) ;
uint8 get_hist_vAnnRow(uint32 row) ;
uint8 get_hist_attr(uint32 row) ;
uint8 get_hist_opstype(uint32 row) ;
uint8 get_hist_devtype(uint32 row) ;
uint8 get_hist_lastnum(uint32 row) ;

void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear) ;

void get_hist_allinfo(uint32 row, history_st* info);

void set_hist_allinfo(uint32 row, history_st* info);

void save_hist_all(void);

uint8 judge_histnums_full(void);

void set_histnum_full(void);

void init_histnums_info(void) ;
void save_histnums_info(void) ;

static void set_histnum_info(uint32 row,uint8 tmp);

static uint8 get_histnum_info(uint32 row);

void init_hist_and_histnums(void);
void init_histsufix_info(void);

void init_flash_all(void);

uint8 CheckDepComp(uint8 dep,uint8 comp);

int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3);
void CAddCirCounter(void);
void CSetCirCounter(uint8 tmp);
uint8 CGetCirCounter(void);
int8 GetRow(uint8 t1,uint8 t2);

uint8 JudgeAlarmType(void);
uint8 JudgeCompAlarmType(uint8 row);
void SetDatatoFlash(uint8 row,uint8 col,uint8 tmp);
uint8 GetDatatoFlash(uint8 row,uint8 col);

uint8 GetDatatoFlashType(uint8 row);
uint8 GetDatatoFlashAlarmType(uint8 row);
void SetFlashData(uint8 id,uint8 tmp);
void SetDepCompSum(uint16 temp,uint8 tmp);
uint8 GetDepCompSum(uint16 tmp);

uint8 ReadFlashPsn(uint8 row,uint8 col);
void SetCom0Ann(uint8 row,uint8 cow,uint8 tmp);

void set_node_all_info(uint32 row,note_info_t *info);






 


#line 16 "..\\src\\MenuCtrl\\runfunction.h"



























void DisplayKeyMenu(void);
void Systemp_Task(void);
void SendHeart(void);

void CS0Setup(uint8 tmp);
void inqury_state__byuart0(void);


void show_head_menu(void);
void set_history_alarm_pos(uint16 pos);

void set_menu_alarm_info(alarminfo alarm_info);

#line 58 "..\\src\\APP\\include.h"

#line 1 "..\\src\\APP\\publicparam.h"












 

#line 1 "..\\src\\APP\\include.h"












 

#line 115 "..\\src\\APP\\include.h"

#line 18 "..\\src\\APP\\publicparam.h"






 

#line 60 "..\\src\\APP\\include.h"

#line 1 "..\\src\\Menu\\startmenu.h"












 





void Start_Menu12by12(void);
void Start_Menu(void);




 




#line 62 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\mainmenu.h"












 





void Main_Menu(uint8 tmp);
void menu_complete(void);
void menu_press_return_toreturn(void);
void menu_Speaker_Open_Close(uint8 tmp);
void menu_waiting(void);



 
#line 63 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\setmenu.h"












 



void Set_Menu(uint8 tmp);
void CSaveInfo(void);

#line 64 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\checkmenu.h"












 



void Check_Menu(uint8 tmp);

#line 65 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\testmenu.h"












 


void Test_Menu(uint8 tmp);
#line 66 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\batteryLow.h"












 



void Battery_Low(uint8 depart,uint8 compent,uint16 sum,uint8 type,PCF8563_DATE timed);

#line 67 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\breakdown.h"












 


void Breakdown(uint8 attr,uint8 compent,uint16 sum,uint8 type,PCF8563_DATE* timed);


#line 68 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CLocalSet.h"












 



uint16 HZ_SHOW(uint8* hz,uint8 num);

void Local_Menu(uint8 local_addr0,uint8 local_addr1,uint8 local_addr2,uint8 depart0,uint8 depart1,uint8 depart2,uint8 selflag,uint8 sureFlag);

#line 69 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompReg.h"












 




#line 25 "..\\src\\Menu\\CCompReg.h"


void CompReg_menu(uint16 department,uint16 tmp,uint8 regf,uint8 tm2,uint8 rflag,uint8 sureflag);
void menu_compaddr(uint8 line);
void menu_compstatus(void);
void menu_comptype(void);
#line 70 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompSet.h"












 





void CompSet_Menu(uint16 temp,uint16 tmp,uint8 tm,uint8 sflag,uint8 sureflag);
void GNSelect(uint8 tm);
void GNSelectBlack(uint8 tm);
#line 71 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CDateMod.h"












 



void DateMod_Menu(uint16 year,uint8 month,uint8 day,uint8 hour,uint8 minute,uint8 second,uint8 tflag,uint8 sureflag);


#line 72 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CAnnotate.h"












 



void Annotate_Menu(uint8 dep,uint8 comp,uint8 aflag);

#line 73 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CSysCheck.h"












 




void SysCheck_Menu(uint16 t1,uint8 t2,uint8 t3,uint8 t4);

#line 74 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompStat.h"












 




void CompStat_Menu(uint8 t1,uint8 t2,uint8 type,uint8 t4,uint8 t5,uint8 sflag);
#line 75 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CHistoryList.h"












 





 
#line 27 "..\\src\\Menu\\CHistoryList.h"





void History_Menu(uint8 num1,uint8 address,uint8 type,uint8 alarmType,uint8 part,PCF8563_DATE* TimeAndDate);
void menu_nohistory(void);
void menu_history_over(void);



#line 76 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CCompInten.h"












 



void CompInten_Menu(uint8 inzone,uint8 compent,uint8 type,int8 inten);
void CSetIntenFlag(uint8 tmp);
uint8 CGetIntenFlag(void);




#line 77 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\CTestSelf.h"












 



void TestSelf_Menu(void);


#line 78 "..\\src\\APP\\include.h"
#line 1 "..\\src\\Menu\\alarmenu.h"












 




void Alarm_Menu(uint8 fisrtpart,uint8 otherpart,uint8 cirAddr,uint16 alarmsum,uint8 type,PCF8563_DATE *timed);


#line 79 "..\\src\\APP\\include.h"


#line 1 "..\\src\\common\\CTimerTask.h"












 





#line 20 "..\\src\\common\\CTimerTask.h"







 







 
 
 









 
















 






 


 







 
 

 

 
extern void InitTmrTickTask(void); 


extern tBoolean GetTickTaskStatus(uint8 taskID); 			
extern tBoolean GetTickTaskStaNoClr(uint8 taskID);
extern tBoolean SetTmrTickTask(uint8 taskID, uint32 SetMSec);
extern tBoolean KillTickTask(uint8 taskID);

extern void ClearTickTaskTmr(uint8 taskID);  
extern void SetTickTaskSign(uint8 taskID); 			
extern void ClrTickTaskSign(uint8 taskID);
extern tBoolean JudgeTickTaskUsing(uint8 taskID); 			

 





#line 82 "..\\src\\APP\\include.h"


#line 1 "..\\src\\Board\\CLED.h"












 



void Led_Init(void);
void Led_ALL_On(void);
void Led_Off(void);

void Led_Run_Init(void);
void Led_Run_On(void);
void Led_Run_Off(void);

void Led_Silence_Init(void);
void Led_Silence_On(void);
void Led_Silence_Off(void);

void Led_Wireless_Init(void);
void Led_Wireless_On(void);
void Led_Wireless_Off(void);


void Led_Fault_Init(void);
void Led_Fault_On(void);
void Led_Fault_Off(void);


void Led_Fire_Init(void);
void Led_Fire_On(void);
void Led_Fire_Off(void);

#line 85 "..\\src\\APP\\include.h"

#line 1 "..\\src\\13CirCon\\CAddressCount.h"












 


void AddCirCounter(void);
uint32 GetCirCounter(void);

void Clr_Alarm(void);






void SetAlarm_Circuit_Flag(uint8 tmp);


void SetSync(void);
uint8 GetSync(void);
void ClrSync(void);


uint32 SyncFlagCounter(void);
void ClrCirCounter(void);
void addxialasignal(void);
uint8 getxialasignal(void);
void add_weixialasignal(void);

void clr_weixialasignal(void);
void clr_xialasignal(void);
#line 87 "..\\src\\APP\\include.h"

#line 1 "..\\src\\common\\CFlash_ADDR_Def.h"







#line 17 "..\\src\\common\\CFlash_ADDR_Def.h"



#line 89 "..\\src\\APP\\include.h"






















 
 
 


#line 43 "..\\src\\common\\CFlashParam.c"
#line 1 "..\\src\\common\\CFlashParam.h"












 

#line 16 "..\\src\\common\\CFlashParam.h"

#line 473 "..\\src\\common\\CFlashParam.h"


 


#line 45 "..\\src\\common\\CFlashParam.c"
#line 1 "..\\src\\12UARTHandle\\CComHandle.h"












 

#line 16 "..\\src\\12UARTHandle\\CComHandle.h"











#line 36 "..\\src\\12UARTHandle\\CComHandle.h"







#line 49 "..\\src\\12UARTHandle\\CComHandle.h"





















 

#line 79 "..\\src\\12UARTHandle\\CComHandle.h"










#line 97 "..\\src\\12UARTHandle\\CComHandle.h"

#line 130 "..\\src\\12UARTHandle\\CComHandle.h"
void SetFirstAlarm_Flag(uint8 tmp);

void SetDisplay_alarm_flag(uint8 tmp);
uint8 GetDisplay_alarm_flag(void);
void Setdisplay_alarm(uint8 row,uint8 tmp);
uint8 Getdisplay_alarm(uint8 row);
PCF8563_DATE Getalarmtime(void);
void AddHeartFaultFlag(void);


void SetSum(uint8 row,uint8 tmp);
uint8 GetSum(uint8 row);





void SetConvertdata(uint8 col,uint8 tmp);

void UartBindSend(uint8 cmd,uint8 len);
uint8 wireless_data_check(void);
void HandleInfo_Uart1(void);
void set_firealarm_ciraddr(uint8 cir_addr);

void set_faultalarm_ciraddr(uint8 cir_addr);

void set_normalalarm_ciraddr(uint8 cir_addr);

uint8 CompareAddr(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3, int16 *com_num);

void check_lp_running(void);



uint8 check_psn_all0xff(void);





 


#line 46 "..\\src\\common\\CFlashParam.c"
#line 1 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"











 





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
 
 
 


extern  void   Init_CLpScanCtrl(void);

extern  void   NewNode_CLpScanCtrl(void);

extern  void   ClrComm_CLpScanCtrl(void);
extern  void   SetComm_CLpScanCtrl(uint8 vComm);
extern  uint8  GetComm_CLpScanCtrl(void);

extern  void   ClrAddr_CLpScanCtrl(void);
extern  void   IncAddr_CLpScanCtrl(void);
extern  void   SetAddr_CLpScanCtrl(uint8 vAddr);
extern  uint8  GetAddr_CLpScanCtrl(void);

extern  void    ClrSys_CLpScanCtrl(void);
extern  void    SetSys_CLpScanCtrl(void);
extern  uint8   GetSys_CLpScanCtrl(void);

extern  void    ClrState_CLpScanCtrl(void);
extern  void    SetState_CLpScanCtrl(void);
extern  uint8   GetState_CLpScanCtrl(void);

extern  void    ClrAnsFlag_CLpScanCtrl(void);
extern  void    SetAnsFlag_CLpScanCtrl(void);
extern  uint8   GetAnsFlag_CLpScanCtrl(void);

extern  void    ClrAnsStar_CLpScanCtrl(void);
extern  void    SetAnsStar_CLpScanCtrl(void);
extern  uint8   GetAnsStar_CLpScanCtrl(void);

extern  void    ClrAnsStep_CLpScanCtrl(void);
extern  void    SetAnsStep_CLpScanCtrl(void);
extern  uint8   GetAnsStep_CLpScanCtrl(void);

extern  void    ClrAnsTId_CLpScanCtrl(void);
extern  void    SetAnsTId_CLpScanCtrl(void);
extern  uint8   GetAnsTId_CLpScanCtrl(void);
extern  void    DecAnsTId_CLpScanCtrl(void);



extern  void  SetReset_CLpScanCtrl(void);
extern  uint8 GetReset_CLpScanCtrl(void);
extern  void  ClrReset_CLpScanCtrl(void);

 
 
 

#line 133 "..\\src\\CLoopCtrl\\CLpScanCtrl.h"







#line 47 "..\\src\\common\\CFlashParam.c"
#line 1 "..\\src\\MenuCtrl\\CTaskSure.h"












 




















#line 42 "..\\src\\MenuCtrl\\CTaskSure.h"



























void SetZjFlag(uint8 tmp);
uint8 GetZjFlag(void);
void Set_Note_Flag(void);
void Clr_Note_Flag(void);
uint8 Get_Note_Flag(void);




void CLevel1_Sure(uint8 tmp);
void setup_Sure(uint8 tmp);
void query_Sure(uint8 tmp);
void test_Sure(uint8 tmp);
void CLevel24_Sure(uint8 tmp);
void CLevel27_Sure(void);
void CLevel3_Sure(uint8 tmp);
void menu_press_ok_complete(uint8 line);
void menu_setup_done(void);
void menu_press_ok_save(void);
void SetSpeaker_ON(void);
void SetSpeaker_OFF(void);
uint8 GetSpeaker_Flag(void);
void menu_ops_done(void);

uint16 local_addr_value(void);

void query_compstatus_ok(void);
void menu_compset(void);
void menu_comp_masked(void);
void menu_comp_started(void);
void menu_opsing(void);


void set_enter_flag(void);
uint8 get_enter_falg(void);
void clr_enter_flag(void);
void menu_deling(void);
void menu_comp_noreg(void);


void set_entry_localaddr_flag(void);
uint8 get_entry_localaddr_flag(void);
void clr_entry_localaddr_flag(void);
void reset_ok(void);
#line 48 "..\\src\\common\\CFlashParam.c"
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







#line 49 "..\\src\\common\\CFlashParam.c"












void SetHistFlag(uint8 tmp)
{
    vHistFlag=tmp;
}
uint8 GetHistFlag(void)
{
    return vHistFlag;
}

























uint8 gethistory_isfirealarm(uint32 row)
{
    if((0x33) == get_hist_attr(row))
        return (1);
    else
        return (0);
}

uint8 gethistory_isbatlow(uint32 row)
{
    if((0x31) == get_hist_attr(row))
        return (1);
    else
        return (0);
}

uint8 gethistory_isfault(uint32 row)
{
    if((0x32) == get_hist_attr(row))
        return (1);
    else
        return (0);
}

void AddPageConter(void)
{
    vPageCounter++;
}
void SetPageConter(uint8 tmp)
{
    vPageCounter=tmp;
}
uint8 GetPageConter(void)
{
    return vPageCounter;
}

void AddHistConter(void)
{
    vHisCounter++;
}
uint16 GetHistConter(void)
{
    return vHisCounter;
}
void SetHistConter(uint16 tmp)
{
    vHisCounter = tmp;
}





 
 
 
 
 










uint8 vHistSufixInfo[(10)][(1)]={0,};





void setHistFullFlag(uint8 flag)
{
    vHistSufixInfo[(0)][0] = flag;
}
uint8 getHistFullFlag(void)
{
    return vHistSufixInfo[(0)][0];
}

uint8 getHistFull(void)
{
    if((1) == getHistFullFlag())
        return 1;
    else
        return 0;
}

 
 
 
 
 




uint8 BaseInfoF[256][(1)]={0,};





 
 
 
 
 



uint8 vSendPSNToFlash[50 +1][(8)]={0,};




 
 
 
 
 




uint8 vMaskPSN[50 +1][(1)] = {0,};







 
 
 
 
 




uint8 AlarmInfo[(50 +1) + 1][(18)]={(0xff),};



 
 
 
 
 
#line 256 "..\\src\\common\\CFlashParam.c"
uint8 data_note[1][(2)]={0,};


 
 
 
 
 



static uint8 vAnnCounter[(1)][(1)]={0,};




 
 
 
 
 




uint8 vHisList[(1000+1)][(17)]={0,};




 
 
 
 
 


uint8 vHisC[3][(1)] = {0,};




 
 
 
 
 

Flash_Record flash_record[]={
    {(0x00000), BaseInfoF ,0,             0,         0,      0, 256,      (1),},
    {(0x10000), 0,        vSendPSNToFlash,0,         0,      0, 50 +1,      (8), },
    {(0x20000), vMaskPSN, 0,              0,         0,      0, 50 +1,      (1), },
    {(0x30000),0,        0,              AlarmInfo, 0,      0, (50 +1) + 1,     (18),},
    {(0x40000),     0,        0,              0,         data_note,  0, 1,      (2),    },
    {(0x80000), vAnnCounter, 0,           0,         0,      0, (1),  (1),},
    {(0x50000),     0,        0,              0,         0,     vHisList, (1000+1), (17),},
    {(0x60000), vHisC,    0,              0,         0,      0, 3,  (1),  },
    {(0x70000), vHistSufixInfo,0 ,      0,         0,      0, (10),(1),},
    {0,}
};

Flash_Record * basic_record = &flash_record[0];
Flash_Record * comp_record = &flash_record[1];
Flash_Record * mask_record = &flash_record[2];
Flash_Record * alarm_record = &flash_record[3];
Flash_Record * node_record = &flash_record[4];
Flash_Record * nodenums_record = &flash_record[5];
Flash_Record * hist_record = &flash_record[6];
Flash_Record * histnums_record = &flash_record[7];
Flash_Record * histsufix_record = &flash_record[8];



static void init_record(Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    uint8 k;
    uint32 rlen = flash_record->rlen;
    if((1) == rlen){
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->buf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((8) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->bigbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((18) == rlen )
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {




                flash_record->alarmbuf[i][j]=0xff;


            }
        }
    }
    else if((2) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->nodebuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((17) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->histbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }

}
static void save_record(Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    uint8 k;
    uint32 rlen = flash_record->rlen;

    check_lp_running();
    M25P80_Section_Erase(flash_record->addr);
    if((1) == rlen){
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->buf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((8) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->bigbuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((18) == rlen )
    {
#line 441 "..\\src\\common\\CFlashParam.c"
    }
    else if((2) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->nodebuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if((17) == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->histbuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }

}
static void clr_record(Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    
    uint32 rlen = flash_record->rlen;
    if((1) == rlen){
#line 485 "..\\src\\common\\CFlashParam.c"
    }
    else if((8) == rlen)
    {
#line 498 "..\\src\\common\\CFlashParam.c"
    }
    else if((18) == rlen )
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {




                flash_record->alarmbuf[i][j]=(0xff);


            }
        }
    }
    else if((2) == rlen)
    {
#line 527 "..\\src\\common\\CFlashParam.c"
    }
    else if((17) == rlen)
    {
#line 540 "..\\src\\common\\CFlashParam.c"
    }
}


static void set_array(Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp)
{
    uint32 rowact;
    uint32 rlen = flash_record->rlen;
    if(row > 0)
    {
        rowact= row-1;
    }else
    {
        rowact = 0;
    }
    
    
    if((1) == rlen )
        flash_record->buf[rowact][col] = tmp;
    else if((8) == rlen)
        flash_record->bigbuf[rowact][col] = tmp;
    else if((18) == rlen)
        flash_record->alarmbuf[rowact][col] = tmp;
    else if((2) == rlen)
        flash_record->nodebuf[rowact][col] = tmp;
    else if((17) == rlen)
        flash_record->histbuf[rowact][col] = tmp;
}

static uint8 get_array(Flash_Record * flash_record,uint32 row,uint32 col)
{
    uint32 rowact;
    uint32 rlen = flash_record->rlen;
    if(row > 0)
    {
        rowact= row-1;
    }else
    {
        rowact = 0;
    }
    

    if((1) == rlen)
        return flash_record->buf[rowact][col];
    else if((8) == rlen)
        return flash_record->bigbuf[rowact][col];
    else if((18) == rlen)
        return flash_record->alarmbuf[rowact][col];
    else if((2) == rlen)
        return flash_record->nodebuf[rowact][col];
    else if((17) == rlen)
        return flash_record->histbuf[rowact][col];
    return 0xff;
}
 
 
 
 
 







void init_basic_info(void)
{
    
    init_record(basic_record);
}
void set_basic_info(uint32 row,uint8 tmp)
{
    set_array(basic_record,row,0,tmp);
}
uint8 get_basic_info(uint32 row)
{
    return get_array(basic_record,row,0);
}

void save_basic_info(void)
{
    Eint_Dis();
    ClrSys_CLpScanCtrl();
    save_record(basic_record);
    Eint_En();
}






void set_basic_nums(uint8 compnums)
{
    if(compnums > 50)
    {
    }
    else
        set_basic_info(3,compnums);
}

void add_basic_nums(void)
{
    if(get_basic_nums() > 50)
    {
    }else
        set_basic_nums(get_basic_nums()+1);
}

void sub_basic_nums(void)
{
    if(get_basic_nums() > 0)
        set_basic_nums(get_basic_nums()-1);
}


void set_basic_localaddr(uint8 localaddr)
{
    set_basic_info(1,localaddr);
}
void set_basic_zones(uint8 departallnums)
{
    set_basic_info(2,departallnums);

}

uint32 get_basic_localaddr(void)
{
    if((0xff) == get_basic_info(1))
        return (150);
    else
        return get_basic_info(1);
}
uint32 get_basic_zones(void)
{
    return get_basic_info(2);
}
uint32 get_basic_nums(void)
{



    uint32 i,nums=0;
    for(i=(1);i<=50;i++)
    {
        if((0xff) != get_comp_partnumber(i))
            nums++;
    }
    return nums;


}







 
 
 
 
 



















































void init_comp_info(void)
{
    init_record(comp_record);
}
void save_comp_info(void)
{
    save_record(comp_record);
}

static void set_comp_info(uint32 row,uint32 col,uint8 tmp)
{
    set_array(comp_record,row,col,tmp);
}

static uint8 get_comp_info(uint32 row,uint32 col)
{
    return get_array(comp_record,row,col);
}


void set_comp_inzone(uint8 item,uint8 inzone)
{
    set_comp_info(item,1,inzone);
}

void set_comp_partnumber(uint8 item,uint8 partnumber)
{
    set_comp_info(item,2,partnumber);
}
void set_comp_ciraddr(uint8 item,uint8 ciraddr)
{
    set_comp_info(item,3,ciraddr);
}
void set_comp_psn0(uint8 item,uint8 psn0)
{
    set_comp_info(item,4,psn0);
}
void set_comp_psn1(uint8 item,uint8 psn1)
{
    set_comp_info(item,5,psn1);
}
void set_comp_psn2(uint8 item,uint8 psn2)
{
    set_comp_info(item,6,psn2);
}
void set_comp_psn3(uint8 item,uint8 psn3)
{
    set_comp_info(item,7,psn3);
}
void set_comp_devtype(uint8 item,uint8 devtype)
{
    set_comp_info(item,8,devtype);
}

void set_comp_all(uint8 item,compent *compinfo)
{
    if(compinfo){
        set_comp_inzone(item,compinfo->inzone);
        set_comp_partnumber(item,compinfo->part);
        set_comp_ciraddr(item,compinfo->ciraddr);
        set_comp_psn0(item,compinfo->psn0);
        set_comp_psn1(item,compinfo->psn1);
        set_comp_psn2(item,compinfo->psn2);
        set_comp_psn3(item,compinfo->psn3);
        set_comp_devtype(item,compinfo->devtype);
    }
}

void clr_comp_all(uint8 item)
{
    set_comp_inzone(item,(0xff));
    set_comp_partnumber(item,(0xff));
    set_comp_ciraddr(item,(0xff));
    set_comp_psn0(item,(0xff));
    set_comp_psn1(item,(0xff));
    set_comp_psn2(item,(0xff));
    set_comp_psn3(item,(0xff));
    set_comp_devtype(item,(0xff));
}

void clr_comp_loop_all(void)
{
    uint8 i;
    for(i=(1);i<= 50;i++)
        if((0xff) != get_comp_partnumber(i))
            ClrReg_CNodeInfo(get_comp_ciraddr(i));
}


void set_comp_all_and_save(uint8 item,compent *compinfo)
{
    set_comp_all(item,compinfo);
    save_comp_info();
}


uint8 get_comp_inzone(uint8 item)
{
    return get_comp_info(item,1);
}
uint8 get_comp_partnumber(uint8 item)
{
    return get_comp_info(item,2);
}
uint8 get_comp_ciraddr(uint8 item)
{
    
    return get_comp_info(item,3);
    
    
    
    
}

uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr)
{
    uint32 i=0;
    for(i= (1) ;i <=50;i++)
    {
        if((get_comp_ciraddr(i) == ciraddr)&&(row!=i))
            return (1);
    }
    return (0);
}

uint8 get_comp_psn0(uint8 item)
{
    return get_comp_info(item,4);
}
uint8 get_comp_psn1(uint8 item)
{
    return get_comp_info(item,5);
}
uint8 get_comp_psn2(uint8 item)
{
    return get_comp_info(item,6);
}
uint8 get_comp_psn3(uint8 item)
{
    return get_comp_info(item,7);
}
uint8 get_comp_devtype(uint8 item)
{
    return get_comp_info(item,8);
}

void get_comp_all(uint8 item, compent *compinfo)
{
    compinfo->inzone  = get_comp_inzone(item);
    compinfo->part    = get_comp_partnumber(item);
    compinfo->ciraddr = get_comp_inzone(item);
    compinfo->psn0    = get_comp_psn0(item);
    compinfo->psn1    = get_comp_psn1(item);
    compinfo->psn2    = get_comp_psn2(item);
    compinfo->psn3    = get_comp_psn3(item);
    compinfo->devtype = get_comp_devtype(item);
}



 
 
 
 
 

void init_mask_info(void) 
{
    init_record(mask_record);
}
void save_mask_info(void) 
{
    save_record(mask_record);
}
void set_mask_info(uint32 row,uint8 tmp)
{
    set_array(mask_record,row,0,tmp);
}
uint8 get_mask_info(uint32 row) 
{
    return get_array(mask_record,row,0);
}




 
 
 
 
 













void init_alarm_info(void)
{
    init_record(alarm_record);
}

void save_alarm_info(void) 
{
    save_record(alarm_record);
}


static void set_alarm(uint32 row,uint32 col, uint8 tmp)
{
    set_array(alarm_record,row,col,tmp);
}
static uint8 get_alarm_info(uint32 row,uint32 col) 
{
    return get_array(alarm_record,row,col);
}

uint8 get_alarm_attr(uint32 row)
{
    return get_alarm_info(row,16);
}
uint8 get_alarm_alarmed(uint32 row)
{
    return get_alarm_info(row,6);
}









uint8 judge_alarm_firealarmed(uint32 row)
{
    if(((0x33) == get_alarm_attr(row))&&get_alarm_alarmed(row))
        return (1);
    else
        return (0);
}

uint8 judge_alarm_faultalarmed(uint32 row)
{
    if(((0x32) == get_alarm_attr(row))&&get_alarm_alarmed(row))
        return (1);
    else
        return (0);
}
uint8 get_alarm_firstalarm(uint32 row)
{
    return get_array(alarm_record,row,15);
}

void set_alarm_inzone(uint32 item, uint8 tmp)
{
    set_alarm(item,1,tmp);
}
void set_alarm_part(uint32 item, uint8 tmp)
{
    set_alarm(item,2,tmp);
}

void set_alarm_ciraddr(uint32 item, uint8 tmp)
{
    set_alarm(item,3,tmp);
}

void set_alarm_alarmsum(uint32 item, uint8 tmp)
{
    set_alarm(item,4,tmp);
}
void set_alarm_type(uint32 item, uint8 tmp)
{
    set_alarm(item,5,tmp);
}

void set_alarm_alarmed(uint32 item, uint8 tmp)
{
    set_alarm(item,6,tmp);
}
void set_alarm_firstalarm(uint32 item, uint8 tmp)
{
    set_alarm(item,15,tmp);
}


void set_alarm_allinfo(uint32 item,alarminfo *info)
{
    set_alarm_inzone(item,info->inzone);
    set_alarm_part(item,info->part);
    set_alarm_ciraddr(item,info->ciraddr);
    set_alarm_alarmsum(item,info->alarmsum);
    set_alarm_type(item,info->type);
    set_alarm_alarmed(item,info->alarmed);
    set_alarm(item,7,info->dateyear.second);
    set_alarm(item,8,info->dateyear.minute);
    set_alarm(item,9,info->dateyear.hour);
    set_alarm(item,10,info->dateyear.day);
    set_alarm(item,11,info->dateyear.week);
    set_alarm(item,12,info->dateyear.month);
    set_alarm(item,13,info->dateyear.year/100);
    set_alarm(item,14,info->dateyear.year%100);
    set_alarm_firstalarm(item,(0x00));
    set_alarm(item,16,info->attr);
    set_alarm(item,17,info->vAnnRow);
}

void clr_alarm_allinfo(void)
{
    clr_firealarm();
    clr_record(alarm_record);
}

void set_alarm_allinfo_andsave(uint32 item,alarminfo *info)
{
    set_alarm_allinfo(item,info);
    save_alarm_info();
}


uint8 get_alarm_part(uint32 item)
{
    return get_alarm_info(item,2);
}
uint8 get_alarm_ciraddr(uint32 item)
{
    return get_alarm_info(item,3);
}
uint8 get_alarm_type(uint32 item)
{
    return get_alarm_info(item,5);
}

void get_alarm_allinfo(uint32 item, alarminfo *info)
{
    info->inzone = get_alarm_info(item,1);
    info->part = get_alarm_info(item,2);
    info->ciraddr = get_alarm_info(item,3);
    info->alarmsum = get_alarm_info(item,4);
    info->type = get_alarm_info(item,5);
    info->alarmed = get_alarm_info(item,6);
    info->dateyear.second =get_alarm_info(item,7);
    info->dateyear.minute =get_alarm_info(item,8);
    info->dateyear.hour =get_alarm_info(item,9);
    info->dateyear.day =get_alarm_info(item,10);
    info->dateyear.week =get_alarm_info(item,11);
    info->dateyear.month =get_alarm_info(item,12);
    info->dateyear.year =get_alarm_info(item,13)*100+get_alarm_info(item,14);
    info->firstalarm    = get_alarm_info(item,15);
    info->attr          = get_alarm_info(item,16);
    info->vAnnRow       = get_alarm_info(item,17);
}

void set_alarm_first(alarminfo *info)
{
    set_alarm_allinfo((51),info);
    set_alarm_firstalarm((51),(0x01));
}

void get_alarm_first(alarminfo *info)
{
    get_alarm_allinfo((51),info);
}

uint8 get_alarm_firstflag(void)
{
    return get_alarm_firstalarm((51));
}

uint8 get_alarm_first_part(void)
{
    return get_alarm_info((51),2);
}

uint8 get_firealarm_nums(void)
{
    uint8 i,nums=0;
    for(i=(1);i<=50;i++)
    {
        if(judge_alarm_firealarmed(i))
        {
            nums++;
        }
    }
    return nums;
}
void clr_firealarm(void)
{
    uint8 i=0;
    for(i=(1);i<=50;i++)
    {
        if(judge_alarm_firealarmed(i))
        {
            lcd_printf("clr %d ciraddr fire alarm!\n");
            set_normalalarm_ciraddr(get_alarm_ciraddr(i));
        }
    }
}


uint8 get_alarm_item_bypart(uint8 part)
{
    uint8 i,nums=0;
    for(i=(1);i<=50;i++)
    {
        if(get_alarm_part(i) == part)
        {
            return i;
        }
    }
    return nums;
}

uint8 get_faultalarm_nums(void)
{
    uint8 i,nums=0;
    for(i=(1);i<=50;i++)
    {
        if(judge_alarm_faultalarmed(i))
        {
            nums++;
        }
    }
    return nums;
}

uint8 judge_alarm_first(void)
{
    if((0x01) == get_alarm_firstflag())
        return (1);
    else
        return (0);
}






















 
 
 
 
 

void init_node_info(void) 
{
    init_record(node_record);
}
void save_node_info(void)
{
    save_record(node_record);
}


void set_node_info(uint32 row,uint32 col,uint8 tmp)
{
    set_array(node_record,row,col,tmp);
}
void set_node_frame1(uint32 row,uint8 tmp)
{
    set_node_info(row,1,tmp);
}
void set_node_frame2(uint32 row,uint8 tmp)
{
    set_node_info(row,2,tmp);
}
void set_node_frame3(uint32 row,uint8 tmp)
{
    set_node_info(row,3,tmp);
}
void set_node_cmd1(uint32 row,uint8 tmp)
{
    set_node_info(row,4,tmp);
}
void set_node_cmd_rw(uint32 row,uint8 tmp)
{
    set_node_info(row,5,tmp);
}
void set_node_devtype(uint32 row,uint8 tmp)
{
    set_node_info(row,6,tmp);
}
void set_node_targetaddr(uint32 row,uint8 tmp)
{
    set_node_info(row,7,tmp);
}
void set_node_controllernum(uint32 row,uint8 tmp)
{
    set_node_info(row,8,tmp);
}
void set_node_datalen(uint32 row,uint8 tmp)
{
    set_node_info(row,9,tmp);
}
void set_node_loop(uint32 row,uint8 tmp)
{
    set_node_info(row,10,tmp);
}
void set_node_addr(uint32 row,uint8 tmp)
{
    set_node_info(row,11,tmp);
}
void set_node_hz(uint32 row,uint8* tmp)
{
    uint8 i;
    for(i=0;i<32;i++)
    {
        set_node_info(row,12+i,tmp[i]);
    }
}
void set_node_cs(uint32 row,uint8* tmp)
{
    uint8 i;
    for(i=0;i<2;i++)
    {
        set_node_info(row,43+i,tmp[i]);
    }
}

void set_node_all_info(uint32 row,note_info_t *info)
{
    set_node_frame1(row,info->frame1);
    set_node_frame2(row,info->frame2);
    set_node_frame3(row,info->frame3);
    set_node_cmd1(row,info->cmd1);
    set_node_cmd_rw(row,info->cmd_rw);
    set_node_devtype(row,info->devtype);
    set_node_controllernum(row,info->controllernum);
    set_node_datalen(row,info->datelen);
    set_node_targetaddr(row,info->targetaddr);
    set_node_loop(row,info->loop);
    set_node_addr(row,info->addr);
    set_node_cs(row,info->cs);
    set_node_hz(row,info->hz);

}




















uint8 get_node_info(uint32 row,uint32 col)
{
    return get_array(node_record,row,col);
}



















int8 get_node_row( uint8 comp)
{
    int8 num = -1;
    uint8 i;
    for(i=(1);i<=50;i++)
    {
        if( (get_node_info(i,2)==comp))
        {
            num = i;
            break;
        }
    }
    return num;
}





























void save_node_and_nodenums(void) 
{
    save_node_info();
    set_nodenums(get_nodenums()+1);
    save_nodenums_info();
}


 
 
 
 
 


void init_nodenums_info(void) 
{
    init_record(nodenums_record);
    if(get_nodenums() == 0xff)
        set_nodenums(0);
}

void save_nodenums_info(void)
{
    save_record(nodenums_record);
}
void set_nodenums(uint8 tmp)
{
    set_array(nodenums_record,1,0,tmp);
}

uint8 get_nodenums(void)
{
    return get_array(nodenums_record,1,0);
}
void add_nodenums(void)
{
    set_nodenums(get_nodenums()+1);

}













 
 
 
 
 

void init_hist_info(void) 
{
    init_record(hist_record);
}
void save_hist_info(void) 
{
    save_record(hist_record);
    SetHistConter(GetHistConter()+1);
    
}

static uint8 get_hist_info(uint32 row,uint8 col) 
{
    if(row < (1000+1))
        return get_array(hist_record,row,col);
    else
        return 0xff;
}
void set_hist_info(uint32 row,uint8 col,uint8 tmp) 
{
    if(row < (1000+1))
        set_array(hist_record,row,col,tmp);
}
void clr_hist_info(void)  
{
    uint32 i;
    uint8 j;
    for(i=0;i<(1000+1);i++)
        for(j=0;j<(17);j++)
            set_hist_info(i,j,0xff);
}

uint8 get_hist_order(uint32 row) 
{
    return get_hist_info(row,1);
}
uint8 get_hist_inzone(uint32 row) 
{
    return get_hist_info(row,2);
}
uint8 get_hist_part(uint32 row) 
{
    return get_hist_info(row,3);
}
uint8 get_hist_circleaddr(uint32 row) 
{
    return get_hist_info(row,4);
}
uint8 get_hist_vAnnRow(uint32 row) 
{
    return get_hist_info(row,5);
}
uint8 get_hist_attr(uint32 row) 
{
    return get_hist_info(row,6);
}
uint8 get_hist_opstype(uint32 row) 
{
    return get_hist_info(row,7);
}

uint8 get_hist_devtype(uint32 row) 
{
    return get_hist_info(row,8);
}
uint8 get_hist_lastnum(uint32 row) 
{
    return get_hist_info(row,9);
}

void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear) 
{
    dateyear->second =  get_hist_info(row,10);
    dateyear->minute =  get_hist_info(row,11);
    dateyear->hour =  get_hist_info(row,12);
    dateyear->day =  get_hist_info(row,13);
    dateyear->week =  get_hist_info(row,14);
    dateyear->month =  get_hist_info(row,15);
    dateyear->year =  get_hist_info(row,16)*100 + get_hist_info(row,17);
}

void get_hist_allinfo(uint32 row, history_st* info)
{
    info->order  = get_hist_order(row);
    info->inzone = get_hist_inzone(row);
    info->part   = get_hist_part(row);
    info->circleaddr = get_hist_circleaddr(row);
    info->attr   = get_hist_attr(row);
    info->devtype = get_hist_devtype(row);
    info->lastnum = get_hist_lastnum(row);
    info->vAnnRow = get_hist_vAnnRow(row);
    info->opstype = get_hist_opstype(row);
    get_hist_datetime(row,&info->dateyear);
}

void set_hist_allinfo(uint32 row, history_st* info)
{
    set_hist_info(row,1,info->order);
    set_hist_info(row,2,info->inzone);
    set_hist_info(row,3,info->part);
    set_hist_info(row,4,info->circleaddr);
    set_hist_info(row,5,info->vAnnRow);
    set_hist_info(row,6,info->attr);
    set_hist_info(row,7,info->opstype);
    set_hist_info(row,8,info->devtype);
    set_hist_info(row,9,info->lastnum);
    
    set_hist_info(row,10,info->dateyear.second);
    set_hist_info(row,11,info->dateyear.minute);
    set_hist_info(row,12,info->dateyear.hour);
    set_hist_info(row,13,info->dateyear.day);
    set_hist_info(row,14,info->dateyear.week);
    set_hist_info(row,15,info->dateyear.month);
    set_hist_info(row,16,info->dateyear.year/100);
    set_hist_info(row,17,info->dateyear.year%100);
}


void save_hist_all(void)
{
    save_hist_info();
    save_histnums_info();
}
























































































































































































 
 
 
 
 


uint8 judge_histnums_full(void)
{
    if(10 == get_histnum_info(3))
        return (1);
    else
        return (0);
}

void set_histnum_full(void)
{
    set_histnum_info(3,10);
}


void init_histnums_info(void) 
{
    init_record(histnums_record);
    
    if((0xff) == get_histnum_info(1)&&
            (0xff) == get_histnum_info(2))
        SetHistConter(0);
    else
        SetHistConter(get_histnum_info(1)*100+get_histnum_info(2));
    

    if(judge_histnums_full())
    {
        SetHistConter((1000+1));
        
    }

    if(GetHistConter()>=(1000+1))
    {
        SetHistConter((1000+1));
        set_histnum_full();
        
    }
    

}
void save_histnums_info(void) 
{
    set_histnum_info(1,GetHistConter()/100);
    set_histnum_info(2,GetHistConter()%100);
    if(judge_histnums_full())
    {

    }else{
        set_histnum_info(3,GetHistConter()>=(1000+1)?10:0xff);
    }
    save_record(histnums_record);
}

static void set_histnum_info(uint32 row,uint8 tmp)
{
    set_array(histnums_record,row,0,tmp);
}

static uint8 get_histnum_info(uint32 row)
{
    return get_array(histnums_record,row,0);
}






void init_hist_and_histnums(void)
{
    init_hist_info();
    init_histnums_info();
}





























 
 
 
 
 

void init_histsufix_info(void)
{
    init_record(histsufix_record);
}


void init_flash_all(void)
{
    init_basic_info();
    init_comp_info();
    init_mask_info();
    init_alarm_info();
    
    

    NoteData_Init();
    AnnCounterInit();


    init_hist_and_histnums();
    init_histsufix_info();


}





































uint8 CheckDepComp(uint8 dep,uint8 comp)
{
    uint8 i,sum;
    dep = dep;
    for(i=(1);i <= 50;i++)
    {
        
        if((get_comp_partnumber(i) == comp)&&
                (0xff) != get_comp_partnumber(i))
        {
            sum=1;
            break;
        }
        else
            sum=0;
    }
    return sum;
}


























































































int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3)
{

    int16 temp = -1;
    uint16 j;
    
    for(j=(1);j<=50;j++)
    {
        if((get_comp_psn0(j) == psn0)
                &&(get_comp_psn1(j) == psn1)
                &&(get_comp_psn2(j) == psn2)
                &&(get_comp_psn3(j) == psn3))
        {
            temp=j;
            break;
        }
    }
    return temp;
#line 2085 "..\\src\\common\\CFlashParam.c"

}
void CAddCirCounter(void)
{
    vCirCounter++;
}
void CSetCirCounter(uint8 tmp)
{
    vCirCounter = tmp;
}
uint8 CGetCirCounter(void)
{
    return vCirCounter;
}
int8 GetRow(uint8 t1,uint8 t2)
{
    int8 row=-1;
    uint8 i;

    t1 = t1;
    for(i=(1);i<=50;i++)
    {
        if((get_comp_partnumber(i) == t2)&&
                (0xff) != get_comp_partnumber(i))
        {
            row = i;
            break;
        }
    }
    return row;
}



















uint8 JudgeAlarmType(void)
{
    uint8 i,tmp=0;
    for(i=(1);i<=50;i++)
    {
        if(judge_alarm_firealarmed(i))
        {
            tmp=0;
            break;
        }
        else
            tmp=1;
    }
    return tmp;
}
uint8 JudgeCompAlarmType(uint8 row)
{
    
    uint8 tmp = 0;
    if(vGetDatatoFlash[row][(3)] == (0x33))
        tmp=0;
    else if(vGetDatatoFlash[row][(3)] == (0x33))
        tmp=0;
    else if(vGetDatatoFlash[row][(3)] == (0x31))
        tmp=0;
    else
        tmp=1;
    return tmp;
}
void SetDatatoFlash(uint8 row,uint8 col,uint8 tmp)
{
    vGetDatatoFlash[row][col] = tmp;
}
uint8 GetDatatoFlash(uint8 row,uint8 col)
{
    return vGetDatatoFlash[row][col];
}







uint8 GetDatatoFlashType(uint8 row)
{
    return vGetDatatoFlash[row][1];
}
uint8 GetDatatoFlashAlarmType(uint8 row)
{
    return vGetDatatoFlash[row][(3)];
}
void SetFlashData(uint8 id,uint8 tmp)
{
    vReadFlashData[id] = tmp;
}
void SetDepCompSum(uint16 temp,uint8 tmp)
{
    vGetDepNum[temp] = tmp;
}
uint8 GetDepCompSum(uint16 tmp)
{
    return vGetDepNum[tmp];
}











uint8 ReadFlashPsn(uint8 row,uint8 col)
{
    return vGetPsn[row][col];
}



void SetCom0Ann(uint8 row,uint8 cow,uint8 tmp)
{
    vGetCom0Ann[row][cow]=tmp;
}





