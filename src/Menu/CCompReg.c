/*
;*********************************************************************************************************
;*                                                
;*                            ����: CCompReg
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompReg.c
;* By   : ������
;* ʱ�� : 2013-06-27
;*********************************************************************************************************
;*/
#include  "Config.h"
#include  "CCompReg.h"
#include "lcd.h"
#include  "include.h"

static void menu_reging(void)
{
    uint8 hz[]="����ע��";
    DisplayJBHZK(1,4,48,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(2,4,0,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(2,4,16,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,4,32,((hz[6]<<8)+hz[7]));
}
static void menu_invalid_comp(void)
{
    uint8 hz[]="�Ƿ�����";
    DisplayJBHZK(1,4,48,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(2,4,0,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(2,4,16,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,4,32,((hz[6]<<8)+hz[7]));
}
void menu_compaddr(uint8 line)
{
    uint8 hz[]="������ַ";
    DisplayJBHZK(1,line,0,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,6));
    Displaynumber(2,line,0,0x0A);
}

void menu_compstatus(void)
{
    //    uint8 hz[]="����״̬";
    //    uint8 line =0;
    //    uint8 offset =16;
    //    DisplayJBHZK(1,line,0+offset,HZ_SHOW(hz,0));
    //    DisplayJBHZK(1,line,16+offset,HZ_SHOW(hz,2));
    //    DisplayJBHZK(1,line,32+offset,HZ_SHOW(hz,4));
    //    DisplayJBHZK(2,line,0,HZ_SHOW(hz,6));
}
void menu_comptype(void)
{
    uint8 hz[]="����";
    uint8 line =2;
    uint8 offset =0;
    DisplayJBHZK(1,line,0+offset,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16+offset,HZ_SHOW(hz,2));
    Displaynumber(1,line,32,0x0A);
}
static void menu_overciraddr(void)
{
    uint8 hz[]="����·��Χ";
    uint8 line =4;
    //    uint8 offset =0;
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
    DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,48,HZ_SHOW(hz,8));

}
static void menu_compreged(void)
{
    uint8 hz[]="������ע��";
    uint8 line =4;
    //    uint8 offset =0;
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
    DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,48,HZ_SHOW(hz,8));

}
// static void menu_devreged(void)
// {
//     uint8 hz[]="�豸��ע��";
//     uint8 line =4;
//     //    uint8 offset =0;
//     DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
//     DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
//     DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
//     DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));
//     DisplayJBHZK(2,line,48,HZ_SHOW(hz,8));

// }
static void menu_overcompnums(void)
{
    uint8 hz[]="�����ѳ���";
    uint8 line =4;
    //    uint8 offset =0;
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
    DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,48,HZ_SHOW(hz,8));

}
static void menu_regedsucc(void)
{
    uint8 hz[]="ע��ɹ�";
    uint8 line =4;
    //    uint8 offset =0;
    DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
    DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
    DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
    DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));

}
static void menu_compreg(uint8 flag)
{
    uint8 hz[]="����ע��";
    uint8 line =4;
    //    uint8 offset =0;
    if(flag)
    {
        DisplayJBHZKBlack(1,line,48,HZ_SHOW(hz,0));
        DisplayJBHZKBlack(2,line,0,HZ_SHOW(hz,2));
        DisplayJBHZKBlack(2,line,16,HZ_SHOW(hz,4));
        DisplayJBHZKBlack(2,line,32,HZ_SHOW(hz,6));

    }else{
        DisplayJBHZK(1,line,48,HZ_SHOW(hz,0));
        DisplayJBHZK(2,line,0,HZ_SHOW(hz,2));
        DisplayJBHZK(2,line,16,HZ_SHOW(hz,4));
        DisplayJBHZK(2,line,32,HZ_SHOW(hz,6));
    }

}

static void menu_compreg_tips(void)
{
    uint8 hz[]="�밴ȷ�ϼ�ע��";
    uint8 line =6;
    uint8 offset =0;
    DisplayJBHZK(1,line,0+offset,HZ_SHOW(hz,0));
    DisplayJBHZK(1,line,16+offset,HZ_SHOW(hz,2));
    DisplayJBHZK(1,line,32+offset,HZ_SHOW(hz,4));
    DisplayJBHZK(1,line,48+offset,HZ_SHOW(hz,6));
    DisplayJBHZK(2,line,0+offset,HZ_SHOW(hz,8));
    DisplayJBHZK(2,line,16+offset,HZ_SHOW(hz,10));
    DisplayJBHZK(2,line,32+offset,HZ_SHOW(hz,12));

}
//tm2-ע���ַ
void CompReg_menu(uint16 department,uint16 tmp,uint8 regf,uint8 tm2,uint8 rflag,uint8 sureflag)
{
    uint8 hz[]="����ע�������ַ״̬�ɹ����豸����·��Χ�ѳ���";
    //    Debug("department:%d\n",department);

    department = department;
    ClearScreen(0);

//    Debug("select:%d\n",rflag);

    if(rflag==2)
    {
        //������ַ��(50)
        DisplaynumberBlack(2,2,8,(tmp/10));
        DisplaynumberBlack(2,2,16,(tmp%10));

    }

    //����ע�ᡪ������
    DisplayJBHZK(1,0,16,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,32,((hz[2]<<8)+hz[3]));
    DisplayJBHZK(1,0,48,((hz[4]<<8)+hz[5]));
    DisplayJBHZK(2,0,0,((hz[6]<<8)+hz[7]));

    //������ַ
    menu_compaddr(2);

    //״̬
    DisplayJBHZK(1,4,0,((hz[16]<<8)+hz[17]));
    DisplayJBHZK(1,4,16,((hz[18]<<8)+hz[19]));
    Displaynumber(1,4,32,0x0A);

    if((0==regf)&&sureflag)
    {

    }
    else if(REG_REGING == regf)
    {
    }
    else{
        menu_compreg_tips();
    }

    if(regf==0)
    {
        if(sureflag)
        {
            menu_compreg(1);
        }
        else
        {
            menu_compreg(0);
        }
        //����ע��

    }
    else if(regf == REG_SUC)
    {
        //ע��ɹ�
        menu_regedsucc();
    }
    //    else if(regf== REGD_DEV)//�豸��ע��
    //    {
    //        menu_devreged();
    //    }
    else if(REGD_COMP == regf || REGD_DEV == regf)//������ע��
    {
        menu_compreged();
    }
    else if(REG_CIR_OVERFLOW ==regf)//����·��Χ
    {
        menu_overciraddr();
    }
    else if(REG_COMP_OVERFLOW ==regf)//�����ѳ���
    {
        menu_overcompnums();
    }
    else if(REG_REGING == regf)//ע����
    {
        menu_reging();
    }
    else if(REG_INVALID_COMP == regf)
    {
        menu_invalid_comp();
    }
    // 	//��Դ
    //
    // 	Display(1,4,0,1263);
    // 	Display(1,4,16,2244);
    // 	Displaynumber(1,4,32,0x0A);
    // 	if(tm2==0)
    // 	{
    // 		//����
    // 		Display(1,4,48,1613);
    // 		Display(2,4,0,414);
    // 	}
    // 	else if(tm2==1)
    // 	{
    // 		//�м���
    // 		Display(1,4,48,105);
    // 		Display(2,4,0,1701);
    // 		Display(2,4,16,2433);
    // 	}

}



