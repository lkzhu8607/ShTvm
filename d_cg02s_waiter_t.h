
#ifndef K1__d_cg02s_waiter_t_T_H
#define K1__d_cg02s_waiter_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "a_waiter_t.h"


//
class d_cg02s_waiter_t : public d_cg00s_t
{
public:

public:
	d_cg02s_waiter_t();
	virtual ~d_cg02s_waiter_t();

public:
	int FnD_WaiterJob( std::string strinput , a_waiter_t_rowtype * pwaiterdata ); // 0=需要更多事件，1=已处理  

};




#endif


