
#ifndef K1__bu_comeag_mgr_t_H
#define K1__bu_comeag_mgr_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"
#include "bu_comeag_ele_t.h"


// 模拟串口，目前不用了	

//
class bu_comeag_mgr_t : public WThrdMgr< bu_comeag_ele_t, bu_hot_thrd_t >
{
public:
	WTcpListener  m_tLsn;

public:
	bu_comeag_mgr_t();
	virtual ~bu_comeag_mgr_t();

public:
	virtual tbool OnMgrPrepare( ThrEle_t & t ) ;
	tbool MyInit();
};




#endif



