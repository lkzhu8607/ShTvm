
#include "2.h"

#ifdef WINENV_
#pragma warning(disable: 4312)
#pragma warning(disable: 4996)
#endif
#include "gtk/gtk.h"

#include "g06.h"
#include "de_ui_t.h"
#include "d_config_t.h"
#include "de_frontinput_t.h"
#include "de_backinput_t.h"
#include "d_str_res.h"
#include "bu_asynwork_t.h"
#include "de_ui_t.xpp"


//
de_ui_t     *gp_ui;


//
de_ui_t::de_ui_t()
{
	m_lblset.Clear();
}


//
de_ui_t::~de_ui_t()
{
}


//
tbool de_ui_t::MyInit()
{
	SimpForm *p = new SimpForm;

	p->tr_openx();

	do{
		WThrd::tr_sleepu( 0.35 );
	}while( m_iUiInitReady != 1 );

	WThrd::tr_sleepu( 0.35 );

	return 1;
}


//
double de_ui_t::GetStrWidth( const char *p, double dSize )
{
	double widthcount = 0.0;

	for( std::string::size_type i = 0; p && p[i]; i++ )
	{
		if( (wl::tuint8)p[i] > '~' ) widthcount += gp_conf->IsOsWin() ? 0.5 : 0.344;
		else widthcount += 0.5;
	}
	
	return widthcount * dSize;
}

// 
int de_ui_t::Get_scr_width( int scrnum )
{
	return m_scr_width[scrnum];
}

//
int de_ui_t::Get_scr_height( int scrnum )
{
	return m_scr_height[scrnum];
}

// 
int de_ui_t::Get_scr_startx( int scrnum )
{
	return m_scr_startx[scrnum];
}

//
int de_ui_t::Get_scr_starty( int scrnum )
{
	return m_scr_starty[scrnum];
}



//
std::string de_ui_t::PicPFn( std::string strFn )
{
	return WFile::MkDir2Path( gp_conf->Get_datapath3() ) + strFn;
}


//
void de_ui_t::CalcPicX2Y2( a_label_t::ROWTYPE & row_inout )
{
	if( row_inout.m_type == "pic" )
	{
		std::string sVal;
		double x2,y2;

		sVal = row_inout.m_value;
		x2 = row_inout.m_pic_width * gp_ui->Get_scr_width(row_inout.m_scr);
		y2 = row_inout.m_pic_height * gp_ui->Get_scr_height(row_inout.m_scr);

		if( gp_conf->IsOsWin() )
		{
			WFile::ChtoUtf8( sVal );
		}
		
		if( x2 < 3 && y2 < 3 )
		{
			//按原始大 
			GdkPixbuf *pixbuf;
				
			pixbuf = gdk_pixbuf_new_from_file( sVal.c_str(), NULL );
			row_inout.m_x2 = (double)gdk_pixbuf_get_width(pixbuf) / (double)gp_ui->Get_scr_width(row_inout.m_scr) + row_inout.m_x;
			row_inout.m_y2 = (double)gdk_pixbuf_get_height(pixbuf) / (double)gp_ui->Get_scr_height(row_inout.m_scr) + row_inout.m_y;
			gdk_pixbuf_unref(pixbuf);
		}
		else
		{
			row_inout.m_x2 = row_inout.m_pic_width + row_inout.m_x;
			row_inout.m_y2 = row_inout.m_pic_height + row_inout.m_y;
		}
	}
}


//
double de_ui_t::X2d( int scrnum, long X )
{
	return (double)X / (double)gp_ui->Get_scr_width(scrnum);
}

//
double de_ui_t::Y2d( int scrnum, long Y )
{
	return (double)Y / (double)gp_ui->Get_scr_height(scrnum);
}



//
double de_ui_t::X2dR( int scrnum, long X )
{
	if( scrnum == 0 )
		return (double)X / 1280.0;
	else
		return (double)X / 640.0;
}

//
double de_ui_t::Y2dR( int scrnum, long Y )
{
	if( scrnum == 0 )
		return (double)Y / 1024.0;
	else
		return (double)Y / 480.0;
}


//
tbool de_ui_t::Parse_KIN_MOUSEBUTT1( const std::string &s1, int &scr, double &x, double &y )
{
	std::vector< std::string > v1;

	if( s1[0] != KIN_MOUSEBUTT1 ) return 0;
	SStrvs::vsa_imp( s1, std::string(","), 1, v1 );
	if( v1[0][0] == KIN_MOUSEBUTT1 ) v1[0][0] = ' '; else return 0;
	v1.push_back(""); v1.push_back(""); v1.push_back("");
	x = SStrf::satof(v1[0]);
	y = SStrf::satof(v1[1]);
	scr = SStrf::satol(v1[2]);
	return 1;
}


//
void de_ui_t::LabelPrep( const a_label_t::ROWTYPE & row )
{
	a_label_t::ROWTYPE *p = new a_label_t::ROWTYPE;

	*p = row;
	p->m_ds =  
					p->GetColStr<std::string>("scr") + 
					p->GetColStr<std::string>("name") + 
					p->GetColStr<std::string>("type") + 
					p->GetColStr<std::string>("value") + 
					p->GetColStr<std::string>("x") + 
					p->GetColStr<std::string>("y") + 
					p->GetColStr<std::string>("font_size") + 
					p->GetColStr<std::string>("font_color") +		
					p->GetColStr<std::string>("font_desc") +		
					p->GetColStr<std::string>("font_align") +		
					p->GetColStr<std::string>("pic_width") +		
					p->GetColStr<std::string>("pic_height") ;	

	this->PostTask( p, 0, 0 );
	//m_lbl_sholdshow.Add(row);
}


//
void de_ui_t::LabelCommit()
{
	a_label_t::ROWTYPE *p = new a_label_t::ROWTYPE;
	p->m_type = "update";
	
	//if( gp_conf->IsOsWin() )
		this->PostTask( p, 0 );
	//else
		//this->PostTask( p, SStrf::rand1() < 0.05 ? 1 : 0 );
}

void de_ui_t::LabelInvisible()
{	
	if(m_lbl_sholdshow.GetRowCount()){
		gdk_threads_enter();
		for( long i = 0; i < m_lbl_sholdshow.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row(m_lbl_sholdshow.GetRow(i));
		
			//if( row.m_iShouldShow == 1 ) continue;
		
			//gdk_threads_enter();
			gtk_widget_hide( (GtkWidget *)row.m_gtkpointer );
			row.m_iShouldShow = 1;
		}
		gdk_threads_leave();
		m_lbl_sholdshow.Clear();
	}

}

void de_ui_t::LabelFixedHide()
{
	gdk_threads_enter();
	gtk_widget_hide( m_fixed );
	gdk_threads_leave();
	return;
}

void de_ui_t::LabelFixedShow()
{
	gdk_threads_enter();
	gtk_widget_show( m_fixed );
	gdk_threads_leave();
	return;
}


void de_ui_t::LabelInvisible(a_label_t &lblset)
{	
	if(lblset.GetRowCount()){
		gdk_threads_enter();
		for( long i = 0; i < lblset.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row(lblset.GetRow(i));
		
			//if( row.m_iShouldShow == 1 ) continue;
		
			//gdk_threads_enter();
			gtk_widget_hide( (GtkWidget *)row.m_gtkpointer );
			//row.m_iShouldShow = 1;
		}
		gdk_threads_leave();
		//lblset.Clear();
	}

}



//
void de_ui_t::LabelMkStr( a_label_t::ROWTYPE & rowout, int scrnum, std::string strName, std::string strVal, double x, double y, double dSize /*= 0.1*/, std::string strColor /*= "red"*/ )
{
	a_label_t::ROWTYPE &r(rowout);

	r.m_scr = (scrnum == 0 ? 0 : 1);
	r.m_name = strName;
	r.m_type = "str";
	r.m_value = strVal;
	r.m_x = x;
	r.m_y = y;
	r.m_font_size = dSize;
	r.m_font_color = strColor;
}


//
void de_ui_t::LabelMkStrPrep( int scrnum, std::string strName, std::string strVal, double x, double y, double dSize /*= 0.1*/, std::string strColor /*= "red"*/ )
{
	a_label_t::ROWTYPE r;

	r.m_scr = (scrnum == 0 ? 0 : 1);
	r.m_name = strName;
	r.m_type = "str";
	r.m_value = strVal;
	r.m_x = x;
	r.m_y = y;
	r.m_font_size = dSize;
	r.m_font_color = strColor;
	
	LabelPrep( r );
}



//
void de_ui_t::LabelMkPic( a_label_t::ROWTYPE & rowout, int scrnum, std::string strName, std::string strVal, double x, double y, double pic_width /*= 0*/, double pic_height /*= 0*/ )
{
	a_label_t::ROWTYPE &r(rowout);

	r.m_scr = (scrnum == 0 ? 0 : 1);
	r.m_name = strName;
	r.m_type = "pic";
	r.m_value = strVal;
	r.m_x = x;
	r.m_y = y;
	r.m_pic_width = pic_width;
	r.m_pic_height = pic_height;
}


//
void de_ui_t::LabelMkPicPrep( int scrnum, std::string strName, std::string strVal, double x, double y, double pic_width /*= 0*/, double pic_height /*= 0*/ )
{
	a_label_t::ROWTYPE r;

	r.m_scr = (scrnum == 0 ? 0 : 1);
	r.m_name = strName;
	r.m_type = "pic";
	r.m_value = strVal;
	r.m_x = x;
	r.m_y = y;
	r.m_pic_width = pic_width;
	r.m_pic_height = pic_height;

	LabelPrep( r );
}


//
void de_ui_t::LabelMkDelPrep( std::string strName )
{
	a_label_t::ROWTYPE r;

	r.m_name = strName;
	r.m_type = "del";

	LabelPrep( r );
}



//
static std::vector< std::string > v_lines[2];
static size_t v_iMax[2] = {20,15};

//
void de_ui_t::LineScrPrint( int scrnum, const std::string & strLine, tbool HaveCommit /*= 1*/ )
{
	//WThrd::tr_sleep( 2 );
	double x, y , fontsize;

	if( scrnum == 0 )
	{
		x = 0.1;
		y = 0.1;
		fontsize = 0.0465;
	}
	else
	{
		x = 0.01;
		y = 0.01;
		fontsize = 0.04;
	}

	v_lines[scrnum].push_back( strLine );

	while( v_lines[scrnum].size() > v_iMax[scrnum] )
		v_lines[scrnum].erase( v_lines[scrnum].begin() );

	for( size_t i = 0; i < v_lines[scrnum].size(); i++ )
	{
		a_label_t::ROWTYPE  row;

		this->LabelMkStr( row, scrnum, 
							SStrf::sltoa((int)scrnum) + "#OutLine#" + SStrf::sltoa((int)i),
							v_lines[scrnum][i],
							x, y + fontsize * i, fontsize, "brown" ); //也可以用LabelMkStrPrep 
		this->LabelPrep(row);
		//if( HaveCommit ) this->showLabel(row);
	}
	
	if( HaveCommit ) this->LabelCommit();
	//if( HaveCommit ) this->showLabel(row);
}


//
void de_ui_t::LineScrClear( int scrnum, tbool HaveCommit /*= 1*/ )
{
	for( size_t i = 0; i < v_lines[scrnum].size(); i++ )
	{
		this->LabelMkDelPrep( SStrf::sltoa((int)scrnum) + "#OutLine#" + SStrf::sltoa((int)i) );
	}
	
	if( HaveCommit ) this->LabelCommit();
	v_lines[scrnum].clear();
}

//
void de_ui_t::LineScrPrintA( const std::string & strLine )
{
	LineScrPrint( 0, strLine, 0 );
	LineScrPrint( 1, strLine );
}

//
void de_ui_t::LineScrPrintA( int i )
{
	LineScrPrintA( SStrf::sltoa(i) );
}

//
void de_ui_t::LineScrClearA()
{
	LineScrClear( 0, 0 );
	LineScrClear( 1 );
}




std::vector< GtkWidget * > aaa;

//
void str_label_del( GtkWidget * lbl )
{
	aaa.push_back( (GtkWidget *)lbl );
	//gtk_widget_hide( (GtkWidget *)lbl ); 
}

//
GtkWidget * str_label_new( tbool & is_old_rc )
{
	GtkWidget * lbl;

	if( aaa.empty() )
	{
		lbl = gtk_label_new("aa");
		is_old_rc = 0;
	}
	else
	{
		lbl = (GtkWidget *)(*aaa.rbegin());
		aaa.pop_back();
		is_old_rc = 1;
	}

	return lbl;
}


//
void de_ui_t::str_task( a_label_t::ROWTYPE & row )
{
	double x, y;
	std::string sVal;
	std::string  sSize;
	std::string s3;
	GtkWidget  *lblTest;
	tbool is_old_rc(0);

	//sSize = SStrf::sftoa( row.m_font_size * 260 * m_scr_width[row.m_scr] / 800.01 ); // 原来的是以1为基准的字体，现在求出GTK要求的字体大小 
	sSize = SStrf::sftoa( row.m_font_size * 260 * m_scr_width[0] / 800.01 ); // 原来的是以1为基准的字体，现在求出GTK要求的字体大小 只以主屏为准 

	sVal = row.m_value;
	wl::SStrf::sreplstr( sVal, "<", "&lt;" );
	wl::SStrf::sreplstr( sVal, ">", "&gt;" );

	if( row.m_iNewModiFlag == 1 ) // a modi label
	{
		if(row.m_gtkpointer != NULL)
		{
			gdk_threads_enter();
			gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
//g_object_unref( G_OBJECT( row.m_gtkpointer ) );
			//str_label_del( (GtkWidget *)row.m_gtkpointer );
			gdk_threads_leave();

			row.m_gtkpointer = NULL;
		}
		row.m_iNewModiFlag = 0; // del its resources and mark it as new lbl.
	}

	if( row.m_iNewModiFlag == 0 ) // a new label
	{
		x = row.m_x;
		y = row.m_y ;
		if( row.m_font_align == 1 ) //指定中线的居中 
		{
			x -= GetStrWidth( sVal.c_str(), row.m_font_size ) / 2 / 2;
			if( x < 0 ) x = 0.0;
		}

		gdk_threads_enter();
		lblTest = gtk_label_new("aa");
		//lblTest = (GtkWidget *)str_label_new( is_old_rc );
		gdk_threads_leave();

		s3  = "<span" ;

		s3 += " font_family='黑体' foreground='" + row.m_font_color + "'";
		s3 += " font_desc='黑体 bold " + sSize + "'";

		//s3 += "   foreground='" + row.m_font_color + "'";
		//s3 += " font_desc=' bold " + sSize + "'";

		s3 += ">" + sVal + "</span>";

		if( gp_conf->IsOsWin() )
		{
			WFile::ChtoUtf8( s3 );
		}

		gdk_threads_enter();
		gtk_label_set_markup( GTK_LABEL(lblTest), s3.c_str() );
		gdk_threads_leave();

		if( is_old_rc )
		{
			gdk_threads_enter();
			gtk_fixed_move( GTK_FIXED(m_fixed), lblTest, (int)( x * m_scr_width[row.m_scr] ) + m_scr_startx[row.m_scr] , (int)( y * m_scr_height[row.m_scr] ) + m_scr_starty[row.m_scr] );
			gdk_threads_leave();
		}
		else
		{
			gdk_threads_enter();
			gtk_fixed_put( GTK_FIXED(m_fixed), lblTest, (int)( x * m_scr_width[row.m_scr] ) + m_scr_startx[row.m_scr] , (int)( y * m_scr_height[row.m_scr] ) + m_scr_starty[row.m_scr] );
			gdk_threads_leave();
		}


		//gdk_threads_enter();
		//gtk_widget_show(lblTest);// //先不显示 
		//gdk_threads_leave();
		if(row.m_gtkpointer != NULL){
			gdk_threads_enter();
			gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
			gdk_threads_leave();
		}
		row.m_gtkpointer = lblTest;
	}
}


//
void de_ui_t::pic_task( a_label_t::ROWTYPE & row )
{
	double x, y;
	std::string sVal;
	GtkWidget  *lblTest;
	wl::WFile fl;
	double x2,y2;

	sVal = row.m_value;
		
	fl.bind(sVal);

	if( !fl.exists() ) return; //未来改为显示字串 
		
	x2 = row.m_pic_width * m_scr_width[row.m_scr];
	y2 = row.m_pic_height * m_scr_height[row.m_scr];

	if( row.m_iNewModiFlag == 1 ) // a modi label
	{
		if(row.m_gtkpointer != NULL)
		{
			gdk_threads_enter();
			gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
			gdk_threads_leave();

			row.m_gtkpointer = NULL;
		}
		row.m_iNewModiFlag = 0; // del its resources and mark it as new lbl.
	}

	if( row.m_iNewModiFlag == 0 ) // a new label
	{
		x = row.m_x;
		y = row.m_y ;

		//get a new lblTest
		if( gp_conf->IsOsWin() )
		{
			WFile::ChtoUtf8( sVal );
		}

		if( x2 < 3 && y2 < 3 )
		{
			//use orginal picture
			gdk_threads_enter();
			lblTest  = gtk_image_new_from_file(sVal.c_str());
			gdk_threads_leave();

			//GdkPixbuf *pixbuf;
			//*   width = gdk_pixbuf_get_width (pixbuf);
			//*   height = gdk_pixbuf_get_height (pixbuf);
			//int           gdk_pixbuf_get_height          (const GdkPixbuf *pixbuf);
		}
		else
		{
			GdkPixbuf *pixbuf;
			GdkPixbuf *pixbuf2;

			gdk_threads_enter();

			pixbuf = gdk_pixbuf_new_from_file( sVal.c_str(), NULL );
			pixbuf2 = gdk_pixbuf_scale_simple( pixbuf, (int)x2, (int)y2, GDK_INTERP_BILINEAR );
			gdk_pixbuf_unref(pixbuf);
			//g_object_unref(pixbuf2);
			lblTest = gtk_image_new_from_pixbuf( pixbuf2 );
			gdk_pixbuf_unref(pixbuf2);
			//g_object_unref(pixbuf2);
//g_object_unref(pixbuf2);

			gdk_threads_leave();
		}

		gdk_threads_enter();
		gtk_fixed_put( GTK_FIXED(m_fixed), lblTest, (int)( x * m_scr_width[row.m_scr] ) + m_scr_startx[row.m_scr] , (int)( y * m_scr_height[row.m_scr] ) + m_scr_starty[row.m_scr] );
		gdk_threads_leave();
		if(row.m_gtkpointer != NULL){
			gdk_threads_enter();
			gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
			gdk_threads_leave();
		}
		row.m_gtkpointer = lblTest;

	}
}


//
void de_ui_t::del_task( a_label_t::ROWTYPE & row, long i )
{
	//a_label_t::ROWTYPE *p = new a_label_t::ROWTYPE;
	//
	//*p = row;
	//p->m_type = "del-delay"; //delay del maybe

	//this->PostTask( p, 0, 0 );

	if(row.m_gtkpointer != NULL)
	{
		gdk_threads_enter();
		gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
		gdk_threads_leave();
	}

	m_lblset.Del(i);
}



//
void de_ui_t::OnRunTask( UiTaskType_t t ) 
{
	//goto L_TASKEND;

	/*if( t->m_type == "update" )
	{
		/*for( long i =  m_lblset.GetRowCount() - 1; i >= 0; i-- )
		{
			a_label_t::ROWTYPE & row(m_lblset.GetRow(i));

			//del
			if( row.m_type == "del" || row.m_type == "delall" || row.m_type == "modifyall" || row.m_type == "update" || row.m_type == "refresh" )
			{
				del_task(row, i);

				continue;
			}
		}*/

		/*for( long i = 0; i < m_lblset.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row(m_lblset.GetRow(i));

			//del
			/*if( row.m_type == "del" || row.m_type == "delall" || row.m_type == "modifyall" || row.m_type == "update" || row.m_type == "refresh" )
			{
				del_task(row, i);
				i = 0;

				continue;
			}*/

			/*if( row.m_iShouldShow == 0 ) continue;

			//str
			if( row.m_type == "str" )
			{
				str_task(row);
			}

			//pic
			if( row.m_type == "pic" )
			{
				pic_task(row);
			}
		}// end, for the whole lbl tbl

		//最后全刷新一把 
		//for( long i = 0; i < m_lblset.GetRowCount(); i++ )
		for( long i = (m_lblset.GetRowCount()-1); i >= 0 ; i-- )
		{
			a_label_t::ROWTYPE & row(m_lblset.GetRow(i));

			if( row.m_iShouldShow == 0 ) continue;
		
			gdk_threads_enter();
			gtk_widget_show( (GtkWidget *)row.m_gtkpointer );
			gdk_threads_leave();

			row.m_iShouldShow = 0;
		}
	
		goto L_TASKEND;
	}
	
	if( t->m_type == "delall" )
	{
		for( long i = 0; i < m_lblset.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row(m_lblset.GetRow(i));

			row.m_type = "del" ;
		}
		
		this->LabelCommit();

		goto L_TASKEND;
	}

	if( t->m_type == "modifyall" )
	{
		for( long i = 0; i < m_lblset.GetRowCount(); i++ )
		{
			a_label_t::ROWTYPE & row2(m_lblset.GetRow(i));

			row2.m_iShouldShow = 1;
			row2.m_iNewModiFlag = 1;
		}

		this->LabelCommit();

		goto L_TASKEND;
	}

	if(1)
	{
		a_label_t::RPSTYPE rps[9];
		
		m_lblset.SelEc_name( t->m_name, rps[1] ); //    
		///

		if( m_lblset.GetRowCount( rps[1] ) == 0 ) //没找到，是新增的记录 
		{
			a_label_t::ROWTYPE & row2(*t);

			row2.m_iShouldShow = 1;
			row2.m_iNewModiFlag = 0;
			m_lblset.Add(*t);
		}
		else
		{
			a_label_t::ROWTYPE & row2( m_lblset.GetRow( rps[1], 0 ) ); 
			PVOID_t p = row2.m_gtkpointer;

			if( row2.m_ds != t->m_ds )
			{
				row2 = *t;
				row2.m_iShouldShow = 1;
				row2.m_iNewModiFlag = 1;
				row2.m_gtkpointer = p;
			}
		}
	
		goto L_TASKEND;
	}
		

	goto L_TASKEND;

L_TASKEND:
	LabelFixedShow();
	delete t;
	return;*/
}

void de_ui_t::updateLabel( a_label_t::ROWTYPE & row, std::string value)
{
	std::string s3;
	std::string  sSize;
	row.m_value = value;
	wl::SStrf::sreplstr( value, "<", "&lt;" );
	wl::SStrf::sreplstr( value, ">", "&gt;" );
	sSize = SStrf::sftoa( row.m_font_size * 260 * m_scr_width[0] / 800.01 );
	
	s3	= "<span" ;	
	s3 += " font_family='黑体' foreground='" + row.m_font_color + "'";
	s3 += " font_desc='黑体 bold " + sSize + "'";	
	s3 += ">" + value + "</span>";

	gdk_threads_enter();
	gtk_label_set_markup( GTK_LABEL((GtkWidget *)row.m_gtkpointer), s3.c_str() );
	gdk_threads_leave();	
	//gtk_label_set_text(GTK_LABEL((GtkWidget *)row.m_gtkpointer),value.c_str());
	//row.m_value = value;
}


void de_ui_t::showLabel( a_label_t::ROWTYPE & row )
{
	gdk_threads_enter();
	gtk_widget_show( (GtkWidget *)row.m_gtkpointer );
	gdk_threads_leave();
}

void de_ui_t::hideLabel( a_label_t::ROWTYPE & row )
{
	gdk_threads_enter();
	gtk_widget_hide( (GtkWidget *)row.m_gtkpointer );
	gdk_threads_leave();
}

void de_ui_t::freeLabel(a_label_t::ROWTYPE & row )
{
	gdk_threads_enter();
	gtk_widget_destroy( (GtkWidget *)row.m_gtkpointer );
	gdk_threads_leave();
}

