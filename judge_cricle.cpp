#pragma once
#include"Interpolating.h"
//含义是判断两个圆的位置关系，并根据条件交换它们的坐标。
void judge_cricle(double &x1,double &y1,double &x2,double &y2,double &x_big,double &y_big,double &x_small,double &y_small,double x01,double y01,double x02,double y02,int t)
{
	double temp=0;
if((x1<=x2&&y1<=y2)||(x1<=x2&&y1>y2))
{if(t==3){
	    x_big = x02;
		y_big = y02;
		x_small = x01;
		y_small = y01;
}
else{
		x_big = x01;
		y_big = y01;
		x_small = x02;
		y_small = y02;
		temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
}
       
}
else{
	if((x1>x2&&y1<y2)||(x1>x2&&y1>=y2))
	{if(t==3){
	    x_big = x01;
		y_big = y01;
		x_small = x02;
		y_small = y02;
      }
else{
		x_big = x02;
		y_big = y02;
		x_small = x01;
		y_small = y01;
		temp=x1;
		x1=x2;
		x2=temp;
		temp=y1;
		y1=y2;
		y2=temp;
}
	}
}

}