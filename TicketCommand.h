#ifndef TicketCommand_H_
#define TicketCommand_H_

#include "2.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


typedef unsigned char BYTE;

//���������ض���
typedef std::vector<BYTE>  BUF_T;
typedef unsigned int UNIT;



//���ƴ���
const BYTE TICKET_STX	= 0x02;
const BYTE TICKET_ETX	= 0x03;
const BYTE TICKET_DLE	= 0x10;

//����ֵ
const int  TICKET_RES_OK			= 0;		//ִ�гɹ�
const int  TICKET_RES_TIMEOUT		= -1;		//���ʱ(�Զ��ط��󣬵�Ӧ�����Գ�ʱ,�Ϸ��˴���)
const int  TICKET_RES_PORTOPEN      = -2;       //�˿�δ��
const int  TICKET_RES_SENDFAIL      = -3;       //�����ʧ��
const int  TICKET_RES_CMDSEQ        = -4;       //�����ʧ��
const int  TICKET_RES_BUSY			= 80;		//�豸״̬æ
const int  TICKET_RES_FAIL			= 98;		//����ִ��ʧ��
const int  TICKET_RES_OTHERWRONG	= 99;		//������������ط�

//ģ���Ϸ�COMState
const BYTE TICKET_MODULE_STATE_OK		= 0x00;	    //����ִ�гɹ�
const BYTE TICKET_MODULE_STATE_FAIL	    = 0x01;	    //����ִ��ʧ��
const BYTE TICKET_MODULE_STATEBUSY		= 0x02;	    //�豸æ
const BYTE TICKET_MODULE_STATE_NAK			        = 0x04;	    //������������ط�

//�������--��������
const BYTE TICKET_CMD_REQ_FAKALUNXUNN		   = 0x31;		 //����ģ���ѯ
const BYTE TICKET_CMD_REQ_POWERTEST            = 0X32;      //�������
const BYTE TICKET_CMD_REQ_FUWEI                = 0X33;      //��λ
const BYTE TICKET_CMD_REQ_BANBEN               = 0X34;      //�汾
const BYTE TICKET_CMD_REQ_FAKA                 = 0X20;      //����
const BYTE TICKET_CMD_REQ_WRITEREAD            = 0X21;      //��д���
const BYTE TICKET_CMD_REQ_KAXIANGHUANXIANG     = 0X22;      //���任��
//const BYTE TICKET_CMD_REQ_QINGKONG           = 0X23;      //���任��
const BYTE TICKET_CMD_REQ_READID               = 0X24;      //ȡģ���Ʊ��Id
//const BYTE CMD_REQ_SHENGJIANG                = 0X25;       //��������
const BYTE CMD_REQ_QINGZANCUN                  = 0X26;       //���ݴ�
const BYTE TICKET_CMD_REQ_WRITEID              = 0X27;       //дģ���Ʊ��ID


//�������--Ӧ������
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

//��������
const int TICKET_RECV_BUFFER_LEN_	           = 300;		    //������󳤶�
const unsigned int  TICKET_Start=1;                                    //��ʼ
const unsigned int  TICKET_End=2;                                      //����


//ȫ�ֱ�������
static unsigned  int TICKET_isTag=0;        //�ж�һ���ַ�
static unsigned int TICKET_iSeq=0;          //�������к�
static unsigned int TICKET_iRetry=3;        //�����ط�����



//////////////////////////////////////////////////////////////////////
//ƽ̨������
/////////////////////////////////////////////////////////////////////
//�����ַ�
//�ж��ַ��Ƿ���ת���ַ����ɻ��Ǳ�ʡ




//�򿪶˿�

class CTicket : public d_com_agent2_t
{

private:
	bool m_isPort;                   //�˿��Ƿ��


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
	// �رն˿�
	bool Ticket_CommClose();
	//����ģ����ѵ
	int  Ticket_Poll(BYTE SensorStatus[6]);
	//�������
	int Ticket_PowerTest(BYTE Index);
	//��λ
	int  Ticket_Reset( );
	//��ѯ��������ģ��汾
	int  Ticket_GetVersion( BYTE & Major,BYTE & Minor);
	//����
	int  Ticket_SendCard( BYTE Box,BYTE & Wrong,BYTE Data[6]);
	//��д���
	int  Ticket_WriteRead( BYTE Box,BYTE IsFail,BYTE & WrongCode,BYTE Data[6]);
	//���任��
	int  Ticket_ExchangeBox( BYTE & Wrong,BYTE Data[6]);
	//ȡģ��Ʊ���ID
	int  Ticket_ReadId( BYTE Data[4]);
	//дģ��Ʊ���ID
	int  Ticket_WriteId( BYTE Data[4]);
	//���ݴ�
	//bTicketTowhere [in]: 0x01 to �˿�    0x02 to ������
	//Wrong          [out]: ������
	//Data           [out]: ���״̬
	int Ticket_CleanEscrow(BYTE bTicketTowhere,BYTE & Wrong,BYTE Data[6]);


};
 

#endif
