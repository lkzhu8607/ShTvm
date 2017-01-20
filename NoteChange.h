#ifndef NOTECHANGE_H_
#define NOTECHANGE_H_
#include <vector>
typedef unsigned char BYTE;
typedef  std::vector<BYTE> BUF_T;
class NoteChanger
{
private:
	  bool isPort;
	  int  Retry;
private:
	  void BCC(BYTE & CRC1,BYTE &CRC2,BYTE * Source,int Length);
	  void BCCbit(unsigned short & bcc,BYTE Data,unsigned short com);
	  void Message(BYTE * message);
	  void IntToHexBcd(BYTE num, char hexbcd[2]);
	  BYTE changeBcdToISO(char bcdcode);
	  BYTE changeISOToBcd(BYTE iso1);
	  void HexBcdToInt(BYTE & num,BYTE hexbcd1,BYTE hexbcd2);
	  bool SendCommand(BYTE * inCommand,int length);
	  bool RecvCommand(BUF_T & buf_out);
	  void MessageCommon(BYTE inData[4],BYTE outData[6]);
public:
	  NoteChanger();
	  bool OpenCom();
	  bool CloseCom();
    int Init(BYTE inData[7],BYTE outData[6]);
	  int Status(BYTE outData[6]);
	  int Count(BYTE inData[6],BYTE outData[2],BYTE rejectData[2],BYTE outData1[6]);
};
#endif

