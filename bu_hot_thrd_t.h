
#ifndef K1__bu_hot_thrd_t_H
#define K1__bu_hot_thrd_t_H


#include "2.h" 



// 
class bu_hot_thrd_t : public WThrd
{
public:
	 

public:
	bu_hot_thrd_t();
	virtual ~bu_hot_thrd_t(){tr_destruct();}

public:
	virtual void tr_on_knl_run();

};




#endif


