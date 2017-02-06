
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
	const char *s[] = { "cg02_goback_ch.png", "cg02_goback_en.png" };
	a_label_t::ROWTYPE  row[2];
	std::string picName;
	std::string strName;
	//Õº∆¨œ‘ æ 
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

		//»»µ„◊¢≤·	
		row[i].m_name += "--hot";
		row[i].m_hot = 1;
		this->AddLg( m_Lg, row[i] );
		gp_ui->LabelPrep(row[i]);
		gp_ui->pic_task(row[i]);
		if(i==0){
			plocalcg02->graphElementsCN.push_back(row[i]);
		}
		else if(i==1){
			plocalcg02->graphElementsEN.push_back(row[i]);
		}		
	}

	//gp_ui->LabelCommit();
}


//
tbool d_cg02s_goback_t::Find_n_do_ShowGoback( std::string strinput )
{
	/*a_label_t::ROWTYPE  row;

	//gp_ui->LabelMkPic( row, 0, GETLABELNAME , gp_ui->PicPFn("tmpx.png") , 0 , 0 , 1 , 1 );
	//gp_ui->LabelCommit();

	if( this->LgFindhot( m_Lg, strinput, row ) )
	{
		if( row.m_funcname == "ShowGoback" )
		{
			//other process
			gp_frontman_mgr->m_pcg = plocalcg02->m_pLastCg;

			return 1;
		}
	}*/
		std::vector<a_label_t::ROWTYPE>  row;
		if( this->LocateHot( plocalcg02->graphElementsCN, strinput, row ) ){
			if(plocalcg02->langFlag == 0)
			{
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
				for(int i=0;i<row.size();i++){
					if(row[i].m_name == "CN_page2Goback--hot"){
						plocalcg01->displayFlag = 0;
						plocalcg01->langFlag = 0;	
						gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;		
						gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
						gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;	
						return 1;
					}
				}
			}		
			if(plocalcg02->langFlag == 1){
				for(int i=0;i<row.size();i++){
					if(row[i].m_name == "EN_page2Goback--hot"){
						return 1;
					}
				}
			}
		}
	return 0;
}




