
#include "AFWEB01_AFlowEle_t.h"


AFWEB_NAMESPACE_BEGIN


//
AFlowEle_t::AFlowEle_t() 
{
	pf_thread__ = NULL;
	m_tSvrGoodFlag = 1;
	m_WebFormBeginGoodFlag = 0;
}


//
AFlowEle_t:: ~AFlowEle_t()
{
	tr_destruct();
}



// 
int AFlowEle_t::tr_on_user_run()
{
	SCake ckTmp;
	tbool rc;
	std::string str1;
	std::string strHttpHead;
	std::string strCmdLine1, strCmdVerb, strProtocolName, strAddr, strUPfn;
	SDte dt;

	dt.MakeNow(); 
	std::cout << m_tSvr.m_strRemoteIPAddress << " " << dt.ReadString() << std::endl;
	
	m_tSvr.recv_ln( ckTmp, "\r\n\r\n" );
	ckTmp.mk_str(strHttpHead);
	WTcpHttp::GetLine1ParaFromHead( strHttpHead, strCmdLine1, strCmdVerb, strProtocolName, strAddr, strUPfn ); // <> a&b strUPfn = "/?T1=%3C%3E+a%26b&B1=Submit"
	
	str1 = SStrvs::vsa_get( m_strUPfn = strUPfn, std::string("?"), 1, 1 );
	m_nvA.impconf( str1, "&", "=", "" );

	m_SessionId = m_nvA.get("sessionid");
	m_paff->purge();
	rc = m_paff->takeout( m_SessionId, m_afd ); 	// 获取一个 m_afd

	if( !rc ) m_SessionId = WFile::MkRUStr() + WFile::MkRUStr() + WFile::MkRUStr();

	//准备环境 
	m_afd.m_env0.m_Dt = dt;
	if( rc ) SStrf::s2b( m_afd.m_env0.m_PMemFunc, pf_thread__ );	//函数指针 恢复 
	
	flow(); 
	
	m_afd.m_env0.m_PMemFunc = SStrf::b2s( pf_thread__ );	//函数指针 保存 
	m_paff->put( m_SessionId, m_afd );	// 保存一个 m_afd

	WebFormEnd();
	m_tSvr.DisConn();

	return 0;
}


//
void AFlowEle_t::WebSendString( std::string strValue )
{
	if( strValue.empty() ) return;

	if( m_tSvrGoodFlag )
	{
		m_tSvrGoodFlag = m_tSvr.send_str( strValue );
	}

	WebFormBegin();
}


// 
void AFlowEle_t::WebFormBegin()
{
	if( m_WebFormBeginGoodFlag == 0 )
	{
		m_WebFormBeginGoodFlag = 1;

		std::string str1;

		str1 = "HTTP/1.0 200 OK\r\n\r\n";
		str1 += "<html><head>\r\n";
		str1 += "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\">\r\n";
		str1 += "<title>"+ m_afd.m_env0.m_strTitle +"</title>\r\n";
		str1 += "</head>\r\n";
		str1 += "<body>\r\n";

		str1 += "<form method=\"GET\">\r\n";
		str1 += "<p>\r\n";

		str1 += "<input type=\"hidden\" name=\"sessionid\" size=\"60\" value=\""+ m_SessionId +"\">\r\n";
		str1 += "<p>\r\n";

		WebSendString( str1 );
	}
}


// 
void AFlowEle_t::WebFormBegin( std::string strTitle )
{
	m_afd.m_env0.m_strTitle = strTitle;
	WebFormBegin(); 
}


// 
void AFlowEle_t::WebFormEnd()
{
	std::string str1;

	str1 += "</form>\r\n";
	str1 += "</body>\r\n";
	str1 += "</html>\r\n";

	WebSendString( str1 );
}



// 
void AFlowEle_t::WebAddCr()
{
	std::string sOut = "<p>\r\n";
	WebSendString( sOut );
}


// 
void AFlowEle_t::WebAddButt( std::string strName, std::string strValue )
{
	std::string sOut = "<input type=\"submit\" value=\""+ strValue +"\" name=\""+ strName +"\">\r\n";
	WebSendString( sOut );
}


// 
void AFlowEle_t::WebAddTextBox( std::string strName, std::string strValue )
{
	std::string str1;
 
	if( strValue == "" )
	{
		str1 = "<input type=\"text\" name=\""+ strName +"\" size=\"20\">\r\n";
	}
	else
	{
		str1 = "<input type=\"text\" name=\""+ strName +"\" size=\"20\" value=\""+ strValue +"\">\r\n";
	}

	WebSendString( str1 );
}










AFWEB_NAMESPACE_END





