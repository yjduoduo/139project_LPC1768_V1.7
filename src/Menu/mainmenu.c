/*
;*********************************************************************************************************
;*                                                
;*                            对象: mainmenu
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : mainmenu.c
;* By   : 尹海星
;* 时间 : 2013-06-19
;*********************************************************************************************************
;*/
#include  "include.h"
#include "mainmenu.h"
#include "lcd.h"

static uint8 hz[]="设置查询测试复位恢复出厂设置蜂鸣器";

static void set_menu_setup(void)
{
    Displaynumber(1,0,10,1);//display 1
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,48,((hz[2]<<8)+hz[3]));
}
static void set_menu_query(void)
{
    //查询
    Displaynumber(1,2,10,2);//display 2
    Displaynumber(1,2,18,0x0A);
    DisplayJBHZK(1,2,32,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,2,48,((hz[6]<<8)+hz[7]));
}
static void set_menu_test(void)
{
    //测试
    Displaynumber(1,4,10,3);//display 3
    Displaynumber(1,4,18,0x0A);
    DisplayJBHZK(1,4,32,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(1,4,48,((hz[10]<<8)+hz[11]));

}
static void set_menu_reset(void)
{
    //复位：清除所有报警信息
    Displaynumber(1,2,10,6);//display 6
    Displaynumber(1,2,18,0x0A);
    DisplayJBHZK(1,2,32,((hz[12]<<8)+hz[13]));
    DisplayJBHZK(1,2,48,((hz[14]<<8)+hz[15]));
}
static void set_menu_backtodefault(void)
{
    //恢复出厂设置
    Displaynumber(1,6,10,4);//display 4
    Displaynumber(1,6,18,0x0A);
    DisplayJBHZK(1,6,32,((hz[16]<<8)+hz[17]));
    DisplayJBHZK(1,6,48,((hz[18]<<8)+hz[19]));
    DisplayJBHZK(2,6,0,((hz[20]<<8)+hz[21]));
    DisplayJBHZK(2,6,16,((hz[22]<<8)+hz[23]));
    DisplayJBHZK(2,6,32,((hz[24]<<8)+hz[25]));
    DisplayJBHZK(2,6,48,((hz[26]<<8)+hz[27]));
}
static void set_menu_speaker_setup(void)
{
    //设置蜂鸣器
    Displaynumber(1,0,10,5);//display 5
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,48,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(2,0,0,((hz[28]<<8)+hz[29]));
    DisplayJBHZK(2,0,16,((hz[30]<<8)+hz[31]));
    DisplayJBHZK(2,0,32,((hz[32]<<8)+hz[33]));
}

void Main_Menu(uint8 tmp)
{  
    //	uint8 hz[]="设置查询测试复位系统重置清历史记录蜂鸣器";

    ClearScreen(0);
    Debug("tmp:%d\n",tmp);
    if(tmp == 1)
    {
        Display(1,0,0,0);
    }
    else if(tmp == 2)
    {
        Display(1,2,0,0);
    }
    else if(tmp == 3)
    {
        Display(1,4,0,0);
    }
    else if(tmp == 4)
    {
        Display(1,6,0,0);
    }
    else if(tmp == 5)
        Display(1,0,0,0);
    else if(tmp == 6)
    {
        Display(1,2,0,0);
    }
    else if(tmp == 7)
    {
        Display(1,4,0,0);
    }
    if(tmp<5)
    {
        //设置
        set_menu_setup();

        //查询
        set_menu_query();

        //测试
        set_menu_test();

        //恢复出厂设置
        set_menu_backtodefault();

    }
    else
    {

        //设置蜂鸣器
        set_menu_speaker_setup();
        //复位：清除所有报警信息
        set_menu_reset();
    }

}
void menu_press_return_toreturn(void)
{
    uint8 hz[]="请按返回键返回";
    DisplayJBHZK(1,6,0,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,6,16,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,6,32,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,6,48,((hz[6]<<8)+hz[7]));
    DisplayJBHZK(2,6,0,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(2,6,16,((hz[10]<<8)+hz[11]));
    DisplayJBHZK(2,6,32,((hz[12]<<8)+hz[13]));
}

void menu_complete(void)
{
    uint8 hz[]="完成";
    DisplayJBHZK(1,2,48,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(2,2,0,((hz[2]<<8)+hz[3]));
}


void menu_Speaker_Open_Close(uint8 tmp)
{
    uint8 hz[]="蜂鸣器开关";
    ClearScreen(0);
    //蜂鸣器
    DisplayJBHZK(1,2,16,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,2,32,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,2,48,((hz[4]<<8)+hz[5]));
    Displaynumber(2,2,0,0x0A);
    if(tmp)//开
        DisplayJBHZK(2,2,16,((hz[6]<<8)+hz[7]));
    else //关
        DisplayJBHZK(2,2,16,((hz[8]<<8)+hz[9]));
}
void menu_waiting(void)
{
    
    uint8 hz[]="操作进行中";
    ClearScreen(0);
    //操作进行中
    DisplayJBHZK(1,2,16,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,2,32,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,2,48,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,2,0,((hz[6]<<8)+hz[7]));
    DisplayJBHZK(2,2,16,((hz[8]<<8)+hz[9]));
}
