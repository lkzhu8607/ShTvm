
#include "bu_me_ele_t.h"
#include "de_log_t.h"
#include "de_tcpmsg_t.h"
#include "d_db_t.h"
#include "d_config_t.h"
#include "d_paratime_t.h"
#include "de_medev_t.h"
#include "FTPManager.h" 
#include "g06.h"



#define RISE_TBLLSAVEFLAG(t)	\
				do{	\
					std::string strTblName = gp_db->t.ut_GetItemStr(-1,"strTblName");\
					MYAUTOLOCK( gp_db->m_DbMgrLck );	/*DbMgrLck*/	\
					if( gp_db->m_mTbllPointer.find(strTblName) != gp_db->m_mTbllPointer.end() )\
					{\
						gp_db->m_mTbllSaveFlag[1][strTblName]="aa";\
						gp_db->m_mTbllSaveFlag[2][strTblName]="aa";\
					}\
				}while(0)



//
bu_me_ele_t::bu_me_ele_t() 
{
	m_mf[(tuint16)0x1040] = &bu_me_ele_t::do_a1040;
	m_mf[(tuint16)0x2000] = &bu_me_ele_t::do_a2000;
	m_mf[(tuint16)0x2001] = &bu_me_ele_t::do_a2001;
	m_mf[(tuint16)0x3000] = &bu_me_ele_t::do_a3000;
	m_mf[(tuint16)0x3001] = &bu_me_ele_t::do_a3001;
	m_mf[(tuint16)0x3002] = &bu_me_ele_t::do_a3002;
	m_mf[(tuint16)0x3003] = &bu_me_ele_t::do_a3003;
	m_mf[(tuint16)0x3006] = &bu_me_ele_t::do_a3006;
	m_mf[(tuint16)0x3007] = &bu_me_ele_t::do_a3007;
	m_mf[(tuint16)0x3008] = &bu_me_ele_t::do_a3008;
	m_mf[(tuint16)0x3009] = &bu_me_ele_t::do_a3009;
	m_mf[(tuint16)0x3011] = &bu_me_ele_t::do_a3011;
	m_mf[(tuint16)0x3012] = &bu_me_ele_t::do_a3012;
	m_mf[(tuint16)0x3014] = &bu_me_ele_t::do_a3014;
	m_mf[(tuint16)0x3082] = &bu_me_ele_t::do_a3082;
	m_mf[(tuint16)0x3083] = &bu_me_ele_t::do_a3083;
	m_mf[(tuint16)0x3084] = &bu_me_ele_t::do_a3084;
	m_mf[(tuint16)0x3085] = &bu_me_ele_t::do_a3085;
	m_mf[(tuint16)0x3086] = &bu_me_ele_t::do_a3086;
	m_mf[(tuint16)0x4001] = &bu_me_ele_t::do_a4001;
	m_mf[(tuint16)0x4002] = &bu_me_ele_t::do_a4002;
	m_mf[(tuint16)0x4003] = &bu_me_ele_t::do_a4003;
	m_mf[(tuint16)0x4004] = &bu_me_ele_t::do_a4004;
	m_mf[(tuint16)0x4006] = &bu_me_ele_t::do_a4006;
	m_mf[(tuint16)0x4007] = &bu_me_ele_t::do_a4007;
	m_mf[(tuint16)0x4008] = &bu_me_ele_t::do_a4008;
	m_mf[(tuint16)0x4009] = &bu_me_ele_t::do_a4009;
	m_mf[(tuint16)0x4015] = &bu_me_ele_t::do_a4015;
	m_mf[(tuint16)0x4016] = &bu_me_ele_t::do_a4016;
	m_mf[(tuint16)0x5000] = &bu_me_ele_t::do_a5000;
	m_mf[(tuint16)0x5003] = &bu_me_ele_t::do_a5003;
	m_mf[(tuint16)0x5001] = &bu_me_ele_t::do_a5001;
	m_mf[(tuint16)0x5002] = &bu_me_ele_t::do_a5002;
	m_mf[(tuint16)0x5005] = &bu_me_ele_t::do_a5005;
	m_mf[(tuint16)0x6004] = &bu_me_ele_t::do_a6004;
	m_mf[(tuint16)0x6005] = &bu_me_ele_t::do_a6005;

	m_mOff[(tuint16)0x1040] = "";
	m_mOff[(tuint16)0x2000] = "";
	m_mOff[(tuint16)0x2001] = "";
	m_mOff[(tuint16)0x3000] = "";
	m_mOff[(tuint16)0x3001] = "";
	m_mOff[(tuint16)0x3002] = "";
	m_mOff[(tuint16)0x3003] = "";
	m_mOff[(tuint16)0x3006] = "8";
	m_mOff[(tuint16)0x3007] = "8";
	m_mOff[(tuint16)0x3008] = "8";
	m_mOff[(tuint16)0x3009] = "8";
	m_mOff[(tuint16)0x3011] = "8";
	m_mOff[(tuint16)0x3014] = "";
	m_mOff[(tuint16)0x3082] = "8";
	m_mOff[(tuint16)0x3083] = "8";
	m_mOff[(tuint16)0x3084] = "8";
	m_mOff[(tuint16)0x3085] = "8";
	m_mOff[(tuint16)0x3086] = "";
	m_mOff[(tuint16)0x4001] = "4";
	m_mOff[(tuint16)0x4002] = "71";
	m_mOff[(tuint16)0x4003] = "8";
	m_mOff[(tuint16)0x4004] = "12";
	m_mOff[(tuint16)0x4006] = "8";
	m_mOff[(tuint16)0x4007] = "4";
	m_mOff[(tuint16)0x4008] = "4";
	m_mOff[(tuint16)0x4009] = "4";
	m_mOff[(tuint16)0x4015] = "4";
	m_mOff[(tuint16)0x4016] = "40";
	m_mOff[(tuint16)0x5000] = "4";
	m_mOff[(tuint16)0x5003] = "4";
}


//
bu_me_ele_t:: ~bu_me_ele_t()
{
	tr_destruct();
}



// 
int bu_me_ele_t::tr_on_user_run()
{
	//std::map< tuint16, tbool(bu_me_ele_t::*)() >::iterator it;
	//tbool(bu_me_ele_t::*p)();

	try
	{
		if( !GetWholeMsg() ) //没收到 
		{
			throw (tuint8)0x01;
		}

		if( m_mf.find( (wl::tuint16)m_uiMsgType ) == m_mf.end() )          // 没有处理函数对应。   
		{
			throw (wl::tuint8)0x02;
		}

		if( !(this->*m_mf[(wl::tuint16)m_uiMsgType])() )
		{
			throw (wl::tuint8)0x01;
		}

	}
	catch( tuint8 c )
	{
		My_SendMACK( c );
	}
	catch(...)
	{
		My_SendMACK( (tuint8)0xff );
	}

	m_tSvr.DisConn();

	return 0;
}


//
tbool bu_me_ele_t::GetWholeMsg()
{
	SCake ck;
	SCake ck2, ck3;
	SCakel ckl;
	tuint16 uiPkgLen;
	tuint8  isLast;
	tuint32  uiSenderId;
	tint32   lConversationFlow;

	for( int iRcvIdx = 0; ; iRcvIdx++ )
	{
		try
		{
			m_tSvr.recv_len( ck, 2 );
			if( ck.len() != 2 ) throw (int)0;

			uiPkgLen = *(tuint16*)ck.buf();
			SStrf::chgendian( uiPkgLen );
	
			if( uiPkgLen <= 16 + 16 ) throw (int)0;

			m_tSvr.recv_len( ck, uiPkgLen );
			if( ck.len() != uiPkgLen ) throw (int)0;

			S_dataeater_t deat(ck);

			m_uiMsgType = deat.eat_data<tuint16>();        // 消息分类/类型码 
			uiSenderId = deat.eat_data<tuint32>();       // 发送方标识码
			m_lConversationFlow = deat.eat_data<tint32>(); // 会话流水号 
			deat.eat_skip<tuint16>();                      // 包序列号	0 ~ 65535，按包序递增	Word	2
			isLast = 0x01 & deat.eat_data<tuint8>();       // 标志Bit7~2：[未定义]Bit1：0-请求消息1-应答消息Bit0：0-还有更大的包序列号的包1-这是本消息的最后一包

			////save ck?
			//if(!BLINU)
			//{
			//	static int aa=1000;
			//	WFile fl;
			//	fl.bind( "..\\fakesc\\" + SStrf::sltoa(aa++) + "_" + SStrf::sltoa(m_uiMsgType,16) + "_" + SStrf::sltoa(iRcvIdx) + ".bin" );
			//	fl.write( ck );
			//}

			ck2.let( ck.buf() + 16, ck.len() - 16 - 16 );

			if( iRcvIdx == 0 )
			{
				ckl.add( ck2 );
			}
			else // if iRcvIdx > 0 then 应去掉包体中的长度固定部分  
			{
				unsigned long iHeadSize = SStrf::satol(m_mOff[m_uiMsgType]);

				if( ck2.len() < iHeadSize ) throw (int)0;

				ck3.let( ck2.buf() + iHeadSize, ck2.len() - iHeadSize );

				ckl.add( ck3 );
			}

			//如果是最后一包
			if( isLast )
				break;
		}
		catch( int )
		{
			//gp_log[LOGSC].LogPrintf( 999 + ck.len() * 3 , "%s|数据包本身有错.dicard it. data=%s", LOGPOSI, ck.Seri_S().c_str() );
			LOGSTREAM( gp_log[LOGSC], LOGPOSI << "数据包本身有错.dicard it. data=" << ck.Seri_S() );
			m_ckWholeMsg.redim(0);
			m_uiMsgType = 0;
			return 0;
		}
	} // end for 

	ckl.collectb();
	m_ckWholeMsg = *ckl.get0();

	//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|数据包已收.MsgType=%X,data=%s", LOGPOSI, (int)m_uiMsgType, m_ckWholeMsg.Seri_S().c_str() );
	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "数据包已收.MsgType=" << SStrf::sltoa( (int)m_uiMsgType, 16 ) << "data=" << m_ckWholeMsg.Seri_S() );
	
	return 1;
}



//
tbool bu_me_ele_t::ExistsVer( unitbl_base_t & tbl , long lVer )
{
	for( int y = 0; y < tbl.ut_GetRowAmount(); y++ )
	{
		if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" ) continue;

		if( lVer == SStrf::satol( tbl.ut_GetItemStr( y, "lVer" ) ) )
		{			
			return 1;
		}
	}

	return 0;
}



wl::tbool bu_me_ele_t::My_SendMACK( wl::tuint8 ui1Answer )
{
	wl::tbool ret = de_tcpmsg_t::SendMACK( &m_tSvr, m_uiMsgType, ui1Answer ,m_lConversationFlow); 

	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "SendMACK ret ="<<ret );
	return ret;
}
//
tbool bu_me_ele_t::do_a_fake()	 
{
	//send ack
	//
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a1040()	 
{
	a1040_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 178 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len() < 178", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len() < 178" );
		return 0;
	}
	
	if( 1 )
	{
		MYAUTOLOCK( gp_db->m_a1040.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a1040, row.m_lVer ) ) 
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<wl::tuint32>() ).ReadString();

		deat.eat_bin( row.m_ScNode );
		
		deat.eat_bin( row.m_PositionNum );

		row.m_strStaNameEnShort = deat.eat_str(6); 

		row.m_strStaNameEn = deat.eat_str(32);
		
		row.m_lStaNameCh = deat.eat_data<long>();

		deat.eat_bin( row.m_CcNode );


		//维护寄存器数据的报告间隔时间变更表，一周7天，每天96刻钟，值是间隔时间秒 Block	56
		for( int iweek = 0; iweek < 7; iweek++ )
		{
			for( int k96 = 0; k96 < 96; k96++ ) //先填写0 
			{
				row.m_TimeTableWeiHu.a[iweek][k96] = 0 * 60;
			}

			for( int igroup4 = 0; igroup4 < 4; igroup4++ )
			{
				tuint8	Byte0 = deat.eat_data<tuint8>();
				tuint8	Byte1 = deat.eat_data<tuint8>();
				int iflag = 0;

				for( int k96 = 0; k96 < 96; k96++ )
				{
					if( Byte0 != k96 && k96 != 0 && iflag != 0 )
					{
						row.m_TimeTableWeiHu.a[iweek][k96] = row.m_TimeTableWeiHu.a[iweek][k96-1];
					}

					if( Byte0 == k96 )
					{
						row.m_TimeTableWeiHu.a[iweek][k96] = Byte1 * 60;
						iflag = 1;
					}
				}
			}

			std::map< long, long > aaa;
			aaa[345] = 345;
			for( int k96 = 0; k96 < 96; k96++ ) // 再把所有是0值的填写为最大的值 
			{
				aaa[ row.m_TimeTableWeiHu.a[iweek][k96] ] = row.m_TimeTableWeiHu.a[iweek][k96] ;
			}
			for( int k96 = 0; k96 < 96; k96++ ) //   
			{
				if( row.m_TimeTableWeiHu.a[iweek][k96] == 0 )
					 row.m_TimeTableWeiHu.a[iweek][k96] = aaa.rbegin()->second;
			}
		}

		//审计寄存器数据的报告间隔时间变更表	Block	56 
		for( int iweek = 0; iweek < 7; iweek++ )
		{
			for( int k96 = 0; k96 < 96; k96++ ) //先填写0 
			{
				row.m_TimeTableShenJi.a[iweek][k96] = 0 * 60;
			}

			for( int igroup4 = 0; igroup4 < 4; igroup4++ )
			{
				tuint8	Byte0 = deat.eat_data<tuint8>();
				tuint8	Byte1 = deat.eat_data<tuint8>();
				int iflag = 0;

				for( int k96 = 0; k96 < 96; k96++ )
				{
					if( Byte0 != k96 && k96 != 0 && iflag != 0 )
					{
						row.m_TimeTableShenJi.a[iweek][k96] = row.m_TimeTableShenJi.a[iweek][k96-1];
					}

					if( Byte0 == k96 )
					{
						row.m_TimeTableShenJi.a[iweek][k96] = Byte1 * 60;
						iflag = 1;
					}
				}
			}

			std::map< long, long > aaa;
			aaa[345] = 345;
			for( int k96 = 0; k96 < 96; k96++ ) // 再把所有是0值的填写为最大的值 
			{
				aaa[ row.m_TimeTableShenJi.a[iweek][k96] ] = row.m_TimeTableShenJi.a[iweek][k96] ;
			}
			for( int k96 = 0; k96 < 96; k96++ ) //   
			{
				if( row.m_TimeTableShenJi.a[iweek][k96] == 0 )
					 row.m_TimeTableShenJi.a[iweek][k96] = aaa.rbegin()->second;
			}
		}

		deat.eat_bin( row.m_RES01 );
		deat.eat_bin( row.m_RES02 );

		deat.eat_bin( row.m_StaWorkTime );
		
		deat.eat_bin( row.m_RES03 );

		gp_db->m_a1040.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a1040);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a2000()	 
{
	a2000_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 38 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 38", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len < 38" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a2000.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a2000, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		row.m_ReSendBeforeWaitTime = deat.eat_data<wl::tuint8>() * 5;
		deat.eat_bin(row.m_ReSendNum);
		row.m_WaitConnTime = deat.eat_data<wl::tuint8>() * 5;
		deat.eat_bin(row.m_NoResponseNum);
		row.m_ParaVerCheckOrSyncTime = deat.eat_str(4);
		row.m_YunYingEndTime = deat.eat_str(4);
		row.m_ParaWaitTime = deat.eat_data<wl::tuint8>() * 5;
		deat.eat_bin(row.m_ResponseTimeoutTime);
		deat.eat_bin(row.m_HostScIpAddr);
		deat.eat_bin(row.m_BackUpScIpAddr);
		row.m_Rule1ScPort = deat.eat_data<wl::tuint16>();
		row.m_Rule2ScPort = deat.eat_data<wl::tuint16>();
		row.m_Rule3ScPort = deat.eat_data<wl::tuint16>();
		row.m_Rule4ScPort = deat.eat_data<wl::tuint16>();

		//记录IP有更新，同时写txt文件中ip(为写入txt文件中)

		gp_conf->m_Sc2000HostIpAddr = wl::SStrf::sltoa(row.m_HostScIpAddr.a[0]) + "." + wl::SStrf::sltoa(row.m_HostScIpAddr.a[1]) + "." +
			                          wl::SStrf::sltoa(row.m_HostScIpAddr.a[2]) + "." + wl::SStrf::sltoa(row.m_HostScIpAddr.a[3]) + ":"+
									  wl::SStrf::sltoa(row.m_Rule1ScPort);
		gp_conf->m_Sc2000BackUpIpAddr = wl::SStrf::sltoa(row.m_BackUpScIpAddr.a[0]) + "." + wl::SStrf::sltoa(row.m_BackUpScIpAddr.a[1]) + "." +
			                            wl::SStrf::sltoa(row.m_BackUpScIpAddr.a[2]) + "." + wl::SStrf::sltoa(row.m_BackUpScIpAddr.a[3]) + ":"+
									    wl::SStrf::sltoa(row.m_Rule1ScPort);

		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "m_Sc2000HostIpAddr="<< gp_conf->m_Sc2000HostIpAddr 
			                              << " m_Sc2000BackUpIpAddr="<<gp_conf->m_Sc2000BackUpIpAddr);
		
		gp_db->m_a2000.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a2000);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a2001()	 
{
	a2001_t::ROWTYPE row;

	if( m_ckWholeMsg.len() != 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len != 4" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a2001.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);
		
		deat.eat_skip( 4 );
	}

	//RISE_TBLLSAVEFLAG(m_a2001);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	de_tcpmsg_t::SendMACK_2001( m_tSvr, m_uiMsgType,m_lConversationFlow ); 

	return 1;
}



//
tbool bu_me_ele_t::do_a3000()	 
{
	a3000_t::ROWTYPE row;
	tuint8 rc = 0x03;

	if( m_ckWholeMsg.len() != 13 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 13", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len != 13" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3000.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);
		
		deat.eat_bin( row.m_BeginNode );
		deat.eat_bin( row.m_RunNode );

		row.m_uiCmdCode = deat.eat_data<tuint8>();

		row.m_lOperatorNum = deat.eat_data<long>();

		//根据命令号做事 
		if( row.m_uiCmdCode == 0x60 )	//	60h	COC、SOC	SLE	上传寄存器数据–票箱/维护,		5040
		{
		}
		
		if( row.m_uiCmdCode == 0x61 )	//	61h	COC、SOC	SLE	上传寄存器数据–审计		6000
		{
			gp_tcpmsg->SendReg6000( 0x01 );
			rc = 0;
		}

		if( row.m_uiCmdCode == 0x62)	//	62h
		{
			gp_conf->m_biSysShouldShutdown= 1;
			gp_medev->m_IsSCNeedSysShutdownOrReboot = 1;
			rc = 0;
		}

		if( row.m_uiCmdCode == 0x63 )	//	63h	COC、SOC	SLE	关闭
		{
			a9999_t::ROWTYPE &Ra9999(gp_db->GetTheRowa9999());

			Ra9999.m_stopservice_sc_flag = 1;
			gp_db->RiseSaveFlag(gp_db->m_a9999);

			rc = 0;
		}
		
		if( row.m_uiCmdCode == 0x64 )	//	64h	COC、SOC	SLE	打开
		{
			a9999_t::ROWTYPE &Ra9999(gp_db->GetTheRowa9999());

			Ra9999.m_stopservice_sc_flag = 0;
			gp_db->RiseSaveFlag(gp_db->m_a9999);

			rc = 0;
		}

		if( row.m_uiCmdCode == 0x6E )	//	6Eh	COC、SOC	SLE	上传设备状态
		{
			gp_tcpmsg->SendAllEvt5041();
			rc = 0;
		}
		
		if( row.m_uiCmdCode == 0x80 )	//	80h	COC、SOC	SLE	设备能使用主IP与所属SC通信
		{
			gp_conf->m_iIsUseSCAddr2 = 0;   //
			rc = 0;
		}

		if( row.m_uiCmdCode == 0x81 )	//	81h	COC、SOC	SLE	设备能使用备份IP与所属SC通信
		{
			gp_conf->m_iIsUseSCAddr2 = 1;   //
			rc = 0;
		}

		if( row.m_uiCmdCode == 0x90 )	//	90h	COC、SOC	SLE	设备立即更新软件版本
		{
			rc = 0;
			if(-1==update_software_by_ftp())
            {
               	LOGSTREAM( gp_log[LOGSC], LOGPOSI << "update software failed ..." );
            }
            else
            {
                LOGSTREAM( gp_log[LOGSC], LOGPOSI << "update software success ..." );
				gp_conf->m_biSysShouldReboot = 1;
				gp_medev->m_IsSCNeedSysShutdownOrReboot = 1;
            }
		}

		if( row.m_uiCmdCode == 0x91 )	//	91h	COC、SOC	SLE	设备立即更新纸币设别器识别参数
		{
			rc = 0;
		}

		if( row.m_uiCmdCode == 0x92 )	//	92h	COC、SOC	SLE	设备立即更新硬币设别器识别参数
		{
			rc = 0;
		}

		//

		gp_db->m_a3000.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3000);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3001()	 
{
	a3001_t::ROWTYPE row;

	if( m_ckWholeMsg.len() != 14 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 14", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len != 14" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3001.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);
		
		deat.eat_bin( row.m_BeginNode );
		deat.eat_bin( row.m_RunNode );
		deat.eat_bin( row.m_ModeCode );
		row.m_lOperatorNum = deat.eat_data<long>();
		
		if( ( row.m_ModeCode.a[0] == 0x00 ) && 
			( row.m_ModeCode.a[1] == 0x00 ) )    //正常模式
		{
			gp_medev->m_IsEmergeModel = 0;
		}
		if( ( row.m_ModeCode.a[0] == 0x00 ) && 
			( row.m_ModeCode.a[1] == 0x01 ) )    //紧急模式
		{
			gp_medev->m_IsEmergeModel = 1;
		}
		
		gp_db->m_a3001.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3001);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}




//
tbool bu_me_ele_t::do_a3002()	 
{
	a3002_t::ROWTYPE row;

	if( m_ckWholeMsg.len() != 207 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 207", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len != 207" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3002.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3002, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		//维护寄存器数据的报告间隔时间变更表，一周7天，每天96刻钟，值是间隔时间秒 Block	56
		for( int iweek = 0; iweek < 7; iweek++ )
		{
			for( int k96 = 0; k96 < 96; k96++ ) //先填写0 
			{
				row.m_TimeTableWeiHu.a[iweek][k96] = 0 * 60;
			}

			for( int igroup4 = 0; igroup4 < 4; igroup4++ )
			{
				tuint8	Byte0 = deat.eat_data<tuint8>();
				tuint8	Byte1 = deat.eat_data<tuint8>();
				int iflag = 0;

				for( int k96 = 0; k96 < 96; k96++ )
				{
					if( Byte0 != k96 && k96 != 0 && iflag != 0 )
					{
						row.m_TimeTableWeiHu.a[iweek][k96] = row.m_TimeTableWeiHu.a[iweek][k96-1];
					}

					if( Byte0 == k96 )
					{
						row.m_TimeTableWeiHu.a[iweek][k96] = Byte1 * 60;
						iflag = 1;
					}
				}
			}
			
			std::map< long, long > aaa;
			aaa[345] = 345;
			for( int k96 = 0; k96 < 96; k96++ ) // 再把所有是0值的填写为最大的值 
			{
				aaa[ row.m_TimeTableWeiHu.a[iweek][k96] ] = row.m_TimeTableWeiHu.a[iweek][k96] ;
			}
			for( int k96 = 0; k96 < 96; k96++ ) //   
			{
				if( row.m_TimeTableWeiHu.a[iweek][k96] == 0 )
					 row.m_TimeTableWeiHu.a[iweek][k96] = aaa.rbegin()->second;
			}
		}

		//审计寄存器数据的报告间隔时间变更表	Block	56 
		for( int iweek = 0; iweek < 7; iweek++ )
		{
			for( int k96 = 0; k96 < 96; k96++ ) //先填写0 
			{
				row.m_TimeTableShenJi.a[iweek][k96] = 0 * 60;
			}

			for( int igroup4 = 0; igroup4 < 4; igroup4++ )
			{
				tuint8	Byte0 = deat.eat_data<tuint8>();
				tuint8	Byte1 = deat.eat_data<tuint8>();
				int iflag = 0;

				for( int k96 = 0; k96 < 96; k96++ )
				{
					if( Byte0 != k96 && k96 != 0 && iflag != 0 )
					{
						row.m_TimeTableShenJi.a[iweek][k96] = row.m_TimeTableShenJi.a[iweek][k96-1];
					}

					if( Byte0 == k96 )
					{
						row.m_TimeTableShenJi.a[iweek][k96] = Byte1 * 60;
						iflag = 1;
					}
				}
			}

			std::map< long, long > aaa;
			aaa[345] = 345;
			for( int k96 = 0; k96 < 96; k96++ ) // 再把所有是0值的填写为最大的值 
			{
				aaa[ row.m_TimeTableShenJi.a[iweek][k96] ] = row.m_TimeTableShenJi.a[iweek][k96] ;
			}
			for( int k96 = 0; k96 < 96; k96++ ) //   
			{
				if( row.m_TimeTableShenJi.a[iweek][k96] == 0 )
					 row.m_TimeTableShenJi.a[iweek][k96] = aaa.rbegin()->second;
			}
		}
		
		//车站运营时间Byte0：运营开始时间Byte1：运营结束时间Byte2：开始产生车站日终报告的时间单位：15min对应：本地时间00:00~23:45Byte3
		deat.eat_bin( row.m_StaWorkTime );

		row.m_lLoginTimeout = deat.eat_data<tuint8>() * 5;
		row.m_lLogoutTimeout = deat.eat_data<tuint16>() * 15;
		row.m_lOperateWaitTimeout = deat.eat_data<wl::tuint8>() * 5;
	
		row.m_iTradeStorageCtrl = deat.eat_data<wl::tuint8>() ;
		row.m_lAlertTimesec = deat.eat_data<wl::tuint8>() * 5;
		row.m_lTradeItemNumTrigger = deat.eat_data<wl::tuint8>();
		row.m_lTradeTimesecTrigger = deat.eat_data<wl::tuint8>() * 5;
		row.m_lBCU = deat.eat_data<wl::tuint16>();
		row.m_lStatusTimesecTrigger = deat.eat_data<wl::tuint8>() * 5;
		deat.eat_bin( row.m_RES04 );//保留  Byte 9

		deat.eat_bin( row.m_RES05 );
		deat.eat_bin( row.m_RES06 );
		deat.eat_bin( row.m_RES07 );
		deat.eat_bin( row.m_RES08 );
		row.m_iCoinBoxWillFullPercent = deat.eat_data<wl::tuint8>();
		row.m_iCoinBoxFullPercent = deat.eat_data<wl::tuint8>();
		row.m_lCoinBoxCapacity = deat.eat_data<long>();
		row.m_lCoinBoxLowTrigger = deat.eat_data<wl::tuint16>();
		row.m_lCoinBoxMaxCapacity = deat.eat_data<wl::tuint16>();
		deat.eat_bin( row.m_RES09 );
		deat.eat_bin( row.m_RES10 );

		row.m_iCashBoxWillFullPercent = deat.eat_data<wl::tuint8>();
		row.m_iCashBoxFullPercent = deat.eat_data<wl::tuint8>();
		row.m_iCashChgBoxWillEmptyPercent = deat.eat_data<wl::tuint8>();
		row.m_lCashChgBoxCapacity = deat.eat_data<wl::tuint8>();
		deat.eat_bin( row.m_RES11 );
		deat.eat_bin( row.m_RES12 );
		deat.eat_bin( row.m_RES13 );
		//
		row.m_iBillCycleChg1 = deat.eat_data<wl::tuint8>();
		row.m_iBillCycleChg2 = deat.eat_data<wl::tuint8>();
		row.m_iBillCycleChg3 = deat.eat_data<wl::tuint8>();
		row.m_iBillCycleChg4 = deat.eat_data<wl::tuint8>();
		deat.eat_bin( row.m_RES14 );

		deat.eat_bin( row.m_RES15 );
		deat.eat_bin( row.m_RES16 );
		wl::tuint8 c1 = deat.eat_data<wl::tuint8>();
		row.m_lTicketReadFailTimes = c1 & 0x0f;
		row.m_lTicketWriteFailTimes = c1 >> 4;
		deat.eat_bin( row.m_RES17 );
		deat.eat_bin( row.m_RES18 );
		deat.eat_bin( row.m_RES19 );
		deat.eat_bin( row.m_RES20 );
		deat.eat_bin( row.m_RES21 );
		deat.eat_bin( row.m_RES22 );

		wl::tuint8 c2 = deat.eat_data<wl::tuint8>();
		row.m_lCardReadFailTimes = c2 & 0x0f;
		row.m_lCardWriteFailTimes = c2 >> 4;
		deat.eat_bin( row.m_RES23 );


		gp_db->m_a3002.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3002);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3003()	 
{
	a3003_t::ROWTYPE row;

	if( m_ckWholeMsg.len() != 109 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 109", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "WholeMsg.len != 109" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3003.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3003, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		row.m_BuyTicketNumLimit = deat.eat_data<tuint8>();
		row.m_GetTicketTimeoutSec = deat.eat_data<tuint8>();
		row.m_PutCoinWaitTimeSec = deat.eat_data<tuint8>() * 5;
		deat.eat_bin( row.m_PermitTicketType );
		deat.eat_bin( row.m_WorkModeConf );
		deat.eat_bin( row.m_RES_01 );
		deat.eat_bin( row.m_PermitCoinType );
		deat.eat_bin( row.m_PermitBillType );
		deat.eat_bin( row.m_PermitCoinChgType );
		deat.eat_bin( row.m_CoinChgMaxNum );
		deat.eat_bin( row.m_BillChgMaxNum );
		deat.eat_bin( row.m_PermitBillChgType );
		row.m_lChgPermitMaxAmount = deat.eat_data<long>();
		deat.eat_bin( row.m_RES_02 );
		deat.eat_bin( row.m_FaultWorkMode );
		deat.eat_bin( row.m_DeviceConfPara );
		deat.eat_bin( row.m_CurrButtonRegion );
		deat.eat_bin( row.m_FutureButtonRegion );
		deat.eat_bin( row.m_ButtonEnableFlag );
		deat.eat_bin( row.m_RES_03 );


		gp_db->m_a3003.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3003);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3006()	 
{
	a3006_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 40 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % 40 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(WholeMsg.len() - 8) % 40 != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3006.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3006, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			deat.eat_bin( row.m_StaNode );

			row.m_strStaNameEn = deat.eat_str(32);

			row.m_lStaNameCh = deat.eat_data<long>();
			
			gp_db->m_a3006.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a3006);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3007()	 
{
	a3007_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 40 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % 40 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(WholeMsg.len() - 8) % 40 != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3007.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3007, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			deat.eat_bin( row.m_CcNode );

			row.m_strLineNameEn = deat.eat_str(32);

			row.m_lLineNameCh = deat.eat_data<long>();
			
			gp_db->m_a3007.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a3007);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3008()	 
{
	a3008_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 40 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % 40 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(WholeMsg.len() - 8) % 40 != 0" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3008.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3008, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		gp_db->m_a3008.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3008);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a3009()	 
{
	a3009_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 50 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % 50 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(WholeMsg.len() - 8) % 50 != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3009.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3009, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			row.m_lOperatorNum = deat.eat_data<long>();
			deat.eat_bin( row.m_PIN );
			deat.eat_bin( row.m_OpManType );
			deat.eat_bin( row.m_AccDeviceType );
			deat.eat_bin( row.m_RES_01 );
			row.m_ValidityPeriod = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

			gp_db->m_a3009.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a3009);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3011()	 
{
	a3011_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < (4+4+1) )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|len() < (4+4+1)", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|len() < (4+4+1)" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3011.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
	
		std::vector<char> vec1;
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3011, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		vec1.insert( vec1.end(), m_ckWholeMsg.buf_const() + 8, m_ckWholeMsg.buf_const() + m_ckWholeMsg.len() );
		vec1.push_back((char)0);

		for( long i = 0; i < (long)vec1.size(); i++ )
			if( vec1[i] == 0x20 ) vec1[i] = 0;

		for( long i = 0; i < (long)vec1.size(); )
		{
			std::string s3, s4;
			
			s3 = s4 = &(vec1[i]);

			if( !gp_conf->IsOsWin() && !s3.empty() )
			{
				WFile::ChtoUtf8( s3 );
			}

			SStrf::strim( s3 );
			SStrf::strim( s4 );

			row.m_lResPointer = i;
			row.m_strResBlockOri = s4;
			row.m_strResBlockSys = s3;

			//write db
			gp_db->m_a3011.Add(row);

			if( vec1[i] == 0 )
				while( i < (long)vec1.size() && vec1[i] == 0 ) i++;
			else
				while( i < (long)vec1.size() && vec1[i] != 0 ) i++;
		}
	}

	RISE_TBLLSAVEFLAG(m_a3011);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3012()	 
{
	if( m_ckWholeMsg.len() != 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|len() != 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|len() != 4" );
		return 0;
	}
 
	S_dataeater_t deat(m_ckWholeMsg);
		
	std::string strDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();
	std::string strDate = SStrvs::vsa_get( strDateTime, " ", 1, 0 );
	std::string strTime = SStrvs::vsa_get( strDateTime, " ", 1, 1 );
	std::string strCmd;

	if( gp_conf->IsOsWin() )
	{
		strCmd = "date " + strDate;
		//system( strCmd.c_str() );

		strCmd = "time " + strTime;
		//system( strCmd.c_str() );
	}
	else
	{
		strCmd = "date -s \"" + strDateTime + "\"";
		system( strCmd.c_str() );
	}

	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a3014()	 
{
	a3014_t::ROWTYPE rownew;
	a3014_t::ROWTYPE rowold;

	if( m_ckWholeMsg.len() != 16 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len != 16", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len != 16" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3014.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		deat.eat_bin( rownew.m_CcNode, 0 );
		rownew.m_CCNodecode1 = deat.eat_data<wl::tuint8>();
		rownew.m_CCNodecode2 = deat.eat_data<wl::tuint8>();
		rownew.m_CCNodecode3 = deat.eat_data<wl::tuint8>();
		rownew.m_CCNodecode4 = deat.eat_data<wl::tuint8>();

		deat.eat_bin( rownew.m_ScNode, 0 );
		rownew.m_SCNodecode1 = deat.eat_data<wl::tuint8>();
		rownew.m_SCNodecode2 = deat.eat_data<wl::tuint8>();
		rownew.m_SCNodecode3 = deat.eat_data<wl::tuint8>();
		rownew.m_SCNodecode4 = deat.eat_data<wl::tuint8>();

		deat.eat_bin( rownew.m_EqpNode, 0 );
		rownew.m_EqpNodecode1 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpNodecode2 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpNodecode3 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpNodecode4 = deat.eat_data<wl::tuint8>();

		deat.eat_bin( rownew.m_EqpAddr, 0 );
		rownew.m_EqpAddr1 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpAddr2 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpAddr3 = deat.eat_data<wl::tuint8>();
		rownew.m_EqpAddr4 = deat.eat_data<wl::tuint8>();
			
		if( gp_db->m_a3014.GetRowCount() != 1 )
		{
			gp_db->m_a3014.ut_ClearTbl();
			gp_db->m_a3014.Add(a3014_t::ROWTYPE()); 
		}

		rowold = gp_db->m_a3014.GetRow(0);

		if( rownew.m_EqpNodecode1 != rowold.m_EqpNodecode1 ||
			rownew.m_EqpNodecode2 != rowold.m_EqpNodecode2 ||
			rownew.m_EqpNodecode3 != rowold.m_EqpNodecode3 ||
			rownew.m_EqpNodecode4 != rowold.m_EqpNodecode4	)
		{
			if(1)
			{
				MYAUTOLOCK( gp_medev->m_DevLck );
				gp_medev->m_IsRecv3014 = 1;      //设置更新参数标志为1
			}
			//设备号不同，所有参数重下  
			gp_db->CleanParaProtect3014();

			if(1)
			{
				MYAUTOLOCK( gp_medev->m_DevLck );
				gp_medev->m_IsRecv3014 = 0;      //清除更新参数标志为1
			}
		}

		gp_db->m_a3014.GetRow(0) = rownew;
	}

	RISE_TBLLSAVEFLAG(m_a3014);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3082()	 
{
	a3082_t::ROWTYPE row;

	if( m_ckWholeMsg.len() <= 8 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|len() <=8", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|len() <=8" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3082.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3082, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		gp_db->m_a3082.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3082);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3083()	 
{
	a3083_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % (72+80) ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % (72+80) != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(WholeMsg.len() - 8) % (72+80) != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3083.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3083, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			deat.eat_bin( row.m_MainUiIdx );
			row.m_MainUiPicFn = deat.eat_str(24);
			row.m_MainUiPicWidth = deat.eat_data<tuint16>();
			row.m_MainUiPicHeight = deat.eat_data<tuint16>();
			row.m_LaunSeleButtX = deat.eat_data<tuint16>();
			row.m_LaunSeleButtY = deat.eat_data<tuint16>();
			row.m_LaunSeleButtWidth = deat.eat_data<tuint8>();
			row.m_LaunSeleButtHeight = deat.eat_data<tuint8>();

			row.m_DirButt1Enable = deat.eat_data<tuint8>();
			row.m_DirButt1X = deat.eat_data<tuint16>();
			row.m_DirButt1Y = deat.eat_data<tuint16>();
			row.m_DirButt1Width = deat.eat_data<tuint8>();
			row.m_DirButt1Height = deat.eat_data<tuint8>();
			row.m_DirButt1MainUiIdx = deat.eat_data<tuint8>();

			row.m_DirButt2Enable = deat.eat_data<tuint8>();
			row.m_DirButt2X = deat.eat_data<tuint16>();
			row.m_DirButt2Y = deat.eat_data<tuint16>();
			row.m_DirButt2Width = deat.eat_data<tuint8>();
			row.m_DirButt2Height = deat.eat_data<tuint8>();
			row.m_DirButt2MainUiIdx = deat.eat_data<tuint8>();

			row.m_DirButt3Enable = deat.eat_data<tuint8>();
			row.m_DirButt3X = deat.eat_data<tuint16>();
			row.m_DirButt3Y = deat.eat_data<tuint16>();
			row.m_DirButt3Width = deat.eat_data<tuint8>();
			row.m_DirButt3Height = deat.eat_data<tuint8>();
			row.m_DirButt3MainUiIdx = deat.eat_data<tuint8>();

			row.m_DirButt4Enable = deat.eat_data<tuint8>();
			row.m_DirButt4X = deat.eat_data<tuint16>();
			row.m_DirButt4Y = deat.eat_data<tuint16>();
			row.m_DirButt4Width = deat.eat_data<tuint8>();
			row.m_DirButt4Height = deat.eat_data<tuint8>();
			row.m_DirButt4MainUiIdx = deat.eat_data<tuint8>();
			
			row.m_LineButtNum = deat.eat_data<tuint8>();

			deat.eat_bin( row.m_RES_02 );

			for( int i = 0; i < 16; i++ ) 
			{
				row.m_LineCode.a[i] = SStrf::GetBcdInt( deat.eat_data<tuint8>() );
				row.m_RES_01.a[i] = deat.eat_data<long>();
			}

			gp_db->m_a3083.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a3083);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3084()	 
{
	a3084_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % (512+30) ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 8) % (512+30) != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(WholeMsg.len() - 8) % (512+30) != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3084.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3084, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString(); //这个字段是保留，需要收下来。 
		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		while( deat.HaveMoreData() )
		{
			row.m_LineCode = SStrf::GetBcdInt( deat.eat_data<tuint8>() );
			row.m_strPicFn = deat.eat_str(24);
			row.m_StaNum = deat.eat_data<tuint8>();
			deat.eat_bin( row.m_RES_01 );

			for( int i = 0; i < 64; i++ ) 
			{
				row.m_StaCode.a[i] = SStrf::GetBcdInt( deat.eat_data<tuint8>() );
				row.m_StaButtX.a[i] = deat.eat_data<tuint16>();
				row.m_StaButtY.a[i] = deat.eat_data<tuint16>();
				row.m_StaButtWidth.a[i] = deat.eat_data<tuint8>();
				row.m_StaButtHeight.a[i] = deat.eat_data<tuint8>();
				row.m_RES_02.a[i] = deat.eat_data<tuint8>();
			}

			gp_db->m_a3084.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a3084);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3085()	 
{
	a3085_t::ROWTYPE row;

	if( m_ckWholeMsg.len() <= 8 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|len() <=8", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|len() <=8" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3085.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3085, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		gp_db->m_a3085.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a3085);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a3086()	 
{
	a3086_t::ROWTYPE row;

	if( m_ckWholeMsg.len() != 124 ) 
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|len() != 124", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|len() != 124" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a3086.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a3086, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		while( deat.HaveMoreData() )
		{
			row.m_strPicPath = deat.eat_str(64);
			row.m_strPicFn = deat.eat_str(16);
			deat.eat_bin( row.m_PicChk );
			deat.eat_bin( row.m_RES_01 );

			row.m_PkgDownloaded = 0;
			
			//接下来收FTP文件 收到就m_PkgDownloaded=1 
			//、、
			UPDATE_3086 update3086;
			std::vector<std::string> vTemp;
			std::string ssep = ":";

			wl::SStrvs::vsa_imp(gp_conf->Get_sc_addr(),ssep,0,vTemp);

			update3086.sFtpIp    = vTemp.at(0);
			printf("ftpIp=%s",update3086.sFtpIp.c_str());
			update3086.sUserName = gp_conf->Get_sc_ftp_username();
			update3086.sPasswd   = gp_conf->Get_sc_ftp_passwd();
			update3086.sPicPath  = row.m_strPicPath;
			update3086.sPicFn    = row.m_strPicFn;
			if( 0 == update_3086_by_ftp( update3086,row.m_PicChk ) )
			{
				row.m_PkgDownloaded = 1;

				gp_db->m_a3086.Add(row);

			}
			
			break;
		}
	}

	RISE_TBLLSAVEFLAG(m_a3086);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a4001()	 
{
	a4001_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 4 ) % 4 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(len-4)%4 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(len-4)%4 != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4001.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4001, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		while( deat.HaveMoreData() )
		{
			tuint8 c1,c2,c3,c4;
			char ss[99];
			SDte dt;

			c1 = deat.eat_data<wl::tuint8>();
			c2 = deat.eat_data<wl::tuint8>();
			c3 = deat.eat_data<wl::tuint8>();
			c4 = deat.eat_data<wl::tuint8>();

			(*SClib::p_sprintf())( ss, "%02x%02x-%02x-%02x 00:00:00", c1, c2, c3, c4 );
			dt.Make( ss );
			row.m_strFestivalDate = dt.ReadString();

			gp_db->m_a4001.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a4001);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a4002()	 
{
	a4002_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 71 ) % 105 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(WholeMsg.len() - 71) % 105 != 0", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(WholeMsg.len() - 71) % 105 != 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4002.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4002, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		row.m_PriorityJudgeType = deat.eat_data<tuint8>();
		row.m_CPUCardParaFlag = deat.eat_data<tuint8>();
		deat.eat_bin( row.m_RES_01 );
		row.m_ConnectGapTimesec = deat.eat_data<tuint8>() * 60;
		row.m_LostTicketPenalty = deat.eat_data<tuint16>();
		row.m_OvertravelPenalty = deat.eat_data<tuint16>();
		row.m_OvertimePenalty = deat.eat_data<tuint16>();
		row.m_ExcessPenalty = deat.eat_data<tuint16>();
		row.m_SavingsCardInitVal = deat.eat_data<tuint16>();
		row.m_NextdayWorkTimehour = deat.eat_data<tuint8>();
		deat.eat_bin( row.m_InStationMaxTime );

		//##车票类型定义记录  
		while( deat.HaveMoreData() )
		{
			row.m_TicketType = deat.eat_data<tuint8>();
			row.m_strTicketTypeDiscEn = deat.eat_str(15);
			row.m_TicketTypeDiscCh = deat.eat_data<long>();
			deat.eat_bin( row.m_TicketCtrlCode ); SStrf::chgendian(row.m_TicketCtrlCode); //为了以后取位方便 可以按照文档所示位置来取位。   
			deat.eat_bin( row.m_TicketValiIndi ); SStrf::chgendian(row.m_TicketValiIndi);
			row.m_ValidityTimeUnit = deat.eat_data<tuint16>();
			row.m_SpecialChkDays = deat.eat_data<tuint16>();
			row.m_InitVal = deat.eat_data<tuint16>();
			row.m_BuyVal = deat.eat_data<tuint16>();
			row.m_CardInitVal = deat.eat_data<tuint16>();
			row.m_CardInitRewardVal = deat.eat_data<tuint16>();
			deat.eat_bin( row.m_CardRechargeChoise );
			deat.eat_bin( row.m_CardRechargeRewardChoise );

			row.m_B0_MarginTimesec = deat.eat_data<tuint8>() * 5;
			row.m_B0_UnRushhourIdx = deat.eat_data<tuint8>();
			row.m_B0_DiscountRateIdx = deat.eat_data<tuint8>();
			row.m_B0_FullFareRateIdx = deat.eat_data<tuint8>();
			row.m_B1_MarginTimesec = deat.eat_data<tuint8>() * 5;
			row.m_B1_UnRushhourIdx = deat.eat_data<tuint8>();
			row.m_B1_DiscountRateIdx = deat.eat_data<tuint8>();
			row.m_B1_FullFareRateIdx = deat.eat_data<tuint8>();
			row.m_B2_MarginTimesec = deat.eat_data<tuint8>() * 5;
			row.m_B2_UnRushhourIdx = deat.eat_data<tuint8>();
			row.m_B2_DiscountRateIdx = deat.eat_data<tuint8>();
			row.m_B2_FullFareRateIdx = deat.eat_data<tuint8>();
			row.m_B3_MarginTimesec = deat.eat_data<tuint8>() * 5;
			row.m_B3_UnRushhourIdx = deat.eat_data<tuint8>();
			row.m_B3_DiscountRateIdx = deat.eat_data<tuint8>();
			row.m_B3_FullFareRateIdx = deat.eat_data<tuint8>();

			row.m_AccumulateBeginPromotionTimes = deat.eat_data<tuint16>();
			row.m_AccumulateBeginPromotionVal = deat.eat_data<long>();
			row.m_AccumulatePromotionPercent = deat.eat_data<tuint16>();
			row.m_ConnectPromotionVal = deat.eat_data<tuint16>();
			row.m_ConnectPromotionPercent = deat.eat_data<tuint16>();
			row.m_PromotionPriorityLevelType = deat.eat_data<tuint8>();
			row.m_ConnectPromotionValidTimePeriod = deat.eat_data<tuint8>();
			row.m_ConnectPromotionTrade = deat.eat_data<tuint8>();
			row.m_SpecialCardMapTypeCode = deat.eat_data<tuint8>();
			row.m_TimeTimesTicketTimeUnit = deat.eat_data<tuint8>();
			row.m_OvertimePenalty2 = deat.eat_data<tuint16>();
			row.m_ExcessPenalty2 = deat.eat_data<tuint16>();
			row.m_CardSavingsLimit = (long)deat.eat_big3();
			row.m_TimesTicketDefaultCarfare = deat.eat_data<tuint16>();
			row.m_CrosssitePenalty = deat.eat_data<tuint16>();
			deat.eat_bin( row.m_RES_02 );
			deat.eat_bin( row.m_RES_03 );
			deat.eat_bin( row.m_RES_04 );
			deat.eat_bin( row.m_RES_05 );
			row.m_DayMaxTakeTimes = deat.eat_data<tuint8>();
			deat.eat_bin( row.m_RES_06 );

			gp_db->m_a4002.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a4002);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a4003()	 
{
	a4003_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 192 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(msglen - 8 ) % 192!= 0 ", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(msglen - 8 ) % 192!= 0 " );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4003.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		long i = 0;
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4003, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			for( int y = 0; y < 64; y++ )
			{
				row.m_FareRate.a[y] = deat.eat_data<tuint16>();
			} // end for
			
			deat.eat_bin( row.m_RES_01 );

			row.m_lFareRateIdx = i;
			i++;

			gp_db->m_a4003.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a4003);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a4004()	 
{
	a4004_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 12 ) % 5 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(msglen - 12 ) % 5!= 0 ", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(msglen - 12 ) % 5!= 0" );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4004.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4004, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		deat.eat_bin( row.m_ANode );

		while( deat.HaveMoreData() )
		{
			deat.eat_bin( row.m_BNode );
			row.m_lZone = deat.eat_data<wl::tuint8>() & 63;

			gp_db->m_a4004.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a4004);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a4006()	 
{
	a4006_t::ROWTYPE row;

	if( ( ( m_ckWholeMsg.len() - 8 ) % 84 ) != 0 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|(msglen - 8 ) % 84!= 0 ", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|(msglen - 8 ) % 84!= 0 " );
		return 0;
	}
 
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4006.m_ut_tbl_lck );
		S_dataeater_t deat(m_ckWholeMsg);
		long i = 0;
		
		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4006, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte("1970-1-1").RelativeSec( deat.eat_data<long>() ).ReadString();

		while( deat.HaveMoreData() )
		{
			for(int x = 0; x < 7; x++ )
			{
				for( int y = 0; y < 12; y++ )
				{
					tuint8 u1 = deat.eat_data<tuint8>();

					for( int z = 0; z < 8; z++)
					{
						long *p = &( row.m_UnRushHourBeginTimeflag.a[x][y*z+z] );
						p += 96;
						*p = SStrf::readbit(u1,z);
					}//z
				}//y
			} //x

			row.m_UnRushHourIdx = i;
			i++;

			gp_db->m_a4006.Add(row);
		}
	}

	RISE_TBLLSAVEFLAG(m_a4006);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a4007()	 
{
	a4007_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len < 4" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4007.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4007, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		gp_db->m_a4007.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a4007);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a4008()	 
{
	a4008_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len < 4" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4008.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4008, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		gp_db->m_a4008.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a4008);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a4009()	 
{
	a4009_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len < 4" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4009.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4009, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		gp_db->m_a4009.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a4009);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a4015()	 
{
	a4015_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len < 4" );
		return 0;
	}
	
	if( 1 )  
	{
		MYAUTOLOCK( gp_db->m_a4015.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4015, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		gp_db->m_a4015.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a4015);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}



//
tbool bu_me_ele_t::do_a4016()	 
{
	a4016_t::ROWTYPE row;

	if( m_ckWholeMsg.len() < 4 )
	{
		//gp_log[LOGSC].LogPrintf( 999 + m_ckWholeMsg.len() * 3 , "%s|m_ckWholeMsg.len < 4", LOGPOSI );
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "|WholeMsg.len < 4" );
		return 0;
	}
	
	if( 1 )
	{
		MYAUTOLOCK( gp_db->m_a4016.m_ut_tbl_lck );

		S_dataeater_t deat(m_ckWholeMsg);

		row.m_lVer = deat.eat_data<long>();
		if( ExistsVer( gp_db->m_a4016, row.m_lVer ) )
			goto L_SEND_ACK;

		row.m_strAffectDateTime = SDte::GetNow().ReadString();

		gp_db->m_a4016.Add(row);
	}

	RISE_TBLLSAVEFLAG(m_a4016);
	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	My_SendMACK( (tuint8)0x00 );

	return 1;
}


//
tbool bu_me_ele_t::do_a5000()	 
{
	if( ( m_ckWholeMsg.len() - 4 ) % 6 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(Msg.len - 4)%6!=0" );
		return 0;
	}
	
	std::vector<tuint16> vType;
	std::vector<long> vVerLocal;
	std::vector<long> vVerFromSC;

	S_dataeater_t deat(m_ckWholeMsg);
	
	//目标节点	被检查的节点标识码	Block	4
	deat.eat_skip( 4 );

	while( deat.HaveMoreData() )
	{
		tuint16 u;
		d_paratime_t pt;

		u = deat.eat_data<tuint16>();
		vType.push_back( u );
		vVerLocal.push_back( pt.GetParaCurrVer(u) );

		wl::tuint32 ui4;
		ui4 = deat.eat_data<tuint32>();
		vVerFromSC.push_back( (long)ui4 );

	}

	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	de_tcpmsg_t::SendAns5000( m_tSvr, m_uiMsgType, vType, vVerLocal,m_lConversationFlow ,&vVerFromSC ); 

	return 1;
}


//
tbool bu_me_ele_t::do_a5003()	 
{
	if( ( m_ckWholeMsg.len() - 4 ) % 10 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "(Msg.len - 4)%10!=0" );
		return 0;
	}
	
	std::vector<tuint16> vType;
	std::vector<long> vVerLocal;
	std::vector<long> vVerFromSC;

	S_dataeater_t deat(m_ckWholeMsg);
	
	//目标节点	被检查的节点标识码	Block	4
	deat.eat_skip( 4 );

	while( deat.HaveMoreData() )
	{
		tuint16 u;
		d_paratime_t pt;

		u = deat.eat_data<tuint16>();
		vType.push_back( u );
		vVerLocal.push_back( pt.GetParaNewVer(u) );

		wl::tuint32 ui4;
		ui4 = deat.eat_data<tuint32>();        //deat.eat_skip( 4 );    //版本号
		vVerFromSC.push_back( (long)ui4 ); 
		
		deat.eat_skip( 4 );    //生效时间
	}

	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	de_tcpmsg_t::SendAns5000( m_tSvr, m_uiMsgType, vType, vVerLocal,m_lConversationFlow ,&vVerFromSC ); 

	return 1;
}



//
tbool bu_me_ele_t::do_a5001()	 
{
	if( m_ckWholeMsg.len() - 4 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "Msg.len - 4!=0" );
		return 0;
	}
	
	std::vector<tuint16> vType;
	std::vector<long> vVer;
	d_paratime_t pt;

	S_dataeater_t deat(m_ckWholeMsg);
	
	//目的方标识	节点标识码	Block	4
	deat.eat_skip( 4 );

	vType.push_back(0x1040); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x2000); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3002); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3003); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3006); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3009); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3011); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3083); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3084); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x3086); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4001); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4002); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4003); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4004); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4006); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );
	vType.push_back(0x4007); vVer.push_back( pt.GetParaCurrVer(*vType.rbegin()) );


	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	de_tcpmsg_t::SendAns5000( m_tSvr, m_uiMsgType, vType, vVer,m_lConversationFlow ); 

	return 1;
}


//
tbool bu_me_ele_t::do_a5002()	 
{
	if( m_ckWholeMsg.len() - 4 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "Msg.len - 4!=0" );
		return 0;
	}
	
	std::vector<tuint16> vType;
	std::vector<long> vVer;
	std::vector<long> vGmtTime;
	d_paratime_t pt;

	S_dataeater_t deat(m_ckWholeMsg);
	
	//目的方标识	节点标识码	Block	4
	deat.eat_skip( 4 );

	vType.push_back(0x1040); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x2000); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3002); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3003); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3006); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3009); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3011); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3083); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3084); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x3086); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4001); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4002); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4003); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4004); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4006); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );
	vType.push_back(0x4007); vGmtTime.push_back(0); vVer.push_back( pt.GetParaNewVer( *vType.rbegin(), &(*(vGmtTime.rbegin())) ) );


	goto L_SEND_ACK;

	//send ack
L_SEND_ACK:
	de_tcpmsg_t::SendAns5002( m_tSvr, m_uiMsgType, vType, vVer, vGmtTime,m_lConversationFlow ); 

	return 1;
}


//
tbool bu_me_ele_t::do_a5005()	 
{
	if( m_ckWholeMsg.len() - 4 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "Msg.len - 4!=0" );
		return 0;
	}
	
	//send ack
	de_tcpmsg_t::SendAns5005( m_tSvr, m_uiMsgType,m_lConversationFlow ); 

	return 1;
}


//
tbool bu_me_ele_t::do_a6004()	 
{
	int iType;
	long lbegin;
	long lend;

	if( m_ckWholeMsg.len() != 35 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "Msg.len() != 35" );
		return 0;
	}

	S_dataeater_t deat(m_ckWholeMsg);
	
	deat.eat_skip( 4 + 4 + 8 );
	
	//处理接收到的数据

	iType  = deat.eat_data<char>();  
	lbegin = deat.eat_data<long>();  
	lend   = deat.eat_data<long>();  
 
	deat.eat_skip( 10 );


	wl::tuint8 rc = 3;

	if( iType == 1  )
	{
		gp_tcpmsg->SendTrade6002_range( lbegin, lend );
		rc = 0;
	}
	else
	{
		rc = 0x03;
	}


	//send ack
	My_SendMACK( (tuint8)0x00 );
	

	return 1;
}

tbool bu_me_ele_t::do_a6005()
{
	if( m_ckWholeMsg.len() - 4 != 0 )
	{
		LOGSTREAM( gp_log[LOGSC], LOGPOSI << "Msg.len - 4!=0" );
		return 0;
	}
	
	S_dataeater_t deat(m_ckWholeMsg);

	deat.eat_skip( 4 );

	//send ack
	//做设备最新交易流水号

	de_tcpmsg_t::SendAns6005( m_tSvr, m_uiMsgType,m_lConversationFlow );

	return 1;
}







