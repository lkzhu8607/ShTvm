
#ifndef K1__d_cg02s_cancel_t_T_H
#define K1__d_cg02s_cancel_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"


//
class d_cg02s_cancel_t : public d_cg00s_t
{
public:

public:
	d_cg02s_cancel_t();
	virtual ~d_cg02s_cancel_t();

public:
	void Showcancel();
	tbool Find_n_do_Showcancel( std::string strinput );
};




#endif


