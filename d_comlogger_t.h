
#ifndef K1__d_comlogger_t_T_H
#define K1__d_comlogger_t_T_H


#include "2.h"
#include "de_log_t.h"


//
class d_comlogger_t 
{
public:
	int					m_LogType;
	std::vector< char >  m_Buf;

public:
	d_comlogger_t( int LogType );
	virtual ~d_comlogger_t();

public:
	void AddData( char c ); 
	
};






#endif


