#include "2.h"
#include "cg02s_machinestate_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"

//
d_cg02s_machinestate_t::d_cg02s_machinestate_t()
{
	m_x = 0.416667;
	m_y = 0.032209;
}


//
d_cg02s_machinestate_t::~d_cg02s_machinestate_t()
{
}

void d_cg02s_machinestate_t::ShowStatus()
{
	std::string strNAME = GETLABELNAME;
	if(1){
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "CN_page2MachineState", "无纸币找零", m_x,m_y, 0.038, "black" );
		this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
	}
	if(1){
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "EN_page2MachineState", "No Notes for Change", m_x,m_y, 0.038, "black" );
		this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsEN.push_back(row);
	}
	//gp_ui->LabelCommit();
}