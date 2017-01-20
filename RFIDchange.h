#ifndef RFIDchange_H_  
#define RFIDchange_H_  
 
#include <stdio.h> 
#include <string>
using namespace std;

struct F_rfidBoxInfo{
	int BoxState;//钱箱状态:0x01在库中,0x02钱箱已出库,但尚未被安装到TVM上,0x03表示钱箱已经安装到TVM上并且正在运营,0x04在维护中
	int LineID;
	int StationID;
	int err;
	int Denomination;
	int Number;
	long Count;
};

class RFIDrwModle
{
public: 
    RFIDrwModle(void)
	{}
	/*通用应答：
	0 正常
	-1 串口未打开
	-2 通讯故障
	-3 通讯超时
	-4 发送数据校验错误
	*/
	//纸币识别器状态
	std::string rfidVer;
	F_rfidBoxInfo BoxInfoList[3];
	int RWerror[7];
	/*读写错误
	0 读取Block出错
	1 写入Block出错
	2 通道参数出错
	3 卡认证出错
	4 选卡出错
	5 非法Block地址
	6 寻卡出错*/

	/*打开串口，iPortNum串口号
	应答：
	0 正常
	-1 失败*/
	int OpenCom();


	/*关闭串口
	应答：
	0 正常
	-1 失败*/
	int CloseCom();


	/*状态查询
	应答：
	0 正常*/
	int GetState();


	/*通讯测试
	应答：
	0 正常*/
	int BoxTest(int vBoxNum);


	/*读钱箱信息
	应答：
	0 正常*/
	int BoxRead(int vBoxNum);


	/*写钱箱信息
	应答：
	0 正常
	1 没有做读取命令
	参数：
	vDenomination纸币面额
	vNumber纸币张数
	vCount钱箱内金额（找零箱金额=面额×张数，只有废币箱是需要另外累加的）
	*/
	int BoxWrite(int vBoxNum,int vDenomination,int vNumber,int vCount);


	/*装载钱箱
	应答：
	0 正常
	1 车站编码不匹配
	7 读写出错
	8 认证出错
	E 时间错误*/
	int BoxInstall(int vBoxNum,unsigned char * UserID,int vLineNum,int vStationNum,unsigned char * NowTime);


	/*钱箱信息
	应答：
	0 正常*/
	int BoxInfomation(int vBoxNum);

private:
	int SendData(unsigned char * vData,unsigned int vlength,int vCmdNo,int time,int vChannel);
};
#endif

