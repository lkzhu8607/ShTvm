
//
#include "2.h"
#include "de_log_t.h"


//
de_log4_t  *gp_log;


//
de_log_t::de_log_t()
{
	m_iThshold = 1000;
}


//
de_log_t::~de_log_t()
{
}


//
tbool de_log_t::LogInit( std::string strFn, int iThshold /*= 987123*/ )
{
	m_strFn = strFn;
	m_strFnBak = m_strFn + ".bak";
	m_iThshold = iThshold;
	return 1;
}


//
void de_log_t::OnLogWrite( const char *sz )
{
	std::string *p;
	
	if( !sz ) return;
	if( !*sz ) return;

	p = new std::string(sz);

	this->PostTask( p );

	//if( this != gp_log )
	//{
	//	gp_log[LOGNULL].LogPrintStr(sz);
	//	printf( "%s\n", sz );
	//}
}


//
void de_log_t::OnRunTask( PLogTaskType_t t ) 
{
	SFile fl;
	std::string &s2(*t);
	
	fl.bind( m_strFn );

	if( fl.len() > 345123 )
	{
		fl.cp( m_strFn, m_strFnBak );
		fl.bind( m_strFn );
		fl.erase();
	}

	s2 += "\r\n";
	fl.write_str(s2, 1);

	goto L_TASKEND;

L_TASKEND:
	delete t;
	return;
}



//=====================


//
void de_log4_t::LogPrintStr( const std::string & ss )
{
	std::string *p;
	
	p = new std::string(ss);

	printf( "%s\n", ss.c_str() );

	this->PostTask( p, 0 );
}


//
void de_log4_t::OnRunTask( PLogTaskType_t t ) 
{
	this->WriteStr( *t );
	delete t;
}


