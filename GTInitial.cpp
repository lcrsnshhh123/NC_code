#include "GT_Move.h"

void GTInitial()
{
	short rtn;
    rtn=GT_Close(); GT_error(rtn);  //�ȹر��˶��������豸����֤�±ߺ�����������
	rtn=GT_Open();  GT_error(rtn);  //���˶��������豸
	rtn=GT_Reset(); GT_error(rtn);  //��λ�˶�������
	// ��1�ſ�����Ϊ��ǰ��(���ڶ࿨ϵͳ)��	
	rtn=GT_SwitchtoCardNo(0);GT_error(rtn);
	rtn=GT_SetSmplTm(200);GT_error(rtn);
	for(int i=1;i<5;i++)
	{
		rtn=GT_Axis(i);
		rtn=GT_SetIntrMsk(0);
	}
}