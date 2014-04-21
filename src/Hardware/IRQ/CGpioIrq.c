/*
*********************************************************************************************************
*                                                
*                               ����: CGpioIrq
*                        (c) Copyright 2010-2018, jxm
*                              All Rights Reserved
*                                    Ver1.0
* File : CGpioIrq.C
* By   : jxm
* Date : 2012-09-25
*********************************************************************************************************
*/ 
#define   CGpioIrq_C   
#include  "CGpioIrq.h" 
#include  "LPC17xx.H" 
#include  "CTimeDef.h"
#include  "CSetCurrent.h"
#include  "CLpCkCtrl.h"
// #include  "CLED.h" 


#define PIN24 (0x1<<24)
#define PIN23 (0x1<<23)

#define cLpCk_Pin  PIN24

//ϵͳ��ʼ������
void Init_CGpioIrq(void)
{   
    PINSEL1 &=~(0x03<<16);//p0.24ѡ��ΪGPIO
    FIO0DIR  &= (~ (0x01<<24)) ;  // P0.24����Ϊ����

    IO0IntEnR |=  (0x01<<24);    //�������ж�P0.24
    IO0IntEnF |=  (0x01<<24);    //�½����ж�P0.24
    NVIC_EnableIRQ(EINT3_IRQn);//�ж�ʹ��
    NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //�ж����ȼ�
}


void EINT3_IRQHandler (void)
{
   if(IO0IntStatR&PIN24)   //�����ش���
	 {  
 			 State_0mA();
             SetPer_CLpCkCtrl(cLpCkPer_Rcv);
 			 SetExtint_CLpCkCtrl(cLpCkFlag_ExtR); 
	 }
	 else if(IO0IntStatF&PIN24) //falling edge,send data
	 { 

             SetPer_CLpCkCtrl(cLpCkPer_Ans);
 			 SetExtint_CLpCkCtrl(cLpCkFlag_ExtF); 

	 }
 	 IO0IntClr |= PIN24;	
}


