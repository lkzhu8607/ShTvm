
#ifndef V1_3AA6002_T_20141006_134533
#define V1_3AA6002_T_20141006_134533

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a6002_t
//Name:	a6002_t_rowtype
class a6002_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		10.0.5 6002-一票通交易数据。此类交互应一次上传多条交易数据记录。 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	wl::tuint8		m_unUploadFlag;			// 8	 0=hot, 1=uploaded 
	wl::tuint8		m_uTradeCode;			// 9	 交易事件码 
	wl::tuint8		m_uTicketTypeCode;			// 10	 车票类型码 仅一票通车票类型 
	long		m_lTicketMark;			// 11	 (原始)票卡标识 
	long		m_lNewTicketMark;			// 12	 新票卡标识 仅用于更换交易 
	long		m_lOperatorNum;			// 13	 操作员编号 仅用于BOM 
	u8arr_t<4>		m_SingleCardSam;			// 14	单程票SAM卡号 
	long		m_lTradeDateTime;			// 15	 交易日期时间 
	long		m_lValBeforeTrade;			// 16	 交易前票值 可为负值 
	long		m_lTradeVal;			// 17	 交易金额 
	wl::tuint8		m_SCNodecode1;			// 18	 当前车站 车站计算机的节点标识码 
	wl::tuint8		m_SCNodecode2;			// 19	 当前车站 车站计算机的节点标识码 
	wl::tuint8		m_SCNodecode3;			// 20	 当前车站 车站计算机的节点标识码 
	wl::tuint8		m_SCNodecode4;			// 21	 当前车站 车站计算机的节点标识码 
	wl::tuint8		m_LastSCNodecode1;			// 22	 上次使用车站 车站计算机的节点标识码 
	wl::tuint8		m_LastSCNodecode2;			// 23	 上次使用车站 车站计算机的节点标识码 
	wl::tuint8		m_LastSCNodecode3;			// 24	 上次使用车站 车站计算机的节点标识码 
	wl::tuint8		m_LastSCNodecode4;			// 25	 上次使用车站 车站计算机的节点标识码 
	wl::tuint8		m_uRemainTakeTimes;			// 26	 剩余乘次 仅用于乘次票 
	wl::tuint8		m_EqpNodecode1;			// 27	 终端设备标识 
	wl::tuint8		m_EqpNodecode2;			// 28	 终端设备标识 
	wl::tuint8		m_EqpNodecode3;			// 29	 终端设备标识 
	wl::tuint8		m_EqpNodecode4;			// 30	 终端设备标识 
	long		m_lTicketTradeTerminalFlow;			// 31	 终端流水号 
	long		m_lTicketCounter;			// 32	 票计数器 
	wl::tuint8		m_SellEqpNodecode1;			// 33	 售票设备标识售票设备标识码 包含线路、车站、设备编码 
	wl::tuint8		m_SellEqpNodecode2;			// 34	 售票设备标识售票设备标识码 包含线路、车站、设备编码 
	wl::tuint8		m_SellEqpNodecode3;			// 35	设备类型? 
	wl::tuint8		m_SellEqpNodecode4;			// 36	 售票设备标识售票设备标识码 包含线路、车站、设备编码 
	long		m_lPromotionVal;			// 37	 优惠金额 全价票额与实际交易额的差值 
	wl::tuint8		m_uTAC1;			// 38	 TAC 
	wl::tuint8		m_uTAC2;			// 39	 TAC 
	wl::tuint8		m_uTAC3;			// 40	 TAC 
	wl::tuint8		m_uTAC4;			// 41	 TAC 
 
public:

	a6002_t_rowtype()
	{
		m_strTblName = "a6002";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_unUploadFlag = 0;
		m_uTradeCode = 0;
		m_uTicketTypeCode = 0;
		m_lTicketMark = 0;
		m_lNewTicketMark = 0;
		m_lOperatorNum = 0;
		//m_SingleCardSam = //use default
		m_lTradeDateTime = 0;
		m_lValBeforeTrade = 0;
		m_lTradeVal = 0;
		m_SCNodecode1 = 0;
		m_SCNodecode2 = 0;
		m_SCNodecode3 = 0;
		m_SCNodecode4 = 0;
		m_LastSCNodecode1 = 0;
		m_LastSCNodecode2 = 0;
		m_LastSCNodecode3 = 0;
		m_LastSCNodecode4 = 0;
		m_uRemainTakeTimes = 0;
		m_EqpNodecode1 = 0;
		m_EqpNodecode2 = 0;
		m_EqpNodecode3 = 0;
		m_EqpNodecode4 = 0;
		m_lTicketTradeTerminalFlow = 0;
		m_lTicketCounter = 0;
		m_SellEqpNodecode1 = 0;
		m_SellEqpNodecode2 = 0;
		m_SellEqpNodecode3 = 0;
		m_SellEqpNodecode4 = 0;
		m_lPromotionVal = 0;
		m_uTAC1 = 0;
		m_uTAC2 = 0;
		m_uTAC3 = 0;
		m_uTAC4 = 0;
	}

	virtual ~a6002_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a6002_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a6002_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a6002_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_unUploadFlag));
		len1 = sizeof(m_unUploadFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTradeCode));
		len1 = sizeof(m_uTradeCode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTicketTypeCode));
		len1 = sizeof(m_uTicketTypeCode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketMark));
		len1 = sizeof(m_lTicketMark);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lNewTicketMark));
		len1 = sizeof(m_lNewTicketMark);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lOperatorNum));
		len1 = sizeof(m_lOperatorNum);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeDateTime));
		len1 = sizeof(m_lTradeDateTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lValBeforeTrade));
		len1 = sizeof(m_lValBeforeTrade);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeVal));
		len1 = sizeof(m_lTradeVal);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode1));
		len1 = sizeof(m_LastSCNodecode1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode2));
		len1 = sizeof(m_LastSCNodecode2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode3));
		len1 = sizeof(m_LastSCNodecode3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode4));
		len1 = sizeof(m_LastSCNodecode4);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uRemainTakeTimes));
		len1 = sizeof(m_uRemainTakeTimes);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketTradeTerminalFlow));
		len1 = sizeof(m_lTicketTradeTerminalFlow);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketCounter));
		len1 = sizeof(m_lTicketCounter);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode1));
		len1 = sizeof(m_SellEqpNodecode1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode2));
		len1 = sizeof(m_SellEqpNodecode2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode3));
		len1 = sizeof(m_SellEqpNodecode3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode4));
		len1 = sizeof(m_SellEqpNodecode4);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lPromotionVal));
		len1 = sizeof(m_lPromotionVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC1));
		len1 = sizeof(m_uTAC1);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC2));
		len1 = sizeof(m_uTAC2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC3));
		len1 = sizeof(m_uTAC3);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC4));
		len1 = sizeof(m_uTAC4);
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

	a6002_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_unUploadFlag = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTradeCode = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTicketTypeCode = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTicketMark = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lNewTicketMark = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lOperatorNum = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SingleCardSam = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTradeDateTime = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lValBeforeTrade = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTradeVal = *(long*)buf2; }else return *this; 
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
		 /*if( *buf2!='}')*/ m_LastSCNodecode1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LastSCNodecode2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LastSCNodecode3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LastSCNodecode4 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uRemainTakeTimes = *(wl::tuint8*)buf2; }else return *this; 
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
		 /*if( *buf2!='}')*/ m_lTicketTradeTerminalFlow = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lTicketCounter = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SellEqpNodecode1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SellEqpNodecode2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SellEqpNodecode3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SellEqpNodecode4 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_lPromotionVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTAC1 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTAC2 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTAC3 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_uTAC4 = *(wl::tuint8*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_unUploadFlag));
		len1 = sizeof(m_unUploadFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTradeCode));
		len1 = sizeof(m_uTradeCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTicketTypeCode));
		len1 = sizeof(m_uTicketTypeCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketMark));
		len1 = sizeof(m_lTicketMark);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lNewTicketMark));
		len1 = sizeof(m_lNewTicketMark);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lOperatorNum));
		len1 = sizeof(m_lOperatorNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SingleCardSam));
		len1 = sizeof(m_SingleCardSam);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeDateTime));
		len1 = sizeof(m_lTradeDateTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lValBeforeTrade));
		len1 = sizeof(m_lValBeforeTrade);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTradeVal));
		len1 = sizeof(m_lTradeVal);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode1));
		len1 = sizeof(m_LastSCNodecode1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode2));
		len1 = sizeof(m_LastSCNodecode2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode3));
		len1 = sizeof(m_LastSCNodecode3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LastSCNodecode4));
		len1 = sizeof(m_LastSCNodecode4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uRemainTakeTimes));
		len1 = sizeof(m_uRemainTakeTimes);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketTradeTerminalFlow));
		len1 = sizeof(m_lTicketTradeTerminalFlow);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lTicketCounter));
		len1 = sizeof(m_lTicketCounter);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode1));
		len1 = sizeof(m_SellEqpNodecode1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode2));
		len1 = sizeof(m_SellEqpNodecode2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode3));
		len1 = sizeof(m_SellEqpNodecode3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SellEqpNodecode4));
		len1 = sizeof(m_SellEqpNodecode4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_lPromotionVal));
		len1 = sizeof(m_lPromotionVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC1));
		len1 = sizeof(m_uTAC1);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC2));
		len1 = sizeof(m_uTAC2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC3));
		len1 = sizeof(m_uTAC3);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_uTAC4));
		len1 = sizeof(m_uTAC4);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a6002_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_unUploadFlag = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTradeCode = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTicketTypeCode = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTicketMark = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lNewTicketMark = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lOperatorNum = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SingleCardSam = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTradeDateTime = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lValBeforeTrade = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTradeVal = *(long*)buf2;
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
		m_LastSCNodecode1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LastSCNodecode2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LastSCNodecode3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LastSCNodecode4 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uRemainTakeTimes = *(wl::tuint8*)buf2;
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
		m_lTicketTradeTerminalFlow = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lTicketCounter = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SellEqpNodecode1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SellEqpNodecode2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SellEqpNodecode3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SellEqpNodecode4 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_lPromotionVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTAC1 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTAC2 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTAC3 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_uTAC4 = *(wl::tuint8*)buf2;
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
//Function:	GetCol_unUploadFlag
//Effect:	get ref of col. col is unUploadFlag
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_unUploadFlag(void)
	{
		return m_unUploadFlag;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_uTradeCode
//Effect:	get ref of col. col is uTradeCode
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTradeCode(void)
	{
		return m_uTradeCode;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_uTicketTypeCode
//Effect:	get ref of col. col is uTicketTypeCode
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTicketTypeCode(void)
	{
		return m_uTicketTypeCode;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_lTicketMark
//Effect:	get ref of col. col is lTicketMark
//Return:	long & 
	long & GetCol_lTicketMark(void)
	{
		return m_lTicketMark;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_lNewTicketMark
//Effect:	get ref of col. col is lNewTicketMark
//Return:	long & 
	long & GetCol_lNewTicketMark(void)
	{
		return m_lNewTicketMark;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_lOperatorNum
//Effect:	get ref of col. col is lOperatorNum
//Return:	long & 
	long & GetCol_lOperatorNum(void)
	{
		return m_lOperatorNum;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_SingleCardSam
//Effect:	get ref of col. col is SingleCardSam
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_SingleCardSam(void)
	{
		return m_SingleCardSam;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_lTradeDateTime
//Effect:	get ref of col. col is lTradeDateTime
//Return:	long & 
	long & GetCol_lTradeDateTime(void)
	{
		return m_lTradeDateTime;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_lValBeforeTrade
//Effect:	get ref of col. col is lValBeforeTrade
//Return:	long & 
	long & GetCol_lValBeforeTrade(void)
	{
		return m_lValBeforeTrade;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lTradeVal
//Effect:	get ref of col. col is lTradeVal
//Return:	long & 
	long & GetCol_lTradeVal(void)
	{
		return m_lTradeVal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode1
//Effect:	get ref of col. col is SCNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode1(void)
	{
		return m_SCNodecode1;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SCNodecode2
//Effect:	get ref of col. col is SCNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SCNodecode2(void)
	{
		return m_SCNodecode2;
	}

/////////////////////////////////////////////////////////////////
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
//Function:	GetCol_LastSCNodecode1
//Effect:	get ref of col. col is LastSCNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_LastSCNodecode1(void)
	{
		return m_LastSCNodecode1;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_LastSCNodecode2
//Effect:	get ref of col. col is LastSCNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_LastSCNodecode2(void)
	{
		return m_LastSCNodecode2;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_LastSCNodecode3
//Effect:	get ref of col. col is LastSCNodecode3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_LastSCNodecode3(void)
	{
		return m_LastSCNodecode3;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_LastSCNodecode4
//Effect:	get ref of col. col is LastSCNodecode4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_LastSCNodecode4(void)
	{
		return m_LastSCNodecode4;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_uRemainTakeTimes
//Effect:	get ref of col. col is uRemainTakeTimes
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uRemainTakeTimes(void)
	{
		return m_uRemainTakeTimes;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode1
//Effect:	get ref of col. col is EqpNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode1(void)
	{
		return m_EqpNodecode1;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_EqpNodecode2
//Effect:	get ref of col. col is EqpNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_EqpNodecode2(void)
	{
		return m_EqpNodecode2;
	}

/////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//Function:	GetCol_lTicketTradeTerminalFlow
//Effect:	get ref of col. col is lTicketTradeTerminalFlow
//Return:	long & 
	long & GetCol_lTicketTradeTerminalFlow(void)
	{
		return m_lTicketTradeTerminalFlow;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_lTicketCounter
//Effect:	get ref of col. col is lTicketCounter
//Return:	long & 
	long & GetCol_lTicketCounter(void)
	{
		return m_lTicketCounter;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_SellEqpNodecode1
//Effect:	get ref of col. col is SellEqpNodecode1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SellEqpNodecode1(void)
	{
		return m_SellEqpNodecode1;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_SellEqpNodecode2
//Effect:	get ref of col. col is SellEqpNodecode2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SellEqpNodecode2(void)
	{
		return m_SellEqpNodecode2;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_SellEqpNodecode3
//Effect:	get ref of col. col is SellEqpNodecode3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SellEqpNodecode3(void)
	{
		return m_SellEqpNodecode3;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_SellEqpNodecode4
//Effect:	get ref of col. col is SellEqpNodecode4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SellEqpNodecode4(void)
	{
		return m_SellEqpNodecode4;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_lPromotionVal
//Effect:	get ref of col. col is lPromotionVal
//Return:	long & 
	long & GetCol_lPromotionVal(void)
	{
		return m_lPromotionVal;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_uTAC1
//Effect:	get ref of col. col is uTAC1
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTAC1(void)
	{
		return m_uTAC1;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_uTAC2
//Effect:	get ref of col. col is uTAC2
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTAC2(void)
	{
		return m_uTAC2;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_uTAC3
//Effect:	get ref of col. col is uTAC3
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTAC3(void)
	{
		return m_uTAC3;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_uTAC4
//Effect:	get ref of col. col is uTAC4
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_uTAC4(void)
	{
		return m_uTAC4;
	}

 
public:

/////////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 41;
	}

/////////////////////////////////////////////////////////////////
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
			return "unUploadFlag";
		}
		if( iColNum == 8 )
		{
			return "uTradeCode";
		}
		if( iColNum == 9 )
		{
			return "uTicketTypeCode";
		}
		if( iColNum == 10 )
		{
			return "lTicketMark";
		}
		if( iColNum == 11 )
		{
			return "lNewTicketMark";
		}
		if( iColNum == 12 )
		{
			return "lOperatorNum";
		}
		if( iColNum == 13 )
		{
			return "SingleCardSam";
		}
		if( iColNum == 14 )
		{
			return "lTradeDateTime";
		}
		if( iColNum == 15 )
		{
			return "lValBeforeTrade";
		}
		if( iColNum == 16 )
		{
			return "lTradeVal";
		}
		if( iColNum == 17 )
		{
			return "SCNodecode1";
		}
		if( iColNum == 18 )
		{
			return "SCNodecode2";
		}
		if( iColNum == 19 )
		{
			return "SCNodecode3";
		}
		if( iColNum == 20 )
		{
			return "SCNodecode4";
		}
		if( iColNum == 21 )
		{
			return "LastSCNodecode1";
		}
		if( iColNum == 22 )
		{
			return "LastSCNodecode2";
		}
		if( iColNum == 23 )
		{
			return "LastSCNodecode3";
		}
		if( iColNum == 24 )
		{
			return "LastSCNodecode4";
		}
		if( iColNum == 25 )
		{
			return "uRemainTakeTimes";
		}
		if( iColNum == 26 )
		{
			return "EqpNodecode1";
		}
		if( iColNum == 27 )
		{
			return "EqpNodecode2";
		}
		if( iColNum == 28 )
		{
			return "EqpNodecode3";
		}
		if( iColNum == 29 )
		{
			return "EqpNodecode4";
		}
		if( iColNum == 30 )
		{
			return "lTicketTradeTerminalFlow";
		}
		if( iColNum == 31 )
		{
			return "lTicketCounter";
		}
		if( iColNum == 32 )
		{
			return "SellEqpNodecode1";
		}
		if( iColNum == 33 )
		{
			return "SellEqpNodecode2";
		}
		if( iColNum == 34 )
		{
			return "SellEqpNodecode3";
		}
		if( iColNum == 35 )
		{
			return "SellEqpNodecode4";
		}
		if( iColNum == 36 )
		{
			return "lPromotionVal";
		}
		if( iColNum == 37 )
		{
			return "uTAC1";
		}
		if( iColNum == 38 )
		{
			return "uTAC2";
		}
		if( iColNum == 39 )
		{
			return "uTAC3";
		}
		if( iColNum == 40 )
		{
			return "uTAC4";
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
		if( strColName == "unUploadFlag" )
		{
			return 7;
		}
		if( strColName == "uTradeCode" )
		{
			return 8;
		}
		if( strColName == "uTicketTypeCode" )
		{
			return 9;
		}
		if( strColName == "lTicketMark" )
		{
			return 10;
		}
		if( strColName == "lNewTicketMark" )
		{
			return 11;
		}
		if( strColName == "lOperatorNum" )
		{
			return 12;
		}
		if( strColName == "SingleCardSam" )
		{
			return 13;
		}
		if( strColName == "lTradeDateTime" )
		{
			return 14;
		}
		if( strColName == "lValBeforeTrade" )
		{
			return 15;
		}
		if( strColName == "lTradeVal" )
		{
			return 16;
		}
		if( strColName == "SCNodecode1" )
		{
			return 17;
		}
		if( strColName == "SCNodecode2" )
		{
			return 18;
		}
		if( strColName == "SCNodecode3" )
		{
			return 19;
		}
		if( strColName == "SCNodecode4" )
		{
			return 20;
		}
		if( strColName == "LastSCNodecode1" )
		{
			return 21;
		}
		if( strColName == "LastSCNodecode2" )
		{
			return 22;
		}
		if( strColName == "LastSCNodecode3" )
		{
			return 23;
		}
		if( strColName == "LastSCNodecode4" )
		{
			return 24;
		}
		if( strColName == "uRemainTakeTimes" )
		{
			return 25;
		}
		if( strColName == "EqpNodecode1" )
		{
			return 26;
		}
		if( strColName == "EqpNodecode2" )
		{
			return 27;
		}
		if( strColName == "EqpNodecode3" )
		{
			return 28;
		}
		if( strColName == "EqpNodecode4" )
		{
			return 29;
		}
		if( strColName == "lTicketTradeTerminalFlow" )
		{
			return 30;
		}
		if( strColName == "lTicketCounter" )
		{
			return 31;
		}
		if( strColName == "SellEqpNodecode1" )
		{
			return 32;
		}
		if( strColName == "SellEqpNodecode2" )
		{
			return 33;
		}
		if( strColName == "SellEqpNodecode3" )
		{
			return 34;
		}
		if( strColName == "SellEqpNodecode4" )
		{
			return 35;
		}
		if( strColName == "lPromotionVal" )
		{
			return 36;
		}
		if( strColName == "uTAC1" )
		{
			return 37;
		}
		if( strColName == "uTAC2" )
		{
			return 38;
		}
		if( strColName == "uTAC3" )
		{
			return 39;
		}
		if( strColName == "uTAC4" )
		{
			return 40;
		}
		return -1;
	}

////////////////////////////////////////////////////////
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
			return wl::SStrf::sltoa(m_unUploadFlag);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_uTradeCode);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_uTicketTypeCode);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_lTicketMark);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_lNewTicketMark);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_lOperatorNum);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::b2s(m_SingleCardSam);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_lTradeDateTime);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_lValBeforeTrade);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_lTradeVal);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_SCNodecode1);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_SCNodecode2);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_SCNodecode3);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_SCNodecode4);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_LastSCNodecode1);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sltoa(m_LastSCNodecode2);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_LastSCNodecode3);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_LastSCNodecode4);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_uRemainTakeTimes);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode1);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode2);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode3);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::sltoa(m_EqpNodecode4);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::sltoa(m_lTicketTradeTerminalFlow);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_lTicketCounter);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_SellEqpNodecode1);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_SellEqpNodecode2);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_SellEqpNodecode3);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_SellEqpNodecode4);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_lPromotionVal);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_uTAC1);
		}
		if( iColNum == 38 )
		{
			return wl::SStrf::sltoa(m_uTAC2);
		}
		if( iColNum == 39 )
		{
			return wl::SStrf::sltoa(m_uTAC3);
		}
		if( iColNum == 40 )
		{
			return wl::SStrf::sltoa(m_uTAC4);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

////////////////////////////////////////////////////////////
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
		if( strColName == "unUploadFlag" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "uTradeCode" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "uTicketTypeCode" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "lTicketMark" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "lNewTicketMark" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "lOperatorNum" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "SingleCardSam" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "lTradeDateTime" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "lValBeforeTrade" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "lTradeVal" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "SCNodecode1" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "SCNodecode2" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "SCNodecode3" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "SCNodecode4" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "LastSCNodecode1" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "LastSCNodecode2" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "LastSCNodecode3" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "LastSCNodecode4" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "uRemainTakeTimes" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "EqpNodecode1" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "EqpNodecode2" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "EqpNodecode3" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "EqpNodecode4" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "lTicketTradeTerminalFlow" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "lTicketCounter" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "SellEqpNodecode1" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "SellEqpNodecode2" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "SellEqpNodecode3" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "SellEqpNodecode4" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "lPromotionVal" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "uTAC1" )
		{
			return GetColStr<STRINGT>(37);
		}
		if( strColName == "uTAC2" )
		{
			return GetColStr<STRINGT>(38);
		}
		if( strColName == "uTAC3" )
		{
			return GetColStr<STRINGT>(39);
		}
		if( strColName == "uTAC4" )
		{
			return GetColStr<STRINGT>(40);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

/////////////////////////////////////////////////////////
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
			m_unUploadFlag=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_uTradeCode=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_uTicketTypeCode=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_lTicketMark=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_lNewTicketMark=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_lOperatorNum=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			wl::SStrf::s2b(strValPARA,m_SingleCardSam);
		}
		if( iColNum == 14 )
		{
			m_lTradeDateTime=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_lValBeforeTrade=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_lTradeVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_SCNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_SCNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_SCNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_SCNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_LastSCNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_LastSCNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 23 )
		{
			m_LastSCNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_LastSCNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_uRemainTakeTimes=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_EqpNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 27 )
		{
			m_EqpNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			m_EqpNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 29 )
		{
			m_EqpNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 30 )
		{
			m_lTicketTradeTerminalFlow=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 31 )
		{
			m_lTicketCounter=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			m_SellEqpNodecode1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
		{
			m_SellEqpNodecode2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_SellEqpNodecode3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_SellEqpNodecode4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_lPromotionVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_uTAC1=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 38 )
		{
			m_uTAC2=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 39 )
		{
			m_uTAC3=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 40 )
		{
			m_uTAC4=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
	}

////////////////////////////////////////////////////////////////
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
		if( strColName == "unUploadFlag" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "uTradeCode" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "uTicketTypeCode" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "lTicketMark" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "lNewTicketMark" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "lOperatorNum" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "SingleCardSam" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "lTradeDateTime" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "lValBeforeTrade" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "lTradeVal" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "SCNodecode1" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "SCNodecode2" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "SCNodecode3" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "SCNodecode4" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "LastSCNodecode1" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "LastSCNodecode2" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "LastSCNodecode3" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "LastSCNodecode4" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "uRemainTakeTimes" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "EqpNodecode1" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "EqpNodecode2" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "EqpNodecode3" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "EqpNodecode4" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "lTicketTradeTerminalFlow" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "lTicketCounter" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "SellEqpNodecode1" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "SellEqpNodecode2" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "SellEqpNodecode3" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "SellEqpNodecode4" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "lPromotionVal" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "uTAC1" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
		if( strColName == "uTAC2" )
		{
			SetColVal<STRINGT>(38,strValPARA);
		}
		if( strColName == "uTAC3" )
		{
			SetColVal<STRINGT>(39,strValPARA);
		}
		if( strColName == "uTAC4" )
		{
			SetColVal<STRINGT>(40,strValPARA);
		}
	}

}
; 
//end of class a6002_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a6002_t
class a6002_t {
 
private:

	a6002_t_rowtype m_EmptyRow;
	std::vector<a6002_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a6002_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a6002_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a6002_t()
	{
	}

	virtual ~a6002_t(){;}
	

	//operator == 
	bool operator == (const a6002_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a6002_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a6002_t & rhs) const
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

	a6002_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a6002_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

////////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl
//Return:	long
	long GetRowCount( )
	{
		return (long)m_DATAcorpora.size();
	}

/////////////////////////////////////////////////////////////////
//Function:	GetRowCount
//Effect:	get row count of the tbl according to RPS
//Return:	long
	long GetRowCount(const std::vector<long> & vRps)
	{
		return (long)vRps.size();
	}

/////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a6002_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

/////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a6002_t_rowtype tmpEmptyrow;
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

///////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a6002_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

/////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

//////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

////////////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a6002_t * p = new a6002_t;
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

///////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_strTblName(std::string strVal) 
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

//////////////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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

////////////////////////////////////////////////////////////
//Function:	SelE1_biIsAffect
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
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
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strStampDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_strStampDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strStampDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strStampDateTime(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_strDataRef
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strDataRef==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_strDataRef(std::string strVal) 
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

/////////////////////////////////////////////////////////////
//Function:	SelE_unUploadFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_unUploadFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_unUploadFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_unUploadFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_unUploadFlag(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_unUploadFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_unUploadFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_unUploadFlag(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_unUploadFlag(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_uTradeCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTradeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTradeCode==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_uTradeCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTradeCode(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTradeCode( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_uTradeCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTradeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTradeCode(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_uTicketTypeCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTicketTypeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTicketTypeCode==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_uTicketTypeCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTicketTypeCode(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTicketTypeCode( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_uTicketTypeCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTicketTypeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTicketTypeCode(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_lTicketMark
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTicketMark(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTicketMark==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_lTicketMark
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lTicketMark(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTicketMark( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_lTicketMark
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTicketMark(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTicketMark(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_lNewTicketMark
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lNewTicketMark(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lNewTicketMark==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_lNewTicketMark
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lNewTicketMark(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lNewTicketMark( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_lNewTicketMark
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lNewTicketMark(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lNewTicketMark(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_lOperatorNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lOperatorNum(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lOperatorNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_lOperatorNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lOperatorNum(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lOperatorNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_lOperatorNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lOperatorNum(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lOperatorNum(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_SingleCardSam
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SingleCardSam(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SingleCardSam==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_SingleCardSam
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SingleCardSam(u8arr_t<4> aVal) 
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

/////////////////////////////////////////////////////////////////
//Function:	SelE_lTradeDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTradeDateTime(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTradeDateTime==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_lTradeDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lTradeDateTime(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTradeDateTime( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_lTradeDateTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTradeDateTime(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTradeDateTime(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_lValBeforeTrade
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lValBeforeTrade(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lValBeforeTrade==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_lValBeforeTrade
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lValBeforeTrade(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lValBeforeTrade( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_lValBeforeTrade
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lValBeforeTrade(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lValBeforeTrade(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_lTradeVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTradeVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTradeVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_lTradeVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lTradeVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTradeVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_lTradeVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTradeVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTradeVal(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SCNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode1(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SCNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode2(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SCNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode3(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_SCNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SCNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_SCNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SCNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SCNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_SCNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SCNodecode4(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_LastSCNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LastSCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LastSCNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_LastSCNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_LastSCNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_LastSCNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_LastSCNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LastSCNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LastSCNodecode1(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_LastSCNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LastSCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LastSCNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_LastSCNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_LastSCNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_LastSCNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_LastSCNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LastSCNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LastSCNodecode2(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_LastSCNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LastSCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LastSCNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_LastSCNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_LastSCNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_LastSCNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_LastSCNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LastSCNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LastSCNodecode3(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_LastSCNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LastSCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LastSCNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_LastSCNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_LastSCNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_LastSCNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_LastSCNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LastSCNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LastSCNodecode4(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_uRemainTakeTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uRemainTakeTimes(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uRemainTakeTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_uRemainTakeTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uRemainTakeTimes(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uRemainTakeTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_uRemainTakeTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uRemainTakeTimes(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uRemainTakeTimes(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_EqpNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode1(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_EqpNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_EqpNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_EqpNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_EqpNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_EqpNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
//Function:	SelE1_EqpNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_EqpNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_EqpNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_EqpNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_EqpNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_EqpNodecode4(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_lTicketTradeTerminalFlow
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTicketTradeTerminalFlow(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTicketTradeTerminalFlow==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_lTicketTradeTerminalFlow
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lTicketTradeTerminalFlow(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTicketTradeTerminalFlow( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_lTicketTradeTerminalFlow
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTicketTradeTerminalFlow(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTicketTradeTerminalFlow(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_lTicketCounter
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lTicketCounter(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lTicketCounter==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_lTicketCounter
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lTicketCounter(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lTicketCounter( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_lTicketCounter
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lTicketCounter(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lTicketCounter(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_SellEqpNodecode1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SellEqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SellEqpNodecode1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_SellEqpNodecode1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SellEqpNodecode1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SellEqpNodecode1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_SellEqpNodecode1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SellEqpNodecode1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SellEqpNodecode1(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SellEqpNodecode2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SellEqpNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SellEqpNodecode2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_SellEqpNodecode2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SellEqpNodecode2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SellEqpNodecode2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_SellEqpNodecode2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SellEqpNodecode2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SellEqpNodecode2(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_SellEqpNodecode3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SellEqpNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SellEqpNodecode3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_SellEqpNodecode3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SellEqpNodecode3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SellEqpNodecode3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_SellEqpNodecode3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SellEqpNodecode3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SellEqpNodecode3(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_SellEqpNodecode4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SellEqpNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SellEqpNodecode4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_SellEqpNodecode4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_SellEqpNodecode4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SellEqpNodecode4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_SellEqpNodecode4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SellEqpNodecode4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SellEqpNodecode4(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_lPromotionVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lPromotionVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_lPromotionVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_lPromotionVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lPromotionVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_lPromotionVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lPromotionVal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_uTAC1
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTAC1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTAC1==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_uTAC1
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTAC1(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTAC1( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_uTAC1
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTAC1(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTAC1(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_uTAC2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTAC2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTAC2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_uTAC2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTAC2(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTAC2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_uTAC2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTAC2(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTAC2(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_uTAC3
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTAC3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTAC3==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_uTAC3
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTAC3(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTAC3( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_uTAC3
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTAC3(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTAC3(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_uTAC4
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_uTAC4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_uTAC4==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_uTAC4
//Effect:	select 1st row where col=val, or return default row.
//Return:	a6002_t_rowtype&
	a6002_t_rowtype & SelE1_uTAC4(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_uTAC4( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_uTAC4
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_uTAC4(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_uTAC4(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
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
//end of class a6002_t


#endif

