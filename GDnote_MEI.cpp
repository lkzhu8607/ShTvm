//#include "stdafx.h"
//#include "GDnote.h"
#include "2.h"
//#include <unistd.h> 
//#include <sys/types.h> 
//#include <sys/stat.h> 
//#include <sys/time.h>
//#include <time.h>
//#include <fcntl.h> 
//#include <termios.h> 
//#include <errno.h> 
//#include <pthread.h>
#include "GDnote_MEI.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


namespace BillMEI {


//协议中的字符
static const BYTE STX=0X02;
static const BYTE ETB=0X17;
static const BYTE ETX=0X03;
static const BYTE DLE=0X10;
static const BYTE NAK=0X15;
static const BYTE ENQ=0X05;
static const BYTE EOT=0X04;


//命令执行成功
static const int RET_SUCCESS=0; 
static const int RET_PORT=1;                //端口打开失败
static const int RET_TIMEOUT=2;
static const int RET_CONNECTION=3; 
static const int RET_INITIAL=4; 
static const int RET_RESET=5; 
static const int RET_PARAMETER=6;

//命令的动作不可行
static const int RET_ACTION=-1;
//未知的命令
static const int RET_UNKNOW=-2;
////////////////////OOS  
//命令的动作不可行
static const int RET_OOSMISSING=-4;
//未知的命令
static const int RET_OOSFULL=-3;

//static int speed_arr[]={B57600,B38400,B19200,B9600,B4800,B2400,B1200,B300};
//static int name_arr[]={57600,38400,19200,9600,4800,2400,1200,300};

GDCashModle::GDCashModle():isPort(false),cNoteValue(0)
{

};



class SerialPortClass : public d_com_agent2_t 
{
public:
};

static SerialPortClass mySerialPort;



// 
bool GDCashModle::ComOpen()
{   
	if (mySerialPort.Conn(gp_conf->Get_bill_com_port()))
	{
		LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "com open ok:" << gp_conf->Get_bill_com_port() );
		 return true;   
	}
	else
	{
		LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "com open fail:" << gp_conf->Get_bill_com_port() );
		return false;
	}
}



bool GDCashModle::ComClose()
{
	LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "com close:" << gp_conf->Get_bill_com_port() );
	mySerialPort.DisConn();
	return true;
}


bool GDCashModle::SendFrame(const BUF_T & buf_in)
{
	if( buf_in.empty() ) 
		return true;
	else
	{
		SCake ck;

		ck.let( (char*)&buf_in[0], (int)buf_in.size() );
		LOGSTREAM( gp_log[LOGBILL], LOGPOSI << ck.Seri() );
		return mySerialPort.send_bin( ck ) ? true : false;
	}
}



bool GDCashModle::RecvFrame(BUF_T & buf_out,int typeENQ,int typeDEL,int typeNAK,int typeEOT,int typeMsg)
{
	 BYTE mid;
	 BYTE temp[1000];
	 int iDel=1;
	 int iEtx=1;
	 int count=0;       
     char recv[1024];
	 int len=1;
	 int readByte;		
	 //struct timeval t_start,t_end;
	 double timeout=0;	
	bu_quickflow_t::qf_counter_t now;

	 //gettimeofday(&t_start,NULL);
	
	gp_qf->GetQf( now );
	 buf_out.clear();

   //while(timeout<15000)
	while( !gp_qf->IsLongQf( now, 15 ) )
    {
		SCake ck;
		
		mySerialPort.recv_bin( ck );

    	///////读取报文
		memset(recv,0,1024);
      //readByte=read(fd,recv,1000);
		readByte= (int)ck.len();

		//if( ck.len() )
		//	gp_qf->GetQf( now );

		if( ck.len() )
			memcpy( recv, ck.buf(), ck.len() );

     //从报文中提取出返回报文
     if(readByte>0)
     	{
     		len=0;
     		while(len<readByte)
     		{
     			mid=recv[len];
     	    if( typeDEL==1)
			{   
				if(mid==0x10 && iDel==1)
				{
				buf_out.push_back(mid);
				iDel=2;
				}
				else if(iDel==2)
				{
				buf_out.push_back(mid);
				count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    //temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
		        return true;
				}
			}
			else if(mid==0x05 && typeENQ==1)
			{
				buf_out.push_back(mid);
				count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    //temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
		        return true;
			} 
			else if(mid==0x05 && typeENQ==1)
			{
				buf_out.push_back(mid);
				count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    //temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
		        return true;
			} 
			else if(mid==0x04 && typeEOT==1)
			{
			  buf_out.push_back(mid);
			  count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
		      return true;
			}
			else if(mid==0x15 && typeNAK==1)
			{
               buf_out.push_back(mid);
			   count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    //temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
		       return true;
			}
			else if(typeMsg==1)
			{
				if(mid==STX)
				{  
				  buf_out.clear();
			      buf_out.push_back(mid);
				}
				else if((mid==ETX || mid==ETB) && iEtx==1)
				{
				  buf_out.push_back(mid);
				  iEtx=2;

				}
				else if(iEtx==2)
				{
				  buf_out.push_back(mid);
				  iEtx=1;
				 count=(int)buf_out.size();
				memset(temp,0,100);
				for( int i=0;i<count;i++)
				{
				    //temp[i]=buf_out[i];
				};
				//cLog.Trace(_T("Recv:"),temp,count);
				  return true;
				}
				else
				{
				   buf_out.push_back(mid);
				};
		  	};
     	     	len++;   
     		};
     	};
    //gettimeofday(&t_end,NULL);
    //timeout=(((long)t_end.tv_sec)*1000+(long)t_end.tv_usec/1000)-(((long)t_start.tv_sec)*1000+(long)t_start.tv_usec/1000);
    };
    return false;
}

//////////////////////////////////////////////////////////////////////////////////

//打开端口函数重载

int GDCashModle::OpenCom()
{
	//cLog.Init(_T("Banknote_log"));
	//m_hndThread=CreateThread(NULL,0,GDCashModle::threadrun ,this,0,NULL);
	if(ComOpen())
	{ 
		//cLog.Trace(_T("Open success!"));
		isPort=true;
	   return 0;
	}
	else
	{  
		//cLog.Trace(_T("Open fail!"));
	   return -1;
	};

}
//
//int GDCashModle::OpenCom(char * Port)
//{
//	//cLog.Init(_T("Banknote_log"));
//	//m_hndThread=CreateThread(NULL,0,GDCashModle::threadrun ,this,0,NULL);
//	if(ComOpen(Port,4800))
//	{ 
//		//cLog.Trace(_T("Open success!"));
//		isPort=true;
//	   return 0;
//	}
//	else
//	{  
//		//cLog.Trace(_T("Open fail!"));
//	   return -1;
//	};
//
//};


int GDCashModle::CloseCom()
{
	
	if(ComClose())
	{ 
		//cLog.Trace(_T("Close success!"));
		isPort=false;
	   return 0;
	}
	else
	{  
		//cLog.Trace(_T("Close fail!"));
	   return -1;
	};
}

int GDCashModle::cmState( )
{
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int length=0;      //返回报文的长度
	BUF_T send;
	BUF_T recv;
	BUF_T recvtemp;
	//BYTE recv[255];
    int sendRet,recvRet;
	int i=0;
	//BYTE temp;
	bool tiaochu=true;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	cNoteValue=0;
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	/*clock_t cinTime = clock_t(30 *1* CLOCKS_PER_SEC);
	clock_t startTime = clock();
	while(clock() - startTime < cinTime)*/

	bu_quickflow_t::qf_counter_t now;

	gp_qf->GetQf( now );
	while( !gp_qf->IsLongQf( now, 30 ) )
	//while(1)
	{           // recvtemp.clear();
	            // recv.clear();
		        recvRet=RecvConnection(recv); 
				/* for(i=0;i<recvtemp.size();i++)
				 {
					 temp=recvtemp[i];
				     recv.push_back(temp);
				 };*/
		          // recvRet=RecvConnection(recv,i);
				 if(recvRet!=0 )
				 {   
					 //为了超时 作特别处理
				      ret=RET_CONNECTION;
					  length=0;
					  //return ret;
				 };
				 //保温处理  //P   //#   //?    //!x   //[Hx>     //Vxxyy   //.>  //Rxx
				 //N
				 length=(int)recv.size();
				   //length=i;
				 if(length==1 && recv[0]==0x4E)
				 {
				      ret=RET_SUCCESS;
					  return ret;
				 };
				 //P
				 if(length==1 && recv[0]==0x50)
				 {
				      
				 };
				  //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				      
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //.> 超时的响应   或者正常结束
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     ret=RET_SUCCESS;
					 return ret;
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
				  //V 纸币的有效值   VRBxyz
				   if(length ==6 && recv[0]==0x56 && recv[1]==0x52 && recv[2]==0x4D)
				  {
				          /* Case "VRMAA1", "VRMAA2", "VRMAA3", "VRMAA4"
                               VNote = 1
                           Case "VRMAB1", "VRMAB2", "VRMAB3", "VRMAB4"
                               VNote = 1
                           Case "VRMBA1", "VRMBA2", "VRMBA3", "VRMBA4"
                               VNote = 2
                           Case "VRMCA1", "VRMCA2", "VRMCA3", "VRMCA4"
                               VNote = 5
                           Case "VRMCB1", "VRMCB2", "VRMCB3", "VRMCB4"
                               VNote = 5
                           Case "VRMDA1", "VRMDA2", "VRMDA3", "VRMDA4"
                               VNote = 10
                           Case "VRMDB1", "VRMDB2", "VRMDB3", "VRMDB4"
                               VNote = 10
                           Case "VRMEA1", "VRMEA2", "VRMEA3", "VRMEA4"
                               VNote = 20
                           Case "VRMGA1", "VRMGA2", "VRMGA3", "VRMGA4"
                               VNote = 50
                           Case "VRMGB1", "VRMGB2", "VRMGB3", "VRMGB4"
                               VNote = 50
                           Case "VRMGC1", "VRMGC2", "VRMGC3", "VRMGC4"
                               VNote = 50
                           Case "VRMHA1", "VRMHA2", "VRMHA3", "VRMHA4"
                               VNote = 100
                           Case "VRMHB1", "VRMHB2", "VRMHB3", "VRMHB4"
                               VNote = 100
                           Case "VRMHC1", "VRMHC2", "VRMHC3", "VRMHC4"
                               VNote = 100*/
					      switch(recv[3])
						  {
						  case 0x41: cNoteValue=1;break;
						  case 0x42: cNoteValue=2;break;
						  case 0x43: cNoteValue=5;break;
						  case 0x44: cNoteValue=10;break;
						  case 0x45: cNoteValue=20;break;
						  case 0x47: cNoteValue=50;break;
						  case 0x48: cNoteValue=100;break;
						  default:cNoteValue=0;break;
						  };
				 };
    }	
	//规定时间内没有接收到纸币 则超时；
	sendRet=cmStopWork();
	if(sendRet==0) 
	{
		return RET_TIMEOUT;
	}
	else
	{
	    return sendRet;
	};

}

int GDCashModle::cmWork()
{
	BYTE work_command[8]={0x02,0x31,0x77,0x6F,0x72,0x3E,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int length=0;      //返回报文的长度
	BUF_T send;
	BUF_T recv;
    int sendRet,recvRet;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(work_command,8);
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //N  // !1  // !2  
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				      ret=RET_SUCCESS;
					  return ret;
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //.> 超时的响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    } 	
}

int GDCashModle::cmStopWork( )
{
	BYTE init_command[5]={0x02,0x31,0x3F,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int length=0;      //返回报文的长度
	BUF_T send;
	BUF_T recv;
    int sendRet,recvRet;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(init_command,5);
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理        // >
				 //>
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x3E)
				 {
				      ret=RET_SUCCESS;
					  return ret;
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //.> 超时的响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}

int GDCashModle::cmEncash()
{
	BYTE encash_command[8]={0x02,0x31,0x65,0x6E,0x63,0x3E,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int length=0;      //返回报文的长度
	BUF_T send;
	BUF_T recv;
    int sendRet,recvRet;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(encash_command,8);
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //Exx  // !1  // !2   //#  //[Hx>   //.>
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				      /*ret=RET_SUCCESS;
					  return ret;*/
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //Exx
				 if(3==length && recv[0]==0x45)
				 {
				     
				 };
				 //.> 正常结束
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     ret=RET_SUCCESS;
					 return ret;
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}

int GDCashModle::cmRefund()
{
	BYTE refund_command[8]={0x02,0x31,0x72,0x65,0x66,0x3E,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int length=0;      //返回报文的长度
	BUF_T send;
	BUF_T recv;
    int sendRet,recvRet;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(refund_command,8);
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //Rxx  // !x  //[Hx>  //.> //#
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				      /*ret=RET_SUCCESS;
					  return ret;*/
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 成功响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     ret=RET_SUCCESS;
					 return ret;
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}
///////////////////////////////////暂不处理 

int GDCashModle::cmState(BYTE reasult[10])
{
	BYTE command[12]={0x02,0x31,0x64,0x69,0x73,0x20,0x73,0x74,0x61,0x3E,0x03,0x00};
	BYTE bcc=0x00;
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    int sendRet;
	bool recvRet;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	//发送命令
	sendRet=SendCommand(command,12);
	if(sendRet!=0)
	{
	     //通讯故障
		return RET_CONNECTION;
	    
	};

	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		recv.clear();
		recvRet=RecvFrame(recv,1,0,0,0,0);
		if(recvRet==true && recv.size()==1 && recv[0]==ENQ)
		{
				break;
		}
	}
	send.clear();
	send.push_back(DLE);
	temp=0x30;
	send.push_back(temp);
	sendRet=SendFrame(send);

	index=0;
	while(1)
	{
	    recv.clear();
		recvRet=RecvFrame(recv,0,0,0,0,1);
		if(recvRet==true && recv.size()>4) 
		{
		  
		  length=(int)recv.size();
		  bcc=0x00;
		  for(i=1;i<length-1;i++)
		  {
		      bcc^=recv[i];
		  };
		  //判断报文正确与否
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETX)
		  {
			   for(i=2;i<length-3 && index<=9;i++)
			  {
				  reasult[index]=recv[i];
				  index++;
			  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);
			  //cLog.Trace(_T("ETX："),reasult,index);
	    	//[Hx>
		    	if(reasult[0]==0x5B &&reasult[1]==0x48)
			    {
                switch((int)reasult[2])
				{
				case 1://ret=RET_OOSRESET;
					break;
				case 2:ret=RET_OOSMISSING;break;
				case 3:ret=RET_OOSFULL;break;
				case 4://ret=RET_OOSOTHER;
					break;
				};
			   };
			//!x
		    	if(reasult[0]==0x21)
			    {
                switch((int)reasult[1])
				{
				case 1:ret=RET_UNKNOW;
				case 2:ret=RET_ACTION;
				};
			    };
			  if(recv[length-3]==0x3E)
			  {
				 //tiaochu=true;
				 break;
			  };
		      //break;
		  }
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETB)
		  {
			   for(i=2;i<length-2 && index<=9;i++)
			  {
				 reasult[index]=recv[i];
				 index++;
			  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);	
			  //cLog.Trace(_T("ETB："),reasult,index);
			  continue;
		  }
		  else
		  {
		      send.clear();
			  send.push_back(NAK);
			  sendRet=SendFrame(send);	
			  continue;		  
		  };		
		}
		else
		{
			////////////////
		};
	};
	recvRet=RecvFrame(recv,0,0,0,1,0);
	return ret;
}

int GDCashModle::cmWorkTimeout(int timeout)
{
	BYTE command[14]={0x02,0x31,0x73,0x65,0x74,0x20,0x77,0x6F,0x72,0x20,0xFF,0x3E,0x03,0x00};
	BYTE bcc=0x00;
	BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    bool sendRet,recvRet;
	int retry=0;
	switch(timeout)
	{
	        case 0: bcc=0x30;
	        break;
			case 1: bcc=0x31;
	        break;
			case 2: bcc=0x32;
	        break;
			case 3: bcc=0x33;
	        break;
			case 4: bcc=0x34;
	        break;
	};
	command[10]=bcc;
	bcc=0x00;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	//通讯过程建立
	while(1)
	{
			send.clear();
			send.push_back(ENQ);
			sendRet=SendFrame(send);
			if(sendRet==false) 
			{
				//cLog.Trace(_T("在建立通讯阶段，发送ENQ失败!"));
				//return RET_CONMUNICATION_SEND;
			}
			recv.clear();
			recvRet=RecvFrame(recv,1,1,1,0,0);
			if(recvRet==false) 
			 {
				 send.clear();
				 send.push_back(EOT);
				 sendRet=SendFrame(send);
				 //cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
				 //return RET_CONMUNICATION_TIMEOUT;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x30)
			{
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);
				//cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				//return RET_CONMUNICATION_FAIL;
			}
			else if(recv.size()==1 && recv[0]==ENQ)
			{
				//cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				//return RET_CONMUNICATION_FAIL;
			};
	}
	//发送正文
	while(1)
	{
			send.clear();
			send.push_back(command[0]);
			for(i=1;i<13;i++)
			{
				send.push_back(command[i]);
				bcc^=command[i];
			};
			send.push_back(bcc);
			sendRet=SendFrame(send);
			if(sendRet==false)
			{
				//cLog.Trace(_T("在发送报文阶段，发送报文失败!"));
				//return RET_COMMAND_SEND;
			};
			recv.clear();
			recvRet=RecvFrame(recv,0,1,1,0,0);
			if(recvRet==false)
			{
				 /*cLog.Trace(_T("在发送报文阶段,响应报文超时!"));
				return RET_COMMAND_TIMEOUT;*/
				//超时  进入recovery
				while(1)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						//cLog.Trace(_T("在发送报文建立通讯阶段，发送ENQ失败!"));
						//return RET_RECOVERY_SEND;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 /*send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{
						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						continue;
					};
				
				};
				continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x31 ||recv[1]==0x3C))
			{
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				/*send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);*/
				//cLog.Trace(_T("在发送报文阶段，报文确认重发!"));
				//return RET_CONMUNICATION_FAIL;
				continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
			{
				/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				return RET_CONMUNICATION_FAIL;*/
				// DEL 0x3F   进入recovery
				while(1)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						//cLog.Trace(_T("在发送报文建立通讯阶段，发送ENQ失败!"));
						//return RET_RECOVERY_SEND;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 /*send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{
						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						continue;
					};
				
				};
			};
	};
	//结束命令发送
	send.clear();
	send.push_back(EOT);
	sendRet=SendFrame(send);
	if(sendRet==true)
	{
	     //cLog.Trace(_T("发送命令成功!"));
	};

	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		recv.clear();
		recvRet=RecvFrame(recv,1,0,0,0,0);
		if(recvRet==true && recv.size()==1 && recv[0]==ENQ)
		{
				break;
		}
	}
	send.clear();
	send.push_back(DLE);
	temp=0x30;
	send.push_back(temp);
	sendRet=SendFrame(send);

	index=0;
	while(1)
	{
	    recv.clear();
		recvRet=RecvFrame(recv,0,0,0,0,1);
		if(recvRet==true && recv.size()>4) 
		{
		  
		  length=(int)recv.size();
		  bcc=0x00;
		  for(i=1;i<length-1;i++)
		  {
		      bcc^=recv[i];
		  };
		  //判断报文正确与否
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETX)
		  {
			   /*for(i=2;i<length-3 && index<9;i++)
			  {
				  reasult[index]=recv[i];
				  index++;
			  };*/
			     if(recv[length-3]==0x3E)
				  {
					   for(i=2;i<length-2 && index<9;i++)
					  {
						  reasult[index]=recv[i];
						  index++;
					  };
				  }
				  else
				  {
				      for(i=2;i<length-2 && index<9;i++)
					  {
						  reasult[index]=recv[i];
						  index++;
					  };
				  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);
			  //cLog.Trace(_T("ETX："),reasult,index+1);
			   if(reasult[0]==0x5B &&reasult[1]==0x48)
				  {
                     switch(((int)reasult[2])%16)
					 {
					 case 1://ret=RET_OOSRESET;
						 break;
					 case 2:ret=RET_OOSMISSING;break;
					 case 3:ret=RET_OOSFULL;break;
					 case 4://ret=RET_OOSOTHER;
						 break;
					 };
				  };
				  //!x
				   if(reasult[0]==0x21)
				  {
                     switch((int)reasult[1]%16)
					 {
					 case 1:ret=RET_UNKNOW;
					 case 2:ret=RET_ACTION;
					 };
				  };
		      if(recv[length-3]==0x3E)
			  {
				 //tiaochu=true;
				 break;
			  };
		      //break;
		  }
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETB)
		  {
			   for(i=2;i<length-2 && index<9;i++)
			  {
				 reasult[index]=recv[i];
				 index++;
			  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);	
			  //cLog.Trace(_T("ETB："),reasult,index+1);
			  continue;
		  }
		  else
		  {
		      send.clear();
			  send.push_back(NAK);
			  sendRet=SendFrame(send);	
			  continue;		  
		  };		
		}
		else
		{
			////////////////
		};
	};
	recvRet=RecvFrame(recv,0,0,0,1,0);
	return ret;
}

int GDCashModle::cmWorkMode(int mode)
{
	BYTE command[14]={0x02,0x31,0x73,0x65,0x74,0x20,0x6F,0x75,0x74,0x20,0x00,0x3E,0x03,0x00};
	BYTE bcc=0x00;
	BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    bool sendRet,recvRet;
	int retry=0;
	switch(mode)
	{
	        case 1: bcc=0x31;
	        break;
			case 2: bcc=0x32;
	};
	command[10]=bcc;
	bcc=0x00;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	//通讯过程建立
	while(1)
	{
			send.clear();
			send.push_back(ENQ);
			sendRet=SendFrame(send);
			if(sendRet==false) 
			{
				//cLog.Trace(_T("在建立通讯阶段，发送ENQ失败!"));
				//return RET_CONMUNICATION_SEND;
			}
			recv.clear();
			recvRet=RecvFrame(recv,1,1,1,0,0);
			if(recvRet==false) 
			 {
				 send.clear();
				 send.push_back(EOT);
				 sendRet=SendFrame(send);
				// cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
				 //return RET_CONMUNICATION_TIMEOUT;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x30)
			{
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);
				//cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				//return RET_CONMUNICATION_FAIL;
			}
			else if(recv.size()==1 && recv[0]==ENQ)
			{
				//cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				//return RET_CONMUNICATION_FAIL;
			};
	}
	//发送正文
	while(1)
	{
			send.clear();
			send.push_back(command[0]);
			for(i=1;i<13;i++)
			{
				send.push_back(command[i]);
				bcc^=command[i];
			};
			send.push_back(bcc);
			sendRet=SendFrame(send);
			if(sendRet==false)
			{
				//cLog.Trace(_T("在发送报文阶段，发送报文失败!"));
				//return RET_COMMAND_SEND;
			};
			recv.clear();
			recvRet=RecvFrame(recv,0,1,1,0,0);
			if(recvRet==false)
			{
				 /*cLog.Trace(_T("在发送报文阶段,响应报文超时!"));
				return RET_COMMAND_TIMEOUT;*/
				//超时  进入recovery
				while(1)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						//cLog.Trace(_T("在发送报文建立通讯阶段，发送ENQ失败!"));
						//return RET_RECOVERY_SEND;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 /*send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{
						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						continue;
					};
				
				};
				continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x31 ||recv[1]==0x3C))
			{
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				/*send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);*/
				//cLog.Trace(_T("在发送报文阶段，报文确认重发!"));
				//return RET_CONMUNICATION_FAIL;
				continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
			{
				/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				return RET_CONMUNICATION_FAIL;*/
				// DEL 0x3F   进入recovery
				while(1)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						//cLog.Trace(_T("在发送报文建立通讯阶段，发送ENQ失败!"));
						//return RET_RECOVERY_SEND;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 /*send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{
						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						continue;
					};
				
				};
			};
	};
	//结束命令发送
	send.clear();
	send.push_back(EOT);
	sendRet=SendFrame(send);
	if(sendRet==true)
	{
	     //cLog.Trace(_T("发送命令成功!"));
	};

	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		recv.clear();
		recvRet=RecvFrame(recv,1,0,0,0,0);
		if(recvRet==true && recv.size()==1 && recv[0]==ENQ)
		{
				break;
		}
	}
	send.clear();
	send.push_back(DLE);
	temp=0x30;
	send.push_back(temp);
	sendRet=SendFrame(send);

	index=0;
	while(1)
	{
	    recv.clear();
		recvRet=RecvFrame(recv,0,0,0,0,1);
		if(recvRet==true && recv.size()>4) 
		{
		  
		  length=(int)recv.size();
		  bcc=0x00;
		  for(i=1;i<length-1;i++)
		  {
		      bcc^=recv[i];
		  };
		  //判断报文正确与否
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETX)
		  {
			  /* for(i=2;i<length-3 && index<9;i++)
			  {
				  reasult[index]=recv[i];
				  index++;
			  };*/
			   if(recv[length-3]==0x3E)
				  {
					   for(i=2;i<length-2 && index<9;i++)
					  {
						  reasult[index]=recv[i];
						  index++;
					  };
				  }
				  else
				  {
				      for(i=2;i<length-2 && index<9;i++)
					  {
						  reasult[index]=recv[i];
						  index++;
					  };
				  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);
			  //cLog.Trace(_T("ETX："),reasult,index+1);
			   if(reasult[0]==0x5B &&reasult[1]==0x48)
				  {
                     switch((int)reasult[2]%16)
					 {
					 case 1://ret=RET_OOSRESET;
						 break;
					 case 2:ret=RET_OOSMISSING;break;
					 case 3:ret=RET_OOSFULL;break;
					 case 4://ret=RET_OOSOTHER;
						 break;
					 };
				  };
				  //!x
				   if(reasult[0]==0x21)
				  {
                     switch((int)reasult[1]%16)
					 {
					 case 1:ret=RET_UNKNOW;
					 case 2:ret=RET_ACTION;
					 };
				  };
		      if(recv[length-3]==0x3E)
			  {
				 //tiaochu=true;
				 break;
			  };
		      //break;
		  }
		  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETB)
		  {
			   for(i=2;i<length-2 && index<9;i++)
			  {
				 reasult[index]=recv[i];
				 index++;
			  };
			  send.clear();
			  send.push_back(DLE);
			  temp=recv[1];
			  send.push_back(temp);
			  sendRet=SendFrame(send);	
			  //cLog.Trace(_T("ETB："),reasult,index+1);
			  continue;
		  }
		  else
		  {
		      send.clear();
			  send.push_back(NAK);
			  sendRet=SendFrame(send);	
			  continue;		  
		  };		
		}
		else
		{
			////////////////
		};
	};
	recvRet=RecvFrame(recv,0,0,0,1,0);
	return ret;
}


/////////////////////////////////////////////////////////////
int GDCashModle::cmActive(int value )
{
	BYTE active_command[13]={0x02,0x31,0x61,0x63,0x74,0x20,0x72,0x6D,0xFF,0x2A,0x3E,0x03,0x00};   //具体某种货币
	BYTE active0_command[10]={0x02,0x31,0x61,0x63,0x74,0x20,0x2A,0x3E,0x03,0x00};;  //全部货币
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	BYTE bcc=0x00;
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    int sendRet,recvRet;
	////////////////////////////////////////
	if(value!=0)
	{    
		switch(value)
		{
		case 1:active_command[8]=0x61;break;
		case 2:active_command[8]=0x62;break;
		case 5:active_command[8]=0x63;break;
		case 10:active_command[8]=0x64;break;
		case 20:active_command[8]=0x65;break;
		case 50: active_command[8]=0x67;break;
		case 100:active_command[8]=0x68;break;
		default: return RET_PARAMETER;
		}
	};
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	if(value==0)
	{
	sendRet=SendCommand(active0_command,10);
	}
	else
	{
	sendRet=SendCommand(active_command,13);
	};
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //>  //!x  //[Hx>  //#
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				      /*ret=RET_SUCCESS;
					  return ret;*/
				 };
				  //>
				 if(1==length && recv[0]==0x3E)
				 {
				     ret=RET_SUCCESS;
					  return ret;
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 成功响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     ret=RET_SUCCESS;
					 return ret;
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}

int GDCashModle::cmInhibit(int value)
{
	BYTE inhibit_command[13]={0x02,0x31,0x69,0x6E,0x68,0x20,0x72,0x6D,0xFF,0x2A,0x3E,0x03,0x00};   //具体某种货币
	BYTE inhibit0_command[10]={0x02,0x31,0x69,0x6E,0x68,0x20,0x2A,0x3E,0x03,0x00};  //全部货币
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	BYTE bcc=0x00;
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    int sendRet,recvRet;
	if(value!=0)
	{    
		switch(value)
		{
		case 1:inhibit_command[8]=0x61;break;
		case 2:inhibit_command[8]=0x62;break;
		case 5:inhibit_command[8]=0x63;break;
		case 10:inhibit_command[8]=0x64;break;
		case 20:inhibit_command[8]=0x65;break;
		case 50:inhibit_command[8]=0x67;break;
		case 100:inhibit_command[8]=0x68;break;
		default: return RET_PARAMETER;
		}
	};
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	if(value==0)
	{
	sendRet=SendCommand(inhibit0_command,10);
	}
	else
	{
	sendRet=SendCommand(inhibit_command,13);
	};
	if(sendRet!=0)
	{
	     //通讯故障
		return sendRet;
	    
	};
	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	//接受返回报文通讯过程建立
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //>  //!x  //[Hx>  //#
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				      /*ret=RET_SUCCESS;
					  return ret;*/
				 };
				  //>
				 if(1==length && recv[0]==0x3E)
				 {
				     ret=RET_SUCCESS;
					  return ret;
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 成功响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}

int GDCashModle::cmReset( )
{
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	BYTE bcc=0x00;
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    int sendRet;
	int recvRet;
	bool tiaochu=false;
	////////////////////////////////////////
	if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(reset_command,5);
	if(sendRet!=0)
	{
	     //通讯故障
		return RET_CONNECTION;
	    
	};

	///////////////////////////////////////////////////////////////////////////
	//开始接受返回报文
	while(1)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   // !x  //[Hx>  //#
				 //N   
				 length=(int)recv.size();
				 if(1==length && recv[0]==0x4E)
				 {
				     /* ret=RET_SUCCESS;
					  return ret;*/
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				  //  sendRet=SendCommand(reset_command,5);
				  //   if(sendRet!=0)
						//{
						//	 //通讯故障
						//	return sendRet;
	    
						//};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				     
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 超时的响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					return ret;				    
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
    }	
}

//响应  atuomatic 模式   出现暂停服务后需要执行的  起监听的作用
int GDCashModle::cmInit()
{
	BYTE init_command[5]={0x02,0x31,0x3E,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	BYTE bcc=0x00;
	BUF_T send;
	BUF_T recv;
	int commandlength=5;
	int i=0;
	int index=0;
	int length=0;
	BYTE reasult[9]={0};
	int sendRet,recvRet;
	bool tiaochu=false;
	BYTE temp=0x00;
	int ret=RET_SUCCESS;
	int count=0;
	count=3;
while(count)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理   //? // !x  //[Hx>  //#  //[Bxxyy>  //[C>
				 length=(int)recv.size();
				 //N   
				 if(1==length && recv[0]==0x4E)
				 {
				     /* ret=RET_SUCCESS;
					  return ret;*/
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				        sendRet=SendCommand(init_command,5);
				        if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					    continue;
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 超时的响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					//return ret;	
					count--;
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
			        //return ret;	
					count--;
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
				  // [Bxxyy
				  	if(length==6 && recv[0]==0x5B && recv[1]==0x42 )
				  {
                    			    
				  };
				 //[C>
					if(length==3 && recv[0]==0x5B && recv[1]==0x43 && recv[2]==0x3E)
				  {
                    ret=RET_SUCCESS;
					return ret;			    
				  };
					//[Bxxyy [C>
					if(length==9 && recv[6]==0x5B && recv[7]==0x43 && recv[8]==0x3E)
				  {
                    ret=RET_SUCCESS;
					return ret;			    
				  };
    }	
   return ret;
}

//响应    slaving 模式   出现暂停服务后需要执行的  上位机主动恢复
int GDCashModle::cmInit(int a)
{
	BYTE recaut_command[12]={0x02,0x31,0x72,0x65,0x63,0x20,0x61,0x75,0x74,0x3E,0x03,0x00};
	BYTE reset_command[5]={0x02,0x31,0x23,0x03,0x00};
	BYTE bcc=0x00;
	BUF_T send;
	BUF_T recv;
	int commandlength=5;
	int i=0;
	int index=0;
	int length=0;
	BYTE reasult[9]={0};
	int sendRet,recvRet;
	bool tiaochu=false;
	BYTE temp=0x00;
	int ret=RET_SUCCESS;
	int count=0;
		if(isPort==false)
	{
	     return RET_PORT;
	};
	sendRet=SendCommand(recaut_command,12);
	if(sendRet!=0)
	{
	     //通讯故障
		return RET_CONNECTION;
	    
	};
	count=3;
    while(count)
	{
		         recvRet=RecvConnection(recv); 
				 if(recvRet!=0)
				 {
				      ret=RET_CONNECTION;
					  return ret;
				 };
				 //保温处理  //!x  //[Hx>  //#  //[Bxxyy>  //[C>
				 length=(int)recv.size();
				 //N   
				 if(1==length && recv[0]==0x4E)
				 {
				     /* ret=RET_SUCCESS;
					  return ret;*/
				 };
				 //#
				 if(1==length && recv[0]==0x23)
				 {
				    sendRet=SendCommand(reset_command,5);
				     if(sendRet!=0)
						{
							 //通讯故障
							return sendRet;
	    
						};
					 continue;
				 };
				 //?.......
				 if(1==length && recv[0]==0x3F)
				 {
				  //      sendRet=SendCommand(init_command,5);
				  //      if(sendRet!=0)
						//{
						//	 //通讯故障
						//	return sendRet;
	    
						//};
					    continue;
				 };
				 //Rxx
				 if(3==length && recv[0]==0x52)
				 {
				     
				 };
				 //.> 超时的响应
				 if(2==length && recv[0]==0x2E && recv[1]==0x3E)
				 {
				     /*ret=RET_SUCCESS;
					 return ret;*/
				 };
				 //!1
				   if(length==3 && recv[0]==0x21 && recv[1]==0x31 && recv[2]==0x3E)
				  {
                     ret=RET_UNKNOW;
					 return ret;
				  };
				  //!2
				   if(length==3 && recv[0]==0x21 && recv[1]==0x32 && recv[2]==0x3E)
				  {
                     ret=RET_ACTION;
					 return ret;
				  };
				    //[Hx>
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x31 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
					//return ret;	
					count--;
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x34 && recv[3]==0x3E)
				  {
                    ret=RET_INITIAL;
			        //return ret;	
					count--;
				  };
				   if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x32 && recv[3]==0x3E)
				  {
                    ret=RET_OOSFULL;
					return ret;				    
				  };
				  if(length==4 && recv[0]==0x5B && recv[1]==0x48 && recv[2]==0x33 && recv[3]==0x3E)
				  {
                    ret=RET_OOSMISSING;
					return ret;				    
				  };
				  // [Bxxyy
				  	if(length==6 && recv[0]==0x5B && recv[1]==0x42 )
				  {
                    			    
				  };
				 //[C>
					if(length==3 && recv[0]==0x5B && recv[1]==0x43 && recv[2]==0x3E)
				  {
                    ret=RET_SUCCESS;
					return ret;			    
				  };
    }	
   return ret;
};

//建立连接，发送命令函数
int GDCashModle::SendCommand(BYTE command[],int commandLength)
{
	BYTE bcc=0x00;
	//BYTE reasult[9];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    bool sendRet,recvRet;
	bool tiaochu=false;
	int count=0;      //循环变量
	int count1=0;      //循环变量
	////////////////////////////////////////
	//通讯过程建立
	count=3;
	while(count--)
	{
			send.clear();
			send.push_back(ENQ);
			sendRet=SendFrame(send);
			if(sendRet==false) 
			{
				/*cLog.Trace(_T("在建立通讯阶段，发送ENQ失败!"));
				return RET_CONMUNICATION_SEND;*/
				ret=RET_CONNECTION;
				continue;
			}
			recv.clear();
			recvRet=RecvFrame(recv,1,1,1,0,0);
			if(recvRet==false) 
			 {
				 send.clear();
				 send.push_back(EOT);
				 sendRet=SendFrame(send);
				 /*cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
				 return RET_CONMUNICATION_TIMEOUT;*/
				 ret=RET_CONNECTION;
				 continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x30)
			{  
				ret=RET_SUCCESS;
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);
				/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				return RET_CONMUNICATION_FAIL;*/
				ret=RET_CONNECTION;
				 continue;
			}
			else if(recv.size()==1 && recv[0]==ENQ)
			{
				/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				return RET_CONMUNICATION_FAIL;*/
				ret=RET_CONNECTION;
				continue;
			};
	}
	if(ret==RET_CONNECTION) return ret;
	//发送正文
	count=3;
	while(count--)
	{
			send.clear();
			send.push_back(command[0]);
			for(i=1;i<commandLength-1;i++)
			{
				send.push_back(command[i]);
				bcc^=command[i];
			};
			send.push_back(bcc);
			sendRet=SendFrame(send);
			if(sendRet==false)
			{
				/*cLog.Trace(_T("在发送报文阶段，发送报文失败!"));
				return RET_COMMAND_SEND;*/
				ret=RET_CONNECTION;
				continue;
			};
			recv.clear();
			recvRet=RecvFrame(recv,0,1,1,0,0);
			if(recvRet==false)
			{
				 /*cLog.Trace(_T("在发送报文阶段,响应报文超时!"));
				return RET_COMMAND_TIMEOUT;*/
				//超时  进入recovery
				count1=3;
				while(count1--)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						/*cLog.Trace(_T("在发送报文过程中建立通讯阶段，发送ENQ失败!"));
						return RET_RECOVERY_SEND;*/
						ret=RET_CONNECTION;
				        continue;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 /*send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 ret=RET_CONNECTION;
				         continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{
						tiaochu=true;
						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						tiaochu=true;
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						 ret=RET_CONNECTION;
				         continue;
					};
				
				};
				break;
			}
			else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x31 ||recv[1]==0x3C))
			{
				ret=RET_SUCCESS;
	            break;
			}
			else if(recv.size()==1 && recv[0]==NAK)
			{   
				/*send.clear();
				send.push_back(EOT);
				sendRet=SendFrame(send);*/
				//cLog.Trace(_T("在发送报文阶段，报文确认重发!"));
				//return RET_CONMUNICATION_FAIL;
				ret=RET_CONNECTION;
				continue;
			}
			else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
			{
				/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
				return RET_CONMUNICATION_FAIL;*/
				// DEL 0x3F   进入recovery   再一次建立连接
				count1=3;
				while(count1--)
				{
				    send.clear();
					send.push_back(ENQ);
					sendRet=SendFrame(send);
					if(sendRet==false) 
					{
						/*cLog.Trace(_T("在发送报文过程中建立通讯阶段，发送ENQ失败!"));
						return RET_RECOVERY_SEND;*/
						 ret=RET_CONNECTION;
				         continue;
					}
					recv.clear();
					recvRet=RecvFrame(recv,0,1,1,0,0);
					if(recvRet==false) 
					 {
						 send.clear();
						 send.push_back(EOT);
						 sendRet=SendFrame(send);
						 /*
						 cLog.Trace(_T("在建立通讯阶段，接受相应报文超时!"));
						 return RET_CONMUNICATION_TIMEOUT;*/
						 ret=RET_CONNECTION;
				         continue;
					}
					else if(recv.size()==2 && recv[0]==DLE && (recv[1]==0x30 ||recv[1]==0x31 || recv[1]==0x3C))
					{

						break;
					}
					else if(recv.size()==1 && recv[0]==NAK)
					{   
						/*send.clear();
						send.push_back(EOT);
						sendRet=SendFrame(send);
						cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						break;
					}
					else if(recv.size()==2 && recv[0]==DLE && recv[1]==0x3F)
					{
						/*cLog.Trace(_T("在建立通讯阶段，建立通讯失败!"));
						return RET_CONMUNICATION_FAIL;*/
						 ret=RET_CONNECTION;
				         continue;
					};
				
				};
				continue;
			};
	};
	//结束命令发送
	send.clear();
	send.push_back(EOT);
	sendRet=SendFrame(send);
	//if(sendRet==true)
	//{
	//     cLog.Trace(_T("发送命令成功!"));
	//};
	return ret;
};

//命令发送成功后，开始接受响应报文
int GDCashModle::RecvConnection(BUF_T & message)
{
    BYTE bcc=0x00;
	BYTE reasult[255];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BYTE temp=0x00;
    bool sendRet,recvRet;
	bool tiaochu=false;
	int type;
	type=-1;    //标记返回的value类型，3 无效，1 有效的纸币面值   2  剔除的纸币面额
	int count=0;
	//开始接受返回报文
	//接受返回报文通讯过程建立
	    count=3;
		while(count--)
		{
			recv.clear();
			recvRet=RecvFrame(recv,1,0,0,0,0);
			if(recvRet==true && recv.size()==1 && recv[0]==ENQ)
			{
				    ret=RET_SUCCESS;
					break;
			}
			else
			{
			        ret=RET_CONNECTION;
			};
		}
		if( ret==RET_CONNECTION) return ret;
		send.clear();
		send.push_back(DLE);
		temp=0x30;
		send.push_back(temp);
		sendRet=SendFrame(send);

		index=0;
		count=3;
		message.clear();
		while(count--)
		{
			recv.clear();
			recvRet=RecvFrame(recv,0,0,0,0,1);
			if(recvRet==true && recv.size()>4) 
			{
		  
			  length=(int)recv.size();
			  bcc=0x00;
			  for(i=1;i<length-1;i++)
			  {
				  bcc^=recv[i];
			  };
			  //判断报文正确与否
			  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETX)
			  {
				  if(recv[length-3]==0x3E)
				  {
					   for(i=2;i<length-2 && index<9;i++)
					  {
						  temp=recv[i];
						  message.push_back(temp);
						  index++;
					  };
				  }
				  else
				  {
				      for(i=2;i<length-2 && index<9;i++)
					  {
						  temp=recv[i];
						  message.push_back(temp);
						  index++;
					  };
				  };
				  send.clear();
				  send.push_back(DLE);
				  temp=recv[1];
				  send.push_back(temp);
				  sendRet=SendFrame(send);
				  memset(reasult,0,255);
				  for(i=0;i<(int)message.size();i++)
				  {
				       reasult[i]=message[i];
				  };
				  //cLog.Trace(_T("ETX："),reasult,message.size());
				  /*
				  if(recv[length-3]==0x3E)
				  {
				    tiaochu=true;
				  }
				    //[Hx>
				  if(reasult[0]==0x5B &&reasult[1]==0x48)
				  {
                     switch((int)reasult[2]%16)
					 {
					 case 1:ret=RET_OOSRESET;break;
					 case 2:ret=RET_OOSMISSING;break;
					 case 3:ret=RET_OOSFULL;break;
					 case 4:ret=RET_OOSOTHER;break;
					 };
				  };
				  //!x
				   if(reasult[0]==0x21)
				  {
                     switch((int)reasult[1]%16)
					 {
					 case 1:ret=RET_UNKNOW;
					 case 2:ret=RET_ACTION;
					 };
				  };
				   //有效地币值
				   if(reasult[0]==0x56)
				   {
				       value=1000;
					   type=1;
				   };
				   ///剔除的币值
				    //R
					if(reasult[0]==0x52)
					{
						value=(((int)reasult[1])%16)*10+((int)reasult[2])%16;
						type=2;
					};*/
				   ret=RET_SUCCESS;
				  break;
			  }
			  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETB)
			  {
				   for(i=2;i<length-2 && index<9;i++)
				  {
					 temp=recv[i];
				     message.push_back(temp);;
					 index++;
				  }; 
				  send.clear();
				  send.push_back(DLE);
				  temp=recv[1];
				  send.push_back(temp);
				  sendRet=SendFrame(send);	
				  //cLog.Trace(_T("ETB："),reasult,index+1);
				  ret=RET_CONNECTION;
				  continue;
			  }
			  else
			  {
				  send.clear();
				  send.push_back(NAK);
				  sendRet=SendFrame(send);	
				  ret=RET_CONNECTION;
				  continue;		  
			  };		
			}
			else
			{
				//Sleep(50);
				//usleep(50000);
				WThrd::tr_sleep( 0, 0.05 );
			};
		};
		count=3;
		while(count--)
		{
		recv.clear();
	    recvRet=RecvFrame(recv,0,0,0,1,0);
		if(recvRet==true && recv[0]==EOT ) 
		{
				ret=RET_SUCCESS;
				break;
		}
		else
		{      
		        ret=RET_CONNECTION;
		};
		};
		return ret;
};
int GDCashModle::RecvConnection(BYTE * sa,int & m)//GDCashModle::RecvConnection(BUF_T & message)
{
	
	BYTE bcc=0x00;
	BYTE reasult[255];
	int ret=RET_SUCCESS;
	int i=0;           //BCC循环中的变量
	int length=0;      //返回报文的长度
	int index=0;       //返回结果值得下标
	BUF_T send;
	BUF_T recv;
	BUF_T message;
	BYTE temp=0x00;
    bool sendRet,recvRet;
	bool tiaochu=false;
	int type;
	type=-1;    //标记返回的value类型，3 无效，1 有效的纸币面值   2  剔除的纸币面额
	int count=0;
	//开始接受返回报文
	//接受返回报文通讯过程建立
	    count=3;
		while(count--)
		{
			recv.clear();
			recvRet=RecvFrame(recv,1,0,0,0,0);
			if(recvRet==true && recv.size()==1 && recv[0]==ENQ)
			{
				    ret=RET_SUCCESS;
					break;
			}
			else
			{
			        ret=RET_CONNECTION;
			};
		}
		if(count==0 && ret==RET_CONNECTION) return ret;
		send.clear();
		send.push_back(DLE);
		temp=0x30;
		send.push_back(temp);
		sendRet=SendFrame(send);

		index=0;
		count=3;
		message.clear();
		while(count--)
		{
			recv.clear();
			recvRet=RecvFrame(recv,0,0,0,0,1);
			if(recvRet==true && recv.size()>4) 
			{
		  
			  length=(int)recv.size();
			  bcc=0x00;
			  for(i=1;i<length-1;i++)
			  {
				  bcc^=recv[i];
			  };
			  //判断报文正确与否
			  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETX)
			  {
				  if(recv[length-3]==0x3E)
				  {
					   for(i=2;i<length-2 && index<9;i++)
					  {
						  temp=recv[i];
						  message.push_back(temp);
						  index++;
					  };
				  }
				  else
				  {
				      for(i=2;i<length-2 && index<9;i++)
					  {
						  temp=recv[i];
						  message.push_back(temp);
						  index++;
					  };
				  };
				  send.clear();
				  send.push_back(DLE);
				  temp=recv[1];
				  send.push_back(temp);
				  sendRet=SendFrame(send);
				  memset(reasult,0,255);
				  for(i=0;i<(int)message.size();i++)
				  {
				       reasult[i]=message[i];
				  };
				  //cLog.Trace(_T("ETX："),reasult,message.size());
				  /*
				  if(recv[length-3]==0x3E)
				  {
				    tiaochu=true;
				  }
				    //[Hx>
				  if(reasult[0]==0x5B &&reasult[1]==0x48)
				  {
                     switch((int)reasult[2]%16)
					 {
					 case 1:ret=RET_OOSRESET;break;
					 case 2:ret=RET_OOSMISSING;break;
					 case 3:ret=RET_OOSFULL;break;
					 case 4:ret=RET_OOSOTHER;break;
					 };
				  };
				  //!x
				   if(reasult[0]==0x21)
				  {
                     switch((int)reasult[1]%16)
					 {
					 case 1:ret=RET_UNKNOW;
					 case 2:ret=RET_ACTION;
					 };
				  };
				   //有效地币值
				   if(reasult[0]==0x56)
				   {
				       value=1000;
					   type=1;
				   };
				   ///剔除的币值
				    //R
					if(reasult[0]==0x52)
					{
						value=(((int)reasult[1])%16)*10+((int)reasult[2])%16;
						type=2;
					};*/
				   ret=RET_SUCCESS;
				  break;
			  }
			  if(recv[0]==STX && recv[length-1]==bcc && recv[length-2]==ETB)
			  {
				   for(i=2;i<length-2 && index<9;i++)
				  {
					 temp=recv[i];
				     message.push_back(temp);;
					 index++;
				  }; 
				  send.clear();
				  send.push_back(DLE);
				  temp=recv[1];
				  send.push_back(temp);
				  sendRet=SendFrame(send);	
				  //cLog.Trace(_T("ETB："),reasult,index+1);
				  ret=RET_CONNECTION;
				  continue;
			  }
			  else
			  {
				  send.clear();
				  send.push_back(NAK);
				  sendRet=SendFrame(send);	
				  ret=RET_CONNECTION;
				  continue;		  
			  };		
			}
			else
			{
				//usleep(50000);
				//Sleep(50);
				WThrd::tr_sleep( 0, 0.05 );
			};
		};
		count=3;
		while(count--)
		{
	    recvRet=RecvFrame(recv,0,0,0,1,0);
		if(recvRet==true && recv[0]==EOT ) 
		{
				ret=RET_SUCCESS;
				break;
		}
		else
		{      
		        ret=RET_CONNECTION;
		};
		};
		 for(i=0;i<(int)message.size();i++)
		{
			sa[i]=message[i];
		};
		 m=(int)message.size();
		return ret;
		
};





int GDCashModle::c2Reset()
{
	SCake ck;
	tbool rc;
	int i;

	for( rc = 0, i = 0; i < 2; i++ )
	{
		ck.UnSeri_S( "05 05" );
		mySerialPort.send_bin( ck ) ;

		mySerialPort.recv_len( ck, 2 );
		if( ck.Seri() == "1030" )
		{
			rc = 1;
			break;
		}
	}

	if( rc == 0 ) return -99;

	i = cmReset( );
	
	printf( "%d\n", i );

	std::string aa;

	aa.clear();
	aa.push_back( 0x02 );  // {0x02,0x31,0x23,0x03,0x00};
	aa += "rec aut>";
	aa.push_back( 0x03 );
	aa.push_back( 0x00 );
	SendCommand( (BYTE*)aa.c_str(), (int)aa.size() );

	aa.clear();
	aa.push_back( 0x02 );  // {0x02,0x31,0x23,0x03,0x00};
	aa += "rec enc>";
	aa.push_back( 0x03 );
	aa.push_back( 0x00 );
	SendCommand( (BYTE*)aa.c_str(), (int)aa.size() );


	i = cmInit();

	printf( "%d\n", i );

	for( rc = 0, i = 0; i < 2; i++ )
	{
		ck.UnSeri_S( "23" );
		mySerialPort.send_bin( ck ) ;

		mySerialPort.recv_bin( ck );
	}



	return 0;

}




// 就是界面上的 reset + init  
int GDCashModle::c3Reset()
{
	int ret=0;

	ret= cmReset( );
	ret=cmInit( );
	ret= cmReset( );
	ret=cmInit( );
	return ret;
}






}	// end namespace BillMEI



