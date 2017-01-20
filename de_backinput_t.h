
#ifndef K1_de_backinput_t_H
#define K1_de_backinput_t_H

#include "2.h"
#include "bu_hot_thrd_t.h"



//   
class de_backinput_t : public WKeyinput< bu_hot_thrd_t >
{
public:

public:
	de_backinput_t();
	virtual ~de_backinput_t();

public:
	tbool backInit( int iPort );
	void input_KIN_KEYPRESS( const char *sz );

	
};



//
extern de_backinput_t     *gp_backinput;

#endif


