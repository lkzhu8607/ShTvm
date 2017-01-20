
//
#include "2.h"
#include "de_coin_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_log_t.h"
#include "de_medev_t.h"



//
de_coin_t   *gp_coin;




#ifdef DE_COIN_REAL_XPP
#include "de_coin_real.xpp"
#else
#include "de_coin_fake.xpp"
#endif


