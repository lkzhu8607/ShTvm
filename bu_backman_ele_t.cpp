#include "bu_timeshower_t.h"
#include "bu_backman_ele_t.h"
#include "de_log_t.h"
#include "de_moneylog_t.h"
#include "d_db_t.h"
#include "de_tcpmsg_t.h"
#include "d_db_t.h"
#include "d_config_t.h"
#include "a_label_t.h"
#include "de_ui_t.h"
#include "de_backinput_t.h"
#include "bu_backupg_t.h"
#include "bu_asynwork_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"
#include "de_topscr_t.h"
#include "de_printer_t.h"
#include "de_upsdev_t.h"
#include "de_frontinput_t.h"
#include "de_cashbox_t.h"
#include "g06.h"
#include "FTPManager.h"



#define HAVEUP ( m_iStart != 0 )
#define HAVEDN ( (tuint32)m_iStart + m_Scr2.size() < m_Scr1.size() )

#define GO_UP  if(HAVEUP) m_iStart -= m_MaxLineNum;
#define GO_DN  if(HAVEDN) m_iStart += m_MaxLineNum;


#define GAP				0.036	//段间距
#define XOFFSET			0.05	//X偏移 
#define YOFFSET			0.05	//Y偏移 
//#define SOPFONTSIZE		0.043
#define SOPFONTSIZE		0.023

#define TITLE_X   (0.0 + XOFFSET) 
#define TITLE_Y   (0.0 + YOFFSET)

#define INPUT_X		0.0 + XOFFSET 
#define INPUT_Y		TITLE_Y + SOPFONTSIZE + GAP 

#define UP_PAGE_X		0.0 + XOFFSET 
#define UP_PAGE_Y		INPUT_Y + SOPFONTSIZE  + GAP  + SOPFONTSIZE  + GAP + GAP + GAP 

#define DN_PAGE_X		0.0 + XOFFSET 
#define DN_PAGE_Y		UP_PAGE_Y + SOPFONTSIZE  + GAP 

//#define TIME_X		0.0 + XOFFSET 
//#define TIME_Y		0.950
#define TIME_X		TITLE_X + 0.65 
#define TIME_Y		TITLE_Y

#define CONTENT_X   0.25
#define CONTENT_Y   INPUT_Y + SOPFONTSIZE  + GAP  + GAP 

#define REMINDER_X  0.0 + XOFFSET 
#define REMINDER_Y  0.950



static std::string  iv_strMenuContent;



//
static void SOPLabel( const std::string & strName, const std::string & strValue, double x, double y )
{
	gp_ui->LabelMkStrPrep( 1, strName, strValue , 
							x , y , SOPFONTSIZE , "black" );
}

//
static void SOPLabel_Commit()
{
	gp_ui->LabelCommit();
}

//
static int UseChMap(int ch)
{
	if(1)
	{
		if( ch == 0xff1b || ch == 27 || ch == 0xffc8 || ch == 0xffc9 )		return 27;
		if( ch == 0xffc0 || ch == '-' )						return '-';
		if( ch == 0xffc1 || ch == 0x3d || ch == '+' )		return '+';
		if( ch == 0xff8d || ch == 0xff0d || ch == 0x0d )	return 0x0d;
		if( ch == 0xff08 || ch == 0x08 )					return 0x08;
		if( ch == 0xffb0 || ch == 0xff9e || ch == 0xff63 || ch == '0' )		return '0';
		if( ch == 0xffb1 || ch == 0xff9c || ch == 0xff57 || ch == '1' )		return '1';
		if( ch == 0xffb2 || ch == 0xff99 || ch == 0xff54 || ch == '2' )		return '2';
		if( ch == 0xffb3 || ch == 0xff9b || ch == 0xff56 || ch == '3' )		return '3';
		if( ch == 0xffb4 || ch == 0xff96 || ch == 0xff51 || ch == '4' )		return '4';
		if( ch == 0xffb5 || ch == 0xff9d ||                 ch == '5' )		return '5';
		if( ch == 0xffb6 || ch == 0xff98 || ch == 0xff53 || ch == '6' )		return '6';
		if( ch == 0xffb7 || ch == 0xff95 || ch == 0xff50 || ch == '7' )		return '7';
		if( ch == 0xffb8 || ch == 0xff97 || ch == 0xff52 || ch == '8' )		return '8';
		if( ch == 0xffb9 || ch == 0xff9a || ch == 0xff55 || ch == '9' )		return '9';
	
		return (ch & 0x7f);
	}
	//else
	//{
	//	return (ch & 0xff);
	//}
}

static std::string get_menu_ele( int x, int y )
{
	return SStrvs::vsa2v_get( iv_strMenuContent, std::string("\n"), 0, std::string("\t"), 0, y, x );
}



#include "bu_backman_ele_f_user_judge.xpp"
#include "bu_backman_ele_f_emitticket_sense.xpp"
#include "bu_backman_ele_menu_bind.xpp"
#include "bu_backman_ele_errcode_bind.xpp"






//
bu_backman_ele_t::bu_backman_ele_t() 
{
	m_MaxLineNum = 9;
	m_iStart = 0;

	m_Scr1.clear();
	m_Scr2.clear();

	m_strTitle = "TVM维护界面";
	m_strInput = "";

	iv_strMenuContent = bu_backman_ele_menu_bind();

	if( ! IsOsWin() && !iv_strMenuContent.empty() )
	{
		WFile::ChtoUtf8( iv_strMenuContent );
	}

	m_x = 0;
	m_y = 0;


	m_Ra3009 = a3009_t::ROWTYPE();

	m_IsJieSuan = 0;
	m_IsWeiHu = 0;

}



//
bu_backman_ele_t:: ~bu_backman_ele_t()
{
}



// 
void bu_backman_ele_t::tr_on_pre_thrd()
{
	m_Ra3009 = a3009_t::ROWTYPE();

	
	//要求输入账户
	f_user_judge();
	
	ShowCurrScr();
	WThrd::tr_sleepu(0.15);

	//如果正确
	GetCurrTitle();
	MkCurrMenu();
}



// 
int bu_backman_ele_t::tr_on_user_run()
{
	std::string  str1;
	int ch;
	
	do
	{
		ShowCurrScr();
		this->GetInputKey(str1);
	}while( str1 == "" );

	if( str1[0] != KIN_KEYPRESS ) 
		return 1;

	ch = UseChMap(SStrf::satol( str1.c_str() + 1 ));

	//处理input key。采用出错崩溃模型。当前输入加当前状态决定下次状态。 

	if( ch >= '1' && ch <= '9' )
	{
		while( m_strInput.size() > 0 )
		{
			m_strInput.erase( m_strInput.begin() );
		}

		m_strInput.append( 1,(char)ch );

		if( HaveAuthority() )
		{
			GoNext( SStrf::satol(m_strInput) );
		}

		if( HaveAuthority() )
		{
			GetCurrTitle();
			MkCurrMenu();
		}
		else
		{
			//显示没有权限的字样	
		}

		return 1;
	}

	if( ch == 27 ) // Esc	
	{
		m_Scr1.clear();
		m_strInput.clear();
		m_iStart = 0;

		//gp_medev->m_legal_authority=0;
		GoPrev();
		GetCurrTitle();
		MkCurrMenu();

		return 1;
	}

	return 1;
}



//
void bu_backman_ele_t::ShowCurrScr()
{
	SOPLabel( "#m_strTitle#", m_strTitle , TITLE_X , TITLE_Y );

	//SOPLabel( "#m_strInput#", m_strInput + "_" , INPUT_X , INPUT_Y  );


	if( HAVEUP )
	{
		SOPLabel( "#UP_PAGE#", "上翻↑" , UP_PAGE_X , UP_PAGE_Y  );
	}
	else
	{
		SOPLabel( "#UP_PAGE#", "" , UP_PAGE_X , UP_PAGE_Y  );
	}


	if( HAVEDN )
	{
		SOPLabel( "#DN_PAGE#", "下翻↓" , DN_PAGE_X , DN_PAGE_Y  );
	}
	else
	{
		SOPLabel( "#DN_PAGE#", "" , DN_PAGE_X , DN_PAGE_Y  );
	}

	SOPLabel( "#time#", SDte::GetNow().ReadString() , TIME_X , TIME_Y  );


	std::string strReminder = "";
	if(1)
	{
		//普通节点
		strReminder = "请通过数字键盘选取相应的功能,Esc键返回上一级菜单";
	}
	//else if()
	//{
	//	//叶子节点
	//	strReminder = "Esc键返回上一级菜单";
	//}
	SOPLabel( "#reminder#", strReminder , REMINDER_X , REMINDER_Y  );

	//清空集合2
	m_Scr2.clear();

	//构造集合2 
	for( int i = m_iStart; ; i++ )
	{
		if( (int)m_Scr2.size() >= m_MaxLineNum ) break; 
		if( i < (int)m_Scr1.size() )
			m_Scr2.push_back(m_Scr1[i]);
		else
			m_Scr2.push_back("");
	}

	//显示集合2
	for( int j = 0; j < (int)m_Scr2.size(); j++ )
	{
		SOPLabel( "#CONTENT#"+ SStrf::sltoa((int)j), m_Scr2[j] , CONTENT_X , CONTENT_Y + GAP * j * 2 );
	}

	SOPLabel_Commit();
}



//
void bu_backman_ele_t::GetInputKey( std::string & s )
{
	s = gp_backinput->GetKey();
	if( s == "" )
	{
	}
	else 
	{
	}
}


//
void bu_backman_ele_t::MkCurrMenu()
{
	int iCurrHead = 0;
	std::string strCurrEle;
	int j = m_y;

	m_Scr1.clear();

	for( int i = 0; i < 100 ; i++ )
	{
		strCurrEle = get_menu_ele( m_x, j++ );
		SStrf::strim( strCurrEle );

		if( strCurrEle == "" ) continue;

		if( SStrf::satol( strCurrEle ) < iCurrHead ) return;

		iCurrHead = SStrf::satol( strCurrEle );

		m_Scr1.push_back( SStrf::sltoa( (int)m_Scr1.size() + 1 ) + " " + SStrvs::vsa_get( strCurrEle, " ", 1, 1 ) );
	}

}


//
void bu_backman_ele_t::GetCurrTitle()
{
	int iCurrHead = 0;
	std::string strCurrEle;

	m_strTitle = "TVM维护";
	
	if( m_x == 0 ) return;

	for( int y = m_y; y >= 0 ; y-- )
	{
		strCurrEle = get_menu_ele( (m_x - 1) , y );
		SStrf::strim( strCurrEle );

		if( strCurrEle == "" ) continue;
		
		iCurrHead = SStrf::satol( strCurrEle );

		m_strTitle = SStrvs::vsa_get( strCurrEle, " ", 1, 1 );

		break;
	}
}


//
void bu_backman_ele_t::GoPrev()
{
	int iCurrHead = 0;
	std::string strCurrEle;

	if( m_x == 0 ) return;

	for( int y = m_y; y >= 0 ; y-- )
	{
		strCurrEle = get_menu_ele( (m_x - 1) , y );
		SStrf::strim( strCurrEle );

		if( strCurrEle == "" ) continue;
		
		iCurrHead = SStrf::satol( strCurrEle );

		m_y = y;

		break;
	}

	m_x --;

	//然后再向上，退到head==1 或到头 
	for( int y = m_y; y >= 0 ; y-- )
	{
		strCurrEle = get_menu_ele( m_x , y );
		SStrf::strim( strCurrEle );

		if( strCurrEle == "" ) continue;
	
		iCurrHead = SStrf::satol( strCurrEle );

		if( iCurrHead == 1 ) 
		{
			m_y = y;

			break;
		}
	}
}



//
void bu_backman_ele_t::GoNext( int iChoose )
{
	int iCurrHead = 0;
	std::string strCurrEle;
	int j = m_y;

	if( iChoose >=1 && iChoose <= 9 )
	{
	}
	else
	{
		return;
	}

	for( int i = 0; i < 100 ; i++ )
	{
		strCurrEle = get_menu_ele( m_x, j++ );
		SStrf::strim( strCurrEle );

		if( strCurrEle == "" ) continue;

		if( SStrf::satol( strCurrEle ) < iCurrHead ) return;

		iCurrHead = SStrf::satol( strCurrEle );

		if( iCurrHead == iChoose )
		{
			strCurrEle = get_menu_ele( m_x + 1, j-1 ) ;
			SStrf::strim( strCurrEle );
	
			iCurrHead = SStrf::satol( strCurrEle );

			if( strCurrEle != "" && iCurrHead != 0 )
			{
				m_y = j-1;
				m_x ++;
				return;
			}
			else
			{
				for( int x = m_x; ; x ++ )
				{
					strCurrEle = get_menu_ele( x, j-1 );
					SStrf::strim( strCurrEle );
					if( strCurrEle[0] == 'f' )
					{
						OnRunFunc(strCurrEle);
						return;
					}
				}
			}
		}
	}
}




//
tbool bu_backman_ele_t::HaveAuthority()
{
		//		操作员类别
		//0–票款员——不能维护
		//2–维护人员——不能访问票款 

	if( m_Ra3009.m_biIsAffect != 1 )
		return 0;

	if( m_Ra3009.m_OpManType == 3 )
		return 1;

	if( m_Ra3009.m_OpManType == 4 )
		return 1;

	if( m_Ra3009.m_OpManType == 0 )
	{
		if( (m_x+1) >= 1 && (m_x+1) <= 42 )
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	if( m_Ra3009.m_OpManType == 2 )
	{
		if( (m_x+1) >= 42 && (m_x+1) <= 50 )
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}



//
void bu_backman_ele_t::OnRunFunc( std::string strFuncName )
{
	do{
		//1
		if( strFuncName == "f_user_judge" )				{ f_user_judge(); break; }

		if( strFuncName == "f_whole_status" )			{ f_whole_status();	break; }
		if( strFuncName == "f_show_ver" )				{ f_show_ver();	break; }
		if( strFuncName == "f_show_err_codes" )			{ f_show_err_codes();	break; }
		if( strFuncName == "f_dev_id" )					{ f_dev_id();	break; }
		if( strFuncName == "f_coincontrol_sense" )		{ f_coincontrol_sense();	break; }
		if( strFuncName == "f_eod_ver" )				{ f_eod_ver();	break; }

		if( strFuncName == "f_Udisk" )					{ f_Udisk();	break; }
		if( strFuncName == "f_clear_all" )				{ f_clear_all(); break; }

		//2_1
		if( strFuncName == "f_tvm_on_off_show" )		{ f_tvm_on_off_show(); break; }
		if( strFuncName == "f_tvm_on_off_on" )			{ f_tvm_on_off_on(); break; }
		if( strFuncName == "f_tvm_on_off_off" )			{ f_tvm_on_off_off(); break; }

		//2_2
		if( strFuncName == "f_ShowCurrCoinMode" )		{ f_ShowCurrCoinMode();	break; }
		if( strFuncName == "f_CurrCoinRecive" )			{ f_CurrCoinRecive();	break; }
		if( strFuncName == "f_CurrCoinNoRecive" )		{ f_CurrCoinNoRecive();	break; }

		//2_3
		if(strFuncName == "f_ShowCurrBillMode")			{ f_ShowCurrBillMode();break;}
		if(strFuncName == "f_CurrBillRecive")			{ f_CurrBillRecive();break;}
		if(strFuncName == "f_CurrBillNoRecive")			{ f_CurrBillNoRecive();break;}

		//2_4
		if(strFuncName == "f_ShowCurrBillChangeMode")	{ f_ShowCurrBillChangeMode();break;}
		if(strFuncName == "f_UseBillChange")			{ f_UseBillChange();break;}
		if(strFuncName == "f_StopUseBillChange")		{ f_StopUseBillChange();break;}

		//2_5
		if(strFuncName == "f_ShowCurrPrintMode")		{ f_ShowCurrPrintMode();break;}
		if(strFuncName == "f_StartPrint")				{ f_StartPrint();break;}
		if(strFuncName == "f_StopPrint")				{ f_StopPrint();break;}

		//2_6
		if(strFuncName == "f_ShowCurrOpenDoorSellMode")	{ f_ShowCurrOpenDoorSellMode();break;}
		if(strFuncName == "f_OpenDoorSellStart")		{ f_OpenDoorSellStart();break;}
		if(strFuncName == "f_OpenDoorSellStop")			{ f_OpenDoorSellStop();break;}

		//2_7 - 2_8
		if( strFuncName == "f_reboot" )					{ f_reboot();	break; }
		if( strFuncName == "f_shutdown" )				{ f_shutdown();	break; }


		//3_1
		if( strFuncName == "f_GuakaMada_Test" )			{ f_GuakaMada_Test();	break; }
		if( strFuncName == "f_TransMada_Test" )			{ f_TransMada_Test();	break; }
		if( strFuncName == "f_StopMotor_Test" )			{ f_StopMotor_Test();	break; }
		if( strFuncName == "f_ChangeBox_Test" )			{ f_ChangeBox_Test();	break; }
		if( strFuncName == "f_Sell1TestTicket" )		{ f_Sell1TestTicket();	break; }

		//3_2
		if( strFuncName == "f_CoinRecognizer_Test" )	{ f_CoinRecognizer_Test();	break; }
		if( strFuncName == "f_CoinStock_Test" )			{ f_CoinStock_Test();	break; }
		if( strFuncName == "f_CoinReturn_Test" )		{ f_CoinReturn_Test();	break; }
		if( strFuncName == "f_CoinRecycieBox_Test" )	{ f_CoinRecycieBox_Test();	break; }

		//3_3
		if( strFuncName == "f_BillMotorReset_Test" )	{ f_BillMotorReset_Test();	break; }
		if( strFuncName == "f_BillRecive_Test" )		{ f_BillRecive_Test();	break; }
		if( strFuncName == "f_BillStock_Test" )			{ f_BillStock_Test();	break; }
		if( strFuncName == "f_BillReturn_Test" )		{ f_BillReturn_Test();	break; }
		if( strFuncName == "f_BillCollect_Test" )		{ f_BillCollect_Test();	break; }
		if( strFuncName == "f_ClearnBillChannel" )		{ f_ClearnBillChannel();	break; }

		//3_4 - 3_8
		if( strFuncName == "f_OpenWarnning" )			{ f_OpenWarnning();	break; }
		if( strFuncName == "f_StopWarnning" )			{ f_StopWarnning();	break; }
		if( strFuncName == "f_OpenLight" )				{ f_OpenLight();	break; }
		if( strFuncName == "f_CloseLight" )				{ f_CloseLight();	break; }
		if( strFuncName == "f_StatusDisplay_Test" )		{ f_StatusDisplay_Test();	break; }

		//4_1  - 4_4
		if( strFuncName == "f_Print_Aduit_Report" )		{ f_Print_Aduit_Report();	break; }
		if( strFuncName == "f_Print_Profit_Report" )	{ f_Print_Profit_Report();	break; }
		if( strFuncName == "f_Print_Ticket_Report" )	{ f_Print_Ticket_Report();	break; }
		if( strFuncName == "f_Print_Trade_Report" )		{ f_Print_Trade_Report();	break; }

		//5_1 
		if( strFuncName == "f_Show6000Data" )           { f_Show6000Data(); break; }

		//6
		if( strFuncName == "f_SelectTransData" )        { f_SelectTransData(); break; }
		
		//7
		if( strFuncName == "f_account" )			    { f_account();	break; }
		if( strFuncName == "f_maintenance" )			{ f_maintenance();	break; }
		if( strFuncName == "f_ClearingCoin" )			{ f_ClearingCoin();	break; }
		if( strFuncName == "f_CleaningBill")            { f_CleaningBill(); break; }
		if( strFuncName == "f_RepCoin" )				{ f_RepCoin();	break; }
		if( strFuncName == "f_RepBill" )				{ f_RepBill();	break; }
		//8
		if( strFuncName == "f_Reset" )				    { f_Reset();	break; }


		m_Scr1.clear();
		m_Scr1.push_back( strFuncName );
		for( int j = 0; j < 55; j++ )
		{
			m_Scr1.push_back( SStrf::sltoa(j) );
		}
	}while(0);


	std::string  str1;
	int ch;
	
	if( m_Scr1.empty() )	// 无内容，就是退出的意思	
		return;

L_SHOWAGAIN:
	for(;;)
	{
		ShowCurrScr();
		this->GetInputKey(str1);

		if( str1 != "" ) 
		{
			if( str1[0] != KIN_KEYPRESS ) continue;
			break;
		}
	}

	ch = UseChMap(SStrf::satol( str1.c_str() + 1 ));
	
	if( ch == 27 || ch == 0x0d ) // Esc		if( ch == 0x0d ) // CR	
	{
		m_Scr1.clear();
		m_strInput.clear();
		m_iStart = 0;
		return;
	}

	if( ch == '-' ) //pg up
	{
		if( HAVEUP )
			m_iStart -= m_MaxLineNum;
		
		goto L_SHOWAGAIN;
	}
	
	if( ch == '+' ) //pg dn
	{
		if( HAVEDN )
			m_iStart += m_MaxLineNum;
		
		goto L_SHOWAGAIN;
	}
	
	goto L_SHOWAGAIN;
}



//
void bu_backman_ele_t::f_Udisk() 
{
	backupg_go();

	m_Scr1.clear();

	m_Scr1.push_back( "U盘升级过程正在启动" );
}



//
void bu_backman_ele_t::f_clear_all() 
{
	if( !IsOsWin() )
		gp_db->CleanPara();

	m_Scr1.clear();

	m_Scr1.push_back( "已清空参数。准备重启。" );

	bu_asynwork_t::DelayReboot(3);
}



//
void bu_backman_ele_t::f_tvm_on_off_show() 
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "TVM是否开启:" );
	
	a9999_t::ROWTYPE & Ra9999(gp_db->GetTheRowa9999());

	if( Ra9999.m_stopservice_sc_flag == 0 )
		m_Scr1.push_back( "..............TVM开启" );

	if( Ra9999.m_stopservice_sc_flag == 1 )
		m_Scr1.push_back( "..............TVM关闭" );
}



//
void bu_backman_ele_t::f_tvm_on_off_on() 
{
	a9999_t::ROWTYPE & Ra9999(gp_db->GetTheRowa9999());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定TVM为开启状态:" );
	
	Ra9999.m_stopservice_sc_flag = 0;
	gp_db->RiseSaveFlag(gp_db->m_a9999);

	m_Scr1.push_back( "..............TVM开启" );
	
	gp_frontinput->input_KIN_APP();
}


//
void bu_backman_ele_t::f_tvm_on_off_off() 
{
	a9999_t::ROWTYPE & Ra9999(gp_db->GetTheRowa9999());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定TVM为关闭状态:" );
	
	Ra9999.m_stopservice_sc_flag = 1;
	gp_db->RiseSaveFlag(gp_db->m_a9999);

	m_Scr1.push_back( "..............TVM关闭" );

	gp_frontinput->input_KIN_APP();
}


//
void bu_backman_ele_t::f_ShowCurrCoinMode() 
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "显示当前硬币模块是否开启:" );
	
	b8701_t::ROWTYPE &R8701(gp_db->GetTheRowb8701());

	if( R8701.m_CoinStopUseFlag == 0 )
		m_Scr1.push_back( "..............硬币模块开启" );

	if( R8701.m_CoinStopUseFlag == 1 )
		m_Scr1.push_back( "..............硬币模块关闭" );
}


//
void bu_backman_ele_t::f_CurrCoinRecive() 
{
	b8701_t::ROWTYPE &R8701(gp_db->GetTheRowb8701());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前硬币模块为开启状态:" );
	
	R8701.m_CoinStopUseFlag = 0;
	gp_db->RiseSaveFlag(gp_db->m_b8701);

	m_Scr1.push_back( "..............硬币模块开启" );
	
	gp_frontinput->input_KIN_COIN();
}


//
void bu_backman_ele_t::f_CurrCoinNoRecive() 
{
	b8701_t::ROWTYPE &R8701(gp_db->GetTheRowb8701());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前硬币模块为关闭状态:" );
	
	R8701.m_CoinStopUseFlag = 1;
	gp_db->RiseSaveFlag(gp_db->m_b8701);

	m_Scr1.push_back( "..............硬币模块关闭" );
	
	gp_frontinput->input_KIN_COIN();
}


//
void bu_backman_ele_t::f_ShowCurrBillMode() 
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "显示当前纸币模式是否开启接收:" );
	
	b8702_t::ROWTYPE &R8702(gp_db->GetTheRowb8702());

	if( R8702.m_BillStopUseFlag == 0 )
		m_Scr1.push_back( "..............当前纸币接收" );

	if( R8702.m_BillStopUseFlag == 1 )
		m_Scr1.push_back( "..............当前纸币不接收" );
}


//
void bu_backman_ele_t::f_CurrBillRecive() 
{
	b8702_t::ROWTYPE &R8702(gp_db->GetTheRowb8702());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前纸币模式是开启接收状态:" );
	
	R8702.m_BillStopUseFlag = 0;
	gp_db->RiseSaveFlag(gp_db->m_b8702);

	m_Scr1.push_back( "..............当前纸币接收" );
	
	gp_frontinput->input_KIN_BILL();
}


//
void bu_backman_ele_t::f_CurrBillNoRecive() 
{
	b8702_t::ROWTYPE &R8702(gp_db->GetTheRowb8702());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前纸币模式为关闭状态:" );
	
	R8702.m_BillStopUseFlag = 1;
	gp_db->RiseSaveFlag(gp_db->m_b8702);

	m_Scr1.push_back( "..............当前纸币不接收" );
	
	gp_frontinput->input_KIN_BILL();
}



void bu_backman_ele_t::f_ShowCurrBillChangeMode()
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "显示当前找零模式是否使用:" );
	
	//b8705_t::ROWTYPE &R8705(gp_db->GetTheRowb8705());

	//if( R8705.m_BillchgStopUseFlag == 0 )

	if( ( 0 == SStrf::readbit( gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0], 0 ) ) )
	{
		m_Scr1.push_back( "..............当前找零不使用" );
	}
	else
	{
		m_Scr1.push_back( "..............当前找零使用" );
	}
}

void bu_backman_ele_t::f_UseBillChange()
{
	//b8705_t::ROWTYPE &R8705(gp_db->GetTheRowb8705());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前找零模式是开启使用状态:" );
	
	//R8705.m_BillchgStopUseFlag = 0;
	//gp_db->RiseSaveFlag(gp_db->m_b8705);
	gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0] = 1;

	m_Scr1.push_back( "..............当前找零使用" );
	
	gp_frontinput->input_KIN_BILL();
}

void bu_backman_ele_t::f_StopUseBillChange()
{
	//b8705_t::ROWTYPE &R8705(gp_db->GetTheRowb8705());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定当前找零模式是停用状态:" );
	
	//R8705.m_BillchgStopUseFlag = 1;
	//gp_db->RiseSaveFlag(gp_db->m_b8705);
	gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0] = 0;

	m_Scr1.push_back( "..............当前找零不使用" );
	
	gp_frontinput->input_KIN_BILL();
}

void bu_backman_ele_t::f_ShowCurrPrintMode()
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "显示当前打印机模式:" );
	
	b8707_t::ROWTYPE &R8707(gp_db->GetTheRowb8707());

	if( R8707.m_PrinterStopUseFlag == 0 )
		m_Scr1.push_back( "..............当前打印机使用" );

	if( R8707.m_PrinterStopUseFlag == 1 )
		m_Scr1.push_back( "..............当前打印机不使用" );
}

void bu_backman_ele_t::f_StartPrint()
{
	b8707_t::ROWTYPE &R8707(gp_db->GetTheRowb8707());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定打印机开启:" );
	
	R8707.m_PrinterStopUseFlag = 0;
	gp_db->RiseSaveFlag(gp_db->m_b8707);

	m_Scr1.push_back( "..............打印机开启" );
	
	gp_frontinput->input_KIN_PRINTER();
}

void bu_backman_ele_t::f_StopPrint()
{
	b8707_t::ROWTYPE &R8707(gp_db->GetTheRowb8707());

	m_Scr1.clear();
	
	m_Scr1.push_back( "设定打印机关闭:" );
	
	R8707.m_PrinterStopUseFlag = 1;
	gp_db->RiseSaveFlag(gp_db->m_b8707);

	m_Scr1.push_back( "..............打印机关闭" );
	
	gp_frontinput->input_KIN_PRINTER();
}

void bu_backman_ele_t::f_ShowCurrOpenDoorSellMode()
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "显示当前门开售票模式:" );
	
	if( ( 0 == gp_medev->m_IsOpenDoorSellModule ) )
	{
		m_Scr1.push_back( "..............当前门开售票模式不使用" );
	}
	else
	{
		m_Scr1.push_back( "..............当前门开售票模式使用" );
	}
}

void bu_backman_ele_t::f_OpenDoorSellStart()
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "开启门开售票模式:" );
	
	gp_medev->m_IsOpenDoorSellModule = 1;

	m_Scr1.push_back( "..............门开售票模式开启" );

	gp_frontinput->input_KIN_APP();
	
}

void bu_backman_ele_t::f_OpenDoorSellStop()
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "关闭门开售票模式:" );
	
	gp_medev->m_IsOpenDoorSellModule = 0;

	m_Scr1.push_back( "..............门开售票模式关闭" );

	gp_frontinput->input_KIN_APP();
	
}

//
void bu_backman_ele_t::f_reboot() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "准备重启。" );

	bu_asynwork_t::DelayReboot(1);
}


//
void bu_backman_ele_t::f_shutdown() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "准备关机。" );

	gp_conf->m_biSysShouldShutdown = 1;
}


 



//
void bu_backman_ele_t::f_GuakaMada_Test() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "刮卡马达测试" );

	ShowCurrScr();

	if( gp_emitticket->eTicket_PowerTest(0x01) == 0 )	//	0x01-刮卡电机测试；
	{
		m_Scr1.push_back( "发送命令成功" );
	}
	else
	{
		m_Scr1.push_back( "发送命令失败" );
	}
}


//
void bu_backman_ele_t::f_TransMada_Test() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "传输马达测试" );

	ShowCurrScr();

	if( gp_emitticket->eTicket_PowerTest(0x03) == 0 )	//	0x03-传输电机测试	
	{
		m_Scr1.push_back( "发送命令成功" );
	}
	else
	{
		m_Scr1.push_back( "发送命令失败" );
	}
}


//
void bu_backman_ele_t::f_StopMotor_Test() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "电机测试关闭" );

	ShowCurrScr();

	if( gp_emitticket->eTicket_PowerTest(0x05) == 0 )	//	0x05-电机测试关闭		
	{
		m_Scr1.push_back( "发送命令成功" );
	}
	else
	{
		m_Scr1.push_back( "发送命令失败" );
	}
}

//
void bu_backman_ele_t::f_ChangeBox_Test() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "换箱测试" );

	ShowCurrScr();

	if( gp_emitticket->eTicket_ExchangeBox() == 0 )	 
	{
		m_Scr1.push_back( "发送命令成功" );
	}
	else
	{
		m_Scr1.push_back( "发送命令失败" );
	}
}


//
void bu_backman_ele_t::f_Sell1TestTicket() 
{
	tbool rc;
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "发售3元测试票" );

	ShowCurrScr();

	rc = gp_emitticket->MkTicketReady();
	if( rc == 0 )	 
	{
		m_Scr1.push_back( "票到读写位置命令失败" );
		return ;
	}

	for( int i = 1;i<101;i++ )
	{

		//写入1元	
		ret = gp_reader1->rReadCard();
		if( ret == 0 )	 
		{
			ret = gp_reader1->rSaleCard2( 1000 );
			if( ret == 0 )	 
			{
				//票发出	
				ret = gp_emitticket->eTicket_SendOut();
				if( ret == 0 )	 
				{
					wl::WThrd::tr_sleepu( 0.1 );
					if( i%10 == 0 )
					{
						gp_emitticket->eTicket_CleanEscrow(0x01);
						if( ret == 0 )	 
						{
							
						}
						else
						{
							m_Scr1.push_back( "清暂存失败" );
							return ;
						}
					}
					continue;
				}
				else
				{
					m_Scr1.push_back( "将票卡发往乘客方向失败" );
				}
			}
			else
			{
				m_Scr1.push_back( "写入1元信息失败" );
			}
		}
		else
		{
			m_Scr1.push_back( "票信息读出失败" );
		}
		
		//进废票箱
		if( gp_emitticket->eTicket_SendIn() )   //进回收票箱
		{
			m_Scr1.push_back( "进回收箱失败" );
			return ;
		}

		wl::WThrd::tr_sleepu( 0.1 );
	}

	gp_emitticket->eTicket_CleanEscrow(0x01);
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "清暂存失败" );
		return ;
	}
	 
	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_CoinRecognizer_Test()
{
	int ret;
	int ch;

	m_Scr1.clear();

	m_Scr1.push_back( "硬币设别器测试" );

	ShowCurrScr();

	ret = 0;


	//1.work     { 打开投币口 }
	ret = gp_coin->dCoinHold();
	ret = gp_coin->dCoin_Work( 1, 1 );
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "打开硬币投币口失败" );
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "dCoin_Work Error ret = "<<ret );
		return ;
	}

	//2.while(1) { 查询是否有投钱，显示 }
	std::string str1;
	int iThrowth = 0;
	BYTE bLastThrow1YuanCount = 0;
	BYTE bLastThrow5MaoCount = 0;
	b8701_t::ROWTYPE &R8701(gp_db->GetTheRowb8701());
	while(1)
	{
		gp_coin->dCoin_Query();
		//bThisThrowCount = R8701.m_CoinPollData.a[0]*100 + R8701.m_CoinPollData.a[1]*50 ;
		if( ( R8701.m_CoinPollData.a[0] - bLastThrow1YuanCount ) ||
			( R8701.m_CoinPollData.a[1] - bLastThrow5MaoCount ) )
		{
			//char sz1[33];
			//SClib::p_sprintf()( sz1, "%0.1f", ( bThisThrowCount - bLastThrowCount ) / 100.00 );
			iThrowth++;
			if(  R8701.m_CoinPollData.a[0] - bLastThrow1YuanCount )
			{
				m_Scr1.push_back( "第" + wl::SStrf::sltoa(iThrowth) + "次投入: 1.0");
			}
			else
			{
				m_Scr1.push_back( "第" + wl::SStrf::sltoa(iThrowth) + "次投入: 0.5" );
			}

			ShowCurrScr();
			bLastThrow1YuanCount = R8701.m_CoinPollData.a[0];
			bLastThrow5MaoCount = R8701.m_CoinPollData.a[1];
			//bLastThrowCount = bThisThrowCount;
		}

		this->GetInputKey(str1);
		if( str1 != "" ) 
		{
			if( str1[0] == KIN_KEYPRESS )
			{
				ch = UseChMap(SStrf::satol( str1.c_str() + 1 ));
		
				if( ch == 27 || ch == 0x0d ) // Esc		if( ch == 0x0d ) // CR	
				{
					break;
				}
			}
		}
		
		wl::WThrd::tr_sleepu(0.1);

	}
	//3.if(退出) { 关闭投币口 }
	gp_coin->dCoin_Stop();
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "硬币投币口关闭失败" );
		return ;
	}

	m_Scr1.push_back( "测试命令成功" );
}

void bu_backman_ele_t::f_CoinStock_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "硬币进循环箱测试" );

	ShowCurrScr();

	ret = 0;

	//1.硬币进循环箱
	ret = gp_coin->dCoin2CircleChg();
	
	if( ret != 0 )	 
	{
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "dCoin2CircleChg Error ret = "<<ret );
		m_Scr1.push_back( "硬币进循环箱测试命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_CoinReturn_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "硬币退币测试" );

	ShowCurrScr();

	ret = 0;
	//1.硬币退币
	gp_coin->returnCoin();
	
	if( ret != 0 )	 
	{
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "returnCoin Error ret="<<ret );
		m_Scr1.push_back( "硬币退币测试命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_CoinRecycieBox_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "硬币进回收箱测试" );

	ShowCurrScr();

	ret = 0;
	//1.硬币进回收箱
	ret = gp_coin->dCoin2StoreBox();
	
	if( ret != 0 )	 
	{
		LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "dCoin2StoreBox Error ret ="<<ret );
		m_Scr1.push_back( "硬币进回收箱测试命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

//
void bu_backman_ele_t::f_BillMotorReset_Test() 
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "纸币识别器复位" );

	ShowCurrScr();

	ret = gp_bill->dBill_Reset(true);
	
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "纸币识别器复位命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_BillRecive_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "纸币接收测试" );

	ShowCurrScr();

	//1.纸币口打开
	ret = gp_bill->dBill_Work();
	//if( ret != 0 )	 
	//{
	//	m_Scr1.push_back( "打开纸币口命令失败" );
	//	//return ;
	//}

	//2.while(1) 查询投入纸币
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	int iThrowCount = 0;
	std::string str1 = "";;
	//std::string strShowThrowMess = "";
	int ch ;

	Rb8702.m_cNoteValue = 0;

	while(1)
	{
		gp_bill->dBill_Query();

		if( Rb8702.m_cNoteValue )
		{
			iThrowCount++;
			//sprintf( (&strShowThrowMess[0]),"第%d次投入：%d",iThrowCount,Rb8702.m_cNoteValue);
			m_Scr1.push_back( "第" + wl::SStrf::sltoa(iThrowCount) + "次投入:" + wl::SStrf::sltoa(Rb8702.m_cNoteValue) );

			Rb8702.m_cNoteValue =Rb8702.m_cNoteNum = 0;
			ShowCurrScr();
			//break;
			ret = gp_bill->dBill_Work();
			if( ret != 0 )	 
			{
				m_Scr1.push_back( "打开纸币口命令失败" );
				return ;
			}

		}

		this->GetInputKey(str1);
		if( str1 != "" ) 
		{
			if( str1[0] == KIN_KEYPRESS )
			{
				ch = UseChMap(SStrf::satol( str1.c_str() + 1 ));
		
				if( ch == 27 || ch == 0x0d ) // Esc		if( ch == 0x0d ) // CR	
				{
					break;
				}
			}
		}
		
		wl::WThrd::tr_sleepu(0.1);

	}
	//3.关闭纸币口

	gp_bill->dBill_Stop();
	
	m_Scr1.push_back( "测试成功" );
}

void bu_backman_ele_t::f_BillStock_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "暂存纸币测试" );

	ShowCurrScr();

	//1.纸币进入暂存
	ret = gp_bill->dBill_Encash();
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "暂存纸币命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_BillReturn_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "纸币退币测试" );

	ShowCurrScr();

	//1.纸币退币
	ret = gp_bill->dBill_Refund();

	if( ret != 0 )	 
	{
		m_Scr1.push_back( "纸币退币命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_BillCollect_Test()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "纸币进入钱箱测试" );

	ShowCurrScr();

	//1.纸币进入钱箱
	ret = gp_bill->dBill_Encash();

	if( ret != 0 )	 
	{
		m_Scr1.push_back( "纸币进入钱箱命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}

void bu_backman_ele_t::f_ClearnBillChannel()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "清纸币通道测试" );

	ShowCurrScr();

	//1.清纸币通道
	//ret = gp_bill->dBill_Encash();

	//if( ret != 0 )	 
	//{
	//	m_Scr1.push_back( "清纸币通道命令失败" );
	//	return ;
	//}

	m_Scr1.push_back( "发送命令成功" );
}


//
void bu_backman_ele_t::f_OpenWarnning() 
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "报警打开" );

	ShowCurrScr();

	ret = gp_coin->dCoinOpenAlert();
	LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "ret：" <<ret );


	if( ret != 0 )	 
	{
		m_Scr1.push_back( "报警打开命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}


//
void bu_backman_ele_t::f_StopWarnning() 
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "报警关闭" );

	ShowCurrScr();

	ret = gp_coin->dCoinCloseAlert();
	LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "ret：" <<ret );


	if( ret != 0 )	 
	{
		m_Scr1.push_back( "报警关闭命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}


//
void bu_backman_ele_t::f_OpenLight() 
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "打开前照明和取票灯" );

	ShowCurrScr();

	ret = gp_coin->dCoinOpenUplight();
	ret = gp_coin->dCoinOpenDownlight();

	LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "ret：" <<ret );
	if( ret != 0 )	 
	{
		m_Scr1.push_back( "打开前照明和取票灯命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}


//
void bu_backman_ele_t::f_CloseLight() 
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "关闭前照明和取票灯" );

	ShowCurrScr();

	ret = gp_coin->dCoinCloseUplight();
	ret = gp_coin->dCoinCloseDownlight();
	LOGSTREAM( gp_log[LOGSOP], LOGPOSI << "ret：" <<ret );

	if( ret != 0 )	 
	{
		m_Scr1.push_back( "关闭前照明和取票灯命令失败" );
		return ;
	}

	m_Scr1.push_back( "发送命令成功" );
}


//
void bu_backman_ele_t::f_StatusDisplay_Test() 
{
	std::string str;

	m_Scr1.clear();

	m_Scr1.push_back( "状态显示器测试" );

	ShowCurrScr();

	str = "上海地铁的吉祥物是畅畅。畅畅是一个来自未来的小机器人，圆润的流线型动感十足，微笑的眼睛透露亲切，现代化的装备科技十足，体内蕴含着热情与力量。畅畅的设计，演绎出上海地铁与都市的密切关系，现代、动感、时尚。畅畅，是上海地铁的形象化身，微笑自信的表情诠释出上海地铁积极进取无限开拓的品牌形象。";
	
	if( !gp_conf->IsOsWin() && !str.empty() )
	{
		WFile::Utf8toCh( str );
	}
	
	gp_topscr->DispStr( str );
	
	m_Scr1.push_back( "发送命令完毕。" );
}

void bu_backman_ele_t::f_Print_Aduit_Report()
{

	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "打印审计报表" );

	ShowCurrScr();
	std::string str = "“a”为了减缓全球变暖的趋势，科学家们想尽了各种办法，而有人则提出了阻挡太阳光进入地球的想法，这可行吗？我们究竟该做些什么？用改装过的飞机喷射出硫酸就可以让北极上空的天空保持灰霾状态好几年，“而这只需要制作一部好莱坞大片的费用”，哈佛大学的物理学家戴维&#8226;基思（DavidKeith）如此说道。他还断言，只需花10亿美元，就能让整个地球在2020年左右被硫酸液滴包裹。" ;
	gp_printer->PrintStr( str );
	//gp_printer->HalfCutAsync();

	m_Scr1.push_back( "打印报表成功" );

}
void bu_backman_ele_t::f_Print_Profit_Report()
{

	int ret;
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]
	BYTE t_line = 0x0F;
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);
	int lineNum = (t_line * 10);
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;
	lineNum += t_line;


	wl::SDte YunYingStartDt = wl::SDte::GetNow();
	wl::SDte YunYingEndDt = wl::SDte::GetNow();
	GetYunYingDT(YunYingStartDt,YunYingEndDt);

	

	std::map<int ,int > MapReceiveBill;  // index 5元 10元 20元 50元 100元 
	int ReceiveCoin[2] = {0};	//1元 5角 
	long lReceiveCoinAmount = 0;
	long lReceivceBillAmount = 0;
	long lCoinChgAmount = 0;
	long lBillChgAmount = 0;
	long lCoinAddAmount = 0;
	long lBillAddAmount = 0;
	long lCoinCleanAmount = 0;
	int iYunYingStartCoinChgBoxAmount = 0;
	int iYunYingStartBillChgBoxAmount = 0;
	int iYunYingEndBillChgBoxAmount = 0;
	long lOverPayAmount = 0;
	long lTodayProfileAmount = 0;

	std::map<int ,int > MapSaleTicket;   // iTicketPrice = m_TickePrice1 分

	int iBadTicketAmount = 0;
	int iSaleTicketAmount = 0;

	for(long l = gp_db->m_a_waiter_t.GetRowCount()-1;l > 0;l--)
	{
		if(gp_db->m_a_waiter_t.GetRow(l).m_begin_time >= YunYingStartDt )
		{
			
			MapSaleTicket[gp_db->m_a_waiter_t.GetRow(l).m_TickePrice1] += gp_db->m_a_waiter_t.GetRow(l).m_TicketoutActual;

			ReceiveCoin[0] += gp_db->m_a_waiter_t.GetRow(l).m_Coin1;
			ReceiveCoin[1] += gp_db->m_a_waiter_t.GetRow(l).m_Coin5;

			MapReceiveBill[5] += gp_db->m_a_waiter_t.GetRow(l).m_BillPieces.a[5];
			MapReceiveBill[10] += gp_db->m_a_waiter_t.GetRow(l).m_BillPieces.a[10];
			MapReceiveBill[20] += gp_db->m_a_waiter_t.GetRow(l).m_BillPieces.a[20];
			MapReceiveBill[50] += gp_db->m_a_waiter_t.GetRow(l).m_BillPieces.a[50];
			MapReceiveBill[100] += gp_db->m_a_waiter_t.GetRow(l).m_BillPieces.a[100];

			lCoinChgAmount += gp_db->m_a_waiter_t.GetRow(l).m_CoinRecycleChgActual;
			lBillChgAmount += gp_db->m_a_waiter_t.GetRow(l).m_BilchgActual;

			lCoinAddAmount += 0;
			lBillAddAmount += 0;
			lCoinCleanAmount += 0;
			lOverPayAmount += ( gp_db->m_a_waiter_t.GetRow(l).m_ShouldChgTotal - 
				                gp_db->m_a_waiter_t.GetRow(l).m_CoinRecycleChgActual -
								gp_db->m_a_waiter_t.GetRow(l).m_BilchgActual );

			iBadTicketAmount += 0;

		}
		else
		{
			break;
		}
	}

	lReceiveCoinAmount =  (ReceiveCoin[1] * 50 + ReceiveCoin[0]*100)/100 ;
	lReceivceBillAmount = ( MapReceiveBill[5]*500 + MapReceiveBill[10]*1000 + 
						    MapReceiveBill[20]*2000 + MapReceiveBill[50]*5000 + 
						    MapReceiveBill[100]*10000 )/100 ;

	lTodayProfileAmount = ( lReceiveCoinAmount + lReceivceBillAmount);

	iSaleTicketAmount = MapSaleTicket[200] + MapSaleTicket[300] +
						MapSaleTicket[400] + MapSaleTicket[500] +
				        MapSaleTicket[600] + MapSaleTicket[700] +
						MapSaleTicket[800] + MapSaleTicket[900] +
						MapSaleTicket[1000] + iBadTicketAmount;
	
	m_Scr1.clear();

	m_Scr1.push_back( "打印收益报表" );

	ShowCurrScr();
	char str[4096] = {0};
	sprintf(str,"    上海地铁TVM每日收益报表\n"
				"车站                     %s\n"
				"线路                     轨道交通%d号线\n"
				"设备号                   \n\n"
				"操作员ID                 %d\n"
				"结算时间              %s\n\n"
				"5元纸币收入张数          %d张\n"
				"10元纸币收入张数         %d张\n"
				"20元纸币收入张数         %d张\n"
				"50元纸币收入张数         %d张\n"
				"100元纸币收入张数        %d张\n"
				"1元硬币收入枚数          %d枚\n"
				"5角硬币收入枚数          %d枚\n"
				"合计纸币收入金额         %d元\n"
				"合计硬币收入金额         %d元\n"
				"合计现金收入金额         %d元\n"
				"硬币找零金额             %d元\n"
				"纸币找零金额             %d元\n"
				"总计找零金额             %d元\n\n"
				"硬币加币金额             %d元\n"
				"纸币加币金额             %d元\n"
				"硬币清币金额             %d元\n"
				"运营开始硬币找零箱金额   %d元\n"
				"运营开始纸币找零箱金额   %d元\n"
				"运营结束纸币找零箱金额   %d元\n"
				"超付金额                 %d元\n\n"
				"本日合计收入             %d元\n"
				"2元票出售张数            %d张\n"
				"3元票出售张数            %d张\n"
				"4元票出售张数            %d张\n"
				"5元票出售张数            %d张\n"
				"6元票出售张数            %d张\n"
				"7元票出售张数            %d张\n"
				"8元票出售张数            %d张\n"
				"9元票出售张数            %d张\n"
				"10元票出售张数           %d张\n"
				"废票张数                 %d张\n"
				"出票合计张数             %d张\n",
				gp_db->GetMyStaName().c_str(),
				lineNum,
				m_Ra3009.m_lOperatorNum,
				SDte::GetNow().ReadString().c_str(),
				MapReceiveBill[5],
				MapReceiveBill[10],
				MapReceiveBill[20],
				MapReceiveBill[50],
				MapReceiveBill[100],
				ReceiveCoin[0],
				ReceiveCoin[1],
				lReceivceBillAmount,
				lReceiveCoinAmount,
				lReceivceBillAmount + lReceiveCoinAmount,
				lCoinChgAmount,
				lBillChgAmount,
				lCoinChgAmount + lBillChgAmount,
				lCoinAddAmount,
				lBillAddAmount,
				lCoinCleanAmount,
				iYunYingStartCoinChgBoxAmount,
				iYunYingStartBillChgBoxAmount,
				iYunYingEndBillChgBoxAmount,
				lOverPayAmount,
				lTodayProfileAmount,
				MapSaleTicket[200],
				MapSaleTicket[300],
				MapSaleTicket[400],
				MapSaleTicket[500],
				MapSaleTicket[600],
				MapSaleTicket[700],
				MapSaleTicket[800],
				MapSaleTicket[900],
				MapSaleTicket[1000],
				iBadTicketAmount,
				iSaleTicketAmount

			);

	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( str );

	//m_Scr1.push_back( "打印报表成功" );
}

void bu_backman_ele_t::f_Print_Ticket_Report()
{
	int ret;

	m_Scr1.clear();

	m_Scr1.push_back( "打印票卡报表" );

	ShowCurrScr();

	m_Scr1.push_back( "没有票卡报表可打印" );
}

void bu_backman_ele_t::f_Print_Trade_Report()
{
	int ret;
	m_Scr1.clear();

	m_Scr1.push_back( "打印交易报表" );

	ShowCurrScr();


	if( gp_db->m_a_waiter_t.GetRowCount() -1  < 0 )
	{
		m_Scr1.push_back( "没有购票交易可打印" );
		return ;
	}

	a_waiter_t::ROWTYPE row( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() -1 ) );
	
	char cc[2048] = {0};
	sprintf(cc,"	上海地铁TVM交通卡购票故障记录单\n"
			   "车站	    \n"
			   "线路	   轨道交通   号线\n"
			   "设备号	    V001\n"
			   "	\n"
			   "交易时间	    %s\n"
			   "交易类型	    现金购票\n"
			   "	\n"
			   "车票单价	    %d元\n"
			   "张数	        %d张\n"
			   "应付金额	    %d元\n"
			   "	\n"
			   "收入总金额	%d元\n"
			   "收入硬币  	%d元\n"
			   "收入纸币	    %d元\n"
			   "交通卡扣款	0元\n"
			   "	\n"
			   "应找金额	    %d元\n"
			   "实找纸币	    %d元\n"
			   "实找硬币	    %d元\n"
			   "	\n"
			   "差额	        0元\n"
			   "实际出票	    %d张\n",
			   row.m_end_time.ReadStringPack().c_str(),
			   row.m_TickePrice1,
			   row.m_TicketoutPlan,
			   row.m_TickePriceTotal / 100,
			   row.m_ReceiveTotal / 100,
			   row.m_ReceiveCoin / 100,
			   row.m_ReceiveBill / 100,
			   row.m_ShouldChgTotal,
			   row.m_BilchgActual,
			   row.m_CoinRecycleChgActual,
			   row.m_TicketoutActual );

	std::string str(cc);

	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( str );


	//m_Scr1.push_back( "打印报表成功" );


}

void bu_backman_ele_t::f_Show6000Data()
{
	int ret;
	tuint32 ui4;
	
	m_Scr1.clear();

	m_Scr1.push_back( "寄存器数据查询" );

	AddMachineDataTo6000();

	a6000_t::ROWTYPE r6000(gp_db->GetTheRowa6000());

	// 寄存器数据 long*64=256
	std::string strtemp = "";
	if(1)
	{
		MYAUTOLOCK( gp_db->m_a6000.m_ut_tbl_lck );

		for( int i = 0; i < 21; i++ )  
		{
			if( 20 == i )
			{
				strtemp = "区域21-64售票数";
			}
			else
			{
				strtemp = "区域00售票数";
				sprintf( &(strtemp[0]),"区域%02d售票数",i+1 );
			}
			
			ui4 = r6000.m_Reg.a[ i ];
			//SStrf::chgendian(ui4) ;
			strtemp += "\t";
			strtemp += SStrf::sltoa(ui4);

			LOGSTREAM( gp_log[LOGSOP], LOGPOSI << " f_Show6000Data strtemp ="<<strtemp );
			m_Scr1.push_back( strtemp );
			
		}
		
		for( int i = 21; i < 41; i++ )  
		{
			strtemp = "区域00售票金额";
			sprintf( &(strtemp[0]),"区域%02d售票金额",i-20 );
			//reg 00 - 63
			ui4 = r6000.m_Reg.a[ i ];
			//SStrf::chgendian(ui4) ;
			strtemp += "\t";
			strtemp += SStrf::sltoa(ui4);

			LOGSTREAM( gp_log[LOGSOP], LOGPOSI << " f_Show6000Data strtemp ="<<strtemp );
			m_Scr1.push_back( strtemp );
			
		}
		if(1)
		{
			

			for(int i = 41;i < 64;i++)
			{
				strtemp = "";
				switch(i)
				{
				case 41:
					{
						strtemp = "区域21--64售票金额";
						break;
					}
				case 42:
					{
						strtemp = "接受的硬币总金额";
						break;
					}
				case 43:
					{
						strtemp = "接受的纸币总金额";
						break;
					}
				case 44:
					{
						strtemp = "累计硬币找零金额";
						break;
					}
				case 45:
					{
						strtemp = "累计纸币找零金额";
						break;
					}
				case 46:
					{
						strtemp = "硬币回收箱1内金额（不累加）";
						break;
					}
				case 47:
					{
						strtemp = "硬币回收箱2内金额（不累加）";
						break;
					}
				case 48:
					{
						strtemp = "硬币暂存器内金额（不累加）";
						break;
					}
				case 49:
					{
						strtemp = "硬币找零箱1内金额（不累加）";
						break;
					}
				case 50:
					{
						strtemp = "硬币找零箱2内金额（不累加）";
						break;
					}
				case 51:
					{
						strtemp = "纸币回收箱内金额（不累加）";
						break;
					}
				case 52:
					{
						strtemp = "纸币找零箱内金额（不累加）";
						break;
					}
				case 53:
					{
						strtemp = "超付金额";
						break;
					}
				case 54:
					{
						strtemp = "储值票购票张数";
						break;
					}
				case 55:
					{
						strtemp = "储值票购票金额";
						break;
					}
				default:
					{
						strtemp = "";
						break;
					}

				}
				
				if( "" != strtemp )
				{
					ui4 = r6000.m_Reg.a[ i ];
					//SStrf::chgendian(ui4) ;
					strtemp += "\t";
					strtemp += SStrf::sltoa(ui4);

					LOGSTREAM( gp_log[LOGSOP], LOGPOSI << " f_Show6000Data strtemp ="<<strtemp );
					m_Scr1.push_back( strtemp );
				}
			}


		}
	}

	ShowCurrScr();

	//m_Scr1.push_back( "寄存器数据查询成功" );
}

void bu_backman_ele_t::f_SelectTransData()
{
	int ret;
	int iShowTransCount = 5;
	std::string strtemp = "";

	m_Scr1.clear();

	m_Scr1.push_back( "交易数据查询" );

	if( gp_db->m_a_waiter_t.ut_GetRowAmount() - 1 < 0 )
	{
		m_Scr1.push_back("没有可查询交易数据");
	}
	else
	{
		m_Scr1.push_back( "时间                 金额\t张数\t纸币收\t硬币收\t纸币找\t硬币找" );

		for( int i = 1 ;( (gp_db->m_a_waiter_t.ut_GetRowAmount() - i >= 0 ) && ( i <= iShowTransCount ) );i++ )
		{
			strtemp = "";
			strtemp += gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_end_time.ReadStringPack();
			strtemp += "  ";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_TickePrice1 );     //金额
			strtemp += "\t";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_TicketoutActual );      //张数
			strtemp += "\t";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_ReceiveBill / 100);      //纸币收
			strtemp += "\t";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_ReceiveCoin / 100 );      //硬币收
			strtemp += "\t";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_BilchgActual );      //纸币找
			strtemp += "\t";
			strtemp += wl::SStrf::sltoa( gp_db->m_a_waiter_t.GetRow( gp_db->m_a_waiter_t.GetRowCount() - i ).m_CoinRecycleChgActual );      //硬币找

			m_Scr1.push_back( strtemp );
		}

	}


	ShowCurrScr();

	//m_Scr1.push_back( "交易数据查询成功" );
}

void bu_backman_ele_t::f_account()
{
     gp_medev->m_legal_authority=2;  //
	//结算，拿走钱箱，将值清零，上传
	m_Scr1.clear();

	m_Scr1.push_back( "您可以操作钱箱了..." );

	ShowCurrScr();
	
}

void bu_backman_ele_t::f_maintenance()
{
	//维护，拿走钱箱，值不清零，不上传
	 gp_medev->m_legal_authority=1;
	m_Scr1.clear();

	m_Scr1.push_back( "您可以操作钱箱了..." );

	ShowCurrScr();
}

//
void bu_backman_ele_t::f_whole_status() 
{
	m_Scr1.clear();

	m_Scr1.push_back( "设备状态" );

	ShowCurrScr();

	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	b8703_t::ROWTYPE & Rb8703(gp_db->GetTheRowb8703());
	b8704_t::ROWTYPE & Rb8704(gp_db->GetTheRowb8704());
	b8705_t::ROWTYPE & Rb8705(gp_db->GetTheRowb8705());
	b8706_t::ROWTYPE & Rb8706(gp_db->GetTheRowb8706());
	b8707_t::ROWTYPE & Rb8707(gp_db->GetTheRowb8707());
	b8708_t::ROWTYPE & Rb8708(gp_db->GetTheRowb8708());

	if( Rb8701.m_ConnState == 1 )
	{
		m_Scr1.push_back( "硬币模块已连接" );
	}
	else
	{
		m_Scr1.push_back( "硬币模块没有连接" );
	}

	if( Rb8702.m_ConnState == 1 )
	{
		m_Scr1.push_back( "纸币模块已连接" );
	}
	else
	{
		m_Scr1.push_back( "纸币模块没有连接" );
	}

	if( Rb8703.m_ConnState == 1 )
	{
		m_Scr1.push_back( "发卡模块已连接" );
	}
	else
	{
		m_Scr1.push_back( "发卡模块没有连接" );
	}


}



//
void bu_backman_ele_t::f_show_ver() 
{
	m_Scr1.clear();
	//m_Scr1.push_back( "版本信息" );
	m_Scr1.push_back( "版本号" );
	m_Scr1.push_back( gp_conf->m_strSysVer );
	m_Scr1.push_back( "内部的版本号" );
	m_Scr1.push_back( gp_conf->m_strSysVerInternal );
}



//
void bu_backman_ele_t::f_show_err_codes() 
{
	WNava  nvA;
	
	nvA.impconf( bu_backman_ele_errcode_bind() );

	m_Scr1.clear();
	
	a5041_t::ROWTYPE  Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	for( int i = 0; i < gp_db->Get5041EvtCapacity() ; i++ )
	{
		if( p->m_e.a[i] ) 
		{
			std::stringstream stream1;
			stream1 << i; // 错误号 
			stream1 << std::string( 7 - stream1.str().length(), ' ' ) 
				    << nvA.get( stream1.str() );

			m_Scr1.push_back( stream1.str() );
		}
	}
}



//
void bu_backman_ele_t::f_dev_id() 
{
	m_Scr1.clear();
	
	m_Scr1.push_back( "设备模块ID:" );
	
	std::string s1(1234,'-');
	std::vector< std::string > v1;
	a3014_t::ROWTYPE r( gp_db->GetTheRowa3014() );
	a4004_t::ROWTYPE rr( gp_db->m_a4004.GetRow(0) );

	sprintf( SADDR(s1), "车站设备标识码:\n"
						"in 3014: (%02Xh)%d\n" 
						"in 3014: (%02Xh)%d\n"
						"in 3014: (%02Xh)%d\n"
						"in 3014: (%02Xh)%d\n"
						"   in 4004: (%02Xh)%d\n" 
						"   in 4004: (%02Xh)%d\n"
						"   in 4004: (%02Xh)%d\n"
						"   in 4004: (%02Xh)%d" , 
						(int)r.m_EqpNodecode1, (int)r.m_EqpNodecode1, 
						(int)r.m_EqpNodecode2, (int)r.m_EqpNodecode2, 
						(int)r.m_EqpNodecode3, (int)r.m_EqpNodecode3, 
						(int)r.m_EqpNodecode4, (int)r.m_EqpNodecode4,
						(int)rr.m_ANode.a[0], (int)rr.m_ANode.a[0], 
						(int)rr.m_ANode.a[1], (int)rr.m_ANode.a[1], 
						(int)rr.m_ANode.a[2], (int)rr.m_ANode.a[2], 
						(int)rr.m_ANode.a[3], (int)rr.m_ANode.a[3] 
						);
	SStrvs::vsa_imp( std::string(SADDR(s1)), std::string("\n"), 1, v1 ); 
	std::copy(v1.begin(), v1.end(), std::back_inserter(m_Scr1));
}



	//
	static std::string _GetVer( unitbl_base_t & tbl )
	{
		MYAUTOLOCK( tbl.m_ut_tbl_lck );
		std::string s1;

		for( int y = 0; y < tbl.ut_GetRowAmount(); y++ )
		{
			if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" ) continue;

			s1 = tbl.ut_GetItemStr( y, "strTblName" );
			s1 += ": ";
			s1 += tbl.ut_GetItemStr( y, "lVer" );

			return s1.c_str() + 1;
		}

		s1 = tbl.ut_GetItemStr( -1, "strTblName" );
		s1 += ": 0";
		
		return s1.c_str() + 1;
	}


//
void bu_backman_ele_t::f_eod_ver() 
{
	m_Scr1.clear();
	m_Scr1.push_back( _GetVer( gp_db->m_a1040 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a2000 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3002 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3003 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3006 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3007 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3008 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3009 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3011 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3082 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3083 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3084 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3085 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a3086 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4001 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4002 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4003 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4004 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4006 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4007 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4008 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4009 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4015 ) );
	m_Scr1.push_back( _GetVer( gp_db->m_a4016 ) );
}



//
void bu_backman_ele_t::f_ClearingCoin() 
{
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]

	m_Scr1.clear();

	m_Scr1.push_back( "硬币清币" );

	ShowCurrScr();

	int yuan1cyclechg = Rb8701.m_A1YuanCycleChg;
	int jiao5cyclechg = Rb8701.m_A5MaoCycleChg;
	int yuan1box = Rb8701.m_A1YuanStoreBox;
	int jiao5box = Rb8701.m_A5MaoStoreBox;

	int iYuan1SpecialChg = 0;
	int iJiao5SpecialChg = 0;
	BYTE t_line = 0x0F;
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);
	int lineNum = (t_line * 10);
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;
	lineNum += t_line;
	
	
	// 1.清除1元循环找零
	gp_coin->dCoin_Clean( 0x01 );		// 0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零
	gp_coin->dCoin_End_Clean( 0x01 );	// 0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零	

	//清出的数字记LOG
	LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "硬币清币 1元循环找零数量：" << Rb8701.m_CoinCleanCount );
	BACK_REC( "硬币清币 1元循环找零数量：" << Rb8701.m_CoinCleanCount );
	m_Scr1.push_back( "硬币清币硬件 1元循环找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );
	m_Scr1.push_back( "硬币清币内存 1元循环找零数量：" + SStrf::sltoa( Rb8701.m_A1YuanCycleChg ) );

	Rb8701.m_A1YuanStoreBox += Rb8701.m_A1YuanCycleChg;
	Rb8701.m_A1YuanCycleChg = 0;

	// 2.清除5角循环找零
	gp_coin->dCoin_Clean( 0x02 );		
	gp_coin->dCoin_End_Clean( 0x02 );
	//清出的数字记LOG
	LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "硬币清币 5角循环找零数量：" << Rb8701.m_CoinCleanCount );
	BACK_REC( "硬币清币 5角循环找零数量：" << Rb8701.m_CoinCleanCount );
	m_Scr1.push_back( "硬币清币硬件 5角循环找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );
	m_Scr1.push_back( "硬币清币内存 5角循环找零数量：" + SStrf::sltoa( Rb8701.m_A5MaoCycleChg ) );

	Rb8701.m_A5MaoStoreBox += Rb8701.m_A5MaoCycleChg;
	Rb8701.m_A5MaoCycleChg = 0;

	
	// 3.清除1元专用找零
	gp_coin->dCoin_Clean( 0x04 );		
	gp_coin->dCoin_End_Clean( 0x04 );
	//清出的数字记LOG
	LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "硬币清币 1元专用找零数量：" << Rb8701.m_CoinCleanCount );
	BACK_REC( "硬币清币 1元专用找零数量：" << Rb8701.m_CoinCleanCount );
	m_Scr1.push_back( "硬币清币硬件 1元专用找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );
	m_Scr1.push_back( "硬币清币内存 1元专用找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );

	iYuan1SpecialChg = Rb8701.m_CoinCleanCount;
	Rb8701.m_A1YuanStoreBox += Rb8701.m_CoinCleanCount;
	Rb8701.m_A1YuanSpecialChg = 0;


	// 2.清除5角专用找零
	gp_coin->dCoin_Clean( 0x08 );		
	gp_coin->dCoin_End_Clean( 0x08 );
	//清出的数字记LOG
	LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "硬币清币 5角专用找零数量：" << Rb8701.m_CoinCleanCount );
	BACK_REC( "硬币清币 5角专用找零数量：" << Rb8701.m_CoinCleanCount );
	m_Scr1.push_back( "硬币清币硬件 5角专用找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );
	m_Scr1.push_back( "硬币清币内存 5角专用找零数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );

	iJiao5SpecialChg = Rb8701.m_CoinCleanCount;
	Rb8701.m_A5MaoStoreBox += Rb8701.m_CoinCleanCount;
	Rb8701.m_A5MaoSpecialChg = 0;
	

	char buffer[1024]={0};


	sprintf(buffer, "\t上海地铁TVM硬币清币记录单\n \
车站                  %s\n \
线路                  轨道交通%d号线\n \
设备号                V001\n\n \
操作员ID              %d\n \
操作时间              %s\n\n \
1元专用找零箱内硬币   %d枚\n \
5角专用找零箱内硬币   %d枚\n \
1元循环找零斗内硬币   %d枚\n \
5角循环找零斗内硬币   %d枚\n \
清币总额              %.2f元\n \
清币前硬币回收箱金额  %.2f元\n \
清币后硬币回收箱金额  %.2f元\n",
				gp_db->GetMyStaName().c_str(),
				lineNum,
				m_Ra3009.m_lOperatorNum,
				SDte::GetNow().ReadString().c_str(),
				iYuan1SpecialChg,
				iJiao5SpecialChg,
				yuan1cyclechg,jiao5cyclechg,
				(Rb8701.m_A1YuanStoreBox + ((float)Rb8701.m_A5MaoStoreBox)/2) - (yuan1box + (((float)jiao5box)/2)) ,
				(yuan1box + (((float)jiao5box)/2)),
				(Rb8701.m_A1YuanStoreBox + ((float)Rb8701.m_A5MaoStoreBox)/2  )			
			);

	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( buffer );

	//m_Scr1.push_back( "硬币清币 5角循环找零" );

	
	ShowCurrScr();

}

void bu_backman_ele_t::f_CleaningBill()
{
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]

	m_Scr1.clear();

	m_Scr1.push_back( "纸币清币" );

	ShowCurrScr();

	//清除纸币
	int iIsCleanBox[5] = {1,1,1,1,1};
	unsigned int LO_ClearNum[8]={0,0,0,0,0,0,0,0};
	unsigned int RE_ClearNum[8]={0,0,0,0,0,0,0,0};
	unsigned int CB_TotalNum[8]={0,};
	char ModuleSerialNums[6][10]={'\0',};
	char clear_str[1024]={0,};
	char tmp_str[128]={0,};

	BYTE t_line = 0x0F;	
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);	
	int lineNum = (t_line * 10);	
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;	
	lineNum += t_line;
	
	gp_bill->dBill_GetSerialNums(ModuleSerialNums);

	strcpy(tmp_str,"2016-12-22 13:23:11");
	snprintf(clear_str,sizeof(clear_str)-1,
		"\t上海地铁TVM纸币清币记录单\n\
车站               %s站\n\
线路               轨道交通%d号线\n\
设备号             v111\n\n\
钱箱ID             %s\n\
操作员ID           %d\n\
操作时间           %s\n\n",\
		gp_db->GetMyStaName().c_str(),lineNum,ModuleSerialNums[5],\
m_Ra3009.m_lOperatorNum,SDte::GetNow().ReadString().c_str());
	

	
	gp_bill->dBill_Clean( iIsCleanBox,LO_ClearNum, RE_ClearNum,CB_TotalNum);
	int ret=0;
	ret=gp_bill->dBill_LockBox("LO1",true);
	ret=gp_bill->dBill_Reset(true);
	//清出的数字记LOG
	//LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "硬币清币 1元数量：" << Rb8701.m_CoinCleanCount );
	//BACK_REC( "硬币清币 1元数量：" << Rb8701.m_CoinCleanCount );
	//m_Scr1.push_back( "硬币清币硬件 1元数量：" + SStrf::sltoa( Rb8701.m_CoinCleanCount ) );
	//m_Scr1.push_back( "硬币清币内存 1元数量：" + SStrf::sltoa( Rb8701.m_A1YuanCycleChg ) );

	//Rb8701.m_A1YuanStoreBox += Rb8701.m_A1YuanCycleChg;
	//Rb8701.m_A1YuanCycleChg = 0;

	int i=0;
	

	//snprintf(tmp_str,sizeof(tmp_str)-1,"钱箱ID			%s\n",ModuleSerialNums[5]);
	
	
	int clear_yuan = 0;

	for (i=0;i<8;i++)
	{
		tmp_str[0]='\0';
		switch (i)
		{
			case 0:
				  if(100==Rb8702.m_ReDenomination.a[0]||100==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"1元补币箱内纸币    %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 1元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
				  	
			      clear_yuan += LO_ClearNum[i];
				  break;	
			case 1:
				  if(200==Rb8702.m_ReDenomination.a[0]||200==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"2元补币箱内纸币    %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 2元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
				 clear_yuan += 2*(LO_ClearNum[i]);
				 break;
			case 2:
				  if(500==Rb8702.m_ReDenomination.a[0]||500==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"5元补币箱内纸币    %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 5元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
				
				 clear_yuan += 5*(LO_ClearNum[i]);	
				 break;
			case 3:
				  if(1000==Rb8702.m_ReDenomination.a[0]||1000==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"10元补币箱内纸币   %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 10元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
				 
				 clear_yuan += 10*(LO_ClearNum[i]);	
				 break;
			case 4:
				  if( 2000==Rb8702.m_ReDenomination.a[0]||2000==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"20元补币箱内纸币   %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 20元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
			 	
				clear_yuan += 20*(LO_ClearNum[i]);	
				 break;
			case 5:
				  if(5000==Rb8702.m_ReDenomination.a[0]||5000==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"50元补币箱内纸币   %d张\n",LO_ClearNum[i]);
					m_Scr1.push_back( "纸币清币硬件 50元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				  }
				  
				 clear_yuan += 50*(LO_ClearNum[i]);
				 break;
			case 6:
				if(10000==Rb8702.m_ReDenomination.a[0]||10000==Rb8702.m_ReDenomination.a[1])
				{
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"100元补币箱内纸币  %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 100元补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				}
			 	
				clear_yuan += 100*(LO_ClearNum[i]);
				 break;
			case 7:
				 if(LO_ClearNum[i]!=0)
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"不识别纸币	       %d张\n",LO_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 不识别补币箱数量：" + SStrf::sltoa( LO_ClearNum[i]) );
				 }
				 
				 break;
		};
		
		strcat(clear_str,tmp_str);
	}
	for (i=0;i<8;i++)
	{
		tmp_str[0]='\0';
		switch (i)
		{
			case 0:
				if(RE_ClearNum[i]!=0||100==Rb8702.m_ReDenomination.a[0]||100==Rb8702.m_ReDenomination.a[1])
				{
				  	 snprintf(tmp_str,sizeof(tmp_str)-1,"1元循环箱内纸币    %d张\n",RE_ClearNum[i]); 
					 m_Scr1.push_back( "纸币清币硬件 1元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				}
			    
				clear_yuan += RE_ClearNum[i];	
				break;	
			case 1:
				 if(RE_ClearNum[i]!=0||200==Rb8702.m_ReDenomination.a[0]||200==Rb8702.m_ReDenomination.a[1])
				  {
				  	snprintf(tmp_str,sizeof(tmp_str)-1,"2元循环箱内纸币    %d张\n",RE_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 2元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 
				  }
				 clear_yuan += 2*(RE_ClearNum[i]);
				 break;
			case 2:
				 if(RE_ClearNum[i]!=0||500==Rb8702.m_ReDenomination.a[0]||500==Rb8702.m_ReDenomination.a[1])
				 {
					snprintf(tmp_str,sizeof(tmp_str)-1,"5元循环箱内纸币    %d张\n",RE_ClearNum[i]); 
					 m_Scr1.push_back( "纸币清币硬件 5元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 }
				 clear_yuan += 5*(RE_ClearNum[i]);	
				 break;
			case 3:
				 if(RE_ClearNum[i]!=0||1000==Rb8702.m_ReDenomination.a[0]||1000==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"10元循环箱内纸币   %d张\n",RE_ClearNum[i]); 
					 m_Scr1.push_back( "纸币清币硬件 10元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 }
				 clear_yuan += 10*(RE_ClearNum[i]);	
				 break;
			case 4:
				 if(RE_ClearNum[i]!=0||2000==Rb8702.m_ReDenomination.a[0]||2000==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"20元循环箱内纸币   %d张\n",RE_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 20元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 }
			 	 clear_yuan += 20*(RE_ClearNum[i]);	
				 break;
			case 5:
				 if(RE_ClearNum[i]!=0||5000==Rb8702.m_ReDenomination.a[0]||5000==Rb8702.m_ReDenomination.a[1])
				 {
					snprintf(tmp_str,sizeof(tmp_str)-1,"50元循环箱内纸币   %d张\n",RE_ClearNum[i]); 	
					m_Scr1.push_back( "纸币清币硬件 50元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 }
				 clear_yuan += 50*(RE_ClearNum[i]);
				 break;
			case 6:
				if(RE_ClearNum[i]!=0||10000==Rb8702.m_ReDenomination.a[0]||10000==Rb8702.m_ReDenomination.a[1])
				{
			 		snprintf(tmp_str,sizeof(tmp_str)-1,"100元循环箱内纸币  %d张\n",RE_ClearNum[i]); 	
					m_Scr1.push_back( "纸币清币硬件 100元循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				}
				clear_yuan += 100*(RE_ClearNum[i]);
				 break;
			case 7:
				 if(RE_ClearNum[i]!=0)
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"不识别纸币	       %d张\n",RE_ClearNum[i]); 
					m_Scr1.push_back( "纸币清币硬件 不识别循环箱数量：" + SStrf::sltoa( RE_ClearNum[i]) );
				 }
				 break;
		};
		
		strcat(clear_str,tmp_str);
	}
	               
	snprintf(tmp_str,sizeof(tmp_str)-1,"清币总额           %.2f元\n",(float)clear_yuan);
	m_Scr1.push_back( "清币总额：" + SStrf::sltoa( clear_yuan) +"元");
	int CB_yuan_total=Rb8702.m_Pieces.a[1]*1+Rb8702.m_Pieces.a[2]*2+Rb8702.m_Pieces.a[5]*5 + \
		Rb8702.m_Pieces.a[10]*10+Rb8702.m_Pieces.a[20]*20+Rb8702.m_Pieces.a[50]*50+Rb8702.m_Pieces.a[100]*100;
	strncat(clear_str,tmp_str,sizeof(clear_str));
	snprintf(tmp_str,sizeof(tmp_str)-1,"回收箱总额         %.2f元\n",(float)CB_yuan_total);
	m_Scr1.push_back( "回收箱总额：" + SStrf::sltoa( CB_yuan_total)+"元");
	strncat(clear_str,tmp_str,sizeof(clear_str));
	std::string str(clear_str);
	/*
	std::string str;
	str =   "上海地铁TVM纸币清币记录单\n"
		    "车站\n"	
			"线路	轨道交通    号线\n"
			"设备号	V001\n"
			"\n"
			"操作员ID	12345678\n"
			"操作时间	2012-01-01 12:00:00\n"
			"\n"	
			"5元补币箱内纸币	    100张\n"
			"10元补币箱内纸币	0张\n"
			"5元循环找零箱内纸币	20张\n"
			"10元循环找零箱内纸币	10张\n"
			"清币总额	125元\n"
			"清币前纸币回收箱内金额	200元\n"
			"清币后纸币回收箱内金额	325元\n";
*/
	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( str );

	//m_Scr1.push_back( "硬币清币 5角循环找零" );

	//ret=gp_bill->dBill_ClearLoaderRecovery();//清除CB  LO钱箱统计数据
	ShowCurrScr();

}

//
void bu_backman_ele_t::f_RepCoin() 
{
	/*a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	b8703_t::ROWTYPE & Rb8703(gp_db->GetTheRowb8703());
	b8704_t::ROWTYPE & Rb8704(gp_db->GetTheRowb8704());
	b8705_t::ROWTYPE & Rb8705(gp_db->GetTheRowb8705());
	b8706_t::ROWTYPE & Rb8706(gp_db->GetTheRowb8706());
	b8707_t::ROWTYPE & Rb8707(gp_db->GetTheRowb8707());
	b8708_t::ROWTYPE & Rb8708(gp_db->GetTheRowb8708());

	m_Scr1.clear();

	m_Scr1.push_back( "硬币找零加币" );

	gp_coin->dCoin_Add( 0x01 ); // 只管1元的。	

	m_Scr1.push_back( "加币数量：" + SStrf::sltoa( Rb8701.m_CoinAddCount ) );

	Rb8701.m_A1YuanSpecialChg += Rb8701.m_CoinAddCount;

	std::string str;
	str =  "上海地铁TVM硬币找零箱加币记录单\n"
			"车站\n"	
			"线路	轨道交通   号线\n"
			"设备号	V001\n"
			"\n"	
			"钱箱ID	12345678\n"
			"钱箱币值	1元\n"
			"操作员ID	12345678\n"
			"操作时间	2012-01-01 12:00:00\n"
			"\n"	
			"加币前钱箱金额	0元\n"
			"添加硬币	50枚\n"
			"加币后钱箱金额	50元\n";

	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( str );*/
	return;

}



//
void bu_backman_ele_t::f_RepBill() 
{
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));//gp_db->m_a1040.GetRow(0).m_CcNode.a[0]
	m_Scr1.clear();

	m_Scr1.push_back( "纸币找零手动加币" );
	char ModuleSerialNums[6][10]={'\0',};
	ShowCurrScr();
	unsigned int LOAdd_Num[8]={0,};
	int ret=0;
	int i=0;
	int add_yuan=0;
	char add_str[1024]={0,};
	char tmp_str[128]={0,};
	BYTE t_line = 0x0F;	
	
	t_line &= (Ra1040.m_CcNode.a[0] >> 4);	
	int lineNum = (t_line * 10);	
	t_line = Ra1040.m_CcNode.a[0] & 0x0F;	
	lineNum += t_line;
	
	gp_bill->dBill_GetSerialNums(ModuleSerialNums);

	snprintf(add_str,sizeof(add_str)-1,
		"\t上海地铁TVM纸币找零箱加币记录单\n\
车站               %s站\n\
线路               轨道交通%d号线\n\
设备号             v111\n\n\
钱箱ID             %s\n\
操作员ID           %d\n\
操作时间           %s\n\n",\
		gp_db->GetMyStaName().c_str(),lineNum,ModuleSerialNums[5],\
m_Ra3009.m_lOperatorNum,SDte::GetNow().ReadString().c_str());



	ret=gp_bill->dBill_Add(LOAdd_Num);
	ret=gp_bill->dBill_LockBox("LO1",true);
	ret=gp_bill->dBill_Reset(true);

	
	for (i=0;i<8;i++)
	{
		tmp_str[0]='\0';
		switch (i)
		{
			case 0:
				if(LOAdd_Num[i]!=0||100==Rb8702.m_ReDenomination.a[0]||100==Rb8702.m_ReDenomination.a[1])
				{
					snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加1元纸币   %d张\n",LOAdd_Num[i]); 
					m_Scr1.push_back( "纸币补币硬件 1元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				}
				add_yuan += LOAdd_Num[i];	
				break;	
			case 1:
				 if(LOAdd_Num[i]!=0||200==Rb8702.m_ReDenomination.a[0]||200==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加2元纸币   %d张\n",LOAdd_Num[i]); 	
					m_Scr1.push_back( "纸币补币硬件 2元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				 }
				 add_yuan += 2*(LOAdd_Num[i]);
				 break;
			case 2:
				 if(LOAdd_Num[i]!=0||500==Rb8702.m_ReDenomination.a[0]||500==Rb8702.m_ReDenomination.a[1])
				 {                                    
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加5元纸币    %d张\n",LOAdd_Num[i]); 
					m_Scr1.push_back( "纸币补币硬件 5元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				 }
				 add_yuan += 5*(LOAdd_Num[i]);	
				 break;
			case 3:
				 if(LOAdd_Num[i]!=0||1000==Rb8702.m_ReDenomination.a[0]||1000==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加10元纸币   %d张\n",LOAdd_Num[i]); 
					m_Scr1.push_back( "纸币补币硬件 10元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				 }                                     
				 add_yuan += 10*(LOAdd_Num[i]);	
				 break;
			case 4:
				 if(LOAdd_Num[i]!=0||2000==Rb8702.m_ReDenomination.a[0]||2000==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加20元纸币   %d张\n",LOAdd_Num[i]); 
					m_Scr1.push_back( "纸币补币硬件 20元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
			 	 }
				 add_yuan += 20*(LOAdd_Num[i]);	
				 break;
			case 5:
				 if(LOAdd_Num[i]!=0||5000==Rb8702.m_ReDenomination.a[0]||5000==Rb8702.m_ReDenomination.a[1])
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加50元纸币   %d张\n",LOAdd_Num[i]); 	
					m_Scr1.push_back( "纸币补币硬件 50元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				 }                                   
				 add_yuan += 50*(LOAdd_Num[i]);
				 break;
			case 6:
				if(LOAdd_Num[i]!=0||10000==Rb8702.m_ReDenomination.a[0]||10000==Rb8702.m_ReDenomination.a[1])
				{
			 		snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱加100元纸币  %d张\n",LOAdd_Num[i]); 	
					m_Scr1.push_back( "纸币补币硬件 100元补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				}                                     
				add_yuan += 100*(LOAdd_Num[i]);
				break;
			case 7:
				 if(LOAdd_Num[i]!=0)
				 {
				 	snprintf(tmp_str,sizeof(tmp_str)-1,"补币箱不识别纸币   %d张\n",LOAdd_Num[i]); 	
					m_Scr1.push_back( "纸币补币硬件 不识别补币箱数量：" + SStrf::sltoa( LOAdd_Num[i]) );
				 }
				 break;
		};
			
		strcat(add_str,tmp_str);
	}
                                       
	snprintf(tmp_str,sizeof(tmp_str)-1,"加币总额           %.2f元\n",(float)add_yuan);
	m_Scr1.push_back( "补币总额：" + SStrf::sltoa( add_yuan) +"元");
	strcat(add_str,tmp_str);
	std::string str(add_str);
	
	ShowCurrScr();
	//gp_printer->PrintStr( str );
	gp_printer->PrintStrAsync( str );

}

void bu_backman_ele_t::f_Reset()
{

	int irc = 0;
	m_Scr1.clear();


	//1.纸币复位
	m_Scr1.push_back( "正在复位纸币模块..." );
	ShowCurrScr();
	irc = gp_bill->RecoverErr();
	if( irc )
	{
		m_Scr1.push_back( "纸币模块复位成功" );
	}
	else
	{
		m_Scr1.push_back( "纸币模块复位失败" );
	}
	ShowCurrScr();

	//2.硬币复位
	m_Scr1.push_back( "正在复位硬币模块..." );
	ShowCurrScr();
	gp_coin->dCoin_Stop();
	irc = gp_coin->RecoverErr();

	if( irc )
	{
		gp_coin->dCoinHold(); 
		gp_coin->dCoin2CircleChg(); 
		gp_coin->dCoin2StoreBox(); 
		gp_coin->dCoinHold();

		m_Scr1.push_back( "硬币模块复位成功" );
	}
	else
	{
		m_Scr1.push_back( "硬币模块复位失败" );
	}
	ShowCurrScr();

	//3.发卡复位
	m_Scr1.push_back( "正在复位发卡模块..." );
	ShowCurrScr();
	irc = gp_emitticket->RecoverErr();
	if( irc )
	{
		m_Scr1.push_back( "发卡模块复位成功" );
	}
	else
	{
		m_Scr1.push_back( "发卡模块复位失败" );
	}
	ShowCurrScr();

	//4.读写器复位
	m_Scr1.push_back( "正在复位读写器模块..." );
	ShowCurrScr();

	irc = gp_reader1->rReset();
	if( 0 == irc )
	{
		irc = gp_reader1->rInit2();
		if( 0 == irc )
		{
			m_Scr1.push_back( "读写器模块复位成功" );

			gp_db->m_b8704.GetRow(0).m_BigErr = 0;   //消除错误
		}
		else
		{
			m_Scr1.push_back( "读写器模块复位失败" );
		}
	}
	else
	{
		m_Scr1.push_back( "读写器模块复位失败" );
	}
	
	ShowCurrScr();

	//消除一些错误码
	a5041_t::ROWTYPE &row2( gp_db->m_a5041.GetRow(0) );

	//清除事件错误码
	row2.m_e_old = a5041_t::ROWTYPE().m_e_old;
	row2.m_e = a5041_t::ROWTYPE().m_e;

	//所有事件都没发生过:
	row2.m_e_flag = a5041_t::ROWTYPE().m_e_flag; //事件flag

	////179 和 180 处理
	//row2.m_e_old.a[179 ] = 0;
	//row2.m_e.    a[179 ] = 0;
	//row2.m_e_old.a[180 ] = 0;
	//row2.m_e.    a[180 ] = 0;

	// 复位消除故障码
	//gp_db->m_a5041.Clear();

	memset( gp_coin->m_iIsRepCoinOk, 1, sizeof(BYTE)*2 );  //清除掉补币箱补币错误
	gp_bill->m_iIsRepBillOk = 1;                           ////清除掉补币箱补币错误


	m_Scr1.push_back( "复位完成" );


}






