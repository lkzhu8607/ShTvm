
#include "2.h"
#include "bu_frontman_mgr_t.h"
#include "d_config_t.h"
#include "de_log_t.h"



//
bu_frontman_mgr_t  *gp_frontman_mgr;



// 
bu_frontman_mgr_t::bu_frontman_mgr_t()
{
	this->m_FailWaitTimesec = 2;
	this->m_biIsMultiEleType = 0;

	//m_pcg = &m_cg01;
	//m_pcg = &m_cg04;
	m_pcg = &m_cg05;
}



// 
bu_frontman_mgr_t::~bu_frontman_mgr_t()
{
	tr_destruct();
}



// 
wl::tbool bu_frontman_mgr_t::frontmanInit()
{
	this->tr_open();
	return 1;
}


// 
tbool bu_frontman_mgr_t::OnMgrPrepare( bu_frontman_mgr_t::ThrEle_t & t ) 
{
		//return 0;

	return 1;
}




