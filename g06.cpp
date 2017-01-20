
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
		//gp_ui->LabelPrepStr( "3", "����-" + SStrf::sltoa(i), 0.1, 0.2 );
		//gp_ui->LabelPrintPrep( "a", "bbbbbbb", 0.1, 0.3, 0.2 );
		//gp_ui->LabelPrintPrep( "c", "����һ����������һ������", 0.0, 0.0, 0.3 );
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
	//gp_ui->LabelPrepStr( "3", "��", 0.02, 0.92 );
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

	//	gp_ui->LabelPrepStr( "3", "����:" + s1, 0.01, 0.92 );
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
	
	//����
	BYTE bit;
	bool isOpen,isClose;
	int iResult;
	//
	
	while(is)
	{
		cout<< "------------------------------------------------------------------------------" <<endl
			<<"�򿪴��ڣ�						0"<<endl
			<<"�رմ��ڣ�						1"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"Ӳ��ģ��״̬��ѯ��   2"<<endl
			<<"Ӳ��ģ��������   3"<<endl
			<<"Ӳ��ģ�����λ��   4"<<endl
			<<"Ӳ��ģ�����汾��ѯ��  5"<<endl
			<<"Ӳ��ģ���������      7"<<endl
			<<"ѭ�������䡢ר�����������������    71"<<endl
			<<"Ӳ��ģ��������    8"<<endl
			<<"ѭ�������䡢ר����������ҽ������81"<<endl
			<<"Ӳ��ģ�������������    9"<<endl
			<<"Ӳ��ʶ������ѯ��           10"<<endl
			<<"Ӳ��ģ�鲹����ӱ����    11"<<endl
			<<"Ӳ��ģ���豸��Ʊ�����IDд��� 12"<<endl
			<<"Ӳ��ģ���豸��Ʊ�����ID����� 13"<<endl  
			<<"Ӳ�һ�����д���   14"<<endl
			<<"Ӳ�һ���������   15"<<endl			
		    <<"///////////////////////////////////////////////////////////////"<<endl
			<<"Ӳ��ģ�����������       16"<<endl
			<<"Ӳ��ģ���̿�ʼ���       17"<<endl
			<<"Ӳ��ģ�鷢�ͱ���������   18"<<endl
			<<"Ӳ��ģ���̽������       19"<<endl
			<<"Ӳ��ģ���л���Ӧ�ó������ 20"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"Ԥ���õķ��ر��ģ� 21"<<endl
			<<"�˳�����         22"<<endl
			<<"///////////////////////////////////////////////////////////////"<<endl
			<<"��ѡ��ָ��Ĳ������룺";
	    cin>>dec>>i;
		switch(i)
		{
		case 0: 
				cout<< gp_conf->Get_coin_com_port() <<endl;
			    isOpen=coinmodule.Coin_CommOpen(); 
				if(isOpen==true)
				{
				  cout<<"�򿪴��ڳɹ���"<<endl;
				}
				else 
				{
				cout<<"�򿪴���ʧ�ܣ�"<<endl;
				}
				break;
		case 1: isClose=coinmodule.Coin_CommClose();
			    if(isClose==true)
				{
				  cout<<"�رմ��ڳɹ���"<<endl;
				}
				else 
				{
				cout<<"�رմ���ʧ�ܣ�"<<endl;
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
						cout<<"Ӳ��ģ�鵽λ��"<<endl;
					}
					else
					{
						cout<<"Ӳ��ģ��δ��λ��"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"ֽ����������λ��"<<endl;
					}
					else
					{
						cout<<"ֽ��������δ��λ��"<<endl;
					};
					/*bit=0x04;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"Ͷ�ҿ�״̬�رգ�"<<endl;
					}
					else
					{
						cout<<"Ͷ�ҿ�״̬�򿪣�"<<endl;
					};*/
					bit=0x08;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"ѭ����������λ��"<<endl;
					}
					else
					{
						cout<<"ѭ��������δ��λ��"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"UPS�ϵ��źŵ�λ��"<<endl;
					}
					else
					{
						cout<<"UPS�ϵ��ź�δ��λ��"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"��ҷ�����ת������˱�λ�õ�λ��"<<endl;
					}
					else
					{
						cout<<"��ҷ�����ת������˱�λ��δ��λ��"<<endl;
					};
					bit=0x40;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					    cout<<"5�ǲ����䵽λ��"<<endl;
					}
					else
					{
						cout<<"5�ǲ�����δ��λ��"<<endl;
					};
					bit=0x80;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					cout<<"1Ԫ�����䵽λ��"<<endl;
					}
					else
					{
					cout<<"1Ԫ������δ��λ��"<<endl;
					};

					//...............1
					bit=0x01;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"�ŵ�λ��"<<endl;
					}
					else
					{
						cout<<"��δ��λ��"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"������λ��"<<endl;
					}
					else
					{
						cout<<"����δ��λ��"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"�ݴ�ѭ��բ�Źرգ�"<<endl;
					}
					else
					{
						cout<<"�ݴ�ѭ��բ�Ŵ򿪣�"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"�ݴ��˱�բ�Źرգ�"<<endl;
					}
					else
					{
						cout<<"�ݴ��˱�բ�Ŵ򿪣�"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"��������ϣ�"<<endl;
					}
					else
					{
						cout<<"�����δ���ϣ�"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"����ģ�鵽λ��λ��"<<endl;
					}
					else
					{
						cout<<"����ģ�鵽λδ��λ��"<<endl;
					};
					bit=0x40;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					   cout<<"�������ȹأ�"<<endl;
					}
					else
					{
						cout<<"�������ȿ���"<<endl;
					};
					bit=0x80;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					cout<<"ȡƱ�������أ�"<<endl;
					}
					else
					{
					cout<<"ȡƱ����������"<<endl;
					};
					//................2
					bit=0x04;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"Ͷ�ҿ�״̬�رգ�"<<endl;
					}
					else
					{
						cout<<"Ͷ�ҿ�״̬�򿪣�"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"Ͷ����ڹ���ڵ���"<<endl;
					}
					else
					{
						cout<<"Ͷ����ڹ��û�ڵ���"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"Ͷ�ҷϱҳ��ڹ���ڵ���"<<endl;
					}
					else
					{
						cout<<"Ͷ�ҷϱҳ��ڹ��û�ڵ���"<<endl;
					};
					//...........3
					bit=0x01;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"Ӳ�һ������λ�ź�3��λ��"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ������λ�ź�3δ��λ��"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"Ӳ�һ������λ�ź�2��λ��"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ������λ�ź�2δ��λ��"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"Ӳ�һ������λ�ź�1��λ��"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ������λ�ź�1δ��λ��"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
						cout<<"Ӳ�һ����䵽λ��λ��"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ����䵽λδ��λ��"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
					   cout<<"Ӳ�һ�����������"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ�����£�"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[3];
					if(bit==0x00)
					{   
					cout<<"Ӳ�һ�����������"<<endl;
					}
					else
					{
					cout<<"Ӳ�һ���������"<<endl;
					};
					//....................4 1Ԫѭ��������״̬
					bit=0x04;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[4];
					if(bit==0x00)
					{   
						cout<<"����������λ��"<<endl;
					}
					else
					{
						cout<<"��������δ��λ��"<<endl;
					};
					//..................5 5��ѭ��������״̬
					bit=0x04;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[5];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					//..............6 1Ԫר��������״̬
					bit=0x04;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					bit=0x20;
					bit&=SensorStatus[6];
					if(bit==0x00)
					{   
						cout<<"����������λ��"<<endl;
					}
					else
					{
						cout<<"��������δ��λ��"<<endl;
					};
					//..............7 5��ר��������״̬
					bit=0x04;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=SensorStatus[7];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};


					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
        else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
				}
				else if(iResult==-3)
				{
					cout<<"�����ʧ�ܣ�"<<endl;
				}
				else if(iResult==-4)
				{
					cout<<"���ر�������������кŴ���"<<endl;
				}
				break;
		case 3:	cout<<"0x11��1Ԫ�ӱ�����������"<<endl
                    <<"0x12��5�Ǽӱ�����������"<<endl
					<<"0x13��1Ԫѭ����������������"<<endl
					<<"0x14��5��ѭ����������������"<<endl
					<<"0x15��1Ԫ��������������"<<endl
					<<"0x16��5�ǲ�������������"<<endl
					<<"0x17��1Ԫ�ӱ���������(�������תȻ��ת)"<<endl
					<<"0x18��5�Ǽӱ���������(�������תȻ��ת)"<<endl
					<<"0x19��1Ԫѭ��������������(�������תȻ��ת)"<<endl
					<<"0x1A��5��ѭ��������������(�������תȻ��ת)"<<endl
					<<"0x1B��1Ԫ������������(�������תȻ��ת)"<<endl
					<<"0x1C��5�ǲ�����������(�������תȻ��ת)"<<endl
					<<"0x00��ֹͣ���ж���"<<endl;
			        cout<<"��ѡ����Եĵ��������";
					cin>>hex>>index;
					Test[0]=(BYTE)index;
					Test[1]=0x11;
			        iResult=coinmodule.Coin_Test(Test);	
					if(iResult==0)
					{
						cout<<"����ִ�гɹ���"<<endl;
					}
					else if(iResult==-1)
					{
						cout<<"����ִ�г�ʱ��"<<endl;
					}
					else if(iResult==80)
					{
						cout<<"�豸״̬æ��"<<endl;
					}
					else if(iResult==98)
					{
						cout<<"����ִ��ʧ�ܣ�"<<endl;
					}
					else if(iResult==99)
					{
						cout<<"������������ط���"<<endl;
					}
					else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
	    case 4: iResult=coinmodule.Coin_Reset();
			    if(iResult==0)
				{  
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
				}
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
				}
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				{
				  	cout<<"�˿�δ�򿪣�"<<endl;
				}
				else if(iResult==-3)
				 {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 5: iResult=coinmodule.Coin_GetVersion(Major,Minor);
			   if(iResult==0)
				{   
				    cout<<"���汾��:"<<hex<<(int)Major<<"  ���汾�ţ�"<<hex<<(int)Minor<<endl;
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 71: cout<<"0x01��1Ԫѭ�����㣻0x02��5��ѭ�����㣻0x04��1Ԫר�����㣻0x08��5��ר������"<<endl;
			     cout<<"��ѡ�����������";
			     cin>>hex>>index;
			    End=(BYTE)index;
				iResult=coinmodule.Coin_End_Change(End);
				if(iResult==0)
				{   
				    cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  };
				break;
		case 7: cout<<"0x01��1Ԫѭ�����㣻0x02��5��ѭ�����㣻0x04��1Ԫר�����㣻0x08��5��ר������"<<endl;
			    cout<<"��ѡ�����������";
			    cin>>hex>>index;
			    Change1[0]=(BYTE)index;
			   /* cout<<"0xAB��A���� 0xBB��B����";
				cin>>hex>>index;
			    Change1[1]=(BYTE)index;*/
				cout<<"�밴ʮ������������������1~48��";
				cin>>hex>>index;
			    Change1[1]=(BYTE)index;
			    iResult=coinmodule.Coin_Change(Change1,Change2);
				 if(iResult==0)
				{   
					//...............0
				    switch(Change2[0])
					{
					case 0x01:cout<<"1Ԫѭ������"<<endl;
						     break;
					case 0x02:cout<<"5��ѭ������"<<endl;
					break;
					case 0x04:cout<<"1Ԫר������"<<endl;
					break;
					case 0x08:cout<<"5��ר������"<<endl;
					break;					
					};
					//................1
					cout<<"��������"<<(int)Change2[1]<<endl;
					//................2
					bit=0x01;
					bit&= Change2[2];
					if(bit==0x00)
					{   
						cout<<"������û�գ�"<<endl;
					}
					else
					{
						cout<<"ѭ���������ר��������գ�"<<endl;
					};
					bit=0x02;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"û�й��ϣ�"<<endl;
					}
					else
					{
						cout<<"�����㶷����)��(���㶷���Ҽ����ݴ�����δ��úͻ�)��(���㶷����ͨ������) ��"<<endl;
					};
                    bit=0x04;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					bit=0x20;
					bit&=Change2[2];
					if(bit==0x00)
					{   
						cout<<"��ѡ���������ģ��λ����λ��"<<endl;
					}
					else
					{
						cout<<"��ѡ���������ģ��λ��δ��λ��"<<endl;
					};
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 81: cout<<"0x01��1Ԫѭ�����㣻0x02��5��ѭ�����㣻0x04��1Ԫר�����㣻0x08��5��ר������"<<endl;
			     cout<<"��ѡ����Ҳ�����";
			     cin>>hex>>index;
			    End=(BYTE)index;
				iResult=coinmodule.Coin_End_Clean(End);
				if(iResult==0)
				{   
				    cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
			    break;
		case 8: cout<<"0x01��1Ԫѭ�����㣻0x02��5��ѭ�����㣻0x04��1Ԫר�����㣻0x08��5��ר������"<<endl;
			    cout<<"��ѡ��Ҳ�����";
			    cin>>hex>>index;
			    Clean1=(BYTE)index;
			    iResult=coinmodule.Coin_Clean(Clean1,Clean2,count);
				if(iResult==0)
				{
					//...............0
				    switch(Clean2[0])
					{
					case 0x01:cout<<"1Ԫѭ������"<<endl;
						     break;
					case 0x02:cout<<"5��ѭ������"<<endl;
					         break;
					case 0x04:cout<<"1Ԫר������"<<endl;
					         break;
					case 0x08:cout<<"5��ר������"<<endl;
					         break;					
					};
					////................1
					//cout<<"������ݸ�λ��"<<(int)Clean2[1]<<endl;
					////................2
					//cout<<"������ݵ�λ��"<<(int)Clean2[2]<<endl;
					//................1
					bit=0x01;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"������û�գ�"<<endl;
					}
					else
					{
						cout<<"������򲹱���գ�"<<endl;
					};
					bit=0x02;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"û�й��ϣ�"<<endl;
					}
					else
					{
						cout<<"��(���㶷����)��(���㶷���Ҽ����ݴ�����δ��úͻ�)��(���㶷����ͨ������)��"<<endl;
					};
                    bit=0x04;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					bit=0x20;
					bit&= Clean2[1];
					if(bit==0x00)
					{   
						cout<<"ѭ��������򲹳�������ģ��λ����λ��"<<endl;
					}
					else
					{
						cout<<"ѭ��������򲹳�������ģ��λ��δ��λ��"<<endl;
					};
					cout<<"���������Ŀ��"<<count<<endl;
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 9: cout<<"��һ�����ݵ�ÿһλ���ܣ�"<<endl;
			    cout<<"Bit7-6:δʹ��"<<endl
					<<"Bit5:=1/0   1��Դ�俪�ؿ���������"<<endl
					<<"Bit4:=1/0   Ԥ��"<<endl
					<<"Bit3:=1/0   1���ҽ�����������0ͣ"<<endl
					<<"Bit2:=1/0   1�ݴ淭������� 0�˱�"<<endl
					<<"Bit1:=1/0   1�ݴ����˱�բ�ſ���0��"<<endl
					<<"Bit0:=1/0   1�ݴ�ѭ������բ�ſ���0��"<<endl;
			   cout<<"������һ��ʮ����������";
			   cin>>hex>>index;
			   Open1[0]=(BYTE)index;
			   cout<<"�ڶ������ݵ�ÿһλ���ܣ�"<<endl;
			   cout<<"Bit7~bit6:δʹ��"<<endl
					<<"Bit5-4��11���˿���ʾ��������01�س˿���ʾ��������00���ı�"<<endl
					<<"Bit3-2��11��ȡƱ��������01��ȡƱ��������00���ı�"<<endl
					<<"Bit1-0��11����������01�ر�������00���ı�"<<endl;
			   cout<<"������һ��ʮ����������";
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
						cout<<"�ݴ�ѭ��բ�Źأ�"<<endl;
					}
					else
					{
						cout<<"�ݴ�ѭ��բ�ſ���"<<endl;
					};
					bit=0x02;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"�ݴ��˱�բ�Ź�!"<<endl;
					}
					else
					{
						cout<<"�ݴ��˱�բ�ſ���"<<endl;
					};
                    bit=0x04;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"�˱ң�"<<endl;
					}
					else
					{
						cout<<"�ݴ淭������գ�"<<endl;
					};
					bit=0x08;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"���ҽ�����δ��λ��"<<endl;
					}
					else
					{
						cout<<"���ҽ����ﵽλ��"<<endl;
					};
					bit=0x20;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"��Դ�俪�عأ�"<<endl;
					}
					else
					{
						cout<<"��Դ�俪�ؿ���"<<endl;
					};
					bit=0x40;
					bit&=Open2[0];
					if(bit==0x00)
					{   
						cout<<"���բ������"<<endl;
					}
					else
					{
						cout<<"���բ�쳣�����ȫ����ȫ������"<<endl;
					};
					//...................1
					 bit=0x01;
					bit&= Open2[1];
					if(bit==0x00)
					{   
						cout<<"�������أ�"<<endl;
					}
					else
					{
						cout<<"����������"<<endl;
					};
					bit=0x02;
					bit&=Open2[1];
					if(bit==0x00)
					{   
						cout<<"ȡƱ�������أ�"<<endl;
					}
					else
					{
						cout<<"ȡƱ����������"<<endl;
					};
                    bit=0x04;
					bit&=Open2[1];
					if(bit==0x00)
					{   
						cout<<"�˿���ʾ�������أ�"<<endl;
					}
					else
					{
						cout<<"�˿���ʾ����������"<<endl;
					};

			   	   cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 10:cout<<"���ݵ�ÿһλ���ܣ�"<<endl;
			   cout<<"Bit7-6:δʹ��"<<endl
					<<"Bit3: =1/0  1 Ͷ�ҿ�բ�Ŵ򿪣� 0բ�Źر�"<<endl
					<<"Bit2:=1/0  1 ���Ӳ�Ҽ����Ĵ�����0�����"<<endl
					<<"Bit1:=1/0  1 ��ֹ5�ǣ� 0����5��"<<endl
					<<"Bit0:=1/0  1 ��ֹ1Ԫ�� 0����1Ԫ"<<endl;					
			   cout<<"������һ��ʮ����������";
			   cin>>hex>>index;
			   Poll=(BYTE)index;
			   iResult=coinmodule.Coin_Poll(Poll,Poll1);
			   if(iResult==0)
			   {
				   //...........0
				   cout<<"���ܵ�1ԪӲ������"<<(int)Poll1[0]<<endl;
				   //...........1
				   cout<<"���ܵ�5��Ӳ������"<<(int)Poll1[1]<<endl;
				   //...........2
				   bit=0x01;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"�ѽ���1Ԫ��"<<endl;
					}
					else
					{
						cout<<"�ѽ�ֹ1Ԫ��"<<endl;
					};
				   bit=0x02;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"�ѽ���5�ǣ�"<<endl;
					}
					else
					{
						cout<<"�ѽ�ֹ5�ǣ�"<<endl;
					};
				   bit=0x04;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"Ͷ�ҿ�բ��δ�򿪣�"<<endl;
					}
					else
					{
						cout<<"Ͷ�ҿ�բ���Ѵ򿪣�"<<endl;
					};
				   bit=0x08;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"Ӳ��ʶ���������ڣ�"<<endl;
					}
					else
					{
						cout<<"Ӳ��ʶ�������ڣ�"<<endl;
					};
				   bit=0x10;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"Ӳ�ҽ���ͨ��������"<<endl;
					}
					else
					{
						cout<<"Ӳ�ҽ���ͨ�����ϣ�"<<endl;
					};
				    bit=0x20;
				   bit&=Poll1[2];
				   if(bit==0x00)
					{   
						cout<<"Ӳ�һ�����ͨ��������"<<endl;
					}
					else
					{
						cout<<"Ӳ�һ�����ͨ����/�£�"<<endl;
					};

			      cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 11:cout<<"0x01��1Ԫ�����䣻  0x02��5�ǲ�����"<<endl;
			    cout<<"��ѡ�񲹱��䣺";
			    cin>>hex>>index;
			    Add1=(BYTE)index;			    
			    iResult=coinmodule.Coin_Add(Add1,Add2,count);
				if(iResult==0)
				{  
					//..................0
					if(Add2[0]==0x01)
					{
						cout<<"1Ԫ������"<<endl;
					}
					else
					{
						cout<<"5�ǲ�����"<<endl;
					};
					////...............1
					//cout<<"�������ݸ�λ "<<(int)Add2[1]<<endl;
					////..............2
				 //   cout<<"�������ݵ�λ "<<(int)Add2[2]<<endl;
					//...................1
					bit=0x01;
					bit&= Add2[1];
					if(bit==0x00)
					{   
						cout<<"������û�գ�"<<endl;
					}
					else
					{
						cout<<"������򲹱���գ�"<<endl;
					};
					bit=0x02;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"û�й��ϣ�"<<endl;
					}
					else
					{
						cout<<"��(���㶷����)��(���㶷���Ҽ����ݴ�����δ��úͻ�)��(���㶷����ͨ������)��"<<endl;
					};
                    bit=0x04;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"�������ͱ�λ�ڵ���"<<endl;
					}
					else
					{
						cout<<"�������ͱ�λδ�ڵ����գ���"<<endl;
					};
					bit=0x08;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"�������߱�λ�ڵ���������"<<endl;
					}
					else
					{
						cout<<"�������߱�λδ�ڵ���"<<endl;
					};
					bit=0x10;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"˫������������"<<endl;
					}
					else
					{
						cout<<"˫���������ϣ�"<<endl;
					};
					bit=0x20;
					bit&=Add2[1];
					if(bit==0x00)
					{   
						cout<<"����������ģ��λ����λ��"<<endl;
					}
					else
					{
						cout<<"����������ģ��λ��δ��λ��"<<endl;
					};
					
					
				  cout<<"�������������� "<<count<<endl;
			      cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 12: cout<<"0x01��1Ԫ���������ID�������������ID��"<<endl
                    <<"0x02��5�ǲ��������ID ��Ԥ����"<<endl
					<<"0x04��Ӳ��ģ���豸��ţ�"<<endl;
				cout<<"��д���豸������ţ�";
				cin>>hex>>index;
				WriteId[0]=(BYTE)index;
				for(int i=1;i<5;i++)
				{
				cout<<"������ģ���ţ���λ��ǰ����";
				cin>>hex>>index;
				WriteId[i]=(BYTE)index;
				}			   
			    iResult=coinmodule.Coin_WriteID(WriteId);
				if(iResult==0)
				{
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 13: cout<<"0x01��1Ԫ���������ID�������������ID��"<<endl
                    <<"0x02��5�ǲ��������ID ��Ԥ����"<<endl
					<<"0x04��Ӳ��ģ���豸��ţ�"<<endl;
				cout<<"��д���豸������ţ�";
				cin>>hex>>index;
				ReadId=(BYTE)index;  
     			iResult=coinmodule.Coin_ReadID(ReadId,id);
				if(iResult==0)
				{
					//cout<<"ģ���ţ���λ��ǰ���ǣ�"<<hex<<(int)ReadId1[0]<<hex<<(int)ReadId1[1]<<hex<<(int)ReadId1[2]<<hex<<(int)ReadId1[3]<<endl;
					cout<<"ģ���ţ�"<<id<<endl;
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 14: j=0;
				while(j<4)
				{
				   cout<<"������Ӳ��Ǯ���ţ���λ��ǰ����һ���ֽ�һ���ֽ����룺";
					cin>>hex>>index;
					Box_WriteId[j]=(BYTE)index;
					j++;
				};
				cout<<"������Ӳ��Ǯ��λ��";
			    cin>>hex>>index;
				Box_WriteId[4]=(BYTE)index;
				cout<<"������Ӳ��Ǯ��λ��";
			    cin>>hex>>index;
				Box_WriteId[5]=(BYTE)index;
				cout<<"�������꣨��λ����";
			    cin>>hex>>index;
				Box_WriteId[6]=(BYTE)index;
				cout<<"�������꣨��λ����";
			    cin>>hex>>index;
				Box_WriteId[7]=(BYTE)index;
				cout<<"�������£�";
			    cin>>hex>>index;
				Box_WriteId[8]=(BYTE)index;
				cout<<"�������գ�";
			    cin>>hex>>index;
				Box_WriteId[9]=(BYTE)index;
				cout<<"������ʱ��";
			    cin>>hex>>index;
				Box_WriteId[10]=(BYTE)index;
				cout<<"������֣�";
			    cin>>hex>>index;
				Box_WriteId[11]=(BYTE)index;
				cout<<"�������룺";
			    cin>>hex>>index;
				Box_WriteId[12]=(BYTE)index;
			    iResult=coinmodule.Coin_Box_WriteID(Box_WriteId);
				if(iResult==0)
				{  
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				  {
				  	cout<<"�˿�δ�򿪣�"<<endl;
				  }
				  else if(iResult==-3)
				  {
					  cout<<"�����ʧ�ܣ�"<<endl;
				  }
				  else if(iResult==-4)
				  {
					  cout<<"���ر�������������кŴ���"<<endl;
				  }
				break;
		case 15:iResult=coinmodule.Coin_Box_ReadID(BoxReadId,id,count);
			   if(iResult==0)
				{
					//...................0---3
					//cout<<"Ӳ��Ǯ���ţ���λ��ǰ���ǣ�"<<hex<<(int)BoxReadId[0]<<hex<<(int)BoxReadId[1]<<hex<<(int)BoxReadId[2]<<hex<<(int)BoxReadId[3]<<endl;
					cout<<"Ӳ��Ǯ�����ǣ�"<<id<<endl;
					//...................4
					//cout<<"Ӳ������λ"<<hex<<(int)BoxReadId[4]<<endl;
					//...................5
					//cout<<"Ӳ������λ"<<hex<<(int)BoxReadId[5]<<endl;
					cout<<"Ӳ��������"<<count<<endl;
					//...........������ʱ���� 6--12
					cout<<hex<<(int)BoxReadId[0]<<hex<<(int)BoxReadId[1]<<"��"
						<<hex<<(int)BoxReadId[2]<<"��"
						<<hex<<(int)BoxReadId[3]<<"��"
						<<hex<<(int)BoxReadId[4]<<"ʱ"
						<<hex<<(int)BoxReadId[5]<<"��"
						<<hex<<(int)BoxReadId[6]<<"��"<<endl;
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
				}
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
				}
				else if(iResult==-3)
				{
					cout<<"�����ʧ�ܣ�"<<endl;
				}
				else if(iResult==-4)
				{
					cout<<"���ر�������������кŴ���"<<endl;
				}
				break;
		case 16:coinmodule.Coin_Program_Update();			   
				break;
		case 17:cout<<"�����̿�ʼ����"<<endl;
			    //sleep(10);
			    coinmodule.Coin_Program_Begin(Program1);
				break;
		case 18:cout<<"����������"<<endl;
			    //sleep(10);
			    coinmodule.Coin_Program_Send(Program2);
				break;
		case 19: coinmodule.Coin_Program_End();
				break;
		case 20:coinmodule.Coin_Program_APP();
				break;
		case 21: cout<<"������С�ڵ���0xFF��ֵ,��������������Ox100:";
				cin>>hex>>pre;
				while(pre<256)
				{
					pre1=(BYTE)pre;
//					m_PreResult.push_back(pre1);
					cout<<"������С�ڵ���0xFF��ֵ,��������������Ox100:";
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
	/*���Ľ������ñ���*/
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
		cout<<"�򿪴��ڣ�          0"<<endl
			<<"�رմ��ڣ�          1"<<endl
			<<"����ģ����ѯ��      2"<<endl
			<<"������ԣ�          3"<<endl
			<<"��λ��              4"<<endl
			<<"��ѯģ��汾��      5"<<endl
			<<"������             6"<<endl
			<<"��д�����         7"<<endl
			<<"���任�䣺         8"<<endl
			<<"ȡģ��ID��         9"<<endl
			<<"дģ��ID��         10"<<endl
			<<"Ԥ���õķ��ر��ģ�  11"<<endl
			<<"�˳�����         12"<<endl;
		cout<< std::string( 44, '-' ) <<endl;
			
		cout<<"��ѡ��ָ��Ĳ������룺" ;
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
				  cout<<"�򿪴��ڳɹ���"<<endl;
				}
				else
				{
				  cout<<"�򿪴���ʧ�ܣ�"<<endl;
				}
				break;
		case 1: isClose=cticket.Ticket_CommClose();
			    if(isClose==true)
				{
				  cout<<"�رմ��ڳɹ���"<<endl;
				}
				else
				{
				  cout<<"�رմ���ʧ�ܣ�"<<endl;
				}
				break;
		case 2: BYTE SensorStatus[6];
			    iResult=cticket.Ticket_Poll(SensorStatus); 
				
				if(iResult==0)
				{

				 ///////////////////////////����ǰ��λ��� SensorStatus[0]
					bit=0x02;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
					cout<<"����ǰ����λ��"<<endl;
					}
					else
					{
						cout<<"����ǰ��λ��"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[0];
					if(bit==0x00)
					{   
						cout<<"ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"ǰ����չ�������ڣ�"<<endl;
					};
					///////////////////////////�����λ��� SensorStatus[1]
					bit=0x02;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
					   cout<<"����󲻵�λ��"<<endl;
					}
					else
					{
						cout<<"�����λ��"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[1];
					if(bit==0x00)
					{   
						cout<<"����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"����չ�������ڣ�"<<endl;
					};
					///////////////////////////������λ��� SensorStatus[2]
					bit=0x10;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"�����ո�δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"�����ոб��ڣ�"<<endl;
					};
					bit=0x08;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"��ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��ǰ����չ�������ڣ�"<<endl;
					};
					bit=0x04;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"˫�������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"˫����������ڣ�"<<endl;
					};
					bit=0x02;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"���������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"������������ڣ�"<<endl;
					};
					bit=0x01;
					bit&=SensorStatus[2];
					if(bit==0x00)
					{   
						cout<<"��д�����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��д��������ڣ�"<<endl;
					};				
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		case 3: cout<<"�����е���� 0"<<endl
					<<"�ο�������ԣ� 1"<<endl
		            <<"���������ԣ� 2"<<endl
					<<"���������ԣ� 3"<<endl
					<<"��������ԣ�   4"<<endl
					
					<<"������ǹرգ� 5"<<endl					
					<<"��ѡ��ָ��Ĳ������룺";
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
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };                
				break;
		case 4: iResult=cticket.Ticket_Reset( );
			    if(iResult==0)
				{
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
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
					cout<<"���汾��:"<<(int)major1<<(int)major2<<"  ���汾�ţ�"<<(int)minor1<<(int)minor2<<endl;
				    cout<<"���汾��:"<<hex<<(int)Major<<"  ���汾�ţ�"<<hex<<(int)Minor<<endl;
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		case 6: cout<<"Ʊ��1�� 0"<<endl
		            <<"Ʊ��2�� 1"<<endl
					<<"Ʊ��3�� 2"<<endl
					<<"Ʊ��4�� 3"<<endl
					<<"��ѡ��ָ��Ĳ������룺";
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
					case 1: cout<<"Ʊ���!"<<endl;
						  break;
                    case 2: cout<<"�ο�����!"<<endl;
						  break;
					case 3: cout<<"�������!"<<endl;
						  break;
                    case 4: cout<<"˫��!"<<endl;
						  break;
					};
					 ///////////////////////////����ǰ��λ��� Data2[0]
					bit=0x02;
					bit&=Data2[0];
					if(bit==0x00)
					{   
					cout<<"����ǰ����λ��"<<endl;
					}
					else
					{
						cout<<"����ǰ��λ��"<<endl;
					};
					bit=0x01;
					bit&=Data2[0];
					if(bit==0x00)
					{   
						cout<<"ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"ǰ����չ�������ڣ�"<<endl;
					};
					///////////////////////////�����λ��� Data2[1]
					bit=0x02;
					bit&=Data2[1];
					if(bit==0x00)
					{   
					   cout<<"����󲻵�λ��"<<endl;
					}
					else
					{
						cout<<"�����λ��"<<endl;
					};
					bit=0x01;
					bit&=Data2[1];
					if(bit==0x00)
					{   
						cout<<"����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"����չ�������ڣ�"<<endl;
					};
					///////////////////////////������λ��� Data2[2]
					bit=0x10;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"�����ո�δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"�����ոб��ڣ�"<<endl;
					};
					bit=0x08;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"��ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��ǰ����չ�������ڣ�"<<endl;
					};
					bit=0x04;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"˫�������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"˫����������ڣ�"<<endl;
					};
					bit=0x02;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"���������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"������������ڣ�"<<endl;
					};
					bit=0x01;
					bit&=Data2[2];
					if(bit==0x00)
					{   
						cout<<"��д�����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��д��������ڣ�"<<endl;
					};			
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		case 7:  cout<<"ͨ��1�� 0"<<endl
		            <<"ͨ��2�� 1"<<endl
					<<"ͨ��3�� 2"<<endl
					<<"ͨ��4�� 3"<<endl
					<<"��ѡ��ָ��Ĳ������룺";
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
			     cout<<"�ɹ��� 0"<<endl
		             <<"ʧ�ܣ� 1"<<endl
					 <<"��ѡ��ָ��Ĳ������룺";
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
					case 1: cout<<"Ʊ���!"<<endl;
						  break;
                    case 2: cout<<"�ο�����!"<<endl;
						  break;
					case 3: cout<<"�������!"<<endl;
						  break;
                    case 4: cout<<"˫��!"<<endl;
						  break;
					};
						 ///////////////////////////����ǰ��λ��� Data3[0]
					bit=0x02;
					bit&=Data3[0];
					if(bit==0x00)
					{   
					cout<<"����ǰ����λ��"<<endl;
					}
					else
					{
						cout<<"����ǰ��λ��"<<endl;
					};
					bit=0x01;
					bit&=Data3[0];
					if(bit==0x00)
					{   
						cout<<"ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"ǰ����չ�������ڣ�"<<endl;
					};
					///////////////////////////�����λ��� Data3[1]
					bit=0x02;
					bit&=Data3[1];
					if(bit==0x00)
					{   
					   cout<<"����󲻵�λ��"<<endl;
					}
					else
					{
						cout<<"�����λ��"<<endl;
					};
					bit=0x01;
					bit&=Data3[1];
					if(bit==0x00)
					{   
						cout<<"����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"����չ�������ڣ�"<<endl;
					};
					///////////////////////////������λ��� Data3[2]
					bit=0x10;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"�����ո�δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"�����ոб��ڣ�"<<endl;
					};
					bit=0x08;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"��ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��ǰ����չ�������ڣ�"<<endl;
					};
					bit=0x04;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"˫�������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"˫����������ڣ�"<<endl;
					};
					bit=0x02;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"���������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"������������ڣ�"<<endl;
					};
					bit=0x01;
					bit&=Data3[2];
					if(bit==0x00)
					{   
						cout<<"��д�����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��д��������ڣ�"<<endl;
					};			
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
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
					case 1: cout<<"Ʊ���!"<<endl;
						  break;
                    case 2: cout<<"�ο�����!"<<endl;
						  break;
					case 3: cout<<"�������!"<<endl;
						  break;
                    case 4: cout<<"˫��!"<<endl;
						  break;
					};
						 ///////////////////////////����ǰ��λ��� Data2[0]
					bit=0x02;
					bit&=Data4[0];
					if(bit==0x00)
					{   
					cout<<"����ǰ����λ��"<<endl;
					}
					else
					{
						cout<<"����ǰ��λ��"<<endl;
					};
					bit=0x01;
					bit&=Data4[0];
					if(bit==0x00)
					{   
						cout<<"ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"ǰ����չ�������ڣ�"<<endl;
					};
					///////////////////////////�����λ��� Data4[1]
					bit=0x02;
					bit&=Data4[1];
					if(bit==0x00)
					{   
					   cout<<"����󲻵�λ��"<<endl;
					}
					else
					{
						cout<<"�����λ��"<<endl;
					};
					bit=0x01;
					bit&=Data4[1];
					if(bit==0x00)
					{   
						cout<<"����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"����չ�������ڣ�"<<endl;
					};
					///////////////////////////������λ��� Data4[2]
					bit=0x10;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"�����ո�δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"�����ոб��ڣ�"<<endl;
					};
					bit=0x08;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"��ǰ����չ����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��ǰ����չ�������ڣ�"<<endl;
					};
					bit=0x04;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"˫�������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"˫����������ڣ�"<<endl;
					};
					bit=0x02;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"���������δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"������������ڣ�"<<endl;
					};
					bit=0x01;
					bit&=Data4[2];
					if(bit==0x00)
					{   
						cout<<"��д�����δ�ڣ�"<<endl;
					}
					else
					{
						cout<<"��д��������ڣ�"<<endl;
					};			
					cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		case 9: BYTE Data1[4];
			   iResult=cticket.Ticket_ReadId(Data1);
			   if(iResult==0)
			   {
				   cout<<"Ʊ��1:"<<hex<<(int)Data1[0]<<"Ʊ��2:"<<hex<<(int)Data1[1]
				       <<"Ʊ��3:"<<hex<<(int)Data1[2]<<"Ʊ��4:"<<hex<<(int)Data1[3]<<endl;				       
				   cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		case 10:Data5[0]=0x01;
			    Data5[1]=0x02;
			    Data5[2]=0x03;
			    Data5[3]=0x04; 
			    iResult=cticket.Ticket_WriteId(Data5); 
				if(iResult==0)
			   {
				cout<<"����ִ�гɹ���"<<endl;
				}
				else if(iResult==-1)
				{
					cout<<"����ִ�г�ʱ��"<<endl;
                }
				else if(iResult==80)
				{
					cout<<"�豸״̬æ��"<<endl;
                }
				else if(iResult==98)
				{
					cout<<"����ִ��ʧ�ܣ�"<<endl;
                }
				else if(iResult==99)
				{
					cout<<"������������ط���"<<endl;
                }
				else if(iResult==-2)
				{
					cout<<"�˿�δ�򿪣�"<<endl;
                }
				else if(iResult==-3)
				{
					cout<<"�����ʧ��"<<endl;
                }
        else if(iResult==-4)
				{
					cout<<"���ر�������������к��д�"<<endl;
                };
				break;
		/*case 11:cout<<"������С�ڵ���0xFF��ֵ,��������������Ox100:";
				cin>>hex>>pre;
				while(pre<256)
				{
					pre1=(BYTE)pre;
					m_PreResult.push_back(pre1);
					cout<<"������С�ڵ���0xFF��ֵ,��������������Ox100:";
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
	gp_printer->PrintLineAsync( "��a��Ϊ�˼���ȫ���ů�����ƣ���ѧ�����뾡�˸��ְ취����������������赲̫������������뷨������������Ǿ�������Щʲô���ø�װ���ķɻ����������Ϳ����ñ����Ͽյ���ձ��ֻ���״̬�ü��꣬������ֻ��Ҫ����һ���������Ƭ�ķ��á��������ѧ������ѧ�Ҵ�ά&#8226;��˼��DavidKeith�����˵�����������ԣ�ֻ�軨10����Ԫ������������������2020�����ұ�����Һ�ΰ�����" );
	gp_printer->HalfCutAsync();

	while(1)
		WThrd::tr_sleep(3);
}



void test_top_scr()
{
	gp_topscr->DispStr( "�Ϻ������ļ������ǳ�����������һ������δ����С�����ˣ�Բ��������Ͷ���ʮ�㣬΢Ц���۾�͸¶���У��ִ�����װ���Ƽ�ʮ�㣬�����̺�����������������������ƣ�������Ϻ������붼�е����й�ϵ���ִ������С�ʱ�С����������Ϻ�������������΢Ц���ŵı���ڹ�ͳ��Ϻ�����������ȡ���޿��ص�Ʒ������" );

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

// [in]  iToBeChange ������ (�Է�Ϊ��λ)
// [in]  iRMB50 Ӳ��ѭ������5�Ǹ���
// [in]  iRMB100 Ӳ��ѭ������1Ԫ����
// [in]  iRMB500 ֽ��ѭ������5Ԫ����   (ֽ����������ĿǰΪ0���������Ū)
// [in]  iRMB1000 ֽ��ѭ������10Ԫ����
// [in]  iRMB2000 ֽ��ѭ������20Ԫ����
// [in]  iRMB5000 ֽ��ѭ������50Ԫ����
// [out] iChangeCoin  ���������Ӳ��Ǯ��   -> ,��Ӳ�ҵײ�����������������������������Ҫת��Ϊ���� (�Է�Ϊ��λ)
// [out] iChangeBill  ���������ֽ��Ǯ��  (��ԪΪ��λ)
// returnvalue :
// true:��������
// false:��������
bool isChangeOK( int iToBeChange, int iRMB50, int iRMB100, int iRMB500, int iRMB1000, int iRMB2000,int iRMB5000, long *iChangeCoin /*= NULL*/ ,long *iChangeBill /*= NULL*/ )
{

	int n50, n100, n500, n1000, n2000, n5000;
	n50 = n100 = n500 = n1000 = n2000 = n5000 = 0;
	if( 1 != gp_bill->m_iIsNotBillChange )
	{
		//�ж�50Ԫ
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

		//�ж�20Ԫ
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

		//�ж�10Ԫ
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

		//�ж�5Ԫ
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

	//�ж�1Ԫ
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

	//�ж�5��
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

// [in]  iChangeLimit ������ (�Է�Ϊ��λ)
// [out] iChangeCoin  ���������Ӳ��Ǯ��   -> ,��Ӳ�ҵײ�����������������������������Ҫת��Ϊ���� (�Է�Ϊ��λ)
// [out] iChangeBill  ���������ֽ��Ǯ��  (��ԪΪ��λ)
bool CanChange( int iChangeLimit /*= 4900*/ ,long *iChangeCoin /*= NULL*/ ,long *iChangeBill /*= NULL*/  )
{
	bool ret = true;
	if( iChangeLimit < 50 )   //С��5��
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

	// �ж�ÿ����λ�����
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

	//��Ʊ�������ĸ�Ʊ������
	//���row4002
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

	//���row4003
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

	//����4004������zone���4003�еļ۸�,��group
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

					//�ҵ����򣬽�6000�ж�Ӧ������ֵ

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
		gp_coin->returnCoin();//��Ӳ��
		//waiter_data.m_ReceiveCoin = 0;
		//waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveBill;
	}

	if(waiter_data.m_ReceiveBill >0)
	{
		gp_bill->dBill_Refund();//add by jfren @20161122
		//waiter_data.m_ReceiveBill = 0;
		//waiter_data.m_ReceiveTotal = waiter_data.m_ReceiveCoin;

		//ֻ��Ҫ��ֽ��
		bu_quickflow_t::qf_counter_t  iQf1_user_idle;
		double iQf1_user_idleMAX = 15;

		gp_qf->GetQf( iQf1_user_idle );

		while(1)
		{
			if( 0 == gp_db->m_b8702.GetRow(0).m_wReturnShutter ||
				gp_qf->IsLongQf( iQf1_user_idle , iQf1_user_idleMAX ) )
			{
				//δ������Ҫ��ֽ�����
				break;
			}
			
		}
	}

	
}
