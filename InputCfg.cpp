#include "GT_Move.h"

void InputCfg()
{
	short rtn;
	unsigned int EncSense=0;
	unsigned short LmtSense=0xF;	
	rtn=GT_LmtSns(LmtSense);
	//rtn=GT_EncSns(EncSense);GT_error(rtn);  //设置编码器方向（仅SV卡：输出类型是模拟量/脉冲量）
}