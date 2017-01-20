
#ifndef K1__d_cg00s_t_T_H
#define K1__d_cg00s_t_T_H


#include "2.h"
#include "d_cg00_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg00s_t 
{
public:
	a_label_t	m_Lg;

public:
	d_cg00s_t();
	virtual ~d_cg00s_t();

public:
	void Clean();
	virtual void OnClean(){;}
	
	static void AddLg( a_label_t &Lg, a_label_t::ROWTYPE & row_in );//覆盖已有或新增.	
	static tbool LgFindhot( a_label_t &Lg, std::string strInput, a_label_t::ROWTYPE & row_out );
	static tbool LocateHot( std::vector<a_label_t::ROWTYPE> &Lg, std::string strInput, std::vector<a_label_t::ROWTYPE> & row_out );
	static tbool trrigerHot( std::vector<a_label_t::ROWTYPE> &Lg, std::string strInput, a_label_t::ROWTYPE & row_out );
};




#endif


