#include "GT_Move.h"

void GMotion()
{
	short rtn;
	rtn=GT_Axis(1);        GT_error(rtn);    // ���õ�ǰ��Ϊ��һ��
	rtn=GT_PrflG(2);       GT_error(rtn);    // �����˶�ģʽΪ���ӳ��ֿ���ģʽ������Ϊ2��
	rtn=GT_SetRatio(-1);   GT_error(rtn);    // ���õ��ӳ��ִ�����Ϊ-1
	rtn=GT_Update();       GT_error(rtn);    // ˢ�²���
}