
#include "2.h"
#include "d_cg03_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "d_cg03s_backpic_t.h"
#include "d_cg03s_lang_t.h"
#include "d_cg01s_seleline_t.h"
#include "d_cg03s_goback_t.h"
#include "d_cg03s_oneline_t.h"
#include "d_cg03s_rightsidemsg_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg03s_machinestate_t.h"
#include "bu_timeshower_t.h"



//
d_cg03_t  *plocalcg03;


//
d_cg03_t::d_cg03_t()
{
	plocalcg03 = this;
	lineCount = 0;
	lineIndex = 0;
	MachineStateIndex = 0;
	pageGraphElementsFlags = 0;

}


//
d_cg03_t::~d_cg03_t()
{
}

//
void d_cg03_t::Proc()
{
	d_cg03s_backpic_t  cg03s_backpic;
	d_cg03s_rightsidemsg_t  cg03s_rightsidemsg;
	d_cg03s_lang_t  cg03s_lang;
	d_cg03s_goback_t  cg03s_goback;
	d_cg03s_oneline_t  cg03s_oneline;
	d_cg01s_seleline_t   cg01s_seleline;
	d_cg03s_machinestate_t  cg03s_machinestate;
	d_cg01s_jud5041_t  cg01s_jud5041;
	if(plocalcg03->pageGraphElementsFlags == 0){
		cg03s_backpic.ShowBack1();
		cg03s_rightsidemsg.Showrightsidemsg();
		cg03s_lang.ShowLangButt();
		cg03s_goback.ShowGoback();
		cg03s_oneline.Showoneline();
		cg03s_machinestate.Showmachinestate();
		plocalcg03->pageGraphElementsFlags = 1;
		//SetLanguageCh();
	}	

	//for timeout 
	bu_quickflow_t::qf_counter_t  iQf1_user_idle;
	double iQf1_user_idleMAX = gp_db->m_a3003.GetRow(0).m_PutCoinWaitTimeSec;
	gp_qf->GetQf( iQf1_user_idle );

	while(1)
	{
		if(plocalcg03->displayFlag == 0){
			if(plocalcg03->langFlag == 0){//
				for(int i=0;i<plocalcg03->graphElementsCN.size();i++){
					if(plocalcg03->graphElementsCN[i].m_name == "CN_thirdBackPic"){
						gp_ui->showLabel(plocalcg03->graphElementsCN[i]);
						plocalcg03->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg03->graphElementsCN[i].m_name == "CN_page3UpRightMsg"){
						gp_ui->showLabel(plocalcg03->graphElementsCN[i]);
						plocalcg03->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					/*if(plocalcg03->graphElementsCN[i].m_name == "CN_page3LangButton"){
						gp_ui->showLabel(plocalcg03->graphElementsCN[i]);
						plocalcg03->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg03->graphElementsCN[i].m_name == "CN_page3GoBack"){
						gp_ui->showLabel(plocalcg03->graphElementsCN[i]);
						continue;
					}*/		
					if(plocalcg03->graphElementsCN[i].m_name == "CN_MachineState"){
						gp_ui->hideLabel(plocalcg03->graphElementsCN[i]);
						gp_ui->updateLabel(plocalcg03->graphElementsCN[i],gp_db->GetMyStaName());
						gp_ui->str_task(plocalcg03->graphElementsCN[i]);
						gp_ui->showLabel(plocalcg03->graphElementsCN[i]);
						plocalcg03->graphElementsCN[i].m_iShouldShow = 1;
						plocalcg03->MachineStateIndex = i;
						continue;
					}							
				}
				
				for(int i = 0;i<plocalcg03->lineCount;i++){
					if(plocalcg03->graphLineStationCN[i][0].m_funcvalue == gp_frontman_mgr->m_cg03.m_iLineCode){
						//gp_ui->pic_task(plocalcg03->graphLineStationCN[i][0]);
						gp_ui->showLabel(plocalcg03->graphLineStationCN[i][0]);
						plocalcg03->graphLineStationCN[i][0].m_iShouldShow = 1;
						plocalcg03->lineIndex = i;
						/*for(int j = 1;j <plocalcg03->graphLineStationCN[i].size(); j++){
							;
						}*/					
					}
				}
				if(gp_frontman_mgr->m_cg03.m_iLineCode <= 10){
					for(int i=0;i<plocalcg01->graphLineButtonCN.size();i++){
						if(plocalcg01->graphLineButtonCN[i].m_funcvalue <= 10){
							//gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
							gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg01->graphLineButtonCN[i].m_funcname == "CN_NextButton"){
							//gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
							gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;	
						}
					}
				}
				else if(gp_frontman_mgr->m_cg03.m_iLineCode > 10){
					for(int i=0;i<plocalcg01->graphLineButtonCN.size();i++){
						if(plocalcg01->graphLineButtonCN[i].m_funcvalue > 10 && plocalcg01->graphLineButtonCN[i].m_funcname == "CN_SeleLine"){
							//gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
							gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg01->graphLineButtonCN[i].m_funcname == "CN_PrevButton"){
							//gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
							gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;	
						}
					}

				}
			}
			else if(plocalcg03->langFlag == 1){
				;
			}
			plocalcg03->displayFlag = 1;
		}

		for(int i=0;i<(gp_timeshower->graphElements.size());i++){
			if(gp_timeshower->graphElements[i].m_name == "dateDisplay"){
				gp_ui->hideLabel(gp_timeshower->graphElements[i]);
		     	gp_ui->updateLabel(gp_timeshower->graphElements[i],SDte::GetNow().ReadStrDate());
				gp_ui->str_task(gp_timeshower->graphElements[i]);
				gp_ui->showLabel(gp_timeshower->graphElements[i]);
				gp_timeshower->graphElements[i].m_iShouldShow = 1;
				
			}			
		}	

		if(plocalcg03->langFlag == 0){
			gp_ui->hideLabel(plocalcg03->graphElementsCN[plocalcg03->MachineStateIndex]);
			gp_ui->updateLabel(plocalcg03->graphElementsCN[plocalcg03->MachineStateIndex],gp_db->GetMyStaName());
			gp_ui->str_task(plocalcg03->graphElementsCN[plocalcg03->MachineStateIndex]);
			gp_ui->showLabel(plocalcg03->graphElementsCN[plocalcg03->MachineStateIndex]);
			
		}	
		else if(plocalcg03->langFlag == 1){
			;
		}

		if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) break;

		//d_cg03s_backpic_t  cg03s_backpic;

		//cg03s_backpic.ShowBack1();

		//d_cg03s_rightsidemsg_t  cg03s_rightsidemsg;

		//cg03s_rightsidemsg.Showrightsidemsg();

		//d_cg03s_lang_t  cg03s_lang;

		//cg03s_lang.ShowLangButt();
	
		//d_cg03s_goback_t  cg03s_goback;

		//cg03s_goback.ShowGoback();

		//d_cg01s_evtcodes_t  cg01s_evtcodes;

L_RESHOW_oneline:
		//d_cg03s_oneline_t  cg03s_oneline;

		//cg03s_oneline.Showoneline();

L_RESHOW_seleline:
		//d_cg01s_seleline_t   cg01s_seleline;

		//cg01s_seleline.Showseleline();

		//¨®D¦Ì??¡Â ??D???3?¨º¡À
		gp_qf->GetQf( iQf1_user_idle );

L_GETINPUT:
		//d_cg03s_machinestate_t  cg03s_machinestate;

		//cg03s_machinestate.Showmachinestate();

		//d_cg01s_jud5041_t  cg01s_jud5041;

		//cg01s_evtcodes.m_x = 0.32;
		//cg01s_evtcodes.ShowEvtCodes();

		do{
			gp_frontinput->GetFrontNextKey();

			//³¬Ê±£¬
			/*if( gp_qf->IsLongQf( iQf1_user_idle , iQf1_user_idleMAX ) )
			{
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "  timeout ");

				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;

				gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
				gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
				SetLanguageCh();
				return;
			}*/

		}while( gp_frontinput->GetFrontCurrentKey() == "" );


		if( cg03s_lang.Find_n_do_ShowLangButt( gp_frontinput->GetFrontCurrentKey() ) )
			continue;

		if( cg01s_seleline.Find_n_do_changepage( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			goto L_RESHOW_seleline;
		}

		if( cg01s_seleline.Find_n_do_seleline( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			goto L_RESHOW_oneline;
		}

		if( cg03s_goback.Find_n_do_ShowGoback( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			return;
		}

		if( cg03s_oneline.Find_n_do_Showoneline( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			return;
		}

		/*if( cg01s_jud5041.Find_n_do_stopservice(gp_frontinput->GetFrontCurrentKey()) )
		{
			return;
		}*/
		
		goto L_GETINPUT;
	}

			
	return;
}


