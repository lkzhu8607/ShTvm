
#ifndef V1_3AB8701_T_20170220_102515
#define V1_3AB8701_T_20170220_102515

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of b8701_t
//Name:	b8701_t_rowtype
class b8701_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		硬币b8701 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	//#.硬币状态字段：
	int		m_ConnState;			// a	1	机器 1=联接 0=失联 
	int		m_RtnVal;			// a	2	调用的返回值 
	int		m_BigErr;			// a	3	大出错，人工干预 
	int		m_CoinStopUseFlag;			// a	4	停用标记,0=使用，1=停用 
	int		m_UseWithOpenFlag;			// a	5	开门售票模式标记,0=不可，1=可以开门售票 
	//#.硬币统计字段：
	long		m_A1YuanSpecialChg;			// a	6	1元专用找零	钱币个数	//现在用补币数量计数，清币时，将值清除 
	long		m_A5MaoSpecialChg;			// a	7	5Mao专用找零	钱币个数 
	long		m_A1YuanCycleChg;			// a	8	1元循环找零	钱币个数 
	long		m_A5MaoCycleChg;			// a	9	5Mao循环找零	钱币个数 
	long		m_A1YuanStoreBox;			// a	10	1元 回收箱 	钱币个数 
	long		m_A5MaoStoreBox;			// a	11	5Mao 回收箱	钱币个数 
	long		m_A1YuanTicketOutlet;			// a	12	1元 TicketOutlet 取票口	钱币个数 
	long		m_A5MaoTicketOutlet;			// a	13	5Mao TicketOutlet 取票口	钱币个数 
	long		m_A1YuanShortTerm;			// a	14	1元 暂存	钱币个数 
	long		m_A5MaoShortTerm;			// a	15	5Mao 暂存	钱币个数 
	//#.各寄存器
	u8arr_t<8>		m_SensorStatus;			// a	16	2.3硬币模块状态查询0x31 
	wl::tuint8		m_Major;			// a	17	主版本号 
	wl::tuint8		m_Minor;			// a	18	副版本号 
	u8arr_t<3>		m_CoinChangeData;			// a	19	2.7硬币模块找零命令0x00 
	u8arr_t<2>		m_CoinCleanData;			// a	20	2.9硬币模块清币命令0x02 
	long		m_CoinCleanCount;			// a	21	清币数据数目 
	u8arr_t<2>		m_CoinOpenCloseData;			// a	22	2.11硬币模块电磁铁开关命令0x04 
	u8arr_t<3>		m_CoinPollData;			// a	23	2.12硬币识别器轮询0x05	Data2[0] 已接受1元硬币个数 /Data2[1]已接受5角硬币个数 
	u8arr_t<2>		m_CoinAddData;			// a	24	2.13硬币模块补币箱加币命令0x06 
	long		m_CoinAddCount;			// a	25	币数目 
	u8arr_t<3>		m_CoinSupplementaryData;			// a	26	补币数据 
	long		m_CoinAddCountForYunYing;			// a	27	运营日内硬币加币总额	运营开始清除 
	long		m_CoinCleanCountForYunYing;			// a	28	运营日内清币总额	运营开始清除 
	long		m_CoinChgCountYunYingStart;			// a	29	运营开始时找零箱总额	运营开始赋值 
	int		m_RES_01;			// a	30	[保留] 
	int		m_RES_02;			// a	31	[保留] 
 
public:

	b8701_t_rowtype()
	{
		m_strTblName = "b8701";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_ConnState = 0;
		m_RtnVal = 0;
		m_BigErr = 0;
		m_CoinStopUseFlag = 0;
		m_UseWithOpenFlag = 0;
		m_A1YuanSpecialChg = 0;
		m_A5MaoSpecialChg = 0;
		m_A1YuanCycleChg = 0;
		m_A5MaoCycleChg = 0;
		m_A1YuanStoreBox = 0;
		m_A5MaoStoreBox = 0;
		m_A1YuanTicketOutlet = 0;
		m_A5MaoTicketOutlet = 0;
		m_A1YuanShortTerm = 0;
		m_A5MaoShortTerm = 0;
		//m_SensorStatus = //use default
		m_Major = 0;
		m_Minor = 0;
		//m_CoinChangeData = //use default
		//m_CoinCleanData = //use default
		m_CoinCleanCount = 0;
		//m_CoinOpenCloseData = //use default
		//m_CoinPollData = //use default
		//m_CoinAddData = //use default
		m_CoinAddCount = 0;
		//m_CoinSupplementaryData = //use default
		m_CoinAddCountForYunYing = 0;
		m_CoinCleanCountForYunYing = 0;
		m_CoinChgCountYunYingStart = 0;
		m_RES_01 = 0;
		m_RES_02 = 0;
	}

	virtual ~b8701_t_rowtype(){;}
	

	//operator == 
	bool operator == (const b8701_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8701_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8701_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinStopUseFlag));
		len1 = sizeof(m_CoinStopUseFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_UseWithOpenFlag));
		len1 = sizeof(m_UseWithOpenFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanSpecialChg));
		len1 = sizeof(m_A1YuanSpecialChg);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoSpecialChg));
		len1 = sizeof(m_A5MaoSpecialChg);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanCycleChg));
		len1 = sizeof(m_A1YuanCycleChg);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoCycleChg));
		len1 = sizeof(m_A5MaoCycleChg);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanStoreBox));
		len1 = sizeof(m_A1YuanStoreBox);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoStoreBox));
		len1 = sizeof(m_A5MaoStoreBox);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanTicketOutlet));
		len1 = sizeof(m_A1YuanTicketOutlet);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoTicketOutlet));
		len1 = sizeof(m_A5MaoTicketOutlet);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanShortTerm));
		len1 = sizeof(m_A1YuanShortTerm);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoShortTerm));
		len1 = sizeof(m_A5MaoShortTerm);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SensorStatus));
		len1 = sizeof(m_SensorStatus);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChangeData));
		len1 = sizeof(m_CoinChangeData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanData));
		len1 = sizeof(m_CoinCleanData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanCount));
		len1 = sizeof(m_CoinCleanCount);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinOpenCloseData));
		len1 = sizeof(m_CoinOpenCloseData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinPollData));
		len1 = sizeof(m_CoinPollData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddData));
		len1 = sizeof(m_CoinAddData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddCount));
		len1 = sizeof(m_CoinAddCount);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSupplementaryData));
		len1 = sizeof(m_CoinSupplementaryData);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddCountForYunYing));
		len1 = sizeof(m_CoinAddCountForYunYing);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanCountForYunYing));
		len1 = sizeof(m_CoinCleanCountForYunYing);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChgCountYunYingStart));
		len1 = sizeof(m_CoinChgCountYunYingStart);
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

	b8701_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_CoinStopUseFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_UseWithOpenFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A1YuanSpecialChg = decode2<long>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A5MaoSpecialChg = decode2<long>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A1YuanCycleChg = decode2<long>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A5MaoCycleChg = decode2<long>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A1YuanStoreBox = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A5MaoStoreBox = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A1YuanTicketOutlet = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A5MaoTicketOutlet = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A1YuanShortTerm = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_A5MaoShortTerm = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SensorStatus = *(u8arr_t<8>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Major = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Minor = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinChangeData = *(u8arr_t<3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinCleanData = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinCleanCount = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinOpenCloseData = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinPollData = *(u8arr_t<3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinAddData = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinAddCount = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinSupplementaryData = *(u8arr_t<3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinAddCountForYunYing = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinCleanCountForYunYing = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinChgCountYunYingStart = *(long*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinStopUseFlag));
		len1 = sizeof(m_CoinStopUseFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_UseWithOpenFlag));
		len1 = sizeof(m_UseWithOpenFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanSpecialChg));
		len1 = sizeof(m_A1YuanSpecialChg);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoSpecialChg));
		len1 = sizeof(m_A5MaoSpecialChg);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanCycleChg));
		len1 = sizeof(m_A1YuanCycleChg);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoCycleChg));
		len1 = sizeof(m_A5MaoCycleChg);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanStoreBox));
		len1 = sizeof(m_A1YuanStoreBox);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoStoreBox));
		len1 = sizeof(m_A5MaoStoreBox);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanTicketOutlet));
		len1 = sizeof(m_A1YuanTicketOutlet);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoTicketOutlet));
		len1 = sizeof(m_A5MaoTicketOutlet);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A1YuanShortTerm));
		len1 = sizeof(m_A1YuanShortTerm);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_A5MaoShortTerm));
		len1 = sizeof(m_A5MaoShortTerm);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SensorStatus));
		len1 = sizeof(m_SensorStatus);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChangeData));
		len1 = sizeof(m_CoinChangeData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanData));
		len1 = sizeof(m_CoinCleanData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanCount));
		len1 = sizeof(m_CoinCleanCount);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinOpenCloseData));
		len1 = sizeof(m_CoinOpenCloseData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinPollData));
		len1 = sizeof(m_CoinPollData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddData));
		len1 = sizeof(m_CoinAddData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddCount));
		len1 = sizeof(m_CoinAddCount);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSupplementaryData));
		len1 = sizeof(m_CoinSupplementaryData);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinAddCountForYunYing));
		len1 = sizeof(m_CoinAddCountForYunYing);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinCleanCountForYunYing));
		len1 = sizeof(m_CoinCleanCountForYunYing);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinChgCountYunYingStart));
		len1 = sizeof(m_CoinChgCountYunYingStart);
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

	b8701_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_CoinStopUseFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_UseWithOpenFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A1YuanSpecialChg = decode2<long>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A5MaoSpecialChg = decode2<long>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A1YuanCycleChg = decode2<long>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A5MaoCycleChg = decode2<long>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A1YuanStoreBox = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A5MaoStoreBox = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A1YuanTicketOutlet = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A5MaoTicketOutlet = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A1YuanShortTerm = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_A5MaoShortTerm = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SensorStatus = *(u8arr_t<8>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Major = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Minor = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinChangeData = *(u8arr_t<3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinCleanData = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinCleanCount = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinOpenCloseData = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinPollData = *(u8arr_t<3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinAddData = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinAddCount = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinSupplementaryData = *(u8arr_t<3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinAddCountForYunYing = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinCleanCountForYunYing = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinChgCountYunYingStart = *(long*)buf2;
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
//Function:	GetCol_CoinStopUseFlag
//Effect:	get ref of col. col is CoinStopUseFlag
//Return:	int & 
	int & GetCol_CoinStopUseFlag(void)
	{
		return m_CoinStopUseFlag;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_UseWithOpenFlag
//Effect:	get ref of col. col is UseWithOpenFlag
//Return:	int & 
	int & GetCol_UseWithOpenFlag(void)
	{
		return m_UseWithOpenFlag;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_A1YuanSpecialChg
//Effect:	get ref of col. col is A1YuanSpecialChg
//Return:	long & 
	long & GetCol_A1YuanSpecialChg(void)
	{
		return m_A1YuanSpecialChg;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_A5MaoSpecialChg
//Effect:	get ref of col. col is A5MaoSpecialChg
//Return:	long & 
	long & GetCol_A5MaoSpecialChg(void)
	{
		return m_A5MaoSpecialChg;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_A1YuanCycleChg
//Effect:	get ref of col. col is A1YuanCycleChg
//Return:	long & 
	long & GetCol_A1YuanCycleChg(void)
	{
		return m_A1YuanCycleChg;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_A5MaoCycleChg
//Effect:	get ref of col. col is A5MaoCycleChg
//Return:	long & 
	long & GetCol_A5MaoCycleChg(void)
	{
		return m_A5MaoCycleChg;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_A1YuanStoreBox
//Effect:	get ref of col. col is A1YuanStoreBox
//Return:	long & 
	long & GetCol_A1YuanStoreBox(void)
	{
		return m_A1YuanStoreBox;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_A5MaoStoreBox
//Effect:	get ref of col. col is A5MaoStoreBox
//Return:	long & 
	long & GetCol_A5MaoStoreBox(void)
	{
		return m_A5MaoStoreBox;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_A1YuanTicketOutlet
//Effect:	get ref of col. col is A1YuanTicketOutlet
//Return:	long & 
	long & GetCol_A1YuanTicketOutlet(void)
	{
		return m_A1YuanTicketOutlet;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_A5MaoTicketOutlet
//Effect:	get ref of col. col is A5MaoTicketOutlet
//Return:	long & 
	long & GetCol_A5MaoTicketOutlet(void)
	{
		return m_A5MaoTicketOutlet;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_A1YuanShortTerm
//Effect:	get ref of col. col is A1YuanShortTerm
//Return:	long & 
	long & GetCol_A1YuanShortTerm(void)
	{
		return m_A1YuanShortTerm;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_A5MaoShortTerm
//Effect:	get ref of col. col is A5MaoShortTerm
//Return:	long & 
	long & GetCol_A5MaoShortTerm(void)
	{
		return m_A5MaoShortTerm;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_SensorStatus
//Effect:	get ref of col. col is SensorStatus
//Return:	u8arr_t<8> & 
	u8arr_t<8> & GetCol_SensorStatus(void)
	{
		return m_SensorStatus;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_Major
//Effect:	get ref of col. col is Major
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Major(void)
	{
		return m_Major;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_Minor
//Effect:	get ref of col. col is Minor
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_Minor(void)
	{
		return m_Minor;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_CoinChangeData
//Effect:	get ref of col. col is CoinChangeData
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_CoinChangeData(void)
	{
		return m_CoinChangeData;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CoinCleanData
//Effect:	get ref of col. col is CoinCleanData
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_CoinCleanData(void)
	{
		return m_CoinCleanData;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CoinCleanCount
//Effect:	get ref of col. col is CoinCleanCount
//Return:	long & 
	long & GetCol_CoinCleanCount(void)
	{
		return m_CoinCleanCount;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CoinOpenCloseData
//Effect:	get ref of col. col is CoinOpenCloseData
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_CoinOpenCloseData(void)
	{
		return m_CoinOpenCloseData;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_CoinPollData
//Effect:	get ref of col. col is CoinPollData
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_CoinPollData(void)
	{
		return m_CoinPollData;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_CoinAddData
//Effect:	get ref of col. col is CoinAddData
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_CoinAddData(void)
	{
		return m_CoinAddData;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_CoinAddCount
//Effect:	get ref of col. col is CoinAddCount
//Return:	long & 
	long & GetCol_CoinAddCount(void)
	{
		return m_CoinAddCount;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_CoinSupplementaryData
//Effect:	get ref of col. col is CoinSupplementaryData
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_CoinSupplementaryData(void)
	{
		return m_CoinSupplementaryData;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_CoinAddCountForYunYing
//Effect:	get ref of col. col is CoinAddCountForYunYing
//Return:	long & 
	long & GetCol_CoinAddCountForYunYing(void)
	{
		return m_CoinAddCountForYunYing;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CoinCleanCountForYunYing
//Effect:	get ref of col. col is CoinCleanCountForYunYing
//Return:	long & 
	long & GetCol_CoinCleanCountForYunYing(void)
	{
		return m_CoinCleanCountForYunYing;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_CoinChgCountYunYingStart
//Effect:	get ref of col. col is CoinChgCountYunYingStart
//Return:	long & 
	long & GetCol_CoinChgCountYunYingStart(void)
	{
		return m_CoinChgCountYunYingStart;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	int & 
	int & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	int & 
	int & GetCol_RES_02(void)
	{
		return m_RES_02;
	}

 
public:

//////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 38;
	}

////////////////////////////////////////////////////////////////
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
			return "CoinStopUseFlag";
		}
		if( iColNum == 11 )
		{
			return "UseWithOpenFlag";
		}
		if( iColNum == 12 )
		{
			return "A1YuanSpecialChg";
		}
		if( iColNum == 13 )
		{
			return "A5MaoSpecialChg";
		}
		if( iColNum == 14 )
		{
			return "A1YuanCycleChg";
		}
		if( iColNum == 15 )
		{
			return "A5MaoCycleChg";
		}
		if( iColNum == 16 )
		{
			return "A1YuanStoreBox";
		}
		if( iColNum == 17 )
		{
			return "A5MaoStoreBox";
		}
		if( iColNum == 18 )
		{
			return "A1YuanTicketOutlet";
		}
		if( iColNum == 19 )
		{
			return "A5MaoTicketOutlet";
		}
		if( iColNum == 20 )
		{
			return "A1YuanShortTerm";
		}
		if( iColNum == 21 )
		{
			return "A5MaoShortTerm";
		}
		if( iColNum == 22 )
		{
			return "SensorStatus";
		}
		if( iColNum == 23 )
		{
			return "Major";
		}
		if( iColNum == 24 )
		{
			return "Minor";
		}
		if( iColNum == 25 )
		{
			return "CoinChangeData";
		}
		if( iColNum == 26 )
		{
			return "CoinCleanData";
		}
		if( iColNum == 27 )
		{
			return "CoinCleanCount";
		}
		if( iColNum == 28 )
		{
			return "CoinOpenCloseData";
		}
		if( iColNum == 29 )
		{
			return "CoinPollData";
		}
		if( iColNum == 30 )
		{
			return "CoinAddData";
		}
		if( iColNum == 31 )
		{
			return "CoinAddCount";
		}
		if( iColNum == 32 )
		{
			return "CoinSupplementaryData";
		}
		if( iColNum == 33 )
		{
			return "CoinAddCountForYunYing";
		}
		if( iColNum == 34 )
		{
			return "CoinCleanCountForYunYing";
		}
		if( iColNum == 35 )
		{
			return "CoinChgCountYunYingStart";
		}
		if( iColNum == 36 )
		{
			return "RES_01";
		}
		if( iColNum == 37 )
		{
			return "RES_02";
		}
		return "";
	}

//////////////////////////////////////////////////////////////
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
		if( strColName == "CoinStopUseFlag" )
		{
			return 10;
		}
		if( strColName == "UseWithOpenFlag" )
		{
			return 11;
		}
		if( strColName == "A1YuanSpecialChg" )
		{
			return 12;
		}
		if( strColName == "A5MaoSpecialChg" )
		{
			return 13;
		}
		if( strColName == "A1YuanCycleChg" )
		{
			return 14;
		}
		if( strColName == "A5MaoCycleChg" )
		{
			return 15;
		}
		if( strColName == "A1YuanStoreBox" )
		{
			return 16;
		}
		if( strColName == "A5MaoStoreBox" )
		{
			return 17;
		}
		if( strColName == "A1YuanTicketOutlet" )
		{
			return 18;
		}
		if( strColName == "A5MaoTicketOutlet" )
		{
			return 19;
		}
		if( strColName == "A1YuanShortTerm" )
		{
			return 20;
		}
		if( strColName == "A5MaoShortTerm" )
		{
			return 21;
		}
		if( strColName == "SensorStatus" )
		{
			return 22;
		}
		if( strColName == "Major" )
		{
			return 23;
		}
		if( strColName == "Minor" )
		{
			return 24;
		}
		if( strColName == "CoinChangeData" )
		{
			return 25;
		}
		if( strColName == "CoinCleanData" )
		{
			return 26;
		}
		if( strColName == "CoinCleanCount" )
		{
			return 27;
		}
		if( strColName == "CoinOpenCloseData" )
		{
			return 28;
		}
		if( strColName == "CoinPollData" )
		{
			return 29;
		}
		if( strColName == "CoinAddData" )
		{
			return 30;
		}
		if( strColName == "CoinAddCount" )
		{
			return 31;
		}
		if( strColName == "CoinSupplementaryData" )
		{
			return 32;
		}
		if( strColName == "CoinAddCountForYunYing" )
		{
			return 33;
		}
		if( strColName == "CoinCleanCountForYunYing" )
		{
			return 34;
		}
		if( strColName == "CoinChgCountYunYingStart" )
		{
			return 35;
		}
		if( strColName == "RES_01" )
		{
			return 36;
		}
		if( strColName == "RES_02" )
		{
			return 37;
		}
		return -1;
	}

/////////////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_CoinStopUseFlag);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_UseWithOpenFlag);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_A1YuanSpecialChg);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_A5MaoSpecialChg);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_A1YuanCycleChg);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_A5MaoCycleChg);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_A1YuanStoreBox);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_A5MaoStoreBox);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_A1YuanTicketOutlet);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_A5MaoTicketOutlet);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_A1YuanShortTerm);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_A5MaoShortTerm);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_SensorStatus);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_Major);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_Minor);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::b2s(m_CoinChangeData);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::b2s(m_CoinCleanData);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_CoinCleanCount);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::b2s(m_CoinOpenCloseData);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::b2s(m_CoinPollData);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::b2s(m_CoinAddData);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_CoinAddCount);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::b2s(m_CoinSupplementaryData);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_CoinAddCountForYunYing);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_CoinCleanCountForYunYing);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_CoinChgCountYunYingStart);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_RES_01);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_RES_02);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

/////////////////////////////////////////////////////////////////
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
		if( strColName == "CoinStopUseFlag" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "UseWithOpenFlag" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "A1YuanSpecialChg" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "A5MaoSpecialChg" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "A1YuanCycleChg" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "A5MaoCycleChg" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "A1YuanStoreBox" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "A5MaoStoreBox" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "A1YuanTicketOutlet" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "A5MaoTicketOutlet" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "A1YuanShortTerm" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "A5MaoShortTerm" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "SensorStatus" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "Major" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "Minor" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "CoinChangeData" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "CoinCleanData" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "CoinCleanCount" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "CoinOpenCloseData" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "CoinPollData" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "CoinAddData" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "CoinAddCount" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "CoinSupplementaryData" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "CoinAddCountForYunYing" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "CoinCleanCountForYunYing" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "CoinChgCountYunYingStart" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(37);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

////////////////////////////////////////////////////////////
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
			m_CoinStopUseFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_UseWithOpenFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_A1YuanSpecialChg=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_A5MaoSpecialChg=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_A1YuanCycleChg=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_A5MaoCycleChg=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_A1YuanStoreBox=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_A5MaoStoreBox=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_A1YuanTicketOutlet=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_A5MaoTicketOutlet=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_A1YuanShortTerm=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_A5MaoShortTerm=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_SensorStatus);
		}
		if( iColNum == 23 )
		{
			m_Major=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_Minor=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinChangeData);
		}
		if( iColNum == 26 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinCleanData);
		}
		if( iColNum == 27 )
		{
			m_CoinCleanCount=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinOpenCloseData);
		}
		if( iColNum == 29 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinPollData);
		}
		if( iColNum == 30 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinAddData);
		}
		if( iColNum == 31 )
		{
			m_CoinAddCount=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			wl::SStrf::s2b(strValPARA,m_CoinSupplementaryData);
		}
		if( iColNum == 33 )
		{
			m_CoinAddCountForYunYing=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_CoinCleanCountForYunYing=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_CoinChgCountYunYingStart=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_RES_01=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_RES_02=wl::SStrf::satol(strValPARA);
		}
	}

////////////////////////////////////////////////////////
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
		if( strColName == "CoinStopUseFlag" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "UseWithOpenFlag" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "A1YuanSpecialChg" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "A5MaoSpecialChg" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "A1YuanCycleChg" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "A5MaoCycleChg" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "A1YuanStoreBox" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "A5MaoStoreBox" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "A1YuanTicketOutlet" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "A5MaoTicketOutlet" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "A1YuanShortTerm" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "A5MaoShortTerm" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "SensorStatus" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "Major" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "Minor" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "CoinChangeData" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "CoinCleanData" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "CoinCleanCount" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "CoinOpenCloseData" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "CoinPollData" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "CoinAddData" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "CoinAddCount" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "CoinSupplementaryData" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "CoinAddCountForYunYing" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "CoinCleanCountForYunYing" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "CoinChgCountYunYingStart" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
	}

}
; 
//end of class b8701_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	b8701_t
class b8701_t {
 
private:

	b8701_t_rowtype m_EmptyRow;
	std::vector<b8701_t_rowtype>  m_DATAcorpora;
 
public:

	typedef b8701_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<b8701_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	b8701_t()
	{
	}

	virtual ~b8701_t(){;}
	

	//operator == 
	bool operator == (const b8701_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const b8701_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const b8701_t & rhs) const
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

	b8701_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	b8701_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

/////////////////////////////////////////////////////////
//Function:	Clear
//Effect:	clear the tbl.
//Return:	no return
	void Clear(void)
	{
		m_DATAcorpora.clear();
	}

////////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

/////////////////////////////////////////////////////////
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
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			b8701_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			b8701_t_rowtype tmpEmptyrow;
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

/////////////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes, if any.
//Return:	no return
	void Add(const b8701_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

/////////////////////////////////////////////////////////////////
//Function:	AddDefaultRow
//Effect:	add one default row using Add function.
//Return:	no return
	void AddDefaultRow()
	{
		Add( b8701_t_rowtype());
	}

/////////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

///////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

/////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		b8701_t * p = new b8701_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

//////////////////////////////////////////////////////////
//Function:	SelE_strTblName
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strTblName==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_strTblName(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTblName( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_strTblName
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTblName(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTblName(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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

//////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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

//////////////////////////////////////////////////////////////
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
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
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
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_strDataRef(std::string strVal) 
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

////////////////////////////////////////////////////////
//Function:	SelE1_ConnState
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_ConnState(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnState( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ConnState
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnState(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnState(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
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
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_RtnVal(int iVal) 
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

//////////////////////////////////////////////////////////
//Function:	SelE1_BigErr
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_BigErr(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BigErr( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_BigErr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BigErr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BigErr(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_CoinStopUseFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinStopUseFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_CoinStopUseFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinStopUseFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinStopUseFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_CoinStopUseFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinStopUseFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinStopUseFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_UseWithOpenFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_UseWithOpenFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_UseWithOpenFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_UseWithOpenFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_UseWithOpenFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_UseWithOpenFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_UseWithOpenFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_UseWithOpenFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_UseWithOpenFlag(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_A1YuanSpecialChg
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A1YuanSpecialChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A1YuanSpecialChg==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_A1YuanSpecialChg
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A1YuanSpecialChg(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A1YuanSpecialChg( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_A1YuanSpecialChg
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A1YuanSpecialChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A1YuanSpecialChg(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_A5MaoSpecialChg
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A5MaoSpecialChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A5MaoSpecialChg==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_A5MaoSpecialChg
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A5MaoSpecialChg(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A5MaoSpecialChg( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_A5MaoSpecialChg
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A5MaoSpecialChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A5MaoSpecialChg(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_A1YuanCycleChg
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A1YuanCycleChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A1YuanCycleChg==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_A1YuanCycleChg
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A1YuanCycleChg(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A1YuanCycleChg( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_A1YuanCycleChg
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A1YuanCycleChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A1YuanCycleChg(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_A5MaoCycleChg
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A5MaoCycleChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A5MaoCycleChg==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_A5MaoCycleChg
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A5MaoCycleChg(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A5MaoCycleChg( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_A5MaoCycleChg
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A5MaoCycleChg(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A5MaoCycleChg(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_A1YuanStoreBox
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A1YuanStoreBox(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A1YuanStoreBox==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_A1YuanStoreBox
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A1YuanStoreBox(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A1YuanStoreBox( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_A1YuanStoreBox
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A1YuanStoreBox(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A1YuanStoreBox(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_A5MaoStoreBox
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A5MaoStoreBox(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A5MaoStoreBox==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_A5MaoStoreBox
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A5MaoStoreBox(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A5MaoStoreBox( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_A5MaoStoreBox
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A5MaoStoreBox(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A5MaoStoreBox(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_A1YuanTicketOutlet
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A1YuanTicketOutlet(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A1YuanTicketOutlet==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_A1YuanTicketOutlet
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A1YuanTicketOutlet(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A1YuanTicketOutlet( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_A1YuanTicketOutlet
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A1YuanTicketOutlet(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A1YuanTicketOutlet(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_A5MaoTicketOutlet
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A5MaoTicketOutlet(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A5MaoTicketOutlet==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_A5MaoTicketOutlet
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A5MaoTicketOutlet(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A5MaoTicketOutlet( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_A5MaoTicketOutlet
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A5MaoTicketOutlet(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A5MaoTicketOutlet(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_A1YuanShortTerm
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A1YuanShortTerm(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A1YuanShortTerm==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_A1YuanShortTerm
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A1YuanShortTerm(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A1YuanShortTerm( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_A1YuanShortTerm
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A1YuanShortTerm(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A1YuanShortTerm(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_A5MaoShortTerm
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_A5MaoShortTerm(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_A5MaoShortTerm==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_A5MaoShortTerm
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_A5MaoShortTerm(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_A5MaoShortTerm( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_A5MaoShortTerm
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_A5MaoShortTerm(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_A5MaoShortTerm(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SensorStatus
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SensorStatus(u8arr_t<8> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SensorStatus==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_SensorStatus
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_SensorStatus(u8arr_t<8> aVal) 
	{
		std::vector<long> vRps ;
		SelE_SensorStatus( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_SensorStatus
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SensorStatus(u8arr_t<8> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SensorStatus(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_Major
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Major==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_Major
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_Major(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Major( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_Major
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Major(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Major(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_Minor
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Minor(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Minor==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_Minor
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_Minor(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_Minor( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_Minor
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Minor(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Minor(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CoinChangeData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinChangeData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinChangeData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_CoinChangeData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinChangeData(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinChangeData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_CoinChangeData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinChangeData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinChangeData(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_CoinCleanData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinCleanData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinCleanData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinCleanData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinCleanData(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinCleanData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinCleanData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinCleanData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinCleanData(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_CoinCleanCount
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinCleanCount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinCleanCount==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_CoinCleanCount
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinCleanCount(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinCleanCount( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_CoinCleanCount
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinCleanCount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinCleanCount(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_CoinOpenCloseData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinOpenCloseData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinOpenCloseData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinOpenCloseData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinOpenCloseData(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinOpenCloseData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_CoinOpenCloseData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinOpenCloseData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinOpenCloseData(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CoinPollData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinPollData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinPollData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_CoinPollData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinPollData(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinPollData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinPollData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinPollData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinPollData(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_CoinAddData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinAddData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinAddData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_CoinAddData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinAddData(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinAddData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_CoinAddData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinAddData(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinAddData(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_CoinAddCount
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinAddCount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinAddCount==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_CoinAddCount
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinAddCount(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinAddCount( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinAddCount
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinAddCount(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinAddCount(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_CoinSupplementaryData
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinSupplementaryData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinSupplementaryData==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_CoinSupplementaryData
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinSupplementaryData(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinSupplementaryData( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinSupplementaryData
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinSupplementaryData(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinSupplementaryData(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_CoinAddCountForYunYing
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinAddCountForYunYing(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinAddCountForYunYing==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinAddCountForYunYing
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinAddCountForYunYing(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinAddCountForYunYing( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_CoinAddCountForYunYing
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinAddCountForYunYing(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinAddCountForYunYing(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_CoinCleanCountForYunYing
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinCleanCountForYunYing(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinCleanCountForYunYing==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_CoinCleanCountForYunYing
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinCleanCountForYunYing(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinCleanCountForYunYing( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_CoinCleanCountForYunYing
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinCleanCountForYunYing(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinCleanCountForYunYing(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_CoinChgCountYunYingStart
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinChgCountYunYingStart(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinChgCountYunYingStart==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_CoinChgCountYunYingStart
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_CoinChgCountYunYingStart(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinChgCountYunYingStart( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_CoinChgCountYunYingStart
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinChgCountYunYingStart(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinChgCountYunYingStart(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_RES_01(int iVal) 
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

////////////////////////////////////////////////////////
//Function:	SelE_RES_02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_02(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_02==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	b8701_t_rowtype&
	b8701_t_rowtype & SelE1_RES_02(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
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
//end of class b8701_t


#endif

