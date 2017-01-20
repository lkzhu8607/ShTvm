
#ifndef K1__d_cg01s_linepic_t_T_H
#define K1__d_cg01s_linepic_t_T_H


#include "2.h"
#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg01s_linepic_t : public d_cg00s_t
{
public:
	a3083_t::ROWTYPE  m_row3083;

public:
	d_cg01s_linepic_t();
	virtual ~d_cg01s_linepic_t();

public:
	virtual void OnClean(){ m_row3083 = a3083_t::ROWTYPE(); }

	void ShowLinePic();
	void ShowDirButt();
	tbool Find_n_do_ShowDirButt( std::string strinput );
};




#endif


