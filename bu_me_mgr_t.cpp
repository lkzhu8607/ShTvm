
#include "2.h"
#include "bu_me_mgr_t.h"
#include "d_config_t.h"
#include "de_log_t.h"



// 
bu_me_mgr_t::bu_me_mgr_t()
{
}



// 
bu_me_mgr_t::~bu_me_mgr_t()
{
		// stop  
	m_Lsn.StopListen();

	wl::WTcpCellc cc;
	wl::tbool rc = 1;
	int i;

	for( i = 0; i < 2; i++ )
	{
		if( rc && cc.Conn( "127.0.0.1", gp_conf->Get_tvm_port() ) ) 
		{
			cc.DisConn();
			rc = 1;
		}
		else
		{
			rc = 0;
		}
	}

	wl::WThrd::tr_sleep(4);
	//tr_destruct();
}



// 
wl::tbool bu_me_mgr_t::Init()
{
	if( m_Lsn.Listen( gp_conf->Get_tvm_port(), NULL ) ) 
	{
		//gp_log[LOGAPP].LogPrintf( 999, "%s|listen %s ok", LOGPOSI, gp_conf->Get_tvm_port().c_str() );
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "|listen " << gp_conf->Get_tvm_port() << " ok" );
		this->tr_open();
		return 1;
	}
	else
	{
		//gp_log[LOGAPP].LogPrintf( 999, "%s|listen %s fail", LOGPOSI, gp_conf->Get_tvm_port().c_str() );
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "|listen " << gp_conf->Get_tvm_port() << " fail" );
		return 0;
	}
}


// 
tbool bu_me_mgr_t::OnMgrPrepare( bu_me_mgr_t::ThrEle_t & t ) 
{
	wl::WThrd::tr_sleep(1);
	//if( gp_conf->IsJT_SC() )  
	//{
	//	
	//}
	//if( gp_conf->IsHT_SC() )  
	//{
	//	wl::WThrd::tr_sleepu(0.1);
	//}

	if( !t.m_tSvr.Conn( m_Lsn ) )
	{
		return 0;
	}

	printf( "  %s  ", t.m_tSvr.GetRemoteIPAddress().c_str() );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|m_tSvr " << t.m_tSvr.GetRemoteIPAddress().c_str() );

	return 1;
}




