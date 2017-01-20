
#ifndef K1__AFlowEle_t_H
#define K1__AFlowEle_t_H


#include "2.h"
#include "AFWEB01_AFlowFolder_t.h"


AFWEB_NAMESPACE_BEGIN


//
class AFlowEle_t : public WThrd
{
public:
	tbool			m_tSvrGoodFlag;
	tbool			m_WebFormBeginGoodFlag;
	WTcpCells		m_tSvr;
	AFlowFolder_t  *m_paff;
	AFlowData_t   m_afd;
	std::string  m_strUPfn;
	WNava  m_nvA;
	std::string  m_SessionId;

public:
	AFlowEle_t();
	virtual ~AFlowEle_t();

public:
	virtual int tr_on_user_run();
	void WebSendString( std::string strValue );

	void WebFormBegin(); // with WebMsgHead
	void WebFormBegin( std::string strTitle );

	void WebFormEnd();
	void WebAddCr();
	void WebAddButt( std::string strName, std::string strValue );
	void WebAddTextBox( std::string strName, std::string strValue );

#include "AFWEB01_AFlowEle_th.xpp"
};


AFWEB_NAMESPACE_END



#endif



