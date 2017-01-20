
#include "2.h"
#include "d_recv_tcp.h"



//
static SCake v_ck;


//
template< class T > T decode2( void *p ) 
	 { T x; memcpy( &x, p, sizeof(T) ); return x; }


//
int RecvTcpData( WTcpCell & aTcp, 
				 tuint16 & uMsgLen_out, 
				 tuint16 & uMsgType_out, 
				 const void *& pPkgHead_out, 
				 const void *& pPkgBody_out, 
				 const void *& pMd5_out		)
{
	aTcp.recv_len( v_ck, 2 );
	if( v_ck.len() != 2 ) return 0;

	uMsgLen_out = decode2<tuint16>(v_ck.buf());
	SStrf::chgendian( uMsgLen_out );

	aTcp.recv_len( v_ck, uMsgLen_out );
	if( v_ck.len() != uMsgLen_out ) return 0;

	uMsgType_out = decode2<tuint16>(v_ck.buf()+2);
	SStrf::chgendian( uMsgType_out );

	pPkgHead_out = v_ck.buf();

	pPkgBody_out = v_ck.buf() + 28;

	pMd5_out = v_ck.buf() + v_ck.len() - 16;

	return 1;
}




