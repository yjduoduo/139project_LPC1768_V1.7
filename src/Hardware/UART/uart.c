/****************************************************************************
 *   $Id:: uart.c 5751 2010-11-30 23:56:11Z usb00423                        $
 *   Project: NXP LPC17xx UART example
 *
 *   Description:
 *     This file contains UART code example which include UART initialization,
 *     UART interrupt handler, and APIs for UART access.
 *
 ****************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
****************************************************************************/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lpc17xx.h"
#include "type.h"
#include "uart.h"
#include  "include.h"
#include  "CComPara.h"
#include  "CTaskSure.h"
#include  "CComHandle.h"
#include "CLpScanCtrl.h"
#include "CFlashParam.h"



#define LPC_UART0_BASE        (LPC_APB0_BASE + 0x0C000)
#define LPC_UART1_BASE        (LPC_APB0_BASE + 0x10000)
#define LPC_UART0             ((LPC_UART0_TypeDef     *) LPC_UART0_BASE    )
#define LPC_UART1             ((LPC_UART1_TypeDef     *) LPC_UART1_BASE    )
#define SERIAL_COM_END				0x05		//serial communication end
#define	SERIAL_COM_START			0xa0		//serial communication start

//串口使用打印
#define TOPRINTF 0x02
#define NOPRINT  0x00


uint8 testann[NODE_BUFSIZE]={0,};
uint8 testann1[10]={0};
uint16 tp3=0;
uint16 tp4=0;
uint8 Save_Ann_flag=0;


uint8 data0[9]={0};
uint8 data2[MAX_COMP+1][55]={0};//汉字注释接收缓存
uint8 data3[12]={0};//存储上位机发送过来的数据
uint8 tp = 0;
uint8 tp1 = 0;
uint8 tp2 = 0;
// uint8 UartTxbuf[9];
uint16 hanzi;
uint8 vAnnCounter=0;










void ClrData3(void)
{
    uint8 i;
    for(i=0;i<12;i++)
        data3[i]=0;
}


void clr_tp(void)
{
    tp =0;
}

uint8 GetCom1Data0(uint8 row)
{
    return	(data0[row]);
}
void ClrCom1Data0(void)
{
    uint8 i;
    for(i=0;i<9;i++)
    {
        data0[i]=0;
    }
}

void AnnCounterInit(void)
{
    //    注释条数
    //    (FLS_NODENUMS_ADR)
    vAnnCounter = M25P80_Read_1Byte(FLS_NODENUMS_ADR);
    if(vAnnCounter == 0xff)
        vAnnCounter = 0;

    Debug("note counter:%d\n",vAnnCounter);
}
//汉字注释数据初始化
void NoteData_Init(void)
{
    uint8 i,j;
    for(i=0;i<MAX_COMP;i++)
    {
        // 	{
        // 		M25P80_Read_Bytes(0x50000,data2[i],sizeof(data2[i]));
        // 	}
        Debug("data2[%d]:",i);
        for(j=0;j<55;j++){
            data2[i][j]=M25P80_Read_1Byte(FLS_NODE_ADR+55*i+j);
            if(data2[i][0] == 0x80)
                Debug("%d ",data2[i][j]);
        }
        Debug("\n");
    }


}

uint8 GetCom0Ann(uint8 row,uint8 cow)
{
    return data2[row][cow];
}


void SetConvertdataAll(void)
{
    SetConvertdata(0,data0[2]);
    SetConvertdata(1,data0[3]);
    SetConvertdata(2,data0[4]);
    SetConvertdata(3,data0[5]);
    SetConvertdata(4,data0[6]);
    SetConvertdata(5,data0[7]);
}

/*****************************************************************************
** Function name:		UART1_IRQHandler
**
** Descriptions:		UART1 interrupt handler
**
** parameters:			None
** Returned value:		None
** 接收感烟或感温探头发送过来的信息，并将信息发送出去

139在主循环中进行接收处理
*****************************************************************************/

#define HEART_WIRELESS (0x38)
#define HEADER_WIRELESS (0x82)


void UART1_IRQHandler(void) 
{
    if(tp<9)
    {
        data0[tp] = U1RBR;
        if(data0[0]==HEADER_WIRELESS)//头文件  data0[]必须在处理后清空
            tp++;
        else
            tp=0;

        if(data0[1]==HEART_WIRELESS)//心跳命令 139w
        {
            tp=0;
            data_from_data0();
            ClrHeartFaultFlag();//清标志

        }
        else if(tp==9)//达到9个字节
        {
            tp=0;
            //            Debug("->>effective info\n");
            data_from_data0();
            if(GetComRegFlag())//部件注册
            {
                SetConvertdataAll();
                UartBindSend(CMD_COMREG,9);//反馈命令给模块
            }
            if(CGetIntenFlag())//部件信号强度
            {
                if(CompareAddr(data0[5],data0[4],data0[3],data0[2],NULL)==0)
                {
                    SetConvertdataAll();
                    UartBindSend(CMD_COMREG,9);
                }
            }
        }

    }
}



uint8 GetAnnFlag(void)
{
    return Save_Ann_flag;
}

uint8 GetAnnRow(/*uint8 dep,*/uint8 comp)
{
    uint8 num =0xff;
    uint8 i;
    for(i=1;i<=MAX_COMP;i++)
    {
        if(/*(data2[i][1]==dep)&&*/(data2[i][2]==comp))
        {
            num = i;
            break;
        }
    }
//    Debug("row is:%d\n",num);
    return num;
}

//中断处只能收数据，不能处理数据，因为数据会丢失
void recv_note_info(void)
{


    testann[tp3]= U0RBR;
    if((testann[tp3]==0x20)&&(tp3>20))//结束标志32
    {
        testann1[0]=testann[tp3];
        tp4=tp3;
    }
    if((testann[tp4+3]==0x6e)&&(testann[tp4+2]==0x0)&&(testann[tp4+1]==0x0))
    {
        tp3=0;
        tp4=0;
        Save_Ann_flag=1;
    }

    Uart0SendByte(testann[tp3],NOPRINT);
    tp3++;
}





/*****************************************************************************
** Function name:		UART0_IRQHandler
**
** Descriptions:		UART0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
*****************************************************************************/

void UART0_IRQHandler (void)
{


    if(Get_Note_Flag())//进入设置即可进行添加注释
    {
//good,single item
        recv_note_info();
    }
    else//处理从上位机上的查询处理
    {
        data3[tp2]=U0RBR;
        if(data3[0]==0xff)
            tp2++;
        else
        {
            tp2=0;
        }

        if(data3[11]==0x83)
        {
            tp2=0;
            SetFlag_195();
            ClrData3();
        }
    }

}



//处理注释，UART0，在设置等页面中即可下载
void HandleNote(void)
{
//good
    uint16 i,j=0;
    uint8 count=0;
    uint8 saveflag=0;
    uint8 comp_pos = 0;
    if(Save_Ann_flag==1)
    {
        for(i=0;i<NODE_BUFSIZE;i++)
        {
            if(testann[i]==0x1f)//31
            {
                testann[i+5]=0x80; //128
                j=i;
            }
            if((testann[i]==0x0)&&(i>j))
                count++;
            else
                count=0;
            if(count==4)
            {
                testann[i-3]=0x87;//135
                count=0;
            }
        }
        for(i=0;i<NODE_BUFSIZE;i++)
        {
            if(testann[i]==0x80)//128
            {
                comp_pos = testann[i+2] ;//存储位置
                if(comp_pos > MAX_COMP)
                    continue;
                if(comp_pos == 0)
                    continue;
                data2[comp_pos][tp1++] = testann[i];
                saveflag=1;
            }
            else if(saveflag==1)
            {
                data2[comp_pos][tp1++] = testann[i];
                if(tp1 >16)//如果超长
                {

                }
                if(testann[i]==0x87)//135
                {
                    //                    vAnnCounter++;
                    tp1=0;
                    saveflag=0;
                }
            }

            //            if(vAnnCounter==MAX_COMP)
            //                vAnnCounter=0;
        }
        for(i=0;i<NODE_BUFSIZE;i++)
            testann[i]=0;
        CSaveAnn();
        Save_Ann_flag=0;
        reset_ok();//复位完成，
        Clr_Note_Flag();//清除下注释标志

    }

}

void CSaveAnn(void)
{
    uint8 i,j;
    //    M25P80_Section_Erase(FLS_NODENUMS_ADR);
    //    M25P80_Write_1Byte(FLS_NODENUMS_ADR,vAnnCounter);
    M25P80_Section_Erase(FLS_NODE_ADR);
    for(i=0;i<MAX_COMP;i++)
        for(j=0;j<55;j++)
            M25P80_Write_1Byte((FLS_NODE_ADR+55*i+j),data2[i][j]);
}



/*****************************************************************************
** Function name:		UARTInit
**
** Descriptions:		Initialize UART port, setup pin select,
**						clock, parity, stop bits, FIFO, etc.
**
** parameters:			portNum(0 or 1) and UART baudrate
** Returned value:		true or false, return false only if the 
**						interrupt handler can't be installed to the 
**						VIC table
** 
*****************************************************************************/
uint32 UARTInit( uint32 PortNum, uint32 baudrate )
{
    uint32 Fdiv;
    uint32 pclkdiv, pclk;

    if ( PortNum == 0 )//Uart0
    {
        PCONP |= (1<<3);
        PINSEL0 &= ~0x000000F0; //p0.2 p0.3 as 0000(clear first,then change)
        PINSEL0 |= 0x00000050;  /* RxD0 is P0.3 and TxD0 is P0.2 */ //5(01 01 as second fun);
        /* By default, the PCLKSELx value is zero, thus, the PCLK for
    all the peripherals is 1/4 of the SystemFrequency. */
        /* Bit 6~7 is for UART0 */
        pclkdiv = (PCLKSEL0 >> 6) & 0x03;
        switch ( pclkdiv )
        {
        case 0x00:
        default:
            pclk = SystemFrequency/4;//12M
            break;
        case 0x01:
            pclk = SystemFrequency;
            break;
        case 0x02:
            pclk = SystemFrequency/2;
            break;
        case 0x03:
            pclk = SystemFrequency/8;
            break;
        }
        Debug("uart0:pclk:%d\n",pclk);

        U0LCR = 0x83;		/* 8 bits, no Parity, 1 Stop bit ,DLAB = 1*/
        Fdiv = ( pclk / 16 ) / baudrate ;	/*baud rate */
        U0DLM = Fdiv / 256;
        U0DLL = Fdiv % 256;
        U0LCR = 0x03;		/* DLAB = 0 禁止除数寄存器重新赋值*/
        U0FCR = 0x07;		/* Enable and reset TX and RX FIFO. */
        // 	U0FCR = 0xa7;		/* Enable and reset TX and RX FIFO 10个字节触发. */
        NVIC_EnableIRQ(UART0_IRQn);

        U0IER = IER_RBR;// | IER_THRE | IER_RLS;	/* Enable UART0 interrupt */


        //    U0IER = IER_RBR | IER_THRE | IER_RLS;

        NVIC_SetPriority(UART0_IRQn, PRIO_FOUR); //中断优先级
        return (TRUE);
    }
    else if ( PortNum == 1 )//Uart1————433接收信号
    {
        PINSEL4 &= ~0x0000000F;  //p2.0,p2.1 as 00
        PINSEL4 |= 0x0000000A;	/* Enable RxD1 P2.1, TxD1 P2.0 as(10 10)*/

        /* By default, the PCLKSELx value is zero, thus, the PCLK for
    all the peripherals is 1/4 of the SystemFrequency. */
        /* Bit 8,9 are for UART1 */
        pclkdiv = (PCLKSEL0 >> 8) & 0x03;
        switch ( pclkdiv )
        {
        case 0x00:
        default:
            pclk = SystemFrequency/4;
            break;
        case 0x01:
            pclk = SystemFrequency;
            break;
        case 0x02:
            pclk = SystemFrequency/2;
            break;
        case 0x03:
            pclk = SystemFrequency/8;
            break;
        }
        Debug("SystemFrequency:%d\n",SystemFrequency);
        Debug("uart1:pclk:%d\n",pclk);
        Debug("uart1:pclk:%010ld\n",pclk);

        U1LCR = 0x83;		/* 8 bits, no Parity, 1 Stop bit */
        Fdiv = ( pclk / 16 ) / baudrate ;	/*baud rate */
        U1DLM = Fdiv / 256;
        U1DLL = Fdiv % 256;
        U1LCR = 0x03;		/* DLAB = 0 */
        U1FCR = 0x07;		/* Enable and reset TX and RX FIFO 1个字节触发. */
        //     U1FCR = 0xe7;		/* Enable and reset TX and RX FIFO e7,14个字节触发. 97,9个字节触发.*/

        NVIC_EnableIRQ(UART1_IRQn);

        U1IER = IER_RBR;//（RBR 使能接收中断） | IER_THRE | IER_RLS;	/* Enable UART1 interrupt */

        //    U1IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART1 interrupt */


        NVIC_SetPriority(UART1_IRQn, PRIO_ONE); //中断优先级

        return (TRUE);
    }
    return( FALSE );
}
void UartIntEnd(void)
{
    NVIC_DisableIRQ(UART0_IRQn);
    NVIC_DisableIRQ(UART1_IRQn);
}


void UartIntStart(void)
{
    U0IER = IER_RBR;
    U1IER = IER_RBR;
    NVIC_EnableIRQ(UART0_IRQn);
    NVIC_SetPriority(UART0_IRQn, PRIO_FOUR); //中断优先级
    NVIC_EnableIRQ(UART1_IRQn);
    NVIC_SetPriority(UART1_IRQn, PRIO_ZERO); //中断优先级
}
void uart_all_disable(void)
{
    NVIC_DisableIRQ(UART0_IRQn);
    NVIC_DisableIRQ(UART1_IRQn);
}
void uart_all_enable(void)
{
    U0IER = IER_RBR;
    U1IER = IER_RBR;
    NVIC_EnableIRQ(UART0_IRQn);
    NVIC_SetPriority(UART0_IRQn, PRIO_FOUR); //中断优先级
    NVIC_EnableIRQ(UART1_IRQn);
    NVIC_SetPriority(UART1_IRQn, PRIO_ZERO); //中断优先级
}

/*****************************************************************************
** Function name:		UARTSend
**
** Descriptions:		Send a block of data to the UART 0 port based
**						on the data length
**
** parameters:			portNum, buffer pointer, and data length
** Returned value:		None
** 
*****************************************************************************/
void UARTSend( uint32 portNum, uint8 *Ptr, uint32 Length  )
{
    if ( portNum == 0 )
    {
        while ( Length != 0 )
        {
            /* THRE status, contain valid data */
            //while ( !(UART0TxEmpty & 0x01) );
            U0THR = *Ptr++;
            //UART0TxEmpty = 0;	/* not empty in the THR until it shifts out */
            //BufferPtr++;
            Length--;
        }
    }
    else
    {
        while ( Length != 0 )
        {
            /* THRE status, contain valid data */
            // while ( !(UART1TxEmpty & 0x01) );
            U1THR =  *Ptr++;
            //UART1TxEmpty = 0;	/* not empty in the THR until it shifts out */
            //BufferPtr++;
            Length--;
        }
    }
    return;
}
/********************************************************************************  
** Descriptions         ：Uart0 Send Data  
**  
** parameters           ：None   
** Returned value       ：None  
*********************************************************************************/  
// uint8 Uart0SendByte(uint8 buf)  
// {  
//     //当检测到UARTn THR已空时，THRE就会立即被设置。写UnTHR会清零THRE
//     //0  -  UnTHR包含有效字符
//     //1  -  UnTHR为空
//     while(!((U0LSR) & 0x20));       //等待判断LSR[5](即THRE)是否是1,1时表示THR中为空

//     //LPC_UART0->THR = buf;

//     return (U0THR = buf);  //发送数据
// }  

uint32 Uart1SendByte(uint32 buf)  
{  
    //当检测到UARTn THR已空时，THRE就会立即被设置。写UnTHR会清零THRE
    //0  -  UnTHR包含有效字符
    //1  -  UnTHR为空
    while(!((U1LSR) & 0x20));       //等待判断LSR[5](即THRE)是否是1,1时表示THR中为空

    //LPC_UART0->THR = buf;

    return (U1THR = buf);  //发送数据
}  
/********************************************************************************
* 函数名称 ：void UART0_SendString (unsigned char *s)
* 函数功能 : 串口0发送字符串
* 入口参数 : unsigned char *s -- 要发送的字符串
* 出口参数 : 无
* 备    注 ：无
*******************************************************************************/
void UART0_SendString (uint8 *s)
{
    while (*s != '\0')
    {
        Uart0SendByte(*s++,NOPRINT);
    }
}
void UART1_SendString (uint8 *s)
{
    while ( *s != 0 )
    {
        Uart1SendByte(*s++);
        //length--;
    }
}

/*********************************************************************************************************
** Function name:	    uart1GetByte
** Descriptions:	    从串口接收1字节数据，使用查询方式接收
** input parameters:    无
** output parameters:   无
** Returned value:      ucRcvData:   接收到的数据
*********************************************************************************************************/
uint32 uart1GetByte (void)
{
    uint32 ucRcvData;
    
    while ((U1LSR & 0x01) == 0);                                        /* 等待接收标志置位             */
    ucRcvData = U1RBR;                                                  /* 读取数据                     */
    return (ucRcvData);
}
uint32 uart0GetByte (void)
{
    uint32 ucRcvData;
    
    while ((U0LSR & 0x01) == 0);                                        /* 等待接收标志置位             */
    ucRcvData = U0RBR;                                                  /* 读取数据                     */
    return (ucRcvData);
}
/*********************************************************************************************************
** Function name:	    uart1GetStr
** Descriptions:	    串口接收字符串
** input parameters:    pucStr:   指向接收数据数组的指针
**                      ulNum:   接收数据的个数
** output parameters:   无
** Returned value:      无
*********************************************************************************************************/
void uart1GetStr (uint32 *pucStr, uint32 ulNum)
{
    for (; ulNum > 0; ulNum--){
        *pucStr++ =  uart1GetByte();
    }
}
void uart0GetStr (uint32_t *pucStr, uint32_t ulNum)
{
    for (; ulNum > 0; ulNum--){
        *pucStr++ =  uart0GetByte();
    }
}


/********************************************************************************  
** Descriptions         ：Uart0 Send Data  
**  
** parameters           ：None   
** Returned value       ：None  
*********************************************************************************/  
static int Uart0SendByte(int buf,uint8 flag)
{  
    //当检测到UARTn THR已空时， THRE就会立即被设置 写UnTHR会清零THRE
    //0  -  UnTHR包含有效字符
    //1  -  UnTHR为空
    if(TOPRINTF == flag)
    {
        if( buf == '\n' )
        {
            while(0 == (U0LSR & (0x20)));
            U0THR = '\r';
        }

    }

    while(0 == (U0LSR & (0x20)));       //等待判断LSR[5](即THRE)是否是1,1时表示THR中为空

    U0THR = buf;                    //发送数据

    return 0;
}  
void puts__(char *s)
{
    while(*s){
        Uart0SendByte(*s,TOPRINTF);
        s++;
    }
}
//调试
#define DEBUGFlag

//void Uart0_printf(char *str,...)
#ifdef DEBUGFlag
char  debugbuf[128];
#endif
void Debug(char *str,...)
{
#ifdef DEBUGFlag
    va_list ptr;
    va_start(ptr,str);
    vsprintf(debugbuf,str,ptr);
    puts__(debugbuf);
    va_end(ptr);
#endif
}




/******************************************************************************
**                            End Of File
******************************************************************************/
