/*
;*********************************************************************************************************
;*
;*                            对象: CComHandle
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CFlashParam.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;





working====================
2014/02/14 09:28:56
139flash配置
存储设置的基本信息
M25P80_Section_Erase(0x00000);
存储PSN数组
M25P80_Section_Erase(0x10000);
存储屏蔽序号
;;M25P80_Section_Erase(0x20000);
存储报警信息
M25P80_Section_Erase(0x30000);
存储历史记录
M25P80_Section_Erase(FLS_HIST_ADR);
M25P80_Section_Erase(0x80000);
存储注释
M25P80_Section_Erase(0x50000);
存储历史记录的计数
((M25P80_Read_1Byte(0x60000)<<8)+(M25P80_Read_1Byte(0x60001)))

注释条数
M25P80_Section_Erase(0x70000)
*/
#define FlashP_c
#include "include.h"
#define _VAR_CFLASH
#include  "CFlashParam.h"
#include  "CComHandle.h"
#include  "CLpScanCtrl.h"
#include  "CTaskSure.h"
#include  "CNodeInfo.h"



#define ADDRINVALID (-1)








void SetHistFlag(uint8 tmp)
{
    vHistFlag=tmp;
}
uint8 GetHistFlag(void)
{
    return vHistFlag;
}



//PCF8563_DATE gethistory_alarmtime(uint32 row)
//{
//    history_alarmtime.year=0;
//    history_alarmtime.month=0;
//    history_alarmtime.day=0;
//    history_alarmtime.hour=0;
//    history_alarmtime.minute=0;
//    history_alarmtime.second=0;
//    if(row < MAX_HIST_NUMS){
//        history_alarmtime.year=(gethistory_highyear(row)<<8)+gethistory_lowyear(row);
//        history_alarmtime.month=gethistory_month(row);
//        history_alarmtime.day=gethistory_day(row);
//        history_alarmtime.hour=gethistory_hour(row);
//        history_alarmtime.minute=gethistory_min(row);
//        history_alarmtime.second=gethistory_sec(row);

//    }
//    return history_alarmtime;
//}


//whether is firealarm
uint8 gethistory_isfirealarm(uint32 row)
{
    if(ATTR_FIRE == get_hist_attr(row))
        return TRUE;
    else
        return FALSE;
}
//whether is battory low
uint8 gethistory_isbatlow(uint32 row)
{
    if(ATTR_BAT_LOW == get_hist_attr(row))
        return TRUE;
    else
        return FALSE;
}
//whether history is fault
uint8 gethistory_isfault(uint32 row)
{
    if(ATTR_FAULT == get_hist_attr(row))
        return TRUE;
    else
        return FALSE;
}

void AddPageConter(void)
{
    vPageCounter++;
}
void SetPageConter(uint8 tmp)
{
    vPageCounter=tmp;
}
uint8 GetPageConter(void)
{
    return vPageCounter;
}

void AddHistConter(void)
{
    vHisCounter++;
}
uint16 GetHistConter(void)
{
    return vHisCounter;
}
void SetHistConter(uint16 tmp)
{
    vHisCounter = tmp;
}





/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史附加信息，历史附加信息]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
////////////////////////////////////////////////////
//历史记录满否
////////////////////////////////////////////////////

#define HIST_FULL_POS       (0) //满标志存放位置
#define HIST_LAST_ADDR      (1) //历史记录最后地址的位置


#define MAX_HIST_SUFIX_LLEN (10) //定义的历史附加信息存储最大数
#define MAX_HIST_SUFIX_RLEN ONESIZE
static uint8 vHistSufixInfo[MAX_HIST_SUFIX_LLEN][MAX_HIST_SUFIX_RLEN]={0,};
//历史记录满标志各种状态
#define DHISTFULLFLAG    (1)
#define DHISTNOTFULLFLAG (0)
#define DHISTINVALIDFLAG (0xff)
//设置历史记录满标志
void setHistFullFlag(uint8 flag)
{
    vHistSufixInfo[HIST_FULL_POS][0] = flag;
}
uint8 getHistFullFlag(void)
{
    return vHistSufixInfo[HIST_FULL_POS][0];
}
//获取历史记录是否为满
uint8 getHistFull(void)
{
    if(DHISTFULLFLAG == getHistFullFlag())
        return 1;
    else
        return 0;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[基本信息]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define BASE_LLEN 256/*203*/
#define BASE_RLEN ONESIZE

static uint8 BaseInfoF[BASE_LLEN][BASE_RLEN]={0,};//基本设置参数缓存





/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[部件存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#define COMP_SINGLESIZE 8
#ifdef _VAR_CFLASH
static uint8 vSendPSNToFlash[COMP_LLEN][COMP_RLEN]={0,};
#endif



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[屏蔽存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//屏蔽数组
#define  MASK_LLEN MAX_ROW
#define  MASK_RLEN ONESIZE
static uint8 vMaskPSN[MASK_LLEN][MASK_RLEN] = {0,};







/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[报警信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//#define MAXALARM (MAX_ROW)
//#define ALARM_LLEN MAXALARM
//#define ALARM_RLEN ALARMSIZE

static uint8 AlarmInfo[ALARM_LLEN][ALARM_RLEN]={INITVAL,};



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[注释信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#if 0
#define NODE_LLEN MAX_COMP+1
#define NODE_RLEN NODESIZE
#else
#define NODE_LLEN 1
#define NODE_RLEN NODESIZE
#endif
static uint8 data_note[NODE_LLEN][NODE_RLEN]={0,};


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[注释条数信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define NODENUMS_LLEN ONESIZE
#define NODENUMS_RLEN ONESIZE

static uint8 vAnnCounter[NODENUMS_LLEN][NODENUMS_RLEN]={0,};




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//#define MAX_HIST_NUMS (1000)
//#define HIST_LLEN MAX_HIST_NUMS
//#define HIST_RLEN HISTSIZE

static uint8 vHisList[HIST_LLEN][HIST_RLEN]={0,};//存储历史记录




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史条数信息存储内容结点]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define HISTNUMS_LLEN 3
#define HISTNUMS_RLEN ONESIZE
static uint8 vHisC[HISTNUMS_LLEN][HISTNUMS_RLEN] = {0,};




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[flash存储结构]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

static const Flash_Record flash_record[]={
    {FLS_BASEINFO_ADR, BaseInfoF ,0,             0,         0,      0, BASE_LLEN,      BASE_RLEN,},
    {FLS_COMPINFO_ADR, 0,        vSendPSNToFlash,0,         0,      0, COMP_LLEN,      COMP_RLEN, },
    {FLS_MASKINFO_ADR, vMaskPSN, 0,              0,         0,      0, MASK_LLEN,      MASK_RLEN, },
    {FLS_ALARMINFO_ADR,0,        0,              AlarmInfo, 0,      0, ALARM_LLEN,     ALARM_RLEN,},
    {FLS_NODE_ADR,     0,        0,              0,         data_note,  0, NODE_LLEN,      NODE_RLEN,    },
    {FLS_NODENUMS_ADR, vAnnCounter, 0,           0,         0,      0, NODENUMS_LLEN,  NODENUMS_RLEN,},
    {FLS_HIST_ADR,     0,        0,              0,         0,     vHisList, HIST_LLEN, HIST_RLEN,},
    {FLS_HISTNUMS_ADR, vHisC,    0,              0,         0,      0, HISTNUMS_LLEN,  HISTNUMS_RLEN,  },
    {FLS_HIST_SUFIX_ADR, vHistSufixInfo,0 ,      0,         0,      0, MAX_HIST_SUFIX_LLEN,MAX_HIST_SUFIX_RLEN,},//历史记录附加信息
    {0,}
};

const static Flash_Record * basic_record = &flash_record[0];
const static Flash_Record * comp_record = &flash_record[1];
const static Flash_Record * mask_record = &flash_record[2];
const static Flash_Record * alarm_record = &flash_record[3];
const static Flash_Record * node_record = &flash_record[4];
const static Flash_Record * nodenums_record = &flash_record[5];
const static Flash_Record * hist_record = &flash_record[6];
const static Flash_Record * histnums_record = &flash_record[7];
const static Flash_Record * histsufix_record = &flash_record[8];



static void init_record(const Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    uint8 k;
    uint32 rlen = flash_record->rlen;
    if(ONESIZE == rlen){//基本信息和历史附加
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->buf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(BIGSIZE == rlen)//部件
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->bigbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(ALARMSIZE == rlen )//报警,不存储
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
#if 0
                //                flash_record->alarmbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                //                for(k=0;k<10;k++);
#else
                flash_record->alarmbuf[i][j]=0xff;
#endif

            }
        }
    }
    else if(NODESIZE == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->nodebuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(HISTSIZE == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->histbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                for(k=0;k<10;k++);
            }
        }
    }

}
static void save_record(const Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    uint8 k;
    uint32 rlen = flash_record->rlen;

    check_lp_running();
    M25P80_Section_Erase(flash_record->addr);
    if(ONESIZE == rlen){//基本信息和历史附加
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->buf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(BIGSIZE == rlen)//部件
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->bigbuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(ALARMSIZE == rlen )//报警，不存储
    {
#if 0
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->alarmbuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
#endif
    }
    else if(NODESIZE == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->nodebuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }
    else if(HISTSIZE == rlen)
    {
        for(i=0;i<flash_record->llen;i++)
        {
            check_lp_running();
            for(j=0;j<flash_record->rlen;j++)
            {
                M25P80_Write_1Byte(flash_record->addr+flash_record->rlen*i+j,flash_record->histbuf[i][j]);
                for(k=0;k<10;k++);
            }
        }
    }

}
static void clr_record(const Flash_Record * flash_record)
{
    uint16 i;
    uint16 j;
    //     uint8 k;
    uint32 rlen = flash_record->rlen;
    if(ONESIZE == rlen){//基本信息和历史附加
#if 0
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->buf[i][j]=INITVAL;
                for(k=0;k<10;k++);
            }
        }
#endif
    }
    else if(BIGSIZE == rlen)//部件
    {
#if 0
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->bigbuf[i][j]=INITVAL;
                for(k=0;k<10;k++);
            }
        }
#endif
    }
    else if(ALARMSIZE == rlen )//报警,不存储
    {
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
#if 0
                //                flash_record->alarmbuf[i][j]=M25P80_Read_1Byte(flash_record->addr+flash_record->rlen*i+j);
                //                for(k=0;k<10;k++);
#else
                flash_record->alarmbuf[i][j]=INITVAL;
#endif

            }
        }
    }
    else if(NODESIZE == rlen)
    {
#if 0
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->nodebuf[i][j]=INITVAL;
                for(k=0;k<10;k++);
            }
        }
#endif
    }
    else if(HISTSIZE == rlen)
    {
#if 0
        for(i=0;i<flash_record->llen;i++)
        {
            for(j=0;j<flash_record->rlen;j++)
            {
                flash_record->histbuf[i][j]=INITVAL;
                for(k=0;k<10;k++);
            }
        }
#endif
    }
}

//设置存储缓存
static void set_array(const Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp)
{
    uint32 rowact;//底层映射，防止在上层重复修改
    uint32 rlen = flash_record->rlen;
    if(row > 0)
    {
        rowact= row-1;
    }else
    {
        rowact = 0;
    }
    //    Debug("set array row:%d\n",rowact);
    
    if(ONESIZE == rlen )
        flash_record->buf[rowact][col] = tmp;
    else if(BIGSIZE == rlen)
        flash_record->bigbuf[rowact][col] = tmp;
    else if(ALARMSIZE == rlen)
        flash_record->alarmbuf[rowact][col] = tmp;
    else if(NODESIZE == rlen)
        flash_record->nodebuf[rowact][col] = tmp;
    else if(HISTSIZE == rlen)
        flash_record->histbuf[rowact][col] = tmp;
}
//获取存储缓存
static uint8 get_array(const Flash_Record * flash_record,uint32 row,uint32 col)
{
    uint32 rowact;//底层映射，防止在上层重复修改
    uint32 rlen = flash_record->rlen;
    if(row > 0)
    {
        rowact= row-1;
    }else
    {
        rowact = 0;
    }
    //    Debug("get array row:%d\n",rowact);

    if(ONESIZE == rlen)
        return flash_record->buf[rowact][col];
    else if(BIGSIZE == rlen)
        return flash_record->bigbuf[rowact][col];
    else if(ALARMSIZE == rlen)
        return flash_record->alarmbuf[rowact][col];
    else if(NODESIZE == rlen)
        return flash_record->nodebuf[rowact][col];
    else if(HISTSIZE == rlen)
        return flash_record->histbuf[rowact][col];
    return 0xff;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[基本信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//由于底层做了存储位置的-1映射，所以此处，必须为1
#define ADDR_LOCALADDR 1 //本机地址
#define ADDR_ZONE_NUMS 2 //防区位置
#define ADDR_COMP_NUMS 3 //部件总数量存储位置，按此数据进行后面的连续存储


void init_basic_info(void)
{
    //默认初始回路地址
    init_record(basic_record);
}
void set_basic_info(uint32 row,uint8 tmp)
{
    set_array(basic_record,row,0,tmp);
}
uint8 get_basic_info(uint32 row)
{
    return get_array(basic_record,row,0);
}
//基本信息具有较高的优先级，需要直接存储
void save_basic_info(void)
{
    Eint_Dis();//清中断与同步标志
    ClrSys_CLpScanCtrl();
    save_record(basic_record);
    Eint_En();//开中断
}





//设置部件总数
void set_basic_nums(uint8 compnums)
{
    if(compnums > MAX_COMP)
    {
    }
    else
        set_basic_info(ADDR_COMP_NUMS,compnums);
}
//add
void add_basic_nums(void)
{
    if(get_basic_nums() > MAX_COMP)
    {
    }else
        set_basic_nums(get_basic_nums()+1);
}
//sub
void sub_basic_nums(void)
{
    if(get_basic_nums() > 0)
        set_basic_nums(get_basic_nums()-1);
}


void set_basic_localaddr(uint8 localaddr)
{
    set_basic_info(ADDR_LOCALADDR,localaddr);
}
void set_basic_zones(uint8 departallnums)
{
    set_basic_info(ADDR_ZONE_NUMS,departallnums);

}
//
uint32 get_basic_localaddr(void)
{
    if(INITVAL == get_basic_info(ADDR_LOCALADDR))
        return DEFAULT_LOCALADDR;
    else
        return get_basic_info(ADDR_LOCALADDR);
}
uint32 get_basic_zones(void)
{
    return get_basic_info(ADDR_ZONE_NUMS);
}
uint32 get_basic_nums(void)
{
#if 0
    return get_basic_info(ADDR_COMP_NUMS);
#else
    uint32 i,nums=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(INITVAL != get_comp_partnumber(i))
            nums++;
    }
    return nums;

#endif
}







/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[部件信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


////计算器件存储地址--------------好像没啥用，只需要找到缓存的一 二维地址就可以
//static int32 calc_addr(uint8 item,uint32 startaddr,uint8 size,uint8 offset)
//{
//    if(item<MAX_COMP)
//        return startaddr + size*item + offset;
//    else
//        return ADDRINVALID;
//}
////防区地址
//static int32 addr_comp_inzone(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,0);
//}
////部件地址
//static int32 addr_comp_part(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,1);
//}
////回路地址
//static int32 addr_comp_ciraddr(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,2);
//}
////psn0地址
//static int32 addr_comp_psn0(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,3);
//}
////psn1地址
//static int32 addr_comp_psn1(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,4);
//}
////psn2地址
//static int32 addr_comp_psn2(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,5);
//}
////psn3地址
//static int32 addr_comp_psn3(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,6);
//}
////类型地址
//static int32 addr_comp_devtype(uint8 item)
//{
//    return calc_addr(item,flash_record[1].addr,COMP_SINGLESIZE,7);
//}

void init_comp_info(void)
{
    init_record(comp_record);
}
void save_comp_info(void)
{
    save_record(comp_record);
}
//设置部件缓存变量
static void set_comp_info(uint32 row,uint32 col,uint8 tmp)
{
    set_array(comp_record,row,col,tmp);
}
//获取部件缓存变量
static uint8 get_comp_info(uint32 row,uint32 col)
{
    return get_array(comp_record,row,col);
}

//设置器件的 防区
void set_comp_inzone(uint8 item,uint8 inzone)
{
    set_comp_info(item,1,inzone);
}
//设置器件的 部件
void set_comp_partnumber(uint8 item,uint8 partnumber)
{
    set_comp_info(item,2,partnumber);
}
void set_comp_ciraddr(uint8 item,uint8 ciraddr)
{
    set_comp_info(item,3,ciraddr);
}
void set_comp_psn0(uint8 item,uint8 psn0)
{
    set_comp_info(item,4,psn0);
}
void set_comp_psn1(uint8 item,uint8 psn1)
{
    set_comp_info(item,5,psn1);
}
void set_comp_psn2(uint8 item,uint8 psn2)
{
    set_comp_info(item,6,psn2);
}
void set_comp_psn3(uint8 item,uint8 psn3)
{
    set_comp_info(item,7,psn3);
}
void set_comp_devtype(uint8 item,uint8 devtype)
{
    set_comp_info(item,8,devtype);
}
//设置器件信息
void set_comp_all(uint8 item,compent *compinfo)
{
    if(compinfo){
        set_comp_inzone(item,compinfo->inzone);
        set_comp_partnumber(item,compinfo->part);
        set_comp_ciraddr(item,compinfo->ciraddr);
        set_comp_psn0(item,compinfo->psn0);
        set_comp_psn1(item,compinfo->psn1);
        set_comp_psn2(item,compinfo->psn2);
        set_comp_psn3(item,compinfo->psn3);
        set_comp_devtype(item,compinfo->devtype);
    }
}
//重置所有信息
void clr_comp_all(uint8 item)
{
    set_comp_inzone(item,INITVAL);
    set_comp_partnumber(item,INITVAL);
    set_comp_ciraddr(item,INITVAL);
    set_comp_psn0(item,INITVAL);
    set_comp_psn1(item,INITVAL);
    set_comp_psn2(item,INITVAL);
    set_comp_psn3(item,INITVAL);
    set_comp_devtype(item,INITVAL);
}
//清回路信息
void clr_comp_loop_all(void)
{
    uint8 i;
    for(i=COMP_START;i<= MAX_COMP;i++)
        if(INITVAL != get_comp_partnumber(i))
            ClrReg_CNodeInfo(get_comp_ciraddr(i));
}

//设置器件信息并保存
void set_comp_all_and_save(uint8 item,compent *compinfo)
{
    set_comp_all(item,compinfo);
    save_comp_info();
}

//获取
uint8 get_comp_inzone(uint8 item)
{
    return get_comp_info(item,1);
}
uint8 get_comp_partnumber(uint8 item)
{
    return get_comp_info(item,2);
}
uint8 get_comp_ciraddr(uint8 item)
{
    //#if 1
    return get_comp_info(item,3);
    //#else
    //    item = item;
    //    return get_basic_localaddr();
    //#endif
}
//判断是否有同回路的部件
uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr)
{
    uint32 i=0;
    for(i= COMP_START ;i <=MAX_COMP;i++)
    {
        if((get_comp_ciraddr(i) == ciraddr)&&(row!=i))
            return TRUE;
    }
    return FALSE;
}

uint8 get_comp_psn0(uint8 item)
{
    return get_comp_info(item,4);
}
uint8 get_comp_psn1(uint8 item)
{
    return get_comp_info(item,5);
}
uint8 get_comp_psn2(uint8 item)
{
    return get_comp_info(item,6);
}
uint8 get_comp_psn3(uint8 item)
{
    return get_comp_info(item,7);
}
uint8 get_comp_devtype(uint8 item)
{
    return get_comp_info(item,8);
}
//获取器件所有信息
void get_comp_all(uint8 item, compent *compinfo)
{
    compinfo->inzone  = get_comp_inzone(item);
    compinfo->part    = get_comp_partnumber(item);
    compinfo->ciraddr = get_comp_inzone(item);
    compinfo->psn0    = get_comp_psn0(item);
    compinfo->psn1    = get_comp_psn1(item);
    compinfo->psn2    = get_comp_psn2(item);
    compinfo->psn3    = get_comp_psn3(item);
    compinfo->devtype = get_comp_devtype(item);
}



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[屏蔽信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void init_mask_info(void)/*MaskPSNInit*/
{
    init_record(mask_record);
}
void save_mask_info(void)/*SaveMaskPSN*/
{
    save_record(mask_record);
}
void set_mask_info(uint32 row,uint8 tmp)
{
    set_array(mask_record,row,0,tmp);//一维的信息
}
uint8 get_mask_info(uint32 row)/*CGetMaskPSN*/
{
    return get_array(mask_record,row,0);
}




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[报警信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//typedef struct alarminfo{
//    uint8 inzone;
//    uint8 part;
//    uint8 ciraddr;
//    uint8 alarmsum;
//    uint8 type;
//    uint8 alarmed;//是否已经报过警
//    PCF8563_DATE dateyear;
//}alarminfo;

//初始化报警信息
void init_alarm_info(void)
{
    init_record(alarm_record);
}
//保存报警信息
void save_alarm_info(void)/**/
{
    save_record(alarm_record);
}


static void set_alarm_info(uint32 row,uint32 col, uint8 tmp)
{
    set_array(alarm_record,row,col,tmp);
}
static uint8 get_alarm_info(uint32 row,uint32 col)/**/
{
    return get_array(alarm_record,row,col);
}
//获取报警属性
uint8 get_alarm_attr(uint32 row)
{
    return get_alarm_info(row,16);
}
uint8 get_alarm_alarmed(uint32 row)
{
    return get_alarm_info(row,6);
}
////有火警否？必须为火警，TRUE，有火警
//uint8 judge_alarm_alarmed(uint32 row)
//{
//    if(ATTR_FIRE == get_alarm_attr(row))
//        return TRUE;
//    else
//        return FALSE;
//}
//是否有火警
uint8 judge_alarm_firealarmed(uint32 row)
{
    if((ATTR_FIRE == get_alarm_attr(row))&&get_alarm_alarmed(row))
        return TRUE;
    else
        return FALSE;
}
//是否有故障
uint8 judge_alarm_faultalarmed(uint32 row)
{
    if((ATTR_FAULT == get_alarm_attr(row))&&get_alarm_alarmed(row))
        return TRUE;
    else
        return FALSE;
}
uint8 get_alarm_firstalarm(uint32 row)
{
    return get_array(alarm_record,row,15);
}
//获取报警信息属性列表 list--------------------------
void set_alarm_inzone(uint32 item, uint8 tmp)
{
    set_alarm_info(item,1,tmp);
}
void set_alarm_part(uint32 item, uint8 tmp)
{
    set_alarm_info(item,2,tmp);
}

void set_alarm_ciraddr(uint32 item, uint8 tmp)
{
    set_alarm_info(item,3,tmp);
}

void set_alarm_alarmsum(uint32 item, uint8 tmp)
{
    set_alarm_info(item,4,tmp);
}
void set_alarm_type(uint32 item, uint8 tmp)
{
    set_alarm_info(item,5,tmp);
}

void set_alarm_alarmed(uint32 item, uint8 tmp)
{
    set_alarm_info(item,6,tmp);
}
void set_alarm_firstalarm(uint32 item, uint8 tmp)
{
    set_alarm_info(item,15,tmp);
}
//获取报警属性
void set_alarm_attr(uint32 row, uint8 tmp)
{
    set_alarm_info(row,16,tmp);
}
void set_alarm_f_recvmess3h(uint32 item,uint8 flag)
{
    set_alarm_info(item,18,flag);
}
void clr_alarm_f_recvmess3h(uint32 item)
{
    set_alarm_f_recvmess3h(item,0);
}

void set_alarm_allinfo(uint32 item,alarminfo *info)
{
    set_alarm_inzone(item,info->inzone);
    set_alarm_part(item,info->part);
    set_alarm_ciraddr(item,info->ciraddr);
    set_alarm_alarmsum(item,info->alarmsum);
    set_alarm_type(item,info->type);
    set_alarm_alarmed(item,info->alarmed);
    set_alarm_info(item,7,info->dateyear.second);
    set_alarm_info(item,8,info->dateyear.minute);
    set_alarm_info(item,9,info->dateyear.hour);
    set_alarm_info(item,10,info->dateyear.day);
    set_alarm_info(item,11,info->dateyear.week);
    set_alarm_info(item,12,info->dateyear.month);
    set_alarm_info(item,13,info->dateyear.year/100);
    set_alarm_info(item,14,info->dateyear.year%100);
    set_alarm_firstalarm(item,ALARM_NOTFIST);//非首警
    set_alarm_info(item,16,info->attr);//属性
    set_alarm_info(item,17,info->vAnnRow);//属性
    set_alarm_info(item,18,info->f_recvmesat3h);
}
//清除报警信息
void clr_alarm_allinfo(void)
{
    clr_firealarm();
    clr_record(alarm_record);
}

void set_alarm_allinfo_andsave(uint32 item,alarminfo *info)
{
    set_alarm_allinfo(item,info);
    save_alarm_info();
}


uint8 get_alarm_part(uint32 item)
{
    return get_alarm_info(item,2);
}
uint8 get_alarm_ciraddr(uint32 item)
{
    return get_alarm_info(item,3);
}
uint8 get_alarm_type(uint32 item)
{
    return get_alarm_info(item,5);
}
//3hour recved message flag?
uint8 get_alarm_f_recvmess3h(uint32 item)
{
    return get_alarm_info(item,18);
}


void get_alarm_allinfo(uint32 item, alarminfo *info)
{
    info->inzone = get_alarm_info(item,1);
    info->part = get_alarm_info(item,2);
    info->ciraddr = get_alarm_info(item,3);
    info->alarmsum = get_alarm_info(item,4);
    info->type = get_alarm_info(item,5);
    info->alarmed = get_alarm_info(item,6);
    info->dateyear.second =get_alarm_info(item,7);
    info->dateyear.minute =get_alarm_info(item,8);
    info->dateyear.hour =get_alarm_info(item,9);
    info->dateyear.day =get_alarm_info(item,10);
    info->dateyear.week =get_alarm_info(item,11);
    info->dateyear.month =get_alarm_info(item,12);
    info->dateyear.year =get_alarm_info(item,13)*100+get_alarm_info(item,14);
    info->firstalarm    = get_alarm_info(item,15);
    info->attr          = get_alarm_info(item,16);
    info->vAnnRow       = get_alarm_info(item,17);
    info->f_recvmesat3h = get_alarm_info(item,18);
}
//设置首警
void set_alarm_first(alarminfo *info)
{
    set_alarm_allinfo(ALARM_FIRST_POS,info);
    set_alarm_firstalarm(ALARM_FIRST_POS,ALARM_FIRST);
}
//获取首警
void get_alarm_first(alarminfo *info)
{
    get_alarm_allinfo(ALARM_FIRST_POS,info);
}
//首警标志
uint8 get_alarm_firstflag(void)
{
    return get_alarm_firstalarm(ALARM_FIRST_POS);
}
//首警部件号
uint8 get_alarm_first_part(void)
{
    return get_alarm_info(ALARM_FIRST_POS,2);
}
//火警个数
uint8 get_firealarm_nums(void)
{
    uint8 i,nums=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(judge_alarm_firealarmed(i))
        {
            nums++;
        }
    }
    return nums;
}
void clr_firealarm(void)
{
    uint8 i=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(judge_alarm_firealarmed(i))
        {
            Debug("clr %d ciraddr fire alarm!\n");
            set_normalalarm_ciraddr(get_alarm_ciraddr(i));
        }
    }
}

//通过部件号查找位置
uint8 get_alarm_item_bypart(uint8 part)
{
    uint8 i,nums=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(get_alarm_part(i) == part)
        {
            return i;
        }
    }
    return nums;
}
//故障个数
uint8 get_faultalarm_nums(void)
{
    uint8 i,nums=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(judge_alarm_faultalarmed(i))
        {
            nums++;
        }
    }
    return nums;
}
//是否为首警
uint8 judge_alarm_first(void)
{
    if(ALARM_FIRST == get_alarm_firstflag())
        return TRUE;
    else
        return FALSE;
}




//void AlarmInfoInit(void)
//{
//    uint8 i,j;
//    for(i=0;i<20;i++)
//        for(j=0;j<13;j++)
//            AlarmInfo[i][j]=0xff;
//}
//uint8 GetAlarmInfo(uint8 row,uint8 col)
//{
//    return AlarmInfo[row][col];
//}
//void SetAlarmInfo(uint8 row,uint8 col,uint8 tmp)
//{
//    AlarmInfo[row][col]=tmp;
//}



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[注释信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void init_node_info(void)/*Com0Data_Init*/
{
    init_record(node_record);
}
void save_node_info(void)
{
    save_record(node_record);
}

//设置部件缓存变量
void set_node_info(uint32 row,uint32 col,uint8 tmp)
{
    set_array(node_record,row,col,tmp);
}
static void set_node_frame1(uint32 row,uint8 tmp)
{
    set_node_info(row,1,tmp);
}
static void set_node_frame2(uint32 row,uint8 tmp)
{
    set_node_info(row,2,tmp);
}
static void set_node_frame3(uint32 row,uint8 tmp)
{
    set_node_info(row,3,tmp);
}
static void set_node_cmd1(uint32 row,uint8 tmp)
{
    set_node_info(row,4,tmp);
}
static void set_node_cmd_rw(uint32 row,uint8 tmp)
{
    set_node_info(row,5,tmp);
}
static void set_node_devtype(uint32 row,uint8 tmp)
{
    set_node_info(row,6,tmp);
}
static void set_node_targetaddr(uint32 row,uint8 tmp)
{
    set_node_info(row,7,tmp);
}
static void set_node_controllernum(uint32 row,uint8 tmp)
{
    set_node_info(row,8,tmp);
}
static void set_node_datalen(uint32 row,uint8 tmp)
{
    set_node_info(row,9,tmp);
}
static void set_node_loop(uint32 row,uint8 tmp)
{
    set_node_info(row,10,tmp);
}
static void set_node_addr(uint32 row,uint8 tmp)
{
    set_node_info(row,11,tmp);
}
static void set_node_hz(uint32 row,uint8* tmp)
{
    uint8 i;
    for(i=0;i<32;i++)
    {
        set_node_info(row,12+i,tmp[i]);
    }
}
static void set_node_cs(uint32 row,uint8* tmp)
{
    uint8 i;
    for(i=0;i<2;i++)
    {
        set_node_info(row,43+i,tmp[i]);
    }
}

void set_node_all_info(uint32 row,note_info_t *info)
{
    set_node_frame1(row,info->frame1);
    set_node_frame2(row,info->frame2);
    set_node_frame3(row,info->frame3);
    set_node_cmd1(row,info->cmd1);
    set_node_cmd_rw(row,info->cmd_rw);
    set_node_devtype(row,info->devtype);
    set_node_controllernum(row,info->controllernum);
    set_node_datalen(row,info->datelen);
    set_node_targetaddr(row,info->targetaddr);
    set_node_loop(row,info->loop);
    set_node_addr(row,info->addr);
    set_node_cs(row,info->cs);
    set_node_hz(row,info->hz);

}

//typedef struct note_info_t
//{
//    uint8 frame1;
//    uint8 frame2;
//    uint8 frame3;
//    uint8 cmd1;
//    uint8 cmd_rw;
//    uint8 devtype;
//    uint8 targetaddr;
//    uint8 controllernum;
//    uint8 datelen;
//    uint8 loop;
//    uint8 addr;
//    uint8 hz[32];
//    uint8 cs[2];
//}note_info_t;


//获取部件缓存变量
uint8 get_node_info(uint32 row,uint32 col)
{
    return get_array(node_record,row,col);
}

//void Com0Data_Init(void)
//{
//    //    存储注释
//    //    (0x50000);
//    uint8 i,j;
//    for(i=COMP_START;i<=MAX_COMP;i++)
//        // 	{
//        // 		M25P80_Read_Bytes(0x50000,data2[i],sizeof(data2[i]));
//        // 	}

//        for(j=0;j<55;j++)
//            data2[i][j]=M25P80_Read_1Byte(0x50000+55*i+j);//加入PSN所在的flash地址

//}
//uint8 GetCom0Ann(uint8 row,uint8 cow) /*get_node_info*/
//{
//    return data2[row][cow];
//}
int8 get_node_row(/*uint8 dep,*/uint8 comp)
{
    int8 num = -1;
    uint8 i;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(/*(get_node_info(i,1)==dep)&&*/(get_node_info(i,2)==comp))
        {
            num = i;
            break;
        }
    }
    return num;
}


//int8 GetAnnRow(uint8 dep,uint8 comp) /*get_node_row*/
//{
//    int8 num = -1;
//    uint8 i;
//    for(i=COMP_START;i<=MAX_COMP;i++)
//    {
//        if((data2[i][1]==dep)&&(data2[i][2]==comp))
//        {
//            num = i;
//            break;
//        }
//    }
//    return num;
//}
//void CSaveAnn(void)
//{
//    //    uint8 i,j;
//    check_lp_running();
//    M25P80_Section_Erase(0x70000);
//    M25P80_Write_1Byte(0x70000,vAnnCounter);
//    //    M25P80_Section_Erase(0x50000);
//    //    for(i=COMP_START;i<=MAX_COMP;i++)
//    //        for(j=0;j<55;j++)
//    //            M25P80_Write_1Byte((0x50000+55*i+j),data2[i][j]);

//}

void save_node_and_nodenums(void)/*CSaveAnn*/
{
    save_node_info();
    set_nodenums(get_nodenums()+1);
    save_nodenums_info();
}


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[注释条数方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//只是一个变量，定义为[1][1]
//初始化注释条数
void init_nodenums_info(void)/*AnnCounterInit*/
{
    init_record(nodenums_record);
    if(get_nodenums() == 0xff)
        set_nodenums(0);
}
//保存注释条数到flash
void save_nodenums_info(void)
{
    save_record(nodenums_record);
}
void set_nodenums(uint8 tmp)
{
    set_array(nodenums_record,1,0,tmp);
}

uint8 get_nodenums(void)
{
    return get_array(nodenums_record,1,0);
}
void add_nodenums(void)
{
    set_nodenums(get_nodenums()+1);

}


//void AnnCounterInit(void)
//{
//    //    注释条数
//    //    (0x70000)
//    vAnnCounter = M25P80_Read_1Byte(0x70000);
//    if(vAnnCounter == 0xff)
//        vAnnCounter = 0;
//}



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史信息方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void init_hist_info(void)/*GetHistory*/
{
    init_record(hist_record);
}
void save_hist_info(void)/*SendHistToFlash*/
{
    save_record(hist_record);
    SetHistConter(GetHistConter()+1);//保存完毕后，自加1
    //    Debug("save hist,counter:%d\n",GetHistConter());
}
//获取历史记录信息
static uint8 get_hist_info(uint32 row,uint8 col)/*GetHistoryList*/
{
    if(row < MAX_HIST_NUMS)
        return get_array(hist_record,row,col);
    else
        return 0xff;
}
void set_hist_info(uint32 row,uint8 col,uint8 tmp)/*SetHistoryList*/
{
    if(row < MAX_HIST_NUMS)
        set_array(hist_record,row,col,tmp);
}
void clr_hist_info(void) /*ClrHistoryList*/
{
    uint32 i;
    uint8 j;
    for(i=0;i<HIST_LLEN;i++)
        for(j=0;j<HIST_RLEN;j++)
            set_hist_info(i,j,0xff);
}

uint8 get_hist_order(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,1);
}
uint8 get_hist_inzone(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,2);
}
uint8 get_hist_part(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,3);
}
uint8 get_hist_circleaddr(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,4);
}
uint8 get_hist_vAnnRow(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,5);
}
uint8 get_hist_attr(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,6);
}
uint8 get_hist_opstype(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,7);
}

uint8 get_hist_devtype(uint32 row)/*gethistory_devtype*/
{
    return get_hist_info(row,8);
}
uint8 get_hist_lastnum(uint32 row)/*gethistory_num*/
{
    return get_hist_info(row,9);
}
//获取历史记录时间
void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear)/*gethistory_num*/
{
    dateyear->second =  get_hist_info(row,10);
    dateyear->minute =  get_hist_info(row,11);
    dateyear->hour =  get_hist_info(row,12);
    dateyear->day =  get_hist_info(row,13);
    dateyear->week =  get_hist_info(row,14);
    dateyear->month =  get_hist_info(row,15);
    dateyear->year =  get_hist_info(row,16)*100 + get_hist_info(row,17);
}
//获取历史记录的所有信息
void get_hist_allinfo(uint32 row, history_st* info)
{
    info->order  = get_hist_order(row);
    info->inzone = get_hist_inzone(row);
    info->part   = get_hist_part(row);
    info->circleaddr = get_hist_circleaddr(row);
    info->attr   = get_hist_attr(row);
    info->devtype = get_hist_devtype(row);
    info->lastnum = get_hist_lastnum(row);
    info->vAnnRow = get_hist_vAnnRow(row);
    info->opstype = get_hist_opstype(row);
    get_hist_datetime(row,&info->dateyear);
}
//设置历史记录所有信息
void set_hist_allinfo(uint32 row, history_st* info)
{
    set_hist_info(row,1,info->order);
    set_hist_info(row,2,info->inzone);
    set_hist_info(row,3,info->part);
    set_hist_info(row,4,info->circleaddr);
    set_hist_info(row,5,info->vAnnRow);
    set_hist_info(row,6,info->attr);
    set_hist_info(row,7,info->opstype);
    set_hist_info(row,8,info->devtype);
    set_hist_info(row,9,info->lastnum);
    //set date time
    set_hist_info(row,10,info->dateyear.second);
    set_hist_info(row,11,info->dateyear.minute);
    set_hist_info(row,12,info->dateyear.hour);
    set_hist_info(row,13,info->dateyear.day);
    set_hist_info(row,14,info->dateyear.week);
    set_hist_info(row,15,info->dateyear.month);
    set_hist_info(row,16,info->dateyear.year/100);
    set_hist_info(row,17,info->dateyear.year%100);
}

//保存历史记录和历史条数
void save_hist_all(void)
{
    save_hist_info();
    save_histnums_info();
}

//void flash_save_historycounter(void)
//{
//    uint8 i,k;
//    uint8 vHisC[3];//0:/10,1:%10,2:>1000 flag

//    vHisC[0]=(uint8)(GetHistConter() / 10); //calc history lists
//    vHisC[1]=(uint8)(GetHistConter()%10);

//    if(GetHistConter()>=MAX_HIST_NUMS){ //calc history nums
//        SetHistConter(MAX_HIST_NUMS);
//        vHisC[2]=HISTNUMOVER1000;//the counter num is MAX_HIST_NUMS
//    }
//    check_lp_running();
//    M25P80_Section_Erase(FLS_HISTNUMS_ADR);//存储历史记录条数
//    for(i=0;i<3;i++)
//    {
//        check_lp_running();
//        M25P80_Write_1Byte((FLS_HISTNUMS_ADR+i),vHisC[i]);
//        for(k=0;k<10;k++);
//    }
//}


//uint8 GetHistoryList(uint32 row,uint8 col)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][col];
//    else
//        return 0xff;
//}
//uint8 gethistory_num(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][0];
//    else
//        return 0xff;
//}
//uint8 gethistory_devtype(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][1];
//    else
//        return 0xff;
//}
//uint8 gethistory_COMSEL(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][2];
//    else
//        return 0xff;
//}
//uint8 gethistory_attr(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][3];
//    else
//        return 0xff;
//}
//uint8 gethistory_highyear(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][4];
//    else
//        return 0xff;
//}
//uint8 gethistory_lowyear(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][5];
//    else
//        return 0xff;
//}
//uint8 gethistory_month(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][6];
//    else
//        return 0xff;
//}
//uint8 gethistory_day(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][7];
//    else
//        return 0xff;
//}
//uint8 gethistory_hour(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][8];
//    else
//        return 0xff;
//}
//uint8 gethistory_min(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][9];
//    else
//        return 0xff;
//}
//uint8 gethistory_sec(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][10];
//    else
//        return 0xff;
//}
//uint8 gethistory_vAnnRow(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][11];
//    else
//        return 0xff;
//}
//uint8 gethistory_inzone(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][12];
//    else
//        return 0xff;
//}
//uint8 gethistory_partnumber(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][13];
//    else
//        return 0xff;
//}
//uint8 gethistory_circleaddr(uint32 row)
//{
//    if(row < MAX_HIST_NUMS)
//        return vHisList[row][14];
//    else
//        return 0xff;
//}



//void SendHistToFlash(void)
//{
//    uint32 i;
//    uint8 j;
//    uint8 k;

//    check_lp_running();
//    M25P80_Section_Erase(FLS_HIST_ADR);
//    for(i=0;i<MAX_HIST_NUMS;i++)
//        for(j=0;j<HIST_INFO_LEN;j++)
//        {
//            M25P80_Write_1Byte((FLS_HIST_ADR+HIST_INFO_LEN*i+j),vHisList[i][j]);
//            for(k=0;k<10;k++);
//        }
//}
//void GetHistory(void)
//{
//    //    存储历史记录
//    //    (0x40000);
//    //    (0x80000);
//    uint32 i;
//    uint8 j;
//    for(i=0;i<MAX_HIST_NUMS;i++)
//        for(j=0;j<HIST_INFO_LEN;j++)
//            vHisList[i][j] = M25P80_Read_1Byte(0x40000+HIST_INFO_LEN*i+j);

//}

//void SetHistoryList(uint32 row,uint8 col,uint8 tmp)
//{
//    if(row < MAX_HIST_NUMS)
//        vHisList[row][col]=tmp;
//}
//void ClrHistoryList(void)
//{
//    uint32 i;
//    uint8 j;
//    for(i=0;i<MAX_HIST_NUMS;i++)
//        for(j=0;j<HIST_INFO_LEN;j++)
//            vHisList[i][j]=0xff;
//}




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史条数方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//历史记录是否为满，置位标志get_histnum_info(2)
uint8 judge_histnums_full(void)
{
    if(HISTNUMOVER1000 == get_histnum_info(3))
        return TRUE;
    else
        return FALSE;
}
//设置历史记录为满
void set_histnum_full(void)
{
    set_histnum_info(3,HISTNUMOVER1000);
}

//初始化历史条数
void init_histnums_info(void)/*InitHistInfo*/
{
    init_record(histnums_record);
    //    SetHistConter(vHisC[0]*10)+vHisC[1]);
    if(INITVAL == get_histnum_info(1)&&
            INITVAL == get_histnum_info(2))
        SetHistConter(0);
    else
        SetHistConter(get_histnum_info(1)*100+get_histnum_info(2));
    //    Debug("hist counter:%d\n",GetHistConter());

    if(judge_histnums_full())
    {
        SetHistConter(MAX_HIST_NUMS);
        //        Debug("hist counter full:%d\n",GetHistConter());
    }

    if(GetHistConter()>=MAX_HIST_NUMS)
    {
        SetHistConter(MAX_HIST_NUMS);
        set_histnum_full();
        //        Debug("hist counter full:%d\n",GetHistConter());
    }
    //    set_history_alarm_pos(GetHistConter());

}
void save_histnums_info(void)/*flash_save_historycounter*/
{
    set_histnum_info(1,GetHistConter()/100);
    set_histnum_info(2,GetHistConter()%100);
    if(judge_histnums_full())
    {

    }else{
        set_histnum_info(3,GetHistConter()>=MAX_HIST_NUMS?HISTNUMOVER1000:0xff);
    }
    save_record(histnums_record);
}
//设置缓存
static void set_histnum_info(uint32 row,uint8 tmp)
{
    set_array(histnums_record,row,0,tmp);
}
//获取缓存
static uint8 get_histnum_info(uint32 row)
{
    return get_array(histnums_record,row,0);
}





//初始化历史记录和历史条数
void init_hist_and_histnums(void)
{
    init_hist_info();
    init_histnums_info();
}


////////////////////存储历史记录数组/////////////////////////
//void InitHistInfo(void)
//{
//    //    存储历史记录的计数
//    //    ((M25P80_Read_1Byte(0x60000)<<8)+(M25P80_Read_1Byte(0x60001)))

//    uint8 i,vHisC[3];
//    for(i=0;i<3;i++)
//        vHisC[i]=M25P80_Read_1Byte(0x60000+i);
//    SetHistConter((vHisC[0]*10)+vHisC[1]);
//    if(GetHistConter()>MAX_HIST_NUMS)
//        SetHistConter(MAX_HIST_NUMS);
//    if(vHisC[2] == HISTNUMOVER1000)
//    {
//        SetHistConter(MAX_HIST_NUMS);
//    }

//    set_history_alarm_pos(GetHistConter());
//    Debug("history nums:%d\n",GetHistConter());

//    //     init_histfullflag();

//}




/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[历史附加方法]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void init_histsufix_info(void)
{
    init_record(histsufix_record);
}

//初始化所有存储
void init_flash_all(void)
{
    init_basic_info();
    init_comp_info();
    init_mask_info();
    init_alarm_info();
    //    init_node_info();
    //    init_nodenums_info();

    NoteData_Init();
    AnnCounterInit();


    init_hist_and_histnums();//初始化两个内容
    init_histsufix_info();


}











///////////////////////存储PSN防区和部件序号//////////////////////
//void CSendPSN(uint8 curpos,uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3,uint8 inzone,uint8 partnumber,uint8 devtype,uint8 CirAddr)
//{
//    uint32 tmp;
//    //    uint32 i;
//    //uint8 psnflag=0;
//    tmp=psn0|(psn1<<8)|(psn2<<16)|(psn3<<24);
//    if(tmp != 0)
//    {//判断是否保存此PSN有问题
//        //        if((vSendPSNToFlash[curpos][0]==0xFF)&&(vSendPSNToFlash[curpos][1]==0xFF)&&(vSendPSNToFlash[curpos][2]==0xFF)&&(vSendPSNToFlash[curpos][3]==0xFF))
//        //        {

//        vSendPSNToFlash[curpos][POS_PSN0]=psn0;
//        vSendPSNToFlash[curpos][POS_PSN1]=psn1;
//        vSendPSNToFlash[curpos][POS_PSN2]=psn2;
//        vSendPSNToFlash[curpos][POS_PSN3]=psn3;
//        vSendPSNToFlash[curpos][POS_INZONE]=inzone;
//        vSendPSNToFlash[curpos][POS_PARTNUMBER]=partnumber;
//        vSendPSNToFlash[curpos][POS_DEVTYPE]=devtype;
//        vSendPSNToFlash[curpos][POS_CIRADDR]=CirAddr;//回路地址
//        //            break;
//        //        }
//    }
//    // 		CSendPSNToFlash();
//    //}
//}
uint8 CheckDepComp(uint8 dep,uint8 comp)
{
    uint8 i,sum;
    dep = dep;
    for(i=COMP_START;i <= MAX_COMP;i++)
    {
        //         get_comp_info();
        if((get_comp_partnumber(i) == comp)&&
                INITVAL != get_comp_partnumber(i))
        {
            sum=1;
            break;
        }
        else
            sum=0;
    }
    return sum;
}
////部件总数(sum)
//uint8 GetCompSum(void)
//{
//    uint8 i,sum=0;
//    for(i=0;i<PSN_TOTALSIZE;i++)
//    {
//        //从此变量来判断变量是否发生变化
//        if((vSendPSNToFlash[i][POS_CIRADDR]<0xff)&&(vSendPSNToFlash[i][POS_CIRADDR]>0))
//            ++sum;
//    }
//    return sum;
//}
////一个防区部件数量
//uint8 GetDep_CompSum(uint8 dep)
//{
//    uint8 i,sum=0;
//    for(i=0;i<PSN_TOTALSIZE;i++)
//    {
//        if(vSendPSNToFlash[i][POS_INZONE]==dep)
//            ++sum;
//    }
//    return sum;
//}
//void CAmendPSNToFlash(uint8 row,uint8 tmp)
//{

//    vSendPSNToFlash[row][POS_PSN0]      = tmp;
//    vSendPSNToFlash[row][POS_PSN1]      = tmp;
//    vSendPSNToFlash[row][POS_PSN2]      = tmp;
//    vSendPSNToFlash[row][POS_PSN3]      = tmp;
//    vSendPSNToFlash[row][POS_INZONE]    = tmp;
//    vSendPSNToFlash[row][POS_PARTNUMBER]  = tmp;
//    vSendPSNToFlash[row][POS_DEVTYPE]   = tmp;
//    vSendPSNToFlash[row][POS_CIRADDR]   = tmp;


//}
//void CSendPSNToFlash(void)
//{
//    uint8 i;
//    uint8 j;
//    uint8 k;
//    check_lp_running();
//    M25P80_Section_Erase(0x10000);
//    for(i=0;i<PSN_TOTALSIZE;i++)
//        // 	{
//        // 		M25P80_Write_Bytes(0x10000,vSendPSNToFlash[i],sizeof(vSendPSNToFlash[i]));
//        // 	}
//        for(j=0;j<8;j++)
//        {
//            M25P80_Write_1Byte((0x10000+8*i+j),vSendPSNToFlash[i][j]);
//            for(k=0;k<10;k++);
//        }


//}
//void CGetPSNFromFlash(void)
//{
//    //    存储PSN数组
//    //    (0x10000);
//    uint8 i;
//    uint8 j;

//    for(i=0;i<PSN_TOTALSIZE;i++)
//        // 	{
//        // 		M25P80_Read_Bytes(0x10000,vSendPSNToFlash[i],sizeof(vSendPSNToFlash[i]));
//        // 	}
//        for(j=0;j<8;j++)
//            vSendPSNToFlash[i][j]=M25P80_Read_1Byte(0x10000+8*i+j);

//}
//void CPSNToFlashInit(void)
//{
//    uint8 i;
//    uint8 j;

//    for(i=0;i<PSN_TOTALSIZE;i++)
//        for(j=0;j<8;j++)
//            vSendPSNToFlash[i][j]=0xff;
//}
//uint8 GetPSNFormFlash(uint8 row,uint8 col)
//{
//    return vSendPSNToFlash[row][col];
//}
//uint32 GetDatatoFlashAddr(uint8 row)
//{
//    uint32 tmp;
//    tmp = vSendPSNToFlash[row][0]|(vSendPSNToFlash[row][1]<<8)|(vSendPSNToFlash[row][2]<<16)|(vSendPSNToFlash[row][3]<<24);
//    return tmp;
//}
int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3)
{
#if 1
    int16 temp = -1;
    uint16 j;
    //从flash中读取
    for(j=COMP_START;j<=MAX_COMP;j++)
    {
        if((get_comp_psn0(j) == psn0)
                &&(get_comp_psn1(j) == psn1)
                &&(get_comp_psn2(j) == psn2)
                &&(get_comp_psn3(j) == psn3))
        {
            temp=j;
            break;
        }
    }
    return temp;
#else
    //    int16 temp = -1;
    //    uint16 j;
    //    //从flash中读取
    //    for(j=0;j<PSN_TOTALSIZE;j++)
    //    {
    //        if((vSendPSNToFlash[j][POS_PSN0]==psn0)&&(vSendPSNToFlash[j][POS_PSN1]==psn1)&&(vSendPSNToFlash[j][POS_PSN2]==psn2)&&(vSendPSNToFlash[j][POS_PSN3]==psn3))
    //        {
    //            temp=j;
    //            break;
    //        }
    //    }
    //    return temp;
#endif

}
void CAddCirCounter(void)
{
    vCirCounter++;
}
void CSetCirCounter(uint8 tmp)
{
    vCirCounter = tmp;
}
uint8 CGetCirCounter(void)
{
    return vCirCounter;
}
int8 GetRow(uint8 t1,uint8 t2)
{
    int8 row=-1;
    uint8 i;

    t1 = t1;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if((get_comp_partnumber(i) == t2)&&
                INITVAL != get_comp_partnumber(i))
        {
            row = i;
            break;
        }
    }
    return row;
}
////////////////////存储当前报警信息/////////////////////////////
//void SaveDataToFlash(void)
//{
//    uint8 i;//j,k;
//    M25P80_Section_Erase(0x30000);
//    for(i=0;i<PSN_TOTALSIZE;i++)
//    {
//        M25P80_Write_Bytes(0x30000,vGetDatatoFlash[i],sizeof(vGetDatatoFlash[i]));
//    }
//    // 		for(j=0;j<13;j++)
//    // 		{
//    // 		M25P80_Write_1Byte((0x30000+13*i+j),vGetDatatoFlash[i][j]);
//    // 		for(k=0;k<10;k++);
//    //
//    // 		}


//}
/////判断是否有报火警，有 0，无 1/////是否之前有火警
uint8 JudgeAlarmType(void)
{
    uint8 i,tmp=0;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {//find whether is haved first fire alarm?
        if(judge_alarm_firealarmed(i))//已有火警了
        {
            tmp=0;
            break;
        }
        else
            tmp=1;
    }
    return tmp;
}
uint8 JudgeCompAlarmType(uint8 row)
{
    //finding whether here has fire,fault,battery low etc's conditions
    uint8 tmp = 0;
    if(vGetDatatoFlash[row][COM_POS_DEVSTATE] == ATTR_FIRE)
        tmp=0;
    else if(vGetDatatoFlash[row][COM_POS_DEVSTATE] == ATTR_FIRE)
        tmp=0;
    else if(vGetDatatoFlash[row][COM_POS_DEVSTATE] == ATTR_BAT_LOW)
        tmp=0;
    else
        tmp=1;
    return tmp;
}
void SetDatatoFlash(uint8 row,uint8 col,uint8 tmp)
{
    vGetDatatoFlash[row][col] = tmp;
}
uint8 GetDatatoFlash(uint8 row,uint8 col)
{
    return vGetDatatoFlash[row][col];
}
//void ClrDatatoFlash(void)
//{
//    uint8 i,j;
//    for(i=0;i<PSN_TOTALSIZE;i++)
//        for(j=3;j<13;j++)
//            vGetDatatoFlash[i][j]=0;
//}
uint8 GetDatatoFlashType(uint8 row)
{
    return vGetDatatoFlash[row][1];
}
uint8 GetDatatoFlashAlarmType(uint8 row)
{
    return vGetDatatoFlash[row][COM_POS_DEVSTATE];
}
void SetFlashData(uint8 id,uint8 tmp)
{
    vReadFlashData[id] = tmp;
}
void SetDepCompSum(uint16 temp,uint8 tmp)
{
    vGetDepNum[temp] = tmp;
}
uint8 GetDepCompSum(uint16 tmp)
{
    return vGetDepNum[tmp];
}
//void GetFlashPsn(void)
//{
//    uint8 i,j;
//    for(i=0;i<PSN_TOTALSIZE;i++)
//        // 	{
//        // 		M25P80_Read_Bytes(0x30000,vGetPsn[i],sizeof(vGetPsn[i]));
//        // 	}
//        for(j=0;j<4;j++)
//            vGetPsn[i][j]=M25P80_Read_1Byte(0x30000+16*i+j);//加入PSN所在的flash地址

//}
uint8 ReadFlashPsn(uint8 row,uint8 col)
{
    return vGetPsn[row][col];
}



void SetCom0Ann(uint8 row,uint8 cow,uint8 tmp)
{
    vGetCom0Ann[row][cow]=tmp;
}





