
#include "2.h"
#include "d_cg03s_oneline_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg01_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_timeshower_t.h"



//
d_cg03s_oneline_t::d_cg03s_oneline_t()
{
}


//
d_cg03s_oneline_t::~d_cg03s_oneline_t()
{
}



//
void d_cg03s_oneline_t::Showoneline()
{
	a3084_t  row3084;
	
	gp_db->get3084tbl(row3084);

	//if( !row3084.m_biIsAffect )
		//return;
	plocalcg03->lineCount = row3084.GetRowCount();
	for(int j=0;j<plocalcg03->lineCount;j++){
		std::vector<a_label_t::ROWTYPE> CNtmp;
		std::vector<a_label_t::ROWTYPE> ENtmp;
		a3084_t::ROWTYPE & row3084tmp(row3084.GetRow(j));
		a3084_t::ROWTYPE  row3084t;
		a_label_t::ROWTYPE  row;
		a_label_t::ROWTYPE  row1;
		std::string strpic[2];
		gp_db->get3084row( row3084tmp.m_LineCode, row3084t );

		strpic[0] = row3084t.m_strPicFn;
		strpic[1] = "e" + strpic[0];

		gp_ui->LabelMkPic( row, 0, 
							"CN_page3Line" + SStrf::sltoa((int)row3084tmp.m_LineCode) , 
							gp_ui->PicPFn( strpic[0] ) , 
							0 , 
							0 , 
							gp_ui->X2dR( 0, 993 ) , 
							gp_ui->Y2dR( 0, 887 ));
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "CN_line"+SStrf::sltoa((int)row3084tmp.m_LineCode)+"Pic";
		row.m_funcvalue = row3084tmp.m_LineCode;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);	
		gp_ui->pic_task(row);
		CNtmp.push_back(row);
		
		gp_ui->LabelMkPic( row1, 0, 
							"EN_page3Line" + SStrf::sltoa((int)row3084tmp.m_LineCode) , 
							gp_ui->PicPFn( strpic[1] ) , 
							0 , 
							0 , 
							gp_ui->X2dR( 0, 993 ) , 
							gp_ui->Y2dR( 0, 887 ));
		gp_ui->CalcPicX2Y2(row1);
		row1.m_hot = 0;
		row1.m_funcname = "EN_line"+SStrf::sltoa((int)row3084tmp.m_LineCode)+"Pic";
		row1.m_funcvalue = row3084tmp.m_LineCode;
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		gp_ui->pic_task(row1);
		ENtmp.push_back(row1);
		
		for( int i = 0; i < row3084t.m_StaNum; i++ )
		{
			a_label_t::ROWTYPE  row;

			gp_ui->LabelMkPic( row, 0, 
								"CN_l"+SStrf::sltoa((int)row3084tmp.m_LineCode)+"Sta"+SStrf::sltoa((int)i) , 
								gp_ui->PicPFn("cashdown.jpg") ,
								gp_ui->X2dR( 0, row3084t.m_StaButtX.a[i] ) , 
								gp_ui->Y2dR( 0, row3084t.m_StaButtY.a[i] ) , 
								gp_ui->X2dR( 0, row3084t.m_StaButtWidth.a[i] ) , 
								gp_ui->Y2dR( 0, row3084t.m_StaButtHeight.a[i] )   );
			gp_ui->CalcPicX2Y2(row);
			row.m_hot = 1;
			row.m_funcname = "CN_line"+SStrf::sltoa((int)row3084tmp.m_LineCode);
			row.m_funcvalue = row3084t.m_StaCode.a[i];
			//this->AddLg( m_Lg, row );
			//gp_ui->LabelPrep(row);
			//gp_ui->pic_task(row);
			CNtmp.push_back(row);
			ENtmp.push_back(row);
			//gp_ui->LabelPrep(row);
		}	
		plocalcg03->graphLineStationCN.push_back(CNtmp);
		plocalcg03->graphLineStationEN.push_back(ENtmp);
	}
}


//
tbool d_cg03s_oneline_t::Find_n_do_Showoneline( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	if(plocalcg03->langFlag == 0){
		if( this->LocateHot( plocalcg03->graphLineStationCN[plocalcg03->lineIndex], strinput, row ) )
		{
			for(int i=0;i<row.size();i++){
				if( row[i].m_funcname == ("CN_line"+SStrf::sltoa((int)gp_frontman_mgr->m_cg03.m_iLineCode)) )
				{
					u8arr_t<4>	ScNode;
					std::vector< int >	v;
				
					ScNode.a[0] = SStrf::Num2Bcd( (tuint8)plocalcg03->m_iLineCode );
					ScNode.a[1] = SStrf::Num2Bcd( (tuint8)row[i].m_funcvalue );
			
					if( !gp_db->GetPossiblePrices(v,ScNode) )
					{
						LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "???????????????" << SStrf::b2s(ScNode) << " ??????" << SStrf::b2s(gp_db->GetTheRowa3014().m_EqpNode) );
						return 0;
					}
					//hide last displayed elements
					plocalcg02->displayFlag = 0;
					plocalcg02->langFlag = 0;
			
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg02;
					gp_frontman_mgr->m_cg02.m_iPrice = v[0]; // 
					gp_frontman_mgr->m_cg02.m_SelectedScNode = ScNode;
					plocalcg03->cg03_graphElementsHide(plocalcg03->langFlag);
					//gp_frontman_mgr->m_cg02.m_pLastCg = plocalcg03;		
					return 1;
				}
			}
		}
	}
	else if(plocalcg03->langFlag == 1){
		if( this->LocateHot( plocalcg03->graphLineStationCN[plocalcg03->lineIndex], strinput, row ) )
		{
			for(int i=0;i<row.size();i++){
				if( row[i].m_funcname == ("CN_line"+SStrf::sltoa((int)gp_frontman_mgr->m_cg03.m_iLineCode)) )
				{
					u8arr_t<4>	ScNode;
					std::vector< int >	v;
				
					ScNode.a[0] = SStrf::Num2Bcd( (tuint8)plocalcg03->m_iLineCode );
					ScNode.a[1] = SStrf::Num2Bcd( (tuint8)row[i].m_funcvalue );
			
					if( !gp_db->GetPossiblePrices(v,ScNode) )
					{
						LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "???????????????" << SStrf::b2s(ScNode) << " ??????" << SStrf::b2s(gp_db->GetTheRowa3014().m_EqpNode) );
						return 0;
					}
					//hide last displayed elements
					plocalcg02->displayFlag = 0;
					plocalcg02->langFlag = 1;
					gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg02;
					gp_frontman_mgr->m_cg02.m_iPrice = v[0]; // 
					gp_frontman_mgr->m_cg02.m_SelectedScNode = ScNode;
					plocalcg03->cg03_graphElementsHide(plocalcg03->langFlag);
					//gp_frontman_mgr->m_cg02.m_pLastCg = plocalcg03;		
					return 1;
				}
			}
		}
	}
	return 0;
}


