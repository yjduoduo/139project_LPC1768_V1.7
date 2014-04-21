/*
;*********************************************************************************************************
;*                                                
;*                            ����: alarmenu
;*
;*                        (c) Copyright 2013-2023, ������
;*                              All Rights Reserved
;*                                    Ver1.0
;* File : alarmenu.c
;* By   : ������
;* ʱ�� : 2013-06-24
;*********************************************************************************************************
;*/
#include  "include.h"
#include  "alarmenu.h"
#include  "CFlashParam.h"
#include  "store_addr.h"



//addr0�׵�ַ,addr1������ַ,alarmsum��������,cnt�������� num ע�����
void Alarm_Menu(uint8 fisrtpart,uint8 otherpart,uint8 cirAddr,
                uint16 alarmsum,uint8 type,PCF8563_DATE *timed)
{
	uint8 i=0;
	uint8 j=0;
	uint8 AnnFlag=1;
	uint8 num=1;
	uint8 row;
	uint8 hz[]="�׾����������̸����ֱ����������������";
    ClearScreen(0);
    if(fisrtpart >= COMP_START && fisrtpart <= MAX_COMP )
	{
        //�׾�,show zone and partnumber
		DisplayJBHZK(1,0,0,((hz[0]<<8)+hz[1]));
		DisplayJBHZK(1,0,16,((hz[2]<<8)+hz[3]));
		Displaynumber(1,0,32,0x0A);
        Displaynumber(1,0,40,(fisrtpart/10));
        Displaynumber(1,0,48,(fisrtpart%10));
        //����
        DisplayJBHZK(2,0,0,((hz[8]<<8)+hz[9]));
        DisplayJBHZK(2,0,16,((hz[10]<<8)+hz[11]));
        Displaynumber(2,0,32,0x0A);
        Displaynumber(2,0,40,(alarmsum/10));
        Displaynumber(2,0,48,(alarmsum%10));


			//��
        DisplayJBHZK(2,2,16,((hz[4]<<8)+hz[5]));
        DisplayJBHZK(2,2,32,((hz[6]<<8)+hz[7]));

		
        //	��·��ַ
        Displaynumber(1,2,32,0x0A);
		Displaynumber(1,2,40,(cirAddr/100));
		Displaynumber(1,2,48,(cirAddr%100/10));
        Displaynumber(1,2,56,(cirAddr%100%10));

		
		
		if(type == 0x30)
		{
			//���ͣ�����
            DisplayJBHZK(1,2,0,((hz[12]<<8)+hz[13]));
            DisplayJBHZK(1,2,16,((hz[14]<<8)+hz[15]));
		}
		else if(type == 0x31)
		{
			//���ͣ�����
            DisplayJBHZK(1,2,0,((hz[16]<<8)+hz[17]));
            DisplayJBHZK(1,2,16,((hz[18]<<8)+hz[19]));
		}
		else if(type == 0x32)
		{
			//���ͣ��ֱ�
            DisplayJBHZK(1,2,0,((hz[20]<<8)+hz[21]));
            DisplayJBHZK(1,2,16,((hz[22]<<8)+hz[23]));
		}
		else if(type == 0x33)
		{
			//���ͣ�����
            DisplayJBHZK(1,2,0,((hz[24]<<8)+hz[25]));
            DisplayJBHZK(1,2,16,((hz[26]<<8)+hz[27]));
		}
		else if(type == 0x34)
		{
			//���ͣ�����
            DisplayJBHZK(1,2,0,((hz[28]<<8)+hz[29]));
            DisplayJBHZK(1,2,16,((hz[30]<<8)+hz[31]));
		}
		else if(type == 0x35)
		{
			//���ͣ����
            DisplayJBHZK(1,2,0,((hz[32]<<8)+hz[33]));
            DisplayJBHZK(1,2,16,((hz[34]<<8)+hz[35]));
		}
		else if(type == 0x36)
		{
			//���ͣ�����
            DisplayJBHZK(1,2,0,((hz[36]<<8)+hz[37]));
            DisplayJBHZK(1,2,16,((hz[38]<<8)+hz[39]));
		}
		
		
		//���� ʱ��
        Displaynumber(1,4,0,(((timed->year%1000)%100)/10));
        Displaynumber(1,4,8,(timed->year%10%100%10));
		//Display(1,4,32,81);	  // ��
        Displaynumber(1,4,16,(timed->month / 10));
        Displaynumber(1,4,24,(timed->month % 10));
		// Display(2,4,0,82);	// ��
        Displaynumber(1,4,32,(timed->day / 10));
        Displaynumber(1,4,40,(timed->day % 10));
		//ʱ
        Displaynumber(1,4,48,(timed->hour/10));
        Displaynumber(1,4,56,(timed->hour%10));
// 		Displaynumber(2,4,48,0x0A);
        Displaynumber(2,4,0,(timed->minute/10));
        Displaynumber(2,4,8,(timed->minute%10));
// 		Displaynumber(1,6,56,0x0A);
        Displaynumber(2,4,16,(timed->second/10));
        Displaynumber(2,4,24,(timed->second%10));
        //�鿴�Ƿ���ע������ finding note of zone's partnumber
        row = GetAnnRow(otherpart);
		//�����ַע��		
        if((row > 0)&&(row <= MAX_COMP)&&(INITVAL != row))
		{
			if((GetCom0Ann(row,3)>=0x30)&&(GetCom0Ann(row,3)<=0x39))
			{
                Displaynumber(1,6,0,GetCom0Ann(row,3)-0x30);
				i = 4;
				j=1;
				
			}		
			else if((GetCom0Ann(row,3)>=0x61)&&(GetCom0Ann(row,3)<=0x7a))
			{
                Display1(1,6,0,GetCom0Ann(row,3)-0x30);
				i=4;
				j=1;
			}
			else if((GetCom0Ann(row,3)>=0xb0)&&(GetCom0Ann(row,3)<0xff))
			{
				DisplayJBHZK(1,6,0,((GetCom0Ann(row,3)<<8)+GetCom0Ann(row,4)));
				i=5;
				j=2;
			}
// 			else
// 				AnnFlag=0;
			while(AnnFlag)
			{
				if((GetCom0Ann(row,i)>=0xb0)&&(GetCom0Ann(row,i)<0xff))
				{
					if((j==7)&&(num==1))
					{
						num=2;
						j=0;
					}
					DisplayJBHZK(num,6,8*j,((GetCom0Ann(row,(i))<<8)+GetCom0Ann(row,(i+1))));
					i += 2;
					j += 2;
				}
				else if((GetCom0Ann(row,i)>=0x30)&&(GetCom0Ann(row,i)<=0x39))
				{
					Displaynumber(num,6,8*j,(GetCom0Ann(row,i)-0x30));
					i += 1;
					j += 1;
				}
				else if((GetCom0Ann(row,i)>=0x41)&&(GetCom0Ann(row,i)<=0x5a))
				{
					Display1(num,6,8*j,(GetCom0Ann(row,i)-0x27));
					i += 1;
					j += 1;
				}
				else if((GetCom0Ann(row,i)>=0x61)&&(GetCom0Ann(row,i)<=0x7a))
				{
					Display1(num,6,8*j,(GetCom0Ann(row,i)-0x61));
					i += 1;
					j += 1;
				}
				else
					AnnFlag=0;
				if(GetCom0Ann(row,i)==0x87)
					AnnFlag=0;
				if(j>=8)
				{
					j=0;
					num=2;
				}
			}
		}
	}	 		
}



