#ifndef CFLASH_ADDR_DEF_H
#define CFLASH_ADDR_DEF_H

//////////////
////139所有内容存储位置定义


#define FLS_BASEINFO_ADR        (0x00000)//基本信息
#define FLS_COMPINFO_ADR        (0x10000)//注册部件信息
#define FLS_MASKINFO_ADR        (0x20000)//屏蔽信息
#define FLS_ALARMINFO_ADR       (0x30000)//报警信息
#define FLS_NODE_ADR            (0x40000)//注释信息
#define FLS_NODENUMS_ADR        (0x80000)//注释条数
#define FLS_HIST_ADR            (0x50000)//历史内容
#define FLS_HISTNUMS_ADR        (0x60000)//历史条数
#define FLS_HIST_SUFIX_ADR    (0x70000)//历史记录达到1000条的标志，最后历史记录地址



#endif // CFLASH_ADDR_DEF_H
