
#include "bu_comeag_mgr_t.h"
#include "de_log_t.h"



// 
bu_comeag_mgr_t::bu_comeag_mgr_t()
{
}



// 
bu_comeag_mgr_t::~bu_comeag_mgr_t()
{
	tr_destruct();
}



// 
tbool bu_comeag_mgr_t::OnMgrPrepare( bu_comeag_mgr_t::ThrEle_t & t ) 
{
	if( !t.m_tSvr.Conn( m_tLsn ) )
		return 0;
	
	LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "RemoteIP=" << t.m_tSvr.GetRemoteIPAddress() );

	return 1;
}



// 
tbool bu_comeag_mgr_t::MyInit() 
{
	if( m_tLsn.Listen( 7007 ) )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "listen 7007 ok." );
		this->tr_openx();
		return 1;
	}
	else
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "listen 7007 fail." );
		return 0;
	}
}




