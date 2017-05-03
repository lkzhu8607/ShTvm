
//代表了本设备自身 
#ifndef K1_de_medev_t_H
#define K1_de_medev_t_H

#include "2.h"
#include "de_base_t.h"



//  
class de_medev_t : public de_base_t 
{
public:
	 
public:
	de_medev_t();
	virtual ~de_medev_t();
	int     m_devstatus;                      //对应显示屏显示  3-正常售票   4-故障暂停服务   5-只收硬币 6-只收纸币 7-进入暂停 9 - 系统关闭
	int     m_legal_authority;                //是否合法权限  如:取钱箱是否登录或者维护  0-非法 1-维护  2-结算
	int     m_IsLegalLoginMaintenance;        // 是否合法登入维护   0: 没有，1：合法登入   目前用做切换模式

	int     m_outofservicestatus;             // 11-票卡已售完   12-暂停售票(default) 13-系统未被初始化

	int     m_IsOpenDoorSellModule;           //开门售票模式  1：开启   0：关闭    //该标志未来加到a9999中，方便统一管理

	int     m_IsYunYingEnd;                   //是否运营结束  1：结束 0：开启  
    
	int     m_IsEmergeModel;                  //是否是紧急模式 1：是  0：正常   

	int     m_IsRecv3014;                     //是否接收到3014 ，需要控制纸币模块非法取钱箱问题     1 ：是  0：不是 (default)
	
	int     m_IsSCNeedSysShutdownOrReboot;      //sc 相关  shutdown and reboot 0 -不需要  1-需要
	int     m_IsChangeToStopSerice;             //是否需要切换到停止服务  0-不需要  1-需要 

	int     m_iIsUpdateParaToStopSerice;       // 1-Yes   0-No
	int     m_iIsUpdatePic;                    // 1-Yes   0-No
	long    m_A3083Get5000NewVer;              
	long    m_A3084Get5000NewVer;
	long    m_A3086Get5000NewVer;

	unsigned char    m_bSendReg6000EventFlag;  // bit 0-door open/close 1-bill chg box 2-coin chg box1 3-coin chg box2 4-stop/open service

public:
	virtual void OnRunTask( std::string t );
	virtual void tr_on_pre_thrd();
	virtual int tr_on_user_run();

	bool IsOnlyCoin();     //只收硬币
	bool IsOnlyBill();     //只收纸币

	//
	void MedevInit();

	//设备对外接口 
	tbool Refresh5041_app_sub(); //不发发送事件码 返回1=有变更
	tbool Refresh5041_dev( std::string strinput );	//设备传过来input的处理		

	void EvtInitBegin(); // 初始化开始，E4=1，E71=0 
	void EvtInitEnd();// 初始化结束，如果参数全则E4=0
	
	void GetEvtStr( std::string & strOut );
	std::string GetEvtStr();

	tbool IntegratedStateGood();      
	tbool IsEODComplete();     //检测参数是否完整

};



//
extern de_medev_t  *gp_medev;


#endif



