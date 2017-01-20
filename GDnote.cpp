#include "2.h"
#include "GDnote.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


using namespace std;


namespace BillGD {


class SerialPortClass : public d_com_agent2_t 
{
public:
	bool WriteData(unsigned char* pData, unsigned int length)
	{
		if( pData && length )
		{
			SCake ck;
			ck.let( (char*)pData, (int)length );
			LOGSTREAM( gp_log[LOGBILL], LOGPOSI << ck.Seri() );
		
			return this->send_bin( SCake((char*)pData,length) ) ? true : false;
		}
		else
			return true;
	}

	bool ReadChar(char &cRecved)
	{
		SCake ck;
		this->recv_len( ck, 1 );
		if( ck.len() == 0 )
			return false;
		cRecved = *(char*)ck.buf();
		return true;
	}
};


	string num2str(long i)
	{
		stringstream ss;
		ss<<i;
		return ss.str();
	}
	
	long str2num(string s)
	{   
		long num;
		stringstream ss(s);
		ss>>num;
		return num;
	}

	long hex2num(string s)
	{   
		long num;
		if(s[0]>='0'&&s[0]<='9'){num=(s[0]-0x30)*16;}
		else
		{
			if(s[0]>='A'&&s[0]<='F'){num=(s[0]-0x41+10)*16;}
			else
			{
				num=0;
			}
		}
		if(s[1]>='0'&&s[1]<='9'){num=num+(s[1]-0x30);}
		else
		{
			if(s[1]>='A'&&s[1]<='F'){num=num+(s[1]-0x41+10);}
			else
			{
				num=num;
			}
		}
		return num;
	}

static SerialPortClass mySerialPort;
int CmdList[100];
int AnsList[100];
int CmdNo;
int AnsNo;
int AnsNum1,AnsNum2;
int gdW[2];
std::string CashBoxID;
std::string sWorkMode;
GD_NoteState cNoteState;
int NoteValueList[10];
int CMerror;
bool IsCmd,IsAct,IsAns;
int IsOpenComm=0;

int GDCashModle::OpenCom()
{
	IsOpenComm=1;
	int i=0;
	CmdNo=0;AnsNo=0;AnsNum1=0;AnsNum2=0;
	IsAct=false;IsCmd=false;
	if (!mySerialPort.Conn(gp_conf->Get_bill_com_port()))
	{
		LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "initPort fail !" << gp_conf->Get_bill_com_port() );
		std::cout << "initPort fail !" << std::endl;
		i=-1;
	}  
	else 
	{
		LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "initPort success !" << gp_conf->Get_bill_com_port() );
		std::cout << "initPort success !" << std::endl;i=0;
	}  
	if(i==-1)
	{return -1;}
	else
	{return 0;}
} 


int GDCashModle::CloseCom()
{
	LOGSTREAM( gp_log[LOGBILL], LOGPOSI << "ClosePort" << gp_conf->Get_bill_com_port() );
	IsOpenComm=0;
	int i=0;
	IsAct=false;
	if (mySerialPort.DisConn(), 0)
	{std::cout << "ClosePort fail !" << std::endl;i=-1;}  
	else 
	{std::cout << "ClosePort success !" << std::endl;i=0;} 
	if(i==-1)
	{return -1;}
	else
	{return 0;}
} 


int ArrReceive(int vCmdNo,int af,int sf,string AnsStr)
{
	string::size_type ii;
	int i;
	int index;
	std::string vStr1,vStr2;
	std::string fStr;
	switch(vCmdNo)
	{
	case 1:
		if(af==0x11){return vCmdNo;}
		break;
	case 2:
		if(af==0x06){return vCmdNo;}
		break;
	case 3:
		if(af==0x06){return vCmdNo;}
		break;
	case 4:
		if(af==0x06){return vCmdNo;}
		break;
	case 5:
		if(sf!=0x03){return 0;}
		sWorkMode=AnsStr.substr(1,2);
		return vCmdNo;
		break;
	case 6:
		if(sf!=0x03||AnsStr==""){return 0;}
		index=0;fStr=AnsStr;
		cNoteState.A=0xFF;
		cNoteState.D=0xFF;
		cNoteState.L=0xFF;
		cNoteState.N=0xFF;
		cNoteState.P=0xFF;
		cNoteState.S=0xFF;
		cNoteState.W=0xFF;
		cNoteState.Enum=0;
		cNoteState.Rnum=0;
		for(i=0;i<10;i++)
		{cNoteState.E[i]=0xFF;}
		for(i=0;i<3;i++)
		{cNoteState.R[i]=0xFF;}

		while(index!=-1)
		{
			vStr1 = fStr.substr(0,1);
			vStr2 = fStr.substr(1,2);
			i=hex2num(vStr2);      
			switch(vStr1[0])
			{
			case 'A':cNoteState.A=i;break;
			case 'D':cNoteState.D=i;break;
			case 'E':cNoteState.E[cNoteState.Enum]=i;cNoteState.Enum++;break;
			case 'L':cNoteState.L=i;break;
			case 'N':cNoteState.N=i;break;
			case 'P':cNoteState.P=i;break;
			case 'R':cNoteState.R[cNoteState.Rnum]=i;cNoteState.Rnum++;break;
			case 'S':cNoteState.S=i;break;
			case 'W':cNoteState.W=i;break;
			default:break;
			}
			ii = fStr.find_first_of(',',0);
			index=(int)ii;
			if(ii!=string::npos){fStr = fStr.substr(4,-1);}
			else{break;}
		}
		return vCmdNo;
		break;
	case 7:
		if(sf!=0x03){return 0;}
		if(AnsStr==""){cNoteState.NoteValue=888;return vCmdNo;}
		int sindex;
		vStr1 = AnsStr.substr(0,3);
		ii=AnsStr.find_first_of(" ",4);
		sindex=(int)ii;
		vStr2 = AnsStr.substr(4,sindex-4);
		if(vStr1=="CNY"){cNoteState.NoteValue=str2num(vStr2);}
		else{cNoteState.NoteValue=888;}
		return vCmdNo;
		break;
	case 8:
		if(sf!=0x03){return 0;}
		CashBoxID=AnsStr;
		return vCmdNo;
		break;
	case 9:
		if(af==0x06){return vCmdNo;}
		break;
	case 10:
		if(af==0x06){return vCmdNo;}
		break;
	case 11:
		if(af==0x11){return vCmdNo;}
		break;
	case 12:
		if(af==0x11){return vCmdNo;}
		break;
	case 13:
		if(af==0x11){return vCmdNo;}
		break;
	case 14:
		if(af==0x11){return vCmdNo;}
		break;
	case 15:
		if(af==0x11){return vCmdNo;}
		break;
	}
	return 0;
}

int SendData(unsigned char * vData,unsigned int vlength,int vCmdNo,int time)
{
	if(IsOpenComm==0) { return -1; }
	AnsNum2=0;
	bool vIsAns=false;
	int vAnsNo=0;
	int arrLen=0;
	int IsArrEnd=0;
	int strf=0;
	int actf=0;
	char vArr;
	bool GetArr;
	string AnsStr="";
	mySerialPort.WriteData(vData,vlength);
	//mySerialPort.send_bin( SCake((char*)vData,vlength) );
	//clock_t now = clock(); 
	bu_quickflow_t::qf_counter_t now;

	gp_qf->GetQf( now );

	while(!vIsAns)
	{
		//if((clock()-now)>time)
		if( gp_qf->IsLongQf( now, time / 1000.00 ) ) 
		{
			switch(actf)
			{
			case 0x00:return 1;
			case 0x02:return 2;
			case 0x06:return 3;
			case 0x13:return 4;
			default:return 7;
			}
		}
	

		GetArr=mySerialPort.ReadChar(vArr);

		if(GetArr==true)
			gp_qf->GetQf( now );


		if(GetArr==true)
		{
			AnsList[AnsNum2]=vArr;
			switch(vArr)
			{
			case 0x06:
				actf=vArr;
				AnsNum2=0;
				break;
			case 0x11:
				actf=vArr;
				AnsNum2=0;
				break;
			case 0x13:
				actf=vArr;
				AnsNum2=0;
				break;
			case 0x02:
				strf=vArr;
				AnsStr="";
				AnsNum2++;
				break;
			case 0x03:
				if(strf==0x02)
				{
					strf=vArr;
					AnsNum2++;
					mySerialPort.ReadChar(vArr);
					AnsList[AnsNum2]=vArr;
					AnsNum2++;
					break;
				}
			default:
				if(strf==0x02)
				{
					if((vArr>=0x30&&vArr<=0x39)||(vArr>=0x40&&vArr<=0x5A)||(vArr>=0x20&&vArr<=0x2F))
					{
						AnsStr=AnsStr+vArr;
						AnsNum2++;
					}
				}
			}
			if(vCmdNo==ArrReceive(vCmdNo,actf,strf,AnsStr)){return 0;}
		}
		//Sleep(1);
		WThrd::tr_sleep( 0, 0.01 );

	}
	return 0;
}

int cmGetDenomination()
{
	int re,i,isend;
	isend=0;
	unsigned char SendArr[20];

	CmdNo=7;

	for(i=0;i<10;i++)
	{
		cNoteState.NoteValue=0;
		SendArr[0]=0x02;
		SendArr[1]='I';
		SendArr[2]='N';
		SendArr[3]='D';
		SendArr[4]=0x30;
		SendArr[5]=0x30+i;
		SendArr[6]=0x03;
		SendArr[7]=SendArr[1]^SendArr[2]^SendArr[3]^SendArr[4]^SendArr[5]^SendArr[6];
		unsigned char * SendStr1= (unsigned char *)SendArr;
		re=SendData(SendStr1,8,CmdNo,1000);

		if(re==0)
		{
			unsigned char SendArr[20];
			SendArr[0]=0x06;
			unsigned char * SendStr3=(unsigned char *)SendArr;
			mySerialPort.WriteData(SendStr3,1);

			NoteValueList[i]=cNoteState.NoteValue;
			cNoteState.NoteValue=0;
		}
		else{cNoteState.NoteValue=0;return re;}
	}

	cNoteState.NoteValue=0;
	return 0;
}

int GDCashModle::cmReset()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=1;
	SendArr[0]=0x02;
	SendArr[1]='T';
	SendArr[2]='F';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,20000);

	if(re==0)
	{
		CmdNo=2;
		SendArr[0]=0x02;
		SendArr[1]='D';
		SendArr[2]='0';
		SendArr[3]=',';
		SendArr[4]='0';
		SendArr[5]=0x03;
		SendArr[6]=SendArr[1]^SendArr[2]^SendArr[3]^SendArr[4]^SendArr[5];
		unsigned char * SendStr2= (unsigned char *)SendArr;
		re=SendData(SendStr2,7,CmdNo,1000);

		if(re==0)
		{
			CmdNo=3;
			SendArr[0]=0x02;
			SendArr[1]='W';
			SendArr[2]='0';
			SendArr[3]='1';
			SendArr[4]=0x03;
			SendArr[5]=SendArr[1]^SendArr[2]^SendArr[3]^SendArr[4];
			unsigned char * SendStr3= (unsigned char *)SendArr;
			re=SendData(SendStr3,6,CmdNo,1000);
		}
	}

	int sre;
	sre=cmGetDenomination();

	if(sre!=0){return sre;}
	else{return re;}
}

int GDCashModle::cmWorkMode(std::string *WorkMode)
{
	int re;
	unsigned char SendArr[20];

	CmdNo=4;
	SendArr[0]=0x02;
	SendArr[1]='D';
	SendArr[2]='0';
	SendArr[3]=',';
	SendArr[4]='0';
	SendArr[5]=0x03;
	SendArr[6]=SendArr[1]^SendArr[2]^SendArr[3]^SendArr[4]^SendArr[5];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,7,CmdNo,1000);

	if(re==0)
	{
		unsigned char SendArr[20];
		CmdNo=5;
		SendArr[0]=0x02;
		SendArr[1]='R';
		SendArr[2]=0x03;
		SendArr[3]=SendArr[1]^SendArr[2];
		unsigned char * SendStr2=(unsigned char *)SendArr;
		re=SendData(SendStr2,4,CmdNo,1000);

		if(re==0)
		{
			unsigned char SendArr[20];
			SendArr[0]=0x06;
			unsigned char * SendStr3=(unsigned char *)SendArr;
			mySerialPort.WriteData(SendStr3,1);

			*WorkMode=sWorkMode;
		}
	}

	return re;
}

int GDCashModle::cmState()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=6;
	SendArr[0]=0x02;
	SendArr[1]='S';
	SendArr[2]='T';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	if(re==0)
	{
		unsigned char SendArr[20];
		SendArr[0]=0x06;
		unsigned char * SendStr3=(unsigned char *)SendArr;
		mySerialPort.WriteData(SendStr3,1);

		cNoteState.NoteValue=0;
		int n,i,j,k;
		cErrorNum=0;
		for(i=0;i<10;i++)
		{
			switch(cNoteState.E[i])
			{
			case 0x01:k=0x01;break;
			case 0x02:k=0x01;break;
			case 0x04:k=0x01;break;
			case 0x05:k=0x01;break;
			case 0x10:k=0x02;break;
			case 0x0F:k=0x03;break;
			case 0x54:k=0x04;break;
			case 0x55:k=0x05;break;
			case 0x56:k=0x06;break;
			case 0x62:k=0x07;break;
			case 0x82:k=0x08;break;
			default:k=0x00;
			}
			if(k!=0x00)
			{
				if(cErrorNum==0)
				{
					cErrorCode[cErrorNum]=k;
					cErrorNum++;
				}
				else
				{
					n=0;
					for(j=0;j<cErrorNum;j++)
					{
						if(cErrorCode[j]==k){n++;}
					}
					if(n==0)
					{
						cErrorCode[cErrorNum]=k;
						cErrorNum++;
					}
				}
			}
		}

		if(cNoteState.D!=0xFF)
		{
			int iGDD;
			iGDD=cNoteState.D;
			if(iGDD>=0&&iGDD<=9){cNoteState.NoteValue=NoteValueList[iGDD];}
			else{cNoteState.NoteValue=888;}
		}
		if(cNoteState.Rnum!=0){cNoteState.NoteValue=888;}
		cNoteValue=cNoteState.NoteValue;
	}
	if(cNoteState.N!=0xFF){cNoteNum=cNoteState.N;}
	else{cNoteNum=0;}

	return re;
}

int GDCashModle::cmBoxID(std::string *NoteBoxID)
{
	int re;
	unsigned char SendArr[20];

	CmdNo=2;
	SendArr[0]=0x02;
	SendArr[1]='D';
	SendArr[2]='4';
	SendArr[3]=',';
	SendArr[4]='2';
	SendArr[5]=0x03;
	SendArr[6]=SendArr[1]^SendArr[2]^SendArr[3]^SendArr[4]^SendArr[5];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,7,CmdNo,1000);

	if(re==0)
	{
		unsigned char SendArr[20];
		CmdNo=8;
		SendArr[0]=0x02;
		SendArr[1]='R';
		SendArr[2]=0x03;
		SendArr[3]=SendArr[1]^SendArr[2];
		unsigned char * SendStr2=(unsigned char *)SendArr;
		re=SendData(SendStr2,4,CmdNo,1000);

		if(re==0)
		{
			unsigned char SendArr[20];
			SendArr[0]=0x06;
			unsigned char * SendStr3=(unsigned char *)SendArr;
			mySerialPort.WriteData(SendStr3,1);
		}
	}

	if(re==0){*NoteBoxID=CashBoxID;}
	return re;
}

int GDCashModle::cmWork()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=9;
	SendArr[0]=0x02;
	SendArr[1]='V';
	SendArr[2]='1';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,2000);

	return re;
}

int GDCashModle::cmStop()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=10;
	SendArr[0]=0x02;
	SendArr[1]='V';
	SendArr[2]='0';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,2000);

	return re;
}

int GDCashModle::cmReturn()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=11;
	SendArr[0]=0x02;
	SendArr[1]='B';
	SendArr[2]='0';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	int sre;
	sre=cmState();
	if(sre!=0&&re==0){return 5;}
	if(sre==0&&cNoteState.A!=0x04){return 6;}
	if(sre==0&&cNoteState.A==0x04){return 0;}
	else{return re;}
}

int GDCashModle::cmReject()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=12;
	SendArr[0]=0x02;
	SendArr[1]='B';
	SendArr[2]='2';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	int sre;
	sre=cmState();
	if(sre!=0&&re==0){return 5;}
	if(sre==0&&cNoteState.A!=0x06){return 6;}
	if(sre==0&&cNoteState.A==0x06){return 0;}
	else{return re;}
}

int GDCashModle::cmEscrow()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=13;
	SendArr[0]=0x02;
	SendArr[1]='B';
	SendArr[2]='3';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	int sre;
	sre=cmState();
	if(sre!=0&&re==0){return 5;}
	if(sre==0&&cNoteState.A!=0x05){return 6;}
	if(sre==0&&cNoteState.A==0x05){return 0;}
	else{return re;}
}

int GDCashModle::cmDeposit()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=14;
	SendArr[0]=0x02;
	SendArr[1]='B';
	SendArr[2]='1';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	int sre;
	sre=cmState();
	if(sre!=0&&re==0){return 5;}
	if(sre==0&&cNoteState.A!=0x03){return 6;}
	if(sre==0&&cNoteState.A==0x03){return 0;}
	else{return re;}
}

int GDCashModle::cmClear()
{
	int re;
	unsigned char SendArr[20];

	CmdNo=15;
	SendArr[0]=0x02;
	SendArr[1]='B';
	SendArr[2]='F';
	SendArr[3]=0x03;
	SendArr[4]=SendArr[1]^SendArr[2]^SendArr[3];
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,5,CmdNo,5000);

	return re;
}

#if 0

#endif



}




