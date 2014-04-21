/*
;*********************************************************************************************************
;*                                                
;*                            ����: setmenu
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : setmenu.c
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
#include  "Config.h"
#include  "setmenu.h"
#include "lcd.h"
#include  "include.h"

uint8 hz[]="�������ò���ע������ʱ��ע�ͱ���";
void set_menu_local_machine(void)
{
    Displaynumber(1,0,10,1);//display 1
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,48,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(2,0,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,16,((hz[6]<<8)+hz[7]));
}
void set_menu_component_reg(void)
{
    Displaynumber(1,2,10,2);//display 2
    Displaynumber(1,2,18,0x0A);
    DisplayJBHZK(1,2,32,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(1,2,48,((hz[10]<<8)+hz[11]));
    DisplayJBHZK(2,2,0,((hz[12]<<8)+hz[13]));
    DisplayJBHZK(2,2,16,((hz[14]<<8)+hz[15]));
}
void set_menu_component_setup(void)
{
    Displaynumber(1,4,10,3);//display 3
    Displaynumber(1,4,18,0x0A);
    DisplayJBHZK(1,4,32,((hz[8]<<8)+hz[9]));
    DisplayJBHZK(1,4,48,((hz[10]<<8)+hz[11]));
    DisplayJBHZK(2,4,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,4,16,((hz[6]<<8)+hz[7]));

}
void set_menu_datetime_setup(void)
{
    Displaynumber(1,6,10,4);//display 4
    Displaynumber(1,6,18,0x0A);//:
    DisplayJBHZK(1,6,32,((hz[16]<<8)+hz[17]));
    DisplayJBHZK(1,6,48,((hz[18]<<8)+hz[19]));
    Displaynumber(2,6,0,0x0b);
    DisplayJBHZK(2,6,8,((hz[20]<<8)+hz[21]));
    DisplayJBHZK(2,6,24,((hz[22]<<8)+hz[23]));
}
void set_menu_note(void)
{
    //ע��
    Displaynumber(1,0,10,5);//display 5
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,((hz[24]<<8)+hz[25]));
    DisplayJBHZK(1,0,48,((hz[26]<<8)+hz[27]));
}
void set_menu_save_all(void)
{
    Displaynumber(1,0,10,5);//display 2
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,((hz[28]<<8)+hz[29]));
    DisplayJBHZK(1,0,48,((hz[30]<<8)+hz[31]));
    DisplayJBHZK(2,0,0,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,16,((hz[6]<<8)+hz[7]));
}

// ѡ��ŵ��趨
void Set_Menu(uint8 tmp)
{  
    ClearScreen(0);
    switch(tmp)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        Display(1,(tmp-1)<<1,0,0);
        break;
//    case 5:
//        Display(1,0,0,0);
//        break;
    default:
        break;
    }
//    Debug("set_menu tmp:%d\n",tmp);
    if(tmp<5)
    {
        //��������
        set_menu_local_machine();
        //����ע��
        set_menu_component_reg();
        //��������
        set_menu_component_setup();
        //����/ʱ��
        set_menu_datetime_setup();
    }
//    else
//    {
//        //ע��
////        set_menu_note();

//        //��������
//        set_menu_save_all();
//    }


}
void CSaveInfo(void)
{ 

    uint8 hz[]="���";
    ClearScreen(0);
    //���
    DisplayJBHZK(1,2,48,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(2,2,0,((hz[2]<<8)+hz[3]));
    //�˳�
    // 	DisplayJBHZK(2,6,32,1382);
    // 	DisplayJBHZK(2,6,48,294);
}

void Set_Menu1(void)
{ 
    Display(1,0,0,0);
    //ע��
    Displaynumber(1,0,10,5);//display 5
    Displaynumber(1,0,18,0x0A);
    DisplayJBHZK(1,0,32,1028);
    DisplayJBHZK(1,0,48,2055);
}



