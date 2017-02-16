
#ifndef K1__bu_backman_ele_t_H
#define K1__bu_backman_ele_t_H


#include "2.h"
#include "bu_hot_thrd_t.h"
#include "d_db_t.h"



//
class bu_backman_ele_t : public bu_hot_thrd_t
{
public:
	int  m_MaxLineNum;
	int  m_iStart;						// 显示部分在 全集 中的起始位置 
	std::vector< std::string >	 m_Scr1; // 显示的内容全集 
	std::vector< std::string >	 m_Scr2; // 显示的部分 
	std::string  m_strTitle;
	std::string  m_strInput;

	std::map< std::string , void(bu_backman_ele_t::*)() >    m_mfp;   // 函数名 ， 函数指针

	int  m_x, m_y;		 // 当前菜单块的位置	以0为基数。	
	
	a3009_t::ROWTYPE	m_Ra3009;	// 当前登录的用户号	
	
	tbool		m_IsJieSuan;
	tbool		m_IsWeiHu;

public:
	bu_backman_ele_t();
	virtual ~bu_backman_ele_t();

public:
	virtual void tr_on_pre_thrd();
	virtual int tr_on_user_run();
	void ShowCurrScr();						// 显示当前内容 
	void GetInputKey( std::string & s );	// 得到输入 	

	void MkCurrMenu();		//	把当前menu做进m_Scr1里。	 
	void GetCurrTitle();	  
	void GoPrev();
	void GoNext( int iChoose );	// 应该有权限判断	
	tbool HaveAuthority(); //有权限	

	void OnRunFunc( std::string strFuncName );

	void f_user_judge();

	//1_
	void f_whole_status();		// 1 设备状态	1 整体设备状态
	void f_show_ver();			// 2 版本信息 
	void f_show_err_codes();	// 3 设备当前故障
	void f_dev_id();			// 4 设备模块ID 
	void f_coincontrol_sense();	// 5 控制板光感状态
	void f_eod_ver();			// 6 当前参数版本	

	//1_7
	void f_Udisk();				//7 其它功能	1 用U盘升级		f_Udisk
	void f_clear_all();			//2 清空到出厂状态		f_clear_all
	
	//2_1
	void f_tvm_on_off_show();	// 2 设置模式	1 TVM开启或关闭	1 显示TVM开启或关闭状态		
	void f_tvm_on_off_on();	 
	void f_tvm_on_off_off();	 
	
	//2_2
	void f_ShowCurrCoinMode();	 
	void f_CurrCoinRecive();	 
	void f_CurrCoinNoRecive();	 

	//2_3
	void f_ShowCurrBillMode();	 
	void f_CurrBillRecive();	 
	void f_CurrBillNoRecive();	 

	//2_4
	void f_ShowCurrBillChangeMode();
	void f_UseBillChange();
	void f_StopUseBillChange();

	//2_5
	void f_ShowCurrPrintMode();
	void f_StartPrint();
	void f_StopPrint();

	//2_6
	void f_ShowCurrOpenDoorSellMode();
	void f_OpenDoorSellStart();
	void f_OpenDoorSellStop();

	//2_7
	void f_reboot();

	//2_8
	void f_shutdown();

	//3_1
	void f_GuakaMada_Test();		//	1 刮卡马达测试	
	void f_TransMada_Test();		//	2 传输马达测试		
	void f_StopMotor_Test();		//	3 电机测试关闭		
	void f_ChangeBox_Test();		//	4 换箱测试		
	void f_Sell1TestTicket();		//	  发售1元测试票		

	//3_2
	void f_CoinRecognizer_Test();    //硬币相关功能测试
	void f_CoinStock_Test();
	void f_CoinReturn_Test();
	void f_CoinRecycieBox_Test();

	//3_3
	void f_BillMotorReset_Test();		// 纸币识别器复位 	
	void f_BillRecive_Test();
	void f_BillStock_Test();
	void f_BillReturn_Test();
	void f_BillCollect_Test();
	void f_ClearnBillChannel();

	//3_4 - 3_8
	void f_OpenWarnning();		// 4 报警打开	
	void f_StopWarnning();		// 5 报警关闭	
	void f_OpenLight();		// 6 打开前照明和取票灯	
	void f_CloseLight();		// 7 关闭前照明和取票灯   	
	void f_StatusDisplay_Test();		// 8 状态显示器测试	   	
	

	//4_1 - 4_4
	void f_Print_Aduit_Report();
	void f_Print_Profit_Report();
	void f_Print_Ticket_Report();
	void f_Print_Trade_Report();

	//5_
	void f_Show6000Data();      //把6000显示出来 00 区域1售票数  
	void f_Show6000Data2();      //把6000显示出来 01 区域2售票数  

	//6_
	void f_SelectTransData();   // 时间 金额 张数 纸币收 硬币收 纸币找 硬币找 (说明：金额 收 找都是指钱数，不是指张数个数)

	//7_
	//7_1
	void f_account();           //结算状态，拿走钱箱时清值上传

	//7_2
	void f_maintenance();       //维护状态，拿走钱箱时不清值不上传
	//7_3
	void f_ClearingCoin();		// 3 硬币清币

	// 7_4
	void f_CleaningBill();      // 4 清除纸币到回收箱

	//7_5
	void f_RepCoin();		// 4 硬币找零加币

	//7_6
	void f_RepBill();		// 5 纸币找零手动加币	暂不开发

	//8_
	void f_Reset();        //复位


};


//#include "bu_backman_mgr_t.h"



#endif



