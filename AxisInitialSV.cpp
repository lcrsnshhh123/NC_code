#include "GT_Move.h"

void AxisInitialSV()
{
	short rtn; 
	rtn=GT_Axis(1);      GT_error(rtn);    // ���õ�һ����Ϊ��ǰ��
	rtn=GT_ClrSts();     GT_error(rtn);    // �����ǰ�᲻��ȷ״̬
	rtn=GT_CtrlMode(0);  GT_error(rtn);    // ����Ϊ���ģ����
	rtn=GT_CloseLp();    GT_error(rtn);    // ����Ϊ�ջ�����
    rtn=GT_SetKp(20);    GT_error(rtn);    // ���ñ�������20
	rtn=GT_SetKi(0);     GT_error(rtn);    // ���û�������0
	rtn=GT_SetKd(10);    GT_error(rtn);    // ����΢������10
	rtn=GT_SetKvff(0);   GT_error(rtn);    // �����ٶ�ǰ����0
	rtn=GT_SetKaff(0);   GT_error(rtn);    // ���ü��ٶ�ǰ����0
	rtn=GT_SetMtrBias(10);  GT_error(rtn); // ����������Ư��ֵΪ10
	rtn=GT_Update();     GT_error(rtn);    // ����ˢ��(������Ч)
	rtn=GT_AxisOn();     GT_error(rtn);    // ����ʹ��
	rtn=GT_Axis(2);      GT_error(rtn);    // ���õڶ���Ϊ��ǰ��
	rtn=GT_ClrSts();     GT_error(rtn);    // �����ǰ�᲻��ȷ״̬
	rtn=GT_CtrlMode(0);  GT_error(rtn);    // ����Ϊ���ģ����
	rtn=GT_OpenLp();     GT_error(rtn);    // ����Ϊ��������
	rtn=GT_AxisOn();     GT_error(rtn);    // ����ʹ��
	//rtn=GT_Axis(3);      GT_error(rtn);    // ���õ�����Ϊ��ǰ��
	//rtn=GT_ClrSts();     GT_error(rtn);    // �����ǰ�᲻��ȷ״̬
	//rtn=GT_CtrlMode(1);  GT_error(rtn);    // �������������
	//rtn=GT_StepDir();    GT_error(rtn);    // �����������+�����ź�
	//rtn=GT_AxisOn();     GT_error(rtn);    // ����ʹ��
	//rtn=GT_Axis(4);      GT_error(rtn);    // ���õ�����Ϊ��ǰ��
	//rtn=GT_ClrSts();     GT_error(rtn);    // �����ǰ�᲻��ȷ״̬
	//rtn=GT_CtrlMode(1);  GT_error(rtn);    // �������������
	//rtn=GT_StepPulse();  GT_error(rtn);    // ����������������ź�
	//rtn=GT_AxisOn();     GT_error(rtn);    // ����ʹ��

}