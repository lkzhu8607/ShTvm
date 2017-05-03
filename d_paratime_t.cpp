
#include "2.h"
#include "d_paratime_t.h"
#include "d_db_t.h"
#include "bu_quickflow_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "de_bill_t.h"


d_paratime_t * gp_paratime_t;

//
#define DETECT_AFFECT(tblname)	\
				do{	\
					MYAUTOLOCK( tblname.m_ut_tbl_lck );\
					if( GetPrepareAffectPk(tblname) != "" ) return 1;\
				}while(0)



//
d_paratime_t::d_paratime_t()
{
	m_iTakeAffectFlag = 0;
}

int d_paratime_t::tr_on_user_run()
{

	if( DetectAffect() )
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "DetectAffect" );
		TakeAffectAll();
	}

	MarkDel();
	Purge();

	wl::WThrd::tr_sleep(1,0.91);

	return 1;

}

// return 0-Not Affect  1-Affect
int d_paratime_t::TakeAffect_1(unitbl_base_t & tblname)
{
	do{	
		if(1)
		{
			MYAUTOLOCK( tblname.m_ut_tbl_lck );
			std::string s1=GetPrepareAffectPk(tblname) ;
			if( s1.empty() ) return 0;
			TakeAffect( tblname, s1 );
		}
		if( 1 )
		{
			MYAUTOLOCK( gp_db->m_DbMgrLck );
			std::string strTblName = tblname.ut_GetItemStr(-1,"strTblName");
			gp_db->m_mTbllSaveFlag[1][strTblName] = "aaa";
			gp_db->m_mTbllSaveFlag[2][strTblName] = "aaa";
		}
	}while(0);

	return 1;
}

//
std::string d_paratime_t::GetRowAffectPk( unitbl_base_t & tbl, long y )
{
	std::string s1,s2;
	
	s1 = tbl.ut_GetItemStr( y, "lVer" );
	s2 = tbl.ut_GetItemStr( y, "strAffectDateTime" );
	if( s2.empty() ) return "";
	s1 = s1 + s2;
	s1 = std::string((33-s1.size()),'0') + s1 ; 
	return s1;
}



//
std::string d_paratime_t::GetPrepareAffectPk( unitbl_base_t & tbl ) // 所有过去的且未生效的PK拿出来排序取最后一个。 如果没有待生效的，就会返回空串。 
{
	std::string s1;
	std::vector< std::string > vec1;
	SDte dtnow, dt2;

	dtnow.MakeNow();

	for( long y = 0; y < tbl.ut_GetRowAmount(); y++ )
	{
		if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" )
			continue;

		if( tbl.ut_GetItemStr( y, "biIsAffect" ) == "1" )
			continue;

		dt2.Make( tbl.ut_GetItemStr( y, "strAffectDateTime" ) );

		if( dtnow < dt2 ) //未来的版本，让过  
			continue;

		s1 = GetRowAffectPk( tbl, y );

		if( s1.empty() ) continue;

		vec1.push_back( s1 );
	}

	if( vec1.empty() )
		return "";
	
	std::sort( vec1.begin(), vec1.end() );

	return *vec1.rbegin();
}



//
void d_paratime_t::TakeAffect( unitbl_base_t & tbl, std::string strAffectPk ) // 小于的全删，等于的生效，大于的不管. 
{
	if(strAffectPk.empty())
		return;

	for( long y = 0; y < tbl.ut_GetRowAmount(); y++ )
	{
		std::string s1;

		if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" ) 
			continue;

		s1 = GetRowAffectPk( tbl, y );

		if( s1 == strAffectPk )
		{
			tbl.ut_SetItemByStr( y, "biIsAffect" , "1" );
		}
		else
		if( s1 < strAffectPk )
		{
			tbl.ut_SetItemByStr( y, "biIsAffect" , "0" );
			tbl.ut_SetItemByStr( y, "biDelFlag" , "1" );
		}
	}
}


//
void d_paratime_t::Purge1( unitbl_base_t & tbl, double dTimeLimit /*= 3.0*/ )
{
	std::map< std::string, std::string > mapDelFile; //利用其first值的唯一性，用来删除关联文件用。 可能因为时间关系提前跳出本循环，造成部分有删除标记的记录其关联文件已经删除。 
	bu_quickflow_t::qf_counter_t  iQf1;
	tbool biDelFlag = 0;
	unitbl_base_t & thetbl(tbl);
	
	if(1)
	{
		gp_qf->GetQf( iQf1 );
		MYAUTOLOCK( thetbl.m_ut_tbl_lck ); 

		for( int y = 0; y < thetbl.ut_GetRowAmount(); /*y++*/ )
		{
			if( thetbl.ut_GetItemStr( y, "biDelFlag" ) != "0" )
			{
				thetbl.ut_DelRowf(y);
				biDelFlag = 1;
				mapDelFile[ thetbl.ut_GetItemStr( y, "strDataRef" ) ] = "aa";
			}
			else
				y++;

			if( gp_qf->IsLongQf( iQf1, dTimeLimit ) ) break;
		}
	}

	if( biDelFlag == 1 )
	{
		thetbl.ut_ReIdx();

		MYAUTOLOCK( gp_db->m_DbMgrLck );

		std::string strTblName = thetbl.ut_GetItemStr(-1,"strTblName");

		//RiseSaveFlag
		gp_db->m_mTbllSaveFlag[1][strTblName] = "aaa";
		gp_db->m_mTbllSaveFlag[2][strTblName] = "aaa";

	}

	//del file(s)
	for( std::map< std::string, std::string >::iterator it = mapDelFile.begin(); it != mapDelFile.end(); ++it )
	{
		if( it->first != "" )
		{
			std::string s2;

			s2 = WFile::MkDir2Path( gp_conf->Get_dbsavepath1() ) + it->first;

			WFile::erase( s2 );
		}
	}
}



//分别检测 
//如果有需要生效的就返回1否则最后返回0 
tbool d_paratime_t::DetectAffect()
{
	//MYAUTOLOCK( gp_db->m_DbMgrLck );
	DETECT_AFFECT(gp_db->m_a1040);
	DETECT_AFFECT(gp_db->m_a2000);
	DETECT_AFFECT(gp_db->m_a2001);
	DETECT_AFFECT(gp_db->m_a3000);
	DETECT_AFFECT(gp_db->m_a3001);
	DETECT_AFFECT(gp_db->m_a3002);
	DETECT_AFFECT(gp_db->m_a3003);
	DETECT_AFFECT(gp_db->m_a3006);
	DETECT_AFFECT(gp_db->m_a3007);
	DETECT_AFFECT(gp_db->m_a3008);
	DETECT_AFFECT(gp_db->m_a3009);
	DETECT_AFFECT(gp_db->m_a3011);
	DETECT_AFFECT(gp_db->m_a3014);
	DETECT_AFFECT(gp_db->m_a3082);
	DETECT_AFFECT(gp_db->m_a3083);
	DETECT_AFFECT(gp_db->m_a3084);
	DETECT_AFFECT(gp_db->m_a3085);
	DETECT_AFFECT(gp_db->m_a3086);
	DETECT_AFFECT(gp_db->m_a4001);
	DETECT_AFFECT(gp_db->m_a4002);
	DETECT_AFFECT(gp_db->m_a4003);
	DETECT_AFFECT(gp_db->m_a4004);
	DETECT_AFFECT(gp_db->m_a4006);
	DETECT_AFFECT(gp_db->m_a4007);
	DETECT_AFFECT(gp_db->m_a4008);
	DETECT_AFFECT(gp_db->m_a4009);
	DETECT_AFFECT(gp_db->m_a4015);
	DETECT_AFFECT(gp_db->m_a4016);
	return 0;
}


//
void d_paratime_t::TakeAffectAll()
{
	int irc = 0;
	irc = TakeAffect_1(gp_db->m_a1040);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a1040=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a2000);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a2000=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a2001);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a2001=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3000);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3000=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3001);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3001=");
	irc = 0;
	if( TakeAffect_1(gp_db->m_a3002) )
	{
		m_iTakeAffectFlag = 1;

	}
	if( TakeAffect_1(gp_db->m_a3003) )
	{
		//更新3003后需要更新一下这些问题
		
		gp_db->m_b8702.GetRow(0).m_BillStopUseFlag = ( 0 == SStrf::readbit( gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0], 3 ) )?1:0;
		gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag = ( 0 == SStrf::readbit( gp_db->m_a3003.GetRow(0).m_WorkModeConf.a[0], 2 ) )?1:0;
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_BillStopUseFlag="<<gp_db->m_b8702.GetRow(0).m_BillStopUseFlag);
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "m_CoinStopUseFlag="<<gp_db->m_b8701.GetRow(0).m_CoinStopUseFlag);

	}

	irc = TakeAffect_1(gp_db->m_a3006);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3006=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3007);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3007=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3008);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3008=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3009);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3009=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3011);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3011=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3014);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3014=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a3082);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3082=");
	irc = 0;

	if( TakeAffect_1(gp_db->m_a3083) ||
		TakeAffect_1(gp_db->m_a3084) )
	{
		////copy 3086的位图
		//if( gp_db->m_a3086.GetRow(0).m_PkgDownloaded )
		//	Copy3086PicToSystemPath();
		
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a3084=");
	}

	TakeAffect_1(gp_db->m_a3085);
	TakeAffect_1(gp_db->m_a3086);
	irc = TakeAffect_1(gp_db->m_a4001);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4001=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4002);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4002=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4003);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4003=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4004);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4004=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4006);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4006=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4007);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4007=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4008);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4008=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4009);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4009=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4015);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4015=");
	irc = 0;
	irc = TakeAffect_1(gp_db->m_a4016);
	if( irc ) 
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "TakeAffect_1 m_a4016=");
	irc = 0;
}


//
void d_paratime_t::Purge()
{
	Purge1(gp_db->m_a1040);
	Purge1(gp_db->m_a2000);
	Purge1(gp_db->m_a2001);
	Purge1(gp_db->m_a3000);
	Purge1(gp_db->m_a3001);
	Purge1(gp_db->m_a3002);
	Purge1(gp_db->m_a3003);
	Purge1(gp_db->m_a3006);
	Purge1(gp_db->m_a3007);
	Purge1(gp_db->m_a3008);
	Purge1(gp_db->m_a3009);
	Purge1(gp_db->m_a3011);
	Purge1(gp_db->m_a3014);
	Purge1(gp_db->m_a3082);
	Purge1(gp_db->m_a3083);
	Purge1(gp_db->m_a3084);
	Purge1(gp_db->m_a3085);
	Purge1(gp_db->m_a3086);
	Purge1(gp_db->m_a4001);
	Purge1(gp_db->m_a4002);
	Purge1(gp_db->m_a4003);
	Purge1(gp_db->m_a4004);
	Purge1(gp_db->m_a4006);
	Purge1(gp_db->m_a4007);
	Purge1(gp_db->m_a4008);
	Purge1(gp_db->m_a4009);
	Purge1(gp_db->m_a4015);
	Purge1(gp_db->m_a4016);
	Purge1(gp_db->m_a6002);
}



//
void d_paratime_t::MarkDel()
{
	unitbl_base_t *ptbl;

	if(1)
	{
		ptbl = &gp_db->m_a3000;
		MYAUTOLOCK( ptbl->m_ut_tbl_lck );

		if( ptbl->ut_GetRowAmount() > 100 )
		{
			for( long y = 0; y < 100; y++ )
			{
				ptbl->ut_SetItemByStr( y, "biDelFlag" , "1" );
			}
		}
	}

	if(1)
	{
		ptbl = &gp_db->m_a3001;
		MYAUTOLOCK( ptbl->m_ut_tbl_lck );

		if( ptbl->ut_GetRowAmount() > 100 )
		{
			for( long y = 0; y < 100; y++ )
			{
				ptbl->ut_SetItemByStr( y, "biDelFlag" , "1" );
			}
		}
	}
	
	if(1)
	{
		ptbl = &gp_db->m_a6002;
		MYAUTOLOCK( ptbl->m_ut_tbl_lck );

		if( ptbl->ut_GetRowAmount() > ( 100000 * 15 ) )
		{
			for( long y = 0; y < 100; y++ )
			{
				ptbl->ut_SetItemByStr( y, "biDelFlag" , "1" );
			}
		}
	}
}


// 本函数有加锁。 
long d_paratime_t::GetParaCurrVer( unitbl_base_t & tbl )
{
	MYAUTOLOCK( tbl.m_ut_tbl_lck );
	
	for( long y = 0; y < tbl.ut_GetRowAmount(); y++ )
	{
		if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" )
			continue;

		if( tbl.ut_GetItemStr( y, "biIsAffect" ) != "1" )
			continue;

		return SStrf::satol( tbl.ut_GetItemStr( y, "lVer" ) );
		
	}

	return 0;
}


//
long d_paratime_t::GetParaCurrVer( tuint16 itype )
{
	if( itype == 0x1040 ) return GetParaCurrVer(gp_db->m_a1040);
	if( itype == 0x2000 ) return GetParaCurrVer(gp_db->m_a2000);
	if( itype == 0x2001 ) return GetParaCurrVer(gp_db->m_a2001);
	if( itype == 0x3000 ) return GetParaCurrVer(gp_db->m_a3000);
	if( itype == 0x3001 ) return GetParaCurrVer(gp_db->m_a3001);
	if( itype == 0x3002 ) return GetParaCurrVer(gp_db->m_a3002);
	if( itype == 0x3003 ) return GetParaCurrVer(gp_db->m_a3003);
	if( itype == 0x3006 ) return GetParaCurrVer(gp_db->m_a3006);
	if( itype == 0x3007 ) return GetParaCurrVer(gp_db->m_a3007);
	if( itype == 0x3008 ) return GetParaCurrVer(gp_db->m_a3008);
	if( itype == 0x3009 ) return GetParaCurrVer(gp_db->m_a3009);
	if( itype == 0x3011 ) return GetParaCurrVer(gp_db->m_a3011);
	if( itype == 0x3014 ) return GetParaCurrVer(gp_db->m_a3014);
	if( itype == 0x3082 ) return GetParaCurrVer(gp_db->m_a3082);
	if( itype == 0x3083 ) return GetParaCurrVer(gp_db->m_a3083);
	if( itype == 0x3084 ) return GetParaCurrVer(gp_db->m_a3084);
	if( itype == 0x3085 ) return GetParaCurrVer(gp_db->m_a3085);
	if( itype == 0x3086 ) return GetParaCurrVer(gp_db->m_a3086);
	if( itype == 0x4001 ) return GetParaCurrVer(gp_db->m_a4001);
	if( itype == 0x4002 ) return GetParaCurrVer(gp_db->m_a4002);
	if( itype == 0x4003 ) return GetParaCurrVer(gp_db->m_a4003);
	if( itype == 0x4004 ) return GetParaCurrVer(gp_db->m_a4004);
	if( itype == 0x4006 ) return GetParaCurrVer(gp_db->m_a4006);
	if( itype == 0x4007 ) return GetParaCurrVer(gp_db->m_a4007);
	if( itype == 0x4008 ) return GetParaCurrVer(gp_db->m_a4008);
	if( itype == 0x4009 ) return GetParaCurrVer(gp_db->m_a4009);
	if( itype == 0x4015 ) return GetParaCurrVer(gp_db->m_a4015);
	if( itype == 0x4016 ) return GetParaCurrVer(gp_db->m_a4016);
	return 0;
}



// 本函数有加锁。 
long d_paratime_t::GetParaNewVer( unitbl_base_t & tbl , long * plAffcGmtTime /*= NULL*/ )
{
	SDte dt1;

	dt1.MakeNow();

	MYAUTOLOCK( tbl.m_ut_tbl_lck );
	
	for( long y = 0; y < tbl.ut_GetRowAmount(); y++ )
	{
		if( tbl.ut_GetItemStr( y, "biDelFlag" ) == "1" )
			continue;

		if( tbl.ut_GetItemStr( y, "biIsAffect" ) == "1" )
			continue;
	
		SDte dt2;

		dt2.Make( tbl.ut_GetItemStr( y, "strAffectDateTime" ) );

		if( dt1< dt2 )
		{
			if(plAffcGmtTime) *plAffcGmtTime = (long)dt2.DiffSec(SDte("1970-1-1 0:0:0"));

			return SStrf::satol( tbl.ut_GetItemStr( y, "lVer" ) );
		}
	}

	return 0;
}


//
long d_paratime_t::GetParaNewVer( tuint16 itype , long * plAffcGmtTime /*= NULL*/ )
{
	if( itype == 0x1040 ) return GetParaNewVer(gp_db->m_a1040,plAffcGmtTime);
	if( itype == 0x2000 ) return GetParaNewVer(gp_db->m_a2000,plAffcGmtTime);
	if( itype == 0x2001 ) return GetParaNewVer(gp_db->m_a2001,plAffcGmtTime);
	if( itype == 0x3000 ) return GetParaNewVer(gp_db->m_a3000,plAffcGmtTime);
	if( itype == 0x3001 ) return GetParaNewVer(gp_db->m_a3001,plAffcGmtTime);
	if( itype == 0x3002 ) return GetParaNewVer(gp_db->m_a3002,plAffcGmtTime);
	if( itype == 0x3003 ) return GetParaNewVer(gp_db->m_a3003,plAffcGmtTime);
	if( itype == 0x3006 ) return GetParaNewVer(gp_db->m_a3006,plAffcGmtTime);
	if( itype == 0x3007 ) return GetParaNewVer(gp_db->m_a3007,plAffcGmtTime);
	if( itype == 0x3008 ) return GetParaNewVer(gp_db->m_a3008,plAffcGmtTime);
	if( itype == 0x3009 ) return GetParaNewVer(gp_db->m_a3009,plAffcGmtTime);
	if( itype == 0x3011 ) return GetParaNewVer(gp_db->m_a3011,plAffcGmtTime);
	if( itype == 0x3014 ) return GetParaNewVer(gp_db->m_a3014,plAffcGmtTime);
	if( itype == 0x3082 ) return GetParaNewVer(gp_db->m_a3082,plAffcGmtTime);
	if( itype == 0x3083 ) return GetParaNewVer(gp_db->m_a3083,plAffcGmtTime);
	if( itype == 0x3084 ) return GetParaNewVer(gp_db->m_a3084,plAffcGmtTime);
	if( itype == 0x3085 ) return GetParaNewVer(gp_db->m_a3085,plAffcGmtTime);
	if( itype == 0x3086 ) return GetParaNewVer(gp_db->m_a3086,plAffcGmtTime);
	if( itype == 0x4001 ) return GetParaNewVer(gp_db->m_a4001,plAffcGmtTime);
	if( itype == 0x4002 ) return GetParaNewVer(gp_db->m_a4002,plAffcGmtTime);
	if( itype == 0x4003 ) return GetParaNewVer(gp_db->m_a4003,plAffcGmtTime);
	if( itype == 0x4004 ) return GetParaNewVer(gp_db->m_a4004,plAffcGmtTime);
	if( itype == 0x4006 ) return GetParaNewVer(gp_db->m_a4006,plAffcGmtTime);
	if( itype == 0x4007 ) return GetParaNewVer(gp_db->m_a4007,plAffcGmtTime);
	if( itype == 0x4008 ) return GetParaNewVer(gp_db->m_a4008,plAffcGmtTime);
	if( itype == 0x4009 ) return GetParaNewVer(gp_db->m_a4009,plAffcGmtTime);
	if( itype == 0x4015 ) return GetParaNewVer(gp_db->m_a4015,plAffcGmtTime);
	if( itype == 0x4016 ) return GetParaNewVer(gp_db->m_a4016,plAffcGmtTime);
	return 0;
}




