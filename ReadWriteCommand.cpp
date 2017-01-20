
#include "ReadWriteCommand.h"



//////////////////////////////////////////////////////////////////////////////////
//处理字符,判断是否是开始与结束标志
static BYTE ProcessChar(BYTE Byte,BYTE pre)
{
	BYTE ret = 0xFF;
	//bool isOriData;
	//int tmp;
	//tmp = GetOriData(Byte,isOriData);
	if(Byte== 0x02 && pre!=0x10)
	{
		return START;		
	}
	else if (Byte == 0x03 && pre!=0x10)
	{
						
	   return END;	
	}	

	return ret;
}

//打开端口
bool ReadWrite::CommOpen()
{   
	if (m_aCom.Conn(gp_conf->Get_reader1_com_port()))
	{
		LOGSTREAM( gp_log[LOGREADER1], LOGPOSI << "com open ok:" << gp_conf->Get_reader1_com_port() );
		 return true;   
	}
	else
	{
		LOGSTREAM( gp_log[LOGREADER1], LOGPOSI << "com open fail:" << gp_conf->Get_reader1_com_port() );
		return false;
	}
}


//关闭端口
bool ReadWrite::CommClose()
{
	LOGSTREAM( gp_log[LOGREADER1], LOGPOSI << "com close:" << gp_conf->Get_reader1_com_port() );
	m_aCom.DisConn();
	return true;
}

//发送报文
bool ReadWrite::SendFrame(const BUF_T & buf_in)
{   
	if( buf_in.empty() ) 
		return true;
	else
	{
		SCake ck;

		ck.let( (char*)&buf_in[0], (int)buf_in.size() );
		LOGSTREAM( gp_log[LOGREADER1], LOGPOSI << ck.Seri() );
		return m_aCom.send_bin( ck ) ? true : false;
	}
}



//
////接受报文
//static bool RecvFrame(BUF_T & buf_out)
//{
//
//    char recv[1024];
//	 int len=1;
//	 int readByte;		
//	bu_quickflow_t::qf_counter_t now;
//	 
//	 //BYTE pre=0xFF;
//	 BYTE current=0x00;
//	 BYTE nret=0x00;
//	
//
//	tuint32  dwBytesRead;
//	BYTE pRecv[128];
//	BYTE nRt;
//	BYTE mid;
//	BYTE pre; //记录当前字符的前一字符，初始值是一个非转义字符，
//	BYTE temp[100];
//	unsigned int length;
//	pre=0x91;
//	//g_isTag=0;
//	int count=0;         
//	bool isStart=false; //标记结束是正常的开始之后的标记
//
//
//
//	
//	 gp_qf->GetQf( now );
//	 buf_out.clear();
//
//   while( !gp_qf->IsLongQf( now, 2000 / 1000.00 ) )
//    {
//    	///////读取报文
//		SCake ck;
//
//		mySerialPort.recv_bin( ck );
//		readByte= (int)ck.len();
//
//		if( ck.len() )
//			gp_qf->GetQf( now );
//
//		if( ck.len() )
//			memcpy( recv, ck.buf(), ck.len() );
//
//     //从报文中提取出返回报文
//     if(readByte>0)
//     	{
//     		len=0;
//     		while(len<readByte)
//     		{
//     			current=recv[len];
//     	    nret=ProcessChar(current,pre);
//     	    if(nret==START)
//     	    	{
//     	    		buf_out.clear();
//     	    		isStart=true;
//     	    		pre=current;
//     	    		buf_out.push_back(current);
//     	    		}
//     	     else if(nret==END&& isStart)
//     	     	{
//     	     		buf_out.push_back(current);
//     	     		pre=0xFF;
//     	     		return true;
//     	     	}
//     	     else
//     	     	{
//     	     		buf_out.push_back(current);
//     	     		if(current==0x10&&pre==0x10)
//     	     			{
//     	     				pre=0xFF;
//     	     				}
//     	     				else
//     	     			{
//     	     				pre=current;
//     	     				};
//     	     	}
//     	     	len++;   
//     		}
//     	}
//     
//    }
//    return false;
//}



//接受报文
bool ReadWrite::RecvFrame(BUF_T & buf_out)
{

    char recv[1024];
	 int len=1;
	 int readByte;		
	bu_quickflow_t::qf_counter_t now;
	 
	 //BYTE pre=0xFF;
	 BYTE current=0x00;
	 BYTE nret=0x00;
	

	tuint32  dwBytesRead;
	BYTE pRecv[128];
	BYTE nRt;
	BYTE mid;
	BYTE pre; //记录当前字符的前一字符，初始值是一个非转义字符，
	BYTE temp[100];
	unsigned int length;
	pre=0x91;
	//g_isTag=0;
	int count=0;         
	bool isStart=false; //标记结束是正常的开始之后的标记


	
	 gp_qf->GetQf( now );

	 buf_out.clear();

   while( !gp_qf->IsLongQf( now, 2000 / 1000.00 ) )
    {
		dwBytesRead = 0;

		SCake ck;

		m_aCom.recv_len( ck , 1 );
		readByte= (int)ck.len();

		if( ck.len() )
			gp_qf->GetQf( now );

		if( ck.len() )
		{
			memcpy( recv, ck.buf(), ck.len() );
			memcpy( pRecv, ck.buf(), ck.len() );
		}

     //从报文中提取出返回报文
     if(readByte>0)
     {  
			
			if(buf_out.size()>=90)
			{   
				memset(temp,0,100);
				for(unsigned int i=0;i<buf_out.size();i++)
				{
		        temp[i]=buf_out[i];
				}
	            length=(int)buf_out.size();
		        //Coin_cLog.Trace(_T("Dirty_Data: "),temp,length);
				buf_out.clear();
			}
			mid=pRecv[0];
			nRt = ProcessChar(pRecv[0],pre);
			if (nRt==START)
			{   
				if(buf_out.size()>0)
				{
				memset(temp,0,100);
				for(unsigned int i=0;i<buf_out.size();i++)
				{
		        temp[i]=buf_out[i];
				}
	            length=(int)buf_out.size();
		        //Coin_cLog.Trace(_T("Dirty_Data: "),temp,length);
				}

				buf_out.clear();
				isStart=true;
				buf_out.push_back(mid);
				pre=mid;
			}
			else if(nRt ==END && isStart)
			{
				//收到应答退出
				buf_out.push_back(mid);
				pre=mid;
				return true;
			}
			else
			{
			   buf_out.push_back(mid);
			   if(mid==0x10 &&pre ==0x10)
				{
					pre=0x91;
			    }
			   else
				{
					pre=mid;
			    }
			}
		}	 
     
    }
    return false;
}





/////////////////////////////////////////////////////////////////////////
//发送时在报文中插入COIN_DLE字符
unsigned int ReadWrite::InsertDLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[_RECV_BUFFER_LEN_];
	int dle_cnt = 0;

	for (int i=0; i<nLen; i++)
	{
		if ( (pBuf[i]==STX)||(pBuf[i]==ETX)||(pBuf[i]==DLE) )
		{
			//插入的COIN_DLE字符必须在字符前面插入
			sdata[i+dle_cnt] = DLE;			
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
};

//接受到正常报文时在报文中去除COIN_DLE字符
unsigned int ReadWrite::DeleteDLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[_RECV_BUFFER_LEN_];
	int dle_cnt = 0;
	int j=1;
	sdata[0]=pBuf[0];
	int dle=0; //作为判定一个字符是不是需要转义，初始时0表示不需要转义
	for (int i=1; i<nLen-1; i++)
	{
		if ( pBuf[i]==DLE && dle==0 )
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
	return j;
};

bool ReadWrite::SendCommand(BYTE * Data,int nLen)
{
	unsigned char OriData[_RECV_BUFFER_LEN_];
	memcpy(OriData,Data, nLen);
	OriData[nLen] = 0; 
	BYTE bcc=0;
	for (int i=0;i<nLen;i++)
	{
		bcc =(bcc+OriData[i])%256;
		OriData[nLen]=bcc;
	}

	unsigned char localdata[_RECV_BUFFER_LEN_];
	localdata[0] = STX;
	unsigned int nNewLen = InsertDLE(OriData, nLen+1, localdata+1) + 2;
	localdata[nNewLen-1] = ETX;

	BUF_T buff_in;
	for(unsigned int i=0;i<nNewLen;i++)
		buff_in.push_back(localdata[i]);
	if(	SendFrame(buff_in))
	{    
		/*for(int i=0;i<buff_in.size();i++)
		cout<<"写日志："<<hex<<int(buff_in[i])<<endl;*/
		//添加写日志
		//Coin_cLog.Trace(_T("Send: "),localdata,nNewLen);
		////////////
		return true;
	}
	else
	{
		return false;
	}
};

//接受报文
bool ReadWrite::RecvCommand(BYTE * Data,int & nLen)
{   BUF_T buf_out;
    BYTE  pBuf[_RECV_BUFFER_LEN_];
	BYTE  BCC=0x00;
	memset(pBuf,0,_RECV_BUFFER_LEN_);
	//实现指定了返回报文
	//正常的获取报文
	if(RecvFrame(buf_out))
	{    

	     for(unsigned int i=0;i<buf_out.size();i++)
		     pBuf[i]=buf_out[i];
	        nLen=(int)buf_out.size();
		 //添加写日志
		/* for(int i=0;i<buf_out.size();i++)
		cout<<"读日志："<<hex<<int(buf_out[i])<<endl;*/
		 //Coin_cLog.Trace(_T("Recv: "),pBuf,nLen);
		 ////////////
	     nLen=DeleteDLE(pBuf,nLen,Data);
		 //检查长度
		 if(nLen>4 && Data[1]==nLen-4)
		 {   
			 //检验BCC
			 for(int i=1;i<nLen-2;i++)
			 {
				 BCC=(BCC+Data[i])%256;
			 }
			if(BCC==Data[nLen-2])
			{
				return true;
			}
			else
			{
				return true;
				//return false;
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

//////////////////////////////////////////////////////////////////////////////////
//命令函数
ReadWrite::ReadWrite()
{
	m_iRetry = 3;
	m_isPort = false;
	m_CMD_Seq = 0;
};

bool ReadWrite::OpenComm()
{
	m_CMD_Seq=0;
	m_iRetry=3;	
	//Coin_cLog.Init(_T("Coin_Log"));
	if(CommOpen())
	{
		//Coin_cLog.Trace(_T("Open success!"));
		//InitializeCriticalSection(&Command);
		m_isPort=true;
		return true;
	}
	else
	{
	    //Coin_cLog.Trace(_T("Open failed！"));
		return false;
	}
}

bool ReadWrite::CloseComm()
{
	//DeleteCriticalSection(&Command);
	if(CommClose())
	{
		//Coin_cLog.Trace(_T("Close success!"));
		m_isPort=false;
		return true;
	}
	else
	{
	   //Coin_cLog.Trace(_T("Close failed！"));
		return false;
	}
};

int ReadWrite::Reset(BYTE ResetOut[3],BYTE DoubleCard[4],BYTE SingleCard[4] )
{
	const int nLen = 4;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = RESET;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = 0x00;
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== RESET )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x15)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						//报文处理
						memset(ResetOut,0,3);
						memcpy(ResetOut,szRecv+5,3);

						//DoubleCard=(((int)(szRecv[11])*256+(int)(szRecv[10]))*256+(int)(szRecv[9]))*256+(int)szRecv[8];
						//SingleCard=(((int)(szRecv[15])*256+(int)(szRecv[14]))*256+(int)(szRecv[13]))*256+(int)szRecv[12];
						DoubleCard[0] = szRecv[8];
						DoubleCard[1] = szRecv[9];
						DoubleCard[2] = szRecv[10];
						DoubleCard[3] = szRecv[11];

						SingleCard[0] = szRecv[12];
						SingleCard[1] = szRecv[13];
						SingleCard[2] = szRecv[14];
						SingleCard[3] = szRecv[15];

						/*DoubleCard=(((int)(szRecv[8])*256+(int)(szRecv[9]))*256+(int)(szRecv[10]))*256+(int)szRecv[11];
						SingleCard=(((int)(szRecv[12])*256+(int)(szRecv[13]))*256+(int)(szRecv[14]))*256+(int)szRecv[15];*/
						ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		szBuf[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
};

int ReadWrite::Init(BYTE InitIn[11],BYTE & InitOut)
{
	const int nLen = 15;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = INIT;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = InitIn[0];
	szBuf[4] = InitIn[1];
	szBuf[5] = InitIn[2];
	szBuf[6] = InitIn[3];
	szBuf[7] = InitIn[4];
	szBuf[8] = InitIn[5];
    szBuf[9] = InitIn[6];
    szBuf[10] = InitIn[7];
	szBuf[11] = InitIn[8];
	szBuf[12] = InitIn[9];
	szBuf[13] = 0x00;
	szBuf[14] = InitIn[10];

	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]==INIT )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x04)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						/*memset(ResetOut,0,11);
						memcpy(ResetOut,szRecv+5,11);*/
						InitOut=szRecv[5];
						ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		szBuf[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
};





int ReadWrite::Init2( BYTE *InitIn, int len , tuint8 commd )
{
	const int nLen = len;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/

	do
	{
		if ( SendCommand( InitIn, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]==commd )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x04)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						/*memset(ResetOut,0,11);
						memcpy(ResetOut,szRecv+5,11);*/
						//InitOut=szRecv[5];
						ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		InitIn[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
}





int ReadWrite::ReadCard(BYTE ReadIn,BYTE ReadOut[28])
{
   const int nLen = 4;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = READCARD;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = ReadIn;
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== READCARD )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x05)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						memset(ReadOut,0,28);
						if(szRecv[5]==0x00)
						{
						  //ret=NOCARD;
							ret=ReadReasult(ReadOut);
						}
						else
						{
						 memcpy(ReadOut,szRecv+6,28);
						 ret=OK;
						}
						//ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		szBuf[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
};

int ReadWrite::SaleCard(BYTE SaleIn[14],BYTE SaleOut[8])
{
	const int nLen = 20;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = SALECARD;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = SaleIn[0];
	szBuf[4] = SaleIn[1];
	szBuf[5] = SaleIn[2];
	szBuf[6] = SaleIn[3];
	szBuf[7] = SaleIn[4];
	szBuf[8] = SaleIn[5];
	szBuf[9] = SaleIn[6];
	szBuf[10] = SaleIn[7];
    szBuf[11] = SaleIn[8];
    szBuf[12] = SaleIn[9];
	szBuf[13] = SaleIn[10];
	szBuf[14] = SaleIn[11];
	szBuf[15] = SaleIn[12];
	szBuf[16] = SaleIn[13];
    szBuf[17] = 0x00;
    szBuf[18] = 0x00;
	szBuf[19] = 0x00;
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== SALECARD)// && szRecv[3]==iSeq )//&& szRecv[1]==0x0B)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						memset(SaleOut,0,8);
						memcpy(SaleOut,szRecv+5,8);
						ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		szBuf[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
};

int ReadWrite::Abort(BYTE & AbortOut)
{
	const int nLen = 4;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = ABORT;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = 0x00;

	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== ABORT )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x0B)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						//memset(SaleOut,0,8);
						//memcpy(SaleOut,szRecv+5,8);
						AbortOut=szRecv[5];
						ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		iSeq++;
		szBuf[2] = (BYTE)iSeq;
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
}

int ReadWrite::ReadReasult(BYTE ReadOut[28])
{
   const int nLen = 4;
	int ret =SENDFAIL;
	int temp=0;
	unsigned int iSeq=0;
	  int iSend=1;
	//读取文件内容未写
	BYTE szRecv[_RECV_BUFFER_LEN_];
	if (!m_isPort)
	{
		//Coin_cLog.Trace(_T("Error: COM not open"));
		return PORT;
	};
	//EnterCriticalSection(&Command);
	//iSeq=m_CMD_Seq%256;
	/*if(iSeq==0) 
	{    m_CMD_Seq++;
	      iSeq=m_CMD_Seq%256;
	};*/
	/*BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = READCARD;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = ReadIn;*/
	do
	{
		if ( true)//SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== 0xC0 )//&& szRecv[3]==iSeq )//&& szRecv[1]==0x05)	//命令，序列号和长度判断
				{
					temp=(int)szRecv[4];
					switch(temp)
					{
					case 0:
						memset(ReadOut,0,28);
						if(szRecv[5]==0x00)
						{
						  ret=NOCARD;
						}
						else
						{
						 memcpy(ReadOut,szRecv+6,28);
						 ret=OK;
						}
						//ret=OK;
						break;
					case 1:
						ret=CHECKERROR;
						break;
					case 2:
						ret=BADREQUEST;
						break;
					case 3:
						ret=BADPARAM;
						break;
					case 4:
						ret=STATUSERROR;
						break;
					case 16:
						ret=AUTHENERROR;
						break;
					case 17:
						ret=READERROR;
						break;
					case 18:
						ret=WRITEERROR;
						break;
					case 19:
						ret=CARDREMOVED;
						break;
					case 20:
						ret=INVALIDCARD;
						break;
					case 22:
						ret=NORECORD;
						break;
					case 23:
						ret=PUTBACKCARD1;
						break;
					case 24:
						ret=PUTBACKCARD2;
						break;
					case 25:
						ret=NOPSAM;
						break;
					case 26:
						ret=NOISAM;
						break;
					case 27:
						ret=PSAMERR;
						break;
					case 28:
						ret=ISAMERR;
						break;
					case 29:
						ret=NOESAM;
						break;
					case 30:
						ret=ESAMERR;
						break;
					case 96:
						ret=NOKEY;
						break;
					case 97:
						ret=MACERR;
						break;
					case 98:
						ret=AUTHERR;
						break;
					case 64:
						ret=AUTHFAIL;
						break;
					case 61:
						ret=NOAUTH;
						break;
					case 99:
						ret=PINERROR;
						break;
					case 100:
						ret=MODIFYPIN;
						break;
					case 112:
						ret=READERERROR;
						break;
					case 127:
						ret=UNKNOWN;
						break;
					}
					break;
				}
			   else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					//Coin_cLog.Trace(_T("N_Recv: "),szRecv, nRecvLen);
					ret = CMDSEQ;
				}
			}
		else
			{
				//Coin_cLog.Trace(_T("Error:TimeOut!"));
				ret = TIMEOUT;
			}
		}
		iSend++;
		/*iSeq++;
		szBuf[2] = (BYTE)iSeq;*/
	}while(iSend<=m_iRetry);
	m_CMD_Seq++;
	//LeaveCriticalSection(&Command);
	if(ret==SENDFAIL)
	{
		//Coin_cLog.Trace(_T("Error:Send Failed!"));
	};
	return ret;
}
