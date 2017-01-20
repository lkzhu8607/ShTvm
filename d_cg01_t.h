
#ifndef K1__d_cg01_t_T_H
#define K1__d_cg01_t_T_H


#include "d_cg00_t.h"
#include "a_label_t.h"


//
class d_cg01_t : public d_cg00_t
{
public:
	std::string  m_strInput;
	int		m_cg01s_linepic_MainUiIdx;
	int		m_cg01s_seleline_PageStartIdx;
	std::vector<a_label_t::ROWTYPE> graphLineButtonCN;
	std::vector<a_label_t::ROWTYPE> graphLineButtonEN;
	std::vector<a_label_t::ROWTYPE> graphFastButtonCN;
	std::vector<a_label_t::ROWTYPE> graphFastButtonEN;
	int pageFlag;// 1:next 0:prev
	
	int ErrCodeIndex;
	int MachineStateIndex;
	//int linePageSize = 0;
	int pageTab;	

public:
	d_cg01_t();
	virtual ~d_cg01_t();

public:
	virtual void Proc();

public:

};


//
extern d_cg01_t  *plocalcg01;



#endif


