
#include "2.h"
#include "d_cg01s_lang_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "bu_timeshower_t.h"

//
d_cg01s_lang_t::d_cg01s_lang_t()
{
}


//
d_cg01s_lang_t::~d_cg01s_lang_t()
{
}



//
void d_cg01s_lang_t::ShowLangButt()
{
	a3083_t::ROWTYPE  row3083;

	gp_db->get3083row( row3083, plocalcg01->m_cg01s_linepic_MainUiIdx );

	//if( !row3083.m_biIsAffect )
		//return;

	a_label_t::ROWTYPE  row;
	std::string strpic[2];

	strpic[0] = row3083.m_MainUiPicFn;
	strpic[1] = "e" + strpic[0];

	gp_ui->LabelMkPic( row, 0, 
						"LangButton",
						gp_ui->PicPFn(strpic[0]), 
						gp_ui->X2dR( 0, row3083.m_LaunSeleButtX ), 
						gp_ui->Y2dR( 0, row3083.m_LaunSeleButtY - 17 ), // 实际观察发现有点错位，修正17个。 
						gp_ui->X2dR( 0, row3083.m_LaunSeleButtWidth ), 
						gp_ui->Y2dR( 0, row3083.m_LaunSeleButtHeight )   );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 1;
	row.m_funcname = "ShowLangButt";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );
	//gp_ui->LabelPrep(row);
	//gp_ui->pic_task(row);
	plocalcg01->graphElementsCN.push_back(row);
	plocalcg01->graphElementsEN.push_back(row);
}


//
tbool d_cg01s_lang_t::Find_n_do_ShowLangButt( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	plocalcg01->displayFlag = 0;
	if(plocalcg01->langFlag == 0){
		if( this->LocateHot( plocalcg01->graphElementsEN, strinput, row ) )
		{
			for(int j=0;j<row.size();j++){
				if( row[j].m_funcname == "ShowLangButt")
				{
					plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
					plocalcg01->langFlag = 1;		
					return 1;
				}			
			}
		}
	}
	else if(plocalcg01->langFlag == 1){
		if( this->LocateHot( plocalcg01->graphElementsEN, strinput, row ) )
		{
			for(int j=0;j<row.size();j++){
				if( row[j].m_funcname == "ShowLangButt")
				{
					plocalcg01->cg01_graphElementsHide(plocalcg01->langFlag);
					plocalcg01->langFlag = 0;		
					return 1;
				}			
			}
		}
	}
	return 0;
}


