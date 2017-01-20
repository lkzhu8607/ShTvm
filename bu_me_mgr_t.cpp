
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
	tr_destruct();
}



// 
wl::tbool bu_me_mgr_t::Init()
{
	if( m_Lsn.Listen( gp_conf->Get_tvm_port(), NULL ) ) 
	{
		//gp_log[LOGAPP].LogPrintf( 999, "%s|listen %s ok", LOGPOSI, gp_conf->Get_tvm_port().c_str() );
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "|listen " << gp_conf->Get_tvm_port() << " ok" );
		this->tr_openx();
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
	if( !t.m_tSvr.Conn( m_Lsn ) )
	{
		return 0;
	}

	return 1;
}




