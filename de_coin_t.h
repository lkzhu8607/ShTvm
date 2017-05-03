
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
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query ; 3=快速查询用于接受投币时	
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

	//设备对外接口 
	bool dCommOpen();
	void dCommClose();
	int dCoin_State();		//硬币模块状态查询0x31 
	int dCoin_Test(BYTE Data[2]);		//2.4硬币模块测试命令0x32
	int dCoin_Reset();		//2.5硬币模块程序复位0x33
	int dCoin_GetVersion();	//2.6硬币模块程序版本查询0x34
	int dCoin_Change( BYTE Box[2] );	//2.7硬币模块找零命令0x00
	int dCoin_End_Change( BYTE Data);	//2.8循环找零箱、专用找零箱找零结束命令0x01
	int dCoin_Clean( BYTE Box ,int iCleanCount = 0 );		//2.9硬币模块清币命令0x02   //iCleanCount需要清币的数量 0表示清空所有的硬币 1-255表示按照具体的数量清币
	int dCoin_End_Clean( BYTE Data);	//2.10循环找零箱、专用找零箱清币结束命令0x03
	int dCoin_OpenClose( BYTE Data1[2] );//2.11硬币模块电磁铁开关命令0x04
	int dCoin_Poll( BYTE Data1 );	//2.12硬币识别器轮询0x05
	int dCoin_Add( BYTE Box );		//2.13硬币模块补币箱加币命令0x06

	//
	int dCoin_Work( tbool enable_mao5, tbool enable_yuan1 );
	int dCoin_Work(); //use last value to work.
	int dCoin_Stop( int iIsCleanReg = 1 );     //1 清除硬币计数寄存器，0不清除 
	int dCoin_Query();

	int dCoinHold(); // 关掉底部币口
	int dCoin2CircleChg(); // 到循环找零箱 
	int dCoin2StoreBox(); // 到币箱 
	int dCoin2CircleChg( long coin1, long coin5 = 0 ); // 到循环找零箱 
	int dCoin2StoreBox( long coin1, long coin5 = 0 ); // 到币箱 
	int dCoin2Return(); // 退币  

	int dCoinOpenUplight(); // 乘客显示器照明  
	int dCoinCloseUplight();
	int dCoinOpenDownlight(); // 取票口照明 
	int dCoinCloseDownlight();
	int dCoinOpenAlert(); // 报警器  
	int dCoinCloseAlert();   
	
	//一元循环找出X，返回是否成功	
	int CircleChgOut( long PlanYuan1 );
	//一元专用找出X，返回是否成功	
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

	bool IsVaultFull();              //硬币箱是否满    true：表示满， false ：正常
	int  RecoverErr();

	int CleanCoinStock();
	int RepCoinStock();


};



//
extern de_coin_t  *gp_coin;


#endif



