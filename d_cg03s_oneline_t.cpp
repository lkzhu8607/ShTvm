
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
	a3084_t::ROWTYPE  row3084;

	gp_db->get3084row( plocalcg03->m_iLineCode, row3084 );

	if( !row3084.m_biIsAffect )
		return;

	//?????? 
	a_label_t::ROWTYPE  row;
	std::string strpic[2];

	strpic[0] = row3084.m_strPicFn;
	strpic[1] = "e" + strpic[0];

	gp_ui->LabelMkPic( row, 0, 
						GETLABELNAME , 
						gp_ui->PicPFn( strpic[GetLanguageState()] ) , 
						0 , 
						0 , 
						gp_ui->X2dR( 0, 993 ) , 
						gp_ui->Y2dR( 0, 887 )    );
	gp_ui->CalcPicX2Y2(row);
	row.m_hot = 0;
	row.m_funcname = "Showoneline";
	row.m_funcvalue = 0;
	this->AddLg( m_Lg, row );
	gp_ui->LabelPrep(row);

	//???????? 
	for( int i = 0; i < row3084.m_StaNum; i++ )
	{
		std::string strLN = GETLABELNAME;

		strLN += "-Sta-" + SStrf::sltoa(i);

		gp_ui->LabelMkPic( row, 0, 
							strLN , 
							gp_ui->PicPFn("cashdown.jpg") ,
							gp_ui->X2dR( 0, row3084.m_StaButtX.a[i] ) , 
							gp_ui->Y2dR( 0, row3084.m_StaButtY.a[i] ) , 
							gp_ui->X2dR( 0, row3084.m_StaButtWidth.a[i] ) , 
							gp_ui->Y2dR( 0, row3084.m_StaButtHeight.a[i] )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 1;
		row.m_funcname = "Showoneline";
		row.m_funcvalue = row3084.m_StaCode.a[i];
		this->AddLg( m_Lg, row );
	//gp_ui->LabelPrep(row);
	}

	gp_ui->LabelCommit();
}


//
tbool d_cg03s_oneline_t::Find_n_do_Showoneline( std::string strinput )
{
	a_label_t::ROWTYPE  row;

	if( this->LgFindhot( m_Lg, strinput, row ) )
	{
		if( row.m_funcname == "Showoneline" )
		{
			u8arr_t<4>  ScNode;
			std::vector< int >  v;

			ScNode.a[0] = SStrf::Num2Bcd( (tuint8)plocalcg03->m_iLineCode );
			ScNode.a[1] = SStrf::Num2Bcd( (tuint8)row.m_funcvalue );

			/*if(plocalcg03->m_iLineCode == 17){
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI<<"plocalcg03->m_iLineCode"<<plocalcg03->m_iLineCode);
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI<<"row.m_funcvalue"<<row.m_funcvalue);
			}*/
	
			if( !gp_db->GetPossiblePrices(v,ScNode) )
			{
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "???????????????" << SStrf::b2s(ScNode) << " ??????" << SStrf::b2s(gp_db->GetTheRowa3014().m_EqpNode) );

				return 0;
			}

			gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg02;
			gp_frontman_mgr->m_cg02.m_iPrice = v[0]; // 
			gp_frontman_mgr->m_cg02.m_SelectedScNode = ScNode;
			gp_frontman_mgr->m_cg02.m_pLastCg = plocalcg03;
	
			return 1;
		}
	}

	return 0;
}


