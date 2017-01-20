
#include "2.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg01_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "de_medev_t.h"



//
d_cg01s_evtcodes_t::d_cg01s_evtcodes_t()
{
	m_x = 0.02;
}


//
d_cg01s_evtcodes_t::~d_cg01s_evtcodes_t()
{
}


//
void d_cg01s_evtcodes_t::ShowEvtCodes()
{
	std::string strNAME = GETLABELNAME;
	a_label_t::ROWTYPE  row;

	gp_ui->LabelMkStr( row, 0, "page1ErrCode", gp_medev->GetEvtStr(), m_x, 0.8761, 0.03, "black" );
	row.m_font_align = 0;
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);
	gp_ui->str_task(row);
	plocalcg01->graphElementsCN.push_back(row);
	plocalcg01->graphElementsEN.push_back(row);	
	//gp_ui->LabelCommit();
}



