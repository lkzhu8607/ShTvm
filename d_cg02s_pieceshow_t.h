
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
	int		m_iPieceNum; // ——张数   
	ButtType_t	m_ButtType;

	int m_payed;	// 已付。单位（分） 
	int m_payed_coin;	// 已付。单位（分） 
	int m_payed_bill;	// 已付。单位（分） 
	int m_chg;		// 需找钱。单位（分） 
	int m_LastPayed;   //相对m_payed，记录一笔交易中上一次的投入总钱，为了实现投钱后重新记超时
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
	void ActiveCoinBill(); //激活硬币纸币接收	
	void StopCoinAndBill();  //关闭硬币纸币投币口，发现在析构函数中，有时不会自己关闭
	int FnD_ShowNewValue( std::string strinput , a_waiter_t_rowtype * pwaiterdata ); // 有事件，显示新值，首次要禁止价钮键盘 。0=无处理，1=钱已够 2=有投钱

};




#endif


