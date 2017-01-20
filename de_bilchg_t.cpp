
//
#include "2.h"
#include "de_bilchg_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_ui_t.h"



//
de_bilchg_t   *gp_bilchg;




#ifdef DE_BILCHG_REAL_XPP
#include "de_bilchg_real.xpp"
#else
#include "de_bilchg_fake.xpp"
#endif



