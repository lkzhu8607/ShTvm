
#ifndef V1_3AA3003_T_20140523_160604
#define V1_3AA3003_T_20140523_160604

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a3003_t
//Name:	a3003_t_rowtype
class a3003_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		7.0.6 3003-TVM运营参数。此类交互用于向TVM传送运营参数。它最初由CC发起，SC 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	wl::tuint8		m_BuyTicketNumLimit;			// a	1	购票数限制 单次购票操作允许的最大购票数 Byte 1 
	wl::tuint8		m_GetTicketTimeoutSec;			// a	2	取票超时时间以s为单位。在车票停在出票口后一定时间内没有取票，则认为取票超时，TVM将发出报警信号和故障消息Byte1 
	wl::tuint8		m_PutCoinWaitTimeSec;			// a	3	投币等待时间以5s为单位。在限定的时间内无投币操作，该项交易将被取消Byte1 
	u8arr_t<20>		m_PermitTicketType;			// a	4	允许发售的车票类型 
	u8arr_t<2>		m_WorkModeConf;			// a	5	工作模式设置 
	u8arr_t<4>		m_RES_01;			// a	6	[保留]  Byte 4 
	wl::tuint8		m_PermitCoinType;			// a	7	允许使用硬币类型对应位设置为1有效：Bit0：1角Bit1：5角Bit2：1元Bit3~7：[保留]Byte1 
	u8arr_t<4>		m_PermitBillType;			// a	8	允许使用纸币类型 
	wl::tuint8		m_PermitCoinChgType;			// a	9	找零允许使用的硬币类型 
	wl::tuint8		m_CoinChgMaxNum;			// a	10	找零允许的最大硬币个数  Byte 1 
	wl::tuint8		m_BillChgMaxNum;			// a	11	找零允许的最多纸币张数  Byte 1 
	u8arr_t<4>		m_PermitBillChgType;			// a	12	找零允许使用的纸币类型 
	long		m_lChgPermitMaxAmount;			// a	13	找零允许最大金额  Long 4 
	wl::tuint8		m_RES_02;			// a	14	[保留]  Byte 1 
	wl::tuint8		m_FaultWorkMode;			// a	15	故障工作方式 
	u8arr_t<2>		m_DeviceConfPara;			// a	16	设备配置参数 
	u8arr_t<16>		m_CurrButtonRegion;			// a	17	当前按钮区域码定义 
	u8arr_t<16>		m_FutureButtonRegion;			// a	18	将来按钮区域码定义 格式同当前按钮区域码定义 Block 16 
	u8arr_t<16>		m_ButtonEnableFlag;			// a	19	按钮可用标志 
	u8arr_t<4>		m_RES_03;			// a	20	[保留]  Byte 4 
 
public:

	a3003_t_rowtype()
	{
		m_strTblName = "a3003";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_BuyTicketNumLimit = 0;
		m_GetTicketTimeoutSec = 0;
		m_PutCoinWaitTimeSec = 0;
		//m_PermitTicketType = //use default
		//m_WorkModeConf = //use default
		//m_RES_01 = //use default
		m_PermitCoinType = 0;
		//m_PermitBillType = //use default
		m_PermitCoinChgType = 0;
		m_CoinChgMaxNum = 0;
		m_BillChgMaxNum = 0;
		//m_PermitBillChgType = //use default
		m_lChgPermitMaxAmount = 0;
		m_RES_02 = 0;
		m_FaultWorkMode = 0;
		//m_DeviceConfPara = //use default
		//m_CurrButtonRegion = //use default
		//m_FutureButtonRegion = //use default
		//m_ButtonEnableFlag = //use default
		//m_RES_03 = //use default
	}

	virtual ~a3003_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a3003_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3003_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3003_t_rowtype & rhs) const
	{
		return this < &rhs;
	}

 
protected:

	template< class T > T decode2( void *p ) 
	 { T x; memcpy( &x, p, sizeof(T) ); return x; }

	//serialize unserialize

	static void en( const char *src, long len, char *destbuf )
	{
		static char strHexPtr[] = "0123456789ABCDEF";
		char *pdest=destbuf;
		pdest[0]=pdest[1]=0;
		pdest[2]=0;pdest[3]=0;
		for( long i = 0; i<len; i++ )
		{
			//int iVal = (unsigned char)src[i];
			pdest[0] = strHexPtr[ (unsigned char)src[i] / 16 % 16 ];
			pdest[1] = strHexPtr[ (unsigned char)src[i] % 16 ];
			pdest += 2;
		}
		*pdest = 0;
	}

	static char *de( char *src )
	{
		long i,k;
		int nReturn=0;
		for( i=k=0; ; )
		{
			if(src[i]=='/'||src[i]==0) break;
			if ( src[i]>='0'&& src[i] <= '9' ) nReturn =        16 + src[i] - '0';
			else if ( src[i] >= 'A'&& src[i] <= 'F' ) nReturn = 16 + src[i] - 'A' + 10;
			i++;nReturn *=16;
			if(src[i]=='/'||src[i]==0) break;
			if ( src[i]>='0'&& src[i] <= '9' ) nReturn +=        src[i] - '0';
			else if ( src[i] >= 'A'&& src[i] <= 'F' ) nReturn += src[i] - 'A' + 10;
			i++; src[k++] = (char)(unsigned char)nReturn;
		}
		if(src[i]==0) return src+i;
		return src+i+1;
	}

 
public:

	//serialize unserialize

	std::string & Serialize( std::string & strOut )
	{
		strOut = "";
		const char *buf1;
		long len1;
		char *buf2;
		std::vector< char > v;
		buf1 = (const char *)m_strTblName.c_str();
		len1 = (long)(m_strTblName.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lVer));
		len1 = sizeof(m_lVer);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strAffectDateTime.c_str();
		len1 = (long)(m_strAffectDateTime.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_biDelFlag));
		len1 = sizeof(m_biDelFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_biIsAffect));
		len1 = sizeof(m_biIsAffect);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strStampDateTime.c_str();
		len1 = (long)(m_strStampDateTime.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strDataRef.c_str();
		len1 = (long)(m_strDataRef.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BuyTicketNumLimit));
		len1 = sizeof(m_BuyTicketNumLimit);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GetTicketTimeoutSec));
		len1 = sizeof(m_GetTicketTimeoutSec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PutCoinWaitTimeSec));
		len1 = sizeof(m_PutCoinWaitTimeSec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitTicketType));
		len1 = sizeof(m_PermitTicketType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_WorkModeConf));
		len1 = sizeof(m_WorkModeConf);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitCoinType));
		len1 = sizeof(m_PermitCoinType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitBillType));
		len1 = sizeof(m_PermitBillType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitCoinChgType));
		len1 = sizeof(m_PermitCoinChgType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChgMaxNum));
		len1 = sizeof(m_CoinChgMaxNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillChgMaxNum));
		len1 = sizeof(m_BillChgMaxNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitBillChgType));
		len1 = sizeof(m_PermitBillChgType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lChgPermitMaxAmount));
		len1 = sizeof(m_lChgPermitMaxAmount);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_FaultWorkMode));
		len1 = sizeof(m_FaultWorkMode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DeviceConfPara));
		len1 = sizeof(m_DeviceConfPara);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CurrButtonRegion));
		len1 = sizeof(m_CurrButtonRegion);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_FutureButtonRegion));
		len1 = sizeof(m_FutureButtonRegion);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ButtonEnableFlag));
		len1 = sizeof(m_ButtonEnableFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_03));
		len1 = sizeof(m_RES_03);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		return strOut;
	}

	std::string Serialize()
	{
		std::string strOut;
		return this->Serialize(strOut);
	}

	a3003_t_rowtype & Unserialize( const char * strIn )
	{
		const char *buf1;
		char *buf2;
		buf1 = strIn;
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strTblName = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lVer = decode2<long>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strAffectDateTime = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_biDelFlag = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_biIsAffect = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strStampDateTime = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strDataRef = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BuyTicketNumLimit = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_GetTicketTimeoutSec = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PutCoinWaitTimeSec = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PermitTicketType = *(u8arr_t<20>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_WorkModeConf = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_01 = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PermitCoinType = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PermitBillType = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PermitCoinChgType = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinChgMaxNum = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BillChgMaxNum = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PermitBillChgType = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lChgPermitMaxAmount = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_02 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_FaultWorkMode = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DeviceConfPara = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CurrButtonRegion = *(u8arr_t<16>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_FutureButtonRegion = *(u8arr_t<16>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ButtonEnableFlag = *(u8arr_t<16>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_03 = *(u8arr_t<4>*)buf2; }else return *this; 
		return *this;
	}

	 
#ifdef X014FASTSERI_

	wl::SCake & Serialize( wl::SCake & ckOut )
	{
		ckOut.redim(0);
		const char *buf1;
		wl::tuint32 len1;
		wl::SCakel ckl;
		buf1 = (const char *)m_strTblName.c_str();
		len1 = (long)(m_strTblName.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lVer));
		len1 = sizeof(m_lVer);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strAffectDateTime.c_str();
		len1 = (long)(m_strAffectDateTime.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_biDelFlag));
		len1 = sizeof(m_biDelFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_biIsAffect));
		len1 = sizeof(m_biIsAffect);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strStampDateTime.c_str();
		len1 = (long)(m_strStampDateTime.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strDataRef.c_str();
		len1 = (long)(m_strDataRef.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BuyTicketNumLimit));
		len1 = sizeof(m_BuyTicketNumLimit);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GetTicketTimeoutSec));
		len1 = sizeof(m_GetTicketTimeoutSec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PutCoinWaitTimeSec));
		len1 = sizeof(m_PutCoinWaitTimeSec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitTicketType));
		len1 = sizeof(m_PermitTicketType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_WorkModeConf));
		len1 = sizeof(m_WorkModeConf);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitCoinType));
		len1 = sizeof(m_PermitCoinType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitBillType));
		len1 = sizeof(m_PermitBillType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitCoinChgType));
		len1 = sizeof(m_PermitCoinChgType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChgMaxNum));
		len1 = sizeof(m_CoinChgMaxNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillChgMaxNum));
		len1 = sizeof(m_BillChgMaxNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PermitBillChgType));
		len1 = sizeof(m_PermitBillChgType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lChgPermitMaxAmount));
		len1 = sizeof(m_lChgPermitMaxAmount);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_FaultWorkMode));
		len1 = sizeof(m_FaultWorkMode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DeviceConfPara));
		len1 = sizeof(m_DeviceConfPara);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CurrButtonRegion));
		len1 = sizeof(m_CurrButtonRegion);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_FutureButtonRegion));
		len1 = sizeof(m_FutureButtonRegion);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ButtonEnableFlag));
		len1 = sizeof(m_ButtonEnableFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_03));
		len1 = sizeof(m_RES_03);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a3003_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
	{
		char *buf1 = p_begin;
		char *buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strTblName = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lVer = decode2<long>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strAffectDateTime = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_biDelFlag = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_biIsAffect = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strStampDateTime = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strDataRef = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BuyTicketNumLimit = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_GetTicketTimeoutSec = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PutCoinWaitTimeSec = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PermitTicketType = *(u8arr_t<20>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_WorkModeConf = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_01 = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PermitCoinType = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PermitBillType = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PermitCoinChgType = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinChgMaxNum = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BillChgMaxNum = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PermitBillChgType = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lChgPermitMaxAmount = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_02 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_FaultWorkMode = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DeviceConfPara = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CurrButtonRegion = *(u8arr_t<16>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_FutureButtonRegion = *(u8arr_t<16>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ButtonEnableFlag = *(u8arr_t<16>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_03 = *(u8arr_t<4>*)buf2;
		*pp_end = buf1;
		return *this;
	}

	 
#endif

 
public:

/////////////////////////////////////////////////////////////
//Function:	GetCol_strTblName
//Effect:	get ref of col. col is strTblName
//Return:	std::string & 
	std::string & GetCol_strTblName(void)
	{
		return m_strTblName;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_lVer
//Effect:	get ref of col. col is lVer
//Return:	long & 
	long & GetCol_lVer(void)
	{
		return m_lVer;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_strAffectDateTime
//Effect:	get ref of col. col is strAffectDateTime
//Return:	std::string & 
	std::string & GetCol_strAffectDateTime(void)
	{
		return m_strAffectDateTime;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_biDelFlag
//Effect:	get ref of col. col is biDelFlag
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_biDelFlag(void)
	{
		return m_biDelFlag;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_biIsAffect
//Effect:	get ref of col. col is biIsAffect
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_biIsAffect(void)
	{
		return m_biIsAffect;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_strStampDateTime
//Effect:	get ref of col. col is strStampDateTime
//Return:	std::string & 
	std::string & GetCol_strStampDateTime(void)
	{
		return m_strStampDateTime;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_strDataRef
//Effect:	get ref of col. col is strDataRef
//Return:	std::string & 
	std::string & GetCol_strDataRef(void)
	{
		return m_strDataRef;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_BuyTicketNumLimit
//Effect:	get ref of col. col is BuyTicketNumLimit
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_BuyTicketNumLimit(void)
	{
		return m_BuyTicketNumLimit;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_GetTicketTimeoutSec
//Effect:	get ref of col. col is GetTicketTimeoutSec
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_GetTicketTimeoutSec(void)
	{
		return m_GetTicketTimeoutSec;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_PutCoinWaitTimeSec
//Effect:	get ref of col. col is PutCoinWaitTimeSec
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_PutCoinWaitTimeSec(void)
	{
		return m_PutCoinWaitTimeSec;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_PermitTicketType
//Effect:	get ref of col. col is PermitTicketType
//Return:	u8arr_t<20> & 
	u8arr_t<20> & GetCol_PermitTicketType(void)
	{
		return m_PermitTicketType;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_WorkModeConf
//Effect:	get ref of col. col is WorkModeConf
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_WorkModeConf(void)
	{
		return m_WorkModeConf;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_PermitCoinType
//Effect:	get ref of col. col is PermitCoinType
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_PermitCoinType(void)
	{
		return m_PermitCoinType;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_PermitBillType
//Effect:	get ref of col. col is PermitBillType
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_PermitBillType(void)
	{
		return m_PermitBillType;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_PermitCoinChgType
//Effect:	get ref of col. col is PermitCoinChgType
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_PermitCoinChgType(void)
	{
		return m_PermitCoinChgType;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_CoinChgMaxNum
//Effect:	get ref of col. col is CoinChgMaxNum
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_CoinChgMaxNum(void)
	{
		return m_CoinChgMaxNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_BillChgMaxNum
//Effect:	get ref of col. col is BillChgMaxNum
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_BillChgMaxNum(void)
	{
		return m_BillChgMaxNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_PermitBillChgType
//Effect:	get ref of col. col is PermitBillChgType
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_PermitBillChgType(void)
	{
		return m_PermitBillChgType;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_lChgPermitMaxAmount
//Effect:	get ref of col. col is lChgPermitMaxAmount
//Return:	long & 
	long & GetCol_lChgPermitMaxAmount(void)
	{
		return m_lChgPermitMaxAmount;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES_02(void)
	{
		return m_RES_02;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_FaultWorkMode
//Effect:	get ref of col. col is FaultWorkMode
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_FaultWorkMode(void)
	{
		return m_FaultWorkMode;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_DeviceConfPara
//Effect:	get ref of col. col is DeviceConfPara
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_DeviceConfPara(void)
	{
		return m_DeviceConfPara;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_CurrButtonRegion
//Effect:	get ref of col. col is CurrButtonRegion
//Return:	u8arr_t<16> & 
	u8arr_t<16> & GetCol_CurrButtonRegion(void)
	{
		return m_CurrButtonRegion;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_FutureButtonRegion
//Effect:	get ref of col. col is FutureButtonRegion
//Return:	u8arr_t<16> & 
	u8arr_t<16> & GetCol_FutureButtonRegion(void)
	{
		return m_FutureButtonRegion;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_ButtonEnableFlag
//Effect:	get ref of col. col is ButtonEnableFlag
//Return:	u8arr_t<16> & 
	u8arr_t<16> & GetCol_ButtonEnableFlag(void)
	{
		return m_ButtonEnableFlag;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES_03
//Effect:	get ref of col. col is RES_03
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_RES_03(void)
	{
		return m_RES_03;
	}

 
public:

/////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 27;
	}

/////////////////////////////////////////////////////////////
//Function:	GetColName
//Effect:	get column name, input col number base on 0.
//Return:	return col's name in string format.
	std::string GetColName( int iColNum )
	{
		if( iColNum == 0 )
		{
			return "strTblName";
		}
		if( iColNum == 1 )
		{
			return "lVer";
		}
		if( iColNum == 2 )
		{
			return "strAffectDateTime";
		}
		if( iColNum == 3 )
		{
			return "biDelFlag";
		}
		if( iColNum == 4 )
		{
			return "biIsAffect";
		}
		if( iColNum == 5 )
		{
			return "strStampDateTime";
		}
		if( iColNum == 6 )
		{
			return "strDataRef";
		}
		if( iColNum == 7 )
		{
			return "BuyTicketNumLimit";
		}
		if( iColNum == 8 )
		{
			return "GetTicketTimeoutSec";
		}
		if( iColNum == 9 )
		{
			return "PutCoinWaitTimeSec";
		}
		if( iColNum == 10 )
		{
			return "PermitTicketType";
		}
		if( iColNum == 11 )
		{
			return "WorkModeConf";
		}
		if( iColNum == 12 )
		{
			return "RES_01";
		}
		if( iColNum == 13 )
		{
			return "PermitCoinType";
		}
		if( iColNum == 14 )
		{
			return "PermitBillType";
		}
		if( iColNum == 15 )
		{
			return "PermitCoinChgType";
		}
		if( iColNum == 16 )
		{
			return "CoinChgMaxNum";
		}
		if( iColNum == 17 )
		{
			return "BillChgMaxNum";
		}
		if( iColNum == 18 )
		{
			return "PermitBillChgType";
		}
		if( iColNum == 19 )
		{
			return "lChgPermitMaxAmount";
		}
		if( iColNum == 20 )
		{
			return "RES_02";
		}
		if( iColNum == 21 )
		{
			return "FaultWorkMode";
		}
		if( iColNum == 22 )
		{
			return "DeviceConfPara";
		}
		if( iColNum == 23 )
		{
			return "CurrButtonRegion";
		}
		if( iColNum == 24 )
		{
			return "FutureButtonRegion";
		}
		if( iColNum == 25 )
		{
			return "ButtonEnableFlag";
		}
		if( iColNum == 26 )
		{
			return "RES_03";
		}
		return "";
	}

////////////////////////////////////////////////////////
//Function:	GetColNumber
//Effect:	input col name, get col number
//Return:	return the column number, int.
	int GetColNumber( std::string strColName ) 
	{
		if( strColName == "strTblName" )
		{
			return 0;
		}
		if( strColName == "lVer" )
		{
			return 1;
		}
		if( strColName == "strAffectDateTime" )
		{
			return 2;
		}
		if( strColName == "biDelFlag" )
		{
			return 3;
		}
		if( strColName == "biIsAffect" )
		{
			return 4;
		}
		if( strColName == "strStampDateTime" )
		{
			return 5;
		}
		if( strColName == "strDataRef" )
		{
			return 6;
		}
		if( strColName == "BuyTicketNumLimit" )
		{
			return 7;
		}
		if( strColName == "GetTicketTimeoutSec" )
		{
			return 8;
		}
		if( strColName == "PutCoinWaitTimeSec" )
		{
			return 9;
		}
		if( strColName == "PermitTicketType" )
		{
			return 10;
		}
		if( strColName == "WorkModeConf" )
		{
			return 11;
		}
		if( strColName == "RES_01" )
		{
			return 12;
		}
		if( strColName == "PermitCoinType" )
		{
			return 13;
		}
		if( strColName == "PermitBillType" )
		{
			return 14;
		}
		if( strColName == "PermitCoinChgType" )
		{
			return 15;
		}
		if( strColName == "CoinChgMaxNum" )
		{
			return 16;
		}
		if( strColName == "BillChgMaxNum" )
		{
			return 17;
		}
		if( strColName == "PermitBillChgType" )
		{
			return 18;
		}
		if( strColName == "lChgPermitMaxAmount" )
		{
			return 19;
		}
		if( strColName == "RES_02" )
		{
			return 20;
		}
		if( strColName == "FaultWorkMode" )
		{
			return 21;
		}
		if( strColName == "DeviceConfPara" )
		{
			return 22;
		}
		if( strColName == "CurrButtonRegion" )
		{
			return 23;
		}
		if( strColName == "FutureButtonRegion" )
		{
			return 24;
		}
		if( strColName == "ButtonEnableFlag" )
		{
			return 25;
		}
		if( strColName == "RES_03" )
		{
			return 26;
		}
		return -1;
	}

//////////////////////////////////////////////////////////////
//Function:	GetColStr
//Effect:	get column value, input col number base on 0.
//Return:	return col value in string format.
	template<class STRINGT>
	STRINGT GetColStr( int iColNum )
	{
		if( iColNum == 0 )
		{
			return m_strTblName;
		}
		if( iColNum == 1 )
		{
			return wl::SStrf::sltoa(m_lVer);
		}
		if( iColNum == 2 )
		{
			return m_strAffectDateTime;
		}
		if( iColNum == 3 )
		{
			return wl::SStrf::sltoa(m_biDelFlag);
		}
		if( iColNum == 4 )
		{
			return wl::SStrf::sltoa(m_biIsAffect);
		}
		if( iColNum == 5 )
		{
			return m_strStampDateTime;
		}
		if( iColNum == 6 )
		{
			return m_strDataRef;
		}
		if( iColNum == 7 )
		{
			return wl::SStrf::sltoa(m_BuyTicketNumLimit);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_GetTicketTimeoutSec);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_PutCoinWaitTimeSec);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::b2s(m_PermitTicketType);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::b2s(m_WorkModeConf);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_RES_01);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_PermitCoinType);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::b2s(m_PermitBillType);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_PermitCoinChgType);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_CoinChgMaxNum);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_BillChgMaxNum);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::b2s(m_PermitBillChgType);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_lChgPermitMaxAmount);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_RES_02);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_FaultWorkMode);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_DeviceConfPara);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::b2s(m_CurrButtonRegion);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::b2s(m_FutureButtonRegion);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::b2s(m_ButtonEnableFlag);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::b2s(m_RES_03);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

///////////////////////////////////////////////////////////
//Function:	GetColStr
//Effect:	get column value, input col name.
//Return:	return col value in string format.
	template<class STRINGT>
	STRINGT GetColStr( std::string strColName )
	{
		if( strColName == "strTblName" )
		{
			return GetColStr<STRINGT>(0);
		}
		if( strColName == "lVer" )
		{
			return GetColStr<STRINGT>(1);
		}
		if( strColName == "strAffectDateTime" )
		{
			return GetColStr<STRINGT>(2);
		}
		if( strColName == "biDelFlag" )
		{
			return GetColStr<STRINGT>(3);
		}
		if( strColName == "biIsAffect" )
		{
			return GetColStr<STRINGT>(4);
		}
		if( strColName == "strStampDateTime" )
		{
			return GetColStr<STRINGT>(5);
		}
		if( strColName == "strDataRef" )
		{
			return GetColStr<STRINGT>(6);
		}
		if( strColName == "BuyTicketNumLimit" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "GetTicketTimeoutSec" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "PutCoinWaitTimeSec" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "PermitTicketType" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "WorkModeConf" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "PermitCoinType" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "PermitBillType" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "PermitCoinChgType" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "CoinChgMaxNum" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "BillChgMaxNum" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "PermitBillChgType" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "lChgPermitMaxAmount" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "FaultWorkMode" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "DeviceConfPara" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "CurrButtonRegion" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "FutureButtonRegion" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "ButtonEnableFlag" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "RES_03" )
		{
			return GetColStr<STRINGT>(26);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

//////////////////////////////////////////////////////////
//Function:	SetColVal
//Effect:	set column value, input col number base on 0, and input value in string format.
//Return:	no return.
	template<class STRINGT>
	void SetColVal( int iColNum, STRINGT strValPARA )
	{
		if( iColNum == 0 )
		{
			m_strTblName=strValPARA;
		}
		if( iColNum == 1 )
		{
			m_lVer=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 2 )
		{
			m_strAffectDateTime=strValPARA;
		}
		if( iColNum == 3 )
		{
			m_biDelFlag=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 4 )
		{
			m_biIsAffect=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 5 )
		{
			m_strStampDateTime=strValPARA;
		}
		if( iColNum == 6 )
		{
			m_strDataRef=strValPARA;
		}
		if( iColNum == 7 )
		{
			m_BuyTicketNumLimit=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_GetTicketTimeoutSec=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_PutCoinWaitTimeSec=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			wl::SStrf::s2b(strValPARA,m_PermitTicketType);
		}
		if( iColNum == 11 )
		{
			wl::SStrf::s2b(strValPARA,m_WorkModeConf);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_01);
		}
		if( iColNum == 13 )
		{
			m_PermitCoinType=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			wl::SStrf::s2b(strValPARA,m_PermitBillType);
		}
		if( iColNum == 15 )
		{
			m_PermitCoinChgType=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_CoinChgMaxNum=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_BillChgMaxNum=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			wl::SStrf::s2b(strValPARA,m_PermitBillChgType);
		}
		if( iColNum == 19 )
		{
			m_lChgPermitMaxAmount=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_RES_02=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_FaultWorkMode=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_DeviceConfPara);
		}
		if( iColNum == 23 )
		{
			wl::SStrf::s2b(strValPARA,m_CurrButtonRegion);
		}
		if( iColNum == 24 )
		{
			wl::SStrf::s2b(strValPARA,m_FutureButtonRegion);
		}
		if( iColNum == 25 )
		{
			wl::SStrf::s2b(strValPARA,m_ButtonEnableFlag);
		}
		if( iColNum == 26 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_03);
		}
	}

///////////////////////////////////////////////////////
//Function:	SetColVal
//Effect:	set column value, input col number base on 0, and input value in string format.
//Return:	no return.
	template<class STRINGT>
	void SetColVal( std::string strColName, STRINGT strValPARA )
	{
		if( strColName == "strTblName" )
		{
			SetColVal<STRINGT>(0,strValPARA);
		}
		if( strColName == "lVer" )
		{
			SetColVal<STRINGT>(1,strValPARA);
		}
		if( strColName == "strAffectDateTime" )
		{
			SetColVal<STRINGT>(2,strValPARA);
		}
		if( strColName == "biDelFlag" )
		{
			SetColVal<STRINGT>(3,strValPARA);
		}
		if( strColName == "biIsAffect" )
		{
			SetColVal<STRINGT>(4,strValPARA);
		}
		if( strColName == "strStampDateTime" )
		{
			SetColVal<STRINGT>(5,strValPARA);
		}
		if( strColName == "strDataRef" )
		{
			SetColVal<STRINGT>(6,strValPARA);
		}
		if( strColName == "BuyTicketNumLimit" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "GetTicketTimeoutSec" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "PutCoinWaitTimeSec" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "PermitTicketType" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "WorkModeConf" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "PermitCoinType" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "PermitBillType" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "PermitCoinChgType" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "CoinChgMaxNum" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "BillChgMaxNum" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "PermitBillChgType" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "lChgPermitMaxAmount" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "FaultWorkMode" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "DeviceConfPara" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "CurrButtonRegion" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "FutureButtonRegion" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "ButtonEnableFlag" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "RES_03" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
	}

}
; 
//end of class a3003_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a3003_t
class a3003_t {
 
private:

	a3003_t_rowtype m_EmptyRow;
	std::vector<a3003_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a3003_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a3003_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a3003_t()
	{
	}

	virtual ~a3003_t(){;}
	

	//operator == 
	bool operator == (const a3003_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3003_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3003_t & rhs) const
	{
		return this < &rhs;
	}

 
public:

	//serialize unserialize

	std::string &  Serialize( std::string & strOut )	
	{
		strOut = "";
		for(long i=0;i<(long)GetRowCount();i++)
		{
			std::string strTmp;
			GetRow(i).Serialize(strTmp);
			strOut += strTmp + "}";
		}
		return strOut;
	}

	std::string Serialize()
	{
		std::string strOut;
		return this->Serialize(strOut);
	}

	a3003_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
	{
		char *p1,*p2;
		p1 = (char*)strIn;
		if(biAppend==0) Clear();
		do
		{
			p2 = p1;
			if(!*p2) return *this;
			ROWTYPE row;
			while( !( *p2=='}' ) && *p2 ) p2++;
			row.Unserialize( p1 );
			Add(row);
			p1=p2+1;
		}while(*p2);
		return *this;
	}

	 
#ifdef X014FASTSERI_

	wl::SCake & Serialize( wl::SCake & ckOut )
	{
		wl::SCakel ckl;
		ckOut.redim(0);
		for(long i=0;i<(long)GetRowCount();i++)
		{
			wl::SCake ck;
			GetRow(i).Serialize(ck);
			ckl.add(ck);
		}
		ckl.collectb(&ckOut);
		return ckOut;
	}

	a3003_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
	{
		char *p1,*p2;
		p1 = p2 = (char*)ckIn.buf();
		if(biAppend==0) Clear();
		do 
		{
			p1 = p2;
			ROWTYPE row;
			row.Unserialize( p1, &p2 );
			Add(row);
			if( p2 >= ckIn.buf() + ckIn.len() ) break;
		}while(1);
		return *this;
	}

	 
#endif

 
public:

///////////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

///////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl according to RPS
//Return:	long
	long GetRowCount(const std::vector<long> & vRps)
	{
		return (long)vRps.size();
	}

//////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a3003_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a3003_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
		}
		ltmp = lRowNum;
		if(ltmp<0) return m_EmptyRow;
		if(ltmp>=(long)vRps.size()) return m_EmptyRow;
		ltmp = vRps[lRowNum];
		if(ltmp<0) return m_EmptyRow;
		if(ltmp>=(long)m_DATAcorpora.size()) return m_EmptyRow;
		return m_DATAcorpora[ltmp];
		}while(0);
	}

//////////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a3003_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

/////////////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

/////////////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a3003_t * p = new a3003_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

////////////////////////////////////////////////////////
//Function:	SelE_strTblName
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strTblName==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_strTblName
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTblName(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_lVer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lVer(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_strAffectDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strAffectDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_strAffectDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strAffectDateTime(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_BuyTicketNumLimit
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BuyTicketNumLimit(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BuyTicketNumLimit==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_BuyTicketNumLimit
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_BuyTicketNumLimit(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_BuyTicketNumLimit( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_BuyTicketNumLimit
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BuyTicketNumLimit(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BuyTicketNumLimit(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_GetTicketTimeoutSec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_GetTicketTimeoutSec(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_GetTicketTimeoutSec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_GetTicketTimeoutSec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_GetTicketTimeoutSec(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_GetTicketTimeoutSec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_GetTicketTimeoutSec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_GetTicketTimeoutSec(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_GetTicketTimeoutSec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_PutCoinWaitTimeSec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PutCoinWaitTimeSec(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PutCoinWaitTimeSec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_PutCoinWaitTimeSec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PutCoinWaitTimeSec(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_PutCoinWaitTimeSec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_PutCoinWaitTimeSec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PutCoinWaitTimeSec(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PutCoinWaitTimeSec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_PermitTicketType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PermitTicketType(u8arr_t<20> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PermitTicketType==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_PermitTicketType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PermitTicketType(u8arr_t<20> aVal) 
	{
		std::vector<long> vRps ;
		SelE_PermitTicketType( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_PermitTicketType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PermitTicketType(u8arr_t<20> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PermitTicketType(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_WorkModeConf
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_WorkModeConf(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_WorkModeConf==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_WorkModeConf
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_WorkModeConf(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_WorkModeConf( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_WorkModeConf
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_WorkModeConf(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_WorkModeConf(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_RES_01(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES_01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_01(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_01(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_PermitCoinType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PermitCoinType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PermitCoinType==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_PermitCoinType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PermitCoinType(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_PermitCoinType( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_PermitCoinType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PermitCoinType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PermitCoinType(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_PermitBillType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PermitBillType(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PermitBillType==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_PermitBillType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PermitBillType(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_PermitBillType( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_PermitBillType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PermitBillType(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PermitBillType(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_PermitCoinChgType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PermitCoinChgType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PermitCoinChgType==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_PermitCoinChgType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PermitCoinChgType(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_PermitCoinChgType( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_PermitCoinChgType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PermitCoinChgType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PermitCoinChgType(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_CoinChgMaxNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinChgMaxNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinChgMaxNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CoinChgMaxNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_CoinChgMaxNum(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinChgMaxNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_CoinChgMaxNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinChgMaxNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinChgMaxNum(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_BillChgMaxNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BillChgMaxNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BillChgMaxNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_BillChgMaxNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_BillChgMaxNum(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_BillChgMaxNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_BillChgMaxNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BillChgMaxNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BillChgMaxNum(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_PermitBillChgType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PermitBillChgType(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PermitBillChgType==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_PermitBillChgType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_PermitBillChgType(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_PermitBillChgType( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_PermitBillChgType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PermitBillChgType(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PermitBillChgType(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lChgPermitMaxAmount
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lChgPermitMaxAmount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lChgPermitMaxAmount==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_lChgPermitMaxAmount
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_lChgPermitMaxAmount(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lChgPermitMaxAmount( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_lChgPermitMaxAmount
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lChgPermitMaxAmount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lChgPermitMaxAmount(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RES_02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_02(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_02==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_RES_02(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_FaultWorkMode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_FaultWorkMode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_FaultWorkMode==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_FaultWorkMode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_FaultWorkMode(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_FaultWorkMode( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_FaultWorkMode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_FaultWorkMode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_FaultWorkMode(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_DeviceConfPara
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DeviceConfPara(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DeviceConfPara==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_DeviceConfPara
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_DeviceConfPara(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_DeviceConfPara( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_DeviceConfPara
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DeviceConfPara(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DeviceConfPara(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_CurrButtonRegion
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CurrButtonRegion(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CurrButtonRegion==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CurrButtonRegion
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_CurrButtonRegion(u8arr_t<16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CurrButtonRegion( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_CurrButtonRegion
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CurrButtonRegion(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CurrButtonRegion(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_FutureButtonRegion
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_FutureButtonRegion(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_FutureButtonRegion==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_FutureButtonRegion
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_FutureButtonRegion(u8arr_t<16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_FutureButtonRegion( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_FutureButtonRegion
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_FutureButtonRegion(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_FutureButtonRegion(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_ButtonEnableFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ButtonEnableFlag(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ButtonEnableFlag==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_ButtonEnableFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_ButtonEnableFlag(u8arr_t<16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ButtonEnableFlag( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_ButtonEnableFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ButtonEnableFlag(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ButtonEnableFlag(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES_03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_03(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_03==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES_03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3003_t_rowtype&
	a3003_t_rowtype & SelE1_RES_03(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_03( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_RES_03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_03(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_03(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	RpsAnd
//Effect:	set intersection for RPSs. the varRpsSource1 is also the result.
//Return:	RPSTYPE &
	RPSTYPE & RpsAnd( RPSTYPE & varRpsSource1, RPSTYPE & varRpsSource2 )
	{
		std::sort( varRpsSource1.begin(), varRpsSource1.end() );
		std::sort( varRpsSource2.begin(), varRpsSource2.end() );
		RPSTYPE source3(varRpsSource1.size()+varRpsSource2.size());
		RPSTYPE::iterator itNewEnd2 = std::set_intersection( 
		 varRpsSource1.begin(), varRpsSource1.end(), varRpsSource2.begin(), varRpsSource2.end(), source3.begin() );
		varRpsSource1.clear();
		for(RPSTYPE::iterator it=source3.begin();it!=itNewEnd2;++it) varRpsSource1.push_back(*it);
		return varRpsSource1;
	}

////////////////////////////////////////////////////////////
//Function:	RpsAnd
//Effect:	set intersection for RPSs. the rps3 is the result. sortflag: 10=rps1 sorted. 01=rps2 sorted.
//Return:	RPSTYPE &
	RPSTYPE & RpsAnd( RPSTYPE & varRpsSource1, RPSTYPE & varRpsSource2, RPSTYPE & vRps3, int sort_flag = 0 )
	{
		if( (sort_flag & 2 ) == 0 ) std::sort( varRpsSource1.begin(), varRpsSource1.end() );
		if( (sort_flag & 1 ) == 0 ) std::sort( varRpsSource2.begin(), varRpsSource2.end() ); 
		vRps3.clear();
		std::set_intersection( 
		 varRpsSource1.begin(), varRpsSource1.end(), varRpsSource2.begin(), varRpsSource2.end(), std::insert_iterator<RPSTYPE>(vRps3,vRps3.begin()) );
		return vRps3;
	}

////////////////////////////////////////////////////////
//Function:	RpsOr
//Effect:	set union for RPSs. the varRpsSource1 is also the result.
//Return:	RPSTYPE &
	RPSTYPE & RpsOr( RPSTYPE & varRpsSource1, RPSTYPE & varRpsSource2 )
	{
		std::sort( varRpsSource1.begin(), varRpsSource1.end() );
		std::sort( varRpsSource2.begin(), varRpsSource2.end() );
		RPSTYPE source3(varRpsSource1.size()+varRpsSource2.size());
		RPSTYPE::iterator itNewEnd2 = std::set_union( 
		 varRpsSource1.begin(), varRpsSource1.end(), varRpsSource2.begin(), varRpsSource2.end(), source3.begin() );
		varRpsSource1.clear();
		for(RPSTYPE::iterator it=source3.begin();it!=itNewEnd2;++it) varRpsSource1.push_back(*it);
		return varRpsSource1;
	}

 
}
; 
//end of class a3003_t


#endif

