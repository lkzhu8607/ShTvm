
#include "2.h"
#include "d_cg02s_backpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"


//
d_cg02s_backpic_t::d_cg02s_backpic_t()
{
}


//
d_cg02s_backpic_t::~d_cg02s_backpic_t()
{
}


//
void d_cg02s_backpic_t::ShowBack1()
{
	const char *s[] = { "cg02_back_ch.png", "cg02_back_en.png" };
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row2;

	//Õº∆¨œ‘ æ 
	for(int i = 0;i<2;i++){
		a_label_t::ROWTYPE  row1;
		std::string strName;
		if(i==0){
			strName = "CN_page2BackPic";
			row1.m_funcvalue = 0;
		}
		else if(i==1){
			strName = "EN_page2BackPic";
			row1.m_funcvalue = 1;
		}		
		gp_ui->LabelMkPic( row1, 0, 
							strName , 
							gp_ui->PicPFn( s[i] ) ,
							0 , 
							0 , 
							1 , 
							1   );
		gp_ui->CalcPicX2Y2(row1);
		row1.m_hot = 0;
		row1.m_funcname = "ShowBack1";
		row1.m_funcvalue = 0;
		this->AddLg( m_Lg, row1 );
		gp_ui->LabelPrep(row1);
		gp_ui->pic_task(row1);
		if(i==0){
			plocalcg02->graphElementsCN.push_back(row1);
		}
		else if(i==1){
			plocalcg02->graphElementsEN.push_back(row1);
		}			
	}

	//◊÷∑˚¥Æœ‘ æ °™°™≥µ’æ 
	if( plocalcg02->m_SelectedScNode != u8arr_t<4>() )
	{
		//int LangFlag = GetLanguageState();
		//SetLanguageCh();
		gp_ui->LabelMkStr( row2, 0, 
							"stationName",
							gp_db->GetThatStaName(plocalcg02->m_SelectedScNode) , 
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 220 ), 
							0.06, 
							"black" );
		row2.m_hot = 0;
		this->AddLg( m_Lg, row2 );
		gp_ui->LabelPrep(row2);
		gp_ui->str_task(row2);
		plocalcg02->graphElementsCN.push_back(row2);
		plocalcg02->graphElementsEN.push_back(row2);		
	}

	//◊÷∑˚¥Æœ‘ æ °™°™µ•º€‘™  
	if( 1 )
	{
		a_label_t::ROWTYPE  row3;
		gp_ui->LabelMkStr( row3, 0, 
							"currentTicketPrice",
							SStrf::sltoa( plocalcg02->m_iPrice ) , 
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 280 ), 
							0.061, 
							"black" );
		row3.m_hot = 0;
		this->AddLg( m_Lg, row3 );
		gp_ui->LabelPrep(row3);
		gp_ui->str_task(row3);
		plocalcg02->graphElementsCN.push_back(row3);
		plocalcg02->graphElementsEN.push_back(row3);
	}
}



