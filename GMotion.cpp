#include "GT_Move.h"

void GMotion()
{
	short rtn;
	rtn=GT_Axis(1);        GT_error(rtn);    // 设置当前轴为第一轴
	rtn=GT_PrflG(2);       GT_error(rtn);    // 设置运动模式为电子齿轮控制模式，主轴为2轴
	rtn=GT_SetRatio(-1);   GT_error(rtn);    // 设置电子齿轮传动比为-1
	rtn=GT_Update();       GT_error(rtn);    // 刷新参数
}