

//接受SC服务器下发的参数 和 bu_me_mgr_t 共同使用
#ifndef K1__bu_me_ele_t_H
#define K1__bu_me_ele_t_H


#include "2.h" 



//
class bu_me_ele_t : public WThrd
{
public:
	WTcpCells		m_tSvr;
	std::map< tuint16, tbool(bu_me_ele_t::*)() >   m_mf; // 处理函数表 
	std::map< tuint16, std::string >	m_mOff; // 固定长度部分的长度表，用字符串记录，无记录的可自动得到0.  
	SCake			m_ckWholeMsg;
	tuint16			m_uiMsgType;
	wl::tint32   m_lConversationFlow;

public:
	bu_me_ele_t();
	virtual ~bu_me_ele_t();

public:
	virtual int tr_on_user_run();
	tbool GetWholeMsg();
	tbool ExistsVer( unitbl_base_t & tbl , long lVer );

	wl::tbool My_SendMACK( wl::tuint8 ui1Answer );

	tbool do_a_fake();
	tbool do_a1040();
	tbool do_a2000();
	tbool do_a2001();
	tbool do_a3000();
	tbool do_a3001();
	tbool do_a3002();
	tbool do_a3003();
	tbool do_a3006();
	tbool do_a3007();
	tbool do_a3008();
	tbool do_a3009();
	tbool do_a3011();
	tbool do_a3012();
	tbool do_a3014();
	tbool do_a3082();
	tbool do_a3083();
	tbool do_a3084();
	tbool do_a3085();
	tbool do_a3086();
	tbool do_a4001();
	tbool do_a4002();
	tbool do_a4003();
	tbool do_a4004();
	tbool do_a4006();
	tbool do_a4007();
	tbool do_a4008();
	tbool do_a4009();
	tbool do_a4015();
	tbool do_a4016();
	tbool do_a5000();
	tbool do_a5003();
	tbool do_a5001();
	tbool do_a5002();
	tbool do_a5005(); //9.0.13 5005-查询软件版本。这是一种涉及多个节点的会话，它最初可由COC、SOC、
	tbool do_a6004();
	tbool do_a6005();
	
};





#endif



