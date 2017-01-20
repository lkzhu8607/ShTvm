
#include "AFWEB01_AFlowFolder_t.h"


AFWEB_NAMESPACE_BEGIN


//
AFlowFolder_t::AFlowFolder_t() 
{
}


//
AFlowFolder_t:: ~AFlowFolder_t()
{
}


//
tbool AFlowFolder_t::takeout( std::string strSessionId, AFlowData_t & afd )
{
	MYAUTOLOCK( m_AFLck );
	std::map< std::string, AFlowData_t* >::iterator it;
	
	it = m_datapool.find( strSessionId );
	
	if( strSessionId == "" || it == m_datapool.end() ) // 没有 
	{
		return 0;
	}

	afd = *(it->second);
	delete it->second;
	m_datapool.erase(it);

	return 1;
}


//
tbool AFlowFolder_t::put( std::string strSessionId, const AFlowData_t & afd )
{
	if( strSessionId != "" )
	{
		MYAUTOLOCK( m_AFLck );
		AFlowData_t *p = new AFlowData_t;

		*p = afd;
		m_datapool[strSessionId] = p;
	}

	return 1;
}


//
tbool AFlowFolder_t::del( std::string strSessionId )
{
	MYAUTOLOCK( m_AFLck );
	std::map< std::string, AFlowData_t* >::iterator it;
	
	it = m_datapool.find( strSessionId );
	
	if( it == m_datapool.end() ) // 没有 
	{
		return 0;
	}

	delete it->second;
	m_datapool.erase(it);

	return 1;
}



//
tbool AFlowFolder_t::purge()
{
	MYAUTOLOCK( m_AFLck );
	std::map< std::string, AFlowData_t* >::iterator it;
	SDte dt;
	tbool rc(0);
	
	dt.MakeNow(); 
	
	for( it = m_datapool.begin(); it != m_datapool.end() ; )
	{
		if( dt.DiffSecInt( it->second->m_env0.m_Dt ) > 2345 )
		{
			delete it->second;
			
			//it = m_datapool.erase(it);
			m_datapool.erase(it);
			it = m_datapool.begin();

			rc = 1;
		}
		else
		{
			++it;
		}
	}

	return rc;
}




AFWEB_NAMESPACE_END


