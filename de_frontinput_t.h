
#ifndef K1_de_frontinput_t_H
#define K1_de_frontinput_t_H

#include "2.h"
#include "bu_hot_thrd_t.h"



//   
class de_frontinput_t : protected WKeyinput< bu_hot_thrd_t >
{
private:
	std::string  * m_pstrLast; //记录最后一次指针，未来要改成释放上一次的对象 ，可能要用字串来传递堆中指针。 
	std::string   m_strInputKey;  

public:
	de_frontinput_t();
	virtual ~de_frontinput_t();

public:
	tbool FrontInit( int iPort );
	std::string GetFrontNextKey( tbool biWithWait = 1 );
	std::string GetFrontCurrentKey();

	void input_KIN_COIN();
	void input_KIN_BILL();
	void input_KIN_EMTICKET();
	void input_KIN_READER1();
	void input_KIN_BILLCHG();

	void input_KIN_TOPSCR();
	void input_KIN_PRINTER();
	void input_KIN_UPS();
	
	void input_KIN_MOUSEBUTT1( const char *sz );
	void input_KIN_APP();
	void input_KIN_SC();

};



//
extern de_frontinput_t     *gp_frontinput;

#endif


