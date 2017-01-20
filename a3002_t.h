
#ifndef V1_3AA3002_T_20140523_160111
#define V1_3AA3002_T_20140523_160111

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a3002_t
//Name:	a3002_t_rowtype
class a3002_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		7.0.5 3002-AFC设备运营参数。此类交互用于向SLE传送AFC设备运营参数。它最初由CC 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	int		m_para1040_valid;			// a	0	是否已成功地从1040复制来相关数据 
	longarr2v_t<7,96>		m_TimeTableWeiHu;			// a	1	维护寄存器数据的报告间隔时间变更表，一周7天，每天96刻钟，值是间隔时间秒  Block 56 
	longarr2v_t<7,96>		m_TimeTableShenJi;			// a	2	审计寄存器数据的报告间隔时间变更表  Block 56 
	u8arr_t<3>		m_StaWorkTime;			// a	3	车站运营时间Byte0：运营开始时间Byte1：运营结束时间Byte2：开始产生车站日终报告的时间单位：15min对应：本地时间00:00~23:45Byte3 
	wl::tuint8		m_RES01;			// a	4	[保留] 
	u8arr_t<2>		m_RES02;			// a	5	[保留] 
	wl::tuint8		m_RES03;			// a	6	[保留] 
	long		m_lLoginTimeout;			// a	7	登录超时时间 秒	系统缺省参数块 见7.0.5-2 Block 20 
	long		m_lLogoutTimeout;			// a	8	签退超时时间 秒 
	long		m_lOperateWaitTimeout;			// a	9	操作等待时间 秒 
	int		m_iTradeStorageCtrl;			// a	10	交易存储满控制0-交易存储满时覆盖最旧的交易1-交易存储满时停止服务 
	long		m_lAlertTimesec;			// a	11	报警时间 表示报警信号的延迟时间 
	long		m_lTradeItemNumTrigger;			// a	12	提交交易数据笔数下限 本地存放的交易数据本笔数即向上提交 
	long		m_lTradeTimesecTrigger;			// a	13	提交交易数据时间上限 秒 
	long		m_lBCU;			// a	14	BCU 基本资金单位的大小，定义为1（=0.01元人民币） 
	long		m_lStatusTimesecTrigger;			// a	15	设备状态定时上传时间间隔  秒 
	u8arr_t<9>		m_RES04;			// a	16	保留  Byte 9 
	u8arr_t<2>		m_RES05;			// a	17	[保留]	硬币处理部件报文格式见表7.0.5-3. 
	wl::tuint8		m_RES06;			// a	18	[保留] 
	wl::tuint8		m_RES07;			// a	19	[保留] 
	wl::tuint8		m_RES08;			// a	20	[保留] 
	int		m_iCoinBoxWillFullPercent;			// a	21	硬币回收箱将满百分比 当硬币多于或等于此时，"硬币回收箱将满"警告被触发 范围：0 ~ 100 
	int		m_iCoinBoxFullPercent;			// a	22	硬币回收箱满百分比 
	long		m_lCoinBoxCapacity;			// a	23	硬币回收箱容量 
	long		m_lCoinBoxLowTrigger;			// a	24	硬币找零箱最低报警参数		硬币找零管记录 
	long		m_lCoinBoxMaxCapacity;			// a	25	硬币找零箱最大容量 
	wl::tuint8		m_RES09;			// a	26	[保留] 
	wl::tuint8		m_RES10;			// a	27	[保留] 
	int		m_iCashBoxWillFullPercent;			// a	28	纸币回收箱将满百分比		纸币处理部件报文格式见表7.0.5-4 
	int		m_iCashBoxFullPercent;			// a	29	纸币回收箱满百分比 
	int		m_iCashChgBoxWillEmptyPercent;			// a	30	纸币找零箱将空百分比 
	long		m_lCashChgBoxCapacity;			// a	31	纸币找零箱最大容量 
	wl::tuint8		m_RES11;			// a	32	[保留] 
	wl::tuint8		m_RES12;			// a	33	[保留] 
	u8arr_t<2>		m_RES13;			// a	34	[保留] 
	u8arr_t<7>		m_RES14;			// a	35	[保留] 
	wl::tuint8		m_RES15;			// a	36	[保留]	“一票通”车票处理部件报文格式见表7.0.5-5. 
	wl::tuint8		m_RES16;			// a	37	[保留] 
	long		m_lTicketReadFailTimes;			// a	38	连续读失败次数[保留 
	long		m_lTicketWriteFailTimes;			// a	39	连续写失败次数 
	u8arr_t<2>		m_RES17;			// a	40	[保留] 
	wl::tuint8		m_RES18;			// a	41	[保留] 
	wl::tuint8		m_RES19;			// a	42	[保留] 
	wl::tuint8		m_RES20;			// a	43	[保留] 
	wl::tuint8		m_RES21;			// a	44	[保留] 
	u8arr_t<7>		m_RES22;			// a	45	[保留] 
	long		m_lCardReadFailTimes;			// a	46	连续读失败次数，为0则不报警		智能卡处理部件 6.交通卡处理部件报文格式见表7.0.5-6. 
	long		m_lCardWriteFailTimes;			// a	47	连续写失败次数，为0则不报警 
	u8arr_t<15>		m_RES23;			// a	48	[保留] 
 
public:

	a3002_t_rowtype()
	{
		m_strTblName = "a3002";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_para1040_valid = 0;
		wl::SStrf::smemset(m_TimeTableWeiHu);
		wl::SStrf::smemset(m_TimeTableShenJi);
		//m_StaWorkTime = //use default
		m_RES01 = 0;
		//m_RES02 = //use default
		m_RES03 = 0;
		m_lLoginTimeout = 0;
		m_lLogoutTimeout = 0;
		m_lOperateWaitTimeout = 0;
		m_iTradeStorageCtrl = 0;
		m_lAlertTimesec = 0;
		m_lTradeItemNumTrigger = 0;
		m_lTradeTimesecTrigger = 0;
		m_lBCU = 0;
		m_lStatusTimesecTrigger = 0;
		//m_RES04 = //use default
		//m_RES05 = //use default
		m_RES06 = 0;
		m_RES07 = 0;
		m_RES08 = 0;
		m_iCoinBoxWillFullPercent = 0;
		m_iCoinBoxFullPercent = 0;
		m_lCoinBoxCapacity = 0;
		m_lCoinBoxLowTrigger = 0;
		m_lCoinBoxMaxCapacity = 0;
		m_RES09 = 0;
		m_RES10 = 0;
		m_iCashBoxWillFullPercent = 0;
		m_iCashBoxFullPercent = 0;
		m_iCashChgBoxWillEmptyPercent = 0;
		m_lCashChgBoxCapacity = 0;
		m_RES11 = 0;
		m_RES12 = 0;
		//m_RES13 = //use default
		//m_RES14 = //use default
		m_RES15 = 0;
		m_RES16 = 0;
		m_lTicketReadFailTimes = 0;
		m_lTicketWriteFailTimes = 0;
		//m_RES17 = //use default
		m_RES18 = 0;
		m_RES19 = 0;
		m_RES20 = 0;
		m_RES21 = 0;
		//m_RES22 = //use default
		m_lCardReadFailTimes = 0;
		m_lCardWriteFailTimes = 0;
		//m_RES23 = //use default
	}

	virtual ~a3002_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a3002_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3002_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3002_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_para1040_valid));
		len1 = sizeof(m_para1040_valid);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StaWorkTime));
		len1 = sizeof(m_StaWorkTime);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lLoginTimeout));
		len1 = sizeof(m_lLoginTimeout);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lLogoutTimeout));
		len1 = sizeof(m_lLogoutTimeout);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lOperateWaitTimeout));
		len1 = sizeof(m_lOperateWaitTimeout);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iTradeStorageCtrl));
		len1 = sizeof(m_iTradeStorageCtrl);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lAlertTimesec));
		len1 = sizeof(m_lAlertTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeItemNumTrigger));
		len1 = sizeof(m_lTradeItemNumTrigger);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeTimesecTrigger));
		len1 = sizeof(m_lTradeTimesecTrigger);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lBCU));
		len1 = sizeof(m_lBCU);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lStatusTimesecTrigger));
		len1 = sizeof(m_lStatusTimesecTrigger);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04));
		len1 = sizeof(m_RES04);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES05));
		len1 = sizeof(m_RES05);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES06));
		len1 = sizeof(m_RES06);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES07));
		len1 = sizeof(m_RES07);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES08));
		len1 = sizeof(m_RES08);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCoinBoxWillFullPercent));
		len1 = sizeof(m_iCoinBoxWillFullPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCoinBoxFullPercent));
		len1 = sizeof(m_iCoinBoxFullPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxCapacity));
		len1 = sizeof(m_lCoinBoxCapacity);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxLowTrigger));
		len1 = sizeof(m_lCoinBoxLowTrigger);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxMaxCapacity));
		len1 = sizeof(m_lCoinBoxMaxCapacity);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES09));
		len1 = sizeof(m_RES09);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES10));
		len1 = sizeof(m_RES10);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashBoxWillFullPercent));
		len1 = sizeof(m_iCashBoxWillFullPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashBoxFullPercent));
		len1 = sizeof(m_iCashBoxFullPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashChgBoxWillEmptyPercent));
		len1 = sizeof(m_iCashChgBoxWillEmptyPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCashChgBoxCapacity));
		len1 = sizeof(m_lCashChgBoxCapacity);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES11));
		len1 = sizeof(m_RES11);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES12));
		len1 = sizeof(m_RES12);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES13));
		len1 = sizeof(m_RES13);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES14));
		len1 = sizeof(m_RES14);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES15));
		len1 = sizeof(m_RES15);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES16));
		len1 = sizeof(m_RES16);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketReadFailTimes));
		len1 = sizeof(m_lTicketReadFailTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketWriteFailTimes));
		len1 = sizeof(m_lTicketWriteFailTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES17));
		len1 = sizeof(m_RES17);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES18));
		len1 = sizeof(m_RES18);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES19));
		len1 = sizeof(m_RES19);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES20));
		len1 = sizeof(m_RES20);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES21));
		len1 = sizeof(m_RES21);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES22));
		len1 = sizeof(m_RES22);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCardReadFailTimes));
		len1 = sizeof(m_lCardReadFailTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCardWriteFailTimes));
		len1 = sizeof(m_lCardWriteFailTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES23));
		len1 = sizeof(m_RES23);
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

	a3002_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_para1040_valid = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimeTableWeiHu = *(longarr2v_t<7,96>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimeTableShenJi = *(longarr2v_t<7,96>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_StaWorkTime = *(u8arr_t<3>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES02 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES03 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lLoginTimeout = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lLogoutTimeout = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lOperateWaitTimeout = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iTradeStorageCtrl = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lAlertTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTradeItemNumTrigger = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTradeTimesecTrigger = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lBCU = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lStatusTimesecTrigger = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES04 = *(u8arr_t<9>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES05 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES06 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES07 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES08 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iCoinBoxWillFullPercent = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iCoinBoxFullPercent = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCoinBoxCapacity = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCoinBoxLowTrigger = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCoinBoxMaxCapacity = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES09 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES10 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iCashBoxWillFullPercent = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iCashBoxFullPercent = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iCashChgBoxWillEmptyPercent = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCashChgBoxCapacity = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES11 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES12 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES13 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES14 = *(u8arr_t<7>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES15 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES16 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTicketReadFailTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTicketWriteFailTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES17 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES18 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES19 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES20 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES21 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES22 = *(u8arr_t<7>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCardReadFailTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lCardWriteFailTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES23 = *(u8arr_t<15>*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_para1040_valid));
		len1 = sizeof(m_para1040_valid);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_StaWorkTime));
		len1 = sizeof(m_StaWorkTime);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lLoginTimeout));
		len1 = sizeof(m_lLoginTimeout);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lLogoutTimeout));
		len1 = sizeof(m_lLogoutTimeout);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lOperateWaitTimeout));
		len1 = sizeof(m_lOperateWaitTimeout);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iTradeStorageCtrl));
		len1 = sizeof(m_iTradeStorageCtrl);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lAlertTimesec));
		len1 = sizeof(m_lAlertTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeItemNumTrigger));
		len1 = sizeof(m_lTradeItemNumTrigger);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeTimesecTrigger));
		len1 = sizeof(m_lTradeTimesecTrigger);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lBCU));
		len1 = sizeof(m_lBCU);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lStatusTimesecTrigger));
		len1 = sizeof(m_lStatusTimesecTrigger);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04));
		len1 = sizeof(m_RES04);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES05));
		len1 = sizeof(m_RES05);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES06));
		len1 = sizeof(m_RES06);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES07));
		len1 = sizeof(m_RES07);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES08));
		len1 = sizeof(m_RES08);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCoinBoxWillFullPercent));
		len1 = sizeof(m_iCoinBoxWillFullPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCoinBoxFullPercent));
		len1 = sizeof(m_iCoinBoxFullPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxCapacity));
		len1 = sizeof(m_lCoinBoxCapacity);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxLowTrigger));
		len1 = sizeof(m_lCoinBoxLowTrigger);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCoinBoxMaxCapacity));
		len1 = sizeof(m_lCoinBoxMaxCapacity);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES09));
		len1 = sizeof(m_RES09);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES10));
		len1 = sizeof(m_RES10);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashBoxWillFullPercent));
		len1 = sizeof(m_iCashBoxWillFullPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashBoxFullPercent));
		len1 = sizeof(m_iCashBoxFullPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iCashChgBoxWillEmptyPercent));
		len1 = sizeof(m_iCashChgBoxWillEmptyPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCashChgBoxCapacity));
		len1 = sizeof(m_lCashChgBoxCapacity);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES11));
		len1 = sizeof(m_RES11);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES12));
		len1 = sizeof(m_RES12);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES13));
		len1 = sizeof(m_RES13);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES14));
		len1 = sizeof(m_RES14);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES15));
		len1 = sizeof(m_RES15);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES16));
		len1 = sizeof(m_RES16);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketReadFailTimes));
		len1 = sizeof(m_lTicketReadFailTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketWriteFailTimes));
		len1 = sizeof(m_lTicketWriteFailTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES17));
		len1 = sizeof(m_RES17);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES18));
		len1 = sizeof(m_RES18);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES19));
		len1 = sizeof(m_RES19);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES20));
		len1 = sizeof(m_RES20);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES21));
		len1 = sizeof(m_RES21);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES22));
		len1 = sizeof(m_RES22);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCardReadFailTimes));
		len1 = sizeof(m_lCardReadFailTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lCardWriteFailTimes));
		len1 = sizeof(m_lCardWriteFailTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES23));
		len1 = sizeof(m_RES23);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a3002_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_para1040_valid = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimeTableWeiHu = *(longarr2v_t<7,96>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimeTableShenJi = *(longarr2v_t<7,96>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_StaWorkTime = *(u8arr_t<3>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES02 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES03 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lLoginTimeout = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lLogoutTimeout = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lOperateWaitTimeout = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iTradeStorageCtrl = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lAlertTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTradeItemNumTrigger = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTradeTimesecTrigger = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lBCU = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lStatusTimesecTrigger = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES04 = *(u8arr_t<9>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES05 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES06 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES07 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES08 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iCoinBoxWillFullPercent = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iCoinBoxFullPercent = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCoinBoxCapacity = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCoinBoxLowTrigger = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCoinBoxMaxCapacity = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES09 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES10 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iCashBoxWillFullPercent = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iCashBoxFullPercent = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iCashChgBoxWillEmptyPercent = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCashChgBoxCapacity = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES11 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES12 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES13 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES14 = *(u8arr_t<7>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES15 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES16 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTicketReadFailTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTicketWriteFailTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES17 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES18 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES19 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES20 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES21 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES22 = *(u8arr_t<7>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCardReadFailTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lCardWriteFailTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES23 = *(u8arr_t<15>*)buf2;
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
//Function:	GetCol_para1040_valid
//Effect:	get ref of col. col is para1040_valid
//Return:	int & 
	int & GetCol_para1040_valid(void)
	{
		return m_para1040_valid;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_TimeTableWeiHu
//Effect:	get ref of col. col is TimeTableWeiHu
//Return:	longarr2v_t<7,96> & 
	longarr2v_t<7,96> & GetCol_TimeTableWeiHu(void)
	{
		return m_TimeTableWeiHu;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TimeTableShenJi
//Effect:	get ref of col. col is TimeTableShenJi
//Return:	longarr2v_t<7,96> & 
	longarr2v_t<7,96> & GetCol_TimeTableShenJi(void)
	{
		return m_TimeTableShenJi;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_StaWorkTime
//Effect:	get ref of col. col is StaWorkTime
//Return:	u8arr_t<3> & 
	u8arr_t<3> & GetCol_StaWorkTime(void)
	{
		return m_StaWorkTime;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_RES01
//Effect:	get ref of col. col is RES01
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01(void)
	{
		return m_RES01;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RES02
//Effect:	get ref of col. col is RES02
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES02(void)
	{
		return m_RES02;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_RES03
//Effect:	get ref of col. col is RES03
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES03(void)
	{
		return m_RES03;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_lLoginTimeout
//Effect:	get ref of col. col is lLoginTimeout
//Return:	long & 
	long & GetCol_lLoginTimeout(void)
	{
		return m_lLoginTimeout;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_lLogoutTimeout
//Effect:	get ref of col. col is lLogoutTimeout
//Return:	long & 
	long & GetCol_lLogoutTimeout(void)
	{
		return m_lLogoutTimeout;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lOperateWaitTimeout
//Effect:	get ref of col. col is lOperateWaitTimeout
//Return:	long & 
	long & GetCol_lOperateWaitTimeout(void)
	{
		return m_lOperateWaitTimeout;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_iTradeStorageCtrl
//Effect:	get ref of col. col is iTradeStorageCtrl
//Return:	int & 
	int & GetCol_iTradeStorageCtrl(void)
	{
		return m_iTradeStorageCtrl;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_lAlertTimesec
//Effect:	get ref of col. col is lAlertTimesec
//Return:	long & 
	long & GetCol_lAlertTimesec(void)
	{
		return m_lAlertTimesec;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_lTradeItemNumTrigger
//Effect:	get ref of col. col is lTradeItemNumTrigger
//Return:	long & 
	long & GetCol_lTradeItemNumTrigger(void)
	{
		return m_lTradeItemNumTrigger;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lTradeTimesecTrigger
//Effect:	get ref of col. col is lTradeTimesecTrigger
//Return:	long & 
	long & GetCol_lTradeTimesecTrigger(void)
	{
		return m_lTradeTimesecTrigger;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_lBCU
//Effect:	get ref of col. col is lBCU
//Return:	long & 
	long & GetCol_lBCU(void)
	{
		return m_lBCU;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_lStatusTimesecTrigger
//Effect:	get ref of col. col is lStatusTimesecTrigger
//Return:	long & 
	long & GetCol_lStatusTimesecTrigger(void)
	{
		return m_lStatusTimesecTrigger;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES04
//Effect:	get ref of col. col is RES04
//Return:	u8arr_t<9> & 
	u8arr_t<9> & GetCol_RES04(void)
	{
		return m_RES04;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_RES05
//Effect:	get ref of col. col is RES05
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES05(void)
	{
		return m_RES05;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RES06
//Effect:	get ref of col. col is RES06
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES06(void)
	{
		return m_RES06;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES07
//Effect:	get ref of col. col is RES07
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES07(void)
	{
		return m_RES07;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES08
//Effect:	get ref of col. col is RES08
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES08(void)
	{
		return m_RES08;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_iCoinBoxWillFullPercent
//Effect:	get ref of col. col is iCoinBoxWillFullPercent
//Return:	int & 
	int & GetCol_iCoinBoxWillFullPercent(void)
	{
		return m_iCoinBoxWillFullPercent;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_iCoinBoxFullPercent
//Effect:	get ref of col. col is iCoinBoxFullPercent
//Return:	int & 
	int & GetCol_iCoinBoxFullPercent(void)
	{
		return m_iCoinBoxFullPercent;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_lCoinBoxCapacity
//Effect:	get ref of col. col is lCoinBoxCapacity
//Return:	long & 
	long & GetCol_lCoinBoxCapacity(void)
	{
		return m_lCoinBoxCapacity;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lCoinBoxLowTrigger
//Effect:	get ref of col. col is lCoinBoxLowTrigger
//Return:	long & 
	long & GetCol_lCoinBoxLowTrigger(void)
	{
		return m_lCoinBoxLowTrigger;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_lCoinBoxMaxCapacity
//Effect:	get ref of col. col is lCoinBoxMaxCapacity
//Return:	long & 
	long & GetCol_lCoinBoxMaxCapacity(void)
	{
		return m_lCoinBoxMaxCapacity;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES09
//Effect:	get ref of col. col is RES09
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES09(void)
	{
		return m_RES09;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES10
//Effect:	get ref of col. col is RES10
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES10(void)
	{
		return m_RES10;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_iCashBoxWillFullPercent
//Effect:	get ref of col. col is iCashBoxWillFullPercent
//Return:	int & 
	int & GetCol_iCashBoxWillFullPercent(void)
	{
		return m_iCashBoxWillFullPercent;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_iCashBoxFullPercent
//Effect:	get ref of col. col is iCashBoxFullPercent
//Return:	int & 
	int & GetCol_iCashBoxFullPercent(void)
	{
		return m_iCashBoxFullPercent;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_iCashChgBoxWillEmptyPercent
//Effect:	get ref of col. col is iCashChgBoxWillEmptyPercent
//Return:	int & 
	int & GetCol_iCashChgBoxWillEmptyPercent(void)
	{
		return m_iCashChgBoxWillEmptyPercent;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_lCashChgBoxCapacity
//Effect:	get ref of col. col is lCashChgBoxCapacity
//Return:	long & 
	long & GetCol_lCashChgBoxCapacity(void)
	{
		return m_lCashChgBoxCapacity;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_RES11
//Effect:	get ref of col. col is RES11
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES11(void)
	{
		return m_RES11;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_RES12
//Effect:	get ref of col. col is RES12
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES12(void)
	{
		return m_RES12;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES13
//Effect:	get ref of col. col is RES13
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES13(void)
	{
		return m_RES13;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES14
//Effect:	get ref of col. col is RES14
//Return:	u8arr_t<7> & 
	u8arr_t<7> & GetCol_RES14(void)
	{
		return m_RES14;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_RES15
//Effect:	get ref of col. col is RES15
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES15(void)
	{
		return m_RES15;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES16
//Effect:	get ref of col. col is RES16
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES16(void)
	{
		return m_RES16;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_lTicketReadFailTimes
//Effect:	get ref of col. col is lTicketReadFailTimes
//Return:	long & 
	long & GetCol_lTicketReadFailTimes(void)
	{
		return m_lTicketReadFailTimes;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_lTicketWriteFailTimes
//Effect:	get ref of col. col is lTicketWriteFailTimes
//Return:	long & 
	long & GetCol_lTicketWriteFailTimes(void)
	{
		return m_lTicketWriteFailTimes;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_RES17
//Effect:	get ref of col. col is RES17
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES17(void)
	{
		return m_RES17;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_RES18
//Effect:	get ref of col. col is RES18
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES18(void)
	{
		return m_RES18;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_RES19
//Effect:	get ref of col. col is RES19
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES19(void)
	{
		return m_RES19;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_RES20
//Effect:	get ref of col. col is RES20
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES20(void)
	{
		return m_RES20;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES21
//Effect:	get ref of col. col is RES21
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES21(void)
	{
		return m_RES21;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES22
//Effect:	get ref of col. col is RES22
//Return:	u8arr_t<7> & 
	u8arr_t<7> & GetCol_RES22(void)
	{
		return m_RES22;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_lCardReadFailTimes
//Effect:	get ref of col. col is lCardReadFailTimes
//Return:	long & 
	long & GetCol_lCardReadFailTimes(void)
	{
		return m_lCardReadFailTimes;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lCardWriteFailTimes
//Effect:	get ref of col. col is lCardWriteFailTimes
//Return:	long & 
	long & GetCol_lCardWriteFailTimes(void)
	{
		return m_lCardWriteFailTimes;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_RES23
//Effect:	get ref of col. col is RES23
//Return:	u8arr_t<15> & 
	u8arr_t<15> & GetCol_RES23(void)
	{
		return m_RES23;
	}

 
public:

//////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 56;
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
			return "para1040_valid";
		}
		if( iColNum == 8 )
		{
			return "TimeTableWeiHu";
		}
		if( iColNum == 9 )
		{
			return "TimeTableShenJi";
		}
		if( iColNum == 10 )
		{
			return "StaWorkTime";
		}
		if( iColNum == 11 )
		{
			return "RES01";
		}
		if( iColNum == 12 )
		{
			return "RES02";
		}
		if( iColNum == 13 )
		{
			return "RES03";
		}
		if( iColNum == 14 )
		{
			return "lLoginTimeout";
		}
		if( iColNum == 15 )
		{
			return "lLogoutTimeout";
		}
		if( iColNum == 16 )
		{
			return "lOperateWaitTimeout";
		}
		if( iColNum == 17 )
		{
			return "iTradeStorageCtrl";
		}
		if( iColNum == 18 )
		{
			return "lAlertTimesec";
		}
		if( iColNum == 19 )
		{
			return "lTradeItemNumTrigger";
		}
		if( iColNum == 20 )
		{
			return "lTradeTimesecTrigger";
		}
		if( iColNum == 21 )
		{
			return "lBCU";
		}
		if( iColNum == 22 )
		{
			return "lStatusTimesecTrigger";
		}
		if( iColNum == 23 )
		{
			return "RES04";
		}
		if( iColNum == 24 )
		{
			return "RES05";
		}
		if( iColNum == 25 )
		{
			return "RES06";
		}
		if( iColNum == 26 )
		{
			return "RES07";
		}
		if( iColNum == 27 )
		{
			return "RES08";
		}
		if( iColNum == 28 )
		{
			return "iCoinBoxWillFullPercent";
		}
		if( iColNum == 29 )
		{
			return "iCoinBoxFullPercent";
		}
		if( iColNum == 30 )
		{
			return "lCoinBoxCapacity";
		}
		if( iColNum == 31 )
		{
			return "lCoinBoxLowTrigger";
		}
		if( iColNum == 32 )
		{
			return "lCoinBoxMaxCapacity";
		}
		if( iColNum == 33 )
		{
			return "RES09";
		}
		if( iColNum == 34 )
		{
			return "RES10";
		}
		if( iColNum == 35 )
		{
			return "iCashBoxWillFullPercent";
		}
		if( iColNum == 36 )
		{
			return "iCashBoxFullPercent";
		}
		if( iColNum == 37 )
		{
			return "iCashChgBoxWillEmptyPercent";
		}
		if( iColNum == 38 )
		{
			return "lCashChgBoxCapacity";
		}
		if( iColNum == 39 )
		{
			return "RES11";
		}
		if( iColNum == 40 )
		{
			return "RES12";
		}
		if( iColNum == 41 )
		{
			return "RES13";
		}
		if( iColNum == 42 )
		{
			return "RES14";
		}
		if( iColNum == 43 )
		{
			return "RES15";
		}
		if( iColNum == 44 )
		{
			return "RES16";
		}
		if( iColNum == 45 )
		{
			return "lTicketReadFailTimes";
		}
		if( iColNum == 46 )
		{
			return "lTicketWriteFailTimes";
		}
		if( iColNum == 47 )
		{
			return "RES17";
		}
		if( iColNum == 48 )
		{
			return "RES18";
		}
		if( iColNum == 49 )
		{
			return "RES19";
		}
		if( iColNum == 50 )
		{
			return "RES20";
		}
		if( iColNum == 51 )
		{
			return "RES21";
		}
		if( iColNum == 52 )
		{
			return "RES22";
		}
		if( iColNum == 53 )
		{
			return "lCardReadFailTimes";
		}
		if( iColNum == 54 )
		{
			return "lCardWriteFailTimes";
		}
		if( iColNum == 55 )
		{
			return "RES23";
		}
		return "";
	}

///////////////////////////////////////////////////////
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
		if( strColName == "para1040_valid" )
		{
			return 7;
		}
		if( strColName == "TimeTableWeiHu" )
		{
			return 8;
		}
		if( strColName == "TimeTableShenJi" )
		{
			return 9;
		}
		if( strColName == "StaWorkTime" )
		{
			return 10;
		}
		if( strColName == "RES01" )
		{
			return 11;
		}
		if( strColName == "RES02" )
		{
			return 12;
		}
		if( strColName == "RES03" )
		{
			return 13;
		}
		if( strColName == "lLoginTimeout" )
		{
			return 14;
		}
		if( strColName == "lLogoutTimeout" )
		{
			return 15;
		}
		if( strColName == "lOperateWaitTimeout" )
		{
			return 16;
		}
		if( strColName == "iTradeStorageCtrl" )
		{
			return 17;
		}
		if( strColName == "lAlertTimesec" )
		{
			return 18;
		}
		if( strColName == "lTradeItemNumTrigger" )
		{
			return 19;
		}
		if( strColName == "lTradeTimesecTrigger" )
		{
			return 20;
		}
		if( strColName == "lBCU" )
		{
			return 21;
		}
		if( strColName == "lStatusTimesecTrigger" )
		{
			return 22;
		}
		if( strColName == "RES04" )
		{
			return 23;
		}
		if( strColName == "RES05" )
		{
			return 24;
		}
		if( strColName == "RES06" )
		{
			return 25;
		}
		if( strColName == "RES07" )
		{
			return 26;
		}
		if( strColName == "RES08" )
		{
			return 27;
		}
		if( strColName == "iCoinBoxWillFullPercent" )
		{
			return 28;
		}
		if( strColName == "iCoinBoxFullPercent" )
		{
			return 29;
		}
		if( strColName == "lCoinBoxCapacity" )
		{
			return 30;
		}
		if( strColName == "lCoinBoxLowTrigger" )
		{
			return 31;
		}
		if( strColName == "lCoinBoxMaxCapacity" )
		{
			return 32;
		}
		if( strColName == "RES09" )
		{
			return 33;
		}
		if( strColName == "RES10" )
		{
			return 34;
		}
		if( strColName == "iCashBoxWillFullPercent" )
		{
			return 35;
		}
		if( strColName == "iCashBoxFullPercent" )
		{
			return 36;
		}
		if( strColName == "iCashChgBoxWillEmptyPercent" )
		{
			return 37;
		}
		if( strColName == "lCashChgBoxCapacity" )
		{
			return 38;
		}
		if( strColName == "RES11" )
		{
			return 39;
		}
		if( strColName == "RES12" )
		{
			return 40;
		}
		if( strColName == "RES13" )
		{
			return 41;
		}
		if( strColName == "RES14" )
		{
			return 42;
		}
		if( strColName == "RES15" )
		{
			return 43;
		}
		if( strColName == "RES16" )
		{
			return 44;
		}
		if( strColName == "lTicketReadFailTimes" )
		{
			return 45;
		}
		if( strColName == "lTicketWriteFailTimes" )
		{
			return 46;
		}
		if( strColName == "RES17" )
		{
			return 47;
		}
		if( strColName == "RES18" )
		{
			return 48;
		}
		if( strColName == "RES19" )
		{
			return 49;
		}
		if( strColName == "RES20" )
		{
			return 50;
		}
		if( strColName == "RES21" )
		{
			return 51;
		}
		if( strColName == "RES22" )
		{
			return 52;
		}
		if( strColName == "lCardReadFailTimes" )
		{
			return 53;
		}
		if( strColName == "lCardWriteFailTimes" )
		{
			return 54;
		}
		if( strColName == "RES23" )
		{
			return 55;
		}
		return -1;
	}

///////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_para1040_valid);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::b2s(m_TimeTableWeiHu);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::b2s(m_TimeTableShenJi);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::b2s(m_StaWorkTime);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_RES01);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::b2s(m_RES02);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_RES03);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_lLoginTimeout);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_lLogoutTimeout);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_lOperateWaitTimeout);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_iTradeStorageCtrl);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_lAlertTimesec);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_lTradeItemNumTrigger);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_lTradeTimesecTrigger);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_lBCU);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sltoa(m_lStatusTimesecTrigger);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::b2s(m_RES04);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::b2s(m_RES05);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_RES06);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_RES07);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_RES08);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::sltoa(m_iCoinBoxWillFullPercent);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::sltoa(m_iCoinBoxFullPercent);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::sltoa(m_lCoinBoxCapacity);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_lCoinBoxLowTrigger);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_lCoinBoxMaxCapacity);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_RES09);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_RES10);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_iCashBoxWillFullPercent);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_iCashBoxFullPercent);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_iCashChgBoxWillEmptyPercent);
		}
		if( iColNum == 38 )
		{
			return wl::SStrf::sltoa(m_lCashChgBoxCapacity);
		}
		if( iColNum == 39 )
		{
			return wl::SStrf::sltoa(m_RES11);
		}
		if( iColNum == 40 )
		{
			return wl::SStrf::sltoa(m_RES12);
		}
		if( iColNum == 41 )
		{
			return wl::SStrf::b2s(m_RES13);
		}
		if( iColNum == 42 )
		{
			return wl::SStrf::b2s(m_RES14);
		}
		if( iColNum == 43 )
		{
			return wl::SStrf::sltoa(m_RES15);
		}
		if( iColNum == 44 )
		{
			return wl::SStrf::sltoa(m_RES16);
		}
		if( iColNum == 45 )
		{
			return wl::SStrf::sltoa(m_lTicketReadFailTimes);
		}
		if( iColNum == 46 )
		{
			return wl::SStrf::sltoa(m_lTicketWriteFailTimes);
		}
		if( iColNum == 47 )
		{
			return wl::SStrf::b2s(m_RES17);
		}
		if( iColNum == 48 )
		{
			return wl::SStrf::sltoa(m_RES18);
		}
		if( iColNum == 49 )
		{
			return wl::SStrf::sltoa(m_RES19);
		}
		if( iColNum == 50 )
		{
			return wl::SStrf::sltoa(m_RES20);
		}
		if( iColNum == 51 )
		{
			return wl::SStrf::sltoa(m_RES21);
		}
		if( iColNum == 52 )
		{
			return wl::SStrf::b2s(m_RES22);
		}
		if( iColNum == 53 )
		{
			return wl::SStrf::sltoa(m_lCardReadFailTimes);
		}
		if( iColNum == 54 )
		{
			return wl::SStrf::sltoa(m_lCardWriteFailTimes);
		}
		if( iColNum == 55 )
		{
			return wl::SStrf::b2s(m_RES23);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

////////////////////////////////////////////////////////
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
		if( strColName == "para1040_valid" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "TimeTableWeiHu" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "TimeTableShenJi" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "StaWorkTime" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "RES01" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "RES02" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "RES03" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "lLoginTimeout" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "lLogoutTimeout" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "lOperateWaitTimeout" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "iTradeStorageCtrl" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "lAlertTimesec" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "lTradeItemNumTrigger" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "lTradeTimesecTrigger" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "lBCU" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "lStatusTimesecTrigger" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "RES04" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "RES05" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "RES06" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "RES07" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "RES08" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "iCoinBoxWillFullPercent" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "iCoinBoxFullPercent" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "lCoinBoxCapacity" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "lCoinBoxLowTrigger" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "lCoinBoxMaxCapacity" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "RES09" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "RES10" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "iCashBoxWillFullPercent" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "iCashBoxFullPercent" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "iCashChgBoxWillEmptyPercent" )
		{
			return GetColStr<STRINGT>(37);
		}
		if( strColName == "lCashChgBoxCapacity" )
		{
			return GetColStr<STRINGT>(38);
		}
		if( strColName == "RES11" )
		{
			return GetColStr<STRINGT>(39);
		}
		if( strColName == "RES12" )
		{
			return GetColStr<STRINGT>(40);
		}
		if( strColName == "RES13" )
		{
			return GetColStr<STRINGT>(41);
		}
		if( strColName == "RES14" )
		{
			return GetColStr<STRINGT>(42);
		}
		if( strColName == "RES15" )
		{
			return GetColStr<STRINGT>(43);
		}
		if( strColName == "RES16" )
		{
			return GetColStr<STRINGT>(44);
		}
		if( strColName == "lTicketReadFailTimes" )
		{
			return GetColStr<STRINGT>(45);
		}
		if( strColName == "lTicketWriteFailTimes" )
		{
			return GetColStr<STRINGT>(46);
		}
		if( strColName == "RES17" )
		{
			return GetColStr<STRINGT>(47);
		}
		if( strColName == "RES18" )
		{
			return GetColStr<STRINGT>(48);
		}
		if( strColName == "RES19" )
		{
			return GetColStr<STRINGT>(49);
		}
		if( strColName == "RES20" )
		{
			return GetColStr<STRINGT>(50);
		}
		if( strColName == "RES21" )
		{
			return GetColStr<STRINGT>(51);
		}
		if( strColName == "RES22" )
		{
			return GetColStr<STRINGT>(52);
		}
		if( strColName == "lCardReadFailTimes" )
		{
			return GetColStr<STRINGT>(53);
		}
		if( strColName == "lCardWriteFailTimes" )
		{
			return GetColStr<STRINGT>(54);
		}
		if( strColName == "RES23" )
		{
			return GetColStr<STRINGT>(55);
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
			m_para1040_valid=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			wl::SStrf::s2b(strValPARA,m_TimeTableWeiHu);
		}
		if( iColNum == 9 )
		{
			wl::SStrf::s2b(strValPARA,m_TimeTableShenJi);
		}
		if( iColNum == 10 )
		{
			wl::SStrf::s2b(strValPARA,m_StaWorkTime);
		}
		if( iColNum == 11 )
		{
			m_RES01=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			wl::SStrf::s2b(strValPARA,m_RES02);
		}
		if( iColNum == 13 )
		{
			m_RES03=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_lLoginTimeout=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_lLogoutTimeout=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_lOperateWaitTimeout=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_iTradeStorageCtrl=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_lAlertTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_lTradeItemNumTrigger=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_lTradeTimesecTrigger=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_lBCU=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_lStatusTimesecTrigger=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 23 )
		{
			wl::SStrf::s2b(strValPARA,m_RES04);
		}
		if( iColNum == 24 )
		{
			wl::SStrf::s2b(strValPARA,m_RES05);
		}
		if( iColNum == 25 )
		{
			m_RES06=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_RES07=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 27 )
		{
			m_RES08=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			m_iCoinBoxWillFullPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 29 )
		{
			m_iCoinBoxFullPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 30 )
		{
			m_lCoinBoxCapacity=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 31 )
		{
			m_lCoinBoxLowTrigger=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			m_lCoinBoxMaxCapacity=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
		{
			m_RES09=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_RES10=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_iCashBoxWillFullPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_iCashBoxFullPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_iCashChgBoxWillEmptyPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 38 )
		{
			m_lCashChgBoxCapacity=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 39 )
		{
			m_RES11=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 40 )
		{
			m_RES12=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 41 )
		{
			wl::SStrf::s2b(strValPARA,m_RES13);
		}
		if( iColNum == 42 )
		{
			wl::SStrf::s2b(strValPARA,m_RES14);
		}
		if( iColNum == 43 )
		{
			m_RES15=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 44 )
		{
			m_RES16=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 45 )
		{
			m_lTicketReadFailTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 46 )
		{
			m_lTicketWriteFailTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 47 )
		{
			wl::SStrf::s2b(strValPARA,m_RES17);
		}
		if( iColNum == 48 )
		{
			m_RES18=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 49 )
		{
			m_RES19=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 50 )
		{
			m_RES20=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 51 )
		{
			m_RES21=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 52 )
		{
			wl::SStrf::s2b(strValPARA,m_RES22);
		}
		if( iColNum == 53 )
		{
			m_lCardReadFailTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 54 )
		{
			m_lCardWriteFailTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 55 )
		{
			wl::SStrf::s2b(strValPARA,m_RES23);
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
		if( strColName == "para1040_valid" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "TimeTableWeiHu" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "TimeTableShenJi" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "StaWorkTime" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "RES01" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "RES02" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "RES03" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "lLoginTimeout" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "lLogoutTimeout" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "lOperateWaitTimeout" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "iTradeStorageCtrl" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "lAlertTimesec" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "lTradeItemNumTrigger" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "lTradeTimesecTrigger" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "lBCU" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "lStatusTimesecTrigger" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "RES04" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "RES05" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "RES06" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "RES07" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "RES08" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "iCoinBoxWillFullPercent" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "iCoinBoxFullPercent" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "lCoinBoxCapacity" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "lCoinBoxLowTrigger" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "lCoinBoxMaxCapacity" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "RES09" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "RES10" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "iCashBoxWillFullPercent" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "iCashBoxFullPercent" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "iCashChgBoxWillEmptyPercent" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
		if( strColName == "lCashChgBoxCapacity" )
		{
			SetColVal<STRINGT>(38,strValPARA);
		}
		if( strColName == "RES11" )
		{
			SetColVal<STRINGT>(39,strValPARA);
		}
		if( strColName == "RES12" )
		{
			SetColVal<STRINGT>(40,strValPARA);
		}
		if( strColName == "RES13" )
		{
			SetColVal<STRINGT>(41,strValPARA);
		}
		if( strColName == "RES14" )
		{
			SetColVal<STRINGT>(42,strValPARA);
		}
		if( strColName == "RES15" )
		{
			SetColVal<STRINGT>(43,strValPARA);
		}
		if( strColName == "RES16" )
		{
			SetColVal<STRINGT>(44,strValPARA);
		}
		if( strColName == "lTicketReadFailTimes" )
		{
			SetColVal<STRINGT>(45,strValPARA);
		}
		if( strColName == "lTicketWriteFailTimes" )
		{
			SetColVal<STRINGT>(46,strValPARA);
		}
		if( strColName == "RES17" )
		{
			SetColVal<STRINGT>(47,strValPARA);
		}
		if( strColName == "RES18" )
		{
			SetColVal<STRINGT>(48,strValPARA);
		}
		if( strColName == "RES19" )
		{
			SetColVal<STRINGT>(49,strValPARA);
		}
		if( strColName == "RES20" )
		{
			SetColVal<STRINGT>(50,strValPARA);
		}
		if( strColName == "RES21" )
		{
			SetColVal<STRINGT>(51,strValPARA);
		}
		if( strColName == "RES22" )
		{
			SetColVal<STRINGT>(52,strValPARA);
		}
		if( strColName == "lCardReadFailTimes" )
		{
			SetColVal<STRINGT>(53,strValPARA);
		}
		if( strColName == "lCardWriteFailTimes" )
		{
			SetColVal<STRINGT>(54,strValPARA);
		}
		if( strColName == "RES23" )
		{
			SetColVal<STRINGT>(55,strValPARA);
		}
	}

}
; 
//end of class a3002_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a3002_t
class a3002_t {
 
private:

	a3002_t_rowtype m_EmptyRow;
	std::vector<a3002_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a3002_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a3002_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a3002_t()
	{
	}

	virtual ~a3002_t(){;}
	

	//operator == 
	bool operator == (const a3002_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3002_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3002_t & rhs) const
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

	a3002_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a3002_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

//////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

//////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl according to RPS
//Return:	long
	long GetRowCount(const std::vector<long> & vRps)
	{
		return (long)vRps.size();
	}

/////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a3002_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

//////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a3002_t_rowtype tmpEmptyrow;
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
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a3002_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

//////////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

////////////////////////////////////////////////////////////
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
		a3002_t * p = new a3002_t;
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
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_strTblName(std::string strVal) 
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

/////////////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_lVer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lVer(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
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
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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

/////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
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
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_para1040_valid
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_para1040_valid(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_para1040_valid==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_para1040_valid
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_para1040_valid(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_para1040_valid( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_para1040_valid
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_para1040_valid(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_para1040_valid(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_TimeTableWeiHu
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimeTableWeiHu(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimeTableWeiHu==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_TimeTableWeiHu
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_TimeTableWeiHu(longarr2v_t<7,96> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TimeTableWeiHu( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_TimeTableWeiHu
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimeTableWeiHu(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimeTableWeiHu(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_TimeTableShenJi
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimeTableShenJi(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimeTableShenJi==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_TimeTableShenJi
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_TimeTableShenJi(longarr2v_t<7,96> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TimeTableShenJi( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_TimeTableShenJi
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimeTableShenJi(longarr2v_t<7,96> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimeTableShenJi(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_StaWorkTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_StaWorkTime(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_StaWorkTime==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_StaWorkTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_StaWorkTime(u8arr_t<3> aVal) 
	{
		std::vector<long> vRps ;
		SelE_StaWorkTime( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_StaWorkTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_StaWorkTime(u8arr_t<3> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_StaWorkTime(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_RES01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_RES01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES01(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_RES01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES02(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES02==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_RES02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES02(u8arr_t<2> aVal) 
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

/////////////////////////////////////////////////////////////
//Function:	SelE_RES03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES03==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES03(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES03( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES03(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_lLoginTimeout
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lLoginTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lLoginTimeout==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_lLoginTimeout
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lLoginTimeout(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lLoginTimeout( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_lLoginTimeout
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lLoginTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lLoginTimeout(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_lLogoutTimeout
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lLogoutTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lLogoutTimeout==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_lLogoutTimeout
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lLogoutTimeout(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lLogoutTimeout( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_lLogoutTimeout
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lLogoutTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lLogoutTimeout(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_lOperateWaitTimeout
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lOperateWaitTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lOperateWaitTimeout==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_lOperateWaitTimeout
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lOperateWaitTimeout(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lOperateWaitTimeout( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_lOperateWaitTimeout
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lOperateWaitTimeout(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lOperateWaitTimeout(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_iTradeStorageCtrl
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iTradeStorageCtrl(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iTradeStorageCtrl==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_iTradeStorageCtrl
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iTradeStorageCtrl(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iTradeStorageCtrl( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_iTradeStorageCtrl
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iTradeStorageCtrl(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iTradeStorageCtrl(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lAlertTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lAlertTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lAlertTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_lAlertTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lAlertTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lAlertTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lAlertTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lAlertTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lAlertTimesec(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_lTradeItemNumTrigger
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTradeItemNumTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTradeItemNumTrigger==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_lTradeItemNumTrigger
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lTradeItemNumTrigger(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTradeItemNumTrigger( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_lTradeItemNumTrigger
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTradeItemNumTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTradeItemNumTrigger(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_lTradeTimesecTrigger
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTradeTimesecTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTradeTimesecTrigger==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_lTradeTimesecTrigger
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lTradeTimesecTrigger(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTradeTimesecTrigger( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_lTradeTimesecTrigger
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTradeTimesecTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTradeTimesecTrigger(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_lBCU
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lBCU(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lBCU==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_lBCU
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lBCU(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lBCU( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_lBCU
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lBCU(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lBCU(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_lStatusTimesecTrigger
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lStatusTimesecTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lStatusTimesecTrigger==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_lStatusTimesecTrigger
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lStatusTimesecTrigger(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lStatusTimesecTrigger( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lStatusTimesecTrigger
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lStatusTimesecTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lStatusTimesecTrigger(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RES04
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES04(u8arr_t<9> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES04==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_RES04
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES04(u8arr_t<9> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES04( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES04
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES04(u8arr_t<9> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES04(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_RES05
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES05(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES05==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_RES05
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES05(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES05( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_RES05
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES05(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES05(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES06
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES06(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES06==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES06
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES06(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES06( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_RES06
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES06(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES06(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES07
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES07(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES07==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_RES07
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES07(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES07( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES07
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES07(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES07(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES08
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES08(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES08==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES08
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES08(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES08( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_RES08
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES08(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES08(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_iCoinBoxWillFullPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iCoinBoxWillFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iCoinBoxWillFullPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_iCoinBoxWillFullPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iCoinBoxWillFullPercent(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iCoinBoxWillFullPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_iCoinBoxWillFullPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iCoinBoxWillFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iCoinBoxWillFullPercent(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_iCoinBoxFullPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iCoinBoxFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iCoinBoxFullPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_iCoinBoxFullPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iCoinBoxFullPercent(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iCoinBoxFullPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_iCoinBoxFullPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iCoinBoxFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iCoinBoxFullPercent(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_lCoinBoxCapacity
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCoinBoxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCoinBoxCapacity==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_lCoinBoxCapacity
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCoinBoxCapacity(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCoinBoxCapacity( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lCoinBoxCapacity
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCoinBoxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCoinBoxCapacity(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lCoinBoxLowTrigger
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCoinBoxLowTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCoinBoxLowTrigger==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_lCoinBoxLowTrigger
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCoinBoxLowTrigger(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCoinBoxLowTrigger( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_lCoinBoxLowTrigger
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCoinBoxLowTrigger(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCoinBoxLowTrigger(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_lCoinBoxMaxCapacity
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCoinBoxMaxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCoinBoxMaxCapacity==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_lCoinBoxMaxCapacity
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCoinBoxMaxCapacity(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCoinBoxMaxCapacity( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_lCoinBoxMaxCapacity
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCoinBoxMaxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCoinBoxMaxCapacity(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RES09
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES09(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES09==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_RES09
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES09(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES09( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_RES09
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES09(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES09(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES10
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES10(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES10==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES10
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES10(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES10( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES10
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES10(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES10(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_iCashBoxWillFullPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iCashBoxWillFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iCashBoxWillFullPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_iCashBoxWillFullPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iCashBoxWillFullPercent(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iCashBoxWillFullPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_iCashBoxWillFullPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iCashBoxWillFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iCashBoxWillFullPercent(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_iCashBoxFullPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iCashBoxFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iCashBoxFullPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_iCashBoxFullPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iCashBoxFullPercent(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iCashBoxFullPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_iCashBoxFullPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iCashBoxFullPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iCashBoxFullPercent(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_iCashChgBoxWillEmptyPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iCashChgBoxWillEmptyPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iCashChgBoxWillEmptyPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_iCashChgBoxWillEmptyPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_iCashChgBoxWillEmptyPercent(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iCashChgBoxWillEmptyPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_iCashChgBoxWillEmptyPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iCashChgBoxWillEmptyPercent(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iCashChgBoxWillEmptyPercent(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_lCashChgBoxCapacity
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCashChgBoxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCashChgBoxCapacity==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_lCashChgBoxCapacity
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCashChgBoxCapacity(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCashChgBoxCapacity( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_lCashChgBoxCapacity
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCashChgBoxCapacity(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCashChgBoxCapacity(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES11
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES11(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES11==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES11
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES11(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES11( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_RES11
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES11(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES11(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_RES12
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES12(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES12==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES12
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES12(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES12( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_RES12
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES12(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES12(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_RES13
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES13(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES13==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES13
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES13(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES13( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES13
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES13(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES13(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES14
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES14(u8arr_t<7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES14==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES14
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES14(u8arr_t<7> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES14( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES14
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES14(u8arr_t<7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES14(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_RES15
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES15(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES15==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES15
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES15(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES15( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES15
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES15(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES15(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_RES16
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES16(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES16==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_RES16
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES16(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES16( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_RES16
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES16(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES16(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_lTicketReadFailTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTicketReadFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTicketReadFailTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_lTicketReadFailTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lTicketReadFailTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTicketReadFailTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_lTicketReadFailTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTicketReadFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTicketReadFailTimes(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lTicketWriteFailTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTicketWriteFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTicketWriteFailTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_lTicketWriteFailTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lTicketWriteFailTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTicketWriteFailTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_lTicketWriteFailTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTicketWriteFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTicketWriteFailTimes(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_RES17
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES17(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES17==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_RES17
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES17(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES17( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES17
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES17(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES17(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES18
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES18(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES18==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_RES18
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES18(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES18( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_RES18
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES18(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES18(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_RES19
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES19(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES19==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_RES19
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES19(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES19( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES19
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES19(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES19(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_RES20
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES20(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES20==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES20
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES20(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES20( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_RES20
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES20(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES20(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_RES21
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES21(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES21==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES21
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES21(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES21( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES21
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES21(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES21(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES22
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES22(u8arr_t<7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES22==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_RES22
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES22(u8arr_t<7> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES22( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_RES22
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES22(u8arr_t<7> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES22(aVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_lCardReadFailTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCardReadFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCardReadFailTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_lCardReadFailTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCardReadFailTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCardReadFailTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lCardReadFailTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCardReadFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCardReadFailTimes(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_lCardWriteFailTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lCardWriteFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lCardWriteFailTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_lCardWriteFailTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_lCardWriteFailTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lCardWriteFailTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_lCardWriteFailTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lCardWriteFailTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lCardWriteFailTimes(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES23
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES23(u8arr_t<15> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES23==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES23
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3002_t_rowtype&
	a3002_t_rowtype & SelE1_RES23(u8arr_t<15> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES23( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_RES23
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES23(u8arr_t<15> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES23(aVal, vRps, pRefRps);
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

////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////
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
//end of class a3002_t


#endif

