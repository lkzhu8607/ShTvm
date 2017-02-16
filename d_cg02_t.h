
#ifndef K1__d_cg02_t_T_H
#define K1__d_cg02_t_T_H


#include "d_cg00_t.h"
#include "a_label_t.h"


//
class d_cg02_t : public d_cg00_t
{
public:
	int m_iPieceNum;
	int			m_iPrice;
	u8arr_t<4>  m_SelectedScNode;
	d_cg00_t  * m_pLastCg;
	std::vector<a_label_t::ROWTYPE> graphPieceNumCN;
	std::vector<a_label_t::ROWTYPE> graphPieceNumEN;
	int payedIndex;
	int shouldChangeIndex;
	//int coinIndex;
	int notesIndex;
	int disableDisplayFlag;
	int gobackFlag;//0,go back cg01;1,go back cg03
	//int exceptNoteIndex;	

public:
	d_cg02_t();
	virtual ~d_cg02_t();

public:
	virtual void Proc();

public:
	void cg02_graphElementsHide(int langFlag);
};


//
extern d_cg02_t  *plocalcg02;



#endif


