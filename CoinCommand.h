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


//�����ض���
typedef std::vector<unsigned char> BUF_T;
typedef unsigned int UNIT;


//����ֵ
const int  COIN_DLL_RES_OK			= 0;		//ִ�гɹ�
const int  COIN_DLL_RES_TIMEOUT		= -1;		//���ʱ(�Զ��ط��󣬵�Ӧ�����Գ�ʱ,�Ϸ��˴���)
const int  COIN_DLL_RES_PORTOPEN	= -2;		//�˿�δ��
const int  COIN_DLL_RES_SENDFAIL 	= -3;		//�����ʧ��
const int  COIN_DLL_RES_CMDSEQ   	= -4;		//���ر���������������кų���
const int  COIN_DLL_RES_BUSY		= 80;		//�豸״̬æ
const int  COIN_DLL_RES_FAIL		= 98;		//����ִ��ʧ��
const int  COIN_DLL_RES_OTHERWRONG	= 99;		//������������ط�


//���ƴ���
const BYTE COIN_STX	= 0x02;
const BYTE COIN_ETX	= 0x03;
const BYTE COIN_DLE	= 0x10;
//ģ���Ϸ�COMState
const BYTE COIN_MODULE_STATE_OK		    = 0x00;	//����ִ�гɹ�
const BYTE COIN_MODULE_STATE_FAIL	    = 0x01;	//����ִ��ʧ��
const BYTE COIN_MODULE_STATE_BUSY		= 0x02;	//�豸æ
const BYTE COIN_MODULE_STATE_NAK		= 0x04;	//������������ط�


//�������--��������
const BYTE COIN_CMD_REQ_STATE    	  		= 0X31;		 //Ӳ��ģ��״̬��ѯ����0x31

const BYTE COIN_CMD_REQ_TEST                 = 0X32;      //Ӳ��ģ���������0x32
const BYTE COIN_CMD_REQ_RESET                = 0X33;      //Ӳ��ģ�����λ0x33
const BYTE COIN_CMD_REQ_VERSION              = 0X34;      //Ӳ��ģ�����汾��ѯ0x34

const BYTE COIN_CMD_REQ_PROGRAM_UPDATE       = 0X35;      //Ӳ��ģ������������0X35
const BYTE COIN_CMD_REQ_PROGRAM_BEGIN        = 0X36;      //Ӳ��ģ���̿�ʼ����0X36
const BYTE COIN_CMD_REQ_PROGRAM_SEND         = 0X37;      //Ӳ��ģ�鷢�ͱ����������0X37
const BYTE COIN_CMD_REQ_PROGRAM_END          = 0X38;      //Ӳ��ģ���̽�������0X38
const BYTE COIN_CMD_REQ_PROGRAM_APP          = 0X39;      //Ӳ��ģ���л���Ӧ�ó�������0X39



const BYTE COIN_CMD_REQ_CHANGE               = 0X00;      //Ӳ��ģ����������0x00const BYTE COIN_CMD_REQ_END_CHANGE           = 0X01;      //ѭ�������䡢ר�������������������0x01
const BYTE COIN_CMD_REQ_CLEAN                = 0X02;      //Ӳ��ģ���������0x02
const BYTE COIN_CMD_REQ_END_CLEAN            = 0X03;      //ѭ�������䡢ר����������ҽ�������0x03
const BYTE COIN_CMD_REQ_OPENCLOSE            = 0X04;      //Ӳ��ģ��������������0x04
const BYTE COIN_CMD_REQ_POLL                 = 0X05;      //Ӳ��ʶ������ѯ0x05
const BYTE COIN_CMD_REQ_ADD                  = 0X06;      //Ӳ��ģ�鲹����ӱ�����0x06
const BYTE COIN_CMD_REQ_WRITEID              = 0X07;      //Ӳ��ģ���豸��Ʊ�����IDд����0x07
const BYTE COIN_CMD_REQ_READID               = 0X08;      //Ӳ��ģ���豸��Ʊ�����ID������0x08
const BYTE COIN_CMD_REQ_BOX_WRITEID          = 0X09;      //Ӳ�һ�����д����0x09
const BYTE COIN_CMD_REQ_BOX_READID           = 0X0A;      //Ӳ�һ����������0x0A

const BYTE COIN_CMD_REQ_BELT_ROLL            = 0X0B;      //Ӳ������������������0X0B --20161114

//�������--Ӧ������
const BYTE COIN_CMD_RES_STATE    	  		 = 0X31;		 //Ӳ��ģ��״̬��ѯ����0x31
const BYTE COIN_CMD_RES_TEST                 = 0X32;      //Ӳ��ģ���������0x32
const BYTE COIN_CMD_RES_RESET                = 0X33;      //Ӳ��ģ�����λ0x33
const BYTE COIN_CMD_RES_VERSION              = 0X34;      //Ӳ��ģ�����汾��ѯ0x34

const BYTE COIN_CMD_RES_PROGRAM_UPDATE       = 0X35;      //Ӳ��ģ������������0X35
const BYTE COIN_CMD_RES_PROGRAM_BEGIN        = 0X36;      //Ӳ��ģ���̿�ʼ����0X36
const BYTE COIN_CMD_RES_PROGRAM_SEND         = 0X37;      //Ӳ��ģ�鷢�ͱ����������0X37
const BYTE COIN_CMD_RES_PROGRAM_END          = 0X38;      //Ӳ��ģ���̽�������0X38
const BYTE COIN_CMD_RES_PROGRAM_APP          = 0X39;      //Ӳ��ģ���л���Ӧ�ó�������0X39



const BYTE COIN_CMD_RES_CHANGE               = 0X00;      //Ӳ��ģ����������0x00
const BYTE COIN_CMD_RES_END_CHANGE           = 0X01;      //ѭ�������䡢ר�������������������0x01
const BYTE COIN_CMD_RES_CLEAN                = 0X02;      //Ӳ��ģ���������0x02
const BYTE COIN_CMD_RES_END_CLEAN            = 0X03;      //ѭ�������䡢ר����������ҽ�������0x03
const BYTE COIN_CMD_RES_OPENCLOSE            = 0X04;      //Ӳ��ģ��������������0x04
const BYTE COIN_CMD_RES_POLL                 = 0X05;      //Ӳ��ʶ������ѯ0x05
const BYTE COIN_CMD_RES_ADD                  = 0X06;      //Ӳ��ģ�鲹����ӱ�����0x06
const BYTE COIN_CMD_RES_WRITEID              = 0X07;      //Ӳ��ģ���豸��Ʊ�����IDд����0x07
const BYTE COIN_CMD_RES_READID               = 0X08;      //Ӳ��ģ���豸��Ʊ�����ID������0x08
const BYTE COIN_CMD_RES_BOX_WRITEID          = 0X09;      //Ӳ�һ�����д����0x09
const BYTE COIN_CMD_RES_BOX_READID           = 0X0A;      //Ӳ�һ����������0x0A

const BYTE COIN_CMD_RES_BELT_ROLL            = 0X0B;      //Ӳ������������������0X0B --20161114


//��������
const int COIN_RECV_BUFFER_LEN_	= 300;		//������󳤶�
const unsigned int  COIN_Start=1;                        //��ʼ
const unsigned int  COIN_End=2;                          //����

//ȫ�ֱ���

////////////////////////////////////////////////
///////ƽ̨����





class CCoin : public d_com_agent2_t
{

private :
	bool m_isPort;      //�˿��Ƿ��
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

	bool Coin_CommOpen();												 //�򿪶˿�	
	bool Coin_CommClose();												// �رն˿�
	int  Coin_State(BYTE SensorStatus[8]);								 //Ӳ��ģ��״̬��ѯ����0x31
	int Coin_Test(BYTE Data[2]);										 //Ӳ��ģ���������0x32
	int Coin_Reset();													//Ӳ��ģ�����λ0x33
	int Coin_GetVersion(BYTE & Major,BYTE & Minor);						//Ӳ��ģ�����汾��ѯ0x34
	int Coin_Program_Update();											//Ӳ��ģ������������0X35
	int Coin_Program_Begin(BYTE Data[4]);								//Ӳ��ģ���̿�ʼ����0X36
	int Coin_Program_Send(BYTE Data[64]);								//Ӳ��ģ�鷢�ͱ����������0X37
	int Coin_Program_End();												 //Ӳ��ģ���̽�������0X38
	int Coin_Program_APP();												//Ӳ��ģ���л���Ӧ�ó�������0X39
	int Coin_Change( BYTE Box[2],BYTE Data[3]);							  //Ӳ��ģ����������0x00
	int Coin_Clean(BYTE Box,BYTE Data[2],int iNeedCleanCount,int & count);	 //Ӳ��ģ���������0x02
	int Coin_OpenClose(BYTE Data1[2],BYTE Data2[2]);					  //Ӳ��ģ��������������0x04
	int Coin_Poll(BYTE Data1,BYTE Data2[3]);							  //Ӳ��ʶ������ѯ0x05
	int Coin_Add(BYTE Box,BYTE Data[2],int & count);					  //Ӳ��ģ�鲹����ӱ�����0x06
	int Coin_WriteID(BYTE Data[5]);										  //Ӳ��ģ���豸��Ʊ�����IDд����0x07
	int Coin_ReadID(BYTE Data1,unsigned long & id);						  //Ӳ��ģ���豸��Ʊ�����ID������0x08
	int Coin_Box_WriteID(BYTE Data[13]);								  //Ӳ�һ�����д����0x09
	int Coin_Box_ReadID(BYTE Data[7],unsigned long & id,int & count);     //Ӳ�һ����������0x0A
	int Coin_Belt_Roll(BYTE Data[6]);                                     //Ӳ��ģ����������0x0B
	int  Coin_End_Change( BYTE Data);                                     //ѭ�������䡢ר�������������������0x01
	int  Coin_End_Clean( BYTE Data);                                      //ѭ�������䡢ר����������ҽ�������0x03
};






#endif
