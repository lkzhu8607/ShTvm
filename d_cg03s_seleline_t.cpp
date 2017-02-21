
#include "2.h"
#include "d_cg03s_seleline_t.h"
#include "d_cg01_t.h"
#include "d_cg03_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_timeshower_t.h"


//
d_cg03s_seleline_t::d_cg03s_seleline_t()
{
}


//
d_cg03s_seleline_t::~d_cg03s_seleline_t()
{
}

//
tbool d_cg03s_seleline_t::Find_n_do_seleline( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	plocalcg01->isFastFlag = 1;
	int line = gp_frontman_mgr->m_cg03.m_iLineCode;
	if(plocalcg03->langFlag == 0){
		if( this->LocateHot( plocalcg01->graphLineButtonCN, strinput, row ) )
		{
			//gp_frontman_mgr->graphLastPageElements.clear();
			for(int j=0;j<row.size();j++){
				if(row[j].m_funcname == "CN_SeleLine" && row[j].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg03->graphLineStationCN[plocalcg03->lineIndex][0]);
					plocalcg03->graphLineStationCN[plocalcg03->lineIndex][0].m_iShouldShow = 0;
					for(int i = 0;i<plocalcg03->lineCount;i++){
						if(plocalcg03->graphLineStationCN[i][0].m_funcvalue == row[j].m_funcvalue){
							//gp_ui->pic_task(plocalcg03->graphLineStationCN[i][0]);
							gp_ui->showLabel(plocalcg03->graphLineStationCN[i][0]);
							plocalcg03->graphLineStationCN[i][0].m_iShouldShow = 1;
							plocalcg03->lineIndex = i;		
							gp_frontman_mgr->m_cg03.m_iLineCode = row[j].m_funcvalue;
							return 1;
						}
					}
				}
			}
		}
	}
	else if(plocalcg03->langFlag == 1){
		if( this->LocateHot( plocalcg01->graphLineButtonEN, strinput, row ) )
		{
			//gp_frontman_mgr->graphLastPageElements.clear();
			for(int j=0;j<row.size();j++){
				if(row[j].m_funcname == "EN_SeleLine" && row[j].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg03->graphLineStationEN[plocalcg03->lineIndex][0]);
					plocalcg03->graphLineStationEN[plocalcg03->lineIndex][0].m_iShouldShow = 0;
					for(int i = 0;i<plocalcg03->lineCount;i++){
						if(plocalcg03->graphLineStationEN[i][0].m_funcvalue == row[j].m_funcvalue){
							//gp_ui->pic_task(plocalcg03->graphLineStationEN[i][0]);
							gp_ui->showLabel(plocalcg03->graphLineStationEN[i][0]);
							plocalcg03->graphLineStationEN[i][0].m_iShouldShow = 1;
							plocalcg03->lineIndex = i;		
							gp_frontman_mgr->m_cg03.m_iLineCode = row[j].m_funcvalue;
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}