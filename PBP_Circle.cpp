#include "Interpolating.h"

void PBP_Circle(double step, double XStart, double YStart, double XEnd,double YEnd, double radius, int bIsCW)
{
	double lDevVal,goallDevVal;//��ǰ�������յ�Ĳ�ֵ
	double xCurVal=XStart,yCurVal=YStart;//��ǰ����
	unsigned short nDir;//����
	long stepcount=0;//����
	lDevVal=xCurVal*xCurVal+yCurVal*yCurVal-radius*radius;
	goallDevVal=(xCurVal-XEnd)*(xCurVal-XEnd)+(yCurVal-YEnd)*(yCurVal-YEnd);
	//�����Ĳ�����Բ
		/*if(!(XStart==XEnd&&YStart==YEnd))
		{*/
			//InsertPoint(XStart,YStart);
		/*}*/
	while(goallDevVal>=(step*step)||stepcount==0)
	{
		if(lDevVal>=0)//�����ڵ�����
		{
			if(bIsCW==0)//��Բ�岹
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
			else//˳Բ�岹
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
		else//���С����
		{
			if(bIsCW==0)//��Բ�岹
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
			else//˳Բ�岹
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
		//����������Բ
		/*if(XStart==XEnd&&YStart==YEnd)
		{
			
		}*/
		lDevVal=xCurVal*xCurVal+yCurVal*yCurVal-radius*radius;
		goallDevVal=(xCurVal-XEnd)*(xCurVal-XEnd)+(yCurVal-YEnd)*(yCurVal-YEnd);
		stepcount++;
	}
	//������һ����
	//InsertPoint(XEnd,YEnd);
}
