
#include "d_cg01s_linepic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_cg01_t.h"


//
d_cg01s_linepic_t::d_cg01s_linepic_t()
{
}


//
d_cg01s_linepic_t::~d_cg01s_linepic_t()
{
}



//
void d_cg01s_linepic_t::ShowLinePic()
{
	if( !m_row3083.m_biIsAffect )
	{
		gp_db->get3083row( m_row3083, plocalcg01->m_cg01s_linepic_MainUiIdx );
		if( !m_row3083.m_biIsAffect ) return;
	}

	a_label_t::ROWTYPE  row;
	a_label_t::ROWTYPE  row1;
	std::string strpic[2];

	strpic[0] = m_row3083.m_MainUiPicFn;
	strpic[1] = "e" + strpic[0];

	gp_ui->LabelMkPic( row, 0, "CN_"+strpic[0], gp_ui->PicPFn( strpic[0] ), 
						0, 
						0, 
						gp_ui->X2dR( 0, m_row3083.m_MainUiPicWidth ), 
						gp_ui->Y2dR( 0, m_row3083.m_MainUiPicHeight )   );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "CN_LinePic";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );

	gp_ui->LabelPrep(row);
	//gp_ui->LabelCommit();
	gp_ui->pic_task(row);
	plocalcg01->graphElementsCN.push_back(row);
	
	gp_ui->LabelMkPic( row1, 0, "EN_"+strpic[1], gp_ui->PicPFn( strpic[1] ), 
						0, 
						0, 
						gp_ui->X2dR( 0, m_row3083.m_MainUiPicWidth ), 
						gp_ui->Y2dR( 0, m_row3083.m_MainUiPicHeight )   );
	gp_ui->CalcPicX2Y2(row1);
	row1.m_hot = 0;
	row1.m_funcname = "EN_LinePic";
	row1.m_funcvalue = 0;
	this->AddLg( m_Lg, row1 );

	gp_ui->LabelPrep(row1);
	//gp_ui->LabelCommit();
	gp_ui->pic_task(row1);
	plocalcg01->graphElementsEN.push_back(row1);	
}



//
void d_cg01s_linepic_t::ShowDirButt()
{
	if( !m_row3083.m_biIsAffect )
	{
		gp_db->get3083row( m_row3083, plocalcg01->m_cg01s_linepic_MainUiIdx );
		if( !m_row3083.m_biIsAffect ) return;
	}
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkPic( row, 0, 
							GETLABELNAME, 
							gp_ui->PicPFn( "" ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt1X ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt1Y ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt1Width ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt1Height )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 1;
		row.m_funcname = "ShowDirButt";
		row.m_funcvalue = m_row3083.m_DirButt1MainUiIdx;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg01->graphElementsCN.push_back(row);
		plocalcg01->graphElementsEN.push_back(row);		
	}
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkPic( row, 0, GETLABELNAME, gp_ui->PicPFn( "" ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt2X ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt2Y ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt2Width ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt2Height )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 1;
		row.m_funcname = "ShowDirButt";
		row.m_funcvalue = m_row3083.m_DirButt2MainUiIdx;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg01->graphElementsCN.push_back(row);
		plocalcg01->graphElementsEN.push_back(row);		
	}
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkPic( row, 0, GETLABELNAME, gp_ui->PicPFn( "" ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt3X ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt3Y ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt3Width ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt3Height )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 1;
		row.m_funcname = "ShowDirButt";
		row.m_funcvalue = m_row3083.m_DirButt3MainUiIdx;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg01->graphElementsCN.push_back(row);
		plocalcg01->graphElementsEN.push_back(row);		
	}
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		gp_ui->LabelMkPic( row, 0, GETLABELNAME, gp_ui->PicPFn( "" ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt4X ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt4Y ), 
							gp_ui->X2dR( 0, m_row3083.m_DirButt4Width ), 
							gp_ui->Y2dR( 0, m_row3083.m_DirButt4Height )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 1;
		row.m_funcname = "ShowDirButt";
		row.m_funcvalue = m_row3083.m_DirButt4MainUiIdx;
		this->AddLg( m_Lg, row );
		gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg01->graphElementsCN.push_back(row);
		plocalcg01->graphElementsEN.push_back(row);	
	}	
}


//
tbool d_cg01s_linepic_t::Find_n_do_ShowDirButt( std::string strinput )
{
	a_label_t::ROWTYPE  row;

	if( this->LgFindhot( m_Lg, strinput, row ) )
	{
		if( row.m_funcname == "ShowDirButt" )
		{
			plocalcg01->m_cg01s_linepic_MainUiIdx = row.m_funcvalue;
	
			return 1;
		}
	}

	return 0;
}




