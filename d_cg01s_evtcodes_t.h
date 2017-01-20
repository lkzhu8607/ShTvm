
#ifndef K1__d_cg01s_evtcodes_t_T_H
#define K1__d_cg01s_evtcodes_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "d_db_t.h"


//
class d_cg01s_evtcodes_t : public d_cg00s_t
{
public:
	//double m_x = 0.332;
	double m_x;

public:
	d_cg01s_evtcodes_t();
	virtual ~d_cg01s_evtcodes_t();

public:
	void ShowEvtCodes();
	 
};




#endif


