
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
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query ; 3=���ٲ�ѯ���ڽ���Ͷ��ʱ	
	CCoin m_coinmodule;
	BYTE   m_iIsRepCoinOk[2];      // 1:ok   0:fail    index 0 : 1Yuan   1:5Jiao
	 
public:
	de_coin_t();
	virtual ~de_coin_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void CoinAdvice();
	int CoinInit();

	//�豸����ӿ� 
	bool dCommOpen();
	void dCommClose();
	int dCoin_State();		//Ӳ��ģ��״̬��ѯ0x31 
	int dCoin_Test(BYTE Data[2]);		//2.4Ӳ��ģ���������0x32
	int dCoin_Reset();		//2.5Ӳ��ģ�����λ0x33
	int dCoin_GetVersion();	//2.6Ӳ��ģ�����汾��ѯ0x34
	int dCoin_Change( BYTE Box[2] );	//2.7Ӳ��ģ����������0x00
	int dCoin_End_Change( BYTE Data);	//2.8ѭ�������䡢ר�������������������0x01
	int dCoin_Clean( BYTE Box ,int iCleanCount = 0 );		//2.9Ӳ��ģ���������0x02   //iCleanCount��Ҫ��ҵ����� 0��ʾ������е�Ӳ�� 1-255��ʾ���վ�����������
	int dCoin_End_Clean( BYTE Data);	//2.10ѭ�������䡢ר����������ҽ�������0x03
	int dCoin_OpenClose( BYTE Data1[2] );//2.11Ӳ��ģ��������������0x04
	int dCoin_Poll( BYTE Data1 );	//2.12Ӳ��ʶ������ѯ0x05
	int dCoin_Add( BYTE Box );		//2.13Ӳ��ģ�鲹����ӱ�����0x06

	//
	int dCoin_Work( tbool enable_mao5, tbool enable_yuan1 );
	int dCoin_Work(); //use last value to work.
	int dCoin_Stop( int iIsCleanReg = 1 );     //1 ���Ӳ�Ҽ����Ĵ�����0����� 
	int dCoin_Query();

	int dCoinHold(); // �ص��ײ��ҿ�
	int dCoin2CircleChg(); // ��ѭ�������� 
	int dCoin2StoreBox(); // ������ 
	int dCoin2CircleChg( long coin1, long coin5 = 0 ); // ��ѭ�������� 
	int dCoin2StoreBox( long coin1, long coin5 = 0 ); // ������ 
	int dCoin2Return(); // �˱�  

	int dCoinOpenUplight(); // �˿���ʾ������  
	int dCoinCloseUplight();
	int dCoinOpenDownlight(); // ȡƱ������ 
	int dCoinCloseDownlight();
	int dCoinOpenAlert(); // ������  
	int dCoinCloseAlert();   
	
	//һԪѭ���ҳ�X�������Ƿ�ɹ�	
	int CircleChgOut( long PlanYuan1 );
	//һԪר���ҳ�X�������Ƿ�ɹ�	
	int SpecialChgOut( long PlanYuan1 );
	int dCoinBletRoll();
	int dCoinBletRoll(int CoinCount);
	int dCoin_Supplementary(BYTE Box[2]);
	int CyrcleYuan1ChgOut( long PlanYuan1 );
	int CyrcleJiao5ChgOut( long PlanJiao5 );
	int CycleBoxChg(long Yuan1Count);
	int SupplementaryYuan1Coins(long Yuan1Count);
	int SupplementaryJiao5Coins(long Jiao5Count);
	void padTriggerReturnKey();
	void padTriggerCancelKey();

	void padTriggerReturnKey(int CoinCount);
	void padTriggerCancelKey(int CoinCount);
	void returnCoin(int CoinCount);
	
	void returnCoin();

	bool IsVaultFull();              //Ӳ�����Ƿ���    true����ʾ���� false ������
	int  RecoverErr();

	int CleanCoinStock();
	int RepCoinStock();


};



//
extern de_coin_t  *gp_coin;


#endif



