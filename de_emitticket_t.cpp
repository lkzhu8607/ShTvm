
//
#include "2.h"
#include "de_emitticket_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"



//
de_emitticket_t   *gp_emitticket;




#ifdef DE_EMITTICKET_REAL_XPP
#include "de_emitticket_real.xpp"
#else
#include "de_emitticket_fake.xpp"
#endif


