
//
#include "2.h"
#include "de_moneylog_t.h"
#include "d_config_t.h"
#include "de_printer_t.h"


//
de_moneylog_t     *gp_moneylog;


//
de_moneylog_t::de_moneylog_t()
{
}


//
de_moneylog_t::~de_moneylog_t()
{
}


//
void de_moneylog_t::sdb_format()
{
	unitbl_base_t *ptbl;
	ptbl = &m_rec_sdb;
	MYAUTOLOCK( ptbl->m_ut_tbl_lck );

	m_rec_sdb.Save();

	if( ptbl->ut_GetRowAmount() > 50000 * 31 )
	{
		for( long y = 0; y < 1000; y++ )
		{
			ptbl->ut_DelRowf(y);
		}
		
		ptbl->ut_ReIdx();
	}
}


//
void de_moneylog_t::Init()
{
	m_front.Init(	gp_conf->Get_logpath6(), "FRONT",	15 );
	m_back.Init(	gp_conf->Get_logpath6(), "BACK",	15 );
	m_sheet.Init(	gp_conf->Get_logpath6(), "SHEET",	15 );
	 
	m_rec_sdb.InitSDB( "b8601", gp_conf->Get_logpath6() );
	m_rec_sdb.Load();
	this->sdb_format();
}


//
void de_moneylog_t::FrontRec( const std::string & ss )
{
	//存文件
	m_front.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );

	//存内存
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 0;	//类型。0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();
}


//
void de_moneylog_t::BackRec( const std::string & ss )
{
	//存文件
	m_back.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );
	
	//存内存
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 1;	//类型。0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();
}

//
void de_moneylog_t::TwoRec( const std::string & ss )
{
	//调用
	FrontRec( ss ); 
	BackRec( ss ); 
}


//
void de_moneylog_t::SheetRec( const std::string & ss )
{
	//调用
	BackRec( ss ); 

	//存文件
	m_sheet.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );
	
	//存内存
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 2;	//类型。0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();

	//打印 
	gp_printer->PrintLineAsync( ss );
}


//
void de_moneylog_t::SheetCut()
{
	//调用
	SheetRec( "SheetCut=================" );
	
	//打印 
	gp_printer->HalfCutAsync();
}




