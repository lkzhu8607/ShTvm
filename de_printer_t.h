
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

	//�豸����ӿ� 
	int PrinterReset();
	bool PrinterCommOpen();
	void PrinterCommClose();
	
private:
	void HalfCut();
	void PrintPic( SCake ckPic );			//	ֱ��������ӡ	
	void PrintLine( std::string str );	//	ֱ��������ӡ	
	void Query();
	void PrintStr(SCake ckStr);

public:
	void PrintStr(std::string str);
	
	void HalfCutAsync();	// �첽	     //�첽����������û���ã����첻��ӡ
	void PrintLineAsync( std::string str );	// �첽	
	void PrintStrAsync( std::string str );	// �첽	

	void PrintAbnormalTrans( a_waiter_t_rowtype & pwaiterdata );
};



//
extern de_printer_t  *gp_printer;


#endif



