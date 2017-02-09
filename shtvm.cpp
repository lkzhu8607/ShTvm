
#include "2.h"
#include "g06.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "de_log_t.h"
#include "de_moneylog_t.h"
#include "de_ui_t.h"
#include "de_frontinput_t.h"
#include "de_backinput_t.h"
#include "bu_comeag_mgr_t.h"
#include "bu_me_mgr_t.h"
#include "d_db_t.h"
#include "de_tcpmsg_t.h"
#include "d_paratime_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_backman_mgr_t.h"
#include "bu_timeshower_t.h"
#include "bu_asynwork_t.h"
#include "bu_backupg_t.h"

#include "de_medev_t.h"

#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"
#include "de_topscr_t.h"
#include "de_printer_t.h"
#include "de_upsdev_t.h"
#include "de_cashbox_t.h"
#include "de_coinbox_t.h"
//封装的纸币模块头文件
#include "bnr_operation.h"

#include "d_cg01_t.h"
#include "d_cg01s_backpic_t.h"
#include "d_cg01s_lang_t.h"
#include "d_cg01s_linepic_t.h"
#include "d_cg01s_rightupmsg_t.h"
#include "d_cg01s_machinestate_t.h"
#include "d_cg01s_fastprice_t.h"
#include "d_cg01s_seleline_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01s_evtcodes_t.h"
#include "d_cg01s_errpic_t.h"
#include "d_cg01s_errexplain_t.h"
#include "d_cg02_t.h"
#include "d_cg02s_backpic_t.h"
#include "d_cg02s_goback_t.h"
#include "d_cg02s_cancel_t.h"
#include "d_cg02s_pieceshow_t.h"
#include "d_cg02s_goodbillcoin_t.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg02s_waiter_t.h"
#include "cg02s_machinestate_t.h"
#include "d_cg03_t.h"
#include "d_cg03s_backpic_t.h"
#include "d_cg03s_lang_t.h"
#include "d_cg03s_seleline_t.h"
#include "d_cg03s_goback_t.h"
#include "d_cg03s_oneline_t.h"
#include "d_cg03s_rightsidemsg_t.h"
#include "d_cg03s_machinestate_t.h"
#include "d_cg04_t.h"
#include "d_cg04s_backpic_t.h"
#include "d_cg04s_stoppic_t.h"





#ifdef LINUENV_
#include <signal.h>
struct A
{
	A() { signal(SIGPIPE, signal_handler); }
	static void signal_handler(int sig)
	{ if( sig==SIGPIPE ) return; }
};
static A a45254563557_;
#endif


//
void LogInit();

//
int main( int argc, char *argv[] )
{
	d_config_t		conf1;
	bu_quickflow_t  qf;
	de_log4_t		log[LOGAMOUNT];
	de_moneylog_t		moneylog;
	de_frontinput_t   frontinput;
	de_backinput_t   backinput;
	de_ui_t			ui;
	d_db_t			db;
	de_tcpmsg_t		tcpmsg;
	bu_frontman_mgr_t  frontman;
	bu_backman_mgr_t   backman;
	bu_timeshower_t    timeshower;
	
	de_medev_t		medev;

	de_coin_t			coin;
	de_bill_t			bill;
	de_emitticket_t		emitticket;
	de_reader1_t		reader1;
	de_bilchg_t			bilchg;
	de_topscr_t			topscr;
	de_printer_t		printer;
	de_upsdev_t			upsdev;

	de_coinbox_t coinbox;
	de_bill_cashbox_t bill_cashbox;
	gp_conf = &conf1;
	gp_conf->LoadConfFile();
	gp_conf->MakeDiskEnv();

	bu_asynwork_t::DoSetThisIp();
	bu_asynwork_t::DoTime1Server();
	bu_asynwork_t::DoTime2Server();

	gp_qf = &qf;
	gp_qf->tr_open();

	//LOG;
	gp_log = log;
	LogInit();

	gp_moneylog = &moneylog;
	gp_moneylog->Init();
	TWO_REC( "tvm begin" );

	//test_coin();
	//test_bill();
	//test_double();
	//return 0;

	gp_db = &db;
	gp_db->LoadDb();
	gp_db->SaveDb();

			//gp_bill = &bill;
			//gp_bill->billInit();
			//test_bill_mei();

			//gp_emitticket = &emitticket;
			//gp_emitticket->EmttInit();
			//test_emt_ticket1();

			//gp_reader1 = &reader1;
			//gp_reader1->Reader1Init();
			//test_read_card();

			//gp_bilchg = &bilchg;
			//gp_bilchg->bilchgInit();
			//gp_bilchg->bilchgChangeOut( 0, 1 );

	//test_send6002aa();
	//return 0;

	extern void test_AFlow();
	test_AFlow();


	gp_tcpmsg = &tcpmsg;
	gp_tcpmsg->MyInit();

	gp_ui = &ui;
	gp_ui->MyInit();
	
	if( gp_conf->getnvB("scrall_width") == "" )
		backupg_go();

	//test2();
	//test_set3014();
	
	//显示版本 
	char s[222];
	sprintf( s, "%s %s", gp_conf->m_strSysVer.c_str(), gp_conf->m_strSysVerInternal.c_str() ); 
	gp_ui->LineScrPrintA( s );

	gp_ui->LineScrPrintA( "数据初始化" );
	gp_ui->LineScrPrintA( "显示模块初始化" );
	gp_ui->LineScrPrintA( "参数输入模块初始化" );

	//if( !SStrf::newobjptr<bu_comeag_mgr_t>()->MyInit() ) 模拟串口，不用了
	//	return 0;

	if( !SStrf::newobjptr<bu_me_mgr_t>()->Init() ) // 接收参数	
		return 0;
	
	gp_ui->LineScrPrintA( "用户输入处理模块的初始化" );

	gp_frontinput = &frontinput;
	if( !gp_frontinput->FrontInit(9999) )
		return 0;

	gp_backinput = &backinput;
	if( !gp_backinput->backInit(8888) )
		return 0;

	gp_timeshower = &timeshower;
	gp_timeshower->init();
	gp_timeshower->tr_open();

	//
	//working thread
	//
	gp_ui->LineScrPrintA( "事件模块初始化" );
	gp_medev = &medev;
	gp_medev->MedevInit();

	gp_ui->LineScrPrintA( "硬币模块初始化" );
	gp_coin = &coin;
	gp_coin->CoinInit();
	gp_coin->dCoinOpenUplight();
	gp_coin->dCoinOpenDownlight();
	gp_coin->dCoinOpenAlert();
	WThrd::tr_sleepu(0.11);
	gp_coin->dCoinCloseUplight();
	gp_coin->dCoinCloseDownlight();
	gp_coin->dCoinCloseAlert();

	//test_coin3();

	gp_ui->LineScrPrintA( "纸币模块初始化" );
	gp_bill = &bill;
	gp_bill->billInit();

	

	gp_ui->LineScrPrintA( "发卡模块初始化" );
	gp_emitticket = &emitticket;
	gp_emitticket->EmttInit();
	gp_emitticket->MkTicketReady();
	//gp_emitticket->eTicket_ExchangeBox();


	gp_ui->LineScrPrintA( "读写器模块初始化" );
	gp_reader1 = &reader1;
	gp_reader1->Reader1Init();


	/*gp_ui->LineScrPrintA( "纸币找零初始化" );
	gp_bilchg = &bilchg;
	gp_bilchg->bilchgInit();*/


	gp_ui->LineScrPrintA( "滚动屏 初始化" );
	gp_topscr = &topscr;
	gp_topscr->TopscrInit();

	gp_ui->LineScrPrintA( "打印机 初始化" );
	gp_printer = &printer;
	gp_printer->PrinterInit();

	//gp_ui->LineScrPrintA( "UPS初始化" );
	//gp_upsdev = &upsdev;
	//gp_upsdev->UpsInit();

	gp_backman_mgr = &backman;
	gp_backman_mgr->backmanInit();

	//gp_frontman_mgr = &frontman;
	//gp_frontman_mgr->frontmanInit();

	//gp_backman_mgr = &backman;
	//gp_backman_mgr->backmanInit();


	//test_top_scr();
	//test_printer();
	//test_printline();
	g_bill_cashbox =&bill_cashbox;
	g_bill_cashbox->bill_cashbox_init();  //初始化监测纸币箱
	
	gp_coinbox = &coinbox;
	gp_coinbox->coinbox_init();
	
	bu_asynwork_t::RepeatSendReg6000();

	gp_medev->EvtInitBegin();
	WThrd::tr_sleep( 3 );
	gp_medev->EvtInitEnd();



	gp_ui->LineScrClearA();
	


	if(plocalcg01->pageGraphElementsFlags == 0){
		d_cg01s_backpic_t			cg01s_backpic;
		d_cg01s_lang_t			cg01s_lang;
		d_cg01s_rightupmsg_t	cg01s_rightupmsg;
		d_cg01s_fastprice_t  cg01s_fastprice;
		d_cg01s_evtcodes_t	cg01s_evtcodes;
		d_cg01s_errpic_t cg01s_errpic;
		d_cg01s_errexplain_t cg01s_errexplain;
		d_cg01s_linepic_t		cg01s_linepic;
		d_cg01s_seleline_t	 cg01s_seleline;
		d_cg01s_machinestate_t	cg01s_machinestate;
		cg01s_backpic.ShowBack1();
		cg01s_lang.ShowLangButt();
		cg01s_rightupmsg.Showrightupmsg();
		cg01s_fastprice.Showfastprice();
		cg01s_linepic.ShowLinePic();
		//cg01s_linepic.ShowDirButt();
		cg01s_machinestate.Showmachinestate();
		cg01s_seleline.Showseleline();
		cg01s_evtcodes.m_x = 0.207;
		cg01s_evtcodes.ShowEvtCodes();	
		cg01s_errpic.Show();
		cg01s_errexplain.Show();
		plocalcg01->pageGraphElementsFlags = 1;
		if((plocalcg01->graphLineButtonCN.size()%10) == 0){
			plocalcg01->pageTab = (plocalcg01->graphLineButtonCN.size() / 10);
		}
		else{
			plocalcg01->pageTab = (plocalcg01->graphLineButtonCN.size() / 10) + 1;
		}
		plocalcg01->displayFlag = 0;
		plocalcg01->langFlag = 0;
		//SetLanguageCh();
	}

	if(plocalcg02->pageGraphElementsFlags == 0){
		d_cg02s_backpic_t  cg02s_backpic;
		d_cg02s_goback_t  cg02s_goback;
		d_cg02s_cancel_t  cg02s_cancel;
		d_cg02s_machinestate_t cg02s_machinestate;
		d_cg02s_goodbillcoin_t cg02s_goodbillcoin;
		d_cg02s_pieceshow_t  cg02s_pieceshow;
		cg02s_backpic.ShowBack1();
		cg02s_goback.ShowGoback();
		cg02s_pieceshow.ShowPieceButtBoard();
		cg02s_pieceshow.ShowPieceInfo();
		cg02s_pieceshow.ShowPayednchg();
		cg02s_cancel.Showcancel();
		cg02s_goodbillcoin.ShowValidMoneyType();
		cg02s_machinestate.ShowStatus();
		plocalcg02->pageGraphElementsFlags = 1;
		plocalcg02->displayFlag = 0;
		plocalcg02->langFlag = 0;		
		//SetLanguageCh();
	}

	if(plocalcg03->pageGraphElementsFlags == 0){
		d_cg03s_backpic_t  cg03s_backpic;
		d_cg03s_rightsidemsg_t  cg03s_rightsidemsg;
		d_cg03s_lang_t  cg03s_lang;
		d_cg03s_goback_t  cg03s_goback;
		d_cg03s_oneline_t  cg03s_oneline;
		d_cg03s_seleline_t   cg03s_seleline;
		d_cg01s_seleline_t   cg01s_seleline;
		d_cg03s_machinestate_t  cg03s_machinestate;
		cg03s_backpic.ShowBack1();
		cg03s_rightsidemsg.Showrightsidemsg();
		cg03s_lang.ShowLangButt();
		cg03s_goback.ShowGoback();
		cg03s_oneline.Showoneline();
		cg03s_machinestate.Showmachinestate();
		plocalcg03->pageGraphElementsFlags = 1;
		plocalcg03->displayFlag = 0;
		plocalcg03->langFlag = 0;
		//SetLanguageCh();
	}	

	if(plocalcg04->pageGraphElementsFlags == 0){
		d_cg04s_backpic_t  cg04s_backpic;
		//d_cg01s_jud5041_t  cg01s_jud5041;
		d_cg04s_stoppic_t  cg04s_stoppic;
		cg04s_stoppic.ShowBack1();
		cg04s_backpic.ShowBack1();
		plocalcg04->pageGraphElementsFlags = 1;
		plocalcg04->displayFlag = 0;
		plocalcg04->langFlag = 0;
		//SetLanguageCh();
	}
	gp_frontman_mgr = &frontman;
	gp_frontman_mgr->frontmanInit();

	//主循环 

	while(1)
	{
		d_paratime_t pt;

		if( pt.DetectAffect() )
		{
			pt.TakeAffectAll();
		}

		pt.MarkDel();
		pt.Purge();
		de_tcpmsg_t::SendTrade6002_1();

		WThrd::tr_sleep( 1 );

		gp_db->SaveDb();

		WThrd::tr_sleep( 1 );
		
		if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot )
			break;

			
		if( SStrf::rand1() < 0.1 ) 
		{
			gp_frontinput->input_KIN_APP();
			gp_frontinput->input_KIN_COIN();
			gp_frontinput->input_KIN_BILL();
			gp_frontinput->input_KIN_EMTICKET();
			gp_frontinput->input_KIN_READER1();
			gp_frontinput->input_KIN_BILLCHG();
			gp_frontinput->input_KIN_TOPSCR();
			gp_frontinput->input_KIN_PRINTER();
			gp_frontinput->input_KIN_UPS();	
		}
	}
	
	//触发所有表的存盘：
	gp_db->RiseAllSaveFlag();
	gp_db->SaveDb();


	if( IsOsWin() )
		exit(0);
	
	//if( gp_conf->m_biSysShouldExit )
	//{
	//	exit(0);
	//}
		
		
	if( gp_conf->m_biSysShouldShutdown )
	{
		std::string strCmd;
		strCmd = "poweroff";
		if(!IsOsWin())
			WFile::run_exe(strCmd);
		WThrd::tr_sleep(9);
	}
	
	if( gp_conf->m_biSysShouldReboot )
	{
		std::string strCmd;
		strCmd = "reboot";
		if(!IsOsWin())
			WFile::run_exe(strCmd);
		WThrd::tr_sleep(9);
	}
	
    return 0;
}



//
void LogInit()
{
	//gp_log[LOGNULL].LogInit("LOGNULL.txt", 3123999); 
	//gp_log[LOGAPP].LogInit("LOGAPP.txt");
	//gp_log[LOGSOP].LogInit("LOGSOP.txt");
	//gp_log[LOGSC].LogInit("LOGSC.txt");
	//gp_log[LOGBILL].LogInit("LOGBILL.txt");
	//gp_log[LOGCOIN].LogInit("LOGCOIN.txt");
	//gp_log[LOGBILLCHG].LogInit("LOGBILLCHG.txt");
	//gp_log[LOGCOINCHG].LogInit("LOGCOINCHG.txt");
	//gp_log[LOGEMTICKET].LogInit("LOGEMTICKET.txt");
	//gp_log[LOGREADER1].LogInit("LOGREADER1.txt");
	//gp_log[LOGTOPSCR].LogInit("LOGTOPSCR.txt");
	//gp_log[LOGPRINTER].LogInit("LOGPRINTER.txt");
	//gp_log[LOGUPS].LogInit("LOGUPS.txt");
	//gp_log[LOGMOUSEBUTT1].LogInit("LOGMOUSEBUTT1.txt");
	//gp_log[LOGKEYPRESS].LogInit("LOGKEYPRESS.txt");
	 
	gp_log[LOGNULL].Init(		gp_conf->Get_logpath5(),	"LOGNULL",		15 );
	gp_log[LOGAPP].Init(		gp_conf->Get_logpath5(),	"LOGAPP",		15 );
	gp_log[LOGSOP].Init(		gp_conf->Get_logpath5(),	"LOGSOP",		15 );
	gp_log[LOGSC].Init(			gp_conf->Get_logpath5(),	"LOGSC",		15 );
	
	gp_log[LOGBILL].Init(		gp_conf->Get_logpath5(),	"LOGBILL",		15 );
	gp_log[LOGCOIN].Init(		gp_conf->Get_logpath5(),	"LOGCOIN",		15 );
	gp_log[LOGBILLCHG].Init(	gp_conf->Get_logpath5(),	"LOGBILLCHG",		15 );
	gp_log[LOGCOINCHG].Init(	gp_conf->Get_logpath5(),	"LOGCOINCHG",		15 );
	gp_log[LOGEMTICKET].Init(	gp_conf->Get_logpath5(),	"LOGEMTICKET",		15 );
	gp_log[LOGREADER1].Init(	gp_conf->Get_logpath5(),	"LOGREADER1",		15 );
	
	gp_log[LOGTOPSCR].Init(		gp_conf->Get_logpath5(),	"LOGTOPSCR",		15 );
	gp_log[LOGPRINTER].Init(	gp_conf->Get_logpath5(),	"LOGPRINTER",		15 );
	gp_log[LOGUPS].Init(		gp_conf->Get_logpath5(),	"LOGUPS",		15 );
	
	gp_log[LOGMOUSEBUTT1].Init(	gp_conf->Get_logpath5(),	"LOGMOUSEBUTT1",	15 );
	gp_log[LOGKEYPRESS].Init(	gp_conf->Get_logpath5(),	"LOGKEYPRESS",		15 );


	for( int i = 0; i < LOGAMOUNT; i++ )
	{
		LOGSTREAM( gp_log[i], LOGPOSI << "tvm begin" );
	}
}



// 
bool IsOsWin()
{
#ifdef WINENV_
	return true;
#else
	return false;
#endif
}




#ifdef WINENV_
#pragma comment( lib, "glib-2.0.lib" )
#pragma comment( lib, "gtk-win32-2.0.lib" )
#pragma comment( lib, "gdk-win32-2.0.lib" )
#pragma comment( lib, "gobject-2.0.lib" )
#pragma comment( lib, "gdk_pixbuf-2.0.lib" )
#pragma comment( lib, "gthread-2.0.lib" )
#pragma comment( lib, "gmodule-2.0.lib" )
#pragma comment( lib, "pango-1.0.lib" )
//#pragma comment( lib, "C:\\gtk\\gtkbundle-2\\lib\\intl.lib" )
#pragma comment( lib, "atk-1.0.lib" )
#pragma comment( lib, "cairo.lib" )
#pragma comment( lib, "fontconfig.lib" )
#pragma comment( lib, "gailutil.lib" )
#pragma comment( lib, "gio-2.0.lib" )
#pragma comment( lib, "glib-2.0.lib" )
#pragma comment( lib, "gmodule-2.0.lib" )
#pragma comment( lib, "gobject-2.0.lib" )
#pragma comment( lib, "gthread-2.0.lib" )
#pragma comment( lib, "pangocairo-1.0.lib" )
#pragma comment( lib, "pangoft2-1.0.lib" )
#pragma comment( lib, "pangowin32-1.0.lib" )
#endif


//glib-2.0.lib
//gtk-win32-2.0.lib
//gdk-win32-2.0.lib
//gobject-2.0.lib
//gdk_pixbuf-2.0.lib
//gthread-2.0.lib
//gmodule-2.0.lib
//pango-1.0.lib
//intl.lib



