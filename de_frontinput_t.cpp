
//
#include "2.h"
#include "de_log_t.h"
#include "bu_asynwork_t.h"
#include "de_frontinput_t.h"


//
de_frontinput_t     *gp_frontinput;


//
de_frontinput_t::de_frontinput_t()
{
	m_pstrLast = NULL;
}


//
de_frontinput_t::~de_frontinput_t()
{
	tr_destruct();
}


//
tbool de_frontinput_t::FrontInit( int iPort )
 {
	int iPortOut;

	if( ! this->KeyiInit(iPort, &iPortOut) ) return 0;

	LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "listen port =" << iPortOut );

	this->SetTimeout( 1.99 );

	return 1;
}


//
std::string de_frontinput_t::GetFrontNextKey( tbool biWithWait /*= 1*/ )
{
	return m_strInputKey = this->GetKey(biWithWait);
}

//
std::string de_frontinput_t::GetFrontCurrentKey()
{
	return m_strInputKey;
}


//
void de_frontinput_t::input_KIN_COIN()
{
	std::string s1;

	s1 += (char)KIN_COIN;
	this->PostTask( s1, 0, 1 );
}

//
void de_frontinput_t::input_KIN_BILL()
{
	std::string s1;

	s1 += (char)KIN_BILL;
	this->PostTask( s1, 0, 1 );
}


//
void de_frontinput_t::input_KIN_EMTICKET()
{
	std::string s1;

	s1 += (char)KIN_EMTICKET;

	this->PostTask( s1, 0, 1 );

	//LOGSTREAM( gp_log[LOGMOUSEBUTT1], LOGPOSI << "KIN_EMTICKET:" << KIN_EMTICKET );
}

//
void de_frontinput_t::input_KIN_READER1()
{
	std::string s1;

	s1 += (char)KIN_READER1;
	this->PostTask( s1, 0, 1 );
}

//
void de_frontinput_t::input_KIN_BILLCHG()
{
	std::string s1;

	s1 += (char)KIN_BILLCHG;
	this->PostTask( s1, 0, 1 );
}

//
void de_frontinput_t::input_KIN_TOPSCR()
{
	std::string s1;

	s1 += (char)KIN_TOPSCR;
	this->PostTask( s1, 0, 1 );
}

//
void de_frontinput_t::input_KIN_PRINTER()
{
	std::string s1;

	s1 += (char)KIN_PRINTER;
	this->PostTask( s1, 0, 1 );
}


//
void de_frontinput_t::input_KIN_UPS()
{
	std::string s1;

	s1 += (char)KIN_UPS;
	this->PostTask( s1, 0, 1 );
}


//
void de_frontinput_t::input_KIN_MOUSEBUTT1( const char *sz )
{
	if( sz && *sz )
	{
		std::string s1;

		s1 += (char)KIN_MOUSEBUTT1;
		s1 += sz;

		bu_asynwork_t::MouseHotPress(s1);
		this->PostTask( s1, 0, 1 );
	


		//gp_log[LOGMOUSEBUTT1].LogPrintf( 999 + (int)s1.size() * 3, "%s|%d,%s", LOGPOSI, (int)KIN_MOUSEBUTT1, p );

		//std::stringstream stream1;
		//gp_log[LOGMOUSEBUTT1].LogPrintStr( (stream1 << LOGPOSI << KIN_MOUSEBUTT1 << "," << p , stream1).str().c_str() );
		////gp_log[LOGMOUSEBUTT1].LogPrintStr( stream1.str().c_str() );

		LOGSTREAM( gp_log[LOGMOUSEBUTT1], LOGPOSI << "KIN_MOUSEBUTT1:" << KIN_MOUSEBUTT1 << "," << sz );
	}
}



//
void de_frontinput_t::input_KIN_APP()
{
	std::string s1;

	s1 += (char)KIN_APP;
	this->PostTask( s1, 1, 1 );
}


//
void de_frontinput_t::input_KIN_SC()
{
	std::string s1;

	s1 += (char)KIN_SC;
	this->PostTask( s1, 0, 1 );
}





