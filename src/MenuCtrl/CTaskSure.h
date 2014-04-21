/*
;*********************************************************************************************************
;*                                                
;*                            ����: CTaskSure
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File :CTaskSure.h
;* By   : ������
;* ʱ�� : 2013-06-28
;*********************************************************************************************************
;*/

// #include  "CTaskSure.h"



#define ENTER_MENU 1
#define EXIT_MENU 0


#define DEFAULT_LOCALADDR (150)




#define MENU_SAVE_NONE 0x00  /* �����棬����ʾ*/
#define MENU_SAVE_DONE 0x01 /*����ɹ� */
#define MENU_SAVING 0x02    /*���ڱ��� */
#define MENU_SAVETIPS 0x03    /*��ʾ����*/
#define MENU_LOCALADDR_NOCHANGE 0x04 /*��ַδ�ı䣬������*/

#define MENU_COMPSET_TIPS  0x10/* �����������·�ʱ��ʾ*/
#define MENU_COMPSET_OPS_DONE 0x09 /*�������*/
#define MENU_COMPSET_STARTED 0x08
#define MENU_COMPSET_STOPED  0x07
#define MENU_COMPSET_DELING         0x06
#define MENU_COMPSET_OPSING       0x05
#define MENU_COMPSET_ERR          0x04
#define MENU_COMPSET_OK_DEL     0x03



//date and time
#define MENU_DATA_NONE  0x00
#define MENU_DATA_TIPS  0x01
#define MENU_DATA_DONE  0x02
#define MENU_DATA_SAVING 0x03


//����״̬
#define MENU_COMPSTATUS_INVALID 0x22 /*δע�Ჿ��*/


//#define MASK_VAL_START 0xff
//#define MASK_VAL_STOP  0x01

#define INZONE_DEFAULT 0x00


// //��������
// #define OPSTYPE_START (0x00)
// #define OPSTYPE_STOP  (0x01)
// #define OPSTYPE_DEL   (0x02)



void SetZjFlag(uint8 tmp);
uint8 GetZjFlag(void);
void Set_Note_Flag(void);
void Clr_Note_Flag(void);
uint8 Get_Note_Flag(void);
//void MaskPSNInit(void);
//void GetMaskPSN(void);
//void SaveMaskPSN(void);
//uint8 CGetMaskPSN(uint8 row);
void CLevel1_Sure(uint8 tmp);
void setup_Sure(uint8 tmp);
void query_Sure(uint8 tmp);
void test_Sure(uint8 tmp);
void CLevel24_Sure(uint8 tmp);
void CLevel27_Sure(void);
void CLevel3_Sure(uint8 tmp);
void menu_press_ok_complete(uint8 line);
void menu_setup_done(void);
void menu_press_ok_save(void);
void SetSpeaker_ON(void);
void SetSpeaker_OFF(void);
uint8 GetSpeaker_Flag(void);
void menu_ops_done(void);
//����ֵַ������ֵ
uint16 local_addr_value(void);
//uint8 department_val(void);
void query_compstatus_ok(void);
void menu_compset(void);
void menu_comp_masked(void);
void menu_comp_started(void);
void menu_opsing(void);
//uint8 enter_flag=EXIT_MENU;

void set_enter_flag(void);
uint8 get_enter_falg(void);
void clr_enter_flag(void);
void menu_deling(void);
void menu_comp_noreg(void);

//�����־
void set_entry_localaddr_flag(void);
uint8 get_entry_localaddr_flag(void);
void clr_entry_localaddr_flag(void);
void reset_ok(void);
