
#include "2.h"
#include "d_cg04_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "d_cg04s_backpic_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg04s_stoppic_t.h"
#include "de_medev_t.h"



//
d_cg04_t  *plocalcg04;


//
d_cg04_t::d_cg04_t()
{
	plocalcg04 = this;
	displayFlag = 0;
	langFlag = 0;

}

//
d_cg04_t::~d_cg04_t()
{
}

//
void d_cg04_t::Proc()
{
	d_cg04s_backpic_t  cg04s_backpic;
	d_cg01s_jud5041_t  cg01s_jud5041;
	d_cg04s_stoppic_t  cg04s_stoppic;
	wl::tuint8 lastmachinestatus; 
	/*if(plocalcg04->pageGraphElementsFlags == 0){
		cg04s_stoppic.ShowBack1();
		cg04s_backpic.ShowBack1();
		plocalcg04->pageGraphElementsFlags = 1;
		//SetLanguageCh();
	}*/
	while(1)
	{
		//if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) 
		//{
		//	if(1)
		//		{
		//			MYAUTOLOCK( gp_medev->m_DevLck );
		//			gp_medev->m_IsChangeToStopSerice = 1;
		//		}
		//}
		
L_CHANGESTATUS:

		//d_cg04s_backpic_t  cg04s_backpic;
		//d_cg04s_stoppic_t  cg04s_stoppic;
//L_GETINPUT:	
		if( ( 9 == gp_medev->m_devstatus ) )
		{
			//cg04s_stoppic.ShowBack1();
			for(int i=0;i<plocalcg04->graphElementsCN.size();i++){
				if(plocalcg04->graphElementsCN[i].m_funcname == "page4StopService"){
					gp_ui->showLabel(plocalcg04->graphElementsCN[i]);
					plocalcg04->graphElementsCN[i].m_iShouldShow = 1;
					continue;
				}
				if(plocalcg04->graphElementsCN[i].m_funcname == "page4OutofService" && plocalcg04->graphElementsCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg04->graphElementsCN[i]);
					plocalcg04->graphElementsCN[i].m_iShouldShow = 0;
					continue;
				}
			}
		}
		else
		{
			for(int i=0;i<plocalcg04->graphElementsCN.size();i++){
				if(plocalcg04->graphElementsCN[i].m_funcname == "page4OutofService"){
					gp_ui->showLabel(plocalcg04->graphElementsCN[i]);
					plocalcg04->graphElementsCN[i].m_iShouldShow = 1;
					continue;
				}
				if(plocalcg04->graphElementsCN[i].m_funcname == "page4StopService" && plocalcg04->graphElementsCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg04->graphElementsCN[i]);
					plocalcg04->graphElementsCN[i].m_iShouldShow = 0;
					continue;
				}				
			}
			//LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->ErrCodeIndex = " << plocalcg01->ErrCodeIndex );
			for(int i=0;i<plocalcg01->graphElementsCN.size();i++){
					if(plocalcg01->graphElementsCN[i].m_name == "page1ErrCode"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsCN[i],gp_medev->GetEvtStr());
					    gp_ui->str_task(plocalcg01->graphElementsCN[i]);
						plocalcg01->ErrCodeIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						break;
					}			
			}
		}
		gp_ui->str_task(gp_conf->VersionDisplayLabel);
		gp_ui->showLabel(gp_conf->VersionDisplayLabel);
		lastmachinestatus = gp_medev->m_devstatus;
		//d_cg01s_evtcodes_t  cg01s_evtcodes;

L_GETINPUT:
		//d_cg01s_jud5041_t  cg01s_jud5041;

		//cg01s_evtcodes.ShowEvtCodes();

		do{
			gp_frontinput->GetFrontNextKey();
			if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) 
			{
				if(1)
				{
					MYAUTOLOCK( gp_medev->m_DevLck );
					gp_medev->m_IsChangeToStopSerice = 1;
				}
				break;
			}
					
		}while( gp_frontinput->GetFrontCurrentKey() == "" );


		if( 2 == cg01s_jud5041.Find_n_do_stopservice( gp_frontinput->GetFrontCurrentKey() ) )
		{
			//LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->ErrCodeIndex = " << plocalcg01->ErrCodeIndex );
			gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
			plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex].m_iShouldShow = 0;	
			gp_ui->showLabel(gp_conf->VersionDisplayLabel);
			
			plocalcg01->displayFlag = 0;
			plocalcg01->langFlag = 0;	
			plocalcg01->errorFlag = 0;
			gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
			if(plocalcg04->langFlag == 0){
				for(int i=0;i<plocalcg04->graphElementsCN.size();i++){
					if(plocalcg04->graphElementsCN[i].m_iShouldShow == 1){
						gp_ui->hideLabel(plocalcg04->graphElementsCN[i]);
						plocalcg04->graphElementsCN[i].m_iShouldShow = 0;
						continue;
					}
				}
			}
			else if(plocalcg04->langFlag == 1){
				for(int i=0;i<plocalcg04->graphElementsEN.size();i++){
					if(plocalcg04->graphElementsEN[i].m_iShouldShow == 1){
						gp_ui->hideLabel(plocalcg04->graphElementsEN[i]);
						plocalcg04->graphElementsEN[i].m_iShouldShow = 0;
						continue;
					}
				}
			}
		
			//plocalcg01->errorFlag = 0;
			return;
		}

		if( cg01s_jud5041.Find_n_do_gotowork(gp_frontinput->GetFrontCurrentKey()) )
		{
			//LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->ErrCodeIndex = " << plocalcg01->ErrCodeIndex );
			gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
			plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex].m_iShouldShow = 0;
			gp_ui->showLabel(gp_conf->VersionDisplayLabel);
			
			plocalcg01->displayFlag = 0;
			plocalcg01->langFlag = 0;
			plocalcg01->errorFlag = 0;
			gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
			if(plocalcg04->langFlag == 0){
				for(int i=0;i<plocalcg04->graphElementsCN.size();i++){
					if(plocalcg04->graphElementsCN[i].m_iShouldShow == 1){
						gp_ui->hideLabel(plocalcg04->graphElementsCN[i]);
						plocalcg04->graphElementsCN[i].m_iShouldShow = 0;
						continue;
					}
				}
			}
			else if(plocalcg04->langFlag == 1){
				for(int i=0;i<plocalcg04->graphElementsEN.size();i++){
					if(plocalcg04->graphElementsEN[i].m_iShouldShow == 1){
						gp_ui->hideLabel(plocalcg04->graphElementsEN[i]);
						plocalcg04->graphElementsEN[i].m_iShouldShow = 0;
						continue;
					}
				}
			}
			//plocalcg01->errorFlag = 0;
			return;
		}

		if( lastmachinestatus != gp_medev->m_devstatus )
		{
			goto L_CHANGESTATUS;
		}

		goto L_GETINPUT;
	}
			
	return;
}


