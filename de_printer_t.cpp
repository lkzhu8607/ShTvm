
//

#include "de_printer_t.h"
#include "de_log_t.h"




//
de_printer_t   *gp_printer;




#ifdef DE_PRINTER_REAL_XPP
#include "de_printer_real.xpp"
#else
#include "de_printer_fake.xpp"
#endif


