/*
;*********************************************************************************************************
;*                                                
;*                            ����: runfunction
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : runfunction.c
;* By   : ������
;* ʱ�� : 2013-06-8
;*********************************************************************************************************
;*/
#define _VAR_RUNFUNCTION
#include  "include.h"
#include  "key.h"
#include  "runfunction.h"
#include  "tasklist.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"
#include  "CAddressCount.h"
#include  "CComPara.h"
#include "CLED.h"
#include  "CTime.h"
#include  "CModelFault.h"
#include  "CSendTo195.h"
#include  "CFlashParam.h"
#include "SysCtrl.h"
#include "CTimeDef.h"
#include "CTaskSure.h"

extern volatile uint32 match_counter1;
uint8 vCounterLed=0;
uint8 HeartTaskFlag=1;
uint8 csflag=0;
uint8 TickCounter=0;
//uint8 ShuaFlag=0;//ˢ�±�־
uint8 vHeartLostFlag=0;
uint8 vMaskScreen=0;//������Ļ
uint8 alarm_display_counter=1;
//uint32 faultTick=0;

//void CSaveHist(void)
//{
//    if(GetHistFlag())
//    {
//        check_lp_running();
//        M25P80_Section_Erase(0x60000);
//        // 		SSP1_Write_1Byte(0x60000,(GetHistConter()>>8));
//        M25P80_Write_1Byte(0x60000,GetHistConter());
//        M25P80_Write_1Byte(0x60001,GetPageConter());
//        if(GetHistConter()==21)
//            SetHistConter(0);
//        SendHistToFlash();
//    }

//}
//��ʾ��ҳ
void show_head_menu(void)
{
    if(GetMenuFlag() == MENU_MAIN)//��ʼ������
    {
        if(/*GetE1_flag()&&*/GetPasswordFlag())//�ж�1��־������,ˢ�½�����ʱ��
        {
            ClrE1_flag();
            ClearScreen(0);
            Start_Menu();

        }
    }
}
#define UPKey_Flag 0
#define DownKey_Flag 1
//keyflag:0-���ϰ�����1-���°���
void gethistory_show_pos(uint8 keyflag,uint16 *curpos)
{
    int i;
    uint16 his_nums=GetHistConter();//history total nums
    if(!keyflag){//���ϰ���
        for(i=*curpos;i<his_nums;i++)//�����µļ�¼��ѯ
            if(gethistory_isfirealarm(i))
            {
                *curpos=i;
                break;
            }
        Debug("up key! curpos:%d\n",*curpos);
    }

    if(keyflag){//���°���
        for(i=*curpos;i>=0;i--)//��ɵ���ʷ��¼��ѯ
            if(gethistory_isfirealarm(i))
            {
                *curpos=i;
                break;
            }
        Debug("down key! curpos:%d\n",*curpos);
    }
}
uint16 his_pos;//save pos for menu show at alarm
void set_history_alarm_pos(uint16 pos)
{
    his_pos=pos;
}
//void get_history_alarm_pos(void)
//{
//    return his_pos;
//}
//����ҳ��


alarminfo menu_alarm_info;
void set_menu_alarm_info(alarminfo alarm_info)
{
    //    menu_alarm_info.ciraddr  =alarm_info.ciraddr;
    //    menu_alarm_info.part     = alarm_info.part;
    //    menu_alarm_info.type     = alarm_info.type;
    //    menu_alarm_info.attr     = alarm_info.attr;
    //    menu_alarm_info.vAnnRow  = alarm_info.vAnnRow;
    menu_alarm_info=alarm_info;
    Debug("------>>>>>>>set menu alarm info\n");
    Debug("part:  %d\n",menu_alarm_info.part);
    Debug("ciraddr:  %d\n",menu_alarm_info.ciraddr);
    Debug("type:  %d\n",menu_alarm_info.type);
    Debug("attr:  %d\n",menu_alarm_info.attr);
    Debug("vAnnRow:  %d\n",menu_alarm_info.vAnnRow);
}
alarminfo* get_menu_alarm_info(void)
{
    return &menu_alarm_info;
}
//��¼��������
uint8 record_alarmnum=0; //��¼������Ϣ�����λ��
static uint8 record_showalarm=0; //��¼���°�����ʾ��λ��

uint8 alarmpart[MAX_LOOP]={0,};//���б������partֵ
uint8 alarm_newest_pos =0;
void set_alarm_newest_pos(uint8 row)
{
    alarm_newest_pos = row;
}
uint8 get_alarm_newest_pos(void)
{
    return alarm_newest_pos;
}

uint8 get_alarmpart(uint8 row)
{
    return alarmpart[row-1];
}

//�Լӱ�����
void add_alarmnums(uint8 part)
{
    alarmpart[record_alarmnum] = part;
    record_alarmnum++;
    if(record_alarmnum > MAX_COMP)
    {
        Debug("alarm nums err!\n");
    }
}
uint8 get_record_alarmnum(void)
{
    return record_alarmnum;
}
/*********************************************
  *********��ʾ��λ��**************************
  ******************************************/
void set_record_showalarm(uint8 pos)
{
    record_showalarm = pos;
}
uint8 get_record_showalarm(void)
{
    return record_showalarm;
}
//ͨ�����°���������
void sub_record_showalarm(void)
{
    record_showalarm--;
}
void add_record_showalarm(void)
{
    record_showalarm++;
}
//��ȡ��ǰ�洢��partֵ
uint8 get_cur_alarmpart(void)
{
    return alarmpart[get_record_showalarm()];
}

//��ȡ���µı�����
uint8 get_alarm_newest_nums()
{
    uint32 i=0;
    uint8 num=0;
    for(i=COMP_START;i<= MAX_COMP;i++)
    {
        if(get_alarmpart(i) != 0)
        {
            set_alarm_newest_pos(i);
            num++;
        }
    }
    return num;
}

void menu_alarm_fire(void)
{
    //��ȡ���µı�������
    static uint8 current_alarmpart = INITVAL;
    //     uint8 item = 0;
    //     alarminfo showinfo;//���°�����ʾ��Ϣ

    //    if(KEY_Up == Get_KeyValue())//�ϰ���
    //    {
    //        Debug("up key!!_menu_alarm_fire\n");
    //        if(!get_alarm_newest_nums())//������Ϊ0
    //        {
    //            return;
    //        }

    //        item = get_cur_alarmpart();
    //        Debug("up item:%d\n",item);
    //        if(item <=get_record_alarmnum())
    //        {
    //            get_alarm_allinfo(item,&showinfo);
    //            Alarm_Menu(get_alarm_first_part(),
    //                       showinfo.part,
    //                       showinfo.ciraddr,
    //                       get_firealarm_nums(),
    //                       showinfo.type,
    //                       &showinfo.dateyear);//time

    //            add_record_showalarm();
    //        }
    //        return;

    //    }
    //    else if(KEY_Down == Get_KeyValue())//�°���
    //    {
    //        Debug("down key!!_menu_alarm_fire\n");

    //        item = get_cur_alarmpart();
    //        Debug("down item:%d\n",item);
    //        if(item <=get_record_alarmnum())
    //        {
    //            get_alarm_allinfo(item,&showinfo);
    //            Alarm_Menu(get_alarm_first_part(),
    //                       showinfo.part,
    //                       showinfo.ciraddr,
    //                       get_firealarm_nums(),
    //                       showinfo.type,
    //                       &showinfo.dateyear);//time
    //            if(get_record_showalarm()>0)
    //                sub_record_showalarm();
    //        }

    //        return;

    //    }
    //    else
    //    {



    if(current_alarmpart != get_menu_alarm_info()->part)
    {

        Debug("fire alarm!!!\n");
        Debug("current alarm part:%d\n",current_alarmpart);
        Debug("alarm info part   :%d\n",get_menu_alarm_info()->part);


        //���Լ��Ҵ�ʱ
        if(GetSpeaker_Flag()&&!GetZjFlag())
            PWM1_Start();
        Alarm_Menu(get_alarm_first_part(),
                   get_menu_alarm_info()->part,
                   get_menu_alarm_info()->ciraddr,
                   get_firealarm_nums(),
                   get_menu_alarm_info()->type,
                   &(get_menu_alarm_info()->dateyear));//time

        //��¼�˴ε�����
        current_alarmpart = get_menu_alarm_info()->part;

        set_record_showalarm(get_record_alarmnum());

        add_alarmnums(get_menu_alarm_info()->part);
    }
    else
    {
        Alarm_Menu(get_alarm_first_part(),
                   get_menu_alarm_info()->part,
                   get_menu_alarm_info()->ciraddr,
                   get_firealarm_nums(),
                   get_menu_alarm_info()->type,
                   &(get_menu_alarm_info()->dateyear));//time
    }




    //    }


}
//void menu_alarm_batlow(void)
//{
//    Battery_Low(Getdisplay_alarm(0),
//                Getdisplay_alarm(1),
//                Getdisplay_alarm(3),
//                Getdisplay_alarm(4),
//                Getalarmtime());
//}
void menu_alarm_fault(void)
{
    ClearScreen(0);
    //        ClearScreen(0);
    //        Breakdown(alarm_info->attr,
    //                  alarm_info->part,
    //                  get_faultalarm_nums(),alarm_info->type,&alarm_info->dateyear);


    Breakdown(get_menu_alarm_info()->attr,
              get_menu_alarm_info()->part,
              get_faultalarm_nums(),
              get_menu_alarm_info()->type,
              &get_menu_alarm_info()->dateyear);
}
#define Time100ms (100)
#define Time3s    (3000/Time100ms)

//after 30s return to alarm page if have alarm info,so reset will clear
void have_alarm_backafter30s()
{
    static uint8 time_alarm_backct=Time3s;
    if(GetDisplay_alarm_flag() == PAGE_AT_FIRE
            ||GetDisplay_alarm_flag() == PAGE_AT_BATLOW
            ||GetDisplay_alarm_flag() == PAGE_AT_FAULT)
        time_alarm_backct--;
    else
        return;
    if(0 == time_alarm_backct){
        SetMenuFlag(MENU_FIREALARM);//return to alarm info
        time_alarm_backct = Time3s;
    }
}

void DisplayKeyMenu(void)//������
{
    uint8 hz[]="����������";//hz������
    if(GetMenuFlag() == MENU_MAIN)//��ʼ������
    {
        //        show_head_menu();//��ʾ��ҳ
        if(Get_KeyValue() == KEY_Sure)//ȷ����
        {
            SetPasswordFlag(0);//1��ʾ��Ҫ����
            ClearScreen(0);
            //����������
            DisplayJBHZK(1,0,16,((hz[0]<<8)+hz[1]));
            DisplayJBHZK(1,0,32,((hz[2]<<8)+hz[3]));
            DisplayJBHZK(1,0,48,((hz[4]<<8)+hz[5]));
            DisplayJBHZK(2,0,0,((hz[6]<<8)+hz[7]));
            DisplayJBHZK(2,0,16,((hz[8]<<8)+hz[9]));
        }
        if(GetBackValue()==KEY_Back)//��ֵ������1��3��������Ĺ���
        {
            Displaynumber(1,4,48,0xd);/*  *��  */
        }
        else if(GetBackValue()==2)
        {
            Displaynumber(1,4,56,0xd);
        }
        else if(GetBackValue()==3)
        {
            Displaynumber(2,4,0,0xd);
            SetMenuFlag(MENU_RUN);//�˵�Ϊ2ȥ��ѭ��
            ClrBackValue();
            SetPasswordFlag(1);//���������־��1Ϊ�������룬0����

            Main_Menu(1);
            SetGrapCount(1);
        }

    }
    else if(GetMenuFlag() == MENU_FIREALARM)//��ʾ��������
    {
        //������°������������Ϣ
        if(GetDisplay_alarm_flag() == PAGE_AT_FIRE )
            menu_alarm_fire();
        else if(GetDisplay_alarm_flag() == PAGE_AT_FAULT)
            menu_alarm_fault();
        if(Get_KeyValue() == KEY_Return)
        {
            Debug("set MENU_RUN at MENU_FIREALARM\n");
            SetMenuFlag(MENU_RUN);
            Main_Menu(1);
        }


    }
    else if(GetMenuFlag() == MENU_RUN)
    {
        //        have_alarm_backafter30s();
        Systemp_Task();//������
    }
    else
    {
        if(Get_KeyValue() == KEY_Return)//�����ؼ�
        {

            if(GetDisplay_alarm_flag() == PAGE_AT_FIRE )
            {
                BEEPOff();
                SetMenuFlag(MENU_FIREALARM);
                SetPasswordFlag(1);
//                Main_Menu(1);
            }

//            SetMenuFlag(MENU_MAIN);
//            SetPasswordFlag(1);
//            SetCheckInfoFlag(0,0);
//            SetCheckInfoFlag(1,0);
//            SetCheckInfoFlag(2,0);
            SetAlarmFlag(0,0);
//            ShuaFlag=0;
            SetReleaseFlag(0);
            Led_Silence_Off();
        }
    }
    if(Get_KeyValue() == KEY_Silence)//����
    {
        BEEPOff();
        SetAlarmFlag(0,0);
        if(GetDisplay_alarm_flag())
        Led_Silence_On();
        PWM1_Stop();
    }

}
void Systemp_Task(void)//����������
{
    uint16 temp = 0;

    temp = Get_KeyValue();

    switch(temp)
    {
    case 1: //���˼�����
        Back_Task();
        break;
    case 2: //���ϼ�����
        Up_Task();
        break;
    case 3: //���¼�����
        Down_Task();
        break;
    case 4: //ȷ�ϼ�����
        Sure_Task();
        break;
    case 5: //���ؼ�����
        Return_Task();
        break;
    case 6: //����������
        Silence_Task();
        //        SetAlarmFlag(0,0);
        break;
    default:
        break;

    }
}


//set
void set_time_sendheart(uint8 n)
{
    time_sendheart = n;
}
//add
void add_time_sendheart()
{
    time_sendheart++;
}
//get
uint8 get_time_sendheart(void)
{
    return time_sendheart;
}
//clr
void clr_time_sendheart(void)
{
    time_sendheart=0;
}


#if 1
//���Լ�������������⴮��1�ϵ�����ģ���Ƿ���������
void SendHeart(void)//��������
{
    if(get_time_sendheart() >= TIME_THR)
    {
        clr_time_sendheart();
        UartBindSend(CMD_139W,2);	   //������������
        UartBindSend(CMD_139W,2);
        SetHeartFaultFlag();
    }
    else
    {
        add_time_sendheart();
        if(GetHeartFaultFlag()==1)//������ cs0=0
        {
            vHeartLostFlag++;
            UartBindSend(CMD_139W,2);	   //������������
            UartBindSend(CMD_139W,2);
            Debug("!err:heart lost:%d\n",vHeartLostFlag);
        }
        else
        {//�����������������,���ص���ҳ��
            vHeartLostFlag=0;
            //�����ʾ����
            if(GetMenuFlag() == MENU_WIRELESS_FAULT)
            {
                SetMenuFlag(MENU_MAIN);
                SetAlarmFlag(POS_ALARM_BIT,0);
                Led_Fault_Off();//turn off fault and wireless led
                Led_Wireless_Off();
            }

        }

        if(vHeartLostFlag >= HEARTLOSTTIMES)
        {
            Debug("!err: wireless fault\n");

            OnLCD();
            ClrHeartFaultFlag();
            vHeartLostFlag=0;

            SetMenuFlag(MENU_WIRELESS_FAULT);
            Led_Fault_On();//���ϵ�
            Led_Wireless_On();//ͨѶ��

            ClearScreen(0);
            menu_wirelessmod_fault();
            if(GetAlarmFlag(POS_ALARM_BIT) != ALARM_FIRE)
                SetAlarmFlag(POS_ALARM_BIT,ALARM_FAULT);
        }
    }
    //    if(csflag)
    //    {
    //        if(((GetHeartTick()-faultTick)>5)&&((GetHeartTick()-faultTick)<10))
    //        {
    //            csflag=0;
    //            //cs0=1;
    //            CS0Setup(1);
    //        }

    //    }
    // 	if(TickCounter>=10)
    // 	{
    // 		Uart0Com(0x0b,0x00,0);
    // 	}
}
#else
//void SendHeart(void)//��������
//{
//    if(GetHeartTick() >= TIME_3M)
//    {
//        SetHeartTick(0);
//        UartBindSend(CMD_139W,2);	   //������������
//        UartBindSend(CMD_139W,2);
//        SetHeartFaultFlag();
//    }
//    else
//    {
//        if(GetHeartTick()<TIME_1M)
//        {
//            if(GetHeartFaultFlag()==1)//������ cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //������������
//                UartBindSend(CMD_139W,2);
//                Debug("!err:heart lost:%d\n",vHeartLostFlag);
//            }
//            else
//                vHeartLostFlag=0;
//        }
//        else if((GetHeartTick()>TIME_1M)&&(GetHeartTick()< TIME_2M))//5s~6s
//        {
//            if(GetHeartFaultFlag()==1)//������ cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //������������
//                UartBindSend(CMD_139W,2);
//                Debug("!err:heart lost:%d\n",vHeartLostFlag);
//            }
//            else
//                vHeartLostFlag=0;
//        }
//        else if((GetHeartTick()>TIME_2M)&&(GetHeartTick()< TIME_3M))//8s&9s
//        {
//            if(GetHeartFaultFlag()==1)//������ cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //������������
//                UartBindSend(CMD_139W,2);
//                Debug("!err:heart lost:%d\n",vHeartLostFlag);
//            }
//            else
//                vHeartLostFlag=0;
//        }
//        if(vHeartLostFlag==3)
//        {
//            Debug("!err:heart lost:%d\n",vHeartLostFlag);
//              ClrHeartFaultFlag();
//            vHeartLostFlag=0;
//            SetMenuFlag(3);
//            ClearScreen(0);
//            CModFault();
//            csflag=1;
//            faultTick=GetHeartTick();
//            CS0Setup(0);
//            TickCounter++;
//            if(GetAlarmFlag(0) !=1)
//                SetAlarmFlag(0,2);
//        }
//    }
//    if(csflag)
//    {
//        if(((GetHeartTick()-faultTick)>5)&&((GetHeartTick()-faultTick)<10))
//        {
//            csflag=0;
//            //cs0=1;
//            CS0Setup(1);
//        }

//    }
//    // 	if(TickCounter>=10)
//    // 	{
//    // 		Uart0Com(0x0b,0x00,0);
//    // 	}
//}

#endif
//void BreezeAlarm(void)//
//{
//    if(GetAlarmFlag(0)==1)
//    {
//        //	CSpeaker_Alarm(1);
//        Breeze_Controll(10,5);
//    }
//    else if(GetAlarmFlag(0)==2)
//    {
//        CSpeaker_Alarm(2);
//    }
//    else
//        BEEPOff();
//}

void CS0Setup(uint8 tmp)
{
    switch(tmp)
    {
    case 0:
        FIO2CLR |= (1<<2);
        break;
    case 1:
        FIO2SET |= (1<<2);
        break;
    default:break;
    }
}
//����λ���ظ���������״̬������0
//uart0 ������Ϣ������ģ��
void inqury_state__byuart0(void)
{
    if(GetFlag_195())//&&GetE3_flag())//�в�ѯ�����־
    {
        if((GetAlarmFlag(POS_INQUIRY_BIT)==ALARM_FIRE))
        {
            /*
�������ͣ�
1����
2���������ϻָ�
��������
*/
            //            //���ͻ�
            Query_ByUart0(0x0A,0x00,GetAlarmFlag(POS_INQUIRY_BIT));
        }
        else if((GetAlarmFlag(POS_INQUIRY_BIT) == ALARM_FAULT)||
                GetAlarmFlag(POS_INQUIRY_BIT) == ALARM_BAT_LOW)
        {
            Query_ByUart0(0x0B,0x00,GetAlarmFlag(POS_INQUIRY_BIT));//��λ����
        }
        else//normal state
            Query_ByUart0(0x13,0x00,0x00);
        SetFlag_195(0);

    }
}

//void DisplayAlarmInfo(void)
//{
//    PCF8563_DATE TimeDate;
//    // 	uint8 i;
//    if(CGetAlarmFlag(0)==ALARM_FIRE)
//    {
//        TimeDate.year=GetAlarmInfo(0,6)+2000;
//        TimeDate.month=GetAlarmInfo(0,7);
//        TimeDate.day=GetAlarmInfo(0,8);
//        TimeDate.hour=GetAlarmInfo(0,9);
//        TimeDate.minute=GetAlarmInfo(0,10);
//        TimeDate.second=GetAlarmInfo(0,11);
//        if(ShuaFlag==0)
//        {
//            ShuaFlag++;
//            ClearScreen(0);
//        }

//        Alarm_Menu(GetAlarmInfo(0,0),GetAlarmInfo(0,1),GetAlarmInfo(0,2),1,GetAlarmInfo(0,4),TimeDate);
//    }
//    else if(GetAlarmInfoFlag()>0)
//    {
//        TimeDate.year=GetAlarmInfo(GetAlarmInfoFlag(),6)+2000;
//        TimeDate.month=GetAlarmInfo(GetAlarmInfoFlag(),7);
//        TimeDate.day=GetAlarmInfo(GetAlarmInfoFlag(),8);
//        TimeDate.hour=GetAlarmInfo(GetAlarmInfoFlag(),9);
//        TimeDate.minute=GetAlarmInfo(GetAlarmInfoFlag(),10);
//        TimeDate.second=GetAlarmInfo(GetAlarmInfoFlag(),11);
//        if((GetAlarmInfo(GetAlarmInfoFlag(),12))==0x33)
//        {
//            ClearScreen(0);
//            Alarm_Menu(GetAlarmInfo(0,0),GetAlarmInfo(0,1),GetAlarmInfo(GetAlarmInfoFlag(),2),GetAlarmInfo(GetAlarmInfoFlag(),3),GetAlarmInfo(GetAlarmInfoFlag(),4),TimeDate);
//            // 			for(i=0;i<13;i++)
//            // 			{
//            // 				SetAlarmInfo(GetAlarmInfoFlag(),i,0xff);
//            // 			}
//        }
//        else if((GetAlarmInfo(GetAlarmInfoFlag(),12))==0x31)
//        {
//            ClearScreen(0);
//            Battery_Low(GetAlarmInfo(GetAlarmInfoFlag(),0),GetAlarmInfo(GetAlarmInfoFlag(),1),GetAlarmInfo(GetAlarmInfoFlag(),3),GetAlarmInfo(GetAlarmInfoFlag(),4),TimeDate);
//            // 			for(i=0;i<13;i++)
//            // 			{
//            // 				SetAlarmInfo(GetAlarmInfoFlag(),i,0xff);
//            // 			}
//        }
//        else if((GetAlarmInfo(GetAlarmInfoFlag(),12))==0x32)
//        {
//            ClearScreen(0);
//            Breakdown(GetAlarmInfo(GetAlarmInfoFlag(),0),GetAlarmInfo(GetAlarmInfoFlag(),1),GetAlarmInfo(GetAlarmInfoFlag(),3),GetAlarmInfo(GetAlarmInfoFlag(),4),TimeDate);
//            // 			for(i=0;i<13;i++)
//            // 			{
//            // 				SetAlarmInfo(GetAlarmInfoFlag(),i,0xff);
//            // 			}
//        }
//    }

//}
