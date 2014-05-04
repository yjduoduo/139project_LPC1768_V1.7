#include "store_addr.h"
#include "CSendToFlash.h"
#define FUNC_COMPONENT
#include "componentinfo.h"
#include  "CNodeInfo.h"
#include  "CFlashParam.h"

////单个部件结构所占内容大小
//#define COMP_SINGLESIZE 4

////get store addr
//uint32 get_store_addr_comp_inzone(uint8 item)
//{
//    if(item<MAX_COMP)
//        return COMP_SINGLESIZE*item+ADDR_COMP_OFFSET;
//    else
//        return 0;
//}
//uint32 get_store_addr_comp_partnumber(uint8 item)
//{
//    if(item<MAX_COMP)
//        return COMP_SINGLESIZE*item+1+ADDR_COMP_OFFSET;
//    else
//        return 0;
//}
//uint32 get_store_addr_comp_state(uint8 item)
//{
//    if(item<MAX_COMP)
//        return COMP_SINGLESIZE*item+2+ADDR_COMP_OFFSET;
//    else
//        return 0;
//}
//uint32 get_store_addr_comp_ciraddr(uint8 item)
//{
//    if(item<MAX_COMP)
//        return COMP_SINGLESIZE*item+3+ADDR_COMP_OFFSET;
//    else
//        return 0;
//}




////
//uint32 get_store_localaddr(void)
//{
//    if( 0xff == get_basic_info(ADDR_LOCALADDR))
//        return 0;
//    else
//        return get_basic_info(ADDR_LOCALADDR);
//}
//uint32 get_store_zone_nums(void)
//{
//    if( 0xff == get_basic_info(ADDR_ZONE_NUMS))
//        return 0;
//    else
//        return get_basic_info(ADDR_ZONE_NUMS);
//}
//uint32 get_store_comp_nums(void)
//{
//    if(0xff ==get_basic_info(ADDR_COMP_NUMS))
//        return 0;
//    else
//        return get_basic_info(ADDR_COMP_NUMS);
//}





//uint32 get_store_comp_inzone(uint8 item)
//{
//    return get_basic_info(get_store_addr_comp_inzone(item));
//}
//uint32 get_store_comp_partnumber(uint8 item)
//{
//    return get_basic_info(get_store_addr_comp_partnumber(item));
//}
//uint32 get_store_comp_state(uint8 item)
//{
//    return get_basic_info(get_store_addr_comp_state(item));
//}
//uint32 get_store_comp_ciraddr(uint8 item)
//{
//    return get_basic_info(get_store_addr_comp_ciraddr(item));
//}



//void set_store_comp_inzone(uint8 item,uint8 depart)
//{
//    set_basic_info(get_store_addr_comp_inzone(item),depart);
//    //set_component_attr_inzone(item,depart);
//}
////void set_store_com_nums(uint8 item,uint8 com_nums)
////{
////    set_basic_info(get_store_com_nums(item),com_nums);
////    //set_component_attr_com_nums(item,com_nums);
////}
//void set_store_comp_partnumber(uint8 item,uint8 partnumber)
//{
//    set_basic_info(get_store_addr_comp_partnumber(item),partnumber);
//    //set_component_attr_partnumber(item,partnumber);
//}
//void set_store_comp_state(uint8 item,uint8 state)
//{
//    set_basic_info(get_store_addr_comp_state(item),state);
//    //set_component_attr_state(item,state);
//}
//void set_store_comp_ciraddr(uint8 item,uint8 ciraddr)
//{
//    set_basic_info(get_store_addr_comp_ciraddr(item),ciraddr);
//    //set_component_attr_ciraddr(item,ciraddr);
//}

//get null address
uint32 get_storepos(void)
{
    uint8 i;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(judge_store_new(i))
            return i;
    }
    return 0;
}

uint32 get_comp_ciraddr_zp(uint8 inzone,uint8 partnumber)
{
    uint8 i;
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if((inzone == get_comp_inzone(i))&&
                (partnumber == get_comp_partnumber(i)))
            return get_comp_ciraddr(i);
    }
    return 0;
}
//查找此回路上探头的总量
static uint8 inqury_ciraddr(uint8 item)
{
    uint8 i;
    uint8 sum=0;
    uint8 ciraddr=get_comp_ciraddr(item);
    for(i=COMP_START;i<=MAX_COMP;i++)
    {
        if(ciraddr == get_comp_ciraddr(i))
            sum++;
    }
    return sum;
}

//clr
void clr_store_comp_info(uint8 item)
{
    //反注册，回路中的地址,不能这么干，一个回路可以挂接多个探头
    //    ClrReg_CNodeInfo(get_comp_ciraddr(item));
    //查找此回路上是否存在其它设备，如果不存在了，反注册回路地址

    //
    if(inqury_ciraddr(item) <=1)//如果回路上没有相应的注册探头，则删除此回路
        ClrReg_CNodeInfo(get_comp_ciraddr(item));

    clr_comp_all(item);
}
//judge
uint8 judge_store_new(uint8 item)
{
    if(item > MAX_COMP)
        return 0;
    if((get_comp_inzone(item) == 0xff)
            &&(get_comp_partnumber(item) == 0xff)
            &&(get_comp_ciraddr(item) == 0xff))
        return 1;
    else
        return 0;
}
//

//部件总数量


//初始化位置，初始化时将各个数据缓存中
void init_store(void)
{
    uint8 i,j;
    Debug("====query component lists\n");
    Debug("get node nums:%d\n",get_nodenums());

    for(i=COMP_START;i<=MAX_COMP;i++)
    {

        if(get_node_info(i,4) == 31)
        {
            Debug("note info 0~45 [%d]:",i);
            for(j=1;j<=45;j++)
            {
              Debug("%d,",get_node_info(i,j));
            }
            Debug("\n");
        }

//        Debug("note info 0~6 :%d,%d,%d,%d,%d,%d,%d,\n",get_node_info(i,0),
//              get_node_info(i,1),
//              get_node_info(i,2),
//              get_node_info(i,3),
//              get_node_info(i,4),
//              get_node_info(i,5),
//              get_node_info(i,6));


        if(INITVAL == get_comp_ciraddr(i))
            continue;
        if( get_comp_inzone(i) > DEPART)
        {
            Debug("number:%d,inzone is:%d err!\n",i,get_comp_inzone(i));
            continue;
        }
        if(get_comp_partnumber(i) > MAX_COMP)
        {
            Debug("number:%d,partnumber is:%d err! part",i,get_comp_partnumber(i));
            continue;
        }

        Debug("cir addr:%d,inzone:%d,partnumber:%d\n",get_comp_ciraddr(i),
              get_comp_inzone(i),get_comp_partnumber(i));
        Debug("psn0~3:%d,%d,%d,%d\n",get_comp_psn0(i),
              get_comp_psn1(i),
              get_comp_psn2(i),
              get_comp_psn3(i));
        Debug("masked:%d\n",get_mask_info(i));

        Debug("devtype:%d\n",get_comp_devtype(i));


        SetReg_CNodeInfo(get_comp_ciraddr(i));
    }

}



