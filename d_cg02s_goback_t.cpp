
#include "2.h"
#include "d_cg02s_goback_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"


//
d_cg02s_goback_t::d_cg02s_goback_t()
{
}


//
d_cg02s_goback_t::~d_cg02s_goback_t()
{
}


//
void d_cg02s_goback_t::ShowGoback()
{
	const char *s[] = { "cg02_goback_ch.png", "cg02_goback_en.png" ,"goback_blank.jpg"};
	a_label_t::ROWTYPE  row[2];
	std::string picName;
	std::string strName;
	//图片显示 
	for(int i=0;i<2;i++){
		if(i==0){
			picName = gp_ui->PicPFn( s[i] );
			strName = "CN_page2Goback";
		}
		else if(i==1){
			picName = gp_ui->PicPFn( s[i] ) ;
			strName = "EN_page2Goback";
		}
		gp_ui->LabelMkPic( row[i], 0, 
							/*GETLABELNAME*/strName , 
							/*gp_ui->PicPFn( s[GetLanguageState()] )*/ picName,
							gp_ui->X2dR( 0, 800 ) , 
							gp_ui->Y2dR( 0, 930 ) , 
							gp_ui->X2dR( 0, 200 ) , 
							gp_ui->Y2dR( 0, 70 )   );
		gp_ui->CalcPicX2Y2(row[i]);
		row[i].m_funcname = "page2Goback";
		row[i].m_funcvalue = i;

		//热点注册	
		row[i].m_name += "--hot";
		row[i].m_hot = 1;
		//this->AddLg( m_Lg, row[i] );
		//gp_ui->LabelPrep(row[i]);
		gp_ui->pic_task(row[i]);
		if(i==0){
			plocalcg02->graphElementsCN.push_back(row[i]);
		}
		else if(i==1){
			plocalcg02->graphElementsEN.push_back(row[i]);
		}		
	}
/*	if(1){
		a_label_t::ROWTYPE	row;
		gp_ui->LabelMkPic( row, 0, 
							"coverGoback" , 
							gp_ui->PicPFn( s[2] ),
							gp_ui->X2dR( 0, 800 ) , 
							gp_ui->Y2dR( 0, 915 ) , 
							gp_ui->X2dR( 0, 200 ) , 
							gp_ui->Y2dR( 0, 70 )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_funcname = "page2CoverGoback";
		row.m_funcvalue = 0;

		//热点注册	
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row[i]);
		gp_ui->pic_task(row);
		plocalcg02->graphElementsCN.push_back(row);
		plocalcg02->graphElementsEN.push_back(row);

	}*/

	//gp_ui->LabelCommit();
}


//
tbool d_cg02s_goback_t::Find_n_do_ShowGoback( std::string strinput )
{
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	std::vector<a_label_t::ROWTYPE>  row;
	if(Rb8701.m_CoinPollData.a[0] + Rb8701.m_CoinPollData.a[1] + Rb8702.m_cNoteNum != 0){
		return 0;
	}
	if(plocalcg02->langFlag == 0){
		if( this->LocateHot( plocalcg02->graphElementsCN, strinput, row ) ){
			for(int i=0;i<row.size();i++){
				if(row[i].m_name == "CN_page2Goback--hot"){
					if(gp_frontman_mgr->m_cg03.m_iLineCode <= 10){
						plocalcg01->pageFlag = 1;
					}
					else 
						plocalcg01->pageFlag = 0;
					plocalcg02->m_iPieceNum = 1;
					if(plocalcg01->isFastFlag ==1 && plocalcg01->mianClickStationFlag ==0){
						//plocalcg02->gobackFlag = 1;
						plocalcg03->displayFlag = 0;
						plocalcg03->langFlag = 0;	
						gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg03;	
					}
					else{
						plocalcg01->displayFlag = 0;
						plocalcg01->langFlag = 0;	
						plocalcg01->errorFlag = 0;
						gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
					}
					gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
					gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;					

					plocalcg01->mianClickStationFlag = 0;
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
					return 1;
				}
			}
		}
	}
	else if(plocalcg02->langFlag == 1){
		if( this->LocateHot( plocalcg02->graphElementsEN, strinput, row ) ){
			for(int i=0;i<row.size();i++){
				if(row[i].m_name == "EN_page2Goback--hot"){
					if(gp_frontman_mgr->m_cg03.m_iLineCode <= 10){
						plocalcg01->pageFlag = 1;
					}
					else 
						plocalcg01->pageFlag = 0;
					plocalcg02->m_iPieceNum = 1;
					if(plocalcg01->isFastFlag ==1 && plocalcg01->mianClickStationFlag ==0){
						//plocalcg02->gobackFlag = 1;
						plocalcg03->displayFlag = 0;
						plocalcg03->langFlag = 1;	
						gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg03;	
					}
					else{
						plocalcg01->displayFlag = 0;
						plocalcg01->langFlag = 0;	
						plocalcg01->errorFlag = 0;
						gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
					}						
					plocalcg01->mianClickStationFlag = 0;
					gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
					gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;	
					plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
					return 1;
				}
			}
		}
	}
	//plocalcg01->isFastFlag = 1;
	return 0;
}




