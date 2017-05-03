
#ifndef K1__de_tcpmsg_t_H
#define K1__de_tcpmsg_t_H


#include "2.h" 



//
typedef WNava * PTcpMsgTaskType_t;

typedef struct 
{
	wl::tuint8 bType;
	wl::tuint8 bVersion[4];
	wl::tuint8 bPins[10];

}EQUIPPARTMESS5041;

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

	static tbool SendMACK( WTcpCell * ptcp, tuint16 uiMsgType, tuint8 ui1Answer, wl::tint32 lConversationFlow );
	static tbool SendMACK_2001( WTcpCell &tc, tuint16 uiMsgType, wl::tint32 lConversationFlow);
	static tbool SendAns5000( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVerLocal, wl::tint32 lConversationFlow ,std::vector<long> *pvVerFromSC = NULL );
	static tbool SendAns5002( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVer, std::vector<long> vGmtTime, wl::tint32 lConversationFlow );
	static tbool SendAns5005( WTcpCell &tc, tuint16 uiMsgType, wl::tint32 lConversationFlow );

	static tbool RecvMACK( WTcpCell * ptcp );
	static tbool RecvMACK_2( WTcpCell * ptcp ); // 应答交易专用 

	static tbool Send1Evt5041( long e_old, long e, int iEventCode );
	static tbool SendAllEvt5041();

	static tbool SendEquipPartMessage5043(std::vector<EQUIPPARTMESS5041> vEquipPartMess);

	static wl::tbool SendReg6000( wl::tuint8 uiAuditType );
	
	static tbool SendTrade6002_1(); //发若干条未发过的 ， 发出了几条看config     应和db-purge串行运行 。高频度调用，自管理。 
	static tbool SendTrade6002_range( long lSeri1, long lSeri2 );

	static wl::tbool SendAns6005( WTcpCell &tc, wl::tuint16 uiMsgType, wl::tint32 lConversationFlow );

};



//
extern de_tcpmsg_t     *gp_tcpmsg;




#endif



