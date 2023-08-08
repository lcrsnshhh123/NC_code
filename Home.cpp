#include "GT_Move.h"

void Home (long pos)
{
	unsigned short status;
	long act1_pos;
	short rtn;
	rtn=GT_ClrSts();GT_error(rtn);     // 清状态
	rtn=GT_CaptHome(); GT_error(rtn);  // 设置捕获Home
	rtn=GT_PrflT(); GT_error(rtn);     // 设置梯形曲线
	rtn=GT_SetVel(1);GT_error(rtn);    // 设置速度为4脉冲/控制周期
	rtn=GT_SetAcc(0.01);GT_error(rtn);    // 设置加速度为1
	rtn=GT_SetPos(pos);GT_error(rtn);  // 设置目标位置
	rtn=GT_Update();GT_error(rtn);     // 刷新参数
	rtn=GT_GetSts(&status);GT_error(rtn);  // 读取轴状态
	while(!(status&0x8))               // 等待Home捕获
	{
		if((status & 0x400)!=0x400) return;         // 如果运动已完成。但Home未触发，结束
		rtn=GT_GetSts(&status);GT_error(rtn);  // 读取轴状态
	}
	rtn=GT_GetCapt(&pos);GT_error(rtn); // 读取捕获位置
	rtn=GT_SetPos(pos);GT_error(rtn);   // 设置捕获位置为目标位置
	rtn=GT_Update();GT_error(rtn);      // 刷新参数
	rtn=GT_ClrSts();GT_error(rtn);      // 清状态
	rtn=GT_GetSts(&status);GT_error(rtn);  // 读取状态值
	while(status & 0x400)                   // 等待运动完成
	{
		rtn=GT_GetSts(&status);GT_error(rtn);  // 读取状态
	}
	rtn=GT_ZeroPos();GT_error(rtn);        // 清零
}