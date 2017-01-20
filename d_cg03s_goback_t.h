
#ifndef K1__d_cg03s_goback_t_T_H
#define K1__d_cg03s_goback_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"


//
class d_cg03s_goback_t : public d_cg00s_t
{
public:

public:
	d_cg03s_goback_t();
	virtual ~d_cg03s_goback_t();

public:
	void ShowGoback();
	tbool Find_n_do_ShowGoback( std::string strinput );
};




#endif


