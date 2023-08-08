#pragma once
#include"Interpolating.h"
#include"inf.h"
void get_manner(string line,inf *line1,int lenth);
void get_shape(string line,inf *line1,int lenth);
void get_local(string line,inf *line1,int num,int lenth);
void get_oxy(inf *m_line,int lenth,CDC * pControlDC,double Ptscale);
void show_point(CDC* pDC,int i,double x2,double y2,pos *p);
unsigned short judgexy(double x,double y);
pos get_criclesetcount(double sx,double sy,double ex,double ey,double r);
//void show_point(CDC* pDC,pos *p);
void gotoG00(inf *m_line,int &spenum,int &G0num);
void gotoG01(inf *m_line,int &spenum,int &G0num);
void gotoG02(inf *m_line,int &spenum,int &G0num);
void gotoG03(inf *m_line,int &spenum,int &G0num);