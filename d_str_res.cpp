
#include "2.h"
#include "d_str_res.h"



//
static std::map< int, std::string > v_mCh;
static std::map< int, std::string > v_mEn;
static int m_LanguageCh0En1;


//
void SetLanguageCh()
{
	m_LanguageCh0En1 = 0;
}


//
void SetLanguageEn()
{
	m_LanguageCh0En1 = 1;
}

//
int GetLanguageState()
{
	return m_LanguageCh0En1;
}


//
const char * GetStrRes( int idx )
{
	if( !v_mCh.empty() )
	{
		if( m_LanguageCh0En1 == 0 ) return v_mCh[idx].c_str();
		else return v_mEn[idx].c_str();
	}


	//用excel粘贴进来

	v_mCh[2]="哈罗";v_mEn[2]="hello";
	v_mCh[3]="正常售票";v_mEn[3]="In Service";
	v_mCh[4]="暂停服务";v_mEn[4]="Out Of Service";
	v_mCh[5]="只收硬币";v_mEn[5]="Coin Only";
	v_mCh[6]="只收纸币";v_mEn[6]="Note Only";
	v_mCh[7]="暂停服务";v_mEn[7]="Out Of Service";
	v_mCh[8]="无纸币找零";v_mEn[8]="No Bill Change";

	//为了故障暂停显示字
	v_mCh[11]="票卡已售完";v_mEn[11]="No Ticket";
	v_mCh[12]="暂停售票";v_mEn[12]="Out Of Service";
	v_mCh[13]="系统未被初始化";v_mEn[13]="System No Init";

	SetLanguageCh();
	return GetStrRes(idx);
}




