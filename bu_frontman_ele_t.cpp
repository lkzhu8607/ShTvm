
#include "bu_frontman_ele_t.h"
#include "de_log_t.h"
#include "de_tcpmsg_t.h"
#include "d_db_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"



//
bu_frontman_ele_t::bu_frontman_ele_t() 
{
}


//
bu_frontman_ele_t:: ~bu_frontman_ele_t()
{
	tr_destruct();
}



// 
int bu_frontman_ele_t::tr_on_user_run()
{
	gp_frontman_mgr->m_pcg->Proc();

	return 1;
}


