
#include "gtk/gtk.h"
#include "2.h"
#include "de_ui_t.h"
#include "d_db_t.h"
#include "de_frontinput_t.h"
#include "d_config_t.h"
#include "CoinCommand.h"
#include "GDnote.h"
#include "TicketCommand.h"
#include "de_tcpmsg_t.h"

#include "de_medev_t.h"

#include "de_coin_t.h"
#include "de_bill_t.h"
#include "de_emitticket_t.h"
#include "de_reader1_t.h"
#include "de_bilchg_t.h"
#include "de_topscr_t.h"
#include "de_printer_t.h"
#include "de_upsdev_t.h"
#include "FTPManager.h"  


int main2();
void test2();
void test3();
void test4();
void test_lbl();
void test_lbl_mem();
void test_key();
void test_reader();
void test_printline();
void test_uicskey();
void test_set3014();
int test_coin();
int test_coin2();
int test_coin3();
int test_bill();
int test_bill_mei();
int test_ticket();
int test_many_keyinput();
void test_double();
void test_send6002aa();
void test_printer();
void test_top_scr();
void test_emt_ticket1();
void test_read_card();


int IsYunYingDT( wl::SDte dtnow ,wl::SDte *pdtstart = NULL );
void GetYunYingDT( wl::SDte &YunYingStartDt,wl::SDte &YunYingEndDt );
SDte GetOperationDate( SDte dt ); // ??¨¨??¨²¡ê?¨º¡À??¨¨?0 

void DoYunYingStart();
void DOYunYingEnd();

bool isChangeOK( int iToBeChange, int iRMB50, int iRMB100, int iRMB500, int iRMB1000, int iRMB2000,int iRMB5000 ,long *iChangeCoin = NULL ,long *iChangeBill = NULL );

bool CanChange( int iChangeLimit = 4900 ,long *iChangeCoin = NULL ,long *iChangeBill = NULL );


void AddTransDataTo6000( a_waiter_t_rowtype & pwaiterdata );
void AddMachineDataTo6000();



int ReturnCoinAndBill( a_waiter_t_rowtype&  waiter_data );


void AddValueTo6002( a_waiter_t_rowtype&  waiter_data );


typedef struct update_3086
{
	std::string sFtpIp;
	std::string sUserName;
	std::string sPasswd;
	std::string sPicPath;
	std::string sPicFn;
}UPDATE_3086;

int update_3086_by_ftp( UPDATE_3086 update3086,wl::u8arr_t<8> picChk );









