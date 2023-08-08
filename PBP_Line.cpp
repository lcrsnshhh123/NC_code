#include "Interpolating.h"

void PBP_Line(double step,double XStart,double YStart, double XEnd, double YEnd)
{
	// step:步长、XStart/YStart:插补起点、XEnd/YEnd:插补终点
	double lDevVal;				             //偏差值
	double xCurVal=XStart,yCurVal=YStart;       //当前点的实际位置
	long StepMount;                   //插补总步数
	long StepCount=0;			      //插补次数计数器
	unsigned short nDir;			  //当前点所在象限

	nDir=Judge_Quadrant(XEnd,YEnd);   //象限判断	
	XEnd=labs(XEnd);//绝对值
	YEnd=labs(YEnd);	
	StepMount=(long) (XEnd+YEnd)/step;
	lDevVal=yCurVal*XEnd-xCurVal*YEnd;//直线插补的偏差计算公式
	while (StepCount<StepMount) 
	{//终点判别	
		if (lDevVal>=0) 
		{ //偏差〉=0
			switch(nDir) {
			case 1:
				xCurVal+=step;
				InsertPoint(xCurVal,yCurVal);		
				break;
			case 2:
				xCurVal-=step;
				InsertPoint(xCurVal,yCurVal);			
				break;
			case 3:
				xCurVal-=step;
				InsertPoint(xCurVal,yCurVal);			
				break;
			case 4:
				xCurVal+=step;
				InsertPoint(xCurVal,yCurVal);		
				break;
			}
			lDevVal-=YEnd;
		}
		else{  //偏差<0
			switch(nDir) {
			case 1:
				yCurVal+=step;
				InsertPoint(xCurVal,yCurVal);	
				break;
			case 2:
				yCurVal+=step;
				InsertPoint(xCurVal,yCurVal);		
				break;
			case 3:
				yCurVal-=step;
				InsertPoint(xCurVal,yCurVal);		
				break;
			case 4:
				yCurVal-=step;
				InsertPoint(xCurVal,yCurVal);			
				break;
			}			
			lDevVal+=XEnd;
		}
		StepCount++;
	}
}

