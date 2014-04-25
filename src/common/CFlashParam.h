/*
;*********************************************************************************************************
;*                                                
;*                            对象: CComHandle
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CFlashParam.h
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CFlashParam.h"
#include "config.h"

#ifndef __FlashPara_H 
#define __FlashPara_H

#include    "pcf8563.h"
#include    "CMaDefine.h"
#include  "uart.h"


//存储的左节点，数值加1
#define MAX_ROW MAX_COMP +1


#define PSN_TOTALSIZE MAX_ROW

//for vSendPSNToFlash
#define POS_PSN0        (0)
#define POS_PSN1        (1)
#define POS_PSN2        (2)
#define POS_PSN3        (3)
#define POS_INZONE      (4)
#define POS_PARTNUMBER  (5)
#define POS_DEVTYPE     (6)
#define POS_CIRADDR     (7)

//for vGetDatatoFlash
#define COM_POS_STORENUM    (0) //store nums
#define COM_POS_DEVTYPE     (1) //dev type
#define COM_POS_COMSEL      (2) //selected what?enable,disable,delete or unsound?
#define COM_POS_DEVSTATE    (3)
#define COM_POS_HIYEAR      (4)
#define COM_POS_LOWYEAR     (5)
#define COM_POS_MONTH       (6)
#define COM_POS_DAY         (7)
#define COM_POS_HOUR        (8)
#define COM_POS_MIN         (9)
#define COM_POS_SEC         (10)
#define COM_POS_SIGSTREN    (11)
//#define COM_POS_
//#define COM_POS_
//#define COM_POS_




#ifdef FlashP_c
//100个部件50个防区
uint8 vGetDatatoFlash[MAX_ROW][13]={0};//获得每个部件的详细信息
uint8 vGetDepNum[MAX_ROW]={0};//获得每个防区里的部件总数
uint8 vReadFlashData[16]={0};//读取flash中对应PSN的信息
// 	uint8 vGetCompType[PSN_TOTALSIZE][5]={0};//获得部件的类型
uint8 vGetPsn[PSN_TOTALSIZE][8]={0};//开机就从flash中读取所有PSN和对应的防区号与顺序号
//    uint8 vSendPSNToFlash[PSN_TOTALSIZE][8]={0};//存储PSN到Flash和对应的防区号与顺序号 部件类型 注册地址
uint8 vCirCounter=0;//回路计数
/*
    *历史记录存储
    *该报警部件的存储序号  0  类型1  设置2 报警类型3 报警时间4-10  部件注释的序号11
    */
uint16 vHisCounter=0;//历史记录计数，大于1000从头开始
//uint8 vHisList[MAX_HIST_NUMS][HIST_INFO_LEN]={0};//存储历史记录

uint8 FlashData[MAX_ROW][15]={0};
uint16 vGetCom0Ann[100][8]={0};//获得汉字注释
uint8  vHistFlag=0;//历史记录标志
uint8 vPageCounter=0;//页计数

static PCF8563_DATE history_alarmtime;//历史记录的时间


#endif


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[各个节点缓冲区长度]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//各个内容必须不同，否则有初始化问题
#define ONESIZE (1)
#define BIGSIZE (8)
#define ALARMSIZE (18)/*与HISTSIZE相同了，不行*/
#ifndef test
#define NODESIZE (2)
#else
//#define NODESIZE (55)
#endif
#define HISTSIZE (17)





/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define MAX_HIST_NUMS (1000+1)
#define HIST_LLEN MAX_HIST_NUMS
#define HIST_RLEN HISTSIZE




typedef	union FlashInfoDef
{
    //uint32   id; //地址0-3
    uint8    row;  //该报警部件的存储序号  0
    uint8 	 type;	//类型4/1  0x30 感烟0x31 感温0x32 手报0x33 消报0x34 输入模块0x35 输入输出0x36 声光报警
    uint8	   setup;	//设置5/2
    uint8    alarmtype;//报警类型6/3  0x30正常0x31电池欠压0x32故障0x33火警
    // 	struct//报警时间7-13/4-10
    // 	{
    uint16  year;
    uint8   month;
    uint8   day;
    uint8   hour;
    uint8   minute;
    uint8   second;
    // 	}Time;
    uint8    signal;//信号强度14/11
    uint8    compann;//部件注释的序号15/12
}tFlashinfoDef,*PFlashinfoDef;






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[flash存储结构]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef void (void_fnc_t) (void);
typedef struct Flash_Record{
    uint32 addr;//写的地址
    uint8 (*buf)[ONESIZE];//缓存指针  ---基本信息和历史附加
    uint8 (*bigbuf)[BIGSIZE];//大缓存指针 ——部件
    uint8 (*alarmbuf)[ALARMSIZE];//    ——报警
    uint8 (*nodebuf)[NODESIZE]; //——注释
    uint8 (*histbuf)[HISTSIZE]; //——历史记录
    uint32 llen;//第一维缓存长度
    uint32 rlen;//第二维缓存长度
    void_fnc_t *initfun;//初始化
    void_fnc_t *savefun;//保存
}Flash_Record;



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[报警信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define MAXALARM (MAX_ROW)
#define ALARM_LLEN MAXALARM + 1 /*+1 表示添加一个首警标志*/
#define ALARM_RLEN ALARMSIZE
#define ALARM_FIRST_POS  (51)  /*首警位置*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[报警信息结构]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#define ALARM_NOTFIST (0x00)/*非首警*/
#define ALARM_FIRST   (0x01)/*首警*/
#define ALARM_HAVE    (0x02)/*已有报警*/
#define ALARM_NONE    (0x03) /*未报警*/


typedef struct alarminfo{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 alarmsum;
    uint8 type;
    uint8 alarmed;//是否已经报过警
    PCF8563_DATE dateyear;
    uint8 firstalarm;//是否为首警 --添加
    uint8 attr;//报警属性,  --添加
    uint8 vAnnRow;//注释序列号 --添加
    uint8 f_recvmesat3h;//3hour recv message?
}alarminfo;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史记录信息结构]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct history_st{
    uint8 order;//第几条
    uint8 inzone;
    uint8 part;
    uint8 circleaddr;
    uint8 vAnnRow;//注释序列号
    uint8 attr;//火警，故障，其它信息,【目前启动，屏蔽合并到此】
    uint8 opstype;//操作类型：删除，启动【暂时未用】
    uint8 devtype;//感烟，感光
    uint8 lastnum;//是否最后一条
    PCF8563_DATE dateyear;//时间
}history_st;



typedef struct
{
    uint32 firesum;
    uint32 faultsum;
    uint32 battlowsum;
}tSum;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[部件信息：防区，部件数，回路地址，PSN，时间等]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define COMP_LLEN MAX_ROW
#define COMP_RLEN BIGSIZE
//#ifdef _VAR_CFLASH
//uint8 vSendPSNToFlash[COMP_LLEN][COMP_RLEN]={0,};
//#endif

typedef struct compent{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 psn0;
    uint8 psn1;
    uint8 psn2;
    uint8 psn3;
    uint8 devtype;
}compent;

//所有存储恢复出厂设置后的初始值
#define INITVAL (0xff)
#define ZEROVAL    (0x00)
//2014/04/04 10:56:59
/*****************************************************************************
*author:
*time  :
*****************************************************************************/
void SetHistFlag(uint8 tmp);
uint8 GetHistFlag(void);
//whether is firealarm
uint8 gethistory_isfirealarm(uint32 row);
//whether is battory low
uint8 gethistory_isbatlow(uint32 row);
//whether history is fault
uint8 gethistory_isfault(uint32 row);
void AddPageConter(void);
void SetPageConter(uint8 tmp);
uint8 GetPageConter(void);
void AddHistConter(void);
uint16 GetHistConter(void);
void SetHistConter(uint16 tmp);
//设置历史记录满标志
void setHistFullFlag(uint8 flag);
uint8 getHistFullFlag(void);
//获取历史记录是否为满
uint8 getHistFull(void);
static void init_record(Flash_Record * flash_record);
static void save_record(Flash_Record * flash_record);
//设置存储缓存
static void set_array(Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp);
//获取存储缓存
static uint8 get_array(Flash_Record * flash_record,uint32 row,uint32 col);
void init_basic_info(void);
void set_basic_info(uint32 row,uint8 tmp);
uint8 get_basic_info(uint32 row);
//基本信息具有较高的优先级，需要直接存储
void save_basic_info(void);
//设置部件总数
void set_basic_nums(uint8 compnums);
//add
void add_basic_nums(void);
//sub
void sub_basic_nums(void);
void set_basic_localaddr(uint8 localaddr);
void set_basic_zones(uint8 departallnums);
uint32 get_basic_localaddr(void);
uint32 get_basic_zones(void);
uint32 get_basic_nums(void);
void init_comp_info(void);
void save_comp_info(void);
//设置部件缓存变量
static void set_comp_info(uint32 row,uint32 col,uint8 tmp);
//获取部件缓存变量
static uint8 get_comp_info(uint32 row,uint32 col);
//设置器件的 防区
void set_comp_inzone(uint8 item,uint8 inzone);
//设置器件的 部件
void set_comp_partnumber(uint8 item,uint8 partnumber);
void set_comp_ciraddr(uint8 item,uint8 ciraddr);
void set_comp_psn0(uint8 item,uint8 psn0);
void set_comp_psn1(uint8 item,uint8 psn1);
void set_comp_psn2(uint8 item,uint8 psn2);
void set_comp_psn3(uint8 item,uint8 psn3);
void set_comp_devtype(uint8 item,uint8 devtype);
//设置器件信息
void set_comp_all(uint8 item,compent *compinfo);
//重置所有信息
void clr_comp_all(uint8 item);
//清回路信息
void clr_comp_loop_all(void);
//设置器件信息并保存
void set_comp_all_and_save(uint8 item,compent *compinfo);
//获取
uint8 get_comp_inzone(uint8 item);
uint8 get_comp_partnumber(uint8 item);
uint8 get_comp_ciraddr(uint8 item);
//判断是否有同回路的部件
uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr);
uint8 get_comp_psn0(uint8 item);
uint8 get_comp_psn1(uint8 item);
uint8 get_comp_psn2(uint8 item);
uint8 get_comp_psn3(uint8 item);
uint8 get_comp_devtype(uint8 item);
//获取器件所有信息
void get_comp_all(uint8 item, compent *compinfo);
void init_mask_info(void)/*MaskPSNInit*/;
void save_mask_info(void)/*SaveMaskPSN*/;
void set_mask_info(uint32 row,uint8 tmp);
uint8 get_mask_info(uint32 row)/*CGetMaskPSN*/;
//初始化报警信息
void init_alarm_info(void);
//保存报警信息
void save_alarm_info(void)/**/;
static void set_alarm_info(uint32 row,uint32 col, uint8 tmp);
static uint8 get_alarm_info(uint32 row,uint32 col)/**/;
//获取报警属性
uint8 get_alarm_attr(uint32 row);
uint8 get_alarm_alarmed(uint32 row);
//是否有火警
uint8 judge_alarm_firealarmed(uint32 row);
//是否有故障
uint8 judge_alarm_faultalarmed(uint32 row);
uint8 get_alarm_firstalarm(uint32 row);
//获取报警信息属性列表 list--------------------------
void set_alarm_inzone(uint32 item, uint8 tmp);
void set_alarm_part(uint32 item, uint8 tmp);
void set_alarm_ciraddr(uint32 item, uint8 tmp);
void set_alarm_alarmsum(uint32 item, uint8 tmp);
void set_alarm_type(uint32 item, uint8 tmp);
void set_alarm_alarmed(uint32 item, uint8 tmp);
void set_alarm_firstalarm(uint32 item, uint8 tmp);
void set_alarm_attr(uint32 row, uint8 tmp);
void set_alarm_f_recvmess3h(uint32 item,uint8 flag);
void clr_alarm_f_recvmess3h(uint32 item);
void set_alarm_allinfo(uint32 item,alarminfo *info);
//清除报警信息
void clr_alarm_allinfo(void);
void set_alarm_allinfo_andsave(uint32 item,alarminfo *info);
uint8 get_alarm_part(uint32 item);
uint8 get_alarm_ciraddr(uint32 item);
uint8 get_alarm_type(uint32 item);
//3hour recved message flag?
uint8 get_alarm_f_recvmess3h(uint32 item);
void get_alarm_allinfo(uint32 item, alarminfo *info);
//设置首警
void set_alarm_first(alarminfo *info);
//获取首警
void get_alarm_first(alarminfo *info);
//首警标志
uint8 get_alarm_firstflag(void);
//首警部件号
uint8 get_alarm_first_part(void);
//火警个数
uint8 get_firealarm_nums(void);
void clr_firealarm(void);
//通过部件号查找位置
uint8 get_alarm_item_bypart(uint8 part);
//故障个数
uint8 get_faultalarm_nums(void);
//是否为首警
uint8 judge_alarm_first(void);
void init_node_info(void)/*Com0Data_Init*/;
void save_node_info(void);
//设置部件缓存变量
void set_node_info(uint32 row,uint32 col,uint8 tmp);
//获取部件缓存变量
uint8 get_node_info(uint32 row,uint32 col);
//}
int8 get_node_row(/*uint8 dep,*/uint8 comp);
void save_node_and_nodenums(void)/*CSaveAnn*/;
//初始化注释条数
void init_nodenums_info(void)/*AnnCounterInit*/;
//保存注释条数到flash
void save_nodenums_info(void);
void set_nodenums(uint8 tmp);
uint8 get_nodenums(void);
void add_nodenums(void);
void init_hist_info(void)/*GetHistory*/;
void save_hist_info(void)/*SendHistToFlash*/;
//获取历史记录信息
static uint8 get_hist_info(uint32 row,uint8 col)/*GetHistoryList*/;
void set_hist_info(uint32 row,uint8 col,uint8 tmp)/*SetHistoryList*/;
void clr_hist_info(void) /*ClrHistoryList*/;
uint8 get_hist_order(uint32 row)/*gethistory_num*/;
uint8 get_hist_inzone(uint32 row)/*gethistory_num*/;
uint8 get_hist_part(uint32 row)/*gethistory_num*/;
uint8 get_hist_circleaddr(uint32 row)/*gethistory_num*/;
uint8 get_hist_vAnnRow(uint32 row)/*gethistory_num*/;
uint8 get_hist_attr(uint32 row)/*gethistory_num*/;
uint8 get_hist_opstype(uint32 row)/*gethistory_num*/;
uint8 get_hist_devtype(uint32 row)/*gethistory_devtype*/;
uint8 get_hist_lastnum(uint32 row)/*gethistory_num*/;
//获取历史记录时间
void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear)/*gethistory_num*/;
//获取历史记录的所有信息
void get_hist_allinfo(uint32 row, history_st* info);
//设置历史记录所有信息
void set_hist_allinfo(uint32 row, history_st* info);
//保存历史记录和历史条数
void save_hist_all(void);
//历史记录是否为满，置位标志get_histnum_info(2)
uint8 judge_histnums_full(void);
//设置历史记录为满
void set_histnum_full(void);
//初始化历史条数
void init_histnums_info(void)/*InitHistInfo*/;
void save_histnums_info(void)/*flash_save_historycounter*/;
//设置缓存
static void set_histnum_info(uint32 row,uint8 tmp);
//获取缓存
static uint8 get_histnum_info(uint32 row);
//初始化历史记录和历史条数
void init_hist_and_histnums(void);
void init_histsufix_info(void);
//初始化所有存储
void init_flash_all(void);
//}
uint8 CheckDepComp(uint8 dep,uint8 comp);
//}
int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3);
void CAddCirCounter(void);
void CSetCirCounter(uint8 tmp);
uint8 CGetCirCounter(void);
int8 GetRow(uint8 t1,uint8 t2);
/////判断是否有报火警，有 0，无 1/////是否之前有火警
uint8 JudgeAlarmType(void);
uint8 JudgeCompAlarmType(uint8 row);
void SetDatatoFlash(uint8 row,uint8 col,uint8 tmp);
uint8 GetDatatoFlash(uint8 row,uint8 col);
//}
uint8 GetDatatoFlashType(uint8 row);
uint8 GetDatatoFlashAlarmType(uint8 row);
void SetFlashData(uint8 id,uint8 tmp);
void SetDepCompSum(uint16 temp,uint8 tmp);
uint8 GetDepCompSum(uint16 tmp);
//}
uint8 ReadFlashPsn(uint8 row,uint8 col);
void SetCom0Ann(uint8 row,uint8 cow,uint8 tmp);
//设置所有注释信息
void set_node_all_info(uint32 row,note_info_t *info);



#endif /* end __FlashPara_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/


