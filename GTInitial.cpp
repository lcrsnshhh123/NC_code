#include "GT_Move.h"

void GTInitial()
{
	short rtn;
    rtn=GT_Close(); GT_error(rtn);  //先关闭运动控制器设备，保证下边函数正常运行
	rtn=GT_Open();  GT_error(rtn);  //打开运动控制器设备
	rtn=GT_Reset(); GT_error(rtn);  //复位运动控制器
	// 将1号卡设置为当前卡(对于多卡系统)；	
	rtn=GT_SwitchtoCardNo(0);GT_error(rtn);
	rtn=GT_SetSmplTm(200);GT_error(rtn);
	for(int i=1;i<5;i++)
	{
		rtn=GT_Axis(i);
		rtn=GT_SetIntrMsk(0);
	}
}