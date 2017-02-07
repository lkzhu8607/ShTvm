
#ifndef K1__d_cg03s_seleline_t_T_H
#define K1__d_cg03s_seleline_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg03s_seleline_t : public d_cg00s_t
{
public:

public:
	d_cg03s_seleline_t();
	virtual ~d_cg03s_seleline_t();

public:
	tbool Find_n_do_seleline( std::string strinput );
};




#endif