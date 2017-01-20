#include "2.h"
#include "d_cg02s_goodbillcoin_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"
#include "de_bill_t.h"


d_cg02s_goodbillcoin_t::d_cg02s_goodbillcoin_t()
{

}

d_cg02s_goodbillcoin_t::~d_cg02s_goodbillcoin_t()
{
}

tbool d_cg02s_goodbillcoin_t::ShowValidMoneyType()
{
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());

	if(1)
	{
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "CN_NormalNotesType", "5元 10元 20元 50元", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);

		/*if( Rb8702.m_ConnState == 1 && Rb8702.m_BigErr == 0 && Rb8702.m_BillStopUseFlag == 0 )
		{
	 		a_label_t::ROWTYPE  row;
			if(GetLanguageState() == 0){
				gp_ui->LabelMkStr( row, 0, GETLABELNAME, "5元 10元 20元 50元", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
				if( gp_bill->m_iIsNotBillChange == 1 )
				{
					gp_ui->LabelMkStr( row, 0, GETLABELNAME, "5元 10元", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
				}			
			
			}
			else{
				gp_ui->LabelMkStr( row, 0, GETLABELNAME, "￥5 ￥10 ￥20 ￥50", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
				if( gp_bill->m_iIsNotBillChange == 1 )
				{
					gp_ui->LabelMkStr( row, 0, GETLABELNAME, "￥5 ￥10", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
				}				
			}
			row.m_hot = 0;
			this->AddLg( m_Lg, row );
			gp_ui->LabelPrep(row);
			//gp_ui->LabelCommit();	
		}*/
		
	}
	if(1){
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "CN_exceptionNotesType", "5元 10元", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
	}
	if(1){
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "EN_NormalNotesType", "￥5 ￥10 ￥20 ￥50", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsEN.push_back(row);
	}
	if(1){
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkStr( row, 0, "EN_exceptionNotesType", "￥5 ￥10", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsEN.push_back(row);
	}

	if(1)
	{
		a_label_t::ROWTYPE	row;
		gp_ui->LabelMkStr( row, 0, "CN_CoinType", "1元 5角", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 770 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);	
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
		/*if( Rb8701.m_ConnState == 1 && Rb8701.m_BigErr == 0 && Rb8701.m_CoinStopUseFlag == 0 )
		{
			a_label_t::ROWTYPE	row;
			if(GetLanguageState() == 0)
				gp_ui->LabelMkStr( row, 0, GETLABELNAME, "1元 5角", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 770 ), 0.05, "black" );
			else
				gp_ui->LabelMkStr( row, 0, GETLABELNAME, "￥1 ￥0.5", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 770 ), 0.05, "black" );
			row.m_hot = 0;
			this->AddLg( m_Lg, row );
			gp_ui->LabelPrep(row);
			//gp_ui->LabelCommit();	
		}*/
	}
	if(1){
		a_label_t::ROWTYPE	row;
		gp_ui->LabelMkStr( row, 0, "EN_CoinType", "￥1 ￥0.5", gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 770 ), 0.05, "black" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);	
		gp_ui->str_task(row);
		plocalcg02->graphElementsEN.push_back(row);
	}
	
	return 0;
}


