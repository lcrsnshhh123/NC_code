#include "Interpolating.h"

void DrawLine(CDC* pDC,double StartX,double StartY,double EndX,double EndY, double Ptscale,double TrPt_x,double TrPt_y)
{
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(255,0,255));
	pDC->SelectObject(&pen);
	//ʹ�� Polyline ���������߶Σ��ú������� p2p �����еĵ��������ӳ��߶Ρ�
	POINT p2p[2] = { { StartX*Ptscale+TrPt_x,StartY*Ptscale+TrPt_y }, { EndX*Ptscale+TrPt_x,EndY*Ptscale+TrPt_y } };
	pDC->Polyline(p2p,2);
	pen.DeleteObject();
}