
#include "2.h"
#include "d_cg04s_backpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg04_t.h"


//
d_cg04s_backpic_t::d_cg04s_backpic_t()
{
}


//
d_cg04s_backpic_t::~d_cg04s_backpic_t()
{
}


//
void d_cg04s_backpic_t::ShowBack1()
{
	std::string ShowBack1NAME = GETLABELNAME;
	const char *s[] = { "outofservice.jpg", "outofservice.jpg" };
	a_label_t::ROWTYPE  row;

	gp_ui->LabelMkPic( row, 0, "outOfServiceBackPic", 
						gp_ui->PicPFn( s[0] ), 0, 0, 1, 1 );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "page4OutofService";
	row.m_funcvalue = 0;
	//this->AddLg( m_Lg, row );
	//gp_ui->LabelPrep(row);
	gp_ui->pic_task(row);
	plocalcg04->graphElementsCN.push_back(row);
	plocalcg04->graphElementsEN.push_back(row);
	//gp_ui->LabelCommit();
}
