
#ifndef K1_de_printer_t_H
#define K1_de_printer_t_H

#include "2.h"
#include "de_base_t.h"
#include "d_com_agent2_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "bu_quickflow_t.h"
#include "d_db_t.h"
#include "de_base_realmode.h"



class CPrinterComm : public d_com_agent2_t
{
public:


};
//  
class de_printer_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= loop query 
	CPrinterComm printercomm;
	 
public:
	de_printer_t();
	virtual ~de_printer_t();

public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void PrinterAdvice();
	void PrinterInit();

	//设备对外接口 
	int PrinterReset();
	bool PrinterCommOpen();
	void PrinterCommClose();
	
private:
	void HalfCut();
	void PrintPic( SCake ckPic );			//	直接驱动打印	
	void PrintLine( std::string str );	//	直接驱动打印	
	void Query();
	void PrintStr(SCake ckStr);

public:
	void PrintStr(std::string str);
	
	void HalfCutAsync();	// 异步	     //异步测试下来，没有用，半天不打印
	void PrintLineAsync( std::string str );	// 异步	
	void PrintStrAsync( std::string str );	// 异步	

	void PrintAbnormalTrans( a_waiter_t_rowtype & pwaiterdata );
};



//
extern de_printer_t  *gp_printer;


#endif



