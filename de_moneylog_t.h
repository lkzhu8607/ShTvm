
#ifndef K1_de_moneylog_t_H
#define K1_de_moneylog_t_H

#include "2.h"
#include "de_log_t.h"
#include "b8601_t.h"


//
class SDB2_t : public SDB_t<b8601_t>	
{
public:
	//
	virtual void OnLightFileSync()
	{
		if( !IsOsWin() )
			WFile::run_exe( "sync" );
	}

};



//=============

//  
class de_moneylog_t
{
private:
	void sdb_format();

public:
	de_log4_t  m_front;
	de_log4_t  m_back;
	de_log4_t  m_sheet;
	SDB2_t		m_rec_sdb;

public:
	de_moneylog_t();
	virtual ~de_moneylog_t();

public:
	void Init();
	void FrontRec( const std::string & ss );
	void BackRec( const std::string & ss );
	void TwoRec( const std::string & ss );
	void SheetRec( const std::string & ss );
	void SheetCut();
	 
};



//
extern de_moneylog_t     *gp_moneylog;



#endif



