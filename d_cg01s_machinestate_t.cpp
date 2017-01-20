
#include "2.h"
#include "d_cg01s_machinestate_t.h"
#include "d_cg01_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "de_medev_t.h"


//
d_cg01s_machinestate_t::d_cg01s_machinestate_t()
{
	//m_x = 0.829688;
	m_x = 0.858758;
	m_y = 0.142917;
}


//
d_cg01s_machinestate_t::~d_cg01s_machinestate_t()
{
}


//
void d_cg01s_machinestate_t::Showmachinestate()
{
	std::string strNAME = GETLABELNAME;
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;

	//gp_ui->LabelMkStr( row, 0, strNAME, GetStrRes(SR_IN_SERVICE), m_x,m_y, 0.038, "black" );
	gp_ui->LabelMkStr( row, 0, "CN_MachineState", GetStrRes(gp_medev->m_devstatus), m_x,m_y, 0.038, "black" );
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);
	gp_ui->str_task(row);
	plocalcg01->graphElementsCN.push_back(row);


	gp_ui->LabelMkStr( row1, 0, "EN_MachineState", GetStrRes(gp_medev->m_devstatus), m_x,m_y, 0.038, "black" );
	this->AddLg( m_Lg, row1 );
	gp_ui->LabelPrep(row1);	
	gp_ui->str_task(row1);
	plocalcg01->graphElementsEN.push_back(row1);
	//gp_ui->LabelCommit();
}


