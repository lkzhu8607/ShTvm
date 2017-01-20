
#ifndef K1__AFlowMgr_t_H
#define K1__AFlowMgr_t_H


#include "2.h"
#include "AFWEB01_AFlowEle_t.h"
#include "AFWEB01_AFlowFolder_t.h"


AFWEB_NAMESPACE_BEGIN

//
class AFlowMgr_t : public WThrdMgr< AFlowEle_t, WThrd >
{
public:
	WTcpListener  m_Lsn;
	AFlowFolder_t  m_aff;

public:
	AFlowMgr_t();
	virtual ~AFlowMgr_t();

public:
	tbool InitAFlow();
	virtual tbool OnMgrPrepare( AFlowEle_t & t ) ;
	
};


AFWEB_NAMESPACE_END






#endif



