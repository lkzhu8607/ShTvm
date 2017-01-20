
#ifndef V1_3AA3083_T_20140523_162103
#define V1_3AA3083_T_20140523_162103

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a3083_t
//Name:	a3083_t_rowtype
class a3083_t_rowtype {
 
public:

	std::string		m_strTblName;			// 1		7.0.21  3083-自动售票机主界面定义报文 
	long		m_lVer;			// 2		参数版本 
	std::string		m_strAffectDateTime;			// 3		生效时间 
	wl::tuint8		m_biDelFlag;			// 4		是否删除 
	wl::tuint8		m_biIsAffect;			// 5		是否生效 
	std::string		m_strStampDateTime;			// 6		Stamp 
	std::string		m_strDataRef;			// 7		数据参考 
	wl::tuint8		m_MainUiIdx;			// a	1	主界面索引号  Byte 1 
	std::string		m_MainUiPicFn;			// a	2	主界面图形文件名  String 24 
	long		m_MainUiPicWidth;			// a	3	主界面图形文件宽度 单位：像素 Word 2 
	long		m_MainUiPicHeight;			// a	4	主界面图形文件高度 单位：像素 Word 2 
	long		m_LaunSeleButtX;			// a	5	语言选择按钮x坐标 语言选择按钮在主界面上的x坐标，单位：像素 Word 2 
	long		m_LaunSeleButtY;			// a	6	语言选择按钮y坐标 语言选择按钮在主界面上的y坐标，单位：像素 Word 2 
	long		m_LaunSeleButtWidth;			// a	7	语言选择长度 按钮区域的横向长度，单位：像素 Byte 1 
	long		m_LaunSeleButtHeight;			// a	8	语言选择宽度 按钮区域的纵向宽度，单位：像素 Byte 1 
	wl::tuint8		m_DirButt1Enable;			// a	9	方向按钮1的有效性表示该按钮是否需要在界面上显示00=无效01=有效Byte1 
	long		m_DirButt1X;			// a	10	方向按钮1的x坐标 按钮在主界面上的x坐标，单位：像素 Word 2 
	long		m_DirButt1Y;			// a	11	方向按钮1的y坐标 按钮在主界面上的y坐标，单位：像素 Word 2 
	long		m_DirButt1Width;			// a	12	方向按钮1长度 按钮区域的横向长度，单位：像素 Byte 1 
	long		m_DirButt1Height;			// a	13	方向按钮1宽度 按钮区域的纵向宽度，单位：像素 Byte 1 
	wl::tuint8		m_DirButt1MainUiIdx;			// a	14	方向按钮1对应的主界面索引 按下按钮后切换的界面索引号 Byte 1 
	wl::tuint8		m_DirButt2Enable;			// a	15		方向按钮2的有效性表示该按钮是否需要在界面上显示00=无效01=有效Byte1 
	long		m_DirButt2X;			// a	16		方向按钮2的x坐标 按钮在主界面上的x坐标，单位：像素 Word 2 
	long		m_DirButt2Y;			// a	17		方向按钮2的y坐标 按钮在主界面上的y坐标，单位：像素 Word 2 
	long		m_DirButt2Width;			// a	18		方向按钮2长度 按钮区域的横向长度，单位：像素 Byte 1 
	long		m_DirButt2Height;			// a	19		方向按钮2宽度 按钮区域的纵向宽度，单位：像素 Byte 1 
	wl::tuint8		m_DirButt2MainUiIdx;			// a	20		方向按钮2对应的主界面索引 按下按钮后切换的界面索引号 Byte 1 
	wl::tuint8		m_DirButt3Enable;			// a	21	按钮3 
	long		m_DirButt3X;			// a	22	按钮3 
	long		m_DirButt3Y;			// a	23	按钮3 
	long		m_DirButt3Width;			// a	24	按钮3 
	long		m_DirButt3Height;			// a	25	按钮3 
	wl::tuint8		m_DirButt3MainUiIdx;			// a	26	按钮3 
	wl::tuint8		m_DirButt4Enable;			// a	27		按钮4 
	long		m_DirButt4X;			// a	28		按钮4 
	long		m_DirButt4Y;			// a	29		按钮4 
	long		m_DirButt4Width;			// a	30		按钮4 
	long		m_DirButt4Height;			// a	31		按钮4 
	wl::tuint8		m_DirButt4MainUiIdx;			// a	32		按钮4 
	long		m_LineButtNum;			// a	33	线路按钮记录数 16进制表示，例10条线路表示为0x0A Byte 1 
	u8arr_t<4>		m_RES_02;			// a	34	保留  Byte 4 
	uiarr_t<long,16>		m_LineCode;			// a	35	线路代码 线路代码，BCD码 Byte 1 
	uiarr_t<long,16>		m_RES_01;			// a	36	保留  Long 4 
 
public:

	a3083_t_rowtype()
	{
		m_strTblName = "a3083";
		m_lVer = 0;
		m_strAffectDateTime = "";
		m_biDelFlag = 0;
		m_biIsAffect = 0;
		m_strStampDateTime = wl::SDte::GetNow().ReadString();
		m_strDataRef = "";
		m_MainUiIdx = 0;
		m_MainUiPicFn = "";
		m_MainUiPicWidth = 0;
		m_MainUiPicHeight = 0;
		m_LaunSeleButtX = 0;
		m_LaunSeleButtY = 0;
		m_LaunSeleButtWidth = 0;
		m_LaunSeleButtHeight = 0;
		m_DirButt1Enable = 0;
		m_DirButt1X = 0;
		m_DirButt1Y = 0;
		m_DirButt1Width = 0;
		m_DirButt1Height = 0;
		m_DirButt1MainUiIdx = 0;
		m_DirButt2Enable = 0;
		m_DirButt2X = 0;
		m_DirButt2Y = 0;
		m_DirButt2Width = 0;
		m_DirButt2Height = 0;
		m_DirButt2MainUiIdx = 0;
		m_DirButt3Enable = 0;
		m_DirButt3X = 0;
		m_DirButt3Y = 0;
		m_DirButt3Width = 0;
		m_DirButt3Height = 0;
		m_DirButt3MainUiIdx = 0;
		m_DirButt4Enable = 0;
		m_DirButt4X = 0;
		m_DirButt4Y = 0;
		m_DirButt4Width = 0;
		m_DirButt4Height = 0;
		m_DirButt4MainUiIdx = 0;
		m_LineButtNum = 0;
		//m_RES_02 = //use default
		//m_LineCode = //use default
		//m_RES_01 = //use default
	}

	virtual ~a3083_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a3083_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3083_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3083_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiIdx));
		len1 = sizeof(m_MainUiIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_MainUiPicFn.c_str();
		len1 = (long)(m_MainUiPicFn.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiPicWidth));
		len1 = sizeof(m_MainUiPicWidth);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiPicHeight));
		len1 = sizeof(m_MainUiPicHeight);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtX));
		len1 = sizeof(m_LaunSeleButtX);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtY));
		len1 = sizeof(m_LaunSeleButtY);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtWidth));
		len1 = sizeof(m_LaunSeleButtWidth);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtHeight));
		len1 = sizeof(m_LaunSeleButtHeight);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Enable));
		len1 = sizeof(m_DirButt1Enable);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1X));
		len1 = sizeof(m_DirButt1X);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Y));
		len1 = sizeof(m_DirButt1Y);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Width));
		len1 = sizeof(m_DirButt1Width);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Height));
		len1 = sizeof(m_DirButt1Height);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1MainUiIdx));
		len1 = sizeof(m_DirButt1MainUiIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Enable));
		len1 = sizeof(m_DirButt2Enable);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2X));
		len1 = sizeof(m_DirButt2X);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Y));
		len1 = sizeof(m_DirButt2Y);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Width));
		len1 = sizeof(m_DirButt2Width);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Height));
		len1 = sizeof(m_DirButt2Height);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2MainUiIdx));
		len1 = sizeof(m_DirButt2MainUiIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Enable));
		len1 = sizeof(m_DirButt3Enable);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3X));
		len1 = sizeof(m_DirButt3X);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Y));
		len1 = sizeof(m_DirButt3Y);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Width));
		len1 = sizeof(m_DirButt3Width);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Height));
		len1 = sizeof(m_DirButt3Height);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3MainUiIdx));
		len1 = sizeof(m_DirButt3MainUiIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Enable));
		len1 = sizeof(m_DirButt4Enable);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4X));
		len1 = sizeof(m_DirButt4X);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Y));
		len1 = sizeof(m_DirButt4Y);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Width));
		len1 = sizeof(m_DirButt4Width);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Height));
		len1 = sizeof(m_DirButt4Height);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4MainUiIdx));
		len1 = sizeof(m_DirButt4MainUiIdx);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineButtNum));
		len1 = sizeof(m_LineButtNum);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineCode));
		len1 = sizeof(m_LineCode);
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
		return strOut;
	}

	std::string Serialize()
	{
		std::string strOut;
		return this->Serialize(strOut);
	}

	a3083_t_rowtype & Unserialize( const char * strIn )
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
		 /*if( *buf2!='}')*/ m_MainUiIdx = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_MainUiPicFn = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_MainUiPicWidth = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_MainUiPicHeight = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LaunSeleButtX = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LaunSeleButtY = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LaunSeleButtWidth = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LaunSeleButtHeight = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1Enable = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1X = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1Y = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1Width = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1Height = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt1MainUiIdx = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2Enable = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2X = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2Y = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2Width = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2Height = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt2MainUiIdx = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3Enable = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3X = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3Y = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3Width = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3Height = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt3MainUiIdx = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4Enable = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4X = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4Y = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4Width = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4Height = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_DirButt4MainUiIdx = *(wl::tuint8*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LineButtNum = *(long*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_02 = *(u8arr_t<4>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_LineCode = *(uiarr_t<long,16>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES_01 = *(uiarr_t<long,16>*)buf2; }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiIdx));
		len1 = sizeof(m_MainUiIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_MainUiPicFn.c_str();
		len1 = (long)(m_MainUiPicFn.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiPicWidth));
		len1 = sizeof(m_MainUiPicWidth);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_MainUiPicHeight));
		len1 = sizeof(m_MainUiPicHeight);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtX));
		len1 = sizeof(m_LaunSeleButtX);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtY));
		len1 = sizeof(m_LaunSeleButtY);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtWidth));
		len1 = sizeof(m_LaunSeleButtWidth);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LaunSeleButtHeight));
		len1 = sizeof(m_LaunSeleButtHeight);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Enable));
		len1 = sizeof(m_DirButt1Enable);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1X));
		len1 = sizeof(m_DirButt1X);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Y));
		len1 = sizeof(m_DirButt1Y);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Width));
		len1 = sizeof(m_DirButt1Width);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1Height));
		len1 = sizeof(m_DirButt1Height);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt1MainUiIdx));
		len1 = sizeof(m_DirButt1MainUiIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Enable));
		len1 = sizeof(m_DirButt2Enable);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2X));
		len1 = sizeof(m_DirButt2X);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Y));
		len1 = sizeof(m_DirButt2Y);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Width));
		len1 = sizeof(m_DirButt2Width);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2Height));
		len1 = sizeof(m_DirButt2Height);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt2MainUiIdx));
		len1 = sizeof(m_DirButt2MainUiIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Enable));
		len1 = sizeof(m_DirButt3Enable);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3X));
		len1 = sizeof(m_DirButt3X);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Y));
		len1 = sizeof(m_DirButt3Y);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Width));
		len1 = sizeof(m_DirButt3Width);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3Height));
		len1 = sizeof(m_DirButt3Height);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt3MainUiIdx));
		len1 = sizeof(m_DirButt3MainUiIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Enable));
		len1 = sizeof(m_DirButt4Enable);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4X));
		len1 = sizeof(m_DirButt4X);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Y));
		len1 = sizeof(m_DirButt4Y);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Width));
		len1 = sizeof(m_DirButt4Width);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4Height));
		len1 = sizeof(m_DirButt4Height);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_DirButt4MainUiIdx));
		len1 = sizeof(m_DirButt4MainUiIdx);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineButtNum));
		len1 = sizeof(m_LineButtNum);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_02));
		len1 = sizeof(m_RES_02);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_LineCode));
		len1 = sizeof(m_LineCode);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a3083_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
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
		m_MainUiIdx = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_MainUiPicFn = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_MainUiPicWidth = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_MainUiPicHeight = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LaunSeleButtX = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LaunSeleButtY = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LaunSeleButtWidth = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LaunSeleButtHeight = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1Enable = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1X = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1Y = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1Width = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1Height = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt1MainUiIdx = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2Enable = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2X = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2Y = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2Width = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2Height = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt2MainUiIdx = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3Enable = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3X = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3Y = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3Width = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3Height = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt3MainUiIdx = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4Enable = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4X = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4Y = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4Width = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4Height = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_DirButt4MainUiIdx = *(wl::tuint8*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LineButtNum = *(long*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_02 = *(u8arr_t<4>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_LineCode = *(uiarr_t<long,16>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_01 = *(uiarr_t<long,16>*)buf2;
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
//Function:	GetCol_MainUiIdx
//Effect:	get ref of col. col is MainUiIdx
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_MainUiIdx(void)
	{
		return m_MainUiIdx;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_MainUiPicFn
//Effect:	get ref of col. col is MainUiPicFn
//Return:	std::string & 
	std::string & GetCol_MainUiPicFn(void)
	{
		return m_MainUiPicFn;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_MainUiPicWidth
//Effect:	get ref of col. col is MainUiPicWidth
//Return:	long & 
	long & GetCol_MainUiPicWidth(void)
	{
		return m_MainUiPicWidth;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_MainUiPicHeight
//Effect:	get ref of col. col is MainUiPicHeight
//Return:	long & 
	long & GetCol_MainUiPicHeight(void)
	{
		return m_MainUiPicHeight;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_LaunSeleButtX
//Effect:	get ref of col. col is LaunSeleButtX
//Return:	long & 
	long & GetCol_LaunSeleButtX(void)
	{
		return m_LaunSeleButtX;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_LaunSeleButtY
//Effect:	get ref of col. col is LaunSeleButtY
//Return:	long & 
	long & GetCol_LaunSeleButtY(void)
	{
		return m_LaunSeleButtY;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_LaunSeleButtWidth
//Effect:	get ref of col. col is LaunSeleButtWidth
//Return:	long & 
	long & GetCol_LaunSeleButtWidth(void)
	{
		return m_LaunSeleButtWidth;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_LaunSeleButtHeight
//Effect:	get ref of col. col is LaunSeleButtHeight
//Return:	long & 
	long & GetCol_LaunSeleButtHeight(void)
	{
		return m_LaunSeleButtHeight;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1Enable
//Effect:	get ref of col. col is DirButt1Enable
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt1Enable(void)
	{
		return m_DirButt1Enable;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1X
//Effect:	get ref of col. col is DirButt1X
//Return:	long & 
	long & GetCol_DirButt1X(void)
	{
		return m_DirButt1X;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1Y
//Effect:	get ref of col. col is DirButt1Y
//Return:	long & 
	long & GetCol_DirButt1Y(void)
	{
		return m_DirButt1Y;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1Width
//Effect:	get ref of col. col is DirButt1Width
//Return:	long & 
	long & GetCol_DirButt1Width(void)
	{
		return m_DirButt1Width;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1Height
//Effect:	get ref of col. col is DirButt1Height
//Return:	long & 
	long & GetCol_DirButt1Height(void)
	{
		return m_DirButt1Height;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_DirButt1MainUiIdx
//Effect:	get ref of col. col is DirButt1MainUiIdx
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt1MainUiIdx(void)
	{
		return m_DirButt1MainUiIdx;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_DirButt2Enable
//Effect:	get ref of col. col is DirButt2Enable
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt2Enable(void)
	{
		return m_DirButt2Enable;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_DirButt2X
//Effect:	get ref of col. col is DirButt2X
//Return:	long & 
	long & GetCol_DirButt2X(void)
	{
		return m_DirButt2X;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_DirButt2Y
//Effect:	get ref of col. col is DirButt2Y
//Return:	long & 
	long & GetCol_DirButt2Y(void)
	{
		return m_DirButt2Y;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_DirButt2Width
//Effect:	get ref of col. col is DirButt2Width
//Return:	long & 
	long & GetCol_DirButt2Width(void)
	{
		return m_DirButt2Width;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt2Height
//Effect:	get ref of col. col is DirButt2Height
//Return:	long & 
	long & GetCol_DirButt2Height(void)
	{
		return m_DirButt2Height;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt2MainUiIdx
//Effect:	get ref of col. col is DirButt2MainUiIdx
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt2MainUiIdx(void)
	{
		return m_DirButt2MainUiIdx;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3Enable
//Effect:	get ref of col. col is DirButt3Enable
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt3Enable(void)
	{
		return m_DirButt3Enable;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3X
//Effect:	get ref of col. col is DirButt3X
//Return:	long & 
	long & GetCol_DirButt3X(void)
	{
		return m_DirButt3X;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3Y
//Effect:	get ref of col. col is DirButt3Y
//Return:	long & 
	long & GetCol_DirButt3Y(void)
	{
		return m_DirButt3Y;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3Width
//Effect:	get ref of col. col is DirButt3Width
//Return:	long & 
	long & GetCol_DirButt3Width(void)
	{
		return m_DirButt3Width;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3Height
//Effect:	get ref of col. col is DirButt3Height
//Return:	long & 
	long & GetCol_DirButt3Height(void)
	{
		return m_DirButt3Height;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_DirButt3MainUiIdx
//Effect:	get ref of col. col is DirButt3MainUiIdx
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt3MainUiIdx(void)
	{
		return m_DirButt3MainUiIdx;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_DirButt4Enable
//Effect:	get ref of col. col is DirButt4Enable
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt4Enable(void)
	{
		return m_DirButt4Enable;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt4X
//Effect:	get ref of col. col is DirButt4X
//Return:	long & 
	long & GetCol_DirButt4X(void)
	{
		return m_DirButt4X;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt4Y
//Effect:	get ref of col. col is DirButt4Y
//Return:	long & 
	long & GetCol_DirButt4Y(void)
	{
		return m_DirButt4Y;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt4Width
//Effect:	get ref of col. col is DirButt4Width
//Return:	long & 
	long & GetCol_DirButt4Width(void)
	{
		return m_DirButt4Width;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_DirButt4Height
//Effect:	get ref of col. col is DirButt4Height
//Return:	long & 
	long & GetCol_DirButt4Height(void)
	{
		return m_DirButt4Height;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_DirButt4MainUiIdx
//Effect:	get ref of col. col is DirButt4MainUiIdx
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_DirButt4MainUiIdx(void)
	{
		return m_DirButt4MainUiIdx;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_LineButtNum
//Effect:	get ref of col. col is LineButtNum
//Return:	long & 
	long & GetCol_LineButtNum(void)
	{
		return m_LineButtNum;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_RES_02
//Effect:	get ref of col. col is RES_02
//Return:	u8arr_t<4> & 
	u8arr_t<4> & GetCol_RES_02(void)
	{
		return m_RES_02;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_LineCode
//Effect:	get ref of col. col is LineCode
//Return:	uiarr_t<long,16> & 
	uiarr_t<long,16> & GetCol_LineCode(void)
	{
		return m_LineCode;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	uiarr_t<long,16> & 
	uiarr_t<long,16> & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

 
public:

////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 43;
	}

////////////////////////////////////////////////////////
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
			return "MainUiIdx";
		}
		if( iColNum == 8 )
		{
			return "MainUiPicFn";
		}
		if( iColNum == 9 )
		{
			return "MainUiPicWidth";
		}
		if( iColNum == 10 )
		{
			return "MainUiPicHeight";
		}
		if( iColNum == 11 )
		{
			return "LaunSeleButtX";
		}
		if( iColNum == 12 )
		{
			return "LaunSeleButtY";
		}
		if( iColNum == 13 )
		{
			return "LaunSeleButtWidth";
		}
		if( iColNum == 14 )
		{
			return "LaunSeleButtHeight";
		}
		if( iColNum == 15 )
		{
			return "DirButt1Enable";
		}
		if( iColNum == 16 )
		{
			return "DirButt1X";
		}
		if( iColNum == 17 )
		{
			return "DirButt1Y";
		}
		if( iColNum == 18 )
		{
			return "DirButt1Width";
		}
		if( iColNum == 19 )
		{
			return "DirButt1Height";
		}
		if( iColNum == 20 )
		{
			return "DirButt1MainUiIdx";
		}
		if( iColNum == 21 )
		{
			return "DirButt2Enable";
		}
		if( iColNum == 22 )
		{
			return "DirButt2X";
		}
		if( iColNum == 23 )
		{
			return "DirButt2Y";
		}
		if( iColNum == 24 )
		{
			return "DirButt2Width";
		}
		if( iColNum == 25 )
		{
			return "DirButt2Height";
		}
		if( iColNum == 26 )
		{
			return "DirButt2MainUiIdx";
		}
		if( iColNum == 27 )
		{
			return "DirButt3Enable";
		}
		if( iColNum == 28 )
		{
			return "DirButt3X";
		}
		if( iColNum == 29 )
		{
			return "DirButt3Y";
		}
		if( iColNum == 30 )
		{
			return "DirButt3Width";
		}
		if( iColNum == 31 )
		{
			return "DirButt3Height";
		}
		if( iColNum == 32 )
		{
			return "DirButt3MainUiIdx";
		}
		if( iColNum == 33 )
		{
			return "DirButt4Enable";
		}
		if( iColNum == 34 )
		{
			return "DirButt4X";
		}
		if( iColNum == 35 )
		{
			return "DirButt4Y";
		}
		if( iColNum == 36 )
		{
			return "DirButt4Width";
		}
		if( iColNum == 37 )
		{
			return "DirButt4Height";
		}
		if( iColNum == 38 )
		{
			return "DirButt4MainUiIdx";
		}
		if( iColNum == 39 )
		{
			return "LineButtNum";
		}
		if( iColNum == 40 )
		{
			return "RES_02";
		}
		if( iColNum == 41 )
		{
			return "LineCode";
		}
		if( iColNum == 42 )
		{
			return "RES_01";
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
		if( strColName == "MainUiIdx" )
		{
			return 7;
		}
		if( strColName == "MainUiPicFn" )
		{
			return 8;
		}
		if( strColName == "MainUiPicWidth" )
		{
			return 9;
		}
		if( strColName == "MainUiPicHeight" )
		{
			return 10;
		}
		if( strColName == "LaunSeleButtX" )
		{
			return 11;
		}
		if( strColName == "LaunSeleButtY" )
		{
			return 12;
		}
		if( strColName == "LaunSeleButtWidth" )
		{
			return 13;
		}
		if( strColName == "LaunSeleButtHeight" )
		{
			return 14;
		}
		if( strColName == "DirButt1Enable" )
		{
			return 15;
		}
		if( strColName == "DirButt1X" )
		{
			return 16;
		}
		if( strColName == "DirButt1Y" )
		{
			return 17;
		}
		if( strColName == "DirButt1Width" )
		{
			return 18;
		}
		if( strColName == "DirButt1Height" )
		{
			return 19;
		}
		if( strColName == "DirButt1MainUiIdx" )
		{
			return 20;
		}
		if( strColName == "DirButt2Enable" )
		{
			return 21;
		}
		if( strColName == "DirButt2X" )
		{
			return 22;
		}
		if( strColName == "DirButt2Y" )
		{
			return 23;
		}
		if( strColName == "DirButt2Width" )
		{
			return 24;
		}
		if( strColName == "DirButt2Height" )
		{
			return 25;
		}
		if( strColName == "DirButt2MainUiIdx" )
		{
			return 26;
		}
		if( strColName == "DirButt3Enable" )
		{
			return 27;
		}
		if( strColName == "DirButt3X" )
		{
			return 28;
		}
		if( strColName == "DirButt3Y" )
		{
			return 29;
		}
		if( strColName == "DirButt3Width" )
		{
			return 30;
		}
		if( strColName == "DirButt3Height" )
		{
			return 31;
		}
		if( strColName == "DirButt3MainUiIdx" )
		{
			return 32;
		}
		if( strColName == "DirButt4Enable" )
		{
			return 33;
		}
		if( strColName == "DirButt4X" )
		{
			return 34;
		}
		if( strColName == "DirButt4Y" )
		{
			return 35;
		}
		if( strColName == "DirButt4Width" )
		{
			return 36;
		}
		if( strColName == "DirButt4Height" )
		{
			return 37;
		}
		if( strColName == "DirButt4MainUiIdx" )
		{
			return 38;
		}
		if( strColName == "LineButtNum" )
		{
			return 39;
		}
		if( strColName == "RES_02" )
		{
			return 40;
		}
		if( strColName == "LineCode" )
		{
			return 41;
		}
		if( strColName == "RES_01" )
		{
			return 42;
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
			return wl::SStrf::sltoa(m_MainUiIdx);
		}
		if( iColNum == 8 )
		{
			return m_MainUiPicFn;
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sltoa(m_MainUiPicWidth);
		}
		if( iColNum == 10 )
		{
			return wl::SStrf::sltoa(m_MainUiPicHeight);
		}
		if( iColNum == 11 )
		{
			return wl::SStrf::sltoa(m_LaunSeleButtX);
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_LaunSeleButtY);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sltoa(m_LaunSeleButtWidth);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sltoa(m_LaunSeleButtHeight);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::sltoa(m_DirButt1Enable);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_DirButt1X);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sltoa(m_DirButt1Y);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::sltoa(m_DirButt1Width);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::sltoa(m_DirButt1Height);
		}
		if( iColNum == 20 )
		{
			return wl::SStrf::sltoa(m_DirButt1MainUiIdx);
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sltoa(m_DirButt2Enable);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sltoa(m_DirButt2X);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_DirButt2Y);
		}
		if( iColNum == 24 )
		{
			return wl::SStrf::sltoa(m_DirButt2Width);
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_DirButt2Height);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::sltoa(m_DirButt2MainUiIdx);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::sltoa(m_DirButt3Enable);
		}
		if( iColNum == 28 )
		{
			return wl::SStrf::sltoa(m_DirButt3X);
		}
		if( iColNum == 29 )
		{
			return wl::SStrf::sltoa(m_DirButt3Y);
		}
		if( iColNum == 30 )
		{
			return wl::SStrf::sltoa(m_DirButt3Width);
		}
		if( iColNum == 31 )
		{
			return wl::SStrf::sltoa(m_DirButt3Height);
		}
		if( iColNum == 32 )
		{
			return wl::SStrf::sltoa(m_DirButt3MainUiIdx);
		}
		if( iColNum == 33 )
		{
			return wl::SStrf::sltoa(m_DirButt4Enable);
		}
		if( iColNum == 34 )
		{
			return wl::SStrf::sltoa(m_DirButt4X);
		}
		if( iColNum == 35 )
		{
			return wl::SStrf::sltoa(m_DirButt4Y);
		}
		if( iColNum == 36 )
		{
			return wl::SStrf::sltoa(m_DirButt4Width);
		}
		if( iColNum == 37 )
		{
			return wl::SStrf::sltoa(m_DirButt4Height);
		}
		if( iColNum == 38 )
		{
			return wl::SStrf::sltoa(m_DirButt4MainUiIdx);
		}
		if( iColNum == 39 )
		{
			return wl::SStrf::sltoa(m_LineButtNum);
		}
		if( iColNum == 40 )
		{
			return wl::SStrf::b2s(m_RES_02);
		}
		if( iColNum == 41 )
		{
			return wl::SStrf::b2s(m_LineCode);
		}
		if( iColNum == 42 )
		{
			return wl::SStrf::b2s(m_RES_01);
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
		if( strColName == "MainUiIdx" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "MainUiPicFn" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "MainUiPicWidth" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "MainUiPicHeight" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "LaunSeleButtX" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "LaunSeleButtY" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "LaunSeleButtWidth" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "LaunSeleButtHeight" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "DirButt1Enable" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "DirButt1X" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "DirButt1Y" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "DirButt1Width" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "DirButt1Height" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "DirButt1MainUiIdx" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "DirButt2Enable" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "DirButt2X" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "DirButt2Y" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "DirButt2Width" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "DirButt2Height" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "DirButt2MainUiIdx" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "DirButt3Enable" )
		{
			return GetColStr<STRINGT>(27);
		}
		if( strColName == "DirButt3X" )
		{
			return GetColStr<STRINGT>(28);
		}
		if( strColName == "DirButt3Y" )
		{
			return GetColStr<STRINGT>(29);
		}
		if( strColName == "DirButt3Width" )
		{
			return GetColStr<STRINGT>(30);
		}
		if( strColName == "DirButt3Height" )
		{
			return GetColStr<STRINGT>(31);
		}
		if( strColName == "DirButt3MainUiIdx" )
		{
			return GetColStr<STRINGT>(32);
		}
		if( strColName == "DirButt4Enable" )
		{
			return GetColStr<STRINGT>(33);
		}
		if( strColName == "DirButt4X" )
		{
			return GetColStr<STRINGT>(34);
		}
		if( strColName == "DirButt4Y" )
		{
			return GetColStr<STRINGT>(35);
		}
		if( strColName == "DirButt4Width" )
		{
			return GetColStr<STRINGT>(36);
		}
		if( strColName == "DirButt4Height" )
		{
			return GetColStr<STRINGT>(37);
		}
		if( strColName == "DirButt4MainUiIdx" )
		{
			return GetColStr<STRINGT>(38);
		}
		if( strColName == "LineButtNum" )
		{
			return GetColStr<STRINGT>(39);
		}
		if( strColName == "RES_02" )
		{
			return GetColStr<STRINGT>(40);
		}
		if( strColName == "LineCode" )
		{
			return GetColStr<STRINGT>(41);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(42);
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
			m_MainUiIdx=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_MainUiPicFn=strValPARA;
		}
		if( iColNum == 9 )
		{
			m_MainUiPicWidth=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_MainUiPicHeight=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 11 )
		{
			m_LaunSeleButtX=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 12 )
		{
			m_LaunSeleButtY=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_LaunSeleButtWidth=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_LaunSeleButtHeight=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 15 )
		{
			m_DirButt1Enable=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 16 )
		{
			m_DirButt1X=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_DirButt1Y=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 18 )
		{
			m_DirButt1Width=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 19 )
		{
			m_DirButt1Height=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 20 )
		{
			m_DirButt1MainUiIdx=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_DirButt2Enable=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_DirButt2X=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 23 )
		{
			m_DirButt2Y=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_DirButt2Width=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 25 )
		{
			m_DirButt2Height=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			m_DirButt2MainUiIdx=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 27 )
		{
			m_DirButt3Enable=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 28 )
		{
			m_DirButt3X=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 29 )
		{
			m_DirButt3Y=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 30 )
		{
			m_DirButt3Width=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 31 )
		{
			m_DirButt3Height=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 32 )
		{
			m_DirButt3MainUiIdx=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 33 )
		{
			m_DirButt4Enable=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 34 )
		{
			m_DirButt4X=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 35 )
		{
			m_DirButt4Y=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 36 )
		{
			m_DirButt4Width=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 37 )
		{
			m_DirButt4Height=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 38 )
		{
			m_DirButt4MainUiIdx=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 39 )
		{
			m_LineButtNum=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 40 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_02);
		}
		if( iColNum == 41 )
		{
			wl::SStrf::s2b(strValPARA,m_LineCode);
		}
		if( iColNum == 42 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_01);
		}
	}

///////////////////////////////////////////////////////////////
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
		if( strColName == "MainUiIdx" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "MainUiPicFn" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "MainUiPicWidth" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "MainUiPicHeight" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "LaunSeleButtX" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "LaunSeleButtY" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "LaunSeleButtWidth" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "LaunSeleButtHeight" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "DirButt1Enable" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "DirButt1X" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "DirButt1Y" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "DirButt1Width" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "DirButt1Height" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "DirButt1MainUiIdx" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "DirButt2Enable" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "DirButt2X" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "DirButt2Y" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "DirButt2Width" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "DirButt2Height" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "DirButt2MainUiIdx" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "DirButt3Enable" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
		if( strColName == "DirButt3X" )
		{
			SetColVal<STRINGT>(28,strValPARA);
		}
		if( strColName == "DirButt3Y" )
		{
			SetColVal<STRINGT>(29,strValPARA);
		}
		if( strColName == "DirButt3Width" )
		{
			SetColVal<STRINGT>(30,strValPARA);
		}
		if( strColName == "DirButt3Height" )
		{
			SetColVal<STRINGT>(31,strValPARA);
		}
		if( strColName == "DirButt3MainUiIdx" )
		{
			SetColVal<STRINGT>(32,strValPARA);
		}
		if( strColName == "DirButt4Enable" )
		{
			SetColVal<STRINGT>(33,strValPARA);
		}
		if( strColName == "DirButt4X" )
		{
			SetColVal<STRINGT>(34,strValPARA);
		}
		if( strColName == "DirButt4Y" )
		{
			SetColVal<STRINGT>(35,strValPARA);
		}
		if( strColName == "DirButt4Width" )
		{
			SetColVal<STRINGT>(36,strValPARA);
		}
		if( strColName == "DirButt4Height" )
		{
			SetColVal<STRINGT>(37,strValPARA);
		}
		if( strColName == "DirButt4MainUiIdx" )
		{
			SetColVal<STRINGT>(38,strValPARA);
		}
		if( strColName == "LineButtNum" )
		{
			SetColVal<STRINGT>(39,strValPARA);
		}
		if( strColName == "RES_02" )
		{
			SetColVal<STRINGT>(40,strValPARA);
		}
		if( strColName == "LineCode" )
		{
			SetColVal<STRINGT>(41,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(42,strValPARA);
		}
	}

}
; 
//end of class a3083_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a3083_t
class a3083_t {
 
private:

	a3083_t_rowtype m_EmptyRow;
	std::vector<a3083_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a3083_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a3083_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a3083_t()
	{
	}

	virtual ~a3083_t(){;}
	

	//operator == 
	bool operator == (const a3083_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a3083_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a3083_t & rhs) const
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

	a3083_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a3083_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

/////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a3083_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

/////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a3083_t_rowtype tmpEmptyrow;
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
	void Add(const a3083_t_rowtype & varRow)
	{
		m_DATAcorpora.push_back( varRow);
	}

////////////////////////////////////////////////////////////////
//Function:	ReIdx
//Effect:	re-build the indexes, if any.
//Return:	no return
	void ReIdx()
	{
	}

///////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

///////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a3083_t * p = new a3083_t;
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

//////////////////////////////////////////////////////////////
//Function:	SelE1_strTblName
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_strTblName(std::string strVal) 
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

///////////////////////////////////////////////////////
//Function:	SelE_lVer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_lVer==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_lVer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_lVer(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_lVer( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_lVer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_lVer(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_lVer(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_strAffectDateTime
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_strAffectDateTime(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_strAffectDateTime==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_strAffectDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_strAffectDateTime(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_strAffectDateTime( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////
//Function:	SelE1_biDelFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_biDelFlag(wl::tuint8 iVal) 
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
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_biIsAffect(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_biIsAffect( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////
//Function:	SelE1_strStampDateTime
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_strStampDateTime(std::string strVal) 
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

////////////////////////////////////////////////////////
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
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_strDataRef(std::string strVal) 
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

///////////////////////////////////////////////////////////////
//Function:	SelE_MainUiIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MainUiIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_MainUiIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_MainUiIdx(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_MainUiIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_MainUiIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MainUiIdx(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_MainUiPicFn
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MainUiPicFn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MainUiPicFn==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_MainUiPicFn
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_MainUiPicFn(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_MainUiPicFn( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_MainUiPicFn
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MainUiPicFn(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MainUiPicFn(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_MainUiPicWidth
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MainUiPicWidth(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MainUiPicWidth==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_MainUiPicWidth
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_MainUiPicWidth(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_MainUiPicWidth( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_MainUiPicWidth
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MainUiPicWidth(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MainUiPicWidth(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_MainUiPicHeight
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_MainUiPicHeight(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_MainUiPicHeight==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_MainUiPicHeight
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_MainUiPicHeight(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_MainUiPicHeight( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_MainUiPicHeight
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_MainUiPicHeight(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_MainUiPicHeight(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_LaunSeleButtX
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LaunSeleButtX(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LaunSeleButtX==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_LaunSeleButtX
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LaunSeleButtX(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LaunSeleButtX( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_LaunSeleButtX
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LaunSeleButtX(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LaunSeleButtX(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_LaunSeleButtY
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LaunSeleButtY(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LaunSeleButtY==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_LaunSeleButtY
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LaunSeleButtY(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LaunSeleButtY( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_LaunSeleButtY
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LaunSeleButtY(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LaunSeleButtY(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_LaunSeleButtWidth
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LaunSeleButtWidth(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LaunSeleButtWidth==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_LaunSeleButtWidth
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LaunSeleButtWidth(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LaunSeleButtWidth( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_LaunSeleButtWidth
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LaunSeleButtWidth(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LaunSeleButtWidth(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_LaunSeleButtHeight
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LaunSeleButtHeight(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LaunSeleButtHeight==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_LaunSeleButtHeight
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LaunSeleButtHeight(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LaunSeleButtHeight( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_LaunSeleButtHeight
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LaunSeleButtHeight(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LaunSeleButtHeight(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_DirButt1Enable
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1Enable==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_DirButt1Enable
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1Enable(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1Enable( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1Enable
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1Enable(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_DirButt1X
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1X==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_DirButt1X
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1X(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1X( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1X
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1X(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt1Y
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1Y==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt1Y
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1Y(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1Y( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1Y
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1Y(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_DirButt1Width
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1Width==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt1Width
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1Width(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1Width( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1Width
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1Width(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_DirButt1Height
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1Height==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt1Height
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1Height(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1Height( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1Height
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1Height(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_DirButt1MainUiIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt1MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt1MainUiIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_DirButt1MainUiIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt1MainUiIdx(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt1MainUiIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt1MainUiIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt1MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt1MainUiIdx(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_DirButt2Enable
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2Enable==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt2Enable
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2Enable(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2Enable( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2Enable
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2Enable(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_DirButt2X
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2X==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_DirButt2X
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2X(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2X( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2X
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2X(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt2Y
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2Y==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_DirButt2Y
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2Y(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2Y( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2Y
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2Y(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_DirButt2Width
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2Width==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////
//Function:	SelE1_DirButt2Width
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2Width(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2Width( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2Width
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2Width(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt2Height
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2Height==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt2Height
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2Height(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2Height( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2Height
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2Height(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_DirButt2MainUiIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt2MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt2MainUiIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt2MainUiIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt2MainUiIdx(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt2MainUiIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_DirButt2MainUiIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt2MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt2MainUiIdx(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt3Enable
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3Enable==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3Enable
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3Enable(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3Enable( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt3Enable
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3Enable(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_DirButt3X
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3X==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3X
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3X(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3X( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_DirButt3X
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3X(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_DirButt3Y
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3Y==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3Y
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3Y(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3Y( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_DirButt3Y
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3Y(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_DirButt3Width
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3Width==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3Width
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3Width(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3Width( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_DirButt3Width
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3Width(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_DirButt3Height
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3Height==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3Height
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3Height(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3Height( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_DirButt3Height
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3Height(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt3MainUiIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt3MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt3MainUiIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt3MainUiIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt3MainUiIdx(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt3MainUiIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_DirButt3MainUiIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt3MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt3MainUiIdx(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_DirButt4Enable
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4Enable==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4Enable
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4Enable(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4Enable( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4Enable
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4Enable(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4Enable(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_DirButt4X
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4X==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4X
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4X(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4X( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4X
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4X(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4X(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_DirButt4Y
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4Y==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4Y
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4Y(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4Y( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4Y
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4Y(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4Y(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_DirButt4Width
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4Width==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4Width
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4Width(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4Width( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4Width
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4Width(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4Width(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_DirButt4Height
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4Height==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4Height
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4Height(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4Height( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4Height
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4Height(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4Height(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_DirButt4MainUiIdx
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_DirButt4MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_DirButt4MainUiIdx==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_DirButt4MainUiIdx
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_DirButt4MainUiIdx(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_DirButt4MainUiIdx( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_DirButt4MainUiIdx
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_DirButt4MainUiIdx(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_DirButt4MainUiIdx(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////
//Function:	SelE_LineButtNum
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LineButtNum(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LineButtNum==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_LineButtNum
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LineButtNum(long iVal) 
	{
		std::vector<long> vRps ;
		SelE_LineButtNum( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_LineButtNum
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LineButtNum(long iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LineButtNum(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES_02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_02(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_02==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_RES_02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_RES_02(u8arr_t<4> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_02( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_RES_02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_02(u8arr_t<4> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_02(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_LineCode
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_LineCode(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_LineCode==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////////
//Function:	SelE1_LineCode
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_LineCode(uiarr_t<long,16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_LineCode( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_LineCode
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_LineCode(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_LineCode(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a3083_t_rowtype&
	a3083_t_rowtype & SelE1_RES_01(uiarr_t<long,16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_RES_01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_01(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_01(aVal, vRps, pRefRps);
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
//end of class a3083_t


#endif

