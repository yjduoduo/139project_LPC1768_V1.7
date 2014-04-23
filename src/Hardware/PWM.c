/*
;*********************************************************************************************************
;*                                                
;*                            对象: PWM
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : PWM.c
;* By   : 尹海星
;* 时间 : 2013-06-25
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "PWM.h"
#include "type.h"
volatile uint32 match_counter1;

#define FOSC                        12000000                            /*  振荡器频率                  */  
  
#define FCCLK                      (FOSC  * 8)                          /*  主时钟频率<=100Mhz          */  
                                                                        /*  FOSC的整数倍                */  
#define FCCO                       (FCCLK * 3)                          /*  PLL频率(275Mhz~550Mhz)      */  
                                                                        /*  与FCCLK相同，或是其的偶数倍 */  
#define FPCLK                      (FCCLK / 4)                          /*  外设时钟频率,FCCLK的1/2、1/4*/  
                                                                        /*  或与FCCLK相同  */             

/*********************************************************************************************************
变量与宏定义	 
*********************************************************************************************************/
#define BEEP        (1 << 3)                                            /* ·??ù?÷                       */
#define BEEPOFF()   FIO2DIR |= BEEP; FIO2SET = BEEP                     /* ·??ù?÷1?                     */
#define BEEPON()    FIO2DIR |= BEEP; FIO2CLR = BEEP                     /* ·??ù?÷?a                     */


void  beepReverse (void)
{
    if ((FIO0PIN & BEEP)!=0) {
        BEEPON();
    } else {
        BEEPOFF();
    }
}


/******************************************************************************
** Function name:		PWM1_IRQHandler
**
** Descriptions:		PWM1 interrupt handler
**						For now, it only deals with PWM1 match 0
**
** parameters:			None
** Returned value:		None
** 
******************************************************************************/
void PWM1_IRQHandler (void) 
{
#if 0

  match_counter1++;	
//    beepReverse();                                                      /* ·??ù?÷è?·′                    */
   PWM1IR      = 0x01;  
#else
  uint32 regVal;

  regVal = PWM1IR;
  if ( regVal & MR0_INT )
  {
	match_counter1++;	
  }
  PWM1IR |= regVal;		/* clear interrupt flag on match 0 */
  return;
  #endif
}
/******************************************************************************
** Function name:		PWM_Init
**
** Descriptions:		PWM initialization, setup all GPIOs to PWM0~6,
**						reset counter, all latches are enabled, interrupt
**						on PWMMR0, install PWM interrupt to the VIC table.
**
** parameters:			ChannelNum, Duty cycle
** Returned value:		true or fase, if VIC table is full, return false
** 
******************************************************************************/

void PWM_Init(void)
{

#if 0
	match_counter1 = 0;
    PCONP 	|= (1 << 6);		    									/* 打开PWM1电源*/
	  /* Further divider is needed on PWM1 clock. */
    PINSEL4 |= 0x040;	/* set GPIOs for p2.3 PWM1[4] pins on PWM1 */ //01 00 00 00



    PWM1TCR  = 0x02;                                                    /* ?′??PWM1?¨ê±?÷               */
    PWM1TC   = 0;                                                       /* ?¨ê±?÷éè???a0                */
    PWM1PR   = 0;                                                       /* ê±?ó2?·??μ                   */
    PWM1MCR  = 0x03;                                                    /* éè??PWMMR0?￥??oó?′??PWMTC￡?  */
                                                                        /* 2￠2úéú?D??±ê??               */
    PWM1MR0  = FPCLK / 2;  

    PWM1LER =  LER0_EN|LER1_EN;
	
  
//     PWM1LER =  LER4_EN|LER0_EN|LER1_EN|LER2_EN|LER3_EN|LER5_EN|LER6_EN;
// 	
    NVIC_EnableIRQ(PWM1_IRQn);
#elif 1
	match_counter1 = 0;
    PCONP 	|= (1 << 6);		    									/* 打开PWM1电源*/
	  /* Further divider is needed on PWM1 clock. */
    PINSEL4 |= 0x040;	/* set GPIOs for p2.3 PWM1[4] pins on PWM1 */ //01 00 00 00


	PWM1TCR = TCR_RESET;	/* Counter Reset */ 
    PWM1PR = 0x00;		/* count frequency:Fpclk */
	PWM1MCR = PWMMR0I;	/* interrupt on PWMMR0, reset on PWMMR0, reset 
								TC if PWM0 matches */				
	PWM1MR0 = 0;	/* set PWM cycle */
// 	LPC_PWM1->MR1 = cycle * 5/6;
// 	LPC_PWM1->MR2 = cycle * 2/3;
// 	LPC_PWM1->MR3 = cycle * 1/2;
	PWM1MR4 = 0;//6800 * 1/3;
// 	LPC_PWM1->MR5 = cycle * 1/6;
// 	LPC_PWM1->MR6 = 0;	

	PWM1LER =  LER4_EN;
	
	NVIC_EnableIRQ(PWM1_IRQn);
  #else
  match_counter1 = 0;
    PCONP 	|= (1 << 6);		    									/* 打开PWM1电源*/
	  /* Further divider is needed on PWM1 clock. */
    PINSEL4 |= 0x040;	/* set GPIOs for p2.3 PWM1[4] pins on PWM1 */ //01 00 00 00

    PWM1TCR  = 0x02;                                                    /* ?′??PWM1?¨ê±?÷               */
    PWM1TC   = 0;                                                       /* ?¨ê±?÷éè???a0                */
    PWM1PR   = 0;                                                       /* ê±?ó2?·??μ                   */
    PWM1MCR  = 0x03;                                                    /* éè??PWMMR0?￥??oó?′??PWMTC￡?  */
                                                                        /* 2￠2úéú?D??±ê??               */
    PWM1MR0  = FPCLK / 2; 
    
  	PWM1LER =  LER4_EN;
	
	NVIC_EnableIRQ(PWM1_IRQn);
  
  #endif
}
void pwm1_enable(void)
{
    NVIC_EnableIRQ(PWM1_IRQn);
}
void pwm1_disable(void)
{
    NVIC_DisableIRQ(PWM1_IRQn);
}

void PWM1_Set(uint32 cycle, uint32 offset )
{			
#if 1
	PWM1MR0 = cycle;		/* set PWM cycle */
// 	LPC_PWM1->MR1 = cycle * 5/6 + offset;
// 	LPC_PWM1->MR2 = cycle * 2/3 + offset;
// 	LPC_PWM1->MR3 = cycle * 1/2 + offset;
	PWM1MR4 = cycle * 1/2+ offset;
// 	LPC_PWM1->MR5 = cycle * 1/6 + offset;
// 	LPC_PWM1->MR6 = offset;
#else
	PWM1MR0 = cycle;		/* set PWM cycle */
 	PWM1MR1 = cycle * 1/6 + offset;
 	PWM1MR2 = cycle * 1/6 + offset;
 	PWM1MR3 = cycle * 1/6 + offset;
	PWM1MR4 = cycle * 1/6 + offset;
 	PWM1MR5 = cycle * 1/6 + offset;
 	PWM1MR6 = cycle * 1/6 + offset;
#endif

	/* The LER will be cleared when the Match 0 takes place, in order to
	load and execute the new value of match registers, all the PWMLERs need to
	reloaded. all PWM latch enabled */
// 	LPC_PWM1->LER = LER0_EN | LER1_EN | LER2_EN | LER3_EN | LER4_EN | LER5_EN | LER6_EN;
		PWM1LER = LER4_EN;
//     PWM1LER = LER0_EN | LER1_EN | LER2_EN | LER3_EN | LER4_EN | LER5_EN | LER6_EN;
}

/******************************************************************************
** Function name:		PWM_Start
**
** Descriptions:		Enable PWM by setting the PCR, PTCR registers
**
** parameters:			channel number
** Returned value:		None
** 
******************************************************************************/
void PWM1_Start( void )
{
	/* All single edge, all enable */
// 	LPC_PWM1->PCR = PWMENA1 | PWMENA2 | PWMENA3 | PWMENA4 | PWMENA5 | PWMENA6;
//   PWM1PCR = PWMENA1 | PWMENA2 | PWMENA3 | PWMENA4 | PWMENA5 | PWMENA6;
//   PWM1PCR = PWMENA1 | PWMENA2;
     PWM1PCR =  PWMENA4 ;//使能PWM4输出
	PWM1TCR = TCR_CNT_EN | TCR_PWM_EN;	/* counter enable, PWM enable */
  
}
uint8 pwm1startflag=0;
uint8 get_PWM1_Started(void)
{
  return pwm1startflag;
}
void set_PWM1_Started(void)
{
  pwm1startflag=1;
}
void clr_PWM1_Started(void)
{
  pwm1startflag=0;
}
/******************************************************************************
** Function name:		PWM_Stop
**
** Descriptions:		Stop all PWM channels
**
** parameters:			channel number
** Returned value:		None
** 
******************************************************************************/
void PWM1_Stop( void )
{

	PWM1PCR = 0;
	PWM1TCR = 0x00;		/* Stop all PWMs */

}



