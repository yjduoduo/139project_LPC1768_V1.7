/*
;*********************************************************************************************************
;*                                                
;*                            对象: CCompSet
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompSet.c
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/
#include  "Config.h"
#include  "CCompSet.h"
#include "lcd.h"
#include  "CCompReg.h"
#include  "CTaskSure.h"



void CompSet_Menu(uint16 temp,uint16 tmp,uint8 tm,uint8 sflag,uint8 sureflag)
{
    uint8 hz[]="部件设置防区确认退出";
    ClearScreen(0);
    temp = temp;
    /*	if(sflag == 1)
    {
//        DisplaynumberBlack(1,2,40,(temp/100));
//        DisplaynumberBlack(1,2,48,(temp%100/10));
//        DisplaynumberBlack(1,2,56,(temp%100%10));
        Displaynumber(1,2,40,(tmp/10));
        Displaynumber(1,2,48,(tmp%10));
        GNSelect(tm);
    }
    else */if(sflag == 2)
    {
        //        Displaynumber(1,2,40,(temp/100));
        //        Displaynumber(1,2,48,(temp%100/10));
        //        Displaynumber(1,2,56,(temp%100%10));
        DisplaynumberBlack(2,2,8,(tmp/10));
        DisplaynumberBlack(2,2,16,(tmp%10));
        GNSelect(tm);
    }
    else
    {
        Displaynumber(2,2,8,(tmp/10));
        Displaynumber(2,2,16,(tmp%10));
        GNSelectBlack(tm);
    }
    //部件 设置
    menu_compset();


    //部件地址
    menu_compaddr(2);

    //设置
    DisplayJBHZK(1,4,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(1,4,16,((hz[6]<<8)+hz[7]));
    Displaynumber(1,4,32,0x0A);


    //确认退出
    if(MENU_COMPSET_OPS_DONE == sureflag)
    {
        menu_ops_done();
    }else if(MENU_COMPSET_TIPS == sureflag){
        menu_press_ok_save();
    }
    else if(MENU_COMPSET_OPSING == sureflag)
    {
        menu_opsing();
    }
    else if(MENU_COMPSET_DELING == sureflag)
    {
        menu_deling();
    }
    else if(MENU_COMPSET_STOPED == sureflag)
    {
        menu_comp_masked();
    }
    else if(MENU_COMPSET_STARTED == sureflag)
    {
        menu_comp_started();
    }
    else if(MENU_COMPSET_ERR == sureflag)
    {
        menu_comp_noreg();
    }
    else if(MENU_COMPSET_OK_DEL == sureflag)
    {
        menu_press_ok_complete(6);
    }
}
void GNSelect(uint8 tm)
{
    uint8 hz[]="启用屏蔽删除消音";
    switch(tm)
    {
    case 0:
        //启用
        DisplayJBHZK(1,4,48,((hz[0]<<8)+hz[1]));
        DisplayJBHZK(2,4,0,((hz[2]<<8)+hz[3]));
        break;
    case 1:
        //屏蔽
        DisplayJBHZK(1,4,48,((hz[4]<<8)+hz[5]));
        DisplayJBHZK(2,4,0,((hz[6]<<8)+hz[7]));
        break;
    case 2:
        //删除
        DisplayJBHZK(1,4,48,((hz[8]<<8)+hz[9]));
        DisplayJBHZK(2,4,0,((hz[10]<<8)+hz[11]));
        break;
        //    case 3:
        //        //消音
        //        DisplayJBHZK(1,4,48,((hz[12]<<8)+hz[13]));
        //        DisplayJBHZK(2,4,0,((hz[14]<<8)+hz[15]));
        //        break;
    default:
        break;
    }
}
void GNSelectBlack(uint8 tm)
{
    uint8 hz[]="启用屏蔽删除消音";
    switch(tm)
    {
    case 0:
        //启用
        DisplayJBHZKBlack(1,4,48,((hz[0]<<8)+hz[1]));
        DisplayJBHZKBlack(2,4,0,((hz[2]<<8)+hz[3]));
        break;
    case 1:
        //屏蔽
        DisplayJBHZKBlack(1,4,48,((hz[4]<<8)+hz[5]));
        DisplayJBHZKBlack(2,4,0,((hz[6]<<8)+hz[7]));
        break;
    case 2:
        //删除
        DisplayJBHZKBlack(1,4,48,((hz[8]<<8)+hz[9]));
        DisplayJBHZKBlack(2,4,0,((hz[10]<<8)+hz[11]));
        break;
//    case 3:
//        //消音
//        DisplayJBHZKBlack(1,4,48,((hz[12]<<8)+hz[13]));
//        DisplayJBHZKBlack(2,4,0,((hz[14]<<8)+hz[15]));
//        break;
    default:
        break;
    }
}
