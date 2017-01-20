
//���ò����Ƿ���Ч
#ifndef K1__d_paratime_t_H
#define K1__d_paratime_t_H


#include "2.h" 
#include "bu_hot_thrd_t.h"



//���ڲ�������

class d_paratime_t
{
public:

public:
	d_paratime_t();
	virtual ~d_paratime_t(){;}

private:
	std::string GetRowAffectPk( unitbl_base_t & tbl, long y );
	std::string GetPrepareAffectPk( unitbl_base_t & tbl ); // ���й�ȥ����δ��Ч��PK�ó�������ȡ���һ���� 
	void TakeAffect( unitbl_base_t & tbl, std::string strAffectPk );
	void Purge1( unitbl_base_t & tbl, double dTimeLimit = 3.0 );
	
public:
	tbool DetectAffect();
	void TakeAffectAll();
	void Purge();
	void MarkDel();
	
	long GetParaCurrVer( unitbl_base_t & tbl );  
	long GetParaCurrVer( tuint16 itype );

	long GetParaNewVer( unitbl_base_t & tbl , long * plAffcGmtTime = NULL );  
	long GetParaNewVer( tuint16 itype , long * plAffcGmtTime = NULL );  
};






#endif



