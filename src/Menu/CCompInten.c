/*
;*********************************************************************************************************
;*                                                
;*                            对象: CCompInten
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompInten.c
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/
#include  "Config.h"
#include  "CCompInten.h"
#include "lcd.h"
#include  "include.h"
#include  "CFlashParam.h"
// #include <stdio.h> 
// #include <math.h> 

static void menu_comp_notreged(void)
{
    uint8 nullhz[]="未注册部件";
    DisplayJBHZK(1,4,48,((nullhz[0]<<8)+nullhz[1]));
    DisplayJBHZK(2,4,0,((nullhz[2]<<8)+nullhz[3]));
    DisplayJBHZK(2,4,16,((nullhz[4]<<8)+nullhz[5]));
    DisplayJBHZK(2,4,32,((nullhz[6]<<8)+nullhz[7]));
    DisplayJBHZK(2,4,48,((nullhz[8]<<8)+nullhz[9]));
}
static void menu_comp_sigstrength(void)
{
    uint8 hz[]="部件信号强度";
    //部件信号强度
    DisplayJBHZK(1,0,16,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,32,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,0,48,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,0,((hz[6]<<8)+hz[7]));
    DisplayJBHZK(2,0,16,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(2,0,32,((hz[10]<<8)+hz[11]));
}

static uint8 vInten_Flag=0;
//主循环显示部件信号强度
void CompInten_Menu(uint8 inzone,uint8 compent,uint8 type,int8 inten)
{
    uint8 nten;
    uint8 hz[]="部件信号强度防区类型感烟感温手报消报输入输出声光";
//    uint8 nullhz[]="    ";
    //部件信号强度
    ClearScreen(0);
    menu_comp_sigstrength();
    //防区
    inzone = inzone;
    //部件
    menu_compaddr(2);
    Displaynumber(2,2,8,(compent%100/10));
    Displaynumber(2,2,16,(compent%10));

    //类型
    DisplayJBHZK(1,4,0,((hz[16]<<8)+hz[17]));
    DisplayJBHZK(1,4,16,((hz[18]<<8)+hz[19]));
    Displaynumber(1,4,32,0x0A);
    if(type == 0x30)
    {
        //类型：感烟
        DisplayJBHZK(1,4,48,((hz[20]<<8)+hz[21]));
        DisplayJBHZK(2,4,0,((hz[22]<<8)+hz[23]));
    }
    else if(type == 0x31)
    {
        //类型：感温
        DisplayJBHZK(1,4,48,((hz[24]<<8)+hz[25]));
        DisplayJBHZK(2,4,0,((hz[26]<<8)+hz[27]));
    }
    else if(type == 0x32)
    {
        //类型：手报
        DisplayJBHZK(1,4,48,((hz[28]<<8)+hz[29]));
        DisplayJBHZK(2,4,0,((hz[30]<<8)+hz[31]));
    }
    else if(type == 0x33)
    {
        //类型：消报
        DisplayJBHZK(1,4,48,((hz[32]<<8)+hz[33]));
        DisplayJBHZK(2,4,0,((hz[34]<<8)+hz[35]));
    }
    else if(type == 0x34)
    {
        //类型：输入
        DisplayJBHZK(1,4,48,((hz[36]<<8)+hz[37]));
        DisplayJBHZK(2,4,0,((hz[38]<<8)+hz[39]));
    }
    else if(type == 0x35)
    {
        //类型：输出
        DisplayJBHZK(1,4,48,((hz[40]<<8)+hz[41]));
        DisplayJBHZK(2,4,0,((hz[42]<<8)+hz[43]));
    }
    else if(type == 0x36)
    {
        //类型：声光
        DisplayJBHZK(1,4,48,((hz[44]<<8)+hz[45]));
        DisplayJBHZK(2,4,0,((hz[46]<<8)+hz[47]));
    }else if(type == INITVAL){
        menu_comp_notreged();
    }

    //信号强度
    DisplayJBHZK(1,6,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,6,16,((hz[6]<<8)+hz[7]));
    DisplayJBHZK(1,6,32,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(1,6,48,((hz[10]<<8)+hz[11]));
    Displaynumber(2,6,0,0x0A);
    if(inten<0)
    {
        nten = 256-(uint8)inten;
        Displaynumber(2,6,8,0x0C);
    }
    else
        nten = (uint8)inten;
    Displaynumber(2,6,16,(nten/100));
    Displaynumber(2,6,24,(nten%100/10));
    Displaynumber(2,6,32,(nten%10));
    Debug("strength:-%03d\n",nten);

    //mdb

    Display1(2,6,40,29);
    Display1(2,6,48,27);
    Display1(2,6,56,12);
}
void CSetIntenFlag(uint8 tmp)
{
    vInten_Flag = tmp;
}
uint8 CGetIntenFlag(void)
{
    return vInten_Flag;
}



