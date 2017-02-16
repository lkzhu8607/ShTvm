
#include "2.h"
#include "d_db_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "d_str_res.h"
#include "de_medev_t.h"
#include "de_bill_t.h"



#define CLEANDBTBL(tblname)	\
				do{	\
					std::string strTblName = tblname.ut_GetItemStr(-1,"strTblName");\
					if(1)\
					{\
						MYAUTOLOCK( tblname.m_ut_tbl_lck );\
						tblname.ut_ClearTbl();\
					}\
					if(1)\
					{\
						MYAUTOLOCK( m_DbMgrLck );\
						m_mTbllSaveFlag[1][strTblName]="aa";\
						m_mTbllSaveFlag[2][strTblName]="aa";\
					}\
				}while(0)


#define LOADTBLFILE(tblname)	\
				do{	\
					CLEANDBTBL(tblname);\
					std::string strContent;\
					std::string strTblName = tblname.ut_GetItemStr(-1,"strTblName");\
					fl.bind( strDbSavePath + strTblName + ".txt" );\
					fl.read_str( strContent );\
					if(1)\
					{\
						MYAUTOLOCK( tblname.m_ut_tbl_lck );\
						tblname.ut_ClearTbl();\
						tblname.ut_UnseriTbl( strContent, 0 );\
					}\
					if(1)\
					{\
						MYAUTOLOCK( m_DbMgrLck );\
						m_mTbllPointer[strTblName] = &tblname;\
						m_mTbllSaveFlag[1][strTblName]="aa";\
						m_mTbllSaveFlag[2][strTblName]="aa";\
					}\
				}while(0)


#define SAVEDBTBL(t) \
	 			do{ \
 					unitbl_base_t * p2 = NULL; \
					std::string strTblName = t.ut_GetItemStr(-1,"strTblName");\
					MYAUTOLOCK( m_DbMgrLck );	/*DbMgrLck*/	\
					if( m_mTbllPointer.find(strTblName) != m_mTbllPointer.end() ){ \
 						MYAUTOLOCK( t.m_ut_tbl_lck ); \
						if( m_mTbllSaveFlag[i][strTblName].empty() ) break;\
 						p2 = t.ut_GetDup(); } \
					if( p2 == NULL ) break;\
 					fl.bind( strDbSavePath + strTblName + ".txt" );  \
 					fl.erase(); \
 					gp_conf->m_biDbDiskOk = p2->ut_SeriTbl(fl); \
					lf_save_readable(p2,fl);\
 					t.ut_DestroyDup(p2); \
					m_mTbllSaveFlag[i][strTblName].clear();\
 				}while(0)



//
d_db_t  *gp_db;



//
static void lf_save_readable( unitbl_base_t * p, std::string strFn )
{
	if( IsOsWin() )
	{
		std::string str2;
		WFile fl;
	
		fl.bind( strFn + ".text.txt" );

		for( int y = 0; y < p->ut_GetRowAmount(); y++ )
		{
			for( int x = 0; x < p->ut_GetColAmount(); x++ )
			{
				char ss[567];
				sprintf( ss, "%s=", p->ut_GetColName(x).c_str() );
				str2 += ss;
				str2 += p->ut_GetItemStr(y,x);
				str2 += ", ";
			}
			str2 += "\r\n";
		}

		fl.write_str( str2 );
	}
}



//
d_db_t::d_db_t()
{
}

//
d_db_t::~d_db_t()
{
}


////
//template < class T >
//void lf_LasyRiseSaveFlag_( T T2 )
//{
//	// 检测本表要不要存盘 
//	static T T1;
//	if( T1.Serialize() != T2.Serialize() )
//	{
//		T1 = T2;
//		gp_db->RiseSaveFlag(T2);
//	}
//}


//
void d_db_t::LasyRiseSaveFlag_a5041( a5041_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static a5041_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			gp_db->RiseSaveFlag(gp_db->m_a5041);
		}
	}
}

//
void d_db_t::LasyRiseSaveFlag_b8701( b8701_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8701_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			gp_db->RiseSaveFlag(gp_db->m_b8701);
		}
	}
}

//
void d_db_t::LasyRiseSaveFlag_b8702( b8702_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8702_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8702);
		}
	}
}


//
void d_db_t::LasyRiseSaveFlag_b8703( b8703_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8703_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8703);
		}
	}
}
//
void d_db_t::LasyRiseSaveFlag_b8704( b8704_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8704_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8704);
		}
	}
}

//
void d_db_t::LasyRiseSaveFlag_b8705( b8705_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8705_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8705);
		}
	}
}

//
void d_db_t::LasyRiseSaveFlag_b8706( b8706_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8706_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8706);
		}
	}
}


//
void d_db_t::LasyRiseSaveFlag_b8707( b8707_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8707_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8707);
		}
	}
}


//
void d_db_t::LasyRiseSaveFlag_b8708( b8708_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static b8708_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_b8708);
		}
	}
}

void d_db_t::LasyRiseSaveFlag_a_waiter( a_waiter_t::ROWTYPE R2 )
{
	//隔一段时间检测本表要不要存盘 
	if( SStrf::rand1() < 0.33 && time(0) % 6 == 0 )
	{
		static a_waiter_t::ROWTYPE R1;
		R1.m_strStampDateTime = R2.m_strStampDateTime;
		if( R1.Serialize() != R2.Serialize() )
		{
			R1 = R2;
			RiseSaveFlag(m_a_waiter_t);
		}
	}
}

//
void d_db_t::LoadA9999K( std::string str9999k )
{
	if( m_a9999.ut_GetItemStr( 0, str9999k + "_c" ) != gp_conf->getnvB(str9999k + "_c") )
	{
		m_a9999.ut_SetItemByStr( 0, str9999k + "_c" , gp_conf->getnvB(str9999k + "_c") );
		m_a9999.ut_SetItemByStr( 0, str9999k , gp_conf->getnvB(str9999k) );
	}
}


//
void d_db_t::fLOADTBLFILE_a9999( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_a9999);
	if( m_a9999.GetRowCount() == 0 )
	{
		MYAUTOLOCK( m_a9999.m_ut_tbl_lck );
		m_a9999.Add( a9999_t::ROWTYPE() );
	}
	LoadA9999K( "SendConversationFlow" );
	LoadA9999K( "TicketTradeTerminalFlow" );
}


#define A3014_NODE_COPY(a,b) a=b
//
void d_db_t::fLOADTBLFILE_a3014( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_a3014);
	if( m_a3014.GetRowCount() == 0 )
	{
		MYAUTOLOCK( m_a3014.m_ut_tbl_lck );
		m_a3014.Add( a3014_t::ROWTYPE() );
	}
 
	a3014_t::ROWTYPE &r( m_a3014.GetRow(0) );
	//unsigned char c1,c2,c3,c4;

	A3014_NODE_COPY( r.m_CcNode.a[0] , r.m_CCNodecode1 );
	A3014_NODE_COPY( r.m_CcNode.a[1] , r.m_CCNodecode2 );
	A3014_NODE_COPY( r.m_CcNode.a[2] , r.m_CCNodecode3 );
	A3014_NODE_COPY( r.m_CcNode.a[3] , r.m_CCNodecode4 );
	 
	A3014_NODE_COPY( r.m_ScNode.a[0] , r.m_SCNodecode1 );
	A3014_NODE_COPY( r.m_ScNode.a[1] , r.m_SCNodecode2 );
	A3014_NODE_COPY( r.m_ScNode.a[2] , r.m_SCNodecode3 );
	A3014_NODE_COPY( r.m_ScNode.a[3] , r.m_SCNodecode4 );

	A3014_NODE_COPY( r.m_EqpNode.a[0] , r.m_EqpNodecode1 );
	A3014_NODE_COPY( r.m_EqpNode.a[1] , r.m_EqpNodecode2 );
	A3014_NODE_COPY( r.m_EqpNode.a[2] , r.m_EqpNodecode3 );
	A3014_NODE_COPY( r.m_EqpNode.a[3] , r.m_EqpNodecode4 );
	
	A3014_NODE_COPY( r.m_EqpAddr.a[0] , r.m_EqpAddr1 );
	A3014_NODE_COPY( r.m_EqpAddr.a[1] , r.m_EqpAddr2 );
	A3014_NODE_COPY( r.m_EqpAddr.a[2] , r.m_EqpAddr3 );
	A3014_NODE_COPY( r.m_EqpAddr.a[3] , r.m_EqpAddr4 );
}


//在这里清除掉重启可以消除的错误码
void d_db_t::fLOADTBLFILE_a5041( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_a5041);
	if( m_a5041.GetRowCount() == 0 || m_a5041.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_a5041.m_ut_tbl_lck );
		m_a5041.Clear();
		m_a5041.Add( a5041_t::ROWTYPE() );
		//加默认值 
		a5041_t::ROWTYPE &row( m_a5041.GetRow(0) );
		row.m_s0.a[	0	] = 	1	;	//	//	开(1)/关(0)
		row.m_s0.a[	1	] = 	1	;	//	//	停止服务(1)/无故障(0)
		row.m_s0.a[	2	] = 	0	;	//	//	测试(1)/生产(0)
		row.m_s0.a[	3	] = 	0	;	//	//	纸币箱被取出(1)
		row.m_s0.a[	4	] = 	0	;	//	//	纸币箱将满(1)
		row.m_s0.a[	5	] = 	0	;	//	//	硬币箱被取出(1)
		row.m_s0.a[	6	] = 	0	;	//	//	硬币箱将满(1)
		row.m_s0.a[	7	] = 	0	;	//	//	硬币找零少(1)
	
		row.m_s1.a[	0	] = 	0	;	//		门开(1)
		row.m_s1.a[	1	] = 	0	;	//		门被开锁(1)
		row.m_s1.a[	2	] = 	0	;	//		票少(1)
		row.m_s1.a[	3	] = 	0	;	//		纸币找零少(1)
		row.m_s1.a[	4	] = 	0	;	//		无找零模式(1)/找零模式(0)
		row.m_s1.a[	5	] = 	0	;	//		钱箱未锁定(1)
		row.m_s1.a[	6	] = 	0	;	//		维护键盘通信故障(1)
		row.m_s1.a[	7	] = 	0	;	//		[保留]

		row.m_e = a5041_t::ROWTYPE().m_e; //事件全清0 
	}
	
	a5041_t::ROWTYPE &row2( m_a5041.GetRow(0) );

	//清除事件错误码
	row2.m_e_old = a5041_t::ROWTYPE().m_e_old;
	row2.m_e = a5041_t::ROWTYPE().m_e;
	////4和71处理
	//row2.m_e_old.a[4 ] = 0;
	//row2.m_e.    a[4 ] = 0;
	//row2.m_e_old.a[71] = 0;
	//row2.m_e.    a[71] = 0;

	////179 和 180 处理
	//row2.m_e_old.a[179 ] = 0;
	//row2.m_e.    a[179 ] = 0;
	//row2.m_e_old.a[180 ] = 0;
	//row2.m_e.    a[180 ] = 0;

	//所有事件都没发生过:
	row2.m_e_flag = a5041_t::ROWTYPE().m_e_flag; //事件flag
}


//
void d_db_t::fLOADTBLFILE_a6000( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_a6000);
	if( m_a6000.GetRowCount() == 0 || m_a6000.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_a6000.m_ut_tbl_lck );
		m_a6000.Clear();
		m_a6000.Add( a6000_t::ROWTYPE() );
	}
}


//
void d_db_t::fLOADTBLFILE_b8701( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8701);
	if( m_b8701.GetRowCount() == 0 || m_b8701.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8701.m_ut_tbl_lck );
		m_b8701.Clear();
		m_b8701.Add( b8701_t::ROWTYPE() );
	}
}


//
void d_db_t::fLOADTBLFILE_b8702( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8702);
	if( m_b8702.GetRowCount() == 0 || m_b8702.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8702.m_ut_tbl_lck );
		m_b8702.Clear();
		m_b8702.Add( b8702_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8703( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8703);
	if( m_b8703.GetRowCount() == 0 || m_b8703.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8703.m_ut_tbl_lck );
		m_b8703.Clear();
		m_b8703.Add( b8703_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8704( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8704);
	if( m_b8704.GetRowCount() == 0 || m_b8704.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8704.m_ut_tbl_lck );
		m_b8704.Clear();
		m_b8704.Add( b8704_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8705( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8705);
	if( m_b8705.GetRowCount() == 0 || m_b8705.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8705.m_ut_tbl_lck );
		m_b8705.Clear();
		m_b8705.Add( b8705_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8706( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8706);
	if( m_b8706.GetRowCount() == 0 || m_b8706.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8706.m_ut_tbl_lck );
		m_b8706.Clear();
		m_b8706.Add( b8706_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8707( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8707);
	if( m_b8707.GetRowCount() == 0 || m_b8707.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8707.m_ut_tbl_lck );
		m_b8707.Clear();
		m_b8707.Add( b8707_t::ROWTYPE() );
	}
}

//
void d_db_t::fLOADTBLFILE_b8708( WFile &fl, std::string &strDbSavePath )
{
	LOADTBLFILE(m_b8708);
	if( m_b8708.GetRowCount() == 0 || m_b8708.GetRowCount() > 1 )
	{
		MYAUTOLOCK( m_b8708.m_ut_tbl_lck );
		m_b8708.Clear();
		m_b8708.Add( b8708_t::ROWTYPE() );
	}
}

//
void d_db_t::LoadDb()
{
	WFile fl;
	std::string strDbSavePath;

	strDbSavePath = WFile::MkDir2Path( gp_conf->Get_dbsavepath1() );
	fl.bind( strDbSavePath + "light.txt" );
	if( !fl.exists() )
		strDbSavePath = WFile::MkDir2Path( gp_conf->Get_dbsavepath2() );


	fLOADTBLFILE_a9999( fl, strDbSavePath );
	fLOADTBLFILE_b8701( fl, strDbSavePath );
	fLOADTBLFILE_b8702( fl, strDbSavePath );
	fLOADTBLFILE_b8703( fl, strDbSavePath );
	fLOADTBLFILE_b8704( fl, strDbSavePath );
	fLOADTBLFILE_b8705( fl, strDbSavePath );
	fLOADTBLFILE_b8706( fl, strDbSavePath );
	fLOADTBLFILE_b8707( fl, strDbSavePath );
	fLOADTBLFILE_b8708( fl, strDbSavePath );	//	return;

	LOADTBLFILE(m_a1040);
	LOADTBLFILE(m_a2000);
	LOADTBLFILE(m_a2001);
	LOADTBLFILE(m_a3000);
	LOADTBLFILE(m_a3001);
	LOADTBLFILE(m_a3002);
	LOADTBLFILE(m_a3003);
	LOADTBLFILE(m_a3006);
	LOADTBLFILE(m_a3007);
	LOADTBLFILE(m_a3008);
	LOADTBLFILE(m_a3009);
	LOADTBLFILE(m_a3011);
	fLOADTBLFILE_a3014( fl, strDbSavePath );
	LOADTBLFILE(m_a3082);
	LOADTBLFILE(m_a3083);
	LOADTBLFILE(m_a3084);
	LOADTBLFILE(m_a3085);
	LOADTBLFILE(m_a3086);
	LOADTBLFILE(m_a4001);
	LOADTBLFILE(m_a4002);
	LOADTBLFILE(m_a4003);
	LOADTBLFILE(m_a4004);
	LOADTBLFILE(m_a4006);
	LOADTBLFILE(m_a4007);
	LOADTBLFILE(m_a4008);
	LOADTBLFILE(m_a4009);
	LOADTBLFILE(m_a4015);
	LOADTBLFILE(m_a4016);
	fLOADTBLFILE_a5041( fl, strDbSavePath );
	fLOADTBLFILE_a6000( fl, strDbSavePath );
	LOADTBLFILE(m_a6002);


	LOADTBLFILE(m_a_waiter_t);
}
	


//
void d_db_t::SaveDb()
{
	WFile fl;
	std::string strDbSavePath;
	
	for( int i = 1; i <= 2; i++ )
	{
		if( i == 1 ) strDbSavePath = WFile::MkDir2Path( gp_conf->Get_dbsavepath1() );
		if( i == 2 ) strDbSavePath = WFile::MkDir2Path( gp_conf->Get_dbsavepath2() );

		//turn off light 
		fl.bind( strDbSavePath + "light.txt" );
		fl.erase();
		if( !gp_conf->IsOsWin() )
			WFile::run_exe( "sync" );

		//save 
		SAVEDBTBL(m_a9999);
		SAVEDBTBL(m_b8701);
		SAVEDBTBL(m_b8702);
		SAVEDBTBL(m_b8703);
		SAVEDBTBL(m_b8704);
		SAVEDBTBL(m_b8705);
		SAVEDBTBL(m_b8706);
		SAVEDBTBL(m_b8707);
		SAVEDBTBL(m_b8708);

		SAVEDBTBL(m_a1040);
		SAVEDBTBL(m_a2000);
		SAVEDBTBL(m_a2001);
		SAVEDBTBL(m_a3000);
		SAVEDBTBL(m_a3001);
		SAVEDBTBL(m_a3002);
		SAVEDBTBL(m_a3003);
		SAVEDBTBL(m_a3006);
		SAVEDBTBL(m_a3007);
		SAVEDBTBL(m_a3008);
		SAVEDBTBL(m_a3009);
		SAVEDBTBL(m_a3011);
		SAVEDBTBL(m_a3014);
		SAVEDBTBL(m_a3082);
		SAVEDBTBL(m_a3083);
		SAVEDBTBL(m_a3084);
		SAVEDBTBL(m_a3085);
		SAVEDBTBL(m_a3086);
		SAVEDBTBL(m_a4001);
		SAVEDBTBL(m_a4002);
		SAVEDBTBL(m_a4003);
		SAVEDBTBL(m_a4004);
		SAVEDBTBL(m_a4006);
		SAVEDBTBL(m_a4007);
		SAVEDBTBL(m_a4008);
		SAVEDBTBL(m_a4009);
		SAVEDBTBL(m_a4015);
		SAVEDBTBL(m_a4016);
		SAVEDBTBL(m_a5041);
		SAVEDBTBL(m_a6000);
		SAVEDBTBL(m_a6002);

		SAVEDBTBL(m_a_waiter_t);

	
		//turn on light 
		fl.bind( strDbSavePath + "light.txt" );
		fl.write_str( SDte::GetNow().ReadString() );
		if( !gp_conf->IsOsWin() )
			WFile::run_exe( "sync" );
	}

}



//
void d_db_t::CleanDb()
{
	for( std::map< std::string, unitbl_base_t* > ::iterator it = m_mTbllPointer.begin(); it != m_mTbllPointer.end(); ++it )
	{
		unitbl_base_t* p = it->second;
		unitbl_base_t &t(*p);

		CLEANDBTBL(t);
	}

	this->SaveDb();
	this->LoadDb();
	this->SaveDb();
}



//
void d_db_t::CleanPara()
{
	CLEANDBTBL(m_a1040);
	CLEANDBTBL(m_a2000);
	CLEANDBTBL(m_a2001);
	CLEANDBTBL(m_a3000);
	CLEANDBTBL(m_a3001);
	CLEANDBTBL(m_a3002);
	CLEANDBTBL(m_a3003);
	CLEANDBTBL(m_a3006);
	CLEANDBTBL(m_a3007);
	CLEANDBTBL(m_a3008);
	CLEANDBTBL(m_a3009);
	CLEANDBTBL(m_a3011);
	  CLEANDBTBL(m_a3014); 
	CLEANDBTBL(m_a3082);
	CLEANDBTBL(m_a3083);
	CLEANDBTBL(m_a3084);
	CLEANDBTBL(m_a3085);
	CLEANDBTBL(m_a3086);
	CLEANDBTBL(m_a4001);
	CLEANDBTBL(m_a4002);
	CLEANDBTBL(m_a4003);
	CLEANDBTBL(m_a4004);
	CLEANDBTBL(m_a4006);
	CLEANDBTBL(m_a4007);
	CLEANDBTBL(m_a4008);
	CLEANDBTBL(m_a4009);
	CLEANDBTBL(m_a4015);
	CLEANDBTBL(m_a4016);
	CLEANDBTBL(m_a5041);
	CLEANDBTBL(m_a6000);
	CLEANDBTBL(m_a6002);

		CLEANDBTBL(m_b8701);
		CLEANDBTBL(m_b8702);
		CLEANDBTBL(m_b8703);
		CLEANDBTBL(m_b8704);
		CLEANDBTBL(m_b8705);
		CLEANDBTBL(m_b8706);
		CLEANDBTBL(m_b8707);
		CLEANDBTBL(m_b8708);

	CLEANDBTBL(m_a9999);

	CLEANDBTBL(m_a_waiter_t);

	this->SaveDb();
	this->LoadDb();
	this->SaveDb();
}



//
void d_db_t::CleanParaProtect3014()
{
	CLEANDBTBL(m_a1040);
	CLEANDBTBL(m_a2000);
	CLEANDBTBL(m_a2001);
	CLEANDBTBL(m_a3000);
	CLEANDBTBL(m_a3001);
	CLEANDBTBL(m_a3002);
	CLEANDBTBL(m_a3003);
	CLEANDBTBL(m_a3006);
	CLEANDBTBL(m_a3007);
	CLEANDBTBL(m_a3008);
	CLEANDBTBL(m_a3009);
	CLEANDBTBL(m_a3011);
	//CLEANDBTBL(m_a3014);
	CLEANDBTBL(m_a3082);
	CLEANDBTBL(m_a3083);
	CLEANDBTBL(m_a3084);
	CLEANDBTBL(m_a3085);
	CLEANDBTBL(m_a3086);
	CLEANDBTBL(m_a4001);
	CLEANDBTBL(m_a4002);
	CLEANDBTBL(m_a4003);
	CLEANDBTBL(m_a4004);
	CLEANDBTBL(m_a4006);
	CLEANDBTBL(m_a4007);
	CLEANDBTBL(m_a4008);
	CLEANDBTBL(m_a4009);
	CLEANDBTBL(m_a4015);
	CLEANDBTBL(m_a4016);
	CLEANDBTBL(m_a5041);
	CLEANDBTBL(m_a6000);
	CLEANDBTBL(m_a6002);

		CLEANDBTBL(m_b8701);
		CLEANDBTBL(m_b8702);
		CLEANDBTBL(m_b8703);
		CLEANDBTBL(m_b8704);
		CLEANDBTBL(m_b8705);
	CLEANDBTBL(m_a9999);
	CLEANDBTBL(m_a_waiter_t);

	this->SaveDb();
	this->LoadDb();
	this->SaveDb();
}


//
void d_db_t::RiseSaveFlag( unitbl_base_t & tbl )
{
		std::string strTblName = tbl.ut_GetItemStr(-1,"strTblName");
		MYAUTOLOCK( m_DbMgrLck );
		m_mTbllSaveFlag[1][strTblName]="aa";
		m_mTbllSaveFlag[2][strTblName]="aa";
}


//
void d_db_t::RiseAllSaveFlag()
{
		RiseSaveFlag(m_a9999);
		RiseSaveFlag(m_b8701);
		RiseSaveFlag(m_b8702);
		RiseSaveFlag(m_b8703);
		RiseSaveFlag(m_b8704);
		RiseSaveFlag(m_b8705);

		RiseSaveFlag(m_a1040);
		RiseSaveFlag(m_a2000);
		RiseSaveFlag(m_a2001);
		RiseSaveFlag(m_a3000);
		RiseSaveFlag(m_a3001);
		RiseSaveFlag(m_a3002);
		RiseSaveFlag(m_a3003);
		RiseSaveFlag(m_a3006);
		RiseSaveFlag(m_a3007);
		RiseSaveFlag(m_a3008);
		RiseSaveFlag(m_a3009);
		RiseSaveFlag(m_a3011);
		RiseSaveFlag(m_a3014);
		RiseSaveFlag(m_a3082);
		RiseSaveFlag(m_a3083);
		RiseSaveFlag(m_a3084);
		RiseSaveFlag(m_a3085);
		RiseSaveFlag(m_a3086);
		RiseSaveFlag(m_a4001);
		RiseSaveFlag(m_a4002);
		RiseSaveFlag(m_a4003);
		RiseSaveFlag(m_a4004);
		RiseSaveFlag(m_a4006);
		RiseSaveFlag(m_a4007);
		RiseSaveFlag(m_a4008);
		RiseSaveFlag(m_a4009);
		RiseSaveFlag(m_a4015);
		RiseSaveFlag(m_a4016);
		RiseSaveFlag(m_a5041);
		RiseSaveFlag(m_a6000);
		RiseSaveFlag(m_a6002);

		RiseSaveFlag(m_a_waiter_t);
}


//
void d_db_t::get3083row( a3083_t::ROWTYPE &row3083out, tuint8 MainUiIdx )
{
	a3083_t::RPSTYPE rps[9];

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a3083.m_ut_tbl_lck );

		row3083out = a3083_t::ROWTYPE();

		gp_db->m_a3083.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a3083.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a3083.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a3083.GetRowCount( rps[3] ) == 0 ) return;

		gp_db->m_a3083.SelEc_MainUiIdx( MainUiIdx, rps[1] );
		gp_db->m_a3083.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a3083.GetRowCount( rps[4] ) == 0 ) return;

		row3083out = gp_db->m_a3083.GetRow( rps[4], 0 );
	}
}


//
std::string d_db_t::GetMyStaName()
{
	a3014_t::ROWTYPE r3014;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a3014.m_ut_tbl_lck );
		
		r3014 = this->m_a3014.GetRow(0);
	}

	return this->GetThatStaName( r3014.m_ScNode );
}


//  
std::string d_db_t::GetThatStaName( u8arr_t<4> ScNode )
{
	a3006_t::ROWTYPE r3006;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a3006.m_ut_tbl_lck );
		
		for( long i = 0; i < gp_db->m_a3006.GetRowCount(); i++ )
		{
			a3006_t::ROWTYPE & row(gp_db->m_a3006.GetRow(i));

			if( row.m_biDelFlag != 0 ) continue;
			if( row.m_biIsAffect != 1 ) continue;

			if( row.m_StaNode.a[0] == ScNode.a[0] && row.m_StaNode.a[1] == ScNode.a[1] )
			{
				r3006 = row;
				break;
			}
		}
	}

	if( GetLanguageState() == 1 ) return r3006.m_strStaNameEn;

	a3011_t::RPSTYPE rps[9];
	std::string s3 ;
			
	if(1)
	{
		MYAUTOLOCK( gp_db->m_a3011.m_ut_tbl_lck );

		gp_db->m_a3011.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a3011.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a3011.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a3011.GetRowCount( rps[3] ) == 0 ) return "";

		gp_db->m_a3011.SelEc_lResPointer( r3006.m_lStaNameCh, rps[1] );
		gp_db->m_a3011.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a3011.GetRowCount( rps[4] ) == 0 ) return "";

		s3 = gp_db->m_a3011.GetRow( rps[4], 0 ).m_strResBlockOri;
		
		if( !gp_conf->IsOsWin() && !s3.empty() )
		{
			WFile::ChtoUtf8( s3 );
		}

		return s3;
	}

	return "";
}

std::string d_db_t::GetVaildNotesType(int iShouldPayAmount){
	//b8701_t::ROWTYPE & Rb8701(gp_db->GetTheRowb8701());
	b8702_t::ROWTYPE & Rb8702(gp_db->GetTheRowb8702());
	std::string strVal;
	if( Rb8702.m_ConnState == 1 && 
		Rb8702.m_BigErr == 0 && 
		Rb8702.m_BillStopUseFlag == 0  &&
		gp_medev->m_devstatus != 5	)
	{
		//a_label_t::ROWTYPE  row;
		if(GetLanguageState() == 0)
		{
			strVal = "5元 10元 20元 50元";
			//gp_ui->LabelMkStr( row, 0, GETLABELNAME, strVal, gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
			if( gp_bill->m_iIsNotBillChange == 1 )
			{
				if( 5000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "5元 10元 20元 50元";
				}
				else if( 2000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "5元 10元 20元";
				}
				else if( 1000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "5元 10元";
				}
				else if( 500 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "5元";
				}
				//gp_ui->LabelMkStr( row, 0, GETLABELNAME, strVal, gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
			}			
		
		}
		else
		{
			strVal = "￥5 ￥10 ￥20 ￥50";
			//gp_ui->LabelMkStr( row, 0, GETLABELNAME, strVal, gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
			if( gp_bill->m_iIsNotBillChange == 1 )
			{
				if( 5000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "￥5 ￥10 ￥20 ￥50";
				}
				else if( 2000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "￥5 ￥10 ￥20";
				}
				else if( 1000 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "￥5 ￥10";
				}
				else if( 500 - iShouldPayAmount - gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum*100 <= 0 )
				{
					strVal = "￥5";
				}
				//gp_ui->LabelMkStr( row, 0, GETLABELNAME, strVal, gp_ui->X2dR( 0, 377 ), gp_ui->Y2dR( 0, 710 ), 0.05, "black" );
			}				
		}
	}
	return strVal;
}



//
tbool d_db_t::GetPossiblePrices( std::vector< int > & pricesout , u8arr_t<4> aCode /*= u8arr_t<4>()*/ )
{
	a3014_t::ROWTYPE  my_r3014;

	pricesout.clear();

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a3014.m_ut_tbl_lck );
		
		my_r3014 = this->m_a3014.GetRow(0);
	}

	//求出row4002
	a4002_t::ROWTYPE  row4002;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4002.m_ut_tbl_lck );
		a4002_t::RPSTYPE rps[9];

		//row4002_out = a4002_t::ROWTYPE();

		gp_db->m_a4002.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a4002.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a4002.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a4002.GetRowCount( rps[3] ) == 0 ) return 0;

		gp_db->m_a4002.SelEc_TicketType( 100, rps[1] );
		gp_db->m_a4002.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a4002.GetRowCount( rps[4] ) == 0 ) return 0;

		row4002 = gp_db->m_a4002.GetRow( rps[4], 0 );
	}

	//求出row4003
	a4003_t::ROWTYPE  row4003;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4003.m_ut_tbl_lck );
		a4003_t::RPSTYPE rps[9];

		gp_db->m_a4003.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a4003.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a4003.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a4003.GetRowCount( rps[3] ) == 0 ) return 0;

		gp_db->m_a4003.SelEc_lFareRateIdx( row4002.m_B0_FullFareRateIdx, rps[1] );
		gp_db->m_a4003.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a4003.GetRowCount( rps[4] ) == 0 ) return 0;

		row4003 = gp_db->m_a4003.GetRow( rps[4], 0 );
	}

	//遍历4004，根据zone求出4003中的价格,再group
	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4004.m_ut_tbl_lck );
		
		for( long i = 0; i < gp_db->m_a4004.GetRowCount(); i++ )
		{
			int z;
			a4004_t::ROWTYPE & row4004(gp_db->m_a4004.GetRow(i));

			if( row4004.m_biDelFlag != 0 ) continue;
			if( row4004.m_biIsAffect != 1 ) continue;

			if( aCode == u8arr_t<4>() )
			{
				z = row4003.m_FareRate.a[row4004.m_lZone] / 100;
				pricesout.push_back(z);
			}
			else
			{
				if( my_r3014.m_ScNode.a[0] == row4004.m_ANode.a[0] && 
					my_r3014.m_ScNode.a[1] == row4004.m_ANode.a[1] && 
					aCode.a[0] == row4004.m_BNode.a[0] &&
					aCode.a[1] == row4004.m_BNode.a[1]		)
				{
					z = row4003.m_FareRate.a[row4004.m_lZone] / 100;
					pricesout.push_back(z);
				}
			}

			//pricesout.insert( pricesout.begin(), row4003.m_FareRate.a, row4003.m_FareRate.a + 64 );
		}

		SSetu::vs_setgroup(pricesout);
	}

	return  pricesout.empty() ? 0 : 1;
}


//
void d_db_t::get3084tbl( a3084_t &a3084tblout )
{
	MYAUTOLOCK( gp_db->m_a3084.m_ut_tbl_lck );
	
	for( long i = 0; i < this->m_a3084.GetRowCount(); i++ )
	{
		a3084_t::ROWTYPE &row(this->m_a3084.GetRow(i));

		if( row.m_biDelFlag != 0 ) continue;
		if( row.m_biIsAffect != 1 ) continue;

		a3084tblout.Add(row);
	}
}

void d_db_t::get3083tbl( a3083_t &a3083tblout )
{
	MYAUTOLOCK( gp_db->m_a3083.m_ut_tbl_lck );
	
	for( long i = 0; i < this->m_a3083.GetRowCount(); i++ )
	{
		a3083_t::ROWTYPE &row(this->m_a3083.GetRow(i));

		if( row.m_biDelFlag != 0 ) continue;
		if( row.m_biIsAffect != 1 ) continue;

		a3083tblout.Add(row);
	}
}


//
void d_db_t::get3084row( int iLineCode , a3084_t::ROWTYPE &row3084out )
{
	MYAUTOLOCK( gp_db->m_a3084.m_ut_tbl_lck );
	
	row3084out = a3084_t::ROWTYPE();
	for( long i = 0; i < this->m_a3084.GetRowCount(); i++ )
	{
		a3084_t::ROWTYPE &row(this->m_a3084.GetRow(i));

		if( row.m_biDelFlag != 0 ) continue;
		if( row.m_biIsAffect != 1 ) continue;
		if( row.m_LineCode != iLineCode ) continue;

		row3084out = row;
	}
}


//
tuint32 d_db_t::GetSendConversationFlow()
{
	tuint32 j;
	if(1)
	{
		MYAUTOLOCK(this->m_a9999.m_ut_tbl_lck);
		tuint32 & l(this->m_a9999.GetRow(0).m_SendConversationFlow);
		l++;
		l &= 0x7FffFFff;
		j = l;
	}
	this->RiseSaveFlag( this->m_a9999 );
	return j;
}



//
tuint32 d_db_t::GetTicketTradeTerminalFlow()
{
	tuint32 j;
	if(1)
	{
		MYAUTOLOCK(this->m_a9999.m_ut_tbl_lck);
		tuint32 & l(this->m_a9999.GetRow(0).m_TicketTradeTerminalFlow);
		l++;
		//l &= 0x7FffFFff;
		j = l;
	}
	this->RiseSaveFlag( this->m_a9999 );
	return j;
}



