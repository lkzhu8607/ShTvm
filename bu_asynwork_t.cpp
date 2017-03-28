
#include "bu_asynwork_t.h"
#include "de_log_t.h"
#include "de_tcpmsg_t.h"
#include "d_db_t.h"
#include "de_ui_t.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"



//
bu_asynwork_t::bu_asynwork_t() 
{
	m_f = NULL;
}


//
bu_asynwork_t:: ~bu_asynwork_t()
{
	tr_destruct();
}



// 
int bu_asynwork_t::tr_on_user_run()
{
	if(m_f) (this->*m_f)();
	return 0;
}




//
void bu_asynwork_t::MouseHotPress( std::string strPosition )
{
	//bu_asynwork_t  *paw;

	//SStrf::newobjptr(paw);
	//paw->m_f = &bu_asynwork_t::MouseHotPress_m;

	//paw->m_para.let( "Position", strPosition );

	//paw->tr_openx();
}

//
void bu_asynwork_t::MouseHotPress_m()
{
	double x, y;
	int scr;

	if( de_ui_t::Parse_KIN_MOUSEBUTT1( m_para.get("Position"), scr, x, y ) )
	{
		char szname[123];
	
		sprintf( szname, "%p%s", &m_para , this->tr_GetCurrentThreadId().c_str() );
		
		x -= 11.01 / gp_ui->Get_scr_width(scr);
		y -= 11.01 / gp_ui->Get_scr_height(scr);

		gp_ui->LabelMkPicPrep( scr, szname, "3.png", x, y, 0, 0 );
		gp_ui->LabelCommit();
		WThrd::tr_sleepu( 0.7 );
		gp_ui->LabelMkDelPrep( szname );
		gp_ui->LabelCommit();
	}
}


//
void bu_asynwork_t::DelayCloseDownlight( /*bu_quickflow_t::qf_counter_t*/void * pQf )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DelayCloseDownlight_m;

	paw->m_para.let( "p", SStrf::b2s(pQf) );

	paw->tr_openx();
}

//
void bu_asynwork_t::DelayCloseDownlight_m()
{
	bu_quickflow_t::qf_counter_t * pQf;

	SStrf::s2b( m_para.get("p") , pQf );

	if( *pQf == 0 ) return;
	WThrd::tr_sleep( 5 );
	if( *pQf == 0 ) return;

	if( gp_qf->IsLongQf( *pQf, 4.5 ) ) 
	{
		gp_coin->dCoinCloseDownlight();
	}
}



//
void bu_asynwork_t::RepeatSendReg6000()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::RepeatSendReg6000_m;

	paw->tr_openx();
}


//
void bu_asynwork_t::RepeatSendReg6000_m()
{
	while(1)
	{
		longarr2v_t<7,96> TimeTableShenJi;
		tbool rc;
		int ShouldSec = 99;
		SDte dt1, dt2;
		int iWeekDay;
		int i;

		if(1)
		{
			MYAUTOLOCK( gp_db->m_a3002.m_ut_tbl_lck );
			
			a3002_t::RPSTYPE rps1, rps2;

			gp_db->m_a3002.SelEc_biDelFlag( 0, rps1 ); // not del
			//
			gp_db->m_a3002.SelEc_biIsAffect( 1, rps2 ); // affect
			gp_db->m_a3002.RpsAnd( rps1, rps2 );

			if( gp_db->m_a3002.GetRowCount( rps1 ) == 0 ) 
				rc = 0;
			else
				rc = 1;

			if(rc) TimeTableShenJi = gp_db->m_a3002.GetRow( rps1, 0 ).m_TimeTableShenJi;
		}

		if( rc == 0 )
		{
			WThrd::tr_sleep(33);
			continue;
		}


		dt1.MakeNow();
		dt2.Make( dt1.ReadStrDate() );
		iWeekDay = dt1.WeekDay();
		i = dt1.DiffSecInt(dt2) / (15*60);
		ShouldSec = TimeTableShenJi.a[iWeekDay][i];
		if( ShouldSec < 10 ) ShouldSec = 99;
	
		WThrd::tr_sleep(ShouldSec);

		de_tcpmsg_t::SendReg6000(0x00);
	}
}





//
void bu_asynwork_t::DelayReboot( int iSec )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DelayReboot_m;

	paw->m_para.let( "p", SStrf::b2s(iSec) );

	paw->tr_openx();
}

//
void bu_asynwork_t::DelayReboot_m()
{
	int iSec;

	SStrf::s2b( m_para.get("p") , iSec );

	WThrd::tr_sleep(iSec);

	gp_conf->m_biSysShouldReboot = 1;
}





//
void bu_asynwork_t::DoSetThisIp()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoSetThisIp_m;

	paw->tr_openx();
	
	if( IsOsWin() )
		WThrd::tr_sleep(1);
}


//
void bu_asynwork_t::DoSetThisIp_m()
{
	if( IsOsWin() ) return;

	while(1)
	{
		std::string s1 ;
		
		s1 = "/sbin/ifconfig em1 " + gp_conf->getnvB("this_ip") +" netmask 255.255.255.0";
		WFile::run_exe( s1 );

		s1 = "route add default gw " + gp_conf->getnvB("this_gateway");
		WFile::run_exe( s1 );

		WThrd::tr_sleep(333);
	}
}






//
void bu_asynwork_t::DoTime1Server()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoTime1Server_m;

	paw->tr_openx();
	
	if( IsOsWin() )
		WThrd::tr_sleep(1);
}


//
void bu_asynwork_t::DoTime1Server_m()
{
	if( IsOsWin() ) return;
	while(1)
	{
		std::string s1 ;
		
		s1 = "sntp -a " + gp_conf->getnvB("time1_server");
		WFile::run_exe( s1 );

		WThrd::tr_sleep(333);
	}
}




//
void bu_asynwork_t::DoTime2Server()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoTime2Server_m;

	paw->tr_openx();
	
	if( IsOsWin() )
		WThrd::tr_sleep(1);
}


//
void bu_asynwork_t::DoTime2Server_m()
{
	if( IsOsWin() ) return;
	while(1)
	{
		std::string s1 ;
		
		s1 = "ntpdate " + gp_conf->getnvB("time2_server");
		WFile::run_exe( s1 );

		WThrd::tr_sleep(333);
	}
}


void bu_asynwork_t::DoAlarmnSec( int iSec )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoAlarmnSec_m;

	paw->m_para.let( "p", SStrf::b2s(iSec) );

	paw->tr_openx();

}

void bu_asynwork_t::DoAlarmnSec_m()
{

	int iSec;

	SStrf::s2b( m_para.get("p") , iSec );

	gp_coin->dCoinOpenAlert();

	WThrd::tr_sleep(iSec);

	gp_coin->dCoinCloseAlert();

}


