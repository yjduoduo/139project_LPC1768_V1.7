///*
//;*********************************************************************************************************
//;*
//;*                            ����: CSendToFlash
//;*
//;*                        (c) Copyright 2013-2023, ������
//;*                              All Rights Reserved
//;*                                    Ver1.0
//;* File : CSendToFlash.c
//;* By   : ������
//;* ʱ�� : 2013-06-24
//;*********************************************************************************************************
//;*/
//#define CSendFlash_H
//#include  "include.h"
//#include  "CSendToFlash.h"
//#include  "CFlashParam.h"
//#include  "CComHandle.h"

//void BaseInfoF_Init(void)
//{
//    /*
//�洢���õĻ�����Ϣ
//(0x00000);
//*/
//    //����ַ0��������ַ��ͨvLocalAddress[3]����ʾ����λ����1������������
//    // 	M25P80_Read_Bytes(0,BaseInfoF,sizeof(BaseInfoF));
//    uint16 i;
//    for(i=0;i<sizeof(BaseInfoF);i++)
//    {
//        BaseInfoF[i]=M25P80_Read_1Byte(FLS_BASEINFO_ADR+i);
//    }
//}
//void SendToArray(uint32 row,uint8 tmp)
//{
//    BaseInfoF[row] = tmp;
//}
//void SendDataToFlash(void)
//{
//    uint16 i;
//    uint16 j;
//    check_lp_running();
//    M25P80_Section_Erase(FLS_BASEINFO_ADR);
//    for(i=0;i<sizeof(BaseInfoF);i++)
//    {
//        M25P80_Write_1Byte(i,BaseInfoF[i]);
//        for(j=0;j<10;j++);
//    }


//}
//uint8 GetBaseInfoF(uint8 row)
//{
//    return BaseInfoF[row];
//}


////void CheckFalshData(void)
////{
////    uint16 i;
////    for(i=0;i<sizeof(BaseInfoF);i++)
////    {
////        if(!(BaseInfoF[i]==M25P80_Read_1Byte(i)))
////        {
////            while(1);
////        }
////    }

////}

////void FlashFault(void)
////{

////}


////void SaveHistoryList(uint8 num)
////{
////    uint8 vAnnRow;
////    uint8 vHisC[2];
////    uint8 i,k;
////    vAnnRow = GetAnnRow(GetPSNFormFlash(num,4),GetPSNFormFlash(num,5));
////    //�洢��ʷ��¼
////    SetHistoryList(GetHistConter(),0,num);
////    SetHistoryList(GetHistConter(),1,GetDatatoFlash(num,COM_POS_DEVTYPE));
////    SetHistoryList(GetHistConter(),2,GetDatatoFlash(num,COM_POS_COMSEL));
////    SetHistoryList(GetHistConter(),3,GetDatatoFlash(num,COM_POS_DEVSTATE));
////    SetHistoryList(GetHistConter(),4,GetDatatoFlash(num,COM_POS_HIYEAR));
////    SetHistoryList(GetHistConter(),5,GetDatatoFlash(num,COM_POS_LOWYEAR));
////    SetHistoryList(GetHistConter(),6,GetDatatoFlash(num,COM_POS_MONTH));
////    SetHistoryList(GetHistConter(),7,GetDatatoFlash(num,COM_POS_DAY));
////    SetHistoryList(GetHistConter(),8,GetDatatoFlash(num,COM_POS_HOUR));
////    SetHistoryList(GetHistConter(),9,GetDatatoFlash(num,COM_POS_MIN));
////    SetHistoryList(GetHistConter(),10,GetDatatoFlash(num,COM_POS_SEC));
////    SetHistoryList(GetHistConter(),11,vAnnRow);
////    SetHistoryList(GetHistConter(),12,GetDatatoFlash(num,COM_POS_DEVTYPE));
////    SetHistoryList(GetHistConter(),13,GetDatatoFlash(num,COM_POS_DEVTYPE));
////    AddHistConter();
////    if(GetHistConter()==1000)
////        SetHistConter(0);
////    vHisC[0]=(uint8)(GetHistConter()>>8);
////    vHisC[1]=(uint8)(GetHistConter());
////    //�洢��flash
////    check_lp_running();
////    M25P80_Section_Erase(0x60000);
////    for(i=0;i<2;i++)
////    {
////        M25P80_Write_1Byte((0x60000+i),vHisC[i]);
////        for(k=0;k<10;k++);
////    }

////    SendHistToFlash();

////}



