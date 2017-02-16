
#include "2.h"
#include "d_cg06_backpic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg06_t.h"


//
d_cg06_backpic_t::d_cg06_backpic_t()
{
}


//
d_cg06_backpic_t::~d_cg06_backpic_t()
{
}


//
void d_cg06_backpic_t::ShowBack1()
{
	std::string ShowBack1NAME = GETLABELNAME;
	const char *s[] = { "CashTicketDonePrompt.jpg", "CashTicketDonePrompt_english.jpg" };
	/*a_label_t::ROWTYPE  row;

	gp_ui->LabelMkPic( row, 0, ShowBack1NAME, 
						gp_ui->PicPFn( s[GetLanguageState()] ), 0, 0, 1, 1 );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "ShowBack1";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );*/
	if(1){
		a_label_t::ROWTYPE	row;
		
		gp_ui->LabelMkPic( row, 0, "CN_page6BackPic", 
							gp_ui->PicPFn( s[0] ), 0, 0, 1, 1 );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "ShowBack1";
		row.m_funcvalue = 0;
		gp_ui->pic_task(row);
		//this->AddLg( m_Lg, row );
		plocalcg06->graphElementsCN.push_back(row);

	}
	if(1){
		a_label_t::ROWTYPE	row;
		
		gp_ui->LabelMkPic( row, 0, "EN_page6BackPic", 
							gp_ui->PicPFn( s[1] ), 0, 0, 1, 1 );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "ShowBack1";
		row.m_funcvalue = 0;
		gp_ui->pic_task(row);
		//this->AddLg( m_Lg, row );
		plocalcg06->graphElementsEN.push_back(row);

	}	
	//×Ö·û´®ÏÔÊ¾ ¡ª¡ª¹ºÆ±   
	if( 1 )
	{
		a_label_t::ROWTYPE  row1;
		char sz1[33];

		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_TicketoutActual );

		gp_ui->LabelMkStr( row1, 0, 
							"CN_TicketNum" ,
							sz1 , 
							gp_ui->X2dR( 0, 642 ), 
							gp_ui->Y2dR( 0, 309 ), 
							0.055, 
							"brown" );
		row1.m_hot = 0;
		gp_ui->str_task(row1);
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		plocalcg06->graphElementsCN.push_back(row1);
	}
	if( 1 )
	{
		a_label_t::ROWTYPE  row1;
		char sz1[33];

		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_TicketoutActual );

		gp_ui->LabelMkStr( row1, 0, 
							"EN_TicketNum" ,
							sz1 , 
							gp_ui->X2dR( 0, 642 ), 
							gp_ui->Y2dR( 0, 309 ), 
							0.055, 
							"brown" );
		row1.m_hot = 0;
		gp_ui->str_task(row1);
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		plocalcg06->graphElementsEN.push_back(row1);
	}
	

	//×Ö·û´®ÏÔÊ¾ ¡ª¡ªÕÒÁã	    
	if( 1 )
	{
		a_label_t::ROWTYPE  row2;
		char sz1[33];
	
		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_BilchgActual + 
			                           gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_CoinRecycleChgActual );

		gp_ui->LabelMkStr( row2, 0, 
							"CN_page6Chg" , //GETLABELNAME + "-chg" ,
							sz1 , 
							gp_ui->X2dR( 0, 642 ), 
							gp_ui->Y2dR( 0, 402 ), 
							0.055, 
							"brown" );
		row2.m_hot = 0;
		gp_ui->str_task(row2);
		plocalcg06->graphElementsCN.push_back(row2);
		//this->AddLg( m_Lg, row2 );
		//gp_ui->LabelPrep(row2);
	}
	
	//×Ö·û´®ÏÔÊ¾ ¡ª¡ªÕÒÁã	    
	if( 1 )
	{
		a_label_t::ROWTYPE  row2;
		char sz1[33];
	
		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_BilchgActual + 
			                           gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_CoinRecycleChgActual );

		gp_ui->LabelMkStr( row2, 0, 
							"EN_page6Chg" , //GETLABELNAME + "-chg" ,
							sz1 , 
							gp_ui->X2dR( 0, 642 ), 
							gp_ui->Y2dR( 0, 402 ), 
							0.055, 
							"brown" );
		row2.m_hot = 0;
		//this->AddLg( m_Lg, row2 );
		gp_ui->str_task(row2);
		//gp_ui->LabelPrep(row2);
		plocalcg06->graphElementsEN.push_back(row2);
	}

	//gp_ui->LabelMkDelPrep( ShowBack1NAME );

	//gp_ui->LabelPrep(row);
	//gp_ui->LabelCommit();
}



