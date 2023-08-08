#pragma once
#include"Interpolating.h"
void DDA_line(double st,int n,double XS,double YS, double XE, double YE)
{

  double Xe=fabs(XE-XS);
  double Ye=fabs(YE-YS);
  int m=0;
  double X=0;
  double Y=0;
  double nu=64;
  double X0[100];
  double Y0[100];
  double x=XS;double y=YS;
  //panduanxiangxian 
  unsigned short quad=Judge_Quadrant(XE-XS,YE-YS);//判断象限

  while(!(m==nu))
  {
      //x方向//Y方向
	  X=X+Xe; 
	  Y=Y+Ye;
	 
	  if(X>=nu)
	  {
		  //x方向进给步长
       if(quad==1||quad==4)
	   {x=x+st;
	   }
	   else{x=x-st;
	   }
	   X=X-nu;
	  }
	  //记录当前的X点到数组中
	  X0[m]=x;
	  if(Y>=nu)
	  {
		  //Y方向进给步长
		  if(quad==1||quad==2)
	   {y=y+st;
	   }
	   else{y=y-st;
	   }
	    Y=Y-nu;
	  } 
	  //记录当前的X点到数组中
	  Y0[m]=y;
	  m++;
  }
  ofstream ofs;
  ofs.open("data/Results.txt",ios::out|ios::app);
  //ofs<<XS<<" "<<YS<<endl;
  for(int i=0;i<nu;i++)
  {ofs<<X0[i]<<" "<<Y0[i]<<endl;
  }
  ofs.close();
}