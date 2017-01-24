
#ifndef K1__d_cg02s_pieceshow_t_T_H
#define K1__d_cg02s_pieceshow_t_T_H


#include "d_cg00_t.h"
#include "d_cg00s_t.h"
#include "a_label_t.h"
#include "a_waiter_t.h"


//
class d_cg02s_pieceshow_t : public d_cg00s_t
{
public:
	enum ButtType_t { UP, DOWN, DISABLE };
	int		m_iPieceNum; // ��������   
	ButtType_t	m_ButtType;

	int m_payed;	// �Ѹ�����λ���֣� 
	int m_payed_coin;	// �Ѹ�����λ���֣� 
	int m_payed_bill;	// �Ѹ�����λ���֣� 
	int m_chg;		// ����Ǯ����λ���֣� 
	int m_LastPayed;   //���m_payed����¼һ�ʽ�������һ�ε�Ͷ����Ǯ��Ϊ��ʵ��ͶǮ�����¼ǳ�ʱ
	int disableDisplayFlag;

public:
	d_cg02s_pieceshow_t();
	virtual ~d_cg02s_pieceshow_t();

public:
	void Show1PieceButt( int i );
	void ShowPieceButtBoard();
	void ShowPieceInfo();
	tbool Find_n_do_ShowAllPieceNum( std::string strinput );
	void ShowPayednchg();
	void ActiveCoinBill(); //����Ӳ��ֽ�ҽ���	
	void StopCoinAndBill();  //�ر�Ӳ��ֽ��Ͷ�ҿڣ����������������У���ʱ�����Լ��ر�
	int FnD_ShowNewValue( std::string strinput , a_waiter_t_rowtype * pwaiterdata ); // ���¼�����ʾ��ֵ���״�Ҫ��ֹ��ť���� ��0=�޴���1=Ǯ�ѹ� 2=��ͶǮ

};




#endif


