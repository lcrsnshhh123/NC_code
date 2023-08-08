#include "Interpolating.h"

void DrawLine(CDC* pDC,double StartX,double StartY,double EndX,double EndY, double Ptscale,double TrPt_x,double TrPt_y)
{
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(255,0,255));
	pDC->SelectObject(&pen);
	//使用 Polyline 函数绘制线段，该函数根据 p2p 数组中的点坐标连接成线段。
	POINT p2p[2] = { { StartX*Ptscale+TrPt_x,StartY*Ptscale+TrPt_y }, { EndX*Ptscale+TrPt_x,EndY*Ptscale+TrPt_y } };
	pDC->Polyline(p2p,2);
	pen.DeleteObject();
}