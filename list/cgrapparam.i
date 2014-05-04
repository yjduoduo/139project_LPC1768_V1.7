#line 1 "..\\src\\common\\CGrapParam.c"












 



#line 1 "..\\src\\common\\CGrapParam.h"












 

#line 1 "..\\src\\APP\\Config.h"












 




 


 


 













enum emTxResult{
	U_TxError = 1,
	U_TxSucc = 0,	
};
	
	
enum emErrorDef{
	U_Error = 1,
	U_Fault = 1,
	U_Usual = 0,	
	
};








 




 
typedef  unsigned  char  tBoolean;
typedef  unsigned char   uchar;                    
typedef  unsigned char   uint8;                    
typedef  signed   char   int8;                     
typedef  unsigned short  uint16;                   
typedef  signed   short  int16;                    
typedef  unsigned int    uint32;                   
typedef  signed   int    int32;                    
typedef  float           fp32;                     
typedef  double          fp64;                     	  
typedef  unsigned long   ulong;



 


#line 16 "..\\src\\common\\CGrapParam.h"






uint8 vLocalAddress[3] = {1,5,0};

uint8  vLocalParaSel = 1;


uint8 department[3] = {0};
uint8 department_sum = 0;
uint8 department_sel = 1;


uint8 vComRegFlag = 0;
uint16 vCompRegDep = 0;
uint16 vCompRegNum = 1;
uint8 vCompRegAddr=0;
uint8  vCompRegParaSel = 2;


uint16 vCompSetDep = 0;
uint16 vCompSetNum = 1;
uint8  vComSetSelSet = 0;
uint8  vComSetSel = 2;


uint16 vYear = 0;
uint16 vMonth = 0;
uint16 vDay = 0;
uint16 vHour = 0;
uint16 vMintue = 0;
uint16 vSecond = 0;
uint8 vSelTime = 1;


uint16 vAnnDep = 0;
uint16 vAnnCompNum = 0;
uint8 vAnnSel = 1;


uint8 vSysCheckDep = 0;


uint8 vStatusDep=0;
uint8 vStatusComp=1;
uint8 vStatusFlag=1;


uint8 vIntenDep=0;
uint8 vIntenComp=0;
uint8 vIntenFlag=1;


void SetBaseAddr(uint8 row,uint8 tmp);
void AddBaseAddr(uint8 row);
void SubBaseAddr(uint8 row);
uint8 GetBaseAddr(uint8 row);

void set_BaseAddr_default(void);

void AddLocalParaSel(void);
void SetLocalParaSel(uint8 tmp);
uint8 GetLocalParaSel(void);


void Set_department(uint8 row,uint8 tmp);

void Add_department(uint8 row);
void Sub_department(uint8 row);
uint8 Get_zone_bit(uint8 row);

void Add_department_sel(void);
void Set_department_sel(uint8 tmp);
uint8 Get_zone_bit_sel(void);
void check_localaddr(void);







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

void AddSysCheckDep(void);
void SubSysCheckDep(void);
void SetSysCheckDep(uint8 tmp);
uint8 GetSysCheckDep(void);

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



#line 18 "..\\src\\common\\CGrapParam.c"

#line 1 "..\\src\\common\\CMaDefine.h"












 















#line 35 "..\\src\\common\\CMaDefine.h"




#line 20 "..\\src\\common\\CGrapParam.c"
#line 1 "..\\src\\MenuCtrl\\CTaskSure.h"












 




















#line 42 "..\\src\\MenuCtrl\\CTaskSure.h"



























void SetZjFlag(uint8 tmp);
uint8 GetZjFlag(void);
void Set_Note_Flag(void);
void Clr_Note_Flag(void);
uint8 Get_Note_Flag(void);




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

uint16 local_addr_value(void);

void query_compstatus_ok(void);
void menu_compset(void);
void menu_comp_masked(void);
void menu_comp_started(void);
void menu_opsing(void);


void set_enter_flag(void);
uint8 get_enter_falg(void);
void clr_enter_flag(void);
void menu_deling(void);
void menu_comp_noreg(void);


void set_entry_localaddr_flag(void);
uint8 get_entry_localaddr_flag(void);
void clr_entry_localaddr_flag(void);
void reset_ok(void);
#line 21 "..\\src\\common\\CGrapParam.c"




void SetBaseAddr(uint8 row,uint8 tmp)
{
    vLocalAddress[row] = tmp;
}
void set_BaseAddr_default(void)
{

    SetBaseAddr(0,0);
    SetBaseAddr(1,0);
    SetBaseAddr(2,0);





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




void Set_department(uint8 row,uint8 tmp)
{
    department[row] = tmp;
}







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
    if(local_addr_value() > 200)
    {
        set_BaseAddr_default();
    }
}


























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
    return vCompRegDep;
}

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

