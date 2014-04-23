/*
;*********************************************************************************************************
;*                                                
;*                            对象: key
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : key.c
;* By   : 尹海星
;* 时间 : 2013-06-25
;*********************************************************************************************************
;*/
#define _KEY_VAR_C
#include  "include.h"
#include  "key.h"
#include  "CTime.h"
#include  "CComPara.h"
#include "CLED.h"
#include  "CKeyCounter.h"
#include  "CComHandle.h"




uint8 GetBackValue(void)
{
    return vBackValue;
}
void ClrBackValue(void)
{
    vBackValue=0;
}





#if 0
#define KEY_SIZE 4
typedef union type_scan_key{
//     uint32 Word[KEY_SIZE];
    struct{
        *(volatile unsigned long *)keym;
        uint32 counterpos;
        uint32 timer;
        void (*fun)(void);
    }Bit;


}t_scan_key;
#define TIMER2_USED 2
void fun_default(void)
{
    OnLCD();
}

void fun_silence(void)
{
    BEEPOff();
    SetAlarmFlag(0,0);
    if(GetDisplay_alarm_flag())
        Led_Silence_On();
    OnLCD();
}
void fun_return(void)
{
    if(!GetDisplay_alarm_flag())
        Led_Silence_Off();
    OnLCD();
}


static t_scan_key m_t_scan_key[]={
    {KEY_UP,4,TIMER2_USED,fun_default},
    {KEY_DOWN,5,TIMER2_USED,fun_default},
    {KEY_SILENCE,1,TIMER2_USED,fun_silence},
    {KEY_BACK,3,TIMER2_USED,fun_default},
    {KEY_OK,0,TIMER2_USED,fun_default},
    {KEY_RETURN,2,TIMER2_USED,fun_return},
};





void Scan_Key(void)
{
    uint8 val=0;
    for(val=0;val<ARRAYSIZE(m_t_scan_key);val++)
    {
        if(!m_t_scan_key[val].Bit.keym)
        {
            Delay1Ms(KEYDELAYTIME);
            if(!m_t_scan_key[val].Bit.keym)
            {
                vKeyCounter[m_t_scan_key[val].Bit.counterpos]++;
                if(vKeyCounter[0] >= 1)
                {
                    disable_timer(m_t_scan_key[val].Bit.timer);
                    m_t_scan_key[val].Bit.fun();
                    Delay1Ms(KEYDELAYTIME); //去抖
                    return;
                }
            }

        }
    }
    return;
}
#elif 0


#define  cMaxSysRunFlagLen    4

typedef union type_tKeyFlag{	   //ê±?ó±êê?

    uint32   Word;
    uint16   UByte[cMaxSysRunFlagLen>>1];
    uint8    Byte[cMaxSysRunFlagLen];
    struct
    {
        uint32 bup:1;               //up
        uint32 bdown:1;             //down
        uint32 bok:1;               //ok
        uint32 bsilence:1;          //silence
        uint32 bback:1;            //back
        uint32 breturnk:1;           //return

    }Bit;
}tKeyFlag;
tKeyFlag vKeyFlag;

#define KEY_VAR(key) vKeyFlag.Bit.b##key




void Scan_Key(void)
{ 
    if(!KEY_UP)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_UP);
        set_up_tkeyflag();
        OnLCD();
        return;
    }/*else{
        clr_up_tkeyflag();
    }*/
    if(!KEY_DOWN)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_DOWN);
        set_down_tkeyflag();
        OnLCD();
        Delay1Ms(KEYDELAYTIME); //去抖
        return;
    }/*else{
        clr_down_tkeyflag();
    }*/

    if(!KEY_OK)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_OK);
        OnLCD();
        //Delay1Ms(KEYDELAYTIME); //去抖
        set_ok_tkeyflag();
    }/*else{
        clr_ok_tkeyflag();
    }*/

    if(!KEY_BACK)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_BACK);
        set_back_tkeyflag();
        OnLCD();
        Delay1Ms(KEYDELAYTIME); //去抖
        return;
    }/*else{
        clr_back_tkeyflag();
    }*/

    if(!KEY_RETURN)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_RETURN);
        set_return_tkeyflag();
        if(!GetDisplay_alarm_flag())
            Led_Silence_Off();
        OnLCD();
        Delay1Ms(KEYDELAYTIME); //去抖
        return;

    }/*else{
        clr_return_tkeyflag();
    }*/

    if(!KEY_SILENCE)
    {
        DelayMs(KEYDELAYTIME);
        while(!KEY_SILENCE);
        set_silence_tkeyflag();
        BEEPOff();
        SetAlarmFlag(0,0);
        if(GetDisplay_alarm_flag())
            Led_Silence_On();
        OnLCD();
        Delay1Ms(KEYDELAYTIME); //去抖

    }/*else{
        clr_silence_tkeyflag();
    }*/
}
uint16 CGet_KeyValue(void)
{
    if(get_up_tkeyflag()&&KEY_UP)
    {
        clr_up_tkeyflag();
        return KEY_Up;
    }
    if(get_down_tkeyflag()&&KEY_DOWN)
    {
        clr_down_tkeyflag();
        return KEY_Down;
    }
    if(get_ok_tkeyflag()&&KEY_OK)
    {
        clr_ok_tkeyflag();
        return KEY_Sure;
    }
    if(get_back_tkeyflag()&&KEY_BACK)
    {
        clr_back_tkeyflag();
        return KEY_Back;
    }
    if(get_return_tkeyflag()&&KEY_RETURN)
    {
        clr_return_tkeyflag();
        return KEY_Return;
    }
    if(get_silence_tkeyflag()&&KEY_SILENCE)
    {
        clr_silence_tkeyflag();
        return KEY_Silence;
    }


    return 0xff;
}




// uint16 Key_Read(void)


void set_up_tkeyflag(void)
{
    KEY_VAR(up)=1;
}
void clr_up_tkeyflag(void)
{
    KEY_VAR(up)=0;
}
uint8 get_up_tkeyflag(void)
{
    return KEY_VAR(up);
}

void set_down_tkeyflag(void)
{
    KEY_VAR(down)=1;
}
void clr_down_tkeyflag(void)
{
    KEY_VAR(down)=0;
}
uint8 get_down_tkeyflag(void)
{
    return KEY_VAR(down);
}

void set_back_tkeyflag(void)
{
    KEY_VAR(back)=1;
}
void clr_back_tkeyflag(void)
{
    KEY_VAR(back)=0;
}
uint8 get_back_tkeyflag(void)
{
    return KEY_VAR(back);
}

void set_silence_tkeyflag(void)
{
    KEY_VAR(silence)=1;
}
void clr_silence_tkeyflag(void)
{
    KEY_VAR(silence)=0;
}
uint8 get_silence_tkeyflag(void)
{
    return KEY_VAR(silence);
}

void set_return_tkeyflag(void)
{
    KEY_VAR(returnk)=1;
}
void clr_return_tkeyflag(void)
{
    KEY_VAR(returnk)=0;
}
uint8 get_return_tkeyflag(void)
{
    return KEY_VAR(returnk);
}

void set_ok_tkeyflag(void)
{
    KEY_VAR(ok)=1;
}
void clr_ok_tkeyflag(void)
{
    KEY_VAR(ok)=0;
}
uint8 get_ok_tkeyflag(void)
{
    return KEY_VAR(ok);
}



#else
void Scan_Key(void)
{

    if(!KEY_OK) //确定键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_OK)
        {
            vKeyCounter[0]++;
            if(vKeyCounter[0] >= 1)
            {
                //disable_timer(2);
            }
            OnLCD();
            //Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }

    }
//    else
//    {
//        vKeyCounter[0] = 0;
//    }
    if(!KEY_SILENCE)//静音键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_SILENCE)
        {
            vKeyCounter[1]++;
            if(vKeyCounter[1] >= 1)
            {
                //disable_timer(2);

            }
//            BEEPOff();
//            SetAlarmFlag(POS_ALARM_BIT,0);//消除所有的报警信息，静音了
//            if(GetDisplay_alarm_flag())
//                Led_Silence_On();
//            OnLCD();
//            Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }
    }
//    else
//    {
//        vKeyCounter[1] = 0;
//    }
    if(!KEY_RETURN)//返回键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_RETURN)
        {
            vKeyCounter[2]++;
            if(vKeyCounter[2] >= 1)
            {
                //disable_timer(2);

            }
            if(!GetDisplay_alarm_flag())
                Led_Silence_Off();
            OnLCD();
//            Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }

    }
//    else
//    {
//        vKeyCounter[2] = 0;
//    }
    if(!KEY_BACK)//回退键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_BACK)
        {
            vKeyCounter[3]++;
            if(vKeyCounter[3] >= 1)
            {
                //disable_timer(2);

            }
            OnLCD();
            //Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }
    }
//    else
//    {
//        vKeyCounter[3] = 0;
//    }
    if(!KEY_UP)//向上键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_UP)
        {
            vKeyCounter[4]++;
            if(vKeyCounter[4] >= 1)
            {
                //disable_timer(2);

            }
            OnLCD();
            //Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }
    }
//    else
//    {
//        vKeyCounter[4] = 0;
//    }
    if(!KEY_DOWN)//向下键
    {
        //Delay1Ms(KEYDELAYTIME);
        if(!KEY_DOWN)
        {
            vKeyCounter[5]++;
            if(vKeyCounter[5] >= 1)
            {
                //disable_timer(2);

            }
            OnLCD();
            ////Delay1Ms(KEYDELAYTIME); //去抖
            return;


        }
    }
//    else
//    {
//        vKeyCounter[5] = 0;
//    }
}

//#if 0
//#define  KEY_Back	   1  //回退键
//#define  KEY_Up      2  //向上键
//#define  KEY_Down    3  //向下键
//#define  KEY_Sure    4  //确认键
//#define  KEY_Return  5  //返回键
//#define  KEY_Silence 6  //消音键

//#endif

#define KEYVAL (5)

uint16 Get_KeyValue(void)
{
//    uint8 i;
//    for(i=0;i<6;i++)
//    {
//        if(!vKeyCounter[i])
//            continue;
//        else if(vKeyCounter[i] >= KEYVAL)
//            Debug("vKeyCounter[%d]:%d\n",i,vKeyCounter[i]);
//    }
  
#ifdef KEYNOTLOCK
    if(vKeyCounter[0] >= KEYVAL)
    {
//        if(KEY_OK)
//        {
            //enable_timer(2);
            vKeyCounter[0] = 0;

            return KEY_Sure;
//        }
    }
    if(vKeyCounter[1] >= KEYVAL)
    {
//        if(KEY_SILENCE)
//        {
            //enable_timer(2);
            vKeyCounter[1] = 0;
            BEEPOff();
            PWM1_Stop();
            clr_PWM1_Started();
            SetAlarmFlag(POS_ALARM_BIT,0);//reset alarm flag,so pwm1 stop

            return KEY_Silence;
//        }
    }
    if(vKeyCounter[2] >= KEYVAL)
    {
//        if(KEY_RETURN)
//        {
            //enable_timer(2);
            vKeyCounter[2] = 0;
            return KEY_Return;
//        }
    }
    if(vKeyCounter[3] >= KEYVAL)
    {
//        if(KEY_BACK)
//        {
            //enable_timer(2);
            vKeyCounter[3] = 0;

            if(GetPasswordFlag())
                ClrBackValue();
            else
                vBackValue++;
            return KEY_Back;
//        }
    }
    if(vKeyCounter[4] >= KEYVAL)
    {
//        if(KEY_UP)
//        {
            //enable_timer(2);
            vKeyCounter[4] = 0;
            return KEY_Up;
//        }
    }
    if(vKeyCounter[5] >= KEYVAL)
    {
//        if(KEY_DOWN)
//        {
            //enable_timer(2);
            vKeyCounter[5] = 0;
            return KEY_Down;
//        }
    }
    return 0xff;
#else
    if((vKeyCounter[0] >= KEYVAL)&&KEY_OK)
    {
//        if(KEY_OK)
//        {
            //enable_timer(2);
            vKeyCounter[0] = 0;

            return KEY_Sure;
//        }
    }
    if((vKeyCounter[1] >= KEYVAL)&&KEY_SILENCE)
    {
//        if(KEY_SILENCE)
//        {
            //enable_timer(2);
            vKeyCounter[1] = 0;
            BEEPOff();
            PWM1_Stop();
            clr_PWM1_Started();
            SetAlarmFlag(POS_ALARM_BIT,0);//reset alarm flag,so pwm1 stop

            return KEY_Silence;
//        }
    }
    if((vKeyCounter[2] >= KEYVAL)&&KEY_RETURN)
    {
//        if(KEY_RETURN)
//        {
            //enable_timer(2);
            vKeyCounter[2] = 0;
            return KEY_Return;
//        }
    }
    if((vKeyCounter[3] >= KEYVAL)&&KEY_BACK)
    {
//        if(KEY_BACK)
//        {
            //enable_timer(2);
            vKeyCounter[3] = 0;

            if(GetPasswordFlag())
                ClrBackValue();
            else
                vBackValue++;
            return KEY_Back;
//        }
    }
    if((vKeyCounter[4] >= KEYVAL)&&KEY_UP)
    {
//        if(KEY_UP)
//        {
            //enable_timer(2);
            vKeyCounter[4] = 0;
            return KEY_Up;
//        }
    }
    if((vKeyCounter[5] >= KEYVAL)&&KEY_DOWN)
    {
//        if(KEY_DOWN)
//        {
            //enable_timer(2);
            vKeyCounter[5] = 0;
            return KEY_Down;
//        }
    }
    return 0xff;

#endif
}

#endif





