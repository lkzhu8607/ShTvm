
#ifndef K1_de_base_t_H
#define K1_de_base_t_H

#include "2.h"
#include "d_comv_t.h"
#include "bu_hot_thrd_t.h"



//
//typedef std::string PEmitTicketTaskType_t;


//  
class de_base_t : public WIdleThrd< std::string >  , public bu_hot_thrd_t
{
protected:
	volatile int	  m_de_ShouldReset;	//默认=1，	1=需要reset	 0=不用reset

public:
	//d_comv_t	m_comv; 没用上.
	WCrsc		 m_DevLck;
	volatile int	  m_de_state;	//慢同步状态： 外部设定值，里面进入指定状态循环。单向操作，内部不改状态。 	 
	 
public:
	de_base_t();
	virtual ~de_base_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	void SetShouldReset();

};



#endif


