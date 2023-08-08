#include "Interpolating.h"
#include "GT_Move.h"

void DrawTrack(char filename[100],double TrPt_x,double TrPt_y)
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

	short rtn;
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();
	rtn=GT_ExOpt(0); //GT_error(rtn);  // 笔架落下

	rtn=GT_StrtList();GT_error(rtn);
	rtn=GT_MvXY(0,0,0.01,0.000000001);GT_error(rtn);//起点坐标0,0

	while (i<=hcount)
	{
		if (NULL == fgets(buf, 256, f)) break;
		sscanf(buf, "%f %f",&x,&y);
		pt[i].x=(long long)(x+TrPt_x);
		pt[i].y=(long long)(y+TrPt_y);

	   rtn=GT_LnXY(pt[i].x,pt[i].y);GT_error(rtn);

	   i++;
	}
	

	rtn=GT_EndList();GT_error(rtn);
	rtn=GT_StrtMtn();GT_error(rtn);
	rtn=GT_Close();
}
