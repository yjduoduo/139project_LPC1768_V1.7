/*
;*********************************************************************************************************
;*                                                
;*                            ����: extint
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : extint.c
;* By   : ������
;* ʱ�� : 2013-06-8
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CAddressCount.h"
#include  "CTimeDef.h"
#include  "CSetCurrent.h"
#include  "CFlashParam.h"

#include  "CLpCkCtrl.h"


uint8 Extint1_flag=0;
uint8 Extint3_flag=0;

volatile uint32_t fallingcount=0;
volatile uint32_t vriseingcount=0;

void extint3_enable(void)
{
    NVIC_EnableIRQ(EINT3_IRQn);//�ж�ʹ��
    NVIC_SetPriority(EINT3_IRQn, PRIO_ZERO); //�ж����ȼ�
}
void extint3_disable(void)
{
    NVIC_DisableIRQ(EINT3_IRQn);
}


/*********************************************************************************************************
** Function name:       Eint3_Init
** Descriptions:        �ⲿ�ж�3��ʼ���������ش��� 
** input parameters:    ��
** Output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void Eint3_Init(void)
{    
    //��·
    //    PINSEL1 &=~(0x03<<14);//p0.23ѡ��ΪGPIO
    //    FIO0DIR  &= (~ (0x01<<23)) ;  // P0.23����Ϊ����
    PINSEL1 &=~(0x03<<16);//p0.24ѡ��ΪGPIO
    FIO0DIR  &= (~ (0x01<<24)) ;  // P0.24����Ϊ����

    IO0IntEnR |=  (0x01<<24);    //�������ж�P0.24
    //     IO0IntEnF |=  (0x01<<24);    //�½����ж�P0.24
    //    IO0IntEnF |=  (0x01<<23);    //�½����ж�P0.23

    extint3_enable();
}


void Eint_Dis(void)
{
    uart_all_disable();
    extint3_disable();
    timern_disable(0);
    timern_disable(1);
    timern_disable(2);
    i2c0_disable();
    IO0IntClr = 0xffff;
    pwm1_disable();

}



void Eint_En(void)
{
    uart_all_enable();
    extint3_enable();
    timern_enable(0);
    timern_enable(1);
    timern_enable(2);
    i2c0_enable();
    IO0IntEnR =  (0x01<<24);    //�������ж�P0.24
    IO0IntEnF =  (0x01<<24);    //ͬʱ�½���
    pwm1_enable();
}


void Eint_DisAll_Exuart(void)
{
    extint3_disable();
    timern_disable(0);
    timern_disable(1);
    timern_disable(2);
    i2c0_disable();
    IO0IntClr = 0xffff;
    pwm1_disable();

}



void Eint_EnAll_Exuart(void)
{
    extint3_enable();
    timern_enable(0);
    timern_enable(1);
    timern_enable(2);
    i2c0_enable();
    IO0IntEnR =  (0x01<<24);    //�������ж�P0.24
    IO0IntEnF =  (0x01<<24);    //ͬʱ�½���
    pwm1_enable();
}


/*********************************************************************************************************
** Function name:       SetE1_flag��ClrE1_flag��GetE1_flag
** Descriptions:        �ⲿ�ж�1��־λ����
** input parameters:    ��
** Output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void SetE1_flag(void)
{
    Extint1_flag   = 1;
}
void ClrE1_flag(void)
{
    Extint1_flag   = 0;
}
uint8 GetE1_flag(void)
{
    return Extint1_flag;
}
void SetE3_flag(void)
{
    Extint3_flag   = 1;
}
void ClrE3_flag(void)
{
    Extint3_flag   = 0;
}
uint8 GetE3_flag(void)
{
    return Extint3_flag;
}
/*********************************************************************************************************
** Function name:       cExt3IntFlow��cExt3IntRise
** Descriptions:        �ⲿ�ж�3�����л�����
** input parameters:    ��
** Output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void cExt3IntFlow(void)
{
    IO0IntEnF = (0x01<<24);    //�½����ж�P0.24
}
void cExt3IntRise(void)
{
    IO0IntEnR = (0x01<<24);    //�������ж�P0.24
}
/*********************************************************************************************************
** Function name:       cExt3IntClrFlow��cExt3IntClrRise
** Descriptions:        �ⲿ�ж�3���жϺ���
** input parameters:    ��
** Output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void cExt3IntClrFlow(void)
{
    IO0IntClr |= IO0IntStatF;
}
void cExt3IntClrRise(void)
{
    IO0IntClr |= IO0IntStatR;
}


void extint1_enable(void)
{
    NVIC_EnableIRQ(EINT1_IRQn);//�ж�ʹ��
    NVIC_SetPriority(EINT1_IRQn, PRIO_FIVE); //�ж����ȼ�
}
void extint1_disable(void)
{
    NVIC_DisableIRQ(EINT1_IRQn);
}

///*********************************************************************************************************
//** Function name:       Eint1_Init
//** Descriptions:        �ⲿ�ж�1��ʼ�����½��ش���
//** input parameters:    ��
//** Output parameters:   ��
//** Returned value:      ��
//�ж�1������RTC_INT
//*********************************************************************************************************/
//void  Eint1_Init(void)
//{
//    PINSEL4 |= (1 << 22);//����p2.11 �ⲿ�ж�1

//    EXTMODE  |= 1 << 0;          /* ���ô�����ʽ     ENIT1���ش���  */
//    //    EXTMODE &= ~(1<<1);            /* ���ô�����ʽ     ENIT1��ƽ����  */
//    EXTPOLAR &= ~(1 << 1);	///* EINT1 is falling edge

//    extint1_enable();
//    // 	 EXTINT    = 2;//1 << 1;
//}


/*********************************************************************************************************
** Function name:       EINT1_IRQHandler
** Descriptions:        �ⲿ�ж�1������
** input parameters:    ��
** Output parameters:   ��
** Returned value:      ��
*********************************************************************************************************/
void EINT1_IRQHandler (void)
{
    Eint_Dis();
    //    Debug("ext1\n");
    EXTINT = 2;//1 << 1;//���жϱ�־
    SetE1_flag();
    Eint_En();
}
