//#ifndef COMPONENTINFO_H
//#define COMPONENTINFO_H
//#include "include.h"

//#ifdef EXT_COMPONENT
//#define EXT_COMPOIENT
//#else
//#define EXT_COMPOIENT extern
//#endif

//#define SIZE_COMPOENT 51/*5*MAX_COMP/4*/
////����ע�Ჿ������
//typedef union _type_component{
//    uint32 Word[SIZE_COMPOENT];
////    uint16   UByte[SIZE_COMPOENT>>1];
////    uint8    Byte[SIZE_COMPOENT>>2];
//    struct{
//        struct{
//            struct{
//                uint8 inzone;//���ڷ���
////                uint8 com_nums;   //�˷���������
//                uint8 partnumber;  //������
//                uint8 state;  //״̬
//            }component;
//            uint8 ciraddr;//��·��ַ
//        }Attr[MAX_COMP];
//        uint8 zone_nums;//��������
//        uint8 localaddr;//����ַ
//        uint8 reg_nums;//ע������
//    }ops_comp;

//}type_component;

//enum Compent_State{
//    Compent_Normal,
//    Compent_BreakDown,
//    Compent_Fault
//};


////#define _VAR_COMPONENT
//#ifdef _VAR_COMPONENT
//type_component m_comp;
//#endif

//#define FUNC_COMPONENT
//#ifdef FUNC_COMPONENT
////���е�������ֻΪstore_addrʹ��


//EXT_COMPOIENT void init_Component_ctrl(void);

//EXT_COMPOIENT void set_localaddr(uint8 localaddr);
//EXT_COMPOIENT void set_total_regnums(uint8 total_reg_nums);
//EXT_COMPOIENT void set_zone_nums(uint8 zone_nums);

//EXT_COMPOIENT void set_component_attr_inzone(uint8 item,uint8 depart);
//EXT_COMPOIENT void set_component_attr_partnumber(uint8 item,uint8 partnumber);
//EXT_COMPOIENT void set_component_attr_ciraddr(uint8 item,uint8 ciraddr);
//EXT_COMPOIENT void set_component_attr_state(uint8 item,uint8 state);
////EXT_COMPOIENT void set_component_attr_com_nums(uint8 item,uint8 com_nums);

////get attr
//EXT_COMPOIENT uint8 get_localaddr(void);
//EXT_COMPOIENT uint8 get_total_regnums(void);
//EXT_COMPOIENT uint8 get_zone_nums(void);

//EXT_COMPOIENT uint8 get_component_attr_inzone(uint8 item);
//EXT_COMPOIENT uint8 get_component_attr_partnumber(uint8 item);
//EXT_COMPOIENT uint8 get_component_attr_ciraddr(uint8 item);
//EXT_COMPOIENT uint8 get_component_attr_state(uint8 item);
////EXT_COMPOIENT uint8 get_component_attr_com_nums(uint8 item);



////set all attr
//EXT_COMPOIENT void set_component_attr_all(uint8 item,uint8 localaddr,uint8 depart,
//                        uint8 partnumber,uint8 ciraddr,uint8 state);
//#endif


//#endif // COMPONENTINFO_H
