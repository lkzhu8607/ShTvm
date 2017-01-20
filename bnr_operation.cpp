#ifndef WIN32
	#define __stdcall
#endif

#include "bnr_operation.h"
#include "de_log_t.h"

using namespace std;
/************************ Defines and typedefs *******************************/


/************************** Global Data Definitions **************************/
//保存LCU对应的编号,找零时用
//[0]:RE3-LCU(循环箱); [1]:RE4-LCU(循环箱); [2]:RE5-LCU(循环箱); [3]:RE6-LCU(循环箱);
//[4]:RE3-LCU(暂存);   [5]:RE4-LCU(暂存);   [6]:RE5-LCU(暂存);   [7]:RE6-LCU(暂存); 
//[8]:LO1-LCU(循环箱); [9]:LO1-LCU(暂存);   [10]:BU-LCU;

unsigned int g_LcuSeq[60];
//保存循环找零箱RE3~RE6的对应币种,以分为单位
unsigned int  g_ibilldeno[4];

//保存找零箱RE3-RE6 对应入账张数
unsigned int g_iREbillCount[4];

unsigned int g_LOClear_Num[8];// 1 2 5 10 20 50 100 未知面额
unsigned int g_REClear_Num[8];// 1 2 5 10 20 50 100 未知面额
unsigned int g_LOAdd_Num[8];//一次补币各面额的数量 1 2 5 10 20 50 100 未知面额
unsigned int g_CashBox_Num[8]; //回收箱各面额纸币数量 1 2 5 10 20 50 100 未知面额

//保存PCU 状态值


/************************** Static Data Definitions **************************/
static BOOL g_used ;
static T_XfsCashOrder g_cashOrder;
static T_BnrXfsResult g_ocResult;
T_XfsCashUnit g_CashUnit;
static T_ModuleIdList g_ModuleIdList;
static UINT32 g_XFS;
static bool g_IsRealBanknote;
ConfigInfo_t g_ConfigInfo;

bool g_log_operation_thread =false;
bool g_log_status_thread =false;
bool g_log_intermediate =false;



int g_StoredNote = 0 ;

INT32 g_iCashInResult = 0;

BYTE g_ibnrhide = 0;

INT32 g_iDoOpen = 0;

INT32 g_iflow = -1;

BNRResult_t	g_BNRResult;
BNRStatus_t g_BNRStatus;
ModuleList_t	g_ModuleList;

#define CONFIG_FILE "../conf/Elis_BNR.conf"
int read_config()
{
	xx1_s8 cmd_str[XX1_BUF_LEN_BIG] = {0};	
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "log_level", &g_ConfigInfo.log_level ))
	{
		fprintf(stderr, "init log_level failed\n");		
		return RET_FAIL;	
	}

	if (RET_SUCC != ini_read_int( CONFIG_FILE, "log_debug_level", &g_ConfigInfo.log_debug_level ))
	{
		fprintf(stderr, "init log_debug_level failed\n");		
		return RET_FAIL;	
	}

	if (RET_SUCC != ini_read_string( CONFIG_FILE, "log_dir",g_ConfigInfo.log_dir, sizeof(g_ConfigInfo.log_dir) ))
	{
		fprintf(stderr, "init log_dir failed\n"); 	
		return RET_FAIL;	
	}
	
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "loaderlock", &g_ConfigInfo.iloaderlock))
	{
		fprintf(stderr, "init loaderlock failed\n");		
		return RET_FAIL;	
	}
	
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "LOW1", &g_ConfigInfo.ReBoxLows[0]))
	{
		fprintf(stderr, "init LOW1 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "LOW2", &g_ConfigInfo.ReBoxLows[1]))
	{
		fprintf(stderr, "init LOW2 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "LOW3", &g_ConfigInfo.ReBoxLows[2]))
	{
		fprintf(stderr, "init LOW3 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "LOW4", &g_ConfigInfo.ReBoxLows[3]))
	{
		fprintf(stderr, "init LOW4 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "LOW5", &g_ConfigInfo.ReBoxLows[4]))
	{
		fprintf(stderr, "init LOW5 failed\n");		
		return RET_FAIL;	
	}

	if (RET_SUCC != ini_read_int( CONFIG_FILE, "HIGH1", &g_ConfigInfo.ReBoxHighs[0]))
	{
		fprintf(stderr, "init HIGH1 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "HIGH2", &g_ConfigInfo.ReBoxHighs[1]))
	{
		fprintf(stderr, "init HIGH2 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "HIGH3", &g_ConfigInfo.ReBoxHighs[2]))
	{
		fprintf(stderr, "init HIGH3 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "HIGH4", &g_ConfigInfo.ReBoxHighs[3]))
	{
		fprintf(stderr, "init HIGH4 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "HIGH5", &g_ConfigInfo.ReBoxHighs[4]))
	{
		fprintf(stderr, "init HIGH5 failed\n");		
		return RET_FAIL;	
	}
	
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "FULL1", &g_ConfigInfo.ReBoxFulls[0]))
	{
		fprintf(stderr, "init FULL1 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "FULL2", &g_ConfigInfo.ReBoxFulls[1]))
	{
		fprintf(stderr, "init FULL2 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "FULL3", &g_ConfigInfo.ReBoxFulls[2]))
	{
		fprintf(stderr, "init FULL3 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "FULL4", &g_ConfigInfo.ReBoxFulls[3]))
	{
		fprintf(stderr, "init FULL4 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "FULL5", &g_ConfigInfo.ReBoxFulls[4]))
	{
		fprintf(stderr, "init FULL5 failed\n");		
		return RET_FAIL;	
	}

	if (RET_SUCC != ini_read_int( CONFIG_FILE, "EMPTY1", &g_ConfigInfo.ReBoxEmptys[0]))
	{
		fprintf(stderr, "init EMPTY1 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "EMPTY2", &g_ConfigInfo.ReBoxEmptys[1]))
	{
		fprintf(stderr, "init EMPTY2 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "EMPTY3", &g_ConfigInfo.ReBoxEmptys[2]))
	{
		fprintf(stderr, "init EMPTY3 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "EMPTY4", &g_ConfigInfo.ReBoxEmptys[3]))
	{
		fprintf(stderr, "init EMPTY4 failed\n");		
		return RET_FAIL;	
	}
	if (RET_SUCC != ini_read_int( CONFIG_FILE, "EMPTY5", &g_ConfigInfo.ReBoxEmptys[4]))
	{
		fprintf(stderr, "init EMPTY5 failed\n");		
		return RET_FAIL;	
	}
	return RET_SUCC;
}

static pthread_mutex_t listenerEvent_mutex;
static pthread_cond_t listenerEvent;
static struct timespec eventTimeOut;

static pthread_mutex_t zero_muttex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t zero_cond = PTHREAD_COND_INITIALIZER;

/********************Public Common Functions***********************/

int CBNROperation::print_BNRStatus(BNRStatus_t* bnrstatus)
{

	if(bnrstatus==NULL)
	{
		return -1;
	}
	xx1_log_debug(LOG_LEVEL_MUST,"入钞口:%d\t退钞口:%d\t暂存状态:%d\t回收箱锁:%d\t补币箱锁:%d\n回收箱状态:%d\t补币箱状态:%d\t纸币模块故障:%d,是否正交易状态:%d\n",\
		bnrstatus->wInShutter,bnrstatus->wReturnShutter,bnrstatus->wStacker,\
		bnrstatus->cCBSafedoor,bnrstatus->cLOSafedoor,bnrstatus->cCBBOX,\
		bnrstatus->cLOBOX,bnrstatus->dwErrorCode,IsCashInStarted());
	printf("入钞口:%d\t退钞口:%d\t暂存状态:%d\t回收箱锁:%d\t补币箱锁:%d\t回收箱状态:%d\n补币箱状态:%d\t纸币模块故障:%d,是否正交易状态:%d\n",\
		bnrstatus->wInShutter,bnrstatus->wReturnShutter,bnrstatus->wStacker,\
		bnrstatus->cCBSafedoor,bnrstatus->cLOSafedoor,bnrstatus->cCBBOX,\
		bnrstatus->cLOBOX,bnrstatus->dwErrorCode,IsCashInStarted());
	return 0;
}
int print_CashUnit(T_XfsCashUnit *CashUnit)
{
	int i=0;
	xx1_log_debug(LOG_LEVEL_MUST,"*****************************************************");
	xx1_log_debug(LOG_LEVEL_MUST," transportCount=[%d],LCUmaxSize=[%d],LCUsize=[%d]",\
							CashUnit->transportCount,\
							CashUnit->logicalCashUnitList.maxSize,\
							CashUnit->logicalCashUnitList.size);
	for(i=0;i<CashUnit->logicalCashUnitList.size;i++)
	{
		int in_count=0;
		int no_count=0;
		if(CashUnit->logicalCashUnitList.items[i].cuType == XFS_C_CDR_LCU_BILL_CASSETTE)
		{
			in_count = CashUnit->logicalCashUnitList.items[i].count;
		}
		if(CashUnit->logicalCashUnitList.items[i].cuType == XFS_C_CDR_LCU_ESCROW)
		{
			no_count = CashUnit->logicalCashUnitList.items[i].count;
		}
		xx1_log_debug(LOG_LEVEL_MUST,"LCU name=[%s],code=[%s],value=[%d],variant=[%04x],in_count=[%d],no_count=[%d],full=[%d],high=[%d],low=[%d]",\
			CashUnit->logicalCashUnitList.items[i].physicalCashUnit->name,\
			CashUnit->logicalCashUnitList.items[i].cashType.currencyCode,\
			CashUnit->logicalCashUnitList.items[i].cashType.value,\
			CashUnit->logicalCashUnitList.items[i].cashType.variant,\
			in_count,\
			no_count,\
			CashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.full,\
			CashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.high,\
			CashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.low);	
					
	}
	xx1_log_debug(LOG_LEVEL_MUST,"\nPCUmaxSize=[%d],PCUsize=[%d]",\
							CashUnit->physicalCashUnitList.maxSize,\
							CashUnit->physicalCashUnitList.size);
	for(i=0;i<CashUnit->physicalCashUnitList.size;i++)
	{
		xx1_log_debug(LOG_LEVEL_MUST,"PCU name=[%s],lock=[%d],count=[%d],status=[%d],Mode=[%d],thresStatus=[%d],full=[%d],high=[%d],low=[%d]",\
					CashUnit->physicalCashUnitList.items[i].name,\
					CashUnit->physicalCashUnitList.items[i].lock,\
					CashUnit->physicalCashUnitList.items[i].count,\
					CashUnit->physicalCashUnitList.items[i].status,\
					CashUnit->physicalCashUnitList.items[i].thresholdMode,\
					CashUnit->physicalCashUnitList.items[i].thresholdStatus,\
					CashUnit->physicalCashUnitList.items[i].threshold.full,\
					CashUnit->physicalCashUnitList.items[i].threshold.high,\
					CashUnit->physicalCashUnitList.items[i].threshold.low);
		
					
	}
	xx1_log_debug(LOG_LEVEL_MUST,"*****************************************************\n");
}
int print_msg_cashType(T_XfsCashType* cashType)
{
	int ret =0;
	if(cashType == NULL)
		return -1;
	xx1_log_debug(LOG_LEVEL_DEBUG,"currencyCode=[%s],value=[%d],variant=[%x]",cashType->currencyCode,(cashType->value)/100,cashType->variant);
	return ret;
}
int print_msg_ModuleIdentification(T_ModuleIdentification *ModuleIdentification)
{
	
	int ret =0;
	if(ModuleIdentification == NULL)
		return -1;
	xx1_log_debug(LOG_LEVEL_MUST,"name=[%s],description=[%s],userdata=[%s]\n",ModuleIdentification->Name,ModuleIdentification->Description,ModuleIdentification->UserData);
	return ret;
}


/************************* Static Function Prototypes ************************/

static void __stdcall onOperationCompleteOccured(
	LONG32 identificationId, LONG32 operationId, LONG32 result, LONG32 extendedResult, void *data);
static void __stdcall onStatusOccured(
	LONG32 status, LONG32 result, LONG32 extendedResult, void *data);
static void __stdcall onIntermediateOccured(
	LONG32 identificationId, LONG32 operationId, LONG32 reason, void *data);

/********************************** Functions ********************************/

/******************************************************************************
 *              setTimeout
 ******************************************************************************
 * Calculate the timeout time
 *****************************************************************************/
struct timespec * setTimeout( struct timespec * timeout, long timeOutMs) {
  struct timeval now;
  gettimeofday(&now, NULL);
  timeout->tv_sec = now.tv_sec + (timeOutMs / 1000);
  timeout->tv_nsec = now.tv_usec * 1000 + ((timeOutMs % 1000)*1000);
  return timeout;
}

/******************************************************************************
 *              operationCompleteOccured
 **************************************************************************//**
 * Called when an Operation Complete event is received
 *
 * @param identificationID job identification number
 * @param operationID J/XFS operation code
 * @param result J/XFS result code
 * @param extendedResult extended result code send by the BNR
 * @param data event data. Contents depend upon operationID.
 *
 *****************************************************************************/
static void __stdcall operationCompleteOccured(
  LONG32 identificationId, LONG32 operationId, LONG32 result, LONG32 extendedResult, void *data)
{
	if(g_log_operation_thread == false)
	{
		init_log_thread("OPCompleted");
		g_log_operation_thread = true;
	}
	int i=0;
  xx1_log_debug(LOG_LEVEL_DEBUG,"identificationId=%d,operationId=%d,result=%d,extenResult=%d",identificationId,operationId,result,extendedResult);
  g_ocResult = result;
  g_BNRResult.ocResult = result;

  if(data != NULL)
  {
      	memcpy(&g_cashOrder, data, sizeof(T_XfsCashOrder));	
		printf("g_cashOrder size=[%d]\n",g_cashOrder.denomination.size);
	  	if(g_cashOrder.denomination.size > 0)
       	{
       		
  			xx1_log_debug(LOG_LEVEL_DEBUG,"currency_code=[%s],exponent=[%d],size=[%d],amount=[%d],cashbox=[%d]\n",\
				g_cashOrder.currency.currencyCode,g_cashOrder.currency.exponent,g_cashOrder.denomination.size,\
				g_cashOrder.denomination.amount,g_cashOrder.denomination.cashbox);
	  	}
		for(i=0; i<g_cashOrder.denomination.size; i++)
		{
			xx1_log_debug(LOG_LEVEL_DEBUG,"----unit=[%d].count=[%d]",\
			g_cashOrder.denomination.items[i].unit,g_cashOrder.denomination.items[i].count);
		}
  }
  switch (operationId) {
    case XFS_O_CDR_CASH_IN: 
		g_iCashInResult = 0;
		g_StoredNote = g_cashOrder.denomination.amount/100;
      	xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_CASH_IN Completed");
		break;
	case XFS_O_CDR_CASH_IN_START:
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_CASH_IN_START Completed");
		break;
	
	case XFS_O_CDR_CASH_IN_END:
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_CASH_IN_END Completed");		
		break;
	
	case XFS_O_CDR_CASH_IN_ROLLBACK:
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_CASH_IN_ROLLBACK Completed");
		break;

	 case XFS_O_CDR_OFFSET: 
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_OFFSET Completed");
	 	break;
	 case XFS_O_CDR_DENOMINATE:              
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_DENOMINATE Completed");	
	 	break;
	 case XFS_O_CDR_DISPENSE:                
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_DISPENSE Completed");	
		if(data!=NULL)
		{
			//只在XFS_O_CDR_DISPENSE来处理,避免重复
			for (i=0; i<g_cashOrder.denomination.size; i++)
			{
				//循环箱3
				if (g_cashOrder.denomination.items[i].unit == g_LcuSeq[0])
				{
					g_BNRResult.ReChangeCount[0] = g_cashOrder.denomination.items[i].count;
				}

				//循环箱4
				if (g_cashOrder.denomination.items[i].unit == g_LcuSeq[1])
				{
					g_BNRResult.ReChangeCount[1] = g_cashOrder.denomination.items[i].count;
				}

				//循环箱5
				if (g_cashOrder.denomination.items[i].unit == g_LcuSeq[2])
				{
					g_BNRResult.ReChangeCount[2] = g_cashOrder.denomination.items[i].count;
				}

				//循环箱6
				if (g_cashOrder.denomination.items[i].unit == g_LcuSeq[3])
				{
					g_BNRResult.ReChangeCount[3] = g_cashOrder.denomination.items[i].count;
				}
			}
		}
		
	 	break;
	 case XFS_O_CDR_QUERY_CASH_UNIT:         
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_QUERY_CASH_UNIT Completed");		
	 	break;
	 case XFS_O_CDR_RESET:                   
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_RESET Completed");	
	 	break;
	 case XFS_O_CDR_UPDATE_CASH_UNIT:        
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_UPDATE_CASH_UNIT Completed");	
	 	break;
	 case XFS_O_CDR_GET_DATE_TIME:           
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_GET_DATE_TIME Completed");	
	 	break;
	 case XFS_O_CDR_SET_DATE_TIME:          
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_SET_DATE_TIME Completed");	
	 	break;
	 case XFS_O_CDR_QUERY_DENOMINATIONS:     
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_QUERY_DENOMINATIONS Completed");	
	 	break;
	 case XFS_O_CDR_UPDATE_DENOMINATIONS:    
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_UPDATE_DENOMINATIONS Completed");	
	 	break;
	 case XFS_O_CDR_EMPTY:                   
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_EMPTY Completed");	
	 	break;
	 case XFS_O_CDR_PRESENT:                 
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_PRESENT Completed");	
	 	break;
	 case XFS_O_CDR_REJECT:                  
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_REJECT Completed");	
	 	break;
	 case XFS_O_CDR_RETRACT:                 
		xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_O_CDR_RETRACT Completed");	
	 	break;

	default:
    	break;
  }//switch
  if (result!=XFS_E_CANCELLED)
  {
  	pthread_mutex_lock (&listenerEvent_mutex);
  	pthread_cond_signal (&listenerEvent);
  	pthread_mutex_unlock (&listenerEvent_mutex);
  }
}//operationCompleteOccured

/******************************************************************************
*             statusOccured
***************************************************************************//**
* Called when an Status event is received
*
* @param status XFS status code
* @param result J/XFS result code
* @param extendedResult extended result code send by the BNR
* @param details event data. Contents depend upon status.
*
******************************************************************************/
static void __stdcall statusOccured(
  LONG32 status, LONG32 result, LONG32 extendedResult, void *data)
{
	
	UINT32 i=0;
	if(g_log_status_thread== false)
	{
		init_log_thread("StatusOccured");
		g_log_status_thread=true;
	}
	if(data !=NULL)
	{
		switch (status)
		{
			case XFS_S_CDR_OFFSET:
				cout<<"statu: XFS_S_CDR_OFFSET"<<endl;
				break;
			case XFS_S_CDR_CASHUNIT_CHANGED:
				{
					cout<<"statu: XFS_S_CDR_CASHUNIT_CHANGED"<<endl;
					memcpy(&g_CashUnit, data, sizeof(T_XfsCashUnit));
					print_CashUnit(&g_CashUnit);
					//暂存中数量
					WORD icount = 0;
					//判断暂存是否有钞
					BYTE cBUstatus = 0x0;
					//不参与循环找零的纸币面额,直接进BU暂存
					for (i=0; i<g_CashUnit.physicalCashUnitList.size; i++)
					{
						if (memcmp("BU", g_CashUnit.physicalCashUnitList.items[i].name, 2)==0)
						{
							if (g_CashUnit.physicalCashUnitList.items[i].count > 0 )
							{
								cBUstatus |= 0x01;

								icount = g_CashUnit.physicalCashUnitList.items[i].count;
							}
							break;
						}
					}

					//参与循环找零,进循环暂存的面额
					if (g_ModuleList.ireboxexist[0])
					{
						for (i=0; i<g_CashUnit.logicalCashUnitList.size; i++)
						{
	// 						if ( (memcmp("RE3", g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
							if ( (memcmp(g_ModuleList.reboxname[0], g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
								(g_CashUnit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
								)
							{
								if (g_CashUnit.logicalCashUnitList.items[i].count > 0)
								{
									cBUstatus |= 0x02;

									icount += g_CashUnit.logicalCashUnitList.items[i].count;
								}
								break;
							}
						}
					}
					
					if (g_ModuleList.ireboxexist[1])
					{
						for (i=0; i<g_CashUnit.logicalCashUnitList.size; i++)
						{
	// 						if ( (memcmp("RE4", g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
							if ( (memcmp(g_ModuleList.reboxname[1], g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
								(g_CashUnit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
								)
							{
								if (g_CashUnit.logicalCashUnitList.items[i].count > 0)
								{
									cBUstatus |= 0x04;

									icount += g_CashUnit.logicalCashUnitList.items[i].count;
								}
								break;
							}
						}
					}
					
					if (g_ModuleList.ireboxexist[2])
					{
						for (i=0; i<g_CashUnit.logicalCashUnitList.size; i++)
						{
	// 						if ( (memcmp("RE5", g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
							if ( (memcmp(g_ModuleList.reboxname[2], g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
								(g_CashUnit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
								)
							{
								if (g_CashUnit.logicalCashUnitList.items[i].count > 0)
								{
									cBUstatus |= 0x08;

									icount += g_CashUnit.logicalCashUnitList.items[i].count;
								}
								break;
							}
						}
					}
					
					if (g_ModuleList.ireboxexist[3])
					{
						for (i=0; i<g_CashUnit.logicalCashUnitList.size; i++)
						{
	// 						if ( (memcmp("RE6", g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
							if ( (memcmp(g_ModuleList.reboxname[3], g_CashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3)==0) &&
								(g_CashUnit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
								)
							{
								if (g_CashUnit.logicalCashUnitList.items[i].count > 0)
								{
									cBUstatus |= 0x10;

									icount += g_CashUnit.logicalCashUnitList.items[i].count;
								}
								break;
							}
						}
					}		
				}
				break;
			//箱子在位(XFS_C_CDR_LCU_OK)或者不在位(XFS_C_CDR_LCU_MISSING),由不在位装上箱子后,需要查询LCU才能得知
			//XFS_C_CDR_LCU_INOP(INOPERATIVE)的状态,此时物理箱的状态仍然是MISSING.
			case XFS_S_CDR_CASHUNIT_CONFIGURATION_CHANGED:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASHUNIT_CONFIGURATION_CHANGED");
				{
					
					memcpy(&g_CashUnit, data, sizeof(T_XfsCashUnit));
					print_CashUnit(&g_CashUnit);
					//回收箱是否在位
					for (i=0; i<g_CashUnit.physicalCashUnitList.size; i++)
					{
						if (memcmp("CB", g_CashUnit.physicalCashUnitList.items[i].name, 2)==0)
						{
							if (g_CashUnit.physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_OK)
							{
								g_BNRStatus.cCBBOX = 0;
								g_BNRStatus.dwErrorCode = 0;
							}
							else if(g_CashUnit.physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_MISSING)
							{
								g_BNRStatus.cCBBOX = 1;
								g_BNRStatus.dwErrorCode = g_CashUnit.physicalCashUnitList.items[i].status;
							}
							else
							{
								//g_BNRStatus.cCBBOX = 1;
								//g_BNRStatus.dwErrorCode = g_CashUnit.physicalCashUnitList.items[i].status;
							}
							break;
						}
					}

					if (g_ModuleList.iloboxexist)
					{
						for (i=0; i<g_CashUnit.physicalCashUnitList.size; i++)
						{
							if (memcmp("LO", g_CashUnit.physicalCashUnitList.items[i].name, 2)==0)
							{
								//补币箱在位状态:在位,空或非空
								if (g_CashUnit.physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_OK)
								{
									if (g_CashUnit.physicalCashUnitList.items[i].thresholdStatus == XFS_S_BIN_EMPTY)
									{
										g_BNRStatus.cLOBOX = 2;
									} 
									else
									{
										g_BNRStatus.cLOBOX = 0;
									}
									g_BNRStatus.dwErrorCode = 0;
								}
								else if(g_CashUnit.physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_MISSING)
								{
									 //不在位
									g_BNRStatus.cLOBOX = 1;
									g_BNRStatus.dwErrorCode = g_CashUnit.physicalCashUnitList.items[i].status;
								}
								else
								{
									//g_BNRStatus.cLOBOX = 1;
									//g_BNRStatus.dwErrorCode = g_CashUnit.physicalCashUnitList.items[i].status;
								}							
								break;
							}					
						}
					}
					else
					{
						//不在位
						g_BNRStatus.cLOBOX = 1;
					}		
				}
				break;
			case XFS_S_CDR_CASHUNIT_THRESHOLD:	
				memcpy(&g_CashUnit, data, sizeof(T_XfsCashUnit));
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASHUNIT_THRESHOLD");
				print_CashUnit(&g_CashUnit);
				break;
			case XFS_S_CDR_DEVICE_STATUS_CHANGED:
				memcpy(&g_XFS, data, sizeof(UINT32));
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DEVICE_STATUS_CHANGED,detail=[%d]",g_XFS);
				switch (g_XFS)
				{
				case XFS_S_CDR_DS_HARDWARE_ERROR:
					{
						g_BNRStatus.dwErrorCode = g_XFS;
					}
					break;
				case XFS_S_CDR_DS_USER_ERROR: //打开锁,或者顶盖打开,或者后盖打开
					{
						g_BNRStatus.cCBSafedoor = 1;
						g_BNRStatus.cLOSafedoor = 1;
						g_BNRStatus.dwErrorCode = g_XFS;
			
						//CBNR_ClearCashUnit("CB");
						//CBNR_ClearCashUnit("LO");
						
					}
					break;
				case XFS_S_CDR_DS_OFF_LINE: //收到此信息,需要复位,锁打开后锁上或者顶盖/后盖打开后又盖上
					{
						g_BNRStatus.cCBSafedoor = 0;
						g_BNRStatus.cLOSafedoor = 0;
						g_BNRStatus.dwErrorCode = g_XFS;
						//CBNR_ClearCashUnit("CB");
						//CBNR_ClearCashUnit("LO");
					}
					break;
				case XFS_S_CDR_DS_ON_LINE:
					{
						g_BNRStatus.cCBSafedoor = 0;
						g_BNRStatus.cLOSafedoor = 0;
						g_BNRStatus.cCBBOX = 0;
						g_BNRStatus.cLOBOX=0;
 						g_BNRStatus.dwErrorCode = 0;
					}
					break;
				}
				print_CashUnit(&g_CashUnit);
				break;
			case XFS_S_CDR_TRANSPORT_CHANGED:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_TRANSPORT_CHANGED");
				break;
			case XFS_S_CDR_DS_HARDWARE_ERROR:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DS_HARDWARE_ERROR");
				break;
			case XFS_S_CDR_DS_USER_ERROR:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DS_USER_ERROR");
				break;
			case XFS_S_CDR_DS_OFF_LINE:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DS_OFF_LINE");
				break;
			case XFS_S_CDR_DS_ON_LINE:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DS_ON_LINE");
				break;
			case XFS_S_CDR_DIS_OK:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DIS_OK");
				break;
			case XFS_S_CDR_DIS_CU_STATE:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DIS_CU_STATE");
				break;
			case XFS_S_CDR_DIS_CU_STOP:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DIS_CU_STOP");
				break;
			case XFS_S_CDR_DIS_CU_UNKNOWN:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_DIS_CU_UNKNOWN");
				break;
			case XFS_S_CDR_IS_EMPTY:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_IS_EMPTY");
				break;
			case XFS_S_CDR_IS_NOT_EMPTY:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_IS_NOT_EMPTY");
				break;
			case XFS_S_CDR_IS_UNKNOWN:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_IS_UNKNOWN");
				break;
			case XFS_S_CDR_CASH_AVAILABLE:
				{
					xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_AVAILABLE");
					memcpy(&g_cashOrder, data, sizeof(T_XfsCashOrder));
					if (g_cashOrder.denomination.amount > 0)
					{
						g_BNRStatus.wReturnShutter = 1;
					}
					for(i=0; i<g_cashOrder.denomination.size; i++)
					{
						xx1_log_debug(LOG_LEVEL_DEBUG,"----item[%d]=[%d],count=[%d]",\
							g_cashOrder.denomination.items[i].unit,\
							g_cashOrder.denomination.items[i].count);
					}
				}
				break;
			case XFS_S_CDR_CASH_TAKEN:
				{
					xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_TAKEN");
					memcpy(&g_cashOrder, data, sizeof(T_XfsCashOrder));

					//入钞口/退钞口,无钞
					g_BNRStatus.wInShutter = 0;
					g_BNRStatus.wReturnShutter = 0;
					for(i=0; i<g_cashOrder.denomination.size; i++)
					{
						xx1_log_debug(LOG_LEVEL_DEBUG,"----item[%d]=[%d],count=[%d]",\
							g_cashOrder.denomination.items[i].unit,\
							g_cashOrder.denomination.items[i].count);
					}
				}			
				break;
			case XFS_S_CDR_SD_OPEN:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_TAKEN");
				break;
			case XFS_S_CDR_SD_LOCKED:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_TAKEN");
				break;
			case XFS_S_CDR_SD_UNKNOWN:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_TAKEN");
				break;
			case XFS_S_CDR_MAINTENANCE_STATUS_CHANGED:
				{
					xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_CASH_TAKEN");
					memcpy(&g_ModuleIdList, data, sizeof(T_ModuleIdList));
				}			
				break;
			case XFS_S_CDR_TP_OK:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_TP_OK");
				break;
			case XFS_S_CDR_TP_INOP:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_TP_INOP");
				break;
			case XFS_S_CDR_TP_UNKNOWN:
				xx1_log_debug(LOG_LEVEL_DEBUG,"XFS_S_CDR_TP_UNKNOWN");
				break;
			//Cash Module error
			case XFS_E_CDR_OFFSET:
			case XFS_E_CDR_CASHIN_ACTIVE:
			case XFS_E_CDR_CASH_DEVICE_ERROR:
			case XFS_E_CDR_CASH_UNIT_ERROR:
			case XFS_E_CDR_INVALID_CASH_UNIT:
			case XFS_E_CDR_INVALID_CURRENCY:
			case XFS_E_CDR_INVALID_MIXNUMBER:
			case XFS_E_CDR_NOT_DISPENSABLE:
			case XFS_E_CDR_NO_BILLS:
			case XFS_E_CDR_NO_CASHIN_STARTED:
			case XFS_E_CDR_TOO_MANY_BILLS:
			case BNRXFS_E_CDR_USER_ERROR:
				{
					g_BNRStatus.dwErrorCode = status;
				}
				break;	
			default:
				break;
		}//end switch
	}
	/*
	pthread_mutex_trylock (&listenerEvent_mutex);
  	pthread_cond_signal (&listenerEvent);
  	pthread_mutex_unlock (&listenerEvent_mutex);
*/
}//statusOccured

/******************************************************************************
*             intermediateOccured
***************************************************************************//**
* Called when an Intermediate event is received
*
* @param identificationID job identification number
* @param operationID J/XFS operation code
* @param reason J/XFS reason code
* @param data event data. Contents depend upon reason
*
******************************************************************************/
static void __stdcall intermediateOccured(
  LONG32 identificationId, LONG32 operationId, LONG32 reason, void *data)
{

	if(g_log_intermediate== false)
	{
		init_log_thread("intermediate");
		g_log_intermediate=true;
	}
	T_SequenceRejectionCode rejectcode ;
	xx1_log_debug(LOG_LEVEL_DEBUG,"intermediateOccured----identificationId=[%d],operationId=[%d],reason=[%d]",\
		identificationId,operationId,reason);
	switch (operationId)
		{
			case XFS_O_CDR_CASH_IN:
				if (reason == XFS_I_CDR_INPUT_REFUSED) 
				{
				
					g_BNRStatus.wInShutter = 1;
					memcpy(&rejectcode,data,sizeof(T_SequenceRejectionCode));
					if(rejectcode == SRC_CONFIGURATION_REJECT) 
						g_IsRealBanknote = false;
					xx1_log_debug(LOG_LEVEL_DEBUG,"rejectcode=[%d]\n",rejectcode);
				}
				break;
			default:
				break;
		}
}//intermediateOccured


static UINT8 do_ack(INT32 iret)
{
	UINT8 iack = 0;
	switch (iret)
	{
	case BXR_NO_ERROR:
		iack = ACK_SUCCESS;
		break;
	case BXR_API_NOT_OPENED:
		iack = ACK_NOTOPENPORT;
		break;	
	case XFS_E_BUSY:
		iack = ACK_CMDEXECING;
		break;
	case BXR_API_INVALID_PARAMETER:
		iack = ACK_INVALIDPARAM;
		break;
	case BXR_USB_NO_SUCH_DEVICE:
		iack = ACK_NOTOPENPORT;
		break;
	case BNR_OPERATION_TIMEOUT:
		iack = ACK_TIMEOUT;
		break;
	default:
		iack = ACK_SUCCESS;
		break;
	}

	return iack;
}

//钱箱被移走或者打开时清除CB  LO
//清除箱内数据(根据钱箱名，如RE3和RE4)

int CBNROperation::CBNR_ClearCashUnit(const char box_name[8])
{
	T_XfsCashUnit cashUnit;
	memset(&cashUnit,0,sizeof(T_XfsCashUnit));
	
	cashUnit.logicalCashUnitList.maxSize= NBMAXLCU;
	cashUnit.physicalCashUnitList.maxSize=NBMAXPCU;
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_QueryCashUnit(&cashUnit);
	pthread_mutex_unlock (&listenerEvent_mutex);

	int i = 0;
	char tmp_name[8]={0,};
	if(result == BXR_NO_ERROR)
	{
		for(i=0;i<cashUnit.logicalCashUnitList.size;i++)
		{
				tmp_name[0]='\0';
				strncpy(tmp_name,cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name,sizeof(tmp_name)-1);
				if(0==strncmp(box_name,tmp_name,strlen(box_name)))
				{
					cashUnit.logicalCashUnitList.items[i].count=0;
					cashUnit.logicalCashUnitList.items[i].initialCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.deposit.depositCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.deposit.retractedCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.deposit.emptiedCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.deposit.forgeryCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.deposit.disappearedCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.dispense.dispenseCount=0;
					cashUnit.logicalCashUnitList.items[i].extendedCounters.dispense.rejectCount=0;
				}
		}
		for(i=0;i<cashUnit.physicalCashUnitList.size;i++)
		{
			tmp_name[0]='\0';
			strncpy(tmp_name,cashUnit.physicalCashUnitList.items[i].name,sizeof(tmp_name)-1);
			if(0==strncmp(box_name,tmp_name,strlen(box_name)))
			{
				cashUnit.physicalCashUnitList.items[i].count=0;
			}
		}
		pthread_mutex_lock (&listenerEvent_mutex);
		result = bnr_UpdateCashUnit(cashUnit.transportCount,&cashUnit.logicalCashUnitList,&cashUnit.physicalCashUnitList);
		pthread_mutex_unlock (&listenerEvent_mutex);
	
	}
	return result;
}

void CBNROperation::init_cashid_map()
{
	m_cashid_map[RE3_ID]="RE3";
	m_cashid_map[RE4_ID]="RE4";
	m_cashid_map[RE5_ID]="RE5";
	m_cashid_map[RE6_ID]="RE6";
	
}
bool CBNROperation::IsCashInStarted()
{
	return m_IsCashInStarted;
}

CBNROperation::CBNROperation()
{
	init_cashid_map();
	m_IsOpened = false;
	m_IsCashInStarted=false;
	m_IsInletFulled = false;	//入钞口是否有纸币
	m_IsOutletFulled = false;  //退钞口是否有纸币
	m_StoredCount = 0;    //暂存区纸币数量
	g_IsRealBanknote = true;  //钱是否被识别
}

CBNROperation::~CBNROperation()
{
	m_cashid_map.clear();
	m_IsOpened = false;
	m_IsCashInStarted = false;
}
//a1001
T_BnrXfsResult CBNROperation::CBNR_Open()
{
	
	read_config();
	char program_name[16]="CBNROperation";
	int daemonid = 1;
	init_log(g_ConfigInfo.log_level,g_ConfigInfo.log_debug_level,program_name,g_ConfigInfo.log_dir,daemonid);
	init_log_thread("main");
	xx1_log_debug(LOG_LEVEL_MUST,"start bnr operation.....");

	if (m_IsOpened == true)
		return XFS_E_NOT_USED ;
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	memset(g_LcuSeq, 0, sizeof(g_LcuSeq));
	memset(g_ibilldeno, 0, sizeof(g_ibilldeno));
	T_XfsCashUnit cashUnit;
	T_BnrXfsResult result;
	pthread_mutex_lock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Open");
	LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "CBNR_Open Func" );
	result = bnr_Open(operationCompleteOccured, statusOccured, intermediateOccured);
	
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED || abs(result)==BXR_USB_ERROR_OFFSET) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	
	pthread_mutex_unlock (&listenerEvent_mutex);
	
	if (result == BXR_NO_ERROR) 
	{
		m_IsOpened = true;	
		//可能异常状态 复位一下(如果正常不会复位)
		//result=CBNR_Reset();
		if(result == BXR_NO_ERROR)
		{
			T_ModuleIdList moidlist;
			memset(&moidlist, 0, sizeof(moidlist));
			result = CBNR_GetMoudles(&moidlist);
			m_IsCashInStarted = false;
		}
	}

	//	
	//if(result == BXR_NO_ERROR)
	//{
	//	result=CBNR_QueryCashUnit(&cashUnit);
	//}

	
	//查询下状态
	if(result == BXR_NO_ERROR)
	{
		result=CBNR_GetStatus();
	}
	return result;
}
//a1002
T_BnrXfsResult CBNROperation::CBNR_Close()
{
	if (m_IsOpened != true)
		return XFS_E_NOT_USED ;
	T_BnrXfsResult result;
	result = bnr_Close();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED || abs(result)==BXR_USB_ERROR_OFFSET) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}

	m_IsOpened = false;
	
	memcpy(&listenerEvent_mutex,&zero_muttex,sizeof(pthread_mutex_t) );
	memcpy(&listenerEvent, &zero_cond, sizeof(pthread_cond_t) );
	xx1_log_debug(LOG_LEVEL_DEBUG,"end bnr operation.....");
	LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "CBNR_Close Func" );
	return result;
}

T_BnrXfsResult CBNROperation::CBNR_Reboot()
{
	T_BnrXfsResult result;
	pthread_mutex_trylock (&listenerEvent_mutex);
	result = bnr_Reboot();
	m_IsOpened = false;
	if (g_used)
	{
		pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_REBOOT_TIME_OUT_IN_MS));
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
	
}

// 返回值为0 成功
T_BnrXfsResult CBNROperation::CBNR_Reset()
{
	T_BnrXfsResult result;
	
	pthread_mutex_lock (&listenerEvent_mutex);
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	result = bnr_Reset();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if(result>=BXR_NO_ERROR)
	{
		int tResult = pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_RESET_OPERATION_TIME_OUT_IN_MS ));
		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;

			g_BNRStatus.dwErrorCode = result;
			g_iCashInResult = 0;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
		m_IsCashInStarted = false;
	}
	pthread_mutex_unlock (&listenerEvent_mutex);

	 //2001,退钞后,不取钞,超时,发压箱会返回1010,发复位会返回2001
	//此时钞如果取走,先发Retract命令,然后再发复位,
	//如果没取走,不再发Retract命令和复位命令,直接返回故障码
	if (result == BNRXFS_E_CDR_USER_ERROR)
	{
		//经过测试发现: CashInRollback()后,发了Cancel命令后,此时不管退钞口的纸币有没有被取走,
		//GetStatus查状态得到的退钞口始终是有纸币存在,除非此时发Retract命令,
		//因此,修改上面的流程,从维护人员流程作出约束:维护人员在登录后进行复位操作前,须确保退钞口无钞.		
		result = CBNR_Retract();
		//再次复位
		if (result == BXR_NO_ERROR)
		{
			pthread_mutex_lock (&listenerEvent_mutex);
			memset(&g_BNRResult, 0, sizeof(g_BNRResult));
			result = bnr_Reset();

			if (result > BXR_NO_ERROR) 
			{
				int tResult = pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_RESET_OPERATION_TIME_OUT_IN_MS ));
				if(tResult == 0)
				{
					result = g_BNRResult.ocResult;

					g_BNRStatus.dwErrorCode = result;
					g_iCashInResult = 0;
					pthread_mutex_unlock (&listenerEvent_mutex);
				}
				else
				{
					//指定时间内没有收到BNR动作结果
					result = BNR_OPERATION_TIMEOUT;
				}
			}
			pthread_mutex_unlock (&listenerEvent_mutex);
		}
	}
	return result;
}



T_BnrXfsResult CBNROperation::CBNR_CashInStart()
{
	T_BnrXfsResult result;
	pthread_mutex_lock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_CashInStart");
	result = bnr_CashInStart();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		xx1_log_debug(LOG_LEVEL_DEBUG,"BXR_USB_NO_SUCH_DEVICE  error ");
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if(result>BXR_NO_ERROR)
	{
		int tResult = pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_DEFAULT_OPERATION_TIME_OUT_IN_MS ));
		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
			g_iCashInResult = 0;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_CashInStart ");
	return result;
	
}

T_BnrXfsResult CBNROperation::CBNR_CashIn()
{
	T_BnrXfsResult result;
	T_XfsCurrencyCode currencyCode = {"CNY"};
	T_Amount waitAmount=100;
	if (g_iCashInResult == 0)
	{
		pthread_mutex_lock (&listenerEvent_mutex);
		xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_CashIn ");
		result = bnr_CashIn(&waitAmount,&currencyCode);
		if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
		{
			g_iDoOpen = -1;
		}
		else
		{
			g_iDoOpen = result;
		}
		pthread_mutex_unlock (&listenerEvent_mutex);
		g_iCashInResult = result;
		if (result > BXR_NO_ERROR)
		{
		}
	}
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_CashIn ");
	return result;
	
}

T_BnrXfsResult CBNROperation::CBNR_CashInEnd()
{
	T_BnrXfsResult result;
	
	pthread_mutex_lock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_CashInEnd ");
	result = bnr_CashInEnd();
	
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if(result>BXR_NO_ERROR)
	{
		int tResult = pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_DEFAULT_OPERATION_TIME_OUT_IN_MS ));
		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
			g_iCashInResult = 0;
			m_IsCashInStarted = false;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}	
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_CashInEnd ");
	return result;
}
//退回纸币
T_BnrXfsResult CBNROperation::CBNR_CashInRollback()
{
	T_BnrXfsResult result;
	
	pthread_mutex_lock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_CashInRollback ");
	result = bnr_CashInRollback();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR)
	{
		int tResult = pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_DEFAULT_OPERATION_TIME_OUT_IN_MS ));
		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
			g_BNRStatus.dwErrorCode = result;
		}
		
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}
//停收纸币
//在使用CashIn后,还没有投入纸币时,此函数取消本次的接收纸币

T_BnrXfsResult CBNROperation::CBNR_Cancel()
{
	
	T_BnrXfsResult result;
	pthread_mutex_lock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Cancel ");
	result = bnr_Cancel();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	g_iCashInResult = 0;
	pthread_mutex_unlock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_Cancel ret=[%d]",result);
	return result;

}

//纸币找零总函数
//参数:需要找零的张数
 //参数:实际找零的张数
int CBNROperation::CBNR_OddChange(int imethod,UINT32 *ireone, UINT32 *iretwo, UINT32 *irethree, UINT32 *irefour)
{
	int ret =-1;
	T_BnrXfsResult tresult = BXR_NO_ERROR;
	if ( (*ireone+*iretwo+*irethree+*irefour) > 20 )
	{
		ret = -1;
		*ireone = 0;
		*iretwo = 0;
		*irethree = 0;
		*irefour = 0;
		return ret;
	}
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	
	//判断找零是否可行
	//tresult = CBNR_Denominate(imethod,*ireone, *iretwo, *irethree, *irefour);
	
	
	
	//准备找零
	tresult = CBNR_Dispense(imethod,*ireone, *iretwo, *irethree, *irefour);
	if(tresult == BXR_NO_ERROR)
	{
		//执行找零
		tresult = CBNR_Present();
	}

	if(tresult == BXR_NO_ERROR)
	{
		*ireone = g_BNRResult.ReChangeCount[0];
		*iretwo = g_BNRResult.ReChangeCount[1];
		*irethree = g_BNRResult.ReChangeCount[2];
		*irefour = g_BNRResult.ReChangeCount[3];
		xx1_log_debug(LOG_LEVEL_DEBUG,"实际找零:(RE3=[%d],RE4=[%d],RE5=[%d],RE6=[%d])\n",*ireone,*iretwo,*irethree,*irefour);
		ret = 0;
	}
	else
	{
		xx1_log_debug(LOG_LEVEL_DEBUG,"找零失败");
	}
	return ret;
}


//判断找零是否可行
T_BnrXfsResult CBNROperation::CBNR_Denominate(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour)
{
	T_BnrXfsResult result = BXR_NO_ERROR;
	T_XfsDispenseRequest dispenseRequest;
	T_XfsCurrencyCode currencyCode = {"CNY"};

	memset(&dispenseRequest,0, sizeof(T_XfsDispenseRequest));
	strncpy(dispenseRequest.currency.currencyCode,currencyCode,sizeof(T_XfsCurrencyCode));

	if (imethod == 1)
	{
		dispenseRequest.mixNumber = XFS_C_CDR_MXA_MIN_BILLS;
		dispenseRequest.denomination.amount = ireone*g_ibilldeno[0] + iretwo*g_ibilldeno[1] + irethree*g_ibilldeno[2] + irefour*g_ibilldeno[3];

	} 
	else
	{
		dispenseRequest.mixNumber = XFS_C_CDR_MIX_DENOM;
// 		dispenseRequest.denomination.size = 4;
// 		dispenseRequest.denomination.items[0].unit = g_LcuSeq[0];
// 		dispenseRequest.denomination.items[0].count = ireone;
// 		dispenseRequest.denomination.items[1].unit = g_LcuSeq[1];
// 		dispenseRequest.denomination.items[1].count = iretwo;
// 		dispenseRequest.denomination.items[2].unit = g_LcuSeq[2];
// 		dispenseRequest.denomination.items[2].count = irethree;
// 		dispenseRequest.denomination.items[3].unit = g_LcuSeq[3];
// 		dispenseRequest.denomination.items[3].count = irefour;

		UINT32 irecount[4] = {ireone, iretwo, irethree, irefour};
		dispenseRequest.denomination.size = g_ModuleList.ireboxnum;
		for (int i=g_ModuleList.ireboxnum-1; i>=0; i--)
		{
			//dispenseRequest.denomination.items[i].unit = g_LcuSeq[i+4-g_ModuleList.ireboxnum];
			//dispenseRequest.denomination.items[i].count = irecount[i+4-g_ModuleList.ireboxnum];
			dispenseRequest.denomination.items[i].unit = g_LcuSeq[i];
			dispenseRequest.denomination.items[i].count = irecount[i];
		}
	}
		
	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_Denominate(&dispenseRequest);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR) 
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_CHANGE_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
		
		
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}

//准备找零
T_BnrXfsResult CBNROperation::CBNR_Dispense(int imethod,UINT32 ireone, UINT32 iretwo, UINT32 irethree, UINT32 irefour)
{
	T_BnrXfsResult result = BXR_NO_ERROR;
	T_XfsDispenseRequest dispenseRequest;
	T_XfsCurrencyCode currencyCode = {"CNY"};

	memset(&dispenseRequest, 0,sizeof(T_XfsDispenseRequest));
	strncpy(dispenseRequest.currency.currencyCode, currencyCode,sizeof(T_XfsCurrencyCode));

	
	if (imethod == 1)
	{
		dispenseRequest.mixNumber = BNRXFS_C_CDR_MXA_OPTIMUM_CHANGE;
		dispenseRequest.denomination.amount = ireone*g_ibilldeno[0] + iretwo*g_ibilldeno[1] + irethree*g_ibilldeno[2] + irefour*g_ibilldeno[3];
	} 
	else
	{
		dispenseRequest.mixNumber = XFS_C_CDR_MIX_DENOM;
	//		dispenseRequest.denomination.size = 4;
	//		dispenseRequest.denomination.items[0].unit = g_LcuSeq[0];
	//		dispenseRequest.denomination.items[0].count = ireone;
	//		dispenseRequest.denomination.items[1].unit = g_LcuSeq[1];
	//		dispenseRequest.denomination.items[1].count = iretwo;
	//		dispenseRequest.denomination.items[2].unit = g_LcuSeq[2];
	//		dispenseRequest.denomination.items[2].count = irethree;
	//		dispenseRequest.denomination.items[3].unit = g_LcuSeq[3];
	//		dispenseRequest.denomination.items[3].count = irefour;
	
		UINT32 irecount[4] = {ireone, iretwo, irethree, irefour};
		dispenseRequest.denomination.size = g_ModuleList.ireboxnum;
		for (int i=g_ModuleList.ireboxnum-1; i>=0; i--)
		{
			dispenseRequest.denomination.items[i].unit = g_LcuSeq[i];
			dispenseRequest.denomination.items[i].count = irecount[i];
		}
	}
	
	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_Dispense(&dispenseRequest);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR) 
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_CASHIN_OPERATION_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;

		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
		
		
	}
	pthread_mutex_unlock (&listenerEvent_mutex);

	return result;
}

//执行找零
T_BnrXfsResult CBNROperation::CBNR_Present()
{
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_Present();

	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR) 
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_CASHIN_OPERATION_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}	
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	
	return result;
}
//清空循环箱至回收箱
T_BnrXfsResult CBNROperation::CBNR_Empty(std::string vstr, BOOL toFloat)
{

	char str[256] = {0};

	sprintf(str, "%s", vstr.c_str());

	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_Empty(str, FALSE);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	
	if (result > BXR_NO_ERROR)
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_CASHIN_OPERATION_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
		
	}
	pthread_mutex_unlock (&listenerEvent_mutex);

	return result;
}

//设定支持的币种列表
T_BnrXfsResult CBNROperation::CBNR_UpdateDenominations(BOOL *bcashenable)
{
		T_BnrXfsResult result = BXR_NO_ERROR;
		T_DenominationList DenominationList;
		DenominationList.maxSize = MAX_NR_OF_DENOMINATION;
		//BOOL bcashenable[7]={FALSE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}; //1元,2元,5元,10元,20元,50元,100元
		UINT32 i = 0;

		pthread_mutex_lock (&listenerEvent_mutex);
		result = bnr_QueryDenominations(&DenominationList);
		pthread_mutex_unlock (&listenerEvent_mutex);
		if (result == BXR_NO_ERROR)
		{
			printf("DenominationList size=[%d]\n",DenominationList.size);
			for (i=0; i<DenominationList.size; i++)
			{
				
				T_Amount amount = DenominationList.items[i].cashType.value;
				printf("amount=[%d],bool=[%d]\n",amount,DenominationList.items[i].enableDenomination);
				switch (amount)
				{
					case RMB_AMOUNT_1:
						DenominationList.items[i].enableDenomination = bcashenable[0];
						break;						
					case RMB_AMOUNT_2:						
						DenominationList.items[i].enableDenomination = bcashenable[1];
						break;						
					case RMB_AMOUNT_5:
						DenominationList.items[i].enableDenomination = bcashenable[2];
						break;						
					case RMB_AMOUNT_10:
						DenominationList.items[i].enableDenomination = bcashenable[3];
						break;					
					case RMB_AMOUNT_20:
						DenominationList.items[i].enableDenomination = bcashenable[4];
						break;				
					case RMB_AMOUNT_50:
						DenominationList.items[i].enableDenomination = bcashenable[5];
						break;
					case RMB_AMOUNT_100:
						DenominationList.items[i].enableDenomination = bcashenable[6];
						break;
					default:
						break;
				}
				
			}
	
			pthread_mutex_lock (&listenerEvent_mutex);
			result = bnr_UpdateDenominations(&DenominationList);
			if (result == -10516 || result==-10521)
			{
				g_iDoOpen = -1;
			}
			else
			{
				g_iDoOpen = result;
			}
			pthread_mutex_unlock (&listenerEvent_mutex);
	
		}
	
		return result;

	
}

//设置钱箱数据  a1012
T_BnrXfsResult CBNROperation::CBNR_SetCashUnit(int yuan_amount[5] ,int yuan_maxcount[5] )
{
	T_XfsCashUnit cashUnit;
	T_XfsCashType Lo_cashtype;
	UINT32 lo_variant =0;
	T_Amount lo_value=0;
	memset(&cashUnit,0,sizeof(T_XfsCashUnit));
	cashUnit.logicalCashUnitList.maxSize= NBMAXLCU;
	cashUnit.physicalCashUnitList.maxSize=NBMAXPCU;
	
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_QueryCashUnit(&cashUnit);
	pthread_mutex_unlock (&listenerEvent_mutex);
	int i=0;
	int iconfig = 0; 
	UINT32 amount=0;
	if (result == BXR_NO_ERROR)
	{
		
		for (i=0;i<cashUnit.physicalCashUnitList.size;i++)
		{
			
			if(memcmp("LO1", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				cashUnit.physicalCashUnitList.items[i].threshold.full =0;
				cashUnit.physicalCashUnitList.items[i].threshold.high = 0;
				cashUnit.physicalCashUnitList.items[i].threshold.low = 0;
				cashUnit.physicalCashUnitList.items[i].threshold.empty = 0;	
				cashUnit.physicalCashUnitList.items[i].thresholdStatus= XFS_S_BIN_OK;	
				//cashUnit.physicalCashUnitList.items[i].count=2;
			}
			
			if (memcmp("RE3", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				if(yuan_amount[0]==0 )
				{
					if(cashUnit.physicalCashUnitList.items[i].lock != 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 1;
						iconfig = 0x01;
					}
				}
				else
				{
					if(cashUnit.physicalCashUnitList.items[i].lock == 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 0;	
						iconfig = 0x01;
					}
					cashUnit.physicalCashUnitList.items[i].threshold.full = yuan_maxcount[0];
				}
			}
			if (memcmp("RE4", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				if(yuan_amount[1]==0 )
				{
					if(cashUnit.physicalCashUnitList.items[i].lock != 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 1;
						iconfig = 0x01;
					}
				}
				else
				{
					if(cashUnit.physicalCashUnitList.items[i].lock == 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 0;	
						iconfig = 0x01;
					}
					cashUnit.physicalCashUnitList.items[i].threshold.full = yuan_maxcount[1];
				}
			}
			if (memcmp("RE5", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				if(yuan_amount[2]==0 )
				{
					if(cashUnit.physicalCashUnitList.items[i].lock != 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 1;
						iconfig = 0x01;
					}
				}
				else
				{
					if(cashUnit.physicalCashUnitList.items[i].lock == 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 0;	
						iconfig = 0x01;
					}
					cashUnit.physicalCashUnitList.items[i].threshold.full = yuan_maxcount[2];
				}
			}
			if (memcmp("RE6", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				if(yuan_amount[3]==0 )
				{
					if(cashUnit.physicalCashUnitList.items[i].lock != 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 1;
						iconfig = 0x01;
					}
				}
				else
				{
					if(cashUnit.physicalCashUnitList.items[i].lock == 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 0;
						iconfig = 0x01;
					}
					cashUnit.physicalCashUnitList.items[i].threshold.full = yuan_maxcount[3];
				}
			}
			if (memcmp("LO1", cashUnit.physicalCashUnitList.items[i].name, 3) == 0)
			{
				//yuan_amount[4]==0 时 锁上,  !=0 时保持不变
				if(yuan_amount[4]==0 )
				{
					if(cashUnit.physicalCashUnitList.items[i].lock != 1)
					{
						cashUnit.physicalCashUnitList.items[i].lock = 1;
						iconfig = 0x01;
					}
				}
			}
			
		}
		for (i=0; i<cashUnit.logicalCashUnitList.size; i++)
		{
			amount = 0;
			if (memcmp("RE3", cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3) == 0)
			{
				amount =yuan_amount[0];
			}
			if (memcmp("RE4", cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3) == 0)
			{
				amount =yuan_amount[1];
			}
			if (memcmp("RE5", cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3) == 0)
			{
				amount =yuan_amount[2];
			}
			if (memcmp("RE6", cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3) == 0)
			{
				amount =yuan_amount[3];
			}
			if (memcmp("LO1", cashUnit.logicalCashUnitList.items[i].physicalCashUnit->name, 3) == 0)
			{
				//补币模块更改cashtype 不能用configueunit  
				amount =yuan_amount[4];
				lo_value=amount*100;
				lo_variant = cashUnit.logicalCashUnitList.items[i].cashType.variant;
				//continue;
			}
			if (amount != 0 &&amount*100 != cashUnit.logicalCashUnitList.items[i].cashType.value)
			{
					iconfig = 0x01;
					cashUnit.logicalCashUnitList.items[i].cashType.value = amount*100;
					switch (amount)
					{
					case 1:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4142; //AB
						break;	
					case 2:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4141; //AA
						break;
					case 5:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4142; //AB
						break;
					case 10:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4142; //AB
						break;
					case 20:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4141; //AA
						break;	
					case 50:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4143; //AC
						break;
					case 100:
						cashUnit.logicalCashUnitList.items[i].cashType.variant = 0x4143; //AC
						break;
					}
					
				}						
			}
	}
	//Module cash type设置 补币箱只能这个函数设置
	
	if(g_ModuleList.iloboxexist && yuan_amount[4]!=0)
	{
		pthread_mutex_lock (&listenerEvent_mutex);
		result = module_GetCashType(g_ModuleList.dwloid, &Lo_cashtype);
		pthread_mutex_unlock (&listenerEvent_mutex);
	
		pthread_mutex_lock (&listenerEvent_mutex);
		if(lo_value != Lo_cashtype.value || Lo_cashtype.variant !=lo_variant)
		{
			Lo_cashtype.value = lo_value;
			Lo_cashtype.variant = lo_variant;
			strncpy(Lo_cashtype.currencyCode,"CNY",sizeof(Lo_cashtype.currencyCode)-1);
			result = module_SetCashType(g_ModuleList.dwloid, &Lo_cashtype);
			iconfig = 0x01;
			if (abs(result) == BXR_USB_DEVICE_NOT_FOUND || abs(result)== BXR_USB_DEVICE_REMOVED)
			{
				g_iDoOpen = -1;
			}
			else
			{
				g_iDoOpen = result;
			}
		}
		pthread_mutex_unlock (&listenerEvent_mutex);
	}

	// 需要复位reset
	
	if (iconfig == 1)
	{
		result = bnr_ConfigureCashUnit(cashUnit.transportCount, &cashUnit.logicalCashUnitList, &cashUnit.physicalCashUnitList);
		result = CBNR_Reset();
	} 
	else
	{
		result = bnr_UpdateCashUnit(cashUnit.transportCount, &cashUnit.logicalCashUnitList, &cashUnit.physicalCashUnitList);
	}
	
	return result;
	
}

//状态纸币单元查询-获取钱箱信息
T_BnrXfsResult CBNROperation::CBNR_QueryCashUnit(T_XfsCashUnit *cashUnit)
{
	memset(cashUnit,0,sizeof(T_XfsCashUnit));
	cashUnit->logicalCashUnitList.maxSize= NBMAXLCU;
	cashUnit->physicalCashUnitList.maxSize=NBMAXPCU;
	UINT32 variant;
	char cu_name[16] ={0,};
	char noteCode[4] = {0}; //纸币币种
	UINT32 notevalue = 0; //纸币面额，单位元
	UINT16 notecount = 0; //纸币张数
	UINT16 donotcount = 0;	//未入账张数
	UINT16 fullcount = 0;	//最大张数
	UINT8 boxstatus = 0;	//钞箱状态
	char   boxstatus_str[64]={0,};
	UINT16 highcount = 0;		
	UINT16 lowcount = 0;
	UINT16 index = 0;
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_QueryCashUnit(cashUnit);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	
	pthread_mutex_unlock (&listenerEvent_mutex);
	int i =0;
	char index_str[4]={0,};
	if (result == BXR_NO_ERROR)
	{	
		memset(&g_CashBox_Num,0,sizeof(g_CashBox_Num));
		memcpy(&g_CashUnit,cashUnit , sizeof(T_XfsCashUnit));
		//PCU 物理单元的 thresholdStatus(BU RE CU LO 都包含)
		for (i=0; i<cashUnit->physicalCashUnitList.size; i++)
		{
			strncpy(cu_name,cashUnit->physicalCashUnitList.items[i].name,sizeof(cu_name)-1);
			printf("PCU name=[%s],lock=[%d],count=[%d],status=[%d],thresholdMode=[%d],thresholdStatus=[%d],full=[%d],high=[%d],low=[%d]\n\n",cu_name,\
					cashUnit->physicalCashUnitList.items[i].lock,\
					cashUnit->physicalCashUnitList.items[i].count,\
					cashUnit->physicalCashUnitList.items[i].status,\
					cashUnit->physicalCashUnitList.items[i].thresholdMode,\
					cashUnit->physicalCashUnitList.items[i].thresholdStatus,\
					cashUnit->physicalCashUnitList.items[i].threshold.full,\
					cashUnit->physicalCashUnitList.items[i].threshold.high,\
					cashUnit->physicalCashUnitList.items[i].threshold.low);
			if (memcmp("CB", cashUnit->physicalCashUnitList.items[i].name, 2)==0)
			{
				
			
				//在位或者不在位
				if (cashUnit->physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_OK)
				{
					g_BNRStatus.dwcuid=CASHBOX_ID;
					g_BNRStatus.cCBBOX = 0;
				}
				else
				{
					g_BNRStatus.cCBBOX = 1;
					g_BNRStatus.dwcuid=0;
				}
			}
			if (memcmp("LO", cashUnit->physicalCashUnitList.items[i].name, 2)==0)
			{
				//在位,空或非空
				if (cashUnit->physicalCashUnitList.items[i].status == XFS_C_CDR_LCU_OK)
				{
					if (cashUnit->physicalCashUnitList.items[i].thresholdStatus == XFS_S_BIN_EMPTY)
					{
						g_BNRStatus.cLOBOX = 2;
					} 
					else
					{
						g_BNRStatus.cLOBOX = 0;
					}
				}
				else
				{ //不在位
					g_BNRStatus.cLOBOX = 1;
				}
			
			}
			switch (cashUnit->physicalCashUnitList.items[i].thresholdStatus)
				{
				case XFS_S_BIN_OK:
					boxstatus = 0;
					break;
				case XFS_S_BIN_FULL:
					boxstatus = 1;
					break;
				case XFS_S_BIN_HIGH:
					boxstatus = 2;
					break;
				case XFS_S_BIN_LOW:
					boxstatus = 3;
					break;
				case XFS_S_BIN_EMPTY:
					boxstatus = 4;
					break;
				case XFS_S_BIN_UNKNOWN:
					boxstatus = 5;
					break;
				case XFS_S_BIN_NOTSUPPORTED:
					boxstatus = 6;
					break;
				}
			m_PCUStatus_map[cu_name]=boxstatus;
		}
		
		//LCU补币箱信息
		for (i=0; i<cashUnit->logicalCashUnitList.size; i++)
		{
			boxstatus_str[0]='\0';
			cu_name[0]='\0';
			noteCode[0]='\0';
			index_str[0]='\0';
			variant = cashUnit->logicalCashUnitList.items[i].cashType.variant;
			strncpy(cu_name,cashUnit->logicalCashUnitList.items[i].physicalCashUnit->name,sizeof(cu_name)-1);

			strncpy(index_str,cu_name+2,1);
			index=atoi(index_str);
			if(memcmp("LO",cu_name,2)==0)
			{
				if(index_str=='\0')  //add by jfren @20161219
				{
					continue;
				}
				if(cashUnit->logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_BILL_CASSETTE)
				{
					g_LcuSeq[index+7]=cashUnit->logicalCashUnitList.items[i].number;
				}
				if(cashUnit->logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
				{
					g_LcuSeq[index+8]=cashUnit->logicalCashUnitList.items[i].number;
				}
					
			
			}
		}
		//LCU循环箱状态查看(主要逻辑单元)
		for (i=0; i<cashUnit->logicalCashUnitList.size; i++)
		{
			boxstatus_str[0]='\0';
			cu_name[0]='\0';
			noteCode[0]='\0';
			index_str[0]='\0';
			variant = cashUnit->logicalCashUnitList.items[i].cashType.variant;
			strncpy(cu_name,cashUnit->logicalCashUnitList.items[i].physicalCashUnit->name,sizeof(cu_name)-1);
			
			
			strncpy(index_str,cu_name+2,1);
			index=atoi(index_str);
			if (memcmp("RE", cu_name, 2) == 0 || memcmp("LO",cu_name,2)==0 || memcmp("BU", cu_name, 2)== 0||\
				memcmp("CB", cu_name, 2)==0 )
			{
				//纸币币种(循环找零箱)
				 strncpy(noteCode,cashUnit->logicalCashUnitList.items[i].cashType.currencyCode,sizeof(noteCode));				 
				 //无效的RE
				 //if(noteCode[0]=='\0')
				 //	continue;
				 
				//纸币面额
				notevalue = cashUnit->logicalCashUnitList.items[i].cashType.value/100;

				
				
				if(index_str[0]!='\0')  //add by jfren @20161219
				{
					g_ibilldeno[index-3] = notevalue*100;
				}

				//入账纸币张数
				if(cashUnit->logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_BILL_CASSETTE)
				{
					notecount = cashUnit->logicalCashUnitList.items[i].count;
					if(index_str[0]!='\0')  //add by jfren @20161219
					{
						g_iREbillCount[index-3] = notecount;  //入账的纸币数量  //add by jfren @20161219
						g_LcuSeq[index-3] = cashUnit->logicalCashUnitList.items[i].number;
					}
				}

				//在暂存区的 未入账纸币张数
				if(cashUnit->logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_ESCROW)
				{
					donotcount = cashUnit->logicalCashUnitList.items[i].count;
					if(index_str[0]!='\0')  //add by jfren @20161219
					{
						g_LcuSeq[index+1] = cashUnit->logicalCashUnitList.items[i].number;
					}
				}
				if(memcmp("CB", cu_name, 2)==0 )
				{
					switch (notevalue)
					{
						case 1:
							g_CashBox_Num[0] +=notecount;
							break;
						case 2:
							g_CashBox_Num[1] +=notecount;
							break;
						case 5:
							g_CashBox_Num[2] +=notecount;
							break;
						case 10:
							g_CashBox_Num[3] +=notecount;
							break;
						case 20:
							g_CashBox_Num[4] +=notecount;
							break;
						case 50:
							g_CashBox_Num[5] +=notecount;
							break;
						case 100:
							g_CashBox_Num[6] +=notecount;
							break;	
					};
				}
				//支持纸币最大张数
				//fullcount = cashUnit->physicalCashUnitList.items[i].threshold.full;
				fullcount = cashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.full;
		
				//高位纸币张数
				//highcount = cashUnit.physicalCashUnitList.items[i].threshold.high;
				highcount = cashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.high;
		
				//低位纸币张数
				//lowcount = cashUnit.physicalCashUnitList.items[i].threshold.low;
				lowcount = cashUnit->logicalCashUnitList.items[i].physicalCashUnit->threshold.low;
		

				printf("name=[%s],curcode=[%s],cashvalue=[%d],variant=[%04x],in_count=[%d],no_count=[%d],full=[%d],high=[%d],low=[%d]\n",\
					cu_name,noteCode,notevalue,variant,notecount,donotcount,fullcount,highcount,lowcount);
					
			}
		}
	}
	return result;
}

T_BnrXfsResult CBNROperation::CBNR_SetReCBPositionNum(int fulls[5],int highs[5],int lows[5],int emptys[5])
{
	T_XfsCashUnit cashUnit;
	memset(&cashUnit,0,sizeof(T_XfsCashUnit));
	T_BnrXfsResult result=BXR_NO_ERROR;
	result=CBNR_QueryCashUnit(&cashUnit);
	
	char cu_name[16]={0,};
	char index_str[4]={0,};
	int index =0;
	int i =0;
	if (result == BXR_NO_ERROR)
	{		
		for (i=0; i<cashUnit.logicalCashUnitList.size; i++)
		{
			strncpy(cu_name,cashUnit.physicalCashUnitList.items[i].name,sizeof(cu_name)-1);
			
			if(strncmp(cu_name,"RE",2)==0)
			{
				strncpy(index_str,cu_name+2,1);
				index=atoi(index_str);  //0:RE3  1:RE4 2:RE5 3:RE6
				
				if (cashUnit.physicalCashUnitList.items[i].threshold.low != lows[index-3] ||
					cashUnit.physicalCashUnitList.items[i].threshold.high!= highs[index-3]||
					cashUnit.physicalCashUnitList.items[i].threshold.full != fulls[index-3]||
					cashUnit.physicalCashUnitList.items[i].threshold.empty != emptys[index-3])
				{
					cashUnit.physicalCashUnitList.items[i].threshold.full = fulls[index-3];
					cashUnit.physicalCashUnitList.items[i].threshold.high = highs[index-3];
					cashUnit.physicalCashUnitList.items[i].threshold.low = lows[index-3];	//0;
					cashUnit.physicalCashUnitList.items[i].threshold.empty = emptys[index-3];
				} 				
			}
			if(strncmp(cu_name,"CB",2)==0)
			{
				cashUnit.physicalCashUnitList.items[i].threshold.full = fulls[4];
				cashUnit.physicalCashUnitList.items[i].threshold.high = highs[4];
				cashUnit.physicalCashUnitList.items[i].threshold.low = lows[4];	//0;
				cashUnit.physicalCashUnitList.items[i].threshold.empty = emptys[4];
			}
		}
		pthread_mutex_lock (&listenerEvent_mutex);
		result=bnr_UpdateCashUnit(cashUnit.transportCount,&cashUnit.logicalCashUnitList,&cashUnit.physicalCashUnitList);
		pthread_mutex_unlock (&listenerEvent_mutex);
		return result;
	}
}



//喷出进出口纸币
T_BnrXfsResult CBNROperation::CBNR_Eject()
{
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_Eject();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}

//缩回出口纸币
T_BnrXfsResult CBNROperation::CBNR_Retract()
{
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_Retract();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR) 
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_DEFAULT_OPERATION_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
		
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}


//清暂存纸币
T_BnrXfsResult CBNROperation::CBNR_Reject()
{
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_Reject();
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	if (result > BXR_NO_ERROR) 
	{
		int tResult= pthread_cond_timedwait (& listenerEvent, & listenerEvent_mutex,
			setTimeout(&eventTimeOut,BNR_CASHIN_OPERATION_TIME_OUT_IN_MS ));

		if(tResult == 0)
		{
			result = g_BNRResult.ocResult;
		}
		else
		{
			result = BNR_OPERATION_TIMEOUT;
		}
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}
//============================================================================
//开始接收纸币-a1001
T_BnrXfsResult CBNROperation::CBNR_Enable()
{
	T_BnrXfsResult tresult = BXR_NO_ERROR;
	//bnr_CashInStart()调用第1次,返回成功,第二次再调用,返回-6072(XFS_E_CDR_CASHIN_ACTIVE)
	//或者-1010(XFS_E_ILLEGAL).
	//需增加变量来避免多次start
	memset(&g_cashOrder,0,sizeof(T_XfsCashOrder));
	if (!m_IsCashInStarted)
	{
		xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Enable ");
		tresult = CBNR_CashInStart();
		if (tresult == BXR_NO_ERROR|| abs(tresult)==XFS_E_CDR_CASHIN_ACTIVE)
		{
			m_IsCashInStarted = true;
		}
	}
	g_IsRealBanknote = true; 
	if(m_IsCashInStarted = true)
	{
		g_StoredNote = 0;
		tresult = CBNR_CashIn();
		xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_Enable ");
	}
	if (tresult >= BXR_NO_ERROR)
	{
		return 0;
	}
	return tresult;
}

//取消接收纸币
T_BnrXfsResult CBNROperation::CBNR_Disable()
{
	T_BnrXfsResult tresult;
	
	tresult = CBNR_Cancel();
	g_StoredNote = 0;
	//tresult = CBNR_CashInEnd();
	return tresult;
}

//纸币压箱
T_BnrXfsResult CBNROperation::CBNR_Encash()
{

	memset(&g_cashOrder,0,sizeof(T_XfsCashOrder));
	T_BnrXfsResult tresult;
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Encash ");
	tresult = CBNR_CashInEnd();
	if(tresult >BXR_NO_ERROR)
	{
		g_StoredNote = 0;
	}
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_Encash ");
	return tresult;
}

//退出纸币
T_BnrXfsResult CBNROperation::CBNR_Refund()
{
	T_BnrXfsResult tresult;
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Refund ");
	tresult = CBNR_Cancel();
	tresult = CBNR_CashInRollback();
	g_StoredNote = 0;
	xx1_log_debug(LOG_LEVEL_DEBUG,"end CBNR_Refund ");
	return tresult;
}




//清币至回收箱 a1026
// 0-3  RE
// 4 LO
T_BnrXfsResult CBNROperation::CBNR_EmptytoRecycle(int uiclear[5])
{
	T_BnrXfsResult tresult = BXR_NO_ERROR;
	T_BnrXfsResult tworesult = BXR_NO_ERROR;
	T_XfsCashUnit beforeunit,afterunit;
	int i=0;
	int j=0;
	UINT32 billcount = 0;
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	memset(&g_LOClear_Num,0,sizeof(g_LOClear_Num));
	memset(&g_REClear_Num,0,sizeof(g_REClear_Num));
	if(uiclear[4]==1 && g_ModuleList.iloboxexist)
	{
		while (1)
		{
			xx1_log_debug(LOG_LEVEL_NOTICE,"---------------清补币箱LO前查询CashUnit-----------");
			tresult = CBNR_QueryCashUnit(&beforeunit);
			INT32 iret = abs(tresult);
			if (iret == XFS_E_BUSY)
			{
				sleep(1);
				continue;
			}
			else if (iret == BXR_NO_ERROR)
			{
				break;
			}
			else if (iret==1 ||iret==10516 || iret==10521)
			{
				xx1_log_debug(LOG_LEVEL_WARNING,"清补币箱时异常,CBNR_QueryCashUnit beforeunit ACK_NOTOPENPORT");
				break;
			}
			else
			{
				sleep(1);
			}
		}
		if ( abs(tresult)==10516 || abs(tresult)==1 || abs(tresult)==10521)
		{
			xx1_log_debug(LOG_LEVEL_WARNING,"清补币箱时异常,人工处理,CBNR_QueryCashUnit afterunit ACK_NOTOPENPORT");
			return ACK_NOTOPENPORT;
		}
		
		if (tresult == BXR_NO_ERROR && g_ConfigInfo.iloaderlock==1)
		{
			tresult == CBNR_LockCashBox( g_ModuleList.loname,false);
			if(tresult == BXR_NO_ERROR)
			{
				tresult = CBNR_Reset();
				if(tresult!=BXR_NO_ERROR)
				{
					xx1_log_debug(LOG_LEVEL_WARNING,"清补币箱时异常,人工处理,CBNR_QueryCashUnit afterunit ACK_NOTOPENPORT");
					return ACK_NOTOPENPORT;
				}
			}
			
		}

		tresult =CBNR_Empty( g_ModuleList.loname,FALSE);
		while (1)
		{
			xx1_log_debug(LOG_LEVEL_NOTICE,"---------------清补币箱LO后查询CashUnit-----------");
			tworesult = CBNR_QueryCashUnit(&afterunit);
			INT32 iret = abs(tworesult);
			if (iret == XFS_E_BUSY)
			{
				sleep(1);
				continue;
			}
			else if (iret == BXR_NO_ERROR)
			{
				break;
			}
			else if (iret==1 ||iret==10516 || iret==10521)
			{
				xx1_log_debug(LOG_LEVEL_ERROR,"清补币箱时异常,CBNR_QueryCashUnit afterunit ACK_NOTOPENPORT");
				break;
			}
			else
			{
				sleep(1);
			}
		}

		for (i=0; i<afterunit.logicalCashUnitList.size; i++)
		{					
			if ( (memcmp("CB", afterunit.logicalCashUnitList.items[i].physicalCashUnit->name, 2)==0) && 
				(afterunit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_REJECT_CASSETTE))
			{
				g_LOClear_Num[7] +=billcount;
				billcount = afterunit.logicalCashUnitList.items[i].count - beforeunit.logicalCashUnitList.items[i].count;
				xx1_log_debug(LOG_LEVEL_MUST,"补币箱清%s,不识别的纸币,数量:%d",\
					g_ModuleList.loname,billcount);
				
			}
			if ( (memcmp("CB", afterunit.logicalCashUnitList.items[i].physicalCashUnit->name, 2)==0) && 
				(afterunit.logicalCashUnitList.items[i].cuType==XFS_C_CDR_LCU_BILL_CASSETTE))
			{
				billcount = afterunit.logicalCashUnitList.items[i].count - beforeunit.logicalCashUnitList.items[i].count;
				
				switch (afterunit.logicalCashUnitList.items[i].cashType.value/100)
				{
					case 1:
						g_LOClear_Num[0] +=billcount;
						break;
					case 2:
						g_LOClear_Num[1] +=billcount;
						break;
					case 5:
						g_LOClear_Num[2] +=billcount;
						break;
					case 10:
						g_LOClear_Num[3] +=billcount;
						break;
					case 20:
						g_LOClear_Num[4] +=billcount;
						break;
					case 50:
						g_LOClear_Num[5] +=billcount;
						break;
					case 100:
						g_LOClear_Num[6] +=billcount;
						break;
				};
				xx1_log_debug(LOG_LEVEL_MUST,"补币箱清%s,面额:%d元,数量:%d",\
					g_ModuleList.loname,\
					afterunit.logicalCashUnitList.items[i].cashType.value/100,billcount);
			}
				
		}

						
	}
	
	//4个循环箱开始清币
	//清循环箱币后查询
	billcount=0;
	while (1)
	{
		xx1_log_debug(LOG_LEVEL_NOTICE,"---------------清循环箱RE前查询CashUnit-----------");
		tresult = CBNR_QueryCashUnit(&beforeunit);
		INT32 iret = abs(tresult);
		if (iret == XFS_E_BUSY)
		{
			sleep(1);
			continue;
		}
		else if (iret == BXR_NO_ERROR)
		{
			break;
		}
		else if (iret==1 ||iret==10516 || iret==10521)
		{
			xx1_log_debug(LOG_LEVEL_WARNING,"清币时异常,CBNR_QueryCashUnit beforeunit ACK_NOTOPENPORT");
			break;
		}
		else
		{
			sleep(1);
		}
	}
	
	if (tresult == BXR_NO_ERROR)
	{
		for (i=0;i<sizeof(g_ModuleList.ireboxexist)/sizeof(BYTE);i++)
		{
			if(g_ModuleList.ireboxexist[i] && uiclear[i]>0)
			{
				tresult = CBNR_Empty(g_ModuleList.reboxname[i], FALSE);
				xx1_log_debug(LOG_LEVEL_MUST,"清%s,返回值=%d\n",g_ModuleList.reboxname[0],abs(tresult));
			}
		}
	}
	//清循环箱币后查询
	while (1)
	{
		xx1_log_debug(LOG_LEVEL_NOTICE,"---------------清循环箱RE后查询CashUnit-----------");
		tworesult = CBNR_QueryCashUnit(&afterunit);
		INT32 iret = abs(tworesult);
		if (iret == XFS_E_BUSY)
		{
			sleep(1);
			continue;
		}
		else if (iret == BXR_NO_ERROR)
		{
			break;
		}
		else if (iret==1 ||iret==10516 || iret==10521)
		{
			xx1_log_debug(LOG_LEVEL_ERROR,"清币时异常,CBNR_QueryCashUnit afterunit ACK_NOTOPENPORT");
			break;
		}
		else
		{
			sleep(1);
		}
	}
	
	if (tworesult == BXR_NO_ERROR)
	{
		for (i=0;i<sizeof(g_ModuleList.ireboxexist)/sizeof(BYTE);i++)
		{
			billcount = 0;
			if(g_ModuleList.ireboxexist[i])
			{
				for(j=0;j<afterunit.logicalCashUnitList.size; j++)
				{
					if ( (memcmp(g_ModuleList.reboxname[i], afterunit.logicalCashUnitList.items[j].physicalCashUnit->name, 3)==0) &&
					(afterunit.logicalCashUnitList.items[j].cuType==XFS_C_CDR_LCU_BILL_CASSETTE)
					)
					{
						g_BNRResult.ReClearCount[i]=billcount;
						billcount = beforeunit.logicalCashUnitList.items[j].count - afterunit.logicalCashUnitList.items[j].count;
						
						switch (afterunit.logicalCashUnitList.items[j].cashType.value/100)
						{
							case 1:
								g_REClear_Num[0] +=billcount;
								break;
							case 2:
								g_REClear_Num[1] +=billcount;
								break;
							case 5:
								g_REClear_Num[2] +=billcount;
								break;
							case 10:
								g_REClear_Num[3] +=billcount;
								break;
							case 20:
								g_REClear_Num[4] +=billcount;
								break;
							case 50:
								g_REClear_Num[5] +=billcount;
								break;
							case 100:
								g_REClear_Num[6] +=billcount;
								break;
						};
							
						xx1_log_debug(LOG_LEVEL_MUST,"清%s,面额:%d元,数量:%d",g_ModuleList.reboxname[i],g_ibilldeno[i]/100,billcount);
					}
				}
			}
		}
	}
	return tresult;
}
int CBNROperation::CBNR_GetStoredBanknote()
{
	int yuan_amount = 0;
	if(g_StoredNote!=0)
	{
		yuan_amount = g_StoredNote;
	}
	if(g_IsRealBanknote == false )
		yuan_amount = -1;
	xx1_log_debug(LOG_LEVEL_DEBUG,"GetStoredBanknote=[%d Yuan]",yuan_amount);
	return yuan_amount;
}

int CBNROperation::CBNR_ClearStoredBanknote()
{
	g_StoredNote = 0;
	g_IsRealBanknote =true;
	return 0;
}

T_BnrXfsResult CBNROperation::CBNR_GetStatus()
{
	T_BnrXfsResult result,ret;
	T_XfsCdrStatus bnrStatus;
	bnrStatus.positionStatusList.maxSize=MAX_NR_OF_POSITIONS;
	T_XfsCashUnit cashunit;
	cashunit.physicalCashUnitList.maxSize = 20;
	UINT16 ipos=0;
	int i=0;
	m_IsInletFulled = false;	//入钞口是否有纸币
	m_IsOutletFulled = false;  //退钞口是否有纸币
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	
	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_GetStatus(&bnrStatus);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	//解析数据
	if (result == BXR_NO_ERROR)
	{
		//入钞口
		g_BNRStatus.wInShutter = bnrStatus.positionStatusList.items[0].contentStatus;

		//退出口
		g_BNRStatus.wReturnShutter = bnrStatus.positionStatusList.items[1].contentStatus;

		//暂存状态
		ipos = (UINT16)bnrStatus.intermediateStackerStatus;
		if (ipos == XFS_S_CDR_IS_EMPTY)
		{
			ipos = 0;
		}
		else
		{
			ipos = 1;
		}
		g_BNRStatus.wStacker = ipos;

		m_IsInletFulled = bnrStatus.positionStatusList.items[0].contentStatus;
		m_IsOutletFulled = bnrStatus.positionStatusList.items[1].contentStatus;
		xx1_log_debug(LOG_LEVEL_DEBUG,"m_IsInletFulled=[%d],m_IsOutletFulled=[%d]\n",\
			m_IsInletFulled,m_IsOutletFulled);
	}
	return result;
}

//锁定或者解锁指定的箱子,参数1:箱子名; 参数2: true为锁定,false为解锁
T_BnrXfsResult CBNROperation::CBNR_LockCashBox(std::string vstrname, bool block)
{
	T_BnrXfsResult result = 0;
	T_XfsCashUnit cashUnit;
	memset(&cashUnit,0,sizeof(T_XfsCashUnit));
	cashUnit.logicalCashUnitList.maxSize= NBMAXLCU;
	cashUnit.physicalCashUnitList.maxSize=NBMAXPCU;
	std::string str;
	UINT32 i;

	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_QueryCashUnit(&cashUnit);
	pthread_mutex_unlock (&listenerEvent_mutex);
	
	if (result == BXR_NO_ERROR)
	{
		int n = 0;

		for(i=0; i<cashUnit.physicalCashUnitList.size; i++)
		{
			str = cashUnit.physicalCashUnitList.items[i].name;

			if (str == vstrname)
			{
				if (block)
				{
					cashUnit.physicalCashUnitList.items[i].lock = 1;
				} 
				else
				{
					cashUnit.physicalCashUnitList.items[i].lock = 0;
				}
				n++;
			}
		}

		if(n!=0)
		{
			pthread_mutex_lock (&listenerEvent_mutex);
			result = bnr_ConfigureCashUnit(cashUnit.transportCount,&cashUnit.logicalCashUnitList,&cashUnit.physicalCashUnitList);
			pthread_mutex_unlock (&listenerEvent_mutex);
		}
	}

	return result;
}
//获取纸币模块信息
T_BnrXfsResult CBNROperation::CBNR_GetMoudleInfo()
{
	//先获取固件版本,再获取序列号,组合
	T_FullVersion ver;
	BOOL bupdate;
	T_ModuleIdentification moduleid;
	T_ModuleId mainid = MAIN_MODULE_ID;	//0x0E0000;
	char version_id[64]={0,};
	char version_name[32]={0,};
	T_BnrXfsResult result,ret,judge;
	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_GetFirmwarePackageVersion(&ver, &bupdate);
	pthread_mutex_unlock (&listenerEvent_mutex);
	if (result == -10516 || result==-10521)
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}

	if (result == BXR_NO_ERROR)
	{
		snprintf(version_id,sizeof(version_id)-1,"%d.%d.%d",ver.major,ver.minor,ver.service);
	}
	
	pthread_mutex_lock (&listenerEvent_mutex);
	ret = module_GetIdentification(mainid, &moduleid);
	pthread_mutex_unlock (&listenerEvent_mutex);
	
	if (ret == -10516 || result==-10521)
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = ret;
	}
	if (ret == BXR_NO_ERROR)
	{
		snprintf(version_name,sizeof(version_name)-1,"%s",moduleid.Name);
	}
	printf("%s %s\n",version_name,version_id);
	if (result==BXR_NO_ERROR && ret==BXR_NO_ERROR)
	{
		judge = result;
	} 
	else if (result!=BXR_NO_ERROR && ret!=BXR_NO_ERROR)
	{
		judge = result;
	}
	else if (result!=BXR_NO_ERROR && ret==BXR_NO_ERROR)
	{
		judge = result;
	}
	else if (result==BXR_NO_ERROR && ret!=BXR_NO_ERROR)
	{
		judge = ret;
	}	
	
	return judge;

}

//获取各模块ID号
T_BnrXfsResult CBNROperation::CBNR_GetMoudles(T_ModuleIdList *moduleList)
{
	T_BnrXfsResult result;
	BYTE iseq=0;
	pthread_mutex_lock (&listenerEvent_mutex);
	result = bnr_GetModules(moduleList);
	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	
	pthread_mutex_unlock (&listenerEvent_mutex);
	int i=0,j=0;
	T_ModuleId moduleId = 0;
	T_XfsCashType cashType;
	T_ModuleIdentification ModuleIdentification;
	memset(&g_ModuleList, 0, sizeof(g_ModuleList));
	
	if(result == BXR_NO_ERROR)
	{
		memset(&cashType,0,sizeof(T_XfsCashType));
		memset(&ModuleIdentification,0,sizeof(T_ModuleIdentification));
		for (i=0; i<moduleList->size; i++)
		{
			moduleId = moduleList->modules[i].moduleId;
			 if ((moduleId & MODULE_CLASS_MASK) == MAIN_MODULE_CLASS)
			 {
			 	printf("MAIN_MODULE_ID=[%06x]\n",moduleId);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == LOADER_CLASS)
			 {
			 	printf("LOADER_ID=[%06x]\n",moduleId);
				g_ModuleList.iloboxexist = 1;
				g_ModuleList.dwloid = moduleList->modules[i].moduleId; 
				iseq = moduleList->modules[i].moduleId - LOADER_CLASS;
				sprintf(g_ModuleList.loname, ("LO%d"), iseq);
			 }
			 if ((moduleId & MODULE_CLASS_MASK) == BUNDLER_CLASS)
			 {
			 	printf("BUNDLER_ID=[%06x]\n",moduleId);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == CASHBOX_CLASS)
			 {
			 	printf("CASHBOX_ID=[%06x]\n",moduleId);
				g_ModuleList.dwcbid=moduleId;
			 }
			 if((moduleId & MODULE_CLASS_MASK) == SPINE_CLASS)
			 {
			 	printf("SPINE_ID=[%06x]\n",moduleId);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == BARCODE_READER_CLASS)
			 {
			 	printf("BARCODE_READER_ID=[%06x]\n",moduleId);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == RECYCLER_CLASS)
			 {
			 	printf("RECYCLER_ID=[%06x]\n",moduleId);
				
				iseq = moduleId - RECYCLER_CLASS;
				snprintf(g_ModuleList.reboxname[iseq-3],sizeof(g_ModuleList.reboxname[iseq-3])-1, ("RE%d"), iseq);
				g_ModuleList.ireboxexist[iseq-3] = 1;
				g_ModuleList.dwreid[iseq-3] = moduleId;
			 }
			 
			
			 pthread_mutex_lock (&listenerEvent_mutex);
			 module_GetCashType(moduleId,&cashType);
			 pthread_mutex_unlock (&listenerEvent_mutex);

			 print_msg_cashType(&cashType);
			 
			 pthread_mutex_lock (&listenerEvent_mutex);
			 module_GetIdentification(moduleId,&ModuleIdentification);
			  if((moduleId & MODULE_CLASS_MASK) == RECYCLER_CLASS && strlen(ModuleIdentification.Name)>=11)
			 {
			 	strncpy(g_ModuleList.RESerialNum[iseq-3],ModuleIdentification.Name+3,8);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == LOADER_CLASS && strlen(ModuleIdentification.Name)>=11)
			 {
			 	strncpy(g_ModuleList.LOSerialNum,ModuleIdentification.Name+3,8);
			 }
			 if((moduleId & MODULE_CLASS_MASK) == CASHBOX_CLASS && strlen(ModuleIdentification.Name)>=11)
			 {
			 	strncpy(g_ModuleList.CBSerialNum,ModuleIdentification.Name+3,8);
			 }
			 pthread_mutex_unlock (&listenerEvent_mutex);
			 print_msg_ModuleIdentification(&ModuleIdentification);
			
		}
	}
	return result;
}

//处理USB线被拔掉和重新插上
T_BnrXfsResult CBNROperation::CBNR_DoUSBOpen(T_BnrXfsResult iresult)
{
	std::string GetStr;
	UINT32 i = 0;
	T_BnrXfsResult result = BXR_NO_ERROR;

	//MEI API版本V1.10.0,在出现卡币故障后,USB通讯会中断,过十几秒钟后才可以再次连接上.
	//取出通道里卡的纸币,可以继续清币或者补币.
	if (iresult == -1)
	{
		int i = 0;
		while (1)
		{
			usleep(500000);
			i++;
			m_IsOpened = TRUE;
			result = CBNR_Close();
			if (i>6)
			{
				break;
			}
			if (result != BXR_NO_ERROR)
			{
				continue;
			}			
		}		

		i = 0;
		while (1)
		{
			sleep(1);
			result = CBNR_Open();
			i++;
			if (result == BXR_NO_ERROR)
			{
				break;
			} 
			else 
			{
				if (i>60)
				{
					break;
				}
				else
				{
					continue;
				}
			}			
		}
		if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED || abs(result)==BXR_USB_ERROR_OFFSET) //BXR_USB_NO_SUCH_DEVICE 绝对值, BXR_USB_DEVICE_REMOVED
		{
			result = -1;
		}
	
	}	

	return result;
}

//模块初始化复位 a1010
T_BnrXfsResult CBNROperation::CBNR_ResetInit(bool OnlyReset)
{
	T_BnrXfsResult tresult = BXR_NO_ERROR;
	T_XfsCapabilities capabilities;
	T_XfsCashUnit cashUnit;
	INT32 iret = 0;
	tresult = CBNR_DoUSBOpen(g_iDoOpen);

	if(tresult == -1)
	{
		return 1;
	}
	if(OnlyReset==true)
	{
		//仅仅机械复位
		tresult = CBNR_Reset();
		if (tresult >= BXR_NO_ERROR && tresult !=  BNR_OPERATION_TIMEOUT )
		{
			m_IsCashInStarted =false;
			CBNR_QueryCashUnit(&cashUnit);
			CBNR_GetStatus();
			return 0;
		}
		else if(tresult ==  BNR_OPERATION_TIMEOUT)
		{
			xx1_log_debug(LOG_LEVEL_DEBUG,"Reset fail  ,BNR_OPERATION_TIMEOUT");
		}
		else
		{
			xx1_log_debug(LOG_LEVEL_DEBUG,"Reset fail =[%d]",tresult);
		}
		return tresult;
	}
	
	tresult = CBNR_GetCapabilities(&capabilities);
	if (tresult == BXR_NO_ERROR)
	{
		if (capabilities.selfTestMode != STM_SLAVE)
		{
			capabilities.selfTestMode = STM_SLAVE;
			tresult = CBNR_SetCapabilities(&capabilities);
			if (tresult != BXR_NO_ERROR)
			{

			}
		}
	}	
	//设定循环箱低位值
	if (tresult == BXR_NO_ERROR)
	{
		tresult = CBNR_SetReCBPositionNum(g_ConfigInfo.ReBoxFulls, g_ConfigInfo.ReBoxHighs, g_ConfigInfo.ReBoxLows, g_ConfigInfo.ReBoxEmptys);
	}
	
	if (tresult == BXR_NO_ERROR)
	{
		//锁箱操作从补币移到此处
		//如果是锁箱设定: 先查询是否已锁. 补币前解锁,补币后锁上
		if (g_ConfigInfo.iloaderlock == 1) //需要锁箱
		{
			if (g_ModuleList.iloboxexist)
			{
				tresult = CBNR_LockCashBox(g_ModuleList.loname, true);
			}							
		}

		if (tresult == BXR_NO_ERROR)
		{
			tresult = CBNR_Reset();

			if (tresult != BXR_NO_ERROR)
			{

			}					
		}
		else
		{

		}
	}
	if (tresult == BXR_NO_ERROR)
	{
		m_IsCashInStarted = false;

		//执行成功时,queue需要删除保存的信息
		//g_clcashinfo.ClearQueue();

		//复位成功后查询一下票箱
		
		tresult=CBNR_QueryCashUnit(&cashUnit);

		//退钞后不取走,发过cancel命令和1024报文后,再取走纸币,模块没有状态事件上发,
		//此时wReturnShutter仍保持有钞状态,因此在复位后,须再查询一下状态,
		tresult=CBNR_GetStatus();

	}
	return tresult;
	
}
T_BnrXfsResult CBNROperation::CBNR_GetCapabilities(T_XfsCapabilities *capabilities)
{
	pthread_mutex_lock (&listenerEvent_mutex);
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));

	T_BnrXfsResult result = bnr_GetCapabilities(capabilities);

	if (abs(result) == BXR_USB_NO_SUCH_DEVICE || abs(result)==BXR_USB_DEVICE_REMOVED)
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	xx1_log_debug(LOG_LEVEL_DEBUG,"bnr_GetCapabilities==[%d]",result);
	return result;
}
	
//
T_BnrXfsResult CBNROperation::CBNR_SetCapabilities(T_XfsCapabilities *capabilities)
{
	memset(&g_BNRResult, 0, sizeof(g_BNRResult));
	pthread_mutex_lock (&listenerEvent_mutex);
	T_BnrXfsResult result = bnr_SetCapabilities(capabilities);

	if (result == -10516 || result==-10521)
	{
		g_iDoOpen = -1;
	}
	else
	{
		g_iDoOpen = result;
	}
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result;
}


//找零之后，缩回纸币
T_BnrXfsResult CBNROperation::CBNR_Backnotes()
{
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Backnotes ");
	T_BnrXfsResult result ; 
		
	result = CBNR_Cancel();
	if(result == BXR_NO_ERROR)
	{
		result = CBNR_Retract();
		xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_Backnotes  ret=[%d]",result);
	}		
	return result;		
}

//找零之后，喷出纸币
T_BnrXfsResult CBNROperation::CBNR_JetBanknotes()
{
	xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_JetBanknotes ");
	T_BnrXfsResult result ; 

	result = CBNR_Cancel();
	if(result == BXR_NO_ERROR)
	{
		result = CBNR_Eject();
		xx1_log_debug(LOG_LEVEL_DEBUG,"CBNR_JetBanknotes  ret=[%d]",result);
	}		
	return result;		
}

//补币箱补币到RE循环箱
T_BnrXfsResult CBNROperation::CBNR_LoadBanknotes()
{
	T_BnrXfsResult tresult=BXR_NO_ERROR;
	T_BnrXfsResult tworesult=BXR_NO_ERROR ;
	T_BnrXfsResult	result=BXR_NO_ERROR;
	XfsCapabilities capabilities;
	XfsCashUnit beforeunit,afterunit;
	memset(&g_LOAdd_Num,0,sizeof(g_LOAdd_Num));
	while (1)
	{
		tresult = CBNR_QueryCashUnit(&beforeunit);
		INT32 iret = abs(tresult);
		if (iret == XFS_E_BUSY)
		{
			sleep(1);
			continue;
		}
		else if (iret == BXR_NO_ERROR)
		{
			break;
		}
		else if (iret==1 ||iret==10516 || iret==10521)
		{
			xx1_log_debug(LOG_LEVEL_WARNING,"补币前异常,CBNR_QueryCashUnit beforeunit ACK_NOTOPENPORT");
			break;
		}
		else
		{
			sleep(1);
		}
	}
	tresult = CBNR_GetCapabilities(&capabilities);
	if (tresult == BXR_NO_ERROR)
	{
		if (capabilities.selfTestMode != STM_AUTO)
		{
				capabilities.selfTestMode = STM_AUTO;
				tresult = CBNR_SetCapabilities(&capabilities);
		}
	}
	result = CBNR_SetReCBPositionNum(g_ConfigInfo.ReBoxFulls,g_ConfigInfo.ReBoxHighs,g_ConfigInfo.ReBoxLows,g_ConfigInfo.ReBoxEmptys);
	result = CBNR_LockCashBox(g_ModuleList.loname,false);
	result = CBNR_Reset();

	//补币箱后查询
	
	while (1)
	{
		tworesult = CBNR_QueryCashUnit(&afterunit);
		INT32 iret = abs(tworesult);
		if (iret == XFS_E_BUSY)
		{
			sleep(1);
			continue;
		}
		else if (iret == BXR_NO_ERROR)
		{
			break;
		}
		else if (iret==1 ||iret==10516 || iret==10521)
		{
			xx1_log_debug(LOG_LEVEL_WARNING,"补币时异常,CBNR_QueryCashUnit afterunit ACK_NOTOPENPORT");
			break;
		}
		else
		{
			sleep(1);
		}
	}
	UINT32 billcount=0;
	int j=0;
	int i=0;
	if (tworesult == BXR_NO_ERROR)
	{
		//补币到回收箱的数量(面额不在RE 或者不识别面额)
		for(j=0;j<afterunit.logicalCashUnitList.size; j++)
		{
			if ( memcmp("CB", afterunit.logicalCashUnitList.items[j].physicalCashUnit->name, 2)==0)
			{
				if(XFS_C_CDR_LCU_BILL_CASSETTE)
				{
					billcount = afterunit.logicalCashUnitList.items[j].count - beforeunit.logicalCashUnitList.items[j].count;
					xx1_log_debug(LOG_LEVEL_MUST,"补币到%s,面额:%d元,版本:%04x,数量:%d",\
						afterunit.logicalCashUnitList.items[j].physicalCashUnit->name,\
						afterunit.logicalCashUnitList.items[j].cashType.value/100,\
						afterunit.logicalCashUnitList.items[j].cashType.variant,\
						billcount);
					switch (afterunit.logicalCashUnitList.items[j].cashType.value/100)
					{
						case 1:
							g_LOAdd_Num[0] += billcount;
							break;
						case 2:
							g_LOAdd_Num[1] += billcount;
							break;
						case 5:
							g_LOAdd_Num[2] += billcount;
							break;
						case 10:
							g_LOAdd_Num[3] += billcount;
							break;
						case 20:
							g_LOAdd_Num[4] += billcount;
							break;
						case 50:
							g_LOAdd_Num[5] += billcount;
							break;
						case 100:
							g_LOAdd_Num[6] += billcount;
							break;
						
					};
				}
				if(afterunit.logicalCashUnitList.items[j].cuType==XFS_C_CDR_LCU_REJECT_CASSETTE)
				{
					billcount = afterunit.logicalCashUnitList.items[j].count - beforeunit.logicalCashUnitList.items[j].count;
					xx1_log_debug(LOG_LEVEL_MUST,"不识别纸币数量:%d",billcount);
					g_LOAdd_Num[7] += billcount;
				}
			}
		}
		for (i=0;i<sizeof(g_ModuleList.ireboxexist)/sizeof(BYTE);i++)
		{
			billcount = 0;
			if(g_ModuleList.ireboxexist[i])
			{
				for(j=0;j<afterunit.logicalCashUnitList.size; j++)
				{
					if ( (memcmp(g_ModuleList.reboxname[i], afterunit.logicalCashUnitList.items[j].physicalCashUnit->name, 3)==0) &&
					(afterunit.logicalCashUnitList.items[j].cuType==XFS_C_CDR_LCU_BILL_CASSETTE)
					)
					{
						billcount = afterunit.logicalCashUnitList.items[j].count - beforeunit.logicalCashUnitList.items[j].count;
						xx1_log_debug(LOG_LEVEL_MUST,"补币到%s,面额:%d元,数量:%d",g_ModuleList.reboxname[i],g_ibilldeno[i]/100,billcount);
						switch (afterunit.logicalCashUnitList.items[j].cashType.value/100)
						{
							case 1:
								g_LOAdd_Num[0] += billcount;
								break;
							case 2:
								g_LOAdd_Num[1] += billcount;
								break;
							case 5:
								g_LOAdd_Num[2] += billcount;
								break;
							case 10:
								g_LOAdd_Num[3] += billcount;
								break;
							case 20:
								g_LOAdd_Num[4] += billcount;
								break;
							case 50:
								g_LOAdd_Num[5] += billcount;
								break;
							case 100:
								g_LOAdd_Num[6] += billcount;
								break;
						};
					}
				}
			}
		}
	}
	
	return result;
}
//获取交易状态
T_BnrXfsResult CBNROperation::CBNR_GetTransactionStatus(T_TransactionStatus *status)
{
	T_BnrXfsResult result;
	pthread_mutex_lock (&listenerEvent_mutex);
	result=bnr_GetTransactionStatus(status);
	xx1_log_debug(LOG_LEVEL_MUST,"currentTransaction=[%d](0:TT_NONE,1:TT_CASHIN,2:TT_DISPENSE)\nOPID=[%d],cashAtBezel=[%d]\n",\
		status->currentTransaction,status->currentOperation,status->cashAtBezel);
	pthread_mutex_unlock (&listenerEvent_mutex);
	return result; 
}


//=========================================================
void usage()
{
	printf("******************* Welcome To Using BNR *******************************\n");
	printf("* 0.Quit\t\t");
	printf("* 1.OpenDevice\n");
	printf("* 2.CashInStart\t\t");
	printf("* 3.CashIn\n");
	printf("* 4.CashInEnd\t\t");
	printf("* 5.CloseDevice\n");
	printf("* 6.Reset\t\t");
	printf("* 7.Cancel\n");
	printf("* 8.Eject\t\t");
	printf("* 9.Reject\n");
	printf("* 10.Reboot\t\t");
	printf("* 11.GetModules\n");
	printf("========================Merge Functions========================\n");
	printf("*31.Enable(开始接收纸币)\n");
	printf("*32.Disable(关闭接收纸币)\n");
	printf("*33.Encash(压箱)\n");
	printf("*34.Refund(退出纸币)\n");
	printf("*35.EmptytoRecycle(清空纸币到回收箱)\n");
	printf("*36.UpdateDenominations(更新接收币种面额)\n");
	printf("*37.GetStoredBanknote(查看暂存区纸币面额)\n");
	printf("*38.GetStatus\n");
	printf("*39.QueryCashUnit\n");
	printf("*40.SetReyclePositionNum\n");
	printf("*41.OddChange(找零)\n");
	printf("*42.ResetInit(复位初始化)\n");
	printf("*43.Retract()\n");
	printf("*44.Backnotes(缩回纸币)\n");
	printf("*45.JetBanknotes(喷出出口纸币)\n");
	printf("*46.SetCashUnit(设定钱箱信息)\n");
	printf("*47.PrintBNRStatus(打印状态信息)\n");
	printf("*48.LoadBanknotes(补币到循环箱)\n");
	printf("*49.GetTransaction(获取交易状态)\n");
	printf("*50.LockLOCashUint(锁LO箱)\n");
	printf("*51.Clear(清LO CB数据)\n");
	printf("*99.Change g_used\n");
	printf("************************************************************************\n");
}

/*
 *Return 1:digit
 *		 0:
 * */
 
int check_number(char* str)
{
	return (strspn(str, "0123456789")==strlen(str));
}
int new_test(int argc, char* argv[])
{
	CBNROperation bnr_demo=CBNROperation();
	g_used = FALSE;
	while(TRUE)
	{
		int quit_flag = 0;
		int number=0;
		char input_str[32]={0,};
		UINT32 reone=1;
		UINT32 retwo=1;
		UINT32 rethree=0;
		UINT32 refour=0;
		int yuan_amount[5]={5,10,0,0,5};
		int yuan_maxcount[5]={30,60,30,60,0};
		int uiclear[5]={1,1,1,1,1};
		int fulls[4]={30,60,30,60};
		int highs[4]={24,48,24,48};
		int lows[4] = {8,16,8,16};
		int emptys[4]= {0,0,0,0};
		T_TransactionStatus TransactionStatus;
		memset(&TransactionStatus,0,sizeof(T_TransactionStatus));
		
		usage();
		printf("Please input choice number:\n");
		scanf("%s",input_str);
		if(!check_number(input_str))
		{
			printf("Your input include nonnumeric!!!!\n");
			continue;
		}
		sscanf(input_str,"%d",&number);
		int ret = -1;
		//BOOL bcashenable[7]={TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}; //1元,2元,5元,10元,20元,50元,100元
		BOOL bcashenable[7]={FALSE,FALSE,TRUE,TRUE,TRUE,TRUE,FALSE}; //1元,2元,5元,10元,20元,50元,100元
		T_XfsCashUnit cashunit;
		switch (number)
		{
			case 0:
				quit_flag = 1;
				break;
			case 1:
				ret = bnr_demo.CBNR_Open();
				printf("CBNR_Open,result=[%d]\n",ret);
				break;
			case 2:
				ret = bnr_demo.CBNR_CashInStart();
				printf("CBNR_CashInStart,result=[%d]\n",ret);
				break;
			case 3:
				ret = bnr_demo.CBNR_CashIn();
				printf("CBNR_CashIn,result=[%d]\n",ret);
				break;
			case 4:
				ret = bnr_demo.CBNR_CashInEnd();
				printf("CBNR_CashEnd,result=[%d]\n",ret);
				break;
			case 5:
				ret = bnr_demo.CBNR_Close();
				printf("CBNR_Close,result=[%d]\n",ret);
				break;
			case 6:
				ret = bnr_demo.CBNR_Reset();
				if(ret >= 0)
				{
					printf("ret=[%d],CBNR_Reset Success\n",ret);
				}
				else
				{
					printf("CBNR_Reset  Failed ,result=[%d]\n",ret);
				}
				break;
			case 7:
				ret = bnr_demo.CBNR_Cancel();
				printf("CBNR_Cancel,result=[%d]\n",ret);
				break;
			case 8:
				ret = bnr_demo.CBNR_Eject();
				printf("CBNR_Eject,result=[%d]\n",ret);
				break;
			case 9:
				ret = bnr_demo.CBNR_Reject();
				printf("CBNR_Reject,result=[%d]\n",ret);
				break;
			case 10:
				ret = bnr_demo.CBNR_Reboot();
				printf("CBNR_Reboot,result=[%d]\n",ret);
				break;
			case 11:
				T_ModuleIdList ModuleIdList;
				ret = bnr_demo.CBNR_GetMoudles(&ModuleIdList);
				printf("CBNR_GetMoudles,result=[%d]\n",ret);
				break;
			case 31:
				ret = bnr_demo.CBNR_Enable();
				printf("CBNR_Enable,result=[%d]\n",ret);
				break;
			case 32:
				ret = bnr_demo.CBNR_Disable();
				printf("CBNR_Disable,result=[%d]\n",ret);
				break;
			case 33:
				ret = bnr_demo.CBNR_Encash();
				printf("CBNR_Encash,result=[%d]\n",ret);
				break;
			case 34:
				ret = bnr_demo.CBNR_Refund();
				printf("CBNR_Refund,result=[%d]\n",ret);
				break;
			case 35:
				ret = bnr_demo.CBNR_EmptytoRecycle(uiclear);
				printf("CBNR_EmptytoRecycle,result=[%d]\n",ret);
				break;
			case 36:
				ret = bnr_demo.CBNR_UpdateDenominations(bcashenable);
				printf("CBNR_UpdateDenominations,result=[%d]\n",ret);
				break;
			case 37:
				ret = bnr_demo.CBNR_GetStoredBanknote();
				printf("CBNR_GetStoredBanknote,amount=[%d]\n",ret);
				break;
			case 38:
				ret = bnr_demo.CBNR_GetStatus();
				printf("CBNR_GetStatus,result=[%d]\n",ret);
				break;
			case 39:
				ret = bnr_demo.CBNR_QueryCashUnit(&cashunit);
				printf("CBNR_QueryCashUnit,result=[%d]\n",ret);
				break;
			case 40:			
				ret = bnr_demo.CBNR_SetReCBPositionNum(g_ConfigInfo.ReBoxFulls, g_ConfigInfo.ReBoxHighs, g_ConfigInfo.ReBoxLows, g_ConfigInfo.ReBoxEmptys);
				printf("CBNR_SetReCBPositionNum,result=[%d]\n",ret);
				break;
			case 41:
				ret = bnr_demo.CBNR_OddChange(1,&reone,&retwo,&rethree,&refour);
				printf("CBNR_OddChange,result=[%d]\n",ret);
				break;
			case 42:
				ret = bnr_demo.CBNR_ResetInit(false);
				printf("CBNR_ResetInit,result=[%d]\n",ret);
				break;
			case 43:
				ret = bnr_demo.CBNR_Retract();
				printf("CBNR_Retract,result=[%d]\n",ret);
				break;
			case 44:
				ret = bnr_demo.CBNR_Backnotes();
				printf("CBNR_Backnotes,result=[%d]\n",ret);
				break;
			case 45:
				ret = bnr_demo.CBNR_JetBanknotes();
				printf("CBNR_JetBanknotes,result=[%d]\n",ret);
				break;
			case 46:
				
				ret = bnr_demo.CBNR_SetCashUnit(yuan_amount,yuan_maxcount);
				printf("CBNR_SetCashUnit,result=[%d]\n",ret);
				break;
			case 47:
				ret = bnr_demo.CBNR_GetMoudleInfo();
				printf("CBNR_GetMoudleInfo,result=[%d]\n",ret);
				ret= bnr_demo.print_BNRStatus(&g_BNRStatus);
				break;
			case 48:
				ret = bnr_demo.CBNR_LoadBanknotes();
				printf("CBNR_LoadBanknotes,result=[%d]\n",ret);
				break;
			case 49:
				ret = bnr_demo.CBNR_GetTransactionStatus(&TransactionStatus);
				printf("CBNR_GetTransactionStatus,result=[%d]\n",ret);
				break;
			case 50:
				
				ret = bnr_demo.CBNR_LockCashBox("LO1",g_used?true:false);
				printf("CBNR_LockCashBox: %d\n",ret);
				break;
			case 51:
				ret = bnr_demo.CBNR_ClearCashUnit("LO1");
				printf("CBNR_ClearCashUnit LO1: %d\n",ret);
				ret = bnr_demo.CBNR_ClearCashUnit("CB");
				printf("CBNR_ClearCashUnit CB: %d\n",ret);
				break;
			case 99:
				g_used = !g_used;
				printf("g_used=[%d]\n",g_used);
				break;
				
			default:
				break;
		}
		if(quit_flag == 1)
		{
			break;
		}

	}
}
/*
int main(int argc, char* argv[]) 
{
	
	new_test(argc,argv);
	
}*/
