//?????????? 
#ifndef K1__bu_frontman_mgr_t_H
#define K1__bu_frontman_mgr_t_H


#include "2.h" 
#include "bu_hot_thrd_t.h"
#include "bu_frontman_ele_t.h"
#include "d_cg00_t.h"
#include "d_cg01_t.h"
#include "d_cg02_t.h"
#include "d_cg03_t.h"
#include "d_cg04_t.h"
#include "d_cg05_t.h"
#include "d_cg06_t.h"



//
class bu_frontman_mgr_t : public WThrdMgr< bu_frontman_ele_t, bu_hot_thrd_t >
{
public:
	d_cg00_t  * m_pcg;
	d_cg01_t   m_cg01;
	d_cg02_t   m_cg02;
	d_cg03_t   m_cg03;
	d_cg04_t   m_cg04;
	d_cg05_t   m_cg05;
	d_cg06_t   m_cg06;
	std::vector<a_label_t::ROWTYPE> graphLastPageElementsCN;
	std::vector<a_label_t::ROWTYPE> graphLastPageElementsEN;
public:
	bu_frontman_mgr_t();
	virtual ~bu_frontman_mgr_t();

public:
	tbool frontmanInit();
	virtual tbool OnMgrPrepare( ThrEle_t & t ) ;
	
};



//
extern bu_frontman_mgr_t  *gp_frontman_mgr;



#endif



