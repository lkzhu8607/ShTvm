
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
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query ; 3=?¨¬?¨´2¨¦?¡¥¨®?¨®¨²?¨®¨º¨¹¨ª?¡À¨°¨º¡À	
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

	//¨¦¨¨¡À???¨ªa?¨®?¨² 
	bool dCommOpen();
	void dCommClose();
	int dCoin_State();		//¨®2¡À¨°?¡ê?¨¦¡Á¡ä¨¬?2¨¦?¡¥0x31 
	int dCoin_Test(BYTE Data[2]);		//2.4¨®2¡À¨°?¡ê?¨¦2a¨º??¨¹¨¢?0x32
	int dCoin_Reset();		//2.5¨®2¡À¨°?¡ê?¨¦3¨¬D¨°?¡ä??0x33
	int dCoin_GetVersion();	//2.6¨®2¡À¨°?¡ê?¨¦3¨¬D¨°¡ã?¡À?2¨¦?¡¥0x34
	int dCoin_Change( BYTE Box[2] );	//2.7¨®2¡À¨°?¡ê?¨¦?¨°¨¢??¨¹¨¢?0x00
	int dCoin_End_Change( BYTE Data);	//2.8?-?¡¤?¨°¨¢????¡é¡Á¡§¨®??¨°¨¢????¨°¨¢??¨¢¨º??¨¹¨¢?0x01
	int dCoin_Clean( BYTE Box );		//2.9¨®2¡À¨°?¡ê?¨¦??¡À¨°?¨¹¨¢?0x02
	int dCoin_End_Clean( BYTE Data);	//2.10?-?¡¤?¨°¨¢????¡é¡Á¡§¨®??¨°¨¢?????¡À¨°?¨¢¨º??¨¹¨¢?0x03
	int dCoin_OpenClose( BYTE Data1[2] );//2.11¨®2¡À¨°?¡ê?¨¦¦Ì?¡ä?¨¬¨²?a1??¨¹¨¢?0x04
	int dCoin_Poll( BYTE Data1 );	//2.12¨®2¡À¨°¨º?¡Àe?¡Â???¡¥0x05
	int dCoin_Add( BYTE Box );		//2.13¨®2¡À¨°?¡ê?¨¦21¡À¨°???¨®¡À¨°?¨¹¨¢?0x06

	//
	int dCoin_Work( tbool enable_mao5, tbool enable_yuan1 );
	int dCoin_Work(); //use last value to work.
	int dCoin_Stop();
	int dCoin_Query();

	int dCoinHold(); // 1?¦Ì?¦Ì¡Á2?¡À¨°?¨²
	int dCoin2CircleChg(); // ¦Ì??-?¡¤?¨°¨¢??? 
	int dCoin2StoreBox(); // ¦Ì?¡À¨°?? 
	int dCoin2CircleChg( long coin1, long coin5 = 0 ); // ¦Ì??-?¡¤?¨°¨¢??? 
	int dCoin2StoreBox( long coin1, long coin5 = 0 ); // ¦Ì?¡À¨°?? 
	int dCoin2Return(); // ¨ª?¡À¨°  

	int dCoinOpenUplight(); // 3??¨ª??¨º??¡Â???¡Â  
	int dCoinCloseUplight();
	int dCoinOpenDownlight(); // ¨¨??¡À?¨²???¡Â 
	int dCoinCloseDownlight();
	int dCoinOpenAlert(); // ¡À¡§?¡¥?¡Â  
	int dCoinCloseAlert();   
	
	//¨°??a?-?¡¤?¨°3?X¡ê?¡¤¦Ì??¨º?¡¤?3¨¦1|	
	int CircleChgOut( long PlanYuan1 );
	//¨°??a¡Á¡§¨®??¨°3?X¡ê?¡¤¦Ì??¨º?¡¤?3¨¦1|	
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

	bool IsVaultFull();              //¨®2¡À¨°??¨º?¡¤??¨²    true¡êo¡À¨ª¨º??¨²¡ê? false ¡êo?y3¡ê
	int  RecoverErr();
};



//
extern de_coin_t  *gp_coin;


#endif



