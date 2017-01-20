
#ifndef K1__AFlowFolder_t_H
#define K1__AFlowFolder_t_H


#include "2.h"
#include "AFWEB01_AFlowData_t.h"


AFWEB_NAMESPACE_BEGIN


//
class AFlowFolder_t  
{
public:
	WCrsc	  m_AFLck;
	 
	std::map< std::string, AFlowData_t* > m_datapool;

public:
	AFlowFolder_t();
	virtual ~AFlowFolder_t();

public:
	tbool takeout( std::string strSessionId, AFlowData_t & afd ); // ¶Á³ö²¢É¾³ý 
	tbool put( std::string strSessionId, const AFlowData_t & afd );
	tbool del( std::string strSessionId );
	tbool purge();
	
};


AFWEB_NAMESPACE_END




#endif



