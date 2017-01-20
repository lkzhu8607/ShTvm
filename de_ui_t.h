
#ifndef K1_de_ui_t_H
#define K1_de_ui_t_H


#include "2.h"
#include "a_label_t.h"


//
typedef  a_label_t::ROWTYPE * UiTaskType_t;


//  
class de_ui_t : public WIdleThrd< UiTaskType_t >  
{
private:
	a_label_t	m_lblset;
	a_label_t   m_lbl_sholdshow;

public:
	de_ui_t();
	virtual ~de_ui_t();

public:
	tbool MyInit();

	double GetStrWidth( const char *p, double dSize );
	int Get_scr_width( int scrnum );
	int Get_scr_height( int scrnum );
	int Get_scr_startx( int scrnum );
	int Get_scr_starty( int scrnum );

	static std::string PicPFn( std::string strFn );	//	为文件名加上前缀路径	
	static void CalcPicX2Y2( a_label_t::ROWTYPE & row_out );	//	calc x2 and y2	
	static double X2d( int scrnum, long X );	// x to double, use config width	
	static double Y2d( int scrnum, long Y );
	static double X2dR( int scrnum, long X );	//x to double, use real width	
	static double Y2dR( int scrnum, long Y );

	static tbool Parse_KIN_MOUSEBUTT1( const std::string &s1, int &scr, double &x, double &y );
	

	void LabelPrep( const a_label_t::ROWTYPE & row );
	void LabelCommit();
	void LabelInvisible();
	void LabelInvisible(a_label_t &lblset);
	void LabelFixedHide();
	void LabelFixedShow();

	void LabelMkStr( a_label_t::ROWTYPE & rowout, int scrnum, std::string strName, std::string strVal, double x, double y, double dSize = 0.1, std::string strColor = "red" );
	void LabelMkStrPrep( int scrnum, std::string strName, std::string strVal, double x, double y, double dSize = 0.1, std::string strColor = "red" );
	void LabelMkPic( a_label_t::ROWTYPE & rowout, int scrnum, std::string strName, std::string strVal, double x, double y, double pic_width = 0, double pic_height = 0 );
	void LabelMkPicPrep( int scrnum, std::string strName, std::string strVal, double x, double y, double pic_width = 0, double pic_height = 0 );
	void LabelMkDelPrep( std::string strName );


	void LineScrPrint( int scrnum, const std::string & strLine, tbool HaveCommit = 1 );
	void LineScrClear( int scrnum, tbool HaveCommit = 1 );
	void LineScrPrintA( const std::string & strLine );
	void LineScrPrintA( int i );
	void LineScrClearA();

	void str_task( a_label_t::ROWTYPE & row );
	void pic_task( a_label_t::ROWTYPE & row );
	void del_task( a_label_t::ROWTYPE & row, long i );

	virtual void OnRunTask( UiTaskType_t t );
	void updateLabel( a_label_t::ROWTYPE & row, std::string value);
	void showLabel( a_label_t::ROWTYPE & row );
	void hideLabel( a_label_t::ROWTYPE & row );

};


//
extern de_ui_t     *gp_ui;



#endif


