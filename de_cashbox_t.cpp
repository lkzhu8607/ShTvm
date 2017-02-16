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
#include "bu_asynwork_t.h"
#include "de_coin_t.h"



de_bill_cashbox_t *g_bill_cashbox;

de_bill_cashbox_t::de_bill_cashbox_t()
{
	m_already_printflag=0;
}

//
de_bill_cashbox_t::~de_bill_cashbox_t()
{
}

void de_bill_cashbox_t::OnRunTask( std::string t ) 
{
		goto L_TASKEND;
	
L_TASKEND:
 
	return;
}


// 

int de_bill_cashbox_t::tr_on_user_run()
{
	b8701_t::ROWTYPE &Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE &R8702(gp_db->GetTheRowb8702());

	// 未登陆，但打开纸币模块物理锁 则报警.   其他线程处登陆后会关闭报警
    if(gp_bill->m_safeunlock==1 && gp_medev->m_IsLegalLoginMaintenance==0)
    {
    	gp_coin->dCoinOpenAlert();
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"illegal Login Maintenance,but safedoor is unlock.....");
    }

	//有结算或者维护权限 关闭报警
	if((gp_medev->m_legal_authority==1 ||gp_medev->m_legal_authority==2)&& m_already_alarmflag==1 )
	{
		gp_coin->dCoinCloseAlert();//关闭报警
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"close alarm 1");
		m_already_alarmflag=0;
	}
	if(gp_bill->m_install_boxflag==1 && gp_bill->m_uninstall_boxflag==1 && gp_bill->m_safeunlock==0 
		&& gp_bill->m_resetok==1)
	{  //不是维护，都要清除数据
		if(m_needclear==1)
		{
			
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI <<"dBill_ClearLoaderRecovery,m_legal_authority="<<gp_medev->m_legal_authority);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"1 yuan,num="<<R8702.m_Pieces.a[1]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"2 yuan,num="<<R8702.m_Pieces.a[2]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"5 yuan,num="<<R8702.m_Pieces.a[5]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"10 yuan,num="<<R8702.m_Pieces.a[10]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"20 yuan,num="<<R8702.m_Pieces.a[20]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"50 yuan,num="<<R8702.m_Pieces.a[50]);
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"100 yuan,num="<<R8702.m_Pieces.a[100]);
			gp_bill->dBill_ClearLoaderRecovery();   //清除数据  
			m_needclear=0;
		}
		if(m_already_alarmflag==1)
		{
			gp_coin->dCoinCloseAlert();//关闭报警
			LOGSTREAM( gp_log[LOGSOP], LOGPOSI<<"close alarm 2");
			m_already_alarmflag=0;
		}
		gp_bill->m_install_boxflag=0;
		gp_bill->m_uninstall_boxflag=0;
	}
	
	//读取门是否打开信息
	//while(SStrf::readbit( Rb8701.m_SensorStatus.a[1], 0 ) == 0 )
	//{
	//	WThrd::tr_sleep( 1 );
	//}
	//while(Rb8701.m_SensorStatus.a[1]==0)
	//	WThrd::tr_sleep( 1 );

    // index 4:回收箱   5:补币箱
	if(R8702.m_boxExist.a[4]==1)
	{
		m_already_printflag=0;
		WThrd::tr_sleep(0.5);
		return 1;
	}
	int check_count=1;
	while(1)
	{	
		if(check_count>=3)  //比较三次连续
		{
			break;
		}
		if(R8702.m_boxExist.a[4]==0)
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

	if(m_already_printflag ==1)//已经打印一次
	{
		return 1;
	}

	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]

	char ModuleSerialNums[6][10]={'\0',};
	char tmp_str[128]={0,};
	char info_str[1024]={'\0',};
	int total_yuan=0;
	
	BYTE t_line = 0x0F; 
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);	
	int lineNum = (t_line * 10);	
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;	
	lineNum += t_line;
		
	gp_bill->dBill_GetSerialNums(ModuleSerialNums);

	snprintf(info_str,sizeof(info_str)-1,	"\t上海地铁TVM取纸币回收箱记录单\n\
车站               %s站\n\
线路               轨道交通%d号线\n\
设备号             v111\n\n\
钱箱ID             %s\n\
操作员ID           %d\n\
操作时间           %s\n\n",
	gp_db->GetMyStaName().c_str(),lineNum,ModuleSerialNums[5],\
11,SDte::GetNow().ReadString().c_str());
	
	
	do
	{
		//维护不清除数据不上报
		//结算取走纸币箱 清除统计 上报数据 
		gp_bill->dBill_QueryCashUint();
		int i=0;
		for (i=0;i<111;i++)
		{
			if(R8702.m_Pieces.a[i]>0)
			{
				total_yuan +=i*R8702.m_Pieces.a[i];
			}
			switch (i)
			{
				case 5:
				{
					snprintf(tmp_str,sizeof(tmp_str)-1,"%d元纸币张数        %d张\n",i,R8702.m_Pieces.a[i]);
					strcat(info_str,tmp_str);
					break;
				}
				case 10:
				case 20:
				case 50:
				{
					snprintf(tmp_str,sizeof(tmp_str)-1,"%d元纸币张数       %d张\n",i,R8702.m_Pieces.a[i]);
					strcat(info_str,tmp_str);
					break;
				}
				case 100:
				{
					snprintf(tmp_str,sizeof(tmp_str)-1,"%d元纸币张数      %d张\n",i,R8702.m_Pieces.a[i]);
					strcat(info_str,tmp_str);
					break;
				}
			}
		}
		                                  
		snprintf(tmp_str,sizeof(tmp_str)-1,"纸币回收箱内金额    %d元\n\n",total_yuan);	
		strcat(info_str,tmp_str);
		
	}while(0);
	
	if(gp_medev->m_legal_authority==0)  
	{
		strcat(info_str,"非法取走纸币回收箱");
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "illegal Take Bill Box,Open Alarm" );
		//bu_asynwork_t::DoAlarmnSec(5);
		gp_coin->dCoinOpenAlert();
		m_already_alarmflag=1;
		m_needclear=1;
	}
	
	if(gp_medev->m_legal_authority==2)
	{
		m_needclear=1;
		; //上报数据
	}
	
	std::string str(info_str);
	gp_printer->PrintStrAsync( str );
	m_already_printflag = 1;
	return 1;
	
}

void de_bill_cashbox_t::bill_cashbox_init()
{
	this->tr_open();
}


