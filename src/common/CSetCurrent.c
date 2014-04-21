/*
;*********************************************************************************************************
;*                                                
;*                            对象: CSetCurrent
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CSetCurrent.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CSetCurrent.h"

#define PIN21_S1 (1<<21)
#define PIN22_S0 (1<<22)

void State_0mA(void)
{	
    FIO0SET |= PIN21_S1|PIN22_S0;
}


void State_6mA(void)
{
    FIO0SET	|= (PIN21_S1);
    FIO0CLR |= (PIN22_S0);
}

#if 1
void State_20mA(void)
{
    FIO0CLR |= (PIN21_S1) | (PIN22_S0);
}
#else
void State_20mA(void)
{
    FIO0CLR |= (PIN21_S1) ;
    FIO0SET |= (PIN22_S0);
}
#endif
//计数，共计10次
uint8 loop_LD_counter = 0;
//采样次数
#define SAMPLE_TIMES 10
//保存状态
uint8 state_loopLD[SAMPLE_TIMES];
//loop ld 的buffer
//uint8 bufcounter=0;
//uint8 loopldbuf[10]={0,};
//读取LOOP_LD的状态
uint32 get_loopLD_state(void)
{
    return FIO0PIN & (1<<23);
}
//void add_bufcounter(void)
//{
//    bufcounter++;
//    bufcounter %= 10;
//}
//void clr_bufcounter(void)
//{
//    bufcounter = 0;
//}
//uint8 get_bufcounter(void)
//{
//    return bufcounter;
//}
//void set_loopldbuf(uint8 bufcounter,uint8 val)
//{
////    loopldbuf[bufcounter%10] = val;
//}
//void clr_loopldbuf(void)
//{
////    clr_bufcounter();
////    clrbuf(loopldbuf,10);
//}
void clrbuf(uint8* buf,uint8 size)
{
    uint32 i;
    for(i=0;i<size;i++)
    {
        buf[i] = 0;
    }
}

void printbuf(uint8* buf,uint8 size)
{
    uint32 i;
    for(i=0;i<size;i++)
    {
        if(buf[i] != 0)
            Debug("buf[%d],%d\n",i,buf[i]);
    }

}

//void info_loopldbuf(void)
//{
//    printbuf(loopldbuf,10);
//}




void clr_loop_LD_counter(void)
{
    uint8 i=0;
    loop_LD_counter = 0;
    
    for(i=0;i<SAMPLE_TIMES;i++)
    {
        state_loopLD[i] = INITVAL;
    }
}
uint8 get_loop_LD_counter(void)
{
    return loop_LD_counter;
}

void add_loop_LD_counter(void)
{
    loop_LD_counter++;
}

void loop_LD_state(void)
{
    state_loopLD[get_loop_LD_counter()] = get_loopLD_state();
    add_loop_LD_counter();
    if(get_loop_LD_counter() > SAMPLE_TIMES)
    {
        clr_loop_LD_counter();
        return;
    }
}
//是否打印标志
uint8 printflag=0;
void set_print(void)
{
    printflag=1;
}
uint8 get_print(void)
{
    return printflag;
}
void clr_print(void)
{
    printflag=0;
}

//打印状态信息
void state_loopld_printf(void)
{
    uint8 i=0;
    if(get_print())
        for(i=0;i<SAMPLE_TIMES;i++)
        {
            Debug("state_loopLD[%d]:%d\n",i,state_loopLD[i]);
        }
    clr_print();
}


