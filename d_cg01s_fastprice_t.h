
#ifndef K1__d_cg01s_fastprice_t_T_H
#define K1__d_cg01s_fastprice_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"


//
class d_cg01s_fastprice_t : public d_cg00s_t
{
public:
	 std::vector< int > m_v;

public:
	d_cg01s_fastprice_t();
	virtual ~d_cg01s_fastprice_t();

public:
	void Showfastprice1block( int i, std::vector< int > & v, int updn );
	void Showfastprice();
	tbool Find_n_do_Showfastprice( std::string strinput );
};




#endif


