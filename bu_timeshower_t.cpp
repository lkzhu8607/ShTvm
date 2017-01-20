
#include "bu_timeshower_t.h"
#include "de_log_t.h"
#include "d_db_t.h"
#include "d_config_t.h"
#include "de_ui_t.h"


//
bu_timeshower_t     *gp_timeshower;


//
bu_timeshower_t::bu_timeshower_t() 
{
	m_stype = HIDED;
	m_stypefuture = HIDED;
	m_stypecount = 0;

	m_x = 0;
	m_y = 0;
	m_scr = 0;
	pageGraphElementsFlags = 0;
	timerFlags = 6;
}


//
bu_timeshower_t:: ~bu_timeshower_t()
{
}

void bu_timeshower_t::timeLabel()
{
	if(pageGraphElementsFlags == 0)
	{
		a_label_t::ROWTYPE  row;
		a_label_t::ROWTYPE  row1;
		m_x = gp_ui->X2dR( 0, 1062 );
		m_y = gp_ui->Y2dR( 0, 145 );
		gp_ui->LabelMkStr(row, m_scr, "timeDisplay", SDte::GetNow().ReadString(), 0.798,0.0734, 0.040, "black" );
		row.m_font_align = 0;
		row.m_hot = 0;
		gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		gp_timeshower->graphElements.push_back(row);

		m_x = gp_ui->X2dR( 0, 1103 );
		m_y = gp_ui->Y2dR( 0, 144 );
		gp_ui->LabelMkStr(row1, m_scr, "dateDisplay", SDte::GetNow().ReadStrDate(), 0.838857,0.14600, 0.040, "black" );
		row1.m_font_align = 0;
		row1.m_hot = 0;
		gp_ui->LabelPrep(row1);
		gp_ui->str_task(row1);
		gp_timeshower->graphElements.push_back(row1);
		pageGraphElementsFlags = 1;
	}

}
void bu_timeshower_t::init()
{
	this->timeLabel();
}

// 
int bu_timeshower_t::tr_on_user_run()
{
	std::string strNAME = GETLABELNAME;

	if( m_stype == HIDE )
	{
		gp_ui->LabelMkDelPrep( strNAME );
		gp_ui->LabelCommit();
	
		m_stype = HIDED;
	}

	if( m_stype == HIDED )
	{
		m_stypecount --;
		if( m_stypecount <= 0 )
		{
			m_stype = m_stypefuture;
		}

		WThrd::tr_sleepu( 1 );
	}

	if( m_stype == DATETIME )
	{
		m_x = gp_ui->X2dR( 0, 1062 );
		m_y = gp_ui->Y2dR( 0, 145 );
		gp_ui->LabelMkStrPrep( m_scr, strNAME, SDte::GetNow().ReadString(), 0.798,0.0734, 0.040, "black" );
		gp_ui->LabelCommit();
	}

	if( m_stype == DATE )
	{
		m_x = gp_ui->X2dR( 0, 1103 );
		m_y = gp_ui->Y2dR( 0, 144 );
		gp_ui->LabelMkStrPrep( m_scr, strNAME, SDte::GetNow().ReadStrDate(), 0.838857,0.14600, 0.040, "black" );
		gp_ui->LabelCommit();
		WThrd::tr_sleepu( 1 );
	}

	if( m_stype == QUIT )
	{
		return 0;
	}

	WThrd::tr_sleepu( 0.95 );

	return 1;
}


//
void bu_timeshower_t::SetSType( ShowType_t S )
{
	if( m_stype != HIDED )
		m_stype = HIDE;
	m_stypecount = 2;
	m_stypefuture = S;
}



