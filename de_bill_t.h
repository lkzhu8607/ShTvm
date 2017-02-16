
#ifndef K1_de_bill_t_H
#define K1_de_bill_t_H

#include "2.h"
#include "de_base_t.h"
#include "bnr_operation.h"



//  
class de_bill_t : public de_base_t 
{
public:
	// m_de_state		  0= idle ;  1= reset & idle ; 2= loop query 
	 
public:
	de_bill_t();
	virtual ~de_bill_t();

	int   m_iIsNotBillChange;      // 0 :normal   1:无纸币找零
	int m_install_boxflag;     //安装上钱箱    0:没有变化  1:安装
	int m_uninstall_boxflag;   //卸载下钱箱    0:没有变化  1:卸载下
	int m_safeunlock;            //0:锁上     1:解锁
    int m_iIsRepBillOk;          //1:ok   0:fail
	int m_resetok;   //安装上箱子之后，自动复位完成1, 未完成自动复位0；
public:
	virtual void OnRunTask( std::string t );
	virtual int tr_on_user_run();

	//
	void billAdvice();		//上报接收纸币信息
	int billInit();		// 已改成mei
	int Reset();
	//设备对外接口 
	int Work();			// 已改成mei 内部有state`	用法：只要work然后查寄存器就行了。
	int State();		//  mei 不直接用。
	int Stop();			//  mei 不直接用。

	int Return1(); // 上退币				// 已改成mei
	int Return2(); // 下退
	int Return3(); // 全退 
	int Escrow();  //一张就要进暂存 进了才能再work.
	int Deposit(); // 暂存中的N张压箱一次。 

	int Mei_Inhibit(int value);	// 0=全部。 value=常用面值(元为单位 1,2,5,10,20,50,100)
	int Mei_Active(int value);	
	
	//add by jfren @20161118
	int dBill_Open();			//打开设备连接
	void dBill_Close();          //关闭设备连接

	//返回0 状态无变化，返回1 状态有变化
	int dBill_State();		    //查询状态 
	
	int dBill_Reset(bool OnlyReset);//复位	true:只机械复位  false:复位且做一些基础设置

	int dBill_Reboot();         //纸币系统重启
	int dBill_GetVersion();	    //获取版本信息
	int dBill_Change(int method,UINT32* CBone,UINT32* CBtwo,UINT32* CBthree,UINT32 *CBfour); //找零  method 1优化的找零策略

	int dBill_Clean(int boxclear[5],unsigned int LOClear_Num[8],unsigned int REClear_Num[8],unsigned int CB_TotalNum[8]);		//清币(循环箱和补币箱清空到回收箱)数组下标 0-6分别对应1 2 5 10 20 50 100 元 ，下标7对应 不识别面额(回收箱总币数)
	int dBill_Add(unsigned int LOAdd_Num[8]);	       //补币 下标0-6 : 1 2 5 10 20 50 100元面额 ，数量 下标 7不识别面额 数量  

	int dBill_Work();	//打开投币口
	int dBill_Stop();  //关闭投币口
	int dBill_Encash();//压箱
	int dBill_End();//结束交易
	//int dBill_CashInEnd; //结束交易  关闭口和退出纸币后调用一下(推荐)

	int dBill_GetSerialNums(char ModuleSerialNums[6][10]);  //获取各模块序列号0-3:RE3-RE6 4:LO1 5:CB 
	int dBill_Refund();  //退币
	int dBill_JetBanknotes();//喷出纸币
	int dBill_BackBanknotes();//缩回纸币
	int dBill_Query();  //查询钱
	int dBill_Inhibit(int bnrdisable[7]);	// 下标 0-6 (元为单位 1,2,5,10,20,50,100)
	int dBill_Active(int bnrenable[7]);	
	int dBill_GetRecycleDenomination(UINT32 REDeno[4],UINT32 REcount[4]);    //获取循环箱存放纸币面额(分)和张数(0-RE3 1-RE4 2-RE5 3-RE6)
	int dBill_ClearLoaderRecovery();  //清空回收箱和补币箱的数据统计
	int dBill_QueryCashUint();  //查询模块单元信息
	
	//设定循环箱满、高、低、空位置值设置信息(设置完不需要Reset) CB:4
	int dBill_SetReCBPositionNum(int full[5],int high[5],int low[5],int empty[5]);

	//设置循环箱(RE3 RE4 RE5 RE6 LO1即 0-4，的接收最大纸币面额元和数量)yuan_amount[i]=0 是lock该设备。yuan_maxcount[4]无效
	int dBill_SetCashUnit(int yuan_amount[5] ,int yuan_maxcount[5] );

	//锁定某个单元模块如:(RE3 RE4 RE5 RE6 LO1 CB),  value值 true: 锁上 false:解锁  //执行该命令需要Reset 
	int dBill_LockBox(char name[8],bool value);
	
	//end add by jfren @20161118

	bool IsVaultFull();        //纸币箱和循环找零箱是否满    true：表示满， false ：正常
	int  RecoverErr();

	int RepBillStock();

};



//
extern de_bill_t  *gp_bill;


#endif



