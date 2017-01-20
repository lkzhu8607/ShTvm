
#include "2.h"
#include "d_cg02s_waiter_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_ui_t.h"
#include "d_str_res.h"
#include "d_db_t.h"
#include "d_cg02_t.h"
#include "bu_frontman_mgr_t.h"
#include "bu_asynwork_t.h"
#include "bu_quickflow_t.h"
#include "de_medev_t.h"
#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"
#include "g06.h"
#include "de_printer_t.h"

#include <iostream>
using namespace std;


static	bu_quickflow_t::qf_counter_t  v_QfDownlight = 0;

//
d_cg02s_waiter_t::d_cg02s_waiter_t()
{
	gp_coin->dCoinOpenUplight();

	v_QfDownlight = 0;
	gp_coin->dCoinOpenDownlight();
}


//
d_cg02s_waiter_t::~d_cg02s_waiter_t()
{
	gp_coin->dCoinCloseUplight();

	gp_qf->GetQf( v_QfDownlight );
	bu_asynwork_t::DelayCloseDownlight(&v_QfDownlight);
}



class _Plan_t;
class MoneyStorePlan_t;		// 
class TicketoutPlan_t;		// 
class CoinRecycleChgPlan_t;	// 
class CoinSpecialChgPlan_t;	// 
class BilchgPlan_t;			// 	
#include "d_cg02s_waiter_00.xpp"




// return value:
// 0 : normal
// 1 : Ʊ�ٳ�/Ʊ���
// 2 : ������/������
int d_cg02s_waiter_t::FnD_WaiterJob( std::string strinput , a_waiter_t_rowtype * pwaiterdata )
{
	LOGSTREAM( gp_log[LOGAPP], LOGPOSI );
	int irc = 0;

	a_waiter_t_rowtype &WR( *pwaiterdata );
	b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());

	//���Ǯ�� ����5ë����ȫ�˻ء�
	//1�����5�ǵ�ѭ������û��5�ǣ����˳�Ǯ��ȡ�����ν���
	//2�����5��ѭ�������п��������Ӳ�ң����������
	if( ( WR.m_Coin5 % 2 != 0 ) && (Rb8701.m_A5MaoCycleChg == 0) )
	{
		//
		//return Coin And Bill
		ReturnCoinAndBill( WR );

		////��Ӳ��
		//gp_coin->returnCoin();

		////��ֽ��
		//if(WR.m_ReceiveBill >0)
		//{
		//	gp_bill->dBill_Refund();
		//	WR.m_ReceiveBill = 0;
		//	WR.m_ReceiveTotal = WR.m_ReceiveCoin;
		//}
		return irc;
	}


	//Ԥ����
	//������Ǯ - �������� * Ʊ��
	if( WR.m_ShouldChgTotal )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_ShouldChgTotal = "<<WR.m_ShouldChgTotal );

		if( !CanChange( WR.m_ShouldChgTotal ,&WR.m_CoinRecycleChgPlan ,&WR.m_BilchgPlan ) )
		{
			LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_CoinRecycleChgPlan = "<<WR.m_CoinRecycleChgPlan<<"m_BilchgPlan="<< WR.m_BilchgPlan);

			//�������㣬���˱�
			//return Coin And Bill
			ReturnCoinAndBill( WR );

			//��¼��Ҫ���㣬��������

			return irc;
		}

		//��¼��Ҫ���㣬�ҿ���
	}
	else
	{
		//��¼����Ҫ����
	}

	int ticketbad = 0;

	//��һ�ų�Ʊ 
	if(WR.m_TicketingFirstFlag == 0)//���е�һ�η���
	{
		
		while( ticketbad < 3 )
		{
			//wl::WThrd::tr_sleepu(0.5);
			if( gp_emitticket->MkTicketReady() )
			{

				//
				int ret = 0;
				//2.����
				ret  = gp_reader1->rReadCard();
				if( ret == 0 )
				{
					//�ɹ�
					//3.д��
					ret = gp_reader1->rSaleCard2( WR.m_TickePrice1*100) ;
					if( ret == 0 )
					{
						//д���ɹ��򿨷���ȥ
						if( !gp_emitticket->eTicket_SendOut() ) // ��ס 
						{
							LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "ticketing succ");
							
							WR.m_TicketingFirstFlag = 1;//��һ�η������
							WR.m_TicketingFirstDone = 1;//��һ�η����ɹ�
							WR.m_TicketoutActual++;
							WR.m_TicketoutOk = 1;
							break;
						}
						else
						{
							LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "Send Ticket Error");
							WR.m_TicketoutOk = 0;  WR.m_TicketoutErrReason = -2;
						}
					}
					else
					{
						//д��ʧ��
						LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "rSaleCard2 Error ret= "<<ret);
						WR.m_TicketoutOk = 0;  WR.m_TicketoutErrReason = -1;
					}
				}
				else
				{
					//����ʧ��
					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "rReadCard Error ret = "<<ret );
					WR.m_TicketoutOk = 0;  WR.m_TicketoutErrReason = -3;
				}
				
				//ִ�е����Ǳ�ʾ���������ʧ�ܣ�������Ʊ��
				if( gp_emitticket->eTicket_SendIn() )   //������Ʊ��
				{
					//������Ʊ��ʧ�ܣ���Ǯ����ͣ����
					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "eTicket_SendOutIn Error");
					WR.m_TicketoutOk = 0;
					gp_db->m_b8703.GetRow(0).m_BigErr = 1;
					break;
				}
				
			}
			else
			{
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "Perpare Tciket Error");
				WR.m_TicketoutOk = 0;
				//return (-1);
			}

			ticketbad++;
		}
		
		//���׽���ʱ��Ϊ��Ʊʱ�䣬�����Ƿ��Ʊ�ɹ���ʧ��
		WR.m_end_time = wl::SDte::GetNow();
	}

	WR.m_MoneyStoreDone = WR.m_TicketoutDone = WR.m_CoinRecycleChgDone = WR.m_BilchgDone = 1;

	WR.m_BilchgOk = WR.m_BilchgDone = WR.m_CoinRecycleChgOk = WR.m_CoinRecycleChgDone = 1;
	if( WR.m_TicketingFirstDone == 1 )
	{
		//1.ѹ��
		WR.m_MoneyStoreOk =	WR.m_MoneyStoreDone = 0;
		SStrf::newobjptr<MoneyStorePlan_t>()->MyInit(pwaiterdata);	

		//2.�����ʣ���Ʊ�����ʣ���Ʊ
		if( WR.m_TicketoutPlan > WR.m_TicketoutActual )
		{
			WR.m_TicketoutOk = WR.m_TicketoutDone = 0;
			WR.m_TicketoutErrReason = 0;
			SStrf::newobjptr<TicketoutPlan_t>()->MyInit(pwaiterdata);
		}

		//�ȴ�ѹ��ͳ�Ʊ��
		while(1)
		{
			WThrd::tr_sleepu( 0.8 );

			LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"while wait allwork");

			if( WR.m_MoneyStoreDone && 
				WR.m_TicketoutDone )
			{
				//gp_emitticket->eTicket_CleanTemp();
				break;
			}

		}

		//3.����
		//��Ҫ�ҵ���Ǯ = ���յ���Ǯ - ʵ�ʳ�Ʊ������ * ÿ�ŵ�Ʊ��(��) * 100
		WR.m_ShouldChgTotal = WR.m_ReceiveTotal - WR.m_TicketoutActual * WR.m_TickePrice1 * 100;
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_ShouldChgTotal="<< WR.m_ShouldChgTotal <<" m_ReceiveTotal="<<WR.m_ReceiveTotal << "rea Total="<< WR.m_TicketoutActual * WR.m_TickePrice1 * 100 );
		if( WR.m_ShouldChgTotal )     //�����ܽ�� ���� Ʊ���ܽ�� ����Ҫ����
		{
			if( !CanChange( WR.m_ShouldChgTotal ,&WR.m_CoinRecycleChgPlan ,&WR.m_BilchgPlan ) )
			{
				//��ͣ����
				//��ӡ�쳣����
				a1040_t::ROWTYPE & Ra1040(gp_db->m_a1040.GetRow(0));
				BYTE t_line = 0x0F;	t_line &= (Ra1040.m_CcNode.a[0] >> 4);	
				int lineNum = (t_line * 10);	
				t_line = Ra1040.m_CcNode.a[0] & 0x0F;	
				lineNum += t_line;
				char str[1024] = {0};
				sprintf(str,"\t�Ϻ�����TVM�ֽ�Ʊ���ϼ�¼��\n\
				            ��վ            %s\n\
							��·	        �����ͨ%d����\n\
							�豸��	        V001\n\n\
							����ʱ��        %s\n\
				            ��������        �ֽ�Ʊ\n\n \	
				            ��Ʊ����        %dԪ\n\
							����            %d��\n\
							Ӧ�����        %.2fԪ\n\n\
				            ʵ��Ӳ��	    %.2fԪ\n\
				            ʵ��ֽ��	    %.2fԪ\n\	
				            Ӧ�ҽ��	    %.2fԪ\n\
				            ʵ�ʳ�Ʊ	    %d��\n\
				            ʵ������	    %dԪ\n\
				            �ٳ�Ʊ	        %d��\n\
				            ������	        %2.fԪ\n",\
				            gp_db->GetMyStaName().c_str(),lineNum,WR.m_begin_time.ReadString().c_str(),\
				            (WR.m_TickePrice1/100),WR.m_TicketoutPlan,(float)WR.m_TickePriceTotal,\
				            (((float)WR.m_ReceiveCoin)/100),(((float)WR.m_ReceiveBill)/100),\
				            (((float)WR.m_ShouldChgTotal)/100),WR.m_TicketoutActual,\
				            (WR.m_TicketoutPlan - WR.m_TicketoutActual),\
				            (((float)WR.m_ShouldChgTotal)/100 - (WR.m_CoinRecycleChgActual + WR.m_BilchgActual))							
						);	
				gp_printer->PrintStrAsync( str );
			}
			else
			{
				//ֽ������ 
				if( WR.m_BilchgPlan )
				{
					WR.m_BilchgOk = WR.m_BilchgDone = 0; 
					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_BilchgPlan=" << WR.m_BilchgPlan);

					SStrf::newobjptr<BilchgPlan_t>()->MyInit(pwaiterdata);
				}
				else
				{
				}

				// Ӳ��ѭ���ҡ����ʧ����һ����תר�á� 
				if( WR.m_CoinRecycleChgPlan )
				{
					WR.m_CoinRecycleChgOk = WR.m_CoinRecycleChgDone = 0;
					WR.m_CoinRecycleChgPlan = ( WR.m_CoinRecycleChgPlan / 100 ) ;   //����Ҫ�������Ǯ��ת��Ϊ���ҵĸ���

					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_CoinRecycleChgPlan=" << WR.m_CoinRecycleChgPlan );
					SStrf::newobjptr<CoinRecycleChgPlan_t>()->MyInit(pwaiterdata);
				}
				else
				{
				}
			}

		}
	}
	else
	{
		//����һ��Ʊʧ��
		//1.��ֽ�ҡ���Ӳ��
		//return Coin And Bill
		ReturnCoinAndBill( WR );
	}

	//�����Ϲ������ 
	while(1)
	{
		WThrd::tr_sleepu( 0.8 );

		LOGSTREAM( gp_log[LOGAPP], LOGPOSI <<"while wait allwork");

		if( WR.m_MoneyStoreDone && 
			WR.m_TicketoutDone && 
			WR.m_CoinRecycleChgDone && 
			WR.m_BilchgDone		)
		{
			break;
		}

	}

	//��Ʊ����
	if(WR.m_TicketoutActual)
	{
		bu_quickflow_t::qf_counter_t  iQf1_user_idle2;
		double iQf1_user_idleMAX2 = 15;

		gp_qf->GetQf( iQf1_user_idle2 );

		while(1)
		{
			if( ( WR.m_BilchgActual ) &&
				( 1 == gp_db->m_b8702.GetRow(0).m_wReturnShutter ) &&
			    ( !gp_qf->IsLongQf( iQf1_user_idle2 , iQf1_user_idleMAX2 )  )  )
			{
				
			}
			else
			{
				gp_emitticket->eTicket_CleanEscrow(0x01);	
				//�������ݼ�¼
				//����Ʊ��������
				gp_db->m_a_waiter_t.Add( WR );
				AddTransDataTo6000( WR );
				break;
			}
			
		}
	}

	

	//if Ʊ�ٳ�/Ʊ���-> event 180
	if( WR.m_TicketoutOk == 0 )
	{
		gp_db->m_a5041.GetRow(0).m_e.a[180] = 1;
		irc = 1;
		//EVT_CHG(180,1);
	}

	//if ������/������ -> event 179
	if(  WR.m_ShouldChgTotal && 
		( ( WR.m_BilchgOk == 0 ) || ( WR.m_CoinRecycleChgOk == 0 ) ) )
	{
		gp_db->m_a5041.GetRow(0).m_e.a[179] = 1;
		irc = 2;
		//EVT_CHG(179,1);

		gp_printer->PrintAbnormalTrans( WR );
		
	}
	

	return irc;
}





