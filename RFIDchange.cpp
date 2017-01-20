
#include "2.h"
#include "RFIDchange.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "d_comlogger_t.h"
#include "d_com_agent2_t.h"


using namespace std;


class SerialPortClass : public d_com_agent2_t 
{
public:
	bool WriteData(unsigned char* pData, unsigned int length)
	{
		if( pData && length )
		{
			SCake ck;
			ck.let( (char*)pData, (int)length );
			LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << ck.Seri() );

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

	int hex2bcd(int vHex)
	{
		int a,b;
		a=vHex/10;
		b=vHex-a*10;
		return (a*16+b);
	}

	int bcd2hex(int vBcd)
	{
		int a,b;
		a=vBcd/16;
		b=vBcd-a*16;
		return (a*10+b);
	}

int IsOpenComm=0;
int IsRead=0;
int boxInfo1[32];
//CSerialPort mySerialPort;
static SerialPortClass mySerialPort;

int RFIDrwModle::OpenCom()
{
	int i=0;
	//if (!mySerialPort.InitPort(iPortNum,38400,'N',8,1))
	if (!mySerialPort.Conn(gp_conf->Get_bilchgrfid_com_port()))
	{
		LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "initPort fail !" << gp_conf->Get_bilchgrfid_com_port() );
		std::cout << "initPort fail !" << std::endl;
		i=-1;
	}  
	else 
	{
		LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "initPort success !" << gp_conf->Get_bilchgrfid_com_port() );
		std::cout << "initPort success !" << std::endl;
		i=0;
	}  
	if(i==-1)
	{
		return -1;
	}
	else
	{
		IsOpenComm=1;
		return 0;
	}
} 

int RFIDrwModle::CloseCom()
{
	LOGSTREAM( gp_log[LOGBILLCHG], LOGPOSI << "ClosePort" << gp_conf->Get_bilchgrfid_com_port() );
	int i=0;
	if (mySerialPort.DisConn(), 0)
	//if (!mySerialPort.ClosePort())
	{
		std::cout << "ClosePort fail !" << std::endl;i=-1;}  
	else 
	{std::cout << "ClosePort success !" << std::endl;i=0;} 
	if(i==-1)
	{return -1;}
	else
	{IsOpenComm=0;return 0;}
} 


int RFIDrwModle::SendData(unsigned char * vData,unsigned int vlength,int vCmdNo,int time,int vChannel)
{
	if(IsOpenComm==0) { return -1; }
	unsigned char AnsList[30];
	int i;
	int AnsNo=0;
	bool vIsAns1=false;
	bool vIsAns2=false;
	bool GetArr;
    char vArr;
	printf("S: ");
	for(i=0;i<28;i++)
	{printf("%02X ",vData[i]);}
	mySerialPort.WriteData(vData,vlength);
	//clock_t now = clock(); 
	bu_quickflow_t::qf_counter_t now;

	gp_qf->GetQf( now );

	while(!vIsAns2)
	{
		//if((clock()-now)>time)
		if( gp_qf->IsLongQf( now, time / 1000.00 ) ) 
		{
			printf("\n");
			if(vIsAns1)
			{return -3;}
			else
			{return -2;}
		}
	
		GetArr=mySerialPort.ReadChar(vArr);

		if(GetArr==true)
			gp_qf->GetQf( now );

		if(GetArr==true)
		{
			AnsList[AnsNo]=vArr;
			if(AnsNo==0){printf("\nR: ");}
			printf("%02X ",AnsList[AnsNo]);
			if(AnsNo==0)
			{
				if((AnsList[AnsNo]==0x10)||(AnsList[AnsNo]==0x2F))
				{AnsNo++;}
			}
			else{AnsNo++;}
			if((AnsNo==2)&&(vIsAns1==false))
			{
				if((AnsList[0]==0x10)&&(AnsList[1]==0x06)){vIsAns1=true;AnsNo=0;}
				if((AnsList[0]==0x10)&&(AnsList[1]==0x15)){return -4;}
			}
			if((AnsNo>=28)&&(AnsList[0]==0x2F)&&(AnsList[1]==vChannel))
			{
				printf("\n");
				switch(vCmdNo)
				{
				case 0x03:
					if(AnsList[2]==0xA3){return 0;}
				case 0x04:
					if(AnsList[2]==0x04)
					{
						rfidVer=num2str(AnsList[3]);
						rfidVer=rfidVer+"."+num2str(AnsList[4]);
						rfidVer=rfidVer+"."+num2str(AnsList[5]);
						rfidVer=rfidVer+"."+num2str(AnsList[6]);
						return 0;
					}
				case 0x05:
					if(AnsList[2]==0x05)
					{
						for(i=0;i<16;i++)
						{boxInfo1[i]=AnsList[i+4];}
						for(i=0;i<7;i++)
						{RWerror[i]=AnsList[i+20];}
						IsRead=0;
						return 0;
					}
				case 0x06:
					if(AnsList[2]==0x06)
					{
						for(i=0;i<16;i++)
						{boxInfo1[i]=AnsList[i+4];}
						for(i=0;i<7;i++)
						{RWerror[i]=AnsList[i+20];}
						IsRead=vChannel;
						return 0;
					}
				case 0x27:
					if(AnsList[2]==0x27)
					{
						if(vChannel==1||vChannel==2||vChannel==3)
						{
							BoxInfoList[vChannel-1].BoxState=AnsList[3];
							BoxInfoList[vChannel-1].LineID=AnsList[16];
							BoxInfoList[vChannel-1].StationID=AnsList[17];
							BoxInfoList[vChannel-1].err=AnsList[20];
							BoxInfoList[vChannel-1].Denomination=AnsList[21];
							BoxInfoList[vChannel-1].Number=bcd2hex(AnsList[22])*100+bcd2hex(AnsList[23]);
							BoxInfoList[vChannel-1].Count=bcd2hex(AnsList[24])*100*100+bcd2hex(AnsList[25])*100+bcd2hex(AnsList[26]);
						}
						return 0;
					}
				case 0x28:
					if(AnsList[2]==0x28){return AnsList[3];}
				}
				AnsNo=0;
			}
			else
			{
				if((AnsNo>=28)&&(AnsList[0]==0x2F)){printf("\n");AnsNo=0;}
			}
		}
		//Sleep(1);
		//WThrd::tr_sleep( 0, 0.01 );
	}
	return 0;
}

int RFIDrwModle::BoxTest(int vBoxNum)
{
	int re,i;
	int vArr=0xFF;
	unsigned char SendArr[28];

	SendArr[0]=0x2F;
	SendArr[1]=vBoxNum;
	SendArr[2]=0x03;
	SendArr[3]=0x00;
	SendArr[4]=0x00;
	SendArr[5]=0x00;
	SendArr[6]=0x00;
	SendArr[7]=0x00;
	SendArr[8]=0x00;
	SendArr[9]=0x00;
	SendArr[10]=0x00;
	SendArr[11]=0x00;
	SendArr[12]=0x00;
	SendArr[13]=0x00;
	SendArr[14]=0x00;
	SendArr[15]=0x00;
	SendArr[16]=0x00;
	SendArr[17]=0x00;
	SendArr[18]=0x00;
	SendArr[19]=0x00;
	SendArr[20]=0x00;
	SendArr[21]=0x00;
	SendArr[22]=0x00;
	SendArr[23]=0x00;
	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}

int RFIDrwModle::GetState()
{
	int re,i;
	int vArr=0xFF;
	unsigned char SendArr[28];

	SendArr[0]=0x2F;
	SendArr[1]=0x00;
	SendArr[2]=0x04;
	SendArr[3]=0x00;
	SendArr[4]=0x00;
	SendArr[5]=0x00;
	SendArr[6]=0x00;
	SendArr[7]=0xFF;
	SendArr[8]=0xFF;
	SendArr[9]=0x00;
	SendArr[10]=0x00;
	SendArr[11]=0x00;
	SendArr[12]=0x00;
	SendArr[13]=0x00;
	SendArr[14]=0x00;
	SendArr[15]=0x00;
	SendArr[16]=0x00;
	SendArr[17]=0x00;
	SendArr[18]=0x00;
	SendArr[19]=0x00;
	SendArr[20]=0x00;
	SendArr[21]=0x00;
	SendArr[22]=0x00;
	SendArr[23]=0x00;
	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}

int RFIDrwModle::BoxWrite(int vBoxNum,int vDenomination,int vNumber,int vCount)
{
	int re,i;
	int a,b,c;
	int vArr=0xFF;
	unsigned char SendArr[28];
	if(IsRead==0){return 1;}
	
	boxInfo1[10]=vDenomination;
	boxInfo1[11]=hex2bcd(vNumber/100);
	boxInfo1[12]=hex2bcd(vNumber-int(vNumber/100)*100);
	a=vCount/10000;
	c=vCount-int(vCount/100)*100;
	b=(vCount-a-c)/100;
	boxInfo1[13]=hex2bcd(a);
	boxInfo1[14]=hex2bcd(b);
	boxInfo1[15]=hex2bcd(c);

	SendArr[0]=0x2F;
	SendArr[1]=vBoxNum;
	SendArr[2]=0x05;
	SendArr[3]=0x0C;
	SendArr[4]=0x00;
	SendArr[5]=0x00;
	SendArr[6]=0x00;
	SendArr[7]=0x00;

	for(i=0;i<16;i++)
	{SendArr[i+8]=boxInfo1[i];}

	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}

int RFIDrwModle::BoxRead(int vBoxNum)
{
	int re,i;
	int vArr=0xFF;
	unsigned char SendArr[28];

	SendArr[0]=0x2F;
	SendArr[1]=vBoxNum;
	SendArr[2]=0x06;
	SendArr[3]=0x0C;
	SendArr[4]=0x00;
	SendArr[5]=0x00;
	SendArr[6]=0x00;
	SendArr[7]=0x00;
	SendArr[8]=0x00;
	SendArr[9]=0x00;
	SendArr[10]=0x00;
	SendArr[11]=0x00;
	SendArr[12]=0x00;
	SendArr[13]=0x00;
	SendArr[14]=0x00;
	SendArr[15]=0x00;
	SendArr[16]=0x00;
	SendArr[17]=0x00;
	SendArr[18]=0x00;
	SendArr[19]=0x00;
	SendArr[20]=0x00;
	SendArr[21]=0x00;
	SendArr[22]=0x00;
	SendArr[23]=0x00;
	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}

int RFIDrwModle::BoxInstall(int vBoxNum,unsigned char * UserID,int vLineNum,int vStationNum,unsigned char * NowTime)
{
	int re,i;
	int vArr=0xFF;
	unsigned char SendArr[28];

	SendArr[0]=0x2F;
	SendArr[1]=vBoxNum;
	SendArr[2]=0x28;
	SendArr[3]=UserID[0];
	SendArr[4]=UserID[1];
	SendArr[5]=UserID[2];
	SendArr[6]=UserID[3];
	SendArr[7]=vLineNum;
	SendArr[8]=vStationNum;

	SendArr[9]=NowTime[0];
	SendArr[10]=NowTime[1];
	SendArr[11]=NowTime[2];
	SendArr[12]=NowTime[3];
	SendArr[13]=NowTime[4];
	SendArr[14]=NowTime[5];
	SendArr[15]=NowTime[6];

	SendArr[16]=0x00;
	SendArr[17]=0x00;
	SendArr[18]=0x00;
	SendArr[19]=0x00;
	SendArr[20]=0x00;
	SendArr[21]=0x00;
	SendArr[22]=0x00;
	SendArr[23]=0x00;
	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}

int RFIDrwModle::BoxInfomation(int vBoxNum)
{
	int re,i;
	int vArr=0xFF;
	unsigned char SendArr[28];

	SendArr[0]=0x2F;
	SendArr[1]=vBoxNum;
	SendArr[2]=0x27;
	SendArr[3]=0x00;
	SendArr[4]=0x00;
	SendArr[5]=0x00;
	SendArr[6]=0x00;
	SendArr[7]=0x00;
	SendArr[8]=0x00;
	SendArr[9]=0x00;
	SendArr[10]=0x00;
	SendArr[11]=0x00;
	SendArr[12]=0x00;
	SendArr[13]=0x00;
	SendArr[14]=0x00;
	SendArr[15]=0x00;
	SendArr[16]=0x00;
	SendArr[17]=0x00;
	SendArr[18]=0x00;
	SendArr[19]=0x00;
	SendArr[20]=0x00;
	SendArr[21]=0x00;
	SendArr[22]=0x00;
	SendArr[23]=0x00;
	SendArr[24]=0x00;
	SendArr[25]=0x00;
	SendArr[26]=0x00;
	for(i=0;i<27;i++)
	{vArr=vArr^SendArr[i];}
	SendArr[27]=vArr;
	unsigned char * SendStr1= (unsigned char *)SendArr;
	re=SendData(SendStr1,28,SendArr[2],1000,SendArr[1]);

	return re;
}
