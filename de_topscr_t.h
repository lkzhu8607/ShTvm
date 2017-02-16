
#ifndef K1_de_topscr_t_H
#define K1_de_topscr_t_H

#include "2.h"
#include "de_base_t.h"


//  
class de_topscr_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= loop query 
	 
public:
	de_topscr_t();
	virtual ~de_topscr_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void TopscrAdvice();
	int TopscrInit();

	//设备对外接口 
	int TopscrReset();
	bool TopscrCommOpen();
	void TopscrCommClose();
	 
	void DispStr( std::string str );
};



//
extern de_topscr_t  *gp_topscr;


#endif



