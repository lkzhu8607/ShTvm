#include "2.h"
#include "de_cashbox_t.h"
#include "de_bill_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_log_t.h"
#include "de_medev_t.h"
#include "de_printer_t.h"
#include "bu_backman_mgr_t.h"
#include "de_coin_t.h"
#include "de_coinbox_t.h"
#include "CoinCommand.h"
#include "bu_asynwork_t.h"


de_coinbox_t *gp_coinbox;

de_coinbox_t::de_coinbox_t()
{
	m_already_printflag=0;
	m_coinbox_ok_flag = 0;
}

//
de_coinbox_t::~de_coinbox_t()
{
}

void de_coinbox_t::OnRunTask( std::string t ) 
{
		goto L_TASKEND;
	
L_TASKEND:
 
	return;
}


// 
static int alertFlag = 0;

int de_coinbox_t::tr_on_user_run()
{
	b8701_t::ROWTYPE &Rb8701(gp_db->GetTheRowb8701());
	

	CCoin cCoin;
	BYTE Data [7] = {0,0,0,0,0,0,0};
	unsigned long coinBoxid;
	int count;
	if(m_coinbox_ok_flag == 0)
	{
		
		cCoin.Coin_Box_ReadID(Data, coinBoxid, count);
		m_coinbox_ok_flag = 1;
	}
		
	//读取门是否打开信息
	/*while(SStrf::readbit( Rb8701.m_SensorStatus.a[1], 0 ) == 0 )
	{
		WThrd::tr_sleep( 1 );
	}*/
	
    // 
	if(SStrf::readbit( Rb8701.m_SensorStatus.a[2], 5) == 0 )
	{
		if(1 == m_already_printflag)
		{
			bu_asynwork_t::SendReg6000ForEvent(0x08);
		}
		m_already_printflag=0;
		//WThrd::tr_sleep(0.5);
		if(alertFlag == 1){
			gp_coin->dCoinCloseAlert();
			alertFlag = 0;
		}
		return 1;
	}
	int check_count=1;
	while(1)
	{	
		if(check_count>=3)  //比较三次连续
		{
			break;
		}
		if(SStrf::readbit( Rb8701.m_SensorStatus.a[2], 5) == 1 )
		{
			check_count++;
			WThrd::tr_sleep(0.1);
		}
		else
		{
			WThrd::tr_sleep(0.5);	
			return 1;
		}	
	}

	//b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]

	char tmp_str[128]={0,};
	char info_str[1024]={0,};
	
	BYTE t_line = 0x0F; 
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);	
	int lineNum = (t_line * 10);	
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;	
	lineNum += t_line;
		
	//gp_bill->dBill_GetSerialNums(ModuleSerialNums);

		sprintf(info_str,	"\t上海地铁TVM取硬币回收箱记录单\n\
车站               %s站\n\
线路               轨道交通%d号线\n\
设备号             v001\n\n\
钱箱ID             %u\n\
操作时间           %s\n\n",	\
		gp_db->GetMyStaName().c_str(),lineNum,coinBoxid,SDte::GetNow().ReadString().c_str());

	if(gp_medev->m_legal_authority==0)
	{
		strcat(info_str,"非法取走硬币回收箱\n");
		m_coinbox_ok_flag = 0;
		//LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "illegal Take Coin Box：" );
		//bu_asynwork_t::DoAlarmnSec(5);
		if (!alertFlag){
			gp_coin->dCoinOpenAlert();
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "illegal Take Coin Box：" );
			alertFlag = 1;
		}
	}
	else if(gp_medev->m_legal_authority==1 || gp_medev->m_legal_authority==2)
	{
		//维护不清除数据不上报
		//结算取走纸币箱 清除统计 上报数据 
		sprintf(tmp_str, "硬币回收箱内5角    %d个\n",Rb8701.m_A5MaoStoreBox);	
		strcat(info_str,tmp_str);
		sprintf(tmp_str, "硬币回收箱内1元    %d个\n",Rb8701.m_A1YuanStoreBox);	
		strcat(info_str,tmp_str);		
		sprintf(tmp_str, "硬币回收箱总金额   %.2f元\n",(((float)Rb8701.m_A5MaoStoreBox)/2 + Rb8701.m_A1YuanStoreBox));	
		strcat(info_str,tmp_str);
		m_coinbox_ok_flag = 0;
		if(alertFlag == 1){
			gp_coin->dCoinCloseAlert();
			alertFlag = 0;
		}
	}
	if(gp_medev->m_legal_authority==2)
	{
		Rb8701.m_A1YuanStoreBox = 0;
		Rb8701.m_A5MaoStoreBox = 0;
		; //上报数据
	}
	if(m_already_printflag ==1)//已经打印一次
	{
		return 1;
	}
	std::string str(info_str);
	gp_printer->PrintStrAsync( str );
	m_already_printflag = 1;

	//上传6000
	bu_asynwork_t::SendReg6000ForEvent(0x07);

	return 1;
}

void de_coinbox_t::coinbox_init()
{
	this->tr_open();
}

