
#ifndef K1__de_tcpmsg_t_H
#define K1__de_tcpmsg_t_H


#include "2.h" 



//
typedef WNava * PTcpMsgTaskType_t;



//
class de_tcpmsg_t : public WIdleThrd< PTcpMsgTaskType_t >    
{
public:
	de_tcpmsg_t();
	~de_tcpmsg_t(){;}

public:
	virtual void OnRunTask( PTcpMsgTaskType_t t );
	void MyInit(){} 
	static void AppendMd5( SCake &ck_in_out );
	static tbool ConnSc( WTcpCellc & tcpc );

	static tbool SendMACK( WTcpCell &tc, tuint16 uiMsgType, tuint8 ui1Answer );
	static tbool SendMACK_2001( WTcpCell &tc, tuint16 uiMsgType );
	static tbool SendAns5000( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVer );
	static tbool SendAns5002( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVer, std::vector<long> vGmtTime );
	static tbool SendAns5005( WTcpCell &tc, tuint16 uiMsgType );

	static tbool RecvMACK( WTcpCell * ptcp );
	static tbool RecvMACK_2( WTcpCell * ptcp ); // 应答交易专用 

	static tbool Send1Evt5041( long e_old, long e, int iEventCode );
	static tbool SendAllEvt5041();

	static wl::tbool SendReg6000( wl::tuint8 uiAuditType );
	
	static tbool SendTrade6002_1(); //发若干条未发过的 ， 发出了几条看config     应和db-purge串行运行 。高频度调用，自管理。 
	static tbool SendTrade6002_range( long lSeri1, long lSeri2 );

};



//
extern de_tcpmsg_t     *gp_tcpmsg;




#endif



