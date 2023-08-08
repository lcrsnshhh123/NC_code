#pragma once
#include"add_heaer.h"
#include"Interpolating.h"
pos get_criclesetcount(double sx,double sy,double ex,double ey,double r)
{
	double numbx=0;
	double numby=0;
	double x=sx;
	double y=sy;
	double t,d;
	t=judgexy(x,y);
	d=judgexy(ex,ey); 
	double cha;
		if(d==t)cha=0;
		else	if(fabs(d-t)<0)
		           {cha=d-t+3;}
		        else cha=fabs(d-t)-1;
	if((t==1&&d==2)||(t==1&&d==4)){numbx=r*cha+fabs(sx)+fabs(ex);numby=r*cha+r-fabs(sy)+r-fabs(ey);}
	if((t==1&&d==3)){numbx=r*cha+fabs(sx)+r-fabs(ex);numby=r*cha+r-fabs(sy)+fabs(ey);}
	if(t==1&&d==1){numbx=r*cha+fabs(sx)-fabs(ex);numby=r*cha-fabs(sy)+fabs(ey);}

   if((t==2&&d==1)||(t==2&&d==4)){numbx=r*cha+r-fabs(sx)+fabs(ex);numby=r*cha+fabs(sy)+r-fabs(ey);}
	if((t==2&&d==3)){numbx=r*cha+r-fabs(sx)+r-fabs(ex);numby=r*cha+fabs(sy)+fabs(ey);}
	if(t==2&&d==2){numbx=r*cha+fabs(sx)-fabs(ex);numby=r*cha+fabs(sy)-fabs(ey);}

	if((t==3&&d==2)||(t==3&&d==4)){numbx=r*cha+fabs(sx)+fabs(ex);numby=r*cha+r-fabs(sy)+r-fabs(ey);}
	if((t==3&&d==1)){numbx=r*cha+fabs(sx)+r-fabs(ex);numby=r*cha+r-fabs(sy)+fabs(ey);}
	if(t==3&&d==3){numbx=r*cha+fabs(sx)-fabs(ex);numby=r*cha-fabs(sy)+fabs(ey);}

	if((t==4&&d==2)){numbx=r*cha+r-fabs(sx)+fabs(ex);numby=r*cha+fabs(sy)+r-fabs(ey);}
	if((t==4&&d==3)||(t==4&&d==1)){numbx=r*cha+r-fabs(sx)+r-fabs(ex);numby=r*cha+fabs(sy)+fabs(ey);}
   if(t==4&&d==4){numbx=r*cha+fabs(sx)-fabs(ex);numby=r*cha+fabs(sy)-fabs(ey);}
   pos p;
   p.m_x=numbx;
   p.m_y=numby;
	return p;

}