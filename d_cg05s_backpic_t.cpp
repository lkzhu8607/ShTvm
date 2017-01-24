
#include "2.h"
#include "d_cg05s_backpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "d_cg05_t.h"


//
d_cg05s_backpic_t::d_cg05s_backpic_t()
{
}


//
d_cg05s_backpic_t::~d_cg05s_backpic_t()
{
}


//
void d_cg05s_backpic_t::ShowBack1()
{
	std::string ShowBack1NAME = GETLABELNAME;
	const char *s[] = { "main.jpg", "maine.jpg" };
	if(1){
		a_label_t::ROWTYPE  row;

		gp_ui->LabelMkPic( row, 0, "CN_page5BackPic", 
							gp_ui->PicPFn( s[0] ), 0, 0, 1, 1 );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "page5BackPic";
		row.m_funcvalue = 0;
		this->AddLg( m_Lg, row );

		//gp_ui->LabelMkDelPrep( ShowBack1NAME );

		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg05->graphElementsCN.push_back(row);
	}
	if(1){
		a_label_t::ROWTYPE  row;

		gp_ui->LabelMkPic( row, 0, "EN_page5BackPic", 
							gp_ui->PicPFn( s[1] ), 0, 0, 1, 1 );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "page5BackPic";
		row.m_funcvalue = 0;
		this->AddLg( m_Lg, row );

		//gp_ui->LabelMkDelPrep( ShowBack1NAME );

		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg05->graphElementsEN.push_back(row);
	}	
	//gp_ui->LabelCommit();
}



