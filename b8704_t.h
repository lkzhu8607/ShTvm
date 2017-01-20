
#ifndef V1_3AB8704_T_20141020_160435
#define V1_3AB8704_T_20141020_160435

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of b8704_t
//Name:	b8704_t_rowtype
class b8704_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		读写器1-b8704 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	int		m_ConnState;			// a	1	机器 1=联接 0=失联 
	int		m_RtnVal;			// a	2	调用的返回值 
	int		m_BigErr;			// a	3	大出错，人工干预 
	wl::tuint8		m_Major;			// a	4	主版本号 
	wl::tuint8		m_Minor;			// a	5	副版本号 
	u8arr_t<3>		m_ResetOut;			// a	6	2.3. 读写器复位 
	u8arr_t<4>		m_DoubleCardSam;			// a	7	交通卡SAM卡号 
	u8arr_t<4>		m_SingleCardSam;			// a	8	单程票SAM卡号 
	wl::tuint8		m_InitOut;			// a	9	读写器的工作状态 
	u8arr_t<28>		m_ReadOut;			// a	10	2.5. 读卡 
	u8arr_t<8>		m_SaleOut;			// a	11	2.6. 售卡 
	long		m_SeriesBad;			// a	12	连续写失败数 最好不大于3 
	long		m_GoodTotal;			// a	13	读写成功的卡的数量 
	long		m_BadTotal;			// a	14	读写失败卡的数量 
	double		m_GoodMoneyTotal;			// a	15	写入总钱数（元） 
	int		m_RES_01;			// a	16	[保留] 
	int		m_RES_02;			// a	17	[保留] 
 
public:

	b8704_t_rowtype()
	{
		m_strTblName = "b8704";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_ConnState = 0;
		m_RtnVal = 0;
		m_BigErr = 0;
		m_Major = 0;
		m_Minor = 0;
		//m_ResetOut = //use default
		//m_DoubleCardSam = //use default
		//m_SingleCardSam = //use default
		m_InitOut = 0;
		//m_ReadOut = //use default
		//m_SaleOut = //use default
		m_SeriesBad = 0;
		m_GoodTotal = 0;
		m_BadTotal = 0;
		m_GoodMoneyTotal = 0;
		m_RES_01 = 0;
		m_RES_02 = 0;
	}

	virtual ~b8704_t_rowtype(){;}
	

	//operator == 
	bool operator == (const b8704_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8704_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8704_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnState));
		len1 = sizeof(m_ConnState);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RtnVal));
		len1 = sizeof(m_RtnVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BigErr));
		len1 = sizeof(m_BigErr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Major));
		len1 = sizeof(m_Major);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Minor));
		len1 = sizeof(m_Minor);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ResetOut));
		len1 = sizeof(m_ResetOut);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DoubleCardSam));
		len1 = sizeof(m_DoubleCardSam);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SingleCardSam));
		len1 = sizeof(m_SingleCardSam);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InitOut));
		len1 = sizeof(m_InitOut);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReadOut));
		len1 = sizeof(m_ReadOut);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SaleOut));
		len1 = sizeof(m_SaleOut);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SeriesBad));
		len1 = sizeof(m_SeriesBad);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GoodTotal));
		len1 = sizeof(m_GoodTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BadTotal));
		len1 = sizeof(m_BadTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GoodMoneyTotal));
		len1 = sizeof(m_GoodMoneyTotal);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
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

	b8704_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_ConnState = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RtnVal = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BigErr = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Major = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Minor = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ResetOut = *(u8arr_t<3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DoubleCardSam = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SingleCardSam = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_InitOut = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReadOut = *(u8arr_t<28>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SaleOut = *(u8arr_t<8>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SeriesBad = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_GoodTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BadTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_GoodMoneyTotal = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_01 = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_02 = *(int*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnState));
		len1 = sizeof(m_ConnState);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RtnVal));
		len1 = sizeof(m_RtnVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BigErr));
		len1 = sizeof(m_BigErr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Major));
		len1 = sizeof(m_Major);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Minor));
		len1 = sizeof(m_Minor);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ResetOut));
		len1 = sizeof(m_ResetOut);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DoubleCardSam));
		len1 = sizeof(m_DoubleCardSam);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SingleCardSam));
		len1 = sizeof(m_SingleCardSam);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InitOut));
		len1 = sizeof(m_InitOut);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReadOut));
		len1 = sizeof(m_ReadOut);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SaleOut));
		len1 = sizeof(m_SaleOut);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SeriesBad));
		len1 = sizeof(m_SeriesBad);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GoodTotal));
		len1 = sizeof(m_GoodTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BadTotal));
		len1 = sizeof(m_BadTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_GoodMoneyTotal));
		len1 = sizeof(m_GoodMoneyTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	b8704_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_ConnState = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RtnVal = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BigErr = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Major = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Minor = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ResetOut = *(u8arr_t<3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DoubleCardSam = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SingleCardSam = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_InitOut = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReadOut = *(u8arr_t<28>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SaleOut = *(u8arr_t<8>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SeriesBad = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_GoodTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BadTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_GoodMoneyTotal = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_01 = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_02 = *(int*)buf2;
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
//Function:	GetCol_ConnState
//Effect:	get ref of col. col is ConnState
//Return:	int & 
	int & GetCol_ConnState(void)
	{
		return m_ConnState;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_RtnVal
//Effect:	get ref of col. col is RtnVal
//Return:	int & 
	int & GetCol_RtnVal(void)
	{
		return m_RtnVal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_BigErr
//Effect:	get ref of col. col is BigErr
//Return:	int & 
	int & GetCol_BigErr(void)
	{
		return m_BigErr;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_Major
//Effect:	get ref of col. col is Major
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Major(void)
	{
		return m_Major;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_Minor
//Effect:	get ref of col. col is Minor
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Minor(void)
	{
		return m_Minor;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_ResetOut
//Effect:	get ref of col. col is ResetOut
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_ResetOut(void)
	{
		return m_ResetOut;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_DoubleCardSam
//Effect:	get ref of col. col is DoubleCardSam
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_DoubleCardSam(void)
	{
		return m_DoubleCardSam;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_SingleCardSam
//Effect:	get ref of col. col is SingleCardSam
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_SingleCardSam(void)
	{
		return m_SingleCardSam;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_InitOut
//Effect:	get ref of col. col is InitOut
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_InitOut(void)
	{
		return m_InitOut;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_ReadOut
//Effect:	get ref of col. col is ReadOut
//Return:	u8arr_t<28> & 
	u8arr_t<28> & GetCol_ReadOut(void)
	{
		return m_ReadOut;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SaleOut
//Effect:	get ref of col. col is SaleOut
//Return:	u8arr_t<8> & 
	u8arr_t<8> & GetCol_SaleOut(void)
	{
		return m_SaleOut;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SeriesBad
//Effect:	get ref of col. col is SeriesBad
//Return:	long & 
	long & GetCol_SeriesBad(void)
	{
		return m_SeriesBad;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_GoodTotal
//Effect:	get ref of col. col is GoodTotal
//Return:	long & 
	long & GetCol_GoodTotal(void)
	{
		return m_GoodTotal;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_BadTotal
//Effect:	get ref of col. col is BadTotal
//Return:	long & 
	long & GetCol_BadTotal(void)
	{
		return m_BadTotal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_GoodMoneyTotal
//Effect:	get ref of col. col is GoodMoneyTotal
//Return:	double & 
	double & GetCol_GoodMoneyTotal(void)
	{
		return m_GoodMoneyTotal;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	int & 
	int & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	int & 
	int & GetCol_RES_02(void)
	{
		return m_RES_02;
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
			return "ConnState";
		}
		if( iColNum == 8 )
		{
			return "RtnVal";
		}
		if( iColNum == 9 )
		{
			return "BigErr";
		}
		if( iColNum == 10 )
		{
			return "Major";
		}
		if( iColNum == 11 )
		{
			return "Minor";
		}
		if( iColNum == 12 )
		{
			return "ResetOut";
		}
		if( iColNum == 13 )
		{
			return "DoubleCardSam";
		}
		if( iColNum == 14 )
		{
			return "SingleCardSam";
		}
		if( iColNum == 15 )
		{
			return "InitOut";
		}
		if( iColNum == 16 )
		{
			return "ReadOut";
		}
		if( iColNum == 17 )
		{
			return "SaleOut";
		}
		if( iColNum == 18 )
		{
			return "SeriesBad";
		}
		if( iColNum == 19 )
		{
			return "GoodTotal";
		}
		if( iColNum == 20 )
		{
			return "BadTotal";
		}
		if( iColNum == 21 )
		{
			return "GoodMoneyTotal";
		}
		if( iColNum == 22 )
		{
			return "RES_01";
		}
		if( iColNum == 23 )
		{
			return "RES_02";
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
		if( strColName == "ConnState" )
		{
			return 7;
		}
		if( strColName == "RtnVal" )
		{
			return 8;
		}
		if( strColName == "BigErr" )
		{
			return 9;
		}
		if( strColName == "Major" )
		{
			return 10;
		}
		if( strColName == "Minor" )
		{
			return 11;
		}
		if( strColName == "ResetOut" )
		{
			return 12;
		}
		if( strColName == "DoubleCardSam" )
		{
			return 13;
		}
		if( strColName == "SingleCardSam" )
		{
			return 14;
		}
		if( strColName == "InitOut" )
		{
			return 15;
		}
		if( strColName == "ReadOut" )
		{
			return 16;
		}
		if( strColName == "SaleOut" )
		{
			return 17;
		}
		if( strColName == "SeriesBad" )
		{
			return 18;
		}
		if( strColName == "GoodTotal" )
		{
			return 19;
		}
		if( strColName == "BadTotal" )
		{
			return 20;
		}
		if( strColName == "GoodMoneyTotal" )
		{
			return 21;
		}
		if( strColName == "RES_01" )
		{
			return 22;
		}
		if( strColName == "RES_02" )
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
			return wl::SStrf::sltoa(m_ConnState);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_RtnVal);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_BigErr);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_Major);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_Minor);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_ResetOut);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::b2s(m_DoubleCardSam);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::b2s(m_SingleCardSam);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_InitOut);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::b2s(m_ReadOut);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::b2s(m_SaleOut);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_SeriesBad);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_GoodTotal);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_BadTotal);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sftoa(m_GoodMoneyTotal);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sltoa(m_RES_01);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_RES_02);
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
		if( strColName == "ConnState" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "RtnVal" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "BigErr" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "Major" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "Minor" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "ResetOut" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "DoubleCardSam" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "SingleCardSam" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "InitOut" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "ReadOut" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "SaleOut" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "SeriesBad" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "GoodTotal" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "BadTotal" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "GoodMoneyTotal" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "RES_02" )
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
			m_ConnState=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_RtnVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_BigErr=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_Major=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_Minor=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_ResetOut);
		}
		if( iColNum == 13 )
		{
			wl::SStrf::s2b(strValPARA,m_DoubleCardSam);
		}
		if( iColNum == 14 )
		{
			wl::SStrf::s2b(strValPARA,m_SingleCardSam);
		}
		if( iColNum == 15 )
		{
			m_InitOut=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			wl::SStrf::s2b(strValPARA,m_ReadOut);
		}
		if( iColNum == 17 )
		{
			wl::SStrf::s2b(strValPARA,m_SaleOut);
		}
		if( iColNum == 18 )
		{
			m_SeriesBad=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_GoodTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_BadTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_GoodMoneyTotal=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_RES_01=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 23 )
		{
			m_RES_02=wl::SStrf::satol(strValPARA);
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
		if( strColName == "ConnState" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "RtnVal" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "BigErr" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "Major" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "Minor" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "ResetOut" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "DoubleCardSam" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "SingleCardSam" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "InitOut" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "ReadOut" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "SaleOut" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "SeriesBad" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "GoodTotal" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "BadTotal" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "GoodMoneyTotal" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
	}

}
; 
//end of class b8704_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	b8704_t
class b8704_t {
 
private:

	b8704_t_rowtype m_EmptyRow;
	std::vector<b8704_t_rowtype>  m_DATAcorpora;
 
public:

	typedef b8704_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<b8704_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	b8704_t()
	{
	}

	virtual ~b8704_t(){;}
	

	//operator == 
	bool operator == (const b8704_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8704_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8704_t & rhs) const
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

	b8704_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	b8704_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			b8704_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

///////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			b8704_t_rowtype tmpEmptyrow;
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
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const b8704_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

//////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

////////////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

//////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		b8704_t * p = new b8704_t;
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

/////////////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_strTblName
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTblName(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_strAffectDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strAffectDateTime(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
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
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_ConnState
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnState(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnState==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_ConnState
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_ConnState(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnState( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_ConnState
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnState(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnState(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RtnVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RtnVal(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RtnVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_RtnVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_RtnVal(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RtnVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RtnVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RtnVal(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RtnVal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_BigErr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BigErr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BigErr==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_BigErr
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_BigErr(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BigErr( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_BigErr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BigErr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BigErr(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_Major
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Major==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_Major
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_Major(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Major( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_Major
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Major(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_Minor
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Minor(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Minor==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_Minor
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_Minor(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Minor( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_Minor
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Minor(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Minor(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_ResetOut
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ResetOut(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ResetOut==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_ResetOut
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_ResetOut(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ResetOut( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ResetOut
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ResetOut(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ResetOut(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_DoubleCardSam
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DoubleCardSam(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DoubleCardSam==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_DoubleCardSam
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_DoubleCardSam(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_DoubleCardSam( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_DoubleCardSam
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DoubleCardSam(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DoubleCardSam(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SingleCardSam
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SingleCardSam(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SingleCardSam==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_SingleCardSam
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_SingleCardSam(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_SingleCardSam( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_SingleCardSam
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SingleCardSam(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SingleCardSam(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_InitOut
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_InitOut(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_InitOut==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_InitOut
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_InitOut(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_InitOut( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_InitOut
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_InitOut(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_InitOut(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_ReadOut
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReadOut(u8arr_t<28> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReadOut==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_ReadOut
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_ReadOut(u8arr_t<28> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ReadOut( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_ReadOut
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReadOut(u8arr_t<28> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReadOut(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_SaleOut
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SaleOut(u8arr_t<8> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SaleOut==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_SaleOut
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_SaleOut(u8arr_t<8> aVal) 
	{
		std::vector<long> vRps ;
		SelE_SaleOut( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_SaleOut
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SaleOut(u8arr_t<8> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SaleOut(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_SeriesBad
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SeriesBad(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SeriesBad==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_SeriesBad
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_SeriesBad(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_SeriesBad( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_SeriesBad
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SeriesBad(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SeriesBad(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_GoodTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_GoodTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_GoodTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_GoodTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_GoodTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_GoodTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_GoodTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_GoodTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_GoodTotal(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_BadTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BadTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BadTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_BadTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_BadTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_BadTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_BadTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BadTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BadTotal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_GoodMoneyTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_GoodMoneyTotal(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_GoodMoneyTotal==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_GoodMoneyTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_GoodMoneyTotal(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_GoodMoneyTotal( dVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_GoodMoneyTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_GoodMoneyTotal(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_GoodMoneyTotal(dVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_RES_01(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES_01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_01(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_01(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES_02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_02(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_02==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8704_t_rowtype&
	b8704_t_rowtype & SelE1_RES_02(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////
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
//end of class b8704_t


#endif

