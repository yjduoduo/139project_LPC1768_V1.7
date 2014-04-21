/*
;*********************************************************************************************************
;*                                                
;*                            对象: CKeyCounter
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CGetGrap.c
;* By   : 尹海星
;* 时间 : 2013-06-27
;*********************************************************************************************************
;*/

#include  "include.h"
#include  "CGetGrap.h"
#include  "CKeyCounter.h"

void GetMainGrap(uint8 tmp)
{
    switch(tmp)
    {
    case 1:

        Main_Menu(1);
        break;
    case 2:

        Main_Menu(2);
        break;
    case 3:

        Main_Menu(3);
        break;
    case 4:

        Main_Menu(4);
        break;
    case 5:

        Main_Menu(5);
        break;
    case 6:

        Main_Menu(6);
        break;
    case 7:

        Main_Menu(7);
        break;
    default:break;
    }

}
void GetSetGrap(uint8 tmp)
{
    switch(tmp)
    {
    case 1://本机设置

        Set_Menu(1);
//        NVIC_DisableIRQ(EINT3_IRQn);
        break;
    case 2://部件注册

        Set_Menu(2);
        break;
    case 3://部件设置

        Set_Menu(3);
        break;
    case 4://时间/日期

        Set_Menu(4);
        break;
        //		case 5:
        //
        //			Set_Menu(5);
        //			break;
    default:break;
    }
    // 	vCounter = 1;
}
void GetCheckGrap(uint8 tmp)
{
    switch(tmp)
    {
    case 1://系统查询
        Check_Menu(1);
        break;
    case 2://部件状态
        Check_Menu(2);
        break;
    case 3://历史记录
        Check_Menu(3);
        break;
    default:break;
    }
}
void GetTestGrap(uint8 tmp)
{
    switch(tmp)
    {
    case 1://自检

        Test_Menu(1);
        break;
    case 2://部件信号强度

        Test_Menu(2);
        break;
    default:break;
    }
}


