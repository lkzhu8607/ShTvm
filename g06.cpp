
#pragma warning(disable: 4312)
#pragma warning(disable: 4996)

#include "g06.h"

//
int main2( int argc, char *argv[] )
{
    GtkWidget * window;
    gtk_init( &argc, &argv );
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title( GTK_WINDOW(window), "hello c!!" );
    gtk_widget_show(window);
    gtk_main();
    return 0;
}



extern GtkWidget * m_frmMain;
extern GtkWidget * m_fixed;
static int  m_width;
static int  m_height;
//static std::map< std::string, SNavass >  v_maplabel;


//
static void add_fixed()
{
	m_fixed = gtk_fixed_new();

	gdk_threads_enter();
	gtk_widget_set_usize( m_fixed, m_width, m_height );
	gdk_threads_leave();

	gdk_threads_enter();
	gtk_container_add( GTK_CONTAINER(m_frmMain), m_fixed );
	gdk_threads_leave();

	gdk_threads_enter();
	gtk_widget_show(m_fixed);
	gdk_threads_leave();
}

//
int main3( int argc, char *argv[] )
{
	m_width = 640;
	m_height = 480;

	if ( !g_thread_supported() )
	{
		g_thread_init(NULL);
		gdk_threads_init();
	}
	
	gtk_init( NULL, NULL );

	m_frmMain = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title( GTK_WINDOW(m_frmMain), "GATE" );
	gtk_window_set_position(GTK_WINDOW(m_frmMain),GTK_WIN_POS_CENTER);
	gtk_widget_set_usize( m_frmMain, m_width, m_height );
	gtk_container_border_width( GTK_CONTAINER(m_frmMain), 1 );
	
	//gtk_window_set_decorated( GTK_WINDOW(m_frmMain), FALSE ); // no head
	//gtk_window_fullscreen( GTK_WINDOW(m_frmMain) ); // large 
	g_signal_connect( GTK_OBJECT(m_frmMain), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL );

	add_fixed();
    gtk_widget_show(m_frmMain);


	PangoFontDescription *desc = pango_font_description_from_string("sans");
	gtk_widget_modify_font(m_frmMain, desc);
	gtk_widget_modify_font(m_fixed, desc);
	pango_font_description_free(desc);


	gdk_threads_enter();
	gtk_main();
	gdk_threads_leave();

    return 0;
}


void test2()
{
	int i;

	for(;;)
	{
		for( i = 0; i < 155; i++ )
		{
			GtkWidget *lblTest;
			
			//lblTest  = gtk_image_new_from_file("1.jpg");

			//gdk_threads_enter();
			//gtk_object_ref (GTK_OBJECT (lblTest));
			//gtk_object_sink (GTK_OBJECT (lblTest));
			//gdk_threads_leave();

			gdk_threads_enter();
			lblTest = gtk_label_new("aa");
			//gtk_fixed_put( GTK_FIXED(m_fixed), lblTest, i*2 , i );
			gtk_container_add( GTK_CONTAINER(m_frmMain), lblTest );
			gdk_threads_leave();



			gdk_threads_enter();
			gtk_widget_show( lblTest );
			//gtk_widget_show_all(gl_psimform->m_frmMain);
			gdk_threads_leave();

			//g_signal_connect( GTK_OBJECT(lblTest), "destroy", GTK_SIGNAL_FUNC(gtk_widget_destroy), NULL );


			WThrd::tr_sleepu( 0.005 );

			gdk_threads_enter();
			gtk_widget_destroy( lblTest );
			//gtk_object_unref(GTK_OBJECT (lblTest));
			//g_free(lblTest);

			gdk_threads_leave();
		}
	}
}


//
void test3()
{
	for( int i = 0; i < 22 ; i++ )
	{
		//gp_ui->LabelPrepStr( "3", "我是-" + SStrf::sltoa(i), 0.1, 0.2 );
		//gp_ui->LabelPrintPrep( "a", "bbbbbbb", 0.1, 0.3, 0.2 );
		//gp_ui->LabelPrintPrep( "c", "我是一个好人你是一个坏人", 0.0, 0.0, 0.3 );
		gp_ui->LabelCommit();
		printf("%d\n", i );
		WThrd::tr_sleep( 0, 0.01 );
	}
}


//
void test4()
{
	//gp_ui->LabelMkPic( "a", "1.jpg", 0, 0 );
	//gp_ui->LabelCommit();
	//WThrd::tr_sleep( 0, 0.5 );
	//
	//gp_ui->LabelMkPic( "a", "0.jpg", 0, 0 );
	//gp_ui->LabelCommit();
	//WThrd::tr_sleep( 0, 0.5 );

	//gp_ui->LabelMkPic( "a", "2.jpg", 0, 0 );
	//gp_ui->LabelCommit();
	//WThrd::tr_sleep( 1 );

	//gp_ui->LabelMkPic( "a", "3.jpg", 0, 0 );
	//gp_ui->LabelCommit();
	//WThrd::tr_sleep( 1 );

	gp_ui->LabelMkPicPrep( 1, "back1", "back.jpg", 0, 0, 1, 1 );
	//gp_ui->LabelMkPicPrep( 1, "back2", "back.jpg", 0, 0 );
	gp_ui->LabelCommit();
}


//
void test_lbl()
{
	test4();
	test3();
	gp_ui->LabelMkDelPrep( "a" );
	gp_ui->LabelCommit();
}



//
void test_lbl_mem()
{
	//int iMax = 33;
	//int i;
	//double x, y;
	//std::string strNameStr;
	//std::string strNamePic;

	//do
	//{
	//	for( i = 0; i < iMax; i++ )
	//	{
	//		strNameStr = "s-" + SStrf::sltoa(i);
	//		strNamePic = SStrf::sltoa(i) + "pic";
	//		x = SStrf::rand1();
	//		y = SStrf::rand1();

	//		printf("%d x=%.2f y=%.2f\n", i, x, y );

	//		gp_ui->LabelMkPic( strNamePic, "1.jpg", x, y );
	//		gp_ui->LabelCommit();
	//		WThrd::tr_sleep( 0, 0.01 );

	//		gp_ui->LabelPrepStr( strNameStr, strNameStr, x, y, 0.05 );
	//		gp_ui->LabelCommit();
	//		WThrd::tr_sleep( 0, 0.01 );
	//	}

	//	//WThrd::tr_sleep( 1, 0.5 );
	//	
	//	for( i = 0; i < iMax; i++ )
	//	{
	//		strNameStr = "s-" + SStrf::sltoa(i);
	//		strNamePic = SStrf::sltoa(i) + "pic";

	//		printf("%d \n", i );

	//		gp_ui->LabelMkDelPrep( strNameStr );
	//		gp_ui->LabelCommit();
	//		WThrd::tr_sleep( 0, 0.01 );

	//		gp_ui->LabelMkDelPrep( strNamePic );
	//		gp_ui->LabelCommit();
	//		WThrd::tr_sleep( 0, 0.01 );
	//	}

	//	WThrd::tr_sleepu( 0.05 );

	//}while(1);
}



//
void test_key()
{
	//gp_ui->LabelPrepStr( "3", "是", 0.02, 0.92 );
	//gp_ui->LabelCommit();

	//gp_key->Clear();

	//for( int i = 0; i < 9999 ; i++ )
	//{
	//	std::string s1;

	//	s1 = gp_key->GetKey();

	//	if( s1.empty() ) 
	//	{
	//		WThrd::tr_sleep( 0, 0.25 );
	//		s1 = "empty";
	//	}
	//	else
	//	{
	//		s1=s1;
	//	}

	//	gp_ui->LabelPrepStr( "3", "我是:" + s1, 0.01, 0.92 );
	//	gp_ui->LabelCommit();
	//}
}



//
void test_reader()
{
	//tbool rc;
	//SCake ck;

	//rc = gp_enter->hzocom_open( gp_conf->Get_reader1_com_port() );

	//rc = gp_enter->a_4_1_1_reset( ck );
	//rc = gp_enter->a_4_1_2_ant( ck, 0x01 );
}



//
void test_printline()
{
	int i;

	do
	{
		for( i = 0; i < 33 ; i++ )
		{
			gp_ui->LineScrPrint( 1, "s-" + SStrf::sltoa(i) + SStrf::sltoa(i) + "pic" );
				 
			WThrd::tr_sleepu( 0.1 );
		}
		
		gp_ui->LineScrClear( 1 );
		
		WThrd::tr_sleepu( 0.5 );

	}while(1);


	while(1)
		WThrd::tr_sleep( 1 );
}



//
void test_uicskey()
{
	//gp_key->Clear();

	for( int i = 0; i < 9999 ; i++ )
	{
		std::string s1;
		std::vector< std::string > v1;

		//s1 = gp_key->GetKey();

		if( s1.empty() ) 
		{
			WThrd::tr_sleepu( 0.25 );
		}
		else
		{
			printf( "%s\n", s1.c_str() );
		}

		SStrvs::vsa_imp( s1, std::string("|"), 0, v1 );

		if( v1.size() >= 4 && v1[3] == "800" )
		{
			//gp_uics->SendCmd( "2|0|00000102|200|1|9|1|2|01020304|0102|10|8|0" ); 
			//gp_uics->SendCmd( "2|0|00000102|200|1|9|1|2|01020304|0102|10|8|0" ); 
			WThrd::tr_sleepu( 2 );
			//gp_uics->SendCmd( "3|0|200|3|3|1|2|2|2|" ); 
			//WThrd::tr_sleepu( 5 );
		}
	}
}


//
void test_set3014()
{
	a3014_t::ROWTYPE &r( gp_db->GetTheRowa3014() );
	unsigned char c1,c2,c3,c4;

	c1 = 0x12;
	c2 = 'Q';	
	c3 = 0x10;
	c4 = 0x44;

	r.m_CcNode.a[0] = c1;
	r.m_CcNode.a[1] = c2;
	r.m_CcNode.a[2] = 0;
	r.m_CcNode.a[3] = 0;
	r.m_CCNodecode1 = c1;
	r.m_CCNodecode2 = c2;
	r.m_CCNodecode3 = 0;
	r.m_CCNodecode4 = 0;

	r.m_ScNode.a[0] = c1;
	r.m_ScNode.a[1] = c2;
	r.m_ScNode.a[2] = c3;
	r.m_ScNode.a[3] = c4;
	r.m_SCNodecode1 = c1;
	r.m_SCNodecode2 = c2;
	r.m_SCNodecode3 = c3;
	r.m_SCNodecode4 = c4;

	r.m_EqpNode.a[0] = c1;
	r.m_EqpNode.a[1] = c2;
	r.m_EqpNode.a[2] = c3;
	r.m_EqpNode.a[3] = c4;
	r.m_EqpNodecode1 = c1;
	r.m_EqpNodecode2 = c2;
	r.m_EqpNodecode3 = c3;
	r.m_EqpNodecode4 = c4;

	gp_db->RiseSaveFlag(gp_db->m_a3014);
}



int test_coin3()
{
	gp_coin->dCoinHold();
	gp_coin->dCoin_Stop();
	
	b8701_t::ROWTYPE &Rb8701(gp_db->GetTheRowb8701());
	
	gp_coin->dCoin_Work( 1, 1 );

	while(1)
	{
		gp_coin->dCoin_Query();

		printf( "%d %d\n", Rb8701.m_CoinPollData.a[0] , Rb8701.m_CoinPollData.a[1] );

		WThrd::tr_sleep(1);

		if( Rb8701.m_CoinPollData.a[0] >= 2 ) 
			break;
	}
	
	//gp_coin->dCoin2CircleChg();
	gp_coin->dCoin2StoreBox();
	WThrd::tr_sleep(3);
	
	gp_coin->dCoinHold();
	gp_coin->dCoin_Stop();

	while(1)
		WThrd::tr_sleep(3);
}


int test_coin2()
{
	gp_coin->dCoin_Work( 1, 1 );

	b8701_t::ROWTYPE &Rb8701(gp_db->GetTheRowb8701());

	gp_coin->dCoinHold();
	WThrd::tr_sleep(1);
	gp_coin->dCoin2CircleChg();
	WThrd::tr_sleep(1);
	gp_coin->dCoin2StoreBox();
	WThrd::tr_sleep(1);
	gp_coin->dCoin2Return();
	WThrd::tr_sleep(1);


	while(1)
	{
		gp_coin->dCoin_Query();

		printf( "%d %d\n", Rb8701.m_CoinPollData.a[0] , Rb8701.m_CoinPollData.a[1] );

		WThrd::tr_sleep(1);

		if( Rb8701.m_CoinPollData.a[0] >= 2 ) 
			break;
	}

	gp_coin->dCoin_Stop();
	
	gp_coin->dCoin_Query();
	printf( "%d %d\n", Rb8701.m_CoinPollData.a[0] , Rb8701.m_CoinPollData.a[1] );

	gp_coin->dCoinOpenUplight();
	WThrd::tr_sleep(1);
	gp_coin->dCoinCloseUplight();
	WThrd::tr_sleep(1);

	gp_coin->dCoinOpenDownlight();
	WThrd::tr_sleep(1);
	gp_coin->dCoinCloseDownlight();
	WThrd::tr_sleep(1);

	gp_coin->dCoinOpenAlert();
	WThrd::tr_sleep(1);
	gp_coin->dCoinCloseAlert();
	WThrd::tr_sleep(1);
	

	while(1)
		WThrd::tr_sleep(3);
}


int test_coin()
{
	//m_iSeq=0;
	bool is=true;
	unsigned int pre;
    int count=0;
	BYTE pre1;
	BYTE SensorStatus[8];
	BYTE Test[2];
	unsigned int index;
	BYTE Major,Minor;
	BYTE Open1[2],Open2[2];
	BYTE Poll,Poll1[3];
	BYTE WriteId[5];
	BYTE ReadId/*,ReadId1[4]*/;
	BYTE Box_WriteId[13],BoxReadId[7];
	BYTE Program1[4],Program2[64];
	BYTE Change1[2],Change2[3];
	BYTE Clean1,Clean2[2];
	BYTE Add1,Add2[2];
	BYTE End;
	int i,j;
	unsigned long id=0;

	CCoin coinmodule;
	
	//测试
	BYTE bit;
	bool isOpen,isClose;
	int iResult;
	//
	
	while(is)
	{
		cout<< "------------------------------------------------------------------------------" <<endl
			<<"打开串口：						0"<<endl
			<<"关闭串口：						1"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"硬币模块状态查询：   2"<<endl
			<<"硬币模块测试命令：   3"<<endl
			<<"硬币模块程序复位：   4"<<endl
			<<"硬币模块程序版本查询：  5"<<endl
			<<"硬币模块找零命令：      7"<<endl
			<<"循环找零箱、专用找零箱找零结束：    71"<<endl
			<<"硬币模块清币命令：    8"<<endl
			<<"循环找零箱、专用找零箱清币结束命令：81"<<endl
			<<"硬币模块电磁铁开关命令：    9"<<endl
			<<"硬币识别器轮询：           10"<<endl
			<<"硬币模块补币箱加币命令：    11"<<endl
			<<"硬币模块设备与票箱电子ID写命令： 12"<<endl
			<<"硬币模块设备与票箱电子ID读命令： 13"<<endl  
			<<"硬币回收箱写命令：   14"<<endl
			<<"硬币回收箱读命令：   15"<<endl			
		    <<"///////////////////////////////////////////////////////////////"<<endl
			<<"硬币模块程序更新命令：       16"<<endl
			<<"硬币模块编程开始命令：       17"<<endl
			<<"硬币模块发送编程数据命令：   18"<<endl
			<<"硬币模块编程结束命令：       19"<<endl
			<<"硬币模块切换到应用程序命令： 20"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"预设置的返回报文： 21"<<endl
			<<"退出程序：         22"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"请选择指向的操作代码：";
	    cin>>dec>>i;
		switch(i)
		{
		case 0: 
				cout<< gp_conf->Get_coin_com_port() <<endl;
			    isOpen=coinmodule.Coin_CommOpen(); 
				if(isOpen==true)
				{
				  cout<<"打开串口成功！"<<endl;
				}
				else 
				{
				cout<<"打开串口失败！"<<endl;
				}
				break;
		case 1: isClose=coinmodule.Coin_CommClose();
			    if(isClose==true)
				{
				  cout<<"关闭串口成功！"<<endl;
				}
				else 
				{
				cout<<"关闭串口失败！"<<endl;
				}
				break;
		case 2: iResult=coinmodule.Coin_State(SensorStatus);
			    if(iResult==0)
				{
					//.........0
					bit=0x01;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"硬币模块到位！"<<endl;
					}
					else
					{
						cout<<"硬币模块未到位！"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"纸币找零器到位！"<<endl;
					}
					else
					{
						cout<<"纸币找零器未到位！"<<endl;
					};
					/*bit=0x04;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"投币口状态关闭！"<<endl;
					}
					else
					{
						cout<<"投币口状态打开！"<<endl;
					};*/
					bit=0x08;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"循环找零器到位！"<<endl;
					}
					else
					{
						cout<<"循环找零器未到位！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"UPS断电信号到位！"<<endl;
					}
					else
					{
						cout<<"UPS断电信号未到位！"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"清币翻版旋转电磁铁退币位置到位！"<<endl;
					}
					else
					{
						cout<<"清币翻版旋转电磁铁退币位置未到位！"<<endl;
					};
					bit=0x40;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					    cout<<"5角补币箱到位！"<<endl;
					}
					else
					{
						cout<<"5角补币箱未到位！"<<endl;
					};
					bit=0x80;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					cout<<"1元补币箱到位！"<<endl;
					}
					else
					{
					cout<<"1元补币箱未到位！"<<endl;
					};

					//...............1
					bit=0x01;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"门到位！"<<endl;
					}
					else
					{
						cout<<"门未到位！"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"门锁到位！"<<endl;
					}
					else
					{
						cout<<"门锁未到位！"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"暂存循环闸门关闭！"<<endl;
					}
					else
					{
						cout<<"暂存循环闸门打开！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"暂存退币闸门关闭！"<<endl;
					}
					else
					{
						cout<<"暂存退币闸门打开！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"点币箱锁上！"<<endl;
					}
					else
					{
						cout<<"点币箱未锁上！"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"发卡模块到位到位！"<<endl;
					}
					else
					{
						cout<<"发卡模块到位未到位！"<<endl;
					};
					bit=0x40;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					   cout<<"报警喇叭关！"<<endl;
					}
					else
					{
						cout<<"报警喇叭开！"<<endl;
					};
					bit=0x80;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					cout<<"取票口照明关！"<<endl;
					}
					else
					{
					cout<<"取票口照明开！"<<endl;
					};
					//................2
					bit=0x04;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"投币口状态关闭！"<<endl;
					}
					else
					{
						cout<<"投币口状态打开！"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"投币入口光感遮挡！"<<endl;
					}
					else
					{
						cout<<"投币入口光感没遮挡！"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"投币废币出口光感遮挡！"<<endl;
					}
					else
					{
						cout<<"投币废币出口光感没遮挡！"<<endl;
					};
					//...........3
					bit=0x01;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"硬币回收箱币位信号3到位！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱币位信号3未到位！"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"硬币回收箱币位信号2到位！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱币位信号2未到位！"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"硬币回收箱币位信号1到位！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱币位信号1未到位！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"硬币回收箱到位到位！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱到位未到位！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
					   cout<<"硬币回收箱正常！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱堵！"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
					cout<<"硬币回收箱正常！"<<endl;
					}
					else
					{
					cout<<"硬币回收箱满！"<<endl;
					};
					//....................4 1元循环找零箱状态
					bit=0x04;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"找零箱锁到位！"<<endl;
					}
					else
					{
						cout<<"找零箱锁未到位！"<<endl;
					};
					//..................5 5角循环找零箱状态
					bit=0x04;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					//..............6 1元专用找零箱状态
					bit=0x04;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"找零箱锁到位！"<<endl;
					}
					else
					{
						cout<<"找零箱锁未到位！"<<endl;
					};
					//..............7 5角专用找零箱状态
					bit=0x04;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};


					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
        else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
				}
				else if(iResult==-3)
				{
					cout<<"命令发送失败！"<<endl;
				}
				else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号错误！"<<endl;
				}
				break;
		case 3:	cout<<"0x11：1元加币箱电磁铁动作"<<endl
                    <<"0x12：5角加币箱电磁铁动作"<<endl
					<<"0x13：1元循环找零箱电磁铁动作"<<endl
					<<"0x14：5角循环找零箱电磁铁动作"<<endl
					<<"0x15：1元补币箱电磁铁动作"<<endl
					<<"0x16：5角补币箱电磁铁动作"<<endl
					<<"0x17：1元加币箱电机动作(电机先正转然反转)"<<endl
					<<"0x18：5角加币箱电机动作(电机先正转然反转)"<<endl
					<<"0x19：1元循环找零箱电机动作(电机先正转然反转)"<<endl
					<<"0x1A：5角循环找零箱电机动作(电机先正转然反转)"<<endl
					<<"0x1B：1元补币箱电机动作(电机先正转然反转)"<<endl
					<<"0x1C：5角补币箱电机动作(电机先正转然反转)"<<endl
					<<"0x00：停止所有动作"<<endl;
			        cout<<"请选择测试的电机操作：";
					cin>>hex>>index;
					Test[0]=(BYTE)index;
					Test[1]=0x11;
			        iResult=coinmodule.Coin_Test(Test);	
					if(iResult==0)
					{
						cout<<"命令执行成功！"<<endl;
					}
					else if(iResult==-1)
					{
						cout<<"命令执行超时！"<<endl;
					}
					else if(iResult==80)
					{
						cout<<"设备状态忙！"<<endl;
					}
					else if(iResult==98)
					{
						cout<<"命令执行失败！"<<endl;
					}
					else if(iResult==99)
					{
						cout<<"解包出错请求重发！"<<endl;
					}
					else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
	    case 4: iResult=coinmodule.Coin_Reset();
			    if(iResult==0)
				{  
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
				}
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
				}
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				{
				  	cout<<"端口未打开！"<<endl;
				}
				else if(iResult==-3)
				 {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 5: iResult=coinmodule.Coin_GetVersion(Major,Minor);
			   if(iResult==0)
				{   
				    cout<<"主版本号:"<<hex<<(int)Major<<"  副版本号："<<hex<<(int)Minor<<endl;
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 71: cout<<"0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零"<<endl;
			     cout<<"请选择找零操作：";
			     cin>>hex>>index;
			    End=(BYTE)index;
				iResult=coinmodule.Coin_End_Change(End);
				if(iResult==0)
				{   
				    cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  };
				break;
		case 7: cout<<"0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零"<<endl;
			    cout<<"请选择找零操作：";
			    cin>>hex>>index;
			    Change1[0]=(BYTE)index;
			   /* cout<<"0xAB：A命令 0xBB：B命令";
				cin>>hex>>index;
			    Change1[1]=(BYTE)index;*/
				cout<<"请按十六进制输入找零数（1~48）";
				cin>>hex>>index;
			    Change1[1]=(BYTE)index;
			    iResult=coinmodule.Coin_Change(Change1,Change2);
				 if(iResult==0)
				{   
					//...............0
				    switch(Change2[0])
					{
					case 0x01:cout<<"1元循环找零"<<endl;
						     break;
					case 0x02:cout<<"5角循环找零"<<endl;
					break;
					case 0x04:cout<<"1元专用找零"<<endl;
					break;
					case 0x08:cout<<"5角专用找零"<<endl;
					break;					
					};
					//................1
					cout<<"找零数："<<(int)Change2[1]<<endl;
					//................2
					bit=0x01;
					bit&= Change2[2];
					if(bit==0x00)
					{   
						cout<<"找零箱没空！"<<endl;
					}
					else
					{
						cout<<"循环找零箱或专用找零箱空！"<<endl;
					};
					bit=0x02;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"没有故障！"<<endl;
					}
					else
					{
						cout<<"（找零斗卡币)或(找零斗出币计数据传感器未插好和坏)或(找零斗出币通道卡币) ！"<<endl;
					};
                    bit=0x04;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					bit=0x20;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"所选择的找零箱模块位锁到位！"<<endl;
					}
					else
					{
						cout<<"所选择的找零箱模块位锁未到位！"<<endl;
					};
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 81: cout<<"0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零"<<endl;
			     cout<<"请选择清币操作：";
			     cin>>hex>>index;
			    End=(BYTE)index;
				iResult=coinmodule.Coin_End_Clean(End);
				if(iResult==0)
				{   
				    cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
			    break;
		case 8: cout<<"0x01：1元循环找零；0x02：5角循环找零；0x04：1元专用找零；0x08：5角专用找零"<<endl;
			    cout<<"请选清币操作：";
			    cin>>hex>>index;
			    Clean1=(BYTE)index;
			    iResult=coinmodule.Coin_Clean(Clean1,Clean2,count);
				if(iResult==0)
				{
					//...............0
				    switch(Clean2[0])
					{
					case 0x01:cout<<"1元循环找零"<<endl;
						     break;
					case 0x02:cout<<"5角循环找零"<<endl;
					         break;
					case 0x04:cout<<"1元专用找零"<<endl;
					         break;
					case 0x08:cout<<"5角专用找零"<<endl;
					         break;					
					};
					////................1
					//cout<<"清币数据高位："<<(int)Clean2[1]<<endl;
					////................2
					//cout<<"清币数据低位："<<(int)Clean2[2]<<endl;
					//................1
					bit=0x01;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"找零箱没空！"<<endl;
					}
					else
					{
						cout<<"找零箱或补币箱空！"<<endl;
					};
					bit=0x02;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"没有故障！"<<endl;
					}
					else
					{
						cout<<"（(找零斗卡币)或(找零斗出币计数据传感器未插好和坏)或(找零斗出币通道卡币)！"<<endl;
					};
                    bit=0x04;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					bit=0x20;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"循环找零箱或补充找零箱模块位锁到位！"<<endl;
					}
					else
					{
						cout<<"循环找零箱或补充找零箱模块位锁未到位！"<<endl;
					};
					cout<<"清币数据数目："<<count<<endl;
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 9: cout<<"第一个数据的每一位介绍："<<endl;
			    cout<<"Bit7-6:未使用"<<endl
					<<"Bit5:=1/0   1电源箱开关开（保留）"<<endl
					<<"Bit4:=1/0   预留"<<endl
					<<"Bit3:=1/0   1卡币解除马达启动，0停"<<endl
					<<"Bit2:=1/0   1暂存翻板进回收 0退币"<<endl
					<<"Bit1:=1/0   1暂存器退币闸门开，0关"<<endl
					<<"Bit0:=1/0   1暂存循环回收闸门开，0关"<<endl;
			   cout<<"请输入一个十六进制数：";
			   cin>>hex>>index;
			   Open1[0]=(BYTE)index;
			   cout<<"第二个数据的每一位介绍："<<endl;
			   cout<<"Bit7~bit6:未使用"<<endl
					<<"Bit5-4：11开乘客显示器照明，01关乘客显示器照明，00不改变"<<endl
					<<"Bit3-2：11开取票口照明，01关取票口照明，00不改变"<<endl
					<<"Bit1-0：11开报警器，01关报警器，00不改变"<<endl;
			   cout<<"请输入一个十六进制数：";
			   cin>>hex>>index;
               Open1[1]=(BYTE)index;			    
			   iResult=coinmodule.Coin_OpenClose(Open1,Open2);
			   if(iResult==0)
			   {  
				   //...................0
				    bit=0x01;
					bit&= Open2[0];
					if(bit==0x00)
					{   
						cout<<"暂存循环闸门关！"<<endl;
					}
					else
					{
						cout<<"暂存循环闸门开！"<<endl;
					};
					bit=0x02;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"暂存退币闸门关!"<<endl;
					}
					else
					{
						cout<<"暂存退币闸门开！"<<endl;
					};
                    bit=0x04;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"退币！"<<endl;
					}
					else
					{
						cout<<"暂存翻板进回收！"<<endl;
					};
					bit=0x08;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"卡币解除马达未到位！"<<endl;
					}
					else
					{
						cout<<"卡币解除马达到位！"<<endl;
					};
					bit=0x20;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"电源箱开关关！"<<endl;
					}
					else
					{
						cout<<"电源箱开关开！"<<endl;
					};
					bit=0x40;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"清币闸正常！"<<endl;
					}
					else
					{
						cout<<"清币闸异常（光感全亮或全暗）！"<<endl;
					};
					//...................1
					 bit=0x01;
					bit&= Open2[1];
					if(bit==0x00)
					{   
						cout<<"报警器关！"<<endl;
					}
					else
					{
						cout<<"报警器开！"<<endl;
					};
					bit=0x02;
					bit&=Open2[1];
					if(bit==0x00)
					{   
						cout<<"取票口照明关！"<<endl;
					}
					else
					{
						cout<<"取票口照明开！"<<endl;
					};
                    bit=0x04;
					bit&=Open2[1];
					if(bit==0x00)
					{   
						cout<<"乘客显示器照明关！"<<endl;
					}
					else
					{
						cout<<"乘客显示器照明开！"<<endl;
					};

			   	   cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 10:cout<<"数据的每一位介绍："<<endl;
			   cout<<"Bit7-6:未使用"<<endl
					<<"Bit3: =1/0  1 投币口闸门打开， 0闸门关闭"<<endl
					<<"Bit2:=1/0  1 清除硬币计数寄存器，0不清除"<<endl
					<<"Bit1:=1/0  1 禁止5角， 0接受5角"<<endl
					<<"Bit0:=1/0  1 禁止1元， 0接受1元"<<endl;					
			   cout<<"请输入一个十六进制数：";
			   cin>>hex>>index;
			   Poll=(BYTE)index;
			   iResult=coinmodule.Coin_Poll(Poll,Poll1);
			   if(iResult==0)
			   {
				   //...........0
				   cout<<"接受的1元硬币数："<<(int)Poll1[0]<<endl;
				   //...........1
				   cout<<"接受的5角硬币数："<<(int)Poll1[1]<<endl;
				   //...........2
				   bit=0x01;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"已接受1元！"<<endl;
					}
					else
					{
						cout<<"已禁止1元！"<<endl;
					};
				   bit=0x02;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"已接受5角！"<<endl;
					}
					else
					{
						cout<<"已禁止5角！"<<endl;
					};
				   bit=0x04;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"投币口闸门未打开！"<<endl;
					}
					else
					{
						cout<<"投币口闸门已打开！"<<endl;
					};
				   bit=0x08;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"硬币识别器不存在！"<<endl;
					}
					else
					{
						cout<<"硬币识别器存在！"<<endl;
					};
				   bit=0x10;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"硬币进口通道正常！"<<endl;
					}
					else
					{
						cout<<"硬币进口通道故障！"<<endl;
					};
				    bit=0x20;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"硬币回收箱通道正常！"<<endl;
					}
					else
					{
						cout<<"硬币回收箱通道满/堵！"<<endl;
					};

			      cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 11:cout<<"0x01：1元补币箱；  0x02：5角补币箱"<<endl;
			    cout<<"请选择补币箱：";
			    cin>>hex>>index;
			    Add1=(BYTE)index;			    
			    iResult=coinmodule.Coin_Add(Add1,Add2,count);
				if(iResult==0)
				{  
					//..................0
					if(Add2[0]==0x01)
					{
						cout<<"1元补币箱"<<endl;
					}
					else
					{
						cout<<"5角补币箱"<<endl;
					};
					////...............1
					//cout<<"补币数据高位 "<<(int)Add2[1]<<endl;
					////..............2
				 //   cout<<"补币数据低位 "<<(int)Add2[2]<<endl;
					//...................1
					bit=0x01;
					bit&= Add2[1];
					if(bit==0x00)
					{   
						cout<<"找零箱没空！"<<endl;
					}
					else
					{
						cout<<"找零箱或补币箱空！"<<endl;
					};
					bit=0x02;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"没有故障！"<<endl;
					}
					else
					{
						cout<<"（(找零斗卡币)或(找零斗出币计数据传感器未插好和坏)或(找零斗出币通道卡币)！"<<endl;
					};
                    bit=0x04;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"找零器低币位遮挡！"<<endl;
					}
					else
					{
						cout<<"找零器低币位未遮挡（空）！"<<endl;
					};
					bit=0x08;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"找零器高币位遮挡（满）！"<<endl;
					}
					else
					{
						cout<<"找零器高币位未遮挡！"<<endl;
					};
					bit=0x10;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"双向电磁铁正常！"<<endl;
					}
					else
					{
						cout<<"双向电磁铁故障！"<<endl;
					};
					bit=0x20;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"补充找零箱模块位锁到位！"<<endl;
					}
					else
					{
						cout<<"补充找零箱模块位锁未到位！"<<endl;
					};
					
					
				  cout<<"补币数据数量： "<<count<<endl;
			      cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 12: cout<<"0x01：1元补币箱电子ID；（补币箱电子ID）"<<endl
                    <<"0x02：5角补币箱电子ID （预留）"<<endl
					<<"0x04：硬币模块设备编号；"<<endl;
				cout<<"请写入设备操作编号：";
				cin>>hex>>index;
				WriteId[0]=(BYTE)index;
				for(int i=1;i<5;i++)
				{
				cout<<"请输入模块编号（高位在前）：";
				cin>>hex>>index;
				WriteId[i]=(BYTE)index;
				}			   
			    iResult=coinmodule.Coin_WriteID(WriteId);
				if(iResult==0)
				{
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 13: cout<<"0x01：1元补币箱电子ID；（补币箱电子ID）"<<endl
                    <<"0x02：5角补币箱电子ID （预留）"<<endl
					<<"0x04：硬币模块设备编号；"<<endl;
				cout<<"请写入设备操作编号：";
				cin>>hex>>index;
				ReadId=(BYTE)index;  
     			iResult=coinmodule.Coin_ReadID(ReadId,id);
				if(iResult==0)
				{
					//cout<<"模块编号（高位在前）是："<<hex<<(int)ReadId1[0]<<hex<<(int)ReadId1[1]<<hex<<(int)ReadId1[2]<<hex<<(int)ReadId1[3]<<endl;
					cout<<"模块编号："<<id<<endl;
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 14: j=0;
				while(j<4)
				{
				   cout<<"请输入硬币钱箱编号（高位在前），一个字节一个字节输入：";
					cin>>hex>>index;
					Box_WriteId[j]=(BYTE)index;
					j++;
				};
				cout<<"请输入硬币钱高位：";
			    cin>>hex>>index;
				Box_WriteId[4]=(BYTE)index;
				cout<<"请输入硬币钱低位：";
			    cin>>hex>>index;
				Box_WriteId[5]=(BYTE)index;
				cout<<"请输入年（高位）：";
			    cin>>hex>>index;
				Box_WriteId[6]=(BYTE)index;
				cout<<"请输入年（低位）：";
			    cin>>hex>>index;
				Box_WriteId[7]=(BYTE)index;
				cout<<"请输入月：";
			    cin>>hex>>index;
				Box_WriteId[8]=(BYTE)index;
				cout<<"请输入日：";
			    cin>>hex>>index;
				Box_WriteId[9]=(BYTE)index;
				cout<<"请输入时：";
			    cin>>hex>>index;
				Box_WriteId[10]=(BYTE)index;
				cout<<"请输入分：";
			    cin>>hex>>index;
				Box_WriteId[11]=(BYTE)index;
				cout<<"请输入秒：";
			    cin>>hex>>index;
				Box_WriteId[12]=(BYTE)index;
			    iResult=coinmodule.Coin_Box_WriteID(Box_WriteId);
				if(iResult==0)
				{  
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"端口未打开！"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"命令发送失败！"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"返回报文命令或者序列号错误！"<<endl;
				  }
				break;
		case 15:iResult=coinmodule.Coin_Box_ReadID(BoxReadId,id,count);
			   if(iResult==0)
				{
					//...................0---3
					//cout<<"硬币钱箱编号（高位在前）是："<<hex<<(int)BoxReadId[0]<<hex<<(int)BoxReadId[1]<<hex<<(int)BoxReadId[2]<<hex<<(int)BoxReadId[3]<<endl;
					cout<<"硬币钱箱编号是："<<id<<endl;
					//...................4
					//cout<<"硬币数高位"<<hex<<(int)BoxReadId[4]<<endl;
					//...................5
					//cout<<"硬币数低位"<<hex<<(int)BoxReadId[5]<<endl;
					cout<<"硬币数量："<<count<<endl;
					//...........年月日时分秒 6--12
					cout<<hex<<(int)BoxReadId[0]<<hex<<(int)BoxReadId[1]<<"年"
						<<hex<<(int)BoxReadId[2]<<"月"
						<<hex<<(int)BoxReadId[3]<<"日"
						<<hex<<(int)BoxReadId[4]<<"时"
						<<hex<<(int)BoxReadId[5]<<"分"
						<<hex<<(int)BoxReadId[6]<<"秒"<<endl;
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
				}
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
				}
				else if(iResult==-3)
				{
					cout<<"命令发送失败！"<<endl;
				}
				else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号错误！"<<endl;
				}
				break;
		case 16:coinmodule.Coin_Program_Update();			   
				break;
		case 17:cout<<"程序编程开始数据"<<endl;
			    //sleep(10);
			    coinmodule.Coin_Program_Begin(Program1);
				break;
		case 18:cout<<"程序编程数据"<<endl;
			    //sleep(10);
			    coinmodule.Coin_Program_Send(Program2);
				break;
		case 19: coinmodule.Coin_Program_End();
				break;
		case 20:coinmodule.Coin_Program_APP();
				break;
		case 21: cout<<"请输入小于等于0xFF的值,如欲结束请输入Ox100:";
				cin>>hex>>pre;
				while(pre<256)
				{
					pre1=(BYTE)pre;
//					m_PreResult.push_back(pre1);
					cout<<"请输入小于等于0xFF的值,如欲结束请输入Ox100:";
					cin>>hex>>pre;	    
				}
				 break;
		case 22: is=false;
				 break;
		}
	}
		
   //system("pause");

   return 0;
}



int test_bill()
{
using namespace std;
using namespace BillGD;

	int actnum;
	int re,i;
	string sre;
	string vBoxID;
	GDCashModle GDCash;
	//int temp;  
	//std::cin >> temp;
	while(true)
	{
		WThrd::tr_sleepu( 1 );
		printf("**************************************************\n");
		printf("1 OpenCom\n");
		printf("2 CloseCom\n");
		printf("3 Reset\n");
		printf("4 WorkMode\n");
		printf("5 State\n");
		printf("6 BoxID\n");
		printf("7 Work\n");
		printf("8 Stop\n");
		printf("9 Return\n");
		printf("10 Reject\n");
		printf("11 Escrow\n");
		printf("12 Deposit\n");
		printf("13 Clear\n");
		printf("0 END\n");
		printf("Choose Act:\n");
		scanf("%d",&actnum);
		switch(actnum)
		{
		case 0:
			return 0;
		case 1:
			re=GDCash.OpenCom();
			printf("Open COM %s : re=%d\n", gp_conf->Get_bill_com_port().c_str(), re );
			break;
		case 2:
			re=GDCash.CloseCom();
			printf("Close COM : re=%d\n",re);
			break;
		case 3:
			re=GDCash.cmReset();
			printf("Reset : re=%d\n",re);
			break;
		case 4:
			re=GDCash.cmWorkMode(&sre);
			printf("WorkMode : re=%d , WorkMode=",re);
			cout<<sre;
			printf("\n");
			break;
		case 5:
			re=GDCash.cmState();
			printf("State, re=%d\n",re);
			if(re==0)
			for(i=0;i<GDCash.cErrorNum;i++)
			{
				printf("Error%d : %X\n",(i+1),GDCash.cErrorCode[i]);
			}
			printf("NoteValue : %d\n",GDCash.cNoteValue);
			printf("NoteNum : %d\n",GDCash.cNoteNum);
			printf("cErrorNum : %d\n",GDCash.cErrorNum);
			break;
		case 6:
			re=GDCash.cmBoxID(&vBoxID);
			printf("BoxID : re=%d , BoxID=",re);
			cout<<vBoxID;
			printf("\n");
			break;
		case 7:
			re=GDCash.cmWork();
			printf("Work : re=%d\n",re);
			break;
		case 8:
			re=GDCash.cmStop();
			printf("Stop : re=%d\n",re);
			break;
		case 9:
			re=GDCash.cmReturn();
			printf("Return : re=%d\n",re);
			break;
		case 10:
			re=GDCash.cmReject();
			printf("Reject : re=%d\n",re);
			break;
		case 11:
			re=GDCash.cmEscrow();
			printf("Escrow : re=%d\n",re);
			break;
		case 12:
			re=GDCash.cmDeposit();
			printf("Deposit : re=%d\n",re);
			break;
		case 13:
			re=GDCash.cmClear();
			printf("Clear : re=%d\n",re);
			break;
		}
		printf("**************************************************\n");
		printf("\n");
	}
	return 0;  
}



int test_bill_mei()
{
	gp_bill->Mei_Inhibit( 0 );
	gp_bill->Mei_Active( 0 );

	b8702_t::ROWTYPE &Rb8702(gp_db->GetTheRowb8702());
	
	Rb8702.m_PasswayTotal = 0;
		
	while(1)
	{
		Rb8702.m_cNoteValue = 0;
		Rb8702.m_cNoteNum = 0;

		gp_bill->Work();

		gp_bill->State();
	
		gp_bill->Stop();

		printf( "%d %d %d %d\n" , Rb8702.m_RtnVal  , Rb8702.m_cNoteValue ,  Rb8702.m_cNoteNum, Rb8702.m_PasswayTotal );

		if( Rb8702.m_RtnVal == 0 )
		{
			Rb8702.m_PasswayTotal += Rb8702.m_cNoteValue;
		}

		if( Rb8702.m_PasswayTotal > 34 )
			break;
	}

	gp_bill->Return1();

	while(1)
		WThrd::tr_sleep(3);
}


//
int test_ticket()
{
   int i;
	bool is=true;
	BYTE Index;
	BYTE Box1;
	BYTE Box;
	BYTE IsFail;
	BYTE Data5[4];
	/*报文解析所用变量*/
	bool isOpen;
	bool isClose;
	string  str;
	BYTE bit;
	int iResult;

	CTicket cticket;
	//
	while(is)
	{
		cout<< std::string( 79, '=' ) <<endl;
		cout<<"打开串口：          0"<<endl
			<<"关闭串口：          1"<<endl
			<<"发卡模块轮询：      2"<<endl
			<<"电机测试：          3"<<endl
			<<"复位：              4"<<endl
			<<"查询模块版本：      5"<<endl
			<<"发卡：             6"<<endl
			<<"读写结果：         7"<<endl
			<<"卡箱换箱：         8"<<endl
			<<"取模块ID：         9"<<endl
			<<"写模块ID：         10"<<endl
			<<"预设置的返回报文：  11"<<endl
			<<"退出程序：         12"<<endl;
		cout<< std::string( 44, '-' ) <<endl;
			
		cout<<"请选择指向的操作代码：" ;
	    cin>>dec>>i;
		switch(i)
		{
		case 0:  
			    isOpen=cticket.Ticket_CommOpen(); 
				if(isOpen==true)
				{ 
					/*bit=0x12;
					cout<<hex<<bit<<endl;
					cout<<bit<<endl;
					cout<<hex<<(int)bit<<endl;
					str="sfdf"&&(int)bit;
					cout<<str<<endl;*/
				  cout<<"打开串口成功！"<<endl;
				}
				else
				{
				  cout<<"打开串口失败！"<<endl;
				}
				break;
		case 1: isClose=cticket.Ticket_CommClose();
			    if(isClose==true)
				{
				  cout<<"关闭串口成功！"<<endl;
				}
				else
				{
				  cout<<"关闭串口失败！"<<endl;
				}
				break;
		case 2: BYTE SensorStatus[6];
			    iResult=cticket.Ticket_Poll(SensorStatus); 
				
				if(iResult==0)
				{

				 ///////////////////////////卡箱前到位光感 SensorStatus[0]
					bit=0x02;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					cout<<"卡向前不到位！"<<endl;
					}
					else
					{
						cout<<"卡向前到位！"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"前卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////卡箱后到位光感 SensorStatus[1]
					bit=0x02;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					   cout<<"卡向后不到位！"<<endl;
					}
					else
					{
						cout<<"卡向后到位！"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"后卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"后卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////其他到位光感 SensorStatus[2]
					bit=0x10;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"卡将空感未遮！"<<endl;
					}
					else
					{
						cout<<"卡将空感被遮！"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"当前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"当前卡箱空光感器被遮！"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"双卡光感器未遮！"<<endl;
					}
					else
					{
						cout<<"双卡光感器被遮！"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"卡出光感器未遮！"<<endl;
					}
					else
					{
						cout<<"卡出光感器被遮！"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"读写光感器未遮！"<<endl;
					}
					else
					{
						cout<<"读写光感器被遮！"<<endl;
					};				
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 3: cout<<"打开所有电机： 0"<<endl
					<<"刮卡电机测试： 1"<<endl
		            <<"换箱电机测试： 2"<<endl
					<<"传输电机测试： 3"<<endl
					<<"电磁铁测试：   4"<<endl
					
					<<"电机测是关闭： 5"<<endl					
					<<"请选择指向的操作代码：";
			    cin>>dec>>i;
				switch(i)
				{
					case 0: Index=0x00; 
				            break;
		            case 1: Index=0x01;
				            break;
					case 2: Index=0x02; 
				            break;
					case 3: Index=0x03; 
				            break;
		            case 4: Index=0x04;
				            break;
					case 5: Index=0x05; 
				            break;	
				};			  
			    iResult=cticket.Ticket_PowerTest(Index);
				if(iResult==0)
				{
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };                
				break;
		case 4: iResult=cticket.Ticket_Reset( );
			    if(iResult==0)
				{
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 5: BYTE Major;
			    BYTE Minor;			   
			    iResult=cticket.Ticket_GetVersion(Major,Minor); 
				if(iResult==0)
				{   
					BYTE major1,major2,minor1,minor2;
					major2=0x0F;
					major2&=Major;
					bit=Major>>4;
					major1=0x0F;
					major1&=bit;

					minor2=0x0F;
					minor2&=Major;
					bit=Minor>>4;
					minor1=0x0F;
					minor1&=bit;
					cout<<"主版本号:"<<(int)major1<<(int)major2<<"  副版本号："<<(int)minor1<<(int)minor2<<endl;
				    cout<<"主版本号:"<<hex<<(int)Major<<"  副版本号："<<hex<<(int)Minor<<endl;
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 6: cout<<"票箱1： 0"<<endl
		            <<"票箱2： 1"<<endl
					<<"票箱3： 2"<<endl
					<<"票箱4： 3"<<endl
					<<"请选择指向的操作代码：";
			    cin>>dec>>i;
				switch(i)
				{
					case 0: Box1=0x01;
				            break;
		            case 1: Box1=0x02;
				            break;
					case 2: Box1=0x03;
				            break;	
					case 3: Box1=0x04;
				            break;	
				};			  
			    BYTE Wrong;
				BYTE Data2[6];
			    iResult=cticket.Ticket_SendCard(Box1,Wrong,Data2);
				if(iResult==0)
				{   
				
				    bit=0x0F;
					bit&=Wrong;
					switch((int)bit)
					{
					case 1: cout<<"票箱空!"<<endl;
						  break;
                    case 2: cout<<"刮卡故障!"<<endl;
						  break;
					case 3: cout<<"传输故障!"<<endl;
						  break;
                    case 4: cout<<"双卡!"<<endl;
						  break;
					};
					 ///////////////////////////卡箱前到位光感 Data2[0]
					bit=0x02;
					bit&=Data2[0];
					if(bit==0x00)
					{   
					cout<<"卡向前不到位！"<<endl;
					}
					else
					{
						cout<<"卡向前到位！"<<endl;
					};
					bit=0x01;
					bit&=Data2[0];
					if(bit==0x00)
					{   
						cout<<"前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"前卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////卡箱后到位光感 Data2[1]
					bit=0x02;
					bit&=Data2[1];
					if(bit==0x00)
					{   
					   cout<<"卡向后不到位！"<<endl;
					}
					else
					{
						cout<<"卡向后到位！"<<endl;
					};
					bit=0x01;
					bit&=Data2[1];
					if(bit==0x00)
					{   
						cout<<"后卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"后卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////其他到位光感 Data2[2]
					bit=0x10;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"卡将空感未遮！"<<endl;
					}
					else
					{
						cout<<"卡将空感被遮！"<<endl;
					};
					bit=0x08;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"当前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"当前卡箱空光感器被遮！"<<endl;
					};
					bit=0x04;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"双卡光感器未遮！"<<endl;
					}
					else
					{
						cout<<"双卡光感器被遮！"<<endl;
					};
					bit=0x02;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"卡出光感器未遮！"<<endl;
					}
					else
					{
						cout<<"卡出光感器被遮！"<<endl;
					};
					bit=0x01;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"读写光感器未遮！"<<endl;
					}
					else
					{
						cout<<"读写光感器被遮！"<<endl;
					};			
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 7:  cout<<"通道1： 0"<<endl
		            <<"通道2： 1"<<endl
					<<"通道3： 2"<<endl
					<<"通道4： 3"<<endl
					<<"请选择指向的操作代码：";
			     cin>>dec>>i;
				 switch(i)
				 {
					case 0: Box=0x01;
				            break;
		            case 1: Box=0x02;
				            break;
					case 2: Box=0x03;
				            break;
					case 3: Box=0x04;
				            break;
				 };			 
			     cout<<"成功： 0"<<endl
		             <<"失败： 1"<<endl
					 <<"请选择指向的操作代码：";
				cin>>dec>>i;
				switch(i)
				{
					case 0: IsFail=0x01;
							break;
					case 1: IsFail=0x02;
							break;
					          				
				};			 
				BYTE Wrongcode;
				BYTE Data3[6];
			    iResult=cticket.Ticket_WriteRead(Box,IsFail,Wrongcode,Data3); 
				if(iResult==0)
				{   
					//BYTE major1,major2,minor1,minor2;
				    bit=0x0F;
					bit&=Wrongcode;
					switch((int)bit)
					{
					case 1: cout<<"票箱空!"<<endl;
						  break;
                    case 2: cout<<"刮卡故障!"<<endl;
						  break;
					case 3: cout<<"传输故障!"<<endl;
						  break;
                    case 4: cout<<"双卡!"<<endl;
						  break;
					};
						 ///////////////////////////卡箱前到位光感 Data3[0]
					bit=0x02;
					bit&=Data3[0];
					if(bit==0x00)
					{   
					cout<<"卡向前不到位！"<<endl;
					}
					else
					{
						cout<<"卡向前到位！"<<endl;
					};
					bit=0x01;
					bit&=Data3[0];
					if(bit==0x00)
					{   
						cout<<"前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"前卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////卡箱后到位光感 Data3[1]
					bit=0x02;
					bit&=Data3[1];
					if(bit==0x00)
					{   
					   cout<<"卡向后不到位！"<<endl;
					}
					else
					{
						cout<<"卡向后到位！"<<endl;
					};
					bit=0x01;
					bit&=Data3[1];
					if(bit==0x00)
					{   
						cout<<"后卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"后卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////其他到位光感 Data3[2]
					bit=0x10;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"卡将空感未遮！"<<endl;
					}
					else
					{
						cout<<"卡将空感被遮！"<<endl;
					};
					bit=0x08;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"当前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"当前卡箱空光感器被遮！"<<endl;
					};
					bit=0x04;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"双卡光感器未遮！"<<endl;
					}
					else
					{
						cout<<"双卡光感器被遮！"<<endl;
					};
					bit=0x02;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"卡出光感器未遮！"<<endl;
					}
					else
					{
						cout<<"卡出光感器被遮！"<<endl;
					};
					bit=0x01;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"读写光感器未遮！"<<endl;
					}
					else
					{
						cout<<"读写光感器被遮！"<<endl;
					};			
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 8: BYTE Wrong1;
			    BYTE Data4[6];
			    iResult=cticket.Ticket_ExchangeBox(Wrong1,Data4); 
				if(iResult==0)
				{   
					//BYTE major1,major2,minor1,minor2;
				    bit=0x0F;
					bit&=Wrong1;
					switch((int)bit)
					{
					case 1: cout<<"票箱空!"<<endl;
						  break;
                    case 2: cout<<"刮卡故障!"<<endl;
						  break;
					case 3: cout<<"传输故障!"<<endl;
						  break;
                    case 4: cout<<"双卡!"<<endl;
						  break;
					};
						 ///////////////////////////卡箱前到位光感 Data2[0]
					bit=0x02;
					bit&=Data4[0];
					if(bit==0x00)
					{   
					cout<<"卡向前不到位！"<<endl;
					}
					else
					{
						cout<<"卡向前到位！"<<endl;
					};
					bit=0x01;
					bit&=Data4[0];
					if(bit==0x00)
					{   
						cout<<"前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"前卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////卡箱后到位光感 Data4[1]
					bit=0x02;
					bit&=Data4[1];
					if(bit==0x00)
					{   
					   cout<<"卡向后不到位！"<<endl;
					}
					else
					{
						cout<<"卡向后到位！"<<endl;
					};
					bit=0x01;
					bit&=Data4[1];
					if(bit==0x00)
					{   
						cout<<"后卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"后卡箱空光感器被遮！"<<endl;
					};
					///////////////////////////其他到位光感 Data4[2]
					bit=0x10;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"卡将空感未遮！"<<endl;
					}
					else
					{
						cout<<"卡将空感被遮！"<<endl;
					};
					bit=0x08;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"当前卡箱空光感器未遮！"<<endl;
					}
					else
					{
						cout<<"当前卡箱空光感器被遮！"<<endl;
					};
					bit=0x04;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"双卡光感器未遮！"<<endl;
					}
					else
					{
						cout<<"双卡光感器被遮！"<<endl;
					};
					bit=0x02;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"卡出光感器未遮！"<<endl;
					}
					else
					{
						cout<<"卡出光感器被遮！"<<endl;
					};
					bit=0x01;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"读写光感器未遮！"<<endl;
					}
					else
					{
						cout<<"读写光感器被遮！"<<endl;
					};			
					cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 9: BYTE Data1[4];
			   iResult=cticket.Ticket_ReadId(Data1);
			   if(iResult==0)
			   {
				   cout<<"票箱1:"<<hex<<(int)Data1[0]<<"票箱2:"<<hex<<(int)Data1[1]
				       <<"票箱3:"<<hex<<(int)Data1[2]<<"票箱4:"<<hex<<(int)Data1[3]<<endl;				       
				   cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		case 10:Data5[0]=0x01;
			    Data5[1]=0x02;
			    Data5[2]=0x03;
			    Data5[3]=0x04; 
			    iResult=cticket.Ticket_WriteId(Data5); 
				if(iResult==0)
			   {
				cout<<"命令执行成功！"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"命令执行超时！"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"设备状态忙！"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"命令执行失败！"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"解包出错请求重发！"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"端口未打开！"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"命令发送失败"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"返回报文命令或者序列号有错！"<<endl;
                };
				break;
		/*case 11:cout<<"请输入小于等于0xFF的值,如欲结束请输入Ox100:";
				cin>>hex>>pre;
				while(pre<256)
				{
					pre1=(BYTE)pre;
					m_PreResult.push_back(pre1);
					cout<<"请输入小于等于0xFF的值,如欲结束请输入Ox100:";
					cin>>hex>>pre;	    
				}
				break;*/
				
		case 12: is=false;
				 break;
		}
	}

    system("pause");
	return 0;
}



//
int test_many_keyinput()
{
	for( int i = 0 ; i < 999944 ; i ++ )
	{
		de_frontinput_t  *p;
		de_frontinput_t   f;

		p = &f;
		p->FrontInit(9999);
	}
	return 0;
}


void test_double()
{
    double *p1=(double*)100;
    double *p2=(double*)117;
    printf("%d\n",p1-p2);
    printf("%d\n",p2-p1);
}



void test_send6002aa()
{
	a6002_t::ROWTYPE r;

	r.m_lTicketTradeTerminalFlow = 1;
	gp_db->m_a6002.Add( r );

	r.m_lTicketTradeTerminalFlow = 2;
	gp_db->m_a6002.Add( r );
	 
	r.m_lTicketTradeTerminalFlow = 3;
	gp_db->m_a6002.Add( r );


	gp_tcpmsg->SendTrade6002_range( 1, 3 );
}



void test_printer()
{
	gp_printer->PrintLineAsync( "“a”为了减缓全球变暖的趋势，科学家们想尽了各种办法，而有人则提出了阻挡太阳光进入地球的想法，这可行吗？我们究竟该做些什么？用改装过的飞机喷射出硫酸就可以让北极上空的天空保持灰霾状态好几年，“而这只需要制作一部好莱坞大片的费用”，哈佛大学的物理学家戴维&#8226;基思（DavidKeith）如此说道。他还断言，只需花10亿美元，就能让整个地球在2020年左右被硫酸液滴包裹。" );
	gp_printer->HalfCutAsync();

	while(1)
		WThrd::tr_sleep(3);
}



void test_top_scr()
{
	gp_topscr->DispStr( "上海地铁的吉祥物是畅畅。畅畅是一个来自未来的小机器人，圆润的流线型动感十足，微笑的眼睛透露亲切，现代化的装备科技十足，体内蕴含着热情与力量。畅畅的设计，演绎出上海地铁与都市的密切关系，现代、动感、时尚。畅畅，是上海地铁的形象化身，微笑自信的表情诠释出上海地铁积极进取无限开拓的品牌形象。" );

	while(1)
		WThrd::tr_sleep(3);
}




void test_emt_ticket1()
{
	gp_emitticket->MkTicketReady();
	
	gp_emitticket->eTicket_SendOut();

	gp_emitticket->eTicket_SendIn();

	gp_emitticket->eTicket_ExchangeBox();


	while(1)
		WThrd::tr_sleep(3);
}



void test_read_card()
{
	gp_reader1->rReadCard();
	gp_reader1->rAbort();

	gp_reader1->rSaleCard2( 100 );


	while(1)
		WThrd::tr_sleep(3);
}

// [in]  iToBeChange 找零金额 (以分为单位)
// [in]  iRMB50 硬币循环箱中5角个数
// [in]  iRMB100 硬币循环箱中1元个数
// [in]  iRMB500 纸币循环箱中5元个数   (纸币箱中数据目前为0，需后面再弄)
// [in]  iRMB1000 纸币循环箱中10元个数
// [in]  iRMB2000 纸币循环箱中20元个数
// [in]  iRMB5000 纸币循环箱中50元个数
// [out] iChangeCoin  可以找零的硬币钱数   -> ,但硬币底层给的是找零个数，所以在外面仍需要转化为个数 (以分为单位)
// [out] iChangeBill  可以找零的纸币钱数  (以元为单位)
// returnvalue :
// true:正常找零
// false:不能找零
bool isChangeOK( int iToBeChange, int iRMB50, int iRMB100, int iRMB500, int iRMB1000, int iRMB2000,int iRMB5000, long *iChangeCoin /*= NULL*/ ,long *iChangeBill /*= NULL*/ )
{

	int n50, n100, n500, n1000, n2000, n5000;
	n50 = n100 = n500 = n1000 = n2000 = n5000 = 0;
	if( 1 != gp_bill->m_iIsNotBillChange )
	{
		//判断50元
		n5000 = iToBeChange/5000;
		if( iRMB5000 < n5000 )
		{
			iToBeChange -= 5000 *  iRMB5000;
			n5000 = iRMB5000;
		}
		else
		{
			iToBeChange -= 5000 * n5000;
		}

		//判断20元
		n2000 = iToBeChange/2000;
		if( iRMB2000 < n2000 )
		{
			iToBeChange -= 2000 *  iRMB2000;
			n2000 = iRMB2000;
		}
		else
		{
			iToBeChange -= 2000 * n2000;
		}

		//判断10元
		n1000 = iToBeChange/1000;
		if( iRMB1000 < n1000 )
		{
			iToBeChange -= 1000 *  iRMB1000;
			n1000 = iRMB1000;
		}
		else
		{
			iToBeChange -= 1000 * n1000;
		}

		//判断5元
		n500 = iToBeChange/500;
		if( iRMB500 < n500 )
		{
			iToBeChange -= 500 *  iRMB500;
			n500 = iRMB500;
		}
		else
		{
			iToBeChange -= 500 * n500;
		}
	}

	//判断1元
	n100 = iToBeChange/100;
	if( iRMB100 < n100 )
	{
		iToBeChange -= 100 *  iRMB100;
		n100 = iRMB100;
	}
	else
	{
		iToBeChange -= 100 * n100;
	}

	//判断5角
	n50 = iToBeChange/50;
	if( iRMB50 < n50 )
	{
		iToBeChange -= 50 *  iRMB50;
		n50 = iRMB50;
	}
	else
	{
		iToBeChange -= 50 * n50;
	}

	LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "iToBeChange=" << iToBeChange <<" coinnum="<<n100 + n50 <<" m_CoinChgMaxNum="<<wl::SStrf::sltoa(gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum)<<
		      " billnum="<<n500 + n1000 + n2000 + n5000 <<" m_BillChgMaxNum="<<wl::SStrf::sltoa(gp_db->m_a3003.GetRow(0).m_BillChgMaxNum) );


	if( (iToBeChange == 0 ) && 
		( ( n100 + n50 ) <= gp_db->m_a3003.GetRow(0).m_CoinChgMaxNum ) &&
		( n500 + n1000 + n2000 + n5000 ) <= gp_db->m_a3003.GetRow(0).m_BillChgMaxNum )
	{
		if( iChangeCoin != NULL && iChangeBill != NULL )
		{
			*iChangeCoin = (long)(n100*100 + n50*50);
			*iChangeBill = (long)(n500*5 + n1000*10 + n2000*20 + n5000*50);
		}
		return true;
	}
	
	return false;
}

// [in]  iChangeLimit 找零金额 (以分为单位)
// [out] iChangeCoin  可以找零的硬币钱数   -> ,但硬币底层给的是找零个数，所以在外面仍需要转化为个数 (以分为单位)
// [out] iChangeBill  可以找零的纸币钱数  (以元为单位)
bool CanChange( int iChangeLimit /*= 4900*/ ,long *iChangeCoin /*= NULL*/ ,long *iChangeBill /*= NULL*/  )
{
	bool ret = true;
	if( iChangeLimit < 50 )   //小于5角
	{
		LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "Invalid Change:" << iChangeLimit );
		return 0;
	}

	int iRMB50 ,iRMB100 ,iRMB500 ,iRMB1000 ,iRMB2000 ,iRMB5000;
	iRMB50 = iRMB100 = iRMB500 = iRMB1000 = iRMB2000 = iRMB5000 = 0;
	
	b8701_t::ROWTYPE rcoin;
	if(1)
	{
		MYAUTOLOCK( gp_db->m_b8701.m_ut_tbl_lck );
		rcoin = gp_db->m_b8701.GetRow(0);
	}

	b8702_t::ROWTYPE rbill;
	if(1)
	{
		MYAUTOLOCK( gp_db->m_b8702.m_ut_tbl_lck );
		rbill = gp_db->m_b8702.GetRow(0);
	}
		
	iRMB50  = rcoin.m_A5MaoCycleChg /*+ rcoin.m_A5MaoSpecialChg*/ ;
	iRMB100 = rcoin.m_A1YuanCycleChg /*+ rcoin.m_A1YuanSpecialChg*/ ;
	gp_bill->dBill_QueryCashUint();
	for(int i=0;i<4;i++)
	{
		if( rbill.m_ReDenomination.a[i] == 500 )  iRMB500  = rbill.m_ReNumber.a[i];
		if( rbill.m_ReDenomination.a[i] == 1000 ) iRMB1000 = rbill.m_ReNumber.a[i];
		if( rbill.m_ReDenomination.a[i] == 2000 ) iRMB2000 = rbill.m_ReNumber.a[i];
		if( rbill.m_ReDenomination.a[i] == 5000 ) iRMB5000 = rbill.m_ReNumber.a[i];
	}

	// 判断每个档位的面额
	if( iChangeLimit == 4900 )
	{
		for (int i=100;i<=iChangeLimit;i+=100)
		{
			if ( !isChangeOK( i, iRMB50, iRMB100, iRMB500, iRMB1000, iRMB2000,iRMB5000,iChangeCoin,iChangeBill ) )
			{
				ret = false;
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "cannot change:" << i );
				break;
			}
		}
	}
	else
	{
		return isChangeOK( iChangeLimit, iRMB50, iRMB100, iRMB500, iRMB1000, iRMB2000,iRMB5000 ,iChangeCoin,iChangeBill );
	}
	
	return ret;


}

void AddTransDataTo6000( a_waiter_t_rowtype & pwaiterdata )
{
	LOGSTREAM( gp_log[LOGAPP], LOGPOSI );

	//购票是属于哪个票价区域
	//求出row4002
	a4002_t::ROWTYPE  row4002;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4002.m_ut_tbl_lck );
		a4002_t::RPSTYPE rps[9];

		//row4002_out = a4002_t::ROWTYPE();

		gp_db->m_a4002.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a4002.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a4002.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a4002.GetRowCount( rps[3] ) == 0 ) return ;

		gp_db->m_a4002.SelEc_TicketType( 100, rps[1] );
		gp_db->m_a4002.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a4002.GetRowCount( rps[4] ) == 0 ) return ;

		row4002 = gp_db->m_a4002.GetRow( rps[4], 0 );
	}

	//求出row4003
	a4003_t::ROWTYPE  row4003;

	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4003.m_ut_tbl_lck );
		a4003_t::RPSTYPE rps[9];

		gp_db->m_a4003.SelEc_biDelFlag( 0, rps[1] ); 
		gp_db->m_a4003.SelEc_biIsAffect( 1, rps[2] ); 
		gp_db->m_a4003.RpsAnd( rps[1], rps[2], rps[3] );
		if( gp_db->m_a4003.GetRowCount( rps[3] ) == 0 ) return ;

		gp_db->m_a4003.SelEc_lFareRateIdx( row4002.m_B0_FullFareRateIdx, rps[1] );
		gp_db->m_a4003.RpsAnd( rps[1], rps[3], rps[4] );
		if( gp_db->m_a4003.GetRowCount( rps[4] ) == 0 ) return ;

		row4003 = gp_db->m_a4003.GetRow( rps[4], 0 );
	}

	//遍历4004，根据zone求出4003中的价格,再group
	if(1)
	{
		MYAUTOLOCK( gp_db->m_a4004.m_ut_tbl_lck );
		
		for( long i = 0; i < gp_db->m_a4004.GetRowCount(); i++ )
		{
			int z;
			a4004_t::ROWTYPE & row4004(gp_db->m_a4004.GetRow(i));

			if( row4004.m_biDelFlag != 0 ) continue;
			if( row4004.m_biIsAffect != 1 ) continue;

			if(1)
			{
					z = row4003.m_FareRate.a[row4004.m_lZone] / 100 ;

					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << "cacl 6000=m_lZone = :" << row4004.m_lZone<<" z="<<z <<" m_TickePrice1="<< pwaiterdata.m_TickePrice1 );

					if( pwaiterdata.m_TickePrice1 != z )
					{
						continue;
					}

					//找到区域，将6000中对应区域填值

					gp_db->m_a6000.GetRow(0).m_Reg.a[ row4004.m_lZone ] += pwaiterdata.m_TicketoutActual;
					gp_db->m_a6000.GetRow(0).m_Reg.a[ 21 + row4004.m_lZone ] += ( pwaiterdata.m_TicketoutActual* pwaiterdata.m_TickePrice1 / 100 );
					gp_db->m_a6000.GetRow(0).m_Reg.a[ 42 ] += pwaiterdata.m_ReceiveCoin / 100;
					gp_db->m_a6000.GetRow(0).m_Reg.a[ 43 ] += pwaiterdata.m_ReceiveBill / 100;
					gp_db->m_a6000.GetRow(0).m_Reg.a[ 44 ] += pwaiterdata.m_CoinRecycleChgActual /*+ pwaiterdata.m_CoinSpecialChgActual*/;
					gp_db->m_a6000.GetRow(0).m_Reg.a[ 45 ] += pwaiterdata.m_BilchgActual;
					break;

			}

		}

	}


}


void AddMachineDataTo6000()
{
	LOGSTREAM( gp_log[LOGAPP], LOGPOSI );

	long lBillVaultAmount = 0;
	long lBillChgBoxAmount = 0;

	gp_bill->dBill_QueryCashUint();

	b8702_t::ROWTYPE rbill;
	if(1)
	{
		MYAUTOLOCK( gp_db->m_b8702.m_ut_tbl_lck );
		rbill = gp_db->m_b8702.GetRow(0);
	}

	for(int i=0;i<4;i++)
	{
		if( rbill.m_ReDenomination.a[i] == 500 )  lBillChgBoxAmount += rbill.m_ReNumber.a[i] * 5;
		if( rbill.m_ReDenomination.a[i] == 1000 ) lBillChgBoxAmount += rbill.m_ReNumber.a[i] * 10;
		if( rbill.m_ReDenomination.a[i] == 2000 ) lBillChgBoxAmount += rbill.m_ReNumber.a[i] * 20;
		if( rbill.m_ReDenomination.a[i] == 5000 ) lBillChgBoxAmount += rbill.m_ReNumber.a[i] * 50;
	}

	lBillVaultAmount = rbill.m_Pieces.a[5] * 5   + rbill.m_Pieces.a[10] * 10 +
		               rbill.m_Pieces.a[20] * 20 + rbill.m_Pieces.a[50] * 50 +
					   rbill.m_Pieces.a[100] * 100;


	gp_db->m_a6000.GetRow(0).m_Reg.a[ 46 ] = gp_db->m_b8701.GetRow(0).m_A1YuanStoreBox;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 47 ] = gp_db->m_b8701.GetRow(0).m_A1YuanStoreBox / 2;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 48 ] = 0;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 49 ] = gp_db->m_b8701.GetRow(0).m_A1YuanCycleChg;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 50 ] = gp_db->m_b8701.GetRow(0).m_A5MaoCycleChg / 2;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 51 ] = lBillVaultAmount;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 52 ] = lBillChgBoxAmount;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 53 ] = 0;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 54 ] = 0;
	gp_db->m_a6000.GetRow(0).m_Reg.a[ 55 ] = 0;
}


int ReturnCoinAndBill( a_waiter_t_rowtype&  waiter_data )
{
	
	if(waiter_data.m_ReceiveCoin >0)
	{
		gp_coin->returnCoin();//退硬币
		//waiter_data.m_ReceiveCoin = 0;
		//waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveBill;
	}

	if(waiter_data.m_ReceiveBill >0)
	{
		gp_bill->dBill_Refund();//add by jfren @20161122
		//waiter_data.m_ReceiveBill = 0;
		//waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveCoin;

		//只需要有纸币
		bu_quickflow_t::qf_counter_t  iQf1_user_idle;
		double iQf1_user_idleMAX = 15;

		gp_qf->GetQf( iQf1_user_idle );

		while(1)
		{
			if( 0 == gp_db->m_b8702.GetRow(0).m_wReturnShutter ||
				gp_qf->IsLongQf( iQf1_user_idle , iQf1_user_idleMAX ) )
			{
				//未来将是要将纸币喷出
				break;
			}
			
		}
	}

	
}
