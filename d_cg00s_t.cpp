
#include "2.h"
#include "d_cg00s_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"



//
d_cg00s_t::d_cg00s_t()
{
}


//
d_cg00s_t::~d_cg00s_t()
{
	Clean();
}


//
void d_cg00s_t::Clean()
{
	for( long i = 0; i < m_Lg.GetRowCount(); i++ )
	{
		a_label_t::ROWTYPE & row2(m_Lg.GetRow(i));

		if( row2.m_hot == 0 )
			gp_ui->LabelMkDelPrep( row2.m_name );
	}

	gp_ui->LabelCommit();
	
	OnClean();
	m_Lg.Clear();
}


//
void d_cg00s_t::AddLg( a_label_t &Lg, a_label_t::ROWTYPE & row_in )
{
	a_label_t::RPSTYPE rps[9];

	Lg.SelEc_name( row_in.m_name, rps[1] ); //    
	///
	 
	if( Lg.GetRowCount( rps[1] ) == 0 ) //没找到，是新增的记录 
	{
		Lg.Add(row_in);
	}
	else
	{
		a_label_t::ROWTYPE & row2( Lg.GetRow( rps[1], 0 ) );

		row2 = row_in;
	}
}

//find hot point
tbool d_cg00s_t::LgFindhot( a_label_t &Lg, std::string strInput, a_label_t::ROWTYPE & row_out )
{
	double x, y;
	int scr;

	if( de_ui_t::Parse_KIN_MOUSEBUTT1( strInput, scr, x, y ) )
	{
		for( long i = 0; i < Lg.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row(Lg.GetRow(i));

			if( row.m_hot == 0 ) continue;

			if( scr == row.m_scr && x >= row.m_x && y >= row.m_y && x <= row.m_x + row.m_pic_width && y <= row.m_y + row.m_pic_height )
			{
				row_out = row;
				return 1;
			}
		}
	}

	return 0;
}

tbool d_cg00s_t::LocateHot( std::vector<a_label_t::ROWTYPE> &Lg, std::string strInput, std::vector<a_label_t::ROWTYPE> & row_out )
{
	double x, y;
	int scr;
	int existFlag = 0;

	if( de_ui_t::Parse_KIN_MOUSEBUTT1( strInput, scr, x, y ) )
	{
		for( long i = 0; i < Lg.size(); i++ )
		{
			//a_label_t::ROWTYPE & row(Lg.GetRow(i));

			if( Lg[i].m_hot == 0 ) continue;

			if( scr == Lg[i].m_scr && x >= Lg[i].m_x && y >= Lg[i].m_y && x <= Lg[i].m_x + Lg[i].m_pic_width && y <= Lg[i].m_y + Lg[i].m_pic_height )
			{
				//row_out = Lg[i];
				row_out.push_back(Lg[i]);
				existFlag = 1;
				//return 1;
			}
		}
		if(existFlag == 1)
			return 1;
	}
	return 0;
}

tbool d_cg00s_t::trrigerHot( std::vector<a_label_t::ROWTYPE> &Lg, std::string strInput, a_label_t::ROWTYPE & row_out )
{
	double x, y;
	int scr;

	if( de_ui_t::Parse_KIN_MOUSEBUTT1( strInput, scr, x, y ) )
	{
		for( long i = 0; i < Lg.size(); i++ )
		{
			//a_label_t::ROWTYPE & row(Lg.GetRow(i));

			if( Lg[i].m_hot == 0 ) continue;

			if( scr == Lg[i].m_scr && x >= Lg[i].m_x && y >= Lg[i].m_y && x <= Lg[i].m_x + Lg[i].m_pic_width && y <= Lg[i].m_y + Lg[i].m_pic_height )
			{
				row_out = Lg[i];
				return 1;
			}
		}
	}
	return 0;
}


