#ifndef GDnote_MEIGDnote_H_  
#define GDnote_MEIGDnote_H_  
#include "stdio.h"
//#include <Windows.h>
#include <string>
#include <vector>


namespace BillMEI {


typedef unsigned char BYTE;
typedef std::vector<BYTE>  BUF_T;
using namespace std;

class GDCashModle
{
public: 
    GDCashModle();
	//ֽ��ʶ����״̬
	
	//�򿪴��ڣ�iPortNum���ں�.........................
	int OpenCom();

	//�رմ���...............
	int CloseCom();

	//1.������λ....................#
	int cmReset();

	//2.״̬��ѯ...................dis sta>
	int cmState();

	int cmState(BYTE reasult[10]);

	//3.����ģʽ����................set wor +>
	int cmWorkMode(int mode);

	//4.��Ͷ�ҿ�.................work
	int cmWork( );

	//5
	int cmWorkTimeout( int timeout);

	//6
	int cmEncash();

	//7
	int cmRefund();

	//8�ر�Ͷ�ҿ�
	int cmStopWork();	

	//9ͣ��ֽ�ҵ�ʶ��                 inh +>
	int cmInhibit(int value);	//cmInhibit( 0��1��5��10��20��50��100	);	

	//10����ֽ�ҵ�ʶ��                 act +>
	int cmActive(int value);	//cmActive( 0��1��5��10��20��50��100	); 

	//11 ��Ӧ��ʼ������
	int cmInit();
	int cmInit(int);

private:
	bool isPort;                   //�˿��Ƿ��
	int SendCommand(BYTE command[],int length);         //�������ӣ��������
	int RecvConnection(BUF_T & message);    //����ͳɹ���ʼ������Ӧ����
	int RecvConnection(BYTE * sa,int & m);  
private:
	int fd;      //�ļ�������
	//HANDLE m_hPort;
	int set_speed(int speed);
	int set_parity(int databits,int stopbits,int parity);
	int cleanMode();
	bool ComOpen();
	bool ComClose();
	bool SendFrame(const BUF_T & buf_in);
	bool RecvFrame(BUF_T & buf_out,int typeENQ,int typeDEL,int typeNAK,int typeEOT,int typeMsg);
public:
	int cNoteValue;

public:
	int c2Reset(); //not use
	int c3Reset();


};
#endif





}




