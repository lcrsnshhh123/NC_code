#pragma once
#include"add_heaer.h"
#include"GT_Move.h"
void gotoG00(inf *m_line,int &spenum,int &G0num)
{
	short rtn;
	double TrPt_x;
	double TrPt_y;
	//笔架抬起
			GTInitial();
		InputCfg();
		//AxisInitialSV();
		AxisInitialSG();
		MapAxis();
		rtn=GT_ExOpt(65535); 

		//运动
		if(m_line[spenum].m_manner=="G90")
		{TrPt_x=m_line[spenum].m_x-m_line[spenum].o_x/10;
		TrPt_y=m_line[spenum].m_y-m_line[spenum].o_y/10;}
		else
		{TrPt_x=m_line[spenum].m_x;
		TrPt_y=m_line[spenum].m_y;}
		rtn=GT_LnXY(TrPt_x,TrPt_y);GT_error(rtn);
		// TODO: 笔架落下
		GTInitial();
		InputCfg();
		//AxisInitialSV();
		AxisInitialSG();
		MapAxis();
		short rtn;
		rtn=GT_ExOpt(0); //GT_error(rtn);
			G0num++;
			spenum++;
		AfxMessageBox(_T("完成G00插补运动!"),MB_OKCANCEL);

}