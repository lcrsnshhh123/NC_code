#include "Interpolating.h"

void ShowTrack(CDC* pDC,char filename[100], double Ptscale,double TrPt_x,double TrPt_y)
{
	int hcount=gethcount(filename);
	POINT *pt=new POINT[hcount];
	float x,y;
	FILE *f;
	if (NULL == (f = fopen(filename, "r+")))
	{
		AfxMessageBox(_T("不能打开文件！"),MB_OKCANCEL);
	}
	int i=0;
	char buf[256];
	while (i<=hcount)
	{
		if (NULL == fgets(buf, 256, f)) break;
		sscanf(buf, "%f %f",&x,&y);
		pt[i].x=(long)(x*Ptscale+TrPt_x);
		pt[i].y=(long)(y*Ptscale+TrPt_y);
		i++;
	}
	CPen pen;
	pen.CreatePen(PS_SOLID,2,RGB(255,255,255));
	pDC->SelectObject(&pen);
	pDC->Polyline(pt,hcount);
	pen.DeleteObject();
}
