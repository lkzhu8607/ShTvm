#ifndef TicketCommand_H_
#define TicketCommand_H_

#include "2.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


typedef unsigned char BYTE;

//数据类型重定义
typedef std::vector<BYTE>  BUF_T;
typedef unsigned int UNIT;



//控制代码
const BYTE TICKET_STX	= 0x02;
const BYTE TICKET_ETX	= 0x03;
const BYTE TICKET_DLE	= 0x10;

//返回值
const int  TICKET_RES_OK			= 0;		//执行成功
const int  TICKET_RES_TIMEOUT		= -1;		//命令超时(自动重发后，等应答报文仍超时,上发此代码)
const int  TICKET_RES_PORTOPEN      = -2;       //端口未打开
const int  TICKET_RES_SENDFAIL      = -3;       //命令发送失败
const int  TICKET_RES_CMDSEQ        = -4;       //命令发送失败
const int  TICKET_RES_BUSY			= 80;		//设备状态忙
const int  TICKET_RES_FAIL			= 98;		//命令执行失败
const int  TICKET_RES_OTHERWRONG	= 99;		//解包出错请求重发

//模块上发COMState
const BYTE TICKET_MODULE_STATE_OK		= 0x00;	    //命令执行成功
const BYTE TICKET_MODULE_STATE_FAIL	    = 0x01;	    //命令执行失败
const BYTE TICKET_MODULE_STATEBUSY		= 0x02;	    //设备忙
const BYTE TICKET_MODULE_STATE_NAK			        = 0x04;	    //解包出错请求重发

//命令代码--请求命令
const BYTE TICKET_CMD_REQ_FAKALUNXUNN		   = 0x31;		 //发卡模块查询
const BYTE TICKET_CMD_REQ_POWERTEST            = 0X32;      //电机测试
const BYTE TICKET_CMD_REQ_FUWEI                = 0X33;      //复位
const BYTE TICKET_CMD_REQ_BANBEN               = 0X34;      //版本
const BYTE TICKET_CMD_REQ_FAKA                 = 0X20;      //发卡
const BYTE TICKET_CMD_REQ_WRITEREAD            = 0X21;      //读写结果
const BYTE TICKET_CMD_REQ_KAXIANGHUANXIANG     = 0X22;      //卡箱换箱
//const BYTE TICKET_CMD_REQ_QINGKONG           = 0X23;      //卡箱换箱
const BYTE TICKET_CMD_REQ_READID               = 0X24;      //取模块和票箱Id
//const BYTE CMD_REQ_SHENGJIANG                = 0X25;       //卡箱升降
const BYTE CMD_REQ_QINGZANCUN                  = 0X26;       //清暂存
const BYTE TICKET_CMD_REQ_WRITEID              = 0X27;       //写模块和票箱ID


//命令代码--应答命令
const BYTE TICKET_CMD_RES_FAKALUNXUN		   = 0x31;
const BYTE TICKET_CMD_RES_POWERTEST            = 0X32;  
const BYTE TICKET_CMD_RES_FUWEI                = 0X33;
const BYTE TICKET_CMD_RES_BANBEN               = 0X34;  
const BYTE TICKET_CMD_RES_FAKA                 = 0X20; 
const BYTE TICKET_CMD_RES_WRITEREAD            = 0X21; 
const BYTE TICKET_CMD_RES_KAXIANGHUANXIANG     = 0X22;
const BYTE TICKET_CMD_RES_QINGKONG             = 0X23;
const BYTE TICKET_CMD_RES_READID               = 0X24;  
//const BYTE CMD_RES_SHENGJIANG                = 0X25;
const BYTE CMD_RES_QINGZANCUN                  = 0X26;
const BYTE TICKET_CMD_RES_WRITEID              = 0X27;

//常量定义
const int TICKET_RECV_BUFFER_LEN_	           = 300;		    //报文最大长度
const unsigned int  TICKET_Start=1;                                    //开始
const unsigned int  TICKET_End=2;                                      //结束


//全局变量定义
static unsigned  int TICKET_isTag=0;        //判断一个字符
static unsigned int TICKET_iSeq=0;          //命令序列号
static unsigned int TICKET_iRetry=3;        //命令重发次数



//////////////////////////////////////////////////////////////////////
//平台处理函数
/////////////////////////////////////////////////////////////////////
//处理字符
//判定字符是否由转义字符生成还是本省




//打开端口

class CTicket : public d_com_agent2_t
{

private:
	bool m_isPort;                   //端口是否打开


	BYTE procchar(BYTE current,BYTE pre);
	bool CommOpen();
	bool CommClose();
	bool SendFrame(const BUF_T & buf_in);
	bool RecvFrame(BUF_T & buf_out);
	unsigned int InsertTICKET_DLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	unsigned int DeleteTICKET_DLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	bool SendCommand(BYTE * Data,int nLen);
	bool RecvCommand(BYTE * Data,int & nLen);

public:
	CTicket();
	~CTicket();

	bool Ticket_CommOpen();
	// 关闭端口
	bool Ticket_CommClose();
	//发卡模块轮训
	int  Ticket_Poll(BYTE SensorStatus[6]);
	//电机测试
	int Ticket_PowerTest(BYTE Index);
	//复位
	int  Ticket_Reset( );
	//查询发卡程序模块版本
	int  Ticket_GetVersion( BYTE & Major,BYTE & Minor);
	//发卡
	int  Ticket_SendCard( BYTE Box,BYTE & Wrong,BYTE Data[6]);
	//读写结果
	int  Ticket_WriteRead( BYTE Box,BYTE IsFail,BYTE & WrongCode,BYTE Data[6]);
	//卡箱换箱
	int  Ticket_ExchangeBox( BYTE & Wrong,BYTE Data[6]);
	//取模块票箱和ID
	int  Ticket_ReadId( BYTE Data[4]);
	//写模块票箱和ID
	int  Ticket_WriteId( BYTE Data[4]);
	//清暂存
	//bTicketTowhere [in]: 0x01 to 乘客    0x02 to 回收箱
	//Wrong          [out]: 错误码
	//Data           [out]: 光感状态
	int Ticket_CleanEscrow(BYTE bTicketTowhere,BYTE & Wrong,BYTE Data[6]);


};
 

#endif
