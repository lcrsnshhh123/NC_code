#include "GT_Move.h"

void InputCfg()
{
	short rtn;
	unsigned int EncSense=0;
	unsigned short LmtSense=0xF;	
	rtn=GT_LmtSns(LmtSense);
	//rtn=GT_EncSns(EncSense);GT_error(rtn);  //���ñ��������򣨽�SV�������������ģ����/��������
}