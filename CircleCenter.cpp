#include "Interpolating.h"

using namespace std;

void CircleCenter(double x1,double y1,double x2,double y2,double R,double &x01,double &y01,double &x02,double &y02) 
{ 
	//x1 == x2
	if (abs(x1-x2)<0.0000001)
	{
		//（x1,y1)(x2,y2)之间的距离 /2
		double dis = abs(y1-y2)/2;
		double dx = sqrt(R*R-dis*dis);
		double dy = (y1+y2)/2;
		x01 = x1-dx;
		y01 = dy;
		x02 = x1+dx;
		y02 = dy;
		return ;
	}
	double c1 = (x2*x2 - x1*x1 + y2*y2 - y1*y1) / (2 *(x2 - x1)); 
	double c2 = (y2 - y1) / (x2 - x1);  //斜率
	double A = (c2*c2 + 1); 
	double B = (2 * x1*c2 - 2 * c1*c2 - 2 * y1); 
	double C = x1*x1 - 2 * x1*c1 + c1*c1 + y1*y1 - R*R; 
	y01 = (-B + sqrt(B*B - 4 * A*C)) / (2 * A);
	x01 = c1 - c2 * y01;  
	y02 = (-B - sqrt(B*B - 4 * A*C)) / (2 * A);
	x02 = c1 - c2*y02;
} 