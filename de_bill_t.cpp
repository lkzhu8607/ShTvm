
//
#include "2.h"
#include "de_bill_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"
#include "de_log_t.h"
#include "de_medev_t.h"




//
de_bill_t   *gp_bill;




#ifdef DE_BILL_REAL_XPP
//#include "de_bill_real.xpp"
//#include "de_bill_real2.xpp"
#include "de_bill_real3.xpp"
#else
#include "de_bill_fake.xpp"
#endif



