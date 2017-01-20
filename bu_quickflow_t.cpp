
#include "bu_quickflow_t.h"



//
bu_quickflow_t  *gp_qf;



//
bu_quickflow_t::bu_quickflow_t()
{
	m_iQf = 0;
	m_dStep = 0.2;
}


//
void bu_quickflow_t::Reset()
{
	//MYAUTOLOCK(m_QfLck);

	m_iQf = 0;
}


//
void bu_quickflow_t::GetQf( qf_counter_t & a ) 
{
	//MYAUTOLOCK(m_QfLck);

	a = m_iQf;
}


//
tbool bu_quickflow_t::IsLongQf( qf_counter_t a, double dSec )
{
	//MYAUTOLOCK(m_QfLck);

	if( (m_iQf - a) * m_dStep >= dSec ) return 1;

	return 0;
}

	
//
int bu_quickflow_t::GetUpNum()
{
	static int i=0;
	return i++;
}


// 
int bu_quickflow_t::tr_on_user_run()
{
	WThrd::tr_sleep( 0, m_dStep );
	if(1)
	{
		//MYAUTOLOCK(m_QfLck);	

		m_iQf++;
	}
	return 1;
}


