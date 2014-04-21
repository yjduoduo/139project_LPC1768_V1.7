/*
;*********************************************************************************************************
;*                                                
;*                            对象: CGrapParam
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CGrapParam.h
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/
// #include  "CGrapParam.h"
#include  "Config.h"
#ifndef GrapPara_H
#define GrapPara_H

#ifdef GrapParam_c

// 本机设置
uint8 vLocalAddress[3] = {1,5,0};//基地址,默认150
//uint8 vinzone = 0;//防区总数
uint8  vLocalParaSel = 1;//选择设置参数

//防区数量
uint8 department[3] = {0};//基地址
uint8 department_sum = 0;//防区总数
uint8 department_sel = 1;//选择设置参数

//部件注册
uint8 vComRegFlag = 0;//界面部件注册标志
uint16 vCompRegDep = 0;//防区
uint16 vCompRegNum = 1;//部件
uint8 vCompRegAddr=0;//地址
uint8  vCompRegParaSel = 2;//选择设置参数,默认选择《部件》

//部件设置
uint16 vCompSetDep = 0;//防区
uint16 vCompSetNum = 1;//部件,
uint8  vComSetSelSet = 0;//选择设置参数,default is case 0:启用，屏蔽与删除
uint8  vComSetSel = 2;//选择设置参数，tab按键的位置,默认为选择此项

//日期/时间
uint16 vYear = 0;
uint16 vMonth = 0;
uint16 vDay = 0;
uint16 vHour = 0;
uint16 vMintue = 0;
uint16 vSecond = 0;
uint8 vSelTime = 1;

//注释  现已不用
uint16 vAnnDep = 0;
uint16 vAnnCompNum = 0;
uint8 vAnnSel = 1;

//系统查询
uint8 vSysCheckDep = 0;

//部件状态
uint8 vStatusDep=0;//防区
uint8 vStatusComp=1;//部件
uint8 vStatusFlag=1;//状态标志

//部件信号强度
uint8 vIntenDep=0;//防区
uint8 vIntenComp=0;//部件
uint8 vIntenFlag=1;//强度标志位
#endif
// 本机设置
void SetBaseAddr(uint8 row,uint8 tmp);
void AddBaseAddr(uint8 row);
void SubBaseAddr(uint8 row);
uint8 GetBaseAddr(uint8 row);

void set_BaseAddr_default(void);

void AddLocalParaSel(void);
void SetLocalParaSel(uint8 tmp);
uint8 GetLocalParaSel(void);

//防区数量
void Set_department(uint8 row,uint8 tmp);
//void set_depart_allzero(void);
void Add_department(uint8 row);
void Sub_department(uint8 row);
uint8 Get_zone_bit(uint8 row);
//防区选择3个符号之间的跳变
void Add_department_sel(void);
void Set_department_sel(uint8 tmp);
uint8 Get_zone_bit_sel(void);
void check_localaddr(void);


//void Setinzone(uint16 tmp);
//void Addinzone(void);
//void Subinzone(void);
//uint16 Getinzone(void);
//部件注册
void SetComRegFlag(void);
uint8 GetComRegFlag(void);
void ClrComRegFlag(void);

void AddCompRegParaSel(void);
void SetCompRegParaSel(uint8 tmp);
uint8 GetCompRegParaSel(void);

void SetCompRegDep(uint16 tmp);
void AddCompRegDep(void);
void SubCompRegDep(void);
uint16 GetCompRegDep(void);

void SetCompRegAddr(uint8 tmp);
void AddCompRegAddr(void);
void SubCompRegAddr(void);
uint8 GetCompRegAddr(void);

void SetCompRegNum(uint16 tmp);
void AddCompRegNum(void);
void SubCompRegNum(void);
uint16 GetCompRegNum(void);
//部件设置
void AddCompSetDep(void);
void SubCompSetDep(void);
uint16 GetCompSetDep(void);
void SetCompSetDep(uint16 tmp);

void AddCompSetNum(void);
void SubCompSetNum(void);
uint16 GetCompSetNum(void);
void SetCompSetNum(uint16 tmp);

void SetComSetSelSet(uint8 tmp);
void AddComSetSelSet(void);
void SubComSetSelSet(void);
uint8 GetComSetSelSet(void);

void AddComSet_seltab(void);
void SubComSet_seltab(void);
uint8 GetComSet_seltab(void);
void SetComSet_seltab(uint8 tmp);
//日期/时间
void SetYear(uint16 tmp);
void AddYear(void);
void SubYear(void);
uint16 GetYear(void);

void SetMonth(uint16 tmp);
void AddMonth(void);
void SubMonth(void);
uint16 GetMonth(void);

void AddDay(void);
void SubDay(void);
uint16 GetDay(void);
void SetDay(uint16 tmp);

void SetHour(uint16 tmp);
void AddHour(void);
void SubHour(void);
uint16 GetHour(void);

void SetMintue(uint16 tmp);
void AddMintue(void);
void SubMintue(void);
uint16 GetMintue(void);

void SetSecond(uint16 tmp);
void AddSecond(void);
void SubSecond(void);
uint16 GetSecond(void);

void SetSelTime(uint8 tmp);
void AddSelTime(void);
uint8 GetSelTime(void);

void SetAnnDep(uint16 tmp);
void AddAnnDep(void);
void SubAnnDep(void);
uint16 GetAnnDep(void);

void SetAnnCompNum(uint16 tmp);
void AddAnnCompNum(void);
void SubAnnCompNum(void);
uint16 GetAnnCompNum(void);

void SetAnnSel(uint8 tmp);
void AddAnnSel(void);
uint8 GetAnnSel(void);
//系统查询
void AddSysCheckDep(void);
void SubSysCheckDep(void);
void SetSysCheckDep(uint8 tmp);
uint8 GetSysCheckDep(void);
//部件状态
void AddStatusDep(void);
void SubStatusDep(void);
void SetStatusDep(uint8 tmp);
uint8 GetStatusDep(void);

void AddStatusComp(void);
void SubStatusComp(void);
void SetStatusComp(uint8 tmp);
uint8 GetStatusComp(void);

void AddStatusFlag(void);
void SetStatusFlag(uint8 tmp);
uint8 GetStatusFlag(void);

//部件信号强度
void AddIntenDep(void);
void SubIntenDep(void);
void SetIntenDep(uint8 tmp);
uint8 GetIntenDep(void);

void AddIntenComp(void);
void SubIntenComp(void);
void SetIntenComp(uint8 tmp);
uint8 GetIntenComp(void);

void AddIntenFlag(void);
void SetIntenFlag(uint8 tmp);
uint8 GetIntenFlag(void);
#endif//GrapPara_H


