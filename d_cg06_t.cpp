
#include "2.h"
#include "d_cg06_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "d_cg06_backpic_t.h"
#include "de_coin_t.h"
#include "d_cg06_showmess_t.h"
#include "de_bill_t.h"



//
d_cg06_t  *plocalcg06;


//
d_cg06_t::d_cg06_t()
{
	plocalcg06 = this;
	displayFlag = 0;
	langFlag = 0;

}


//
d_cg06_t::~d_cg06_t()
{
}

//
void d_cg06_t::Proc()
{
	
		d_cg06_backpic_t  cg06_backpic;
		d_cg06_showmess_t cg06_showmess;

		//cg06_backpic.ShowBack1();
		//cg06_showmess.ShowMessage();
		char sz1[33];


		if(plocalcg06->displayFlag == 0){
			if(plocalcg06->langFlag == 0){
				for(int i=0;i< (plocalcg06->graphElementsCN.size());i++){
					if(plocalcg06->graphElementsCN[i].m_name == "CN_page6BackPic"){
						gp_ui->showLabel(plocalcg06->graphElementsCN[i]);
						plocalcg06->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg06->graphElementsCN[i].m_name == "CN_TicketNum"){
						SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_TicketoutActual );
						gp_ui->updateLabel(plocalcg06->graphElementsCN[i],sz1);
						gp_ui->showLabel(plocalcg06->graphElementsCN[i]);
						plocalcg06->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg06->graphElementsCN[i].m_name == "CN_page6Chg"){
						SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_BilchgActual + \
			                           gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_CoinRecycleChgActual );
						gp_ui->updateLabel(plocalcg06->graphElementsCN[i],sz1);
						gp_ui->showLabel(plocalcg06->graphElementsCN[i]);
						plocalcg06->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
				}
			}
			else if(plocalcg06->langFlag == 1){
				for(int i=0;i< (plocalcg06->graphElementsEN.size());i++){
					if(plocalcg06->graphElementsEN[i].m_name == "EN_page6BackPic"){
						gp_ui->showLabel(plocalcg06->graphElementsEN[i]);
						plocalcg06->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg06->graphElementsEN[i].m_name == "EN_TicketNum"){
						SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_TicketoutActual );
						gp_ui->updateLabel(plocalcg06->graphElementsEN[i],sz1);
						gp_ui->showLabel(plocalcg06->graphElementsEN[i]);
						plocalcg06->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg06->graphElementsEN[i].m_name == "EN_page6Chg"){
						SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_BilchgActual + \
			                           gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_CoinRecycleChgActual );	
						gp_ui->updateLabel(plocalcg06->graphElementsEN[i],sz1);
						gp_ui->showLabel(plocalcg06->graphElementsEN[i]);
						plocalcg06->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
				}

			}
			plocalcg06->displayFlag = 1;

		}
		wl::WThrd::tr_sleepu( 3 );
		if(plocalcg06->langFlag == 0){
			for(int i=0;i<plocalcg06->graphElementsCN.size();i++){
				if(plocalcg06->graphElementsCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg06->graphElementsCN[i]);
					plocalcg06->graphElementsCN[i].m_iShouldShow = 0;
					continue;
				}
			}
		}
		else if(plocalcg06->langFlag == 1){
			for(int i=0;i<plocalcg06->graphElementsEN.size();i++){
				if(plocalcg06->graphElementsEN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg06->graphElementsEN[i]);
					plocalcg06->graphElementsEN[i].m_iShouldShow = 0;
					continue;
				}
			}
		}

		plocalcg01->displayFlag = 0;
		plocalcg01->langFlag = 0;
		plocalcg01->errorFlag = 0;		
		gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;

		gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
		gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
		SetLanguageCh();
		

		
		gp_coin->RepCoinStock();    //检测是否需要补充硬币
		gp_coin->CleanCoinStock();  //检测是否需要清除部分硬币
		gp_bill->RepBillStock();    //检测是否需要补充纸币
		
		//wl::WThrd::tr_sleepu( 3 );
		
		return ;
		
}


