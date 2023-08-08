#include "Interpolating.h"

void DrawLocalAxle(CDC* pDC,int rWidth,int rHeight)
{
	//»­XÖá
	pDC->MoveTo(0,0);
	pDC->LineTo(rWidth,0);
	//»­YÖá
	pDC->MoveTo(0,0);
	pDC->LineTo(0,rHeight);
	CPen pen;
	pen.CreatePen(PS_SOLID,0.1,RGB(0,0,255));
	pDC->SelectObject(&pen);

	//»­XÖá¿Ì¶È
	CString str;
	for(int i=0;i<=rWidth;i+=10)
	{
		pDC->MoveTo(i,0);
		pDC->LineTo(i,rHeight);
	}
	for(int i=0;i<=rWidth;i+=10)
	{
		str.Format(_T("%d"), (int)i);
		pDC->TextOut(10*i, -2, str);
	}
	//»­YÖá¿Ì¶È
	for(int i=0;i<=rHeight;i+=10)
	{
		pDC->MoveTo(0,i);
		pDC->LineTo(rWidth,i);
	}
	for(int i=10;i<=rHeight;i+=10)
	{
		str.Format(_T("%d"), (int)i);
		pDC->TextOut(-18, i*10, str);
	}
	pen.DeleteObject();
}