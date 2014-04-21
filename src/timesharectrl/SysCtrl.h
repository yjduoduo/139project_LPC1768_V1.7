#ifndef SYSCTRL_H
#define SYSCTRL_H
#include "include.h"

#ifdef  CSysRunFlag_C
#define Ex_CSysRunFlag
#else
#define Ex_CSysRunFlag extern
#endif

/*******************************************************************/
/******************       数据结构定义    *********************/
/*******************************************************************/
typedef union type_tSysRun{	   //时钟标识

    uint32   Word;
//    uint16   UByte[cMaxSysTimeDataLen>>1];
//    uint8    Byte[cMaxSysTimeDataLen];
    struct
    {
        uint32 b100us:1;//loop
        uint32 b20ms:1;//keyboard
        uint32 b100ms:1;//lcd display
        uint32 b500ms:1;//rtc clock
        uint32 b1s:1;//menu
        uint32 b2s:1;//comment
        uint32 b5s:1;//clear alarm info
        uint32 b1m:1;//send heart
        uint32 bSCloseTime:1;         //保存关机时间

//        uint32 bWinClose:1;
//        uint32 bSd:1;
//        uint32 bUartComm:1;		//8

//        uint32 bReset:1;
//        uint32 bTime:1;
//        uint32 bLang:2;	 	//最多支持4国语言

//        uint32 bInsulW:1;
//        uint32 bInsul:1;

//        uint32 bAutoReg:1;
//        uint32 b1sCtrl:1;	  //16

//        uint32 bLed:1;
//        uint32 bSound:1;
//        uint32 bRelay:1;

//        uint32 bMenu:1;	   //进入菜单标志
//        uint32 bEReset:1;
//        uint32 bEHeart:1;

//        uint32 bCanFdBk:1;	   //需要显示反馈信息
//        uint32 bCanChkRec:1;	 //需要显示反馈信息   24

//        uint32 bWM_TIMER:1;	    //需要实时变化
//        uint32 bHydAns:1;	      //消防泵回答状态

//        uint32 bECanFdBk:1;	   //需要显示反馈信息
//        uint32 bECanChkRec:1;	 //需要显示反馈信息

//        uint32 bEAutoOn:1;	     //外CAN开启自动允许
//        uint32 bLink:1;	         //联动标识
//        uint32 bUCanChkRec:1;	   //Crt需要显示反馈信息

//        uint32 bEAutoRcv:1;	     //允许接收外CAN开启标识
//        //uint32 bGas1s:1;	     //灭火延时1S

    }Flag;
}tSysRun;


/*******************************************************************/
/****************     公有成员变量,函数及常量     ******************/
/*******************************************************************/
//public:

Ex_CSysRunFlag  void  Init_CSysRunFlag(void);

//100us
Ex_CSysRunFlag  void  Set_CSys100usFlag(void);
Ex_CSysRunFlag  void  Clr_CSys100usFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys100usFlag(void);

//20ms
Ex_CSysRunFlag  void  Set_CSys20msFlag(void);
Ex_CSysRunFlag  void  Clr_CSys20msFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys20msFlag(void);


//100ms
Ex_CSysRunFlag  void  Set_CSys100msFlag(void);
Ex_CSysRunFlag  void  Clr_CSys100msFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys100msFlag(void);


//500ms
Ex_CSysRunFlag  void  Set_CSys500msFlag(void);
Ex_CSysRunFlag  void  Clr_CSys500msFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys500msFlag(void);


//1s
Ex_CSysRunFlag  void  Set_CSys1SFlag(void);
Ex_CSysRunFlag  void  Clr_CSys1SFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys1SFlag(void);

//2s
Ex_CSysRunFlag  void  Set_CSys2SFlag(void);
Ex_CSysRunFlag  void  Clr_CSys2SFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys2SFlag(void);

//5s
Ex_CSysRunFlag  void  Set_CSys5SFlag(void);
Ex_CSysRunFlag  void  Clr_CSys5SFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys5SFlag(void);



//1m
Ex_CSysRunFlag  void  Set_CSys1MFlag(void);
Ex_CSysRunFlag  void  Clr_CSys1MFlag(void);
Ex_CSysRunFlag  uint8 Get_CSys1MFlag(void);













/*******************************************************************/
/********************* 私有成员变量,函数及常量    *******************/
/*******************************************************************/
//Private:
//#define CSysRunFlag_C
#ifdef  CSysRunFlag_C

tSysRun	m_SysRun; //当前时钟

#endif





#endif // SYSCTRL_H
