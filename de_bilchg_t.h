
#ifndef K1_de_bilchg_t_H
#define K1_de_bilchg_t_H

#include "2.h"
#include "de_base_t.h"



typedef unsigned int UNIT;
typedef unsigned char BYTE;


//  
class de_bilchg_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	 
public:
	de_bilchg_t();
	virtual ~de_bilchg_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void bilchgAdvice();
	void bilchgInit();

	//
	int bilchgReset();	
	int bilchgState();	 // 获取设备的状态。	
	int bilchgBoxInstall( int iBoxNum, tuint32 Uid, tuint8 LineNum, tuint8 vStationNum );	//boxnum以0为基准。	// 2.8.	装载钱箱  把钱箱变成加载于TVM的状态。	

	int bilchgChangeOut_internal( int iBoxNum, tuint32 Num );	//boxnum以0为基准。	// 找零命令。钱箱和张数。		
	int bilchgChangeOut( int iBoxNum, tuint32 Num ); 

};



//
extern de_bilchg_t   *gp_bilchg;


#endif



