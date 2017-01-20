//前端操作对象管理者类 
#ifndef K1__bu_backman_mgr_t_H
#define K1__bu_backman_mgr_t_H


#include "2.h" 
#include "bu_hot_thrd_t.h"
#include "bu_backman_ele_t.h"



//
class bu_backman_mgr_t : public WThrdMgr< bu_backman_ele_t, bu_hot_thrd_t >
{
public:

public:
	bu_backman_mgr_t();
	virtual ~bu_backman_mgr_t();

public:
	tbool backmanInit();
	virtual tbool OnMgrPrepare( ThrEle_t & t ) ;
	
};



//
extern bu_backman_mgr_t  *gp_backman_mgr;



#endif



