
//
#include "2.h"
#include "de_base_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"



//
de_base_t::de_base_t()
{
	m_de_ShouldReset = 0; // 照顾没有reset的模块。 

	m_de_state = 0;
}


//
de_base_t::~de_base_t() //bu_hot_thrd_t中有tr析构
{
}


//
void de_base_t::OnRunTask( std::string t ) 
{
		goto L_TASKEND;
	
L_TASKEND:
 
	return;
}


// 
int de_base_t::tr_on_user_run()
{
	return 0;
}



// 
void de_base_t:: SetShouldReset()
{
	m_de_ShouldReset = 1;
}



