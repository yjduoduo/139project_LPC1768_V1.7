/*
;*********************************************************************************************************
;*                                                
;*                            ����: CComHandle
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CFlashParam.h
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CFlashParam.h"
#include "config.h"

#ifndef __FlashPara_H 
#define __FlashPara_H

#include    "pcf8563.h"
#include    "CMaDefine.h"
#include  "uart.h"


//�洢����ڵ㣬��ֵ��1
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
//100������50������
uint8 vGetDatatoFlash[MAX_ROW][13]={0};//���ÿ����������ϸ��Ϣ
uint8 vGetDepNum[MAX_ROW]={0};//���ÿ��������Ĳ�������
uint8 vReadFlashData[16]={0};//��ȡflash�ж�ӦPSN����Ϣ
// 	uint8 vGetCompType[PSN_TOTALSIZE][5]={0};//��ò���������
uint8 vGetPsn[PSN_TOTALSIZE][8]={0};//�����ʹ�flash�ж�ȡ����PSN�Ͷ�Ӧ�ķ�������˳���
//    uint8 vSendPSNToFlash[PSN_TOTALSIZE][8]={0};//�洢PSN��Flash�Ͷ�Ӧ�ķ�������˳��� �������� ע���ַ
uint8 vCirCounter=0;//��·����
/*
    *��ʷ��¼�洢
    *�ñ��������Ĵ洢���  0  ����1  ����2 ��������3 ����ʱ��4-10  ����ע�͵����11
    */
uint16 vHisCounter=0;//��ʷ��¼����������1000��ͷ��ʼ
//uint8 vHisList[MAX_HIST_NUMS][HIST_INFO_LEN]={0};//�洢��ʷ��¼

uint8 FlashData[MAX_ROW][15]={0};
uint16 vGetCom0Ann[100][8]={0};//��ú���ע��
uint8  vHistFlag=0;//��ʷ��¼��־
uint8 vPageCounter=0;//ҳ����

static PCF8563_DATE history_alarmtime;//��ʷ��¼��ʱ��


#endif


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[�����ڵ㻺��������]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//�������ݱ��벻ͬ�������г�ʼ������
#define ONESIZE (1)
#define BIGSIZE (8)
#define ALARMSIZE (18)/*��HISTSIZE��ͬ�ˣ�����*/
#ifndef test
#define NODESIZE (2)
#else
//#define NODESIZE (55)
#endif
#define HISTSIZE (17)





/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[��ʷ��Ϣ�洢���ݽ��]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define MAX_HIST_NUMS (1000+1)
#define HIST_LLEN MAX_HIST_NUMS
#define HIST_RLEN HISTSIZE




typedef	union FlashInfoDef
{
    //uint32   id; //��ַ0-3
    uint8    row;  //�ñ��������Ĵ洢���  0
    uint8 	 type;	//����4/1  0x30 ����0x31 ����0x32 �ֱ�0x33 ����0x34 ����ģ��0x35 �������0x36 ���ⱨ��
    uint8	   setup;	//����5/2
    uint8    alarmtype;//��������6/3  0x30����0x31���Ƿѹ0x32����0x33��
    // 	struct//����ʱ��7-13/4-10
    // 	{
    uint16  year;
    uint8   month;
    uint8   day;
    uint8   hour;
    uint8   minute;
    uint8   second;
    // 	}Time;
    uint8    signal;//�ź�ǿ��14/11
    uint8    compann;//����ע�͵����15/12
}tFlashinfoDef,*PFlashinfoDef;






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[flash�洢�ṹ]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

typedef void (void_fnc_t) (void);
typedef struct Flash_Record{
    uint32 addr;//д�ĵ�ַ
    uint8 (*buf)[ONESIZE];//����ָ��  ---������Ϣ����ʷ����
    uint8 (*bigbuf)[BIGSIZE];//�󻺴�ָ�� ��������
    uint8 (*alarmbuf)[ALARMSIZE];//    ��������
    uint8 (*nodebuf)[NODESIZE]; //����ע��
    uint8 (*histbuf)[HISTSIZE]; //������ʷ��¼
    uint32 llen;//��һά���泤��
    uint32 rlen;//�ڶ�ά���泤��
    void_fnc_t *initfun;//��ʼ��
    void_fnc_t *savefun;//����
}Flash_Record;



/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[������Ϣ�洢���ݽ��]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
#define MAXALARM (MAX_ROW)
#define ALARM_LLEN MAXALARM + 1 /*+1 ��ʾ���һ���׾���־*/
#define ALARM_RLEN ALARMSIZE
#define ALARM_FIRST_POS  (51)  /*�׾�λ��*/


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[������Ϣ�ṹ]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#define ALARM_NOTFIST (0x00)/*���׾�*/
#define ALARM_FIRST   (0x01)/*�׾�*/
#define ALARM_HAVE    (0x02)/*���б���*/
#define ALARM_NONE    (0x03) /*δ����*/


typedef struct alarminfo{
    uint8 inzone;
    uint8 part;
    uint8 ciraddr;
    uint8 alarmsum;
    uint8 type;
    uint8 alarmed;//�Ƿ��Ѿ�������
    PCF8563_DATE dateyear;
    uint8 firstalarm;//�Ƿ�Ϊ�׾� --���
    uint8 attr;//��������,  --���
    uint8 vAnnRow;//ע�����к� --���
    uint8 f_recvmesat3h;//3hour recv message?
}alarminfo;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[��ʷ��¼��Ϣ�ṹ]~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct history_st{
    uint8 order;//�ڼ���
    uint8 inzone;
    uint8 part;
    uint8 circleaddr;
    uint8 vAnnRow;//ע�����к�
    uint8 attr;//�𾯣����ϣ�������Ϣ,��Ŀǰ���������κϲ����ˡ�
    uint8 opstype;//�������ͣ�ɾ������������ʱδ�á�
    uint8 devtype;//���̣��й�
    uint8 lastnum;//�Ƿ����һ��
    PCF8563_DATE dateyear;//ʱ��
}history_st;



typedef struct
{
    uint32 firesum;
    uint32 faultsum;
    uint32 battlowsum;
}tSum;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~[������Ϣ������������������·��ַ��PSN��ʱ���]~~~~~~~~~~~~~~~~~~~~~~~~*/
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

//���д洢�ָ��������ú�ĳ�ʼֵ
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
//������ʷ��¼����־
void setHistFullFlag(uint8 flag);
uint8 getHistFullFlag(void);
//��ȡ��ʷ��¼�Ƿ�Ϊ��
uint8 getHistFull(void);
static void init_record(Flash_Record * flash_record);
static void save_record(Flash_Record * flash_record);
//���ô洢����
static void set_array(Flash_Record * flash_record,uint32 row,uint32 col,uint8 tmp);
//��ȡ�洢����
static uint8 get_array(Flash_Record * flash_record,uint32 row,uint32 col);
void init_basic_info(void);
void set_basic_info(uint32 row,uint8 tmp);
uint8 get_basic_info(uint32 row);
//������Ϣ���нϸߵ����ȼ�����Ҫֱ�Ӵ洢
void save_basic_info(void);
//���ò�������
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
//���ò����������
static void set_comp_info(uint32 row,uint32 col,uint8 tmp);
//��ȡ�����������
static uint8 get_comp_info(uint32 row,uint32 col);
//���������� ����
void set_comp_inzone(uint8 item,uint8 inzone);
//���������� ����
void set_comp_partnumber(uint8 item,uint8 partnumber);
void set_comp_ciraddr(uint8 item,uint8 ciraddr);
void set_comp_psn0(uint8 item,uint8 psn0);
void set_comp_psn1(uint8 item,uint8 psn1);
void set_comp_psn2(uint8 item,uint8 psn2);
void set_comp_psn3(uint8 item,uint8 psn3);
void set_comp_devtype(uint8 item,uint8 devtype);
//����������Ϣ
void set_comp_all(uint8 item,compent *compinfo);
//����������Ϣ
void clr_comp_all(uint8 item);
//���·��Ϣ
void clr_comp_loop_all(void);
//����������Ϣ������
void set_comp_all_and_save(uint8 item,compent *compinfo);
//��ȡ
uint8 get_comp_inzone(uint8 item);
uint8 get_comp_partnumber(uint8 item);
uint8 get_comp_ciraddr(uint8 item);
//�ж��Ƿ���ͬ��·�Ĳ���
uint8 judge_same_ciraddr(uint8 row,uint8 ciraddr);
uint8 get_comp_psn0(uint8 item);
uint8 get_comp_psn1(uint8 item);
uint8 get_comp_psn2(uint8 item);
uint8 get_comp_psn3(uint8 item);
uint8 get_comp_devtype(uint8 item);
//��ȡ����������Ϣ
void get_comp_all(uint8 item, compent *compinfo);
void init_mask_info(void)/*MaskPSNInit*/;
void save_mask_info(void)/*SaveMaskPSN*/;
void set_mask_info(uint32 row,uint8 tmp);
uint8 get_mask_info(uint32 row)/*CGetMaskPSN*/;
//��ʼ��������Ϣ
void init_alarm_info(void);
//���汨����Ϣ
void save_alarm_info(void)/**/;
static void set_alarm_info(uint32 row,uint32 col, uint8 tmp);
static uint8 get_alarm_info(uint32 row,uint32 col)/**/;
//��ȡ��������
uint8 get_alarm_attr(uint32 row);
uint8 get_alarm_alarmed(uint32 row);
//�Ƿ��л�
uint8 judge_alarm_firealarmed(uint32 row);
//�Ƿ��й���
uint8 judge_alarm_faultalarmed(uint32 row);
uint8 get_alarm_firstalarm(uint32 row);
//��ȡ������Ϣ�����б� list--------------------------
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
//���������Ϣ
void clr_alarm_allinfo(void);
void set_alarm_allinfo_andsave(uint32 item,alarminfo *info);
uint8 get_alarm_part(uint32 item);
uint8 get_alarm_ciraddr(uint32 item);
uint8 get_alarm_type(uint32 item);
//3hour recved message flag?
uint8 get_alarm_f_recvmess3h(uint32 item);
void get_alarm_allinfo(uint32 item, alarminfo *info);
//�����׾�
void set_alarm_first(alarminfo *info);
//��ȡ�׾�
void get_alarm_first(alarminfo *info);
//�׾���־
uint8 get_alarm_firstflag(void);
//�׾�������
uint8 get_alarm_first_part(void);
//�𾯸���
uint8 get_firealarm_nums(void);
void clr_firealarm(void);
//ͨ�������Ų���λ��
uint8 get_alarm_item_bypart(uint8 part);
//���ϸ���
uint8 get_faultalarm_nums(void);
//�Ƿ�Ϊ�׾�
uint8 judge_alarm_first(void);
void init_node_info(void)/*Com0Data_Init*/;
void save_node_info(void);
//���ò����������
void set_node_info(uint32 row,uint32 col,uint8 tmp);
//��ȡ�����������
uint8 get_node_info(uint32 row,uint32 col);
//}
int8 get_node_row(/*uint8 dep,*/uint8 comp);
void save_node_and_nodenums(void)/*CSaveAnn*/;
//��ʼ��ע������
void init_nodenums_info(void)/*AnnCounterInit*/;
//����ע��������flash
void save_nodenums_info(void);
void set_nodenums(uint8 tmp);
uint8 get_nodenums(void);
void add_nodenums(void);
void init_hist_info(void)/*GetHistory*/;
void save_hist_info(void)/*SendHistToFlash*/;
//��ȡ��ʷ��¼��Ϣ
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
//��ȡ��ʷ��¼ʱ��
void get_hist_datetime(uint32 row,PCF8563_DATE* dateyear)/*gethistory_num*/;
//��ȡ��ʷ��¼��������Ϣ
void get_hist_allinfo(uint32 row, history_st* info);
//������ʷ��¼������Ϣ
void set_hist_allinfo(uint32 row, history_st* info);
//������ʷ��¼����ʷ����
void save_hist_all(void);
//��ʷ��¼�Ƿ�Ϊ������λ��־get_histnum_info(2)
uint8 judge_histnums_full(void);
//������ʷ��¼Ϊ��
void set_histnum_full(void);
//��ʼ����ʷ����
void init_histnums_info(void)/*InitHistInfo*/;
void save_histnums_info(void)/*flash_save_historycounter*/;
//���û���
static void set_histnum_info(uint32 row,uint8 tmp);
//��ȡ����
static uint8 get_histnum_info(uint32 row);
//��ʼ����ʷ��¼����ʷ����
void init_hist_and_histnums(void);
void init_histsufix_info(void);
//��ʼ�����д洢
void init_flash_all(void);
//}
uint8 CheckDepComp(uint8 dep,uint8 comp);
//}
int16 GetNum(uint8 psn0,uint8 psn1,uint8 psn2,uint8 psn3);
void CAddCirCounter(void);
void CSetCirCounter(uint8 tmp);
uint8 CGetCirCounter(void);
int8 GetRow(uint8 t1,uint8 t2);
/////�ж��Ƿ��б��𾯣��� 0���� 1/////�Ƿ�֮ǰ�л�
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
//��������ע����Ϣ
void set_node_all_info(uint32 row,note_info_t *info);



#endif /* end __FlashPara_H */
/*****************************************************************************
**                            End Of File
******************************************************************************/


