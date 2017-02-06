
#include "2.h"
#include "d_cg01s_errexplain_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "de_medev_t.h"


//
d_cg01s_errexplain_t::d_cg01s_errexplain_t()
{
}


//
d_cg01s_errexplain_t::~d_cg01s_errexplain_t()
{
}


//
void d_cg01s_errexplain_t::Show()
{

	std::string strNAME = GETLABELNAME;
	a_label_t::ROWTYPE  row2;

	SetLanguageEn();
	gp_ui->LabelMkStr( row2, 0, "EN_ErrorDetail", GetStrRes( gp_medev->m_outofservicestatus ), 0.288752,0.418333, 0.186, "red" );
	gp_ui->LabelPrep(row2);
	plocalcg01->graphElementsEN.push_bak(row2);

	a_label_t::ROWTYPE  row1;
	SetLanguageCh();
	gp_ui->LabelMkStr( row1, 0, "CN_ErrorDetail", GetStrRes( gp_medev->m_outofservicestatus ), 0.288752,0.418333, 0.186, "red" );
	gp_ui->LabelPrep(row1);
	plocalcg01->graphElementsCN.push_bak(row1);	
	//gp_ui->LabelCommit();

}
