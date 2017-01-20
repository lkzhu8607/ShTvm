
#ifndef V1_3AB8705_T_20150815_162415
#define V1_3AB8705_T_20150815_162415

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of b8705_t
//Name:	b8705_t_rowtype
class b8705_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		纸币找零-b8705 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	int		m_ConnState;			// a	1	机器 1=联接 0=失联 
	int		m_RtnVal;			// a	2	调用的返回值 
	int		m_BigErr;			// a	3	大出错，人工干预 
	int		m_BillchgStopUseFlag;			// a	4	停用标记,0=使用，1=停用 
	u8arr_t<4>		m_ver1;			// a	5	 版本号1 
	uiarr_t<long,7>		m_RWerror;			// a	6	int RWerror[7] 读写钱箱后读取 
	uiarr_t<long,3>		m_BoxState;			// a	7	0x02=未被安装到,0x03=已经安装正在运营,0x04=维护中 
	uiarr_t<long,3>		m_LineID;			// a	8	 LineID;//线路ID 
	uiarr_t<long,3>		m_StationID;			// a	9	车站ID 
	uiarr_t<long,3>		m_err;			// a	10	错误码 
	uiarr_t<long,3>		m_Denomination;			// a	11	纸币面额	现实数据 
	uiarr_t<long,3>		m_Number;			// a	12	纸币张数	现实数据 
	uiarr_t<long,3>		m_Count;			// a	13	金额	现实数据 
	uiarr_t<long,3>		m_Denomination_TmpRead;			// a	14	读出来的 纸币面额	读出值是作为临时空间使用，存盘后无意义。每次都是读出再判断是否作为现实数据使用，还是就使用存盘时的现实数据 
	uiarr_t<long,3>		m_Number_TmpRead;			// a	15	读出来的 纸币张数 
	uiarr_t<long,3>		m_Count_TmpRead;			// a	16	读出来的 金额 
	uiarr_t<long,3>		m_rfid_ret_flag_arr;			// a	17	写RFID时的返回值	值是0则说明写RFID成功，则读出的值就当作现实数据。是其它值则读RFID的原始数据与现实数据有差异不能覆盖现实数据。 
	int		m_rfid_ret_flag;			// a	18	本次调用的返回值 
	wl::tuint8		m_Major;			// a	19	主版本号 
	wl::tuint8		m_Minor;			// a	20	副版本号 
	uiarr_t<long,3>		m_OutNumber;			// a	21	找出的纸币数目 
	uiarr_t<long,3>		m_rejectNumber;			// a	22	找出的纸币废币数目 
	uiarr_t<long,3>		m_boxExist;			// a	23	箱存在	0=存在 1=不存在 
	uiarr_t<long,3>		m_boxNearEmpty;			// a	24	即将空	0=不空  1=将空 
	uiarr_t<long,3>		m_boxFull;			// a	25	回收箱满,只有[2]有用。 
	uiarr_t<long,3>		m_boxIsEmpty;			// a	26	0=不空  1=空	只有[0]，[1]有用。 
	int		m_RES_02;			// a	27	[保留] 
	int		m_RES_03;			// a	28	[保留] 
 
public:

	b8705_t_rowtype()
	{
		m_strTblName = "b8705";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_ConnState = 0;
		m_RtnVal = 0;
		m_BigErr = 0;
		m_BillchgStopUseFlag = 0;
		//m_ver1 = //use default
		//m_RWerror = //use default
		//m_BoxState = //use default
		//m_LineID = //use default
		//m_StationID = //use default
		//m_err = //use default
		//m_Denomination = //use default
		//m_Number = //use default
		//m_Count = //use default
		//m_Denomination_TmpRead = //use default
		//m_Number_TmpRead = //use default
		//m_Count_TmpRead = //use default
		//m_rfid_ret_flag_arr = //use default
		m_rfid_ret_flag = 0;
		m_Major = 0;
		m_Minor = 0;
		//m_OutNumber = //use default
		//m_rejectNumber = //use default
		//m_boxExist = //use default
		//m_boxNearEmpty = //use default
		//m_boxFull = //use default
		//m_boxIsEmpty = //use default
		m_RES_02 = 0;
		m_RES_03 = 0;
	}

	virtual ~b8705_t_rowtype(){;}
	

	//operator == 
	bool operator == (const b8705_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8705_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8705_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillchgStopUseFlag));
		len1 = sizeof(m_BillchgStopUseFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ver1));
		len1 = sizeof(m_ver1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RWerror));
		len1 = sizeof(m_RWerror);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BoxState));
		len1 = sizeof(m_BoxState);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineID));
		len1 = sizeof(m_LineID);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StationID));
		len1 = sizeof(m_StationID);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_err));
		len1 = sizeof(m_err);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Denomination));
		len1 = sizeof(m_Denomination);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Number));
		len1 = sizeof(m_Number);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Count));
		len1 = sizeof(m_Count);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Denomination_TmpRead));
		len1 = sizeof(m_Denomination_TmpRead);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Number_TmpRead));
		len1 = sizeof(m_Number_TmpRead);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Count_TmpRead));
		len1 = sizeof(m_Count_TmpRead);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rfid_ret_flag_arr));
		len1 = sizeof(m_rfid_ret_flag_arr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rfid_ret_flag));
		len1 = sizeof(m_rfid_ret_flag);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
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

	b8705_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_BillchgStopUseFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ver1 = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RWerror = *(uiarr_t<long,7>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BoxState = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LineID = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_StationID = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_err = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Denomination = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Number = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Count = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Denomination_TmpRead = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Number_TmpRead = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Count_TmpRead = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_rfid_ret_flag_arr = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_rfid_ret_flag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Major = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Minor = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_OutNumber = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_rejectNumber = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxExist = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxNearEmpty = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxFull = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_boxIsEmpty = *(uiarr_t<long,3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_02 = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_03 = *(int*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillchgStopUseFlag));
		len1 = sizeof(m_BillchgStopUseFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ver1));
		len1 = sizeof(m_ver1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RWerror));
		len1 = sizeof(m_RWerror);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BoxState));
		len1 = sizeof(m_BoxState);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineID));
		len1 = sizeof(m_LineID);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StationID));
		len1 = sizeof(m_StationID);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_err));
		len1 = sizeof(m_err);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Denomination));
		len1 = sizeof(m_Denomination);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Number));
		len1 = sizeof(m_Number);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Count));
		len1 = sizeof(m_Count);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Denomination_TmpRead));
		len1 = sizeof(m_Denomination_TmpRead);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Number_TmpRead));
		len1 = sizeof(m_Number_TmpRead);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Count_TmpRead));
		len1 = sizeof(m_Count_TmpRead);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rfid_ret_flag_arr));
		len1 = sizeof(m_rfid_ret_flag_arr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rfid_ret_flag));
		len1 = sizeof(m_rfid_ret_flag);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OutNumber));
		len1 = sizeof(m_OutNumber);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_rejectNumber));
		len1 = sizeof(m_rejectNumber);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxFull));
		len1 = sizeof(m_boxFull);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_boxIsEmpty));
		len1 = sizeof(m_boxIsEmpty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_03));
		len1 = sizeof(m_RES_03);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	b8705_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_BillchgStopUseFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ver1 = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RWerror = *(uiarr_t<long,7>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BoxState = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LineID = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_StationID = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_err = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Denomination = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Number = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Count = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Denomination_TmpRead = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Number_TmpRead = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Count_TmpRead = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_rfid_ret_flag_arr = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_rfid_ret_flag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Major = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Minor = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_OutNumber = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_rejectNumber = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxExist = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxNearEmpty = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxFull = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_boxIsEmpty = *(uiarr_t<long,3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_02 = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_03 = *(int*)buf2;
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
//Function:	GetCol_BillchgStopUseFlag
//Effect:	get ref of col. col is BillchgStopUseFlag
//Return:	int & 
	int & GetCol_BillchgStopUseFlag(void)
	{
		return m_BillchgStopUseFlag;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_ver1
//Effect:	get ref of col. col is ver1
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_ver1(void)
	{
		return m_ver1;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RWerror
//Effect:	get ref of col. col is RWerror
//Return:	uiarr_t<long,7> & 
	uiarr_t<long,7> & GetCol_RWerror(void)
	{
		return m_RWerror;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_BoxState
//Effect:	get ref of col. col is BoxState
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_BoxState(void)
	{
		return m_BoxState;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_LineID
//Effect:	get ref of col. col is LineID
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_LineID(void)
	{
		return m_LineID;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_StationID
//Effect:	get ref of col. col is StationID
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_StationID(void)
	{
		return m_StationID;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_err
//Effect:	get ref of col. col is err
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_err(void)
	{
		return m_err;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Denomination
//Effect:	get ref of col. col is Denomination
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Denomination(void)
	{
		return m_Denomination;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Number
//Effect:	get ref of col. col is Number
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Number(void)
	{
		return m_Number;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_Count
//Effect:	get ref of col. col is Count
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Count(void)
	{
		return m_Count;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_Denomination_TmpRead
//Effect:	get ref of col. col is Denomination_TmpRead
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Denomination_TmpRead(void)
	{
		return m_Denomination_TmpRead;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Number_TmpRead
//Effect:	get ref of col. col is Number_TmpRead
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Number_TmpRead(void)
	{
		return m_Number_TmpRead;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_Count_TmpRead
//Effect:	get ref of col. col is Count_TmpRead
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_Count_TmpRead(void)
	{
		return m_Count_TmpRead;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_rfid_ret_flag_arr
//Effect:	get ref of col. col is rfid_ret_flag_arr
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_rfid_ret_flag_arr(void)
	{
		return m_rfid_ret_flag_arr;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_rfid_ret_flag
//Effect:	get ref of col. col is rfid_ret_flag
//Return:	int & 
	int & GetCol_rfid_ret_flag(void)
	{
		return m_rfid_ret_flag;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_Major
//Effect:	get ref of col. col is Major
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Major(void)
	{
		return m_Major;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_Minor
//Effect:	get ref of col. col is Minor
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Minor(void)
	{
		return m_Minor;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_OutNumber
//Effect:	get ref of col. col is OutNumber
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_OutNumber(void)
	{
		return m_OutNumber;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_rejectNumber
//Effect:	get ref of col. col is rejectNumber
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_rejectNumber(void)
	{
		return m_rejectNumber;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_boxExist
//Effect:	get ref of col. col is boxExist
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_boxExist(void)
	{
		return m_boxExist;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_boxNearEmpty
//Effect:	get ref of col. col is boxNearEmpty
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_boxNearEmpty(void)
	{
		return m_boxNearEmpty;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_boxFull
//Effect:	get ref of col. col is boxFull
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_boxFull(void)
	{
		return m_boxFull;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_boxIsEmpty
//Effect:	get ref of col. col is boxIsEmpty
//Return:	uiarr_t<long,3> & 
	uiarr_t<long,3> & GetCol_boxIsEmpty(void)
	{
		return m_boxIsEmpty;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	int & 
	int & GetCol_RES_02(void)
	{
		return m_RES_02;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES_03
//Effect:	get ref of col. col is RES_03
//Return:	int & 
	int & GetCol_RES_03(void)
	{
		return m_RES_03;
	}

 
public:

///////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 35;
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
			return "BillchgStopUseFlag";
		}
		if( iColNum == 11 )
		{
			return "ver1";
		}
		if( iColNum == 12 )
		{
			return "RWerror";
		}
		if( iColNum == 13 )
		{
			return "BoxState";
		}
		if( iColNum == 14 )
		{
			return "LineID";
		}
		if( iColNum == 15 )
		{
			return "StationID";
		}
		if( iColNum == 16 )
		{
			return "err";
		}
		if( iColNum == 17 )
		{
			return "Denomination";
		}
		if( iColNum == 18 )
		{
			return "Number";
		}
		if( iColNum == 19 )
		{
			return "Count";
		}
		if( iColNum == 20 )
		{
			return "Denomination_TmpRead";
		}
		if( iColNum == 21 )
		{
			return "Number_TmpRead";
		}
		if( iColNum == 22 )
		{
			return "Count_TmpRead";
		}
		if( iColNum == 23 )
		{
			return "rfid_ret_flag_arr";
		}
		if( iColNum == 24 )
		{
			return "rfid_ret_flag";
		}
		if( iColNum == 25 )
		{
			return "Major";
		}
		if( iColNum == 26 )
		{
			return "Minor";
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
			return "boxExist";
		}
		if( iColNum == 30 )
		{
			return "boxNearEmpty";
		}
		if( iColNum == 31 )
		{
			return "boxFull";
		}
		if( iColNum == 32 )
		{
			return "boxIsEmpty";
		}
		if( iColNum == 33 )
		{
			return "RES_02";
		}
		if( iColNum == 34 )
		{
			return "RES_03";
		}
		return "";
	}

////////////////////////////////////////////////////////////
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
		if( strColName == "BillchgStopUseFlag" )
		{
			return 10;
		}
		if( strColName == "ver1" )
		{
			return 11;
		}
		if( strColName == "RWerror" )
		{
			return 12;
		}
		if( strColName == "BoxState" )
		{
			return 13;
		}
		if( strColName == "LineID" )
		{
			return 14;
		}
		if( strColName == "StationID" )
		{
			return 15;
		}
		if( strColName == "err" )
		{
			return 16;
		}
		if( strColName == "Denomination" )
		{
			return 17;
		}
		if( strColName == "Number" )
		{
			return 18;
		}
		if( strColName == "Count" )
		{
			return 19;
		}
		if( strColName == "Denomination_TmpRead" )
		{
			return 20;
		}
		if( strColName == "Number_TmpRead" )
		{
			return 21;
		}
		if( strColName == "Count_TmpRead" )
		{
			return 22;
		}
		if( strColName == "rfid_ret_flag_arr" )
		{
			return 23;
		}
		if( strColName == "rfid_ret_flag" )
		{
			return 24;
		}
		if( strColName == "Major" )
		{
			return 25;
		}
		if( strColName == "Minor" )
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
		if( strColName == "boxExist" )
		{
			return 29;
		}
		if( strColName == "boxNearEmpty" )
		{
			return 30;
		}
		if( strColName == "boxFull" )
		{
			return 31;
		}
		if( strColName == "boxIsEmpty" )
		{
			return 32;
		}
		if( strColName == "RES_02" )
		{
			return 33;
		}
		if( strColName == "RES_03" )
		{
			return 34;
		}
		return -1;
	}

//////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_BillchgStopUseFlag);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::b2s(m_ver1);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_RWerror);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::b2s(m_BoxState);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::b2s(m_LineID);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::b2s(m_StationID);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::b2s(m_err);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::b2s(m_Denomination);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::b2s(m_Number);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::b2s(m_Count);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::b2s(m_Denomination_TmpRead);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::b2s(m_Number_TmpRead);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_Count_TmpRead);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::b2s(m_rfid_ret_flag_arr);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_rfid_ret_flag);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_Major);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_Minor);
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
			return wl::SStrf::b2s(m_boxExist);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::b2s(m_boxNearEmpty);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::b2s(m_boxFull);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::b2s(m_boxIsEmpty);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_RES_02);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_RES_03);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

////////////////////////////////////////////////////////////////
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
		if( strColName == "BillchgStopUseFlag" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "ver1" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "RWerror" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "BoxState" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "LineID" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "StationID" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "err" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "Denomination" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "Number" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "Count" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "Denomination_TmpRead" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "Number_TmpRead" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "Count_TmpRead" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "rfid_ret_flag_arr" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "rfid_ret_flag" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "Major" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "Minor" )
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
		if( strColName == "boxExist" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "boxNearEmpty" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "boxFull" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "boxIsEmpty" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "RES_03" )
		{
			return GetColStr<STRINGT>(34);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

//////////////////////////////////////////////////////////////
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
			m_BillchgStopUseFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			wl::SStrf::s2b(strValPARA,m_ver1);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_RWerror);
		}
		if( iColNum == 13 )
		{
			wl::SStrf::s2b(strValPARA,m_BoxState);
		}
		if( iColNum == 14 )
		{
			wl::SStrf::s2b(strValPARA,m_LineID);
		}
		if( iColNum == 15 )
		{
			wl::SStrf::s2b(strValPARA,m_StationID);
		}
		if( iColNum == 16 )
		{
			wl::SStrf::s2b(strValPARA,m_err);
		}
		if( iColNum == 17 )
		{
			wl::SStrf::s2b(strValPARA,m_Denomination);
		}
		if( iColNum == 18 )
		{
			wl::SStrf::s2b(strValPARA,m_Number);
		}
		if( iColNum == 19 )
		{
			wl::SStrf::s2b(strValPARA,m_Count);
		}
		if( iColNum == 20 )
		{
			wl::SStrf::s2b(strValPARA,m_Denomination_TmpRead);
		}
		if( iColNum == 21 )
		{
			wl::SStrf::s2b(strValPARA,m_Number_TmpRead);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_Count_TmpRead);
		}
		if( iColNum == 23 )
		{
			wl::SStrf::s2b(strValPARA,m_rfid_ret_flag_arr);
		}
		if( iColNum == 24 )
		{
			m_rfid_ret_flag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_Major=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_Minor=(wl::tuint8)wl::SStrf::satol(strValPARA);
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
			wl::SStrf::s2b(strValPARA,m_boxExist);
		}
		if( iColNum == 30 )
		{
			wl::SStrf::s2b(strValPARA,m_boxNearEmpty);
		}
		if( iColNum == 31 )
		{
			wl::SStrf::s2b(strValPARA,m_boxFull);
		}
		if( iColNum == 32 )
		{
			wl::SStrf::s2b(strValPARA,m_boxIsEmpty);
		}
		if( iColNum == 33 )
		{
			m_RES_02=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_RES_03=wl::SStrf::satol(strValPARA);
		}
	}

/////////////////////////////////////////////////////////////////
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
		if( strColName == "BillchgStopUseFlag" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "ver1" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "RWerror" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "BoxState" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "LineID" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "StationID" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "err" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "Denomination" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "Number" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "Count" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "Denomination_TmpRead" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "Number_TmpRead" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "Count_TmpRead" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "rfid_ret_flag_arr" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "rfid_ret_flag" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "Major" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "Minor" )
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
		if( strColName == "boxExist" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "boxNearEmpty" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "boxFull" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "boxIsEmpty" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "RES_03" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
	}

}
; 
//end of class b8705_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	b8705_t
class b8705_t {
 
private:

	b8705_t_rowtype m_EmptyRow;
	std::vector<b8705_t_rowtype>  m_DATAcorpora;
 
public:

	typedef b8705_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<b8705_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	b8705_t()
	{
	}

	virtual ~b8705_t(){;}
	

	//operator == 
	bool operator == (const b8705_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8705_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8705_t & rhs) const
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

	b8705_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	b8705_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

////////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			b8705_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			b8705_t_rowtype tmpEmptyrow;
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

/////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const b8705_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
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
		b8705_t * p = new b8705_t;
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_strTblName(std::string strVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_lVer(long iVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_strDataRef(std::string strVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_ConnState(int iVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_RtnVal(int iVal) 
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_BigErr(int iVal) 
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
//Function:	SelE_BillchgStopUseFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BillchgStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BillchgStopUseFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_BillchgStopUseFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_BillchgStopUseFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BillchgStopUseFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_BillchgStopUseFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BillchgStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BillchgStopUseFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_ver1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ver1(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ver1==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_ver1
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_ver1(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_ver1( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_ver1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ver1(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ver1(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_RWerror
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RWerror(uiarr_t<long,7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RWerror==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_RWerror
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_RWerror(uiarr_t<long,7> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RWerror( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_RWerror
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RWerror(uiarr_t<long,7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RWerror(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_BoxState
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BoxState(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BoxState==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_BoxState
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_BoxState(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_BoxState( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_BoxState
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BoxState(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BoxState(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_LineID
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LineID(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LineID==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_LineID
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_LineID(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_LineID( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_LineID
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LineID(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LineID(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_StationID
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_StationID(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_StationID==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_StationID
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_StationID(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_StationID( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_StationID
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_StationID(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_StationID(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_err
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_err(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_err==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_err
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_err(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_err( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_err
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_err(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_err(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_Denomination
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Denomination(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Denomination==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_Denomination
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Denomination(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Denomination( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_Denomination
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Denomination(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Denomination(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_Number
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Number(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Number==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_Number
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Number(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Number( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_Number
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Number(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Number(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_Count
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Count(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Count==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_Count
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Count(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Count( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_Count
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Count(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Count(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_Denomination_TmpRead
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Denomination_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Denomination_TmpRead==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_Denomination_TmpRead
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Denomination_TmpRead(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Denomination_TmpRead( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_Denomination_TmpRead
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Denomination_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Denomination_TmpRead(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_Number_TmpRead
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Number_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Number_TmpRead==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_Number_TmpRead
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Number_TmpRead(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Number_TmpRead( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_Number_TmpRead
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Number_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Number_TmpRead(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_Count_TmpRead
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Count_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Count_TmpRead==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_Count_TmpRead
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Count_TmpRead(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_Count_TmpRead( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_Count_TmpRead
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Count_TmpRead(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Count_TmpRead(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_rfid_ret_flag_arr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_rfid_ret_flag_arr(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_rfid_ret_flag_arr==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_rfid_ret_flag_arr
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_rfid_ret_flag_arr(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_rfid_ret_flag_arr( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_rfid_ret_flag_arr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_rfid_ret_flag_arr(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_rfid_ret_flag_arr(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_rfid_ret_flag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_rfid_ret_flag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_rfid_ret_flag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_rfid_ret_flag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_rfid_ret_flag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_rfid_ret_flag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_rfid_ret_flag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_rfid_ret_flag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_rfid_ret_flag(iVal, vRps, pRefRps);
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

///////////////////////////////////////////////////////////
//Function:	SelE1_Major
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Major(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Major( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_Major
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Major(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_Minor(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Minor( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_Minor
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Minor(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Minor(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_OutNumber
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_OutNumber(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_OutNumber==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_OutNumber
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_OutNumber(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_OutNumber( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_OutNumber
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_OutNumber(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_OutNumber(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_rejectNumber
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_rejectNumber(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_rejectNumber==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_rejectNumber
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_rejectNumber(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_rejectNumber( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_rejectNumber
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_rejectNumber(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_rejectNumber(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_boxExist
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxExist(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxExist==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_boxExist
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_boxExist(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxExist( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_boxExist
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxExist(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxExist(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_boxNearEmpty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxNearEmpty(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxNearEmpty==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_boxNearEmpty
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_boxNearEmpty(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxNearEmpty( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_boxNearEmpty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxNearEmpty(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxNearEmpty(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_boxFull
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxFull(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxFull==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_boxFull
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_boxFull(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxFull( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_boxFull
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxFull(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxFull(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_boxIsEmpty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_boxIsEmpty(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_boxIsEmpty==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_boxIsEmpty
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_boxIsEmpty(uiarr_t<long,3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_boxIsEmpty( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_boxIsEmpty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_boxIsEmpty(uiarr_t<long,3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_boxIsEmpty(aVal, vRps, pRefRps);
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
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_RES_02(int iVal) 
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
//Function:	SelE_RES_03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_03(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_03==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES_03
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8705_t_rowtype&
	b8705_t_rowtype & SelE1_RES_03(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_03( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_RES_03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_03(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_03(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
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
//end of class b8705_t


#endif

