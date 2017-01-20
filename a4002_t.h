
#ifndef V1_3AA4002_T_20140523_162738
#define V1_3AA4002_T_20140523_162738

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a4002_t
//Name:	a4002_t_rowtype
class a4002_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		8.0.4  4002-车票类型表。此类交互用于向交互的接受方发送车票类型参数。这些参数 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	int		m_PriorityJudgeType;			// a	1	交通卡交易优先级判断（仅纯消费类设备使用） Byte 1 
	int		m_CPUCardParaFlag;			// a	2	CPU卡维护参数启用标志（仅充资类设备适用）   Byte 1 
	u8arr_t<33>		m_RES_01;			// a	3	[保留]  BLock 33 
	long		m_ConnectGapTimesec;			// a	4	车站联乘间隔时间 以1分钟为单位 Block 1 
	long		m_LostTicketPenalty;			// a	5	遗失票罚款金额  Word 2 
	long		m_OvertravelPenalty;			// a	6	超程罚款金额  Word 2 
	long		m_OvertimePenalty;			// a	7	超时罚款金额  Word 2 
	long		m_ExcessPenalty;			// a	8	进/出站补票罚款金额  Word 2 
	long		m_SavingsCardInitVal;			// a	9	储值卡初始票值[保留]  Word 2 
	long		m_NextdayWorkTimehour;			// a	10	次日运营时间午夜后的小时数，当验票时这段时间仍被认为是同一天范围：0~12Byte1 
	u8arr_t<16>		m_InStationMaxTime;			// a	11	进站到出站允许最长时间按照区域分别定义的允许最长时间，每区域一个字节，以6分钟为单位，区域号大于16时统一按区域16计算每字节范围：0~240（0~1440分钟）Byte16 
	wl::tuint8		m_TicketType;			// a	12	车票类型码 一票通和一卡通中的车票种类 Byte 1 
	std::string		m_strTicketTypeDiscEn;			// a	13	车票类型描述（英文）  String 15 
	long		m_TicketTypeDiscCh;			// a	14	车票类型描述（中文） 清分系统本地语言资源文件指针 Pointer 4 
	u8arr_t<2>		m_TicketCtrlCode;			// a	15	车票控制码 Word 2 
	u8arr_t<2>		m_TicketValiIndi;			// a	16	车票验证指示 Word 2 
	long		m_ValidityTimeUnit;			// a	17	有效期单位：0000：表示卡内记录有效期其它：代表卡内启用日期后加上该参数的有效单位时间（以小时为单位）为最终卡片有效期Word2 
	long		m_SpecialChkDays;			// a	18	特殊验证期发售/最后一次充值后在检票机上使用的有效期的天数，若为0，则无需特殊验证Word2 
	long		m_InitVal;			// a	19	初始票值  Word 2 
	long		m_BuyVal;			// a	20	 购买值	Word 2 
	long		m_CardInitVal;			// a	21	 交通卡初始票值		Word 2 
	long		m_CardInitRewardVal;			// a	22	交通卡初始奖励值  Word 2 
	ui16arr_t<4>		m_CardRechargeChoise;			// a	23	交通卡充值选择 4个充值金额，每个2字节，供BOM或CVM显示界面用 Word 8 
	ui16arr_t<4>		m_CardRechargeRewardChoise;			// a	23	交通卡充值奖励选择[保留]  Word 8 
	long		m_B0_MarginTimesec;			// a	24	宽限时间 Byte 1 
	long		m_B0_UnRushhourIdx;			// a	25	非高峰时段码 Byte 1 
	long		m_B0_DiscountRateIdx;			// a	26	打折费率码（非高峰）指向4003-费率表中记录的索引用于得到非高峰时的扣费值范围：0~61Byte1 
	long		m_B0_FullFareRateIdx;			// a	27	全价费率码（高峰） Byte 1 
	long		m_B1_MarginTimesec;			// a	28	宽限时间 Byte 1 
	long		m_B1_UnRushhourIdx;			// a	29	非高峰时段码 Byte 1 
	long		m_B1_DiscountRateIdx;			// a	30	打折费率码（非高峰）指向4003-费率表中记录的索引用于得到非高峰时的扣费值范围：0~61Byte1 
	long		m_B1_FullFareRateIdx;			// a	31	全价费率码（高峰） Byte 1 
	long		m_B2_MarginTimesec;			// a	32	宽限时间 Byte 1 
	long		m_B2_UnRushhourIdx;			// a	33	非高峰时段码 Byte 1 
	long		m_B2_DiscountRateIdx;			// a	34	打折费率码（非高峰）指向4003-费率表中记录的索引用于得到非高峰时的扣费值范围：0~61Byte1 
	long		m_B2_FullFareRateIdx;			// a	35	全价费率码（高峰） Byte 1 
	long		m_B3_MarginTimesec;			// a	36	宽限时间 Byte 1 
	long		m_B3_UnRushhourIdx;			// a	37	非高峰时段码 Byte 1 
	long		m_B3_DiscountRateIdx;			// a	38	打折费率码（非高峰）指向4003-费率表中记录的索引用于得到非高峰时的扣费值范围：0~61Byte1 
	long		m_B3_FullFareRateIdx;			// a	39	全价费率码（高峰） Byte 1 
	long		m_AccumulateBeginPromotionTimes;			// a	40	累积乘坐起始优惠次数 当车票验证指示的Bit0、Bit2为1且Bit3为0时有效 Word 2 
	long		m_AccumulateBeginPromotionVal;			// a	41	累积乘坐起始优惠金额 当车票验证指示的Bit0、Bit2为1且Bit3为1时有效 LONG 4 
	long		m_AccumulatePromotionPercent;			// a	42	累积乘坐优惠比例 优惠百分比，使用时需除以100 Word 2 
	long		m_ConnectPromotionVal;			// a	43	联乘优惠金额 当车票验证指示的Bit0、Bit4为1且Bit5为1时本字段有效，以分为单位 Word 2 
	long		m_ConnectPromotionPercent;			// a	44	联乘优惠比例 当车票验证指示的Bit0、Bit4为1且Bit5为0时本字段有效，表示优惠百分比，使用时需除以100 Word 2 
	long		m_PromotionPriorityLevelType;			// a	45	优惠优先级 Byte 1 
	long		m_ConnectPromotionValidTimePeriod;			// a	46	联乘优惠有效时段 以10分钟为单位 Byte 1 
	wl::tuint8		m_ConnectPromotionTrade;			// a	47	联乘优惠行业范围 Byte 1 
	wl::tuint8		m_SpecialCardMapTypeCode;			// a	48	特种卡映射的卡型代码 在特种卡不满足自身属性条件时，应映射为本字段制定的卡型代码。00表示本字段无效。 Block 1 
	long		m_TimeTimesTicketTimeUnit;			// a	49	计时计次票时间单位 规定计时计次票单位时间（小时） Block 1 
	long		m_OvertimePenalty2;			// a	50	超时罚款金额  Word 2 
	long		m_ExcessPenalty2;			// a	51	进/出站补票罚款金额  Word 2 
	long		m_CardSavingsLimit;			// a	52	交通卡储值限额规定交通卡内金额上限，以元为单位（以1000元上限为例，此域为0003E8）Byte3 
	long		m_TimesTicketDefaultCarfare;			// a	53	计次类车票单次默认车资单位为分Word2 
	long		m_CrosssitePenalty;			// a	54	跨线跨站乘坐罚款单位为分Word2 
	u8arr_t<4>		m_RES_02;			// a	55	[保留]  Block 4 
	wl::tuint8		m_RES_03;			// a	56	[保留]  Byte 1 
	wl::tuint8		m_RES_04;			// a	57	[保留]  Byte 1 
	wl::tuint8		m_RES_05;			// a	58	[保留]  Byte 1 
	long		m_DayMaxTakeTimes;			// a	59	每日最大乘次 范围：0~255，255 – 无限制，对于单程票，此字段为0 Byte 1 
	wl::tuint8		m_RES_06;			// a	60	[保留]  Byte 1 
 
public:

	a4002_t_rowtype()
	{
		m_strTblName = "a4002";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_PriorityJudgeType = 0;
		m_CPUCardParaFlag = 0;
		//m_RES_01 = //use default
		m_ConnectGapTimesec = 0;
		m_LostTicketPenalty = 0;
		m_OvertravelPenalty = 0;
		m_OvertimePenalty = 0;
		m_ExcessPenalty = 0;
		m_SavingsCardInitVal = 0;
		m_NextdayWorkTimehour = 0;
		//m_InStationMaxTime = //use default
		m_TicketType = 0;
		m_strTicketTypeDiscEn = "";
		m_TicketTypeDiscCh = 0;
		//m_TicketCtrlCode = //use default
		//m_TicketValiIndi = //use default
		m_ValidityTimeUnit = 0;
		m_SpecialChkDays = 0;
		m_InitVal = 0;
		m_BuyVal = 0;
		m_CardInitVal = 0;
		m_CardInitRewardVal = 0;
		//m_CardRechargeChoise = //use default
		//m_CardRechargeRewardChoise = //use default
		m_B0_MarginTimesec = 0;
		m_B0_UnRushhourIdx = 0;
		m_B0_DiscountRateIdx = 0;
		m_B0_FullFareRateIdx = 0;
		m_B1_MarginTimesec = 0;
		m_B1_UnRushhourIdx = 0;
		m_B1_DiscountRateIdx = 0;
		m_B1_FullFareRateIdx = 0;
		m_B2_MarginTimesec = 0;
		m_B2_UnRushhourIdx = 0;
		m_B2_DiscountRateIdx = 0;
		m_B2_FullFareRateIdx = 0;
		m_B3_MarginTimesec = 0;
		m_B3_UnRushhourIdx = 0;
		m_B3_DiscountRateIdx = 0;
		m_B3_FullFareRateIdx = 0;
		m_AccumulateBeginPromotionTimes = 0;
		m_AccumulateBeginPromotionVal = 0;
		m_AccumulatePromotionPercent = 0;
		m_ConnectPromotionVal = 0;
		m_ConnectPromotionPercent = 0;
		m_PromotionPriorityLevelType = 0;
		m_ConnectPromotionValidTimePeriod = 0;
		m_ConnectPromotionTrade = 0;
		m_SpecialCardMapTypeCode = 0;
		m_TimeTimesTicketTimeUnit = 0;
		m_OvertimePenalty2 = 0;
		m_ExcessPenalty2 = 0;
		m_CardSavingsLimit = 0;
		m_TimesTicketDefaultCarfare = 0;
		m_CrosssitePenalty = 0;
		//m_RES_02 = //use default
		m_RES_03 = 0;
		m_RES_04 = 0;
		m_RES_05 = 0;
		m_DayMaxTakeTimes = 0;
		m_RES_06 = 0;
	}

	virtual ~a4002_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a4002_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a4002_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a4002_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PriorityJudgeType));
		len1 = sizeof(m_PriorityJudgeType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CPUCardParaFlag));
		len1 = sizeof(m_CPUCardParaFlag);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectGapTimesec));
		len1 = sizeof(m_ConnectGapTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LostTicketPenalty));
		len1 = sizeof(m_LostTicketPenalty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertravelPenalty));
		len1 = sizeof(m_OvertravelPenalty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertimePenalty));
		len1 = sizeof(m_OvertimePenalty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ExcessPenalty));
		len1 = sizeof(m_ExcessPenalty);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SavingsCardInitVal));
		len1 = sizeof(m_SavingsCardInitVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_NextdayWorkTimehour));
		len1 = sizeof(m_NextdayWorkTimehour);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InStationMaxTime));
		len1 = sizeof(m_InStationMaxTime);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketType));
		len1 = sizeof(m_TicketType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_strTicketTypeDiscEn.c_str();
		len1 = (long)(m_strTicketTypeDiscEn.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketTypeDiscCh));
		len1 = sizeof(m_TicketTypeDiscCh);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketCtrlCode));
		len1 = sizeof(m_TicketCtrlCode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketValiIndi));
		len1 = sizeof(m_TicketValiIndi);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ValidityTimeUnit));
		len1 = sizeof(m_ValidityTimeUnit);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SpecialChkDays));
		len1 = sizeof(m_SpecialChkDays);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InitVal));
		len1 = sizeof(m_InitVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BuyVal));
		len1 = sizeof(m_BuyVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardInitVal));
		len1 = sizeof(m_CardInitVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardInitRewardVal));
		len1 = sizeof(m_CardInitRewardVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardRechargeChoise));
		len1 = sizeof(m_CardRechargeChoise);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardRechargeRewardChoise));
		len1 = sizeof(m_CardRechargeRewardChoise);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_MarginTimesec));
		len1 = sizeof(m_B0_MarginTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_UnRushhourIdx));
		len1 = sizeof(m_B0_UnRushhourIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_DiscountRateIdx));
		len1 = sizeof(m_B0_DiscountRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_FullFareRateIdx));
		len1 = sizeof(m_B0_FullFareRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_MarginTimesec));
		len1 = sizeof(m_B1_MarginTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_UnRushhourIdx));
		len1 = sizeof(m_B1_UnRushhourIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_DiscountRateIdx));
		len1 = sizeof(m_B1_DiscountRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_FullFareRateIdx));
		len1 = sizeof(m_B1_FullFareRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_MarginTimesec));
		len1 = sizeof(m_B2_MarginTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_UnRushhourIdx));
		len1 = sizeof(m_B2_UnRushhourIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_DiscountRateIdx));
		len1 = sizeof(m_B2_DiscountRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_FullFareRateIdx));
		len1 = sizeof(m_B2_FullFareRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_MarginTimesec));
		len1 = sizeof(m_B3_MarginTimesec);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_UnRushhourIdx));
		len1 = sizeof(m_B3_UnRushhourIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_DiscountRateIdx));
		len1 = sizeof(m_B3_DiscountRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_FullFareRateIdx));
		len1 = sizeof(m_B3_FullFareRateIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulateBeginPromotionTimes));
		len1 = sizeof(m_AccumulateBeginPromotionTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulateBeginPromotionVal));
		len1 = sizeof(m_AccumulateBeginPromotionVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulatePromotionPercent));
		len1 = sizeof(m_AccumulatePromotionPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionVal));
		len1 = sizeof(m_ConnectPromotionVal);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionPercent));
		len1 = sizeof(m_ConnectPromotionPercent);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PromotionPriorityLevelType));
		len1 = sizeof(m_PromotionPriorityLevelType);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionValidTimePeriod));
		len1 = sizeof(m_ConnectPromotionValidTimePeriod);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionTrade));
		len1 = sizeof(m_ConnectPromotionTrade);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SpecialCardMapTypeCode));
		len1 = sizeof(m_SpecialCardMapTypeCode);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTimesTicketTimeUnit));
		len1 = sizeof(m_TimeTimesTicketTimeUnit);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertimePenalty2));
		len1 = sizeof(m_OvertimePenalty2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ExcessPenalty2));
		len1 = sizeof(m_ExcessPenalty2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardSavingsLimit));
		len1 = sizeof(m_CardSavingsLimit);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimesTicketDefaultCarfare));
		len1 = sizeof(m_TimesTicketDefaultCarfare);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CrosssitePenalty));
		len1 = sizeof(m_CrosssitePenalty);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_04));
		len1 = sizeof(m_RES_04);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_05));
		len1 = sizeof(m_RES_05);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DayMaxTakeTimes));
		len1 = sizeof(m_DayMaxTakeTimes);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_06));
		len1 = sizeof(m_RES_06);
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

	a4002_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_PriorityJudgeType = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CPUCardParaFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_01 = *(u8arr_t<33>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ConnectGapTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LostTicketPenalty = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_OvertravelPenalty = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_OvertimePenalty = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ExcessPenalty = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SavingsCardInitVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_NextdayWorkTimehour = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_InStationMaxTime = *(u8arr_t<16>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketType = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_strTicketTypeDiscEn = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketTypeDiscCh = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketCtrlCode = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TicketValiIndi = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ValidityTimeUnit = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SpecialChkDays = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_InitVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_BuyVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CardInitVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CardInitRewardVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CardRechargeChoise = *(ui16arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CardRechargeRewardChoise = *(ui16arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B0_MarginTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B0_UnRushhourIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B0_DiscountRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B0_FullFareRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B1_MarginTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B1_UnRushhourIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B1_DiscountRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B1_FullFareRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B2_MarginTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B2_UnRushhourIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B2_DiscountRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B2_FullFareRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B3_MarginTimesec = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B3_UnRushhourIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B3_DiscountRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_B3_FullFareRateIdx = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_AccumulateBeginPromotionTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_AccumulateBeginPromotionVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_AccumulatePromotionPercent = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ConnectPromotionVal = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ConnectPromotionPercent = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_PromotionPriorityLevelType = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ConnectPromotionValidTimePeriod = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ConnectPromotionTrade = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_SpecialCardMapTypeCode = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimeTimesTicketTimeUnit = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_OvertimePenalty2 = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ExcessPenalty2 = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CardSavingsLimit = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_TimesTicketDefaultCarfare = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_CrosssitePenalty = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_02 = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_03 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_04 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_05 = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DayMaxTakeTimes = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_06 = *(wl::tuint8*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PriorityJudgeType));
		len1 = sizeof(m_PriorityJudgeType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CPUCardParaFlag));
		len1 = sizeof(m_CPUCardParaFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectGapTimesec));
		len1 = sizeof(m_ConnectGapTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LostTicketPenalty));
		len1 = sizeof(m_LostTicketPenalty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertravelPenalty));
		len1 = sizeof(m_OvertravelPenalty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertimePenalty));
		len1 = sizeof(m_OvertimePenalty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ExcessPenalty));
		len1 = sizeof(m_ExcessPenalty);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SavingsCardInitVal));
		len1 = sizeof(m_SavingsCardInitVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_NextdayWorkTimehour));
		len1 = sizeof(m_NextdayWorkTimehour);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InStationMaxTime));
		len1 = sizeof(m_InStationMaxTime);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketType));
		len1 = sizeof(m_TicketType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_strTicketTypeDiscEn.c_str();
		len1 = (long)(m_strTicketTypeDiscEn.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketTypeDiscCh));
		len1 = sizeof(m_TicketTypeDiscCh);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketCtrlCode));
		len1 = sizeof(m_TicketCtrlCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TicketValiIndi));
		len1 = sizeof(m_TicketValiIndi);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ValidityTimeUnit));
		len1 = sizeof(m_ValidityTimeUnit);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SpecialChkDays));
		len1 = sizeof(m_SpecialChkDays);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_InitVal));
		len1 = sizeof(m_InitVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_BuyVal));
		len1 = sizeof(m_BuyVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardInitVal));
		len1 = sizeof(m_CardInitVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardInitRewardVal));
		len1 = sizeof(m_CardInitRewardVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardRechargeChoise));
		len1 = sizeof(m_CardRechargeChoise);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardRechargeRewardChoise));
		len1 = sizeof(m_CardRechargeRewardChoise);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_MarginTimesec));
		len1 = sizeof(m_B0_MarginTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_UnRushhourIdx));
		len1 = sizeof(m_B0_UnRushhourIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_DiscountRateIdx));
		len1 = sizeof(m_B0_DiscountRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B0_FullFareRateIdx));
		len1 = sizeof(m_B0_FullFareRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_MarginTimesec));
		len1 = sizeof(m_B1_MarginTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_UnRushhourIdx));
		len1 = sizeof(m_B1_UnRushhourIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_DiscountRateIdx));
		len1 = sizeof(m_B1_DiscountRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B1_FullFareRateIdx));
		len1 = sizeof(m_B1_FullFareRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_MarginTimesec));
		len1 = sizeof(m_B2_MarginTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_UnRushhourIdx));
		len1 = sizeof(m_B2_UnRushhourIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_DiscountRateIdx));
		len1 = sizeof(m_B2_DiscountRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B2_FullFareRateIdx));
		len1 = sizeof(m_B2_FullFareRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_MarginTimesec));
		len1 = sizeof(m_B3_MarginTimesec);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_UnRushhourIdx));
		len1 = sizeof(m_B3_UnRushhourIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_DiscountRateIdx));
		len1 = sizeof(m_B3_DiscountRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_B3_FullFareRateIdx));
		len1 = sizeof(m_B3_FullFareRateIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulateBeginPromotionTimes));
		len1 = sizeof(m_AccumulateBeginPromotionTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulateBeginPromotionVal));
		len1 = sizeof(m_AccumulateBeginPromotionVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_AccumulatePromotionPercent));
		len1 = sizeof(m_AccumulatePromotionPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionVal));
		len1 = sizeof(m_ConnectPromotionVal);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionPercent));
		len1 = sizeof(m_ConnectPromotionPercent);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_PromotionPriorityLevelType));
		len1 = sizeof(m_PromotionPriorityLevelType);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionValidTimePeriod));
		len1 = sizeof(m_ConnectPromotionValidTimePeriod);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ConnectPromotionTrade));
		len1 = sizeof(m_ConnectPromotionTrade);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_SpecialCardMapTypeCode));
		len1 = sizeof(m_SpecialCardMapTypeCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimeTimesTicketTimeUnit));
		len1 = sizeof(m_TimeTimesTicketTimeUnit);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_OvertimePenalty2));
		len1 = sizeof(m_OvertimePenalty2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_ExcessPenalty2));
		len1 = sizeof(m_ExcessPenalty2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CardSavingsLimit));
		len1 = sizeof(m_CardSavingsLimit);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_TimesTicketDefaultCarfare));
		len1 = sizeof(m_TimesTicketDefaultCarfare);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_CrosssitePenalty));
		len1 = sizeof(m_CrosssitePenalty);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_04));
		len1 = sizeof(m_RES_04);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_05));
		len1 = sizeof(m_RES_05);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DayMaxTakeTimes));
		len1 = sizeof(m_DayMaxTakeTimes);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_06));
		len1 = sizeof(m_RES_06);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a4002_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_PriorityJudgeType = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CPUCardParaFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_01 = *(u8arr_t<33>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ConnectGapTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LostTicketPenalty = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_OvertravelPenalty = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_OvertimePenalty = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ExcessPenalty = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SavingsCardInitVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_NextdayWorkTimehour = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_InStationMaxTime = *(u8arr_t<16>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketType = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_strTicketTypeDiscEn = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketTypeDiscCh = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketCtrlCode = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TicketValiIndi = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ValidityTimeUnit = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SpecialChkDays = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_InitVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_BuyVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CardInitVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CardInitRewardVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CardRechargeChoise = *(ui16arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CardRechargeRewardChoise = *(ui16arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B0_MarginTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B0_UnRushhourIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B0_DiscountRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B0_FullFareRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B1_MarginTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B1_UnRushhourIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B1_DiscountRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B1_FullFareRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B2_MarginTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B2_UnRushhourIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B2_DiscountRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B2_FullFareRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B3_MarginTimesec = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B3_UnRushhourIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B3_DiscountRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_B3_FullFareRateIdx = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_AccumulateBeginPromotionTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_AccumulateBeginPromotionVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_AccumulatePromotionPercent = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ConnectPromotionVal = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ConnectPromotionPercent = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_PromotionPriorityLevelType = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ConnectPromotionValidTimePeriod = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ConnectPromotionTrade = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_SpecialCardMapTypeCode = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimeTimesTicketTimeUnit = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_OvertimePenalty2 = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ExcessPenalty2 = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CardSavingsLimit = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_TimesTicketDefaultCarfare = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_CrosssitePenalty = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_02 = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_03 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_04 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_05 = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DayMaxTakeTimes = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_06 = *(wl::tuint8*)buf2;
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
//Function:	GetCol_PriorityJudgeType
//Effect:	get ref of col. col is PriorityJudgeType
//Return:	int & 
	int & GetCol_PriorityJudgeType(void)
	{
		return m_PriorityJudgeType;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_CPUCardParaFlag
//Effect:	get ref of col. col is CPUCardParaFlag
//Return:	int & 
	int & GetCol_CPUCardParaFlag(void)
	{
		return m_CPUCardParaFlag;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	u8arr_t<33> & 
	u8arr_t<33> & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_ConnectGapTimesec
//Effect:	get ref of col. col is ConnectGapTimesec
//Return:	long & 
	long & GetCol_ConnectGapTimesec(void)
	{
		return m_ConnectGapTimesec;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_LostTicketPenalty
//Effect:	get ref of col. col is LostTicketPenalty
//Return:	long & 
	long & GetCol_LostTicketPenalty(void)
	{
		return m_LostTicketPenalty;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_OvertravelPenalty
//Effect:	get ref of col. col is OvertravelPenalty
//Return:	long & 
	long & GetCol_OvertravelPenalty(void)
	{
		return m_OvertravelPenalty;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_OvertimePenalty
//Effect:	get ref of col. col is OvertimePenalty
//Return:	long & 
	long & GetCol_OvertimePenalty(void)
	{
		return m_OvertimePenalty;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_ExcessPenalty
//Effect:	get ref of col. col is ExcessPenalty
//Return:	long & 
	long & GetCol_ExcessPenalty(void)
	{
		return m_ExcessPenalty;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_SavingsCardInitVal
//Effect:	get ref of col. col is SavingsCardInitVal
//Return:	long & 
	long & GetCol_SavingsCardInitVal(void)
	{
		return m_SavingsCardInitVal;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_NextdayWorkTimehour
//Effect:	get ref of col. col is NextdayWorkTimehour
//Return:	long & 
	long & GetCol_NextdayWorkTimehour(void)
	{
		return m_NextdayWorkTimehour;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_InStationMaxTime
//Effect:	get ref of col. col is InStationMaxTime
//Return:	u8arr_t<16> & 
	u8arr_t<16> & GetCol_InStationMaxTime(void)
	{
		return m_InStationMaxTime;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TicketType
//Effect:	get ref of col. col is TicketType
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_TicketType(void)
	{
		return m_TicketType;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_strTicketTypeDiscEn
//Effect:	get ref of col. col is strTicketTypeDiscEn
//Return:	std::string & 
	std::string & GetCol_strTicketTypeDiscEn(void)
	{
		return m_strTicketTypeDiscEn;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_TicketTypeDiscCh
//Effect:	get ref of col. col is TicketTypeDiscCh
//Return:	long & 
	long & GetCol_TicketTypeDiscCh(void)
	{
		return m_TicketTypeDiscCh;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TicketCtrlCode
//Effect:	get ref of col. col is TicketCtrlCode
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_TicketCtrlCode(void)
	{
		return m_TicketCtrlCode;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_TicketValiIndi
//Effect:	get ref of col. col is TicketValiIndi
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_TicketValiIndi(void)
	{
		return m_TicketValiIndi;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_ValidityTimeUnit
//Effect:	get ref of col. col is ValidityTimeUnit
//Return:	long & 
	long & GetCol_ValidityTimeUnit(void)
	{
		return m_ValidityTimeUnit;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_SpecialChkDays
//Effect:	get ref of col. col is SpecialChkDays
//Return:	long & 
	long & GetCol_SpecialChkDays(void)
	{
		return m_SpecialChkDays;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_InitVal
//Effect:	get ref of col. col is InitVal
//Return:	long & 
	long & GetCol_InitVal(void)
	{
		return m_InitVal;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_BuyVal
//Effect:	get ref of col. col is BuyVal
//Return:	long & 
	long & GetCol_BuyVal(void)
	{
		return m_BuyVal;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CardInitVal
//Effect:	get ref of col. col is CardInitVal
//Return:	long & 
	long & GetCol_CardInitVal(void)
	{
		return m_CardInitVal;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_CardInitRewardVal
//Effect:	get ref of col. col is CardInitRewardVal
//Return:	long & 
	long & GetCol_CardInitRewardVal(void)
	{
		return m_CardInitRewardVal;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_CardRechargeChoise
//Effect:	get ref of col. col is CardRechargeChoise
//Return:	ui16arr_t<4> & 
	ui16arr_t<4> & GetCol_CardRechargeChoise(void)
	{
		return m_CardRechargeChoise;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_CardRechargeRewardChoise
//Effect:	get ref of col. col is CardRechargeRewardChoise
//Return:	ui16arr_t<4> & 
	ui16arr_t<4> & GetCol_CardRechargeRewardChoise(void)
	{
		return m_CardRechargeRewardChoise;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_B0_MarginTimesec
//Effect:	get ref of col. col is B0_MarginTimesec
//Return:	long & 
	long & GetCol_B0_MarginTimesec(void)
	{
		return m_B0_MarginTimesec;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_B0_UnRushhourIdx
//Effect:	get ref of col. col is B0_UnRushhourIdx
//Return:	long & 
	long & GetCol_B0_UnRushhourIdx(void)
	{
		return m_B0_UnRushhourIdx;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_B0_DiscountRateIdx
//Effect:	get ref of col. col is B0_DiscountRateIdx
//Return:	long & 
	long & GetCol_B0_DiscountRateIdx(void)
	{
		return m_B0_DiscountRateIdx;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_B0_FullFareRateIdx
//Effect:	get ref of col. col is B0_FullFareRateIdx
//Return:	long & 
	long & GetCol_B0_FullFareRateIdx(void)
	{
		return m_B0_FullFareRateIdx;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_B1_MarginTimesec
//Effect:	get ref of col. col is B1_MarginTimesec
//Return:	long & 
	long & GetCol_B1_MarginTimesec(void)
	{
		return m_B1_MarginTimesec;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_B1_UnRushhourIdx
//Effect:	get ref of col. col is B1_UnRushhourIdx
//Return:	long & 
	long & GetCol_B1_UnRushhourIdx(void)
	{
		return m_B1_UnRushhourIdx;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_B1_DiscountRateIdx
//Effect:	get ref of col. col is B1_DiscountRateIdx
//Return:	long & 
	long & GetCol_B1_DiscountRateIdx(void)
	{
		return m_B1_DiscountRateIdx;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_B1_FullFareRateIdx
//Effect:	get ref of col. col is B1_FullFareRateIdx
//Return:	long & 
	long & GetCol_B1_FullFareRateIdx(void)
	{
		return m_B1_FullFareRateIdx;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_B2_MarginTimesec
//Effect:	get ref of col. col is B2_MarginTimesec
//Return:	long & 
	long & GetCol_B2_MarginTimesec(void)
	{
		return m_B2_MarginTimesec;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_B2_UnRushhourIdx
//Effect:	get ref of col. col is B2_UnRushhourIdx
//Return:	long & 
	long & GetCol_B2_UnRushhourIdx(void)
	{
		return m_B2_UnRushhourIdx;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_B2_DiscountRateIdx
//Effect:	get ref of col. col is B2_DiscountRateIdx
//Return:	long & 
	long & GetCol_B2_DiscountRateIdx(void)
	{
		return m_B2_DiscountRateIdx;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_B2_FullFareRateIdx
//Effect:	get ref of col. col is B2_FullFareRateIdx
//Return:	long & 
	long & GetCol_B2_FullFareRateIdx(void)
	{
		return m_B2_FullFareRateIdx;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_B3_MarginTimesec
//Effect:	get ref of col. col is B3_MarginTimesec
//Return:	long & 
	long & GetCol_B3_MarginTimesec(void)
	{
		return m_B3_MarginTimesec;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_B3_UnRushhourIdx
//Effect:	get ref of col. col is B3_UnRushhourIdx
//Return:	long & 
	long & GetCol_B3_UnRushhourIdx(void)
	{
		return m_B3_UnRushhourIdx;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_B3_DiscountRateIdx
//Effect:	get ref of col. col is B3_DiscountRateIdx
//Return:	long & 
	long & GetCol_B3_DiscountRateIdx(void)
	{
		return m_B3_DiscountRateIdx;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_B3_FullFareRateIdx
//Effect:	get ref of col. col is B3_FullFareRateIdx
//Return:	long & 
	long & GetCol_B3_FullFareRateIdx(void)
	{
		return m_B3_FullFareRateIdx;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_AccumulateBeginPromotionTimes
//Effect:	get ref of col. col is AccumulateBeginPromotionTimes
//Return:	long & 
	long & GetCol_AccumulateBeginPromotionTimes(void)
	{
		return m_AccumulateBeginPromotionTimes;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_AccumulateBeginPromotionVal
//Effect:	get ref of col. col is AccumulateBeginPromotionVal
//Return:	long & 
	long & GetCol_AccumulateBeginPromotionVal(void)
	{
		return m_AccumulateBeginPromotionVal;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_AccumulatePromotionPercent
//Effect:	get ref of col. col is AccumulatePromotionPercent
//Return:	long & 
	long & GetCol_AccumulatePromotionPercent(void)
	{
		return m_AccumulatePromotionPercent;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_ConnectPromotionVal
//Effect:	get ref of col. col is ConnectPromotionVal
//Return:	long & 
	long & GetCol_ConnectPromotionVal(void)
	{
		return m_ConnectPromotionVal;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_ConnectPromotionPercent
//Effect:	get ref of col. col is ConnectPromotionPercent
//Return:	long & 
	long & GetCol_ConnectPromotionPercent(void)
	{
		return m_ConnectPromotionPercent;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_PromotionPriorityLevelType
//Effect:	get ref of col. col is PromotionPriorityLevelType
//Return:	long & 
	long & GetCol_PromotionPriorityLevelType(void)
	{
		return m_PromotionPriorityLevelType;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_ConnectPromotionValidTimePeriod
//Effect:	get ref of col. col is ConnectPromotionValidTimePeriod
//Return:	long & 
	long & GetCol_ConnectPromotionValidTimePeriod(void)
	{
		return m_ConnectPromotionValidTimePeriod;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_ConnectPromotionTrade
//Effect:	get ref of col. col is ConnectPromotionTrade
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_ConnectPromotionTrade(void)
	{
		return m_ConnectPromotionTrade;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_SpecialCardMapTypeCode
//Effect:	get ref of col. col is SpecialCardMapTypeCode
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_SpecialCardMapTypeCode(void)
	{
		return m_SpecialCardMapTypeCode;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_TimeTimesTicketTimeUnit
//Effect:	get ref of col. col is TimeTimesTicketTimeUnit
//Return:	long & 
	long & GetCol_TimeTimesTicketTimeUnit(void)
	{
		return m_TimeTimesTicketTimeUnit;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_OvertimePenalty2
//Effect:	get ref of col. col is OvertimePenalty2
//Return:	long & 
	long & GetCol_OvertimePenalty2(void)
	{
		return m_OvertimePenalty2;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_ExcessPenalty2
//Effect:	get ref of col. col is ExcessPenalty2
//Return:	long & 
	long & GetCol_ExcessPenalty2(void)
	{
		return m_ExcessPenalty2;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_CardSavingsLimit
//Effect:	get ref of col. col is CardSavingsLimit
//Return:	long & 
	long & GetCol_CardSavingsLimit(void)
	{
		return m_CardSavingsLimit;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_TimesTicketDefaultCarfare
//Effect:	get ref of col. col is TimesTicketDefaultCarfare
//Return:	long & 
	long & GetCol_TimesTicketDefaultCarfare(void)
	{
		return m_TimesTicketDefaultCarfare;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_CrosssitePenalty
//Effect:	get ref of col. col is CrosssitePenalty
//Return:	long & 
	long & GetCol_CrosssitePenalty(void)
	{
		return m_CrosssitePenalty;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_RES_02(void)
	{
		return m_RES_02;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_RES_03
//Effect:	get ref of col. col is RES_03
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES_03(void)
	{
		return m_RES_03;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES_04
//Effect:	get ref of col. col is RES_04
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES_04(void)
	{
		return m_RES_04;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_RES_05
//Effect:	get ref of col. col is RES_05
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES_05(void)
	{
		return m_RES_05;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_DayMaxTakeTimes
//Effect:	get ref of col. col is DayMaxTakeTimes
//Return:	long & 
	long & GetCol_DayMaxTakeTimes(void)
	{
		return m_DayMaxTakeTimes;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES_06
//Effect:	get ref of col. col is RES_06
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES_06(void)
	{
		return m_RES_06;
	}

 
public:

//////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 68;
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
			return "PriorityJudgeType";
		}
		if( iColNum == 8 )
		{
			return "CPUCardParaFlag";
		}
		if( iColNum == 9 )
		{
			return "RES_01";
		}
		if( iColNum == 10 )
		{
			return "ConnectGapTimesec";
		}
		if( iColNum == 11 )
		{
			return "LostTicketPenalty";
		}
		if( iColNum == 12 )
		{
			return "OvertravelPenalty";
		}
		if( iColNum == 13 )
		{
			return "OvertimePenalty";
		}
		if( iColNum == 14 )
		{
			return "ExcessPenalty";
		}
		if( iColNum == 15 )
		{
			return "SavingsCardInitVal";
		}
		if( iColNum == 16 )
		{
			return "NextdayWorkTimehour";
		}
		if( iColNum == 17 )
		{
			return "InStationMaxTime";
		}
		if( iColNum == 18 )
		{
			return "TicketType";
		}
		if( iColNum == 19 )
		{
			return "strTicketTypeDiscEn";
		}
		if( iColNum == 20 )
		{
			return "TicketTypeDiscCh";
		}
		if( iColNum == 21 )
		{
			return "TicketCtrlCode";
		}
		if( iColNum == 22 )
		{
			return "TicketValiIndi";
		}
		if( iColNum == 23 )
		{
			return "ValidityTimeUnit";
		}
		if( iColNum == 24 )
		{
			return "SpecialChkDays";
		}
		if( iColNum == 25 )
		{
			return "InitVal";
		}
		if( iColNum == 26 )
		{
			return "BuyVal";
		}
		if( iColNum == 27 )
		{
			return "CardInitVal";
		}
		if( iColNum == 28 )
		{
			return "CardInitRewardVal";
		}
		if( iColNum == 29 )
		{
			return "CardRechargeChoise";
		}
		if( iColNum == 30 )
		{
			return "CardRechargeRewardChoise";
		}
		if( iColNum == 31 )
		{
			return "B0_MarginTimesec";
		}
		if( iColNum == 32 )
		{
			return "B0_UnRushhourIdx";
		}
		if( iColNum == 33 )
		{
			return "B0_DiscountRateIdx";
		}
		if( iColNum == 34 )
		{
			return "B0_FullFareRateIdx";
		}
		if( iColNum == 35 )
		{
			return "B1_MarginTimesec";
		}
		if( iColNum == 36 )
		{
			return "B1_UnRushhourIdx";
		}
		if( iColNum == 37 )
		{
			return "B1_DiscountRateIdx";
		}
		if( iColNum == 38 )
		{
			return "B1_FullFareRateIdx";
		}
		if( iColNum == 39 )
		{
			return "B2_MarginTimesec";
		}
		if( iColNum == 40 )
		{
			return "B2_UnRushhourIdx";
		}
		if( iColNum == 41 )
		{
			return "B2_DiscountRateIdx";
		}
		if( iColNum == 42 )
		{
			return "B2_FullFareRateIdx";
		}
		if( iColNum == 43 )
		{
			return "B3_MarginTimesec";
		}
		if( iColNum == 44 )
		{
			return "B3_UnRushhourIdx";
		}
		if( iColNum == 45 )
		{
			return "B3_DiscountRateIdx";
		}
		if( iColNum == 46 )
		{
			return "B3_FullFareRateIdx";
		}
		if( iColNum == 47 )
		{
			return "AccumulateBeginPromotionTimes";
		}
		if( iColNum == 48 )
		{
			return "AccumulateBeginPromotionVal";
		}
		if( iColNum == 49 )
		{
			return "AccumulatePromotionPercent";
		}
		if( iColNum == 50 )
		{
			return "ConnectPromotionVal";
		}
		if( iColNum == 51 )
		{
			return "ConnectPromotionPercent";
		}
		if( iColNum == 52 )
		{
			return "PromotionPriorityLevelType";
		}
		if( iColNum == 53 )
		{
			return "ConnectPromotionValidTimePeriod";
		}
		if( iColNum == 54 )
		{
			return "ConnectPromotionTrade";
		}
		if( iColNum == 55 )
		{
			return "SpecialCardMapTypeCode";
		}
		if( iColNum == 56 )
		{
			return "TimeTimesTicketTimeUnit";
		}
		if( iColNum == 57 )
		{
			return "OvertimePenalty2";
		}
		if( iColNum == 58 )
		{
			return "ExcessPenalty2";
		}
		if( iColNum == 59 )
		{
			return "CardSavingsLimit";
		}
		if( iColNum == 60 )
		{
			return "TimesTicketDefaultCarfare";
		}
		if( iColNum == 61 )
		{
			return "CrosssitePenalty";
		}
		if( iColNum == 62 )
		{
			return "RES_02";
		}
		if( iColNum == 63 )
		{
			return "RES_03";
		}
		if( iColNum == 64 )
		{
			return "RES_04";
		}
		if( iColNum == 65 )
		{
			return "RES_05";
		}
		if( iColNum == 66 )
		{
			return "DayMaxTakeTimes";
		}
		if( iColNum == 67 )
		{
			return "RES_06";
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
		if( strColName == "PriorityJudgeType" )
		{
			return 7;
		}
		if( strColName == "CPUCardParaFlag" )
		{
			return 8;
		}
		if( strColName == "RES_01" )
		{
			return 9;
		}
		if( strColName == "ConnectGapTimesec" )
		{
			return 10;
		}
		if( strColName == "LostTicketPenalty" )
		{
			return 11;
		}
		if( strColName == "OvertravelPenalty" )
		{
			return 12;
		}
		if( strColName == "OvertimePenalty" )
		{
			return 13;
		}
		if( strColName == "ExcessPenalty" )
		{
			return 14;
		}
		if( strColName == "SavingsCardInitVal" )
		{
			return 15;
		}
		if( strColName == "NextdayWorkTimehour" )
		{
			return 16;
		}
		if( strColName == "InStationMaxTime" )
		{
			return 17;
		}
		if( strColName == "TicketType" )
		{
			return 18;
		}
		if( strColName == "strTicketTypeDiscEn" )
		{
			return 19;
		}
		if( strColName == "TicketTypeDiscCh" )
		{
			return 20;
		}
		if( strColName == "TicketCtrlCode" )
		{
			return 21;
		}
		if( strColName == "TicketValiIndi" )
		{
			return 22;
		}
		if( strColName == "ValidityTimeUnit" )
		{
			return 23;
		}
		if( strColName == "SpecialChkDays" )
		{
			return 24;
		}
		if( strColName == "InitVal" )
		{
			return 25;
		}
		if( strColName == "BuyVal" )
		{
			return 26;
		}
		if( strColName == "CardInitVal" )
		{
			return 27;
		}
		if( strColName == "CardInitRewardVal" )
		{
			return 28;
		}
		if( strColName == "CardRechargeChoise" )
		{
			return 29;
		}
		if( strColName == "CardRechargeRewardChoise" )
		{
			return 30;
		}
		if( strColName == "B0_MarginTimesec" )
		{
			return 31;
		}
		if( strColName == "B0_UnRushhourIdx" )
		{
			return 32;
		}
		if( strColName == "B0_DiscountRateIdx" )
		{
			return 33;
		}
		if( strColName == "B0_FullFareRateIdx" )
		{
			return 34;
		}
		if( strColName == "B1_MarginTimesec" )
		{
			return 35;
		}
		if( strColName == "B1_UnRushhourIdx" )
		{
			return 36;
		}
		if( strColName == "B1_DiscountRateIdx" )
		{
			return 37;
		}
		if( strColName == "B1_FullFareRateIdx" )
		{
			return 38;
		}
		if( strColName == "B2_MarginTimesec" )
		{
			return 39;
		}
		if( strColName == "B2_UnRushhourIdx" )
		{
			return 40;
		}
		if( strColName == "B2_DiscountRateIdx" )
		{
			return 41;
		}
		if( strColName == "B2_FullFareRateIdx" )
		{
			return 42;
		}
		if( strColName == "B3_MarginTimesec" )
		{
			return 43;
		}
		if( strColName == "B3_UnRushhourIdx" )
		{
			return 44;
		}
		if( strColName == "B3_DiscountRateIdx" )
		{
			return 45;
		}
		if( strColName == "B3_FullFareRateIdx" )
		{
			return 46;
		}
		if( strColName == "AccumulateBeginPromotionTimes" )
		{
			return 47;
		}
		if( strColName == "AccumulateBeginPromotionVal" )
		{
			return 48;
		}
		if( strColName == "AccumulatePromotionPercent" )
		{
			return 49;
		}
		if( strColName == "ConnectPromotionVal" )
		{
			return 50;
		}
		if( strColName == "ConnectPromotionPercent" )
		{
			return 51;
		}
		if( strColName == "PromotionPriorityLevelType" )
		{
			return 52;
		}
		if( strColName == "ConnectPromotionValidTimePeriod" )
		{
			return 53;
		}
		if( strColName == "ConnectPromotionTrade" )
		{
			return 54;
		}
		if( strColName == "SpecialCardMapTypeCode" )
		{
			return 55;
		}
		if( strColName == "TimeTimesTicketTimeUnit" )
		{
			return 56;
		}
		if( strColName == "OvertimePenalty2" )
		{
			return 57;
		}
		if( strColName == "ExcessPenalty2" )
		{
			return 58;
		}
		if( strColName == "CardSavingsLimit" )
		{
			return 59;
		}
		if( strColName == "TimesTicketDefaultCarfare" )
		{
			return 60;
		}
		if( strColName == "CrosssitePenalty" )
		{
			return 61;
		}
		if( strColName == "RES_02" )
		{
			return 62;
		}
		if( strColName == "RES_03" )
		{
			return 63;
		}
		if( strColName == "RES_04" )
		{
			return 64;
		}
		if( strColName == "RES_05" )
		{
			return 65;
		}
		if( strColName == "DayMaxTakeTimes" )
		{
			return 66;
		}
		if( strColName == "RES_06" )
		{
			return 67;
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
			return wl::SStrf::sltoa(m_PriorityJudgeType);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sltoa(m_CPUCardParaFlag);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::b2s(m_RES_01);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_ConnectGapTimesec);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_LostTicketPenalty);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_OvertravelPenalty);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_OvertimePenalty);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_ExcessPenalty);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_SavingsCardInitVal);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_NextdayWorkTimehour);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::b2s(m_InStationMaxTime);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_TicketType);
		}
		if( iColNum == 19 )
		{
			return m_strTicketTypeDiscEn;
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_TicketTypeDiscCh);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::b2s(m_TicketCtrlCode);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::b2s(m_TicketValiIndi);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_ValidityTimeUnit);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_SpecialChkDays);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_InitVal);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_BuyVal);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_CardInitVal);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::sltoa(m_CardInitRewardVal);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::b2s(m_CardRechargeChoise);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::b2s(m_CardRechargeRewardChoise);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_B0_MarginTimesec);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_B0_UnRushhourIdx);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_B0_DiscountRateIdx);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_B0_FullFareRateIdx);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_B1_MarginTimesec);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_B1_UnRushhourIdx);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_B1_DiscountRateIdx);
		}
		if( iColNum == 38 )
		{
			return wl::SStrf::sltoa(m_B1_FullFareRateIdx);
		}
		if( iColNum == 39 )
		{
			return wl::SStrf::sltoa(m_B2_MarginTimesec);
		}
		if( iColNum == 40 )
		{
			return wl::SStrf::sltoa(m_B2_UnRushhourIdx);
		}
		if( iColNum == 41 )
		{
			return wl::SStrf::sltoa(m_B2_DiscountRateIdx);
		}
		if( iColNum == 42 )
		{
			return wl::SStrf::sltoa(m_B2_FullFareRateIdx);
		}
		if( iColNum == 43 )
		{
			return wl::SStrf::sltoa(m_B3_MarginTimesec);
		}
		if( iColNum == 44 )
		{
			return wl::SStrf::sltoa(m_B3_UnRushhourIdx);
		}
		if( iColNum == 45 )
		{
			return wl::SStrf::sltoa(m_B3_DiscountRateIdx);
		}
		if( iColNum == 46 )
		{
			return wl::SStrf::sltoa(m_B3_FullFareRateIdx);
		}
		if( iColNum == 47 )
		{
			return wl::SStrf::sltoa(m_AccumulateBeginPromotionTimes);
		}
		if( iColNum == 48 )
		{
			return wl::SStrf::sltoa(m_AccumulateBeginPromotionVal);
		}
		if( iColNum == 49 )
		{
			return wl::SStrf::sltoa(m_AccumulatePromotionPercent);
		}
		if( iColNum == 50 )
		{
			return wl::SStrf::sltoa(m_ConnectPromotionVal);
		}
		if( iColNum == 51 )
		{
			return wl::SStrf::sltoa(m_ConnectPromotionPercent);
		}
		if( iColNum == 52 )
		{
			return wl::SStrf::sltoa(m_PromotionPriorityLevelType);
		}
		if( iColNum == 53 )
		{
			return wl::SStrf::sltoa(m_ConnectPromotionValidTimePeriod);
		}
		if( iColNum == 54 )
		{
			return wl::SStrf::sltoa(m_ConnectPromotionTrade);
		}
		if( iColNum == 55 )
		{
			return wl::SStrf::sltoa(m_SpecialCardMapTypeCode);
		}
		if( iColNum == 56 )
		{
			return wl::SStrf::sltoa(m_TimeTimesTicketTimeUnit);
		}
		if( iColNum == 57 )
		{
			return wl::SStrf::sltoa(m_OvertimePenalty2);
		}
		if( iColNum == 58 )
		{
			return wl::SStrf::sltoa(m_ExcessPenalty2);
		}
		if( iColNum == 59 )
		{
			return wl::SStrf::sltoa(m_CardSavingsLimit);
		}
		if( iColNum == 60 )
		{
			return wl::SStrf::sltoa(m_TimesTicketDefaultCarfare);
		}
		if( iColNum == 61 )
		{
			return wl::SStrf::sltoa(m_CrosssitePenalty);
		}
		if( iColNum == 62 )
		{
			return wl::SStrf::b2s(m_RES_02);
		}
		if( iColNum == 63 )
		{
			return wl::SStrf::sltoa(m_RES_03);
		}
		if( iColNum == 64 )
		{
			return wl::SStrf::sltoa(m_RES_04);
		}
		if( iColNum == 65 )
		{
			return wl::SStrf::sltoa(m_RES_05);
		}
		if( iColNum == 66 )
		{
			return wl::SStrf::sltoa(m_DayMaxTakeTimes);
		}
		if( iColNum == 67 )
		{
			return wl::SStrf::sltoa(m_RES_06);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT & GetColStr( int iColNum , STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(iColNum); }

/////////////////////////////////////////////////////////
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
		if( strColName == "PriorityJudgeType" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "CPUCardParaFlag" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "ConnectGapTimesec" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "LostTicketPenalty" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "OvertravelPenalty" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "OvertimePenalty" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "ExcessPenalty" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "SavingsCardInitVal" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "NextdayWorkTimehour" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "InStationMaxTime" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "TicketType" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "strTicketTypeDiscEn" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "TicketTypeDiscCh" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "TicketCtrlCode" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "TicketValiIndi" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "ValidityTimeUnit" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "SpecialChkDays" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "InitVal" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "BuyVal" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "CardInitVal" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "CardInitRewardVal" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "CardRechargeChoise" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "CardRechargeRewardChoise" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "B0_MarginTimesec" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "B0_UnRushhourIdx" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "B0_DiscountRateIdx" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "B0_FullFareRateIdx" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "B1_MarginTimesec" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "B1_UnRushhourIdx" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "B1_DiscountRateIdx" )
		{
			return GetColStr<STRINGT>(37);
		}
		if( strColName == "B1_FullFareRateIdx" )
		{
			return GetColStr<STRINGT>(38);
		}
		if( strColName == "B2_MarginTimesec" )
		{
			return GetColStr<STRINGT>(39);
		}
		if( strColName == "B2_UnRushhourIdx" )
		{
			return GetColStr<STRINGT>(40);
		}
		if( strColName == "B2_DiscountRateIdx" )
		{
			return GetColStr<STRINGT>(41);
		}
		if( strColName == "B2_FullFareRateIdx" )
		{
			return GetColStr<STRINGT>(42);
		}
		if( strColName == "B3_MarginTimesec" )
		{
			return GetColStr<STRINGT>(43);
		}
		if( strColName == "B3_UnRushhourIdx" )
		{
			return GetColStr<STRINGT>(44);
		}
		if( strColName == "B3_DiscountRateIdx" )
		{
			return GetColStr<STRINGT>(45);
		}
		if( strColName == "B3_FullFareRateIdx" )
		{
			return GetColStr<STRINGT>(46);
		}
		if( strColName == "AccumulateBeginPromotionTimes" )
		{
			return GetColStr<STRINGT>(47);
		}
		if( strColName == "AccumulateBeginPromotionVal" )
		{
			return GetColStr<STRINGT>(48);
		}
		if( strColName == "AccumulatePromotionPercent" )
		{
			return GetColStr<STRINGT>(49);
		}
		if( strColName == "ConnectPromotionVal" )
		{
			return GetColStr<STRINGT>(50);
		}
		if( strColName == "ConnectPromotionPercent" )
		{
			return GetColStr<STRINGT>(51);
		}
		if( strColName == "PromotionPriorityLevelType" )
		{
			return GetColStr<STRINGT>(52);
		}
		if( strColName == "ConnectPromotionValidTimePeriod" )
		{
			return GetColStr<STRINGT>(53);
		}
		if( strColName == "ConnectPromotionTrade" )
		{
			return GetColStr<STRINGT>(54);
		}
		if( strColName == "SpecialCardMapTypeCode" )
		{
			return GetColStr<STRINGT>(55);
		}
		if( strColName == "TimeTimesTicketTimeUnit" )
		{
			return GetColStr<STRINGT>(56);
		}
		if( strColName == "OvertimePenalty2" )
		{
			return GetColStr<STRINGT>(57);
		}
		if( strColName == "ExcessPenalty2" )
		{
			return GetColStr<STRINGT>(58);
		}
		if( strColName == "CardSavingsLimit" )
		{
			return GetColStr<STRINGT>(59);
		}
		if( strColName == "TimesTicketDefaultCarfare" )
		{
			return GetColStr<STRINGT>(60);
		}
		if( strColName == "CrosssitePenalty" )
		{
			return GetColStr<STRINGT>(61);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(62);
		}
		if( strColName == "RES_03" )
		{
			return GetColStr<STRINGT>(63);
		}
		if( strColName == "RES_04" )
		{
			return GetColStr<STRINGT>(64);
		}
		if( strColName == "RES_05" )
		{
			return GetColStr<STRINGT>(65);
		}
		if( strColName == "DayMaxTakeTimes" )
		{
			return GetColStr<STRINGT>(66);
		}
		if( strColName == "RES_06" )
		{
			return GetColStr<STRINGT>(67);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

///////////////////////////////////////////////////////////////
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
			m_PriorityJudgeType=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_CPUCardParaFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 9 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_01);
		}
		if( iColNum == 10 )
		{
			m_ConnectGapTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_LostTicketPenalty=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_OvertravelPenalty=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_OvertimePenalty=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_ExcessPenalty=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_SavingsCardInitVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_NextdayWorkTimehour=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			wl::SStrf::s2b(strValPARA,m_InStationMaxTime);
		}
		if( iColNum == 18 )
		{
			m_TicketType=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_strTicketTypeDiscEn=strValPARA;
		}
		if( iColNum == 20 )
		{
			m_TicketTypeDiscCh=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			wl::SStrf::s2b(strValPARA,m_TicketCtrlCode);
		}
		if( iColNum == 22 )
		{
			wl::SStrf::s2b(strValPARA,m_TicketValiIndi);
		}
		if( iColNum == 23 )
		{
			m_ValidityTimeUnit=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_SpecialChkDays=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_InitVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_BuyVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 27 )
		{
			m_CardInitVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			m_CardInitRewardVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 29 )
		{
			wl::SStrf::s2b(strValPARA,m_CardRechargeChoise);
		}
		if( iColNum == 30 )
		{
			wl::SStrf::s2b(strValPARA,m_CardRechargeRewardChoise);
		}
		if( iColNum == 31 )
		{
			m_B0_MarginTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			m_B0_UnRushhourIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
		{
			m_B0_DiscountRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_B0_FullFareRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_B1_MarginTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_B1_UnRushhourIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_B1_DiscountRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 38 )
		{
			m_B1_FullFareRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 39 )
		{
			m_B2_MarginTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 40 )
		{
			m_B2_UnRushhourIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 41 )
		{
			m_B2_DiscountRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 42 )
		{
			m_B2_FullFareRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 43 )
		{
			m_B3_MarginTimesec=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 44 )
		{
			m_B3_UnRushhourIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 45 )
		{
			m_B3_DiscountRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 46 )
		{
			m_B3_FullFareRateIdx=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 47 )
		{
			m_AccumulateBeginPromotionTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 48 )
		{
			m_AccumulateBeginPromotionVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 49 )
		{
			m_AccumulatePromotionPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 50 )
		{
			m_ConnectPromotionVal=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 51 )
		{
			m_ConnectPromotionPercent=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 52 )
		{
			m_PromotionPriorityLevelType=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 53 )
		{
			m_ConnectPromotionValidTimePeriod=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 54 )
		{
			m_ConnectPromotionTrade=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 55 )
		{
			m_SpecialCardMapTypeCode=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 56 )
		{
			m_TimeTimesTicketTimeUnit=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 57 )
		{
			m_OvertimePenalty2=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 58 )
		{
			m_ExcessPenalty2=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 59 )
		{
			m_CardSavingsLimit=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 60 )
		{
			m_TimesTicketDefaultCarfare=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 61 )
		{
			m_CrosssitePenalty=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 62 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_02);
		}
		if( iColNum == 63 )
		{
			m_RES_03=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 64 )
		{
			m_RES_04=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 65 )
		{
			m_RES_05=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 66 )
		{
			m_DayMaxTakeTimes=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 67 )
		{
			m_RES_06=(wl::tuint8)wl::SStrf::satol(strValPARA);
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
		if( strColName == "PriorityJudgeType" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "CPUCardParaFlag" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "ConnectGapTimesec" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "LostTicketPenalty" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "OvertravelPenalty" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "OvertimePenalty" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "ExcessPenalty" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "SavingsCardInitVal" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "NextdayWorkTimehour" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "InStationMaxTime" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "TicketType" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "strTicketTypeDiscEn" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "TicketTypeDiscCh" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "TicketCtrlCode" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "TicketValiIndi" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "ValidityTimeUnit" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "SpecialChkDays" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "InitVal" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "BuyVal" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "CardInitVal" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "CardInitRewardVal" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "CardRechargeChoise" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "CardRechargeRewardChoise" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "B0_MarginTimesec" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "B0_UnRushhourIdx" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "B0_DiscountRateIdx" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "B0_FullFareRateIdx" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "B1_MarginTimesec" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "B1_UnRushhourIdx" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "B1_DiscountRateIdx" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
		if( strColName == "B1_FullFareRateIdx" )
		{
			SetColVal<STRINGT>(38,strValPARA);
		}
		if( strColName == "B2_MarginTimesec" )
		{
			SetColVal<STRINGT>(39,strValPARA);
		}
		if( strColName == "B2_UnRushhourIdx" )
		{
			SetColVal<STRINGT>(40,strValPARA);
		}
		if( strColName == "B2_DiscountRateIdx" )
		{
			SetColVal<STRINGT>(41,strValPARA);
		}
		if( strColName == "B2_FullFareRateIdx" )
		{
			SetColVal<STRINGT>(42,strValPARA);
		}
		if( strColName == "B3_MarginTimesec" )
		{
			SetColVal<STRINGT>(43,strValPARA);
		}
		if( strColName == "B3_UnRushhourIdx" )
		{
			SetColVal<STRINGT>(44,strValPARA);
		}
		if( strColName == "B3_DiscountRateIdx" )
		{
			SetColVal<STRINGT>(45,strValPARA);
		}
		if( strColName == "B3_FullFareRateIdx" )
		{
			SetColVal<STRINGT>(46,strValPARA);
		}
		if( strColName == "AccumulateBeginPromotionTimes" )
		{
			SetColVal<STRINGT>(47,strValPARA);
		}
		if( strColName == "AccumulateBeginPromotionVal" )
		{
			SetColVal<STRINGT>(48,strValPARA);
		}
		if( strColName == "AccumulatePromotionPercent" )
		{
			SetColVal<STRINGT>(49,strValPARA);
		}
		if( strColName == "ConnectPromotionVal" )
		{
			SetColVal<STRINGT>(50,strValPARA);
		}
		if( strColName == "ConnectPromotionPercent" )
		{
			SetColVal<STRINGT>(51,strValPARA);
		}
		if( strColName == "PromotionPriorityLevelType" )
		{
			SetColVal<STRINGT>(52,strValPARA);
		}
		if( strColName == "ConnectPromotionValidTimePeriod" )
		{
			SetColVal<STRINGT>(53,strValPARA);
		}
		if( strColName == "ConnectPromotionTrade" )
		{
			SetColVal<STRINGT>(54,strValPARA);
		}
		if( strColName == "SpecialCardMapTypeCode" )
		{
			SetColVal<STRINGT>(55,strValPARA);
		}
		if( strColName == "TimeTimesTicketTimeUnit" )
		{
			SetColVal<STRINGT>(56,strValPARA);
		}
		if( strColName == "OvertimePenalty2" )
		{
			SetColVal<STRINGT>(57,strValPARA);
		}
		if( strColName == "ExcessPenalty2" )
		{
			SetColVal<STRINGT>(58,strValPARA);
		}
		if( strColName == "CardSavingsLimit" )
		{
			SetColVal<STRINGT>(59,strValPARA);
		}
		if( strColName == "TimesTicketDefaultCarfare" )
		{
			SetColVal<STRINGT>(60,strValPARA);
		}
		if( strColName == "CrosssitePenalty" )
		{
			SetColVal<STRINGT>(61,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(62,strValPARA);
		}
		if( strColName == "RES_03" )
		{
			SetColVal<STRINGT>(63,strValPARA);
		}
		if( strColName == "RES_04" )
		{
			SetColVal<STRINGT>(64,strValPARA);
		}
		if( strColName == "RES_05" )
		{
			SetColVal<STRINGT>(65,strValPARA);
		}
		if( strColName == "DayMaxTakeTimes" )
		{
			SetColVal<STRINGT>(66,strValPARA);
		}
		if( strColName == "RES_06" )
		{
			SetColVal<STRINGT>(67,strValPARA);
		}
	}

}
; 
//end of class a4002_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a4002_t
class a4002_t {
 
private:

	a4002_t_rowtype m_EmptyRow;
	std::vector<a4002_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a4002_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a4002_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a4002_t()
	{
	}

	virtual ~a4002_t(){;}
	

	//operator == 
	bool operator == (const a4002_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a4002_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a4002_t & rhs) const
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

	a4002_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a4002_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

///////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a4002_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

///////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a4002_t_rowtype tmpEmptyrow;
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

///////////////////////////////////////////////////////////////
//Function:	Add
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a4002_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

/////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a4002_t * p = new a4002_t;
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

/////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_strTblName(std::string strVal) 
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

///////////////////////////////////////////////////////////////
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
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_lVer(long iVal) 
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

///////////////////////////////////////////////////////////////
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
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
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

////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
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

//////////////////////////////////////////////////////////
//Function:	SelE1_strDataRef
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_strDataRef(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strDataRef( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_strDataRef
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strDataRef(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strDataRef(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_PriorityJudgeType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PriorityJudgeType(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PriorityJudgeType==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_PriorityJudgeType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_PriorityJudgeType(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_PriorityJudgeType( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_PriorityJudgeType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PriorityJudgeType(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PriorityJudgeType(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_CPUCardParaFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CPUCardParaFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CPUCardParaFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_CPUCardParaFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CPUCardParaFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_CPUCardParaFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_CPUCardParaFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CPUCardParaFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CPUCardParaFlag(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(u8arr_t<33> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_01(u8arr_t<33> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES_01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_01(u8arr_t<33> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_01(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_ConnectGapTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnectGapTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnectGapTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_ConnectGapTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ConnectGapTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnectGapTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_ConnectGapTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnectGapTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnectGapTimesec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_LostTicketPenalty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LostTicketPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LostTicketPenalty==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_LostTicketPenalty
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_LostTicketPenalty(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LostTicketPenalty( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_LostTicketPenalty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LostTicketPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LostTicketPenalty(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_OvertravelPenalty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_OvertravelPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_OvertravelPenalty==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_OvertravelPenalty
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_OvertravelPenalty(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_OvertravelPenalty( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_OvertravelPenalty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_OvertravelPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_OvertravelPenalty(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_OvertimePenalty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_OvertimePenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_OvertimePenalty==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_OvertimePenalty
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_OvertimePenalty(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_OvertimePenalty( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_OvertimePenalty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_OvertimePenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_OvertimePenalty(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_ExcessPenalty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ExcessPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ExcessPenalty==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_ExcessPenalty
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ExcessPenalty(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ExcessPenalty( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_ExcessPenalty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ExcessPenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ExcessPenalty(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_SavingsCardInitVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SavingsCardInitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SavingsCardInitVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_SavingsCardInitVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_SavingsCardInitVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_SavingsCardInitVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_SavingsCardInitVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SavingsCardInitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SavingsCardInitVal(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_NextdayWorkTimehour
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_NextdayWorkTimehour(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_NextdayWorkTimehour==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_NextdayWorkTimehour
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_NextdayWorkTimehour(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_NextdayWorkTimehour( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_NextdayWorkTimehour
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_NextdayWorkTimehour(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_NextdayWorkTimehour(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_InStationMaxTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_InStationMaxTime(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_InStationMaxTime==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_InStationMaxTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_InStationMaxTime(u8arr_t<16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_InStationMaxTime( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_InStationMaxTime
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_InStationMaxTime(u8arr_t<16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_InStationMaxTime(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_TicketType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketType==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_TicketType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TicketType(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketType( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_TicketType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketType(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketType(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_strTicketTypeDiscEn
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strTicketTypeDiscEn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strTicketTypeDiscEn==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_strTicketTypeDiscEn
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_strTicketTypeDiscEn(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strTicketTypeDiscEn( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_strTicketTypeDiscEn
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_strTicketTypeDiscEn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_strTicketTypeDiscEn(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_TicketTypeDiscCh
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketTypeDiscCh(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketTypeDiscCh==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_TicketTypeDiscCh
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TicketTypeDiscCh(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketTypeDiscCh( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_TicketTypeDiscCh
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketTypeDiscCh(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketTypeDiscCh(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_TicketCtrlCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketCtrlCode(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketCtrlCode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_TicketCtrlCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TicketCtrlCode(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketCtrlCode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_TicketCtrlCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketCtrlCode(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketCtrlCode(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_TicketValiIndi
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TicketValiIndi(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TicketValiIndi==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_TicketValiIndi
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TicketValiIndi(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_TicketValiIndi( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_TicketValiIndi
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TicketValiIndi(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TicketValiIndi(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_ValidityTimeUnit
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ValidityTimeUnit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ValidityTimeUnit==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_ValidityTimeUnit
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ValidityTimeUnit(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ValidityTimeUnit( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_ValidityTimeUnit
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ValidityTimeUnit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ValidityTimeUnit(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_SpecialChkDays
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SpecialChkDays(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SpecialChkDays==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_SpecialChkDays
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_SpecialChkDays(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_SpecialChkDays( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_SpecialChkDays
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SpecialChkDays(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SpecialChkDays(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_InitVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_InitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_InitVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_InitVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_InitVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_InitVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_InitVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_InitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_InitVal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_BuyVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_BuyVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_BuyVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_BuyVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_BuyVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_BuyVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_BuyVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_BuyVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_BuyVal(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_CardInitVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CardInitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CardInitVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CardInitVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CardInitVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CardInitVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_CardInitVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CardInitVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CardInitVal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_CardInitRewardVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CardInitRewardVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CardInitRewardVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_CardInitRewardVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CardInitRewardVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CardInitRewardVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_CardInitRewardVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CardInitRewardVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CardInitRewardVal(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_CardRechargeChoise
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CardRechargeChoise(ui16arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CardRechargeChoise==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CardRechargeChoise
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CardRechargeChoise(ui16arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CardRechargeChoise( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_CardRechargeChoise
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CardRechargeChoise(ui16arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CardRechargeChoise(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_CardRechargeRewardChoise
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CardRechargeRewardChoise(ui16arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CardRechargeRewardChoise==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_CardRechargeRewardChoise
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CardRechargeRewardChoise(ui16arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_CardRechargeRewardChoise( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_CardRechargeRewardChoise
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CardRechargeRewardChoise(ui16arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CardRechargeRewardChoise(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_B0_MarginTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B0_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B0_MarginTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_B0_MarginTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B0_MarginTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B0_MarginTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_B0_MarginTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B0_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B0_MarginTimesec(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_B0_UnRushhourIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B0_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B0_UnRushhourIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_B0_UnRushhourIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B0_UnRushhourIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B0_UnRushhourIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_B0_UnRushhourIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B0_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B0_UnRushhourIdx(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_B0_DiscountRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B0_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B0_DiscountRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_B0_DiscountRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B0_DiscountRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B0_DiscountRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_B0_DiscountRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B0_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B0_DiscountRateIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_B0_FullFareRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B0_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B0_FullFareRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_B0_FullFareRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B0_FullFareRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B0_FullFareRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_B0_FullFareRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B0_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B0_FullFareRateIdx(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_B1_MarginTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B1_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B1_MarginTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_B1_MarginTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B1_MarginTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B1_MarginTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_B1_MarginTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B1_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B1_MarginTimesec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_B1_UnRushhourIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B1_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B1_UnRushhourIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_B1_UnRushhourIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B1_UnRushhourIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B1_UnRushhourIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_B1_UnRushhourIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B1_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B1_UnRushhourIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_B1_DiscountRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B1_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B1_DiscountRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_B1_DiscountRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B1_DiscountRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B1_DiscountRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_B1_DiscountRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B1_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B1_DiscountRateIdx(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_B1_FullFareRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B1_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B1_FullFareRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_B1_FullFareRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B1_FullFareRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B1_FullFareRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_B1_FullFareRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B1_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B1_FullFareRateIdx(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_B2_MarginTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B2_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B2_MarginTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_B2_MarginTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B2_MarginTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B2_MarginTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_B2_MarginTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B2_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B2_MarginTimesec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_B2_UnRushhourIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B2_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B2_UnRushhourIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_B2_UnRushhourIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B2_UnRushhourIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B2_UnRushhourIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_B2_UnRushhourIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B2_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B2_UnRushhourIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_B2_DiscountRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B2_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B2_DiscountRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_B2_DiscountRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B2_DiscountRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B2_DiscountRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_B2_DiscountRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B2_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B2_DiscountRateIdx(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_B2_FullFareRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B2_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B2_FullFareRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_B2_FullFareRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B2_FullFareRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B2_FullFareRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_B2_FullFareRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B2_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B2_FullFareRateIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_B3_MarginTimesec
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B3_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B3_MarginTimesec==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_B3_MarginTimesec
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B3_MarginTimesec(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B3_MarginTimesec( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_B3_MarginTimesec
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B3_MarginTimesec(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B3_MarginTimesec(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_B3_UnRushhourIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B3_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B3_UnRushhourIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_B3_UnRushhourIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B3_UnRushhourIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B3_UnRushhourIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_B3_UnRushhourIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B3_UnRushhourIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B3_UnRushhourIdx(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_B3_DiscountRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B3_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B3_DiscountRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_B3_DiscountRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B3_DiscountRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B3_DiscountRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_B3_DiscountRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B3_DiscountRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B3_DiscountRateIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_B3_FullFareRateIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_B3_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_B3_FullFareRateIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_B3_FullFareRateIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_B3_FullFareRateIdx(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_B3_FullFareRateIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_B3_FullFareRateIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_B3_FullFareRateIdx(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_B3_FullFareRateIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_AccumulateBeginPromotionTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_AccumulateBeginPromotionTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_AccumulateBeginPromotionTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_AccumulateBeginPromotionTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_AccumulateBeginPromotionTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_AccumulateBeginPromotionTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_AccumulateBeginPromotionTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_AccumulateBeginPromotionTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_AccumulateBeginPromotionTimes(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_AccumulateBeginPromotionVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_AccumulateBeginPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_AccumulateBeginPromotionVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_AccumulateBeginPromotionVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_AccumulateBeginPromotionVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_AccumulateBeginPromotionVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_AccumulateBeginPromotionVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_AccumulateBeginPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_AccumulateBeginPromotionVal(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_AccumulatePromotionPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_AccumulatePromotionPercent(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_AccumulatePromotionPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_AccumulatePromotionPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_AccumulatePromotionPercent(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_AccumulatePromotionPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_AccumulatePromotionPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_AccumulatePromotionPercent(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_AccumulatePromotionPercent(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_ConnectPromotionVal
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnectPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnectPromotionVal==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_ConnectPromotionVal
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ConnectPromotionVal(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnectPromotionVal( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ConnectPromotionVal
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnectPromotionVal(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnectPromotionVal(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_ConnectPromotionPercent
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnectPromotionPercent(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnectPromotionPercent==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_ConnectPromotionPercent
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ConnectPromotionPercent(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnectPromotionPercent( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_ConnectPromotionPercent
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnectPromotionPercent(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnectPromotionPercent(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_PromotionPriorityLevelType
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_PromotionPriorityLevelType(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_PromotionPriorityLevelType==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_PromotionPriorityLevelType
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_PromotionPriorityLevelType(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_PromotionPriorityLevelType( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_PromotionPriorityLevelType
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_PromotionPriorityLevelType(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_PromotionPriorityLevelType(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_ConnectPromotionValidTimePeriod
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnectPromotionValidTimePeriod(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnectPromotionValidTimePeriod==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_ConnectPromotionValidTimePeriod
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ConnectPromotionValidTimePeriod(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnectPromotionValidTimePeriod( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_ConnectPromotionValidTimePeriod
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnectPromotionValidTimePeriod(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnectPromotionValidTimePeriod(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_ConnectPromotionTrade
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ConnectPromotionTrade(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ConnectPromotionTrade==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_ConnectPromotionTrade
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ConnectPromotionTrade(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_ConnectPromotionTrade( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_ConnectPromotionTrade
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ConnectPromotionTrade(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ConnectPromotionTrade(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_SpecialCardMapTypeCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_SpecialCardMapTypeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_SpecialCardMapTypeCode==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_SpecialCardMapTypeCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_SpecialCardMapTypeCode(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_SpecialCardMapTypeCode( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_SpecialCardMapTypeCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_SpecialCardMapTypeCode(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_SpecialCardMapTypeCode(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_TimeTimesTicketTimeUnit
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimeTimesTicketTimeUnit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimeTimesTicketTimeUnit==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_TimeTimesTicketTimeUnit
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TimeTimesTicketTimeUnit(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TimeTimesTicketTimeUnit( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_TimeTimesTicketTimeUnit
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimeTimesTicketTimeUnit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimeTimesTicketTimeUnit(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_OvertimePenalty2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_OvertimePenalty2(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_OvertimePenalty2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_OvertimePenalty2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_OvertimePenalty2(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_OvertimePenalty2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_OvertimePenalty2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_OvertimePenalty2(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_OvertimePenalty2(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_ExcessPenalty2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ExcessPenalty2(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ExcessPenalty2==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_ExcessPenalty2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_ExcessPenalty2(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_ExcessPenalty2( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_ExcessPenalty2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ExcessPenalty2(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ExcessPenalty2(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_CardSavingsLimit
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CardSavingsLimit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CardSavingsLimit==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_CardSavingsLimit
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CardSavingsLimit(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CardSavingsLimit( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_CardSavingsLimit
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CardSavingsLimit(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CardSavingsLimit(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_TimesTicketDefaultCarfare
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_TimesTicketDefaultCarfare(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_TimesTicketDefaultCarfare==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_TimesTicketDefaultCarfare
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_TimesTicketDefaultCarfare(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_TimesTicketDefaultCarfare( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_TimesTicketDefaultCarfare
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_TimesTicketDefaultCarfare(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_TimesTicketDefaultCarfare(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_CrosssitePenalty
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_CrosssitePenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_CrosssitePenalty==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_CrosssitePenalty
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_CrosssitePenalty(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_CrosssitePenalty( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_CrosssitePenalty
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_CrosssitePenalty(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_CrosssitePenalty(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES_02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_02(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_02==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_02(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RES_03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_03==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES_03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_03(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_03( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_RES_03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_03(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_03(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_RES_04
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_04(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_04==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_RES_04
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_04(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_04( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES_04
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_04(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_04(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_RES_05
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_05(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_05==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_RES_05
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_05(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_05( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES_05
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_05(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_05(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_DayMaxTakeTimes
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DayMaxTakeTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DayMaxTakeTimes==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_DayMaxTakeTimes
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_DayMaxTakeTimes(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DayMaxTakeTimes( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_DayMaxTakeTimes
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DayMaxTakeTimes(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DayMaxTakeTimes(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_RES_06
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_06(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_06==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_RES_06
//Effect:	select 1st row where col=val, or return default row.
//Return:	a4002_t_rowtype&
	a4002_t_rowtype & SelE1_RES_06(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_06( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES_06
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_06(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_06(iVal, vRps, pRefRps);
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

/////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////
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
//end of class a4002_t


#endif

