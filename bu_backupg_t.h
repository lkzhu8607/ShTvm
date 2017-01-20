
#ifndef K1__bu_backupg_t_H
#define K1__bu_backupg_t_H


#include "2.h" 
#include "bu_hot_thrd_t.h"



//
class bu_backupg_t : public bu_hot_thrd_t
{
public:

public:
	bu_backupg_t();
	virtual ~bu_backupg_t(){;}

public:

	virtual int tr_on_user_run();
	int is_dir_exist(const char* dir_path);

};

extern void backupg_go();



#endif



