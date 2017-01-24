
#ifndef K1__d_cg02s_machinestate_t_T_H
#define K1__d_cg02s_machinestate_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"


//
class d_cg02s_machinestate_t : public d_cg00s_t
{
public:

	double m_x,m_y;
public:
	d_cg02s_machinestate_t();
	virtual ~d_cg02s_machinestate_t();

public:
	void ShowStatus();
};




#endif