
#include"TicketCommand.h"

CTicket::CTicket()
{

}

CTicket::~CTicket()
{

}

BYTE CTicket::procchar(BYTE current,BYTE pre)
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
bool CTicket::CommOpen()
{   
	if (m_aCom.Conn(gp_conf->Get_ticket_com_port()))
	{
		LOGSTREAM( gp_log[LOGEMTICKET], LOGPOSI << "com open ok:" << gp_conf->Get_ticket_com_port() );
		 return true;  
	}
	else
	{
		LOGSTREAM( gp_log[LOGEMTICKET], LOGPOSI << "com open fail:" << gp_conf->Get_ticket_com_port() );
		return false;
	}
}

//关闭端口
bool CTicket::CommClose()
{
	m_aCom.DisConn();
	return true;
}

//发送报文
bool CTicket::SendFrame(const BUF_T & buf_in)
{
	if( buf_in.empty() ) 
		return true;
	else
	{
		SCake ck;
		ck.let( (char*)&buf_in[0], (int)buf_in.size() );
		LOGSTREAM( gp_log[LOGEMTICKET], LOGPOSI << ck.Seri() );
		return m_aCom.send_bin( ck ) ? true : false;
	}
}

//接受报文
 bool CTicket::RecvFrame(BUF_T & buf_out)
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
	 
	while( !gp_qf->IsLongQf( now, 500 / 1000.00 ) )
   //while(timeout<500)
    {
		SCake ck;
    	///////读取报文
		m_aCom.recv_bin( ck );

		readByte= (int)ck.len();

		if( ck.len() )
			gp_qf->GetQf( now );

		if( ck.len() )
			memcpy( recv, ck.buf(), ck.len() );
    //readByte=read(fd,recv,1024);
     //从报文中提取出返回报文
     if(readByte>0)
     	{
     		/*for(int i=0;i<readByte;i++)
     		{
     		   printf("Recv:%2x\n",recv[i]);}*/
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



 ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

//发送时在报文中插入TICKET_DLE字符
unsigned int CTicket::InsertTICKET_DLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[TICKET_RECV_BUFFER_LEN_];
	int TICKET_DLE_cnt = 0;

	for (int i=0; i<nLen; i++)
	{
		if ( (pBuf[i]==TICKET_STX)||(pBuf[i]==TICKET_ETX)||(pBuf[i]==TICKET_DLE) )
		{
			//插入的TICKET_DLE字符必须在字符前面插入
			sdata[i+TICKET_DLE_cnt] = TICKET_DLE;			
			TICKET_DLE_cnt++;
			sdata[i+TICKET_DLE_cnt] = pBuf[i];		
		}
		else
		{
			sdata[i+TICKET_DLE_cnt] = pBuf[i];
		}
		
	}	

	memcpy(ptarget, sdata, nLen+TICKET_DLE_cnt);
	return (nLen+TICKET_DLE_cnt);
}

//接受到正常报文时在报文中去除TICKET_DLE字符
unsigned int CTicket::DeleteTICKET_DLE(BYTE * pBuf,int nLen, BYTE * ptarget)
{	
	unsigned char sdata[TICKET_RECV_BUFFER_LEN_];
	int TICKET_DLE_cnt = 0;
	int j=1;
	sdata[0]=pBuf[0];
	int isTICKET_DLE=0; //作为判定一个字符是不是需要转义，初始时0表示不需要转义
	for (int i=1; i<nLen-1; i++)
	{
		if ( pBuf[i]==TICKET_DLE && isTICKET_DLE==0 )
		{
			isTICKET_DLE=1;
				
		}
		else
		{   
			isTICKET_DLE=0;
			sdata[j] = pBuf[i];
			j++;
		}
		
	}	
	sdata[j]=pBuf[nLen-1];
	j++;
	memcpy(ptarget, sdata, j);
	/*for(int i=0;i<j;i++)
     		{
     		   printf("Del:%2x\n",ptarget[i]);}
     		   */
	return (j);
}

//发送报文
bool CTicket::SendCommand(BYTE * Data,int nLen)
{
	unsigned char OriData[TICKET_RECV_BUFFER_LEN_];
	memcpy(OriData,Data, nLen);
	OriData[nLen] = 0; 
	for (int i=0;i<nLen;i++)
	{
		OriData[nLen] ^= OriData[i];
	}

	unsigned char localdata[TICKET_RECV_BUFFER_LEN_];
	localdata[0] = TICKET_STX;
	unsigned int nNewLen = InsertTICKET_DLE(OriData, nLen+1, localdata+1) + 2;
	localdata[nNewLen-1] = TICKET_ETX;

	BUF_T buff_in;
	for(unsigned int i=0;i<nNewLen;i++)
		buff_in.push_back(localdata[i]);
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
bool CTicket::RecvCommand(BYTE * Data,int & nLen)
{   BUF_T buf_out;
    BYTE  pBuf[TICKET_RECV_BUFFER_LEN_];
	BYTE  BCC=0x00;
	memset(pBuf,0,TICKET_RECV_BUFFER_LEN_);
	//实现指定了返回报文

	//正常的获取报文
	if(RecvFrame(buf_out))
	{    

	     for(unsigned int i=0;i<buf_out.size();i++)
		     pBuf[i]=buf_out[i];
	        nLen=(int)buf_out.size();
	     for(int i=0;i<nLen;i++)
     		{
     		   printf("Temp:%2x\n",pBuf[i]);}
		 //添加写日志
		/* for(int i=0;i<buf_out.size();i++)
		cout<<"读日志："<<hex<<int(buf_out[i])<<endl;*/
		 //cLog.Trace(_T("Recv: "),pBuf,nLen);
		 ////////////
	     nLen=DeleteTICKET_DLE(pBuf,nLen,Data);
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
	
};

//////////////////////////////////////////////////////////////////////
//对外接口函数
/////////////////////////////////////////////////////////////////////

//打开端口
bool CTicket::Ticket_CommOpen()
{ 
    //	cLog.Init(_T("Log"));
	TICKET_iRetry=3;
	if(CommOpen())
	{
		//pthread_mutex_init(&shared,NULL);
		//cLog.Trace(_T("Open success!"));
		//TICKET_iRetry=0;
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
bool CTicket::Ticket_CommClose()
{
	if(CommClose())
	{
		//cLog.Trace(_T("Close success!"));
		//pthread_mutex_destroy(&shared);
		m_isPort=false;
		return true;
	}
	else
	{
	    //cLog.Trace(_T("Close failed！"));
		return false;
	}
}

//发卡模块轮训
int  CTicket::Ticket_Poll(BYTE SensorStatus[6])
{
	int ret = TICKET_RES_SENDFAIL;
	const int nLen = 3;
	unsigned int iSeq;
	unsigned int iSend=1;
	BYTE  temp;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_FAKALUNXUNN;
	szBuf[2] = (BYTE)iSeq;
	do
	{
		if ( SendCommand(szBuf,nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv,nRecvLen))
			{   
				wl::SCake ck;
				ck.let( (char*)szRecv,nRecvLen );
				LOGSTREAM( gp_log[LOGAPP], LOGPOSI << ck.Seri_S());
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_FAKALUNXUN && szRecv[3]==iSeq && szRecv[1]==0x09)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{    
						//SensorStatus[0]   卡箱前到位光感
						SensorStatus[0]=szRecv[5];
						SensorStatus[1]=szRecv[6];
						//temp=0x00;
						//temp=(szRecv[5]&0xA0);
						//SensorStatus[0]=0x00;
						//SensorStatus[0]=(temp>>5);
						//SensorStatus[0]|=(temp>>6);
						////SensorStatus[1]  卡箱后到位光感
						//temp=0x00;
						//temp=(szRecv[5]&0x48);
						//SensorStatus[1]=0x00;
						//SensorStatus[1]=(temp>>3);
						//SensorStatus[1]|=(temp>>5);
						////SensorStatus[2]  其他光感
						//temp=0x00;
						//temp=(szRecv[6]&0x80);
						//SensorStatus[2]=0x00;
						//SensorStatus[2]=(temp>>3);
						//temp=0x00;
						//temp=(szRecv[5]&0x07);
						//SensorStatus[2]|=temp;
						//temp=0x00;
						//temp=(szRecv[5]&0x10);
						//SensorStatus[2]|=(temp>>1);
						//SensorStatus[3]--SensorStatus[5]
						memcpy(SensorStatus+2,szRecv+7,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}

		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared);  
	return ret;
}

//电机测试
int CTicket::Ticket_PowerTest(BYTE Index)
{
    const int nLen = 4;
	int ret = TICKET_RES_SENDFAIL;
	unsigned int iSeq;
    unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_POWERTEST;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=Index;
	////SendCommand(szBuf,nLen);

	//BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	//memset(szRecv, 0, sizeof(szRecv));
	//int nRecvLen = 0;
	//RecvCommand(szRecv,nRecvLen);
	do
	{
		if ( SendCommand(szBuf,nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv,nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_POWERTEST && szRecv[3]==iSeq &&szRecv[5]==Index && szRecv[1]==0x09)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//复位
int  CTicket::Ticket_Reset( )
{
	int ret = TICKET_RES_SENDFAIL;
	const int nLen = 3;
	unsigned int iSeq;
    unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_FUWEI;
	szBuf[2] = (BYTE)iSeq;
	do
	{
		if ( SendCommand(szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				/*for(int i=0;i<nRecvLen;i++)
     		{
     		   printf("Msg:%2x\n",szRecv[i]);}*/
				if (szRecv[2]== TICKET_CMD_RES_FUWEI && szRecv[3]==iSeq &&szRecv[1]==0x09)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
	  iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//查询发卡程序模块版本
int  CTicket::Ticket_GetVersion( BYTE & Major,BYTE & Minor)
{
    int ret = TICKET_RES_SENDFAIL;
	const int nLen = 3;
	unsigned int iSeq;
    unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);	
    szBuf[0] = nLen-1;
	szBuf[1] =TICKET_CMD_REQ_BANBEN;
	szBuf[2] = (BYTE)iSeq;
	do
	{
		if ( SendCommand(szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_BANBEN && szRecv[3]==iSeq && szRecv[1]==0x09)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						Major=szRecv[5];
						Minor=szRecv[6];
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
	   iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//发卡
int  CTicket::Ticket_SendCard( BYTE Box,BYTE & Wrong,BYTE Data[6])
{
	const int nLen = 4;
	int ret = TICKET_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	BYTE temp;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};


	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_FAKA;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=Box;
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_FAKA && szRecv[3]==iSeq && szRecv[5]==Box && szRecv[1]==0x0B)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						Wrong=szRecv[6];
						//memcpy(Data,szRecv+7,6);
						Data[0] = szRecv[7];
						Data[1] = szRecv[8];
						//temp=0x00;
						//temp=(szRecv[7]&0xA0);
						//Data[0]=0x00;
						//Data[0]=(temp>>5);
						//Data[0]|=(temp>>6);
						////SensorStatus[1]  卡箱后到位光感
						//temp=0x00;
						//temp=(szRecv[7]&0x48);
						//Data[1]=0x00;
						//Data[1]=(temp>>3);
						//Data[1]|=(temp>>5);
						////SensorStatus[2]  其他光感
						//temp=0x00;
						//temp=(szRecv[8]&0x80);
						//Data[2]=0x00;
						//Data[2]=(temp>>3);
						//temp=0x00;
						//temp=(szRecv[7]&0x07);
						//Data[2]|=temp;
						//temp=0x00;
						//temp=(szRecv[7]&0x10);
						//Data[2]|=(temp>>1);
						//SensorStatus[3]--SensorStatus[5]
						memcpy(Data+2,szRecv+9,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//读写结果
int  CTicket::Ticket_WriteRead( BYTE Box,BYTE IsFail,BYTE & WrongCode,BYTE Data[6])
{
	const int nLen = 5;
	int ret = TICKET_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	BYTE temp;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_WRITEREAD;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=Box;
	szBuf[4]=IsFail;
	do
	{
		if ( SendCommand(szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_WRITEREAD  && szRecv[3]==iSeq && szRecv[5]==Box && szRecv[6]==IsFail && szRecv[1]==0x0C)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						WrongCode=szRecv[7];
						//memcpy(Data,szRecv+8,6);
						Data[0] = szRecv[8];
						Data[1] = szRecv[9];

						//temp=0x00;
						//temp=(szRecv[8]&0xA0);
						//Data[0]=0x00;
						//Data[0]=(temp>>5);
						//Data[0]|=(temp>>6);
						////SensorStatus[1]  卡箱后到位光感
						//temp=0x00;
						//temp=(szRecv[8]&0x48);
						//Data[1]=0x00;
						//Data[1]=(temp>>3);
						//Data[1]|=(temp>>5);
						////SensorStatus[2]  其他光感
						//temp=0x00;
						//temp=(szRecv[9]&0x80);
						//Data[2]=0x00;
						//Data[2]=(temp>>3);
						//temp=0x00;
						//temp=(szRecv[8]&0x07);
						//Data[2]|=temp;
						//temp=0x00;
						//temp=(szRecv[8]&0x10);
						//Data[2]|=(temp>>1);
						////SensorStatus[3]--SensorStatus[5]
						memcpy(Data+2,szRecv+10,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//卡箱换箱
int  CTicket::Ticket_ExchangeBox( BYTE & Wrong,BYTE Data[6])
{
	int ret = TICKET_RES_SENDFAIL;
	const int nLen = 4;
	unsigned int iSeq;
	unsigned int iSend=1;
	BYTE temp;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};

	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_KAXIANGHUANXIANG;
	szBuf[2] = (BYTE)iSeq;
	//保留字段
	szBuf[3]=0x22;
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_KAXIANGHUANXIANG && szRecv[3]==iSeq && szRecv[5]==0x22 && szRecv[1]==0x0B)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						Wrong=szRecv[6];
						//memcpy(Data,szRecv+7,6);	
						Data[0] = szRecv[7];
						Data[1] = szRecv[8];

						//temp=0x00;
						//temp=(szRecv[7]&0xA0);
						//Data[0]=0x00;
						//Data[0]=(temp>>5);
						//Data[0]|=(temp>>6);
						////SensorStatus[1]  卡箱后到位光感
						//temp=0x00;
						//temp=(szRecv[7]&0x48);
						//Data[1]=0x00;
						//Data[1]=(temp>>3);
						//Data[1]|=(temp>>5);
						////SensorStatus[2]  其他光感
						//temp=0x00;
						//temp=(szRecv[8]&0x80);
						//Data[2]=0x00;
						//Data[2]=(temp>>3);
						//temp=0x00;
						//temp=(szRecv[7]&0x07);
						//Data[2]|=temp;
						//temp=0x00;
						//temp=(szRecv[7]&0x10);
						//Data[2]|=(temp>>1);
						//SensorStatus[3]--SensorStatus[5]
						memcpy(Data+2,szRecv+9,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
	   iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//取模块票箱和ID
int  CTicket::Ticket_ReadId( BYTE Data[4])
{
	int ret = TICKET_RES_SENDFAIL;
	const int nLen = 4;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};
	BYTE szBuf[nLen];
	memset(szBuf, 0, nLen);
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_READID;
	szBuf[2] = (BYTE)iSeq;
	//保留字段
	szBuf[3]=0x00;
	do
	{
		if ( SendCommand(szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_READID && szRecv[3]==iSeq && szRecv[5]==0x00 && szRecv[1]==0x08)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						memcpy(Data,szRecv+6,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

//写模块票箱和ID
int  CTicket::Ticket_WriteId( BYTE Data[4])
{
	const int nLen = 8;
	int ret = TICKET_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = TICKET_CMD_REQ_WRITEID;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3]=0x00;
	szBuf[4]=Data[0];
	szBuf[5]=Data[1];
	szBuf[6]=Data[2];
	szBuf[7]=Data[3];
	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== TICKET_CMD_RES_WRITEID && szRecv[3]==iSeq && szRecv[5]==0x00 && szRecv[1]==0x04)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}

int CTicket::Ticket_CleanEscrow(BYTE bTicketTowhere,BYTE & Wrong,BYTE Data[6])
{
	const int nLen = 4;
	int ret = TICKET_RES_SENDFAIL;
	unsigned int iSeq;
	unsigned int iSend=1;
	BYTE temp;
	//读取文件内容未写
	BYTE szRecv[TICKET_RECV_BUFFER_LEN_];
	if(m_isPort==false)
	{
		return TICKET_RES_PORTOPEN;
	}
	//pthread_mutex_lock(&shared);
	iSeq=TICKET_iSeq%256;
	if(iSeq==0) 
	{     TICKET_iSeq++;
	      iSeq=TICKET_iSeq%256;
	};
	BYTE szBuf[nLen];
	szBuf[0] = nLen-1;
	szBuf[1] = CMD_REQ_QINGZANCUN;
	szBuf[2] = (BYTE)iSeq;
	szBuf[3] = bTicketTowhere;

	do
	{
		if ( SendCommand( szBuf, nLen) )
		{
			memset(szRecv, 0, sizeof(szRecv));
			int nRecvLen = 0;

			if (RecvCommand(szRecv, nRecvLen))
			{
				//cWriteLog.Trace(_T("Recv Success1: "),szRecv,nRecvLen);
				if (szRecv[2]== CMD_RES_QINGZANCUN && szRecv[3]==iSeq && szRecv[5]==bTicketTowhere && szRecv[1]==0x0B)	//命令,序列号，长度
				{
					if (szRecv[4]==TICKET_MODULE_STATE_OK)
					{
						Wrong=szRecv[6];
						Data[0] = szRecv[7];
						Data[1] = szRecv[8];
						//memcpy(Data,szRecv+7,6);						
						//temp=0x00;
						//temp=(szRecv[7]&0xA0);
						//Data[0]=0x00;
						//Data[0]=(temp>>5);
						//Data[0]|=(temp>>6);
						////SensorStatus[1]  卡箱后到位光感
						//temp=0x00;
						//temp=(szRecv[7]&0x48);
						//Data[1]=0x00;
						//Data[1]=(temp>>3);
						//Data[1]|=(temp>>5);
						////SensorStatus[2]  其他光感
						//temp=0x00;
						//temp=(szRecv[8]&0x80);
						//Data[2]=0x00;
						//Data[2]=(temp>>3);
						//temp=0x00;
						//temp=(szRecv[7]&0x07);
						//Data[2]|=temp;
						//temp=0x00;
						//temp=(szRecv[7]&0x10);
						//Data[2]|=(temp>>1);
						////SensorStatus[3]--SensorStatus[5]
						memcpy(Data+2,szRecv+9,4);
						ret = TICKET_RES_OK;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_FAIL) 
					{
						ret = TICKET_RES_FAIL;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATEBUSY) 
					{
						ret = TICKET_RES_BUSY;
						break;
					}
					else if (szRecv[4]==TICKET_MODULE_STATE_NAK	) 
					{
						ret = TICKET_RES_OTHERWRONG;
						break;
					}
				}
				else
				{
					//cWriteLog.Trace(_T("Error: Cmd or Seq No."));
					ret = TICKET_RES_CMDSEQ;
				}
			}
			else
			{
				ret = TICKET_RES_TIMEOUT;
			}
		}
		iSend++;
	}while(iSend<=TICKET_iRetry);
	TICKET_iSeq++;
	//pthread_mutex_unlock(&shared); 
	return ret;
}
