#include "Interpolating.h"

void DrawCircle(CDC* pDC,double StartX,double StartY,double EndX,double EndY,double R,double Ptscale,double &TrPt_x,double &Trpt_y,int t)
{
	double x01,y01,x02,y02;double temp;
	double x_big,y_big;//��Բ��
	double x_small,y_small;//С��Բ��
	LONG nLeftRect, nTopRect,nRightRect,nBottomRect;
	
	CircleCenter(StartX,StartY,EndX,EndY,R,x01,y01,x02,y02);//�����������Բ������ҲΪ��������
	judge_cricle(StartX,StartY,EndX,EndY,x_big,y_big,x_small,y_small,x01,y01,x02,y02,t);

	////����
	//double ax = EndX- StartX;
	//double ay = EndY - StartY;
	//double bx = x01 - StartX;
	//double by = y01 - StartY;
	////���������Ĳ���ж�Բ��λ��
	////��A�ļ��Ǵ��ڵ�C�ļ��ǣ���Ϊ˳ʱ�� ��������ͬ���жϵ�B ������ͬ�����ʾ���㹲�� ���Ǽ��� Math.Atan2(p.Y,p.X��
	////���<0  ��Ϊ��Բ�ģ�����ΪС��Բ��
	//double mulRt = ax*by-bx*ay;
	////if (mulRt<0)//Բ����˳Բ
	////{
	////	x_big = x01;
	////	y_big = y01;
	////	x_small = x02;
	////	y_small = y02;
	////
	////
	////}
	////else
	////{
	////	x_big = x02;
	////	y_big = y02;
	////	x_small = x01;
	////	y_small = y01;
	////
	////}
	
	////R>0   ��<180�ȣ� R<0  ��>180��
	if (R<0) //��
	{
		TrPt_x=x_big;
		Trpt_y=y_big;
		nLeftRect = x_big-R;
		nTopRect = y_big + R;
		nRightRect = x_big+R;
		nBottomRect = y_big -R;

		CPen penc1;
		penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		pDC->SelectObject(&penc1);
		//pDC->Arc(nLeftRect*Ptscale+TrPt_x,nTopRect*Ptscale+Trpt_y,nRightRect*Ptscale+TrPt_x,nBottomRect*Ptscale+Trpt_y,StartX*Ptscale+TrPt_x,StartY*Ptscale+Trpt_y,EndX*Ptscale+TrPt_x,EndY*Ptscale+Trpt_y);
		pDC->Arc(nLeftRect*Ptscale,nTopRect*Ptscale,nRightRect*Ptscale,nBottomRect*Ptscale,StartX*Ptscale,StartY*Ptscale,EndX*Ptscale,EndY*Ptscale);
		penc1.DeleteObject();
	}
	else //С��
	{
		TrPt_x=x_small;
		Trpt_y=y_small;
		nLeftRect = x_small-R;
		nTopRect = y_small+R;
		nRightRect = x_small+R;
		nBottomRect = y_small - R;

		CPen penc1;
		penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		pDC->SelectObject(&penc1);

		//pDC->Arc(nLeftRect*Ptscale+TrPt_x,nTopRect*Ptscale+Trpt_y,nRightRect*Ptscale+TrPt_x,nBottomRect*Ptscale+Trpt_y,StartX*Ptscale+TrPt_x,StartY*Ptscale+Trpt_y,EndX*Ptscale+TrPt_x,EndY*Ptscale+Trpt_y);
		pDC->Arc(nLeftRect*Ptscale,nTopRect*Ptscale,nRightRect*Ptscale,nBottomRect*Ptscale,StartX*Ptscale,StartY*Ptscale,EndX*Ptscale,EndY*Ptscale);
		penc1.DeleteObject();		
	}
}
