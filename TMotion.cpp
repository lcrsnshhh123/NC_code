#include "GT_Move.h"

void TMotion()
{	short rtn;
	rtn=GT_PrflT();        GT_error(rtn);  // �����˶�ģʽΪ��������ģʽ
	rtn=GT_SetAcc(0.01);   GT_error(rtn);  // ���������ٶ�Ϊ0.01
	rtn=GT_SetVel(1);      GT_error(rtn);  // ����Ŀ���ٶ�Ϊ1
	rtn=GT_SetPos(-10000);  GT_error(rtn);  // ����Ŀ��λ��Ϊ80000
	rtn=GT_Update();       GT_error(rtn);  // ˢ�²���
}