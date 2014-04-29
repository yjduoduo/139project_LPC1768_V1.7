#line 1 "..\\src\\Menu\\CSysCheck.c"












 
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



 


#line 15 "..\\src\\Menu\\CSysCheck.c"
#line 1 "..\\src\\Menu\\CSysCheck.h"












 




void SysCheck_Menu(uint16 t1,uint8 t2,uint8 t3,uint8 t4);

#line 16 "..\\src\\Menu\\CSysCheck.c"
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

#line 17 "..\\src\\Menu\\CSysCheck.c"
#line 1 "..\\src\\common\\CGetCompSum.h"





















#line 18 "..\\src\\Menu\\CSysCheck.c"
#line 1 "..\\src\\common\\CFlashParam.h"












 

#line 16 "..\\src\\common\\CFlashParam.h"




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




 
#line 21 "..\\src\\common\\CFlashParam.h"
#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 22 "..\\src\\common\\CFlashParam.h"
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
void DebugOnce(char *str,...);

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





 
 
 
 
 
 










 

#line 173 "..\\src\\Hardware\\UART\\uart.h"





 


 



 




 

 


 

 



 
 

 
 


 

 
 


 

 
 

 


 

 
 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 




 

 
 

 

 

 

 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 

 

 

 

 

 

 

 

 


 

 
 


 

 
 

 

 

 

 

 


 

 
 

 

 

 

 


 

 
 

 

 


 

 
 

 


 

 
 

 

 

 

 


 


 


 

 


 

 
 


 

 
 

 

 





 



 




 


 

 

 

 

 





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







 
#line 23 "..\\src\\common\\CFlashParam.h"









#line 40 "..\\src\\common\\CFlashParam.h"


#line 54 "..\\src\\common\\CFlashParam.h"







#line 86 "..\\src\\common\\CFlashParam.h"


 
 
 
 
 

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
    uint8 f_recvmesat3h;
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
static void set_alarm_info(uint32 row,uint32 col, uint8 tmp);
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
void set_alarm_attr(uint32 row, uint8 tmp);
void set_alarm_f_recvmess3h(uint32 item,uint8 flag);
void clr_alarm_f_recvmess3h(uint32 item);
void set_alarm_allinfo(uint32 item,alarminfo *info);

void clr_alarm_allinfo(void);
void set_alarm_allinfo_andsave(uint32 item,alarminfo *info);
uint8 get_alarm_part(uint32 item);
uint8 get_alarm_ciraddr(uint32 item);
uint8 get_alarm_type(uint32 item);

uint8 get_alarm_f_recvmess3h(uint32 item);
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






 


#line 19 "..\\src\\Menu\\CSysCheck.c"

void menu_system_query(void)
{
    uint8 hz[]="系统查询";
    uint8 offset = 16;
    DisplayJBHZK(1,0,0+offset,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,16+offset,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,0,32+offset,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,0,((hz[6]<<8)+hz[7]));

}
void menu_system_query_compnums(void)
{
    uint8 t2 = get_basic_nums();
    uint8 hz[]="注册部件数个";
    DisplayJBHZK(1,2,0,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,2,16,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,2,32,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,2,48,((hz[6]<<8)+hz[7]));
    DisplayJBHZK(2,2,0,((hz[8]<<8)+hz[9]));

    Displaynumber(2,2,16,0x0A);
    Displaynumber(2,2,24,(t2/10));
    Displaynumber(2,2,32,(t2%10));
    DisplayJBHZK(2,2,48,((hz[10]<<8)+hz[11]));

}

void SysCheck_Menu(uint16 t1,uint8 t2,uint8 t3,uint8 t4)
{

    menu_system_query();
    menu_system_query_compnums();
    
    
    
    
    
    
    
    
    
    











































}

