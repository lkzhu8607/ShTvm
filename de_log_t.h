
#ifndef K1_de_log_t_H
#define K1_de_log_t_H

#include "2.h"


		//LOGSTREAM( gp_log[LOGMOUSEBUTT1], LOGPOSI << "KIN_MOUSEBUTT1:" << KIN_MOUSEBUTT1 << "," << sz );

//
typedef std::string * PLogTaskType_t;


//  
class de_log_t : public WBoxLog_t, public WIdleThrd< PLogTaskType_t >  
{
private:
	std::string  m_strFn;
	std::string  m_strFnBak;
	int			m_iThshold;

public:
	de_log_t();
	virtual ~de_log_t();

public:
	tbool LogInit( std::string strFn, int iThshold = 987123 );
	virtual void OnLogWrite( const char *sz );
	virtual void OnRunTask( PLogTaskType_t t );

};


//=============

//  
class de_log4_t : public WIdleThrd< PLogTaskType_t > , public LOG4_t< 7 > 
{
private:

public:
	de_log4_t(){}
	virtual ~de_log4_t(){}

public:
	void LogPrintStr( const std::string & ss );
	virtual void OnRunTask( PLogTaskType_t t );
};



//
extern de_log4_t   *gp_log;



#endif



