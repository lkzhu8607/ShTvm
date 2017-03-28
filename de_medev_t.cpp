
//
#include "2.h"
#include "de_medev_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_tcpmsg_t.h"
#include "de_log_t.h"
#include "de_base_realmode.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_topscr_t.h"
#include "g06.h"



//
de_medev_t   *gp_medev;



//
de_medev_t::de_medev_t()
{
	m_devstatus = 3;
	m_legal_authority = 0;
	m_IsLegalLoginMaintenance = 0;
	m_outofservicestatus = 12;

	m_IsOpenDoorSellModule = 0;

	m_IsYunYingEnd = 0;

	m_IsEmergeModel = 0;

	m_IsRecv3014 = 0;
	m_IsSCNeedSysShutdownOrReboot = 0;
	m_IsChangeToStopSerice = 0;
}


//
de_medev_t::~de_medev_t()
{
}



//
void de_medev_t::OnRunTask( std::string t ) //用t来传送一个指针。需要delete. 
{
	a5041_t::ROWTYPE * p;

	SStrf::s2b( t, p );

	for( int i = 0; i < gp_db->Get5041EvtCapacity() ; i++ )
	{
		if( p->m_e_old.a[i] != p->m_e.a[i] ) //如果事件码有变化，说明发生了事件 
		{
			//send the 5041 event
			//
			gp_tcpmsg->Send1Evt5041( p->m_e_old.a[i] , p->m_e.a[i], i );

			a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); //用一个copy在工作，但要回填数据。 

			Ra5041.m_e_old.a[i] = Ra5041.m_e.a[i];

			Ra5041.m_e_flag.a[i] = 1;
		}

	}
	 
	goto L_TASKEND;
	
L_TASKEND:
	delete p;
	return;
}


//
void de_medev_t::tr_on_pre_thrd()
{
	//先发2次全0 清掉所有事件
	for( int i = 0 ; i < 2 ; i++ )
	{
		WThrd::tr_sleepu( 1 );
		
		//开机时上传evt 00,00， 清所有evt 
		gp_tcpmsg->Send1Evt5041( 1 , 0, 0 );
	}

	WThrd::tr_sleepu( 2.91 );
}


// 
int de_medev_t::tr_on_user_run()
{
	a5041_t::ROWTYPE &Ra5041(gp_db->GetTheRowa5041());

	do{
		break;

	}while(0);

	WThrd::tr_sleepu( 0.91 );

	gp_db->LasyRiseSaveFlag_a5041(Ra5041);

	return 1;
}


// 
void de_medev_t::MedevInit()
{
	this->tr_open();

}

bool de_medev_t::IsOnlyCoin()
{
	if( m_devstatus == 5 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool de_medev_t::IsOnlyBill()
{
	if( m_devstatus == 6 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

//#define E_CHG_0(eventnum)	do{ if( Ra5041.m_e.a[eventnum] != 0 )	biEChgFlag = 1; Ra5041.m_e.a[eventnum] = 0; } while(0)
//#define E_CHG_1(eventnum)	do{ if( Ra5041.m_e.a[eventnum] != 1 )	biEChgFlag = 1; Ra5041.m_e.a[eventnum] = 1; } while(0)
//#define S0_CHG_0(statusnum)	do{ if( Ra5041.m_s0.a[statusnum] != 0 ) biSChgFlag = 1; Ra5041.m_s0.a[statusnum] = 0; } while(0)
//#define S0_CHG_1(statusnum)	do{ if( Ra5041.m_s0.a[statusnum] != 1 ) biSChgFlag = 1; Ra5041.m_s0.a[statusnum] = 1; } while(0)
//#define S1_CHG_0(statusnum)	do{ if( Ra5041.m_s1.a[statusnum] != 0 ) biSChgFlag = 1; Ra5041.m_s1.a[statusnum] = 0; } while(0)
//#define S1_CHG_1(statusnum)	do{ if( Ra5041.m_s1.a[statusnum] != 1 ) biSChgFlag = 1; Ra5041.m_s1.a[statusnum] = 1; } while(0)
#define EVT_CHG(eventnum,evtvalue)	do{ if( Ra5041.m_e.a[eventnum]  != evtvalue  )  biEChgFlag = 1, Ra5041.m_e.a[eventnum] = evtvalue; } while(0)
#define S0_CHG(statenum,statevalue)	do{ if( Ra5041.m_s0.a[statenum] != statevalue ) biSChgFlag = 1, Ra5041.m_s0.a[statenum] = statevalue; } while(0)
#define S1_CHG(statenum,statevalue)	do{ if( Ra5041.m_s1.a[statenum] != statevalue ) biSChgFlag = 1, Ra5041.m_s1.a[statenum] = statevalue; } while(0)


#include "de_medev00_refresh5041_app_sub.xpp"


// 每模块做一遍：遍历5041各字段，每字段遍历各模块寄存器，刷新5041.模块状态与5041 的关系。 
// 这样方便新增模块
//
tbool de_medev_t::Refresh5041_dev( std::string strinput )
{
	char c = strinput[0];

	if( c == KIN_APP	/*||  
		c == KIN_SC 	*/	)
	{
		return 1;
	}

	//if( c == KIN_UPS )
	//{
	//	c = c;
	//}


	if( c == KIN_COIN	||  
		c == KIN_BILL || 
		c == KIN_EMTICKET || 
		c == KIN_READER1 || 
		c == KIN_BILLCHG  ||
		c == KIN_TOPSCR  ||
		c == KIN_PRINTER  ||
		c == KIN_UPS      ||
		c == KIN_SC
		)
	{ 
		//flow down
	}
	else
	{
		return 0;
	}

	tbool biEChgFlag = 0;
	tbool biSChgFlag = 0;

	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());

	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	b8703_t::ROWTYPE & Rb8703(gp_db->GetTheRowb8703());
	b8704_t::ROWTYPE & Rb8704(gp_db->GetTheRowb8704());
	b8705_t::ROWTYPE & Rb8705(gp_db->GetTheRowb8705());

	b8706_t::ROWTYPE & Rb8706(gp_db->GetTheRowb8706());
	b8707_t::ROWTYPE & Rb8707(gp_db->GetTheRowb8707());
	b8708_t::ROWTYPE & Rb8708(gp_db->GetTheRowb8708());



	//	屏蔽	
	//
#ifdef DE_GOOD_FLAG
	#include "de_medev21_GOOD_FLAG.xpp"
#endif



	if( Refresh5041_app_sub() )		//	所有总状态	
	{
		biEChgFlag = biSChgFlag = 1;
	}


	//if( c == KIN_COIN )
	#include "de_medev11_KIN_COIN.xpp"

	//if( c == KIN_BILL )
	#include "de_medev12_KIN_BILL.xpp"

	//if( c == KIN_EMTICKET )
	#include "de_medev13_KIN_EMTICKET.xpp"

	//if( c == KIN_READER1 )
	#include "de_medev14_KIN_READER1.xpp"

	//if( c == KIN_BILLCHG )
	//#include "de_medev15_KIN_BILLCHG.xpp"

	//if( c == KIN_TOPSCR )
	#include "de_medev16_KIN_TOPSCR.xpp"

	//if( c == KIN_PRINTER )
	#include "de_medev17_KIN_PRINTER.xpp"

	//if( c == KIN_UPS )
	#include "de_medev18_KIN_UPS.xpp"


	int iChangeModule = 0;
	//iChangeModule = CanChange();

	LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"now coin num="<< gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ );

	if( ( ( gp_db->m_b8702.GetRow(0).m_BillStopUseFlag == 1 ) ||
		( gp_db->m_b8702.GetRow(0).m_BigErr == 1 || gp_db->m_b8702.GetRow(0).m_ConnState == 0 ) ||
		( gp_bill->IsVaultFull() ) || 
	    ( ( gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ + 
		    gp_db->m_b8701.GetRow(0).m_A5MaoCycleChg  /*+ gp_db->m_b8701.GetRow(0).m_A5MaoSpecialChg */) < 
			gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) ) && 
		( ( gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag == 1 ) ||
	    ( gp_db->m_b8701.GetRow(0).m_BigErr == 1 || gp_db->m_b8701.GetRow(0).m_ConnState == 0 ) ||
		( gp_coin->IsVaultFull() ) || 
		( gp_db->m_a5041.GetRow(0).m_e.a[137] == 1 ) ) )
	{
		//纸币硬币都有问题，暂停服务
		// 清除 事件 136 135
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Coin And Bill Have Truble To Out Of Service");

		EVT_CHG(135,0);
		EVT_CHG(136,0);
		//S0_CHG(1,1);
		m_devstatus = 4;
	}
	//1.模式手动改为只收硬币模式   2.纸币接收装置出现故障   3.纸币循环找零斗和纸币回收箱满  
	//4.硬币补币箱，硬币缓存找零斗硬币存量小于最低报警参数值  5.无硬币找零(硬币找零箱总数小于最大可找数) -----> 只收硬币模式
	else if( ( gp_db->m_b8702.GetRow(0).m_BillStopUseFlag == 1 ) ||
		( gp_db->m_b8702.GetRow(0).m_BigErr == 1 || gp_db->m_b8702.GetRow(0).m_ConnState == 0 ) ||
		( gp_bill->IsVaultFull() ) || 
	    ( ( gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ + 
		    gp_db->m_b8701.GetRow(0).m_A5MaoCycleChg  /*+ gp_db->m_b8701.GetRow(0).m_A5MaoSpecialChg */) < 
			gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) )
	{
		// 136	只收硬币
		EVT_CHG(136,1);
		EVT_CHG(135,0);
	}

	//1.模式手动改为只收纸币模式   2.硬币接收装置出现故障（硬币箱不再位）   3.硬币回收箱和硬币暂存器满  -----> 只收纸币模式
	else if( ( gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag == 1 ) ||
	    ( gp_db->m_b8701.GetRow(0).m_BigErr == 1 || gp_db->m_b8701.GetRow(0).m_ConnState == 0 ) ||
		( gp_coin->IsVaultFull() ) || 
		( gp_db->m_a5041.GetRow(0).m_e.a[137] == 1 ) )    //137 硬币回收箱不在位 
	{
		// 135	只收纸币
		EVT_CHG(135,1);
		EVT_CHG(136,0);
	}
	else
	{
		// 清除 事件 136 135
		EVT_CHG(135,0);
		EVT_CHG(136,0);

		m_devstatus = 3;
	}

	

	//******发送事件码： 

	if( biEChgFlag || biSChgFlag )
	{
		a5041_t::ROWTYPE * pR5041 = new a5041_t::ROWTYPE;

		*pR5041 = Ra5041;
		this->PostTask( SStrf::b2s(pR5041) );
	}


	return 1;
}


		
//
void de_medev_t::EvtInitBegin()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	// 4	机器未初始化	√	√	√	√	√	5
	Ra5041.m_e.a[4] = 1;
	Ra5041.m_e_old.a[4] = !Ra5041.m_e.a[4];
	Ra5041.m_e_flag.a[4] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[4] , p->m_e.a[4], 4 );
	Ra5041.m_e_old.a[4] = Ra5041.m_e.a[4];

	
	//开机	 71	开		√	√	√	√	0
	Ra5041.m_e.a[71] = 0;
	Ra5041.m_e_old.a[71] = !Ra5041.m_e.a[71];
	Ra5041.m_e_flag.a[71] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[71] , p->m_e.a[71], 71 );
	Ra5041.m_e_old.a[71] = Ra5041.m_e.a[71];

	gp_frontinput->input_KIN_APP();
}


//
void de_medev_t::EvtInitEnd()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	// 4	机器未初始化	√	√	√	√	√	5
	// 初始化结束，如果参数全则E4=0
	if(1)
	{
		if( this->IsEODComplete() )
			Ra5041.m_e.a[4] = 0;
		else
			Ra5041.m_e.a[4] = 1;

		Ra5041.m_e_old.a[4] = !Ra5041.m_e.a[4];
		Ra5041.m_e_flag.a[4] = 1;
		gp_tcpmsg->Send1Evt5041( p->m_e_old.a[4] , p->m_e.a[4], 4 );
		Ra5041.m_e_old.a[4] = Ra5041.m_e.a[4];
	}

	//开机	 71	开		√	√	√	√	0
	Ra5041.m_e.a[71] = 1;
	Ra5041.m_e_old.a[71] = !Ra5041.m_e.a[71];
	Ra5041.m_e_flag.a[71] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[71] , p->m_e.a[71], 71 );
	Ra5041.m_e_old.a[71] = Ra5041.m_e.a[71];

	gp_frontinput->input_KIN_APP();
}


//
void de_medev_t::GetEvtStr( std::string & strOut )
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	strOut = " "; // 查找时数字前后加空格即可找 

	for( int i = 0; i < gp_db->Get5041EvtCapacity() ; i++ )
	{
		if( p->m_e.a[i] ) 
		{
			strOut += SStrf::sltoa( i );
			strOut += " ";
		}
	}
}


//
std::string de_medev_t::GetEvtStr()
{
	std::string a;
	GetEvtStr(a);
	return a;
}



//return value:
// -1 : 普通暂停服务
// 0 : 故障暂停服务
// 1 : normal
// 
tbool de_medev_t::IntegratedStateGood()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());
	//暂停服务 条件：   1.供票口卡票 2.传输通道卡票 3. 票箱空 4. 硬币处理单元不再位 5.单程票读写器通讯故障 
	//6.控制板1通讯故障 7.维护门开 8.接收到紧急模式
	std::string strshow = "      暂停服务      "
			              "   Out Of Service  ";

	
	// m_e.a[4]		参数未初始化
	if( Ra5041.m_e.a[4] == 1 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[4] = " );
		this->m_outofservicestatus = 13;
		m_devstatus = 4;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// s0.a[0]		0	开(1)/关(0)
	if( Ra5041.m_s0.a[0] == 0 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s0.a[0] = " );
		m_devstatus = 7;
		gp_topscr->DispStr( strshow );
		return -1;
	}


	if( Ra5041.m_e.a[62] == 1 )     //62 紧急模式
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[62] = ");
		m_devstatus = 7;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// s0.a[1]		1	停止服务(1)/无故障(0)
	if( Ra5041.m_s0.a[1] == 1 )
	{
		 strshow = "      关闭服务      "
			       "    Stop Service   ";

		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s0.a[1] = " );
		m_devstatus = 9;
		gp_topscr->DispStr( strshow );

		return -1;
	}
	if( 0 == gp_medev->m_IsOpenDoorSellModule )
	{
		// s1.a[0]		门开(1)  //维护门到位信号
		if( Ra5041.m_s1.a[0] == 1 || m_IsLegalLoginMaintenance == 1 )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s1.a[0] = " );

			if( 1 == this->m_IsLegalLoginMaintenance )
			{
				//进入维护
				gp_db->m_a5041.GetRow(0).m_e.a[59] = 1;   //TVM维护面板登录的事件代码（59）

				LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"m_IsLegalLoginMaintenance =1 " );
				m_devstatus = 7;
				gp_topscr->DispStr( strshow );
				return -1;
				
			}
			else
			{
				//只是门开
				gp_db->m_a5041.GetRow(0).m_e.a[59] = 0;
				this->m_outofservicestatus = 12;
				m_devstatus = 4;
				gp_topscr->DispStr( strshow );
				return 0;
			}
		}
		else
		{
			gp_db->m_a5041.GetRow(0).m_e.a[59] = 0;   //清除掉不开门进维护的登录标志，
		}

		// s1.a[1]		门被开锁(1)
		if( Ra5041.m_s1.a[1] == 1 )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s1.a[1] = ");
			this->m_outofservicestatus = 12;
			m_devstatus = 4;
			gp_topscr->DispStr( strshow );
			return 0;
		}
	}

	// 130 发卡模块坏
	if( Ra5041.m_e.a[130] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[130]");
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 11 供票口卡票 
	if( Ra5041.m_e.a[11] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[11] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 12 传输通道卡票 
	if( Ra5041.m_e.a[12] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[12] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//113 票箱空时，暂停服务 //显示票卡少
	if( Ra5041.m_e.a[113] && 
	    Ra5041.m_e.a[115] 	&& 
		SStrf::readbit( gp_db->m_b8703.GetRow(0).m_SensorStatus.a[0], 4 ) == 0 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041 = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 11;
		gp_topscr->DispStr("      暂停服务");

		return 0;
	}
	
	//129 硬币处理单元通信故障
	if(Ra5041.m_e.a[129])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[129] " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//303 硬币处理单元不再位
	if(Ra5041.m_e.a[303])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[303] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 179 少找零/多找零
	if(Ra5041.m_e.a[179])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[179] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 180 票少出/票多出
	if(Ra5041.m_e.a[180])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[180] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 120 TVM读卡器1故障 
	if( Ra5041.m_e.a[120] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[120] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 116 废票箱满 
	if( Ra5041.m_e.a[116] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[116] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}


	//以下为正常情况下的降级模式
	if( Ra5041.m_e.a[135] )
	{
		strshow = "      只收纸币      "
			      "      Note Only    ";
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[135] = " );
		m_devstatus = 6;
		gp_topscr->DispStr( strshow );
		if(1)
		{
			//清除掉无纸币找零状态
			//MYAUTOLOCK( gp_bill->m_DevLck );
			//gp_bill->m_iIsNotBillChange = 0;
		}
		return 1;
	}

	if( Ra5041.m_e.a[136] )
	{
		strshow =  "      只收硬币      "
			       "      Coin Only    ";
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[136] = " );
		m_devstatus = 5;
		gp_topscr->DispStr( strshow );
		if(1)
		{
			//清除掉无纸币找零状态
			MYAUTOLOCK( gp_bill->m_DevLck );
			gp_bill->m_iIsNotBillChange = 0;
		}
		return 1;
	}

	//在纸币硬币同时降级后，则会暂停服务
	if( 4 == m_devstatus )
	{
		
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"m_devstatus = "<< 4 );
		this->m_outofservicestatus = 12;
		m_devstatus = 4;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//则是正常售票
	if( 1 )
	{
		strshow = "      正常售票      "
			      "     In Service    " ;

		m_devstatus = 3;
		gp_topscr->DispStr( strshow );

		// 1.计算出不能找零( 纸币可找张数 < 最大可找张数 )  2.参数设置不找零  -> 无纸币找零   (只在正常售票模式才检测是否无纸币找零)
		int iRMB500 ,iRMB1000 ,iRMB2000 ,iRMB5000;
		iRMB500 = iRMB1000 = iRMB2000 = iRMB5000 = 0;
		
		gp_bill->dBill_QueryCashUint();
		for(int i=0;i<4;i++)
		{
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 500 )  iRMB500  += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 1000 ) iRMB1000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 2000 ) iRMB2000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 5000 ) iRMB5000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
		}

		if ( ( 0 == SStrf::readbit( gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0], 0 ) ) || 
			 ( ( iRMB500 + iRMB1000 + iRMB2000 + iRMB5000 )<gp_db->m_a3003.GetRow(0).m_BillChgMaxNum ) 
			)  
		{
			// 76	无纸币找零
			gp_db->m_a5041.GetRow(0).m_e.a[76] = 1;
			//EVT_CHG(76,1);
			if(1)
			{
				MYAUTOLOCK( gp_bill->m_DevLck );
				gp_bill->m_iIsNotBillChange = 1;
			}
		}
		else
		{
			//EVT_CHG(76,0);
			gp_db->m_a5041.GetRow(0).m_e.a[76] = 0;
			if(1)
			{
				MYAUTOLOCK( gp_bill->m_DevLck );
				gp_bill->m_iIsNotBillChange = 0;
			}
		}

	}
	
	return 1;
}



//
template < class T >
static tbool ChkEod_2( T & eodtbl )
{
	MYAUTOLOCK( eodtbl.m_ut_tbl_lck );
	typename T::RPSTYPE rps1, rps2;
	eodtbl.SelEc_biDelFlag( 0, rps1 );
	eodtbl.SelEc_biIsAffect( 1, rps2 );
	eodtbl.RpsAnd( rps1, rps2 );
	if( eodtbl.GetRowCount( rps1 ) == 0 )
	{
		std::string strTblName = eodtbl.ut_GetItemStr(-1,"strTblName");
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "缺少参数。表名是：" << strTblName );
		return 0;
	}

	return 1;
}


//
tbool de_medev_t::IsEODComplete()
{
	if( !ChkEod_2( gp_db->m_a2000 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3002 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3003 ) )
		return 0;
	 
	if( !ChkEod_2( gp_db->m_a3006 ) )
		return 0;
	
	if( !ChkEod_2( gp_db->m_a3007 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3009 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3011 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3083 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3084 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3086 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4001 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4002 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4003 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4004 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4006 ) )
		return 0;


	return 1;
}




