#include "Interpolating.h"

void PBP_Circle(double step, double XStart, double YStart, double XEnd,double YEnd, double radius, int bIsCW)
{
	double lDevVal,goallDevVal;//当前误差和与终点的差值
	double xCurVal=XStart,yCurVal=YStart;//当前坐标
	unsigned short nDir;//象限
	long stepcount=0;//步数
	lDevVal=xCurVal*xCurVal+yCurVal*yCurVal-radius*radius;
	goallDevVal=(xCurVal-XEnd)*(xCurVal-XEnd)+(yCurVal-YEnd)*(yCurVal-YEnd);
	//当画的不是整圆
		/*if(!(XStart==XEnd&&YStart==YEnd))
		{*/
			//InsertPoint(XStart,YStart);
		/*}*/
	while(goallDevVal>=(step*step)||stepcount==0)
	{
		if(lDevVal>=0)//误差大于等于零
		{
			if(bIsCW==0)//逆圆插补
			{
				nDir=Judge_Quadrant(xCurVal,yCurVal); 
				switch(nDir)
				{
				case 1:
					xCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 2:
					yCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 3:
					xCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 4:
					yCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				}
			}
			else//顺圆插补
			{
				nDir=Judge_Quadrant(xCurVal,yCurVal); 
				switch(nDir)
				{
				case 1:
					yCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 2:
					xCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 3:
					yCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 4:
					xCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				}
			}
		}
		else//误差小于零
		{
			if(bIsCW==0)//逆圆插补
			{
				nDir=Judge_Quadrant(xCurVal,yCurVal); 
				switch(nDir)
				{
				case 1:
					yCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 2:
					xCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 3:
					yCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 4:
					xCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				}
			}
			else//顺圆插补
			{
				nDir=Judge_Quadrant(xCurVal,yCurVal); 
				switch(nDir)
				{
				case 1:
					xCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 2:
					yCurVal+=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 3:
					xCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				case 4:
					yCurVal-=step;
					InsertPoint(xCurVal,yCurVal);
					break;
				}
			}
		}
		//当画的是整圆
		/*if(XStart==XEnd&&YStart==YEnd)
		{
			
		}*/
		lDevVal=xCurVal*xCurVal+yCurVal*yCurVal-radius*radius;
		goallDevVal=(xCurVal-XEnd)*(xCurVal-XEnd)+(yCurVal-YEnd)*(yCurVal-YEnd);
		stepcount++;
	}
	//添加最后一个点
	//InsertPoint(XEnd,YEnd);
}
