/*
;*********************************************************************************************************
;*                                                
;*                            对象: runfunction
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : runfunction.c
;* By   : 尹海星
;* 时间 : 2013-06-8
;*********************************************************************************************************
;*/


#define _VAR_RUNFUNCTION
#include  "runfunction.h"
#include  "include.h"
#include  "key.h"
#include  "tasklist.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"
// #include  "CAddressCount.h"
#include  "CComPara.h"
// #include "CLED.h"
// #include  "CTime.h"
#include  "CModelFault.h"
#include  "CSendTo195.h"
// #include  "CFlashParam.h"
#include "SysCtrl.h"
#include "CTimeDef.h"
#include "CTaskSure.h"


// #define UPKey_Flag (0)
// #define DownKey_Flag (1)
// #define Time100ms (100)
// #define Time3s    (3000/(Time100ms))



extern uint32 match_counter1;
// uint8 vCounterLed=0;
// uint8 HeartTaskFlag=1;
// uint8 csflag=0;
// uint8 TickCounter=0;
//uint8 ShuaFlag=0;//刷新标志
static uint8 vHeartLostFlag=0;
// uint8 vMaskScreen=0;//屏蔽屏幕
// uint8 alarm_display_counter=1;
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
//显示首页
void show_head_menu(void)
{
    if(GetMenuFlag() == MENU_MAIN)//初始化界面
    {
        if(/*GetE1_flag()&&*/GetPasswordFlag())//中断1标志和密码,刷新界面与时间
        {
            ClrE1_flag();
            ClearScreen(0);
            Start_Menu();

        }
    }
}

// //keyflag:0-向上按键，1-向下按键
// void gethistory_show_pos(uint8 keyflag,uint16 *curpos)
// {
//     int i;
//     uint16 his_nums=GetHistConter();//history total nums
//     if(!keyflag){//向上按键
//         for(i=*curpos;i<his_nums;i++)//向最新的记录查询
//             if(gethistory_isfirealarm(i))
//             {
//                 *curpos=i;
//                 break;
//             }
//         Debug("up key! curpos:%d\n",*curpos);
//     }

//     if(keyflag){//向下按键
//         for(i=*curpos;i>=0;i--)//向旧的历史记录查询
//             if(gethistory_isfirealarm(i))
//             {
//                 *curpos=i;
//                 break;
//             }
//         Debug("down key! curpos:%d\n",*curpos);
//     }
// }
// uint16 his_pos;//save pos for menu show at alarm
// void set_history_alarm_pos(uint16 pos)
// {
//     his_pos=pos;
// }
//void get_history_alarm_pos(void)
//{
//    return his_pos;
//}
//报警页面


static alarminfo menu_alarm_info;//火警界面变量
static alarminfo menu_faultalarm_info;//故障界面变量
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
static alarminfo* get_menu_alarm_info(void)
{
    return &menu_alarm_info;
}
void set_menu_faultalarm_info(alarminfo alarm_info)
{
    //    menu_alarm_info.ciraddr  =alarm_info.ciraddr;
    //    menu_alarm_info.part     = alarm_info.part;
    //    menu_alarm_info.type     = alarm_info.type;
    //    menu_alarm_info.attr     = alarm_info.attr;
    //    menu_alarm_info.vAnnRow  = alarm_info.vAnnRow;
    menu_faultalarm_info=alarm_info;
    Debug("------>>>>>>>set menu fault alarm info\n");
    Debug("part:  %d\n",menu_faultalarm_info.part);
    Debug("ciraddr:  %d\n",menu_faultalarm_info.ciraddr);
    Debug("type:  %d\n",menu_faultalarm_info.type);
    Debug("attr:  %d\n",menu_faultalarm_info.attr);
    Debug("vAnnRow:  %d\n",menu_faultalarm_info.vAnnRow);
}
static alarminfo* get_menu_faultalarm_info(void)
{
    return &menu_faultalarm_info;
}
//记录报警部件
static uint8 record_alarmnum=0; //记录保存信息的最大位置
static uint8 record_alarmnum_fault=0; //记录保存信息的最大位置
volatile static uint8 record_showalarm=0; //记录上下按键显示的位置
volatile static uint8 record_showalarm_fault=0; //记录上下按键显示的位置

static uint8 alarmpart[MAX_COMP+1]={0,};//此中保存的是part值
static uint8 alarmpart_fault[MAX_COMP+1]={0,};//此中保存的是part值
// uint8 alarm_newest_pos =0;
// static void set_alarm_newest_pos(uint8 row)
// {
//     alarm_newest_pos = row;
// }
// static uint8 get_alarm_newest_pos(void)
// {
//     return alarm_newest_pos;
// }

// static uint8 get_alarmpart(uint8 row)
// {
//     return alarmpart[row-1];
// }

//自加报警数
static void add_alarmnums(uint8 part)
{
    alarmpart[record_alarmnum] = part;
    record_alarmnum++;
    if(record_alarmnum > MAX_COMP)
    {
        Debug("alarm nums err!\n");
    }
}
//报警数目
static uint8 get_record_alarmnum(void)
{
    return record_alarmnum;
}

//自加报警数
static void add_alarmnums_fault(uint8 part)
{
    alarmpart_fault[record_alarmnum_fault] = part;
    record_alarmnum_fault++;
    if(record_alarmnum_fault > MAX_COMP)
    {
        Debug("alarm nums err!\n");
    }
}
//报警数目
static uint8 get_record_alarmnum_fault(void)
{
    return record_alarmnum_fault;
}


// /*********************************************
//   *********显示的位置**************************
//   ******************************************/
static void set_record_showalarm(uint8 pos)
{
    record_showalarm = pos;
}
static void set_record_showalarm_fault(uint8 pos)
{
    record_showalarm_fault = pos;
}



// static uint8 get_record_showalarm(void)
// {
//     return record_showalarm;
// }
// //通过上下按键来调用
// static void sub_record_showalarm(void)
// {
//     record_showalarm--;
// }
// static void add_record_showalarm(void)
// {
//     record_showalarm++;
// }
// //获取当前存储的part值
// static uint8 get_cur_alarmpart(void)
// {
//     return alarmpart[get_record_showalarm()];
// }

// //获取最新的报警数
// static uint8 get_alarm_newest_nums()
// {
//     uint32 i=0;
//     uint8 num=0;
//     for(i=COMP_START;i<= MAX_COMP;i++)
//     {
//         if(get_alarmpart(i) != 0)
//         {
//             set_alarm_newest_pos(i);
//             num++;
//         }
//     }
//     return num;
// }
//火警时界面轮显循环显示

void clr_alarm_loop_show(void)
{
    loopflag=0;
}
void set_alarm_loop_show(void)
{
    loopflag=1;
}
uint8 get_alarm_loop_show(void)
{
    return loopflag;
}
//故障警报时界面轮显循环显示

void clr_alarm_loop_show_fault(void)
{
    loopflag_fault=0;
}
void set_alarm_loop_show_fault(void)
{
    loopflag_fault=1;
}
uint8 get_alarm_loop_show_fault(void)
{
    return loopflag_fault;
}
//界面轮显
static alarminfo alarm_info_loop;
static uint8 pos;
static void menu_alarm_fire(void)
{
    //获取最新的报警部件
    static uint8 current_alarmpart = INITVAL;
    uint8 alarmnums = get_firealarm_nums()/*get_record_alarmnum()*/;

    Debug("get_alarm_loop_show:%d\n",get_alarm_loop_show());
    if(current_alarmpart != get_menu_alarm_info()->part)
    {

        Debug("fire alarm!!!\n");
        Debug("current alarm part:%d\n",current_alarmpart);
        Debug("alarm info part   :%d\n",get_menu_alarm_info()->part);


        //非自检且打开时
        if(GetSpeaker_Flag()&&!GetZjFlag()){
            PWM1_Start();
            set_PWM1_Started();
        }
        Alarm_Menu(get_alarm_first_part(),
                   get_menu_alarm_info()->part,
                   get_menu_alarm_info()->ciraddr,
                   alarmnums/*get_firealarm_nums()*/,
                   get_menu_alarm_info()->type,
                   &(get_menu_alarm_info()->dateyear));//time

        //记录此次的内容
        current_alarmpart = get_menu_alarm_info()->part;

        set_record_showalarm(get_record_alarmnum());

        add_alarmnums(get_menu_alarm_info()->part);
        pos = alarmnums-1;//添加位置
    }
    else if((alarmnums > 1)&&get_alarm_loop_show() )
    {

        uint8 part = alarmpart[pos];
        //get item by part
        uint8 item = get_alarm_item_bypart(part);

        clr_alarm_loop_show();

        get_alarm_allinfo(item,&alarm_info_loop);
        Debug("loop show pos:%d\n",pos);
        Debug("alarmnums:%d\n",alarmnums);

        Alarm_Menu(get_alarm_first_part(),
                   alarm_info_loop.part,
                   alarm_info_loop.ciraddr,
                   alarmnums/*get_firealarm_nums()*/,
                   alarm_info_loop.type,
                   &(alarm_info_loop.dateyear));//time



        if(pos > 1)
            pos--;
        else if(1 == pos)
            pos = 0;
        else if(0 == pos)
            pos = alarmnums-1;

    }
    else
    {
        if(alarmnums > 1)
        {
            uint8 part = alarmpart[pos];
            //get item by part
            uint8 item = get_alarm_item_bypart(part);

            clr_alarm_loop_show();

            get_alarm_allinfo(item,&alarm_info_loop);
            Debug("loop show pos:%d\n",pos);
            Debug("alarmnums:%d\n",alarmnums);

            Alarm_Menu(get_alarm_first_part(),
                       alarm_info_loop.part,
                       alarm_info_loop.ciraddr,
                       alarmnums/*get_firealarm_nums()*/,
                       alarm_info_loop.type,
                       &(alarm_info_loop.dateyear));//time
        }else{
            Alarm_Menu(get_alarm_first_part(),
                       get_menu_alarm_info()->part,
                       get_menu_alarm_info()->ciraddr,
                       alarmnums/*get_firealarm_nums()*/,
                       get_menu_alarm_info()->type,
                       &(get_menu_alarm_info()->dateyear));//time
        }
    }

}
//void menu_alarm_batlow(void)
//{
//    Battery_Low(Getdisplay_alarm(0),
//                Getdisplay_alarm(1),
//                Getdisplay_alarm(3),
//                Getdisplay_alarm(4),
//                Getalarmtime());
//}

//界面轮显
static alarminfo alarm_info_loop_fault;
static uint8 pos_fault;

static void menu_alarm_fault(void)
{
#if 1

    //获取最新的报警部件
    static uint8 current_alarmpart_fault = INITVAL;
    uint8 alarmnums = get_faultalarm_nums()/*get_record_alarmnum()*/;

    Debug("get_alarm_loop_show:%d\n",get_alarm_loop_show_fault());
    if(current_alarmpart_fault != get_menu_faultalarm_info()->part)
    {

        Debug("fault alarm!!!\n");
        Debug("current alarm part:%d\n",current_alarmpart_fault);
        Debug("alarm info part   :%d\n",get_menu_faultalarm_info()->part);


        //非自检且打开时
        if(GetSpeaker_Flag()&&!GetZjFlag()){
            PWM1_Start();
            set_PWM1_Started();
        }
        Breakdown(get_menu_faultalarm_info()->attr,
                  get_menu_faultalarm_info()->part,
                  get_faultalarm_nums(),
                  get_menu_faultalarm_info()->type,
                  &get_menu_faultalarm_info()->dateyear);


        //记录此次的内容
        current_alarmpart_fault = get_menu_faultalarm_info()->part;

        set_record_showalarm_fault(get_record_alarmnum_fault());

        add_alarmnums_fault(get_menu_faultalarm_info()->part);
        pos_fault = alarmnums-1;//添加位置
    }
    else if((alarmnums > 1)&&get_alarm_loop_show_fault() )
    {

        uint8 part = alarmpart_fault[pos_fault];
        //get item by part
        uint8 item = get_alarm_item_bypart(part);

        clr_alarm_loop_show_fault();

        get_alarm_allinfo(item,&alarm_info_loop_fault);
        Debug("loop show pos:%d\n",pos_fault);
        Debug("alarmnums:%d\n",alarmnums);

        Breakdown(get_menu_faultalarm_info()->attr,
                  get_menu_faultalarm_info()->part,
                  get_faultalarm_nums(),
                  get_menu_faultalarm_info()->type,
                  &get_menu_faultalarm_info()->dateyear);



        if(pos_fault > 1)
            pos_fault--;
        else if(1 == pos_fault)
            pos_fault = 0;
        else if(0 == pos_fault)
            pos_fault = alarmnums-1;

    }
    else
    {
        if(alarmnums > 1)
        {
            uint8 part = alarmpart_fault[pos_fault];
            //get item by part
            uint8 item = get_alarm_item_bypart(part);

            clr_alarm_loop_show_fault();

            get_alarm_allinfo(item,&alarm_info_loop_fault);
            Debug("loop show pos_fault:%d\n",pos_fault);
            Debug("alarmnums:%d\n",alarmnums);

            Breakdown(get_menu_faultalarm_info()->attr,
                      get_menu_faultalarm_info()->part,
                      get_faultalarm_nums(),
                      get_menu_faultalarm_info()->type,
                      &get_menu_faultalarm_info()->dateyear);
        }else{
            Breakdown(get_menu_faultalarm_info()->attr,
                      get_menu_faultalarm_info()->part,
                      get_faultalarm_nums(),
                      get_menu_faultalarm_info()->type,
                      &get_menu_faultalarm_info()->dateyear);
        }
    }


#else

    //非自检且打开时
    if(GetSpeaker_Flag()&&!GetZjFlag()){
        PWM1_Start();
        set_PWM1_Started();
    }
    Breakdown(get_menu_alarm_info()->attr,
              get_menu_alarm_info()->part,
              get_faultalarm_nums(),
              get_menu_alarm_info()->type,
              &get_menu_alarm_info()->dateyear);
#endif
}

////after 30s return to alarm page if have alarm info,so reset will clear
//void have_alarm_backafter30s()
//{
//    static uint8 time_alarm_backct=Time3s;
//    if(GetDisplay_alarm_flag() == PAGE_AT_FIRE
//            ||GetDisplay_alarm_flag() == PAGE_AT_BATLOW
//            ||GetDisplay_alarm_flag() == PAGE_AT_FAULT)
//        time_alarm_backct--;
//    else
//        return;
//    if(0 == time_alarm_backct){
//        SetMenuFlag(MENU_FIREALARM);//return to alarm info
//        time_alarm_backct = Time3s;
//    }
//}

void DisplayKeyMenu(void)//主界面
{
    uint8 hz[]="请输入密码";//hz：汉字
    if(GetMenuFlag() == MENU_MAIN)//初始化界面
    {
        Debug("->>MENU_MAIN\n");
        //        show_head_menu();//显示首页
        if(Get_KeyValue() == KEY_Sure)//确定键
        {
            SetPasswordFlag(0);//1表示不要密码
            ClearScreen(0);
            //请输入密码
            DisplayJBHZK(1,0,16,((hz[0]<<8)+hz[1]));
            DisplayJBHZK(1,0,32,((hz[2]<<8)+hz[3]));
            DisplayJBHZK(1,0,48,((hz[4]<<8)+hz[5]));
            DisplayJBHZK(2,0,0,((hz[6]<<8)+hz[7]));
            DisplayJBHZK(2,0,16,((hz[8]<<8)+hz[9]));
        }
        if(GetBackValue()==KEY_Back)//此值自增加1，3次输密码的过程
        {
            Displaynumber(1,4,48,0xd);/*  *号  */
        }
        else if(GetBackValue()==2)
        {
            Displaynumber(1,4,56,0xd);
        }
        else if(GetBackValue()==3)
        {
            Displaynumber(2,4,0,0xd);
            SetMenuFlag(MENU_RUN);//菜单为2去主循环
            ClrBackValue();
            SetPasswordFlag(1);//设置密码标志，1为不用输入，0输入

            Main_Menu(1);
            SetGrapCount(1);
        }

    }
    else if(GetMenuFlag() == MENU_FIREALARM)//显示报警界面
    {
        Debug("-->>MENU_FIREALARM\n");
        //添加上下按键浏览报警信息
        if(GetDisplay_alarm_flag() == PAGE_AT_FIRE )
            menu_alarm_fire();
        if(Get_KeyValue() == KEY_Return)
        {
            Debug("-->>set MENU_RUN\n");
            SetMenuFlag(MENU_RUN);
            Main_Menu(1);
            SetGrapCount(1);
            SetPasswordFlag(1);
        }


    }
    else if(GetMenuFlag() == MENU_FAULTALARM)//显示故障界面
    {
        Debug("-->>MENU_FAULTALARM\n");
        //添加上下按键浏览报警信息
        if(GetDisplay_alarm_flag() == PAGE_AT_FAULT)
            menu_alarm_fault();

        if(Get_KeyValue() == KEY_Return)
        {
            Debug("set MENU_RUN at MENU_FAULTALARM \n");
            SetMenuFlag(MENU_RUN);
            Main_Menu(1);
            SetGrapCount(1);
            SetPasswordFlag(1);
        }
    }
    else if(GetMenuFlag() == MENU_RUN)
    {
        Debug("-->>MENU_RUN\n");
        //        have_alarm_backafter30s();
        Systemp_Task();//主界面
    }
    else
    {
        Debug("-->>else MENU\n");
        if(Get_KeyValue() == KEY_Return)//按返回键
        {


            if(GetDisplay_alarm_flag() == PAGE_AT_FIRE )
            {
                SetMenuFlag(MENU_FIREALARM);
                SetPasswordFlag(1);
            }
            if(GetDisplay_alarm_flag() == PAGE_AT_FAULT )
            {
                SetMenuFlag(MENU_FAULTALARM);
                SetPasswordFlag(1);
            }
            //            SetMenuFlag(MENU_MAIN);
            //            SetPasswordFlag(1);
            //            SetCheckInfoFlag(0,0);
            //            SetCheckInfoFlag(1,0);
            //            SetCheckInfoFlag(2,0);
//            SetAlarmFlag(0,0);
            //            ShuaFlag=0;
            SetReleaseFlag(0);
            Led_Silence_Off();
        }
    }
    if(Get_KeyValue() == KEY_Silence)//消音
    {

        clr_PWM1_Started();
        PWM1_Stop();
        BEEPOff();


//        SetAlarmFlag(0,0);
        if(GetDisplay_alarm_flag())
            Led_Silence_On();
        PWM1_Stop();
    }

}
void Systemp_Task(void)//主工作任务
{
    uint16 temp = 0;

//    Debug("GetCounter0:(%d)1:(%d)2:(%d)\n",GetGrapCount(),GetCounter1(),GetCounter2());
    temp = Get_KeyValue();

    switch(temp)
    {
    case 1: //回退键任务
        Back_Task();
        break;
    case 2: //向上键任务
        Up_Task();
        break;
    case 3: //向下键任务
        Down_Task();
        break;
    case 4: //确认键任务
        Sure_Task();
        break;
    case 5: //返回键任务
        Return_Task();
        break;
    case 6: //消音键任务
        Silence_Task();
        //        SetAlarmFlag(0,0);
        break;
    default:
        break;

    }
}


// //set
// static void set_time_sendheart(uint8 n)
// {
//     time_sendheart = n;
// }
//add
static void add_time_sendheart()
{
    time_sendheart++;
}
//get
static uint8 get_time_sendheart(void)
{
    return time_sendheart;
}
//clr
static void clr_time_sendheart(void)
{
    time_sendheart=0;
}


#if 1
//给自己发送心跳，检测串口1上的无线模块是否正常工作
void SendHeart(void)//心跳发送
{
    if(get_time_sendheart() >= TIME_THR)
    {
        clr_time_sendheart();
        UartBindSend(CMD_139W,2);	   //发送心跳命令
        UartBindSend(CMD_139W,2);
        SetHeartFaultFlag();
    }
    else
    {
        add_time_sendheart();
        if(GetHeartFaultFlag()==1)//报故障 cs0=0
        {
            vHeartLostFlag++;
            UartBindSend(CMD_139W,2);	   //发送心跳命令
            UartBindSend(CMD_139W,2);
            Debug("!err:heart lost:%d\n",vHeartLostFlag);
        }
        else
        {//如果情况正常的情况下,返回到首页面
            vHeartLostFlag=0;
            //清空显示界面
            if(GetMenuFlag() == MENU_WIRELESS_FAULT)
            {
                SetMenuFlag(MENU_MAIN);
                SetAlarmFlag(POS_ALARM_BIT,ALARM_NORMAL);
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
            Led_Fault_On();//故障灯
            Led_Wireless_On();//通讯灯


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
//void SendHeart(void)//心跳发送
//{
//    if(GetHeartTick() >= TIME_3M)
//    {
//        SetHeartTick(0);
//        UartBindSend(CMD_139W,2);	   //发送心跳命令
//        UartBindSend(CMD_139W,2);
//        SetHeartFaultFlag();
//    }
//    else
//    {
//        if(GetHeartTick()<TIME_1M)
//        {
//            if(GetHeartFaultFlag()==1)//报故障 cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //发送心跳命令
//                UartBindSend(CMD_139W,2);
//                Debug("!err:heart lost:%d\n",vHeartLostFlag);
//            }
//            else
//                vHeartLostFlag=0;
//        }
//        else if((GetHeartTick()>TIME_1M)&&(GetHeartTick()< TIME_2M))//5s~6s
//        {
//            if(GetHeartFaultFlag()==1)//报故障 cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //发送心跳命令
//                UartBindSend(CMD_139W,2);
//                Debug("!err:heart lost:%d\n",vHeartLostFlag);
//            }
//            else
//                vHeartLostFlag=0;
//        }
//        else if((GetHeartTick()>TIME_2M)&&(GetHeartTick()< TIME_3M))//8s&9s
//        {
//            if(GetHeartFaultFlag()==1)//报故障 cs0=0
//            {
//                vHeartLostFlag++;
//                UartBindSend(CMD_139W,2);	   //发送心跳命令
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
//向上位机回复机器工作状态，串口0
//uart0 发送信息至短信模块
void inqury_state__byuart0(void)
{
    if(GetFlag_195()/*&&GetE3_flag()*/)//有查询命令标志
    {
        if((GetAlarmFlag(POS_ALARM_BIT)==ALARM_FIRE))
        {
            /*
警报类型：
1：火警
2：部件故障恢复
其它正常
*/
            //            //发送火警
            Query_ByUart0(0x0A,0x00,GetAlarmFlag(POS_ALARM_BIT));
        }
        else if((GetAlarmFlag(POS_ALARM_BIT) == ALARM_FAULT)||
                GetAlarmFlag(POS_ALARM_BIT) == ALARM_BAT_LOW)
        {
            Query_ByUart0(0x0B,0x00,GetAlarmFlag(POS_ALARM_BIT));//部位故障
        }
        else//normal state
            Query_ByUart0(0x13,0x00,0x00);

//        SetFlag_195();
        ClrFlag_195();
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
