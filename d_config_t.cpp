
//
#include "2.h"
#include "d_config_t.h"


//
d_config_t  *gp_conf;



//
d_config_t::d_config_t()
{
	m_bMajorSysVer = 1;
	m_bMinorSysVer = 1;
	m_strSysVer = "V1.01";
	m_strSysVerInternal = "20170106.094101" + std::string(" ") + std::string(__DATE__) + std::string(" ") + std::string(__TIME__) + std::string(" ");
	//20140327.153829	初版，开发中. 

	m_biSysShouldExit = 0;
	m_biSysShouldShutdown = 0;
	m_biSysShouldReboot = 0;

	m_strUDiskDev = "";
	m_biDbDiskOk = 1;
	m_biScConnOk = 1;
	m_iEn0Ch1 = 1;
	m_biSOPMode = 0;

	m_iSend6002RowCount = 0;
	m_iSend6002ShouldNum = 0;

	m_iIsUseSCAddr2 = 0;

	m_Sc2000HostIpAddr = "";
	m_Sc2000BackUpIpAddr = "";

	m_iBillCycleChg1 = 5;    //default
	m_iBillCycleChg2 = 10;   //default

}


//
tbool d_config_t::LoadConfFile()
{
	SFile fInFile;
	std::string	 strFileContent;
	MYAUTOLOCK(m_ConfLck);

	fInFile.bind( "shtvm_config_a.txt" );
	fInFile.read_str( strFileContent );
	m_nvA.clear();
	m_nvA.impconf( strFileContent );

	fInFile.bind( "shtvm_config_b.txt" );
	fInFile.read_str( strFileContent );
	m_nvB.clear();
	m_nvB.impconf( strFileContent );


	m_coin_rep_num = (int)SStrf::satol( gp_conf->getnvB("coin_rep_num") ) ;


	m_TicketTradeTerminalFlow0 = (long)SStrf::satol( gp_conf->getnvB("TicketTradeTerminalFlow0") ) ;

	return 1;
}



// 
tbool d_config_t::IsOsWin()
{
	tbool itype = 1;
#ifdef WINENV_
	itype = 1;
#endif
#ifdef LINUENV_
	itype = 0;
#endif

	return itype;
}



// 
void d_config_t::MakeDiskEnv()
{
	if( !this->IsOsWin() )
	{
		WFile::makedir( "/mnt2" ); // U盘挂在这。
	}

	WFile::makedir( this->Get_dbsavepath1() );
	WFile::makedir( this->Get_dbsavepath2() );
	WFile::makedir( this->Get_datapath3() );
	WFile::makedir( this->Get_datapath4() );
	WFile::makedir( this->Get_logpath5() );
	WFile::makedir( this->Get_logpath6() );

	
	if( !this->IsOsWin() )
	{
		WFile fl;
		fl.bind( gp_conf->m_strUDiskDev = "/dev/sdb1" );
		if( fl.exists() )
			gp_conf->m_strUDiskDev = "/dev/sdc1";
	}

	if( !this->IsOsWin() )
	{
		WFile::run_exe( "ln -v -s /dev/ttyS0 /dev/mycom1" );
		WFile::run_exe( "ln -v -s /dev/ttyS1 /dev/mycom2" );
		WFile::run_exe( "ln -v -s /dev/ttyS4 /dev/mycom3" );
		WFile::run_exe( "ln -v -s /dev/ttyS5 /dev/mycom4" );
		WFile::run_exe( "ln -v -s /dev/ttyS6 /dev/mycom5" );
		WFile::run_exe( "ln -v -s /dev/ttyS7 /dev/mycom6" );
		WFile::run_exe( "ln -v -s /dev/ttyS8 /dev/mycom7" );
		WFile::run_exe( "ln -v -s /dev/ttyS9 /dev/mycom8" );
		WFile::run_exe( "ln -v -s /dev/ttyS10 /dev/mycom9" );
		WFile::run_exe( "ln -v -s /dev/ttyS11 /dev/mycom10" );
		WFile::run_exe( "ln -v -s /dev/ttyS12 /dev/mycom11" );
		WFile::run_exe( "ln -v -s /dev/ttyS13 /dev/mycom12" );
		WFile::run_exe( "ln -v -s /dev/ttyS14 /dev/mycom13" );
		WFile::run_exe( "ln -v -s /dev/ttyS15 /dev/mycom14" );
	}
}



//
std::string d_config_t::getnvA( std::string strName )
{
	MYAUTOLOCK(m_ConfLck);
	return m_nvA.get(strName);
}

//
std::string d_config_t::getnvB( std::string strName )
{
	MYAUTOLOCK(m_ConfLck);
	return m_nvB.get(strName);
}



//
WNava d_config_t::getnvA()
{
	MYAUTOLOCK(m_ConfLck);
	return m_nvA;
}


//
WNava d_config_t::getnvB()
{
	MYAUTOLOCK(m_ConfLck);
	return m_nvB;
}

// 
std::string d_config_t::Get_coin_com_port()
{
	if( this->IsOsWin() )
		//return "com=3;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=0.5;";
		return "com=2;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=1.61;";

	return getnvB("coin_com_port");
}

// 
std::string d_config_t::Get_bill_com_port()
{
	if( this->IsOsWin() )
		//return "com=8;start=1;stop=1;speed=9600;parity=O;datalen=8;timeoutsec=2.5;";
		return "com=1;start=1;stop=1;speed=4800 ;parity=E;datalen=7;timeoutsec=2.51;";

	return getnvB("bill_com_port");
}

// 
std::string d_config_t::Get_ticket_com_port()
{
	if( this->IsOsWin() )
		//return "com=44;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=0.5;";
		return "com=4;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=1.99;";

	return getnvB("ticket_com_port");
}


// 
std::string d_config_t::Get_reader1_com_port()
{
	if( this->IsOsWin() )
		//return "com=4;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=0.5;";
		return "com=10;start=1;stop=1;speed=28800;parity=N;datalen=8;timeoutsec=1.62;";

	return getnvB("reader1_com_port");
}

// 
std::string d_config_t::Get_bilchgrfid_com_port()
{
	if( this->IsOsWin() )
		//return "com=5;start=1;stop=1;speed=38400;parity=N;datalen=8;timeoutsec=0.51;";
		return "com=13;start=1;stop=1;speed=38400;parity=N;datalen=8;timeoutsec=1.62;";

	return getnvB("bilchgrfid_com_port");
}

// 
std::string d_config_t::Get_bilchg_com_port()
{
	if( this->IsOsWin() )
		//return "com=6;start=1;stop=1;speed=9600;parity=E;datalen=8;timeoutsec=0.51;";
		return "com=6;start=1;stop=1;speed=9600 ;parity=E;datalen=8;timeoutsec=1.62;";

	return getnvB("bilchg_com_port");
}

// 
std::string d_config_t::Get_topscr_com_port()
{
	if( this->IsOsWin() )
		//return "com=8;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=0.51;";
		return "com=6;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=1.88;";

	return getnvB("topscr_com_port");
}

// 
std::string d_config_t::Get_printer_com_port()
{
	if( this->IsOsWin() )
		//return "com=9;start=1;stop=1;speed=9600 ;parity=N;datalen=8;timeoutsec=0.51;";
		//return "com=7;start=1;stop=1;speed=38400;parity=N;datalen=8;timeoutsec=0.62;";
		return "com=8;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=1.6;";
		//return "com=3;start=1;stop=1;speed=57600;parity=N;datalen=8;timeoutsec=1.6;";

	return getnvB("printer_com_port");
}

// 
std::string d_config_t::Get_ups_com_port()
{
	if( this->IsOsWin() )
		//return "com=10;start=1;stop=1;speed=2400 ;parity=N;datalen=8;timeoutsec=4.51;";
		return "com=9;start=1;stop=1;speed=2400 ;parity=N;datalen=8;timeoutsec=4.62;";

	return getnvB("ups_com_port");
}


// 
std::string d_config_t::Get_tvm_port()
{
	return getnvB("tvm_port");
}


// 
std::string d_config_t::Get_path0()
{
	if( this->IsOsWin() )
		return "d:\\t\\";
	else
		return "/mnt/";
}

// 
std::string d_config_t::Get_dbsavepath1()
{
	if( this->IsOsWin() )
		return "d:\\t\\db1\\";
	else
		return "/mnt/db1/";
}

// 
std::string d_config_t::Get_dbsavepath2()
{
	if( this->IsOsWin() )
		return "d:\\t\\db2\\";
	else
		return "/mnt/db2/";
}


// 
std::string d_config_t::Get_datapath3()
{
	if( this->IsOsWin() )
		return "d:\\t\\db3\\";
	else
		return "/mnt/db3/";
}

// 
std::string d_config_t::Get_datapath4()
{
	if( this->IsOsWin() )
		return "d:\\t\\db4\\";
	else
		return "/mnt/db4/";
}

// 
std::string d_config_t::Get_logpath5()
{
	if( this->IsOsWin() )
		return "d:\\t\\db5\\";
	else
		return "/mnt/db5/";
}

// 
std::string d_config_t::Get_logpath6()
{
	if( this->IsOsWin() )
		return "d:\\t\\db6\\";
	else
		return "/mnt/db6/";
}

// 
int d_config_t::Get_pkg_seri_style()
{
	return (int)SStrf::satol( getnvB("pkg_seri_style") );
}


// 
int d_config_t::Get_scrall_width()
{
	return (int)SStrf::satol( getnvB("scrall_width") );
}

// 
int d_config_t::Get_scrall_height()
{
	return (int)SStrf::satol( getnvB("scrall_height") );
}

// 
int d_config_t::Get_scr_width( int scrnum )
{
	if( scrnum == 0 )
		return (int)SStrf::satol( getnvB("scr0_width") );
	return (int)SStrf::satol( getnvB("scr1_width") );
}

//
int d_config_t::Get_scr_height( int scrnum )
{
	if( scrnum == 0 )
		return (int)SStrf::satol( getnvB("scr0_height") );
	return (int)SStrf::satol( getnvB("scr1_height") );
}

// 
int d_config_t::Get_scr_startx( int scrnum )
{
	if( scrnum == 0 )
		return (int)SStrf::satol( getnvB("scr0_startx") );
	return (int)SStrf::satol( getnvB("scr1_startx") );
}

//
int d_config_t::Get_scr_starty( int scrnum )
{
	if( scrnum == 0 )
		return (int)SStrf::satol( getnvB("scr0_starty") );
	return (int)SStrf::satol( getnvB("scr1_starty") );
}


// 
std::string d_config_t::Get_sc_addr()
{
	if( m_iIsUseSCAddr2 )
	{
		return Get_sc_addr2();
	}
	
	return Get_sc_addr1();
}


std::string d_config_t::Get_sc_addr1()
{
	if( m_Sc2000HostIpAddr != "" )
	{
		return m_Sc2000HostIpAddr;
	}
	return getnvB("sc_addr");
}

std::string d_config_t::Get_sc_addr2()
{
	if( m_Sc2000BackUpIpAddr != "" )
	{
		return m_Sc2000BackUpIpAddr;
	}
	return getnvB("sc_addr2");
}

wl::tbool d_config_t::IsJT_SC()
{
	if( Get_pkg_seri_style() == 0 ) // 0:技通式  1:华腾式 
		return 1;

	return 0;
}
wl::tbool d_config_t::IsHT_SC()
{
	if( Get_pkg_seri_style() == 1 ) // 0:技通式  1:华腾式 
		return 1;

	return 0;
}

std::string d_config_t::Get_sc_ftp_username()
{

	return getnvB("sc_ftp_username");

}

std::string d_config_t::Get_sc_ftp_passwd()
{
	return getnvB("sc_ftp_passwd");

}

void d_config_t::VersionDisplay(){
	//a_label_t::ROWTYPE	row;
	gp_ui->LabelMkStr( this->VersionDisplayLabel, 0, "shtvmVersion", this->m_strSysVer, gp_ui->X2dR( 0, 0 ), gp_ui->Y2dR( 0, 0 ), 0.01, "red" );
	this->VersionDisplayLabel.m_hot = 0;
	gp_ui->str_task(this->VersionDisplayLabel);

}

