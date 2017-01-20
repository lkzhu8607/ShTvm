
#include "2.h"
#include "bu_backman_mgr_t.h"
#include "d_config_t.h"
#include "de_log_t.h"


//
bu_backman_mgr_t  *gp_backman_mgr;



// 
bu_backman_mgr_t::bu_backman_mgr_t()
{
	this->m_FailWaitTimesec = 2;
	this->m_biIsMultiEleType = 0;
}



// 
bu_backman_mgr_t::~bu_backman_mgr_t()
{
	tr_destruct();
}



// 
wl::tbool bu_backman_mgr_t::backmanInit()
{
	this->tr_open();
	return 1;
}


// 
tbool bu_backman_mgr_t::OnMgrPrepare( bu_backman_mgr_t::ThrEle_t & t ) 
{
		//return 0;

	return 1;
}




