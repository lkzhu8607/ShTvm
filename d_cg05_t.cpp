
#include "2.h"
#include "d_cg05_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg05s_backpic_t.h"



//
d_cg05_t  *plocalcg05;


//
d_cg05_t::d_cg05_t()
{
	plocalcg05 = this;

}


//
d_cg05_t::~d_cg05_t()
{
}

//
void d_cg05_t::Proc()
{
	while(1)
	{
		if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) break;
		
		d_cg05s_backpic_t  cg05s_backpic;
		//cg05s_backpic.ShowBack1();
		//d_cg01s_evtcodes_t  cg01s_evtcodes;
	
		a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
		d_cg01s_jud5041_t  cg01s_jud5041;

L_GETINPUT:
		//d_cg01s_jud5041_t  cg01s_jud5041;
		//cg01s_evtcodes.m_x = 0.33;
		//cg01s_evtcodes.ShowEvtCodes();

		do{
			gp_frontinput->GetFrontNextKey();
			if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) return;
			//gp_frontinput->input_KIN_APP();
		}while( gp_frontinput->GetFrontCurrentKey() == "" );

		if( !IsOsWin() )
			WThrd::tr_sleep( 1 );

		if( Ra5041.m_e.a[71] == 1 ) 
		{
			if( cg01s_jud5041.Find_n_do_gotowork(gp_frontinput->GetFrontCurrentKey()) )
			{
				plocalcg01->displayFlag = 0;
				plocalcg01->langFlag = 0;
				plocalcg01->errorFlag = 0;
				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;

				return;
			}

			int ret = 0;
			if( ret = cg01s_jud5041.Find_n_do_stopservice(gp_frontinput->GetFrontCurrentKey()) )
			{
				//如果有投钱，则退钱 或 列印异常交易
				if(ret == 2){
					plocalcg01->displayFlag = 0;
					plocalcg01->langFlag = 0;
					plocalcg01->errorFlag = 0;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
				}
				else if(ret == 1){
					plocalcg04->displayFlag = 0;
					plocalcg04->langFlag = 0;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg04;
				}
				return;
			}	
		}

		goto L_GETINPUT;
	}

	return;
}


