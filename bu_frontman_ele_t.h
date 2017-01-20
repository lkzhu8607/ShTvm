
#ifndef K1__bu_frontman_ele_t_H
#define K1__bu_frontman_ele_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"
#include "d_cg01_t.h"



//
class bu_frontman_ele_t : public bu_hot_thrd_t
{
public:

public:
	bu_frontman_ele_t();
	virtual ~bu_frontman_ele_t();

public:
	virtual int tr_on_user_run();
	
};


#include "bu_frontman_mgr_t.h"



#endif



