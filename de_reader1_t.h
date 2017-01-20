
#ifndef K1_de_reader1_t_H
#define K1_de_reader1_t_H

#include "2.h"
#include "de_base_t.h"
#include "ReadWriteCommand.h"




typedef unsigned int UNIT;
typedef unsigned char BYTE;


//  
class de_reader1_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	 ReadWrite rw;
public:
	de_reader1_t();
	virtual ~de_reader1_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void Reader1Advice();
	void Reader1Init();

	//设备对外接口 
	bool rCommOpen();
	void rCommClose();

	int rReset();	 //	2.3.	读写器复位	
	int rInit( BYTE InitIn[11] );	//	2.4.	读写器初始化	
	int rInit2();	//	初始化	
	int rAbort();

	int rReadCard();	//	2.5.	读卡	
	int rSaleCard( BYTE SaleIn[14] );	//	2.6.	售卡	

	int rSaleCard2( int iPrice );	// 包装后的售卡	
	//
};



//
extern de_reader1_t  *gp_reader1;


#endif



