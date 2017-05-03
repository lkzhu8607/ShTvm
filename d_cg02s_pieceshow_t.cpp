
#include "2.h"
#include "d_cg02s_pieceshow_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"



//
d_cg02s_pieceshow_t::d_cg02s_pieceshow_t()
{
	m_iPieceNum = 1;
	m_ButtType = UP;
	disableDisplayFlag = 0;
	m_payed = m_payed_coin = m_payed_bill = 0;
	m_LastPayed = 0;
	m_chg = 0;
}


//
d_cg02s_pieceshow_t::~d_cg02s_pieceshow_t()
{
	gp_coin->dCoinHold();
	gp_coin->dCoin_Stop();

	if( !gp_medev->IsOnlyCoin() ) 
	{
		gp_bill->dBill_Stop();
		gp_bill->m_de_state = 0;
	}
}


//
void d_cg02s_pieceshow_t::Show1PieceButt( int i )
{
	const char *s; 
	//a_label_t::ROWTYPE  row;
	//a_label_t::ROWTYPE  row1;
	long x, y;
	std::string strName;

	if( m_ButtType == UP )		s = "butt_upx.png";
	else if( m_ButtType == DOWN )s = "butt_dnx.png";
	else						s = "butt_disx.png";
	
	if( i % 3 == 1 ) x = 851;
	if( i % 3 == 2 ) x = 851 + 136;
	if( i % 3 == 0 ) x = 851 + 136 + 136;

	if( (i-1) / 3 == 0 ) y = 327;
	if( (i-1) / 3 == 1 ) y = 327 + 140;
	if( (i-1) / 3 == 2 ) y = 327 + 140 + 140;

	if(1){
		a_label_t::ROWTYPE  row;
		//图片显示 
		strName = "page2PieceNumPicUp";
		gp_ui->LabelMkPic( row, 0, strName + SStrf::sltoa((int)i) , gp_ui->PicPFn("butt_upx.png") ,
							gp_ui->X2dR( 0, x ) , gp_ui->Y2dR( 0, y ) , gp_ui->X2dR( 0, 116 ) , 
							gp_ui->Y2dR( 0, 101 )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "PieceNumUp";
		row.m_funcvalue = i;

		//热点注册	
		row.m_name += "--hot";
		row.m_hot = 1;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);		
		gp_ui->pic_task(row);
		plocalcg02->graphPieceNumCN.push_back(row);
		plocalcg02->graphPieceNumEN.push_back(row);
	}
	if(1){
		//图片显示 
		a_label_t::ROWTYPE  row;
		strName = "page2PieceNumPiDn";
		gp_ui->LabelMkPic( row, 0, strName + SStrf::sltoa((int)i) , gp_ui->PicPFn("butt_dnx.png") ,
							gp_ui->X2dR( 0, x ) , gp_ui->Y2dR( 0, y ) , gp_ui->X2dR( 0, 116 ) , 
							gp_ui->Y2dR( 0, 101 )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_hot = 0;
		row.m_funcname = "PieceNumDn";
		row.m_funcvalue = i;

		//热点注册	
		row.m_name += "--hot";
		row.m_hot = 1;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg02->graphPieceNumCN.push_back(row);
		plocalcg02->graphPieceNumEN.push_back(row);
	}
	if(1){
		a_label_t::ROWTYPE  row;
		//图片显示 
		strName = "page2PieceNumPicDis";
		gp_ui->LabelMkPic( row, 0, strName + SStrf::sltoa((int)i) , gp_ui->PicPFn("butt_disx.png") ,
							gp_ui->X2dR( 0, x ) , gp_ui->Y2dR( 0, y ) , gp_ui->X2dR( 0, 116 ) , 
							gp_ui->Y2dR( 0, 101 )   );
		gp_ui->CalcPicX2Y2(row);
		row.m_funcname = "PieceNumDis";
		row.m_funcvalue = i;

		//热点注册
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->pic_task(row);
		plocalcg02->graphPieceNumCN.push_back(row);
		plocalcg02->graphPieceNumEN.push_back(row);
	}	

	if(1){
		a_label_t::ROWTYPE  row1;
		strName = "page2PieceNumDigitUp";
		//字符串显示  
		gp_ui->LabelMkStr( row1, 0, 
							strName + SStrf::sltoa((int)i),
							SStrf::sltoa(i) , 
							gp_ui->X2dR( 0, 53 + x ) , 
							gp_ui->Y2dR( 0, 17 + y ) , 
							0.07, 
							"yellow");
		row1.m_font_align = 1;
		row1.m_hot = 0;
		row1.m_funcvalue = i;
		row1.m_funcname = "PieceNumDigitUp";
		row1.m_pic_width += SStrf::rand1(x+i); //为了影响数字摘要而不影响内容 
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		gp_ui->str_task(row1);
		plocalcg02->graphPieceNumCN.push_back(row1);
		plocalcg02->graphPieceNumEN.push_back(row1);
	}
	if(1){
		a_label_t::ROWTYPE  row1;
		strName = "page2PieceNumDigitDn";
		//字符串显示  
		gp_ui->LabelMkStr( row1, 0, 
							strName + SStrf::sltoa((int)i),
							SStrf::sltoa(i) , 
							gp_ui->X2dR( 0, 53 + x ) , 
							gp_ui->Y2dR( 0, 17 + y ) , 
							0.07, 
							"black"	);
		row1.m_font_align = 1;
		row1.m_hot = 0;
		row1.m_funcvalue = i;
		row1.m_funcname = "PieceNumDigitDn";
		row1.m_pic_width += SStrf::rand1(x+i); //为了影响数字摘要而不影响内容 
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		gp_ui->str_task(row1);
		plocalcg02->graphPieceNumCN.push_back(row1);
		plocalcg02->graphPieceNumEN.push_back(row1);
	}
	if(1){
		a_label_t::ROWTYPE  row1;
		strName = "page2PieceNumDigitDis";
		//字符串显示  
		gp_ui->LabelMkStr( row1, 0, 
							strName + SStrf::sltoa((int)i),
							SStrf::sltoa(i) , 
							gp_ui->X2dR( 0, 53 + x ) , 
							gp_ui->Y2dR( 0, 17 + y ) , 
							0.07, 
							"gray");
		row1.m_font_align = 1;
		row1.m_hot = 0;
		row1.m_funcvalue = i;
		row1.m_funcname = "PieceNumDigitDis";
		row1.m_pic_width += SStrf::rand1(x+i); //为了影响数字摘要而不影响内容 
		//this->AddLg( m_Lg, row1 );
		//gp_ui->LabelPrep(row1);
		gp_ui->str_task(row1);
		plocalcg02->graphPieceNumCN.push_back(row1);
		plocalcg02->graphPieceNumEN.push_back(row1);
	}	
}


//
void d_cg02s_pieceshow_t::ShowPieceButtBoard()
{
	for( int i = 1 ; i < (int)gp_db->m_a3003.GetRow(0).m_BuyTicketNumLimit + 1; i ++ )
	{
		Show1PieceButt( i );
	}	
}


//
void d_cg02s_pieceshow_t::ShowPieceInfo()
{
	//字符串显示 ——张数   
	if( 1 )
	{
		a_label_t::ROWTYPE  row;

		gp_ui->LabelMkStr( row, 0, 
							"choicePieceNum" ,
							SStrf::sltoa( m_iPieceNum ),
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 340 ), 
							0.061, 
							"black" );
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
		plocalcg02->graphElementsEN.push_back(row);		
	}

	//字符串显示 ——应付    
	if( 1 )
	{
		a_label_t::ROWTYPE  row;

		gp_ui->LabelMkStr( row, 0, 
							"shouldPay",
							SStrf::sltoa( m_iPieceNum * plocalcg02->m_iPrice ) , 
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 400 ), 
							0.061, 
							"black" );
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
		plocalcg02->graphElementsEN.push_back(row);		
	}
}

//
tbool d_cg02s_pieceshow_t::Find_n_do_ShowAllPieceNum( std::string strinput )
{
	std::vector<a_label_t::ROWTYPE>  row;
	int choicePieceNum = 0;
	//如果已全禁止，则不能再选价	
	//if( m_ButtType == DISABLE ) return 0;
	if(this->disableDisplayFlag == 1){
		return 0;
	}
	if(plocalcg02->langFlag==0){
		if( this->LocateHot(plocalcg02->graphPieceNumCN, strinput, row)){
			for(int i =0;i < row.size();i++){
				choicePieceNum = row[i].m_funcvalue;
				if(row[i].m_funcvalue == m_iPieceNum){
					continue;
				}
				if(row[i].m_funcname == "PieceNumDn"){
					for(int j = 0;j<plocalcg02->graphPieceNumCN.size();j++){
					 	if(plocalcg02->graphPieceNumCN[j].m_funcname == "PieceNumDn" && plocalcg02->graphPieceNumCN[j].m_funcvalue == m_iPieceNum){
							gp_ui->hideLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 0;
							continue;
						}	
						if(plocalcg02->graphPieceNumCN[j].m_funcname == "PieceNumDigitDn" && plocalcg02->graphPieceNumCN[j].m_funcvalue == m_iPieceNum){
							gp_ui->hideLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 0;
							continue;
						}							
					 	if(plocalcg02->graphPieceNumCN[j].m_funcname == "PieceNumUp" && plocalcg02->graphPieceNumCN[j].m_funcvalue == m_iPieceNum){
							gp_ui->showLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphPieceNumCN[j].m_funcname == "PieceNumDigitUp" && plocalcg02->graphPieceNumCN[j].m_funcvalue == m_iPieceNum){
							gp_ui->showLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}						
						if(row[i].m_funcname == plocalcg02->graphPieceNumCN[j].m_funcname && row[i].m_funcvalue == plocalcg02->graphPieceNumCN[j].m_funcvalue){
							gp_ui->showLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphPieceNumCN[j].m_funcname == "PieceNumDigitDn" && row[i].m_funcvalue == plocalcg02->graphPieceNumCN[j].m_funcvalue){
							gp_ui->showLabel(plocalcg02->graphPieceNumCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}
					}
					for(int j = 0;j<plocalcg02->graphElementsCN.size();j++){
						if(plocalcg02->graphElementsCN[j].m_name == "choicePieceNum"){
							gp_ui->hideLabel(plocalcg02->graphElementsCN[j]);
							gp_ui->updateLabel(plocalcg02->graphElementsCN[j],SStrf::sltoa( row[i].m_funcvalue ));
							gp_ui->str_task(plocalcg02->graphElementsCN[j]);
							gp_ui->showLabel(plocalcg02->graphElementsCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphElementsCN[j].m_name == "shouldPay"){
							gp_ui->hideLabel(plocalcg02->graphElementsCN[j]);
							gp_ui->updateLabel(plocalcg02->graphElementsCN[j],SStrf::sltoa( row[i].m_funcvalue * plocalcg02->m_iPrice));
							gp_ui->str_task(plocalcg02->graphElementsCN[j]);
							gp_ui->showLabel(plocalcg02->graphElementsCN[j]);
							plocalcg02->graphPieceNumCN[j].m_iShouldShow = 1;
							continue;
						}
					}						
				}			
			}
			m_iPieceNum = choicePieceNum;
			plocalcg02->m_iPieceNum = choicePieceNum;
			return 1;
		}
	}
	else if(plocalcg02->langFlag==1){
		if( this->LocateHot(plocalcg02->graphPieceNumEN, strinput, row)){
			for(int i =0;i < row.size();i++){
				choicePieceNum = row[i].m_funcvalue;
				if(row[i].m_funcvalue == m_iPieceNum){
					continue;
				}
				if(row[i].m_funcname == "PieceNumDn"){
					for(int j = 0;j<plocalcg02->graphPieceNumEN.size();j++){
					 	if(plocalcg02->graphPieceNumEN[j].m_funcname == "PieceNumDn" && plocalcg02->graphPieceNumEN[j].m_funcvalue == m_iPieceNum){
							gp_ui->hideLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 0;
							continue;
						}	
						if(plocalcg02->graphPieceNumEN[j].m_funcname == "PieceNumDigitDn" && plocalcg02->graphPieceNumEN[j].m_funcvalue == m_iPieceNum){
							gp_ui->hideLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 0;
							continue;
						}							
					 	if(plocalcg02->graphPieceNumEN[j].m_funcname == "PieceNumUp" && plocalcg02->graphPieceNumEN[j].m_funcvalue == m_iPieceNum){
							gp_ui->showLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphPieceNumEN[j].m_funcname == "PieceNumDigitUp" && plocalcg02->graphPieceNumEN[j].m_funcvalue == m_iPieceNum){
							gp_ui->showLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}						
						if(row[i].m_funcname == plocalcg02->graphPieceNumEN[j].m_funcname && row[i].m_funcvalue == plocalcg02->graphPieceNumEN[j].m_funcvalue){
							gp_ui->showLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphPieceNumEN[j].m_funcname == "PieceNumDigitDn" && row[i].m_funcvalue == plocalcg02->graphPieceNumEN[j].m_funcvalue){
							gp_ui->showLabel(plocalcg02->graphPieceNumEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}
					}
					for(int j = 0;j<plocalcg02->graphElementsEN.size();j++){
						if(plocalcg02->graphElementsEN[j].m_name == "choicePieceNum"){
							gp_ui->hideLabel(plocalcg02->graphElementsEN[j]);
							gp_ui->updateLabel(plocalcg02->graphElementsEN[j],SStrf::sltoa( row[i].m_funcvalue ));
							gp_ui->str_task(plocalcg02->graphElementsEN[j]);
							gp_ui->showLabel(plocalcg02->graphElementsEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}
						if(plocalcg02->graphElementsEN[j].m_name == "shouldPay"){
							gp_ui->hideLabel(plocalcg02->graphElementsEN[j]);
							gp_ui->updateLabel(plocalcg02->graphElementsEN[j],SStrf::sltoa( row[i].m_funcvalue * plocalcg02->m_iPrice));
							gp_ui->str_task(plocalcg02->graphElementsEN[j]);
							gp_ui->showLabel(plocalcg02->graphElementsEN[j]);
							plocalcg02->graphPieceNumEN[j].m_iShouldShow = 1;
							continue;
						}
					}						
				}			
			}
			m_iPieceNum = choicePieceNum;
			plocalcg02->m_iPieceNum = choicePieceNum;
			return 1;
		}

	}
	return 0;
}



//
void d_cg02s_pieceshow_t::ShowPayednchg()
{
	//字符串显示 ——已付   
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		char sz1[33];

		SClib::p_sprintf()( sz1, "%0.1f", m_payed / 100.00 );

		gp_ui->LabelMkStr( row, 0, 
							"dealPayed" ,
							sz1 , 
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 460 ), 
							0.061, 
							"brown" );
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
	 	plocalcg02->graphElementsCN.push_back(row);
		plocalcg02->graphElementsEN.push_back(row);			
	}
	
	//字符串显示 ——找零	    
	if( 1 )
	{
		a_label_t::ROWTYPE  row;
		char sz1[33];
	
		SClib::p_sprintf()( sz1, "%d", m_chg / 100 );

		gp_ui->LabelMkStr( row, 0, 
							"shouldChange" , //GETLABELNAME + "-chg" ,
							sz1 , 
							gp_ui->X2dR( 0, 377 ), 
							gp_ui->Y2dR( 0, 520 ), 
							0.061, 
							"brown" );
		row.m_hot = 0;
		//this->AddLg( m_Lg, row );
		//gp_ui->LabelPrep(row);
		gp_ui->str_task(row);
		plocalcg02->graphElementsCN.push_back(row);
		plocalcg02->graphElementsEN.push_back(row);			
	}

	//gp_ui->LabelCommit();
}



//
void d_cg02s_pieceshow_t::ActiveCoinBill()
{
	int irc = 0;
	if( !gp_medev->IsOnlyBill() )
	{
		gp_coin->dCoinHold();
		//参数走参数

		tbool enable_mao5 =  (SStrf::readbit( gp_db->m_a3003.GetRow(0).m_PermitCoinType, 1 ) == 1)?1:0;  //5角
		tbool enable_yuan1 = (SStrf::readbit( gp_db->m_a3003.GetRow(0).m_PermitCoinType, 2 ) == 1)?1:0;  // 1元
		irc = gp_coin->dCoin_Work( enable_mao5, enable_yuan1 );
		if( irc != 0 )
		{
			gp_db->m_b8701.GetRow(0).m_BigErr = 1;
			//return ;
		}

		//如果硬币口没打开，则表示打开失败。设bigerr
		//Bit2:=1/0  1投币口闸门已打开，    0 未打开
		if( ( !gp_medev->IsOnlyBill() ) &&
			( SStrf::readbit( gp_db->m_b8701.GetRow(0).m_CoinPollData.a[2], 2 ) == 0 ) )
		{
			gp_db->m_b8701.GetRow(0).m_BigErr = 1;
			//return ;
		}
	}

	if( !gp_medev->IsOnlyCoin() )
	{
		irc = gp_bill->dBill_Work();  //modify by jfren@2161122
	
		if( irc != 0 )
		{
			gp_db->m_b8702.GetRow(0).m_BigErr = 1;
			return ;
		}
		gp_bill->m_de_state = 2;
	}
}

void d_cg02s_pieceshow_t::StopCoinAndBill()
{
	int irc = 0;
	gp_coin->dCoinHold();
	irc = gp_coin->dCoin_Stop();

	if( !gp_medev->IsOnlyCoin() ) 
	{
		irc = gp_bill->dBill_Stop();

		gp_bill->m_de_state = 0;
		if( irc != 0 )
		{
			gp_db->m_b8701.GetRow(0).m_BigErr = 1;
		}
	}
}


//
int d_cg02s_pieceshow_t::FnD_ShowNewValue( std::string strinput , a_waiter_t_rowtype * pwaiterdata )
{
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	int iShouldPay = m_iPieceNum * plocalcg02->m_iPrice * 100;
	int rc = 0;

	if( ! ( strinput[0] == KIN_COIN || strinput[0] == KIN_BILL ) )
		return rc;
	/*if(plocalcg02->disableDisplayFlag == 1){
		return rc;
	}*/
	//如果有钱投入则 张数键盘 全禁止
	if( Rb8701.m_CoinPollData.a[0] + Rb8701.m_CoinPollData.a[1] + Rb8702.m_cNoteNum != 0 && this->m_payed == 0) 
	{
		if(this->disableDisplayFlag == 0){
			if(plocalcg02->langFlag == 0){
				for(int i=0;i<plocalcg02->graphPieceNumCN.size();i++){
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumDis" && plocalcg02->graphPieceNumCN[i].m_funcvalue != plocalcg02->m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumCN[i].m_funcname == "PieceNumDigitDis" && plocalcg02->graphPieceNumCN[i].m_funcvalue != plocalcg02->m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumCN[i]);
						plocalcg02->graphPieceNumCN[i].m_iShouldShow = 1;
						continue;
					}					
				}
				for(int i=0;i<plocalcg02->graphElementsCN.size();i++){
					if(plocalcg02->graphElementsCN[i].m_name == "CN_page2Goback--hot"){
						gp_ui->hideLabel(plocalcg02->graphElementsCN[i]);
						plocalcg02->graphElementsCN[i].m_iShouldShow = 0;
						continue;
					}					
				}				
			}
			else if(plocalcg02->langFlag == 1){
				for(int i=0;i<plocalcg02->graphPieceNumEN.size();i++){
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumDis" && plocalcg02->graphPieceNumEN[i].m_funcvalue != plocalcg02->m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}
					if(plocalcg02->graphPieceNumEN[i].m_funcname == "PieceNumDigitDis" && plocalcg02->graphPieceNumEN[i].m_funcvalue != plocalcg02->m_iPieceNum){
						gp_ui->showLabel(plocalcg02->graphPieceNumEN[i]);
						plocalcg02->graphPieceNumEN[i].m_iShouldShow = 1;
						continue;
					}					
				}
				for(int i=0;i<plocalcg02->graphElementsEN.size();i++){
					if(plocalcg02->graphElementsEN[i].m_name == "EN_page2Goback--hot"){
						gp_ui->hideLabel(plocalcg02->graphElementsEN[i]);
						plocalcg02->graphElementsEN[i].m_iShouldShow = 0;
						continue;
					}					
				}	
			}
			this->disableDisplayFlag = 1;
			plocalcg02->disableDisplayFlag = 1;
		}
		/*if( m_ButtType != DISABLE ) 
		{
			m_ButtType = DISABLE;
			this->ShowPieceButtBoard();

			gp_emitticket->MkTicketReady();
		}*/
	}

	//计算已付的钱数  
	if( strinput[0] == KIN_COIN )
	{
		this->m_payed_coin = Rb8701.m_CoinPollData.a[0] * 100 + Rb8701.m_CoinPollData.a[1] * 50;

		pwaiterdata->m_Coin5 = Rb8701.m_CoinPollData.a[1];
		pwaiterdata->m_Coin1 = Rb8701.m_CoinPollData.a[0];

		//if coin count = 30   //则该笔交易停止接收硬币   
		if( ( 30 == ( pwaiterdata->m_Coin5 + pwaiterdata->m_Coin1 ) ) &&
			( 3  == gp_coin->m_de_state ) )
		{
			// 关闭硬币投币口
			gp_coin->dCoinHold();
			gp_coin->dCoin_Stop( 0 );   //
		}
	}
	else
	if( strinput[0] == KIN_BILL )  
	{
		if( Rb8702.m_cNoteValue == 888 || Rb8702.m_cNoteNum == 888 ) // 此处检查参数3003允许的纸币类型 
		{
			Rb8702.m_cNoteValue = Rb8702.m_cNoteNum = 0;
			gp_bill->dBill_Refund();  //modify by jfren @20161122 

			if( !gp_medev->IsOnlyCoin() )
			{
				gp_bill->dBill_Work();
			}
		}
		else
		{
			this->m_payed_bill += Rb8702.m_cNoteValue * Rb8702.m_cNoteNum * 100;
			
			pwaiterdata->m_BillPieces.a[Rb8702.m_cNoteValue] += Rb8702.m_cNoteNum;
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "Rb8702.notevalue=["<<Rb8702.m_cNoteValue<<"],Notenum=["<<pwaiterdata->m_BillPieces.a[Rb8702.m_cNoteValue]<<"]");//add by jfren @20161123
			Rb8702.m_cNoteValue = Rb8702.m_cNoteNum = 0;
			//gp_bill->dBill_Encash();   //modify by jfren @20161122  默认到暂存
			if( !gp_medev->IsOnlyCoin() )
			{
				gp_bill->dBill_Work();
			}
		}
	}

	this->m_payed = m_payed_coin + m_payed_bill;
	

	//如果有投钱，则rc = 2
	if( m_payed != m_LastPayed )
	{
		rc = 2;
		m_LastPayed = m_payed;
	}

	//计算找零数。	
	if( m_payed >= iShouldPay )
	{
		this->m_chg = m_payed - iShouldPay ;
		if( !gp_medev->IsOnlyCoin() ) 
		{
			gp_bill->dBill_Stop(); //关闭投币口
		}
	}

	//this->ShowPayednchg();
	
	if( plocalcg02->m_SelectedScNode != u8arr_t<4>() )
		pwaiterdata->m_stationname = gp_db->GetThatStaName(plocalcg02->m_SelectedScNode); 
	pwaiterdata->m_ReceiveTotal = this->m_payed;
	pwaiterdata->m_ReceiveCoin = this->m_payed_coin;
	pwaiterdata->m_ReceiveBill = this->m_payed_bill;
	pwaiterdata->m_TickePriceTotal = iShouldPay;
	pwaiterdata->m_TickePrice1 = plocalcg02->m_iPrice;
	pwaiterdata->m_TicketoutPlan = m_iPieceNum; 
	pwaiterdata->m_ShouldChgTotal = this->m_chg;
	
	if(plocalcg02->langFlag == 0){
		char sz1[33];
		SClib::p_sprintf()( sz1, "%0.1f", this->m_chg / 100.00 );
		gp_ui->updateLabel(plocalcg02->graphElementsCN[plocalcg02->shouldChangeIndex],sz1);
		plocalcg02->graphElementsCN[plocalcg02->shouldChangeIndex].m_iShouldShow = 1;

		char sz2[33];
		SClib::p_sprintf()( sz2, "%0.1f", this->m_payed / 100.00 );
		gp_ui->updateLabel(plocalcg02->graphElementsCN[plocalcg02->payedIndex],sz2);
		plocalcg02->graphElementsCN[plocalcg02->payedIndex].m_iShouldShow = 1;
	}
	else if(plocalcg02->langFlag == 1){
		char sz1[33];
		SClib::p_sprintf()( sz1, "%0.1f", this->m_chg / 100.00 );
		gp_ui->updateLabel(plocalcg02->graphElementsEN[plocalcg02->shouldChangeIndex],sz1);
		plocalcg02->graphElementsEN[plocalcg02->shouldChangeIndex].m_iShouldShow = 1;

		char sz2[33];
		SClib::p_sprintf()( sz2, "%0.1f", this->m_payed / 100.00 );
		gp_ui->updateLabel(plocalcg02->graphElementsEN[plocalcg02->payedIndex],sz2);
		plocalcg02->graphElementsEN[plocalcg02->payedIndex].m_iShouldShow = 1;
	}

	
	//返回各种状态值	
	if( m_payed >= iShouldPay )
	{
		//other process
		/*
		plocalcg01->displayFlag = 0;
		plocalcg01->langFlag = 0;
		plocalcg01->errorFlag = 0;
		gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
		gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
		gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
		
		if(plocalcg02->langFlag == 0){
			plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
		}
		else if(plocalcg02->langFlag == 1){
			//TODO
			plocalcg02->cg02_graphElementsHide(plocalcg02->langFlag);
		}
		SetLanguageCh();*/
		rc =  1;
	}
	//plocalcg02->disableDisplayFlag = 0;

	return rc;
}




