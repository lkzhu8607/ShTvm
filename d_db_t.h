
#ifndef K1__d_db_t_T_H
#define K1__d_db_t_T_H


#include "2.h"
#include "a1040_t.h"
#include "a2000_t.h"
#include "a2001_t.h"
#include "a3000_t.h"
#include "a3001_t.h"
#include "a3002_t.h"
#include "a3003_t.h"
#include "a3006_t.h"
#include "a3007_t.h"
#include "a3008_t.h"
#include "a3009_t.h"
#include "a3011_t.h"
#include "a3014_t.h"
#include "a3082_t.h"
#include "a3083_t.h"
#include "a3084_t.h"
#include "a3085_t.h"
#include "a3086_t.h"
#include "a4001_t.h"
#include "a4002_t.h"
#include "a4003_t.h"
#include "a4004_t.h"
#include "a4006_t.h"
#include "a4007_t.h"
#include "a4008_t.h"
#include "a4009_t.h"
#include "a4015_t.h"
#include "a4016_t.h"
#include "a5041_t.h"
#include "a6000_t.h"
#include "a6002_t.h"

#include "a9999_t.h"
#include "b8701_t.h"
#include "b8702_t.h"
#include "b8703_t.h"
#include "b8704_t.h"
#include "b8705_t.h"
#include "b8706_t.h"
#include "b8707_t.h"
#include "b8708_t.h"

#include "a_waiter_t.h"



//
class d_db_t 
{
public:
	unitbl_t<a1040_t>		m_a1040;
	unitbl_t<a2000_t>		m_a2000;
	unitbl_t<a2001_t>		m_a2001;
	unitbl_t<a3000_t>		m_a3000;
	unitbl_t<a3001_t>		m_a3001;
	unitbl_t<a3002_t>		m_a3002;
	unitbl_t<a3003_t>		m_a3003;
	unitbl_t<a3006_t>		m_a3006;
	unitbl_t<a3007_t>		m_a3007;
	unitbl_t<a3008_t>		m_a3008;
	unitbl_t<a3009_t>		m_a3009;
	unitbl_t<a3011_t>		m_a3011;
	unitbl_t<a3014_t>		m_a3014;
	unitbl_t<a3082_t>		m_a3082;
	unitbl_t<a3083_t>		m_a3083;
	unitbl_t<a3084_t>		m_a3084;
	unitbl_t<a3085_t>		m_a3085;
	unitbl_t<a3086_t>		m_a3086;
	unitbl_t<a4001_t>		m_a4001;
	unitbl_t<a4002_t>		m_a4002;
	unitbl_t<a4003_t>		m_a4003;
	unitbl_t<a4004_t>		m_a4004;
	unitbl_t<a4006_t>		m_a4006;
	unitbl_t<a4007_t>		m_a4007;
	unitbl_t<a4008_t>		m_a4008;
	unitbl_t<a4009_t>		m_a4009;
	unitbl_t<a4015_t>		m_a4015;
	unitbl_t<a4016_t>		m_a4016;
	unitbl_t<a5041_t>		m_a5041;
	unitbl_t<a6000_t>		m_a6000;
	unitbl_t<a6002_t>		m_a6002;

	unitbl_t<a9999_t>		m_a9999;
	unitbl_t<b8701_t>		m_b8701;
	unitbl_t<b8702_t>		m_b8702;
	unitbl_t<b8703_t>		m_b8703;
	unitbl_t<b8704_t>		m_b8704;
	unitbl_t<b8705_t>		m_b8705;
	unitbl_t<b8706_t>		m_b8706;
	unitbl_t<b8707_t>		m_b8707;
	unitbl_t<b8708_t>		m_b8708;

	unitbl_t<a_waiter_t>    m_a_waiter_t;

public:
	WCrsc									m_DbMgrLck;
	std::map< std::string, std::string >	 m_mTbllSaveFlag[3]; // 库表的列表管理 - 不为empty即为dirty，表示需要存盘. 下标0 浪费掉。1和2表示2套存盘 
	std::map< std::string, unitbl_base_t* >	 m_mTbllPointer; //  库表的列表管理 - 所有库表指针 

public:
	d_db_t();
	virtual ~d_db_t();

public:
	a3014_t::ROWTYPE & GetTheRowa3014() { return this->m_a3014.GetRow(0); } 
	a5041_t::ROWTYPE & GetTheRowa5041() { return this->m_a5041.GetRow(0); } 
	a6000_t::ROWTYPE & GetTheRowa6000() { return this->m_a6000.GetRow(0); } 
	a9999_t::ROWTYPE & GetTheRowa9999() { return this->m_a9999.GetRow(0); }
	b8701_t::ROWTYPE & GetTheRowb8701() { return this->m_b8701.GetRow(0); }
	b8702_t::ROWTYPE & GetTheRowb8702() { return this->m_b8702.GetRow(0); }
	b8703_t::ROWTYPE & GetTheRowb8703() { return this->m_b8703.GetRow(0); }
	b8704_t::ROWTYPE & GetTheRowb8704() { return this->m_b8704.GetRow(0); }
	b8705_t::ROWTYPE & GetTheRowb8705() { return this->m_b8705.GetRow(0); }
	b8706_t::ROWTYPE & GetTheRowb8706() { return this->m_b8706.GetRow(0); }
	b8707_t::ROWTYPE & GetTheRowb8707() { return this->m_b8707.GetRow(0); }
	b8708_t::ROWTYPE & GetTheRowb8708() { return this->m_b8708.GetRow(0); }
	void LasyRiseSaveFlag_a5041( a5041_t::ROWTYPE R2);
	void LasyRiseSaveFlag_b8701( b8701_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8702( b8702_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8703( b8703_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8704( b8704_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8705( b8705_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8706( b8706_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8707( b8707_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_b8708( b8708_t::ROWTYPE R2 );
	void LasyRiseSaveFlag_a_waiter( a_waiter_t::ROWTYPE R2 );

	void LoadA9999K( std::string str9999k );
	void fLOADTBLFILE_a9999( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_a3014( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_a5041( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_a6000( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8701( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8702( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8703( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8704( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8705( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8706( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8707( WFile &fl, std::string &strDbSavePath );
	void fLOADTBLFILE_b8708( WFile &fl, std::string &strDbSavePath );

	void LoadDb();
	void SaveDb();

	void CleanDb();
	void CleanPara();
	void CleanParaProtect3014();

	void RiseSaveFlag( unitbl_base_t & tbl );
	void RiseAllSaveFlag();
	
	void get3083row( a3083_t::ROWTYPE &row3083out, tuint8 MainUiIdx );
	void get3083tbl( a3083_t &a3083tblout );
	std::string GetMyStaName();
	std::string GetThatStaName( u8arr_t<4> ScNode ); //只比较前两位,根据当前中英文设定，返回从参数中查到的中或英名称	
	tbool GetPossiblePrices( std::vector< int > & pricesout, u8arr_t<4> aCode = u8arr_t<4>() );
	void get3084tbl( a3084_t &a3084tblout );
	void get3084row( int iLineCode , a3084_t::ROWTYPE &row3084out );

	tuint32 GetSendConversationFlow();	//
	tuint32 GetTicketTradeTerminalFlow();	//

	int Get5041EvtCapacity(){ return 234;} 
};



//
extern d_db_t  *gp_db;





#endif


