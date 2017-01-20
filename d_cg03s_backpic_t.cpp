
#include "2.h"
#include "d_cg03s_backpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "d_cg03_t.h"



//
d_cg03s_backpic_t::d_cg03s_backpic_t()
{
}


//
d_cg03s_backpic_t::~d_cg03s_backpic_t()
{
}


//
void d_cg03s_backpic_t::ShowBack1()
{
	std::string ShowBack1NAME = GETLABELNAME;
	const char *s[] = { "cg03_back_ch.jpg", "cg03_back_en.jpg" };
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;

	gp_ui->LabelMkPic( row, 0, "CN_thirdBackPic", 
						gp_ui->PicPFn( s[0] ), 0, 0, 1, 1 );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "CN_page3BackPic";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);
	gp_ui->pic_task(row);
	plocalcg03->graphElementsCN.push_back(row);

	gp_ui->LabelMkPic( row1, 0, "EN_thirdBackPic", 
						gp_ui->PicPFn( s[1] ), 0, 0, 1, 1 );
	gp_ui->CalcPicX2Y2(row1);
	row1.m_hot = 0;
	row1.m_funcname = "EN_page3BackPic";
	row1.m_funcvalue = 1;
	this->AddLg( m_Lg, row1 );
	gp_ui->LabelPrep(row1);
	gp_ui->pic_task(row1);
	plocalcg03->graphElementsEN.push_back(row1);

	//gp_ui->LabelCommit();
}



