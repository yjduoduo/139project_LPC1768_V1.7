/*
;*********************************************************************************************************
;*                                                
;*                            对象: CCompReg
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CCompReg.h
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "Config.h"
// #include  "CCompReg.h"


#define REG_SUC 1  //注册成功
#define REGD_COMP 2  //部件已注册
#define REGD_DEV  3  //设备已注册
#define REG_CIR_OVERFLOW 4
#define REG_COMP_OVERFLOW 5
#define REG_REGING  6//注册中
#define REG_INVALID_COMP 7


void CompReg_menu(uint16 department,uint16 tmp,uint8 regf,uint8 tm2,uint8 rflag,uint8 sureflag);
void menu_compaddr(uint8 line);
void menu_compstatus(void);
void menu_comptype(void);
