/*
;*********************************************************************************************************
;*                                                
;*                            对象: tasklist
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : tasklist.c
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/
#define TaskList_C

#include  "include.h"
#include  "tasklist.h"
#include  "CTaskSure.h"
#include  "CGetGrap.h"
#include  "CTaskReturn.h"
#include  "CKeyCounter.h"
#include  "CTaskReturn.h"
#include  "CTaskUp.h"
#include  "CTaskDown.h"
#include  "CComHandle.h"
#include  "CFlashParam.h"
#include  "CComPara.h"


static void menu_setup_localaddr_tab(void)
{
    if(get_entry_localaddr_flag()){
        AddLocalParaSel();
        if(GetLocalParaSel() > 3)
            SetLocalParaSel(1);
        check_localaddr();
        if(local_addr_value() != get_basic_localaddr())
            Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                       Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVETIPS);
        else
            Local_Menu(GetBaseAddr(0),GetBaseAddr(1),GetBaseAddr(2),Get_zone_bit(0),
                       Get_zone_bit(1),Get_zone_bit(2),GetLocalParaSel(),MENU_SAVE_NONE);

    }
}
static void menu_comp_reg_tab(void)
{
    //    AddCompRegParaSel();
    //    if(GetCompRegParaSel() > 2)
    SetCompRegParaSel(2);
    CompReg_menu(GetCompRegDep(),GetCompRegNum(),0,GetCompRegAddr(),GetCompRegParaSel(),0);

}
static void menu_setup_comp_tab(void)
{
    AddComSet_seltab();
    if(GetComSet_seltab() > 3)
        SetComSet_seltab(2);
    CompSet_Menu(GetCompSetDep(),GetCompSetNum(),GetComSetSelSet(),GetComSet_seltab(),0);

}
static void back_task_setup_datetime(void)
{
    AddSelTime();
    if(GetSelTime() > 6)
        SetSelTime(1);

    DateMod_Menu(GetYear(),GetMonth(),GetDay(),GetHour(),GetMintue(),GetSecond(),GetSelTime(),0);

}
static void back_task_save(void)
{
    AddAnnSel();
    if(GetAnnSel() > 2)
        SetAnnSel(1);
    ClearScreen(0);
    Annotate_Menu(GetAnnDep(),GetAnnCompNum(),GetAnnSel());
}
static void back_task_comp_state(void)
{
    //    AddStatusFlag();
    //    if(GetStatusFlag() > 2)
    SetStatusFlag(1);
    ClearScreen(0);
    CompStat_Menu(GetStatusDep(),GetStatusComp(),0,0,0,GetStatusFlag());
}

//tab键处理
void Back_Task(void)
{
    if((GetCounter1() == 1)&&(GetCounter2()== 1))//本机设置
    {
        menu_setup_localaddr_tab();
    }
    else 	if((GetCounter1() == 1)&&(GetCounter2()== 2))
    {//部件注册中对tab对光标的影响
        menu_comp_reg_tab();
    }
    else 	if((GetCounter1() == 1)&&(GetCounter2()== 3))
    {
        menu_setup_comp_tab();
    }
    else 	if((GetCounter1() == 1)&&(GetCounter2()== 4))
    {
        back_task_setup_datetime();
    }
    else 	if((GetCounter1() == 1)&&(GetCounter2()== 5))
    {
        back_task_save();
    }
    else 	if((GetCounter1() == 2)&&(GetCounter2()== 1))
    {

    }
    else 	if((GetCounter1() == 2)&&(GetCounter2()== 2))
    {
        back_task_comp_state();

    }
    else 	if((GetCounter1() == 2)&&(GetCounter2()== 3))
    {

    }
    else 	if((GetCounter1() == 3)&&(GetCounter2()== 1))
    {

    }
    else 	if((GetCounter1() == 3)&&(GetCounter2()== 2))
    {
        AddIntenFlag();
        if(GetIntenFlag() > 2)
            SetIntenFlag(1);
    }
}
void Up_Task(void)
{
    switch(GetGrapCount())//层次
    {
    case 1:
        if(GetCounter1() > 1)
            SubCounter1();
        else
            SetCounter1(6);
        GetMainGrap(GetCounter1());
        break;
    case 2:
        Level2_Up();
        break;
    case 3:
        Level3_Up();
        break;
    default:break;
    }

}
void Down_Task(void)
{
    switch(GetGrapCount())//层次
    {
    case 1:
        AddCounter1();
        if(GetCounter1() > 6)
            SetCounter1(1);
        GetMainGrap(GetCounter1());
        break;
    case 2:
        Level2_Down();
        break;
    case 3:
        Level3_Down();
        break;
    case 4:
        Level4_Down();
        break;
    default:break;
    }


}
void Sure_Task(void)//确认键处理
{
    switch(GetGrapCount())//层次
    {
    case 1://第一层
        SetGrapCount(2);
        CLevel1_Sure(GetCounter1());
        break;
    case 2://第二层
        SetGrapCount(3);
        if(GetCounter1()==1)
        {//本机设置部件注册
            setup_Sure(GetCounter2());

        }
        else if(GetCounter1()==2)
        {
            query_Sure(GetCounter2());
        }
        else if(GetCounter1()==3)
        {
            test_Sure(GetCounter2());
        }
        else if(GetCounter1()==7)
        {
            CLevel27_Sure();
        }

        break;
    case 3://第三层
        SetGrapCount(3);
        CLevel3_Sure(GetCounter2());
        break;
        //		case 4:
        //			//AddGrapCount();
        //			SetGrapCount(4);
        //		  //CLevel4_Sure(vCounter[1]);
        //			CLevel4_Sure(GetCounter2());
        //			break;
    default:break;
    }

}
void Return_Task(void)
{
    switch(GetGrapCount())
    {
    case 1:
        clr_entry_localaddr_flag();
        //SubMenuFlag();
        // 		SetPasswordFlag(1);
        SubGrapCount();
        SetCounter1(1);
        //to alarm menu if have alarm,else to main
        if(GetDisplay_alarm_flag())
        {
            SetMenuFlag(MENU_FIREALARM);
            ClearScreen(0);
        }
        else
            SetMenuFlag(MENU_MAIN);
        break;
    case 2:
        SubGrapCount();
        CLevel1_Return();
        break;
    case 3:
        //SubGrapCount();
        SetGrapCount(2);
        if(GetCounter1()==1)
        {
            CLevel21_Return();
        }
        else if(GetCounter1()==2)
        {
            CLevel22_Return();
        }
        else if(GetCounter1()==3)
        {
            CLevel23_Return();
        }
        break;
    case 4:
        SubGrapCount();
        CLevel3_Return();
        break;
    default:
        break;
    }
    if(GetGrapCount()==0)
    {
        SetGrapCount(1);
    }

}
void Silence_Task(void)
{
    BEEPOff();
}





