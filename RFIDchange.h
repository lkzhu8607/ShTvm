#ifndef RFIDchange_H_  
#define RFIDchange_H_  
 
#include <stdio.h> 
#include <string>
using namespace std;

struct F_rfidBoxInfo{
	int BoxState;//Ǯ��״̬:0x01�ڿ���,0x02Ǯ���ѳ���,����δ����װ��TVM��,0x03��ʾǮ���Ѿ���װ��TVM�ϲ���������Ӫ,0x04��ά����
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
	/*ͨ��Ӧ��
	0 ����
	-1 ����δ��
	-2 ͨѶ����
	-3 ͨѶ��ʱ
	-4 ��������У�����
	*/
	//ֽ��ʶ����״̬
	std::string rfidVer;
	F_rfidBoxInfo BoxInfoList[3];
	int RWerror[7];
	/*��д����
	0 ��ȡBlock����
	1 д��Block����
	2 ͨ����������
	3 ����֤����
	4 ѡ������
	5 �Ƿ�Block��ַ
	6 Ѱ������*/

	/*�򿪴��ڣ�iPortNum���ں�
	Ӧ��
	0 ����
	-1 ʧ��*/
	int OpenCom();


	/*�رմ���
	Ӧ��
	0 ����
	-1 ʧ��*/
	int CloseCom();


	/*״̬��ѯ
	Ӧ��
	0 ����*/
	int GetState();


	/*ͨѶ����
	Ӧ��
	0 ����*/
	int BoxTest(int vBoxNum);


	/*��Ǯ����Ϣ
	Ӧ��
	0 ����*/
	int BoxRead(int vBoxNum);


	/*дǮ����Ϣ
	Ӧ��
	0 ����
	1 û������ȡ����
	������
	vDenominationֽ�����
	vNumberֽ������
	vCountǮ���ڽ���������=����������ֻ�зϱ�������Ҫ�����ۼӵģ�
	*/
	int BoxWrite(int vBoxNum,int vDenomination,int vNumber,int vCount);


	/*װ��Ǯ��
	Ӧ��
	0 ����
	1 ��վ���벻ƥ��
	7 ��д����
	8 ��֤����
	E ʱ�����*/
	int BoxInstall(int vBoxNum,unsigned char * UserID,int vLineNum,int vStationNum,unsigned char * NowTime);


	/*Ǯ����Ϣ
	Ӧ��
	0 ����*/
	int BoxInfomation(int vBoxNum);

private:
	int SendData(unsigned char * vData,unsigned int vlength,int vCmdNo,int time,int vChannel);
};
#endif

