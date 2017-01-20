
#include "2.h"
#include "d_cg01s_rightupmsg_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "bu_timeshower_t.h"


//
d_cg01s_rightupmsg_t::d_cg01s_rightupmsg_t()
{
}


//
d_cg01s_rightupmsg_t::~d_cg01s_rightupmsg_t()
{
	gp_timeshower->SetSType( bu_timeshower_t::HIDE );
}


//
void d_cg01s_rightupmsg_t::Showrightupmsg()
{
	std::string strNAME = GETLABELNAME;
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;

	gp_ui->LabelMkStr( row, 0, "CN_StaName", gp_db->GetMyStaName(), 0.868750,0.110750, 0.038, "black" );
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);
	gp_ui->str_task(row);
	plocalcg01->graphElementsCN.push_back(row);

	SetLanguageEn();
	gp_ui->LabelMkStr( row1, 0, "EN_StaName", gp_db->GetMyStaName(), 0.896875,0.125000, 0.022, "black" );
	this->AddLg( m_Lg, row1 );
	gp_ui->LabelPrep(row1);
	gp_ui->str_task(row1);
	plocalcg01->graphElementsEN.push_back(row1);

}


