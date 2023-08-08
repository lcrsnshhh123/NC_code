#include "GT_Move.h"

void TMotion()
{	short rtn;
	rtn=GT_PrflT();        GT_error(rtn);  // 设置运动模式为梯形曲线模式
	rtn=GT_SetAcc(0.01);   GT_error(rtn);  // 设置最大加速度为0.01
	rtn=GT_SetVel(1);      GT_error(rtn);  // 设置目标速度为1
	rtn=GT_SetPos(-10000);  GT_error(rtn);  // 设置目标位置为80000
	rtn=GT_Update();       GT_error(rtn);  // 刷新参数
}