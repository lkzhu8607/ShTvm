
#ifndef K1_de_coin_t_H
#define K1_de_coin_t_H

#include "2.h"
#include "de_base_t.h"
#include "CoinCommand.h"



typedef unsigned int UNIT;
typedef unsigned char BYTE;


//  
class de_coin_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query ; 3=?��?��2��?����?����?��������?��������	
	CCoin m_coinmodule;
	int   m_iIsRepCoinOk;      // 1:ok   0:fail
	 
public:
	de_coin_t();
	virtual ~de_coin_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void CoinAdvice();
	void CoinInit();

	//������???��a?��?�� 
	bool dCommOpen();
	void dCommClose();
	int dCoin_State();		//��2����?��?�����䨬?2��?��0x31 
	int dCoin_Test(BYTE Data[2]);		//2.4��2����?��?��2a��??����?0x32
	int dCoin_Reset();		//2.5��2����?��?��3��D��?��??0x33
	int dCoin_GetVersion();	//2.6��2����?��?��3��D����?��?2��?��0x34
	int dCoin_Change( BYTE Box[2] );	//2.7��2����?��?��?����??����?0x00
	int dCoin_End_Change( BYTE Data);	//2.8?-?��?����????�������??����????����??����??����?0x01
	int dCoin_Clean( BYTE Box );		//2.9��2����?��?��??����?����?0x02
	int dCoin_End_Clean( BYTE Data);	//2.10?-?��?����????�������??����?????����?����??����?0x03
	int dCoin_OpenClose( BYTE Data1[2] );//2.11��2����?��?����?��?����?a1??����?0x04
	int dCoin_Poll( BYTE Data1 );	//2.12��2������?��e?��???��0x05
	int dCoin_Add( BYTE Box );		//2.13��2����?��?��21����???������?����?0x06

	//
	int dCoin_Work( tbool enable_mao5, tbool enable_yuan1 );
	int dCoin_Work(); //use last value to work.
	int dCoin_Stop();
	int dCoin_Query();

	int dCoinHold(); // 1?��?�̡�2?����?��
	int dCoin2CircleChg(); // ��??-?��?����??? 
	int dCoin2StoreBox(); // ��?����?? 
	int dCoin2CircleChg( long coin1, long coin5 = 0 ); // ��??-?��?����??? 
	int dCoin2StoreBox( long coin1, long coin5 = 0 ); // ��?����?? 
	int dCoin2Return(); // ��?����  

	int dCoinOpenUplight(); // 3??��??��??��???��  
	int dCoinCloseUplight();
	int dCoinOpenDownlight(); // ��??��?��???�� 
	int dCoinCloseDownlight();
	int dCoinOpenAlert(); // ����?��?��  
	int dCoinCloseAlert();   
	
	//��??a?-?��?��3?X��?����??��?��?3��1|	
	int CircleChgOut( long PlanYuan1 );
	//��??a������??��3?X��?����??��?��?3��1|	
	int SpecialChgOut( long PlanYuan1 );
	int dCoinBletRoll();
	int dCoin_Supplementary(BYTE Box[2]);
	int CyrcleYuan1ChgOut( long PlanYuan1 );
	int CyrcleJiao5ChgOut( long PlanJiao5 );
	int CycleBoxChg(long Yuan1Count);
	int SupplementaryYuan1Coins(long Yuan1Count);
	int SupplementaryJiao5Coins(long Jiao5Count);
	void padTriggerReturnKey();
	void padTriggerCancelKey();
	void returnCoin();

	bool IsVaultFull();              //��2����??��?��??��    true��o������??����? false ��o?y3��
	int  RecoverErr();
};



//
extern de_coin_t  *gp_coin;


#endif



