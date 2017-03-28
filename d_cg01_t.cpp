
#include "2.h"
#include "d_cg01_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01s_backpic_t.h"
#include "d_cg01s_lang_t.h"
#include "d_cg01s_linepic_t.h"
#include "d_cg01s_rightupmsg_t.h"
#include "d_cg01s_machinestate_t.h"
#include "d_cg01s_fastprice_t.h"
#include "d_cg01s_seleline_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg01s_errpic_t.h"
#include "d_cg01s_errexplain_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "bu_timeshower_t.h"
#include "bu_frontman_mgr_t.h"



//
d_cg01_t  *plocalcg01;


//
d_cg01_t::d_cg01_t()
{
	plocalcg01 = this;

	m_cg01s_linepic_MainUiIdx = 1;
	m_cg01s_seleline_PageStartIdx = 0;
	pageGraphElementsFlags = 0;
	displayFlag = 0;
	langFlag = 0;
	pageFlag = 0;
	ErrCodeIndex = 0;
	MachineStateIndex = 0;
	pageTab = 0;	
	isFastFlag = 0;
	mianPicRecordCount = 0;
	errorFlag = 0;
	errorDetailIndex = 0;
}


//
d_cg01_t::~d_cg01_t()
{
}
void d_cg01_t::cg01_graphElementsHide(int langFlag)
{
	gp_ui->hideLabel(gp_conf->VersionDisplayLabel);
	if(langFlag == 0){
		for(int i=0;i< (plocalcg01->graphElementsCN.size());i++){
			if(plocalcg01->graphElementsCN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphElementsCN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
				plocalcg01->graphElementsCN[i].m_iShouldShow = 0;
			}
		}
		for(int i=0;i<plocalcg01->graphFastButtonCN.size();i++){
			if(plocalcg01->graphFastButtonCN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphFastButtonCN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
				plocalcg01->graphFastButtonCN[i].m_iShouldShow = 0;
			}			
		}
		for(int i=0;i<plocalcg01->graphLineButtonCN.size();i++){
			if(plocalcg01->graphLineButtonCN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
				plocalcg01->graphLineButtonCN[i].m_iShouldShow = 0;
			}			
		}	
		for(int i=0;i<plocalcg01->graphMainInterfaceCN.size();i++){
			//std::string strPic = "CN_MainPic_"+SStrf::sltoa((int)(i+1));
			//if(plocalcg01->graphMainInterfaceCN[i].m_name == strPic && plocalcg01->graphMainInterfaceCN[i].m_iShouldShow == 1){
			if(plocalcg01->graphMainInterfaceCN[i].m_funcname == "CN_mInterface"/* && plocalcg01->graphMainInterfaceCN[i].m_iShouldShow == 1*/){
				gp_ui->hideLabel(plocalcg01->graphMainInterfaceCN[i]);
				plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 0;
				continue;
			}
			else{
				plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 0;
			}
		}
	}
	else if(langFlag == 1){
		for(int i=0;i< (plocalcg01->graphElementsEN.size());i++){
			if(plocalcg01->graphElementsEN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphElementsEN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
				plocalcg01->graphElementsEN[i].m_iShouldShow = 0;
			}
		}
		for(int i=0;i<plocalcg01->graphFastButtonEN.size();i++){
			if(plocalcg01->graphFastButtonEN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphFastButtonEN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
				plocalcg01->graphFastButtonEN[i].m_iShouldShow = 0;
			}			
		}
		for(int i=0;i<plocalcg01->graphLineButtonEN.size();i++){
			if(plocalcg01->graphLineButtonEN[i].m_iShouldShow == 1){
				gp_ui->hideLabel(plocalcg01->graphLineButtonEN[i]);
				//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
				plocalcg01->graphLineButtonEN[i].m_iShouldShow = 0;
			}			
		}	
		for(int i=0;i<plocalcg01->graphMainInterfaceEN.size();i++){
			//std::string strPic = "EN_MainPic_"+SStrf::sltoa((int)(i+1));
			if(plocalcg01->graphMainInterfaceEN[i].m_funcname == "EN_mInterface"/* && plocalcg01->graphMainInterfaceEN[i].m_iShouldShow == 1*/){
				gp_ui->hideLabel(plocalcg01->graphMainInterfaceEN[i]);
				plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 0;
				continue;
			}
			else{
				plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 0;
			}
		}
	}
	for(int i=0;i<(gp_timeshower->graphElements.size());i++){
		if(gp_timeshower->graphElements[i].m_iShouldShow == 1){
			gp_ui->hideLabel(gp_timeshower->graphElements[i]);
			gp_timeshower->graphElements[i].m_iShouldShow = 0;
		}			
	}
}


//
void d_cg01_t::Proc()
{
	d_cg01s_backpic_t			cg01s_backpic;
	d_cg01s_lang_t			cg01s_lang;
	d_cg01s_rightupmsg_t	cg01s_rightupmsg;
	d_cg01s_fastprice_t  cg01s_fastprice;
	d_cg01s_evtcodes_t	cg01s_evtcodes;
	d_cg01s_errpic_t cg01s_errpic;
	d_cg01s_errexplain_t cg01s_errexplain;
	d_cg01s_linepic_t		cg01s_linepic;
	d_cg01s_seleline_t   cg01s_seleline;
	d_cg01s_machinestate_t	cg01s_machinestate;
	d_cg01s_jud5041_t  cg01s_jud5041;
	
	/*if(plocalcg01->pageGraphElementsFlags == 0){
		cg01s_backpic.ShowBack1();
		cg01s_lang.ShowLangButt();
		cg01s_rightupmsg.Showrightupmsg();
		cg01s_fastprice.Showfastprice();
		cg01s_linepic.ShowLinePic();
		//cg01s_linepic.ShowDirButt();
		cg01s_machinestate.Showmachinestate();
		cg01s_seleline.Showseleline();
		cg01s_evtcodes.m_x = 0.207;
		cg01s_evtcodes.ShowEvtCodes();	
		cg01s_errpic.Show();
		cg01s_errexplain.Show();
		plocalcg01->pageGraphElementsFlags = 1;
		if((plocalcg01->graphLineButtonCN.size()%10) == 0){
			plocalcg01->pageTab = (plocalcg01->graphLineButtonCN.size() / 10);
		}
		else{
			plocalcg01->pageTab = (plocalcg01->graphLineButtonCN.size() / 10) + 1;
		}		
		SetLanguageCh();
	}*/
	//WThrd::tr_sleepu(2);

	while(1)
	{
		//show page info
		if(plocalcg01->displayFlag == 0){
			if(plocalcg01->langFlag == 0){//
				//if(gp_frontman_mgr->graphLastPageElements.size())
					//gp_frontman_mgr->graphLastPageElements.clear();
				for(int i=0;i< (plocalcg01->graphElementsCN.size());i++){
					//WThrd::tr_sleepu(5);
					if(plocalcg01->graphElementsCN[i].m_name == "CN_page1BackPic"){
					//if(plocalcg01->graphElementsCN[i].m_funcname == "CN_ShowBack1"){
						//gp_ui->pic_task(plocalcg01->graphElementsCN[i]);
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}
					if(plocalcg01->graphElementsCN[i].m_name == "CN_StaName"){
						//gp_ui->str_task(plocalcg01->graphElementsCN[i]);
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}
					if(plocalcg01->graphElementsCN[i].m_name == "CN_MachineState"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsCN[i],GetStrRes(gp_medev->m_devstatus));
						//gp_ui->str_task(plocalcg01->graphElementsCN[i]);
						plocalcg01->MachineStateIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}					
					if(plocalcg01->graphElementsCN[i].m_name == "page1ErrCode"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsCN[i],gp_medev->GetEvtStr());
						//gp_ui->str_task(plocalcg01->graphElementsCN[i]);
						plocalcg01->ErrCodeIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}
				}
				for(int i=0;i < (plocalcg01->graphMainInterfaceCN.size());i++){
					if(plocalcg01->graphMainInterfaceCN[i].m_name == "CN_MainPic_1"){
						//gp_ui->pic_task(plocalcg01->graphMainInterfaceCN[i]);
						gp_ui->showLabel(plocalcg01->graphMainInterfaceCN[i]);
						plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}
					if(plocalcg01->graphMainInterfaceCN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt1")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceCN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt2")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceCN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt3")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceCN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt4")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}						

				}
				for(int i=0;i < (plocalcg01->graphFastButtonCN.size());i++){
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "CN_FastPicUp"){
						//gp_ui->pic_task(plocalcg01->graphFastButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
						continue;
					}	
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "ShowFastDigit"){
						//gp_ui->str_task(plocalcg01->graphFastButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
						continue;
					}
				}
				for(int i=0;i < (plocalcg01->graphLineButtonCN.size());i++){
					if(plocalcg01->pageTab == 1){
						if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_SeleLine"){
							//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							continue;
						}
					}
					else if(plocalcg01->pageTab == 2){
						if(plocalcg01->graphLineButtonCN[i].m_funcvalue <= 10){
							//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->pageFlag = 1;
							continue;
						}
						if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_NextButton"){
							//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							continue;
						}				
					}
				}
			}
			else if(plocalcg01->langFlag == 1){
				//if(gp_frontman_mgr->graphLastPageElements.size())
					//gp_frontman_mgr->graphLastPageElements.clear();
				for(int i=0;i< (plocalcg01->graphElementsEN.size());i++){
					//WThrd::tr_sleepu(5);
					if(plocalcg01->graphElementsEN[i].m_name == "EN_page1BackPic"){
					//if(plocalcg01->graphElementsCN[i].m_funcname == "EN_ShowBack1"){
						//gp_ui->pic_task(plocalcg01->graphElementsEN[i]);
						gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
						plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsEN[i]);
						continue;
					}
					if(plocalcg01->graphElementsEN[i].m_name == "EN_StaName"){
						//gp_ui->str_task(plocalcg01->graphElementsEN[i]);
						gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
						plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}
					if(plocalcg01->graphElementsEN[i].m_name == "EN_MachineState"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsEN[i],GetStrRes(gp_medev->m_devstatus));
						//gp_ui->str_task(plocalcg01->graphElementsEN[i]);
						plocalcg01->MachineStateIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
						plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}					
					if(plocalcg01->graphElementsEN[i].m_name == "page1ErrCode"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsEN[i],gp_medev->GetEvtStr());
						//gp_ui->str_task(plocalcg01->graphElementsCN[i]);
						plocalcg01->ErrCodeIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
						plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
						continue;
					}
				}
				for(int i=0;i < (plocalcg01->graphMainInterfaceEN.size());i++){
					if(plocalcg01->graphMainInterfaceEN[i].m_name == "EN_MainPic_1"){
						//gp_ui->pic_task(plocalcg01->graphMainInterfaceEN[i]);
						gp_ui->showLabel(plocalcg01->graphMainInterfaceEN[i]);
						plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}
					if(plocalcg01->graphMainInterfaceEN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt1")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceEN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt2")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceEN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt3")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}	
					if(plocalcg01->graphMainInterfaceEN[i].m_name == ("MainPic_"+SStrf::sltoa((int)(1))+"_dirButt4")){
						//gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphMainInterfaceEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphMainInterfaceCN[i]);
						continue;
					}						
				}
				for(int i=0;i < (plocalcg01->graphFastButtonEN.size());i++){
					if(plocalcg01->graphFastButtonEN[i].m_funcname == "EN_FastPicUp"){
						//gp_ui->pic_task(plocalcg01->graphFastButtonEN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphFastButtonEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
						continue;
					}	
					if(plocalcg01->graphFastButtonEN[i].m_funcname == "ShowFastDigit"){
						//gp_ui->str_task(plocalcg01->graphFastButtonEN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphFastButtonEN[i].m_iShouldShow = 1;
						//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphFastButtonCN[i]);
						continue;
					}
				}
				for(int i=0;i < (plocalcg01->graphLineButtonEN.size());i++){
					if(plocalcg01->pageTab == 1){
						if(plocalcg01->graphLineButtonEN[i].m_funcname=="EN_SeleLine"){
							//gp_ui->pic_task(plocalcg01->graphLineButtonEN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonEN[i]);
							plocalcg01->graphLineButtonEN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							continue;
						}
					}
					else if(plocalcg01->pageTab == 2){
						if(plocalcg01->graphLineButtonEN[i].m_funcvalue <= 10){
							//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonEN[i]);
							plocalcg01->graphLineButtonEN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->pageFlag = 1;
							continue;
						}
						if(plocalcg01->graphLineButtonEN[i].m_funcname=="EN_NextButton"){
							//gp_ui->pic_task(plocalcg01->graphLineButtonEN[i]);
							gp_ui->showLabel(plocalcg01->graphLineButtonEN[i]);
							plocalcg01->graphLineButtonEN[i].m_iShouldShow = 1;
							//gp_frontman_mgr->graphLastPageElements.push_back(plocalcg01->graphLineButtonCN[i]);
							continue;
						}
					}
				}
			}
			plocalcg01->displayFlag = 1;//
		}
		for(int i=0;i<(gp_timeshower->graphElements.size());i++){
			if(gp_timeshower->graphElements[i].m_name == "timeDisplay"){
				gp_ui->hideLabel(gp_timeshower->graphElements[i]);
		     	gp_ui->updateLabel(gp_timeshower->graphElements[i],SDte::GetNow().ReadString());
				gp_ui->str_task(gp_timeshower->graphElements[i]);
				gp_ui->showLabel(gp_timeshower->graphElements[i]);
				gp_timeshower->graphElements[i].m_iShouldShow = 1;
				//gp_frontman_mgr.graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
			}			
		}
		
		//if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) break;
		//d_cg01s_backpic_t			cg01s_backpic;
		//d_cg01s_lang_t			cg01s_lang;
		//d_cg01s_rightupmsg_t	cg01s_rightupmsg;
		//cg01s_backpic.ShowBack1();
		//cg01s_lang.ShowLangButt();
		//cg01s_rightupmsg.Showrightupmsg();
		//d_cg01s_fastprice_t  cg01s_fastprice;
		//cg01s_fastprice.Showfastprice();
		//d_cg01s_evtcodes_t  cg01s_evtcodes;
		//d_cg01s_errpic_t cg01s_errpic;
		//d_cg01s_errexplain_t cg01s_errexplain;
//L_RESHOW_linepic:
		//d_cg01s_linepic_t		cg01s_linepic;
		//cg01s_linepic.ShowLinePic();
		//cg01s_linepic.ShowDirButt();
//L_RESHOW_seleline:
		//d_cg01s_seleline_t   cg01s_seleline;
		//cg01s_seleline.Showseleline();
		gp_ui->str_task(gp_conf->VersionDisplayLabel);
		gp_ui->showLabel(gp_conf->VersionDisplayLabel);
		//LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->MachineStateIndex = " << plocalcg01->MachineStateIndex );
		//LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->ErrCodeIndex = " << plocalcg01->ErrCodeIndex );
L_GETINPUT:
		//d_cg01s_machinestate_t  cg01s_machinestate;
		//cg01s_machinestate.Showmachinestate();	
		//WThrd::tr_sleepu( 0.71 );
		//continue;
		//d_cg01s_jud5041_t  cg01s_jud5041;
		//cg01s_evtcodes.m_x = 0.207;
		//cg01s_evtcodes.ShowEvtCodes();
		do
		{
			m_strInput = gp_frontinput->GetFrontNextKey();
			if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) 
			{
				if(1)
				{
					MYAUTOLOCK( gp_medev->m_DevLck );
					gp_medev->m_IsChangeToStopSerice = 1;
				}
				break;
			}
		}while( m_strInput == "" );
		//refresh timedisplay
		for(int i=0;i<(gp_timeshower->graphElements.size());i++){
			if(gp_timeshower->graphElements[i].m_name == "timeDisplay"){
				gp_ui->hideLabel(gp_timeshower->graphElements[i]);
		     	gp_ui->updateLabel(gp_timeshower->graphElements[i],SDte::GetNow().ReadString());
				gp_ui->str_task(gp_timeshower->graphElements[i]);
				gp_ui->showLabel(gp_timeshower->graphElements[i]);
				gp_timeshower->graphElements[i].m_iShouldShow = 1;
				//gp_frontman_mgr.graphLastPageElements.push_back(plocalcg01->graphElementsCN[i]);
			}			
		}

		//refresh MachineState and ErrorCodes
		if(plocalcg01->langFlag == 0){
			SetLanguageCh();
			//gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex],GetStrRes(gp_medev->m_devstatus));
			//gp_ui->str_task(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex]);

			//gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex],gp_medev->GetEvtStr());
			//gp_ui->str_task(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
		}
		else if(plocalcg01->langFlag == 1){
			SetLanguageEn();
			//gp_ui->hideLabel(plocalcg01->graphElementsEN[plocalcg01->MachineStateIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsEN[plocalcg01->MachineStateIndex],GetStrRes(gp_medev->m_devstatus));
			//gp_ui->str_task(plocalcg01->graphElementsEN[plocalcg01->MachineStateIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsEN[plocalcg01->MachineStateIndex]);

			//gp_ui->hideLabel(plocalcg01->graphElementsEN[plocalcg01->ErrCodeIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsEN[plocalcg01->ErrCodeIndex],gp_medev->GetEvtStr());
			//gp_ui->str_task(plocalcg01->graphElementsEN[plocalcg01->ErrCodeIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsEN[plocalcg01->ErrCodeIndex]);
		}

		int  iLastOutOfServiceStatus = gp_medev->m_outofservicestatus;

		if( 4 == gp_medev->m_devstatus || 7 == gp_medev->m_devstatus)
		{
			//??¨º?o¨²?¨°o¨ª??¨®|¨ºy¡Á?
			//cg01s_errpic.Show();
			//cg01s_errexplain.Show();
			if(plocalcg01->errorFlag == 0){
				if(plocalcg01->langFlag == 0){
					for(int i=0;i<plocalcg01->graphElementsCN.size();i++){
						if(plocalcg01->graphElementsCN[i].m_name == "errPic"){
							//gp_ui->pic_task(plocalcg01->graphElementsCN[i]);
							gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
							plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
							plocalcg01->errorPicIndex = i;
							continue;
						}
						if(plocalcg01->graphElementsCN[i].m_name == "CN_ErrorDetail"){
							//gp_ui->str_task(plocalcg01->graphElementsCN[i]);
							gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
							plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
							plocalcg01->errorDetailIndex = i;
							continue;
						}
					}
				}
				else if(plocalcg01->langFlag == 1){
					for(int i=0;i<plocalcg01->graphElementsEN.size();i++){
						if(plocalcg01->graphElementsEN[i].m_name == "errPic"){
							//gp_ui->pic_task(plocalcg01->graphElementsEN[i]);
							gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
							plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
							plocalcg01->errorPicIndex = i;
							continue;
						}
						if(plocalcg01->graphElementsEN[i].m_name == "EN_ErrorDetail"){
							//gp_ui->str_task(plocalcg01->graphElementsEN[i]);
							gp_ui->showLabel(plocalcg01->graphElementsEN[i]);
							plocalcg01->graphElementsEN[i].m_iShouldShow = 1;
							plocalcg01->errorDetailIndex = i;
							continue;
						}
					}
				}
				plocalcg01->errorFlag = 1;
			}
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->errorDetailIndex = " << plocalcg01->errorDetailIndex );
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "plocalcg01->errorPicIndex = " << plocalcg01->errorPicIndex );			
L_GETINPUT2:

			do
			{
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

			if( 1 == cg01s_jud5041.Find_n_do_stopservice( gp_frontinput->GetFrontCurrentKey() ) )
			{
				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg04;
				if(plocalcg01->langFlag == 0){
					plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
				}
				else if(plocalcg01->langFlag == 1){
					plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
				}
				return;
			}
			if( cg01s_jud5041.Find_n_do_gotowork(gp_frontinput->GetFrontCurrentKey()) )
			{
				//plocalcg01->displayFlag = 0;
				//plocalcg01->langFlag = 0;
				if(plocalcg01->errorFlag == 1){
					if(plocalcg01->langFlag == 0){
						gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->errorDetailIndex]);
						plocalcg01->graphElementsCN[plocalcg01->errorDetailIndex].m_iShouldShow = 0;
						gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->errorPicIndex]);
						plocalcg01->graphElementsCN[plocalcg01->errorPicIndex].m_iShouldShow = 0;	
					}
					else if(plocalcg01->langFlag == 1){
						//TODO
						gp_ui->hideLabel(plocalcg01->graphElementsEN[plocalcg01->errorDetailIndex]);
						plocalcg01->graphElementsEN[plocalcg01->errorDetailIndex].m_iShouldShow = 0;
						gp_ui->hideLabel(plocalcg01->graphElementsEN[plocalcg01->errorPicIndex]);
						plocalcg01->graphElementsEN[plocalcg01->errorPicIndex].m_iShouldShow = 0;						
					}
				}
				plocalcg01->errorFlag = 0;
				continue;
			}
			if( iLastOutOfServiceStatus != gp_medev->m_outofservicestatus )
			{
				goto L_GETINPUT;
			}
			goto L_GETINPUT2;
		}

		if(1)
		{			

			if( cg01s_lang.Find_n_do_ShowLangButt( m_strInput ) ){
				continue;
			}
			if( cg01s_linepic.Find_n_do_ShowDirButt( m_strInput ) ) 
			{
				//cg01s_linepic.Clean();
				goto L_GETINPUT;
			}
			
			if( cg01s_fastprice.Find_n_do_Showfastprice( m_strInput ) ) 
			{
				return;
			}
			
			if( cg01s_seleline.Find_n_do_changepage( m_strInput ) ) 
			{
				goto L_GETINPUT;
			}

			if( cg01s_seleline.Find_n_do_seleline( m_strInput ) ) 
			{
				return;
			}
		
			int ret = 0;
			if( ret = cg01s_jud5041.Find_n_do_stopservice(m_strInput) )
			{
				if(ret == 2){
					plocalcg01->errorFlag = 0;
					continue;
				}
				else if(ret == 1){
					plocalcg04->displayFlag = 0;
					plocalcg04->langFlag = 0;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg04;
					if(plocalcg01->langFlag == 0){
						plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
					}
					else if(plocalcg01->langFlag == 1){
						plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
					}
					return;
				}
			}
			goto L_GETINPUT;
		}
	}
	return;
}


