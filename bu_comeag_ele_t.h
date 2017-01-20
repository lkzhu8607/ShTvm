
#ifndef K1__bu_comeag_ele_t_H
#define K1__bu_comeag_ele_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"
#include "d_com_PR_0203.h"
#include "d_com_PR_LEN_AT_3.h"



//
class bu_comeag_ele_t : public WThrd
{
public:
	WTcpCells		m_tSvr;
	WComeliCell		m_Comelicell;

	d_com_PR_0203		m_com_PR_0203;
	d_com_PR_LEN_AT_3	m_com_PR_LEN_AT_3;

public:
	bu_comeag_ele_t();
	virtual ~bu_comeag_ele_t();

public:
	virtual void tr_on_pre_thrd();
	virtual void tr_on_post_thrd();
	virtual int tr_on_user_run();

};





#endif



