
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

	//int iShowidx = 4;
	//if( gp_db->m_a5041.GetRow(0).m_e.a[113] )    
	//{
	//	iShowidx = 9;
	//}
	gp_ui->LabelMkStr( row2, 0, strNAME, GetStrRes( gp_medev->m_outofservicestatus ), 0.288752,0.418333, 0.186, "red" );
	this->AddLg( m_Lg, row2 );
	gp_ui->LabelPrep(row2);
	gp_ui->LabelCommit();

}
