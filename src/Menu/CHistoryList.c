/*
;*********************************************************************************************************
;*                                                
;*                            对象: CHistoryList
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CHistoryList.c
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CHistoryList.h"
#include 	"lcd.h"
#include   "pcf8563.h"
#include  "CFlashParam.h"
#include  "CComHandle.h"


void menu_nohistory(void)
{
    uint8 hz1[]="无历史记录";
    //无历史记录
    ClearScreen(0);
    DisplayJBHZK(1,2,32,((hz1[0]<<8)+hz1[1]));
    DisplayJBHZK(1,2,48,((hz1[2]<<8)+hz1[3]));
    DisplayJBHZK(2,2,0,((hz1[4]<<8)+hz1[5]));
    DisplayJBHZK(2,2,16,((hz1[6]<<8)+hz1[7]));
    DisplayJBHZK(2,2,32,((hz1[8]<<8)+hz1[9]));
}
void menu_history_over(void)
{
    uint8 hz1[]="记录结束";
    ClearScreen(0);
    DisplayJBHZK(1,2,32,((hz1[0]<<8)+hz1[1]));
    DisplayJBHZK(1,2,48,((hz1[2]<<8)+hz1[3]));
    DisplayJBHZK(2,2,0,((hz1[4]<<8)+hz1[5]));
    DisplayJBHZK(2,2,16,((hz1[6]<<8)+hz1[7]));
}
static void menu_ciraddr(uint8 address)
{
    uint8 hz[]="回路地址";
    DisplayJBHZK(1,0,0,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,16,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,0,32,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,0,48,((hz[6]<<8)+hz[7]));
//    Displaynumber(2,0,0,0x0A);
    Displaynumber(2,0,0,(address/100));
    Displaynumber(2,0,8,(address%100/10));
    Displaynumber(2,0,16,(address%10));
}
static void menu_status(void)
{
    uint8 hz[]="状态";
    DisplayJBHZK(1,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,2,16,HZ_SHOW(hz,2));
    Displaynumber(1,2,32,0x0A);
}
static void menu_start(void)
{
    uint8 hz[]="启用";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
static void menu_stop(void)
{
    uint8 hz[]="屏蔽";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
static void menu_del(void)
{
    uint8 hz[]="删除";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
static void menu_normal(void)
{
    uint8 hz[]="正常";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
static void menu_lowvolatage(void)
{
    uint8 hz[]="电池欠压";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
    DisplayJBHZK(2,2,32,HZ_SHOW(hz,4));
    DisplayJBHZK(2,2,48,HZ_SHOW(hz,6));
}
static void menu_fault(void)
{
    uint8 hz[]="故障";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
static void menu_fire(void)
{
    uint8 hz[]="火警";
    DisplayJBHZK(2,2,0,HZ_SHOW(hz,0));
    DisplayJBHZK(2,2,16,HZ_SHOW(hz,2));
}
//此中的row为part
void History_Menu(uint8 num1,uint8 address,uint8 type,uint8 alarmType,uint8 row,PCF8563_DATE* TimeAndDate)
{
    uint8 i=0;
    uint8 j=0;
    uint8 AnnFlag=1;
    uint8 num=1;

    num1 = num1;
    if((GetHistConter() <= MAX_HIST_NUMS))
    {

        //回路地址
        menu_ciraddr(address);

        //显示历史条数
        Displaynumber(2,0,32,num1/1000);
        Displaynumber(2,0,40,num1%1000/100);
        Displaynumber(2,0,48,num1%1000%100/10);
        Displaynumber(2,0,56,num1%10);


//        switch(type)
//        {
//        case DEVTYPE_GANYAN:
//            //类型：感烟
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,8));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,10));
//            break;
//        case DEVTYPE_GANWEN:
//            //类型：感温
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,12));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,14));
//            break;
//        case DEVTYPE_SHOUBAO:
//            //类型：手报
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,16));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,18));
//            break;
//        case DEVTYPE_XIAOBAO:
//            //类型：消报
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,20));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,22));
//            break;
//        case DEVTYPE_INPUT:
//            //类型：输入
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,24));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,26));
//            break;
//        case DEVTYPE_OUTPUT:
//            //类型：输出
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,28));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,30));
//            break;
//        case DEVTYPE_SHENGGUANG:
//            //类型：声光
//            DisplayJBHZK(1,2,0,HZ_SHOW(hz,32));
//            DisplayJBHZK(1,2,16,HZ_SHOW(hz,34));
//            break;
//        default:
//            break;
//        }

        //状态
        menu_status();

        switch(alarmType)
        {
        case OPSTYPE_STOP:
            menu_stop();
            break;
        case OPSTYPE_START:
            menu_start();
            break;
        case OPSTYPE_DEL:
            menu_del();
            break;
        case OPSTYPE_ALARM_NORMAL:
            //正常
            menu_normal();
            break;
        case OPSTYPE_ALARM_LOWVOL:
            //类型：电池欠压
            menu_lowvolatage();
            break;
        case OPSTYPE_ALARM_FAULT:
            //故障
            menu_fault();
            break;
        case OPSTYPE_ALARM_FIRE:
            //火警
            menu_fire();
            break;
        default:
            break;
        }
        //部件号
        Displaynumber(1,2,40,row/10);
        Displaynumber(1,2,48,row%10);


        //时间
        Displaynumber(1,4,0,2);
        Displaynumber(1,4,8,0);
        Displaynumber(1,4,16,(((TimeAndDate->year%1000)%100)/10));
        Displaynumber(1,4,24,(TimeAndDate->year%10));
        // 		Displaynumber(1,4,32,0x0B);
        Displaynumber(1,4,32,(TimeAndDate->month / 10));
        Displaynumber(1,4,40,(TimeAndDate->month % 10));
        // 		Displaynumber(1,4,56,0x0B);
        Displaynumber(1,4,48,(TimeAndDate->day / 10));
        Displaynumber(1,4,56,(TimeAndDate->day % 10));

        Displaynumber(2,4,16,(TimeAndDate->hour / 10));
        Displaynumber(2,4,24,(TimeAndDate->hour % 10));
        // 		Displaynumber(2,4,48,0x0A);
        Displaynumber(2,4,32,(TimeAndDate->minute / 10));
        Displaynumber(2,4,40,(TimeAndDate->minute % 10));
        Displaynumber(2,4,48,(TimeAndDate->second/10));
        Displaynumber(2,4,56,(TimeAndDate->second%10));
        //输入地址注释
        row = GetAnnRow(get_comp_partnumber(row));
        if((row<100)&&(INITVAL != row))
        {
			if((GetCom0Ann(row,3)>=0x30)&&(GetCom0Ann(row,3)<=0x39))
			{
                Displaynumber(1,6,0,GetCom0Ann(row,3)-0x30);
				i = 4;
				j=1;
				
			}		
			else if((GetCom0Ann(row,3)>=0x61)&&(GetCom0Ann(row,3)<=0x7a))
			{
                Display1(1,6,0,GetCom0Ann(row,3)-0x30);
				i=4;
				j=1;
			}
			else if((GetCom0Ann(row,3)>=0xb0)&&(GetCom0Ann(row,3)<0xff))
			{
				DisplayJBHZK(1,6,0,((GetCom0Ann(row,3)<<8)+GetCom0Ann(row,4)));
				i=5;
				j=2;
			}
// 			else
// 				AnnFlag=0;
			while(AnnFlag)
			{
				if((GetCom0Ann(row,i)>=0xb0)&&(GetCom0Ann(row,i)<0xff))
				{
					if((j==7)&&(num==1))
					{
						num=2;
						j=0;
					}
					DisplayJBHZK(num,6,8*j,((GetCom0Ann(row,(i))<<8)+GetCom0Ann(row,(i+1))));
					i += 2;
					j += 2;
				}
				else if((GetCom0Ann(row,i)>=0x30)&&(GetCom0Ann(row,i)<=0x39))
				{
					Displaynumber(num,6,8*j,(GetCom0Ann(row,i)-0x30));
					i += 1;
					j += 1;
				}
				else if((GetCom0Ann(row,i)>=0x41)&&(GetCom0Ann(row,i)<=0x5a))
				{
					Display1(num,6,8*j,(GetCom0Ann(row,i)-0x27));
					i += 1;
					j += 1;
				}
				else if((GetCom0Ann(row,i)>=0x61)&&(GetCom0Ann(row,i)<=0x7a))
				{
					Display1(num,6,8*j,(GetCom0Ann(row,i)-0x61));
					i += 1;
					j += 1;
				}
				else
					AnnFlag=0;
				if(GetCom0Ann(row,i)==0x87)
					AnnFlag=0;
                if(j>=8)
                {
                    j=0;
                    num=2;
                }
            }
        }

    }
    else
    {
        menu_nohistory();
        //无历史记录
    }

}
