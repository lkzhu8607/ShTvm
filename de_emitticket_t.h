
//发卡模块 

#ifndef K1_de_emitticket_t_H
#define K1_de_emitticket_t_H

#include "2.h"
#include "d_comv_t.h"
#include "bu_hot_thrd_t.h"
#include "de_base_t.h"
#include "de_log_t.h"
#include "TicketCommand.h"



typedef unsigned int UNIT;
typedef unsigned char BYTE;


//  
class de_emitticket_t : public de_base_t
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	CTicket cticket;

public:
	de_emitticket_t();
	virtual ~de_emitticket_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void EmttAdvice();
	void EmttInit();

	//设备对外接口 
	bool CommOpen();
	void CommClose();
	int eTicket_Poll();						//2.3发卡模块轮询
	int eTicket_PowerTest(BYTE Index);			//2.4电机测试
	int eTicket_Reset();					//2.5复位
	int eTicket_GetVersion();				//2.6查询发卡模块程序版本
	int eTicket_PrepareCard();				//2.7发卡		总是票箱1发卡	功能：将卡发到读写位置
	int eTicket_SendOutIn( BYTE Data1 );		//2.8读写结果	将卡发往乘客方向（Data1=1）， 发往废票箱（Data1=2
	int eTicket_SendOut() ;
	int eTicket_SendIn() { return eTicket_SendOutIn(2);  }		 
	int eTicket_ExchangeBox();				//2.9卡箱换箱	

	int eTicket_CleanEscrow(BYTE bTicketTowhere);

	tbool MkTicketReady(); // 若无则准备一张。1=OK。0=出错。
	int RecoverErr();
};



//
extern de_emitticket_t  *gp_emitticket;


#endif

