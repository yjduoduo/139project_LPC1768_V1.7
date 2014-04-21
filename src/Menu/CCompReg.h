/*
;*********************************************************************************************************
;*                                                
;*                            ����: CCompReg
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompReg.h
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "Config.h"
// #include  "CCompReg.h"


#define REG_SUC 1  //ע��ɹ�
#define REGD_COMP 2  //������ע��
#define REGD_DEV  3  //�豸��ע��
#define REG_CIR_OVERFLOW 4
#define REG_COMP_OVERFLOW 5
#define REG_REGING  6//ע����
#define REG_INVALID_COMP 7


void CompReg_menu(uint16 department,uint16 tmp,uint8 regf,uint8 tm2,uint8 rflag,uint8 sureflag);
void menu_compaddr(uint8 line);
void menu_compstatus(void);
void menu_comptype(void);
