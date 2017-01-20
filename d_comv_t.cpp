
#include "2.h"
#include "d_comv_t.h"
#include "de_log_t.h"



//
d_comv_t::d_comv_t()
{
	m_CellType = REMOTE;
	m_strPrType = "";
	m_iLogType = 0;
}



//
tbool d_comv_t::Conn()
{
	MYAUTOLOCK( m_ComvLck );
	WNava nv1;
	WNava nv2;
	SCake ck;

	nv1.let( "cmd", "conn" );
	nv1.let( "id", m_strComId );
	nv1.let( "type", m_strPrType );

	m_tcAg.send_str( nv1.serialize() );
	m_tcAg.send_str( "\n" );
	
	m_tcAg.recv_ln( ck );

	if( ck.len() == 0 )
	{
		return 0;
	}
	
	nv2.unserialize( ck.mk_str() );

	if( nv2.get("rc") != "1" )
	{
		return 0;
	}

	return 1;
}



//
tbool d_comv_t::Close()
{
	MYAUTOLOCK( m_ComvLck );
	WNava nv1;
	WNava nv2;
	SCake ck;

	nv1.let( "cmd", "close" );
	nv1.let( "id", m_strComId );
	nv1.let( "type", m_strPrType );

	m_tcAg.send_str( nv1.serialize() );
	m_tcAg.send_str( "\n" );
	
	m_tcAg.recv_ln( ck );

	if( ck.len() == 0 )
	{
		return 0;
	}
	
	nv2.unserialize( ck.mk_str() );

	if( nv2.get("rc") != "1" )
	{
		return 0;
	}

	return 1;
}



//
tbool d_comv_t::SendFrame( SCake & ck_in, std::string *pstrTagPara /*= NULL*/ )
{
	MYAUTOLOCK( m_ComvLck );
	WNava nv1;
	WNava nv2;
	SCake ck;

	nv1.let( "cmd", "send" );
	nv1.let( "id", m_strComId );
	nv1.let( "type", m_strPrType );
	nv1.let( "data", ck_in.Seri_S() );
	if(pstrTagPara)
		nv1.let( "tag", *pstrTagPara );

	m_tcAg.send_str( nv1.serialize() );
	m_tcAg.send_str( "\n" );
	
	m_tcAg.recv_ln( ck );

	if( ck.len() == 0 )
	{
		return 0;
	}
	
	nv2.unserialize( ck.mk_str() );

	if( nv2.get("rc") != "1" )
	{
		return 0;
	}

	return 1;
}



//
tbool d_comv_t::RecvFrame( SCake & ck_out, std::string *pstrTagPara /*= NULL*/ )
{
	MYAUTOLOCK( m_ComvLck );
	WNava nv1;
	WNava nv2;
	SCake ck;

	nv1.let( "cmd", "recv" );
	nv1.let( "id", m_strComId );
	nv1.let( "type", m_strPrType );
	if(pstrTagPara)
		nv1.let( "tag", *pstrTagPara );

	m_tcAg.send_str( nv1.serialize() );
	m_tcAg.send_str( "\n" );
	
	m_tcAg.recv_ln( ck );

	if( ck.len() == 0 )
	{
		return 0;
	}
	
	nv2.unserialize( ck.mk_str() );

	if( nv2.get("rc") != "1" )
	{
		return 0;
	}

	ck_out.UnSeri_S( nv1.get( "data" ) );

	return 1;
}


