
#include "de_tcpmsg_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "d_db_t.h"
#include "de_medev_t.h"
#include "de_frontinput_t.h"


//
de_tcpmsg_t     *gp_tcpmsg;



//
de_tcpmsg_t::de_tcpmsg_t()
{
}



//
void de_tcpmsg_t::OnRunTask( PTcpMsgTaskType_t t ) 
{
		
	goto L_TcpMsgTASKEND;

L_TcpMsgTASKEND:
	delete t;
	return;
}

	
//
void de_tcpmsg_t::AppendMd5( SCake &ck_in_out )
{
	//MAC
	unsigned char binmd5[16];

	if( ck_in_out.len() == 0 ) return;

	md5_encode( ck_in_out.buf() , ck_in_out.len(), binmd5 );
	ck_in_out.append( (tchar*)binmd5, 16 ); 
}


// 
tbool de_tcpmsg_t::ConnSc( WTcpCellc & tcpc )
{
	if( gp_conf->m_biSysShouldExit + gp_conf->m_biSysShouldShutdown + gp_conf->m_biSysShouldReboot ) 
	{
		gp_conf->m_biScConnOk = 0;
		return 0;
	}

	tbool rc = 0;

	if( gp_conf->m_biScConnOk ==1 )
	{
		rc = tcpc.Conn( gp_conf->Get_sc_addr() );
	}
	else if( gp_conf->m_biScConnOk == 0 && ((long)time(0) % 2) == 0 )
	{
		rc = tcpc.Conn( gp_conf->Get_sc_addr() );
	}

	if( gp_conf->m_biScConnOk != rc ) 	gp_frontinput->input_KIN_SC();

	return gp_conf->m_biScConnOk = rc;
}


// 
tbool de_tcpmsg_t::SendMACK( WTcpCell &tc, tuint16 uiMsgType, tuint8 ui1Answer )
{
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	//消息分类/类型码 
	ui2 = (tuint16)uiMsgType;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 发送方标识码 
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode1 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode2 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode3 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow();
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;

	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 3;	 
	ck.append( (tchar)ui1 );

	ui2 = 0;	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	ui1 = 0;
	ck.append( (tchar)ui1 );


	//send 应答

	ck.append( (tchar)ui1Answer ); 


	//MAC
	unsigned char binmd5[16];

	md5_encode( ck.buf() , ck.len(), binmd5 );
	ck.append( (tchar*)binmd5, 16 ); 

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	//gp_log[LOGSC].LogPrintf( 999 + ck2.len() * 3 , "%s|通信原始数据data=%s", LOGPOSI, ck2.Seri_S().c_str() );
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|通信原始数据data= " << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return 1;
}


// 
tbool de_tcpmsg_t::SendMACK_2001( WTcpCell &tc, tuint16 uiMsgType )
{
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	//消息分类/类型码 
	ui2 = (tuint16)uiMsgType;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 发送方标识码 
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode1 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode2 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode3 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;

	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 3;	 
	ck.append( (tchar)ui1 );

	ui2 = 0;	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	ui1 = 0;
	ck.append( (tchar)ui1 );


	//send 应答

	ck.append( (tchar)0x00 ); 
	ck.append( (tchar)0x01 ); 


	//MAC
	unsigned char binmd5[16];

	md5_encode( ck.buf() , ck.len(), binmd5 );
	ck.append( (tchar*)binmd5, 16 ); 

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	//gp_log[LOGSC].LogPrintf( 999 + ck2.len() * 3 , "%s|通信原始数据data=%s", LOGPOSI, ck2.Seri_S().c_str() );
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|通信原始数据data= " << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return 1;
}


//
tbool de_tcpmsg_t::SendAns5000( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVer )
{
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	//消息分类/类型码 
	ui2 = (tuint16)uiMsgType;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 发送方标识码 
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode1 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode2 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode3 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;

	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 3;	 
	ck.append( (tchar)ui1 );

	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	 
	ui2 = (tuint16)vType.size();	 
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	ui1 = 0;
	ck.append( (tchar)ui1 );


	//send 应答

	ck.append( (wl::tchar)0 ); 	//应答码 
	
	for( int i1 = 0; i1 < (int)vType.size(); i1++ )
	{
		ui2 = (tuint16)vType[i1];
		SStrf::chgendian(ui2) ;
		ck.append( (wl::tchar*)&ui2, 2 );

		ui4 = vVer[i1];
		SStrf::chgendian(ui4) ;
		ck.append( (tchar*)&ui4, 4 );
	}	

	//MAC
	unsigned char binmd5[16];

	md5_encode( ck.buf() , ck.len(), binmd5 );
	ck.append( (tchar*)binmd5, 16 ); 

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	//
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "通信原始数据data=" << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return 1;
}


//
tbool de_tcpmsg_t::SendAns5002( WTcpCell &tc, tuint16 uiMsgType, std::vector<tuint16> vType, std::vector<long> vVer, std::vector<long> vGmtTime )
{
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	//消息分类/类型码 
	ui2 = (tuint16)uiMsgType;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 发送方标识码 
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode1 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode2 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode3 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;

	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 3;	 
	ck.append( (tchar)ui1 );

	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	 
	ui2 = (tuint16)vType.size();	 
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	//压缩/加密算法  
	ui1 = 0;
	ck.append( (tchar)ui1 );


	//send 应答

	ck.append( (wl::tchar)0 ); 	//应答码 
	
	for( int i1 = 0; i1 < (int)vType.size(); i1++ )
	{
		ui2 = (tuint16)vType[i1];
		SStrf::chgendian(ui2) ;
		ck.append( (wl::tchar*)&ui2, 2 );

		ui4 = vVer[i1];
		SStrf::chgendian(ui4) ;
		ck.append( (tchar*)&ui4, 4 );

		ui4 = vGmtTime[i1];
		SStrf::chgendian(ui4) ;
		ck.append( (tchar*)&ui4, 4 );
	}	

	//MAC
	unsigned char binmd5[16];

	md5_encode( ck.buf() , ck.len(), binmd5 );
	ck.append( (tchar*)binmd5, 16 ); 

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	//
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "通信原始数据data=" << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return 1;
}


// 
tbool de_tcpmsg_t::SendAns5005( WTcpCell &tc, tuint16 uiMsgType )
{
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	//消息分类/类型码 
	ui2 = (tuint16)uiMsgType;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 发送方标识码 
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode1 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode2 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode3 );
	ck.append( (tchar)gp_db->m_a3014.GetRow(0).m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;

	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 3;	 
	ck.append( (tchar)ui1 );

	ui2 = 0;	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	//压缩/加密算法  
	ui1 = 0;
	ck.append( (tchar)ui1 );


	//send 应答

	for( int i1 = 0; i1 <= 9; i1++ )
	{
		//厂商代码 
		ui4 = 0;
		SStrf::chgendian(ui4) ;
		ck.append( (tchar*)&ui4, 4 );
		// 主版本号 
		ui1 = (tuint8)0;
		ck.append( (tchar)ui1 );
		// 副版本号 
		ui1 = (tuint8)0;
		ck.append( (tchar)ui1 );
	}


	//MAC
	unsigned char binmd5[16];

	md5_encode( ck.buf() , ck.len(), binmd5 );
	ck.append( (tchar*)binmd5, 16 ); 

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	//gp_log[LOGSC].LogPrintf( 999 + ck2.len() * 3 , "%s|通信原始数据data=%s", LOGPOSI, ck2.Seri_S().c_str() );
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|通信原始数据data= " << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return 1;
}


// 
wl::tbool de_tcpmsg_t::RecvMACK( wl::WTcpCell * ptcp )
{
	wl::WTcpCell & tc(*ptcp);
	wl::SCake ck;
	wl::tuint16 ui2;

	//接收 MACK，如果接失败则return 0;

	tc.recv_len( ck, 2 );

	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "接收:" << ck.GetReadable() );

	if( ck.len() != 2 )
		return 0;

	ui2 = *(wl::tuint16*)ck.buf();
	wl::SStrf::chgendian(ui2);

	if( ui2 != 16 + 1 + 16 )
		return 0;


	tc.recv_len( ck, ui2 );

	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "接收:" << ck.GetReadable() );

	if( ck.len() != ui2 )
		return 0;

	if( *wl::SStrf::splast(ck.buf(), ck.len(), 16) != 0 )
		return 0;

	return 1;
}


// 
wl::tbool de_tcpmsg_t::RecvMACK_2( wl::WTcpCell * ptcp )
{
	wl::WTcpCell & tc(*ptcp);
	wl::SCake ck;
	wl::tuint16 ui2;

	//接收 MACK，如果接失败则return 0;

	tc.recv_len( ck, 2 );

	////LOOG2(LOGSCNUM, ck.GetReadable() ) //记录通信原始数据 

	if( ck.len() != 2 )
		return 0;

	ui2 = *(wl::tuint16*)ck.buf();
	wl::SStrf::chgendian(ui2);

	if( ui2 == 16 + 1 + 8 + 16 )
	{
		tc.recv_len( ck, ui2 );

		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "接收:" << ck.GetReadable() );

		if( ck.len() != ui2 )
			return 0;

		if( *wl::SStrf::splast(ck.buf(), ck.len(), 8+16) != 0 )
			return 0;

		return 1;
	}

	if( ui2 == 33 )
	{
		tc.recv_len( ck, ui2 );

		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "接收:" << ck.GetReadable() );

		if( ck.len() != ui2 )
			return 0;

		if( *wl::SStrf::splast(ck.buf(), ck.len(), 16) != 0 )
			return 0;

		return 1;
	} 

	return 0;
}

// 
tbool de_tcpmsg_t::Send1Evt5041( long e_old, long e, int iEventCode )
{
	a5041_t::ROWTYPE r5041(gp_db->GetTheRowa5041());

	WTcpCellc  tc;
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	if( !ConnSc(tc) ) 
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "无法连接SC:" << gp_conf->Get_sc_addr() );
		return 0;
	}
	
	//消息分类/类型码 
	ui2 = (tuint16)0x5041;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );
	
	// 发送方标识码 
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志		Bit1：0-请求消息1-应答消息		Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 1;	 
	ck.append( (tchar)ui1 );

	ui2 = 1;	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	//压缩/加密算法  
	ui1 = 0;
	ck.append( (tchar)ui1 );

	//send 
	// 事件源节点	报告事件的节点标识码	Block	4
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

	//事件发生时间		GMT	4
	ui4 = (tuint32)SDte::GetNow().DiffSec(SDte("1970-1-1"));
	//ui4 = (tuint32)SDte(row.m_strStampDateTime).DiffSec(SDte("1970-1-1"));
	SStrf::chgendian(ui4) ;
	ck.append( (tchar*)&ui4, 4 );

	//设备状态	Block	5
		//Byte0: 节点类型
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
		//Byte1: 机器状态0
	for( int i = 0; i < 8; i++ ) SStrf::writebit( &ui1, i, r5041.m_s0.a[i] );
	ck.append( (tchar)ui1 );
		//Byte2: 机器状态1
	for( int i = 0; i < 8; i++ ) SStrf::writebit( &ui1, i, r5041.m_s1.a[i] );
	ck.append( (tchar)ui1 );
		//Byte3: 事件代码高位字节/动作
	ui1 = ((tuint16)iEventCode) >> 8;
	ui1 &= 0x7F;
	if( e_old != e && e ) ui1 |= 0x80;
	ck.append( (tchar)ui1 );
		//Byte4: 事件代码低位字节
	ui1 = (tuint8)iEventCode & 0xFF;
	ck.append( (tchar)ui1 );

	//与事件相关的节点	仅用于事件7和事件14	Block	4
	ui4 = 0;
	ck.append( (tchar*)&ui4, 4 );

	//MAC
	AppendMd5(ck);

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "通信原始数据data:" << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return RecvMACK(&tc);
}



// 
tbool de_tcpmsg_t::SendAllEvt5041()
{
	a5041_t::ROWTYPE r5041(gp_db->GetTheRowa5041());

	WTcpCellc  tc;
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	if( !ConnSc(tc) ) 
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "无法连接SC:" << gp_conf->Get_sc_addr() );
		return 0;
	}
	
	//消息分类/类型码 
	ui2 = (tuint16)0x5041;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );
	
	// 发送方标识码 
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志		Bit1：0-请求消息1-应答消息		Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 1;	 
	ck.append( (tchar)ui1 );

	tuint16 recordNum = 0;    //	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	for( int j = 0; j < gp_db->Get5041EvtCapacity() ; j++ )
	{
		if( !r5041.m_e_flag.a[j] ) continue;
		recordNum++;
	}
	SStrf::chgendian(recordNum) ;
	ck.append( (tchar*)&recordNum, 2 );
	
	//压缩/加密算法  
	ui1 = 0;
	ck.append( (tchar)ui1 );

	//send 

	for( int j = 0; j < gp_db->Get5041EvtCapacity() ; j++ )
	{
		if( !r5041.m_e_flag.a[j] ) continue;

		r5041.m_e_flag.a[j] = 0;

		// 事件源节点	报告事件的节点标识码	Block	4
		ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
		ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
		ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
		ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

		//事件发生时间		GMT	4
		ui4 = (tuint32)SDte::GetNow().DiffSec(SDte("1970-1-1"));
		//ui4 = (tuint32)SDte(row.m_strStampDateTime).DiffSec(SDte("1970-1-1"));
		SStrf::chgendian(ui4) ;
		ck.append( (tchar*)&ui4, 4 );

		//设备状态	Block	5
			//Byte0: 节点类型
		ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
			//Byte1: 机器状态0
		for( int i = 0; i < 8; i++ ) SStrf::writebit( &ui1, i, r5041.m_s0.a[i] );
		ck.append( (tchar)ui1 );
			//Byte2: 机器状态1
		for( int i = 0; i < 8; i++ ) SStrf::writebit( &ui1, i, r5041.m_s1.a[i] );
		ck.append( (tchar)ui1 );
			//Byte3: 事件代码高位字节/动作
		ui1 = ((tuint16)j) >> 8;
		ui1 &= 0x7F;
		if( r5041.m_e.a[j] ) ui1 |= 0x80;
		ck.append( (tchar)ui1 );
			//Byte4: 事件代码低位字节
		ui1 = (tuint8)j & 0xFF;
		ck.append( (tchar)ui1 );

		//与事件相关的节点	仅用于事件7和事件14	Block	4
		ui4 = 0;
		ck.append( (tchar*)&ui4, 4 );
	}

	//MAC
	AppendMd5(ck);

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "通信原始数据data:" << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return RecvMACK(&tc);
}


// 
tbool de_tcpmsg_t::SendReg6000( wl::tuint8 uiAuditType )
{
	a6000_t::ROWTYPE r6000(gp_db->GetTheRowa6000());

	WTcpCellc  tc;
	SCake ck;
	SCake ck2;
	tuint8  ui1;
	tuint16 ui2;
	tuint32 ui4;

	if( !ConnSc(tc) ) 
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "无法连接SC:" << gp_conf->Get_sc_addr() );
		return 0;
	}
	
	//消息分类/类型码 
	ui2 = (tuint16)0x5041;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );
	
	// 发送方标识码 
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

	// 会话流水号  
	ui4 = gp_db->GetSendConversationFlow() ;
	SStrf::chgendian(ui4);
	ck.append( (tchar*)&ui4, 4 );

	//包序列号	0 ~ 65535，按包序递增	Word	2 
	if( gp_conf->Get_pkg_seri_style() == 0 )
		ui2 = 0;
	else
		ui2 = 0;
	SStrf::chgendian(ui2);
	ck.append( (tchar*)&ui2, 2 );

	// 标志		Bit1：0-请求消息1-应答消息		Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包 
	ui1 = 1;	 
	ck.append( (tchar)ui1 );

	ui2 = 0;	//	记录数0~65535，对于没有长度可变部分的包,填0，否则，为长度可变部分中包含的记录数	
	SStrf::chgendian(ui2) ;
	ck.append( (tchar*)&ui2, 2 );

	//压缩/加密算法  
	ui1 = 0;
	ck.append( (tchar)ui1 );

	//send 

	//节点标识码	TVM、THM的节点标识码	Block	4
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode1 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode2 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode4 );

	//审计类型码	Byte	1
	ui1 = (wl::tuint8)uiAuditType;
	ck.append( (wl::tchar)ui1 );

	//节点类型	类型为触摸屏式TVM	Byte	1
	ck.append( (tchar)gp_db->GetTheRowa3014().m_EqpNodecode3 );

	// [保留]		Byte	1
	ui1 = (wl::tuint8)r6000.m_RES_01;
	ck.append( (wl::tchar)ui1 );

	//操作员编号		Long	4
	ui4 = (wl::tuint32)r6000.m_OperatorNum;
	wl::SStrf::chgendian(ui4) ;
	ck.append( (wl::tchar*)&ui4, 4 );

	// 钞箱编号		Long	4 
	ui4 = (wl::tuint32)r6000.m_BoxNum;
	wl::SStrf::chgendian(ui4) ;
	ck.append( (wl::tchar*)&ui4, 4 );

	// 采集时间		GMT	4
	ui4 = (wl::tuint32)wl::SDte("").DiffSec(wl::SDte("1970-1-1"));
	wl::SStrf::chgendian(ui4) ;
	ck.append( (wl::tchar*)&ui4, 4 );

	// 寄存器数据 long*64=256
	if(1)
	{
		MYAUTOLOCK( gp_db->m_a6000.m_ut_tbl_lck );

		for( int i = 0; i < 64; i++ )  
		{
			//reg 00 - 63
			ui4 = r6000.m_Reg.a[i];
			SStrf::chgendian(ui4) ;
			ck.append( (tchar*)&ui4, 4 );
		}
	}

	//MAC
	AppendMd5(ck);

	//长度 
	ui2 = (tuint16)ck.len();
	SStrf::chgendian(ui2);

	//组织全部数据为一个包  
	ck2.append( (tchar*)&ui2, 2 );
	ck2.append( ck );

	///
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "通信原始数据data:" << ck2.Seri_S() );

	if( !tc.send_bin( ck2 ) )
		return 0;

	return RecvMACK(&tc);
}




#include "de_tcpmsg_6002_1.xpp"
#include "de_tcpmsg_6002_range.xpp"


