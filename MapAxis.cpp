#include "GT_Move.h"

void MapAxis()
{
	short rtn;
	double cnt1[5]={2000,0,0,0,0};            // ����ϵͳ��������ӳ������
	double cnt2[5]={0,2000,0,0,0};            // ����ϵͳ��������ӳ������
	rtn=GT_MapAxis(1,cnt1);   GT_error(rtn);  // ӳ���1�ᵽX��
	rtn=GT_MapAxis(2,cnt2);   GT_error(rtn);  // ӳ���2�ᵽY��
}