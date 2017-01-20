
#include "2.h"
#include "d_comlogger_t.h"
#include "de_log_t.h"



//
d_comlogger_t::d_comlogger_t( int LogType )
{
	m_LogType = LogType;
}


//
d_comlogger_t::~d_comlogger_t()
{
	if( !m_Buf.empty() )
	{
		SCake ck;
		ck.let( SADDR(m_Buf) , (int)m_Buf.size() );
		LOGSTREAM( gp_log[m_LogType], LOGPOSI << ck.Seri() );
	}
}

//
////
//void d_comlogger_t::AddData( char c )
//{
//	m_Buf.push_back(c);
//}
//




