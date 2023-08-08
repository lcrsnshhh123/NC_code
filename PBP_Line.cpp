#include "Interpolating.h"

void PBP_Line(double step,double XStart,double YStart, double XEnd, double YEnd)
{
	// step:������XStart/YStart:�岹��㡢XEnd/YEnd:�岹�յ�
	double lDevVal;				             //ƫ��ֵ
	double xCurVal=XStart,yCurVal=YStart;       //��ǰ���ʵ��λ��
	long StepMount;                   //�岹�ܲ���
	long StepCount=0;			      //�岹����������
	unsigned short nDir;			  //��ǰ����������

	nDir=Judge_Quadrant(XEnd,YEnd);   //�����ж�	
	XEnd=labs(XEnd);//����ֵ
	YEnd=labs(YEnd);	
	StepMount=(long) (XEnd+YEnd)/step;
	lDevVal=yCurVal*XEnd-xCurVal*YEnd;//ֱ�߲岹��ƫ����㹫ʽ
	while (StepCount<StepMount) 
	{//�յ��б�	
		if (lDevVal>=0) 
		{ //ƫ�=0
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
		else{  //ƫ��<0
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

