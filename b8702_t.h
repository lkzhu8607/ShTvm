#ifndef V1_3AB8702_T_20170103_094937
#define V1_3AB8702_T_20170103_094937

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of b8702_t
//Name:	b8702_t_rowtype
class b8702_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		纸币模块b8702 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	//#.纸币状态字段：
	int		m_ConnState;			// a	1	机器 1=联接 0=失联 
	int		m_RtnVal;			// a	2	调用的返回值 
	int		m_BigErr;			// a	3	大出错，人工干预 
	int		m_BillStopUseFlag;			// a	4	停用标记,0=使用，1=停用 
	//#.各寄存器
	wl::tuint8		m_Major;			// a	5	主版本号 
	wl::tuint8		m_Minor;			// a	6	副版本号 
	int		m_cNoteValue;			// a	7	面额 
	int		m_cNoteNum;			// a	8	张数 
	uiarr_t<int,10>		m_cErrorCode;			// a	9 
	int		m_cErrorNum;			// a	10 
	//#.统计字段：
	long		m_PasswayTotal;			// a	11	通道中的钱数 
	long		m_BoxTotal;			// a	12	压箱中的钱数 
	uiarr_t<long,111>		m_Pieces;			// a	13	面额和张数，最大50元（回收箱） 
	int		m_wInShutter;			// a	14	入钞口状态 0：无纸币 1：有纸币 
	int		m_wReturnShutter;			// a	15	退钞口状态 0：无纸币 1：有纸币 
	uiarr_t<long,6>		m_boxExist;			// a	16	箱存在(循环箱0-3 RE3-RE6,4回收箱CB ，5补币箱LO， 现在用RE5,RE6暂时不用)0=不存在 1=存在 
	uiarr_t<long,6>		m_boxNearEmpty;			// a	17	即将空(循环箱0-3 RE3-RE6,4回收箱CB ，5补币箱LO， 现在用RE5,RE6暂时不用)0=不存在 1=存在 
	uiarr_t<long,6>		m_boxNearFull;			// a	18	即将满(循环箱0-3,RE3-RE6,4回收箱CB ，5补币箱LO， 现在RE5,RE6暂时不用)0=否，1=是 
	uiarr_t<long,6>		m_boxFull;			// a	19	满(循环箱0-3,RE3-RE6,4回收箱CB ，5补币箱LO， 现在RE5,RE6暂时不用)0=否，1=是 
	uiarr_t<long,6>		m_boxIsEmpty;			// a	20	0=不空  1=空(循环箱0-3,RE3-RE6,4回收箱CB ，5补币箱LO， 现在RE5,RE6暂时不用)只有[0]，[1]有用 
	uiarr_t<long,6>		m_OutNumber;			// a	21	找出的纸币数目（0-1 RE3，RE4  有用） 
	uiarr_t<long,6>		m_rejectNumber;			// a	22	找出的纸币废币数目（0-1 RE3，RE4  有用） 
	uiarr_t<long,4>		m_ReDenomination;			// a	23	循环箱纸币面额(0-3 RE3-RE6,现在用RE3，RE4) 
	uiarr_t<long,4>		m_ReNumber;			// a	24	循环箱纸币张数(0-3 RE3-RE6,现在用RE3，RE4) 
	uiarr_t<long,4>		m_ReCount;			// a	25	金额(0-3 RE3-RE6,现在用RE3，RE4) 
	int		m_RES_01;			// a	26	[保留] 
	int		m_RES_02;			// a	27	[保留] 
 
public:

	b8702_t_rowtype()
	{
		m_strTblName = "b8702";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_ConnState = 0;
		m_RtnVal = 0;
		m_BigErr = 0;
		m_BillStopUseFlag = 0;
		m_Major = 0;
		m_Minor = 0;
		m_cNoteValue = 0;
		m_cNoteNum = 0;
		//m_cErrorCode = //use default
		m_cErrorNum = 0;
		m_PasswayTotal = 0;
		m_BoxTotal = 0;
		//m_Pieces = //use default
		m_wInShutter = 0;
		m_wReturnShutter = 0;
		//m_boxExist = //use default
		//m_boxNearEmpty = //use default
		//m_boxNearFull = //use default
		//m_boxFull = //use default
		//m_boxIsEmpty = //use default
		//m_OutNumber = //use default
		//m_rejectNumber = //use default
		//m_ReDenomination = //use default
		//m_ReNumber = //use default
		//m_ReCount = //use default
		m_RES_01 = 0;
		m_RES_02 = 0;
	}

	virtual ~b8702_t_rowtype(){;}
	

	//operator == 
	bool operator == (const b8702_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8702_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8702_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillStopUseFlag));
		len1 = sizeof(m_BillStopUseFlag);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cNoteValue));
		len1 = sizeof(m_cNoteValue);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cNoteNum));
		len1 = sizeof(m_cNoteNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cErrorCode));
		len1 = sizeof(m_cErrorCode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cErrorNum));
		len1 = sizeof(m_cErrorNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PasswayTotal));
		len1 = sizeof(m_PasswayTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BoxTotal));
		len1 = sizeof(m_BoxTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Pieces));
		len1 = sizeof(m_Pieces);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_wInShutter));
		len1 = sizeof(m_wInShutter);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_wReturnShutter));
		len1 = sizeof(m_wReturnShutter);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxExist));
		len1 = sizeof(m_boxExist);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxNearEmpty));
		len1 = sizeof(m_boxNearEmpty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxNearFull));
		len1 = sizeof(m_boxNearFull);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxFull));
		len1 = sizeof(m_boxFull);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxIsEmpty));
		len1 = sizeof(m_boxIsEmpty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OutNumber));
		len1 = sizeof(m_OutNumber);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rejectNumber));
		len1 = sizeof(m_rejectNumber);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReDenomination));
		len1 = sizeof(m_ReDenomination);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReNumber));
		len1 = sizeof(m_ReNumber);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReCount));
		len1 = sizeof(m_ReCount);
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

	b8702_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_BillStopUseFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Major = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Minor = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_cNoteValue = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_cNoteNum = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_cErrorCode = *(uiarr_t<int,10>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_cErrorNum = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PasswayTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BoxTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Pieces = *(uiarr_t<long,111>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_wInShutter = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_wReturnShutter = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxExist = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxNearEmpty = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxNearFull = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxFull = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxIsEmpty = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_OutNumber = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_rejectNumber = *(uiarr_t<long,6>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReDenomination = *(uiarr_t<long,4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReNumber = *(uiarr_t<long,4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReCount = *(uiarr_t<long,4>*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillStopUseFlag));
		len1 = sizeof(m_BillStopUseFlag);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cNoteValue));
		len1 = sizeof(m_cNoteValue);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cNoteNum));
		len1 = sizeof(m_cNoteNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cErrorCode));
		len1 = sizeof(m_cErrorCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_cErrorNum));
		len1 = sizeof(m_cErrorNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PasswayTotal));
		len1 = sizeof(m_PasswayTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BoxTotal));
		len1 = sizeof(m_BoxTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Pieces));
		len1 = sizeof(m_Pieces);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_wInShutter));
		len1 = sizeof(m_wInShutter);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_wReturnShutter));
		len1 = sizeof(m_wReturnShutter);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxExist));
		len1 = sizeof(m_boxExist);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxNearEmpty));
		len1 = sizeof(m_boxNearEmpty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxNearFull));
		len1 = sizeof(m_boxNearFull);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxFull));
		len1 = sizeof(m_boxFull);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxIsEmpty));
		len1 = sizeof(m_boxIsEmpty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OutNumber));
		len1 = sizeof(m_OutNumber);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rejectNumber));
		len1 = sizeof(m_rejectNumber);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReDenomination));
		len1 = sizeof(m_ReDenomination);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReNumber));
		len1 = sizeof(m_ReNumber);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReCount));
		len1 = sizeof(m_ReCount);
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

	b8702_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_BillStopUseFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Major = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Minor = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_cNoteValue = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_cNoteNum = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_cErrorCode = *(uiarr_t<int,10>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_cErrorNum = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PasswayTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BoxTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Pieces = *(uiarr_t<long,111>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_wInShutter = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_wReturnShutter = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxExist = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxNearEmpty = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxNearFull = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxFull = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxIsEmpty = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_OutNumber = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_rejectNumber = *(uiarr_t<long,6>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReDenomination = *(uiarr_t<long,4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReNumber = *(uiarr_t<long,4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReCount = *(uiarr_t<long,4>*)buf2;
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
//Function:	GetCol_BillStopUseFlag
//Effect:	get ref of col. col is BillStopUseFlag
//Return:	int & 
	int & GetCol_BillStopUseFlag(void)
	{
		return m_BillStopUseFlag;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_Major
//Effect:	get ref of col. col is Major
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Major(void)
	{
		return m_Major;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_Minor
//Effect:	get ref of col. col is Minor
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Minor(void)
	{
		return m_Minor;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_cNoteValue
//Effect:	get ref of col. col is cNoteValue
//Return:	int & 
	int & GetCol_cNoteValue(void)
	{
		return m_cNoteValue;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_cNoteNum
//Effect:	get ref of col. col is cNoteNum
//Return:	int & 
	int & GetCol_cNoteNum(void)
	{
		return m_cNoteNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_cErrorCode
//Effect:	get ref of col. col is cErrorCode
//Return:	uiarr_t<int,10> & 
	uiarr_t<int,10> & GetCol_cErrorCode(void)
	{
		return m_cErrorCode;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_cErrorNum
//Effect:	get ref of col. col is cErrorNum
//Return:	int & 
	int & GetCol_cErrorNum(void)
	{
		return m_cErrorNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_PasswayTotal
//Effect:	get ref of col. col is PasswayTotal
//Return:	long & 
	long & GetCol_PasswayTotal(void)
	{
		return m_PasswayTotal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_BoxTotal
//Effect:	get ref of col. col is BoxTotal
//Return:	long & 
	long & GetCol_BoxTotal(void)
	{
		return m_BoxTotal;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_Pieces
//Effect:	get ref of col. col is Pieces
//Return:	uiarr_t<long,111> & 
	uiarr_t<long,111> & GetCol_Pieces(void)
	{
		return m_Pieces;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_wInShutter
//Effect:	get ref of col. col is wInShutter
//Return:	int & 
	int & GetCol_wInShutter(void)
	{
		return m_wInShutter;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_wReturnShutter
//Effect:	get ref of col. col is wReturnShutter
//Return:	int & 
	int & GetCol_wReturnShutter(void)
	{
		return m_wReturnShutter;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_boxExist
//Effect:	get ref of col. col is boxExist
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_boxExist(void)
	{
		return m_boxExist;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_boxNearEmpty
//Effect:	get ref of col. col is boxNearEmpty
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_boxNearEmpty(void)
	{
		return m_boxNearEmpty;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_boxNearFull
//Effect:	get ref of col. col is boxNearFull
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_boxNearFull(void)
	{
		return m_boxNearFull;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_boxFull
//Effect:	get ref of col. col is boxFull
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_boxFull(void)
	{
		return m_boxFull;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_boxIsEmpty
//Effect:	get ref of col. col is boxIsEmpty
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_boxIsEmpty(void)
	{
		return m_boxIsEmpty;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_OutNumber
//Effect:	get ref of col. col is OutNumber
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_OutNumber(void)
	{
		return m_OutNumber;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_rejectNumber
//Effect:	get ref of col. col is rejectNumber
//Return:	uiarr_t<long,6> & 
	uiarr_t<long,6> & GetCol_rejectNumber(void)
	{
		return m_rejectNumber;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_ReDenomination
//Effect:	get ref of col. col is ReDenomination
//Return:	uiarr_t<long,4> & 
	uiarr_t<long,4> & GetCol_ReDenomination(void)
	{
		return m_ReDenomination;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_ReNumber
//Effect:	get ref of col. col is ReNumber
//Return:	uiarr_t<long,4> & 
	uiarr_t<long,4> & GetCol_ReNumber(void)
	{
		return m_ReNumber;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_ReCount
//Effect:	get ref of col. col is ReCount
//Return:	uiarr_t<long,4> & 
	uiarr_t<long,4> & GetCol_ReCount(void)
	{
		return m_ReCount;
	}

//////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 34;
	}

///////////////////////////////////////////////////////////////
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
			return "BillStopUseFlag";
		}
		if( iColNum == 11 )
		{
			return "Major";
		}
		if( iColNum == 12 )
		{
			return "Minor";
		}
		if( iColNum == 13 )
		{
			return "cNoteValue";
		}
		if( iColNum == 14 )
		{
			return "cNoteNum";
		}
		if( iColNum == 15 )
		{
			return "cErrorCode";
		}
		if( iColNum == 16 )
		{
			return "cErrorNum";
		}
		if( iColNum == 17 )
		{
			return "PasswayTotal";
		}
		if( iColNum == 18 )
		{
			return "BoxTotal";
		}
		if( iColNum == 19 )
		{
			return "Pieces";
		}
		if( iColNum == 20 )
		{
			return "wInShutter";
		}
		if( iColNum == 21 )
		{
			return "wReturnShutter";
		}
		if( iColNum == 22 )
		{
			return "boxExist";
		}
		if( iColNum == 23 )
		{
			return "boxNearEmpty";
		}
		if( iColNum == 24 )
		{
			return "boxNearFull";
		}
		if( iColNum == 25 )
		{
			return "boxFull";
		}
		if( iColNum == 26 )
		{
			return "boxIsEmpty";
		}
		if( iColNum == 27 )
		{
			return "OutNumber";
		}
		if( iColNum == 28 )
		{
			return "rejectNumber";
		}
		if( iColNum == 29 )
		{
			return "ReDenomination";
		}
		if( iColNum == 30 )
		{
			return "ReNumber";
		}
		if( iColNum == 31 )
		{
			return "ReCount";
		}
		if( iColNum == 32 )
		{
			return "RES_01";
		}
		if( iColNum == 33 )
		{
			return "RES_02";
		}
		return "";
	}

///////////////////////////////////////////////////////////////
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
		if( strColName == "BillStopUseFlag" )
		{
			return 10;
		}
		if( strColName == "Major" )
		{
			return 11;
		}
		if( strColName == "Minor" )
		{
			return 12;
		}
		if( strColName == "cNoteValue" )
		{
			return 13;
		}
		if( strColName == "cNoteNum" )
		{
			return 14;
		}
		if( strColName == "cErrorCode" )
		{
			return 15;
		}
		if( strColName == "cErrorNum" )
		{
			return 16;
		}
		if( strColName == "PasswayTotal" )
		{
			return 17;
		}
		if( strColName == "BoxTotal" )
		{
			return 18;
		}
		if( strColName == "Pieces" )
		{
			return 19;
		}
		if( strColName == "wInShutter" )
		{
			return 20;
		}
		if( strColName == "wReturnShutter" )
		{
			return 21;
		}
		if( strColName == "boxExist" )
		{
			return 22;
		}
		if( strColName == "boxNearEmpty" )
		{
			return 23;
		}
		if( strColName == "boxNearFull" )
		{
			return 24;
		}
		if( strColName == "boxFull" )
		{
			return 25;
		}
		if( strColName == "boxIsEmpty" )
		{
			return 26;
		}
		if( strColName == "OutNumber" )
		{
			return 27;
		}
		if( strColName == "rejectNumber" )
		{
			return 28;
		}
		if( strColName == "ReDenomination" )
		{
			return 29;
		}
		if( strColName == "ReNumber" )
		{
			return 30;
		}
		if( strColName == "ReCount" )
		{
			return 31;
		}
		if( strColName == "RES_01" )
		{
			return 32;
		}
		if( strColName == "RES_02" )
		{
			return 33;
		}
		return -1;
	}

////////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_BillStopUseFlag);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_Major);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_Minor);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_cNoteValue);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_cNoteNum);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::b2s(m_cErrorCode);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_cErrorNum);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_PasswayTotal);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_BoxTotal);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::b2s(m_Pieces);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_wInShutter);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_wReturnShutter);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_boxExist);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::b2s(m_boxNearEmpty);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::b2s(m_boxNearFull);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::b2s(m_boxFull);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::b2s(m_boxIsEmpty);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::b2s(m_OutNumber);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::b2s(m_rejectNumber);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::b2s(m_ReDenomination);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::b2s(m_ReNumber);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::b2s(m_ReCount);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_RES_01);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_RES_02);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

//////////////////////////////////////////////////////////
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
		if( strColName == "BillStopUseFlag" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "Major" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "Minor" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "cNoteValue" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "cNoteNum" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "cErrorCode" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "cErrorNum" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "PasswayTotal" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "BoxTotal" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "Pieces" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "wInShutter" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "wReturnShutter" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "boxExist" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "boxNearEmpty" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "boxNearFull" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "boxFull" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "boxIsEmpty" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "OutNumber" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "rejectNumber" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "ReDenomination" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "ReNumber" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "ReCount" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(33);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

////////////////////////////////////////////////////////////////
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
			m_BillStopUseFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_Major=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_Minor=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_cNoteValue=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_cNoteNum=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			wl::SStrf::s2b(strValPARA,m_cErrorCode);
		}
		if( iColNum == 16 )
		{
			m_cErrorNum=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_PasswayTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_BoxTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			wl::SStrf::s2b(strValPARA,m_Pieces);
		}
		if( iColNum == 20 )
		{
			m_wInShutter=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_wReturnShutter=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_boxExist);
		}
		if( iColNum == 23 )
		{
			wl::SStrf::s2b(strValPARA,m_boxNearEmpty);
		}
		if( iColNum == 24 )
		{
			wl::SStrf::s2b(strValPARA,m_boxNearFull);
		}
		if( iColNum == 25 )
		{
			wl::SStrf::s2b(strValPARA,m_boxFull);
		}
		if( iColNum == 26 )
		{
			wl::SStrf::s2b(strValPARA,m_boxIsEmpty);
		}
		if( iColNum == 27 )
		{
			wl::SStrf::s2b(strValPARA,m_OutNumber);
		}
		if( iColNum == 28 )
		{
			wl::SStrf::s2b(strValPARA,m_rejectNumber);
		}
		if( iColNum == 29 )
		{
			wl::SStrf::s2b(strValPARA,m_ReDenomination);
		}
		if( iColNum == 30 )
		{
			wl::SStrf::s2b(strValPARA,m_ReNumber);
		}
		if( iColNum == 31 )
		{
			wl::SStrf::s2b(strValPARA,m_ReCount);
		}
		if( iColNum == 32 )
		{
			m_RES_01=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
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
		if( strColName == "BillStopUseFlag" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "Major" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "Minor" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "cNoteValue" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "cNoteNum" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "cErrorCode" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "cErrorNum" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "PasswayTotal" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "BoxTotal" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "Pieces" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "wInShutter" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "wReturnShutter" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "boxExist" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "boxNearEmpty" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "boxNearFull" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "boxFull" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "boxIsEmpty" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "OutNumber" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "rejectNumber" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "ReDenomination" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "ReNumber" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "ReCount" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
	}

}
; 
//end of class b8702_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	b8702_t
class b8702_t {
 
private:

	b8702_t_rowtype m_EmptyRow;
	std::vector<b8702_t_rowtype>  m_DATAcorpora;
 
public:

	typedef b8702_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<b8702_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	b8702_t()
	{
	}

	virtual ~b8702_t(){;}
	

	//operator == 
	bool operator == (const b8702_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8702_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8702_t & rhs) const
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

	b8702_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	b8702_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

/////////////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl according to RPS
//Return:	long
	long GetRowCount(const std::vector<long> & vRps)
	{
		return (long)vRps.size();
	}

////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			b8702_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

/////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			b8702_t_rowtype tmpEmptyrow;
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

////////////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes, if any.
//Return:	no return
	void Add(const b8702_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

/////////////////////////////////////////////////////////
//Function:	AddDefaultRow
//Effect:	add one default row using Add function.
//Return:	no return
	void AddDefaultRow()
	{
		Add( b8702_t_rowtype());
	}

///////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		b8702_t * p = new b8702_t;
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

/////////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_strTblName
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTblName(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_lVer(long iVal) 
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

///////////////////////////////////////////////////////
//Function:	SelE_strAffectDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strAffectDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_strAffectDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strAffectDateTime(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
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

/////////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_ConnState
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnState(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnState==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_ConnState
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_ConnState(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnState( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_ConnState
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnState(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnState(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_RtnVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RtnVal(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RtnVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RtnVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_RtnVal(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RtnVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RtnVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RtnVal(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RtnVal(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_BigErr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BigErr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BigErr==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_BigErr
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_BigErr(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BigErr( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_BigErr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BigErr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BigErr(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_BillStopUseFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BillStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BillStopUseFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_BillStopUseFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_BillStopUseFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BillStopUseFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_BillStopUseFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BillStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BillStopUseFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
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
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_Major(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Major( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_Major
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Major(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
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
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_Minor(wl::tuint8 iVal) 
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
//Function:	SelE_cNoteValue
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_cNoteValue(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_cNoteValue==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_cNoteValue
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_cNoteValue(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_cNoteValue( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_cNoteValue
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_cNoteValue(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_cNoteValue(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_cNoteNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_cNoteNum(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_cNoteNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_cNoteNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_cNoteNum(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_cNoteNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_cNoteNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_cNoteNum(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_cNoteNum(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_cErrorCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_cErrorCode(uiarr_t<int,10> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_cErrorCode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_cErrorCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_cErrorCode(uiarr_t<int,10> aVal) 
	{
		std::vector<long> vRps ;
		SelE_cErrorCode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_cErrorCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_cErrorCode(uiarr_t<int,10> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_cErrorCode(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_cErrorNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_cErrorNum(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_cErrorNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_cErrorNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_cErrorNum(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_cErrorNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_cErrorNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_cErrorNum(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_cErrorNum(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_PasswayTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PasswayTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PasswayTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_PasswayTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_PasswayTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_PasswayTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_PasswayTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PasswayTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PasswayTotal(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_BoxTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BoxTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BoxTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_BoxTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_BoxTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_BoxTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_BoxTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BoxTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BoxTotal(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_Pieces
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Pieces(uiarr_t<long,111> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Pieces==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_Pieces
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_Pieces(uiarr_t<long,111> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Pieces( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_Pieces
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Pieces(uiarr_t<long,111> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Pieces(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_wInShutter
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_wInShutter(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_wInShutter==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_wInShutter
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_wInShutter(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_wInShutter( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_wInShutter
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_wInShutter(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_wInShutter(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_wReturnShutter
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_wReturnShutter(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_wReturnShutter==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_wReturnShutter
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_wReturnShutter(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_wReturnShutter( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_wReturnShutter
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_wReturnShutter(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_wReturnShutter(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_boxExist
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxExist(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxExist==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_boxExist
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_boxExist(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxExist( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_boxExist
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxExist(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxExist(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_boxNearEmpty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxNearEmpty(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxNearEmpty==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_boxNearEmpty
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_boxNearEmpty(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxNearEmpty( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_boxNearEmpty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxNearEmpty(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxNearEmpty(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_boxNearFull
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxNearFull(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxNearFull==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_boxNearFull
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_boxNearFull(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxNearFull( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_boxNearFull
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxNearFull(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxNearFull(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_boxFull
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxFull(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxFull==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_boxFull
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_boxFull(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxFull( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_boxFull
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxFull(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxFull(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_boxIsEmpty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxIsEmpty(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxIsEmpty==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_boxIsEmpty
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_boxIsEmpty(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxIsEmpty( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_boxIsEmpty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxIsEmpty(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxIsEmpty(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_OutNumber
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_OutNumber(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_OutNumber==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_OutNumber
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_OutNumber(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_OutNumber( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_OutNumber
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_OutNumber(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_OutNumber(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_rejectNumber
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_rejectNumber(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_rejectNumber==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_rejectNumber
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_rejectNumber(uiarr_t<long,6> aVal) 
	{
		std::vector<long> vRps ;
		SelE_rejectNumber( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_rejectNumber
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_rejectNumber(uiarr_t<long,6> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_rejectNumber(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_ReDenomination
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReDenomination(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReDenomination==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_ReDenomination
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_ReDenomination(uiarr_t<long,4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ReDenomination( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_ReDenomination
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReDenomination(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReDenomination(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_ReNumber
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReNumber(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReNumber==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_ReNumber
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_ReNumber(uiarr_t<long,4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ReNumber( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_ReNumber
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReNumber(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReNumber(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_ReCount
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReCount(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReCount==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_ReCount
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_ReCount(uiarr_t<long,4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ReCount( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_ReCount
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReCount(uiarr_t<long,4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReCount(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_RES_01(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8702_t_rowtype&
	b8702_t_rowtype & SelE1_RES_02(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////
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
//end of class b8702_t


#endif


