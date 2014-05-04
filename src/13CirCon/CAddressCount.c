/*
;*********************************************************************************************************
;*                                                
;*                            对象: CComPara
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CAddressCount.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "CAddressCount.h"
#include  "CTimeDef.h"
#include  "CFlashParam.h"
#include  "CSetCurrent.h"
#include  "CGetCompSum.h"
#include  "CSendToFlash.h"
#include  "CComPara.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"
#include  "CTaskSure.h"

#define PIN23 (0x1<<23)
#define PIN24 (0x1<<24)

//部件个数
#define COMPNETNUMS 50
#define SYNCCOUNTER 1000 /*the max counter of two falling edge of normal is 50ms*/
#define MAXSYNCCOUNTER 4100



// static volatile uint32 RisingCount=0;//记录上升沿的时长数量
static volatile uint32 circuit_counter=0;//回路地址计数
// static volatile uint8 vCirAddrv=0;//回路地址
static volatile uint8 syn_flag=0;
// static volatile uint8 fireflag[2]={0};
// volatile uint8 Reset_Flag[50]={0};
// volatile uint8 Reset_Flag1[50]={0};
// volatile uint8 Reset_Counter[50]={0};
static volatile uint8 alarm_circuit_flag=0;
void SetAlarm_Circuit_Flag(uint8 tmp)
{
    alarm_circuit_flag=tmp;
}
void AddCirCounter(void)//回路地址+1
{
    circuit_counter++;
}
uint32 GetCirCounter(void)
{
    return circuit_counter;
}
void ClrCirCounter(void)
{
    circuit_counter=0;
}

////p0.23 low,return 1
//uint8_t PIN023LOW(void)
//{
//    return (0 == (FIO0PIN&(PIN23)));
//}
//void ledtest(void)
//{
//    if(GetCirCounter()==219)
//        Led_Silence_On();
//    else
//        Led_Silence_Off();

//}
//void RisingTest(void)
//{
//    if(GetCirCounter()>=219)
//    {
//        //            Debug("addr:%d,counter:%d\n",GetCirCounter(),RisingCount);
//        if(vGetRiseingCount()>118)
//            Led_Fault_On();
//        else
//            Led_Fault_Off();
//        //            Debug("addr:%d,counter:%d\n",GetCirCounter(),vGetFallingCount());
//        //            State_20mA();
//        //            fireflag[0]=1;
//    }
//}
//void ClrOverCirAddr(void)
//{
//    if(GetCirCounter() >= 219 )
//    {
//         syn_flag = 0;
////         Debug("clear sync\n");
//    }
//}



//8ms
//uint8 NormalState(void)
//{
//    return (vGetRiseingCount() > 70)&&(vGetRiseingCount() < 90);
//}
////类型状态 8+4ms 12
//uint8 TypeState(void)
//{
//    return (vGetRiseingCount() > 110)&&(vGetRiseingCount() < 130);
//}
////模拟量 8+8ms 16  157联动测试
//uint8 AnalogInquiry(void)
//{
//    return (vGetRiseingCount() > 150)&&(vGetRiseingCount() < 170);
//}
////数据查询 8+12ms，196，197现场部件数据查询
//uint8 DataInquiry(void)
//{
//    return (vGetRiseingCount() > 190)&&(vGetRiseingCount() < 210);
//}

//uint32 SyncFlagCounter(void)
//{
//    return (vGetFallingCount() > SYNCCOUNTER)&&(vGetFallingCount()<MAXSYNCCOUNTER);
//}

//set sync flag
void SetSync(void)
{
    syn_flag=1;
}
uint8 GetSync(void)
{
    return syn_flag;
}
void ClrSync(void)
{
    syn_flag=0;
}

//#if 1
////处理回路信息,回路波形
////static uint8 vCirtmp=0;
//void CirAddrCounter(void)
//{
//    if(GetSync())//同步后的地址计数
//    {
//        RisingCount=vGetRiseingCount();
//        vCirAddrv=GetCirCounter();

//        if(!vCirAddrv){
////            Debug("begin sync.....\n");
//            Led_Silence_On();
//        }else{
//            Led_Silence_Off();
//        }
//        /*the first rising edge's counter(8ms/100us=?)*/
////        ledtest();
////        RisingTest();

//        if((RisingCount > 70)&&(RisingCount < 90))//normal,8ms
//        {
////            if(vCirAddrv>217)
////                Debug("normal! counter:%d,addr:%d\n",RisingCount,vCirAddrv);

////            if(vCirAddrv>10&&vCirAddrv<120)
////            {
////                if(Is2msArrived()){//是否时间到了
////                    Set2msArrived();
////                    Disable2ms();
////                }
////            }

//            Check_Addr(vCirAddrv);	//判断地址函数
//            ClrOverCirAddr();
//        }
//        else if((RisingCount > 120)&&(RisingCount < 135))//状态和类型查询,12ms
//        {
//            Debug("type&state! counter:%d,addr:%d\n",RisingCount,vCirAddrv);
//            Sel_Addr_fire(vCirAddrv);//选择报警地址
//            // 			if(vCirAddrv == 2 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}
//            // 			if(vCirAddrv == 3 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}


//            ClrOverCirAddr();
//        }
//        else if((RisingCount > 140)&&(RisingCount < 170)) //模拟量查询,16ms
//        {
//            Debug("Analog! counter:%d,addr:%d\n",RisingCount,vCirAddrv);
//            ClrOverCirAddr();
//        }
//        else if((RisingCount > 180)&&(RisingCount < 210)) //数据查询,20ms
//        {
//            Debug("Data! counter:%d,addr:%d\n",RisingCount,vCirAddrv);
//            ClrOverCirAddr();
//        }else{
//            //            Debug("other counter:%d,addr:%d\n",RisingCount,vCirAddrv);
//        }

//#if 0
//        if((vGetFallingCount() > 50)&&(vGetFallingCount() < 90))
//        {
//            //            AddCirCounter(); 	//回路地址+1
//            ////            Debug("addr:%d,counter:%d\n",GetCirCounter(),vGetFallingCount());

//            if(GetCirCounter() == 2 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 3 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            Check_Addr(GetCirCounter());	//判断地址函数
//            if(GetCirCounter() >= 219 )
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }
//        else if((vGetFallingCount() > 100)&&(vGetFallingCount() < 135))//状态和类型查询
//        {
//            //            AddCirCounter();
//            Sel_Addr_fire(GetCirCounter());//选择报警地址
//            // 			if(GetCirCounter() == 2 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}
//            // 			if(GetCirCounter() == 3 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}


//            //            if(GetCirCounter() >= 219 )
//            //            {
//            //                syn_flag = 0;
//            //                Debug("clear sync\n");
//            //            }
//        }

//        else if((vGetFallingCount() > 140)&&(vGetFallingCount() < 170)) //模拟量查询
//        {
//            //            AddCirCounter();
//            if(GetCirCounter() >= 219 )
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }
//        else if((vGetFallingCount() > 180)&&(vGetFallingCount() < 210)) //数据查询
//        {
//            //            AddCirCounter();
//            if(GetCirCounter() >= 219)
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }else{

//        }
//#endif

//    }

//}
//#else//org
//void CirAddrCounter(void)
//{
//    if(GetTimer0Counter() > SYNCCOUNTER)//同步  计数
//    {
//        Debug("counter:%d\n",GetTimer0Counter());
//        ClrTimer0Counter();
//        circuit_counter = 0;//回路地址
//        syn_flag = 1;
//        Debug("begin sync...\n");
//    }
//    if(syn_flag)//同步后的地址计数
//    {
//        /*the first rising edge's counter(8ms/100us=?)*/
//        if((GetTimer0Counter() > 50)&&(GetTimer0Counter() < 90))
//        {
//            AddCirCounter(); 	//回路地址+1
//            //            Debug("addr:%d,counter:%d\n",GetCirCounter(),GetTimer0Counter());
//            ClrTimer0Counter();

//            if(GetCirCounter() == 2 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 3 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 20 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 21 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 22 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 217 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 218 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            if(GetCirCounter() == 219 )
//            {
//                State_20mA();
//                fireflag[0]=1;
//            }
//            Check_Addr(GetCirCounter());	//判断地址函数
//            if(GetCirCounter() >= 219 )
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }
//        else if((GetTimer0Counter() > 100)&&(GetTimer0Counter() < 135))//状态和类型查询
//        {
//            AddCirCounter();
//            ClrTimer0Counter();
//            Sel_Addr_fire(GetCirCounter());//选择报警地址
//            // 			if(GetCirCounter() == 2 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}
//            // 			if(GetCirCounter() == 3 )
//            // 			{
//            // 				fireflag[1]=1;
//            // 				State_6mA();
//            // 			}
//            if(GetCirCounter() >= 219 )
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }

//        else if((GetTimer0Counter() > 140)&&(GetTimer0Counter() < 170)) //模拟量查询
//        {
//            AddCirCounter();
//            ClrTimer0Counter();
//            if(GetCirCounter() >= 219 )
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }
//        else if((GetTimer0Counter() > 180)&&(GetTimer0Counter() < 210)) //数据查询
//        {
//            AddCirCounter();
//            ClrTimer0Counter();
//            if(GetCirCounter() >= 219)
//            {
//                syn_flag = 0;
//                Debug("clear sync\n");
//            }
//        }else{

//        }
//    }

//}
//#endif
//void Reset_Alarm(void)
//{

//    if(Compare_Address(GetCirCounter()))
//    {
//        // 		if(GetCirAlarmData(GetCirCounter()-GetSendToF(0)+1)==0x33)//fire
//        if(Reset_Flag1[GetCirCounter()-GetSendToF(0)])
//        {
//            if(GetTwoFallEdgeCounter() == 5)
//            {
//                if(FIO0PIN&(1 << 23))//(((~(FIO0PIN))&(1 << 23))==0x0800000)
//                    Reset_Counter[GetCirCounter()-GetSendToF(0)]++;
//                else
//                    Reset_Counter[GetCirCounter()-GetSendToF(0)]=0;
//            }
//        }
//    }
//}
static uint8 xialasignal =0;
void addxialasignal(void)
{
    xialasignal++;
    if(xialasignal>200)
        xialasignal=200;
}
uint8 getxialasignal(void)
{
    return xialasignal;
}
void clr_xialasignal(void)
{
    xialasignal=0;
}

static uint8 weixialasignal =0;
void add_weixialasignal(void)
{
    weixialasignal++;
    if(weixialasignal>200)
        weixialasignal=200;
}
static uint8 get_weixialasignal(void)
{
    return weixialasignal;
}
void clr_weixialasignal(void)
{
    weixialasignal=0;
}

void Clr_Alarm(void)
{
    static uint8 tmpnums=0;
#if 1
    if(get_firealarm_nums()>0)
    {
#endif
        if(0 == (tmpnums++)%30){
            Debug("Clr_Alarm:have fir alarms\n");
            Debug("xia la val:%d\n",getxialasignal());
            Debug("wei la val:%d\n",get_weixialasignal());

        }
        if(getxialasignal() >  50)//有下拉信号，并且三次出现正常时未下拉时复位
        {
            Debug("xialasignal >4\n");
            if(get_weixialasignal() >20)
            {
                Debug("-------reset alarm succ!!!\n");
                reset_ok();


//                ClearScreen(0);

//                UartBindSend(CMD_139W,2);	   //发送心跳命令
//                UartBindSend(CMD_139W,2);
//                Led_Fault_Off();
//                Led_Fire_Off();
//                Fire_Relay_Off();
//                Fault_Relay_Off();
//                SetAlarmFlag(POS_ALARM_BIT,0);
//                SetAlarmFlag(POS_INQUIRY_BIT,0);
//                SetReleaseFlag(0);

//                SetMenuFlag(MENU_MAIN);

//                SetDisplay_alarm_flag(PAGE_AT_NORMAL);
//                //清报警回路
//                clr_alarm_allinfo();

//                PWM1_Stop();

//                //清计数
//                clr_weixialasignal();
//                clr_xialasignal();

            }
        }
#if 1
    }
#endif


#if 0
    uint8 i;
    uint32 JSValue=0;
    if(alarm_circuit_flag==1)
    {//get_basic_info(0)为基址值
        if((GetCirCounter()>=get_basic_info(0))&&((GetCirCounter()-get_basic_info(0))<50))
            JSValue=Reset_Counter[GetCirCounter()-get_basic_info(0)];
        if((JSValue>=3)&&(get_basic_info(0)<220)&&(JSValue<0x0ff))
            // 	if((Reset_Counter[GetCirCounter()-get_basic_info(0)]>=3)&&(get_basic_info(0)<220))
        {
            for(i=0;i<50;i++)
            {
                Reset_Counter[GetCirCounter()-get_basic_info(0)]=0;
                Reset_Flag[GetCirCounter()-get_basic_info(0)]=0;
                Reset_Flag1[GetCirCounter()-get_basic_info(0)]=0;
            }
            //reset code
            ClrCirAlarmData();

            //            ClrDatatoFlash();
            UartBindSend(CMD_139W,2);
            Led_Fault_Off();
            Led_Fire_Off();
            Fire_Relay_Off();
            Fault_Relay_Off();
            SetMenuFlag(MENU_MAIN);
        }
        alarm_circuit_flag=0;
    }
#endif
}
//void Check_Addr(uint8 Current_Addr)
//{
//    //if((Current_Addr < (get_basic_info(0) + GetSumRegNum()))&&(get_basic_info(0)<= Current_Addr))
//    //if((Current_Addr < (get_basic_info(0) + get_basic_info(2)))&&(get_basic_info(0)<= Current_Addr))
//    if(Compare_Address(Current_Addr))
//    {
//        if(GetCirAlarmData(Current_Addr-get_basic_info(0)+1)==0x31)//batterylow
//        {
//            State_0mA();
//        }
//        else if(GetCirAlarmData(Current_Addr-get_basic_info(0)+1)==0x32)//broken
//        {
//            State_0mA();
//        }
//        else if(GetCirAlarmData(Current_Addr-get_basic_info(0)+1)==0x33)//fire
//            //else if(GetDatatoFlashAlarmType(1)==0x33)//fire
//        {
//            State_6mA();
//            fireflag[0]=1;
//            if(Reset_Flag[Current_Addr-get_basic_info(0)])
//                Reset_Flag1[Current_Addr-get_basic_info(0)]=1;
//        }
//        else
//            State_6mA();
//    }
//}
//void Sel_Addr_fire(uint8 Current_Addr)
//{

//    // 	if((Current_Addr < (get_basic_info(0) + GetSumRegNum()))&&(get_basic_info(0)<= Current_Addr))
//    // 	if((Current_Addr < (get_basic_info(0) + get_basic_info(2)))&&(get_basic_info(0)<= Current_Addr))
//    if(Compare_Address(Current_Addr))
//    {
//        if(GetCirAlarmData(Current_Addr-get_basic_info(0)+1)==0x33)//fire
//            // 		if(GetDatatoFlashAlarmType(1)==0x33)//fire
//        {
//            fireflag[1]=1;
//            State_6mA();
//            Reset_Flag[Current_Addr-get_basic_info(0)]=1;
//        }
//    }
//}
////回路功能：火警信号
//void CirSendAlarmInfo(void)
//{
//    if(fireflag[0])
//    {
//        if(GetTwoFallEdgeCounter() >= 20)
//        {
//            //火警
//            State_20mA();
//            fireflag[0] = 0;
//        }
//    }

//}
////回路功能：火警信息
//void CirSendFireInfo(void)
//{
//    if(fireflag[1])
//    {
//        if(GetTwoFallEdgeCounter() == 17) //拉低
//        {
//            State_0mA();
//        }
//        //发火警信号3B
//        if(GetTwoFallEdgeCounter() == 23) //11
//        {
//            State_20mA();
//        }
//        if(GetTwoFallEdgeCounter() == 35)  //0
//        {
//            State_6mA();
//        }
//        if(GetTwoFallEdgeCounter() == 41) //1
//        {
//            State_20mA();
//        }
//        if(GetTwoFallEdgeCounter() == 47)//0
//        {
//            State_6mA();
//        }
//        if(GetTwoFallEdgeCounter() == 53)//111
//        {
//            State_20mA();
//        }
//        if(GetTwoFallEdgeCounter() == 71)
//        {
//            State_0mA();
//        }
//        if(GetTwoFallEdgeCounter() == 77)//火警状态
//        {
//            State_20mA();
//            fireflag[1]=0;
//            // 			status_flag = 0;
//            // 			ladi_flag = 1;
//        }
//    }
//}

//uint8 Compare_Address(uint8 addr)
//{
//    uint8 i,j;
//    for(i=0;i<COMPNETNUMS;i++)
//    {
//        if(get_basic_info(i+15)==(addr-get_basic_info(0)+1))
//        {
//            j=1;//get_basic_info(i+15);
//            break;
//        }
//        else
//            j=0;
//    }
//    return j;
//}



