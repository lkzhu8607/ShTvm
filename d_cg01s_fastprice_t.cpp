
#include "2.h"
#include "d_cg01s_fastprice_t.h"
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
d_cg01s_fastprice_t::d_cg01s_fastprice_t()
{
}


//
d_cg01s_fastprice_t::~d_cg01s_fastprice_t()
{
}


//
void d_cg01s_fastprice_t::Showfastprice1block( int i, std::vector< int > & v, int updn )
{
	const char *s_up[] = { "caseup.jpg", "cashupe.jpg" };
	const char *s_dn[] = { "cashdown.jpg", "cashdowne.jpg" };
	std::string strPicPFn ;
	long x;

	/*if( updn == 0 )
		strPicPFn = gp_ui->PicPFn( s_up[GetLanguageState()] );
	else
		strPicPFn = gp_ui->PicPFn( s_dn[GetLanguageState()] );*/

	if( ( i & 1 ) == 0 )
		x = 1033;
	else
		x = 1033 + 16 * 7;
 
	a_label_t::ROWTYPE  row[5];

	//图片显示 
	gp_ui->LabelMkPic( row[0], 0, 
						"CN_fastPicUp" + SStrf::sltoa((int)i), 
						gp_ui->PicPFn(s_up[0]) ,
						gp_ui->X2dR( 0, x ), 
						gp_ui->Y2dR( 0, 250 + i / 2 * 16 * 5 ), 
						gp_ui->X2dR( 0, 16 * 6 ), 
						gp_ui->Y2dR( 0, 16 * 5 )   );

	gp_ui->CalcPicX2Y2(row[0]);
	row[0].m_hot = 1;
	row[0].m_funcname = "CN_FastPicUp";
	row[0].m_funcvalue = v[i];
	//this->AddLg( m_Lg, row[0] );
	gp_ui->LabelPrep(row[0]);
	gp_ui->pic_task(row[0]);
	plocalcg01->graphFastButtonCN.push_back(row[0]);

	gp_ui->LabelMkPic( row[1], 0, 
						"EN_fastPicUp" + SStrf::sltoa((int)i), 
						gp_ui->PicPFn(s_up[1]) ,
						gp_ui->X2dR( 0, x ), 
						gp_ui->Y2dR( 0, 250 + i / 2 * 16 * 5 ), 
						gp_ui->X2dR( 0, 16 * 6 ), 
						gp_ui->Y2dR( 0, 16 * 5 )   );

	gp_ui->CalcPicX2Y2(row[1]);
	row[1].m_hot = 1;
	row[1].m_funcname = "EN_FastPicUp";
	row[1].m_funcvalue = v[i];
	//this->AddLg( m_Lg, row[1] );
	gp_ui->LabelPrep(row[1]);	
	gp_ui->pic_task(row[1]);
	plocalcg01->graphFastButtonEN.push_back(row[1]);
	
	gp_ui->LabelMkPic( row[2], 0, 
						"CN_fastPicDn" + SStrf::sltoa((int)i), 
						gp_ui->PicPFn(s_dn[0])  ,
						gp_ui->X2dR( 0, x ), 
						gp_ui->Y2dR( 0, 250 + i / 2 * 16 * 5 ), 
						gp_ui->X2dR( 0, 16 * 6 ), 
						gp_ui->Y2dR( 0, 16 * 5 )   );

	gp_ui->CalcPicX2Y2(row[2]);
	row[2].m_hot = 1;
	row[2].m_funcname = "CN_FastPicDn";
	row[2].m_funcvalue = v[i];
	//this->AddLg( m_Lg, row[2] );
	gp_ui->LabelPrep(row[2]);
	gp_ui->pic_task(row[2]);
	plocalcg01->graphFastButtonCN.push_back(row[2]);

	gp_ui->LabelMkPic( row[3], 0, 
						"EN_fastPicDn" + SStrf::sltoa((int)i), 
						gp_ui->PicPFn(s_dn[1])  ,
						gp_ui->X2dR( 0, x ), 
						gp_ui->Y2dR( 0, 250 + i / 2 * 16 * 5 ), 
						gp_ui->X2dR( 0, 16 * 6 ), 
						gp_ui->Y2dR( 0, 16 * 5 )   );

	gp_ui->CalcPicX2Y2(row[3]);
	row[3].m_hot = 1;
	row[3].m_funcname = "EN_FastPicDn";
	row[3].m_funcvalue = v[i];
	//this->AddLg( m_Lg, row[3] );
	gp_ui->LabelPrep(row[3]);
	gp_ui->pic_task(row[3]);
	plocalcg01->graphFastButtonEN.push_back(row[3]);
	//gp_ui->LabelCommit();

	//热点注册	
	//row[3].m_name += "--hot";
	//row[3].m_hot = 1;
	//this->AddLg( m_Lg, row[3] );

	//std::string sVal = SCalc::dseal( "a", 22 * SStrf::rand1() );
	//for( tsize j = 0; j < sVal.size(); j++ ) sVal[j] = ~sVal[j];

	//字符串显示  
	gp_ui->LabelMkStr( row[4], 0, 
						"fastPriceDigit" + SStrf::sltoa((int)i),
						SStrf::sltoa(v[i]) , 
						gp_ui->X2dR( 0, 45 + x ), 
						gp_ui->Y2dR( 0, 23 + 250 + i / 2 * 16 * 5 ), 
						0.07, "white" );
	row[4].m_font_align = 1;
	row[4].m_hot = 0;
	row[4].m_funcname = "ShowFastDigit";
	row[4].m_funcvalue = v[i];
	row[4].m_pic_width += SStrf::rand1(x+i); //为了影响数字摘要而不影响内容 
	//this->AddLg( m_Lg, row[4] );
	gp_ui->LabelPrep(row[4]);
	gp_ui->str_task(row[4]);
	plocalcg01->graphFastButtonCN.push_back(row[4]);
	plocalcg01->graphFastButtonEN.push_back(row[4]);
	//plocalcg01->graphElements.push_back(row);
}



//
void d_cg01s_fastprice_t::Showfastprice()
{
	std::vector< int >  v;

	if( !gp_db->GetPossiblePrices(v) ) return;

	m_v = v;

	for( tsize i = 0 ; i < v.size(); i ++ )
	{
		Showfastprice1block( i, v, 0 );
	}

	//gp_ui->LabelCommit();
}


//
tbool d_cg01s_fastprice_t::Find_n_do_Showfastprice( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	int j=0;
	if( this->LocateHot( plocalcg01->graphFastButtonCN, strinput, row ) )
	{
		for(j=0;j<row.size();j++){
			if( row[j].m_funcname == "CN_FastPicUp" && GetLanguageState()==0)
			{
				/*Showfastprice1block( row.m_funcvalue, m_v, 1 );*/
				for(int i=0;i<plocalcg01->graphFastButtonCN.size();i++){
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "CN_FastPicDn" && plocalcg01->graphFastButtonCN[i].m_funcvalue == row[j].m_funcvalue){
						//gp_ui->pic_task(plocalcg01->graphFastButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);	
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
					}
					if(plocalcg01->graphFastButtonCN[i].m_funcname == "ShowFastDigit" && plocalcg01->graphFastButtonCN[i].m_funcvalue == row[j].m_funcvalue){
						//gp_ui->str_task(plocalcg01->graphFastButtonCN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonCN[i]);
						plocalcg01->graphFastButtonCN[i].m_iShouldShow = 1;
					}
				}
				
				break;
				//return 1;
			}
			else if(row[j].m_funcname == "EN_FastPicUp" ){
				for(int i=0;i<plocalcg01->graphFastButtonEN.size();i++){
					if(plocalcg01->graphFastButtonEN[i].m_funcname == "EN_FastPicDn" && plocalcg01->graphFastButtonEN[i].m_funcvalue == row[j].m_funcvalue){
							//gp_ui->pic_task(plocalcg01->graphFastButtonEN[i]);
							gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
							plocalcg01->graphFastButtonEN[i].m_iShouldShow = 1;
					}
					if(plocalcg01->graphFastButtonEN[i].m_funcname == "ShowFastDigit" && plocalcg01->graphFastButtonEN[i].m_funcvalue == row[j].m_funcvalue){
						//gp_ui->str_task(plocalcg01->graphFastButtonEN[i]);
						gp_ui->showLabel(plocalcg01->graphFastButtonEN[i]);
						plocalcg01->graphFastButtonEN[i].m_iShouldShow = 1;
					}					
				}
				break;

			}
			/*else if(row.m_funcname == "EN_FastPicDn"){

			}
			else if(row.m_funcname == "CN_FastPicDn"){

			}*/	
			else if(row[j].m_funcname == "ShowFastDigit"){
				break;
			}
		}
			//other process
		if(GetLanguageState()==0){
			for(int i=0;i< (plocalcg01->graphElementsCN.size());i++){
				if(plocalcg01->graphElementsCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg01->graphElementsCN[i]);
					plocalcg01->graphElementsCN[i].m_iShouldShow = 0;
				}
			}
			for(int i=0;i<plocalcg01->graphFastButtonCN.size();i++){
				if(plocalcg01->graphFastButtonCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg01->graphFastButtonCN[i]);
					plocalcg01->graphFastButtonCN[i].m_iShouldShow = 0;
				}			
			}
			for(int i=0;i<plocalcg01->graphLineButtonCN.size();i++){
				if(plocalcg01->graphLineButtonCN[i].m_iShouldShow == 1){
					gp_ui->hideLabel(plocalcg01->graphLineButtonCN[i]);
					plocalcg01->graphLineButtonCN[i].m_iShouldShow = 0;
				}			
			}			
		}
		for(int i=0;i<(gp_timeshower->graphElements.size());i++){
			if(gp_timeshower->graphElements[i].m_iShouldShow == 1){
				gp_ui->hideLabel(gp_timeshower->graphElements[i]);
				gp_timeshower->graphElements[i].m_iShouldShow = 0;
			}			
		}

		gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg02;
		//gp_frontman_mgr->m_cg02.m_iPrice = m_v[row[j].m_funcvalue]; //的值就是价 
		gp_frontman_mgr->m_cg02.m_iPrice = row[j].m_funcvalue;
		gp_frontman_mgr->m_cg02.m_SelectedScNode = u8arr_t<4>();
		gp_frontman_mgr->m_cg02.m_pLastCg = plocalcg01;	
		if(GetLanguageState() == 0){
			plocalcg02->langFlag = 0;
		}
		else if(GetLanguageState() == 1){
			plocalcg02->langFlag = 1;
		}
		//plocalcg02->displayFlag = 0;
		return 1;
	}

	return 0;
}
