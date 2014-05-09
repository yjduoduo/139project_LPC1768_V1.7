/*
;*********************************************************************************************************
;*                                                
;*                            对象: CTaskDown
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskDown.c
;* By   : 尹海星
;* 时间 : 2013-06-28
;*********************************************************************************************************
;*/

#include  "include.h"
#include  "CTaskDown.h"
#include  "CKeyCounter.h"
#include  "CGetGrap.h"
// #include  "CFlashParam.h"
#include  "CGetCompSum.h"
#include  "CSendToFlash.h"
#include  "CTaskSure.h"
#include  "store_addr.h"
// #include  "CTaskSure.h"


extern tFlashinfoDef  FlashInfo;
extern PCF8563_DATE    timedate;
uint32 vHisCountDown=0;//历史记录计数
static volatile uint32 vHistCount=0;//历史记录计数





void ClrHisCountDown(void)
{
    vHisCountDown=0;
}
void ClrHistCount(void)
{ 
    vHistCount=0;
}
void Level2_Down(void)//第二层
{
    switch(GetCounter1())
    {
    case 1:
        AddCounter2();//vCounter[1]++;
        if(GetCounter2()>5)//if(vCounter[1] > 5)
            SetCounter2(1);//vCounter[1] = 1;
        GetSetGrap(GetCounter2());
        break;
    case 2:
        AddCounter2();//vCounter[1]++;
        if(GetCounter2()>4)//if(vCounter[1] > 3)
            SetCounter2(1);//vCounter[1] = 1;
        GetCheckGrap(GetCounter2());
        break;
    case 3:
        AddCounter2();//vCounter[1]++;
        if(GetCounter2()>2)//if(vCounter[1] > 2)
            SetCounter2(1);//vCounter[1] = 1;
        GetTestGrap(GetCounter2());
        break;
    case 5://关蜂鸣器 //调整位置，为5
        Debug("close speaker\n");
        SetSpeaker_OFF();
        CLevel27_Sure();
        break;
    default:break;
    }
}
void Level3_Down(void)
{
    switch(GetCounter1())
    {
    case 1:
        setup_Down();
        break;
    case 2:
        Level32_Down();
        break;
    case 3:
        Level33_Down();
        break;
    case 4:
        break;
    default:break;
    }
}
static void setup_localaddr_down(void)
{
    switch(GetLocalParaSel())
    {
    case 1://基地址：010 ——第一位
        if(GetBaseAddr(0) > 0)
            SubBaseAddr(0);
        else
            SetBaseAddr(0,2);
        break;
    case 2://基地址：010 ——第二位
        if(GetBaseAddr(1) > 0)
            SubBaseAddr(1);
        else
            SetBaseAddr(1,9);
        break;
    case 3://基地址：010 ——第三位
        if(GetBaseAddr(2) > 0)
            SubBaseAddr(2);
        else
            SetBaseAddr(2,9);
        break;
    default:
        break;
    }

    check_localaddr();

    if(local_addr_value() != get_basic_localaddr())
        Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                   Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVETIPS);
    else{
        Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                   Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVE_NONE);

    }
}
static void setup_compreg_down(void)
{
    switch(GetCompRegParaSel() )
    {
    //    case 1://防区
    //        if(GetCompRegDep() > 0)
    //            SubCompRegDep();
    //        else
    //            SetCompRegDep(get_basic_zones()>0?get_basic_zones()-1:0);
    //        break;
    case 2://部件
        if(GetCompRegNum() > 1)
            SubCompRegNum();
        else
            SetCompRegNum(MAX_COMP);
        break;
    default:
        break;
    }

    CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),0);

}
static void setup_setcomp_down(void)
{
    switch(GetComSet_seltab())
    {
    //    case 1:
    //        if(GetCompSetDep() > 1)
    //            SubCompSetDep();
    //        else
    //            SetCompSetDep(get_basic_zones()>0?get_basic_zones()-1:0);
    //        break;
    case 2:
        if(GetCompSetNum() > 1)
            SubCompSetNum();
        else
            SetCompSetNum(MAX_COMP);
        break;
    case 3:
        if(GetComSetSelSet() > 0)
            SubComSetSelSet();
        else
            SetComSetSelSet(2);

        break;
    default:
        break;
    }


    CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_TIPS);

}
static void setup_timedate_down(void)
{
    switch(GetSelTime())
    {
    case 1:
        if(GetYear()>0)
            SubYear();
        break;
    case 2:
        if(GetMonth() > 1)
            SubMonth();
        else if(GetMonth() == 1)
            SetMonth(12);
        break;
    case 3:
        if(GetDay() > 1)
            SubDay();
        else if(GetDay() == 1)
            SetDay(31);
        break;
    case 4:
        if(GetHour() > 0)
            SubHour();
        else if(GetHour() == 0)
            SetHour(24);
        break;
    case 5:
        if(GetMintue() > 0)
            SubMintue();
        else if(GetMintue() == 0)
            SetMintue(59);
        break;

    default:
        if(GetSecond() > 0)
            SubSecond();
        else if(GetSecond() == 0)
            SetSecond(59);
        break;
    }
    DateMod_Menu(GetYear(),GetMonth(),GetDay(),GetHour(),GetMintue(),GetSecond(),GetSelTime(),MENU_DATA_TIPS);
    timedate.year = GetYear();
    timedate.month = GetMonth();
    timedate.day      = GetDay();
    timedate.hour     = GetHour();
    timedate.minute   = GetMintue();
    timedate.second   = GetSecond();
}

void setup_Down(void)
{
    switch(GetCounter2())
    {
    case 1://本机设置
        setup_localaddr_down();
        break;
    case 2://部件注册
        setup_compreg_down();
        break;
    case 3://设置部件
        setup_setcomp_down();
        break;
    case 4://日期/时间
        setup_timedate_down();

        break;
        // 		case 5://注释
        // 			if(GetAnnSel() == 1)
        // 			{
        // 				if(GetAnnDep() > 0)
        // 					SubAnnDep();
        // 			}
        // 			else
        // 			{
        // 				if(GetAnnCompNum() > 0)
        // 					SubAnnCompNum();
        // 			}
        // 			ClearScreen(0);
        // 			Annotate_Menu(GetAnnDep(),GetAnnCompNum(),GetAnnSel());
        // 			break;
    default:break;
    }
}
//历史记录的第几条
int32 hist_item(int32 tmp_num)
{
    return tmp_num+1;
}
extern history_st histinfo;
void Level32_Down(void)
{
    int32 tmp_num;

    switch(GetCounter2())
    {
    //    case 1://系统查询
    //        if(GetSysCheckDep()>0)
    //            SubSysCheckDep();
    //        else
    //            SetSysCheckDep(get_basic_zones()>0?get_basic_zones()-1:0);
    //        ClearScreen(0);
    //        SysCheck_Menu(get_basic_zones(),GetCompSum(),GetSysCheckDep(),0);
    //        break;
    case 2://
        //        if(GetStatusFlag() == 1)
        //        {
        //            if(GetStatusDep() > 0)
        //                SubStatusDep();
        //            else
        //                SetStatusDep(get_basic_zones()>0?get_basic_zones()-1:0);
        //        }
        //        else
        //        {
        if(GetStatusComp() > 1)
            SubStatusComp();
        else
            SetStatusComp(MAX_COMP);
        //        }

    
        query_compstatus_ok();

        break;
    case 3://历史记录

        if(++vHisCountDown < GetHistConter())
        {
            tmp_num =GetHistConter()-vHisCountDown-1;
            Debug("history nums:%d\n",GetHistConter());
            Debug("--->>look history xuhao:%d\n",tmp_num);
            if(tmp_num >= 0)
            {
                get_hist_allinfo(tmp_num, &histinfo);
            }
        }
        else
        {
            Debug("-->>history over");
            menu_history_over();
            return;
        }

        Debug("part:%d\n",histinfo.part);
        Debug("circleaddr:%d\n",histinfo.circleaddr);
        Debug("devtype:%d\n",histinfo.devtype);
        Debug("attr:%d\n",histinfo.attr);
        Debug("year:%d\n",histinfo.dateyear.year);
        Debug("month:%d\n",histinfo.dateyear.month);
        Debug("day:%d\n",histinfo.dateyear.day);
        Debug("hour:%d\n",histinfo.dateyear.hour);
        Debug("minute:%d\n",histinfo.dateyear.minute);
        Debug("second:%d\n",histinfo.dateyear.second);

        ClearScreen(0);
        History_Menu(hist_item(tmp_num),histinfo.circleaddr,
                     histinfo.devtype,histinfo.attr,
                     histinfo.part,&histinfo.dateyear);//第一个报警的序号

        break;
    default:break;
    }
}
void Level33_Down(void)
{
    switch(GetCounter2())
    {
    case 1://

        break;
    case 2://
        if(GetIntenFlag() == 1)
        {
            if(GetIntenDep() > 0)
                SubIntenDep();
        }
        else
        {
            if(GetIntenComp() > 0)
                SubIntenComp();
        }
        CompInten_Menu(GetIntenDep(),GetIntenComp(),0,0);
        break;
    case 3://
        break;
    default:
        break;
    }
}
void Level4_Down(void)
{
    switch(GetCounter3())
    {
    case 1://
        break;
    case 2://
        break;
    case 3://
        break;
    default:break;
    }
}

