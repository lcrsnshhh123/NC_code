#pragma once
#include"add_heaer.h"
#include"GT_Move.h"
void gotoG00(inf *m_line,int &spenum,int &G0num)
{
	short rtn;
	double TrPt_x;
	double TrPt_y;
	//�ʼ�̧��
			GTInitial();
		InputCfg();
		//AxisInitialSV();
		AxisInitialSG();
		MapAxis();
		rtn=GT_ExOpt(65535); 

		//�˶�
		if(m_line[spenum].m_manner=="G90")
		{TrPt_x=m_line[spenum].m_x-m_line[spenum].o_x/10;
		TrPt_y=m_line[spenum].m_y-m_line[spenum].o_y/10;}
		else
		{TrPt_x=m_line[spenum].m_x;
		TrPt_y=m_line[spenum].m_y;}
		rtn=GT_LnXY(TrPt_x,TrPt_y);GT_error(rtn);
		// TODO: �ʼ�����
		GTInitial();
		InputCfg();
		//AxisInitialSV();
		AxisInitialSG();
		MapAxis();
		short rtn;
		rtn=GT_ExOpt(0); //GT_error(rtn);
			G0num++;
			spenum++;
		AfxMessageBox(_T("���G00�岹�˶�!"),MB_OKCANCEL);

}