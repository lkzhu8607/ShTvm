#ifndef K1_de_bill_cashbox_t_H
#define K1_de_bill_cashbox_t_H

#include "2.h"
#include "de_base_t.h"
#include "bnr_operation.h"



//  
class de_bill_cashbox_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	int m_already_printflag;
	int m_already_alarmflag;
	int m_needclear;
	
public:
	de_bill_cashbox_t();
	virtual ~de_bill_cashbox_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();
	void bill_cashbox_init();
	
};

extern de_bill_cashbox_t *g_bill_cashbox;
#endif

