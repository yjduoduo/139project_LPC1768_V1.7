/*
*********************************************************************************************************
*                               对象: CUartRcv
*                        (c) Copyright 2000-2004, 蒋雪梅
*                              All Rights Reserved
;* File : CUartRcv.c
;* Ver1.0
;* 时间 : 2012-12-08
*********************************************************************************************************
*/
#define   CUartRcv_C	   
#include  "CUartRcv.h"
#include  "CUart.h" 
#include  "CUartDef.h"
#include  "CSemaphore.h" 
#include  "CUartSend.h"
#include  "CSysRunFlag.h" 
#include  "CLcdOffCtrl.h" 
#include  "CSilentCtrl.h"
#include  "CCanSend.h"
#include  "CCtrlAddr.h" 
#include  "CSwitchWin.h"
#include  "CFunIdValue.h"
#include  "CPro11sBuff.h" 
#include  "CSysRunFlag.h"  
#include  "CRunTimeCtrl.h" 
#include  "CNoteSaveCtrl.h"
#include  "CUartSend.h"
#include  "CPhysicalAddr.h"
#include  "CNoteIndexCtrl.h"
#include  "CBoardDef.h"	 
#if (_Board_DOMM == _Board_51S11)	
// #include  "CRProSave.h"
#include  "CRProSave.h" 
#include  "CBKeyProCtrl.h" 
#include  "C11sTo21s.h"
#include  "CCanRcv.h"
#include  "CPro11sDef.h"
#include  "CCan_51S_Def.h"
#endif




void  Init_CUartRcv(void) //初始化函数
{   
	  vUartRcvHead=0; 
    vUartRcvRdFlag=0;	
	  ClrBuff_CUartRcv();  
}

void   ClrBuff_CUartRcv(void)  
{
	  uint16 i;
	  for(i=0;i<cMaxUartRcvNum;i++)
	      vUartRcvBuf[i]=0;
	  ResetCBufCtrl(cMaxUartRcvNum,&vUartRcvBufCtrl); 
	  vUartRcvEndLen=cMaxUartInfoLen;
	  vUartRcvRdFlag=0;	
}

void   Add_CUartRcv(uint8 vRcvData)
{
	  //收齐3个0xff后进入数据保存
	  if(vUartRcvBufCtrl.In)
		{ 
			  if(vUartRcvBufCtrl.In == cUartInfoLenId) //预期文件长度
			  {
					  vUartRcvEndLen=vRcvData+cUartInfoLenId; 
				}
				vUartRcvBuf[GetInPosi_CBuf(&vUartRcvBufCtrl)]=vRcvData;
				if(vUartRcvBufCtrl.In > vUartRcvEndLen)
				{ 
					  vUartRcvRdFlag=1;	 
					  OSSemPost(pUartRxSem);
				}
		}
	  else if(vRcvData==cUartHead)
		{
			  vUartRcvHead++; 
			  if(vUartRcvHead>=3)
				{
					  uint16 i;
					  ClrBuff_CUartRcv();
            for(i=0;i<3;i++)
						{							
					      vUartRcvBuf[GetInPosi_CBuf(&vUartRcvBufCtrl)]=cUartHead;
						}
				}
		} 
		else
		{
			  vUartRcvHead=0;  
		}
}   

 
void   Read_CUartRcv(void)
{
	  if(vUartRcvRdFlag)
		{
        if((vUartRcvBuf[0]==0xff)&&(vUartRcvBuf[1]==0xff)&&(vUartRcvBuf[2]==0xff))
				{
            switch(vUartRcvBuf[cUartComm0Id])
					  {
						     case cUartCommScan:   //09 
									   if(vUartRcvBuf[cUartFlagId]==10)
										 {   
											   Load_CUartSend();
										 }
									   break; 
										 
									case cUartCommScanNew:   //09 
									   if(vUartRcvBuf[cUartFlagId]==10)
										 {   
											   Load_CUartSend();
										 } 
									   break; 
										 
								 case cUartCommRest:   //复位
									   Save_CNoteIndexCtrl(); 
									   SetReset_CSysRunFlag();
						         Set_CLcdOffCtrl(); 
									   break; 		 
										 
								case cUartCommSilen:   //静音 
									   do_CSilentCtrl(); 
						         Set_CLcdOffCtrl(); 
									   break; 

                 case cUartCommAct:   //启停设备 
									   if((vUartRcvBuf[cUartComm2Id]==1)
											 ||(vUartRcvBuf[cUartComm2Id]==2))
										 { 
												 RcvAct_CUartRcv();    
									   } 
								      break; 
								
								 case cUartCommInsul:   //屏蔽设备 
									   if((vUartRcvBuf[cUartComm2Id]==1)
											 ||(vUartRcvBuf[cUartComm2Id]==2))
										 { 
												 RcvInsul_CUartRcv();    
									   } 
								     break; 
										 
								case cUartInStarFlag:   //计算机通讯
							        Set_CUartCommFlag();
								      SetBroad_CCanSend(c11s_BC_EnPro);
							        Init_CSwitchWin(cFunc_DisUart); 
					            Set_CLcdOffCtrl(); 
								      BatInit_CNoteSaveCtrl();
								      break; 	


	              case cUartInMidFlag:   //计算机通讯
									    if(vUartRcvBuf[cUartComm1Id]==cUartSetPro)
											{   
												  SetPro_CUartRcv();
											}
											else if(vUartRcvBuf[cUartComm1Id]==cUartChkPro)
											{  
												  ChkPro_CUartRcv();
											}
											else if(vUartRcvBuf[cUartComm1Id]==cUartSetNote)
											{  //写注释
												  SetNote_CUartRcv();
											}
											else if(vUartRcvBuf[cUartComm1Id]==cUartChkNote)
											{ //读注释
												  ChkNote_CUartRcv();
											}
											else if(vUartRcvBuf[cUartComm1Id]==cUartSetBusPro)
											{ 
												  SetBusPro_CUartRcv();
											}
											else if(vUartRcvBuf[cUartComm1Id]==cUartChkBusPro)
											{ 
												  ChkBusPro_CUartRcv();
											}
						          Set_CLcdOffCtrl(); 
								      break;  
										 
								case cUartInEndFlag:   //计算机通讯
									    BatDone_CNoteSaveCtrl();
									    Save_CNoteIndexCtrl(); 
									    SetReset_CSysRunFlag();
						          Set_CLcdOffCtrl();  
								      break; 		
								
								default:
                     ;									
					  }
				}					
        Init_CUartRcv(); //初始化函数	 
		}		 
}

uint8  UartRcvCkFlag_CUartRcv(void) 
{
	  return vUartRcvCkFlag;
}

uint8  UartAddr_CUartRcv(uint8 vId)
{
	  if(vId < cMaxUartOldRcvNum)
		{
			  return vUartOldRcvBuf[vId];	
		}
		else
		{
			  return 0;	
		}
}

//发送联动编程文件
//将Uart接收的联动保存文件下发至目标板
//同时反馈给计算机
void  SetPro_CUartRcv(void)
{
	  uint8 i;
	  for(i=0;i<3;i++)
		{
	      vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
		} 
	  Init_CPro11sBuff();  
	  Copy_CPro11sBuff(&vUartRcvBuf[cUartSetLpId],vUartRcvBuf[cUartInfoLenId]);  
		vUartRcvCkFlag=c11s_DCk_Pro;
	  #if (_Board_DOMM == _Board_51S11)	   
// 		if((vUartOldRcvBuf[0]==1)||(vUartOldRcvBuf[0]==66))
//  		if(((vUartOldRcvBuf[0])&&(vUartOldRcvBuf[0]<cMaxProLpNum))||(vUartOldRcvBuf[0]==66))
		{
			  Set_CRProSave(Get_CPro11sBuff(),GetLen_CPro11sBuff());				
		} 
		ChkPro_CUartRcv();
	  #else 
	  Load_CPro11sBuff();  
		SetRunTimeCount(1);  
		#endif 
		
}

void   ChkPro_CUartRcv(void)
{
	  //发送查询命令 
	  #if (_Board_DOMM == _Board_51S11)	  
	  {
	       uint8 i;
			   if(vUartRcvCkFlag!=c11s_DCk_Pro)
				 {
						 for(i=0;i<3;i++)
						 {
								 vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
						 }
			   } 
				 InitRcvFileBuff_CCanRcv();
			   m_CanRcvFileBuff[1]=Get_CRProSave(vUartOldRcvBuf[0],vUartOldRcvBuf[1],&m_CanRcvFileBuff[2]);
			   if(!m_CanRcvFileBuff[1])
				 {
					   i=2;
					   m_CanRcvFileBuff[i++]=0xff;
					   m_CanRcvFileBuff[i++]=0xff;
					   m_CanRcvFileBuff[i++]=0xff;
					   m_CanRcvFileBuff[i++]=0;  
					   m_CanRcvFileBuff[1]=i;
				 }
				 else
				 {
					   m_CanRcvFileBuff[1]++;
				 }
	       AnsPro_CUartSend(&m_CanRcvFileBuff[2],m_CanRcvFileBuff[1]+3);
		}
	  #else
	  if(vUartRcvCkFlag==c11s_DCk_Pro)
		{ 
			   SetComm_CCanSend(c11s_DCk_Pro,vUartOldRcvBuf,4);  
		}
		else
		{    
			   uint8 i;
			   for(i=0;i<3;i++)
				 {
						 vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
				 } 
			   SetComm_CCanSend(c11s_DCk_Pro,vUartOldRcvBuf,4);  
		}
		vUartRcvCkFlag=0;
		SetUCanChkRec_CSysRunFlag(); 
	  SetRunTimeCount(1);  
		#endif 
}

//计算机设置注释信息
void   BatChkNote_CUartRcv(void)
{
	  uint8  vUartWtId=cChgUartRcvNum;   
	  vUartRcvBuf[vUartWtId]=vUartRcvBuf[7];
	  vUartRcvBuf[vUartWtId+1]=vUartRcvBuf[cUartSetLpId];
	  vUartRcvBuf[vUartWtId+2]=vUartRcvBuf[cUartSetAddrId];   
	  if(!Ck11sAddr_CPhysicalAddr(vUartRcvBuf[vUartWtId],vUartRcvBuf[vUartWtId+1],vUartRcvBuf[vUartWtId+2]))
		{			
	     BatGet_CNoteSaveCtrl(vUartRcvBuf[vUartWtId],vUartRcvBuf[vUartWtId+1],vUartRcvBuf[vUartWtId+2],(char *)&vUartRcvBuf[vUartWtId+3]);
	     AnsNote_CUartSend(&vUartRcvBuf[vUartWtId],strlen((char *)&vUartRcvBuf[vUartWtId+3])+2); 
		}
} 

void   SetNote_CUartRcv(void)
{
	  uint8 vMach=vUartRcvBuf[7];
	  uint8 vLpNum=vUartRcvBuf[cUartSetLpId];
	  uint8 vAddrNum=vUartRcvBuf[cUartSetAddrId];
	  //检查数据的合法性
	  if(!Ck11sAddr_CPhysicalAddr(vMach,vLpNum,vAddrNum))
		{	 
			  if(Get_CUartCommFlag())
				{
			      BatSave_CNoteSaveCtrl(vMach,vLpNum,vAddrNum,(char *)&vUartRcvBuf[cUartSetNoteId]); 
					  BatChkNote_CUartRcv();
			  }
				else
				{
			      Save_CNoteSaveCtrl(vMach,vLpNum,vAddrNum,(char *)&vUartRcvBuf[cUartSetNoteId]); 
					  ChkNote_CUartRcv();
				} 
		}
}

void   ChkNote_CUartRcv(void)
{
	  uint8  vUartWtId=cChgUartRcvNum;   
	  vUartRcvBuf[vUartWtId]=vUartRcvBuf[7];
	  vUartRcvBuf[vUartWtId+1]=vUartRcvBuf[cUartSetLpId];
	  vUartRcvBuf[vUartWtId+2]=vUartRcvBuf[cUartSetAddrId];   
	  if(!Ck11sAddr_CPhysicalAddr(vUartRcvBuf[vUartWtId],vUartRcvBuf[vUartWtId+1],vUartRcvBuf[vUartWtId+2]))
		{			
	     Get_CNoteSaveCtrl(vUartRcvBuf[vUartWtId],vUartRcvBuf[vUartWtId+1],vUartRcvBuf[vUartWtId+2],(char *)&vUartRcvBuf[vUartWtId+3]);
	     AnsNote_CUartSend(&vUartRcvBuf[vUartWtId],strlen((char *)&vUartRcvBuf[vUartWtId+3])+2); 
		}
} 

//计算机设置总线盘对应关系
void   SetBusPro_CUartRcv(void)
{
	  uint8  vUart2CanId=cChgUartRcvNum;  
	  uint8  vUartRdId=cUartSetLpId; 
	  uint8  i;
	
	  vUartRcvBuf[vUart2CanId++]=vUartRcvBuf[vUartRdId++]+cBusConStarNum-1; //目标板号 
	  vUartRcvBuf[vUart2CanId++]=vUartRcvBuf[vUartRdId++]; //按键
	  vUartRcvBuf[vUart2CanId++]=vUartRcvBuf[vUartRdId++]; //回路
	  vUartRcvBuf[vUart2CanId++]=vUartRcvBuf[vUartRdId++]; //地址
	  vUartRcvBuf[vUart2CanId]=(vUartRcvBuf[vUartRdId]&0xf8)+1; //通道
	
		#if (_Board_DOMM == _Board_51S11)	  
		if(vUartRcvBuf[cUartSetLpId]==1)
		{  
				 tLA4 vSaveAddr;
				 vSaveAddr.Word=0;
				 //转化成最后需要比较处理的物理地址
	       vSaveAddr=LpPA4_C11sTo21s(0,vUartRcvBuf[cChgUartRcvNum+2],vUartRcvBuf[cChgUartRcvNum+3],vUartRcvBuf[cChgUartRcvNum+4]);
		     			
			   Set_CBKeyProCtrl(vUartRcvBuf[cChgUartRcvNum+1],&vSaveAddr);	
         for(i=0;i<2;i++)
				 {
						vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
				 }			
         BusPro_CUartSend((uint8 *)&vUartRcvBuf[cChgUartRcvNum+2],3);   //加载总线盘对应关系 	 
		}
		#else			
	  SetComm_CCanSend(c11s_DS_SetBusPro,&vUartRcvBuf[cChgUartRcvNum],5);   
		vUartRcvCkFlag=c11s_DCk_BusPro;
	  for(i=0;i<2;i++)
		{
	      vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
		}
	  SetRunTimeCount(1);  
		#endif 
	  
}

void   ChkBusPro_CUartRcv(void)
{
	  //发送查询命令 
	  uint8  vUart2CanId=cChgUartRcvNum;  
	  uint8  vUartRdId=cUartSetLpId; 
	  uint8 i;
	  if(vUartRcvCkFlag!=c11s_DCk_BusPro)
		{ 
			   for(i=0;i<2;i++)
				 {
						 vUartOldRcvBuf[i]=vUartRcvBuf[cUartSetLpId+i];
				 }  
		} 
		vUartRdId=0; 
	  vUartRcvBuf[vUart2CanId++]=vUartOldRcvBuf[vUartRdId++]+cBusConStarNum-1; //目标板号 
	  vUartRcvBuf[vUart2CanId++]=vUartOldRcvBuf[vUartRdId++]; //按键 
	  vUartRcvBuf[vUart2CanId++]=0; 
	  vUartRcvBuf[vUart2CanId++]=0; 
		#if (_Board_DOMM == _Board_51S11)	  
		if(vUartRcvBuf[cUartSetLpId]==1)
		{  
				 tLA4 vCkLA4;
         vCkLA4=SLPA2IPA_CPhysicalAddr(Get_CBKeyProCtrl(vUartRcvBuf[cUartSetLpId+1]));			
				 BusPro_CUartSend((uint8 *)&vCkLA4.Byte[1],4);   //加载总线盘对应关系 	 
		}
		#else	 
 	  SetComm_CCanSend(c11s_DCk_BusPro,&vUartRcvBuf[cChgUartRcvNum],4);   
	  SetUCanChkRec_CSysRunFlag(); 
	  SetRunTimeCount(1); 
		#endif 
}

void   RcvAct_CUartRcv(void)   
{
	 uint8 vRdId=cUartMachId;
	 uint8 vWtId=cChgUartRcvNum;
 
	 if((vUartRcvBuf[vRdId]==0)|| //本地命令
			(vUartRcvBuf[vRdId]==GetCtrlAddr()))
	 {
			if(vUartRcvBuf[cUartComm2Id]==1)
			{
					vUartRcvBuf[vWtId++]=c11s_DS_ManuStar; 
			}
			else if(vUartRcvBuf[cUartComm2Id]==2)
			{
				 vUartRcvBuf[vWtId++]=c11s_DS_ManuStop; 
			}	
			vRdId++;
			vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
			vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
			vUartRcvBuf[vWtId++]=1;  
			SetComm_CCanSend(vUartRcvBuf[cChgUartRcvNum],(uint8 *)&vUartRcvBuf[cChgUartRcvNum+1],4);
	 }
	 else
	 {
		   if(vUartRcvBuf[cUartComm2Id]==1)
				{
						vUartRcvBuf[vWtId++]=cw11s_BC_MaStar; 
				}
				else if(vUartRcvBuf[cUartComm2Id]==2)
				{
						vUartRcvBuf[vWtId++]=cw11s_BC_MaStop; 
				}	  
				vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]-1; 
				vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
				vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++];   
				SetEComm_CCanSend(vUartRcvBuf[cChgUartRcvNum],(uint8 *)&vUartRcvBuf[cChgUartRcvNum+1],4); 
	 }
	 Set_CLcdOffCtrl();  
}

void   RcvInsul_CUartRcv(void)   
{
	 uint8 vRdId=cUartMachId;
	 uint8 vWtId=cChgUartRcvNum;
 
	 if((vUartRcvBuf[vRdId]==0)|| //本地命令
			(vUartRcvBuf[vRdId]==GetCtrlAddr()))
	 {
			if(vUartRcvBuf[cUartComm2Id]==1)
			{
					vUartRcvBuf[vWtId++]=c11s_DS_SetInsul; 
			}
			else if(vUartRcvBuf[cUartComm2Id]==2)
			{
				 vUartRcvBuf[vWtId++]=c11s_DS_ClrInsul; 
			}	
			vRdId++;
			vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
			vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
			vUartRcvBuf[vWtId++]=1;  
			SetComm_CCanSend(vUartRcvBuf[cChgUartRcvNum],(uint8 *)&vUartRcvBuf[cChgUartRcvNum+1],4);
	 }
	 else
	 {
				if(vUartRcvBuf[cUartComm2Id]==1)
				{
						vUartRcvBuf[vWtId++]=cw11s_BC_Insul; 
				}
				else if(vUartRcvBuf[cUartComm2Id]==2)
				{
						vUartRcvBuf[vWtId++]=cw11s_BC_ClrInsul; 
				}
        vRdId++;			
				vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
				vUartRcvBuf[vWtId++]=vUartRcvBuf[vRdId++]; 
				vUartRcvBuf[vWtId++]=vUartRcvBuf[cUartMachId];   
				SetEComm_CCanSend(vUartRcvBuf[cChgUartRcvNum],(uint8 *)&vUartRcvBuf[cChgUartRcvNum+1],4); 
	 }
	 Set_CLcdOffCtrl();  
}
