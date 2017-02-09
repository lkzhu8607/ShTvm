
#include "2.h"
#include "d_cg03s_goback_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_timeshower_t.h"


//
d_cg03s_goback_t::d_cg03s_goback_t()
{
}


//
d_cg03s_goback_t::~d_cg03s_goback_t()
{
}


//
void d_cg03s_goback_t::ShowGoback()
{
	const char *s[] = { "cg02_goback_ch.png", "cg02_goback_en.png" };
	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;

	//热点注册	
	gp_ui->LabelMkPic( row, 0, 
						"CN_page3GoBack" , 
						"" ,
						gp_ui->X2dR( 0, 1040 ) , 
						gp_ui->Y2dR( 0, 739 ) , 
						gp_ui->X2dR( 0, 1235 - 1040 ) , 
						gp_ui->Y2dR( 0, 800 - 739 )   );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 1;
	row.m_funcname = "CN_page3Goback";
	row.m_funcvalue = 0;
	//this->AddLg( m_Lg, row );
	gp_ui->pic_task(row);
	plocalcg03->graphElementsCN.push_back(row);

	//热点注册	
	gp_ui->LabelMkPic( row1, 0, 
						"EN_page3GoBack" , 
						"" ,
						gp_ui->X2dR( 0, 1040 ) , 
						gp_ui->Y2dR( 0, 739 ) , 
						gp_ui->X2dR( 0, 1235 - 1040 ) , 
						gp_ui->Y2dR( 0, 800 - 739 )   );
	gp_ui->CalcPicX2Y2(row1);
	row1.m_hot = 1;
	row1.m_funcname = "EN_page3Goback";
	row1.m_funcvalue = 0;
	//this->AddLg( m_Lg, row1 );
	gp_ui->pic_task(row1);
	plocalcg03->graphElementsEN.push_back(row1);	
}


//
tbool d_cg03s_goback_t::Find_n_do_ShowGoback( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	if( this->LocateHot( plocalcg03->graphElementsCN, strinput, row ) )
	{
		if(plocalcg03->langFlag == 0){
			for(int i = 0;i<row.size();i++){
				if( row[i].m_funcname == "CN_page3Goback" )
				{
					//other process
					/*for(int j=0;j<plocalcg03->graphElementsCN.size();j++){
						if(plocalcg03->graphElementsCN[j].m_iShouldShow == 1){
							gp_ui->hideLabel(plocalcg03->graphElementsCN[j]);
							plocalcg03->graphElementsCN[j].m_iShouldShow = 0;
						}
					}
					for(int j=0;j<plocalcg01->graphLineButtonCN.size();j++){
						if(plocalcg01->graphLineButtonCN[j].m_iShouldShow == 1){
							gp_ui->hideLabel(plocalcg01->graphLineButtonCN[j]);
							plocalcg01->graphLineButtonCN[j].m_iShouldShow = 0;
						}
					}
					for(int j=0;j<gp_timeshower->graphElements.size();j++){
						if(gp_timeshower->graphElements[j].m_iShouldShow == 1){
							gp_ui->hideLabel(gp_timeshower->graphElements[j]);
							gp_timeshower->graphElements[j].m_iShouldShow = 0;
						}
					}
					for(int j = 0;j<plocalcg03->lineCount;j++){
						if(plocalcg03->graphLineStationCN[j][0].m_funcvalue == gp_frontman_mgr->m_cg03.m_iLineCode){
							gp_ui->hideLabel(plocalcg03->graphLineStationCN[j][0]);
							plocalcg03->graphLineStationCN[j][0].m_iShouldShow = 0; 				
						}
					}*/
					plocalcg01->langFlag = 0;
					plocalcg01->displayFlag = 0;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
					plocalcg03->cg03_graphElementsHide(plocalcg03->langFlag);
					return 1;
				}
			}
		}
		else if(plocalcg03->langFlag == 1){
			for(int i = 0;i<row.size();i++){
				if( row[i].m_funcname == "EN_page3GoBack" )
				{
					//other process
					plocalcg01->langFlag = 1;
					plocalcg01->displayFlag = 0;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
					plocalcg03->cg03_graphElementsHide(plocalcg03->langFlag);
					return 1;
				}
			}
		}
	}
	return 0;
}




