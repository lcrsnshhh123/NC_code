#include "GT_Move.h"

void AxisInitialSG()
{
	short rtn;
	for (int i=1;i<=2;i++)
	{
		rtn=GT_Axis(i);        GT_error(rtn);      // ���õ�i��Ϊ��ǰ��
		rtn=GT_ClrSts();       GT_error(rtn);      // �����ǰ�᲻��ȷ״̬
		rtn=GT_StepPulse();    GT_error(rtn);      // ����������������ź�
		rtn=GT_StepDir();      GT_error(rtn);
		rtn=GT_LmtsOn();       GT_error(rtn);
		rtn=GT_AxisOn();       GT_error(rtn);      // ����ʹ��
	}
}