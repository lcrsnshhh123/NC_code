#pragma once
#include"add_heaer.h"
#include"GT_Move.h"
void gotoG03(inf *m_line,int &spenum,int &G0num)
{
	int n1=spenum-G0num;
	string s10;
	string s20;
	string s30;
	string str0;
	char temp1[100];
	stringstream ss1;
	const char *s11;
	int z1;
	char a1[100];
	double TrPt_x;
	double TrPt_y;
	short rtn; 
	        s10="data/Results"; 
			sprintf (a1,"%d", n1); 
			s20=a1;
			s30=".txt";
			str0=s10+s20+s30;
			s11=str0.c_str();

			for( z1=0;z1<str0.length();z1++)
				temp1[z1] =str0[z1];
			temp1[z1] = '\0'; 
			
			if(m_line[spenum].m_manner=="G90")//绝对-》绝对
				{TrPt_x=m_line[spenum].o_x/10-m_line[spenum-1].m_x;
				TrPt_y=m_line[spenum].o_y/10-m_line[spenum-1].m_y;}
				else
				{TrPt_x=m_line[spenum].o_x/10-m_line[spenum-1].m_x-m_line[spenum-1].o_x/10;
				TrPt_y=m_line[spenum].o_y/10-m_line[spenum-1].m_y-m_line[spenum-1].o_y/10;}

			//对当前图形进行插补
			DrawTrack(temp1,TrPt_x,TrPt_y);
			spenum++;
			AfxMessageBox(_T("完成G03插补运动!"),MB_OKCANCEL);
}