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
	//纸币识别器状态
	
	//打开串口，iPortNum串口号.........................
	int OpenCom();

	//关闭串口...............
	int CloseCom();

	//1.机器复位....................#
	int cmReset();

	//2.状态查询...................dis sta>
	int cmState();

	int cmState(BYTE reasult[10]);

	//3.工作模式设置................set wor +>
	int cmWorkMode(int mode);

	//4.打开投币口.................work
	int cmWork( );

	//5
	int cmWorkTimeout( int timeout);

	//6
	int cmEncash();

	//7
	int cmRefund();

	//8关闭投币口
	int cmStopWork();	

	//9停用纸币的识别                 inh +>
	int cmInhibit(int value);	//cmInhibit( 0、1、5、10、20、50、100	);	

	//10激活纸币的识别                 act +>
	int cmActive(int value);	//cmActive( 0、1、5、10、20、50、100	); 

	//11 响应初始化操作
	int cmInit();
	int cmInit(int);

private:
	bool isPort;                   //端口是否打开
	int SendCommand(BYTE command[],int length);         //建立连接，发送命令！
	int RecvConnection(BUF_T & message);    //命令发送成功后开始接受响应报文
	int RecvConnection(BYTE * sa,int & m);  
private:
	int fd;      //文件描述符
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




