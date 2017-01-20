
#ifndef V1_3AA3014_T_20140523_161812
#define V1_3AA3014_T_20140523_161812

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a3014_t
//Name:	a3014_t_rowtype
class a3014_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1	0	7.0.18  3014-设置SLE节点标识 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	u8arr_t<4>		m_CcNode;			// a	1 
	wl::tuint8		m_CCNodecode1;			// a	2	线路中央标识码 CC的节点标识码 
	wl::tuint8		m_CCNodecode2;			// a	3	线路中央标识码 CC的节点标识码 
	wl::tuint8		m_CCNodecode3;			// a	4	线路中央标识码 CC的节点标识码 
	wl::tuint8		m_CCNodecode4;			// a	5	线路中央标识码 CC的节点标识码 
	u8arr_t<4>		m_ScNode;			// a	6 
	wl::tuint8		m_SCNodecode1;			// a	7	车站标识码 SC的节点标识码 
	wl::tuint8		m_SCNodecode2;			// a	8	车站标识码 SC的节点标识码 
	wl::tuint8		m_SCNodecode3;			// a	9	车站标识码 SC的节点标识码 
	wl::tuint8		m_SCNodecode4;			// a	10	车站标识码 SC的节点标识码 
	u8arr_t<4>		m_EqpNode;			// a	11 
	wl::tuint8		m_EqpNodecode1;			// a	12	 车站设备标识码 SLE的节点标识码				线路编码00特殊定义编码范围：01~99；线路编号采用BCD码 
	wl::tuint8		m_EqpNodecode2;			// a	13	 车站设备标识码 SLE的节点标识码				车站编码00特殊定义编码范围：01~99；车站编号采用BCD码 
	wl::tuint8		m_EqpNodecode3;			// a	14	 车站设备标识码 SLE的节点标识码				设备类型编码范围：01h~FFh；车站编号采用HEX码 
	wl::tuint8		m_EqpNodecode4;			// a	15	 车站设备标识码 SLE的节点标识码				设备编码00h特殊定义编码范围：01h~FFh；设备编码采用HEX码 
	u8arr_t<4>		m_EqpAddr;			// a	16 
	wl::tuint8		m_EqpAddr1;			// a	17	 车站设备地址 SLE的地址 
	wl::tuint8		m_EqpAddr2;			// a	18	 车站设备地址 SLE的地址 
	wl::tuint8		m_EqpAddr3;			// a	19	 车站设备地址 SLE的地址 
	wl::tuint8		m_EqpAddr4;			// a	20	 车站设备地址 SLE的地址 
 
public:

	a3014_t_rowtype()
	{
		m_strTblName = "a3014";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		//m_CcNode = //use default
		m_CCNodecode1 = 0;
		m_CCNodecode2 = 0;
		m_CCNodecode3 = 0;
		m_CCNodecode4 = 0;
		//m_ScNode = //use default
		m_SCNodecode1 = 0;
		m_SCNodecode2 = 0;
		m_SCNodecode3 = 0;
		m_SCNodecode4 = 0;
		//m_EqpNode = //use default
		m_EqpNodecode1 = 0;
		m_EqpNodecode2 = 0;
		m_EqpNodecode3 = 0;
		m_EqpNodecode4 = 0;
		//m_EqpAddr = //use default
		m_EqpAddr1 = 0;
		m_EqpAddr2 = 0;
		m_EqpAddr3 = 0;
		m_EqpAddr4 = 0;
	}

	virtual ~a3014_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a3014_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3014_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3014_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CcNode));
		len1 = sizeof(m_CcNode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode1));
		len1 = sizeof(m_CCNodecode1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode2));
		len1 = sizeof(m_CCNodecode2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode3));
		len1 = sizeof(m_CCNodecode3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode4));
		len1 = sizeof(m_CCNodecode4);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ScNode));
		len1 = sizeof(m_ScNode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode1));
		len1 = sizeof(m_SCNodecode1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode2));
		len1 = sizeof(m_SCNodecode2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode3));
		len1 = sizeof(m_SCNodecode3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode4));
		len1 = sizeof(m_SCNodecode4);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNode));
		len1 = sizeof(m_EqpNode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode1));
		len1 = sizeof(m_EqpNodecode1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode2));
		len1 = sizeof(m_EqpNodecode2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode3));
		len1 = sizeof(m_EqpNodecode3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode4));
		len1 = sizeof(m_EqpNodecode4);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr));
		len1 = sizeof(m_EqpAddr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr1));
		len1 = sizeof(m_EqpAddr1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr2));
		len1 = sizeof(m_EqpAddr2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr3));
		len1 = sizeof(m_EqpAddr3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr4));
		len1 = sizeof(m_EqpAddr4);
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

	a3014_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_CcNode = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CCNodecode1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CCNodecode2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CCNodecode3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CCNodecode4 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ScNode = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SCNodecode1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SCNodecode2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SCNodecode3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SCNodecode4 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpNode = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpNodecode1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpNodecode2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpNodecode3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpNodecode4 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpAddr = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpAddr1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpAddr2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpAddr3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_EqpAddr4 = *(wl::tuint8*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CcNode));
		len1 = sizeof(m_CcNode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode1));
		len1 = sizeof(m_CCNodecode1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode2));
		len1 = sizeof(m_CCNodecode2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode3));
		len1 = sizeof(m_CCNodecode3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CCNodecode4));
		len1 = sizeof(m_CCNodecode4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ScNode));
		len1 = sizeof(m_ScNode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode1));
		len1 = sizeof(m_SCNodecode1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode2));
		len1 = sizeof(m_SCNodecode2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode3));
		len1 = sizeof(m_SCNodecode3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SCNodecode4));
		len1 = sizeof(m_SCNodecode4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNode));
		len1 = sizeof(m_EqpNode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode1));
		len1 = sizeof(m_EqpNodecode1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode2));
		len1 = sizeof(m_EqpNodecode2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode3));
		len1 = sizeof(m_EqpNodecode3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpNodecode4));
		len1 = sizeof(m_EqpNodecode4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr));
		len1 = sizeof(m_EqpAddr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr1));
		len1 = sizeof(m_EqpAddr1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr2));
		len1 = sizeof(m_EqpAddr2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr3));
		len1 = sizeof(m_EqpAddr3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_EqpAddr4));
		len1 = sizeof(m_EqpAddr4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a3014_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_CcNode = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CCNodecode1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CCNodecode2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CCNodecode3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CCNodecode4 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ScNode = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SCNodecode1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SCNodecode2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SCNodecode3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SCNodecode4 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpNode = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpNodecode1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpNodecode2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpNodecode3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpNodecode4 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpAddr = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpAddr1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpAddr2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpAddr3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_EqpAddr4 = *(wl::tuint8*)buf2;
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
//Function:	GetCol_CcNode
//Effect:	get ref of col. col is CcNode
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_CcNode(void)
	{
		return m_CcNode;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_CCNodecode1
//Effect:	get ref of col. col is CCNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_CCNodecode1(void)
	{
		return m_CCNodecode1;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_CCNodecode2
//Effect:	get ref of col. col is CCNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_CCNodecode2(void)
	{
		return m_CCNodecode2;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_CCNodecode3
//Effect:	get ref of col. col is CCNodecode3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_CCNodecode3(void)
	{
		return m_CCNodecode3;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_CCNodecode4
//Effect:	get ref of col. col is CCNodecode4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_CCNodecode4(void)
	{
		return m_CCNodecode4;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_ScNode
//Effect:	get ref of col. col is ScNode
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_ScNode(void)
	{
		return m_ScNode;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode1
//Effect:	get ref of col. col is SCNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode1(void)
	{
		return m_SCNodecode1;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode2
//Effect:	get ref of col. col is SCNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode2(void)
	{
		return m_SCNodecode2;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode3
//Effect:	get ref of col. col is SCNodecode3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode3(void)
	{
		return m_SCNodecode3;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode4
//Effect:	get ref of col. col is SCNodecode4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode4(void)
	{
		return m_SCNodecode4;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_EqpNode
//Effect:	get ref of col. col is EqpNode
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_EqpNode(void)
	{
		return m_EqpNode;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode1
//Effect:	get ref of col. col is EqpNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode1(void)
	{
		return m_EqpNodecode1;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode2
//Effect:	get ref of col. col is EqpNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode2(void)
	{
		return m_EqpNodecode2;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode3
//Effect:	get ref of col. col is EqpNodecode3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode3(void)
	{
		return m_EqpNodecode3;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode4
//Effect:	get ref of col. col is EqpNodecode4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode4(void)
	{
		return m_EqpNodecode4;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_EqpAddr
//Effect:	get ref of col. col is EqpAddr
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_EqpAddr(void)
	{
		return m_EqpAddr;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_EqpAddr1
//Effect:	get ref of col. col is EqpAddr1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpAddr1(void)
	{
		return m_EqpAddr1;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_EqpAddr2
//Effect:	get ref of col. col is EqpAddr2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpAddr2(void)
	{
		return m_EqpAddr2;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_EqpAddr3
//Effect:	get ref of col. col is EqpAddr3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpAddr3(void)
	{
		return m_EqpAddr3;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_EqpAddr4
//Effect:	get ref of col. col is EqpAddr4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpAddr4(void)
	{
		return m_EqpAddr4;
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
			return "CcNode";
		}
		if( iColNum == 8 )
		{
			return "CCNodecode1";
		}
		if( iColNum == 9 )
		{
			return "CCNodecode2";
		}
		if( iColNum == 10 )
		{
			return "CCNodecode3";
		}
		if( iColNum == 11 )
		{
			return "CCNodecode4";
		}
		if( iColNum == 12 )
		{
			return "ScNode";
		}
		if( iColNum == 13 )
		{
			return "SCNodecode1";
		}
		if( iColNum == 14 )
		{
			return "SCNodecode2";
		}
		if( iColNum == 15 )
		{
			return "SCNodecode3";
		}
		if( iColNum == 16 )
		{
			return "SCNodecode4";
		}
		if( iColNum == 17 )
		{
			return "EqpNode";
		}
		if( iColNum == 18 )
		{
			return "EqpNodecode1";
		}
		if( iColNum == 19 )
		{
			return "EqpNodecode2";
		}
		if( iColNum == 20 )
		{
			return "EqpNodecode3";
		}
		if( iColNum == 21 )
		{
			return "EqpNodecode4";
		}
		if( iColNum == 22 )
		{
			return "EqpAddr";
		}
		if( iColNum == 23 )
		{
			return "EqpAddr1";
		}
		if( iColNum == 24 )
		{
			return "EqpAddr2";
		}
		if( iColNum == 25 )
		{
			return "EqpAddr3";
		}
		if( iColNum == 26 )
		{
			return "EqpAddr4";
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
		if( strColName == "CcNode" )
		{
			return 7;
		}
		if( strColName == "CCNodecode1" )
		{
			return 8;
		}
		if( strColName == "CCNodecode2" )
		{
			return 9;
		}
		if( strColName == "CCNodecode3" )
		{
			return 10;
		}
		if( strColName == "CCNodecode4" )
		{
			return 11;
		}
		if( strColName == "ScNode" )
		{
			return 12;
		}
		if( strColName == "SCNodecode1" )
		{
			return 13;
		}
		if( strColName == "SCNodecode2" )
		{
			return 14;
		}
		if( strColName == "SCNodecode3" )
		{
			return 15;
		}
		if( strColName == "SCNodecode4" )
		{
			return 16;
		}
		if( strColName == "EqpNode" )
		{
			return 17;
		}
		if( strColName == "EqpNodecode1" )
		{
			return 18;
		}
		if( strColName == "EqpNodecode2" )
		{
			return 19;
		}
		if( strColName == "EqpNodecode3" )
		{
			return 20;
		}
		if( strColName == "EqpNodecode4" )
		{
			return 21;
		}
		if( strColName == "EqpAddr" )
		{
			return 22;
		}
		if( strColName == "EqpAddr1" )
		{
			return 23;
		}
		if( strColName == "EqpAddr2" )
		{
			return 24;
		}
		if( strColName == "EqpAddr3" )
		{
			return 25;
		}
		if( strColName == "EqpAddr4" )
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
			return wl::SStrf::b2s(m_CcNode);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_CCNodecode1);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_CCNodecode2);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_CCNodecode3);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_CCNodecode4);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_ScNode);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_SCNodecode1);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_SCNodecode2);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_SCNodecode3);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_SCNodecode4);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::b2s(m_EqpNode);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode1);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode2);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode3);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode4);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_EqpAddr);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_EqpAddr1);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_EqpAddr2);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_EqpAddr3);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_EqpAddr4);
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
		if( strColName == "CcNode" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "CCNodecode1" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "CCNodecode2" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "CCNodecode3" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "CCNodecode4" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "ScNode" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "SCNodecode1" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "SCNodecode2" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "SCNodecode3" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "SCNodecode4" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "EqpNode" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "EqpNodecode1" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "EqpNodecode2" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "EqpNodecode3" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "EqpNodecode4" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "EqpAddr" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "EqpAddr1" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "EqpAddr2" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "EqpAddr3" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "EqpAddr4" )
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
			wl::SStrf::s2b(strValPARA,m_CcNode);
		}
		if( iColNum == 8 )
		{
			m_CCNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_CCNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_CCNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_CCNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_ScNode);
		}
		if( iColNum == 13 )
		{
			m_SCNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_SCNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_SCNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_SCNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			wl::SStrf::s2b(strValPARA,m_EqpNode);
		}
		if( iColNum == 18 )
		{
			m_EqpNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_EqpNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_EqpNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_EqpNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_EqpAddr);
		}
		if( iColNum == 23 )
		{
			m_EqpAddr1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_EqpAddr2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_EqpAddr3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_EqpAddr4=(wl::tuint8)wl::SStrf::satol(strValPARA);
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
		if( strColName == "CcNode" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "CCNodecode1" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "CCNodecode2" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "CCNodecode3" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "CCNodecode4" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "ScNode" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "SCNodecode1" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "SCNodecode2" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "SCNodecode3" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "SCNodecode4" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "EqpNode" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "EqpNodecode1" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "EqpNodecode2" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "EqpNodecode3" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "EqpNodecode4" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "EqpAddr" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "EqpAddr1" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "EqpAddr2" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "EqpAddr3" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "EqpAddr4" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
	}

}
; 
//end of class a3014_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a3014_t
class a3014_t {
 
private:

	a3014_t_rowtype m_EmptyRow;
	std::vector<a3014_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a3014_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a3014_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a3014_t()
	{
	}

	virtual ~a3014_t(){;}
	

	//operator == 
	bool operator == (const a3014_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3014_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3014_t & rhs) const
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

	a3014_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a3014_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a3014_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a3014_t_rowtype tmpEmptyrow;
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
	void Add(const a3014_t_rowtype & varRow)
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
		a3014_t * p = new a3014_t;
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_strTblName(std::string strVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_lVer(long iVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
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
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_strDataRef(std::string strVal) 
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
//Function:	SelE_CcNode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CcNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CcNode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_CcNode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_CcNode(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CcNode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_CcNode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CcNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CcNode(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_CCNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CCNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CCNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_CCNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_CCNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_CCNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CCNodecode1(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CCNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CCNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_CCNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_CCNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_CCNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_CCNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CCNodecode2(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CCNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CCNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_CCNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_CCNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_CCNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_CCNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CCNodecode3(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_CCNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CCNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CCNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_CCNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_CCNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_CCNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CCNodecode4(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_ScNode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ScNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ScNode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_ScNode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_ScNode(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ScNode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ScNode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ScNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ScNode(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_SCNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode1(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_SCNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode2(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_SCNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode3(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_SCNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode4(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_EqpNode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_EqpNode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpNode(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_EqpNode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNode(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode1(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode2(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode3(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode4(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_EqpAddr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpAddr==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_EqpAddr
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpAddr(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpAddr( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_EqpAddr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpAddr(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpAddr(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_EqpAddr1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpAddr1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpAddr1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_EqpAddr1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpAddr1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpAddr1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_EqpAddr1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpAddr1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpAddr1(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_EqpAddr2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpAddr2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpAddr2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_EqpAddr2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpAddr2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpAddr2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_EqpAddr2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpAddr2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpAddr2(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_EqpAddr3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpAddr3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpAddr3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_EqpAddr3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpAddr3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpAddr3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_EqpAddr3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpAddr3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpAddr3(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_EqpAddr4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpAddr4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpAddr4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_EqpAddr4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3014_t_rowtype&
	a3014_t_rowtype & SelE1_EqpAddr4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpAddr4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_EqpAddr4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpAddr4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpAddr4(iVal, vRps, pRefRps);
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
//end of class a3014_t


#endif

