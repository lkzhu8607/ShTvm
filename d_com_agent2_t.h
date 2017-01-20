
#ifndef K1__d_com_agent2_t_T_H
#define K1__d_com_agent2_t_T_H


#include "2.h"


/*
 各串口需继承。用于虚拟串口
*/
//处理字符串
//根据字符是否是开始与结束判断是否是一段报文的开始与结束
//判定字符是否由转义字符生成还是本省
#define CHAR_START 0x02
#define CHAR_END 0x03

//  
class d_com_agent2_t  
{
public:
	std::string  m_strConnStr;

	WComeliCell  m_aCom;		// for real
	WTcpCellc    m_sp2;		// for fake	

public:
	d_com_agent2_t();
	virtual ~d_com_agent2_t();

public:
	tbool Conn( std::string strname );
	void DisConn();
	
	tbool send_bin( const SCake & ckData );
	tbool recv_len( SCake & ckData , tsize iWantDataLen ) ;
	tbool recv_bin( SCake & ckData ) ;
	tbool recv_all( SCake & ckData ) ;
	int getFd(int *fileDes);
	
};





#endif


