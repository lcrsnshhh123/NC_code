#pragma once
#include"add_heaer.h"
#include"GT_Move.h"
void gotoG01(inf *m_line,int &spenum,int &G0num)
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
			
			TrPt_x=0;
			TrPt_y=0;

			//对当前图形进行插补
			DrawTrack(temp1,TrPt_x,TrPt_y);
			spenum++;
			AfxMessageBox(_T("完成G01插补运动!"),MB_OKCANCEL);
}