/*
;*********************************************************************************************************
;*                                                
;*                            对象: CTaskUp
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskUp.c
;* By   : 尹海星
;* 时间 : 2013-06-28
;*********************************************************************************************************
;*/

#include  "include.h"
#include  "CTaskUp.h"
#include  "CKeyCounter.h"
#include  "CGetGrap.h"
#include  "CFlashParam.h"
#include  "CGetCompSum.h"
#include  "CSendToFlash.h"
#include  "CTaskSure.h"
#include  "store_addr.h"
#include  "CTaskDown.h"

extern tFlashinfoDef  FlashInfo;
extern PCF8563_DATE    timedate;
void Level2_Up(void)
{
    switch(GetCounter1())
    {
    case 1:
        if(GetCounter2() > 1)
            SubCounter2();
        else
            SetCounter2(4);
        GetSetGrap(GetCounter2());
        break;
    case 2:
        if(GetCounter2() > 1)
            SubCounter2();
        else
            SetCounter2(3);
        GetCheckGrap(GetCounter2());
        break;
    case 3:
        if(GetCounter2() > 1)
            SubCounter2();
        else
            SetCounter2(2);
        GetTestGrap(GetCounter2());
        break;
    case 5://调整位置，为5
        Debug("open speaker\n");
        SetSpeaker_ON();
        CLevel27_Sure();
        break;
    default:break;
    }
}
void Level3_Up(void)
{
    switch(GetCounter1())
    {
    case 1://设置
        setup_Up();
        break;
    case 2://查询
        query_Up();
        break;
    case 3://测试
        test_Up();
        break;
    default:break;
    }
}
static void setup_localaddr_up(void)
{
//    Debug("setup_localaddr_up\n");
    switch(GetLocalParaSel())
    {
    case 1://基地址： 第一位
        AddBaseAddr(0);
        if(GetBaseAddr(0) > 2)
            SetBaseAddr(0,0);
        break;
    case 2://基地址： 第二位
        AddBaseAddr(1);
        if(GetBaseAddr(1) > 9)
            SetBaseAddr(1,0);
        break;
    case 3://基地址： 第三位
        AddBaseAddr(2);
        if(GetBaseAddr(2) > 9)
            SetBaseAddr(2,0);
        break;
    default:
        break;
    }

    check_localaddr();

    if(local_addr_value() != get_basic_localaddr())
        Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                   Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVETIPS);
    else
        Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                   Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVE_NONE);


}
static void setup_compreg_up(void)
{
    switch(GetCompRegParaSel())
    {
    //    case 1://防区：000  表示三位数字

    //        AddCompRegDep();
    //        if(GetCompRegDep() >= get_basic_zones())
    //            SetCompRegDep(0);
    //        if(GetCompRegDep()>=DEPART)
    //            SetCompRegDep(0);


    //         break;
    case 2://部件：01 表示两位数字
        AddCompRegNum();
        if(GetCompRegNum() > MAX_COMP)
            SetCompRegNum(1);


        break;
    default:
        break;
    }
    CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),0);
}
static void setup_setcomp_up(void)
{
    switch(GetComSet_seltab())
    {
    //    case 1:
    //        AddCompSetDep();
    //        if(GetCompSetDep() >= get_basic_zones())
    //            SetCompSetDep(0);
    //        break;
    case 2:
        AddCompSetNum();
        if(GetCompSetNum() > MAX_COMP)
            SetCompSetNum(1);
        break;
    case 3:
        AddComSetSelSet();
        if(GetComSetSelSet() > 2)
            SetComSetSelSet(0);
        //        else
        //            SetComSetSelSet(2);

        break;
    default:

        break;
    }

    CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),MENU_COMPSET_TIPS);

}
static void setup_datetime_up(void)
{
    switch(GetSelTime())
    {
    case 1:
        AddYear();
        break;
    case 2:
        AddMonth();
        if(GetMonth()> 12)
            SetMonth(1);
        break;
    case 3:
        AddDay();
        if(GetDay() > 31)
            SetDay(1);
        break;
    case 4:
        AddHour();
        if(GetHour() > 24)
            SetHour(0);
        break;
    case 5:
        AddMintue();
        if(GetMintue() > 60)
            SetMintue(0);
        break;
    default:
        AddSecond();
        if(GetSecond() > 60)
            SetSecond(0);
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

//上键变化数字
void setup_Up(void)
{
    switch(GetCounter2())
    {
    case 1://本机设置
        setup_localaddr_up();
        break;
    case 2://部件注册
        setup_compreg_up();
        break;
    case 3://部件设置
        setup_setcomp_up();

        break;
    case 4://日期/时间
        setup_datetime_up();
        break;
        // 		case 5://注释
        // 			if(GetAnnSel() == 1)
        // 			{
        // 				AddAnnDep();
        // 				if(GetAnnDep() > 99)
        // 					SetAnnDep(0);
        // 			}
        // 			else
        // 			{
        // 				AddAnnCompNum();
        // 				if(GetAnnCompNum() > 99)
        // 					SetAnnCompNum(0);
        // 			}
        // 			ClearScreen(0);
        // 			Annotate_Menu(GetAnnDep(),GetAnnCompNum(),GetAnnSel());
        // 			break;
    default:
        break;
    }
}
static void query_system_up(void)
{
    AddSysCheckDep();
    if(GetSysCheckDep()>=get_basic_zones())
        SetSysCheckDep(0);
    ClearScreen(0);
    SysCheck_Menu(get_basic_zones(),get_basic_nums(),GetSysCheckDep(),0);

}
static void query_compstatus_up(void)
{
    //    switch(GetStatusFlag())
    //    {
    ////    case 1:
    ////        AddStatusDep();
    ////        if(GetStatusDep() >= get_basic_zones())
    ////            SetStatusDep(0);
    ////        break;
    //    default:
    AddStatusComp();
    if(GetStatusComp() > MAX_COMP)
        SetStatusComp(1);
    //        break;
    //    }
    query_compstatus_ok();
}
static void query_hist_up(void)
{
    extern uint32 vHisCountDown;
    int32 tmp_num;
    history_st histinfo;
    if(--vHisCountDown < GetHistConter())
    {
        tmp_num =GetHistConter()-vHisCountDown-1;
        Debug("vHisCountDown:%d\n",vHisCountDown);
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


}

void query_Up(void)
{
    switch(GetCounter2())
    {
    case 1://系统查询
        query_system_up();
        break;
    case 2://部件状态
        query_compstatus_up();
        break;
    case 3://历史记录
        query_hist_up();
        break;
    default:break;
    }
}

static void test_sigStrlength_up(void)
{
    switch(GetIntenFlag())
    {
    case 1:
        AddIntenDep();
        if(GetIntenDep() >= get_basic_zones())
            SetIntenDep(0);
        break;
    default:
        AddIntenComp();
        if(GetIntenComp() > 99)
            SetIntenComp(0);
        break;
    }
    CompInten_Menu(GetIntenDep(),GetIntenComp(),0,0);
}

void test_Up(void)
{
    switch(GetCounter2())
    {
    case 1://
        break;
    case 2://
        test_sigStrlength_up();
        break;
    case 3://
        break;
    default:break;
    }
}
