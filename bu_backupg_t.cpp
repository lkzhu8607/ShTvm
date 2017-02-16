
#include "bu_backupg_t.h"
#include "bu_asynwork_t.h"
#include "de_ui_t.h"
#include "d_config_t.h"
#include "d_db_t.h"

#define PROGRAM_NAME "shtvm"
#define PROGRAM_DIR "/root/shtvm_sys/"
#define PROGRAMBIN_DIR  "/root/shtvm_sys/bin/"
#define PROGRAMCONF_DIR  "/root/shtvm_sys/conf/"
#define PROGRAMLIB_DIR  "/root/shtvm_sys/lib/"
#define PROGRAMLOG_DIR  "/root/shtvm_sys/log/"



//
bu_backupg_t::bu_backupg_t()
{
}


// 
int bu_backupg_t::tr_on_user_run()
{
	WFile fl;
	char s1[333];
	char sCmd[333];
	char szUDiskname[333];
	int rc;

	WThrd::tr_sleep(1);

	gp_ui->LineScrClearA();

	sprintf( szUDiskname, "%s", gp_conf->m_strUDiskDev.c_str() ); 

    WFile::makedir(PROGRAM_DIR);  //创建程序工作目录
    WFile::makedir(PROGRAMBIN_DIR);  //
    WFile::makedir(PROGRAMCONF_DIR);  
	WFile::makedir(PROGRAMLIB_DIR);  
	WFile::makedir(PROGRAMLOG_DIR);  //
	
	//显示版本 
	char s[222];
	sprintf( s, "%s %s", gp_conf->m_strSysVer.c_str(), gp_conf->m_strSysVerInternal.c_str() ); 
	gp_ui->LineScrPrintA( s );


	sprintf( s1, "开始查找U盘 %s", szUDiskname ); 
	gp_ui->LineScrPrintA( s1 );


	if( IsOsWin() )
	{
		WThrd::tr_sleep(5);
		gp_ui->LineScrClearA();
		return 0;
	}


	for( int i = 0; i < 1000; i++ )
	{
		WThrd::tr_sleep(1);

		fl.bind( szUDiskname );
		if( fl.exists() )
		{
			sprintf( s1, "发现 %s", szUDiskname ); 
			gp_ui->LineScrPrintA( s1 );
			break;
		}
	}


	if( !fl.exists() )
	{
		gp_ui->LineScrClearA();
		return 0;
	}


	sprintf( s1, "发现 %s", szUDiskname ); 
	gp_ui->LineScrPrintA( s1 );

	sprintf( sCmd, "umount %s ", szUDiskname ); //可能已经自动挂载到某个目录，先卸载
	system( sCmd );
	WThrd::tr_sleep(1);
	sprintf( sCmd, "mount %s /mnt2", szUDiskname );
	rc = system( sCmd );
	sprintf( s1, "执行%s,结果%d", sCmd, rc );
	gp_ui->LineScrPrintA( s1 );

	//found shtvm 
	sprintf(s1,"/mnt2/%s",PROGRAM_NAME);
	fl.bind(s1);
	if( fl.exists() )
	{
		// copy sbsgui
		sprintf( sCmd, "cp -f /mnt2/sbsgui /work/sbsgui" );
		rc = system( sCmd );
		sprintf( s1, "执行%s,结果%d", sCmd, rc );
		gp_ui->LineScrPrintA( s1 );

		sprintf( s1, "发现 /mnt2/%s",PROGRAM_NAME ); 
		gp_ui->LineScrPrintA( s1 );

		// copy shtvm  shtvm.new
		sprintf( sCmd, "cp -f /mnt2/%s %s/%s.new",PROGRAM_NAME,PROGRAMBIN_DIR,PROGRAM_NAME );
		rc = system( sCmd );
		sprintf( s1, "执行%s,结果%d", sCmd, rc );
		gp_ui->LineScrPrintA( s1 );

		//backup to u disk.
		sprintf( sCmd, "cp -f %s/shtvm_config_a.txt /mnt2/confa_%d_%s",PROGRAMBIN_DIR ,(int)( gp_db->GetTheRowa3014().m_EqpNodecode4 ), SDte("").ReadStringPack14().c_str() );
		rc = system( sCmd );
		sprintf( sCmd, "cp -f %s/shtvm_config_b.txt /mnt2/confb_%d_%s", PROGRAMBIN_DIR,(int)( gp_db->GetTheRowa3014().m_EqpNodecode4 ), SDte("").ReadStringPack14().c_str() );
		rc = system( sCmd );

		sprintf( sCmd, "cp -f %s/Elis_BNR.conf /mnt2/Elis_BNR_%d_%s", PROGRAMCONF_DIR,(int)( gp_db->GetTheRowa3014().m_EqpNodecode4 ), SDte("").ReadStringPack14().c_str() );
		rc = system( sCmd );
		
        //copy lib
		if(is_dir_exist("/mnt2/lib/"))
		{
			sprintf( sCmd, "rm -f %s/*" ,PROGRAMLIB_DIR);
			rc = system( sCmd );

			
			sprintf( sCmd, "cp -f /mnt2/lib/* %s" ,PROGRAMLIB_DIR);
			rc = system( sCmd );
			sprintf( s1, "执行%s,结果%d", sCmd, rc );
		    gp_ui->LineScrPrintA( s1 );

			sprintf( sCmd, "rm -rf /mnt2/lib");
			rc = system( sCmd );
			
		}
		
		//found shtvm_config_a.txt
		fl.bind( "/mnt2/shtvm_config_a.txt" );
		if( fl.exists() )
		{
			// erase config
			sprintf( sCmd, "rm -f %s/shtvm_config_a.txt" ,PROGRAMBIN_DIR);
			rc = system( sCmd );

			// copy 1 config
			sprintf( sCmd, "cp -f /mnt2/shtvm_config_a.txt %s/shtvm_config_a.txt" ,PROGRAMBIN_DIR);
			rc = system( sCmd );
			sprintf( s1, "执行%s,结果%d", sCmd, rc );
			gp_ui->LineScrPrintA( s1 );

			// del the config
			sprintf( sCmd, "rm -f /mnt2/shtvm_config_a.txt" );
			rc = system( sCmd );
		}

		//found shtvm_config_b.txt
		fl.bind( "/mnt2/shtvm_config_b.txt" );
		if( fl.exists() )
		{
			// erase config
			sprintf( sCmd, "rm -f %s/shtvm_config_b.txt" ,PROGRAMBIN_DIR);
			rc = system( sCmd );

			// copy 1 config
			sprintf( sCmd, "cp -f /mnt2/shtvm_config_b.txt %s/shtvm_config_b.txt",PROGRAMBIN_DIR );
			rc = system( sCmd );
			sprintf( s1, "执行%s,结果%d", sCmd, rc );
			gp_ui->LineScrPrintA( s1 );

			// del the config
			sprintf( sCmd, "rm -f /mnt2/shtvm_config_b.txt" );
			rc = system( sCmd );
		}

		//found shtvm_config_a.txt
		fl.bind( "/mnt2/Elis_BNR.conf" );
		if( fl.exists() )
		{
			// erase config
			sprintf( sCmd, "rm -f %s/Elis_BNR.conf" ,PROGRAMCONF_DIR);
			rc = system( sCmd );

			// copy 1 config
			sprintf( sCmd, "cp -f /mnt2/Elis_BNR.conf %s/Elis_BNR.conf" ,PROGRAMCONF_DIR);
			rc = system( sCmd );
			sprintf( s1, "执行%s,结果%d", sCmd, rc );
			gp_ui->LineScrPrintA( s1 );

			// del the config
			sprintf( sCmd, "rm -f /mnt2/Elis_BNR.conf" );
			rc = system( sCmd );
		}
		//相当于只要用U盘更新，就把n个文件放在DOM上 
		if( !IsOsWin() ) 
		{
			sprintf( sCmd,"cp -f %s/%s.new /mnt/%s",PROGRAMBIN_DIR,PROGRAM_NAME,PROGRAM_NAME);
			system( sCmd ); //
			sprintf( sCmd,"cp -f %s/shtvm_config_a.txt /mnt/shtvm_config_a.txt",PROGRAMBIN_DIR);
			system( sCmd ); //
			sprintf( sCmd,"cp -f %s/shtvm_config_b.txt /mnt/shtvm_config_b.txt",PROGRAMBIN_DIR);
			system( sCmd ); // 
		}

		//found shtvm pic zip file 
		fl.bind( "/mnt2/tvmpic.zip" );
		if( fl.exists() )
		{
			sprintf( sCmd, "unzip -o -d %s /mnt2/tvmpic.zip", gp_conf->Get_path0().c_str() );
			sprintf( s1, "执行%s", sCmd );
			rc = system( sCmd );
			sprintf( s1, "执行%s,结果%d", sCmd, rc );
			gp_ui->LineScrPrintA( s1 );
		}

		//found reboot flag
		fl.bind( "/mnt2/rebootflag.txt" );
		if( fl.exists() )
		{
			sprintf( s1, "有标志：%s", fl.filename().c_str() );
			gp_ui->LineScrPrintA( s1 );

			//env_t::Plywvready();
			system("sync");
			if( IsOsWin() ) 
				gp_conf->m_biSysShouldExit = 1;
			if( !IsOsWin() ) 
				gp_conf->m_biSysShouldReboot = 1;
		}

	} //found k2 
	else
	{
		sprintf( s1, "未发现 /mnt2/%s",PROGRAM_NAME ); 
		gp_ui->LineScrPrintA( s1 );
	}


	system("sync");
	system("umount /mnt2");

	sprintf( s1, "现在应该拔除U盘" ); 
	gp_ui->LineScrPrintA( s1 );

	//env_t::Plywvready();

	for( ; ; )
	{
		fl.bind( szUDiskname );
		if( fl.exists() )
			WThrd::tr_sleep(1);
		else
			break;
	}

	WThrd::tr_sleep(1);

	sprintf( s1, "发现 %s 已拔除", szUDiskname ); 
	gp_ui->LineScrPrintA( s1 );

	//env_t::Plywvready();

	WThrd::tr_sleep(5);
	gp_ui->LineScrClearA();

	return 0;
}

int bu_backupg_t::is_dir_exist(const char* dir_path)
{
	DIR *dirptr = NULL;
	if(dir_path==NULL)
		return -1;
	dirptr=opendir(dir_path);
	if(dirptr==NULL)
		return -1;
	closedir(dirptr);
	return 1;
}


//
void backupg_go()
{
	wl::SStrf::newobjptr<bu_backupg_t>()->tr_openx();
}


