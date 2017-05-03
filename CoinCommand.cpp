
#include "CoinCommand.h"



CCoin::CCoin()
{

	m_Coin_iSeq = 0;
	m_Coin_iRetry = 3;
}

CCoin::~CCoin()
{

}

BYTE CCoin::procchar(BYTE current,BYTE pre)
{   
	  BYTE ret=0xFF;
	  if(pre!=0x10&&current==0x02)
	  	    { 
	  	    	return CHAR_START;
	  	    	};
	  if(pre!=0x10&&current==0x03)
	  	{    
	  	    return CHAR_END;
	  	  };
	  	return ret;
	  
}
//打开端口
bool CCoin::CommOpen()
{   
	if (m_aCom.Conn(gp_conf->Get_coin_com_port()))
	{
		LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "com open ok:" << gp_conf->Get_coin_com_port() );
		 return true;   
	}
	else
	{
		LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "com open fail:" << gp_conf->Get_coin_com_port() );
		return false;
	}
}

//关闭端口
bool CCoin::CommClose()
{
	LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << "com close:" << gp_conf->Get_coin_com_port() );
	m_aCom.DisConn();
	return true;
}

//发送报文
bool CCoin::SendFrame(const BUF_T & buf_in)
{
	if( buf_in.empty() ) 
		return true;
	else
	{
		SCake ck;

		ck.let( (char*)&buf_in[0], (int)buf_in.size() );
		LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << ck.Seri_S() );
		return m_aCom.send_bin( ck ) ? true : false;
	}
}

//接受报文
bool CCoin::RecvFrame(BUF_T & buf_out)
{
	char recv[1024];
	int len=1;
	int readByte;		
	bu_quickflow_t::qf_counter_t now;
	 
	BYTE pre=0xFF;
	BYTE current=0x00;
	BYTE nret=0x00;
	bool isStart=false;
	
	gp_qf->GetQf( now );
	 buf_out.clear();

	while( !gp_qf->IsLongQf( now, 900 / 1000.00 ) )
	{
		///////读取报文
		SCake ck;

		m_aCom.recv_bin( ck );
		
		if( ck.len() )
			gp_qf->GetQf( now ); //有数据则超时清0重记。	

		readByte= (int)ck.len();
		if( ck.len() )
			memcpy( recv, ck.buf(), ck.len() );

		//从报文中提取出返回报文
		if(readByte>0)
		{
			len=0;
			while(len<readByte)
			{
				current=recv[len];
				nret=procchar(current,pre);
				if(nret==CHAR_START)
				{
					buf_out.clear();
					isStart=true;
					pre=current;
					buf_out.push_back(current);
				}
				else if(nret==CHAR_END && isStart)
				{
					buf_out.push_back(current);
					pre=0xFF;
					return true;
				}
				else
				{
					buf_out.push_back(current);
					if(current==0x10&&pre==0x10)
					{
						pre=0xFF;
					}
					else
					{
						pre=current;
					}
				}
				len++;   
			}
		}
		
	}
	return false;
}



//////////////////////////////////////////////////////////////////////////
/////////硬币命令



//发送时在报文中插入COIN_DLE字符
unsigned int CCoin::InsertDLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[COIN_RECV_BUFFER_LEN_];
	int dle_cnt = 0;

	for (int i=0; i<nLen; i++)
	{
		if ( (pBuf[i]==COIN_STX)||(pBuf[i]==COIN_ETX)||(pBuf[i]==COIN_DLE) )
		{
			//插入的COIN_DLE字符必须在字符前面插入
			sdata[i+dle_cnt] = COIN_DLE;			
			dle_cnt++;
			sdata[i+dle_cnt] = pBuf[i];		
		}
		else
		{
			sdata[i+dle_cnt] = pBuf[i];
		}
		
	}	

	memcpy(ptarget, sdata, nLen+dle_cnt);
	return (nLen+dle_cnt);
}

//接受到正常报文时在报文中去除COIN_DLE字符
unsigned int CCoin::DeleteDLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[COIN_RECV_BUFFER_LEN_];
	int dle_cnt = 0;
	int j=1;
	sdata[0]=pBuf[0];
	int dle=0; //作为判定一个字符是不是需要转义，初始时0表示不需要转义
	for (int i=1; i<nLen-1; i++)
	{
		if ( pBuf[i]==COIN_DLE && dle==0 )
		{
			dle=1;
				
		}
		else
		{   
			dle=0;
			sdata[j] = pBuf[i];
			j++;
		}
		
	}	
	sdata[j]=pBuf[nLen-1];
	j++;
	memcpy(ptarget, sdata, j);
	return (j);
}

bool CCoin::SendCommand(BYTE * Data,int nLen)
{
	unsigned char OriData[COIN_RECV_BUFFER_LEN_];
	memcpy(OriData,Data, nLen);
	OriData[nLen] = 0; 
	for (int i=0;i<nLen;i++)
	{
		OriData[nLen] ^= OriData[i];
	}

	//
	//wl::SCake ck;
	//ck.let( (char*)Data,nLen );
	//LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << ck.Seri_S());

	unsigned char localdata[COIN_RECV_BUFFER_LEN_];
	localdata[0] = COIN_STX;
	unsigned int nNewLen = InsertDLE(OriData, nLen+1, localdata+1) + 2;
	localdata[nNewLen-1] = COIN_ETX;

	

	BUF_T buff_in;
	//std::string strsend;
	for(unsigned int i=0;i<nNewLen;i++)
	{
		buff_in.push_back(localdata[i]);
		//strsend += wl::SStrf::sltoa( localdata[i] );
		//strsend += " ";
	}

	if(	SendFrame(buff_in))
	{    
		/*for(int i=0;i<buff_in.size();i++)
		cout<<"写日志："<<hex<<int(buff_in[i])<<endl;*/
		//添加写日志
		//cLog.Trace(_T("Send: "),localdata,nNewLen);
		////////////
		return true;
	}
	else
	{
		return false;
	}
}

//接受报文
bool CCoin::RecvCommand(BYTE * Data,int & nLen)
{   BUF_T buf_out;
    BYTE  pBuf[COIN_RECV_BUFFER_LEN_];
	BYTE  BCC=0x00;
	memset(pBuf,0,COIN_RECV_BUFFER_LEN_);
	 
	//正常的获取报文
	if(RecvFrame(buf_out))
	{    

	     for(unsigned int i=0;i<buf_out.size();i++)
		     pBuf[i]=buf_out[i];
	        nLen=(int)buf_out.size();
		 //添加写日志
		/* for(int i=0;i<buf_out.size();i++)
		cout<<"读日志："<<hex<<int(buf_out[i])<<endl;*/
		 //cLog.Trace(_T("Recv: "),pBuf,nLen);
		 ////////////
		

	     nLen=DeleteDLE(pBuf,nLen,Data);


	    wl::SCake ck;
		ck.let( (char*)Data,nLen );
		LOGSTREAM( gp_log[LOGCOIN], LOGPOSI << ck.Seri_S());

		 //检查长度
		 if(nLen>4 && Data[1]==nLen-4)
		 {   
			 //检验BCC
			 for(int i=1;i<nLen-2;i++)
			 {
				 BCC^=Data[i];
			 }
			if(BCC==Data[nLen-2])
			{
			  return true;
			}
			else
			{
			return false;
			}
		 }
		 else
		 {
			 return false;
		 }
	}
	else
	{
	  return false;
	}
}



//打开端口
bool CCoin::Coin_CommOpen()
{ 
	m_Coin_iRetry= 3;
	//CommOpen(ComPort,Rate);
	//cLog.Init(_T("Log"));
	if(CommOpen())
	{   
		//cLog.Trace(_T("Open success!"));
		m_isPort=true;
		return true;
	}
	else
	{
	    //cLog.Trace(_T("Open failed！"));
		return false;
	}
}

// 关闭端口
bool CCoin::Coin_CommClose()
{
	//CommClose();
	if(CommClose())
	{
		//cLog.Trace(_T("Close success!"));
		m_isPort=false;
		return true;
	}
	else
	{
	    //cLog.Trace(_T("Close failed！"));
		return false;
	}
}

//硬币模块状态查询命令0x31
int CCoin::Coin_State(BYTE SensorStatus[8])
{   const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	unsigned int iSend=1;
	BYTE temp=0x00;
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_STATE;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_STATE && szRecv[3]==iSeq && szRecv[1]==0x0A)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{   
						///////////////////
						SensorStatus[0]=szRecv[5];
						SensorStatus[1]=szRecv[6];
						/////////////////////////投币口光感状态：
						//temp=szRecv[5]&0x04;
						//SensorStatus[2]=temp;
						//temp=szRecv[7]&0x33;
						//SensorStatus[2]|=temp;
						////SensorStatus[2] = szRecv[7];
						/////////////////////////////
						//temp=szRecv[7]&0xFC;
						//SensorStatus[3]=(temp>>2);

						SensorStatus[2]=szRecv[7];
						//////////////////
						for(int i=3,j=8;j<12;j++,i++)
						{
							SensorStatus[i]=szRecv[j];
						}
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
	
}

//硬币模块测试命令0x32
int CCoin::Coin_Test(BYTE Data[2])
{
	const int nLen = 5;
	int ret = COIN_DLL_RES_SENDFAIL	;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_TEST;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data[0];
	szBuf[4] = Data[1];
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_TEST && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	return ret;
}

//硬币模块程序复位0x33
int CCoin::Coin_Reset()
{
	const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL	;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_RESET;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
		
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_RESET && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块程序版本查询0x34
int CCoin::Coin_GetVersion(BYTE & Major,BYTE & Minor)
{
    const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL	;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_VERSION;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_VERSION && szRecv[3]==iSeq && szRecv[1]==0x05)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{   
						Major=szRecv[5];
						Minor=szRecv[6];
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	
	return ret;
}


//硬币模块程序更新命令0X35
int CCoin::Coin_Program_Update()
{
    const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
    //读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_PROGRAM_UPDATE;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_PROGRAM_UPDATE  && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
//	cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块编程开始命令0X36
int CCoin::Coin_Program_Begin(BYTE Data[4])
{
    const int nLen = 7;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_PROGRAM_BEGIN;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data[0];
	szBuf[4] = Data[1];
	szBuf[5] = Data[2];
	szBuf[6] = Data[3];
	//pthread_mutex_lock(&mySerialPort.coinMutex);
   do
   {
		if ( SendCommand( szBuf, nLen) )
		{		
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_PROGRAM_BEGIN  && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
   }while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块发送编程数据命令0X37
int CCoin::Coin_Program_Send(BYTE Data[64])
{
     const int nLen = 67;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_PROGRAM_SEND;
	szBuf[2] =(BYTE)iSeq;
	for(int i=0,j=3;i<64;i++,j++)
	{
	szBuf[j] = Data[i];
	}
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_PROGRAM_SEND && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块编程结束命令0X38
int CCoin::Coin_Program_End()
{
     const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_PROGRAM_END;
	szBuf[2] = (BYTE)iSeq;
  	//pthread_mutex_lock(&mySerialPort.coinMutex);
	 do
	 { if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_PROGRAM_END && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
	 iSend++;
	 }while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块切换到应用程序命令0X39
int CCoin::Coin_Program_APP()
{
    const int nLen = 3;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_PROGRAM_APP;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_PROGRAM_APP && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}



//硬币模块找零命令0x00-----------------------------
int CCoin::Coin_Change( BYTE Box[2],BYTE Data[3])
{
    const int nLen = 6;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	bool isProc=true;  //标志报文是过程报文换是命令报文，true 过程报文，false 命令报文
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_CHANGE;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Box[0];
	szBuf[4] = 0xBB;  //执行B命令
	szBuf[5] = Box[1];
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			int nRecvLen = 0;
			isProc=true;
			while(isProc)
			{
				memset(szRecv, 0, sizeof(szRecv));
				if (RecvCommand(szRecv, nRecvLen))
				{
					//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
					//处理过程报文
					if(szRecv[2]== COIN_CMD_RES_CHANGE && szRecv[3]==iSeq && szRecv[1]==0x05)
					{
					   //不处理过程应答
					}
					else if (szRecv[2]== COIN_CMD_RES_CHANGE && szRecv[3]==iSeq && szRecv[1]==0x07)	//命令及序列号相同
					{   
				
						if (szRecv[4]==COIN_MODULE_STATE_OK)
						{   					
							Data[0]=szRecv[5];
							Data[1]=szRecv[7];
							Data[2]=szRecv[8];
							ret = COIN_DLL_RES_OK;	
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
						{
							ret = COIN_DLL_RES_FAIL	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
						{
							ret = COIN_DLL_RES_BUSY	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
						{
							ret = COIN_DLL_RES_OTHERWRONG	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						isProc=false;
					}
					else
					{
						//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
						ret = COIN_DLL_RES_CMDSEQ;
						isProc=false;
					}
				}
				else
				{   
					//可在此添加次数限制				
					ret = COIN_DLL_RES_TIMEOUT;
					isProc=false;
				}
			}//while
		}//if
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块清币命令0x02-----------------------------
int CCoin::Coin_Clean(BYTE Box,BYTE Data[2] ,int iNeedCleanCount,int &count)
{
    const int nLen = 6;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	bool isProc=true;  //标志报文是过程报文换是命令报文，true 过程报文，false 命令报文
	unsigned int iSeq;
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_CLEAN;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Box;
	szBuf[4] = 0xBC;
	szBuf[5] = iNeedCleanCount;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
		
			int nRecvLen = 0;
			isProc=true;
			while( isProc )
			{
				memset(szRecv, 0, sizeof(szRecv));
				if (RecvCommand(szRecv, nRecvLen))
				{
					wl::SCake ck;
					ck.let( (char*)szRecv,nRecvLen );
					LOGSTREAM( gp_log[LOGAPP], LOGPOSI << ck.Seri_S());
					//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
					if(szRecv[2]== COIN_CMD_RES_CLEAN && szRecv[3]==iSeq  && szRecv[1]==0x05)
					{
						//处理过程报文
					}
					else if (szRecv[2]== COIN_CMD_RES_CLEAN && szRecv[3]==iSeq && szRecv[1]==0x08)	//命令及序列号相同
					{
						if (szRecv[4]==COIN_MODULE_STATE_OK)
						{   
							//命令应答  过程应答						
							Data[0]=szRecv[5];
							Data[1]=szRecv[9];
							/*Data[1]=szRecv[7];
							Data[2]=szRecv[8];
							Data[3]=szRecv[9];*/
							count=(int(szRecv[7])*256)+((int)(szRecv[8]));
							ret = COIN_DLL_RES_OK;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
						{
							ret = COIN_DLL_RES_FAIL	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
						{
							ret = COIN_DLL_RES_BUSY	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
						{
							ret = COIN_DLL_RES_OTHERWRONG	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						isProc=false;
					}
					else
					{
						//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
						ret = COIN_DLL_RES_CMDSEQ;
						isProc=false;
					}
				}
				else
				{
					ret = COIN_DLL_RES_TIMEOUT;
					isProc=false;
				}
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块电磁铁开关命令0x04
int CCoin::Coin_OpenClose(BYTE Data1[2],BYTE Data2[2])
{
   const int nLen = 5;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_OPENCLOSE;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data1[0];
	szBuf[4] = Data1[1];
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;
			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_OPENCLOSE && szRecv[3]==iSeq && szRecv[1]==0x05)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{  
						Data2[0]=szRecv[5];
						Data2[1]=szRecv[6];
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						cout<<"--------设备忙。。。---------"<<endl;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
				//SendCommand( szBuf, nLen);
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);//m_Coin_iRetry=3
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币识别器轮询0x05
int CCoin::Coin_Poll( BYTE  Data1,BYTE Data2[3])
{
    const int nLen = 4;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_POLL;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data1;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_POLL && szRecv[3]==iSeq && szRecv[1]==0x06)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						Data2[0]=szRecv[5];
						Data2[1]=szRecv[6];
						Data2[2]=szRecv[7];
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						cout<<"--------设备忙。。。---------"<<endl;
						ret = COIN_DLL_RES_BUSY	;
						
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块补币箱加币命令0x06------------------------
int CCoin::Coin_Add(BYTE Box,BYTE Data[2],int & count)
{
    const int nLen = 5;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	bool isProc=true;  //标志报文是过程报文换是命令报文，true 过程报文，false 命令报文
	unsigned int iSeq;
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_ADD;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Box;
	szBuf[4] = 0xBC;
		
	//pthread_mutex_lock(&mySerialPort.coinMutex);
    do
    {	if ( SendCommand( szBuf, nLen) )
		{
		
			int nRecvLen = 0;
			isProc=true;
			while( isProc )
			{
				memset(szRecv, 0, sizeof(szRecv));
				if (RecvCommand(szRecv, nRecvLen))
				{
					//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
					if(szRecv[2]== COIN_CMD_RES_ADD && szRecv[3]==iSeq &&szRecv[1]==0x05)
					{
					   //处理过程报文
					}
					else if (szRecv[2]== COIN_CMD_RES_ADD && szRecv[3]==iSeq &&szRecv[1]==0x08)	//命令及序列号相同
					{
						if (szRecv[4]==COIN_MODULE_STATE_OK)
						{   
					
							Data[0]=szRecv[5];
							Data[1]=szRecv[9];
							/*Data[1]=szRecv[7];
							Data[2]=szRecv[8];
							Data[3]=szRecv[9];*/
							count=(int(szRecv[7])*256)+((int)(szRecv[8]));
							ret = COIN_DLL_RES_OK;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
						{
							ret = COIN_DLL_RES_FAIL	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
						{
							ret = COIN_DLL_RES_BUSY	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
						{
							ret = COIN_DLL_RES_OTHERWRONG	;
							m_Coin_iSeq++;
							//pthread_mutex_unlock(&mySerialPort.coinMutex);
							return ret;
						}
						isProc=false;
					}
					else
					{
						//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
						isProc=false;
						ret = COIN_DLL_RES_CMDSEQ;
					}
					
				}
				else
				{
					ret = COIN_DLL_RES_TIMEOUT;
					isProc=false;
				}
			}
		}
	   iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币模块设备与票箱电子ID写命令0x07
int CCoin::Coin_WriteID(BYTE Data[5])
{
    const int nLen = 8;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_WRITEID;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data[0];
	szBuf[4] = Data[1];
	szBuf[5] = Data[2];
	szBuf[6] = Data[3];
	szBuf[7] = Data[4];
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_WRITEID && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}
//硬币模块设备与票箱电子ID读命令0x08
int CCoin::Coin_ReadID(BYTE Data1, unsigned long & id)
{
    const int nLen = 4;
	int ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	unsigned long idTemp=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	BYTE temp=0x00;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_READID;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data1;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_READID && szRecv[3]==iSeq && szRecv[1]==0x07)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						/*Data2[0]=szRecv[5];
						Data2[1]=szRecv[6];
						Data2[2]=szRecv[7];
						Data2[3]=szRecv[8];*/
						id=0;
						for(int i=5,j=7;i<9;i++)
						{
						      temp=(szRecv[i]&0xF0)>>4;
							  for(int k=1;k<=j;k++)
							   {
								  idTemp=idTemp*10;
							   };
							   idTemp=(int)temp*idTemp;
							   id=id+idTemp;
							   ////////////
							   idTemp=1;
							   j--;


							   temp=szRecv[i]&0x0F;
							   for(int k=1;k<=j;k++)
							   {
								 idTemp=idTemp*10;
							   };
							   idTemp=(int)temp*idTemp;
							   id=id+idTemp;
							   j--;
						}
					
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币回收箱写命令0x09
int CCoin::Coin_Box_WriteID(BYTE Data[13])
{
    const int nLen = 16;
	int  ret = COIN_DLL_RES_SENDFAIL	;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_BOX_WRITEID;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = Data[0];
	szBuf[4] = Data[1];
	szBuf[5] = Data[2];
	szBuf[6] = Data[3];
	szBuf[7] = Data[4];
	szBuf[8] = Data[5];
	szBuf[9] = Data[6];
	szBuf[10] = Data[7];
	szBuf[11] = Data[8];
	szBuf[12] = Data[9];
	szBuf[13] = Data[10];
	szBuf[14] = Data[11];
	szBuf[15] = Data[12];	
	//pthread_mutex_lock(&mySerialPort.coinMutex);

	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_BOX_WRITEID && szRecv[3]==iSeq && szRecv[1]==0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//硬币回收箱读命令0x0A
int CCoin::Coin_Box_ReadID(BYTE Data[7],unsigned long & id,int & count)
{
    const int nLen = 3;
	int  ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	unsigned long idTemp=1;
	BYTE temp=0x00;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_BOX_READID;
	szBuf[2] = (BYTE)iSeq;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{  if ( SendCommand( szBuf, nLen) )
		  {
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_BOX_READID && szRecv[3]==iSeq && szRecv[1]==0x10)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{   
						/*for(int i=0,j=5;j<18;j++)
						{
						  Data[i]=szRecv[j];
						}*/
						for(int i=0,j=11;j<18&&i<7;j++,i++)
						{
						  Data[i]=szRecv[j];
						};
						//获取钱箱ID
						for(int i=5,j=7;i<9;i++)
						{
						      temp=(szRecv[i]&0xF0)>>4;
							  for(int k=1;k<=j;k++)
							   {
								  idTemp=idTemp*10;
							   };
							   idTemp=(int)temp*idTemp;
							   id=id+idTemp;
							   ////////////
							   idTemp=1;
							   j--;


							   temp=szRecv[i]&0x0F;
							   for(int k=1;k<=j;k++)
							   {
								 idTemp=idTemp*10;
							   };
							   idTemp=(int)temp*idTemp;
							   id=id+idTemp;
							   j--;
						};
						//硬币数量
						count=(int)szRecv[9]*256+(int)szRecv[10];
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
	iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

/*硬币模块提升机构命令0X0B*/
int CCoin::Coin_Belt_Roll(BYTE Data[6])
{
    const int nLen = 9;
	int  ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	unsigned long idTemp=1;
	BYTE temp=0x00;
	//读取文件内容未写
	BYTE szRecv[COIN_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_BELT_ROLL;
	szBuf[2] = (BYTE)iSeq;
	for(int i=0,j=3;i<6;i++,j++)
	{
		szBuf[j] = Data[i];
		//cout<<"写日志："<<hex<<int(szBuf[i])<<endl;
	}
	/*cout<<"----------------start-------------------------------"<<endl;
	for(int m=0;m<nLen;m++)
		cout<<"提升机构数据："<<int(szBuf[m])<<endl;
	cout<<"----------------end---------------------------------"<<endl;*/
	
	//cWriteLog.Trace(_T("sending Data: "),szBuf,nLen);
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{  if ( SendCommand( szBuf, nLen) )
		  {
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== COIN_CMD_RES_BELT_ROLL && szRecv[3]==iSeq && szRecv[1] == 0x03)	//命令，序列号和长度判断
				{
					if (szRecv[4]==COIN_MODULE_STATE_OK)
					{   
						ret = COIN_DLL_RES_OK;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_FAIL) 
					{
						ret = COIN_DLL_RES_FAIL	;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_BUSY) 
					{
						ret = COIN_DLL_RES_BUSY	;
						cout<<"--------设备忙。。。---------"<<endl;
						break;
					}
					else if (szRecv[4]==COIN_MODULE_STATE_NAK) 
					{
						ret = COIN_DLL_RES_OTHERWRONG	;
						cout<<"--------解包出错请求重发---------"<<endl;
						break;
					}
				}
				else
				{
					//SendCommand( szBuf, nLen);
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = COIN_DLL_RES_CMDSEQ;
				}
			}
			else
			{
				ret = COIN_DLL_RES_TIMEOUT;
			}
		}
	iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//cout<<"Hello World!"<<endl;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}


//循环找零箱、专用找零箱找零结束命令0x01
int  CCoin::Coin_End_Change( BYTE Data)
{
	const int nLen = 4;
	int  ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_END_CHANGE;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=Data;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			ret = COIN_DLL_RES_OK;
			break;
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;  
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}

//循环找零箱、专用找零箱清币结束命令0x03
int  CCoin::Coin_End_Clean( BYTE Data)
{
    const int nLen = 4;
	int  ret = COIN_DLL_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	if(m_isPort==false)
	{
		return COIN_DLL_RES_PORTOPEN;
	}
	iSeq=m_Coin_iSeq%256;
	if(iSeq==0) 
	{     m_Coin_iSeq++;
	      iSeq=m_Coin_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = COIN_CMD_REQ_END_CLEAN;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=Data;
	//pthread_mutex_lock(&mySerialPort.coinMutex);
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			ret = COIN_DLL_RES_OK;
			break;
		}
		iSend++;
	}while(iSend<=m_Coin_iRetry);
	m_Coin_iSeq++;
	//pthread_mutex_unlock(&mySerialPort.coinMutex);
	return ret;
}
