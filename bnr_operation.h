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

//æš‚å­˜åŒºçº¸å¸é¢é¢?
extern int g_StoredNote;

//åœ¨ç¬¬ä¸€æ¬¡CashInåŠ¨ä½œæ²¡æœ‰ç»“æŸå‰?ç¦æ­¢å‘ç¬¬äºŒæ¬¡
extern INT32 g_iCashInResult;

//0:ä¸æ˜¾ç¤ºç•Œé?æ‰˜ç›˜åŒºä¸æ˜¾ç¤º; 1:æ˜¾ç¤ºåœ¨æ‰˜ç›˜åŒº
extern BYTE g_ibnrhide;

//ç”¨äºŽUSBçº¿æ–­å¼€åŽé‡æ–°æ’ä¸?ä¿å­˜BNRçš„APIè¿”å›žå€?åˆ¤æ–­-1
extern INT32 g_iDoOpen;

//æµæ°´å?
extern INT32 g_iflow;
//é…ç½®æ–‡ä»¶
struct  tagConfigInfo
{
	int  log_level;
	int log_debug_level;
	char log_dir[64];
	
	int iloaderlock; //è¡¥å¸ç®?1:lock; 0:unlock
	//4ä¸ªå¾ªçŽ¯ç®±ä½Žå¸ä½å’Œ1ä¸ªå›žæ”¶ç®±
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


//ä¿å­˜æ‰¾é›¶ä¿¡æ¯
typedef struct tagBNRResult 
{
	T_BnrXfsResult ocResult;	//BNRåŠ¨ä½œå‘½ä»¤æ‰§è¡Œç»“æžœ

	//æ‰¾é›¶ä¿¡æ¯ä¿å­˜(0-3å¯¹åº”RE3---RE6,4å¯¹åº”LO1 )
	T_BillCount ReChangeCount[5];
	
	//æ¸…å¸ä¿¡æ¯æ•°é‡ä¿å­˜(0-3å¯¹åº”RE3---RE6,4å¯¹åº”LO1 )
	T_BillCount ReClearCount[5];
}BNRResult_t;
extern BNRResult_t	g_BNRResult;
extern unsigned int g_LOClear_Num[8];//清币 1 2 5 10 20 50 100 未知面额
extern unsigned int g_REClear_Num[8];// 清币 1 2 5 10 20 50 100 未知面额

extern unsigned int g_LOAdd_Num[8];//一次补币各面额的数量 1 2 5 10 20 50 100 未知面额
extern unsigned int g_CashBox_Num[8]; //回收箱各面额纸币数量 1 2 5 10 20 50 100 未知面额

typedef struct  tagCashInInfo
{
	T_Amount amount_yuan;	//çº¸å¸é¢é¢,ä»¥å…ƒä¸ºå•ä½?
	T_BillCount billcount;	//çº¸å¸æ•°é‡
}CashInInfo_t;
struct  tagREInfo
{
	T_Amount amount_yuan;	//çº¸å¸é¢é¢,ä»¥å…ƒä¸ºå•ä½?
	T_BillCount billmax;	//æœ€å¤§å¼ æ•?
	BYTE bconfig;	//0:è¡¨ç¤ºä¸ç”¨è®¾ç½®; 1:è¡¨ç¤ºéœ€è¦è®¾ç½?
};
typedef struct  tagREInfo REInfo_t;

typedef  struct tagBNRStatus 
{
	WORD wInShutter;	//å…¥é’žå£çŠ¶æ€?0:æ— çº¸å¸? 1:æœ‰çº¸å¸?
	WORD wReturnShutter;	//é€€é’žå£çŠ¶æ€?
	WORD wStacker;	//æš‚å­˜çŠ¶æ€?
	BYTE cCBSafedoor;	//å›žæ”¶ç®±ç‰©ç†é”çŠ¶æ€? 0:å·²é”ä¸? 1:è¢«æ‰“å¼€é”?
	BYTE cLOSafedoor;	//è¡¥å¸ç®±ç‰©ç†é”çŠ¶æ€? 0:å·²é”ä¸? 1:è¢«æ‰“å¼€é”?
	BYTE cCBBOX;	//å›žæ”¶ç®±çŠ¶æ€? 0:åœ¨ä½; 1:ä¸åœ¨ä½?
	BYTE cLOBOX;	//è¡¥å¸ç®±çŠ¶æ€? 0:åœ¨ä½ï¼Œéžç©? 1:ä¸åœ¨ä½? 2:åœ¨ä½ï¼Œè¡¥å¸ç®±ä¸ºç©º
	UINT32 dwErrorCode;	//çº¸å¸æ¨¡å—æ•…éšœç ?
	T_ModuleId dwcuid;//å›žæ”¶ç®±id
}BNRStatus_t;

extern BNRStatus_t g_BNRStatus;

typedef struct tagModuleList 
{
	BYTE iloboxexist; //æ˜¯å¦å­˜åœ¨è¡¥å¸ç®?1:å­˜åœ¨; 0:ä¸å­˜åœ?
	char loname[5]; //è¡¥å¸ç®±ç‰©ç†å
	BYTE ireboxnum; //å­˜åœ¨å¾ªçŽ¯ç®±æ•°é‡?
	BYTE ireboxexist[4]; //4ä¸ªå¾ªçŽ¯ç®±æ˜¯å¦å­˜åœ¨,,1:å­˜åœ¨; 0:ä¸å­˜åœ?
	char reboxname[4][6]; //å¾ªçŽ¯ç®?~4,ç‰©ç†å?
	T_ModuleId dwloid; //è¡¥å¸ç®±ID
	T_ModuleId dwreid[4]; //4ä¸ªå¾ªçŽ¯ç®±ID
	T_ModuleId dwcbid; //回收箱ID
	char CBSerialNum[16];//回收箱序列号列号
	char RESerialNum[4][16];//循环箱序列号 
	char LOSerialNum[16];//补币箱序列号
}ModuleList_t;
extern ModuleList_t	g_ModuleList;

const int BNR_OPERATION_TIMEOUT = 66080341;
const std::string Elis_BNR_VERSION = "Elis_BNR_DRIVER_V1.0.1.5";



//åè®®ä¸­åº”ç­”ç 
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

//4ä¸ªå¾ªçŽ¯æ‰¾é›¶æ¨¡å—çš„IDå?
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

//ä¿å­˜LCUå¯¹åº”çš„ç¼–å?æ‰¾é›¶æ—¶ç”¨
//[0]:RE3-LCU(å¾ªçŽ¯ç®?; [1]:RE4-LCU(å¾ªçŽ¯ç®?; [2]:RE5-LCU(å¾ªçŽ¯ç®?; [3]:RE6-LCU(å¾ªçŽ¯ç®?;
//[4]:RE3-LCU(æš‚å­˜);   [5]:RE4-LCU(æš‚å­˜);   [6]:RE5-LCU(æš‚å­˜);   [7]:RE6-LCU(æš‚å­˜); 
//[8]:LO1-LCU(å¾ªçŽ¯ç®?; [9]:LO1-LCU(æš‚å­˜);   [10]:BU-LCU;

extern unsigned int g_LcuSeq[60];
//ä¿å­˜å¾ªçŽ¯æ‰¾é›¶ç®±RE3~RE6çš„å¯¹åº”å¸ç§?ä»¥åˆ†ä¸ºå•ä½?
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
		
		bool m_IsInletFulled;	//å…¥é’žå£æ˜¯å¦æœ‰çº¸å¸
		bool m_IsOutletFulled;  //é€€é’žå£æ˜¯å¦æœ‰çº¸å¸?
		bool m_IsStoredEmpty;  //æš‚å­˜åŒºæ˜¯å¦æœ‰çº¸å¸
		int  m_StoredCount;    //æš‚å­˜åŒºçº¸å¸æ•°é‡?
	
		MAP_UINT_STRING	m_cashid_map;  //
		MAP_STRING_UINT m_PCUStatus_map;  //PCUä¿¡æ¯åˆ—è¡¨
		bool m_IsCashInStarted;
	private:
		
		void init_cashid_map();
		
		//
		T_BnrXfsResult CBNR_GetCapabilities(T_XfsCapabilities *capabilities);
	
		//
		T_BnrXfsResult CBNR_SetCapabilities(T_XfsCapabilities *capabilities);
		//å‚æ•°åˆ†åˆ«æ˜?ä¸ªå¾ªçŽ¯ç®±éœ€è¦æ‰¾é›¶çš„å¼ æ•°
		//åˆ¤æ–­æ‰¾é›¶æ˜¯å¦å¯è¡Œ
		T_BnrXfsResult CBNR_Denominate(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour);

		//å‡†å¤‡æ‰¾é›¶
		T_BnrXfsResult CBNR_Dispense(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour);

		//æ‰§è¡Œæ‰¾é›¶
		T_BnrXfsResult CBNR_Present();

		//æ¸…ç©ºå¾ªçŽ¯ç®±è‡³å›žæ”¶ç®?
		T_BnrXfsResult CBNR_Empty(std::string vstr, BOOL toFloat);	
		
	public:
		CBNROperation();
		~CBNROperation();
	
	public:
		bool IsCashInStarted();
		int print_BNRStatus(BNRStatus_t* bnrstatus);
				
		//å¼€å§‹çŽ°é‡‘äº¤æ˜?
		T_BnrXfsResult CBNR_CashInStart();
		//æŽ¥å—çº¸å¸
		T_BnrXfsResult CBNR_CashIn();
		//ç»“æŸçŽ°é‡‘äº¤æ˜“
		T_BnrXfsResult CBNR_CashInEnd();
		//é€€å›žçº¸å¸?
		T_BnrXfsResult CBNR_CashInRollback();
		//åœæ”¶çº¸å¸
		T_BnrXfsResult CBNR_Cancel();

		//ä¸­æ–­å½“å‰äº¤æ˜“
		T_BnrXfsResult CBNR_CancelWaitingCashTaken();

		
		//çº¸å¸æ‰¾é›¶æ€»å‡½æ•?
		//å‚æ•°:éœ€è¦æ‰¾é›¶çš„å¼ æ•°
 		//å‚æ•°:å®žé™…æ‰¾é›¶çš„å¼ æ•?
 		//è¿”å›žå€?0  :æˆåŠŸ
 		//		 -1 :å¤±è´¥
		int CBNR_OddChange(int imethod,UINT32 *ireone, UINT32 *iretwo, UINT32 *irethree, UINT32 *irefour);
		
		//å–·å‡ºè¿›å‡ºå£çº¸å¸?
		T_BnrXfsResult CBNR_Eject();
		//ç¼©å›žå‡ºå£çº¸å¸
		T_BnrXfsResult CBNR_Retract();
		//æ¸…æš‚å­˜çº¸å¸?
		T_BnrXfsResult CBNR_Reject();

		//======================================== Merge Functions=============================
	public:
		//è¿žæŽ¥BNRè®¾å¤‡
		T_BnrXfsResult CBNR_Open();
		//æ–­å¼€è¿žæŽ¥
		T_BnrXfsResult CBNR_Close();
		//å¤ä½
		T_BnrXfsResult CBNR_Reset();
		//é‡å¯bnrç³»ç»Ÿ(ç±»ä¼¼äºŽæ–­ç”?
		T_BnrXfsResult CBNR_Reboot();
		//æ‰“å¼€æŠ•å¸å?
		T_BnrXfsResult CBNR_Enable();

		//å…³é—­æŠ•å¸å?
		T_BnrXfsResult CBNR_Disable();

		//çº¸å¸åŽ‹ç®±
		T_BnrXfsResult CBNR_Encash();
		//é€€å‡ºçº¸å¸?
		T_BnrXfsResult CBNR_Refund();

		//æ¸…ç©ºçº¸å¸åˆ°å›žæ”¶ç®±
		T_BnrXfsResult CBNR_EmptytoRecycle(int uiclear[5]);
		
		//æŸ¥è¯¢æš‚å­˜åŒºçº¸å¸é¢å€?(å…ƒä¸ºå•ä½,0:ç©?
		int CBNR_GetStoredBanknote();

		//æ¸…é™¤æš‚å­˜åŒºçº¸å¸é¢é¢?
		int CBNR_ClearStoredBanknote();
		//è®¾ç½®å¾ªçŽ¯ç®±æ»¡é«˜ä½Žç©ºå››ä¸ªçº¸å¸ä½(ä¸éœ€è¦å¤ä½Reset) CB:4
		T_BnrXfsResult CBNR_SetReCBPositionNum(int fulls[5],int highs[5],int lows[5],int empty[5]);
		
		//æŸ¥çœ‹ä»¥åŠè®¾å®šæŽ¥æ”¶çº¸å¸ç›¸å…³ä¿¡æ¯
		//è®¾å®šæ”¯æŒçš„å¸ç§?
		T_BnrXfsResult CBNR_UpdateDenominations(BOOL *bcashenable);

		//æŸ¥è¯¢bnrçŠ¶æ€?
		T_BnrXfsResult CBNR_GetStatus();

		//çŠ¶æ€çº¸å¸å•å…ƒæŸ¥è¯?èŽ·å–é’±ç®±ä¿¡æ¯
		T_BnrXfsResult CBNR_QueryCashUnit(T_XfsCashUnit *cashUnit);
		
		//è®¾ç½®é’±ç®±æ•°æ®,RE3----RE6 (è®¾å®šé¢å’Œ å¼ æ•°)
		//             æ•°ç»„ä¸‹æ ‡ 0-3
		T_BnrXfsResult CBNR_SetCashUnit(int yuan_amount[5] ,int yuan_maxcount[5]);

		//æ¸…é™¤ç®±å†…æ•°æ®

		

		//é”å®šæˆ–è€…è§£é”æŒ‡å®šçš„ç®±å­,å‚æ•°1:ç®±å­å? å‚æ•°2: trueä¸ºé”å®?falseä¸ºè§£é”?
		T_BnrXfsResult CBNR_LockCashBox(std::string vstrname, bool block);


		//èŽ·å–çº¸å¸æ¨¡å—ä¿¡æ¯
		T_BnrXfsResult CBNR_GetMoudleInfo();
		//èŽ·å–æ¨¡å—IDåˆ—è¡¨
		T_BnrXfsResult CBNR_GetMoudles(T_ModuleIdList *moduleList);
		//å¤„ç†USBçº¿è¢«æ‹”æŽ‰å’Œé‡æ–°æ’ä¸?
		T_BnrXfsResult CBNR_DoUSBOpen(T_BnrXfsResult iresult);
		//æ¨¡å—åˆå§‹åŒ–å¤ä½?
		//å‚æ•°:true  ä»…ä»…æœºæ¢°å¤ä½
		//    :false  è®¾å®šä¸€äº›å‚æ•°ï¼Œå¹¶å¤ä½?
		T_BnrXfsResult CBNR_ResetInit(bool OnlyReset);

		//æ‰¾é›¶ä¹‹åŽï¼Œç¼©å›žçº¸å¸?
		T_BnrXfsResult CBNR_Backnotes();

		//æ‰¾é›¶ä¹‹åŽ å–·å‡ºå‡ºå£çš„çº¸å¸?
		T_BnrXfsResult CBNR_JetBanknotes();

		//è¡¥å¸ç®±è¡¥å¸åˆ°REå¾ªçŽ¯ç®?
		T_BnrXfsResult CBNR_LoadBanknotes();

		//èŽ·å–äº¤æ˜“çŠ¶æ€?
		T_BnrXfsResult CBNR_GetTransactionStatus(T_TransactionStatus *status);

		//æ¸…é™¤å•å…ƒçº¸å¸æ•°é‡
		int CBNR_ClearCashUnit(const char box_name[8]);
		//=========================================================================
};

#endif
