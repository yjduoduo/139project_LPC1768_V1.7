#ifndef STORE_ADDR_H
#define STORE_ADDR_H
#include "include.h"
//#include "componentinfo.h"

#ifdef EXT_STORE_ADDR
#define EXT_STORE_ADDR
#else
#define EXT_STORE_ADDR extern
#endif


#define ADDR_COMP_OFFSET ADDR_COMP_NUMS+1




EXT_STORE_ADDR void init_store(void);

//EXT_STORE_ADDR void set_store_comp_nums(uint8 compnums);
//EXT_STORE_ADDR void set_store_localaddr(uint8 localaddr);
//EXT_STORE_ADDR void set_store_zone_nums(uint8 departallnums);

//EXT_STORE_ADDR void set_store_comp_inzone(uint8 item,uint8 depart);
////EXT_STORE_ADDR void set_store_com_nums(uint8 item,uint8 com_nums);
//EXT_STORE_ADDR void set_store_comp_partnumber(uint8 item,uint8 partnumber);
//EXT_STORE_ADDR void set_store_comp_state(uint8 item,uint8 state);
//EXT_STORE_ADDR void set_store_comp_ciraddr(uint8 item,uint8 ciraddr);

//get
//EXT_STORE_ADDR uint32 get_store_localaddr(void);
//EXT_STORE_ADDR uint32 get_store_zone_nums(void);
//EXT_STORE_ADDR uint32 get_store_comp_nums(void);

//EXT_STORE_ADDR uint32 get_store_comp_inzone(uint8 item);
//EXT_STORE_ADDR uint32 get_store_com_nums(uint8 item);
//EXT_STORE_ADDR uint32 get_store_comp_partnumber(uint8 item);
EXT_STORE_ADDR uint32 get_store_comp_state(uint8 item);
//EXT_STORE_ADDR uint32 get_store_comp_ciraddr(uint8 item);
EXT_STORE_ADDR uint32 get_comp_ciraddr_zp(uint8 inzone,uint8 partnumber);
//get null address
EXT_STORE_ADDR uint32 get_storepos(void);

//clr

EXT_STORE_ADDR void clr_store_comp_info(uint8 item);
//judge
EXT_STORE_ADDR uint8 judge_store_new(uint8 item);

//add
EXT_STORE_ADDR void add_store_comp_nums(void);
//sub
EXT_STORE_ADDR void sub_store_comp_nums(void);
#endif // STORE_ADDR_H
