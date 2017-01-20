
#include "2.h"
#include "d_cg02s_cancel_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"


//
d_cg02s_cancel_t::d_cg02s_cancel_t()
{
}


//
d_cg02s_cancel_t::~d_cg02s_cancel_t()
{
}


//
void d_cg02s_cancel_t::Showcancel()
{
	const char *s[] = { "cg02_cancel_ch.png", "cg02_cancel_en.png" };
	a_label_t::ROWTYPE  row[2];
	std::string picName;
	std::string strName;
	//Õº∆¨œ‘ æ 
	for(int i=0;i<2;i++){
		if(i==0){
			picName = gp_ui->PicPFn( s[i] );
			strName = "CN_page2Cancel";
		}
		else if(i==1){
			picName = gp_ui->PicPFn( s[i] ) ;
			strName = "EN_page2Cancel";
		}	
		gp_ui->LabelMkPic( row[i], 0, 
							/*GETLABELNAME*/strName , 
							/*gp_ui->PicPFn( s[GetLanguageState()] )*/picName ,
							gp_ui->X2dR( 0, 1053 ) , 
							gp_ui->Y2dR( 0, 930 ) , 
							gp_ui->X2dR( 0, 200 ) , 
							gp_ui->Y2dR( 0, 70 )   );
		gp_ui->CalcPicX2Y2(row[i]);
		row[i].m_funcname = "Showcancel";
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
tbool d_cg02s_cancel_t::Find_n_do_Showcancel( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	if(plocalcg02->langFlag == 0){
		if( this->LocateHot( plocalcg02->graphElementsCN, strinput, row ) )
		{
			for(int i=0;i<row.size();i++){
				if(row[i].m_name == "CN_page2Cancel--hot"){
					return 1;
				}
			}
		}
	}
	if(plocalcg02->langFlag == 1){
		if( this->LocateHot( plocalcg02->graphElementsCN, strinput, row ) )
		{
			for(int i=0;i<row.size();i++){
				if(row[i].m_name == "EN_page2Cancel--hot"){
					return 1;
				}
			}
		}
	}
	return 0;
}




