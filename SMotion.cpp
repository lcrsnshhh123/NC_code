#include "GT_Move.h"

//S-曲线模式运动函数
void SMotion()  
{
  short rtn;
  rtn=GT_PrflS();               GT_error(rtn);   // 设置运动模式为S曲线模式
  rtn=GT_SetJerk(0.00000002);   GT_error(rtn);   // 设置最大加加速度为0.00000002
  rtn=GT_SetMAcc(0.004);        GT_error(rtn);   // 设置最大加速度为0.004
  rtn=GT_SetVel(4);             GT_error(rtn);   // 设置目标速度为4
  rtn=GT_SetPos(80000);         GT_error(rtn);   // 设置目标位置为80000
  rtn=GT_Update();              GT_error(rtn);   // 刷新参数
}