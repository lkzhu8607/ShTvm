
#include "d_cg01s_linepic_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_cg01_t.h"
#include "2.h"


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
	a3083_t  row3083;
	gp_db->get3083tbl(row3083);
	plocalcg01->mianPicRecordCount = row3083.GetRowCount();

	/*if( !m_row3083.m_biIsAffect )
	{
		gp_db->get3083row( m_row3083, plocalcg01->m_cg01s_linepic_MainUiIdx );
		if( !m_row3083.m_biIsAffect ) return;
	}*/
	for(int i = 0; i < plocalcg01->mianPicRecordCount; i++){
		/*if( !m_row3083.m_biIsAffect )
		{
			gp_db->get3083row( m_row3083, (i+1) );
			if( !m_row3083.m_biIsAffect ) return;
		}*/
		gp_db->get3083row( m_row3083, (i+1) );
		a_label_t::ROWTYPE	row;
		a_label_t::ROWTYPE	row1;
		std::string strpic[2];
		
		strpic[0] = m_row3083.m_MainUiPicFn;
		strpic[1] = "e" + strpic[0];
		std::string num2str = SStrf::sltoa((int)(i+1));
		gp_ui->LabelMkPic( row, 0, "CN_MainPic_"+ SStrf::sltoa((int)(i+1)), gp_ui->PicPFn( strpic[0] ), 
							0, 
							0, 
							gp_ui->X2dR( 0, m_row3083.m_MainUiPicWidth ), 
							gp_ui->Y2dR( 0, m_row3083.m_MainUiPicHeight )	);
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "CN_mInterface";
		row.m_funcvalue = m_row3083.m_MainUiIdx;
		//this->AddLg( m_Lg, row );
		
		//gp_ui->LabelPrep(row);
		//gp_ui->LabelCommit();
		gp_ui->pic_task(row);
		plocalcg01->graphMainInterfaceCN.push_back(row);
		
		gp_ui->LabelMkPic( row1, 0, "EN_MainPic_" + SStrf::sltoa((int)(i+1)), gp_ui->PicPFn( strpic[1] ), 
							0, 
							0, 
							gp_ui->X2dR( 0, m_row3083.m_MainUiPicWidth ), 
							gp_ui->Y2dR( 0, m_row3083.m_MainUiPicHeight )	);
		gp_ui->CalcPicX2Y2(row1);
		row1.m_hot = 0;
		row1.m_funcname = "EN_mInterface";
		row1.m_funcvalue = m_row3083.m_MainUiIdx;
		//this->AddLg( m_Lg, row1 );
		
		//gp_ui->LabelPrep(row1);
		//gp_ui->LabelCommit();
		gp_ui->pic_task(row1);
		plocalcg01->graphMainInterfaceEN.push_back(row1);	

		if( m_row3083.m_DirButt1Enable )
		{
			a_label_t::ROWTYPE  row;
			gp_ui->LabelMkPic( row, 0, 
								"MainPic_"+SStrf::sltoa((int)(i+1))+"_dirButt1", 
								"", 
								gp_ui->X2dR( 0, m_row3083.m_DirButt1X ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt1Y ), 
								gp_ui->X2dR( 0, m_row3083.m_DirButt1Width ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt1Height )   );
			gp_ui->CalcPicX2Y2(row);
			row.m_hot = 1;
			row.m_funcname = "ShowDirButt";
			row.m_funcvalue = m_row3083.m_DirButt1MainUiIdx;
			//this->AddLg( m_Lg, row );
			//gp_ui->LabelPrep(row);
			//gp_ui->pic_task(row);
			plocalcg01->graphMainInterfaceCN.push_back(row);
			plocalcg01->graphMainInterfaceEN.push_back(row);		
		}
		if( m_row3083.m_DirButt2Enable )
		{
			a_label_t::ROWTYPE  row;
			gp_ui->LabelMkPic( row, 0, 
								"MainPic_"+SStrf::sltoa((int)(i+1))+"_dirButt2", 
								"", 
								gp_ui->X2dR( 0, m_row3083.m_DirButt2X ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt2Y ), 
								gp_ui->X2dR( 0, m_row3083.m_DirButt2Width ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt2Height )   );
			gp_ui->CalcPicX2Y2(row);
			row.m_hot = 1;
			row.m_funcname = "ShowDirButt";
			row.m_funcvalue = m_row3083.m_DirButt2MainUiIdx;
			//this->AddLg( m_Lg, row );
			//gp_ui->LabelPrep(row);
			//gp_ui->pic_task(row);
			plocalcg01->graphMainInterfaceCN.push_back(row);
			plocalcg01->graphMainInterfaceEN.push_back(row);		
		}
		if( m_row3083.m_DirButt3Enable )
		{
			a_label_t::ROWTYPE  row;
			gp_ui->LabelMkPic( row, 0, 
								"MainPic_"+SStrf::sltoa((int)(i+1))+"_dirButt3", 
								"", 
								gp_ui->X2dR( 0, m_row3083.m_DirButt3X ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt3Y ), 
								gp_ui->X2dR( 0, m_row3083.m_DirButt3Width ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt3Height )   );
			gp_ui->CalcPicX2Y2(row);
			row.m_hot = 1;
			row.m_funcname = "ShowDirButt";
			row.m_funcvalue = m_row3083.m_DirButt3MainUiIdx;
			//this->AddLg( m_Lg, row );
			//gp_ui->LabelPrep(row);
			//gp_ui->pic_task(row);
			plocalcg01->graphMainInterfaceCN.push_back(row);
			plocalcg01->graphMainInterfaceEN.push_back(row);	
		}
		if( m_row3083.m_DirButt4Enable )
		{
			a_label_t::ROWTYPE  row;
			gp_ui->LabelMkPic( row, 0, 
								"MainPic_"+SStrf::sltoa((int)(i+1))+"_dirButt4", 
								"", 
								gp_ui->X2dR( 0, m_row3083.m_DirButt4X ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt4Y ), 
								gp_ui->X2dR( 0, m_row3083.m_DirButt4Width ), 
								gp_ui->Y2dR( 0, m_row3083.m_DirButt4Height )   );
			gp_ui->CalcPicX2Y2(row);
			row.m_hot = 1;
			row.m_funcname = "ShowDirButt";
			row.m_funcvalue = m_row3083.m_DirButt4MainUiIdx;
			//this->AddLg( m_Lg, row );
			//gp_ui->LabelPrep(row);
			//gp_ui->pic_task(row);
			plocalcg01->graphMainInterfaceCN.push_back(row);
			plocalcg01->graphMainInterfaceEN.push_back(row);
		}	
	}
}

//
tbool d_cg01s_linepic_t::Find_n_do_ShowDirButt( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE> row;

	if( this->LocateHot( plocalcg01->graphMainInterfaceCN, strinput, row ) )
	{
		if(plocalcg01->langFlag == 0){
			for(int i=0;i<plocalcg01->graphMainInterfaceCN.size();i++){
				std::string strPic = "CN_MainPic_"+SStrf::sltoa((int)(i+1));
				if(plocalcg01->graphMainInterfaceCN[i].m_name == strPic && plocalcg01->graphMainInterfaceCN[i].m_iShouldShow == 1){
					//gp_ui->hideLabel(plocalcg01->graphMainInterfaceCN[i]);
					plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 0;
					continue;
				}
				else{
					plocalcg01->graphMainInterfaceCN[i].m_iShouldShow = 0;
				}
			}
			for(int i=0;i<row.size();i++){
				if( row[i].m_funcname == "ShowDirButt" && row[i].m_iShouldShow == 1){
					for(int j=0;j<plocalcg01->graphMainInterfaceCN.size();j++){
						if(plocalcg01->graphMainInterfaceCN[j].m_funcname == "CN_mInterface" && plocalcg01->graphMainInterfaceCN[j].m_funcvalue == row[i].m_funcvalue){
							gp_ui->pic_task(plocalcg01->graphMainInterfaceCN[j]);
							gp_ui->showLabel(plocalcg01->graphMainInterfaceCN[j]);
							plocalcg01->graphMainInterfaceCN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg01->graphMainInterfaceCN[j].m_name == ("MainPic_"+SStrf::sltoa((int)row[i].m_funcvalue)+"_dirButt1") || \
							plocalcg01->graphMainInterfaceCN[j].m_name == ("MainPic_"+SStrf::sltoa((int)row[i].m_funcvalue)+"_dirButt2") || \
							plocalcg01->graphMainInterfaceCN[j].m_name == ("MainPic_"+SStrf::sltoa((int)row[i].m_funcvalue)+"_dirButt3") || \
							plocalcg01->graphMainInterfaceCN[j].m_name == ("MainPic_"+SStrf::sltoa((int)row[i].m_funcvalue)+"_dirButt4") ){
							plocalcg01->graphMainInterfaceCN[j].m_iShouldShow = 1;
							continue;
						}
					}
				}				
			}
		}
		/*if( row.m_funcname == "ShowDirButt" )
		{
			plocalcg01->m_cg01s_linepic_MainUiIdx = row.m_funcvalue;
	
			return 1;
		}*/
	}
	return 0;
}




