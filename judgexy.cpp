#pragma once
#include"add_heaer.h"
unsigned short judgexy(double x,double y)
{
	
	if((x>0&&y>0)||(y==0&&x>0))return 1;
	else
	{	if((x<0&&y>0)||(x==0&&y>0))return 2;
	else
	{if((x<0&&y<0)||(y==0&&x<0))return 3;
	else
		return 4;
	}
	}


}