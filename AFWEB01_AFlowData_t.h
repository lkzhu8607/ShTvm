
#ifndef K1__AFlowData_t_H
#define K1__AFlowData_t_H


#include "2.h"
#include "AFWEB01_AFlowDa00_env_t.h"
#include "d_db_t.h"


#define AFWEB_NAMESPACE_BEGIN namespace AFWEB01	{
#define AFWEB_NAMESPACE_END						}


AFWEB_NAMESPACE_BEGIN


//
class AFlowData_t  
{
public:
	AFlowDa00_env_t_rowtype  m_env0;

public:
	AFlowData_t(){}
	virtual ~AFlowData_t(){}

public: 
	
};


AFWEB_NAMESPACE_END



#endif



