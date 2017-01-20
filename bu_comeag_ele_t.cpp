
#include "bu_comeag_ele_t.h"



//
bu_comeag_ele_t::bu_comeag_ele_t() 
{
}


//
bu_comeag_ele_t:: ~bu_comeag_ele_t()
{
	tr_destruct();
}



//
void bu_comeag_ele_t::tr_on_pre_thrd()
{
}



//
void bu_comeag_ele_t::tr_on_post_thrd()
{
}



// 
int bu_comeag_ele_t::tr_on_user_run()
{
	WNava nv1;
	WNava nv2;
	SCake ck;

	std::string		strCmd;
	std::string		strComId;
	std::string		strPrType; 
	std::string     strData;
	SCake			ckData;
	std::string     strTagPara;
	tbool	rc;

	m_tSvr.recv_ln( ck );

	if( ck.len() == 0 )
	{
		WThrd::tr_sleep( 0, 0.5 );
		return 0;
	}

	nv1.unserialize( ck.mk_str() );

	strCmd = nv1.get("cmd");
	strComId = nv1.get("id");
	strPrType = nv1.get("type");
	strData = nv1.get("data");
	ckData.UnSeri_S( strData );
	strTagPara = nv1.get("tag");

	if( strCmd == "conn" )
	{
		rc = m_Comelicell.Conn( nv1.get("id") );
		nv2.let( "rc", (int)rc );
		goto L_ELE_TASKEND;
	}
	
	if( strCmd == "close" )
	{
		rc = 1;
		m_Comelicell.DisConn();
		nv2.let( "rc", (int)rc );
		goto L_ELE_TASKEND;
	}

	if( strCmd == "send" )
	{
		if( strPrType == "PR_0203" )
		{
			rc = m_com_PR_0203.SendFrame( m_Comelicell, nv1, strData, ckData, strTagPara );
			nv2.let( "rc", (int)rc );
			goto L_ELE_TASKEND;
		}

		if( strPrType == "PR_LEN_AT_3" )
		{
			rc = m_com_PR_LEN_AT_3.SendFrame( m_Comelicell, nv1, strData, ckData, strTagPara );
			nv2.let( "rc", (int)rc );
			goto L_ELE_TASKEND;
		}

	}

	if( strCmd == "recv" )
	{
		if( strPrType == "PR_0203" )
		{
			rc = m_com_PR_0203.RecvFrame( m_Comelicell, nv1, strTagPara, ck );
			nv2.let( "rc", (int)rc );
			nv2.let( "data", ck.Seri_S() );
			goto L_ELE_TASKEND;
		}

		if( strPrType == "PR_LEN_AT_3" )
		{
			rc = m_com_PR_LEN_AT_3.RecvFrame( m_Comelicell, nv1, strTagPara, ck );
			nv2.let( "rc", (int)rc );
			nv2.let( "data", ck.Seri_S() );
			goto L_ELE_TASKEND;
		}

	}



	//
L_ELE_TASKEND:

	m_tSvr.send_str( nv2.serialize() + "\n" );

	return 1;
}



