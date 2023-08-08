#include "GT_Move.h"

void MapAxis()
{
	short rtn;
	double cnt1[5]={2000,0,0,0,0};            // 根据系统设置坐标映射数组
	double cnt2[5]={0,2000,0,0,0};            // 根据系统设置坐标映射数组
	rtn=GT_MapAxis(1,cnt1);   GT_error(rtn);  // 映射第1轴到X轴
	rtn=GT_MapAxis(2,cnt2);   GT_error(rtn);  // 映射第2轴到Y轴
}