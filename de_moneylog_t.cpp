
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
	//���ļ�
	m_front.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );

	//���ڴ�
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 0;	//���͡�0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();
}


//
void de_moneylog_t::BackRec( const std::string & ss )
{
	//���ļ�
	m_back.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );
	
	//���ڴ�
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 1;	//���͡�0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();
}

//
void de_moneylog_t::TwoRec( const std::string & ss )
{
	//����
	FrontRec( ss ); 
	BackRec( ss ); 
}


//
void de_moneylog_t::SheetRec( const std::string & ss )
{
	//����
	BackRec( ss ); 

	//���ļ�
	m_sheet.LogPrintStr( SDte::GetNow().Get_now_mtime() + "|" + ss );
	
	//���ڴ�
	b8601_t::ROWTYPE r;
	r.m_LogStr = ss;
	r.m_Type = 2;	//���͡�0=front,1=back,2=sheet 
	m_rec_sdb.Add( r );
	this->sdb_format();

	//��ӡ 
	gp_printer->PrintLineAsync( ss );
}


//
void de_moneylog_t::SheetCut()
{
	//����
	SheetRec( "SheetCut=================" );
	
	//��ӡ 
	gp_printer->HalfCutAsync();
}




