#line 1 "..\\src\\Menu\\CDateMod.c"












 
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



 


#line 15 "..\\src\\Menu\\CDateMod.c"
#line 1 "..\\src\\Menu\\CDateMod.h"












 



void DateMod_Menu(uint16 year,uint8 month,uint8 day,uint8 hour,uint8 minute,uint8 second,uint8 tflag,uint8 sureflag);


#line 16 "..\\src\\Menu\\CDateMod.c"
#line 1 "..\\src\\Board\\lcd.h"












 
#line 1 "..\\inc\\lpc17xx.h"








 
 
 
 
#line 20 "..\\inc\\lpc17xx.h"






 



 

 
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







 
#line 95 "..\\inc\\lpc17xx.h"
#line 1 "..\\inc\\system_LPC17xx.h"




















 










#line 1 "..\\inc\\LPC17xx.h"
#line 33 "..\\inc\\system_LPC17xx.h"

extern uint32_t SystemFrequency;     










 
extern void SystemInit (void);










 
extern void SystemClockUpdate (void);





#line 96 "..\\inc\\lpc17xx.h"


 
 
 


#pragma anon_unions



 
#line 120 "..\\inc\\lpc17xx.h"

#line 136 "..\\inc\\lpc17xx.h"


 

#line 146 "..\\inc\\lpc17xx.h"

























 

























































































































































































 

 




 




				 
 





 



 
#line 387 "..\\inc\\lpc17xx.h"
    
 




 


 
 






 
#line 411 "..\\inc\\lpc17xx.h"










 
#line 440 "..\\inc\\lpc17xx.h"

 
#line 460 "..\\inc\\lpc17xx.h"

 
#line 480 "..\\inc\\lpc17xx.h"

 
#line 500 "..\\inc\\lpc17xx.h"


 
#line 525 "..\\inc\\lpc17xx.h"


 
#line 544 "..\\inc\\lpc17xx.h"

 
#line 565 "..\\inc\\lpc17xx.h"

 
#line 583 "..\\inc\\lpc17xx.h"

 
#line 602 "..\\inc\\lpc17xx.h"


 
#line 611 "..\\inc\\lpc17xx.h"

 
#line 624 "..\\inc\\lpc17xx.h"

 
#line 637 "..\\inc\\lpc17xx.h"


 
#line 657 "..\\inc\\lpc17xx.h"

 
#line 676 "..\\inc\\lpc17xx.h"

 
#line 695 "..\\inc\\lpc17xx.h"


 
#line 713 "..\\inc\\lpc17xx.h"


 







 
#line 756 "..\\inc\\lpc17xx.h"


 
#line 765 "..\\inc\\lpc17xx.h"


 
#line 782 "..\\inc\\lpc17xx.h"


 






 
#line 823 "..\\inc\\lpc17xx.h"


 


 




 
#line 847 "..\\inc\\lpc17xx.h"

 
#line 855 "..\\inc\\lpc17xx.h"


 

 
#line 872 "..\\inc\\lpc17xx.h"

 





 
#line 905 "..\\inc\\lpc17xx.h"

 
#line 932 "..\\inc\\lpc17xx.h"


 
#line 950 "..\\inc\\lpc17xx.h"

 






 






 






 






 






 






 






 







 





 

 



 






 






 




 



 






 
#line 1069 "..\\inc\\lpc17xx.h"


 
#line 1095 "..\\inc\\lpc17xx.h"


 

 









 
#line 1116 "..\\inc\\lpc17xx.h"

 



 


 


 
#line 1145 "..\\inc\\lpc17xx.h"

 
#line 1164 "..\\inc\\lpc17xx.h"

 






 










 
#line 1216 "..\\inc\\lpc17xx.h"

















 
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

#line 17 "..\\src\\Menu\\CDateMod.c"
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




 
#line 18 "..\\src\\Menu\\CDateMod.c"
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
#line 19 "..\\src\\Menu\\CDateMod.c"

extern PCF8563_DATE    TimeAndDate;

void DateMod_Menu(uint16 year,uint8 month,uint8 day,uint8 hour,uint8 minute,uint8 second,uint8 tflag,uint8 sureflag)
{
    uint8 hz[]="日期时间年月日时分秒设置完成";
    ClearScreen(0);


    TimeAndDate.year     = year;
    TimeAndDate.month    = month;
    TimeAndDate.day      = day;
    TimeAndDate.hour     = hour;
    TimeAndDate.minute   = minute;
    TimeAndDate.second   = second;
    if(tflag == 1)
    {
        DisplaynumberBlack(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        DisplaynumberBlack(1,2,24,(TimeAndDate.year%10));
        
        Displaynumber(1,2,48,(TimeAndDate.month / 10));
        Displaynumber(1,2,56,(TimeAndDate.month % 10));
        
        Displaynumber(2,2,16,(TimeAndDate.day / 10));
        Displaynumber(2,2,24,(TimeAndDate.day % 10));
        

        Displaynumber(1,4,16,(TimeAndDate.hour / 10));
        Displaynumber(1,4,24,(TimeAndDate.hour % 10));
        
        Displaynumber(1,4,48,(TimeAndDate.minute / 10));
        Displaynumber(1,4,56,(TimeAndDate.minute % 10));
        
        Displaynumber(2,4,16,(TimeAndDate.second / 10));
        Displaynumber(2,4,24,(TimeAndDate.second % 10));
    }
    else if(tflag == 2)
    {
        Displaynumber(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        Displaynumber(1,2,24,(TimeAndDate.year%10));
        
        DisplaynumberBlack(1,2,48,(TimeAndDate.month / 10));
        DisplaynumberBlack(1,2,56,(TimeAndDate.month % 10));
        
        Displaynumber(2,2,16,(TimeAndDate.day / 10));
        Displaynumber(2,2,24,(TimeAndDate.day % 10));
        

        Displaynumber(1,4,16,(TimeAndDate.hour / 10));
        Displaynumber(1,4,24,(TimeAndDate.hour % 10));
        
        Displaynumber(1,4,48,(TimeAndDate.minute / 10));
        Displaynumber(1,4,56,(TimeAndDate.minute % 10));
        
        Displaynumber(2,4,16,(TimeAndDate.second / 10));
        Displaynumber(2,4,24,(TimeAndDate.second % 10));

    }
    else if(tflag == 3)
    {
        Displaynumber(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        Displaynumber(1,2,24,(TimeAndDate.year%10));
        
        Displaynumber(1,2,48,(TimeAndDate.month / 10));
        Displaynumber(1,2,56,(TimeAndDate.month % 10));
        
        DisplaynumberBlack(2,2,16,(TimeAndDate.day / 10));
        DisplaynumberBlack(2,2,24,(TimeAndDate.day % 10));
        

        Displaynumber(1,4,16,(TimeAndDate.hour / 10));
        Displaynumber(1,4,24,(TimeAndDate.hour % 10));
        
        Displaynumber(1,4,48,(TimeAndDate.minute / 10));
        Displaynumber(1,4,56,(TimeAndDate.minute % 10));
        
        Displaynumber(2,4,16,(TimeAndDate.second / 10));
        Displaynumber(2,4,24,(TimeAndDate.second % 10));

    }
    else if(tflag == 4)
    {
        Displaynumber(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        Displaynumber(1,2,24,(TimeAndDate.year%10));
        
        Displaynumber(1,2,48,(TimeAndDate.month / 10));
        Displaynumber(1,2,56,(TimeAndDate.month % 10));
        
        Displaynumber(2,2,16,(TimeAndDate.day / 10));
        Displaynumber(2,2,24,(TimeAndDate.day % 10));
        

        DisplaynumberBlack(1,4,16,(TimeAndDate.hour / 10));
        DisplaynumberBlack(1,4,24,(TimeAndDate.hour % 10));
        
        Displaynumber(1,4,48,(TimeAndDate.minute / 10));
        Displaynumber(1,4,56,(TimeAndDate.minute % 10));
        
        Displaynumber(2,4,16,(TimeAndDate.second / 10));
        Displaynumber(2,4,24,(TimeAndDate.second % 10));

    }
    else if(tflag == 5)
    {
        Displaynumber(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        Displaynumber(1,2,24,(TimeAndDate.year%10));
        
        Displaynumber(1,2,48,(TimeAndDate.month / 10));
        Displaynumber(1,2,56,(TimeAndDate.month % 10));
        
        Displaynumber(2,2,16,(TimeAndDate.day / 10));
        Displaynumber(2,2,24,(TimeAndDate.day % 10));
        

        Displaynumber(1,4,16,(TimeAndDate.hour / 10));
        Displaynumber(1,4,24,(TimeAndDate.hour % 10));
        
        DisplaynumberBlack(1,4,48,(TimeAndDate.minute / 10));
        DisplaynumberBlack(1,4,56,(TimeAndDate.minute % 10));
        
        Displaynumber(2,4,16,(TimeAndDate.second / 10));
        Displaynumber(2,4,24,(TimeAndDate.second % 10));

    }
    else
    {
        Displaynumber(1,2,16,(((TimeAndDate.year%1000)%100)/10));
        Displaynumber(1,2,24,(TimeAndDate.year%10));
        
        Displaynumber(1,2,48,(TimeAndDate.month / 10));
        Displaynumber(1,2,56,(TimeAndDate.month % 10));
        
        Displaynumber(2,2,16,(TimeAndDate.day / 10));
        Displaynumber(2,2,24,(TimeAndDate.day % 10));
        

        Displaynumber(1,4,16,(TimeAndDate.hour / 10));
        Displaynumber(1,4,24,(TimeAndDate.hour % 10));
        
        Displaynumber(1,4,48,(TimeAndDate.minute / 10));
        Displaynumber(1,4,56,(TimeAndDate.minute % 10));
        
        DisplaynumberBlack(2,4,16,(TimeAndDate.second / 10));
        DisplaynumberBlack(2,4,24,(TimeAndDate.second % 10));

    }

    
    
    DisplayJBHZK(1,0,16,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,32,((hz[2]<<8)+hz[3]));
    Displaynumber(1,0,48,0x0b);   
    DisplayJBHZK(2,0,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,16,((hz[6]<<8)+hz[7]));
    Displaynumber(2,0,32,0x0A);

    Displaynumber(1,2,0,2);
    Displaynumber(1,2,8,0);
    
    
    DisplayJBHZK(1,2,32,((hz[8]<<8)+hz[9]));	  
    
    
    DisplayJBHZK(2,2,0,((hz[10]<<8)+hz[11]));	
    
    
    DisplayJBHZK(2,2,32,((hz[12]<<8)+hz[13])); 

    
    
    DisplayJBHZK(1,4,32,((hz[14]<<8)+hz[15]));	  
    
    
    DisplayJBHZK(2,4,0,((hz[16]<<8)+hz[17]));	
    
    
    DisplayJBHZK(2,4,32,((hz[18]<<8)+hz[19])); 


    if(0x02 == sureflag)
    {
        menu_setup_done();
    }
    else if(0x01 == sureflag)
    {
        menu_press_ok_save();
    }
}
