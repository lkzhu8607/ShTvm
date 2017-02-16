/******************************************************************************
 *
 *			BNR SDK Project
 *
 ******************************************************************************
 *
 * File :   BnrAcceptBills.c
 *
 * Author : MEI Geneva
 *
 * Date :   09.06.09
 *
 * History of modifications
 * Date       Rev.    Reason
 *
 ******************************************************************************
 * FILE DESCRIPTION *//** @file
 *  Main file for the BNR API client application.
 *
 *  This source code is intended only as a supplement to the BNR API for Windows
 *  and/or on-line documentation.                          
 *                                                                         
 *  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.                                                    
 ***************************************************************************//*
 *
 *  MEI
 *
 *      U.S.A.  1301 Wilson Drive, West Chester, Pennsylvania 19380
 *                      Tel: +1-610-430-2500
 *
 *      C.H.    Ch. Pont-du-Centenaire 109, Plan-les-Ouates, P.O. Box 2650
 *                      Tel: +41-22-884-0505
 *
 *  http://www.meigroup.com
 *
 ************************* Copyright (c) MEI 2009 *****************************
 *
 * The information contained here-in is the property of MEI and is not to be
 * disclosed or used without the prior written permission of MEI. This
 * copyright extends to all media in which this information may be preserved
 * including magnetic storage, computer print-out or visual display.
 *
*****************************************************************************/
#ifndef _BNR_OPERATION_H
#define _BNR_OPERATION_H
#ifndef WIN32
	#define __stdcall
#endif

#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>

#include "BnrCtlL32.h"
#include <iostream>
#include <map>
#include <sstream>
#include <math.h>
#include "public.h"

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (!FALSE)
#endif


using namespace std;
/************************ Defines and typedefs *******************************/
typedef map<UINT32,string> MAP_UINT_STRING;
typedef map<string,UINT32> MAP_STRING_UINT;
typedef map<string,XfsPhysicalCashUnit> MAP_STRING_PCU;
typedef UINT8 BYTE;
typedef UINT16 WORD;

extern bool g_log_operation_thread;
extern bool g_log_status_thread;
extern bool g_log_intermediate;
extern T_XfsCashUnit g_CashUnit;

//暂存区纸币面额
extern int g_StoredNote;

//在第一次CashIn动作没有结束前,禁止发第二次
extern INT32 g_iCashInResult;

//0:不显示界面,托盘区不显示; 1:显示在托盘区
extern BYTE g_ibnrhide;

//用于USB线断开后重新插上,保存BNR的API返回值,判断-1
extern INT32 g_iDoOpen;

//流水号
extern INT32 g_iflow;
//配置文件
struct  tagConfigInfo
{
	int  log_level;
	int log_debug_level;
	char log_dir[64];
	
	int iloaderlock; //补币箱,1:lock; 0:unlock
	//4个循环箱低币位和1个回收箱
	int ReBoxLows[5];
	int ReBoxHighs[5];
	int ReBoxFulls[5];
	int ReBoxEmptys[5];
	int ireonelow;	
	int iretwolow;
	int irethreelow;
	int irefourlow;
};
typedef struct tagConfigInfo ConfigInfo_t;

extern ConfigInfo_t g_ConfigInfo;


//保存找零信息
typedef struct tagBNRResult 
{
	T_BnrXfsResult ocResult;	//BNR动作命令执行结果

	//找零信息保存(0-3对应RE3---RE6,4对应LO1 )
	T_BillCount ReChangeCount[5];
	
	//清币信息数量保存(0-3对应RE3---RE6,4对应LO1 )
	T_BillCount ReClearCount[5];
}BNRResult_t;
extern BNRResult_t	g_BNRResult;
extern unsigned int g_LOClear_Num[8];//清币 1 2 5 10 20 50 100 未知面额
extern unsigned int g_REClear_Num[8];// 清币 1 2 5 10 20 50 100 未知面额

extern unsigned int g_LOAdd_Num[8];//一次补币各面额的数量 1 2 5 10 20 50 100 未知面额
extern unsigned int g_CashBox_Num[8]; //回收箱各面额纸币数量 1 2 5 10 20 50 100 未知面额

typedef struct  tagCashInInfo
{
	T_Amount amount_yuan;	//纸币面额,以元为单位
	T_BillCount billcount;	//纸币数量
}CashInInfo_t;
struct  tagREInfo
{
	T_Amount amount_yuan;	//纸币面额,以元为单位
	T_BillCount billmax;	//最大张数
	BYTE bconfig;	//0:表示不用设置; 1:表示需要设置
};
typedef struct  tagREInfo REInfo_t;

typedef  struct tagBNRStatus 
{
	WORD wInShutter;	//入钞口状态 0:无纸币  1:有纸币
	WORD wReturnShutter;	//退钞口状态
	WORD wStacker;	//暂存状态
	BYTE cCBSafedoor;	//回收箱物理锁状态, 0:已锁上; 1:被打开锁
	BYTE cLOSafedoor;	//补币箱物理锁状态, 0:已锁上; 1:被打开锁
	BYTE cRESafedoor;   //循环箱物理锁状态,0:锁上  1:锁被打开
	BYTE cCBBOX;	//回收箱状态, 0:在位; 1:不在位
	BYTE cLOBOX;	//补币箱状态, 0:在位，非空; 1:不在位; 2:在位，补币箱为空
	BYTE cREBOX[4];  //循环箱，RE3-RE6  0:在位 1:不在位
	UINT32 dwErrorCode;	//纸币模块故障码
	T_ModuleId dwcuid;//回收箱id
}BNRStatus_t;

extern BNRStatus_t g_BNRStatus;

typedef struct tagModuleList 
{
	BYTE iloboxexist; //是否存在补币箱,1:存在; 0:不存在
	char loname[5]; //补币箱物理名
	BYTE ireboxnum; //存在循环箱数量
	BYTE ireboxexist[4]; //4个循环箱是否存在,,1:存在; 0:不存在
	char reboxname[4][6]; //循环箱1~4,物理名	
	T_ModuleId dwloid; //补币箱ID
	T_ModuleId dwreid[4]; //4个循环箱ID
	T_ModuleId dwcbid; //回收箱ID
	char CBSerialNum[16];//回收箱序列号列号
	char RESerialNum[4][16];//循环箱序列号 
	char LOSerialNum[16];//补币箱序列号
}ModuleList_t;
extern ModuleList_t	g_ModuleList;

const int BNR_OPERATION_TIMEOUT = 66080341;
const std::string Elis_BNR_VERSION = "Elis_BNR_DRIVER_V1.0.1.5";



//协议中应答码
#define ACK_SUCCESS			0x00
#define ACK_INVALIDMESSAGE	0x01
#define ACK_INVALIDPARAM	0x02
#define ACK_CHECKERROR		0x03
#define ACK_NOCOMMPARAM		0x04
#define ACK_CMDEXECING		0x05
#define ACK_TIMEOUT			0x06
#define ACK_NOTOPENPORT		0x07
#define ACK_OTHERERROR		0xFF


#define	RMB_AMOUNT_1 	(100)
#define RMB_AMOUNT_2 	(200)
#define	RMB_AMOUNT_5 	(500)
#define	RMB_AMOUNT_10 	(1000)
#define	RMB_AMOUNT_20 	(2000)
#define	RMB_AMOUNT_50 	(5000)
#define	RMB_AMOUNT_100 	(10000)

//4个循环找零模块的ID号:
#define RE3_ID	RECYCLER_CLASS+0x03
#define RE4_ID	RECYCLER_CLASS+0x04
#define RE5_ID  RECYCLER_CLASS+0x05
#define RE6_ID	RECYCLER_CLASS+0x07


#define BNR_CHANGE_TIME_OUT_IN_MS (30000)

#define BNR_QUERY_TIME_OUT_IN_MS (2000)
#define BNR_CANCLE_TIME_OUT_IN_MS (2000)
#define BNR_REBOOT_TIME_OUT_IN_MS (20000)
#define BNR_CASHINEND_OPERATION_TIME_OUT_IN_MS (1000)
#define BNR_EMPTY_OPERATION_TIME_OUT_IN_MS (200000)

#define BNR_GET_MOUDLES_TIMEOUT_IN_MS (1000)
#define BNR_CASHTAKEN_TIME_OUT_IN_MS            (30000)
#define BNR_DEFAULT_OPERATION_TIME_OUT_IN_MS    (5000)
#define BNR_OPEN_OPERATION_TIME_OUT_IN_MS       (1000)
#define BNR_RESET_OPERATION_TIME_OUT_IN_MS      (60000)
#define BNR_CASHIN_OPERATION_TIME_OUT_IN_MS     (30000)
//#define BNR_CASHIN_OPERATION_TIME_OUT_IN_MS     (3000)


/************************** Global Data Definitions **************************/


/************************** Static Data Definitions **************************/

//保存LCU对应的编号,找零时用
//[0]:RE3-LCU(循环箱); [1]:RE4-LCU(循环箱); [2]:RE5-LCU(循环箱); [3]:RE6-LCU(循环箱);
//[4]:RE3-LCU(暂存);   [5]:RE4-LCU(暂存);   [6]:RE5-LCU(暂存);   [7]:RE6-LCU(暂存); 
//[8]:LO1-LCU(循环箱); [9]:LO1-LCU(暂存);   [10]:BU-LCU;

extern unsigned int g_LcuSeq[60];
//保存循环找零箱RE3~RE6的对应币种,以分为单位
extern unsigned int  g_ibilldeno[4];

//保存找零箱RE3-RE6 对应入账张数
extern unsigned int g_iREbillCount[4];

//保存PCU 状态值

;

int read_config();
static UINT8 do_ack(INT32 iret);

class CBNROperation
{
	private:
		bool m_IsOpened;
		
		bool m_IsInletFulled;	//入钞口是否有纸币
		bool m_IsOutletFulled;  //退钞口是否有纸币
		bool m_IsStoredEmpty;  //暂存区是否有纸币
		int  m_StoredCount;    //暂存区纸币数量
	
		MAP_UINT_STRING	m_cashid_map;  //
		MAP_STRING_UINT m_PCUStatus_map;  //PCU信息列表
		bool m_IsCashInStarted;
	private:
		
		void init_cashid_map();
		
		//
		T_BnrXfsResult CBNR_GetCapabilities(T_XfsCapabilities *capabilities);
	
		//
		T_BnrXfsResult CBNR_SetCapabilities(T_XfsCapabilities *capabilities);
		//参数分别是4个循环箱需要找零的张数
		//判断找零是否可行
		T_BnrXfsResult CBNR_Denominate(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour);

		//准备找零
		T_BnrXfsResult CBNR_Dispense(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour);

		//执行找零
		T_BnrXfsResult CBNR_Present();

		//清空循环箱至回收箱
		T_BnrXfsResult CBNR_Empty(std::string vstr, BOOL toFloat);	
		
	public:
		CBNROperation();
		~CBNROperation();
	
	public:
		bool IsCashInStarted();
		int print_BNRStatus(BNRStatus_t* bnrstatus);
				
		//开始现金交易
		T_BnrXfsResult CBNR_CashInStart();
		//接受纸币
		T_BnrXfsResult CBNR_CashIn();
		//结束现金交易
		T_BnrXfsResult CBNR_CashInEnd();
		//退回纸币
		T_BnrXfsResult CBNR_CashInRollback();
		//停收纸币
		T_BnrXfsResult CBNR_Cancel();

		//中断当前交易
		T_BnrXfsResult CBNR_CancelWaitingCashTaken();

		
		//纸币找零总函数
		//参数:需要找零的张数
 		//参数:实际找零的张数
 		//返回值:0  :成功
 		//		 -1 :失败
		int CBNR_OddChange(int imethod,UINT32 *ireone, UINT32 *iretwo, UINT32 *irethree, UINT32 *irefour);
		
		//喷出进出口纸币
		T_BnrXfsResult CBNR_Eject();
		//缩回出口纸币
		T_BnrXfsResult CBNR_Retract();
		//清暂存纸币
		T_BnrXfsResult CBNR_Reject();

		//======================================== Merge Functions=============================
	public:
		//连接BNR设备
		T_BnrXfsResult CBNR_Open();
		//断开连接
		T_BnrXfsResult CBNR_Close();
		//复位
		T_BnrXfsResult CBNR_Reset();
		//重启bnr系统(类似于断电)
		T_BnrXfsResult CBNR_Reboot();
		//打开投币口
		T_BnrXfsResult CBNR_Enable();

		//关闭投币口
		T_BnrXfsResult CBNR_Disable();

		//纸币压箱
		T_BnrXfsResult CBNR_Encash();
		//退出纸币
		T_BnrXfsResult CBNR_Refund();

		//清空纸币到回收箱
		T_BnrXfsResult CBNR_EmptytoRecycle(int uiclear[5]);
		
		//查询暂存区纸币面值 (元为单位,0:空)
		int CBNR_GetStoredBanknote();

		//清除暂存区纸币面额
		int CBNR_ClearStoredBanknote();
		//设置循环箱满高低空四个纸币位(不需要复位Reset) CB:4
		T_BnrXfsResult CBNR_SetReCBPositionNum(int fulls[5],int highs[5],int lows[5],int empty[5]);
		
		//查看以及设定接收纸币相关信息
		//设定支持的币种
		T_BnrXfsResult CBNR_UpdateDenominations(BOOL *bcashenable);

		//查询bnr状态
		T_BnrXfsResult CBNR_GetStatus();

		//状态纸币单元查询-获取钱箱信息
		T_BnrXfsResult CBNR_QueryCashUnit(T_XfsCashUnit *cashUnit);
		
		//设置钱箱数据,RE3----RE6 (设定面和 张数)
		//             数组下标 0-3
		T_BnrXfsResult CBNR_SetCashUnit(int yuan_amount[5] ,int yuan_maxcount[5]);

		//清除箱内数据

		

		//锁定或者解锁指定的箱子,参数1:箱子名; 参数2: true为锁定,false为解锁
		T_BnrXfsResult CBNR_LockCashBox(std::string vstrname, bool block);


		//获取纸币模块信息
		T_BnrXfsResult CBNR_GetMoudleInfo();
		//获取模块ID列表
		T_BnrXfsResult CBNR_GetMoudles(T_ModuleIdList *moduleList);
		//处理USB线被拔掉和重新插上
		T_BnrXfsResult CBNR_DoUSBOpen(T_BnrXfsResult iresult);
		//模块初始化复位
		//参数:true  仅仅机械复位
		//    :false  设定一些参数，并复位
		T_BnrXfsResult CBNR_ResetInit(bool OnlyReset);

		//找零之后，缩回纸币
		T_BnrXfsResult CBNR_Backnotes();

		//找零之后 喷出出口的纸币
		T_BnrXfsResult CBNR_JetBanknotes();

		//补币箱补币到RE循环箱
		T_BnrXfsResult CBNR_LoadBanknotes();

		//获取交易状态
		T_BnrXfsResult CBNR_GetTransactionStatus(T_TransactionStatus *status);

		//清除单元纸币数量
		int CBNR_ClearCashUnit(const char box_name[8]);
		//=========================================================================
};

#endif
