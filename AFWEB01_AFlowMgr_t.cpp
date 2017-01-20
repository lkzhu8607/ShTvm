
#include "2.h"
#include "AFWEB01_AFlowMgr_t.h"


AFWEB_NAMESPACE_BEGIN


// 
AFlowMgr_t::AFlowMgr_t()
{
}



// 
AFlowMgr_t::~AFlowMgr_t()
{
	tr_destruct();
}



// 
tbool AFlowMgr_t::InitAFlow()
{
	if( m_Lsn.Listen(9008) ) 
	{
		this->tr_openx();
		return 1;
	}
	
	return 0;
}


// 
tbool AFlowMgr_t::OnMgrPrepare( AFlowEle_t & t ) 
{
	if( !t.m_tSvr.Conn( m_Lsn ) )
	{
		return 0;
	}

	t.m_paff = &m_aff;

	return 1;
}



AFWEB_NAMESPACE_END





void test_AFlow()
{
	AFWEB01::AFlowMgr_t *p;
	p = new AFWEB01::AFlowMgr_t;
	p->InitAFlow();
 
}


