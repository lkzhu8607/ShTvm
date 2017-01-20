
#ifndef K1__bu_timeshower_t_H
#define K1__bu_timeshower_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"
#include "a_label_t.h"


//
class bu_timeshower_t : public bu_hot_thrd_t
{
public:
	enum ShowType_t {	HIDE , 
						HIDED , 
						DATETIME , 
						DATE , 
						QUIT };
	
	ShowType_t  m_stype;
	ShowType_t  m_stypefuture;
	int			m_stypecount;
	double m_x;
	double m_y;
	int		m_scr;
	std::vector<a_label_t::ROWTYPE> graphElements;
	int pageGraphElementsFlags;
	int timerFlags;

public:
	bu_timeshower_t();
	virtual ~bu_timeshower_t();

public:
	virtual int tr_on_user_run();
	void timeLabel();
	void init();
	void SetSType( ShowType_t S );
	
};


//
extern bu_timeshower_t     *gp_timeshower;



#endif



