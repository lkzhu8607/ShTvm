
#ifndef K1__d_com_agent2_t_T_H
#define K1__d_com_agent2_t_T_H


#include "2.h"


/*
 ��������̳С��������⴮��
*/
//�����ַ���
//�����ַ��Ƿ��ǿ�ʼ������ж��Ƿ���һ�α��ĵĿ�ʼ�����
//�ж��ַ��Ƿ���ת���ַ����ɻ��Ǳ�ʡ
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


