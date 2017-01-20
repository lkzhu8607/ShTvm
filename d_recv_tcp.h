
#ifndef K1__d_recv_tcp__H
#define K1__d_recv_tcp__H

#include "2.h" 




// if wrong then return 0 。if right then return 1.
extern int RecvTcpData( WTcpCell & aTcp, 
				 tuint16 & uMsgLen_out, 
				 tuint16 & uMsgType_out, 
				 const void *& pPkgHead_out, 
				 const void *& pPkgBody_out, 
				 const void *& pMd5_out		); 




#endif


