
#ifndef K1__d_cg01s_seleline_t_T_H
#define K1__d_cg01s_seleline_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg01s_seleline_t : public d_cg00s_t
{
public:
	a3084_t		m_a3084snapshot;
	int		m_iPageSize;


public:
	d_cg01s_seleline_t();
	virtual ~d_cg01s_seleline_t();

public:
	std::string GetLinepicPFn( int iLineNum );
	void Showseleline();
	tbool Find_n_do_seleline( std::string strinput );
	tbool Find_n_do_changepage( std::string strinput );
};




#endif


