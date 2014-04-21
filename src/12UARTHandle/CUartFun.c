/*
*********************************************************************************************************
*                                                
*                               对象: CUartFun
*                        (c) Copyright 2010-2018, jxm
*                              All Rights Reserved
*                                    Ver1.0
* File : CUartFun.C
* By   : jxm
* Date : 2012-6-14
*********************************************************************************************************
*/ 
#define   CUartFun_C   
#include  "CUartFun.h" 
// #include  "CExNorFlash.h"  
// #include  "CUart.h"  



//系统初始化函数
void Init_CUartFun(void)
{   
    //uint32 i;
    ///InitBuff_CExNorFlash();
    // 	  vUartSaveAddr=GUI_HZK16_SC_BASE;
    //ClrBk_CExNorFlash(vUartSaveAddr, 0x45080);
    //ClrBk_CExNorFlash(vUartSaveAddr, 0x1000);
    InitBuff_CUartFun();
    vUartRcvBuffRcv=0;
    vUart0SaveFlag=0;
}

//功能初始化
void do_CUartFun(void)
{
    if(vUart0SaveFlag)
    {
        uint32 vRcvLen=0;
        vRcvLen=UARTReceive(_LPC_UART,(uint8*)&vUartRcvBuff[0],vUart0SaveFlag);
        //接收的数据返送回去
        UARTSend(_LPC_UART,(uint8*)&vUartRcvBuff[0],vRcvLen);
        vUartRcvBuffCtrl=vRcvLen;
        if(vRcvLen)
        {
            //Save_CExNorFlash(vUartSaveAddr,(uint8*)&vUartRcvBuff[0],vRcvLen);
            vUartSaveAddr+=vRcvLen>>1;
            InitBuff_CUartFun();
        }
        vUart0SaveFlag=0;
    }

}





void   InitBuff_CUartFun(void)    //初始化
{
    uint32 i;
    for(i=0;i<cMaxUartRcvBuffNum;i++)
    {
        vUartRcvBuff[i]=0xff;
    }
    vUartRcvBuffCtrl=0;
}

void   AddBuff_CUartFun(uint8 vData)
{
    vUartRcvBuff[vUartRcvBuffCtrl++]=vData;
}




