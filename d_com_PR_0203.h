
#ifndef K1__d_com_PR_0203_T_H
#define K1__d_com_PR_0203_T_H


#include "2.h"
#include "d_comv_t.h"



//
class d_com_PR_0203 : public WComeliProtocol 
{
public:

public:
	d_com_PR_0203();
	virtual ~d_com_PR_0203(){};

public:
	tbool SendFrame( WComeliCell &Comelicell, WNava &nv1, std::string &strData, SCake &ckData, std::string &strTagPara );
	tbool RecvFrame( WComeliCell &Comelicell, WNava &nv1, const std::string &strTagPara, SCake &ck_out );

};






#endif


