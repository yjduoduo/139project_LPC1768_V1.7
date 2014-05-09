#include "about139.h"
#include "CSoftVerDef.h"
#include  "include.h"
#include  "breakdown.h"
#include  "CFlashParam.h"
#include  "CComHandle.h"



void about_version_Menu(uint8 A,
                        uint8 B,
                        uint8 C,
                        uint8 D)
{
    uint8 hz[]="°æ±¾";
    ClearScreen(0);

    DisplayJBHZK(1,0,32,((hz[0]<<8)+hz[1]));
    DisplayJBHZK(1,0,48,((hz[2]<<8)+hz[3]));
    Displaynumber(1,2,0,A);
    Displaynumber(1,2,8,B);
    Displaynumber(1,2,16,C);
    Displaynumber(1,2,24,D);
}
