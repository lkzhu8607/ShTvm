
#ifndef K1_de_upsdev_t_H
#define K1_de_upsdev_t_H

#include "2.h"
#include "de_base_t.h"


//  
class de_upsdev_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= loop query 
	 
public:
	de_upsdev_t();
	virtual ~de_upsdev_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void UpsAdvice();
	void UpsInit();

	//设备对外接口 
	int UpsReset();
	bool UpsCommOpen();
	void UpsCommClose();
	
	void Query();
};



//
extern de_upsdev_t  *gp_upsdev;


#endif



