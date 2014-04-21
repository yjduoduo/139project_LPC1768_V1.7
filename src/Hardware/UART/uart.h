/****************************************************************************
 *   $Id:: uart.h 5751 2010-11-30 23:56:11Z usb00423                        $
 *   Project: NXP LPC17xx UART example
 *
 *   Description:
 *     This file contains UART code header definition.
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
#include "config.h"

#ifndef __UART_H 
#define __UART_H




#define IER_RBR		0x01//接收中断
#define IER_THRE	0x02
#define IER_RLS		0x04

#define IIR_PEND	0x01
#define IIR_RLS		0x03
#define IIR_RDA		0x02
#define IIR_CTI		0x06
#define IIR_THRE	0x01

#define LSR_RDR		0x01
#define LSR_OE		0x02
#define LSR_PE		0x04
#define LSR_FE		0x08
#define LSR_BI		0x10
#define LSR_THRE	0x20
#define LSR_TEMT	0x40
#define LSR_RXFE	0x80

#define BUFSIZE		0x40



/*把所有数据全部集中收集到一块，再处理*/
#define NODE_BUFSIZE  2000/*45*//*2000*///3+2+1+ 32字符（16汉字）



/***************************************************/

typedef struct note_info_t
{
    uint8 frame1;
    uint8 frame2;
    uint8 frame3;
    uint8 cmd1;
    uint8 cmd_rw;
    uint8 devtype;
    uint8 targetaddr;
    uint8 controllernum;
    uint8 datelen;
    uint8 loop;
    uint8 addr;
    uint8 hz[32];
    uint8 cs[2];
}note_info_t;


/***************************************************/

// #define	UART_COM_FLAG		0x82  // 头文件
// #define	UART_COM_TAIL		0x83  // 文件尾
// #define	UART_DATA_ADDR		0x03  //
// #define	CMD_PANT		0x3131	//心跳
// #define	CMD_BROADCAST_M		0x3730	//广播
// #define	CMD_DEF_ADDR_M		0x3731	//编址确认
// #define	CMD_RD_STATUS_M		0x3732	//读模块状态
// #define	CMD_RD_ANA_M		0x3733	//读模拟量
// #define	CMD_RST_M		0x3734	//复位传感器
// #define CMD_DIS_M		0x3735	//禁用传感器
// #define	CMD_EN_M		0x3736	//启用传感器
// #define	CMD_ADDR_UP_M		0x3737	//部件上报地址码
// #define	CMD_RSSI_M		0x3738	//接受信号强度
// #define	CMD_STATUS_M		0x3739	//接受模块状态
void ClrData3(void);

extern void NoteData_Init(void);
extern uint8 GetCom0Ann(uint8 row,uint8 cow);
extern uint8 GetAnnRow(/*uint8 dep,*/uint8 comp);
extern void ClrCom1Data0(void);
extern void clr_tp(void);
extern uint8 GetCom1Data0(uint8 row);
void CSaveAnn(void);
void AnnCounterInit(void);
extern uint32 UARTInit( uint32 portNum, uint32 Baudrate );
extern void UartIntEnd(void);
extern void UartIntStart(void);
extern void UART0_IRQHandler( void );
extern void UART1_IRQHandler( void );
extern void UARTSend(uint32 portNum, uint8 *Ptr, uint32 Length);
extern uint32 uart1GetByte (void);
extern void uart1GetStr (uint32 *pucStr, uint32 ulNum);

static int Uart0SendByte(int buf, uint8 flag) ;
// extern uint8 Uart0SendByte(uint8 buf) ;
extern uint32 Uart1SendByte(uint32 buf) ;
extern void UART0_SendString (uint8 *s);
extern void UART1_SendString (uint8 *s);
uint8 GetAnnFlag(void);
void HandleNote(void);
void SaveAnnFun(void);
void puts__(char *s);
void lcd_printf(char *str,...);

void uart_all_disable(void);
void uart_all_enable(void);

void SetConvertdataAll(void);

void set_note_info(note_info_t *info);

//void convert_noteinfo(note_info_t* info,uint8* array);


//uint8 * get_ann(void);


void add_note_nums(void);
void add_note_size(void);
void check_note_nums(void);
void check_note_size(void);
void reset_note_buf(uint8 notenum);
void set_note_buf(uint8 notenum, uint8 note_size, uint8 val);
void print_note_buf(void);





/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/***************************************************/
/************create another file*******************/



//#include "include.h"


/**
 * IO definitions
 *
 * define access restrictions to peripheral registers
 */

#ifdef __cplusplus
#define     __I     volatile                  /*!< defines 'read only' permissions      */
#else
#define     __I     volatile const            /*!< defines 'read only' permissions      */
#endif
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */





/* Public Macros -------------------------------------------------------------- */
/** @defgroup UART_Public_Macros  UART Public Macros
 * @{
 */

/** UART time-out definitions in case of using Read() and Write function
 * with Blocking Flag mode
 */
#define UART_BLOCKING_TIMEOUT			(0xFFFFFFFFUL)

/**
 * @}
 */

/* Private Macros ------------------------------------------------------------- */
/** @defgroup UART_Private_Macros UART Private Macros
 * @{
 */

/* Accepted Error baud rate value (in percent unit) */
#define UART_ACCEPTED_BAUDRATE_ERROR	(3)			/*!< Acceptable UART baudrate error */


/* --------------------- BIT DEFINITIONS -------------------------------------- */
/*********************************************************************//**
 * Macro defines for Macro defines for UARTn Receiver Buffer Register
 **********************************************************************/
/** UART Received Buffer mask bit (8 bits) */
#define UART_RBR_MASKBIT   	((uint8_t)0xFF)

/*********************************************************************//**
 * Macro defines for Macro defines for UARTn Transmit Holding Register
 **********************************************************************/
/** UART Transmit Holding mask bit (8 bits) */
#define UART_THR_MASKBIT   	((uint8_t)0xFF)

/*********************************************************************//**
 * Macro defines for Macro defines for UARTn Divisor Latch LSB register
 **********************************************************************/
/** Macro for loading least significant halfs of divisors */
#define UART_LOAD_DLL(div)	((div) & 0xFF)
/** Divisor latch LSB bit mask */
#define UART_DLL_MASKBIT	((uint8_t)0xFF)

/*********************************************************************//**
 * Macro defines for Macro defines for UARTn Divisor Latch MSB register
 **********************************************************************/
/** Divisor latch MSB bit mask */
#define UART_DLM_MASKBIT	((uint8_t)0xFF)
/** Macro for loading most significant halfs of divisors */
#define UART_LOAD_DLM(div)  (((div) >> 8) & 0xFF)

/*********************************************************************//**
 * Macro defines for Macro defines for UART interrupt enable register
 **********************************************************************/
/** RBR Interrupt enable*/
#define UART_IER_RBRINT_EN		((uint32_t)(1<<0))
/** THR Interrupt enable*/
#define UART_IER_THREINT_EN		((uint32_t)(1<<1))
/** RX line status interrupt enable*/
#define UART_IER_RLSINT_EN		((uint32_t)(1<<2))
/** Modem status interrupt enable */
#define UART1_IER_MSINT_EN		((uint32_t)(1<<3))
/** CTS1 signal transition interrupt enable */
#define UART1_IER_CTSINT_EN		((uint32_t)(1<<7))
/** Enables the end of auto-baud interrupt */
#define UART_IER_ABEOINT_EN		((uint32_t)(1<<8))
/** Enables the auto-baud time-out interrupt */
#define UART_IER_ABTOINT_EN		((uint32_t)(1<<9))
/** UART interrupt enable register bit mask */
#define UART_IER_BITMASK		((uint32_t)(0x307))
/** UART1 interrupt enable register bit mask */
#define UART1_IER_BITMASK		((uint32_t)(0x38F))

/*********************************************************************//**
 * Macro defines for Macro defines for UART interrupt identification register
 **********************************************************************/
/** Interrupt Status - Active low */
#define UART_IIR_INTSTAT_PEND	((uint32_t)(1<<0))
/** Interrupt identification: Receive line status*/
#define UART_IIR_INTID_RLS		((uint32_t)(3<<1))
/** Interrupt identification: Receive data available*/
#define UART_IIR_INTID_RDA		((uint32_t)(2<<1))
/** Interrupt identification: Character time-out indicator*/
#define UART_IIR_INTID_CTI		((uint32_t)(6<<1))
/** Interrupt identification: THRE interrupt*/
#define UART_IIR_INTID_THRE		((uint32_t)(1<<1))
/** Interrupt identification: Modem interrupt*/
#define UART1_IIR_INTID_MODEM	((uint32_t)(0<<1))
/** Interrupt identification: Interrupt ID mask */
#define UART_IIR_INTID_MASK		((uint32_t)(7<<1))
/** These bits are equivalent to UnFCR[0] */
#define UART_IIR_FIFO_EN		((uint32_t)(3<<6))
/** End of auto-baud interrupt */
#define UART_IIR_ABEO_INT		((uint32_t)(1<<8))
/** Auto-baud time-out interrupt */
#define UART_IIR_ABTO_INT		((uint32_t)(1<<9))
/** UART interrupt identification register bit mask */
#define UART_IIR_BITMASK		((uint32_t)(0x3CF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART FIFO control register
 **********************************************************************/
/** UART FIFO enable */
#define UART_FCR_FIFO_EN		((uint8_t)(1<<0))
/** UART FIFO RX reset */
#define UART_FCR_RX_RS			((uint8_t)(1<<1))
/** UART FIFO TX reset */
#define UART_FCR_TX_RS			((uint8_t)(1<<2))
/** UART DMA mode selection */
#define UART_FCR_DMAMODE_SEL 	((uint8_t)(1<<3))
/** UART FIFO trigger level 0: 1 character */
#define UART_FCR_TRG_LEV0		((uint8_t)(0))
/** UART FIFO trigger level 1: 4 character */
#define UART_FCR_TRG_LEV1		((uint8_t)(1<<6))
/** UART FIFO trigger level 2: 8 character */
#define UART_FCR_TRG_LEV2		((uint8_t)(2<<6))
/** UART FIFO trigger level 3: 14 character */
#define UART_FCR_TRG_LEV3		((uint8_t)(3<<6))
/** UART FIFO control bit mask */
#define UART_FCR_BITMASK		((uint8_t)(0xCF))

#define UART_TX_FIFO_SIZE		(16)

/*********************************************************************//**
 * Macro defines for Macro defines for UART line control register
 **********************************************************************/
/** UART 5 bit data mode */
#define UART_LCR_WLEN5     		((uint8_t)(0))
/** UART 6 bit data mode */
#define UART_LCR_WLEN6     		((uint8_t)(1<<0))
/** UART 7 bit data mode */
#define UART_LCR_WLEN7     		((uint8_t)(2<<0))
/** UART 8 bit data mode */
#define UART_LCR_WLEN8     		((uint8_t)(3<<0))
/** UART Two Stop Bits Select */
#define UART_LCR_STOPBIT_SEL	((uint8_t)(1<<2))
/** UART Parity Enable */
#define UART_LCR_PARITY_EN		((uint8_t)(1<<3))
/** UART Odd Parity Select */
#define UART_LCR_PARITY_ODD		((uint8_t)(0))
/** UART Even Parity Select */
#define UART_LCR_PARITY_EVEN	((uint8_t)(1<<4))
/** UART force 1 stick parity */
#define UART_LCR_PARITY_F_1		((uint8_t)(2<<4))
/** UART force 0 stick parity */
#define UART_LCR_PARITY_F_0		((uint8_t)(3<<4))
/** UART Transmission Break enable */
#define UART_LCR_BREAK_EN		((uint8_t)(1<<6))
/** UART Divisor Latches Access bit enable */
#define UART_LCR_DLAB_EN		((uint8_t)(1<<7))
/** UART line control bit mask */
#define UART_LCR_BITMASK		((uint8_t)(0xFF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART1 Modem Control Register
 **********************************************************************/
/** Source for modem output pin DTR */
#define UART1_MCR_DTR_CTRL		((uint8_t)(1<<0))
/** Source for modem output pin RTS */
#define UART1_MCR_RTS_CTRL		((uint8_t)(1<<1))
/** Loop back mode select */
#define UART1_MCR_LOOPB_EN		((uint8_t)(1<<4))
/** Enable Auto RTS flow-control */
#define UART1_MCR_AUTO_RTS_EN	((uint8_t)(1<<6))
/** Enable Auto CTS flow-control */
#define UART1_MCR_AUTO_CTS_EN	((uint8_t)(1<<7))
/** UART1 bit mask value */
#define UART1_MCR_BITMASK		((uint8_t)(0x0F3))

/*********************************************************************//**
 * Macro defines for Macro defines for UART line status register
 **********************************************************************/
/** Line status register: Receive data ready*/
#define UART_LSR_RDR		((uint8_t)(1<<0))
/** Line status register: Overrun error*/
#define UART_LSR_OE			((uint8_t)(1<<1))
/** Line status register: Parity error*/
#define UART_LSR_PE			((uint8_t)(1<<2))
/** Line status register: Framing error*/
#define UART_LSR_FE			((uint8_t)(1<<3))
/** Line status register: Break interrupt*/
#define UART_LSR_BI			((uint8_t)(1<<4))
/** Line status register: Transmit holding register empty*/
#define UART_LSR_THRE		((uint8_t)(1<<5))
/** Line status register: Transmitter empty*/
#define UART_LSR_TEMT		((uint8_t)(1<<6))
/** Error in RX FIFO*/
#define UART_LSR_RXFE		((uint8_t)(1<<7))
/** UART Line status bit mask */
#define UART_LSR_BITMASK	((uint8_t)(0xFF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART Modem (UART1 only) status register
 **********************************************************************/
/** Set upon state change of input CTS */
#define UART1_MSR_DELTA_CTS		((uint8_t)(1<<0))
/** Set upon state change of input DSR */
#define UART1_MSR_DELTA_DSR		((uint8_t)(1<<1))
/** Set upon low to high transition of input RI */
#define UART1_MSR_LO2HI_RI		((uint8_t)(1<<2))
/** Set upon state change of input DCD */
#define UART1_MSR_DELTA_DCD		((uint8_t)(1<<3))
/** Clear To Send State */
#define UART1_MSR_CTS			((uint8_t)(1<<4))
/** Data Set Ready State */
#define UART1_MSR_DSR			((uint8_t)(1<<5))
/** Ring Indicator State */
#define UART1_MSR_RI			((uint8_t)(1<<6))
/** Data Carrier Detect State */
#define UART1_MSR_DCD			((uint8_t)(1<<7))
/** MSR register bit-mask value */
#define UART1_MSR_BITMASK		((uint8_t)(0xFF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART Scratch Pad Register
 **********************************************************************/
/** UART Scratch Pad bit mask */
#define UART_SCR_BIMASK		((uint8_t)(0xFF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART Auto baudrate control register
 **********************************************************************/
/** UART Auto-baud start */
#define UART_ACR_START				((uint32_t)(1<<0))
/** UART Auto baudrate Mode 1 */
#define UART_ACR_MODE				((uint32_t)(1<<1))
/** UART Auto baudrate restart */
#define UART_ACR_AUTO_RESTART		((uint32_t)(1<<2))
/** UART End of auto-baud interrupt clear */
#define UART_ACR_ABEOINT_CLR		((uint32_t)(1<<8))
/** UART Auto-baud time-out interrupt clear */
#define UART_ACR_ABTOINT_CLR		((uint32_t)(1<<9))
/** UART Auto Baudrate register bit mask */
#define UART_ACR_BITMASK			((uint32_t)(0x307))

/*********************************************************************//**
 * Macro defines for Macro defines for UART IrDA control register
 **********************************************************************/
/** IrDA mode enable */
#define UART_ICR_IRDAEN			((uint32_t)(1<<0))
/** IrDA serial input inverted */
#define UART_ICR_IRDAINV		((uint32_t)(1<<1))
/** IrDA fixed pulse width mode */
#define UART_ICR_FIXPULSE_EN	((uint32_t)(1<<2))
/** PulseDiv - Configures the pulse when FixPulseEn = 1 */
#define UART_ICR_PULSEDIV(n)	((uint32_t)((n&0x07)<<3))
/** UART IRDA bit mask */
#define UART_ICR_BITMASK		((uint32_t)(0x3F))

/*********************************************************************//**
 * Macro defines for Macro defines for UART Fractional divider register
 **********************************************************************/
/** Baud-rate generation pre-scaler divisor */
#define UART_FDR_DIVADDVAL(n)	((uint32_t)(n&0x0F))
/** Baud-rate pre-scaler multiplier value */
#define UART_FDR_MULVAL(n)		((uint32_t)((n<<4)&0xF0))
/** UART Fractional Divider register bit mask */
#define UART_FDR_BITMASK		((uint32_t)(0xFF))

/*********************************************************************//**
 * Macro defines for Macro defines for UART Tx Enable register
 **********************************************************************/
/** Transmit enable bit */
#define UART_TER_TXEN			((uint8_t)(1<<7))
/** UART Transmit Enable Register bit mask */
#define UART_TER_BITMASK		((uint8_t)(0x80))

/*********************************************************************//**
 * Macro defines for Macro defines for UART1 RS485 Control register
 **********************************************************************/
/** RS-485/EIA-485 Normal Multi-drop Mode (NMM) is disabled */
#define UART1_RS485CTRL_NMM_EN		((uint32_t)(1<<0))
/** The receiver is disabled */
#define UART1_RS485CTRL_RX_DIS		((uint32_t)(1<<1))
/** Auto Address Detect (AAD) is enabled */
#define UART1_RS485CTRL_AADEN		((uint32_t)(1<<2))
/** If direction control is enabled (bit DCTRL = 1), pin DTR is used for direction control */
#define UART1_RS485CTRL_SEL_DTR		((uint32_t)(1<<3))
/** Enable Auto Direction Control */
#define UART1_RS485CTRL_DCTRL_EN	((uint32_t)(1<<4))
/** This bit reverses the polarity of the direction control signal on the RTS (or DTR) pin.
The direction control pin will be driven to logic "1" when the transmitter has data to be sent */
#define UART1_RS485CTRL_OINV_1		((uint32_t)(1<<5))

/** RS485 control bit-mask value */
#define UART1_RS485CTRL_BITMASK		((uint32_t)(0x3F))

/*********************************************************************//**
 * Macro defines for Macro defines for UART1 RS-485 Address Match register
 **********************************************************************/
#define UART1_RS485ADRMATCH_BITMASK ((uint8_t)(0xFF)) 	/**< Bit mask value */

/*********************************************************************//**
 * Macro defines for Macro defines for UART1 RS-485 Delay value register
 **********************************************************************/
/* Macro defines for UART1 RS-485 Delay value register */
#define UART1_RS485DLY_BITMASK		((uint8_t)(0xFF)) 	/** Bit mask value */

/*********************************************************************//**
 * Macro defines for Macro defines for UART FIFO Level register
 **********************************************************************/
/** Reflects the current level of the UART receiver FIFO */
#define UART_FIFOLVL_RXFIFOLVL(n)	((uint32_t)(n&0x0F))
/** Reflects the current level of the UART transmitter FIFO */
#define UART_FIFOLVL_TXFIFOLVL(n)	((uint32_t)((n>>8)&0x0F))
/** UART FIFO Level Register bit mask */
#define UART_FIFOLVL_BITMASK		((uint32_t)(0x0F0F))


/**
 * @}
 */

/**
 * @}
 */




/* buffer size definition */
#define UART_RING_BUFSIZE  256

/* Buf mask */
#define __BUF_MASK (UART_RING_BUFSIZE-1)
/* Check buf is full or not */
#define __BUF_IS_FULL(head, tail) ((tail&__BUF_MASK)==((head+1)&__BUF_MASK))
/* Check buf will be full in next receiving or not */
#define __BUF_WILL_FULL(head, tail) ((tail&__BUF_MASK)==((head+2)&__BUF_MASK))
/* Check buf is empty */
#define __BUF_IS_EMPTY(head, tail) ((head&__BUF_MASK)==(tail&__BUF_MASK))
/* Reset buf */
#define __BUF_RESET(bufidx)	(bufidx=0)
#define __BUF_INCR(bufidx)	(bufidx=(bufidx+1)&__BUF_MASK)



typedef struct
{
    __IO uint32 tx_head;                /*!< UART Tx ring buffer head index */
    __IO uint32 tx_tail;                /*!< UART Tx ring buffer tail index */
    __IO uint32 rx_head;                /*!< UART Rx ring buffer head index */
    __IO uint32 rx_tail;                /*!< UART Rx ring buffer tail index */
    __IO uint8  tx[UART_RING_BUFSIZE];  /*!< UART Tx data ring buffer */
    __IO uint8  rx[UART_RING_BUFSIZE];  /*!< UART Rx data ring buffer */
} UART_RING_BUFFER_T;
















typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;




#define	SERIAL_ARRAY_LEN		0x100		//the lengtn of the data whitch communication with computer

#define	UART_RDR				0x01
#define	UART_THRE				0x20

#define	NOTE_BUF_LEN			0x100


//the defination relate to serial frame
#define	SERIAL_HEAD_LEN			0x0b
#define	SERIAL_TIAL_LEN			0x2e
#define	SERIAL_HEAD_BYTE		0xff		//the head byte of a frame



/**********************************************************************************************************
*                                         GLOBAL VARIABLES
**********************************************************************************************************/
typedef struct{
    unsigned short len;									/* send length      */
    unsigned short num;									/* already send	num */
    unsigned char senden;
    unsigned char datarray[SERIAL_ARRAY_LEN];			/* send data        */
}TdUartSend;

typedef struct{
    unsigned char clrlen;								/* clear data length*/
    unsigned char datarray[SERIAL_ARRAY_LEN];			/* send data        */
}TdUartRcv;




#endif /* end __UART_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/
