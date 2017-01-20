
#ifndef V1_3AA_LABEL_T_20150115_130616
#define V1_3AA_LABEL_T_20150115_130616

 
///////////////////////////////////////////////////////
//Contents:	The row class type definition of a_label_t
//Name:	a_label_t_rowtype
class a_label_t_rowtype {
 
public:

	int		m_scr;			// 1	0=scr0  1=scr1 
	std::string		m_name;			// 2	unique 
	std::string		m_ds;			// 3	value ds3 
	int		m_iShouldShow;			// 4	should show flag 
	int		m_iNewModiFlag;			// 5	0=new  1=modify 
	std::string		m_type;			// 6	str/pic/del/update/refresh 
	std::string		m_value;			// 7	内容 
	double		m_x;			// 8	x 
	double		m_y;			// 9	y 
	double		m_font_size;			// 10	size 
	std::string		m_font_color;			// 11	color 
	std::string		m_font_desc;			// 12	字体 
	int		m_font_align;			// 13	0=不居中 1=指定中线的居中 
	double		m_pic_width;			// 14	width	如果为0则使用原始大小 
	double		m_pic_height;			// 15	height 
	PVOID_t		m_gtkpointer;			// 16	gtk resouce 
	wl::tuint8		m_RES01;			// 17	[保留] 
	wl::tuint32		m_RES02;			// 18	[保留] 
	u8arr_t<2>		m_RES03;			// 19	[保留] 
	longarr2v_t<7,2>		m_RES04;			// 20	[保留] 
	NaStrarr		m_valuearr;			// 21	value	用map模拟的数组，支持序列化 
	double		m_x2;			// 22	x2 
	double		m_y2;			// 23	y2 
	int		m_hot;			// 24	是1=占位控制  否0=只是显示对象 
	std::string		m_funcname;			// 25	功能名 
	int		m_funcvalue;			// 26	功能值 
	PVOID_t		m_funcpara;			// 27	功能其它参数 
	uiarr_t<long,16>		m_RES_01;			// 28	保留  Long 4 
 
public:

	a_label_t_rowtype()
	{
		m_scr = 0;
		//m_name = //use default
		//m_ds = //use default
		m_iShouldShow = 0;
		m_iNewModiFlag = 0;
		//m_type = //use default
		//m_value = //use default
		m_x = 0;
		m_y = 0;
		m_font_size = 0;
		//m_font_color = //use default
		//m_font_desc = //use default
		m_font_align = 0;
		m_pic_width = 0;
		m_pic_height = 0;
		m_gtkpointer = NULL;
		m_RES01 = 0;
		m_RES02 = 0;
		//m_RES03 = //use default
		wl::SStrf::smemset(m_RES04);
		//m_valuearr = //use default
		m_x2 = 0;
		m_y2 = 0;
		m_hot = 0;
		//m_funcname = //use default
		m_funcvalue = 0;
		m_funcpara = NULL;
		//m_RES_01 = //use default
	}

	virtual ~a_label_t_rowtype(){;}
	

	//operator == 
	bool operator == (const a_label_t_rowtype & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a_label_t_rowtype & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a_label_t_rowtype & rhs) const
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_scr));
		len1 = sizeof(m_scr);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_name.c_str();
		len1 = (long)(m_name.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_ds.c_str();
		len1 = (long)(m_ds.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iShouldShow));
		len1 = sizeof(m_iShouldShow);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iNewModiFlag));
		len1 = sizeof(m_iNewModiFlag);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_type.c_str();
		len1 = (long)(m_type.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_value.c_str();
		len1 = (long)(m_value.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_x));
		len1 = sizeof(m_x);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_y));
		len1 = sizeof(m_y);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_font_size));
		len1 = sizeof(m_font_size);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_font_color.c_str();
		len1 = (long)(m_font_color.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_font_desc.c_str();
		len1 = (long)(m_font_desc.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_font_align));
		len1 = sizeof(m_font_align);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_pic_width));
		len1 = sizeof(m_pic_width);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_pic_height));
		len1 = sizeof(m_pic_height);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_gtkpointer));
		len1 = sizeof(m_gtkpointer);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04));
		len1 = sizeof(m_RES04);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_valuearr.serialize_hold_addr();
		len1 = m_valuearr.serialize_hold_len();
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_x2));
		len1 = sizeof(m_x2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_y2));
		len1 = sizeof(m_y2);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_hot));
		len1 = sizeof(m_hot);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)m_funcname.c_str();
		len1 = (long)(m_funcname.length()*sizeof(char)+sizeof(char));
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_funcvalue));
		len1 = sizeof(m_funcvalue);
		if( (int)v.size() < ( len1 * 2 + 4 ) ) v.resize( len1 * 2 + 4 );
		buf2 = (char*)(&(v[0]));
		en( buf1, len1, buf2 );
		strOut += std::string(buf2);
		strOut += std::string("/");
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_funcpara));
		len1 = sizeof(m_funcpara);
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

	a_label_t_rowtype & Unserialize( const char * strIn )
	{
		const char *buf1;
		char *buf2;
		buf1 = strIn;
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_scr = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_name = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_ds = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iShouldShow = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_iNewModiFlag = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_type = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_value = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_x = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_y = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_font_size = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_font_color = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_font_desc = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_font_align = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_pic_width = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_pic_height = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_gtkpointer = decode2<PVOID_t>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES01 = decode2<wl::tuint8>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES02 = decode2<tuint32>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES03 = *(u8arr_t<2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_RES04 = *(longarr2v_t<7,2>*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_valuearr.unserialize((char*)buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_x2 = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_y2 = decode2<double>(buf2); }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_hot = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_funcname = (char*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_funcvalue = *(int*)buf2; }else return *this; 
		buf2 = (char*)buf1;
		 if( *buf2!='}') {buf1 = de( buf2 );  
		 /*if( *buf2!='}')*/ m_funcpara = decode2<PVOID_t>(buf2); }else return *this; 
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_scr));
		len1 = sizeof(m_scr);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_name.c_str();
		len1 = (long)(m_name.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_ds.c_str();
		len1 = (long)(m_ds.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iShouldShow));
		len1 = sizeof(m_iShouldShow);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_iNewModiFlag));
		len1 = sizeof(m_iNewModiFlag);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_type.c_str();
		len1 = (long)(m_type.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_value.c_str();
		len1 = (long)(m_value.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_x));
		len1 = sizeof(m_x);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_y));
		len1 = sizeof(m_y);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_font_size));
		len1 = sizeof(m_font_size);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_font_color.c_str();
		len1 = (long)(m_font_color.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_font_desc.c_str();
		len1 = (long)(m_font_desc.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_font_align));
		len1 = sizeof(m_font_align);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_pic_width));
		len1 = sizeof(m_pic_width);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_pic_height));
		len1 = sizeof(m_pic_height);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_gtkpointer));
		len1 = sizeof(m_gtkpointer);
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
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES04));
		len1 = sizeof(m_RES04);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_valuearr.serialize_hold_addr();
		len1 = m_valuearr.serialize_hold_len();
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_x2));
		len1 = sizeof(m_x2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_y2));
		len1 = sizeof(m_y2);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_hot));
		len1 = sizeof(m_hot);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)m_funcname.c_str();
		len1 = (long)(m_funcname.length()*sizeof(char)+sizeof(char));
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_funcvalue));
		len1 = sizeof(m_funcvalue);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_funcpara));
		len1 = sizeof(m_funcpara);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		buf1 = (const char *)reinterpret_cast<char *>(&reinterpret_cast<char&>(m_RES_01));
		len1 = sizeof(m_RES_01);
		ckl.add( wl::SCake( (wl::tchar*)&len1, 4 ) );
		ckl.add( wl::SCake( buf1, len1 ) );
		ckl.collectb();
		return ckOut=*ckl.get0();
	}

	a_label_t_rowtype & Unserialize( wl::tchar * p_begin, wl::tchar ** pp_end )
	{
		char *buf1 = p_begin;
		char *buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_scr = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_name = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_ds = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iShouldShow = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_iNewModiFlag = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_type = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_value = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_x = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_y = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_font_size = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_font_color = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_font_desc = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_font_align = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_pic_width = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_pic_height = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_gtkpointer = decode2<PVOID_t>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES01 = decode2<wl::tuint8>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES02 = decode2<tuint32>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES03 = *(u8arr_t<2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES04 = *(longarr2v_t<7,2>*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_valuearr = buf2COL.unserialize((char*)buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_x2 = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_y2 = decode2<double>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_hot = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_funcname = (char*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_funcvalue = *(int*)buf2;
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_funcpara = decode2<PVOID_t>(buf2);
		buf2 = (char*)buf1 + 4;
		buf1 = buf2 + *(wl::tuint32*)buf1;
		m_RES_01 = *(uiarr_t<long,16>*)buf2;
		*pp_end = buf1;
		return *this;
	}

	 
#endif

 
public:

/////////////////////////////////////////////////////////////
//Function:	GetCol_scr
//Effect:	get ref of col. col is scr
//Return:	int & 
	int & GetCol_scr(void)
	{
		return m_scr;
	}

/////////////////////////////////////////////////////////
//Function:	GetCol_name
//Effect:	get ref of col. col is name
//Return:	std::string & 
	std::string & GetCol_name(void)
	{
		return m_name;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_ds
//Effect:	get ref of col. col is ds
//Return:	std::string & 
	std::string & GetCol_ds(void)
	{
		return m_ds;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_iShouldShow
//Effect:	get ref of col. col is iShouldShow
//Return:	int & 
	int & GetCol_iShouldShow(void)
	{
		return m_iShouldShow;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_iNewModiFlag
//Effect:	get ref of col. col is iNewModiFlag
//Return:	int & 
	int & GetCol_iNewModiFlag(void)
	{
		return m_iNewModiFlag;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_type
//Effect:	get ref of col. col is type
//Return:	std::string & 
	std::string & GetCol_type(void)
	{
		return m_type;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_value
//Effect:	get ref of col. col is value
//Return:	std::string & 
	std::string & GetCol_value(void)
	{
		return m_value;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_x
//Effect:	get ref of col. col is x
//Return:	double & 
	double & GetCol_x(void)
	{
		return m_x;
	}

///////////////////////////////////////////////////////////////
//Function:	GetCol_y
//Effect:	get ref of col. col is y
//Return:	double & 
	double & GetCol_y(void)
	{
		return m_y;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_font_size
//Effect:	get ref of col. col is font_size
//Return:	double & 
	double & GetCol_font_size(void)
	{
		return m_font_size;
	}

////////////////////////////////////////////////////////////////
//Function:	GetCol_font_color
//Effect:	get ref of col. col is font_color
//Return:	std::string & 
	std::string & GetCol_font_color(void)
	{
		return m_font_color;
	}

//////////////////////////////////////////////////////////////
//Function:	GetCol_font_desc
//Effect:	get ref of col. col is font_desc
//Return:	std::string & 
	std::string & GetCol_font_desc(void)
	{
		return m_font_desc;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_font_align
//Effect:	get ref of col. col is font_align
//Return:	int & 
	int & GetCol_font_align(void)
	{
		return m_font_align;
	}

//////////////////////////////////////////////////////////
//Function:	GetCol_pic_width
//Effect:	get ref of col. col is pic_width
//Return:	double & 
	double & GetCol_pic_width(void)
	{
		return m_pic_width;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_pic_height
//Effect:	get ref of col. col is pic_height
//Return:	double & 
	double & GetCol_pic_height(void)
	{
		return m_pic_height;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_gtkpointer
//Effect:	get ref of col. col is gtkpointer
//Return:	PVOID_t & 
	PVOID_t & GetCol_gtkpointer(void)
	{
		return m_gtkpointer;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_RES01
//Effect:	get ref of col. col is RES01
//Return:	wl::tuint8 & 
	wl::tuint8 & GetCol_RES01(void)
	{
		return m_RES01;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES02
//Effect:	get ref of col. col is RES02
//Return:	wl::tuint32 & 
	wl::tuint32 & GetCol_RES02(void)
	{
		return m_RES02;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_RES03
//Effect:	get ref of col. col is RES03
//Return:	u8arr_t<2> & 
	u8arr_t<2> & GetCol_RES03(void)
	{
		return m_RES03;
	}

/////////////////////////////////////////////////////////////////
//Function:	GetCol_RES04
//Effect:	get ref of col. col is RES04
//Return:	longarr2v_t<7,2> & 
	longarr2v_t<7,2> & GetCol_RES04(void)
	{
		return m_RES04;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_valuearr
//Effect:	get ref of col. col is valuearr
//Return:	NaStrarr & 
	NaStrarr & GetCol_valuearr(void)
	{
		return m_valuearr;
	}

////////////////////////////////////////////////////////
//Function:	GetCol_x2
//Effect:	get ref of col. col is x2
//Return:	double & 
	double & GetCol_x2(void)
	{
		return m_x2;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_y2
//Effect:	get ref of col. col is y2
//Return:	double & 
	double & GetCol_y2(void)
	{
		return m_y2;
	}

///////////////////////////////////////////////////////
//Function:	GetCol_hot
//Effect:	get ref of col. col is hot
//Return:	int & 
	int & GetCol_hot(void)
	{
		return m_hot;
	}

///////////////////////////////////////////////////////////
//Function:	GetCol_funcname
//Effect:	get ref of col. col is funcname
//Return:	std::string & 
	std::string & GetCol_funcname(void)
	{
		return m_funcname;
	}

////////////////////////////////////////////////////////////
//Function:	GetCol_funcvalue
//Effect:	get ref of col. col is funcvalue
//Return:	int & 
	int & GetCol_funcvalue(void)
	{
		return m_funcvalue;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_funcpara
//Effect:	get ref of col. col is funcpara
//Return:	PVOID_t & 
	PVOID_t & GetCol_funcpara(void)
	{
		return m_funcpara;
	}

/////////////////////////////////////////////////////////////
//Function:	GetCol_RES_01
//Effect:	get ref of col. col is RES_01
//Return:	uiarr_t<long,16> & 
	uiarr_t<long,16> & GetCol_RES_01(void)
	{
		return m_RES_01;
	}

 
public:

/////////////////////////////////////////////////////////////
//Function:	GetColAmount
//Effect:	get column amount
//Return:	return the column amount, int.
	int GetColAmount() 
	{
		return 28;
	}

////////////////////////////////////////////////////////
//Function:	GetColName
//Effect:	get column name, input col number base on 0.
//Return:	return col's name in string format.
	std::string GetColName( int iColNum )
	{
		if( iColNum == 0 )
		{
			return "scr";
		}
		if( iColNum == 1 )
		{
			return "name";
		}
		if( iColNum == 2 )
		{
			return "ds";
		}
		if( iColNum == 3 )
		{
			return "iShouldShow";
		}
		if( iColNum == 4 )
		{
			return "iNewModiFlag";
		}
		if( iColNum == 5 )
		{
			return "type";
		}
		if( iColNum == 6 )
		{
			return "value";
		}
		if( iColNum == 7 )
		{
			return "x";
		}
		if( iColNum == 8 )
		{
			return "y";
		}
		if( iColNum == 9 )
		{
			return "font_size";
		}
		if( iColNum == 10 )
		{
			return "font_color";
		}
		if( iColNum == 11 )
		{
			return "font_desc";
		}
		if( iColNum == 12 )
		{
			return "font_align";
		}
		if( iColNum == 13 )
		{
			return "pic_width";
		}
		if( iColNum == 14 )
		{
			return "pic_height";
		}
		if( iColNum == 15 )
		{
			return "gtkpointer";
		}
		if( iColNum == 16 )
		{
			return "RES01";
		}
		if( iColNum == 17 )
		{
			return "RES02";
		}
		if( iColNum == 18 )
		{
			return "RES03";
		}
		if( iColNum == 19 )
		{
			return "RES04";
		}
		if( iColNum == 20 )
		{
			return "valuearr";
		}
		if( iColNum == 21 )
		{
			return "x2";
		}
		if( iColNum == 22 )
		{
			return "y2";
		}
		if( iColNum == 23 )
		{
			return "hot";
		}
		if( iColNum == 24 )
		{
			return "funcname";
		}
		if( iColNum == 25 )
		{
			return "funcvalue";
		}
		if( iColNum == 26 )
		{
			return "funcpara";
		}
		if( iColNum == 27 )
		{
			return "RES_01";
		}
		return "";
	}

//////////////////////////////////////////////////////////////
//Function:	GetColNumber
//Effect:	input col name, get col number
//Return:	return the column number, int.
	int GetColNumber( std::string strColName ) 
	{
		if( strColName == "scr" )
		{
			return 0;
		}
		if( strColName == "name" )
		{
			return 1;
		}
		if( strColName == "ds" )
		{
			return 2;
		}
		if( strColName == "iShouldShow" )
		{
			return 3;
		}
		if( strColName == "iNewModiFlag" )
		{
			return 4;
		}
		if( strColName == "type" )
		{
			return 5;
		}
		if( strColName == "value" )
		{
			return 6;
		}
		if( strColName == "x" )
		{
			return 7;
		}
		if( strColName == "y" )
		{
			return 8;
		}
		if( strColName == "font_size" )
		{
			return 9;
		}
		if( strColName == "font_color" )
		{
			return 10;
		}
		if( strColName == "font_desc" )
		{
			return 11;
		}
		if( strColName == "font_align" )
		{
			return 12;
		}
		if( strColName == "pic_width" )
		{
			return 13;
		}
		if( strColName == "pic_height" )
		{
			return 14;
		}
		if( strColName == "gtkpointer" )
		{
			return 15;
		}
		if( strColName == "RES01" )
		{
			return 16;
		}
		if( strColName == "RES02" )
		{
			return 17;
		}
		if( strColName == "RES03" )
		{
			return 18;
		}
		if( strColName == "RES04" )
		{
			return 19;
		}
		if( strColName == "valuearr" )
		{
			return 20;
		}
		if( strColName == "x2" )
		{
			return 21;
		}
		if( strColName == "y2" )
		{
			return 22;
		}
		if( strColName == "hot" )
		{
			return 23;
		}
		if( strColName == "funcname" )
		{
			return 24;
		}
		if( strColName == "funcvalue" )
		{
			return 25;
		}
		if( strColName == "funcpara" )
		{
			return 26;
		}
		if( strColName == "RES_01" )
		{
			return 27;
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
			return wl::SStrf::sltoa(m_scr);
		}
		if( iColNum == 1 )
		{
			return m_name;
		}
		if( iColNum == 2 )
		{
			return m_ds;
		}
		if( iColNum == 3 )
		{
			return wl::SStrf::sltoa(m_iShouldShow);
		}
		if( iColNum == 4 )
		{
			return wl::SStrf::sltoa(m_iNewModiFlag);
		}
		if( iColNum == 5 )
		{
			return m_type;
		}
		if( iColNum == 6 )
		{
			return m_value;
		}
		if( iColNum == 7 )
		{
			return wl::SStrf::sftoa(m_x);
		}
		if( iColNum == 8 )
		{
			return wl::SStrf::sftoa(m_y);
		}
		if( iColNum == 9 )
		{
			return wl::SStrf::sftoa(m_font_size);
		}
		if( iColNum == 10 )
		{
			return m_font_color;
		}
		if( iColNum == 11 )
		{
			return m_font_desc;
		}
		if( iColNum == 12 )
		{
			return wl::SStrf::sltoa(m_font_align);
		}
		if( iColNum == 13 )
		{
			return wl::SStrf::sftoa(m_pic_width);
		}
		if( iColNum == 14 )
		{
			return wl::SStrf::sftoa(m_pic_height);
		}
		if( iColNum == 15 )
		{
			return wl::SStrf::b2s(m_gtkpointer);
		}
		if( iColNum == 16 )
		{
			return wl::SStrf::sltoa(m_RES01);
		}
		if( iColNum == 17 )
		{
			return wl::SStrf::sultoa(m_RES02);
		}
		if( iColNum == 18 )
		{
			return wl::SStrf::b2s(m_RES03);
		}
		if( iColNum == 19 )
		{
			return wl::SStrf::b2s(m_RES04);
		}
		if( iColNum == 20 )
		{
			return m_valuearr.serialize();
		}
		if( iColNum == 21 )
		{
			return wl::SStrf::sftoa(m_x2);
		}
		if( iColNum == 22 )
		{
			return wl::SStrf::sftoa(m_y2);
		}
		if( iColNum == 23 )
		{
			return wl::SStrf::sltoa(m_hot);
		}
		if( iColNum == 24 )
		{
			return m_funcname;
		}
		if( iColNum == 25 )
		{
			return wl::SStrf::sltoa(m_funcvalue);
		}
		if( iColNum == 26 )
		{
			return wl::SStrf::b2s(m_funcpara);
		}
		if( iColNum == 27 )
		{
			return wl::SStrf::b2s(m_RES_01);
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
		if( strColName == "scr" )
		{
			return GetColStr<STRINGT>(0);
		}
		if( strColName == "name" )
		{
			return GetColStr<STRINGT>(1);
		}
		if( strColName == "ds" )
		{
			return GetColStr<STRINGT>(2);
		}
		if( strColName == "iShouldShow" )
		{
			return GetColStr<STRINGT>(3);
		}
		if( strColName == "iNewModiFlag" )
		{
			return GetColStr<STRINGT>(4);
		}
		if( strColName == "type" )
		{
			return GetColStr<STRINGT>(5);
		}
		if( strColName == "value" )
		{
			return GetColStr<STRINGT>(6);
		}
		if( strColName == "x" )
		{
			return GetColStr<STRINGT>(7);
		}
		if( strColName == "y" )
		{
			return GetColStr<STRINGT>(8);
		}
		if( strColName == "font_size" )
		{
			return GetColStr<STRINGT>(9);
		}
		if( strColName == "font_color" )
		{
			return GetColStr<STRINGT>(10);
		}
		if( strColName == "font_desc" )
		{
			return GetColStr<STRINGT>(11);
		}
		if( strColName == "font_align" )
		{
			return GetColStr<STRINGT>(12);
		}
		if( strColName == "pic_width" )
		{
			return GetColStr<STRINGT>(13);
		}
		if( strColName == "pic_height" )
		{
			return GetColStr<STRINGT>(14);
		}
		if( strColName == "gtkpointer" )
		{
			return GetColStr<STRINGT>(15);
		}
		if( strColName == "RES01" )
		{
			return GetColStr<STRINGT>(16);
		}
		if( strColName == "RES02" )
		{
			return GetColStr<STRINGT>(17);
		}
		if( strColName == "RES03" )
		{
			return GetColStr<STRINGT>(18);
		}
		if( strColName == "RES04" )
		{
			return GetColStr<STRINGT>(19);
		}
		if( strColName == "valuearr" )
		{
			return GetColStr<STRINGT>(20);
		}
		if( strColName == "x2" )
		{
			return GetColStr<STRINGT>(21);
		}
		if( strColName == "y2" )
		{
			return GetColStr<STRINGT>(22);
		}
		if( strColName == "hot" )
		{
			return GetColStr<STRINGT>(23);
		}
		if( strColName == "funcname" )
		{
			return GetColStr<STRINGT>(24);
		}
		if( strColName == "funcvalue" )
		{
			return GetColStr<STRINGT>(25);
		}
		if( strColName == "funcpara" )
		{
			return GetColStr<STRINGT>(26);
		}
		if( strColName == "RES_01" )
		{
			return GetColStr<STRINGT>(27);
		}
		return GetColStr<STRINGT>(0);
	}

	template<class STRINGT>
	STRINGT& GetColStr( std::string strColName, STRINGT & sBuf ) { return sBuf = GetColStr<STRINGT>(strColName); }

///////////////////////////////////////////////////////
//Function:	SetColVal
//Effect:	set column value, input col number base on 0, and input value in string format.
//Return:	no return.
	template<class STRINGT>
	void SetColVal( int iColNum, STRINGT strValPARA )
	{
		if( iColNum == 0 )
		{
			m_scr=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 1 )
		{
			m_name=strValPARA;
		}
		if( iColNum == 2 )
		{
			m_ds=strValPARA;
		}
		if( iColNum == 3 )
		{
			m_iShouldShow=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 4 )
		{
			m_iNewModiFlag=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 5 )
		{
			m_type=strValPARA;
		}
		if( iColNum == 6 )
		{
			m_value=strValPARA;
		}
		if( iColNum == 7 )
		{
			m_x=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 8 )
		{
			m_y=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 9 )
		{
			m_font_size=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 10 )
		{
			m_font_color=strValPARA;
		}
		if( iColNum == 11 )
		{
			m_font_desc=strValPARA;
		}
		if( iColNum == 12 )
		{
			m_font_align=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 13 )
		{
			m_pic_width=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 14 )
		{
			m_pic_height=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 15 )
		{
			wl::SStrf::s2b(strValPARA,m_gtkpointer);
		}
		if( iColNum == 16 )
		{
			m_RES01=(wl::tuint8)wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 17 )
		{
			m_RES02=wl::SStrf::satoul(strValPARA);
		}
		if( iColNum == 18 )
		{
			wl::SStrf::s2b(strValPARA,m_RES03);
		}
		if( iColNum == 19 )
		{
			wl::SStrf::s2b(strValPARA,m_RES04);
		}
		if( iColNum == 20 )
		{
			m_valuearr.unserialize(strValPARA);
		}
		if( iColNum == 21 )
		{
			m_x2=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 22 )
		{
			m_y2=wl::SStrf::satof(strValPARA);
		}
		if( iColNum == 23 )
		{
			m_hot=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 24 )
		{
			m_funcname=strValPARA;
		}
		if( iColNum == 25 )
		{
			m_funcvalue=wl::SStrf::satol(strValPARA);
		}
		if( iColNum == 26 )
		{
			wl::SStrf::s2b(strValPARA,m_funcpara);
		}
		if( iColNum == 27 )
		{
			wl::SStrf::s2b(strValPARA,m_RES_01);
		}
	}

/////////////////////////////////////////////////////////////
//Function:	SetColVal
//Effect:	set column value, input col number base on 0, and input value in string format.
//Return:	no return.
	template<class STRINGT>
	void SetColVal( std::string strColName, STRINGT strValPARA )
	{
		if( strColName == "scr" )
		{
			SetColVal<STRINGT>(0,strValPARA);
		}
		if( strColName == "name" )
		{
			SetColVal<STRINGT>(1,strValPARA);
		}
		if( strColName == "ds" )
		{
			SetColVal<STRINGT>(2,strValPARA);
		}
		if( strColName == "iShouldShow" )
		{
			SetColVal<STRINGT>(3,strValPARA);
		}
		if( strColName == "iNewModiFlag" )
		{
			SetColVal<STRINGT>(4,strValPARA);
		}
		if( strColName == "type" )
		{
			SetColVal<STRINGT>(5,strValPARA);
		}
		if( strColName == "value" )
		{
			SetColVal<STRINGT>(6,strValPARA);
		}
		if( strColName == "x" )
		{
			SetColVal<STRINGT>(7,strValPARA);
		}
		if( strColName == "y" )
		{
			SetColVal<STRINGT>(8,strValPARA);
		}
		if( strColName == "font_size" )
		{
			SetColVal<STRINGT>(9,strValPARA);
		}
		if( strColName == "font_color" )
		{
			SetColVal<STRINGT>(10,strValPARA);
		}
		if( strColName == "font_desc" )
		{
			SetColVal<STRINGT>(11,strValPARA);
		}
		if( strColName == "font_align" )
		{
			SetColVal<STRINGT>(12,strValPARA);
		}
		if( strColName == "pic_width" )
		{
			SetColVal<STRINGT>(13,strValPARA);
		}
		if( strColName == "pic_height" )
		{
			SetColVal<STRINGT>(14,strValPARA);
		}
		if( strColName == "gtkpointer" )
		{
			SetColVal<STRINGT>(15,strValPARA);
		}
		if( strColName == "RES01" )
		{
			SetColVal<STRINGT>(16,strValPARA);
		}
		if( strColName == "RES02" )
		{
			SetColVal<STRINGT>(17,strValPARA);
		}
		if( strColName == "RES03" )
		{
			SetColVal<STRINGT>(18,strValPARA);
		}
		if( strColName == "RES04" )
		{
			SetColVal<STRINGT>(19,strValPARA);
		}
		if( strColName == "valuearr" )
		{
			SetColVal<STRINGT>(20,strValPARA);
		}
		if( strColName == "x2" )
		{
			SetColVal<STRINGT>(21,strValPARA);
		}
		if( strColName == "y2" )
		{
			SetColVal<STRINGT>(22,strValPARA);
		}
		if( strColName == "hot" )
		{
			SetColVal<STRINGT>(23,strValPARA);
		}
		if( strColName == "funcname" )
		{
			SetColVal<STRINGT>(24,strValPARA);
		}
		if( strColName == "funcvalue" )
		{
			SetColVal<STRINGT>(25,strValPARA);
		}
		if( strColName == "funcpara" )
		{
			SetColVal<STRINGT>(26,strValPARA);
		}
		if( strColName == "RES_01" )
		{
			SetColVal<STRINGT>(27,strValPARA);
		}
	}

}
; 
//end of class a_label_t_rowtype
 
 
///////////////////////////////////////////////////////
//Contents:	The tbl class type definition
//Name:	a_label_t
class a_label_t {
 
private:

	a_label_t_rowtype m_EmptyRow;
	std::vector<a_label_t_rowtype>  m_DATAcorpora;
 
public:

	typedef a_label_t_rowtype 	ROWTYPE;
	typedef std::vector<long> 	RPSTYPE; //RPS(return pointer set) type definition
	typedef std::vector<a_label_t_rowtype>::iterator 	TBLITTYPE;
 
public:

	a_label_t()
	{
	}

	virtual ~a_label_t(){;}
	

	//operator == 
	bool operator == (const a_label_t & rhs) const
	{
		return this == &rhs;
	}

	//operator > 
	bool operator > (const a_label_t & rhs) const
	{
		return this > &rhs;
	}

	//operator < 
	bool operator < (const a_label_t & rhs) const
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

	a_label_t &  Unserialize( const char * strIn , int biAppend = 0 ) //if append==0, it would over-write the current tbl. 
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

	a_label_t & Unserialize( wl::SCake & ckIn , int biAppend = 0 )
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

////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & GetRow(long lRowNum)
	{
		if(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())
		return m_DATAcorpora[lRowNum];
		else 
		{
			a_label_t_rowtype tmpEmptyrow;
			m_EmptyRow = tmpEmptyrow;
			return m_EmptyRow;
		}
	}

//////////////////////////////////////////////////////////////
//Function:	GetRow
//Effect:	get one appointed row within RPS
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & GetRow(const std::vector<long> & vRps, long lRowNum)
	{
		long ltmp;
		do{
		{
			a_label_t_rowtype tmpEmptyrow;
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
//Effect:	add one appointed row and build the indexes
//Return:	no return
	void Add(const a_label_t_rowtype & varRow)
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

////////////////////////////////////////////////////////////
//Function:	DelInternal
//Effect:	Internally del one appointed row number
//Return:	no return
	void DelInternal( long lRowNum )
	{
		if(!(lRowNum>=0&&lRowNum<(long)m_DATAcorpora.size())) return;
		m_DATAcorpora.erase( m_DATAcorpora.begin()+lRowNum);
	}

////////////////////////////////////////////////////////
//Function:	Del
//Effect:	Del one appointed row number. Rebuild indexes, if any.
//Return:	no return
	void Del( long lRowNum )
	{
		a_label_t * p = new a_label_t;
		*p = *this;
		p->DelInternal(lRowNum);
		Clear();
		for( long i = 0; i < p->GetRowCount(); i++ ) Add( p->GetRow(i) );
		delete p;
	}

////////////////////////////////////////////////////////////
//Function:	SelE_scr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_scr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_scr==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_scr
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_scr(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_scr( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_scr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_scr(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_scr(iVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_name
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_name(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_name==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_name
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_name(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_name( strVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_name
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_name(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_name(strVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_ds
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_ds(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_ds==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_ds
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_ds(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_ds( strVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_ds
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_ds(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_ds(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_iShouldShow
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iShouldShow(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iShouldShow==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////
//Function:	SelE1_iShouldShow
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_iShouldShow(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iShouldShow( iVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_iShouldShow
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iShouldShow(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iShouldShow(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_iNewModiFlag
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_iNewModiFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_iNewModiFlag==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_iNewModiFlag
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_iNewModiFlag(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_iNewModiFlag( iVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_iNewModiFlag
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_iNewModiFlag(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_iNewModiFlag(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_type
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_type(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_type==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_type
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_type(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_type( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////
//Function:	SelEc_type
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_type(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_type(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_value
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_value(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_value==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_value
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_value(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_value( strVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_value
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_value(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_value(strVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_x
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_x(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_x==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_x
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_x(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_x( dVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_x
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_x(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_x(dVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_y
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_y(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_y==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_y
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_y(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_y( dVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_y
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_y(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_y(dVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////
//Function:	SelE_font_size
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_font_size(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_font_size==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_font_size
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_font_size(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_font_size( dVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_font_size
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_font_size(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_font_size(dVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_font_color
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_font_color(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_font_color==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_font_color
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_font_color(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_font_color( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_font_color
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_font_color(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_font_color(strVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_font_desc
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_font_desc(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_font_desc==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_font_desc
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_font_desc(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_font_desc( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_font_desc
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_font_desc(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_font_desc(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////////
//Function:	SelE_font_align
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_font_align(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_font_align==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_font_align
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_font_align(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_font_align( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_font_align
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_font_align(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_font_align(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////
//Function:	SelE_pic_width
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_pic_width(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_pic_width==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_pic_width
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_pic_width(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_pic_width( dVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_pic_width
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_pic_width(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_pic_width(dVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_pic_height
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_pic_height(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_pic_height==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_pic_height
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_pic_height(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_pic_height( dVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_pic_height
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_pic_height(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_pic_height(dVal, vRps, pRefRps);
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE_gtkpointer
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_gtkpointer(PVOID_t pVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_gtkpointer==pVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_gtkpointer
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_gtkpointer(PVOID_t pVal) 
	{
		std::vector<long> vRps ;
		SelE_gtkpointer( pVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_gtkpointer
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_gtkpointer(PVOID_t pVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_gtkpointer(pVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES01==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_RES01(wl::tuint8 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES01( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES01(wl::tuint8 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES01(iVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////
//Function:	SelE_RES02
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES02(wl::tuint32 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES02==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES02
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_RES02(wl::tuint32 iVal) 
	{
		std::vector<long> vRps ;
		SelE_RES02( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_RES02
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES02(wl::tuint32 iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES02(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_RES03
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES03(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES03==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelE1_RES03
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_RES03(u8arr_t<2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES03( aVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////
//Function:	SelEc_RES03
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES03(u8arr_t<2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES03(aVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_RES04
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES04(longarr2v_t<7,2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES04==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////////
//Function:	SelE1_RES04
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_RES04(longarr2v_t<7,2> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES04( aVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////
//Function:	SelEc_RES04
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES04(longarr2v_t<7,2> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES04(aVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_valuearr
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_valuearr(NaStrarr aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_valuearr==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////
//Function:	SelE1_valuearr
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_valuearr(NaStrarr aVal) 
	{
		std::vector<long> vRps ;
		SelE_valuearr( aVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////////
//Function:	SelEc_valuearr
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_valuearr(NaStrarr aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_valuearr(aVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_x2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_x2(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_x2==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_x2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_x2(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_x2( dVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////////
//Function:	SelEc_x2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_x2(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_x2(dVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////////
//Function:	SelE_y2
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_y2(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_y2==dVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

/////////////////////////////////////////////////////////////
//Function:	SelE1_y2
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_y2(double dVal) 
	{
		std::vector<long> vRps ;
		SelE_y2( dVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////
//Function:	SelEc_y2
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_y2(double dVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_y2(dVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_hot
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_hot(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_hot==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_hot
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_hot(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_hot( iVal, vRps );
		return GetRow( vRps, 0 );
	}

////////////////////////////////////////////////////////////
//Function:	SelEc_hot
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_hot(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_hot(iVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////
//Function:	SelE_funcname
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_funcname(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_funcname==strVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////////
//Function:	SelE1_funcname
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_funcname(std::string strVal) 
	{
		std::vector<long> vRps ;
		SelE_funcname( strVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////////
//Function:	SelEc_funcname
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_funcname(std::string strVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_funcname(strVal, vRps, pRefRps);
	}

///////////////////////////////////////////////////////////
//Function:	SelE_funcvalue
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_funcvalue(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_funcvalue==iVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

//////////////////////////////////////////////////////////
//Function:	SelE1_funcvalue
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_funcvalue(int iVal) 
	{
		std::vector<long> vRps ;
		SelE_funcvalue( iVal, vRps );
		return GetRow( vRps, 0 );
	}

/////////////////////////////////////////////////////////////
//Function:	SelEc_funcvalue
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_funcvalue(int iVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_funcvalue(iVal, vRps, pRefRps);
	}

//////////////////////////////////////////////////////////////
//Function:	SelE_funcpara
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_funcpara(PVOID_t pVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_funcpara==pVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

///////////////////////////////////////////////////////////////
//Function:	SelE1_funcpara
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_funcpara(PVOID_t pVal) 
	{
		std::vector<long> vRps ;
		SelE_funcpara( pVal, vRps );
		return GetRow( vRps, 0 );
	}

//////////////////////////////////////////////////////////////
//Function:	SelEc_funcpara
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_funcpara(PVOID_t pVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_funcpara(pVal, vRps, pRefRps);
	}

////////////////////////////////////////////////////////////
//Function:	SelE_RES_01
//Effect:	select and build RPS where col=val use traverse
//Return:	no return
	void SelE_RES_01(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //(ni)
	{
		for(long ltmp=0;ltmp<(long)m_DATAcorpora.size();ltmp++)
		if(m_DATAcorpora[ltmp].m_RES_01==aVal)
		if( !pRefRps || !pRefRps->empty() && std::binary_search( pRefRps->begin(), pRefRps->end(), ltmp ) ) vRps.push_back( ltmp );
	}

////////////////////////////////////////////////////////
//Function:	SelE1_RES_01
//Effect:	select 1st row where col=val, or return default row.
//Return:	a_label_t_rowtype&
	a_label_t_rowtype & SelE1_RES_01(uiarr_t<long,16> aVal) 
	{
		std::vector<long> vRps ;
		SelE_RES_01( aVal, vRps );
		return GetRow( vRps, 0 );
	}

///////////////////////////////////////////////////////////
//Function:	SelEc_RES_01
//Effect:	select and build RPS where col=val. clear rps first.
//Return:	no return
	void SelEc_RES_01(uiarr_t<long,16> aVal, std::vector<long> & vRps, std::vector<long> * pRefRps=NULL) //()
	{
		vRps.clear();
		SelE_RES_01(aVal, vRps, pRefRps);
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
//end of class a_label_t


#endif

