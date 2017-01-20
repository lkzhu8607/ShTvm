#ifndef K1_de_coinbox_t_H
#define K1_de_coinbox_t_H

#include "2.h"
#include "de_base_t.h"

//  
class de_coinbox_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	int m_already_printflag;
	int m_coinbox_ok_flag;
	 
public:
	de_coinbox_t();
	virtual ~de_coinbox_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();
	void coinbox_init();
	
};

extern de_coinbox_t *gp_coinbox;
#endif

