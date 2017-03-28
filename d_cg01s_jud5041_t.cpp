
#include "2.h"
#include "d_cg01s_jud5041_t.h"
#include "d_cg01_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "bu_frontman_mgr_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "de_bill_t.h"




//
d_cg01s_jud5041_t::d_cg01s_jud5041_t()
{
}


//
d_cg01s_jud5041_t::~d_cg01s_jud5041_t()
{
}


//return value :
// 2 : ??????
// 1 : ??????
// 0 : normal 
tbool d_cg01s_jud5041_t::Find_n_do_stopservice( std::string strinput )
{
	if( gp_medev->Refresh5041_dev(strinput) )
	{
		//a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());

		//?if????,?return 1
		int irc = gp_medev->IntegratedStateGood();
		if( 0 == irc )
		{
			a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); //????	

			//gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
			//plocalcg01->displayFlag = 0;
			//plocalcg01->langFlag = 0;
			gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
			gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
			SetLanguageCh();

			gp_db->m_a5041.GetRow(0).m_e.a[104] = 1;       //进入故障暂停服务画面，则产生该事件码104

			return 2;
		}
		if( -1 == irc )
		{
			a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); //试验代码	

			//gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg04;

			gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
			gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
			SetLanguageCh();
			//plocalcg04->displayFlag = 0;
			//plocalcg04->langFlag = 0;

			gp_db->m_a5041.GetRow(0).m_e.a[104] = 0;       //清除事件码104

			return 1;
		}
	}

	return 0;
}


//
tbool d_cg01s_jud5041_t::Find_n_do_gotowork( std::string strinput )
{
	if( gp_medev->Refresh5041_dev(strinput) )
	{
		//a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());
		 
		// ?????????,???gotowork 
		int irc = gp_medev->IntegratedStateGood() ;
		if( ( 1 == irc ) )
		{
			//gp_frontman_mgr->m_pcg = &gp_frontman_mgr->m_cg01;
			//plocalcg01->displayFlag = 0;
			//plocalcg01->langFlang = 0;
			gp_frontman_mgr->m_cg01.m_cg01s_linepic_MainUiIdx = 1;
			gp_frontman_mgr->m_cg01.m_cg01s_seleline_PageStartIdx = 0;
			SetLanguageCh();

			gp_db->m_a5041.GetRow(0).m_e.a[104] = 0;       //清除事件码104

			
			gp_coin->RepCoinStock();    //检测是否需要补充硬币
			gp_coin->CleanCoinStock();  //检测是否需要清除部分硬币
			gp_bill->RepBillStock();    //检测是否需要补充纸币
			

			return 1;
		}
	}
	return 0;
}



