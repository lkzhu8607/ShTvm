#ifndef CoinCommand_H_
#define CoinCommand_H_

#include "2.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


#include <iostream>
using namespace std;
typedef unsigned char BYTE;


//类型重定义
typedef std::vector<unsigned char> BUF_T;
typedef unsigned int UNIT;


//返回值
const int  COIN_DLL_RES_OK			= 0;		//执行成功
const int  COIN_DLL_RES_TIMEOUT		= -1;		//命令超时(自动重发后，等应答报文仍超时,上发此代码)
const int  COIN_DLL_RES_PORTOPEN	= -2;		//端口未打开
const int  COIN_DLL_RES_SENDFAIL 	= -3;		//命令发送失败
const int  COIN_DLL_RES_CMDSEQ   	= -4;		//返回报文中命令或者序列号出错
const int  COIN_DLL_RES_BUSY		= 80;		//设备状态忙
const int  COIN_DLL_RES_FAIL		= 98;		//命令执行失败
const int  COIN_DLL_RES_OTHERWRONG	= 99;		//解包出错请求重发


//控制代码
const BYTE COIN_STX	= 0x02;
const BYTE COIN_ETX	= 0x03;
const BYTE COIN_DLE	= 0x10;
//模块上发COMState
const BYTE COIN_MODULE_STATE_OK		    = 0x00;	//命令执行成功
const BYTE COIN_MODULE_STATE_FAIL	    = 0x01;	//命令执行失败
const BYTE COIN_MODULE_STATE_BUSY		= 0x02;	//设备忙
const BYTE COIN_MODULE_STATE_NAK		= 0x04;	//解包出错请求重发


//命令代码--请求命令
const BYTE COIN_CMD_REQ_STATE    	  		= 0X31;		 //硬币模块状态查询命令0x31

const BYTE COIN_CMD_REQ_TEST                 = 0X32;      //硬币模块测试命令0x32
const BYTE COIN_CMD_REQ_RESET                = 0X33;      //硬币模块程序复位0x33
const BYTE COIN_CMD_REQ_VERSION              = 0X34;      //硬币模块程序版本查询0x34

const BYTE COIN_CMD_REQ_PROGRAM_UPDATE       = 0X35;      //硬币模块程序更新命令0X35
const BYTE COIN_CMD_REQ_PROGRAM_BEGIN        = 0X36;      //硬币模块编程开始命令0X36
const BYTE COIN_CMD_REQ_PROGRAM_SEND         = 0X37;      //硬币模块发送编程数据命令0X37
const BYTE COIN_CMD_REQ_PROGRAM_END          = 0X38;      //硬币模块编程结束命令0X38
const BYTE COIN_CMD_REQ_PROGRAM_APP          = 0X39;      //硬币模块切换到应用程序命令0X39



const BYTE COIN_CMD_REQ_CHANGE               = 0X00;      //硬币模块找零命令0x00const BYTE COIN_CMD_REQ_END_CHANGE           = 0X01;      //循环找零箱、专用找零箱找零结束命令0x01
const BYTE COIN_CMD_REQ_CLEAN                = 0X02;      //硬币模块清币命令0x02
const BYTE COIN_CMD_REQ_END_CLEAN            = 0X03;      //循环找零箱、专用找零箱清币结束命令0x03
const BYTE COIN_CMD_REQ_OPENCLOSE            = 0X04;      //硬币模块电磁铁开关命令0x04
const BYTE COIN_CMD_REQ_POLL                 = 0X05;      //硬币识别器轮询0x05
const BYTE COIN_CMD_REQ_ADD                  = 0X06;      //硬币模块补币箱加币命令0x06
const BYTE COIN_CMD_REQ_WRITEID              = 0X07;      //硬币模块设备与票箱电子ID写命令0x07
const BYTE COIN_CMD_REQ_READID               = 0X08;      //硬币模块设备与票箱电子ID读命令0x08
const BYTE COIN_CMD_REQ_BOX_WRITEID          = 0X09;      //硬币回收箱写命令0x09
const BYTE COIN_CMD_REQ_BOX_READID           = 0X0A;      //硬币回收箱读命令0x0A

const BYTE COIN_CMD_REQ_BELT_ROLL            = 0X0B;      //硬币提升机构控制命令0X0B --20161114

//命令代码--应答命令
const BYTE COIN_CMD_RES_STATE    	  		 = 0X31;		 //硬币模块状态查询命令0x31
const BYTE COIN_CMD_RES_TEST                 = 0X32;      //硬币模块测试命令0x32
const BYTE COIN_CMD_RES_RESET                = 0X33;      //硬币模块程序复位0x33
const BYTE COIN_CMD_RES_VERSION              = 0X34;      //硬币模块程序版本查询0x34

const BYTE COIN_CMD_RES_PROGRAM_UPDATE       = 0X35;      //硬币模块程序更新命令0X35
const BYTE COIN_CMD_RES_PROGRAM_BEGIN        = 0X36;      //硬币模块编程开始命令0X36
const BYTE COIN_CMD_RES_PROGRAM_SEND         = 0X37;      //硬币模块发送编程数据命令0X37
const BYTE COIN_CMD_RES_PROGRAM_END          = 0X38;      //硬币模块编程结束命令0X38
const BYTE COIN_CMD_RES_PROGRAM_APP          = 0X39;      //硬币模块切换到应用程序命令0X39



const BYTE COIN_CMD_RES_CHANGE               = 0X00;      //硬币模块找零命令0x00
const BYTE COIN_CMD_RES_END_CHANGE           = 0X01;      //循环找零箱、专用找零箱找零结束命令0x01
const BYTE COIN_CMD_RES_CLEAN                = 0X02;      //硬币模块清币命令0x02
const BYTE COIN_CMD_RES_END_CLEAN            = 0X03;      //循环找零箱、专用找零箱清币结束命令0x03
const BYTE COIN_CMD_RES_OPENCLOSE            = 0X04;      //硬币模块电磁铁开关命令0x04
const BYTE COIN_CMD_RES_POLL                 = 0X05;      //硬币识别器轮询0x05
const BYTE COIN_CMD_RES_ADD                  = 0X06;      //硬币模块补币箱加币命令0x06
const BYTE COIN_CMD_RES_WRITEID              = 0X07;      //硬币模块设备与票箱电子ID写命令0x07
const BYTE COIN_CMD_RES_READID               = 0X08;      //硬币模块设备与票箱电子ID读命令0x08
const BYTE COIN_CMD_RES_BOX_WRITEID          = 0X09;      //硬币回收箱写命令0x09
const BYTE COIN_CMD_RES_BOX_READID           = 0X0A;      //硬币回收箱读命令0x0A

const BYTE COIN_CMD_RES_BELT_ROLL            = 0X0B;      //硬币提升机构控制命令0X0B --20161114


//常量定义
const int COIN_RECV_BUFFER_LEN_	= 300;		//报文最大长度
const unsigned int  COIN_Start=1;                        //开始
const unsigned int  COIN_End=2;                          //结束

//全局变量

////////////////////////////////////////////////
///////平台函数





class CCoin : public d_com_agent2_t
{

private :
	bool m_isPort;      //端口是否打开
	unsigned int m_Coin_iSeq;
	unsigned int m_Coin_iRetry;


	BYTE procchar(BYTE current,BYTE pre);
	bool CommOpen();
	bool CommClose();
	bool SendFrame(const BUF_T & buf_in);
	bool RecvFrame(BUF_T & buf_out);
	unsigned int InsertDLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	unsigned int DeleteDLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	bool SendCommand(BYTE * Data,int nLen);
	bool RecvCommand(BYTE * Data,int & nLen);



public:
	CCoin();
	~CCoin();

	bool Coin_CommOpen();												 //打开端口	
	bool Coin_CommClose();												// 关闭端口
	int  Coin_State(BYTE SensorStatus[8]);								 //硬币模块状态查询命令0x31
	int Coin_Test(BYTE Data[2]);										 //硬币模块测试命令0x32
	int Coin_Reset();													//硬币模块程序复位0x33
	int Coin_GetVersion(BYTE & Major,BYTE & Minor);						//硬币模块程序版本查询0x34
	int Coin_Program_Update();											//硬币模块程序更新命令0X35
	int Coin_Program_Begin(BYTE Data[4]);								//硬币模块编程开始命令0X36
	int Coin_Program_Send(BYTE Data[64]);								//硬币模块发送编程数据命令0X37
	int Coin_Program_End();												 //硬币模块编程结束命令0X38
	int Coin_Program_APP();												//硬币模块切换到应用程序命令0X39
	int Coin_Change( BYTE Box[2],BYTE Data[3]);							  //硬币模块找零命令0x00
	int Coin_Clean(BYTE Box,BYTE Data[2],int iNeedCleanCount,int & count);	 //硬币模块清币命令0x02
	int Coin_OpenClose(BYTE Data1[2],BYTE Data2[2]);					  //硬币模块电磁铁开关命令0x04
	int Coin_Poll(BYTE Data1,BYTE Data2[3]);							  //硬币识别器轮询0x05
	int Coin_Add(BYTE Box,BYTE Data[2],int & count);					  //硬币模块补币箱加币命令0x06
	int Coin_WriteID(BYTE Data[5]);										  //硬币模块设备与票箱电子ID写命令0x07
	int Coin_ReadID(BYTE Data1,unsigned long & id);						  //硬币模块设备与票箱电子ID读命令0x08
	int Coin_Box_WriteID(BYTE Data[13]);								  //硬币回收箱写命令0x09
	int Coin_Box_ReadID(BYTE Data[7],unsigned long & id,int & count);     //硬币回收箱读命令0x0A
	int Coin_Belt_Roll(BYTE Data[6]);                                     //硬币模块提升机构0x0B
	int  Coin_End_Change( BYTE Data);                                     //循环找零箱、专用找零箱找零结束命令0x01
	int  Coin_End_Clean( BYTE Data);                                      //循环找零箱、专用找零箱清币结束命令0x03
};






#endif
