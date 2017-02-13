
#include "2.h"
#include "d_cg02_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "d_cg02s_backpic_t.h"
#include "d_cg02s_goback_t.h"
#include "d_cg02s_cancel_t.h"
#include "d_cg02s_pieceshow_t.h"
#include "d_cg02s_goodbillcoin_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg02s_waiter_t.h"
#include "cg02s_machinestate_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "de_coin_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bill_t.h"
#include <iostream>

using namespace std;
//
d_cg02_t  *plocalcg02;



//
d_cg02_t::d_cg02_t()
{
	plocalcg02 = this;

	m_iPrice = 0;
	m_iPieceNum = 1;
	m_pLastCg = &gp_frontman_mgr->m_cg01;
	displayFlag = 0;
	langFlag = 0;	
	payedIndex = 0;
	shouldChangeIndex = 0;
	//normalNoteIndex = 0;
	//exceptNoteIndex = 0;
	notesIndex = 0;
	pageGraphElementsFlags = 0;
	//coinIndex = 0;

}


//
d_cg02_t::~d_cg02_t()
{
}

void d_cg02_t::cg02_graphElementsHide(int langFlag)
{
	if(langFlag == 0){
		for(int i=0;i<plocalcg02->graphElementsCN.size();i++){
			if(plocalcg02->graphElementsCN[i].m_iShouldShow ==1){
				gp_ui->hideLabel(plocalcg02->graphElementsCN[i]);
				plocalcg02->graphElementsCN[i].m_iShouldShow = 0;
			}
		}
		for(int i=0;i<plocalcg02->graphPieceNumCN.size();i++){
			if(plocalcg02->graphPieceNumCN[i].m_iShouldShow ==1){
				gp_ui->hideLabel(plocalcg02->graphPieceNumCN[i]);
				plocalcg02->graphPieceNumCN[i].m_iShouldShow = 0;
			}
		}
	}
	else if(langFlag == 1){
		for(int i=0;i<plocalcg02->graphElementsEN.size();i++){
			if(plocalcg02->graphElementsEN[i].m_iShouldShow ==1){
				gp_ui->hideLabel(plocalcg02->graphElementsEN[i]);
				plocalcg02->graphElementsEN[i].m_iShouldShow = 0;
			}
		}
		for(int i=0;i<plocalcg02->graphPieceNumEN.size();i++){
			if(plocalcg02->graphPieceNumEN[i].m_iShouldShow ==1){
				gp_ui->hideLabel(plocalcg02->graphPieceNumEN[i]);
				plocalcg02->graphPieceNumEN[i].m_iShouldShow = 0;
			}
		}
	}
	plocalcg01->isFastFlag = 0;
}

//
void d_cg02_t::Proc()
{
	d_cg02s_backpic_t  cg02s_backpic;
	d_cg02s_goback_t  cg02s_goback;
	d_cg02s_cancel_t  cg02s_cancel;
	d_cg02s_machinestate_t cg02s_machinestate;
	d_cg02s_goodbillcoin_t cg02s_goodbillcoin;
	d_cg02s_pieceshow_t  cg02s_pieceshow;
	d_cg02s_waiter_t  cg02s_waiter;
	d_cg01s_jud5041_t  cg01s_jud5041;
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	/*if(plocalcg02->pageGraphElementsFlags == 0){
		cg02s_backpic.ShowBack1();
		cg02s_goback.ShowGoback();
		cg02s_pieceshow.ShowPieceButtBoard();
		cg02s_pieceshow.ShowPieceInfo();
		cg02s_pieceshow.ShowPayednchg();
		cg02s_cancel.Showcancel();
		cg02s_goodbillcoin.ShowValidMoneyType();
		cg02s_machinestate.ShowStatus();
		plocalcg02->pageGraphElementsFlags = 1;
		//SetLanguageCh();
	}*/
	
	a_waiter_t_rowtype  waiter_data; // 本窗体接收钱。记录收钱各币种的数量。 
	//de_coin_t coin_data;//主界面直接调用coin操作
	bu_quickflow_t::qf_counter_t  iQf1_user_idle;
	double iQf1_user_idleMAX = gp_db->m_a3003.GetRow(0).m_PutCoinWaitTimeSec;
	
	LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"m_PutCoinWaitTimeSec="<< wl::SStrf::sltoa(gp_db->m_a3003.GetRow(0).m_PutCoinWaitTimeSec) );
	gp_qf->GetQf( iQf1_user_idle );

	while(1)
	{
		if(plocalcg02->displayFlag == 0){
			if(plocalcg02->langFlag == 0){//
				for(int i = 0;i < plocalcg02->graphElementsCN.size();i++){
					if(plocalcg02->graphElementsCN[i].m_name == "CN_page2BackPic"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsCN[i].m_name == "CN_page2Goback--hot"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsCN[i].m_name == "CN_stationName" && plocalcg01->isFastFlag ==1){
						SetLanguageCh();
						gp_ui->updateLabel(plocalcg02->graphElementsCN[i], gp_db->GetThatStaName(gp_frontman_mgr->m_cg02.m_SelectedScNode) );
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphElementsCN[i].m_name == "currentTicketPrice"){
						gp_ui->updateLabel(plocalcg02->graphElementsCN[i],SStrf::sltoa( plocalcg02->m_iPrice ));
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphElementsCN[i].m_name == "choicePieceNum"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsCN[i].m_name == "shouldPay"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}		
					if(plocalcg02->graphElementsCN[i].m_name == "shouldChange"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						plocalcg02->shouldChangeIndex = i;
						continue;
					}				
					if(plocalcg02->graphElementsCN[i].m_name == "dealPayed"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						plocalcg02->payedIndex = i;
						continue;
					}
					if(plocalcg02->graphElementsCN[i].m_name == "CN_page2Cancel--hot"){
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;
					}					
					/*if(plocalcg02->graphElementsCN[i].m_name == "CN_exceptionNotesType"){
						plocalcg02->exceptNoteIndex = i;
						if(Rb8702.m_ConnState == 1 && Rb8702.m_BigErr == 0 && Rb8702.m_BillStopUseFlag == 0 && gp_bill->m_iIsNotBillChange == 1){
							gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
							plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
							continue;
						}
					}*/
					if(plocalcg02->graphElementsCN[i].m_name == "CN_NotesType"){
						plocalcg02->notesIndex = i;
						//SetLanguageCh();
						//gp_ui->updateLabel(plocalcg02->graphElementsCN[i],gp_db->GetVaildNotesType(waiter_data.m_TickePriceTotal));
						gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
						continue;

					}						
					/*if(plocalcg02->graphElementsCN[i].m_name == "CN_NormalNotesType"){
						plocalcg02->normalNoteIndex = i;
						if(Rb8702.m_ConnState == 1 && Rb8702.m_BigErr == 0 && Rb8702.m_BillStopUseFlag == 0){
							gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
							plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
							continue;
						}
					}	*/				
					if( Rb8701.m_ConnState == 1 && Rb8701.m_BigErr == 0 && Rb8701.m_CoinStopUseFlag == 0 ){
						if(plocalcg02->graphElementsCN[i].m_name == "CN_CoinType"){
							gp_ui->showLabel(plocalcg02->graphElementsCN[i]);
							plocalcg02->graphElementsCN[i].m_iShouldShow = 1;
							//plocalcg02->coinIndex = i;
							continue;
						}
					}
				}
				for(int i=0;i < plocalcg02->graphPieceNumCN.size();i++){
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumUp"){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumDn" && plocalcg02->graphPieceNumCN[i].m_funcvalue == m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumDigitUp" && plocalcg02->graphPieceNumCN[i].m_funcvalue != m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumDigitDn" && plocalcg02->graphPieceNumCN[i].m_funcvalue == m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}					
				}
			}
			if(plocalcg02->langFlag == 1){
				for(int i = 0;i < plocalcg02->graphElementsEN.size();i++){
					if(plocalcg02->graphElementsEN[i].m_name == "EN_page2BackPic"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsEN[i].m_name == "EN_page2Goback--hot"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsEN[i].m_name == "EN_stationName" && plocalcg01->isFastFlag ==1){
						SetLanguageEn();
						gp_ui->updateLabel(plocalcg02->graphElementsEN[i], gp_db->GetThatStaName(gp_frontman_mgr->m_cg02.m_SelectedScNode) );
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphElementsEN[i].m_name == "currentTicketPrice"){
						gp_ui->updateLabel(plocalcg02->graphElementsEN[i],SStrf::sltoa( plocalcg02->m_iPrice ));
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphElementsEN[i].m_name == "choicePieceNum"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphElementsEN[i].m_name == "shouldPay"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}		
					if(plocalcg02->graphElementsEN[i].m_name == "shouldChange"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						plocalcg02->shouldChangeIndex = i;
						continue;
					}				
					if(plocalcg02->graphElementsEN[i].m_name == "dealPayed"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						plocalcg02->payedIndex = i;
						continue;
					}
					if(plocalcg02->graphElementsEN[i].m_name == "EN_page2Cancel--hot"){
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;
					}					
					/*if(plocalcg02->graphElementsEN[i].m_name == "EN_exceptionNotesType"){
						plocalcg02->exceptNoteIndex = i;
						if(Rb8702.m_ConnState == 1 && Rb8702.m_BigErr == 0 && Rb8702.m_BillStopUseFlag == 0 && gp_bill->m_iIsNotBillChange == 1){
							gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
							plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
							continue;
						}
					}*/
					if(plocalcg02->graphElementsEN[i].m_name == "EN_NotesType"){
						plocalcg02->notesIndex = i;
						//SetLanguageEn();
						//gp_ui->updateLabel(plocalcg02->graphElementsEN[i],gp_db->GetVaildNotesType(waiter_data.m_TickePriceTotal));
						gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
						continue;

					}
					/*if(plocalcg02->graphElementsEN[i].m_name == "EN_NormalNotesType"){
						plocalcg02->normalNoteIndex = i;
						if(Rb8702.m_ConnState == 1 && Rb8702.m_BigErr == 0 && Rb8702.m_BillStopUseFlag == 0){
							gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
							plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
							continue;
						}
					}*/		
					if( Rb8701.m_ConnState == 1 && Rb8701.m_BigErr == 0 && Rb8701.m_CoinStopUseFlag == 0 ){
						if(plocalcg02->graphElementsEN[i].m_name == "EN_CoinType"){
							gp_ui->showLabel(plocalcg02->graphElementsEN[i]);
							plocalcg02->graphElementsEN[i].m_iShouldShow = 1;
							//plocalcg02->coinIndex = i;
							continue;
						}
					}
				}
				for(int i=0;i < plocalcg02->graphPieceNumEN.size();i++){
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumUp"){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}					
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumDn" && plocalcg02->graphPieceNumEN[i].m_funcvalue == m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumDigitUp" && plocalcg02->graphPieceNumEN[i].m_funcvalue != m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumDigitDn" && plocalcg02->graphPieceNumEN[i].m_funcvalue == m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}					
				}
			}
			plocalcg02->displayFlag = 1;
		}
		
		if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) break;

		//d_cg02s_backpic_t  cg02s_backpic;

		//cg02s_backpic.ShowBack1();

		//d_cg02s_goback_t  cg02s_goback;

		//cg02s_goback.ShowGoback();

		//d_cg02s_cancel_t  cg02s_cancel;

		//cg02s_cancel.Showcancel();
		//如果无纸币找零，则显示无纸币找零
		//d_cg02s_machinestate_t cg02s_machinestate;

		if( gp_bill->m_iIsNotBillChange == 1 )
		{
			cg02s_machinestate.ShowStatus();
		}

		//d_cg01s_evtcodes_t  cg01s_evtcodes;
		//d_cg02s_goodbillcoin_t cg02s_goodbillcoin;

// show about piece 
		//d_cg02s_pieceshow_t  cg02s_pieceshow;

		//cg02s_pieceshow.ShowPieceButtBoard();
		//cg02s_pieceshow.ShowPieceInfo();
		//cg02s_pieceshow.ShowPayednchg();
		cg02s_pieceshow.ActiveCoinBill();//激活硬币模块

		//d_cg02s_waiter_t  cg02s_waiter;


L_GETINPUT:
		//d_cg01s_jud5041_t  cg01s_jud5041;
		int irc(0);
		if(plocalcg02->langFlag == 0){
			SetLanguageCh();
			gp_ui->hideLabel(plocalcg02->graphElementsCN[plocalcg02->notesIndex]);
			gp_ui->updateLabel(plocalcg02->graphElementsCN[plocalcg02->notesIndex],gp_db->GetVaildNotesType(waiter_data.m_TickePriceTotal));
			gp_ui->showLabel(plocalcg02->graphElementsCN[plocalcg02->notesIndex]);
			plocalcg02->graphElementsCN[plocalcg02->notesIndex].m_iShouldShow = 1;

		}
		else if(plocalcg02->langFlag == 0){
			gp_ui->hideLabel(plocalcg02->graphElementsEN[plocalcg02->notesIndex]);
			gp_ui->updateLabel(plocalcg02->graphElementsEN[plocalcg02->notesIndex],gp_db->GetVaildNotesType(waiter_data.m_TickePriceTotal));
			gp_ui->showLabel(plocalcg02->graphElementsEN[plocalcg02->notesIndex]);
			plocalcg02->graphElementsEN[plocalcg02->notesIndex].m_iShouldShow = 1; 

		}

		//cg01s_evtcodes.ShowEvtCodes();
		//cg02s_goodbillcoin.ShowValidMoneyType();

		do
		{
			gp_frontinput->GetFrontNextKey();

			//投钱超时，
			if( gp_qf->IsLongQf( iQf1_user_idle , iQf1_user_idleMAX ) )
			{
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << " Throw  timeout ");

				//关闭纸币硬币投币口
				cg02s_pieceshow.StopCoinAndBill();

				//超时，有钱则退钱，没钱也退出
				gp_qf->GetQf( iQf1_user_idle );
				//add by jfren @20161122
				if(waiter_data.m_ReceiveBill >0)
				{
					gp_bill->dBill_Refund();//add by jfren @20161122
					waiter_data.m_ReceiveBill = 0;
					waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveCoin;
				}
				if(waiter_data.m_ReceiveCoin >0)
				{
					gp_coin->returnCoin();//退硬币
					waiter_data.m_ReceiveCoin = 0;
					waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveBill;
				}
				
				plocalcg01->displayFlag = 0;
				if(plocalcg02->langFlag == 0){
					plocalcg01->langFlag = 0;
				}
				else if(plocalcg02->langFlag == 1){
					plocalcg01->langFlag = 1;
				}
				plocalcg01->langFlag = 0;
				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
				gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
				gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
				
				if(plocalcg02->langFlag == 0){
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
				}
				else if(plocalcg02->langFlag == 1){
					//TODO
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
				}
				SetLanguageCh();
				return;
			}
		}while( gp_frontinput->GetFrontCurrentKey() == "" );

		if( cg02s_goback.Find_n_do_ShowGoback( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			//关闭纸币硬币投币口
			cg02s_pieceshow.StopCoinAndBill();

			//add by jfren @20161122
			if(waiter_data.m_ReceiveBill >0)
			{
				gp_bill->dBill_Refund();
				waiter_data.m_ReceiveBill = 0;
				waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveCoin;
			}

			if(waiter_data.m_ReceiveCoin >0)
			{
				gp_coin->returnCoin();//退硬币
				waiter_data.m_ReceiveCoin = 0;
				waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveBill;
			}
			//如果有投钱，则需要退钱，返回上一层界面	
			return;
		}

		if( cg02s_cancel.Find_n_do_Showcancel( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			//关闭纸币硬币投币口
			cg02s_pieceshow.StopCoinAndBill();

			//add by jfren @20161122
			if(waiter_data.m_ReceiveBill >0)
			{
				gp_bill->dBill_Refund();//add by jfren @20161122
				waiter_data.m_ReceiveBill = 0;
				waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveCoin;
			}
			if(waiter_data.m_ReceiveCoin >0)
			{
				gp_coin->returnCoin();//退硬币
				waiter_data.m_ReceiveCoin = 0;
				waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveBill;
			}
			return;
		}

		if( cg02s_pieceshow.Find_n_do_ShowAllPieceNum( gp_frontinput->GetFrontCurrentKey() ) ) 
		{
			gp_qf->GetQf( iQf1_user_idle );//retime when any button clicked
			//点击张数，动态切换可接受纸币(50元)
			goto L_GETINPUT;
		}

	
		irc = cg02s_pieceshow.FnD_ShowNewValue( gp_frontinput->GetFrontCurrentKey() , &waiter_data ); //1=钱已够 

		if( irc == 2 )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "FnD_ShowNewValue irc = 2");
			//表示有投钱，将超时清除，重新记超时
			gp_qf->GetQf( iQf1_user_idle );
		}
		if( irc == 1 )
		{
			//d_cg02s_waiter_t  cg02s_waiter;
			plocalcg01->isFastFlag = 0;
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "处理找零和出票");

			//钱足够，开始关闭纸币、硬币投币口
			cg02s_pieceshow.StopCoinAndBill();
 
			irc = cg02s_waiter.FnD_WaiterJob( gp_frontinput->GetFrontCurrentKey() , &waiter_data ); // 处理找零和出票 内有getinput 
			if( 0 != irc )
			{
				//交易失败，暂停服务

				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
				plocalcg01->displayFlag = 0;
				plocalcg01->langFlag = 0;
				gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
				gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
				
				if(plocalcg02->langFlag == 0){
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
				}
				else if(plocalcg02->langFlag == 1){
					//TODO
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
				}
				SetLanguageCh();
			}
			return;
		}

		/*int ret = 0;
		if( ret = cg01s_jud5041.Find_n_do_stopservice(gp_frontinput->GetFrontCurrentKey()) )
		{
			//如果有投钱，则退钱 或 列印异常交易
			if(ret == 2){
				plocalcg01->displayFlag = 0;
				plocalcg01->langFlag = 0;
				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
			}
			else if(ret == 1){
				plocalcg04->displayFlag = 0;
				plocalcg04->langFlag = 0;
				gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg04;
			}

			if(plocalcg02->langFlag == 0){
				plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);	
			}
			else if(plocalcg02->langFlag == 1){
				//TODO
				plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
			}

			return;
		}	*/
		goto L_GETINPUT;
	}

	return;
}
