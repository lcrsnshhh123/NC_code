#include "GT_Move.h"

void AxisInitialSG()
{
	short rtn;
	for (int i=1;i<=2;i++)
	{
		rtn=GT_Axis(i);        GT_error(rtn);      // 设置第i轴为当前轴
		rtn=GT_ClrSts();       GT_error(rtn);      // 清楚当前轴不正确状态
		rtn=GT_StepPulse();    GT_error(rtn);      // 设置输出正负脉冲信号
		rtn=GT_StepDir();      GT_error(rtn);
		rtn=GT_LmtsOn();       GT_error(rtn);
		rtn=GT_AxisOn();       GT_error(rtn);      // 驱动使能
	}
}