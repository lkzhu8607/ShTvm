
//
#include "2.h"
#include "de_topscr_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_log_t.h"
#include "d_com_agent2_t.h"



//
de_topscr_t   *gp_topscr;	




#ifdef DE_TOPSCR_REAL_XPP
#include "de_topscr_real.xpp"
#else
#include "de_topscr_fake.xpp"
#endif


