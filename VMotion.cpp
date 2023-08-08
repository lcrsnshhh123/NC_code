#include "GT_Move.h"

void VMotion()
{
	short rtn;
	rtn=GT_PrflV();      GT_error(rtn);
	rtn=GT_SetAcc(0.01); GT_error(rtn);
	rtn=GT_SetVel(1);    GT_error(rtn);
	rtn=GT_Update();     GT_error(rtn);
}