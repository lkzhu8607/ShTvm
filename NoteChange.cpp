#include "2.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"

////////////////////////////
#include <iostream>
using namespace std;
#include "NoteChange.h"
//typedef unsigned char BYTE;
using namespace std;
static const unsigned short BCC_Init=0x0000;
static const unsigned short BCC_Bit=0x0001;
static const unsigned short BCC_Crc=0x8408;
static const BYTE STX=0X02;
static const BYTE ETX=0X03;
static const BYTE DLE=0X10;
static const BYTE NAK=0X15;
static const BYTE ENQ=0X05;
static const BYTE ACK=0X06;
static const BYTE END=0X1C;
static const int  PORT=-1;
static const int  SENDFAIL=-2;
static const int  TIMEOUT=-3;
static const int  SUCCESS=0;
static const int  ERR=1;
static const int  CMDSEQ=-4;


////////////////////////////////////////////////////////////////////////////
//Platform

static int limitTime=1;    //用于出钞时间控制，初始1，随着出钞的数目增加5的倍数,在每个命令执行前进行设置
static int fd;
//static int speed_arr[]={B57600,B38400,B19200,B9600,B4800,B2400,B1200,B300};
//static int name_arr[]={57600,38400,19200,9600,4800,2400,1200,300};

class SerialPortClass : public d_com_agent2_t 
{
public:
};
static SerialPortClass mySerialPort;


//打开端口
static bool ComOpen()
{   
	if (mySerialPort.Conn(gp_conf->Get_bilchg_com_port()))
	{
		LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "com open ok:" << gp_conf->Get_bilchg_com_port() );
		 return true;   
	}
	else
	{
		LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "com open fail:" << gp_conf->Get_bilchg_com_port() );
		return false;
	}
}

//关闭端口
static bool CommClose()
{
	mySerialPort.DisConn();
	LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "com close:" << gp_conf->Get_bilchg_com_port() );
	return true;
}

//发送报文
static bool SendFrame(const BUF_T & buf_in)
{
	if( buf_in.empty() ) 
		return true;
	else
	{
		SCake ck;

		ck.let( (char*)&buf_in[0], (int)buf_in.size() );

		LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << ck.Seri() );

		return mySerialPort.send_bin( ck ) ? true : false;
	}
}

//接受报文
static bool RecvFrame(BUF_T & buf_out,int typeENQ,int typeACK,int typeNAK,int typeMsg)
{

   char recv[1024];
	 int len=1;
	 int readByte;		
	bu_quickflow_t::qf_counter_t now;
	 //struct timeval t_start,t_end; 
	 double timeout=0;	 
	 BYTE mid=0x00;
	 int size=0;
	 int count=0;    //记录循环的次数
	 int number=0;   //记录获取报文分离字符后，需要在获取的字符数
	 int isStart=0; //0:代表接受DEL，然后设置为1   1：代表接受ENQ，ACK，NAK，STX(message报文头设置为2）
	
	 //gettimeofday(&t_start,NULL);
	gp_qf->GetQf( now );
	 buf_out.clear();

   //while(timeout<1000*(5+limitTime))
	while( !gp_qf->IsLongQf( now, 1000*(5+limitTime) / 1000.00 ) )
    {
    	///////读取报文
		SCake ck;
		mySerialPort.recv_bin( ck );
		readByte= (int)ck.len();
		
		if( ck.len() )
			gp_qf->GetQf( now );
		
		if( ck.len() )
			memcpy( recv, ck.buf(), ck.len() );
    //readByte=read(fd,recv,1024);
     //从报文中提取出返回报文
     if(readByte>0)
     	{
     		len=0;
     		while(len<readByte)
     		{
     			mid=recv[len];
     	    if(isStart==0 && mid==DLE)
		    	{
				    buf_out.clear();
			    	buf_out.push_back(mid);
					  isStart=1;
					}
					else if(mid==ENQ && typeENQ==1 && isStart==1)
					{
						buf_out.push_back(mid);
						isStart=1;
		        return true;
					} 
					else if(mid==ACK && typeACK==1 && isStart==1)
					{
						buf_out.push_back(mid);
						isStart=1;
		        return true;
					} 
					else if(mid==NAK && typeNAK==1 && isStart==1)
					{
						buf_out.push_back(mid);
						isStart=1;
		        return true;
					}
					else if(typeMsg==1 && isStart==1)
					{
						if(mid==STX)
						{
							//isMessage=1;
							buf_out.push_back(mid);
							isStart=2;
						}
						else
						{
							isStart=0;
						}
					}else if(typeMsg==1 && isStart==2)
					{
						/*if(mid==END)
							{
								isStart=3;
								buf_out.push_back(mid);
							}
							else
							{
								buf_out.push_back(mid);
							}*/
							buf_out.push_back(mid);
							size=(int)buf_out.size();
							if(size>=4 && buf_out[size-1]==ETX && buf_out[size-2]==DLE &&buf_out[size-3]==END)
							{
								isStart=3;
							}
					}
					else if(typeMsg==1 && isStart==3 && (number<2))
					{
						number++;
						buf_out.push_back(mid);
						/*if(number==1 && mid!=DLE)
						{
							buf_out.clear();
							return false;
						}
						if(number==2 && mid!=ETX)
						{
							buf_out.clear();
							return false;
						}*/
						if(number==2)
						{
							return true;
						}
					}
					else
					{

					}
     	    len++;   
     		};
     	};
    //gettimeofday(&t_end,NULL);
    //timeout=(((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000)-(((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000);
    }
    return false;
}


////////////////////////////////////////////////////////////////////////////
NoteChanger::NoteChanger()
{
	isPort=false;
	Retry=0;
}


void NoteChanger::BCC(BYTE & CRC1,BYTE &CRC2,BYTE * Source,int Length)
{
	int i=0;
	unsigned short bcc=BCC_Init;
	for(i=0;i<Length;i++)
	{
	  BCCbit(bcc,*(Source+i),BCC_Crc);
	}
	CRC1=(BYTE)(bcc/256);
	CRC2=(BYTE)(bcc%256);
	
}

void NoteChanger::BCCbit(unsigned short & bcc,BYTE Data,unsigned short com)
{
	unsigned short WkDAT;
	unsigned short WkCRC;
		int i=0;
	for (i=0 ; i<8 ; i++, Data=Data>>1)
	{
		WkDAT = (unsigned short)Data;
		WkCRC = bcc;
		bcc = bcc >> 1;

		WkDAT = WkDAT^WkCRC;
		WkDAT = WkDAT&BCC_Bit;
		if( WkDAT == BCC_Bit)
		{
			bcc = bcc^com;
		}
	}

}
 
bool NoteChanger::SendCommand(BYTE * inCommand,int length )
{
	BUF_T buf_in;
	BUF_T buf_out;
	bool bool_ret=false;
	BYTE CRC1=0x00;
	BYTE CRC2=0x00;
	int count=0;
	int command_length=length;
	//计算命令BBC校验位
	BCC(CRC1,CRC2,inCommand+2,command_length-4);
	inCommand[command_length-1]=CRC1;
	inCommand[command_length-2]=CRC2;
	//发送ENQ
	buf_in.clear();
	buf_in.push_back(DLE);
	buf_in.push_back(ENQ);
	bool_ret=SendFrame(buf_in);
	if(!bool_ret)
	{
	     return false;
	}
	//接受ACK
    buf_out.clear();
	bool_ret=RecvFrame(buf_out,0,1,1,0);
	if((!bool_ret))
	{
	     return false;
	}
	if(buf_out.size()!=2 || buf_out[0]!=DLE || buf_out[1]!=ACK)
	{
		return false;
	}	  
	//发送command
	while(count<3)
	{
		buf_in.clear();
		for(int i=0;i<command_length;i++)
		{
			buf_in.push_back(inCommand[i]);
		}
		bool_ret=SendFrame(buf_in);
		if(!bool_ret)
		{
			return false;
		}
		//接受ACK
		buf_out.clear();
		bool_ret=RecvFrame(buf_out,0,1,1,0);
		if((!bool_ret))
		{
			 return false;
		}
		if(buf_out.size()==2 || buf_out[0]==DLE || buf_out[1]==ACK)
		{
			return true;
		}else if(buf_out.size()==2 || buf_out[0]==DLE || buf_out[1]==NAK)
		{
			count++;
		}
		else
		{
			return false;
		}
	}
	return false;;
}

bool NoteChanger::RecvCommand(BUF_T & buf_out)
{
	BUF_T buf_in;
	int size=0;
	BYTE * temp;
	BYTE CRC1=0x00;
	BYTE CRC2=0x00;
	bool bool_ret=false;
	int count=0;
	//接受ENQ
	buf_out.clear();
	bool_ret=RecvFrame(buf_out,1,0,0,0);
	if(!bool_ret)
	{
		return false;
	}	
	if(buf_out.size()!=2 || buf_out[0]!=DLE || buf_out[1]!=ENQ)
	{
		return false;
	}
	//发送ACK
	buf_in.clear();
	buf_in.push_back(DLE);
	buf_in.push_back(ACK);
	bool_ret=SendFrame(buf_in);
	if(!bool_ret)
	{
		return false;
	}
	// 接受messagen
	while(count<3)
	{
		buf_out.clear();
		bool_ret=RecvFrame(buf_out,0,0,0,1);
		if(!bool_ret)
		{
			return false;
		}
		//校验BCC
		size=(int)buf_out.size();
		temp=new BYTE[size];
		for(int i=0;i<size;i++)
		{
			temp[i]=buf_out[i];
		}
		BCC(CRC1,CRC2,temp+2,size-4);
		delete []temp;
		if(CRC1==buf_out[size-1] && CRC2==buf_out[size-2])
		{
			buf_in.clear();
			buf_in.push_back(DLE);
			buf_in.push_back(ACK);
			bool_ret=SendFrame(buf_in);
			return true;
		}
		else
		{
			buf_in.clear();
			buf_in.push_back(DLE);
			buf_in.push_back(NAK);
			bool_ret=SendFrame(buf_in);
			count++;
		}
	}
	return false;
	
}

bool NoteChanger::OpenCom()
{   
	bool bool_ret=false;
	Retry=3;
	bool_ret=ComOpen();
	if(bool_ret)
	{
		isPort=true;
	   return true;
	}
	else
	{
		
		return false;
	}
}

bool NoteChanger::CloseCom()
{
	 
	bool bool_ret=false;
	bool_ret=CommClose();
	if(bool_ret)
	{
		isPort=false;
	   return true;
	}
	else
	{
		
		return false;
	}
}


int NoteChanger::Init(BYTE inData[7],BYTE outData[6])	
{
	BYTE szBuf[41]={0x10,0x02,0x00,0x21,0x60,0x02,0xFF,0x00,0x00,0x1A,0x00,}; 
	BUF_T buf_out;
	int size=0;
	//BYTE * buffer;
	int int_ret;
	int count=0;
	int bool_ret=false;
	BYTE temp[4]={0};
	//参数设置
	szBuf[11] = inData[0]; //ODR的第二个字节
	szBuf[12] = inData[1];
	szBuf[13] = inData[2];
	szBuf[14] = inData[3];
	szBuf[15] = inData[4];
	szBuf[20] = inData[5];
	szBuf[21] = inData[6];
	//szBuf[11] = 0xC0; //ODR的第二个字节
	//szBuf[12] = 0x96;
	//szBuf[13] = 0x82;
	//szBuf[14] = 0x96;
	//szBuf[15] = 0x82;
	//szBuf[20] = 0x0c;
	//szBuf[21] = 0x0c;
	szBuf[36] = END; //FS
	szBuf[37] = DLE;
	szBuf[38] = ETX;
	//szBuf[11] = Odr; //ODR的第二个字节
	//szBuf[12] = Box1BillLongMax;
	//szBuf[13] = Box1BillLongMin;
	//szBuf[14] = Box2BillLongMax;
	//szBuf[15] = Box2BillLongMin;
	//szBuf[20] = Box1BillThickness;
	//szBuf[21] = Box2BillThickness;
	limitTime =5;
	if(!isPort)
	{
		return int_ret=PORT;
	}
    do
	{
		bool_ret=SendCommand(szBuf,41);
		if(!bool_ret)
		{
			int_ret=SENDFAIL;
		}
		else
		{
			buf_out.clear();
			bool_ret=RecvCommand(buf_out);
			if(!bool_ret)
			{
				int_ret=TIMEOUT;
			}
			else
			{
				//正确报文处理
				if(buf_out[4]==0xE0 && buf_out[5]==0x02)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					delete []buffer;*/
					//return int_ret=size;
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData);
				   	return int_ret=SUCCESS;
				}
				else if(buf_out[4]==0xF0 && buf_out[5]==0x02)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					delete []buffer;*/
					//第一个纸币找零箱为空
					if(buf_out[10]==0x11)
					{
						//第一个纸币找零箱为空
						int_ret=2;
					}
					else if(buf_out[10]==0x21)
					{
						//第二个纸币找零箱为空
						int_ret=3;
					}
//					else if(buf_out[10]==0x10)
//					{
//						//第一个纸币找零箱不存在
//						int_ret=4;
//					}
//					else if(buf_out[10]==0x20)
//					{
//						//第二个纸币找零箱不存在
//						int_ret=5;
//					}
					else if(buf_out[10]==0xB5)
					{
						//回收箱溢出
						int_ret=4;
					}
					else
					{
						int_ret=ERR;
					}
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData);
					return int_ret;
				}
				else
				{  
					return int_ret=CMDSEQ;
				}			
			}
		}
	}while(count<Retry);
	return int_ret;
}

int NoteChanger::Status(BYTE outData[6])
{   
	BYTE status_command[16]={0x10,0x02,0x00,0x08,0x60,0x01,0xFF,0x00,0x00,0x01,0x00,0x1C,0x10,0x03,0x00,0x00}; 
	BUF_T buf_out;
	int size=0;
	//BYTE * buffer;
	int int_ret=0;
	int count=0;
	int bool_ret=false;
	BYTE temp[4]={0};
	limitTime =5;
	if(!isPort)
	{
		return int_ret=PORT;
	}
    do
	{
		bool_ret=SendCommand(status_command,16);
		if(!bool_ret)
		{
			int_ret=SENDFAIL;
		}
		else
		{
			buf_out.clear();
			bool_ret=RecvCommand(buf_out);
			if(!bool_ret)
			{
				int_ret=TIMEOUT;
			}
			else
			{
				//正确报文处理
				if(buf_out[4]==0xE0 && buf_out[5]==0x01)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					delete []buffer;*/
					//return int_ret=size;
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData);
					return int_ret=SUCCESS;
				}
				else if(buf_out[4]==0xF0 && buf_out[5]==0x01)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					delete []buffer;*/
					//第一个纸币找零箱为空
					if(buf_out[10]==0x11)
					{
						//第一个纸币找零箱为空
						int_ret=2;
					}
					else if(buf_out[10]==0x21)
					{
						//第二个纸币找零箱为空
						int_ret=3;
					}
//					else if(buf_out[10]==0x10)
//					{
//						//第一个纸币找零箱不存在
//						int_ret=4;
//					}
//					else if(buf_out[10]==0x20)
//					{
//						//第二个纸币找零箱不存在
//						int_ret=5;
//					}
					else if(buf_out[10]==0xB5)
					{
						//回收箱溢出
						int_ret=4;
					}
					else
					{
						int_ret=ERR;
					}
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData);
					return int_ret;
				}
				else
				{  
					return int_ret=CMDSEQ;
				}			
			}
		}
	}while(count<Retry);
	return int_ret;
}

int NoteChanger::Count(BYTE inData[6],BYTE outData[2],BYTE rejectData[2],BYTE outData1[6])
{
	BYTE szBuf[59] = {0x10,0x02,0x00,0x33,0x60,0x03,0xFF,0x00,0x00,0x2C,0xFE,0xDC,0xBA,0x98,};
	BUF_T buf_out;
	int size=0;
	//BYTE * buffer;
	int int_ret=0;
	int count=0;
	int bool_ret=false;
	char changebuf[2] = {0};
	BYTE temp[4]={0};
	BYTE isocode = 0x0;	
	//BYTE N1Count=0x03;
	//BYTE N2Count=0x06;
	//BYTE R1Max=0x02;
	//BYTE R2Max=0x02;
	//BYTE Pick1=0x01;
	//BYTE Pick2=0x01;
	BYTE N1Count=inData[0];
	BYTE N2Count=inData[1];
	BYTE R1Max=inData[2];
	BYTE R2Max=inData[3];
	BYTE Pick1=inData[4];
	BYTE Pick2=inData[5];
	limitTime =int(N1Count+N2Count+R1Max+R2Max+Pick1+Pick2)*5;
	IntToHexBcd(N1Count, changebuf);
	isocode = changeBcdToISO(changebuf[0]);
	szBuf[14] = isocode;
	isocode = changeBcdToISO(changebuf[1]);
	szBuf[15] = isocode;

	memset(changebuf, 0, 2);
	IntToHexBcd(N2Count, changebuf);
	isocode = changeBcdToISO(changebuf[0]);
	szBuf[16] = isocode;
	isocode = changeBcdToISO(changebuf[1]);
	szBuf[17] = isocode;

	memset(&szBuf[18], 0x30, 4); //其它Nx参数写入"0"的ISO Code	
	
	memset(changebuf, 0, 2);
	IntToHexBcd(R1Max, changebuf);
	isocode = changeBcdToISO(changebuf[0]);
	szBuf[22] = isocode;
	isocode = changeBcdToISO(changebuf[1]);
	szBuf[23] = isocode;

	memset(changebuf, 0, 2);
	IntToHexBcd(R2Max, changebuf);
	isocode = changeBcdToISO(changebuf[0]);
	szBuf[24] = isocode;
	isocode = changeBcdToISO(changebuf[1]);
	szBuf[25] = isocode;

	memset(&szBuf[26], 0x30, 4); //其它Rx参数写入"0"的ISO Code

	szBuf[30] = Pick1;
	szBuf[31] = Pick2;

	memset(&szBuf[34], 0x30, 16); //其它Rx,Nx参数写入"0"的ISO Code

	szBuf[54] = END;
	szBuf[55] = DLE;
	szBuf[56] = ETX;

	if(!isPort)
	{
		return int_ret=PORT;
	}
    do
	{
		bool_ret=SendCommand(szBuf,59);
		if(!bool_ret)
		{
			int_ret=SENDFAIL;
		}
		else
		{
			buf_out.clear();
			bool_ret=RecvCommand(buf_out);

			SCake ck;

			ck.let( (char*)&buf_out[0], (int)buf_out.size() );

			if(!bool_ret)
			{
				int_ret=TIMEOUT;
			}
			else
			{
				//正确报文处理
				if(buf_out[4]==0xE0 && buf_out[5]==0x03)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					cout<<"box1 couted:"<<" "<<(int)buffer[94]<<" "<<(int)buffer[95]<<endl;
					cout<<"box2 couted:"<<" "<<(int)buffer[96]<<" "<<(int)buffer[97]<<endl;
					cout<<"box1 rejected:"<<" "<<(int)buffer[102]<<" "<<(int)buffer[103]<<endl;
					cout<<"box2 rejected:"<<" "<<(int)buffer[104]<<" "<<(int)buffer[105]<<endl;
					cout<<"box1 to be couted:"<<" "<<(int)buffer[175]<<" "<<(int)buffer[176]<<endl;
					cout<<"box2 to be couted:"<<" "<<(int)buffer[177]<<" "<<(int)buffer[178]<<endl;
					delete []buffer;*/
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[94];
					changebuf[1]=buf_out[95];
					HexBcdToInt(outData[0],changebuf[0],changebuf[1]);
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[96];
					changebuf[1]=buf_out[97];
					HexBcdToInt(outData[1],changebuf[0],changebuf[1]);
					//剔除废币的数量
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[102];
					changebuf[1]=buf_out[103];
					HexBcdToInt(rejectData[0],changebuf[0],changebuf[1]);
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[104];
					changebuf[1]=buf_out[105];
					HexBcdToInt(rejectData[1],changebuf[0],changebuf[1]);
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData);
					return int_ret=SUCCESS;
				}
				else if(buf_out[4]==0xF0 && buf_out[5]==0x03)
				{
					size=(int)buf_out.size();
					/*buffer=new BYTE[size];
					for(int i=0;i<size;i++)
					{
						buffer[i]=buf_out[i];
					}
					Message(buffer);
					cout<<"box1 couted:"<<" "<<(int)buffer[94]<<" "<<(int)buffer[95]<<endl;
					cout<<"box2 couted:"<<" "<<(int)buffer[96]<<" "<<(int)buffer[97]<<endl;
					cout<<"box1 rejected:"<<" "<<(int)buffer[102]<<" "<<(int)buffer[103]<<endl;
					cout<<"box2 rejected:"<<" "<<(int)buffer[104]<<" "<<(int)buffer[105]<<endl;
					cout<<"box1 to be couted:"<<" "<<(int)buffer[175]<<" "<<(int)buffer[176]<<endl;
					cout<<"box2 to be couted:"<<" "<<(int)buffer[177]<<" "<<(int)buffer[178]<<endl;
					delete []buffer;*/
					
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[94];
					changebuf[1]=buf_out[95];
					HexBcdToInt(outData[0],changebuf[0],changebuf[1]);
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[96];
					changebuf[1]=buf_out[97];
					HexBcdToInt(outData[1],changebuf[0],changebuf[1]);
					//剔除废币的数量
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[102];
					changebuf[1]=buf_out[103];
					HexBcdToInt(rejectData[0],changebuf[0],changebuf[1]);
					memset(changebuf, 0, 2);
					changebuf[0]=buf_out[104];
					changebuf[1]=buf_out[105];
					HexBcdToInt(rejectData[1],changebuf[0],changebuf[1]);
					if(buf_out[10]==0x11)
					{
						//第一个纸币找零箱为空
						int_ret=2;
					}
					else if(buf_out[10]==0x21)
					{
						//第二个纸币找零箱为空
						int_ret=3;
					}
//					else if(buf_out[10]==0x10)
//					{
//						//第一个纸币找零箱不存在
//						int_ret=4;
//					}else if(buf_out[10]==0x20)
//					{
//						//第二个纸币找零箱不存在
//						int_ret=5;
//					}
					else if(buf_out[10]==0xB5)
					{
						//回收箱溢出
						int_ret=4;
					}
					else
					{
						int_ret=ERR;
					}
					/*if(buf_out[10]==0x11 && N2Count!=0x00 && outData[1]<N2Count)
					{
						int_ret=ERR;
					}
					if(buf_out[10]==0x21 && N1Count!=0x00 && outData[0]<N1Count)
					{
						int_ret=ERR;
					}*/
					memset(temp,0,4);
					temp[0]=buf_out[25];
					temp[1]=buf_out[26];
					temp[2]=buf_out[17];
					temp[3]=buf_out[21];
					MessageCommon(temp,outData1);
					return int_ret;
				}
				else
				{  
					return int_ret=CMDSEQ;
				}			
			}
		}
	}while(count<Retry);
	return int_ret;
}



//返回代码公用部分解析,仅用于测试
void NoteChanger::Message(BYTE *message)
{
	//
	 cout<<"**********************************************"<<endl;
     cout<<"Error code:"<<(int)message[10]<<" "<<(int)message[11]<<endl;
	 cout<<"Error address:"<<(int)message[40]<<" "<<(int)message[41]<<" "<<(int)message[42]<<" "<<(int)message[43]<<endl;
	 cout<<"Error register:"<<(int)message[16]<<" "<<(int)message[17]<<" "<<(int)message[18]<<endl;
	 cout<<"Error register2:"<<(int)message[64]<<" "<<(int)message[65]<<" "<<(int)message[66]<<endl;
	 cout<<"**********************************************"<<endl;
	 cout<<"Version:"<<(int)message[12]<<" "<<(int)message[13]<<" "<<(int)message[14]<<" "<<(int)message[15]<<endl;
	 cout<<"Version information:"<<(int)message[52]<<" "<<(int)message[53]<<" "<<(int)message[54]<<" "<<(int)message[55]<<" "<<(int)message[56]<<" "<<(int)message[57]<<endl;
	 //cout<<"Data information:"<<(int)message[36]<<" "<<(int)message[37]<<" "<<(int)message[38]<<" "<<(int)message[39]<<" "<<(int)message[40]<<" "<<(int)message[41]<<endl;
	 cout<<"Data information:"<<(int)message[36]<<" "<<(int)message[37]<<" "<<(int)message[38]<<" "<<(int)message[39]<<" "<<(int)message[40]<<" "<<(int)message[41]<<endl;
	 cout<<"POM:"<<(int)message[29]<<endl;
	 cout<<"**********************************************"<<endl;
	 cout<<"Sensor register:"<<(int)message[19]<<" "<<(int)message[20]<<" "<<(int)message[21]<<" "<<(int)message[22]<<" "<<(int)message[23]<<" "<<(int)message[24]<<endl;
	 cout<<"Sensor register2:"<<(int)message[67]<<" "<<(int)message[68]<<" "<<(int)message[69]<<" "<<(int)message[70]<<" "<<(int)message[71]<<" "<<(int)message[72]<<endl;
	 cout<<"**********************************************"<<endl;
	 cout<<"Box1: length:"<<" "<<(int)message[30]<<" width:"<<" "<<(int)message[31]<<" thickness:"<<" "<<(int)message[38]<<" left: "<<(int)message[42]<<endl;
	 cout<<"Box2: length:"<<" "<<(int)message[32]<<" width:"<<" "<<(int)message[33]<<" thickness:"<<" "<<(int)message[39]<<" left: "<<(int)message[43]<<endl;
}

void NoteChanger::IntToHexBcd(BYTE num, char hexbcd[2])
{
	BYTE tmp;
	tmp = ( (num/10)*16 + num%10 );

	hexbcd[0] = (BYTE)( tmp/0x10 );
	hexbcd[1] = (BYTE)( tmp&0x0F );
}

BYTE NoteChanger::changeBcdToISO(char bcdcode)
{
	BYTE nRt = 0x0;
	
	switch(bcdcode)
	{
	case 0x0:
		nRt = 0x30;
		break;
	case 0x1:
		nRt = 0xB1;
		break;
	case 0x2:
		nRt = 0xB2;
	    break;
	case 0x3:
		nRt = 0x33;
	    break;
	case 0x4:
		nRt = 0xB4;
		break;
	case 0x5:
		nRt = 0x35;
		break;
	case 0x6:
		nRt = 0x36;
	    break;
	case 0x7:
		nRt = 0xB7;
	    break;
	case 0x8:
		nRt = 0xB8;
	    break;
	case 0x9:
		nRt = 0x39;
		break;
	}
	return nRt;
}

BYTE NoteChanger::changeISOToBcd(BYTE iso1)
{
	BYTE nRt = 0x0;
	
	switch(iso1)
	{
	case 0x30:
		nRt = 0x0;
		break;
	case 0xB1:
		nRt = 0x1;
		break;
	case 0xB2:
		nRt = 0x2;
	    break;
	case 0x33:
		nRt = 0x3;
	    break;
	case 0xB4:
		nRt = 0x4;
		break;
	case 0x35:
		nRt = 0x5;
		break;
	case 0x36:
		nRt = 0x6;
	    break;
	case 0xB7:
		nRt = 0x7;
	    break;
	case 0xB8:
		nRt = 0x8;
	    break;
	case 0x39:
		nRt = 0x9;
		break;
	}
	return nRt;
}

void NoteChanger::HexBcdToInt(BYTE & num, BYTE hexbcd1,BYTE hexbcd2)
{
	BYTE temp1,temp2;
	temp1=changeISOToBcd(hexbcd1);
	temp2=changeISOToBcd(hexbcd2);
	num=(BYTE)((int)temp1*10+(int)temp2);
}


void NoteChanger::MessageCommon(BYTE inData[4],BYTE outData[6])
{
  if(inData[0]&0x10)
  {
	  outData[0]=0x01;
  }
  else
  {
	  outData[0]=0x00;
  }
  ////////////////////
  if(inData[1]&0x10)
  {
	  outData[1]=0x01;
  }
  else
  {
	  outData[1]=0x00;
  }
  /////////////////////////
  if(inData[0]&0x80)
  {
	  outData[3]=0x01;
  }
  else
  {
	  outData[3]=0x00;
  }
  ////////////////////////////
   if(inData[1]&0x80)
  {
	  outData[4]=0x01;
  }
  else
  {
	  outData[4]=0x00;
  }
   /////////////////////////
   if(inData[2]&0x04)
   {
	   outData[5]=0x01;
   }
   else
   {
	   outData[5]=0x00;
   }
   //////////////////////////
  /* if((inData[3]&0x40)&&(inData[3]&0x20))
   {
	   outData[2]=0x00;
   }
   else
   {
	   outData[2]=0x01;
   }*/
   if(inData[3]&0x40)
   {
		if((inData[3]&0x20))
	   {
		   outData[2]=0x01;
	   }
	   else
	   {
		   outData[2]=0x00;
	   }
   }
   else
   {
	   outData[2]=0x01;
   }

}
