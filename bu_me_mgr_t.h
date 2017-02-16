


//接受SC服务器下发的参数
#ifndef K1__bu_me_mgr_t_H
#define K1__bu_me_mgr_t_H


#include "2.h" 
#include "bu_hot_thrd_t.h"
#include "bu_me_ele_t.h"



//
class bu_me_mgr_t : public WThrdMgr< bu_me_ele_t, bu_hot_thrd_t >
{
public:
	WTcpListener  m_Lsn;

public:
	bu_me_mgr_t();
	virtual ~bu_me_mgr_t();

public:
	tbool Init();
	virtual tbool OnMgrPrepare( ThrEle_t & t ) ;
	
};




#endif


