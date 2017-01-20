
//
#include "2.h"
#include "de_log_t.h"
#include "de_backinput_t.h"


//
de_backinput_t     *gp_backinput;


//
de_backinput_t::de_backinput_t()
{
}


//
de_backinput_t::~de_backinput_t()
{
	tr_destruct();
}


//
tbool de_backinput_t::backInit( int iPort )
 {
	int iPortOut;

	if( ! this->KeyiInit(iPort, &iPortOut) ) return 0;

	LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "listen port =" << iPortOut );

	this->SetTimeout( 0.98 );

	return 1;
}


//
void de_backinput_t::input_KIN_KEYPRESS( const char *sz )
{
	if( sz && *sz )
	{
		std::string s1;

		s1 += (char)KIN_KEYPRESS;
		s1 += sz;
		this->PostTask( s1, 0, 1 );


		LOGSTREAM( gp_log[LOGKEYPRESS], LOGPOSI << "KIN_KEYPRESS:" << KIN_KEYPRESS << "," << sz );
	}
}




