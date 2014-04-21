/*
;*********************************************************************************************************
;*                                                
;*                            对象: CCompStat
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompStat.c
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CCompStat.h"
#include "lcd.h"
#include  "CFlashParam.h"
#include  "CComPara.h"
#include  "CComHandle.h"
#include  "CTaskSure.h"

void menu_devtype(uint8 *hz,uint8 startnum)
{
    //类型：感烟
    DisplayJBHZK(1,2,48,  HZ_SHOW(hz,startnum));
    DisplayJBHZK(2,2,0, HZ_SHOW(hz,startnum+2));
}
void menu_mask_start(void)
{
    uint8 hz[]="启用";
    uint8 startnum =0;
    DisplayJBHZK(2,2,32,  HZ_SHOW(hz,startnum));
    DisplayJBHZK(2,2,48, HZ_SHOW(hz,startnum+2));
}
void menu_mask_stop(void)
{
    uint8 hz[]="屏蔽";
    uint8 startnum =0;
    DisplayJBHZK(2,2,32,  HZ_SHOW(hz,startnum));
    DisplayJBHZK(2,2,48, HZ_SHOW(hz,startnum+2));
}
//部件状态
void CompStat_Menu(uint8 t1,uint8 t2,uint8 type,uint8 t4,uint8 t5,uint8 sflag)
{
    uint8 hz[]="防区部件感烟感温手报消报输入输出声光正常电池欠压故障火警回路地址";
    uint8 i=0;
    uint8 j=0;
    uint8 AnnFlag=1;
    uint8 num=1;
    uint8 row;

    ClearScreen(0);
    //部件状态
    //    menu_compstatus();
    //部件地址
    menu_compaddr(0);
    //部件
    //	if(sflag == 1)
    //	{
    DisplaynumberBlack(2,0,8,(t2/10));
    DisplaynumberBlack(2,0,16,(t2%10));
    //	}


    menu_comptype();
    //类型
    // 	Display(1,2,0,1326);
    // 	Display(1,2,16,1108);
    // 	Displaynumber(1,2,32,0x0A);

    if(type == DEVTYPE_GANYAN)
    {
        //类型：感烟
        menu_devtype(hz,8);
    }
    else if(type == DEVTYPE_GANWEN)
    {
        //类型：感温
        menu_devtype(hz,12);
    }
    else if(type == DEVTYPE_SHOUBAO)
    {
        //类型：手报
        menu_devtype(hz,16);
    }
    else if(type == DEVTYPE_XIAOBAO)
    {
        //类型：消报
        menu_devtype(hz,20);
    }
    else if(type == DEVTYPE_INPUT)
    {
        //类型：输入
        menu_devtype(hz,24);
    }
    else if(type == DEVTYPE_OUTPUT)
    {
        //类型：输出
        menu_devtype(hz,28);
    }
    else if(type == DEVTYPE_SHENGGUANG)
    {
        //类型：声光
        menu_devtype(hz,32);
    }


    if(MENU_COMPSTATUS_INVALID != sflag)
    {
        switch(get_mask_info(t2))
        {
        case OPSTYPE_START:
            menu_mask_start();
            break;
        case OPSTYPE_STOP:
            menu_mask_stop();
            break;
        default:
            break;
        }

        //输入地址注释
        row = GetAnnRow(t2);
        if((INITVAL != row)&&(row<100)&&(t2>0))
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


    //		//状态
    //// 	Display(1,4,0,703);
    //// 	Display(1,4,16,871);
    //// 	Displaynumber(1,4,32,0x0A);
    //    if(t4 == ATTR_NORMAL)
    //	{
    //		//正常
    //		DisplayJBHZK(2,2,0,((hz[36]<<8)+hz[37]));
    //		DisplayJBHZK(2,2,16,((hz[38]<<8)+hz[39]));
    //	}
    //    else if(t4 == ATTR_BAT_LOW)
    //	{
    //		//类型：电池欠压
    //		DisplayJBHZK(2,2,0,((hz[40]<<8)+hz[41]));
    //		DisplayJBHZK(2,2,16,((hz[42]<<8)+hz[43]));
    //		DisplayJBHZK(2,2,32,((hz[44]<<8)+hz[45]));
    //		DisplayJBHZK(2,2,48,((hz[46]<<8)+hz[47]));
    //	}
    //    else if(t4 == ATTR_FAULT)
    //	{
    //		//故障
    //		DisplayJBHZK(2,2,0,((hz[48]<<8)+hz[49]));
    //		DisplayJBHZK(2,2,16,((hz[50]<<8)+hz[51]));
    //	}
    //    else if(t4 == ATTR_FIRE)
    //	{
    //		//火警
    //		DisplayJBHZK(2,2,0,((hz[52]<<8)+hz[53]));
    //		DisplayJBHZK(2,2,16,((hz[54]<<8)+hz[55]));
    //	}
    //回路地址

    DisplayJBHZK(1,4,0,((hz[56]<<8)+hz[57]));
    DisplayJBHZK(1,4,16,((hz[58]<<8)+hz[59]));
    DisplayJBHZK(1,4,32,((hz[60]<<8)+hz[61]));
    DisplayJBHZK(1,4,48,((hz[62]<<8)+hz[63]));
    Displaynumber(2,4,0,0x0A);
    Displaynumber(2,4,8,(t5/100));
    Displaynumber(2,4,16,(t5%100/10));
    Displaynumber(2,4,24,(t5%10));


    if(MENU_COMPSTATUS_INVALID == sflag)
    {
        menu_comp_noreg();
    }



}

