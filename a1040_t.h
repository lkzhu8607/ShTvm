
#ifndef V1_3AA1040_T_20140523_151859
#define V1_3AA1040_T_20140523_151859

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a1040_t
//Name:	a1040_t_rowtype
class a1040_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		5.0.1  1040-车站配置。此类交互用于CC向车站发送车站的配置参数。对于不同的车 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	u8arr_t<4>		m_ScNode;			// a	1	车站标识码 SC节点标识码 Block 4 
	u8arr_t<2>		m_PositionNum;			// a	2	站点/位置号[保留] 车站人员概念中的车站的站点/位置号，用于打印和显示 Word 2 
	std::string		m_strStaNameEnShort;			// a	3	车站简称（英文）  String 6 
	std::string		m_strStaNameEn;			// a	4	车站名称（英文）  String 32 
	long		m_lStaNameCh;			// a	5	车站名称（中文） 线路本地语言资源文件指针 Pointer 4 
	u8arr_t<4>		m_CcNode;			// a	6	主线路标识码 所属线路的CC的节点标识码 Block 4 
	longarr2v_t<7,96>		m_TimeTableWeiHu;			// a	7	维护寄存器数据的报告间隔时间变更表，一周7天，每天96刻钟，值是间隔时间秒  Block 56 
	longarr2v_t<7,96>		m_TimeTableShenJi;			// a	8	审计寄存器数据的报告间隔时间变更表  Block 56 
	wl::tuint8		m_RES01;			// a	9	[保留] 
	u8arr_t<2>		m_RES02;			// a	10	[保留] 
	u8arr_t<3>		m_StaWorkTime;			// a	11	车站运营时间Byte0：运营开始时间Byte1：运营结束时间Byte2：开始产生车站日终报告的时间单位：15min对应：本地时间00:00~23:45Byte3 
	wl::tuint8		m_RES03;			// a	12	[保留] 
 
public:

	a1040_t_rowtype()
	{
		m_strTblName = "a1040";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		//m_ScNode = //use default
		//m_PositionNum = //use default
		m_strStaNameEnShort = "";
		m_strStaNameEn = "";
		m_lStaNameCh = 0;
		//m_CcNode = //use default
		wl::SStrf::smemset(m_TimeTableWeiHu);
		wl::SStrf::smemset(m_TimeTableShenJi);
		m_RES01 = 0;
		//m_RES02 = //use default
		//m_StaWorkTime = //use default
		m_RES03 = 0;
	}

	virtual ~a1040_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a1040_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a1040_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a1040_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ScNode));
		len1 = sizeof(m_ScNode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PositionNum));
		len1 = sizeof(m_PositionNum);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strStaNameEnShort.c_str();
		len1 = (long)(m_strStaNameEnShort.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strStaNameEn.c_str();
		len1 = (long)(m_strStaNameEn.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lStaNameCh));
		len1 = sizeof(m_lStaNameCh);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTableWeiHu));
		len1 = sizeof(m_TimeTableWeiHu);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTableShenJi));
		len1 = sizeof(m_TimeTableShenJi);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StaWorkTime));
		len1 = sizeof(m_StaWorkTime);
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

	a1040_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_ScNode = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PositionNum = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strStaNameEnShort = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strStaNameEn = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lStaNameCh = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CcNode = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimeTableWeiHu = *(longarr2v_t<7,96>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimeTableShenJi = *(longarr2v_t<7,96>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES02 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_StaWorkTime = *(u8arr_t<3>*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ScNode));
		len1 = sizeof(m_ScNode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PositionNum));
		len1 = sizeof(m_PositionNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strStaNameEnShort.c_str();
		len1 = (long)(m_strStaNameEnShort.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strStaNameEn.c_str();
		len1 = (long)(m_strStaNameEn.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lStaNameCh));
		len1 = sizeof(m_lStaNameCh);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CcNode));
		len1 = sizeof(m_CcNode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTableWeiHu));
		len1 = sizeof(m_TimeTableWeiHu);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTableShenJi));
		len1 = sizeof(m_TimeTableShenJi);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StaWorkTime));
		len1 = sizeof(m_StaWorkTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES03));
		len1 = sizeof(m_RES03);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a1040_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_ScNode = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PositionNum = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strStaNameEnShort = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strStaNameEn = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lStaNameCh = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CcNode = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimeTableWeiHu = *(longarr2v_t<7,96>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimeTableShenJi = *(longarr2v_t<7,96>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES02 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_StaWorkTime = *(u8arr_t<3>*)buf2;
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
//Function:	GetCol_ScNode
//Effect:	get ref of col. col is ScNode
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_ScNode(void)
	{
		return m_ScNode;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_PositionNum
//Effect:	get ref of col. col is PositionNum
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_PositionNum(void)
	{
		return m_PositionNum;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_strStaNameEnShort
//Effect:	get ref of col. col is strStaNameEnShort
//Return:	std::string & 
	std::string & GetCol_strStaNameEnShort(void)
	{
		return m_strStaNameEnShort;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_strStaNameEn
//Effect:	get ref of col. col is strStaNameEn
//Return:	std::string & 
	std::string & GetCol_strStaNameEn(void)
	{
		return m_strStaNameEn;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_lStaNameCh
//Effect:	get ref of col. col is lStaNameCh
//Return:	long & 
	long & GetCol_lStaNameCh(void)
	{
		return m_lStaNameCh;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_CcNode
//Effect:	get ref of col. col is CcNode
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_CcNode(void)
	{
		return m_CcNode;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_TimeTableWeiHu
//Effect:	get ref of col. col is TimeTableWeiHu
//Return:	longarr2v_t<7,96> & 
	longarr2v_t<7,96> & GetCol_TimeTableWeiHu(void)
	{
		return m_TimeTableWeiHu;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_TimeTableShenJi
//Effect:	get ref of col. col is TimeTableShenJi
//Return:	longarr2v_t<7,96> & 
	longarr2v_t<7,96> & GetCol_TimeTableShenJi(void)
	{
		return m_TimeTableShenJi;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES01
//Effect:	get ref of col. col is RES01
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01(void)
	{
		return m_RES01;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_RES02
//Effect:	get ref of col. col is RES02
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES02(void)
	{
		return m_RES02;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_StaWorkTime
//Effect:	get ref of col. col is StaWorkTime
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_StaWorkTime(void)
	{
		return m_StaWorkTime;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES03
//Effect:	get ref of col. col is RES03
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES03(void)
	{
		return m_RES03;
	}

 
public:

/////////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 19;
	}

///////////////////////////////////////////////////////////
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
			return "ScNode";
		}
		if( iColNum == 8 )
		{
			return "PositionNum";
		}
		if( iColNum == 9 )
		{
			return "strStaNameEnShort";
		}
		if( iColNum == 10 )
		{
			return "strStaNameEn";
		}
		if( iColNum == 11 )
		{
			return "lStaNameCh";
		}
		if( iColNum == 12 )
		{
			return "CcNode";
		}
		if( iColNum == 13 )
		{
			return "TimeTableWeiHu";
		}
		if( iColNum == 14 )
		{
			return "TimeTableShenJi";
		}
		if( iColNum == 15 )
		{
			return "RES01";
		}
		if( iColNum == 16 )
		{
			return "RES02";
		}
		if( iColNum == 17 )
		{
			return "StaWorkTime";
		}
		if( iColNum == 18 )
		{
			return "RES03";
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
		if( strColName == "ScNode" )
		{
			return 7;
		}
		if( strColName == "PositionNum" )
		{
			return 8;
		}
		if( strColName == "strStaNameEnShort" )
		{
			return 9;
		}
		if( strColName == "strStaNameEn" )
		{
			return 10;
		}
		if( strColName == "lStaNameCh" )
		{
			return 11;
		}
		if( strColName == "CcNode" )
		{
			return 12;
		}
		if( strColName == "TimeTableWeiHu" )
		{
			return 13;
		}
		if( strColName == "TimeTableShenJi" )
		{
			return 14;
		}
		if( strColName == "RES01" )
		{
			return 15;
		}
		if( strColName == "RES02" )
		{
			return 16;
		}
		if( strColName == "StaWorkTime" )
		{
			return 17;
		}
		if( strColName == "RES03" )
		{
			return 18;
		}
		return -1;
	}

///////////////////////////////////////////////////////
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
			return wl::SStrf::b2s(m_ScNode);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::b2s(m_PositionNum);
		}
		if( iColNum == 9 )
		{
			return m_strStaNameEnShort;
		}
		if( iColNum == 10 )
		{
			return m_strStaNameEn;
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_lStaNameCh);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_CcNode);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::b2s(m_TimeTableWeiHu);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::b2s(m_TimeTableShenJi);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_RES01);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::b2s(m_RES02);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::b2s(m_StaWorkTime);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_RES03);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

///////////////////////////////////////////////////////
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
		if( strColName == "ScNode" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "PositionNum" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "strStaNameEnShort" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "strStaNameEn" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "lStaNameCh" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "CcNode" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "TimeTableWeiHu" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "TimeTableShenJi" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "RES01" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "RES02" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "StaWorkTime" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "RES03" )
		{
			return GetColStr<STRINGT>(18);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

///////////////////////////////////////////////////////////
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
			wl::SStrf::s2b(strValPARA,m_ScNode);
		}
		if( iColNum == 8 )
		{
			wl::SStrf::s2b(strValPARA,m_PositionNum);
		}
		if( iColNum == 9 )
		{
			m_strStaNameEnShort=strValPARA;
		}
		if( iColNum == 10 )
		{
			m_strStaNameEn=strValPARA;
		}
		if( iColNum == 11 )
		{
			m_lStaNameCh=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_CcNode);
		}
		if( iColNum == 13 )
		{
			wl::SStrf::s2b(strValPARA,m_TimeTableWeiHu);
		}
		if( iColNum == 14 )
		{
			wl::SStrf::s2b(strValPARA,m_TimeTableShenJi);
		}
		if( iColNum == 15 )
		{
			m_RES01=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			wl::SStrf::s2b(strValPARA,m_RES02);
		}
		if( iColNum == 17 )
		{
			wl::SStrf::s2b(strValPARA,m_StaWorkTime);
		}
		if( iColNum == 18 )
		{
			m_RES03=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
	}

////////////////////////////////////////////////////////////
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
		if( strColName == "ScNode" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "PositionNum" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "strStaNameEnShort" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "strStaNameEn" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "lStaNameCh" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "CcNode" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "TimeTableWeiHu" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "TimeTableShenJi" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "RES01" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "RES02" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "StaWorkTime" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "RES03" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
	}

}
; 
//end of class a1040_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a1040_t
class a1040_t {
 
private:

	a1040_t_rowtype m_EmptyRow;
	std::vector<a1040_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a1040_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a1040_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a1040_t()
	{
	}

	virtual ~a1040_t(){;}
	

	//operator == 
	bool operator == (const a1040_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a1040_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a1040_t & rhs) const
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

	a1040_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a1040_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

/////////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

/////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a1040_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

///////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a1040_t_rowtype tmpEmptyrow;
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

//////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a1040_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

///////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

/////////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

///////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a1040_t * p = new a1040_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

///////////////////////////////////////////////////////////////
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
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_lVer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lVer(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_strAffectDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strAffectDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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

////////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_ScNode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ScNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ScNode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_ScNode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_ScNode(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ScNode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_ScNode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ScNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ScNode(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_PositionNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PositionNum(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PositionNum==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_PositionNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_PositionNum(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_PositionNum( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_PositionNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PositionNum(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PositionNum(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_strStaNameEnShort
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStaNameEnShort(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStaNameEnShort==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_strStaNameEnShort
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strStaNameEnShort(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStaNameEnShort( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_strStaNameEnShort
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStaNameEnShort(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStaNameEnShort(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_strStaNameEn
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStaNameEn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStaNameEn==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_strStaNameEn
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_strStaNameEn(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStaNameEn( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_strStaNameEn
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStaNameEn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStaNameEn(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_lStaNameCh
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lStaNameCh(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lStaNameCh==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_lStaNameCh
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_lStaNameCh(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lStaNameCh( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_lStaNameCh
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lStaNameCh(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lStaNameCh(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_CcNode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CcNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CcNode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_CcNode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_CcNode(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CcNode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_CcNode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CcNode(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CcNode(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_TimeTableWeiHu
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimeTableWeiHu(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimeTableWeiHu==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_TimeTableWeiHu
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_TimeTableWeiHu(longarr2v_t<7,96> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TimeTableWeiHu( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_TimeTableWeiHu
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimeTableWeiHu(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimeTableWeiHu(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_TimeTableShenJi
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimeTableShenJi(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimeTableShenJi==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_TimeTableShenJi
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_TimeTableShenJi(longarr2v_t<7,96> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TimeTableShenJi( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_TimeTableShenJi
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimeTableShenJi(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimeTableShenJi(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_RES01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_RES01(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
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
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_RES02(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES02( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES02(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES02(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_StaWorkTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_StaWorkTime(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_StaWorkTime==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_StaWorkTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_StaWorkTime(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_StaWorkTime( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_StaWorkTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_StaWorkTime(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_StaWorkTime(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_RES03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES03==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a1040_t_rowtype&
	a1040_t_rowtype & SelE1_RES03(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES03( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
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
//end of class a1040_t


#endif

