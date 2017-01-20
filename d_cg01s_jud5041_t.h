
#ifndef K1__d_cg01s_jud5041_t_T_H
#define K1__d_cg01s_jud5041_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg01s_jud5041_t : public d_cg00s_t
{
public:

public:
	d_cg01s_jud5041_t();
	virtual ~d_cg01s_jud5041_t();

public:
	tbool Find_n_do_stopservice( std::string strinput );
	tbool Find_n_do_gotowork( std::string strinput );

	void ShowEvtCodes();
	 
};




#endif


