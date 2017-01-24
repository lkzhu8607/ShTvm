
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
}


//
d_cg01_t::~d_cg01_t()
{
}

//
void d_cg01_t::Proc()
{
	//gp_ui->LabelFixedHide();
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
	
	if(plocalcg01->pageGraphElementsFlags == 0){
		cg01s_backpic.ShowBack1();
		cg01s_lang.ShowLangButt();
		cg01s_rightupmsg.Showrightupmsg();
		cg01s_fastprice.Showfastprice();
		cg01s_linepic.ShowLinePic();
		cg01s_linepic.ShowDirButt();
		cg01s_machinestate.Showmachinestate();
		cg01s_seleline.Showseleline();
		cg01s_evtcodes.m_x = 0.207;
		cg01s_evtcodes.ShowEvtCodes();	
		plocalcg01->pageGraphElementsFlags = 1;
		if((plocalcg01->graphLineButtonCN.size()%10) == 0){
			pageTab = (plocalcg01->graphLineButtonCN.size() / 10);
		}
		else{
			pageTab = (plocalcg01->graphLineButtonCN.size() / 10) + 1;
		}		
		SetLanguageCh();
	}

	while(1)
	{
		//show page info
		if(plocalcg01->displayFlag == 0){
			if(plocalcg01->langFlag == 0){//
				for(int i=0;i< (plocalcg01->graphElementsCN.size());i++){
					if(plocalcg01->graphElementsCN[i].m_name == "CN_page1BackPic"){
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg01->graphElementsCN[i].m_name == "CN_StaName"){
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}				
					if(plocalcg01->graphElementsCN[i].m_funcname == "ShowDirButt"){
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}	
					if(plocalcg01->graphElementsCN[i].m_funcname == "CN_LinePic"){
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg01->graphElementsCN[i].m_name == "CN_MachineState"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsCN[i],GetStrRes(gp_medev->m_devstatus));
						plocalcg01->MachineStateIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg01->graphElementsCN[i].m_name == "page1ErrCode"){
		     			gp_ui->updateLabel(plocalcg01->graphElementsCN[i],gp_medev->GetEvtStr());
						plocalcg01->ErrCodeIndex = i;
						gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
						plocalcg01->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					//else 
						
					//gp_ui->showLabel(plocalcg01->graphElementsCN[i]);
				}
				for(int i=0;i < (plocalcg01->graphFastButtonCN.size());i++){
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "CN_FastPicUp"){
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
						continue;
					}	
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "ShowFastDigit"){
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
						continue;
					}	
				}
				for(int i=0;i < (plocalcg01->graphLineButtonCN.size());i++){
					if(plocalcg01->pageTab == 1){
						if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_SeleLine"){
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;
						}
					}
					else if(plocalcg01->pageTab == 2){
						if(plocalcg01->graphLineButtonCN[i].m_funcvalue <= 10){
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							plocalcg01->pageFlag = 1;
							continue;
						}
						if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_NextButton"){
							gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);
							plocalcg01->graphLineButtonCN[i].m_iShouldShow = 1;
							continue;
						}						
					}
					/*else{
						continue;
					}*/
				}
			}
			else if(plocalcg01->langFlag == 1){

			}
			plocalcg01->displayFlag = 1;//
		
		}

		//refresh timedisplay
		for(int i=0;i<(gp_timeshower->graphElements.size());i++){
			if(gp_timeshower->graphElements[i].m_name == "timeDisplay"){
				gp_ui->hideLabel(gp_timeshower->graphElements[i]);
		     	gp_ui->updateLabel(gp_timeshower->graphElements[i],SDte::GetNow().ReadString());
				gp_ui->str_task(gp_timeshower->graphElements[i]);
				gp_ui->showLabel(gp_timeshower->graphElements[i]);
				gp_timeshower->graphElements[i].m_iShouldShow = 1;
			}			
		}		

		//refresh MachineState and ErrorCodes
		if(plocalcg01->langFlag == 0){
			//gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex],GetStrRes(gp_medev->m_devstatus));
			//gp_ui->showLabel(plocalcg01->graphElementsCN[plocalcg01->MachineStateIndex]);

			//gp_ui->hideLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex],gp_medev->GetEvtStr());
			//gp_ui->showLabel(plocalcg01->graphElementsCN[plocalcg01->ErrCodeIndex]);
		}
		else if(plocalcg01->langFlag == 1){
			/*gp_ui->hideLabel(plocalcg01->graphElementsEN[MachineStateIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsEN[MachineStateIndex],GetStrRes(gp_medev->m_devstatus));
			gp_ui->str_task(plocalcg01->graphElementsEN[MachineStateIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsEN[MachineStateIndex]);

			gp_ui->hideLabel(plocalcg01->graphElementsEN[ErrCodeIndex]);
		    gp_ui->updateLabel(plocalcg01->graphElementsEN[ErrCodeIndex],gp_medev->GetEvtStr());
			gp_ui->str_task(plocalcg01->graphElementsEN[ErrCodeIndex]);
			gp_ui->showLabel(plocalcg01->graphElementsEN[ErrCodeIndex]);*/
		}
		//检查是否需要补充硬币   //补充条件-> 1. 初始化界面 2.是否需要补币 3.补币箱中是否有币
		/*if( ( 4 != gp_medev->m_devstatus ) &&
			( gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg < gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) &&
			( 0 != gp_coin->m_iIsRepCoinOk ) )
		{
			if( gp_coin->SupplementaryYuan1Coins( gp_conf->m_coin_rep_num ) != 0 )
			{
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "补币失败");
				if( 1 )
				{
					MYAUTOLOCK( gp_coin->m_DevLck );
					gp_coin->m_iIsRepCoinOk = 0;
				}
			}
			else
			{
				if( gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg < gp_conf->m_coin_rep_num  )
				{
					if( 1 )
					{
						MYAUTOLOCK( gp_coin->m_DevLck );
						gp_coin->m_iIsRepCoinOk = 0;
					}
				}
				else
				{
					if( 1 )
					{
						MYAUTOLOCK( gp_coin->m_DevLck );
						gp_coin->m_iIsRepCoinOk = 1;
					}
				}
				
			}			
		}*/

		if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) break;

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

L_RESHOW_linepic:
		//d_cg01s_linepic_t		cg01s_linepic;

		//cg01s_linepic.ShowLinePic();
		//cg01s_linepic.ShowDirButt();

		
L_RESHOW_seleline:
		//d_cg01s_seleline_t   cg01s_seleline;

		//cg01s_seleline.Showseleline();

L_GETINPUT:
		//d_cg01s_machinestate_t  cg01s_machinestate;

		//cg01s_machinestate.Showmachinestate();
		
		//WThrd::tr_sleepu( 0.71 );
		//continue;

		//d_cg01s_jud5041_t  cg01s_jud5041;

		//cg01s_evtcodes.m_x = 0.207;
		//cg01s_evtcodes.ShowEvtCodes();

		
		int  iLastOutOfServiceStatus = gp_medev->m_outofservicestatus;

		/*if( 4 == gp_medev->m_devstatus )
		{

			//??ê?oú?òoí??ó|êy×?
			cg01s_errpic.Show();
			cg01s_errexplain.Show();

L_GETINPUT2:

			do
			{
				gp_frontinput->GetFrontNextKey();
				if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) return;
			}while( gp_frontinput->GetFrontCurrentKey() == "" );

			if( 1 == cg01s_jud5041.Find_n_do_stopservice( gp_frontinput->GetFrontCurrentKey() ) )
			{
				return;
			}
			if( cg01s_jud5041.Find_n_do_gotowork(gp_frontinput->GetFrontCurrentKey()) )
			{
				return;
			}
			if( iLastOutOfServiceStatus != gp_medev->m_outofservicestatus )
			{
				goto L_GETINPUT;
			}
			goto L_GETINPUT2;

		}*/
		//else
		if(1)
		{

			do
			{
				m_strInput = gp_frontinput->GetFrontNextKey();
			}while( m_strInput == "" );

			if( cg01s_lang.Find_n_do_ShowLangButt( m_strInput ) ){
				plocalcg01->langFlag = 1;
				plocalcg01->displayFlag = 0;
				continue;
			}
			if( cg01s_linepic.Find_n_do_ShowDirButt( m_strInput ) ) 
			{
				//cg01s_linepic.Clean();
				goto L_RESHOW_linepic;
			}
			
			if( cg01s_fastprice.Find_n_do_Showfastprice( m_strInput ) ) 
			{
				return;
			}
			
			if( cg01s_seleline.Find_n_do_changepage( m_strInput ) ) 
			{
				goto L_RESHOW_seleline;
			}

			if( cg01s_seleline.Find_n_do_seleline( m_strInput ) ) 
			{
				return;
			}
		

			if( cg01s_jud5041.Find_n_do_stopservice(m_strInput) )
			{
				return;
			}

		
			goto L_GETINPUT;
		}
		//WThrd::tr_sleepu( 0.15 );
	}

	return;
}


