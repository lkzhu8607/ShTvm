
//
#ifndef READWRITECOMMAND_H_
#define READWRITECOMMAND_H_

#include "2.h"
#include "ReadWriteCommand.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"

typedef unsigned char BYTE;
typedef std::vector<BYTE> BUF_T;
typedef unsigned int UNIT;
//协议中的字符
static const BYTE STX=0X02;
static const BYTE ETX=0X03;
static const BYTE DLE=0X10;
static const int _RECV_BUFFER_LEN_=500;
static const int START=1;
static const int END=2;
//命令
static const BYTE INIT=0X20;
static const BYTE RESET=0x21;
static const BYTE READCARD=0X30;
static const BYTE SALECARD=0XC5;
static const BYTE ABORT=0X3F;
//返回的应答码
static const int OK=0;
static const int CHECKERROR=1;
static const int BADREQUEST=2;
static const int BADPARAM=3;
static const int STATUSERROR=4;
static const int AUTHENERROR=5;
static const int READERROR=6;
static const int WRITEERROR=7;
static const int CARDREMOVED=8;
static const int INVALIDCARD=9;
//static const BYTE ETX=0X15;
static const int NORECORD=10;
static const int PUTBACKCARD1=11;
static const int PUTBACKCARD2=12;
static const int NOPSAM=13;
static const int NOISAM=14;
static const int PSAMERR=15;
static const int ISAMERR=16;
static const int NOESAM=17;
static const int ESAMERR=18;
static const int NOKEY=19;
static const int MACERR=20;
static const int AUTHERR=21;
static const int AUTHFAIL=22;
static const int NOAUTH=23;
static const int PINERROR=24;
static const int MODIFYPIN=25;
static const int READERERROR=16;
static const int UNKNOWN=17;
static const int PORT=-1;
static const int SENDFAIL=-2;
static const int TIMEOUT=-3;
static const int CMDSEQ=-4;
static const int NOCARD=-5;
//////////////////////////////
static BUF_T m_PreResult;                    //预报文
//static bool m_isPort=false;                   //端口是否打开


typedef unsigned char BYTE;

class ReadWrite : public d_com_agent2_t
{
	/////////////////////////////////////
private:
	int m_iRetry;
	bool m_isPort;
	//CRITICAL_SECTION Command;
	int m_CMD_Seq;
	
	bool CommOpen();
	bool CommClose();
	bool SendFrame(const BUF_T & buf_in);
	bool RecvFrame(BUF_T & buf_out);
	unsigned int InsertDLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	unsigned int DeleteDLE(BYTE * pBuf,int nLen, BYTE * ptarget);
	bool SendCommand(BYTE * Data,int nLen);
	bool RecvCommand(BYTE * Data,int & nLen);

public:
	ReadWrite();
	bool OpenComm();
	bool CloseComm();
	int Reset(BYTE ResetOut[3],BYTE DoubleCard[4],BYTE SingleCard[4]);   //复位器读写命令

	int Init(BYTE InitIn[11],BYTE & InitOut);                   //初始化读写命令
	int Init2( BYTE *InitIn, int len , tuint8 commd );                   //初始化读写命令

	int ReadCard(BYTE ReadIn,BYTE ReadOut[28]);               //取卡信息命令
	int SaleCard(BYTE SaleIn[14],BYTE SaleOut[8]);             //单程票售票交易
	int Abort(BYTE & AbortOut);                                //终止命令   暂时不用
	int ReadReasult(BYTE ReadOut[28]);                        //取得单程票的返回结果 2000ms等待
};

#endif

