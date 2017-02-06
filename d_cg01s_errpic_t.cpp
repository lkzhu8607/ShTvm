
#include "2.h"
#include "d_cg01s_errpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"


//
d_cg01s_errpic_t::d_cg01s_errpic_t()
{
}


//
d_cg01s_errpic_t::~d_cg01s_errpic_t()
{
}


//
void d_cg01s_errpic_t::Show()
{
	std::string ShowBack1NAME = GETLABELNAME;
	const char *s[] = { "u5_dark_rect.jpg", "u5_dark_rect.jpg" };
	
	a_label_t::ROWTYPE	row;
	
	gp_ui->LabelMkPic( row, 0, "errPic", 
						gp_ui->PicPFn( s[GetLanguageState()] ), 0.133750, 0.198333, 0.672500, 0.600000 );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "errorPicShow";
	row.m_funcvalue = 0;
	gp_ui->LabelPrep(row);
	plocalcg01->graphElementsCN.push_bak(row);	

}
