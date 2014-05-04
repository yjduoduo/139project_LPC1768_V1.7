#line 1 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"











  
#line 1 "..\\src\\Hardware\\IRQ\\CGpioIrq.h"












 





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



 


#line 20 "..\\src\\Hardware\\IRQ\\CGpioIrq.h"
#line 1 "..\\inc\\LPC17xx.H"








 
 
 
 
#line 20 "..\\inc\\LPC17xx.H"






 



 

 
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



















 




















































 

 
 
 
 
 
 
 
 


#line 1 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"
 
 





 









#line 25 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"







 

     

     
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




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 196 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"

     







     










     











#line 260 "f:\\Keil\\ARM\\RV31\\Inc\\stdint.h"



 


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
  if (ticks > ((1<<24) -1))  
    return (1);                                              

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







 
#line 95 "..\\inc\\LPC17xx.H"
#line 1 "..\\inc\\system_LPC17xx.h"




















 










#line 1 "..\\inc\\LPC17xx.h"
#line 33 "..\\inc\\system_LPC17xx.h"

extern uint32_t SystemFrequency;     










 
extern void SystemInit (void);










 
extern void SystemClockUpdate (void);





#line 96 "..\\inc\\LPC17xx.H"


 
 
 


#pragma anon_unions



 
#line 120 "..\\inc\\LPC17xx.H"

#line 136 "..\\inc\\LPC17xx.H"


 

#line 146 "..\\inc\\LPC17xx.H"

























 

























































































































































































 

 




 




				 
 





 



 
#line 387 "..\\inc\\LPC17xx.H"
    
 




 


 
 






 
#line 411 "..\\inc\\LPC17xx.H"










 
#line 440 "..\\inc\\LPC17xx.H"

 
#line 460 "..\\inc\\LPC17xx.H"

 
#line 480 "..\\inc\\LPC17xx.H"

 
#line 500 "..\\inc\\LPC17xx.H"


 
#line 525 "..\\inc\\LPC17xx.H"


 
#line 544 "..\\inc\\LPC17xx.H"

 
#line 565 "..\\inc\\LPC17xx.H"

 
#line 583 "..\\inc\\LPC17xx.H"

 
#line 602 "..\\inc\\LPC17xx.H"


 
#line 611 "..\\inc\\LPC17xx.H"

 
#line 624 "..\\inc\\LPC17xx.H"

 
#line 637 "..\\inc\\LPC17xx.H"


 
#line 657 "..\\inc\\LPC17xx.H"

 
#line 676 "..\\inc\\LPC17xx.H"

 
#line 695 "..\\inc\\LPC17xx.H"


 
#line 713 "..\\inc\\LPC17xx.H"


 







 
#line 756 "..\\inc\\LPC17xx.H"


 
#line 765 "..\\inc\\LPC17xx.H"


 
#line 782 "..\\inc\\LPC17xx.H"


 






 
#line 823 "..\\inc\\LPC17xx.H"


 


 




 
#line 847 "..\\inc\\LPC17xx.H"

 
#line 855 "..\\inc\\LPC17xx.H"


 

 
#line 872 "..\\inc\\LPC17xx.H"

 





 
#line 905 "..\\inc\\LPC17xx.H"

 
#line 932 "..\\inc\\LPC17xx.H"


 
#line 950 "..\\inc\\LPC17xx.H"

 






 






 






 






 






 






 






 







 





 

 



 






 






 




 



 






 
#line 1069 "..\\inc\\LPC17xx.H"


 
#line 1095 "..\\inc\\LPC17xx.H"


 

 









 
#line 1116 "..\\inc\\LPC17xx.H"

 



 


 


 
#line 1145 "..\\inc\\LPC17xx.H"

 
#line 1164 "..\\inc\\LPC17xx.H"

 






 










 
#line 1216 "..\\inc\\LPC17xx.H"

















 
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




#line 21 "..\\src\\Hardware\\IRQ\\CGpioIrq.h"
 






 
 
 


 
 
 
 
 
 

 
 
 

    void   Init_CGpioIrq(void);    
    void   GPIO_IRQHandler(void);

    

 
 
 



                                       






#line 15 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"
#line 16 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"
#line 1 "..\\src\\Hardware\\Timer\\CTimeDef.h"











 





#line 19 "..\\src\\Hardware\\Timer\\CTimeDef.h"
 







 
 
 






















#line 60 "..\\src\\Hardware\\Timer\\CTimeDef.h"







#line 78 "..\\src\\Hardware\\Timer\\CTimeDef.h"

 
 
  
typedef union type_WaitToRun{
    uint32 Word;
    struct
    {
        volatile uint32 b2ms:1;
        uint32 b20ms:1;
        uint32 b100ms:1;
        uint32 b500ms:1;
    }Flag;


}WaitToRun;
 
 	

 
 
 

  
extern  uint32   Get_CTime0Def(void);
extern  void     Set_CTime0Def(uint32 vTimeId); 
extern  uint32   Sel_CTime0Def(uint8 vTimer);
extern  uint32   Get_Timer_100us(void);
extern  uint32   Get_Timer_200us(void);
extern  uint32   Get_Timer_600us(void);
extern  uint32   Get_Timer_2ms(void);
extern  uint32   Get_Timer_5ms(void);
extern  uint32   Get_Timer_8ms(void);
extern  uint32   Get_Timer_10ms(void);
extern  uint32   Get_Timer_20ms(void);

void AddTwoFallEdgeCounter(void);
void ClrTwoFallEdgeCounter(void);
uint32 GetTwoFallEdgeCounter(void);

void AddRisedgeCounter(void);
void ClrRisedgeCounter(void);
uint32 GetRisedgeCounter(void);

void AddWait2msCounter(void);
void ClrWait2msCounter(void);
uint32 GetWait2msCounter(void);
uint8 Is2msArrived(void);
void Enable2ms(void);
void Disable2ms(void);
uint8 Get2msState(void);



void Set2msArrived(void);
uint32 Get2msArrived(void);
void Clr2msArrived(void);


  
 
 


#line 154 "..\\src\\Hardware\\Timer\\CTimeDef.h"


#line 17 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"
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
#line 18 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"
#line 1 "..\\src\\CLoopCtrl\\CLpCkCtrl.h"











 





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
 
 
 


extern  void  Init_CLpCkCtrl(void);

extern  void   SetExtint_CLpCkCtrl(uint8 vType);
extern  uint8  GetExtint_CLpCkCtrl(void);
extern  void   ClrExtint_CLpCkCtrl(void);

extern  void   ClrPer_CLpCkCtrl(void); 
extern  void   SetPer_CLpCkCtrl(uint8 vType); 
extern  uint8  GetPer_CLpCkCtrl(void); 

extern  void  Clr10ms_CLpCkCtrl(void);
extern  void  Set10ms_CLpCkCtrl(void);
extern  uint8 Get10ms_CLpCkCtrl(void);

extern  void  Clr50ms_CLpCkCtrl(void);
extern  void  Set50ms_CLpCkCtrl(void);
extern  uint8 Get50ms_CLpCkCtrl(void);

extern  void  ClrReset_CLpCkCtrl(void);
extern  void  SetReset_CLpCkCtrl(void);
extern  uint8 GetReset_CLpCkCtrl(void);

extern  void  ClrReg_CLpCkCtrl(void);
extern  void  SetReg_CLpCkCtrl(void);
extern  uint8 GetReg_CLpCkCtrl(void);

extern  void  ClrAlarm_CLpCkCtrl(void);
extern  void  SetAlarm_CLpCkCtrl(void);
extern  uint8 GetAlarm_CLpCkCtrl(void);


extern  void  Clr5s_CLpCkCtrl(void);
extern  void  Set5s_CLpCkCtrl(void);
extern  uint8 Get5s_CLpCkCtrl(void);


extern  void  Clr1s_CLpCkCtrl(void);
extern  void  Set1s_CLpCkCtrl(void);
extern  uint8 Get1s_CLpCkCtrl(void);



 
 
 

#line 130 "..\\src\\CLoopCtrl\\CLpCkCtrl.h"







#line 19 "..\\src\\Hardware\\IRQ\\CGpioIrq.c"









void Init_CGpioIrq(void)
{   
    (*(volatile unsigned long *)(0x4002C000 + 0x04)) &=~(0x03<<16);
    (*(volatile unsigned long *)(0x2009C000 + 0x00))  &= (~ (0x01<<24)) ;  

    (*(volatile unsigned long *)(0x40028000 + 0x90)) |=  (0x01<<24);    
    (*(volatile unsigned long *)(0x40028000 + 0x94)) |=  (0x01<<24);    
    NVIC_EnableIRQ(EINT3_IRQn);
    NVIC_SetPriority(EINT3_IRQn, (0x00)); 
}


void EINT3_IRQHandler (void)
{
   if((*(volatile unsigned long *)(0x40028000 + 0x84))&(0x1<<24))   
	 {  
 			 State_0mA();
             SetPer_CLpCkCtrl(1);
 			 SetExtint_CLpCkCtrl(1); 
	 }
	 else if((*(volatile unsigned long *)(0x40028000 + 0x88))&(0x1<<24)) 
	 { 

             SetPer_CLpCkCtrl(0);
 			 SetExtint_CLpCkCtrl(2); 

	 }
 	 (*(volatile unsigned long *)(0x40028000 + 0x8C)) |= (0x1<<24);	
}


