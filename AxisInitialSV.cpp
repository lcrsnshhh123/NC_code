#include "GT_Move.h"

void AxisInitialSV()
{
	short rtn; 
	rtn=GT_Axis(1);      GT_error(rtn);    // 设置第一个轴为当前轴
	rtn=GT_ClrSts();     GT_error(rtn);    // 清除当前轴不正确状态
	rtn=GT_CtrlMode(0);  GT_error(rtn);    // 设置为输出模拟量
	rtn=GT_CloseLp();    GT_error(rtn);    // 设置为闭环控制
    rtn=GT_SetKp(20);    GT_error(rtn);    // 设置比例增益20
	rtn=GT_SetKi(0);     GT_error(rtn);    // 设置积分增益0
	rtn=GT_SetKd(10);    GT_error(rtn);    // 设置微分增益10
	rtn=GT_SetKvff(0);   GT_error(rtn);    // 设置速度前反馈0
	rtn=GT_SetKaff(0);   GT_error(rtn);    // 设置加速度前反馈0
	rtn=GT_SetMtrBias(10);  GT_error(rtn); // 设置输出零点漂移值为10
	rtn=GT_Update();     GT_error(rtn);    // 参数刷新(参数生效)
	rtn=GT_AxisOn();     GT_error(rtn);    // 驱动使能
	rtn=GT_Axis(2);      GT_error(rtn);    // 设置第二轴为当前轴
	rtn=GT_ClrSts();     GT_error(rtn);    // 清除当前轴不正确状态
	rtn=GT_CtrlMode(0);  GT_error(rtn);    // 设置为输出模拟量
	rtn=GT_OpenLp();     GT_error(rtn);    // 设置为开环控制
	rtn=GT_AxisOn();     GT_error(rtn);    // 驱动使能
	//rtn=GT_Axis(3);      GT_error(rtn);    // 设置第三轴为当前轴
	//rtn=GT_ClrSts();     GT_error(rtn);    // 清除当前轴不正确状态
	//rtn=GT_CtrlMode(1);  GT_error(rtn);    // 设置输出脉冲量
	//rtn=GT_StepDir();    GT_error(rtn);    // 设置输出脉冲+方向信号
	//rtn=GT_AxisOn();     GT_error(rtn);    // 驱动使能
	//rtn=GT_Axis(4);      GT_error(rtn);    // 设置第四轴为当前轴
	//rtn=GT_ClrSts();     GT_error(rtn);    // 清除当前轴不正确状态
	//rtn=GT_CtrlMode(1);  GT_error(rtn);    // 设置输出脉冲量
	//rtn=GT_StepPulse();  GT_error(rtn);    // 设置输出正负脉冲信号
	//rtn=GT_AxisOn();     GT_error(rtn);    // 驱动使能

}