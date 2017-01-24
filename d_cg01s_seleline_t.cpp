
#include "2.h"
#include "d_cg01s_seleline_t.h"
#include "d_cg01_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_timeshower_t.h"


//
d_cg01s_seleline_t::d_cg01s_seleline_t()
{
	gp_db->get3084tbl(m_a3084snapshot);
	m_iPageSize = 10;
}


//
d_cg01s_seleline_t::~d_cg01s_seleline_t()
{
}


//
std::string d_cg01s_seleline_t::GetLinepicPFn( int iLineNum )
{
	std::string s1;

	if( GetLanguageState() == 0 )
	{
		s1 = "linecode" + SStrf::sltoa(iLineNum) + ".jpg";
	}
	else
	{
		s1 = "linecode" + SStrf::sltoa(iLineNum) + "e.jpg";
	}

	return gp_ui->PicPFn( s1 );
}


//
void d_cg01s_seleline_t::Showseleline()
{
	int count = 0;
	long i;
	int &j(plocalcg01->m_cg01s_seleline_PageStartIdx);
	//gp_ui->LabelInvisible(m_Lg);
	for( i = 0; i+j < m_a3084snapshot.GetRowCount() ; i++ )
	{
		count = i;
		if(count>=10)
			count -= 10;
		a3084_t::ROWTYPE & row3084(m_a3084snapshot.GetRow(i + plocalcg01->m_cg01s_seleline_PageStartIdx));

		a_label_t::ROWTYPE  row;
		a_label_t::ROWTYPE  row1;
		std::string s_CN,s_EN;
		s_CN = "linecode" + SStrf::sltoa(row3084.m_LineCode) + ".jpg";
		s_EN = "linecode" + SStrf::sltoa(row3084.m_LineCode) + "e.jpg";

		//Í¼Æ¬ÏÔÊ¾ 
		gp_ui->LabelMkPic( row, 0, 
							"CN_LineButton" + SStrf::sltoa((int)(i+1)), 
							gp_ui->PicPFn( s_CN ) ,
							gp_ui->X2dR( 0, 16 * 2 + count * 16 * 7 ), 
							gp_ui->Y2dR( 0, 940 ), 
							gp_ui->X2dR( 0, 16 * 6 ), 
							gp_ui->Y2dR( 0, 16 * 4 )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "CN_SeleLine";
		row.m_funcvalue = row3084.m_LineCode;
		this->AddLg( m_Lg, row );
	
		gp_ui->LabelPrep(row);

		//ÈÈµã×¢²á 
		row.m_name += "--hot";
		row.m_hot = 1;
		this->AddLg( m_Lg, row );
		gp_ui->pic_task(row);
		plocalcg01->graphLineButtonCN.push_back(row);

		gp_ui->LabelMkPic( row1, 0, 
							"EN_LineButton" + SStrf::sltoa((int)(i+1)), 
							gp_ui->PicPFn( s_EN ) ,
							gp_ui->X2dR( 0, 16 * 2 + count * 16 * 7 ), 
							gp_ui->Y2dR( 0, 940 ), 
							gp_ui->X2dR( 0, 16 * 6 ), 
							gp_ui->Y2dR( 0, 16 * 4 )   );
		gp_ui->CalcPicX2Y2(row1);
		row1.m_hot = 0;
		row1.m_funcname = "EN_SeleLine";
		row1.m_funcvalue = row3084.m_LineCode;
		this->AddLg( m_Lg, row1 );
	
		gp_ui->LabelPrep(row1);

		//ÈÈµã×¢²á 
		row1.m_name += "--hot";
		row1.m_hot = 1;
		this->AddLg( m_Lg, row1 );		
		gp_ui->pic_task(row1);
		plocalcg01->graphLineButtonEN.push_back(row1);
	}

	//ÏÔÊ¾»»Ò³Í¼ 
	const char *sNext[] = { "next.jpg", "enext.jpg" };
	const char *sPrev[] = { "prev.jpg", "eprev.jpg" };
	a_label_t::ROWTYPE  row[4];
	std::string strChgPageButt;

	/*if( plocalcg01->m_cg01s_seleline_PageStartIdx == 0 )
		strChgPageButt = gp_ui->PicPFn( sNext[GetLanguageState()] );
	else
		strChgPageButt = gp_ui->PicPFn( sPrev[GetLanguageState()] );*/

	i = m_iPageSize;

	for(int j = 0;j<4;j++){
		if(j==0){
			strChgPageButt = gp_ui->PicPFn(sNext[0]);
		}
		else if(j==1){
			strChgPageButt = gp_ui->PicPFn(sNext[1]);
		}
		else if(j==2){
			strChgPageButt = gp_ui->PicPFn(sPrev[0]);
		}
		else if(j==3){
			strChgPageButt = gp_ui->PicPFn(sPrev[1]);
		}		
		gp_ui->LabelMkPic( row[j], 0, 
							"lineButtonUpDn" + SStrf::sltoa((int)j), 
							strChgPageButt ,
							gp_ui->X2dR( 0, 16 * 2 + i * 16 * 7 ), 
							gp_ui->Y2dR( 0, 940 ), 
							gp_ui->X2dR( 0, 16 * 6 ), 
							gp_ui->Y2dR( 0, 16 * 4 )   );
		
		gp_ui->CalcPicX2Y2(row[j]);
		row[j].m_hot = 0;
		
		//row[j].m_funcvalue = plocalcg01->m_cg01s_seleline_PageStartIdx == 0 ? m_iPageSize : 0;
		row[j].m_funcvalue = m_a3084snapshot.GetRowCount()+j+1;
		this->AddLg( m_Lg, row[j] );

		gp_ui->LabelPrep(row[j]);

		//ÈÈµã×¢²á 
		row[j].m_name += "--hot";
		row[j].m_hot = 1;
		this->AddLg( m_Lg, row[j] );
		if(j==0){
			row[j].m_funcname = "CN_NextButton";
			gp_ui->pic_task(row[j]);
			plocalcg01->graphLineButtonCN.push_back(row[j]);
		}
		else if(j==1){
			row[j].m_funcname = "EN_NextButton";
			gp_ui->pic_task(row[j]);
			plocalcg01->graphLineButtonEN.push_back(row[j]);
		}
		else if(j==2){
			row[j].m_funcname = "CN_PrevButton";
			gp_ui->pic_task(row[j]);
			plocalcg01->graphLineButtonCN.push_back(row[j]);
		}
		else if(j==3){
			row[j].m_funcname = "EN_PrevButton";
			gp_ui->pic_task(row[j]);
			plocalcg01->graphLineButtonEN.push_back(row[j]);
		}			
	}

	//gp_ui->LabelCommit();
}


//
tbool d_cg01s_seleline_t::Find_n_do_seleline( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;

	if( this->LocateHot( plocalcg01->graphLineButtonCN, strinput, row ) )
	{
		if(plocalcg01->langFlag == 0){
			for(int j=0;j<row.size();j++){
				if(row[j].m_funcname == "CN_SeleLine"){
					if(GetLanguageState()==0){
						for(int i=0;i< (plocalcg01->graphElementsCN.size());i++){
							if(plocalcg01->graphElementsCN[i].m_iShouldShow == 1){
								gp_ui->hideLabel(plocalcg01->graphElementsCN[i]);
							}
						}
						for(int i=0;i<plocalcg01->graphFastButtonCN.size();i++){
							if(plocalcg01->graphFastButtonCN[i].m_iShouldShow == 1){
								gp_ui->hideLabel(plocalcg01->graphFastButtonCN[i]);
							}			
						}
						for(int i=0;i<plocalcg01->graphLineButtonCN.size();i++){
							if(plocalcg01->graphLineButtonCN[i].m_iShouldShow == 1){
								gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
							}			
						}			
					}
					for(int i=0;i<(gp_timeshower->graphElements.size());i++){
						if(gp_timeshower->graphElements[i].m_iShouldShow == 1){
							gp_ui->hideLabel(gp_timeshower->graphElements[i]);
						}			
					}		

					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg03;
					gp_frontman_mgr->m_cg03.m_iLineCode = row[j].m_funcvalue;
					
					return 1;
				}
			}
		}
		if(plocalcg01->langFlag == 1){
			for(int i=0;i<row.size();i++){
				if(row[i].m_funcname == "EN_SeleLine"){
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg03;
					gp_frontman_mgr->m_cg03.m_iLineCode = row[i].m_funcvalue;
					return 1;
				}
			}
		}
		
	}
	return 0;
}


//
tbool d_cg01s_seleline_t::Find_n_do_changepage( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;

	if( this->LocateHot( plocalcg01->graphLineButtonCN, strinput, row ) )
	{
		for(int j = 0; j < row.size(); j++){
			if(row[j].m_funcname == "EN_NextButton"  && plocalcg01->pageFlag == 1 && GetLanguageState()==1)
			{
				return 1;
			}
	 		else if(row[j].m_funcname == "CN_NextButton" && plocalcg01->pageFlag == 1 && GetLanguageState()==0){
				for(int i = 0;i < plocalcg01->graphLineButtonCN.size(); i++){
					if(plocalcg01->graphLineButtonCN[i].m_funcvalue <= 10){
						gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
					}
					else if(plocalcg01->graphLineButtonCN[i].m_funcvalue > 10 && plocalcg01->graphLineButtonCN[i].m_funcvalue <= m_a3084snapshot.GetRowCount()){
						//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]);	
					}
					if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_PrevButton"){
						//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]); 
					}				
				}
				plocalcg01->pageFlag = 0;
				return 1;
			}
			else if(row[j].m_funcname == "CN_PrevButton"&& plocalcg01->pageFlag == 0 && GetLanguageState()==0){
				for(int i = 0;i < plocalcg01->graphLineButtonCN.size(); i++){
					if(plocalcg01->graphLineButtonCN[i].m_funcvalue <= 10){
						//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]); 

					}
					else if(plocalcg01->graphLineButtonCN[i].m_funcname=="CN_NextButton"){
						//gp_ui->pic_task(plocalcg01->graphLineButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphLineButtonCN[i]); 
					}
					else{
						gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
					}
				}
				plocalcg01->pageFlag = 1;
				return 1;
			}
			else if(row[j].m_funcname == "EN_PrevButton" && plocalcg01->pageFlag == 0 && GetLanguageState()==1){
				return 1;
			}
		}
		//plocalcg01->m_cg01s_seleline_PageStartIdx = row.m_funcvalue;
		//return 1;
	}

	return 0;
}



