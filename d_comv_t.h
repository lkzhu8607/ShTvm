
#ifndef K1__d_comv_t_T_H
#define K1__d_comv_t_T_H


#include "2.h"


//
class d_comv_t 
{
public:
	enum CellType_t { LOCAL, REMOTE }; 
	CellType_t			m_CellType;

	WCrsc			m_ComvLck;

public:
	WTcpCellc		m_tcAg;
	std::string		m_strComId;
	std::string		m_strPrType;	// "PR_0203"   "PR_LEN_AT_3" 

	int				m_iLogType;

public:
	d_comv_t();
	virtual ~d_comv_t(){};

public:
	tbool Conn();
	tbool Close();
	tbool SendFrame( SCake & ck_in, std::string *pstrTagPara = NULL );
	tbool RecvFrame( SCake & ck_out, std::string *pstrTagPara = NULL );
	
};






#endif


