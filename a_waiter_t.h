
#ifndef V1_3AA_WAITER_T_20161219_141850
#define V1_3AA_WAITER_T_20161219_141850

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a_waiter_t
//Name:	a_waiter_t_rowtype
class a_waiter_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		人员操作的交易过程记录 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	SDte		m_begin_time;			// a	交易起始时间	投币开始算 
	SDte		m_end_time;			// a	结束时间	出票时间点 
	std::string		m_stationname;			// 1	name 
	long		m_ReceiveTotal;			// 2	总收	单位：分 
	long		m_ReceiveCoin;			// 3	硬币	单位：分 
	long		m_ReceiveBill;			// 4	纸	单位：分 
	long		m_TickePriceTotal;			// 5	票总价 
	long		m_TickePrice1;			// 6	一张票的价钱	单位：分 
	long		m_TicketoutPlan;			// 7	应该出几张票	张数 
	long		m_ShouldChgTotal;			// 8	共应找	单位：分 
	wl::tuint8		m_RES01_MoneyStorePlan_t;			// 9	[保留] 
	long		m_Coin5;			// 10	收到5毛硬币	个数 
	long		m_Coin1;			// 11	收到1元硬币	个数 
	uiarr_t<long,111>		m_BillPieces;			// 12	收到纸币	张数 
	int		m_MoneyStoreOk;			// 13	收钱入箱成功	1=成功；0=失败； 
	int		m_MoneyStoreDone;			// 14	收钱入箱做完 
	wl::tuint8		m_RES01_TicketoutPlan_t;			// 15	[保留] 
	long		m_TicketoutActual;			// 16	Ticketout实际出	张数 
	int		m_TicketoutOk;			// 17	Ticketout出成功	1=成功；0=失败； 
	int		m_TicketoutErrReason;			// 18	当失败时，失败的原因：0=其它；-1=写失败；-2=写成功但卡住 
	int		m_TicketoutDone;			// 19	Ticketout做完 
	wl::tuint8		m_RES02_CoinRecycleChgPlan_t;			// 20	[保留] 
	long		m_CoinRecycleChgPlan;			// 21	硬币循环应该找	个数 
	long		m_CoinRecycleChgActual;			// 22	硬币循环实际找	个数 
	int		m_CoinRecycleChgOk;			// 23	硬币循环找成功	1=成功；0=失败； 
	int		m_CoinRecycleChgDone;			// 24	硬币循环找 做完 
	wl::tuint8		m_RES03_CoinSpecialChgPlan_t;			// 25	[保留] 
	long		m_CoinSpecialChgPlan;			// 26	硬币专用应该找	个数 
	long		m_CoinSpecialChgActual;			// 27	硬币专用实际找	个数 
	int		m_CoinSpecialChgOk;			// 28	硬币专用找成功	1=成功；0=失败； 
	int		m_CoinSpecialChgDone;			// 29	硬币专用找 做完 
	wl::tuint8		m_RES04_BilchgPlan_t;			// 30	[保留] 
	long		m_BilchgPlan;			// 31	Billchg应该找	单位：元 
	long		m_BilchgActual;			// 32	Billchg实际找	单位：元 
	int		m_BilchgOk;			// 33	Billchg找成功	1=成功；0=失败； 
	int		m_BilchgDone;			// 34	Billchg找 做完 
	int		m_TicketingFirstFlag;			// 35	单笔交易第一次出卡标志	0:表示未发第一张卡;1:表示第一张卡已发 
	int		m_TicketingFirstDone;			// 36	单笔交易第一次出卡成功	0:表示第一张票卡发送不成功;1:表示成功 
 
public:

	a_waiter_t_rowtype()
	{
		m_strTblName = "a_waiter_t";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_begin_time.MakeNow();
		m_end_time.MakeNow();
		//m_stationname = //use default
		m_ReceiveTotal = 0;
		m_ReceiveCoin = 0;
		m_ReceiveBill = 0;
		m_TickePriceTotal = 0;
		m_TickePrice1 = 0;
		m_TicketoutPlan = 0;
		m_ShouldChgTotal = 0;
		m_RES01_MoneyStorePlan_t = 0;
		m_Coin5 = 0;
		m_Coin1 = 0;
		//m_BillPieces = //use default
		m_MoneyStoreOk = 0;
		m_MoneyStoreDone = 0;
		m_RES01_TicketoutPlan_t = 0;
		m_TicketoutActual = 0;
		m_TicketoutOk = 0;
		m_TicketoutErrReason = 0;
		m_TicketoutDone = 0;
		m_RES02_CoinRecycleChgPlan_t = 0;
		m_CoinRecycleChgPlan = 0;
		m_CoinRecycleChgActual = 0;
		m_CoinRecycleChgOk = 0;
		m_CoinRecycleChgDone = 0;
		m_RES03_CoinSpecialChgPlan_t = 0;
		m_CoinSpecialChgPlan = 0;
		m_CoinSpecialChgActual = 0;
		m_CoinSpecialChgOk = 0;
		m_CoinSpecialChgDone = 0;
		m_RES04_BilchgPlan_t = 0;
		m_BilchgPlan = 0;
		m_BilchgActual = 0;
		m_BilchgOk = 0;
		m_BilchgDone = 0;
		m_TicketingFirstFlag = 0;
		m_TicketingFirstDone = 0;
	}

	virtual ~a_waiter_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a_waiter_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a_waiter_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a_waiter_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_begin_time));
		len1 = sizeof(wl::SDte_bare);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_end_time));
		len1 = sizeof(wl::SDte_bare);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_stationname.c_str();
		len1 = (long)(m_stationname.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveTotal));
		len1 = sizeof(m_ReceiveTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveCoin));
		len1 = sizeof(m_ReceiveCoin);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveBill));
		len1 = sizeof(m_ReceiveBill);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TickePriceTotal));
		len1 = sizeof(m_TickePriceTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TickePrice1));
		len1 = sizeof(m_TickePrice1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutPlan));
		len1 = sizeof(m_TicketoutPlan);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ShouldChgTotal));
		len1 = sizeof(m_ShouldChgTotal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01_MoneyStorePlan_t));
		len1 = sizeof(m_RES01_MoneyStorePlan_t);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Coin5));
		len1 = sizeof(m_Coin5);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Coin1));
		len1 = sizeof(m_Coin1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillPieces));
		len1 = sizeof(m_BillPieces);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MoneyStoreOk));
		len1 = sizeof(m_MoneyStoreOk);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MoneyStoreDone));
		len1 = sizeof(m_MoneyStoreDone);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01_TicketoutPlan_t));
		len1 = sizeof(m_RES01_TicketoutPlan_t);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutActual));
		len1 = sizeof(m_TicketoutActual);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutOk));
		len1 = sizeof(m_TicketoutOk);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutErrReason));
		len1 = sizeof(m_TicketoutErrReason);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutDone));
		len1 = sizeof(m_TicketoutDone);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES02_CoinRecycleChgPlan_t));
		len1 = sizeof(m_RES02_CoinRecycleChgPlan_t);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgPlan));
		len1 = sizeof(m_CoinRecycleChgPlan);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgActual));
		len1 = sizeof(m_CoinRecycleChgActual);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgOk));
		len1 = sizeof(m_CoinRecycleChgOk);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgDone));
		len1 = sizeof(m_CoinRecycleChgDone);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES03_CoinSpecialChgPlan_t));
		len1 = sizeof(m_RES03_CoinSpecialChgPlan_t);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgPlan));
		len1 = sizeof(m_CoinSpecialChgPlan);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgActual));
		len1 = sizeof(m_CoinSpecialChgActual);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgOk));
		len1 = sizeof(m_CoinSpecialChgOk);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgDone));
		len1 = sizeof(m_CoinSpecialChgDone);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04_BilchgPlan_t));
		len1 = sizeof(m_RES04_BilchgPlan_t);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgPlan));
		len1 = sizeof(m_BilchgPlan);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgActual));
		len1 = sizeof(m_BilchgActual);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgOk));
		len1 = sizeof(m_BilchgOk);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgDone));
		len1 = sizeof(m_BilchgDone);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketingFirstFlag));
		len1 = sizeof(m_TicketingFirstFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketingFirstDone));
		len1 = sizeof(m_TicketingFirstDone);
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

	a_waiter_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ memcpy(reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_begin_time)),buf2,sizeof(wl::SDte_bare)); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ memcpy(reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_end_time)),buf2,sizeof(wl::SDte_bare)); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_stationname = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReceiveTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReceiveCoin = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ReceiveBill = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TickePriceTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TickePrice1 = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketoutPlan = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ShouldChgTotal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01_MoneyStorePlan_t = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Coin5 = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_Coin1 = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BillPieces = *(uiarr_t<long,111>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_MoneyStoreOk = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_MoneyStoreDone = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01_TicketoutPlan_t = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketoutActual = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketoutOk = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketoutErrReason = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketoutDone = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES02_CoinRecycleChgPlan_t = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinRecycleChgPlan = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinRecycleChgActual = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinRecycleChgOk = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinRecycleChgDone = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES03_CoinSpecialChgPlan_t = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinSpecialChgPlan = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinSpecialChgActual = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinSpecialChgOk = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CoinSpecialChgDone = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES04_BilchgPlan_t = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BilchgPlan = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BilchgActual = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BilchgOk = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BilchgDone = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketingFirstFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketingFirstDone = *(int*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_begin_time));
		len1 = sizeof(wl::SDte_bare);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(m_end_time));
		len1 = sizeof(wl::SDte_bare);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_stationname.c_str();
		len1 = (long)(m_stationname.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveTotal));
		len1 = sizeof(m_ReceiveTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveCoin));
		len1 = sizeof(m_ReceiveCoin);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ReceiveBill));
		len1 = sizeof(m_ReceiveBill);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TickePriceTotal));
		len1 = sizeof(m_TickePriceTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TickePrice1));
		len1 = sizeof(m_TickePrice1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutPlan));
		len1 = sizeof(m_TicketoutPlan);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ShouldChgTotal));
		len1 = sizeof(m_ShouldChgTotal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01_MoneyStorePlan_t));
		len1 = sizeof(m_RES01_MoneyStorePlan_t);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Coin5));
		len1 = sizeof(m_Coin5);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_Coin1));
		len1 = sizeof(m_Coin1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BillPieces));
		len1 = sizeof(m_BillPieces);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MoneyStoreOk));
		len1 = sizeof(m_MoneyStoreOk);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MoneyStoreDone));
		len1 = sizeof(m_MoneyStoreDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES01_TicketoutPlan_t));
		len1 = sizeof(m_RES01_TicketoutPlan_t);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutActual));
		len1 = sizeof(m_TicketoutActual);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutOk));
		len1 = sizeof(m_TicketoutOk);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutErrReason));
		len1 = sizeof(m_TicketoutErrReason);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketoutDone));
		len1 = sizeof(m_TicketoutDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES02_CoinRecycleChgPlan_t));
		len1 = sizeof(m_RES02_CoinRecycleChgPlan_t);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgPlan));
		len1 = sizeof(m_CoinRecycleChgPlan);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgActual));
		len1 = sizeof(m_CoinRecycleChgActual);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgOk));
		len1 = sizeof(m_CoinRecycleChgOk);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinRecycleChgDone));
		len1 = sizeof(m_CoinRecycleChgDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES03_CoinSpecialChgPlan_t));
		len1 = sizeof(m_RES03_CoinSpecialChgPlan_t);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgPlan));
		len1 = sizeof(m_CoinSpecialChgPlan);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgActual));
		len1 = sizeof(m_CoinSpecialChgActual);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgOk));
		len1 = sizeof(m_CoinSpecialChgOk);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CoinSpecialChgDone));
		len1 = sizeof(m_CoinSpecialChgDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04_BilchgPlan_t));
		len1 = sizeof(m_RES04_BilchgPlan_t);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgPlan));
		len1 = sizeof(m_BilchgPlan);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgActual));
		len1 = sizeof(m_BilchgActual);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgOk));
		len1 = sizeof(m_BilchgOk);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BilchgDone));
		len1 = sizeof(m_BilchgDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketingFirstFlag));
		len1 = sizeof(m_TicketingFirstFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketingFirstDone));
		len1 = sizeof(m_TicketingFirstDone);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a_waiter_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_begin_time = memcpy(reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(buf2COL)),buf2,sizeof(wl::SDte_bare));
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_end_time = memcpy(reinterpret_cast<char *>(&static_cast<wl::SDte_bare&>(buf2COL)),buf2,sizeof(wl::SDte_bare));
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_stationname = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReceiveTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReceiveCoin = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ReceiveBill = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TickePriceTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TickePrice1 = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketoutPlan = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ShouldChgTotal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01_MoneyStorePlan_t = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Coin5 = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_Coin1 = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BillPieces = *(uiarr_t<long,111>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_MoneyStoreOk = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_MoneyStoreDone = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01_TicketoutPlan_t = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketoutActual = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketoutOk = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketoutErrReason = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketoutDone = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES02_CoinRecycleChgPlan_t = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinRecycleChgPlan = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinRecycleChgActual = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinRecycleChgOk = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinRecycleChgDone = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES03_CoinSpecialChgPlan_t = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinSpecialChgPlan = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinSpecialChgActual = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinSpecialChgOk = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CoinSpecialChgDone = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES04_BilchgPlan_t = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BilchgPlan = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BilchgActual = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BilchgOk = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BilchgDone = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketingFirstFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketingFirstDone = *(int*)buf2;
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
//Function:	GetCol_begin_time
//Effect:	get ref of col. col is begin_time
//Return:	SDte & 
	SDte & GetCol_begin_time(void)
	{
		return m_begin_time;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_end_time
//Effect:	get ref of col. col is end_time
//Return:	SDte & 
	SDte & GetCol_end_time(void)
	{
		return m_end_time;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_stationname
//Effect:	get ref of col. col is stationname
//Return:	std::string & 
	std::string & GetCol_stationname(void)
	{
		return m_stationname;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_ReceiveTotal
//Effect:	get ref of col. col is ReceiveTotal
//Return:	long & 
	long & GetCol_ReceiveTotal(void)
	{
		return m_ReceiveTotal;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_ReceiveCoin
//Effect:	get ref of col. col is ReceiveCoin
//Return:	long & 
	long & GetCol_ReceiveCoin(void)
	{
		return m_ReceiveCoin;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_ReceiveBill
//Effect:	get ref of col. col is ReceiveBill
//Return:	long & 
	long & GetCol_ReceiveBill(void)
	{
		return m_ReceiveBill;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_TickePriceTotal
//Effect:	get ref of col. col is TickePriceTotal
//Return:	long & 
	long & GetCol_TickePriceTotal(void)
	{
		return m_TickePriceTotal;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_TickePrice1
//Effect:	get ref of col. col is TickePrice1
//Return:	long & 
	long & GetCol_TickePrice1(void)
	{
		return m_TickePrice1;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TicketoutPlan
//Effect:	get ref of col. col is TicketoutPlan
//Return:	long & 
	long & GetCol_TicketoutPlan(void)
	{
		return m_TicketoutPlan;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_ShouldChgTotal
//Effect:	get ref of col. col is ShouldChgTotal
//Return:	long & 
	long & GetCol_ShouldChgTotal(void)
	{
		return m_ShouldChgTotal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES01_MoneyStorePlan_t
//Effect:	get ref of col. col is RES01_MoneyStorePlan_t
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01_MoneyStorePlan_t(void)
	{
		return m_RES01_MoneyStorePlan_t;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_Coin5
//Effect:	get ref of col. col is Coin5
//Return:	long & 
	long & GetCol_Coin5(void)
	{
		return m_Coin5;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_Coin1
//Effect:	get ref of col. col is Coin1
//Return:	long & 
	long & GetCol_Coin1(void)
	{
		return m_Coin1;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_BillPieces
//Effect:	get ref of col. col is BillPieces
//Return:	uiarr_t<long,111> & 
	uiarr_t<long,111> & GetCol_BillPieces(void)
	{
		return m_BillPieces;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_MoneyStoreOk
//Effect:	get ref of col. col is MoneyStoreOk
//Return:	int & 
	int & GetCol_MoneyStoreOk(void)
	{
		return m_MoneyStoreOk;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_MoneyStoreDone
//Effect:	get ref of col. col is MoneyStoreDone
//Return:	int & 
	int & GetCol_MoneyStoreDone(void)
	{
		return m_MoneyStoreDone;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES01_TicketoutPlan_t
//Effect:	get ref of col. col is RES01_TicketoutPlan_t
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01_TicketoutPlan_t(void)
	{
		return m_RES01_TicketoutPlan_t;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_TicketoutActual
//Effect:	get ref of col. col is TicketoutActual
//Return:	long & 
	long & GetCol_TicketoutActual(void)
	{
		return m_TicketoutActual;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_TicketoutOk
//Effect:	get ref of col. col is TicketoutOk
//Return:	int & 
	int & GetCol_TicketoutOk(void)
	{
		return m_TicketoutOk;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_TicketoutErrReason
//Effect:	get ref of col. col is TicketoutErrReason
//Return:	int & 
	int & GetCol_TicketoutErrReason(void)
	{
		return m_TicketoutErrReason;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_TicketoutDone
//Effect:	get ref of col. col is TicketoutDone
//Return:	int & 
	int & GetCol_TicketoutDone(void)
	{
		return m_TicketoutDone;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES02_CoinRecycleChgPlan_t
//Effect:	get ref of col. col is RES02_CoinRecycleChgPlan_t
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES02_CoinRecycleChgPlan_t(void)
	{
		return m_RES02_CoinRecycleChgPlan_t;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_CoinRecycleChgPlan
//Effect:	get ref of col. col is CoinRecycleChgPlan
//Return:	long & 
	long & GetCol_CoinRecycleChgPlan(void)
	{
		return m_CoinRecycleChgPlan;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_CoinRecycleChgActual
//Effect:	get ref of col. col is CoinRecycleChgActual
//Return:	long & 
	long & GetCol_CoinRecycleChgActual(void)
	{
		return m_CoinRecycleChgActual;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_CoinRecycleChgOk
//Effect:	get ref of col. col is CoinRecycleChgOk
//Return:	int & 
	int & GetCol_CoinRecycleChgOk(void)
	{
		return m_CoinRecycleChgOk;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_CoinRecycleChgDone
//Effect:	get ref of col. col is CoinRecycleChgDone
//Return:	int & 
	int & GetCol_CoinRecycleChgDone(void)
	{
		return m_CoinRecycleChgDone;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES03_CoinSpecialChgPlan_t
//Effect:	get ref of col. col is RES03_CoinSpecialChgPlan_t
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES03_CoinSpecialChgPlan_t(void)
	{
		return m_RES03_CoinSpecialChgPlan_t;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CoinSpecialChgPlan
//Effect:	get ref of col. col is CoinSpecialChgPlan
//Return:	long & 
	long & GetCol_CoinSpecialChgPlan(void)
	{
		return m_CoinSpecialChgPlan;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_CoinSpecialChgActual
//Effect:	get ref of col. col is CoinSpecialChgActual
//Return:	long & 
	long & GetCol_CoinSpecialChgActual(void)
	{
		return m_CoinSpecialChgActual;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_CoinSpecialChgOk
//Effect:	get ref of col. col is CoinSpecialChgOk
//Return:	int & 
	int & GetCol_CoinSpecialChgOk(void)
	{
		return m_CoinSpecialChgOk;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_CoinSpecialChgDone
//Effect:	get ref of col. col is CoinSpecialChgDone
//Return:	int & 
	int & GetCol_CoinSpecialChgDone(void)
	{
		return m_CoinSpecialChgDone;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_RES04_BilchgPlan_t
//Effect:	get ref of col. col is RES04_BilchgPlan_t
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES04_BilchgPlan_t(void)
	{
		return m_RES04_BilchgPlan_t;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_BilchgPlan
//Effect:	get ref of col. col is BilchgPlan
//Return:	long & 
	long & GetCol_BilchgPlan(void)
	{
		return m_BilchgPlan;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_BilchgActual
//Effect:	get ref of col. col is BilchgActual
//Return:	long & 
	long & GetCol_BilchgActual(void)
	{
		return m_BilchgActual;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_BilchgOk
//Effect:	get ref of col. col is BilchgOk
//Return:	int & 
	int & GetCol_BilchgOk(void)
	{
		return m_BilchgOk;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_BilchgDone
//Effect:	get ref of col. col is BilchgDone
//Return:	int & 
	int & GetCol_BilchgDone(void)
	{
		return m_BilchgDone;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_TicketingFirstFlag
//Effect:	get ref of col. col is TicketingFirstFlag
//Return:	int & 
	int & GetCol_TicketingFirstFlag(void)
	{
		return m_TicketingFirstFlag;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TicketingFirstDone
//Effect:	get ref of col. col is TicketingFirstDone
//Return:	int & 
	int & GetCol_TicketingFirstDone(void)
	{
		return m_TicketingFirstDone;
	}

 
public:

////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 45;
	}

/////////////////////////////////////////////////////////
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
			return "begin_time";
		}
		if( iColNum == 8 )
		{
			return "end_time";
		}
		if( iColNum == 9 )
		{
			return "stationname";
		}
		if( iColNum == 10 )
		{
			return "ReceiveTotal";
		}
		if( iColNum == 11 )
		{
			return "ReceiveCoin";
		}
		if( iColNum == 12 )
		{
			return "ReceiveBill";
		}
		if( iColNum == 13 )
		{
			return "TickePriceTotal";
		}
		if( iColNum == 14 )
		{
			return "TickePrice1";
		}
		if( iColNum == 15 )
		{
			return "TicketoutPlan";
		}
		if( iColNum == 16 )
		{
			return "ShouldChgTotal";
		}
		if( iColNum == 17 )
		{
			return "RES01_MoneyStorePlan_t";
		}
		if( iColNum == 18 )
		{
			return "Coin5";
		}
		if( iColNum == 19 )
		{
			return "Coin1";
		}
		if( iColNum == 20 )
		{
			return "BillPieces";
		}
		if( iColNum == 21 )
		{
			return "MoneyStoreOk";
		}
		if( iColNum == 22 )
		{
			return "MoneyStoreDone";
		}
		if( iColNum == 23 )
		{
			return "RES01_TicketoutPlan_t";
		}
		if( iColNum == 24 )
		{
			return "TicketoutActual";
		}
		if( iColNum == 25 )
		{
			return "TicketoutOk";
		}
		if( iColNum == 26 )
		{
			return "TicketoutErrReason";
		}
		if( iColNum == 27 )
		{
			return "TicketoutDone";
		}
		if( iColNum == 28 )
		{
			return "RES02_CoinRecycleChgPlan_t";
		}
		if( iColNum == 29 )
		{
			return "CoinRecycleChgPlan";
		}
		if( iColNum == 30 )
		{
			return "CoinRecycleChgActual";
		}
		if( iColNum == 31 )
		{
			return "CoinRecycleChgOk";
		}
		if( iColNum == 32 )
		{
			return "CoinRecycleChgDone";
		}
		if( iColNum == 33 )
		{
			return "RES03_CoinSpecialChgPlan_t";
		}
		if( iColNum == 34 )
		{
			return "CoinSpecialChgPlan";
		}
		if( iColNum == 35 )
		{
			return "CoinSpecialChgActual";
		}
		if( iColNum == 36 )
		{
			return "CoinSpecialChgOk";
		}
		if( iColNum == 37 )
		{
			return "CoinSpecialChgDone";
		}
		if( iColNum == 38 )
		{
			return "RES04_BilchgPlan_t";
		}
		if( iColNum == 39 )
		{
			return "BilchgPlan";
		}
		if( iColNum == 40 )
		{
			return "BilchgActual";
		}
		if( iColNum == 41 )
		{
			return "BilchgOk";
		}
		if( iColNum == 42 )
		{
			return "BilchgDone";
		}
		if( iColNum == 43 )
		{
			return "TicketingFirstFlag";
		}
		if( iColNum == 44 )
		{
			return "TicketingFirstDone";
		}
		return "";
	}

////////////////////////////////////////////////////////////////
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
		if( strColName == "begin_time" )
		{
			return 7;
		}
		if( strColName == "end_time" )
		{
			return 8;
		}
		if( strColName == "stationname" )
		{
			return 9;
		}
		if( strColName == "ReceiveTotal" )
		{
			return 10;
		}
		if( strColName == "ReceiveCoin" )
		{
			return 11;
		}
		if( strColName == "ReceiveBill" )
		{
			return 12;
		}
		if( strColName == "TickePriceTotal" )
		{
			return 13;
		}
		if( strColName == "TickePrice1" )
		{
			return 14;
		}
		if( strColName == "TicketoutPlan" )
		{
			return 15;
		}
		if( strColName == "ShouldChgTotal" )
		{
			return 16;
		}
		if( strColName == "RES01_MoneyStorePlan_t" )
		{
			return 17;
		}
		if( strColName == "Coin5" )
		{
			return 18;
		}
		if( strColName == "Coin1" )
		{
			return 19;
		}
		if( strColName == "BillPieces" )
		{
			return 20;
		}
		if( strColName == "MoneyStoreOk" )
		{
			return 21;
		}
		if( strColName == "MoneyStoreDone" )
		{
			return 22;
		}
		if( strColName == "RES01_TicketoutPlan_t" )
		{
			return 23;
		}
		if( strColName == "TicketoutActual" )
		{
			return 24;
		}
		if( strColName == "TicketoutOk" )
		{
			return 25;
		}
		if( strColName == "TicketoutErrReason" )
		{
			return 26;
		}
		if( strColName == "TicketoutDone" )
		{
			return 27;
		}
		if( strColName == "RES02_CoinRecycleChgPlan_t" )
		{
			return 28;
		}
		if( strColName == "CoinRecycleChgPlan" )
		{
			return 29;
		}
		if( strColName == "CoinRecycleChgActual" )
		{
			return 30;
		}
		if( strColName == "CoinRecycleChgOk" )
		{
			return 31;
		}
		if( strColName == "CoinRecycleChgDone" )
		{
			return 32;
		}
		if( strColName == "RES03_CoinSpecialChgPlan_t" )
		{
			return 33;
		}
		if( strColName == "CoinSpecialChgPlan" )
		{
			return 34;
		}
		if( strColName == "CoinSpecialChgActual" )
		{
			return 35;
		}
		if( strColName == "CoinSpecialChgOk" )
		{
			return 36;
		}
		if( strColName == "CoinSpecialChgDone" )
		{
			return 37;
		}
		if( strColName == "RES04_BilchgPlan_t" )
		{
			return 38;
		}
		if( strColName == "BilchgPlan" )
		{
			return 39;
		}
		if( strColName == "BilchgActual" )
		{
			return 40;
		}
		if( strColName == "BilchgOk" )
		{
			return 41;
		}
		if( strColName == "BilchgDone" )
		{
			return 42;
		}
		if( strColName == "TicketingFirstFlag" )
		{
			return 43;
		}
		if( strColName == "TicketingFirstDone" )
		{
			return 44;
		}
		return -1;
	}

/////////////////////////////////////////////////////////
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
			return m_begin_time.ReadString();
		}
		if( iColNum == 8 )
		{
			return m_end_time.ReadString();
		}
		if( iColNum == 9 )
		{
			return m_stationname;
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_ReceiveTotal);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_ReceiveCoin);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_ReceiveBill);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_TickePriceTotal);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_TickePrice1);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_TicketoutPlan);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_ShouldChgTotal);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_RES01_MoneyStorePlan_t);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_Coin5);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_Coin1);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::b2s(m_BillPieces);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_MoneyStoreOk);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sltoa(m_MoneyStoreDone);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_RES01_TicketoutPlan_t);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_TicketoutActual);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_TicketoutOk);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_TicketoutErrReason);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_TicketoutDone);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::sltoa(m_RES02_CoinRecycleChgPlan_t);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::sltoa(m_CoinRecycleChgPlan);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::sltoa(m_CoinRecycleChgActual);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_CoinRecycleChgOk);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_CoinRecycleChgDone);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_RES03_CoinSpecialChgPlan_t);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_CoinSpecialChgPlan);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_CoinSpecialChgActual);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_CoinSpecialChgOk);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_CoinSpecialChgDone);
		}
		if( iColNum == 38 )
		{
			return wl::SStrf::sltoa(m_RES04_BilchgPlan_t);
		}
		if( iColNum == 39 )
		{
			return wl::SStrf::sltoa(m_BilchgPlan);
		}
		if( iColNum == 40 )
		{
			return wl::SStrf::sltoa(m_BilchgActual);
		}
		if( iColNum == 41 )
		{
			return wl::SStrf::sltoa(m_BilchgOk);
		}
		if( iColNum == 42 )
		{
			return wl::SStrf::sltoa(m_BilchgDone);
		}
		if( iColNum == 43 )
		{
			return wl::SStrf::sltoa(m_TicketingFirstFlag);
		}
		if( iColNum == 44 )
		{
			return wl::SStrf::sltoa(m_TicketingFirstDone);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

///////////////////////////////////////////////////////////////
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
		if( strColName == "begin_time" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "end_time" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "stationname" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "ReceiveTotal" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "ReceiveCoin" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "ReceiveBill" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "TickePriceTotal" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "TickePrice1" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "TicketoutPlan" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "ShouldChgTotal" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "RES01_MoneyStorePlan_t" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "Coin5" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "Coin1" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "BillPieces" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "MoneyStoreOk" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "MoneyStoreDone" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "RES01_TicketoutPlan_t" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "TicketoutActual" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "TicketoutOk" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "TicketoutErrReason" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "TicketoutDone" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "RES02_CoinRecycleChgPlan_t" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "CoinRecycleChgPlan" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "CoinRecycleChgActual" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "CoinRecycleChgOk" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "CoinRecycleChgDone" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "RES03_CoinSpecialChgPlan_t" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "CoinSpecialChgPlan" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "CoinSpecialChgActual" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "CoinSpecialChgOk" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "CoinSpecialChgDone" )
		{
			return GetColStr<STRINGT>(37);
		}
		if( strColName == "RES04_BilchgPlan_t" )
		{
			return GetColStr<STRINGT>(38);
		}
		if( strColName == "BilchgPlan" )
		{
			return GetColStr<STRINGT>(39);
		}
		if( strColName == "BilchgActual" )
		{
			return GetColStr<STRINGT>(40);
		}
		if( strColName == "BilchgOk" )
		{
			return GetColStr<STRINGT>(41);
		}
		if( strColName == "BilchgDone" )
		{
			return GetColStr<STRINGT>(42);
		}
		if( strColName == "TicketingFirstFlag" )
		{
			return GetColStr<STRINGT>(43);
		}
		if( strColName == "TicketingFirstDone" )
		{
			return GetColStr<STRINGT>(44);
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
			m_begin_time.Make(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_end_time.Make(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_stationname=strValPARA;
		}
		if( iColNum == 10 )
		{
			m_ReceiveTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_ReceiveCoin=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_ReceiveBill=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_TickePriceTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_TickePrice1=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_TicketoutPlan=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_ShouldChgTotal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_RES01_MoneyStorePlan_t=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_Coin5=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_Coin1=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			wl::SStrf::s2b(strValPARA,m_BillPieces);
		}
		if( iColNum == 21 )
		{
			m_MoneyStoreOk=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_MoneyStoreDone=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 23 )
		{
			m_RES01_TicketoutPlan_t=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_TicketoutActual=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_TicketoutOk=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_TicketoutErrReason=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 27 )
		{
			m_TicketoutDone=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			m_RES02_CoinRecycleChgPlan_t=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 29 )
		{
			m_CoinRecycleChgPlan=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 30 )
		{
			m_CoinRecycleChgActual=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 31 )
		{
			m_CoinRecycleChgOk=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			m_CoinRecycleChgDone=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
		{
			m_RES03_CoinSpecialChgPlan_t=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_CoinSpecialChgPlan=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_CoinSpecialChgActual=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_CoinSpecialChgOk=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_CoinSpecialChgDone=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 38 )
		{
			m_RES04_BilchgPlan_t=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 39 )
		{
			m_BilchgPlan=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 40 )
		{
			m_BilchgActual=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 41 )
		{
			m_BilchgOk=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 42 )
		{
			m_BilchgDone=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 43 )
		{
			m_TicketingFirstFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 44 )
		{
			m_TicketingFirstDone=wl::SStrf::satol(strValPARA);
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
		if( strColName == "begin_time" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "end_time" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "stationname" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "ReceiveTotal" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "ReceiveCoin" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "ReceiveBill" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "TickePriceTotal" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "TickePrice1" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "TicketoutPlan" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "ShouldChgTotal" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "RES01_MoneyStorePlan_t" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "Coin5" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "Coin1" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "BillPieces" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "MoneyStoreOk" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "MoneyStoreDone" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "RES01_TicketoutPlan_t" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "TicketoutActual" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "TicketoutOk" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "TicketoutErrReason" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "TicketoutDone" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "RES02_CoinRecycleChgPlan_t" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "CoinRecycleChgPlan" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "CoinRecycleChgActual" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "CoinRecycleChgOk" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "CoinRecycleChgDone" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "RES03_CoinSpecialChgPlan_t" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "CoinSpecialChgPlan" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "CoinSpecialChgActual" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "CoinSpecialChgOk" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "CoinSpecialChgDone" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
		if( strColName == "RES04_BilchgPlan_t" )
		{
			SetColVal<STRINGT>(38,strValPARA);
		}
		if( strColName == "BilchgPlan" )
		{
			SetColVal<STRINGT>(39,strValPARA);
		}
		if( strColName == "BilchgActual" )
		{
			SetColVal<STRINGT>(40,strValPARA);
		}
		if( strColName == "BilchgOk" )
		{
			SetColVal<STRINGT>(41,strValPARA);
		}
		if( strColName == "BilchgDone" )
		{
			SetColVal<STRINGT>(42,strValPARA);
		}
		if( strColName == "TicketingFirstFlag" )
		{
			SetColVal<STRINGT>(43,strValPARA);
		}
		if( strColName == "TicketingFirstDone" )
		{
			SetColVal<STRINGT>(44,strValPARA);
		}
	}

}
; 
//end of class a_waiter_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a_waiter_t
class a_waiter_t {
 
private:

	a_waiter_t_rowtype m_EmptyRow;
	std::vector<a_waiter_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a_waiter_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a_waiter_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a_waiter_t()
	{
	}

	virtual ~a_waiter_t(){;}
	

	//operator == 
	bool operator == (const a_waiter_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a_waiter_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a_waiter_t & rhs) const
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

	a_waiter_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a_waiter_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

///////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a_waiter_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a_waiter_t_rowtype tmpEmptyrow;
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

///////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes, if any.
//Return:	no return
	void Add(const a_waiter_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

///////////////////////////////////////////////////////////
//Function:	AddDefaultRow
//Effect:	add one default row using Add function.
//Return:	no return
	void AddDefaultRow()
	{
		Add( a_waiter_t_rowtype());
	}

////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a_waiter_t * p = new a_waiter_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

///////////////////////////////////////////////////////
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
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_strTblName(std::string strVal) 
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

//////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_lVer(long iVal) 
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

//////////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_strAffectDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strAffectDateTime(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_biDelFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biDelFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biDelFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_biDelFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biDelFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biDelFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_biIsAffect
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_biIsAffect==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_biIsAffect
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_biIsAffect(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_biIsAffect(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_strStampDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strStampDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
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

/////////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_begin_time
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_begin_time(SDte strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_begin_time==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_begin_time
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_begin_time(SDte strVal) 
	{
		std::vector<long> vRps ;
		SelE_begin_time( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_begin_time
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_begin_time(SDte strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_begin_time(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_end_time
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_end_time(SDte strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_end_time==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_end_time
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_end_time(SDte strVal) 
	{
		std::vector<long> vRps ;
		SelE_end_time( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_end_time
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_end_time(SDte strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_end_time(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_stationname
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_stationname(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_stationname==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_stationname
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_stationname(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_stationname( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_stationname
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_stationname(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_stationname(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_ReceiveTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReceiveTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReceiveTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_ReceiveTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_ReceiveTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ReceiveTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_ReceiveTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReceiveTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReceiveTotal(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_ReceiveCoin
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReceiveCoin(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReceiveCoin==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_ReceiveCoin
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_ReceiveCoin(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ReceiveCoin( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_ReceiveCoin
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReceiveCoin(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReceiveCoin(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_ReceiveBill
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ReceiveBill(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ReceiveBill==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_ReceiveBill
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_ReceiveBill(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ReceiveBill( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_ReceiveBill
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ReceiveBill(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ReceiveBill(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_TickePriceTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TickePriceTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TickePriceTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_TickePriceTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TickePriceTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TickePriceTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_TickePriceTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TickePriceTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TickePriceTotal(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_TickePrice1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TickePrice1(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TickePrice1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_TickePrice1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TickePrice1(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TickePrice1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_TickePrice1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TickePrice1(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TickePrice1(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_TicketoutPlan
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketoutPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketoutPlan==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_TicketoutPlan
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketoutPlan(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketoutPlan( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_TicketoutPlan
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketoutPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketoutPlan(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_ShouldChgTotal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ShouldChgTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ShouldChgTotal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_ShouldChgTotal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_ShouldChgTotal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ShouldChgTotal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_ShouldChgTotal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ShouldChgTotal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ShouldChgTotal(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES01_MoneyStorePlan_t
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01_MoneyStorePlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01_MoneyStorePlan_t==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES01_MoneyStorePlan_t
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_RES01_MoneyStorePlan_t(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01_MoneyStorePlan_t( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES01_MoneyStorePlan_t
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01_MoneyStorePlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01_MoneyStorePlan_t(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_Coin5
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Coin5(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Coin5==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_Coin5
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_Coin5(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_Coin5( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_Coin5
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Coin5(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Coin5(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_Coin1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_Coin1(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_Coin1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_Coin1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_Coin1(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_Coin1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_Coin1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_Coin1(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_Coin1(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_BillPieces
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BillPieces(uiarr_t<long,111> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BillPieces==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_BillPieces
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_BillPieces(uiarr_t<long,111> aVal) 
	{
		std::vector<long> vRps ;
		SelE_BillPieces( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_BillPieces
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BillPieces(uiarr_t<long,111> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BillPieces(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_MoneyStoreOk
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MoneyStoreOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MoneyStoreOk==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_MoneyStoreOk
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_MoneyStoreOk(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_MoneyStoreOk( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_MoneyStoreOk
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MoneyStoreOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MoneyStoreOk(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_MoneyStoreDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MoneyStoreDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MoneyStoreDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_MoneyStoreDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_MoneyStoreDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_MoneyStoreDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_MoneyStoreDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MoneyStoreDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MoneyStoreDone(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_RES01_TicketoutPlan_t
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01_TicketoutPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01_TicketoutPlan_t==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_RES01_TicketoutPlan_t
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_RES01_TicketoutPlan_t(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01_TicketoutPlan_t( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES01_TicketoutPlan_t
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01_TicketoutPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01_TicketoutPlan_t(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_TicketoutActual
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketoutActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketoutActual==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_TicketoutActual
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketoutActual(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketoutActual( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_TicketoutActual
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketoutActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketoutActual(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_TicketoutOk
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketoutOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketoutOk==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_TicketoutOk
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketoutOk(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketoutOk( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_TicketoutOk
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketoutOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketoutOk(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_TicketoutErrReason
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketoutErrReason(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketoutErrReason==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_TicketoutErrReason
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketoutErrReason(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketoutErrReason( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_TicketoutErrReason
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketoutErrReason(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketoutErrReason(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_TicketoutDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketoutDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketoutDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_TicketoutDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketoutDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketoutDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_TicketoutDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketoutDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketoutDone(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_RES02_CoinRecycleChgPlan_t
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES02_CoinRecycleChgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES02_CoinRecycleChgPlan_t==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES02_CoinRecycleChgPlan_t
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_RES02_CoinRecycleChgPlan_t(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES02_CoinRecycleChgPlan_t( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES02_CoinRecycleChgPlan_t
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES02_CoinRecycleChgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES02_CoinRecycleChgPlan_t(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_CoinRecycleChgPlan
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinRecycleChgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinRecycleChgPlan==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinRecycleChgPlan
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinRecycleChgPlan(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinRecycleChgPlan( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_CoinRecycleChgPlan
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinRecycleChgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinRecycleChgPlan(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CoinRecycleChgActual
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinRecycleChgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinRecycleChgActual==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinRecycleChgActual
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinRecycleChgActual(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinRecycleChgActual( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_CoinRecycleChgActual
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinRecycleChgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinRecycleChgActual(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_CoinRecycleChgOk
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinRecycleChgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinRecycleChgOk==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_CoinRecycleChgOk
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinRecycleChgOk(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinRecycleChgOk( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_CoinRecycleChgOk
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinRecycleChgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinRecycleChgOk(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_CoinRecycleChgDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinRecycleChgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinRecycleChgDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_CoinRecycleChgDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinRecycleChgDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinRecycleChgDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinRecycleChgDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinRecycleChgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinRecycleChgDone(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES03_CoinSpecialChgPlan_t
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES03_CoinSpecialChgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES03_CoinSpecialChgPlan_t==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES03_CoinSpecialChgPlan_t
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_RES03_CoinSpecialChgPlan_t(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES03_CoinSpecialChgPlan_t( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES03_CoinSpecialChgPlan_t
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES03_CoinSpecialChgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES03_CoinSpecialChgPlan_t(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_CoinSpecialChgPlan
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinSpecialChgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinSpecialChgPlan==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CoinSpecialChgPlan
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinSpecialChgPlan(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinSpecialChgPlan( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_CoinSpecialChgPlan
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinSpecialChgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinSpecialChgPlan(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_CoinSpecialChgActual
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinSpecialChgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinSpecialChgActual==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_CoinSpecialChgActual
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinSpecialChgActual(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinSpecialChgActual( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_CoinSpecialChgActual
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinSpecialChgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinSpecialChgActual(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_CoinSpecialChgOk
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinSpecialChgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinSpecialChgOk==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_CoinSpecialChgOk
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinSpecialChgOk(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinSpecialChgOk( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_CoinSpecialChgOk
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinSpecialChgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinSpecialChgOk(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_CoinSpecialChgDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CoinSpecialChgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CoinSpecialChgDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CoinSpecialChgDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_CoinSpecialChgDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CoinSpecialChgDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_CoinSpecialChgDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CoinSpecialChgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CoinSpecialChgDone(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES04_BilchgPlan_t
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES04_BilchgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES04_BilchgPlan_t==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES04_BilchgPlan_t
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_RES04_BilchgPlan_t(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES04_BilchgPlan_t( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_RES04_BilchgPlan_t
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES04_BilchgPlan_t(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES04_BilchgPlan_t(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_BilchgPlan
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BilchgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BilchgPlan==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_BilchgPlan
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_BilchgPlan(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_BilchgPlan( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_BilchgPlan
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BilchgPlan(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BilchgPlan(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_BilchgActual
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BilchgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BilchgActual==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_BilchgActual
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_BilchgActual(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_BilchgActual( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_BilchgActual
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BilchgActual(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BilchgActual(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_BilchgOk
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BilchgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BilchgOk==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_BilchgOk
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_BilchgOk(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BilchgOk( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_BilchgOk
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BilchgOk(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BilchgOk(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_BilchgDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BilchgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BilchgDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_BilchgDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_BilchgDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_BilchgDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_BilchgDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BilchgDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BilchgDone(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_TicketingFirstFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketingFirstFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketingFirstFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_TicketingFirstFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketingFirstFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketingFirstFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_TicketingFirstFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketingFirstFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketingFirstFlag(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_TicketingFirstDone
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketingFirstDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketingFirstDone==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_TicketingFirstDone
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_waiter_t_rowtype&
	a_waiter_t_rowtype & SelE1_TicketingFirstDone(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketingFirstDone( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_TicketingFirstDone
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketingFirstDone(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketingFirstDone(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////
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
//end of class a_waiter_t


#endif

