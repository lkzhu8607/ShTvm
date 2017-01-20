
#ifndef K1__bu_asynwork_t_H
#define K1__bu_asynwork_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"



//
class bu_asynwork_t : public bu_hot_thrd_t
{
private:
	WNava  m_para;
	void (bu_asynwork_t::*m_f)();	// 处理函数 

private:
	virtual int tr_on_user_run();

public:
	bu_asynwork_t();
	virtual ~bu_asynwork_t();

public:
	static 
	void MouseHotPress( std::string strPosition );
	void MouseHotPress_m();
	
	static 
	void DelayCloseDownlight( /*bu_quickflow_t::qf_counter_t*/void * pQf );
	void DelayCloseDownlight_m();

	static 
	void RepeatSendReg6000();	//	等待参数规定的时间，重复发出6000	
	void RepeatSendReg6000_m();

	static 
	void DelayReboot( int iSec );
	void DelayReboot_m();

	static 
	void DoSetThisIp();
	void DoSetThisIp_m();

	static 
	void DoTime1Server();
	void DoTime1Server_m();

	static 
	void DoTime2Server();
	void DoTime2Server_m();

	static 
	void DoAlarmnSec( int iSec);
	void DoAlarmnSec_m();

};





#endif



