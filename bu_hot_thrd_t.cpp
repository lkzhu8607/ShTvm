
#include "2.h"
#include "bu_hot_thrd_t.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"



//
bu_hot_thrd_t::bu_hot_thrd_t()
{
}


static	bu_quickflow_t::qf_counter_t  iQf1;
static int j = 0;
// 
void bu_hot_thrd_t::tr_on_knl_run()
{
	while(1)
	{
		if( gp_conf->m_biSysShouldExit || gp_conf->m_biSysShouldShutdown || gp_conf->m_biSysShouldReboot )
		{
			j++;
			if( j == 1 )
				gp_qf->GetQf( iQf1 );
		
			if( j > 1 && gp_qf->IsLongQf( iQf1, 5*60 ) ) 
			{
				this->tr_shouldbrk();
				break;
			}
		}

		if( !tr_on_user_run() ) break;

		if( this->tr_isShouldBrk() ) break;
	}
}

