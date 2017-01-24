
#include "2.h"
#include "d_cg03s_lang_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "d_cg03_t.h"



//
d_cg03s_lang_t::d_cg03s_lang_t()
{
}


//
d_cg03s_lang_t::~d_cg03s_lang_t()
{
}



//
void d_cg03s_lang_t::ShowLangButt()
{
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;

	gp_ui->LabelMkPic( row, 0, 
						"CN_page3LangButton", 
						"" , 
						gp_ui->X2dR( 0, 1051 ), 
						gp_ui->Y2dR( 0, 23 ), 
						gp_ui->X2dR( 0, 1226 - 1051 ), 
						gp_ui->Y2dR( 0, 82 - 23 )   );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 1;
	row.m_funcname = "CN_LangButt";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );
	gp_ui->pic_task(row);
	plocalcg03->graphElementsCN.push_back(row);

	gp_ui->LabelMkPic( row1, 0, 
						"EN_page3LangButton", 
						"" , 
						gp_ui->X2dR( 0, 1051 ), 
						gp_ui->Y2dR( 0, 23 ), 
						gp_ui->X2dR( 0, 1226 - 1051 ), 
						gp_ui->Y2dR( 0, 82 - 23 )   );
	gp_ui->CalcPicX2Y2(row1);
	row1.m_hot = 1;
	row1.m_funcname = "EN_LangButt";
	row1.m_funcvalue = 1;
	this->AddLg( m_Lg, row1 );
	gp_ui->pic_task(row1);
	plocalcg03->graphElementsEN.push_back(row1);	
}


//
tbool d_cg03s_lang_t::Find_n_do_ShowLangButt( std::string strinput )
{
	a_label_t::ROWTYPE  row;

	if( this->LgFindhot( m_Lg, strinput, row ) )
	{
		if( row.m_funcname == "ShowLangButt" )
		{
			if( row.m_funcvalue == 0 )
				SetLanguageEn();
			else
				SetLanguageCh();
	
			return 1;
		}
	}

	return 0;
}


