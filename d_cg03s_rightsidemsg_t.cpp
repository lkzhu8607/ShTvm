
#include "2.h"
#include "d_cg03s_rightsidemsg_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "bu_timeshower_t.h"
#include "d_cg03_t.h"


//
d_cg03s_rightsidemsg_t::d_cg03s_rightsidemsg_t()
{
}


//
d_cg03s_rightsidemsg_t::~d_cg03s_rightsidemsg_t()
{
	gp_timeshower->SetSType( bu_timeshower_t::HIDE );
}


//
void d_cg03s_rightsidemsg_t::Showrightsidemsg()
{
	std::string strNAME = GETLABELNAME;
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;
	gp_ui->LabelMkStr( row, 0, "CN_page3UpRightMsg", gp_db->GetMyStaName(), 0.870000,0.18940, 0.041, "black" );
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);
	gp_ui->str_task(row1);
	plocalcg03->graphElementsCN.push_back(row);

	gp_ui->LabelMkStr( row1, 0, "EN_page3UpRightMsg", gp_db->GetMyStaName(), 0.890000,0.200000, 0.022, "black" );
	this->AddLg( m_Lg, row1 );
	gp_ui->LabelPrep(row1);
	gp_ui->str_task(row1);
	plocalcg03->graphElementsEN.push_back(row1);	
	/*if( GetLanguageState() == 0 ) 
	{
		gp_ui->LabelMkStr( row, 0, strNAME, gp_db->GetMyStaName(), 0.870000,0.18940, 0.041, "black" );
	}
	else
	{
		gp_ui->LabelMkStr( row, 0, strNAME, gp_db->GetMyStaName(), 0.890000,0.200000, 0.022, "black" );
	}*/
	//gp_timeshower->SetSType( bu_timeshower_t::DATE );
}


