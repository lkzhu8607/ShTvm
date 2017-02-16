
#include "2.h"
#include "d_cg06_showmess_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"


//
d_cg06_showmess_t::d_cg06_showmess_t()
{
}


//
d_cg06_showmess_t::~d_cg06_showmess_t()
{
}


//
void d_cg06_showmess_t::ShowMessage()
{

	//×Ö·û´®ÏÔÊ¾ ¡ª¡ª¹ºÆ±   
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		char sz1[33];

		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_TicketoutActual );

		gp_ui->LabelMkStr( row, 0, 
							GETLABELNAME + "-ticket" ,
							sz1 , 
							gp_ui->X2dR( 0, 650 ), 
							gp_ui->Y2dR( 0, 310 ), 
							0.061, 
							"brown" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
	}
	
	//×Ö·û´®ÏÔÊ¾ ¡ª¡ªÕÒÁã	    
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		char sz1[33];
	
		SClib::p_sprintf()( sz1, "%d", gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_BilchgActual + 
			                           gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount()-1 ).m_CoinRecycleChgActual );

		gp_ui->LabelMkStr( row, 0, 
							"×Ö·û´®ÏÔÊ¾ ¡ª¡ªÕÒÁã" , //GETLABELNAME + "-chg" ,
							sz1 , 
							gp_ui->X2dR( 0, 650 ), 
							gp_ui->Y2dR( 0, 400 ), 
							0.061, 
							"brown" );
		row.m_hot = 0;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
	}


	gp_ui->LabelCommit();

}



