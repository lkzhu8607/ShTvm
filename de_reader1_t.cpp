
//
#include "2.h"
#include "de_reader1_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_log_t.h"



//
de_reader1_t   *gp_reader1;




#ifdef DE_READER1_REAL_XPP
#include "de_reader1_real.xpp"
#else
#include "de_reader1_fake.xpp"
#endif



