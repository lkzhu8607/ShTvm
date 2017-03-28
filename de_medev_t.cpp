
//
#include "2.h"
#include "de_medev_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_tcpmsg_t.h"
#include "de_log_t.h"
#include "de_base_realmode.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_topscr_t.h"
#include "g06.h"



//
de_medev_t   *gp_medev;



//
de_medev_t::de_medev_t()
{
	m_devstatus = 3;
	m_legal_authority = 0;
	m_IsLegalLoginMaintenance = 0;
	m_outofservicestatus = 12;

	m_IsOpenDoorSellModule = 0;

	m_IsYunYingEnd = 0;

	m_IsEmergeModel = 0;

	m_IsRecv3014 = 0;
	m_IsSCNeedSysShutdownOrReboot = 0;
	m_IsChangeToStopSerice = 0;
}


//
de_medev_t::~de_medev_t()
{
}



//
void de_medev_t::OnRunTask( std::string t ) //��t������һ��ָ�롣��Ҫdelete. 
{
	a5041_t::ROWTYPE * p;

	SStrf::s2b( t, p );

	for( int i = 0; i < gp_db->Get5041EvtCapacity() ; i++ )
	{
		if( p->m_e_old.a[i] != p->m_e.a[i] ) //����¼����б仯��˵���������¼� 
		{
			//send the 5041 event
			//
			gp_tcpmsg->Send1Evt5041( p->m_e_old.a[i] , p->m_e.a[i], i );

			a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); //��һ��copy�ڹ�������Ҫ�������ݡ� 

			Ra5041.m_e_old.a[i] = Ra5041.m_e.a[i];

			Ra5041.m_e_flag.a[i] = 1;
		}

	}
	 
	goto L_TASKEND;
	
L_TASKEND:
	delete p;
	return;
}


//
void de_medev_t::tr_on_pre_thrd()
{
	//�ȷ�2��ȫ0 ��������¼�
	for( int i = 0 ; i < 2 ; i++ )
	{
		WThrd::tr_sleepu( 1 );
		
		//����ʱ�ϴ�evt 00,00�� ������evt 
		gp_tcpmsg->Send1Evt5041( 1 , 0, 0 );
	}

	WThrd::tr_sleepu( 2.91 );
}


// 
int de_medev_t::tr_on_user_run()
{
	a5041_t::ROWTYPE &Ra5041(gp_db->GetTheRowa5041());

	do{
		break;

	}while(0);

	WThrd::tr_sleepu( 0.91 );

	gp_db->LasyRiseSaveFlag_a5041(Ra5041);

	return 1;
}


// 
void de_medev_t::MedevInit()
{
	this->tr_open();

}

bool de_medev_t::IsOnlyCoin()
{
	if( m_devstatus == 5 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool de_medev_t::IsOnlyBill()
{
	if( m_devstatus == 6 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

//#define E_CHG_0(eventnum)	do{ if( Ra5041.m_e.a[eventnum] != 0 )	biEChgFlag = 1; Ra5041.m_e.a[eventnum] = 0; } while(0)
//#define E_CHG_1(eventnum)	do{ if( Ra5041.m_e.a[eventnum] != 1 )	biEChgFlag = 1; Ra5041.m_e.a[eventnum] = 1; } while(0)
//#define S0_CHG_0(statusnum)	do{ if( Ra5041.m_s0.a[statusnum] != 0 ) biSChgFlag = 1; Ra5041.m_s0.a[statusnum] = 0; } while(0)
//#define S0_CHG_1(statusnum)	do{ if( Ra5041.m_s0.a[statusnum] != 1 ) biSChgFlag = 1; Ra5041.m_s0.a[statusnum] = 1; } while(0)
//#define S1_CHG_0(statusnum)	do{ if( Ra5041.m_s1.a[statusnum] != 0 ) biSChgFlag = 1; Ra5041.m_s1.a[statusnum] = 0; } while(0)
//#define S1_CHG_1(statusnum)	do{ if( Ra5041.m_s1.a[statusnum] != 1 ) biSChgFlag = 1; Ra5041.m_s1.a[statusnum] = 1; } while(0)
#define EVT_CHG(eventnum,evtvalue)	do{ if( Ra5041.m_e.a[eventnum]  != evtvalue  )  biEChgFlag = 1, Ra5041.m_e.a[eventnum] = evtvalue; } while(0)
#define S0_CHG(statenum,statevalue)	do{ if( Ra5041.m_s0.a[statenum] != statevalue ) biSChgFlag = 1, Ra5041.m_s0.a[statenum] = statevalue; } while(0)
#define S1_CHG(statenum,statevalue)	do{ if( Ra5041.m_s1.a[statenum] != statevalue ) biSChgFlag = 1, Ra5041.m_s1.a[statenum] = statevalue; } while(0)


#include "de_medev00_refresh5041_app_sub.xpp"


// ÿģ����һ�飺����5041���ֶΣ�ÿ�ֶα�����ģ��Ĵ�����ˢ��5041.ģ��״̬��5041 �Ĺ�ϵ�� 
// ������������ģ��
//
tbool de_medev_t::Refresh5041_dev( std::string strinput )
{
	char c = strinput[0];

	if( c == KIN_APP	/*||  
		c == KIN_SC 	*/	)
	{
		return 1;
	}

	//if( c == KIN_UPS )
	//{
	//	c = c;
	//}


	if( c == KIN_COIN	||  
		c == KIN_BILL || 
		c == KIN_EMTICKET || 
		c == KIN_READER1 || 
		c == KIN_BILLCHG  ||
		c == KIN_TOPSCR  ||
		c == KIN_PRINTER  ||
		c == KIN_UPS      ||
		c == KIN_SC
		)
	{ 
		//flow down
	}
	else
	{
		return 0;
	}

	tbool biEChgFlag = 0;
	tbool biSChgFlag = 0;

	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());

	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	b8703_t::ROWTYPE & Rb8703(gp_db->GetTheRowb8703());
	b8704_t::ROWTYPE & Rb8704(gp_db->GetTheRowb8704());
	b8705_t::ROWTYPE & Rb8705(gp_db->GetTheRowb8705());

	b8706_t::ROWTYPE & Rb8706(gp_db->GetTheRowb8706());
	b8707_t::ROWTYPE & Rb8707(gp_db->GetTheRowb8707());
	b8708_t::ROWTYPE & Rb8708(gp_db->GetTheRowb8708());



	//	����	
	//
#ifdef DE_GOOD_FLAG
	#include "de_medev21_GOOD_FLAG.xpp"
#endif



	if( Refresh5041_app_sub() )		//	������״̬	
	{
		biEChgFlag = biSChgFlag = 1;
	}


	//if( c == KIN_COIN )
	#include "de_medev11_KIN_COIN.xpp"

	//if( c == KIN_BILL )
	#include "de_medev12_KIN_BILL.xpp"

	//if( c == KIN_EMTICKET )
	#include "de_medev13_KIN_EMTICKET.xpp"

	//if( c == KIN_READER1 )
	#include "de_medev14_KIN_READER1.xpp"

	//if( c == KIN_BILLCHG )
	//#include "de_medev15_KIN_BILLCHG.xpp"

	//if( c == KIN_TOPSCR )
	#include "de_medev16_KIN_TOPSCR.xpp"

	//if( c == KIN_PRINTER )
	#include "de_medev17_KIN_PRINTER.xpp"

	//if( c == KIN_UPS )
	#include "de_medev18_KIN_UPS.xpp"


	int iChangeModule = 0;
	//iChangeModule = CanChange();

	LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"now coin num="<< gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ );

	if( ( ( gp_db->m_b8702.GetRow(0).m_BillStopUseFlag == 1 ) ||
		( gp_db->m_b8702.GetRow(0).m_BigErr == 1 || gp_db->m_b8702.GetRow(0).m_ConnState == 0 ) ||
		( gp_bill->IsVaultFull() ) || 
	    ( ( gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ + 
		    gp_db->m_b8701.GetRow(0).m_A5MaoCycleChg  /*+ gp_db->m_b8701.GetRow(0).m_A5MaoSpecialChg */) < 
			gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) ) && 
		( ( gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag == 1 ) ||
	    ( gp_db->m_b8701.GetRow(0).m_BigErr == 1 || gp_db->m_b8701.GetRow(0).m_ConnState == 0 ) ||
		( gp_coin->IsVaultFull() ) || 
		( gp_db->m_a5041.GetRow(0).m_e.a[137] == 1 ) ) )
	{
		//ֽ��Ӳ�Ҷ������⣬��ͣ����
		// ��� �¼� 136 135
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Coin And Bill Have Truble To Out Of Service");

		EVT_CHG(135,0);
		EVT_CHG(136,0);
		//S0_CHG(1,1);
		m_devstatus = 4;
	}
	//1.ģʽ�ֶ���Ϊֻ��Ӳ��ģʽ   2.ֽ�ҽ���װ�ó��ֹ���   3.ֽ��ѭ�����㶷��ֽ�һ�������  
	//4.Ӳ�Ҳ����䣬Ӳ�һ������㶷Ӳ�Ҵ���С����ͱ�������ֵ  5.��Ӳ������(Ӳ������������С����������) -----> ֻ��Ӳ��ģʽ
	else if( ( gp_db->m_b8702.GetRow(0).m_BillStopUseFlag == 1 ) ||
		( gp_db->m_b8702.GetRow(0).m_BigErr == 1 || gp_db->m_b8702.GetRow(0).m_ConnState == 0 ) ||
		( gp_bill->IsVaultFull() ) || 
	    ( ( gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg /*+ gp_db->m_b8701.GetRow(0).m_A1YuanSpecialChg*/ + 
		    gp_db->m_b8701.GetRow(0).m_A5MaoCycleChg  /*+ gp_db->m_b8701.GetRow(0).m_A5MaoSpecialChg */) < 
			gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) )
	{
		// 136	ֻ��Ӳ��
		EVT_CHG(136,1);
		EVT_CHG(135,0);
	}

	//1.ģʽ�ֶ���Ϊֻ��ֽ��ģʽ   2.Ӳ�ҽ���װ�ó��ֹ��ϣ�Ӳ���䲻��λ��   3.Ӳ�һ������Ӳ���ݴ�����  -----> ֻ��ֽ��ģʽ
	else if( ( gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag == 1 ) ||
	    ( gp_db->m_b8701.GetRow(0).m_BigErr == 1 || gp_db->m_b8701.GetRow(0).m_ConnState == 0 ) ||
		( gp_coin->IsVaultFull() ) || 
		( gp_db->m_a5041.GetRow(0).m_e.a[137] == 1 ) )    //137 Ӳ�һ����䲻��λ 
	{
		// 135	ֻ��ֽ��
		EVT_CHG(135,1);
		EVT_CHG(136,0);
	}
	else
	{
		// ��� �¼� 136 135
		EVT_CHG(135,0);
		EVT_CHG(136,0);

		m_devstatus = 3;
	}

	

	//******�����¼��룺 

	if( biEChgFlag || biSChgFlag )
	{
		a5041_t::ROWTYPE * pR5041 = new a5041_t::ROWTYPE;

		*pR5041 = Ra5041;
		this->PostTask( SStrf::b2s(pR5041) );
	}


	return 1;
}


		
//
void de_medev_t::EvtInitBegin()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	// 4	����δ��ʼ��	��	��	��	��	��	5
	Ra5041.m_e.a[4] = 1;
	Ra5041.m_e_old.a[4] = !Ra5041.m_e.a[4];
	Ra5041.m_e_flag.a[4] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[4] , p->m_e.a[4], 4 );
	Ra5041.m_e_old.a[4] = Ra5041.m_e.a[4];

	
	//����	 71	��		��	��	��	��	0
	Ra5041.m_e.a[71] = 0;
	Ra5041.m_e_old.a[71] = !Ra5041.m_e.a[71];
	Ra5041.m_e_flag.a[71] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[71] , p->m_e.a[71], 71 );
	Ra5041.m_e_old.a[71] = Ra5041.m_e.a[71];

	gp_frontinput->input_KIN_APP();
}


//
void de_medev_t::EvtInitEnd()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	// 4	����δ��ʼ��	��	��	��	��	��	5
	// ��ʼ���������������ȫ��E4=0
	if(1)
	{
		if( this->IsEODComplete() )
			Ra5041.m_e.a[4] = 0;
		else
			Ra5041.m_e.a[4] = 1;

		Ra5041.m_e_old.a[4] = !Ra5041.m_e.a[4];
		Ra5041.m_e_flag.a[4] = 1;
		gp_tcpmsg->Send1Evt5041( p->m_e_old.a[4] , p->m_e.a[4], 4 );
		Ra5041.m_e_old.a[4] = Ra5041.m_e.a[4];
	}

	//����	 71	��		��	��	��	��	0
	Ra5041.m_e.a[71] = 1;
	Ra5041.m_e_old.a[71] = !Ra5041.m_e.a[71];
	Ra5041.m_e_flag.a[71] = 1;
	gp_tcpmsg->Send1Evt5041( p->m_e_old.a[71] , p->m_e.a[71], 71 );
	Ra5041.m_e_old.a[71] = Ra5041.m_e.a[71];

	gp_frontinput->input_KIN_APP();
}


//
void de_medev_t::GetEvtStr( std::string & strOut )
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041()); 
	a5041_t::ROWTYPE * p = & Ra5041;

	strOut = " "; // ����ʱ����ǰ��ӿո񼴿��� 

	for( int i = 0; i < gp_db->Get5041EvtCapacity() ; i++ )
	{
		if( p->m_e.a[i] ) 
		{
			strOut += SStrf::sltoa( i );
			strOut += " ";
		}
	}
}


//
std::string de_medev_t::GetEvtStr()
{
	std::string a;
	GetEvtStr(a);
	return a;
}



//return value:
// -1 : ��ͨ��ͣ����
// 0 : ������ͣ����
// 1 : normal
// 
tbool de_medev_t::IntegratedStateGood()
{
	a5041_t::ROWTYPE & Ra5041(gp_db->GetTheRowa5041());
	//��ͣ���� ������   1.��Ʊ�ڿ�Ʊ 2.����ͨ����Ʊ 3. Ʊ��� 4. Ӳ�Ҵ���Ԫ����λ 5.����Ʊ��д��ͨѶ���� 
	//6.���ư�1ͨѶ���� 7.ά���ſ� 8.���յ�����ģʽ
	std::string strshow = "      ��ͣ����      "
			              "   Out Of Service  ";

	
	// m_e.a[4]		����δ��ʼ��
	if( Ra5041.m_e.a[4] == 1 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[4] = " );
		this->m_outofservicestatus = 13;
		m_devstatus = 4;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// s0.a[0]		0	��(1)/��(0)
	if( Ra5041.m_s0.a[0] == 0 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s0.a[0] = " );
		m_devstatus = 7;
		gp_topscr->DispStr( strshow );
		return -1;
	}


	if( Ra5041.m_e.a[62] == 1 )     //62 ����ģʽ
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[62] = ");
		m_devstatus = 7;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// s0.a[1]		1	ֹͣ����(1)/�޹���(0)
	if( Ra5041.m_s0.a[1] == 1 )
	{
		 strshow = "      �رշ���      "
			       "    Stop Service   ";

		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s0.a[1] = " );
		m_devstatus = 9;
		gp_topscr->DispStr( strshow );

		return -1;
	}
	if( 0 == gp_medev->m_IsOpenDoorSellModule )
	{
		// s1.a[0]		�ſ�(1)  //ά���ŵ�λ�ź�
		if( Ra5041.m_s1.a[0] == 1 || m_IsLegalLoginMaintenance == 1 )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s1.a[0] = " );

			if( 1 == this->m_IsLegalLoginMaintenance )
			{
				//����ά��
				gp_db->m_a5041.GetRow(0).m_e.a[59] = 1;   //TVMά������¼���¼����루59��

				LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"m_IsLegalLoginMaintenance =1 " );
				m_devstatus = 7;
				gp_topscr->DispStr( strshow );
				return -1;
				
			}
			else
			{
				//ֻ���ſ�
				gp_db->m_a5041.GetRow(0).m_e.a[59] = 0;
				this->m_outofservicestatus = 12;
				m_devstatus = 4;
				gp_topscr->DispStr( strshow );
				return 0;
			}
		}
		else
		{
			gp_db->m_a5041.GetRow(0).m_e.a[59] = 0;   //����������Ž�ά���ĵ�¼��־��
		}

		// s1.a[1]		�ű�����(1)
		if( Ra5041.m_s1.a[1] == 1 )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_s1.a[1] = ");
			this->m_outofservicestatus = 12;
			m_devstatus = 4;
			gp_topscr->DispStr( strshow );
			return 0;
		}
	}

	// 130 ����ģ�黵
	if( Ra5041.m_e.a[130] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[130]");
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 11 ��Ʊ�ڿ�Ʊ 
	if( Ra5041.m_e.a[11] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[11] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 12 ����ͨ����Ʊ 
	if( Ra5041.m_e.a[12] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[12] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//113 Ʊ���ʱ����ͣ���� //��ʾƱ����
	if( Ra5041.m_e.a[113] && 
	    Ra5041.m_e.a[115] 	&& 
		SStrf::readbit( gp_db->m_b8703.GetRow(0).m_SensorStatus.a[0], 4 ) == 0 )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041 = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 11;
		gp_topscr->DispStr("      ��ͣ����");

		return 0;
	}
	
	//129 Ӳ�Ҵ���Ԫͨ�Ź���
	if(Ra5041.m_e.a[129])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[129] " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//303 Ӳ�Ҵ���Ԫ����λ
	if(Ra5041.m_e.a[303])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[303] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 179 ������/������
	if(Ra5041.m_e.a[179])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[179] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 180 Ʊ�ٳ�/Ʊ���
	if(Ra5041.m_e.a[180])
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[180] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 120 TVM������1���� 
	if( Ra5041.m_e.a[120] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[120] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	// 116 ��Ʊ���� 
	if( Ra5041.m_e.a[116] )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[116] = " );
		m_devstatus = 4;
		this->m_outofservicestatus = 12;
		gp_topscr->DispStr( strshow );
		return 0;
	}


	//����Ϊ��������µĽ���ģʽ
	if( Ra5041.m_e.a[135] )
	{
		strshow = "      ֻ��ֽ��      "
			      "      Note Only    ";
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[135] = " );
		m_devstatus = 6;
		gp_topscr->DispStr( strshow );
		if(1)
		{
			//�������ֽ������״̬
			//MYAUTOLOCK( gp_bill->m_DevLck );
			//gp_bill->m_iIsNotBillChange = 0;
		}
		return 1;
	}

	if( Ra5041.m_e.a[136] )
	{
		strshow =  "      ֻ��Ӳ��      "
			       "      Coin Only    ";
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"Ra5041.m_e.a[136] = " );
		m_devstatus = 5;
		gp_topscr->DispStr( strshow );
		if(1)
		{
			//�������ֽ������״̬
			MYAUTOLOCK( gp_bill->m_DevLck );
			gp_bill->m_iIsNotBillChange = 0;
		}
		return 1;
	}

	//��ֽ��Ӳ��ͬʱ�����������ͣ����
	if( 4 == m_devstatus )
	{
		
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"m_devstatus = "<< 4 );
		this->m_outofservicestatus = 12;
		m_devstatus = 4;
		gp_topscr->DispStr( strshow );
		return 0;
	}

	//����������Ʊ
	if( 1 )
	{
		strshow = "      ������Ʊ      "
			      "     In Service    " ;

		m_devstatus = 3;
		gp_topscr->DispStr( strshow );

		// 1.�������������( ֽ�ҿ������� < ���������� )  2.�������ò�����  -> ��ֽ������   (ֻ��������Ʊģʽ�ż���Ƿ���ֽ������)
		int iRMB500 ,iRMB1000 ,iRMB2000 ,iRMB5000;
		iRMB500 = iRMB1000 = iRMB2000 = iRMB5000 = 0;
		
		gp_bill->dBill_QueryCashUint();
		for(int i=0;i<4;i++)
		{
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 500 )  iRMB500  += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 1000 ) iRMB1000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 2000 ) iRMB2000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
			if( gp_db->m_b8702.GetRow(0).m_ReDenomination.a[i] == 5000 ) iRMB5000 += gp_db->m_b8702.GetRow(0).m_ReNumber.a[i];
		}

		if ( ( 0 == SStrf::readbit( gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0], 0 ) ) || 
			 ( ( iRMB500 + iRMB1000 + iRMB2000 + iRMB5000 )<gp_db->m_a3003.GetRow(0).m_BillChgMaxNum ) 
			)  
		{
			// 76	��ֽ������
			gp_db->m_a5041.GetRow(0).m_e.a[76] = 1;
			//EVT_CHG(76,1);
			if(1)
			{
				MYAUTOLOCK( gp_bill->m_DevLck );
				gp_bill->m_iIsNotBillChange = 1;
			}
		}
		else
		{
			//EVT_CHG(76,0);
			gp_db->m_a5041.GetRow(0).m_e.a[76] = 0;
			if(1)
			{
				MYAUTOLOCK( gp_bill->m_DevLck );
				gp_bill->m_iIsNotBillChange = 0;
			}
		}

	}
	
	return 1;
}



//
template < class T >
static tbool ChkEod_2( T & eodtbl )
{
	MYAUTOLOCK( eodtbl.m_ut_tbl_lck );
	typename T::RPSTYPE rps1, rps2;
	eodtbl.SelEc_biDelFlag( 0, rps1 );
	eodtbl.SelEc_biIsAffect( 1, rps2 );
	eodtbl.RpsAnd( rps1, rps2 );
	if( eodtbl.GetRowCount( rps1 ) == 0 )
	{
		std::string strTblName = eodtbl.ut_GetItemStr(-1,"strTblName");
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "ȱ�ٲ����������ǣ�" << strTblName );
		return 0;
	}

	return 1;
}


//
tbool de_medev_t::IsEODComplete()
{
	if( !ChkEod_2( gp_db->m_a2000 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3002 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3003 ) )
		return 0;
	 
	if( !ChkEod_2( gp_db->m_a3006 ) )
		return 0;
	
	if( !ChkEod_2( gp_db->m_a3007 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3009 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3011 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3083 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3084 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a3086 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4001 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4002 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4003 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4004 ) )
		return 0;

	if( !ChkEod_2( gp_db->m_a4006 ) )
		return 0;


	return 1;
}




