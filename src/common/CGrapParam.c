/*
;*********************************************************************************************************
;*                                                
;*                            对象: CGrapParam
;*
;*                        (c) Copyright 2013-2023, 尹海星
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : CGrapParam.c
;* By   : 尹海星
;* 时间 : 2013-06-24
;*********************************************************************************************************
;*/

#define GrapParam_c

#include  "CGrapParam.h"
#include  "Config.h"
#include  "CMaDefine.h"
#include  "CTaskSure.h"



//基地址
void SetBaseAddr(uint8 row,uint8 tmp)
{
    vLocalAddress[row] = tmp;
}
void set_BaseAddr_default(void)
{
#if 1
    SetBaseAddr(0,0);
    SetBaseAddr(1,0);
    SetBaseAddr(2,0);
#else
    SetBaseAddr(0,vLocalAddress[0]);
    SetBaseAddr(1,vLocalAddress[1]);
    SetBaseAddr(2,vLocalAddress[2]);
#endif
}

void AddBaseAddr(uint8 row)
{
    vLocalAddress[row]++;
}
void SubBaseAddr(uint8 row)
{
    vLocalAddress[row]--;
}
uint8 GetBaseAddr(uint8 row)
{
    return vLocalAddress[row];
}
//基地址选择
void AddLocalParaSel(void)
{
    vLocalParaSel++;
}
void SetLocalParaSel(uint8 tmp)
{
    vLocalParaSel = tmp;
}
uint8 GetLocalParaSel(void)
{
    return vLocalParaSel;
}
//防区
//uint8 department[3] = {0};//基地址
//uint8 department_sum = 0;//防区总数
//uint8 department_sel = 1;//选择设置参数
void Set_department(uint8 row,uint8 tmp)
{
    department[row] = tmp;
}
//void set_depart_allzero(void)
//{
//    Set_department(0,0);
//    Set_department(1,0);
//    Set_department(2,0);
//}

void Add_department(uint8 row)
{
    department[row]++;
}
void Sub_department(uint8 row)
{
    department[row]--;
}
uint8 Get_zone_bit(uint8 row)
{
    return department[row];
}
//防区选择3个符号之间的跳变
void Add_department_sel(void)
{
    department_sel++;
}
void Set_department_sel(uint8 tmp)
{
    department_sel = tmp;
}
uint8 Get_zone_bit_sel(void)
{
    return department_sel;
}
void check_localaddr(void)
{
    if(local_addr_value() > MAX_LOOP)
    {
        set_BaseAddr_default();
    }
}






//实际可选的防区 防区：001
//void Setinzone(uint16 tmp)
//{
//    vinzone = tmp;
//}
//void Addinzone(void)
//{
//    vinzone++;
//}
//void Subinzone(void)
//{
//    vinzone--;
//}
//部件注册：
//防区：000 三位数字，可按上下键进行变化
//uint16 Getinzone(void)
//{
//    return vinzone;
//}

void SetComRegFlag(void)
{
    vComRegFlag = 1;
}
void ClrComRegFlag(void)
{
    vComRegFlag = 0;
}

uint8 GetComRegFlag(void)
{
    return vComRegFlag;
}
void AddCompRegParaSel(void)
{
    vCompRegParaSel++;
}
void SetCompRegParaSel(uint8 tmp)
{
    vCompRegParaSel = tmp;
}
uint8 GetCompRegParaSel(void)
{
    return vCompRegParaSel;
}
void SetCompRegDep(uint16 tmp)
{
    vCompRegDep = tmp;
}
void AddCompRegDep(void)
{
    vCompRegDep++;
}
void SubCompRegDep(void)
{
    vCompRegDep--;
}
uint16 GetCompRegDep(void)
{
    return vCompRegDep;//防区
}
//部件数量0~50
void SetCompRegNum(uint16 tmp)
{
    vCompRegNum = tmp;
}
void AddCompRegNum(void)
{
    vCompRegNum++;
}
void SubCompRegNum(void)
{
    vCompRegNum--;
}
uint16 GetCompRegNum(void)
{
//    if(vCompRegNum > MAX_COMP)
//        return COMP_START;
//    else
        return vCompRegNum;
}
void SetCompRegAddr(uint8 tmp)
{
    vCompRegAddr = tmp;
}
void AddCompRegAddr(void)
{
    vCompRegAddr++;
}
void SubCompRegAddr(void)
{
    vCompRegAddr--;
}
uint8 GetCompRegAddr(void)
{
    return vCompRegAddr;
}
void AddCompSetDep(void)
{
    vCompSetDep++;
}
void SubCompSetDep(void)
{
    vCompSetDep--;
}
uint16 GetCompSetDep(void)
{
    return vCompSetDep;
}
void SetCompSetDep(uint16 tmp)
{
    vCompSetDep = tmp;
}
void AddCompSetNum(void)
{
    vCompSetNum++;
}
void SubCompSetNum(void)
{
    vCompSetNum--;
}
uint16 GetCompSetNum(void)
{
    return vCompSetNum;
}
void SetCompSetNum(uint16 tmp)
{
    vCompSetNum = tmp;
}
void SetComSetSelSet(uint8 tmp)
{
    vComSetSelSet = tmp;
}
void AddComSetSelSet(void)
{
    vComSetSelSet++;
}
void SubComSetSelSet(void)
{
    vComSetSelSet--;
}
uint8 GetComSetSelSet(void)
{
    return vComSetSelSet;
}

void AddComSet_seltab(void)
{
    vComSetSel++;
}
void SubComSet_seltab(void)
{
    vComSetSel--;
}
uint8 GetComSet_seltab(void)
{
    return vComSetSel;
}
void SetComSet_seltab(uint8 tmp)
{
    vComSetSel = tmp;
}
void SetYear(uint16 tmp)
{
    vYear=tmp;
}
void AddYear(void)
{
    vYear++;
}
void SubYear(void)
{
    vYear--;
}
uint16 GetYear(void)
{
    return (2000+vYear%1000%100);
    // 	return (vYear);
}
void SetMonth(uint16 tmp)
{
    vMonth = tmp;
}
void AddMonth(void)
{
    vMonth++;
}
void SubMonth(void)
{
    vMonth--;
}
uint16 GetMonth(void)
{
    return vMonth;
}

void AddDay(void)
{
    vDay++;
}
void SubDay(void)
{
    vDay--;
}
uint16 GetDay(void)
{
    return vDay;
}
void SetDay(uint16 tmp)
{
    vDay = tmp;
}

void SetHour(uint16 tmp)
{
    vHour = tmp;
}
void AddHour(void)
{
    vHour++;
}
void SubHour(void)
{
    vHour--;
}
uint16 GetHour(void)
{
    return vHour;
}
void SetMintue(uint16 tmp)
{
    vMintue = tmp;
}
void AddMintue(void)
{
    vMintue++;
}
void SubMintue(void)
{
    vMintue--;
}
uint16 GetMintue(void)
{
    return vMintue;
}
void SetSecond(uint16 tmp)
{
    vSecond = tmp;
}
void AddSecond(void)
{
    vSecond++;
}
void SubSecond(void)
{
    vSecond--;
}
uint16 GetSecond(void)
{
    return vSecond;
}
void SetSelTime(uint8 tmp)
{
    vSelTime = tmp;
}
void AddSelTime(void)
{
    vSelTime++;
}
uint8 GetSelTime(void)
{
    return vSelTime;
}
void SetAnnDep(uint16 tmp)
{
    vAnnDep = tmp;
}
void AddAnnDep(void)
{
    vAnnDep++;
}
void SubAnnDep(void)
{
    vAnnDep--;
}
uint16 GetAnnDep(void)
{
    return vAnnDep;
}
void SetAnnCompNum(uint16 tmp)
{
    vAnnCompNum = tmp;
}
void AddAnnCompNum(void)
{
    vAnnCompNum++;
}
void SubAnnCompNum(void)
{
    vAnnCompNum--;
}
uint16 GetAnnCompNum(void)
{
    return vAnnCompNum;
}
void SetAnnSel(uint8 tmp)
{
    vAnnSel = tmp;
}
void AddAnnSel(void)
{
    vAnnSel++;
}
uint8 GetAnnSel(void)
{
    return vAnnSel;
}

void AddSysCheckDep(void)
{
    vSysCheckDep++;
}
void SubSysCheckDep(void)
{
    vSysCheckDep--;
}
void SetSysCheckDep(uint8 tmp)
{
    vSysCheckDep = tmp;
}
uint8 GetSysCheckDep(void)
{
    return vSysCheckDep;
}

void AddStatusDep(void)
{
    vStatusDep++;
}
void SubStatusDep(void)
{
    vStatusDep--;
}
void SetStatusDep(uint8 tmp)
{
    vStatusDep = tmp;
}
uint8 GetStatusDep(void)
{
    return vStatusDep;
}

void AddStatusComp(void)
{
    vStatusComp++;
}
void SubStatusComp(void)
{
    vStatusComp--;
}
void SetStatusComp(uint8 tmp)
{
    vStatusComp = tmp;
}
uint8 GetStatusComp(void)
{
    return vStatusComp;
}

void AddStatusFlag(void)
{
    vStatusFlag++;
}
void SetStatusFlag(uint8 tmp)
{
    vStatusFlag = tmp;
}
uint8 GetStatusFlag(void)
{
    return vStatusFlag;
}

void AddIntenDep(void)
{
    vIntenDep++;
}
void SubIntenDep(void)
{
    vIntenDep--;
}
void SetIntenDep(uint8 tmp)
{
    vIntenDep = tmp;
}
uint8 GetIntenDep(void)
{
    return vIntenDep;
}

void AddIntenComp(void)
{
    vIntenComp++;
}
void SubIntenComp(void)
{
    vIntenComp--;
}
void SetIntenComp(uint8 tmp)
{
    vIntenComp = tmp;
}
uint8 GetIntenComp(void)
{
    return vIntenComp;
}

void AddIntenFlag(void)
{
    vIntenFlag++;
}
void SetIntenFlag(uint8 tmp)
{
    vIntenFlag = tmp;
}
uint8 GetIntenFlag(void)
{
    return vIntenFlag;
}

