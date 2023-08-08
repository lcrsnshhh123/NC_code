#include "Interpolating.h"

unsigned short Judge_Quadrant(double x, double y)
{
	unsigned short nDir;

	if (x>=0) 
	{ //ÏóÏŞÅĞ¶Ï
		if (y>=0) 
		{
			nDir=1;	
			return 1;
		}
		else 
		{
			nDir=4;
			return 4;
		}
	}
	else 
	{
		if (y>=0) 
		{
			nDir=2;
			return 2;
		}
		else 
		{
			nDir=3;
			return 3;
		}
	}	
}