
#ifndef K1__d_cg03_t_T_H
#define K1__d_cg03_t_T_H


#include "d_cg00_t.h"
#include "a_label_t.h"


//
class d_cg03_t : public d_cg00_t
{
public:
	int  m_iLineCode;

public:
	d_cg03_t();
	virtual ~d_cg03_t();

public:
	virtual void Proc();

public:

};


//
extern d_cg03_t  *plocalcg03;



#endif


