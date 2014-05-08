/*
;*********************************************************************************************************
;*                                                
;*                            对象: CLocalSet
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CLocalSet.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
#include  "Config.h"
#include  "CLocalSet.h"
#include "lcd.h"
#include "CTaskSure.h"
#include  "include.h"

//汉字
static uint8 hz[]="本机设置报警地址防区总数";

static void menu_haved_saved(void)
{
    uint8 hz[]="保存完成";
    DisplayJBHZK(1,6,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,6,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,6,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,6,48,HZ_SHOW(hz,6));
}
static void menu_saving(void)
{
    static uint8 hz[]="正在保存";
    DisplayJBHZK(1,6,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,6,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,6,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,6,48,HZ_SHOW(hz,6));

}
static void menu_savetips(void)
{
    static uint8 hz[]="请按确定键保存";
    DisplayJBHZK(1,6,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,6,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,6,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,6,48,HZ_SHOW(hz,6));
    DisplayJBHZK(2,6,0,HZ_SHOW(hz,8));
    DisplayJBHZK(2,6,16,HZ_SHOW(hz,10));
    DisplayJBHZK(2,6,32,HZ_SHOW(hz,12));
}
static void menu_localaddr_nochange(void)
{
//    static uint8 hz[]="地址未改变";
//    DisplayJBHZK(1,6,0,HZ_SHOW(hz,0));
//    DisplayJBHZK(1,6,16,HZ_SHOW(hz,2));
//    DisplayJBHZK(1,6,32,HZ_SHOW(hz,4));
//    DisplayJBHZK(1,6,48,HZ_SHOW(hz,6));
//    DisplayJBHZK(2,6,0,HZ_SHOW(hz,8));
////    DisplayJBHZK(2,6,16,HZ_SHOW(hz,10));
////    DisplayJBHZK(2,6,32,HZ_SHOW(hz,12));
}
//显示反显 1:反显，0：正常
static void display_or_reverse(uint8 selflag,uint8  ss,uint8 page,uint8  column,uint8  number)
{
    if(selflag)
        DisplaynumberBlack(ss,page,column,number);
    else
        Displaynumber(ss,page,column,number);
}
#define OFFSET (8)
#define LOCALADDR_1POS 0 + OFFSET
#define LOCALADDR_2POS 8 + OFFSET
#define LOCALADDR_3POS 16 + OFFSET

#define DEPART_1POS 8
#define DEPART_2POS 16
#define DEPART_3POS 24

uint16 HZ_SHOW(uint8* hz,uint8 num)
{
    if(0==num%2)
        return ((hz[num]<<8) + hz[num+1]);
    else{
        Debug("hz_show num not odd\n");
        return 0;
    }
}

void Local_Menu(uint8 local_addr0,uint8 local_addr1,uint8 local_addr2,uint8 depart0,uint8 depart1,uint8 depart2,uint8 selflag,uint8 sureFlag)
{
    ClearScreen(0);
    if(selflag==1)//本机地址
    {
        display_or_reverse(1,2,2,LOCALADDR_1POS,(local_addr0%10));
        display_or_reverse(0,2,2,LOCALADDR_2POS,(local_addr1%10));
        display_or_reverse(0,2,2,LOCALADDR_3POS,(local_addr2%10));
        //        display_or_reverse(0,2,4,DEPART_1POS,(depart0%10));
        //        display_or_reverse(0,2,4,DEPART_2POS,(depart1%10));
        //        display_or_reverse(0,2,4,DEPART_3POS,(depart2%10));
    }
    else if(selflag==2)
    {
        display_or_reverse(0,2,2,LOCALADDR_1POS,(local_addr0%10));
        display_or_reverse(1,2,2,LOCALADDR_2POS,(local_addr1%10));
        display_or_reverse(0,2,2,LOCALADDR_3POS,(local_addr2%10));
        //        display_or_reverse(0,2,4,DEPART_1POS,(depart0%10));
        //        display_or_reverse(0,2,4,DEPART_2POS,(depart1%10));
        //        display_or_reverse(0,2,4,DEPART_3POS,(depart2%10));
    }
    else if(selflag==3)
    {
        display_or_reverse(0,2,2,LOCALADDR_1POS,(local_addr0%10));
        display_or_reverse(0,2,2,LOCALADDR_2POS,(local_addr1%10));
        display_or_reverse(1,2,2,LOCALADDR_3POS,(local_addr2%10));
        //        display_or_reverse(0,2,4,DEPART_1POS,(depart0%10));
        //        display_or_reverse(0,2,4,DEPART_2POS,(depart1%10));
        //        display_or_reverse(0,2,4,DEPART_3POS,(depart2%10));
    }
    //    else if(selflag ==4)//防区
    //	{
    //        display_or_reverse(0,2,2,LOCALADDR_1POS,(local_addr0%10));
    //        display_or_reverse(0,2,2,LOCALADDR_2POS,(local_addr1%10));
    //        display_or_reverse(0,2,2,LOCALADDR_3POS,(local_addr2%10));
    ////        display_or_reverse(1,2,4,DEPART_1POS,(depart0%10));
    ////        display_or_reverse(0,2,4,DEPART_2POS,(depart1%10));
    ////        display_or_reverse(0,2,4,DEPART_3POS,(depart2%10));
    //    }
    //    else if(selflag ==5)
    //    {
    //        display_or_reverse(0,2,2,LOCALADDR_1POS,(local_addr0%10));
    //        display_or_reverse(0,2,2,LOCALADDR_2POS,(local_addr1%10));
    //        display_or_reverse(0,2,2,LOCALADDR_3POS,(local_addr2%10));
    ////        display_or_reverse(0,2,4,DEPART_1POS,(depart0%10));
    ////        display_or_reverse(1,2,4,DEPART_2POS,(depart1%10));
    ////        display_or_reverse(0,2,4,DEPART_3POS,(depart2%10));
    //    }else if(selflag ==6)
    //    {
    //        display_or_reverse(0,2,2,LOCALADDR_1POS,(local_addr0%10));
    //        display_or_reverse(0,2,2,LOCALADDR_2POS,(local_addr1%10));
    //        display_or_reverse(0,2,2,LOCALADDR_3POS,(local_addr2%10));
    ////        display_or_reverse(0,2,4,DEPART_1POS,(depart0%10));
    ////        display_or_reverse(0,2,4,DEPART_2POS,(depart1%10));
    ////        display_or_reverse(1,2,4,DEPART_3POS,(depart2%10));
    //    }

    //本机设置
    DisplayJBHZK(1,0,16,(HZ_SHOW(hz,0)));
    DisplayJBHZK(1,0,32,(HZ_SHOW(hz,2)));
    DisplayJBHZK(1,0,48,(HZ_SHOW(hz,4)));
    DisplayJBHZK(2,0,0,(HZ_SHOW(hz,6)));


    //本机地址
    DisplayJBHZK(1,2,0,(HZ_SHOW(hz,8)));
    DisplayJBHZK(1,2,16,(HZ_SHOW(hz,10)));
    DisplayJBHZK(1,2,32,(HZ_SHOW(hz,12)));
    DisplayJBHZK(1,2,48,(HZ_SHOW(hz,14)));
    Displaynumber(2,2,0,0x0A);

    //确认退出
    if(MENU_SAVE_DONE == sureFlag)
    {
        menu_haved_saved();
    }
    else if(MENU_SAVING == sureFlag)
    {
        menu_saving();
    }
    else if(MENU_SAVETIPS == sureFlag)
    {
        menu_savetips();
    }
    else if(MENU_LOCALADDR_NOCHANGE == sureFlag)
    {
        menu_localaddr_nochange();
    }

}


