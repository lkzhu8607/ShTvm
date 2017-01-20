#ifndef XX1_DEFINE_H
#define XX1_DEFINE_H

#define xx1_u8 			unsigned char
#define xx1_s8 			char
#define xx1_u16 			unsigned short
#define xx1_s16 			short
#define xx1_u32 			unsigned int
#define xx1_s32 			int
#define xx1_u64 			unsigned long long 
#define xx1_s64 			long long
#define xx1_f32  		float

#define RET_SUCC		0
#define RET_FAIL		-1
#define RET_ERR_ARG		-2
#define RET_OTHER		-3
#define RET_TRUE		0
#define RET_FALSE		1

#define	XX1_FILENAME_LEN		100	

#define XX1_BUF_LEN_LEAST	16
#define XX1_BUF_LEN_MINI		32
#define XX1_BUF_LEN_TINY		64
#define XX1_BUF_LEN_SMALL	128
#define XX1_BUF_LEN_LESS		256
#define XX1_BUF_LEN_NORMAL	512
#define XX1_BUF_LEN_BIG		1024
#define XX1_BUF_LEN_LARGE	2048
#define XX1_BUF_LEN_HUGE		4096

#define OP_CHECK_WRITE 0
#define OP_CHECK_CLOSE 1
#define OP_CHECK_TIME 2

#define LIST_MAX_NM 50

#define OP_VID_VID_NO 0
#define OP_VID_VID_OK 1

#define NETBAR_AUTH_COUNT 6000
#define AUTH_TERM "AUTH_TERM"
#endif

