#ifndef GDnote_H_  
#define GDnote_H_  
 
#include "stdio.h" 
#include <string>
using namespace std;

namespace BillGD {

//G+D状态：A上个动作，D纸币面额（仅指面额相应的序号），E错误码，L无法识别的纸币长度，N暂存纸币数，
//P（这个其实没啥用），R无法识别纸币的原因，S现在的模式，W无法识别的纸币宽度
struct GD_NoteState{
	long A;//00无动作，02纸币进通道，03暂存压箱，04退回通道纸币，05纸币进暂存，06退回所有纸币
	long D;
	long E[10];
	long Enum;
	long L;
	long N;
	long P;
	long R[3];
	long Rnum;
	long S;
	long W;
	long NoteValue; //纸币面额,单位：元
};

class GDCashModle
{
public: 
    GDCashModle(void)
	{}
	/*应答：
	-1 串口未打开
	0 正常
	1 通讯故障
	2 无返回信息、或信息不完整
	3 动作未运行
	4 动作运行超时
	5 动作后读状态失败
	6 动作后状态中上个动作数据不符 
	7 其他
	*/
	//纸币识别器状态
	int cNoteValue;
	int cNoteNum;
	int cErrorCode[10];
	int cErrorNum;
	//打开串口，iPortNum串口号.........................
	int OpenCom();
	//关闭串口...............
	int CloseCom();
	//1.机器复位....................#
	int cmReset();
	//2.状态查询...................dis sta>
	int cmState();
	//3.工作模式设置................set wor +>
	int cmWorkMode(std::string *WorkMode);
	//4.收取纸币面额设置
	int cmWorkCash();
	//5.建立通讯...............>
	int cmCall();
	//6.获取钱箱ID..............dis cbs>
	int cmBoxID(std::string *NoteBoxID);
	//7.打开投币口.................work
	int cmWork();
	//8.关闭投币口................?
	int cmStop();
	//9.通道退币
	int cmReturn();
	//10.暂存退币..................ref>
	int cmReject();
	//11.纸币从通道进入暂存
	int cmEscrow();
	//12.压箱.......................enc>
	int cmDeposit();
	//13.通道清币
	int cmClear();
	
	/*  下面几个是新加的*/
	
	//获取模块ID                  dis ide>
	int  cmModuleID();
	
	//停用纸币的识别                 inh +>
	int cmInhibit();
	
	//激活纸币的识别                 act +>
	int cmActive();
};


}


#endif
