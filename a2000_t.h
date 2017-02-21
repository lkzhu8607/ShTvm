
#ifndef V1_3AA2000_T_20170220_172617
#define V1_3AA2000_T_20170220_172617

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a2000_t
//Name:	a2000_t_rowtype
class a2000_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		a2000 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	//#.字段													说明	类型	长度
	wl::tuint8		m_ReSendBeforeWaitTime;			// 8	重发前等待时间	Byte	1 
	wl::tuint8		m_ReSendNum;			// 9	重发次数	Byte	1 
	wl::tuint8		m_WaitConnTime;			// 10	等待建立连接的时间	Byte	1 
	wl::tuint8		m_NoResponseNum;			// 11	未应答的交互数	Byte	1 
	std::string		m_ParaVerCheckOrSyncTime;			// 12	参数版本检查/同步时间	N	4 
	std::string		m_YunYingEndTime;			// 13	运营日结束时间	N	4 
	wl::tuint8		m_ParaWaitTime;			// 14	参数表等待时间	Byte	1 
	wl::tuint8		m_ResponseTimeoutTime;			// 15	应答超时时间	Byte	1 
	u8arr_t<4>		m_HostScIpAddr;			// 16	主服务器IP地址	Long	4 
	u8arr_t<4>		m_BackUpScIpAddr;			// 17	备服务器IP地址	Long	4 
	wl::tuint16		m_Rule1ScPort;			// 18	规程1服务端口	Word	2 
	wl::tuint16		m_Rule2ScPort;			// 19	规程2服务端口	Word	2 
	wl::tuint16		m_Rule3ScPort;			// 20	规程3服务端口	Word	2 
	wl::tuint16		m_Rule4ScPort;			// 21	规程4服务端口	Word	2 
	wl::tuint8		m_RES01;			// a	22	[保留] 
	u8arr_t<2>		m_RES02;			// a	23	[保留] 
	wl::tuint8		m_RES03;			// a	24	[保留] 
 
public:

	a2000_t_rowtype()
	{
		m_strTblName = "a2000";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_ReSendBeforeWaitTime = 0;
		m_ReSendNum = 0;
		m_WaitConnTime = 0;
		m_NoResponseNum = 0;
		m_ParaVerCheckOrSyncTime = "";
		m_YunYingEndTime = "";
		m_ParaWaitTime = 0;
		m_ResponseTimeoutTime = 0;
		//m_HostScIpAddr = //use default
		//m_BackUpScIpAddr = //use default
		m_Rule1ScPort = 0;
		m_Rule2ScPort = 0;
		m_Rule3ScPort = 0;
		m_Rule4ScPort = 0;
		m_RES01 = 0;
		//m_RES02 = //use default
		m_RES03 = 0;
	}

	virtual ~a2000_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a2000_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a2000_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a2000_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReSendBeforeWaitTime));
		len1 = sizeof(m_ReSendBeforeWaitTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReSendNum));
		len1 = sizeof(m_ReSendNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_WaitConnTime));
		len1 = sizeof(m_WaitConnTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_NoResponseNum));
		len1 = sizeof(m_NoResponseNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_ParaVerCheckOrSyncTime.c_str();
		len1 = (long)(m_ParaVerCheckOrSyncTime.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_YunYingEndTime.c_str();
		len1 = (long)(m_YunYingEndTime.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ParaWaitTime));
		len1 = sizeof(m_ParaWaitTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ResponseTimeoutTime));
		len1 = sizeof(m_ResponseTimeoutTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_HostScIpAddr));
		len1 = sizeof(m_HostScIpAddr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BackUpScIpAddr));
		len1 = sizeof(m_BackUpScIpAddr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule1ScPort));
		len1 = sizeof(m_Rule1ScPort);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule2ScPort));
		len1 = sizeof(m_Rule2ScPort);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule3ScPort));
		len1 = sizeof(m_Rule3ScPort);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule4ScPort));
		len1 = sizeof(m_Rule4ScPort);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01));
		len1 = sizeof(m_RES01);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES02));
		len1 = sizeof(m_RES02);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES03));
		len1 = sizeof(m_RES03);
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

	a2000_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_ReSendBeforeWaitTime = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReSendNum = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_WaitConnTime = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_NoResponseNum = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ParaVerCheckOrSyncTime = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_YunYingEndTime = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ParaWaitTime = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ResponseTimeoutTime = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_HostScIpAddr = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BackUpScIpAddr = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Rule1ScPort = *(wl::tuint16*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Rule2ScPort = *(wl::tuint16*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Rule3ScPort = *(wl::tuint16*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Rule4ScPort = *(wl::tuint16*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES02 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES03 = *(wl::tuint8*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReSendBeforeWaitTime));
		len1 = sizeof(m_ReSendBeforeWaitTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReSendNum));
		len1 = sizeof(m_ReSendNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_WaitConnTime));
		len1 = sizeof(m_WaitConnTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_NoResponseNum));
		len1 = sizeof(m_NoResponseNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_ParaVerCheckOrSyncTime.c_str();
		len1 = (long)(m_ParaVerCheckOrSyncTime.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_YunYingEndTime.c_str();
		len1 = (long)(m_YunYingEndTime.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ParaWaitTime));
		len1 = sizeof(m_ParaWaitTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ResponseTimeoutTime));
		len1 = sizeof(m_ResponseTimeoutTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_HostScIpAddr));
		len1 = sizeof(m_HostScIpAddr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BackUpScIpAddr));
		len1 = sizeof(m_BackUpScIpAddr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule1ScPort));
		len1 = sizeof(m_Rule1ScPort);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule2ScPort));
		len1 = sizeof(m_Rule2ScPort);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule3ScPort));
		len1 = sizeof(m_Rule3ScPort);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Rule4ScPort));
		len1 = sizeof(m_Rule4ScPort);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01));
		len1 = sizeof(m_RES01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES02));
		len1 = sizeof(m_RES02);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES03));
		len1 = sizeof(m_RES03);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a2000_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_ReSendBeforeWaitTime = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReSendNum = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_WaitConnTime = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_NoResponseNum = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ParaVerCheckOrSyncTime = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_YunYingEndTime = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ParaWaitTime = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ResponseTimeoutTime = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_HostScIpAddr = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BackUpScIpAddr = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Rule1ScPort = *(wl::tuint16*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Rule2ScPort = *(wl::tuint16*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Rule3ScPort = *(wl::tuint16*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Rule4ScPort = *(wl::tuint16*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES02 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES03 = *(wl::tuint8*)buf2;
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
//Function:	GetCol_ReSendBeforeWaitTime
//Effect:	get ref of col. col is ReSendBeforeWaitTime
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_ReSendBeforeWaitTime(void)
	{
		return m_ReSendBeforeWaitTime;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_ReSendNum
//Effect:	get ref of col. col is ReSendNum
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_ReSendNum(void)
	{
		return m_ReSendNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_WaitConnTime
//Effect:	get ref of col. col is WaitConnTime
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_WaitConnTime(void)
	{
		return m_WaitConnTime;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_NoResponseNum
//Effect:	get ref of col. col is NoResponseNum
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_NoResponseNum(void)
	{
		return m_NoResponseNum;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_ParaVerCheckOrSyncTime
//Effect:	get ref of col. col is ParaVerCheckOrSyncTime
//Return:	std::string & 
	std::string & GetCol_ParaVerCheckOrSyncTime(void)
	{
		return m_ParaVerCheckOrSyncTime;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_YunYingEndTime
//Effect:	get ref of col. col is YunYingEndTime
//Return:	std::string & 
	std::string & GetCol_YunYingEndTime(void)
	{
		return m_YunYingEndTime;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_ParaWaitTime
//Effect:	get ref of col. col is ParaWaitTime
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_ParaWaitTime(void)
	{
		return m_ParaWaitTime;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_ResponseTimeoutTime
//Effect:	get ref of col. col is ResponseTimeoutTime
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_ResponseTimeoutTime(void)
	{
		return m_ResponseTimeoutTime;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_HostScIpAddr
//Effect:	get ref of col. col is HostScIpAddr
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_HostScIpAddr(void)
	{
		return m_HostScIpAddr;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_BackUpScIpAddr
//Effect:	get ref of col. col is BackUpScIpAddr
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_BackUpScIpAddr(void)
	{
		return m_BackUpScIpAddr;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Rule1ScPort
//Effect:	get ref of col. col is Rule1ScPort
//Return:	wl::tuint16 & 
	wl::tuint16 & GetCol_Rule1ScPort(void)
	{
		return m_Rule1ScPort;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Rule2ScPort
//Effect:	get ref of col. col is Rule2ScPort
//Return:	wl::tuint16 & 
	wl::tuint16 & GetCol_Rule2ScPort(void)
	{
		return m_Rule2ScPort;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_Rule3ScPort
//Effect:	get ref of col. col is Rule3ScPort
//Return:	wl::tuint16 & 
	wl::tuint16 & GetCol_Rule3ScPort(void)
	{
		return m_Rule3ScPort;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_Rule4ScPort
//Effect:	get ref of col. col is Rule4ScPort
//Return:	wl::tuint16 & 
	wl::tuint16 & GetCol_Rule4ScPort(void)
	{
		return m_Rule4ScPort;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES01
//Effect:	get ref of col. col is RES01
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01(void)
	{
		return m_RES01;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES02
//Effect:	get ref of col. col is RES02
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES02(void)
	{
		return m_RES02;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES03
//Effect:	get ref of col. col is RES03
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES03(void)
	{
		return m_RES03;
	}

 
public:

///////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 24;
	}

////////////////////////////////////////////////////////////
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
			return "ReSendBeforeWaitTime";
		}
		if( iColNum == 8 )
		{
			return "ReSendNum";
		}
		if( iColNum == 9 )
		{
			return "WaitConnTime";
		}
		if( iColNum == 10 )
		{
			return "NoResponseNum";
		}
		if( iColNum == 11 )
		{
			return "ParaVerCheckOrSyncTime";
		}
		if( iColNum == 12 )
		{
			return "YunYingEndTime";
		}
		if( iColNum == 13 )
		{
			return "ParaWaitTime";
		}
		if( iColNum == 14 )
		{
			return "ResponseTimeoutTime";
		}
		if( iColNum == 15 )
		{
			return "HostScIpAddr";
		}
		if( iColNum == 16 )
		{
			return "BackUpScIpAddr";
		}
		if( iColNum == 17 )
		{
			return "Rule1ScPort";
		}
		if( iColNum == 18 )
		{
			return "Rule2ScPort";
		}
		if( iColNum == 19 )
		{
			return "Rule3ScPort";
		}
		if( iColNum == 20 )
		{
			return "Rule4ScPort";
		}
		if( iColNum == 21 )
		{
			return "RES01";
		}
		if( iColNum == 22 )
		{
			return "RES02";
		}
		if( iColNum == 23 )
		{
			return "RES03";
		}
		return "";
	}

/////////////////////////////////////////////////////////////
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
		if( strColName == "ReSendBeforeWaitTime" )
		{
			return 7;
		}
		if( strColName == "ReSendNum" )
		{
			return 8;
		}
		if( strColName == "WaitConnTime" )
		{
			return 9;
		}
		if( strColName == "NoResponseNum" )
		{
			return 10;
		}
		if( strColName == "ParaVerCheckOrSyncTime" )
		{
			return 11;
		}
		if( strColName == "YunYingEndTime" )
		{
			return 12;
		}
		if( strColName == "ParaWaitTime" )
		{
			return 13;
		}
		if( strColName == "ResponseTimeoutTime" )
		{
			return 14;
		}
		if( strColName == "HostScIpAddr" )
		{
			return 15;
		}
		if( strColName == "BackUpScIpAddr" )
		{
			return 16;
		}
		if( strColName == "Rule1ScPort" )
		{
			return 17;
		}
		if( strColName == "Rule2ScPort" )
		{
			return 18;
		}
		if( strColName == "Rule3ScPort" )
		{
			return 19;
		}
		if( strColName == "Rule4ScPort" )
		{
			return 20;
		}
		if( strColName == "RES01" )
		{
			return 21;
		}
		if( strColName == "RES02" )
		{
			return 22;
		}
		if( strColName == "RES03" )
		{
			return 23;
		}
		return -1;
	}

/////////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_ReSendBeforeWaitTime);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_ReSendNum);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_WaitConnTime);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_NoResponseNum);
		}
		if( iColNum == 11 )
		{
			return m_ParaVerCheckOrSyncTime;
		}
		if( iColNum == 12 )
		{
			return m_YunYingEndTime;
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_ParaWaitTime);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_ResponseTimeoutTime);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::b2s(m_HostScIpAddr);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::b2s(m_BackUpScIpAddr);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_Rule1ScPort);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_Rule2ScPort);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_Rule3ScPort);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_Rule4ScPort);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_RES01);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_RES02);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_RES03);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

/////////////////////////////////////////////////////////////
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
		if( strColName == "ReSendBeforeWaitTime" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "ReSendNum" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "WaitConnTime" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "NoResponseNum" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "ParaVerCheckOrSyncTime" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "YunYingEndTime" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "ParaWaitTime" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "ResponseTimeoutTime" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "HostScIpAddr" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "BackUpScIpAddr" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "Rule1ScPort" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "Rule2ScPort" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "Rule3ScPort" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "Rule4ScPort" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "RES01" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "RES02" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "RES03" )
		{
			return GetColStr<STRINGT>(23);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

////////////////////////////////////////////////////////
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
			m_ReSendBeforeWaitTime=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_ReSendNum=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_WaitConnTime=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_NoResponseNum=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_ParaVerCheckOrSyncTime=strValPARA;
		}
		if( iColNum == 12 )
		{
			m_YunYingEndTime=strValPARA;
		}
		if( iColNum == 13 )
		{
			m_ParaWaitTime=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_ResponseTimeoutTime=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			wl::SStrf::s2b(strValPARA,m_HostScIpAddr);
		}
		if( iColNum == 16 )
		{
			wl::SStrf::s2b(strValPARA,m_BackUpScIpAddr);
		}
		if( iColNum == 17 )
		{
			m_Rule1ScPort=(wl::tuint16)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_Rule2ScPort=(wl::tuint16)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_Rule3ScPort=(wl::tuint16)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_Rule4ScPort=(wl::tuint16)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_RES01=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_RES02);
		}
		if( iColNum == 23 )
		{
			m_RES03=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
	}

//////////////////////////////////////////////////////////////
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
		if( strColName == "ReSendBeforeWaitTime" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "ReSendNum" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "WaitConnTime" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "NoResponseNum" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "ParaVerCheckOrSyncTime" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "YunYingEndTime" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "ParaWaitTime" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "ResponseTimeoutTime" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "HostScIpAddr" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "BackUpScIpAddr" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "Rule1ScPort" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "Rule2ScPort" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "Rule3ScPort" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "Rule4ScPort" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "RES01" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "RES02" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "RES03" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
	}

}
; 
//end of class a2000_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a2000_t
class a2000_t {
 
private:

	a2000_t_rowtype m_EmptyRow;
	std::vector<a2000_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a2000_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a2000_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a2000_t()
	{
	}

	virtual ~a2000_t(){;}
	

	//operator == 
	bool operator == (const a2000_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a2000_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a2000_t & rhs) const
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

	a2000_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a2000_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

//////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

///////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

/////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl according to RPS
//Return:	long
	long GetRowCount(const std::vector<long> & vRps)
	{
		return (long)vRps.size();
	}

///////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a2000_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

///////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a2000_t_rowtype tmpEmptyrow;
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

////////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes, if any.
//Return:	no return
	void Add(const a2000_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

//////////////////////////////////////////////////////////
//Function:	AddDefaultRow
//Effect:	add one default row using Add function.
//Return:	no return
	void AddDefaultRow()
	{
		Add( a2000_t_rowtype());
	}

////////////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

//////////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

/////////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a2000_t * p = new a2000_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

/////////////////////////////////////////////////////////////////
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
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_strTblName
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTblName(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
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
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lVer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lVer(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_strAffectDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strAffectDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_strAffectDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strAffectDateTime(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_ReSendBeforeWaitTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReSendBeforeWaitTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReSendBeforeWaitTime==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_ReSendBeforeWaitTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_ReSendBeforeWaitTime(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_ReSendBeforeWaitTime( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_ReSendBeforeWaitTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReSendBeforeWaitTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReSendBeforeWaitTime(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_ReSendNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReSendNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReSendNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_ReSendNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_ReSendNum(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_ReSendNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_ReSendNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReSendNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReSendNum(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_WaitConnTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_WaitConnTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_WaitConnTime==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_WaitConnTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_WaitConnTime(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_WaitConnTime( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_WaitConnTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_WaitConnTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_WaitConnTime(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_NoResponseNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_NoResponseNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_NoResponseNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_NoResponseNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_NoResponseNum(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_NoResponseNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_NoResponseNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_NoResponseNum(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_NoResponseNum(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_ParaVerCheckOrSyncTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ParaVerCheckOrSyncTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ParaVerCheckOrSyncTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_ParaVerCheckOrSyncTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_ParaVerCheckOrSyncTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_ParaVerCheckOrSyncTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_ParaVerCheckOrSyncTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ParaVerCheckOrSyncTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ParaVerCheckOrSyncTime(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_YunYingEndTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_YunYingEndTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_YunYingEndTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_YunYingEndTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_YunYingEndTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_YunYingEndTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_YunYingEndTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_YunYingEndTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_YunYingEndTime(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_ParaWaitTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ParaWaitTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ParaWaitTime==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_ParaWaitTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_ParaWaitTime(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_ParaWaitTime( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ParaWaitTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ParaWaitTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ParaWaitTime(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_ResponseTimeoutTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ResponseTimeoutTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ResponseTimeoutTime==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_ResponseTimeoutTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_ResponseTimeoutTime(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_ResponseTimeoutTime( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_ResponseTimeoutTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ResponseTimeoutTime(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ResponseTimeoutTime(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_HostScIpAddr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_HostScIpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_HostScIpAddr==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_HostScIpAddr
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_HostScIpAddr(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_HostScIpAddr( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_HostScIpAddr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_HostScIpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_HostScIpAddr(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_BackUpScIpAddr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BackUpScIpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BackUpScIpAddr==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_BackUpScIpAddr
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_BackUpScIpAddr(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_BackUpScIpAddr( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_BackUpScIpAddr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BackUpScIpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BackUpScIpAddr(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_Rule1ScPort
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Rule1ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Rule1ScPort==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_Rule1ScPort
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_Rule1ScPort(wl::tuint16 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Rule1ScPort( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_Rule1ScPort
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Rule1ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Rule1ScPort(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_Rule2ScPort
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Rule2ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Rule2ScPort==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_Rule2ScPort
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_Rule2ScPort(wl::tuint16 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Rule2ScPort( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_Rule2ScPort
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Rule2ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Rule2ScPort(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_Rule3ScPort
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Rule3ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Rule3ScPort==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_Rule3ScPort
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_Rule3ScPort(wl::tuint16 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Rule3ScPort( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_Rule3ScPort
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Rule3ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Rule3ScPort(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_Rule4ScPort
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Rule4ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Rule4ScPort==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_Rule4ScPort
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_Rule4ScPort(wl::tuint16 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Rule4ScPort( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_Rule4ScPort
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Rule4ScPort(wl::tuint16 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Rule4ScPort(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_RES01(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_RES01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_RES02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES02(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES02==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_RES02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_RES02(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES02( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_RES02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES02(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES02(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES03==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a2000_t_rowtype&
	a2000_t_rowtype & SelE1_RES03(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES03( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES03(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////
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
//end of class a2000_t


#endif

