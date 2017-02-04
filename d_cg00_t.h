
#ifndef K1__d_cg00_t_T_H
#define K1__d_cg00_t_T_H


#include "2.h"
#include "a_label_t.h"
#include "bu_quickflow_t.h"


//
class d_cg00_t 
{
public:
	std::vector<a_label_t::ROWTYPE> graphElementsCN;
	std::vector<a_label_t::ROWTYPE> graphElementsEN;
	int pageGraphElementsFlags;
	int displayFlag;//0--No,1--yes
	int langFlag;//0--CN,1--EN
	std::vector<a_label_t::ROWTYPE> graphLastPageElements;
	
public:
	d_cg00_t();
	virtual ~d_cg00_t();

public:
	virtual void Proc(){}

public:

};




#endif


