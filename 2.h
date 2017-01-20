
#ifndef K1__2_H
#define K1__2_H



#ifdef _MT
#define WINENV_
#else
#define LINUENV_
#endif


#ifdef LINUENV_
//#include "gtk/gtk.h"
//#include <gdk/gdk.h>
//#include <glib.h>
//#include <glib/gprintf.h>
//#include <gdk/gdkkeysyms.h>
//#include <X11/Xlib.h>
#include "list"
#include "1.h"
#else
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <windows.h>
#include <shellapi.h>
#include "atlstr.h" //CString in here
//#import "msado27.tlb" rename("EOF", "adoEOF")
#include "list"
//#include "\a1\a\k\mydup04\CDUP\w_alls.h"
//#include "\a1\a\k\mydup04\CDUP\w_allw.h"
//#include "\a1\a\k\mydup04\CDUP\net\a01ref_net.h"
#include "1.h"
#endif
using namespace wl;
#include "gfunc_md5.h"
extern bool IsOsWin();


#define KIN_APP				1
#define KIN_SOP				2
#define KIN_SC				3	 
#define		KIN_BILL				4	 
#define		KIN_COIN				5	 
#define		KIN_BILLCHG				6	 
#define	KIN_COINCHG			7	 
#define		KIN_EMTICKET			8	 
#define		KIN_READER1				9	 
#define		 KIN_TOPSCR			15	/* ������10����10�պ���\n����keyinput�����г�ͻ */ 
#define		 KIN_PRINTER		11
#define		 KIN_UPS			12
#define		KIN_MOUSEBUTT1			13
#define		KIN_KEYPRESS			14

#define LOGAMOUNT			15	/* ��־��������  */ 
#define LOGNULL				0	/* ��  */ 
#define LOGAPP				1	/* Ӧ�ó���  */ 
#define LOGSOP				2	/* ��̨���̲���  */ 
#define LOGSC				3	/* ��SC��ͨ��  */ 
#define LOGBILL				4	/* ֽ��  */ 
#define LOGCOIN				5	/* Ӳ��  */ 
#define LOGBILLCHG			6	/* ֽ������  */ 
#define LOGCOINCHG			7	/* Ӳ������  */ 
#define LOGEMTICKET			8	/* ����  */ 
#define LOGREADER1			9	/* ��д��1  */ 
#define LOGTOPSCR			10	/* ������  */ 
#define LOGPRINTER			11	/* ��ӡ��  */ 
#define LOGUPS				12	/* UPS  */ 
#define LOGMOUSEBUTT1		13	/* �����  */ 
#define LOGKEYPRESS			14	/* ����  */ 


#define LOGPOSI  ( SDte::GetNow().ReadString() + "|" + std::string(__FILE__) + "|" + std::string(__FUNCTION__) + "|" + SStrf::sltoa(__LINE__) + "\t" ).c_str()
//#define LOG do{ printf( "%s-\n", LOGPOSI );  }while(0)

#define SADDR(s)  (&(s[0]))
#define GETLABELNAME  "J6a"   " "  "|" + std::string(__FILE__) + "|" + std::string(__FUNCTION__) + "|" + SStrf::sltoa(__LINE__)

#define LOGSTREAM(logobj,streamexp)  do{std::stringstream stream1; stream1<<streamexp; (logobj).LogPrintStr( stream1.str().c_str() ); }while(0)

#define MYAUTOLOCK2(Suffix,obj)   WCrsc aLoc_myLck_ ## Suffix (&(obj))
#define MYAUTOLOCK1(Suffix,obj) MYAUTOLOCK2(Suffix,obj)
#define MYAUTOLOCK(obj) MYAUTOLOCK1(__COUNTER__,obj)

// ǰ̨��Ǯ����	
#define FRONT_REC(streamexp)  do{std::stringstream stream1; stream1<<streamexp; gp_moneylog->FrontRec( stream1.str().c_str() ); }while(0)
// ��̨��Ǯ����	
#define BACK_REC(streamexp)   do{std::stringstream stream1; stream1<<streamexp; gp_moneylog->BackRec( stream1.str().c_str() ); }while(0)
// ǰ��̨ͬʱ��	
#define TWO_REC(streamexp)    do{std::stringstream stream1; stream1<<streamexp; gp_moneylog->TwoRec( stream1.str().c_str() ); }while(0)
// ����ֽ�ϣ�ͬʱ�Ǻ�̨	
#define SHEET_REC(streamexp)  do{std::stringstream stream1; stream1<<streamexp; gp_moneylog->SheetRec( stream1.str().c_str() ); }while(0)


typedef	 void *	PVOID_t;
typedef	 unsigned char *	PU8_t;
#define	u8arr_t ui8arr_t  


//
template < int XIDX_T, int YIDX_T >
struct longarr2v_t
{
	long a[XIDX_T][YIDX_T];
	 
	bool operator == (const longarr2v_t & rhs) const
	{
		return false;
	}

	bool operator > (const longarr2v_t & rhs) const
	{
		return false;
	}

	bool operator < (const longarr2v_t & rhs) const
	{
		return false;
	}

};




#endif


