#ifndef GDnote_H_  
#define GDnote_H_  
 
#include "stdio.h" 
#include <string>
using namespace std;

namespace BillGD {

//G+D״̬��A�ϸ�������Dֽ������ָ�����Ӧ����ţ���E�����룬L�޷�ʶ���ֽ�ҳ��ȣ�N�ݴ�ֽ������
//P�������ʵûɶ�ã���R�޷�ʶ��ֽ�ҵ�ԭ��S���ڵ�ģʽ��W�޷�ʶ���ֽ�ҿ��
struct GD_NoteState{
	long A;//00�޶�����02ֽ�ҽ�ͨ����03�ݴ�ѹ�䣬04�˻�ͨ��ֽ�ң�05ֽ�ҽ��ݴ棬06�˻�����ֽ��
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
	long NoteValue; //ֽ�����,��λ��Ԫ
};

class GDCashModle
{
public: 
    GDCashModle(void)
	{}
	/*Ӧ��
	-1 ����δ��
	0 ����
	1 ͨѶ����
	2 �޷�����Ϣ������Ϣ������
	3 ����δ����
	4 �������г�ʱ
	5 �������״̬ʧ��
	6 ������״̬���ϸ��������ݲ��� 
	7 ����
	*/
	//ֽ��ʶ����״̬
	int cNoteValue;
	int cNoteNum;
	int cErrorCode[10];
	int cErrorNum;
	//�򿪴��ڣ�iPortNum���ں�.........................
	int OpenCom();
	//�رմ���...............
	int CloseCom();
	//1.������λ....................#
	int cmReset();
	//2.״̬��ѯ...................dis sta>
	int cmState();
	//3.����ģʽ����................set wor +>
	int cmWorkMode(std::string *WorkMode);
	//4.��ȡֽ���������
	int cmWorkCash();
	//5.����ͨѶ...............>
	int cmCall();
	//6.��ȡǮ��ID..............dis cbs>
	int cmBoxID(std::string *NoteBoxID);
	//7.��Ͷ�ҿ�.................work
	int cmWork();
	//8.�ر�Ͷ�ҿ�................?
	int cmStop();
	//9.ͨ���˱�
	int cmReturn();
	//10.�ݴ��˱�..................ref>
	int cmReject();
	//11.ֽ�Ҵ�ͨ�������ݴ�
	int cmEscrow();
	//12.ѹ��.......................enc>
	int cmDeposit();
	//13.ͨ�����
	int cmClear();
	
	/*  ���漸�����¼ӵ�*/
	
	//��ȡģ��ID                  dis ide>
	int  cmModuleID();
	
	//ͣ��ֽ�ҵ�ʶ��                 inh +>
	int cmInhibit();
	
	//����ֽ�ҵ�ʶ��                 act +>
	int cmActive();
};


}


#endif
