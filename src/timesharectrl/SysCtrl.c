#define CSysRunFlag_C
#include "SysCtrl.h"

#define B100USFLAG  m_SysRun.Flag.b100us
#define B20MSFLAG   m_SysRun.Flag.b20ms
#define B100MSFLAG  m_SysRun.Flag.b100ms
#define B500MSFLAG  m_SysRun.Flag.b500ms
#define B1SFLAG    m_SysRun.Flag.b1s
#define B2SFLAG    m_SysRun.Flag.b2s
#define B5SFLAG    m_SysRun.Flag.b5s
#define B1MFLAG    m_SysRun.Flag.b1m

void  Init_CSysRunFlag(void)
{
    m_SysRun.Word=0;
}
//100us
void  Set_CSys100usFlag(void)
{
    B100USFLAG=1;
}

void  Clr_CSys100usFlag(void)
{
    B100USFLAG=0;
}
uint8 Get_CSys100usFlag(void)
{
    return B100USFLAG;
}
//20ms
void   Set_CSys20msFlag(void)
{
    B20MSFLAG=1;

}

void  Clr_CSys20msFlag(void)
{
    B20MSFLAG=0;
}

uint8 Get_CSys20msFlag(void)
{
    return B20MSFLAG;
}
//100ms
Ex_CSysRunFlag  void  Set_CSys100msFlag(void)
{
    B100MSFLAG=1;
}
Ex_CSysRunFlag  void  Clr_CSys100msFlag(void)
{
    B100MSFLAG=0;
}
Ex_CSysRunFlag  uint8 Get_CSys100msFlag(void)
{
    return B100MSFLAG;
}


//500ms
void   Set_CSys500msFlag(void)
{
    B500MSFLAG=1;

}

void  Clr_CSys500msFlag(void)
{
    B500MSFLAG=0;
}

uint8 Get_CSys500msFlag(void)
{
    return B500MSFLAG;
}


void  Set_CSys1SFlag(void)
{
    B1SFLAG=1;
}

void  Clr_CSys1SFlag(void)
{
    B1SFLAG=0;
}

uint8 Get_CSys1SFlag(void)
{
    return B1SFLAG;
}


//2s
void  Set_CSys2SFlag(void)
{
    B2SFLAG=1;
}

void  Clr_CSys2SFlag(void)
{
    B2SFLAG=0;
}
uint8 Get_CSys2SFlag(void)
{
    return B2SFLAG;
}
//5s
void  Set_CSys5SFlag(void)
{
    B5SFLAG=1;
}
void  Clr_CSys5SFlag(void)
{
    B5SFLAG=0;
}
uint8 Get_CSys5SFlag(void)
{
    return B5SFLAG;
}



//1m
void  Set_CSys1MFlag(void)
{
    B1MFLAG=1;
}
void  Clr_CSys1MFlag(void)
{
    B1MFLAG=0;
}
uint8 Get_CSys1MFlag(void)
{
    return B1MFLAG;
}



