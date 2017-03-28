
#ifndef K1__CONFIG_T_H
#define K1__CONFIG_T_H


#include "2.h"
#include "a_label_t.h"
#include "de_ui_t.h"


//
class d_config_t
{
public:

	tuint8       m_bMajorSysVer;
	tuint8       m_bMinorSysVer;
	std::string  m_strSysVer;
	std::string  m_strSysVerInternal;

	volatile int  m_biSysShouldExit;
	volatile int  m_biSysShouldShutdown;
	volatile int  m_biSysShouldReboot;

	std::string			m_strUDiskDev; //U盘的设备名 开机时检测，U盘升级时有用 
	volatile tbool		m_biDbDiskOk;	//DB写盘正常
	volatile tbool		m_biScConnOk;	//SC连接正常
	volatile int		m_iEn0Ch1;		//英文、中文	没用到。实际用到的是 m_LanguageCh0En1	
	volatile tbool		m_biSOPMode; 	//

	long		m_iSend6002RowCount;		// 6002发出去多少 
	long		m_iSend6002ShouldNum;		// 6002待发有多少  

	int         m_coin_rep_num;

	int m_iIsUseSCAddr2;         //是否使用备用sc地址     0-不使用(default)  1-使用

	std::string m_Sc2000HostIpAddr;       //零时用变量存储
	std::string m_Sc2000BackUpIpAddr;

	int m_iBillCycleChg1;
	int m_iBillCycleChg2;

	long   m_TicketTradeTerminalFlow0;    //配置读取初始交易流水号
	a_label_t::ROWTYPE	VersionDisplayLabel;

private:
	WCrsc  m_ConfLck;

	WNava  m_nvA;
	WNava  m_nvB;

public:
	d_config_t();
	virtual ~d_config_t(){};

public:
	tbool LoadConfFile();
	tbool IsOsWin();
	void MakeDiskEnv();

	WNava getnvA(); 
	WNava getnvB();
	std::string getnvA( std::string strName ); 
	std::string getnvB( std::string strName ); 

	std::string Get_coin_com_port();
	std::string Get_bill_com_port();
	std::string Get_ticket_com_port();
	std::string Get_reader1_com_port();
	std::string Get_bilchgrfid_com_port();
	std::string Get_bilchg_com_port();
	std::string Get_topscr_com_port();
	std::string Get_printer_com_port();
	std::string Get_ups_com_port();

	std::string Get_tvm_port();	//	# 本机侦听的端口号，供SC连进来时候用  

	std::string Get_path0(); // 数据根 
	std::string Get_dbsavepath1(); //第1套DB，以及strDataRef  
	std::string Get_dbsavepath2(); //第2套DB
	std::string Get_datapath3();  //其它功能用路径 图片在此。 
	std::string Get_datapath4();  //测试用路径  
	std::string Get_logpath5();   //LOG路径  
	std::string Get_logpath6();   // MONEYLOG路径  
	int Get_pkg_seri_style();

	int Get_scrall_width();
	int Get_scrall_height();
	int Get_scr_width( int scrnum );
	int Get_scr_height( int scrnum );
	int Get_scr_startx( int scrnum );
	int Get_scr_starty( int scrnum );
	
	std::string Get_sc_addr();  // sc

	wl::tbool IsJT_SC(); // 是技通SC
	wl::tbool IsHT_SC(); // 是华腾SC

	std::string Get_sc_ftp_username();
	std::string Get_sc_ftp_passwd();
	void VersionDisplay();

private:
	std::string Get_sc_addr1();  // sc
	std::string Get_sc_addr2();  // sc
	

};



//
extern d_config_t  *gp_conf;



#endif


