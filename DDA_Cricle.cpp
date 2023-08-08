#pragma once
#include"Interpolating.h"
#include"add_heaer.h"
#include"inf.h"
void DDA_circle(double step, double XStart, double YStart, double XEnd,double YEnd, double radius, int bIsCW)
{
	double JVX=fabs(YStart);
	double JVY=fabs(XStart);
	double JRX=0;
	double JRY=0;
	double JX;
	double JY;
	double x=XStart;double y=YStart;
	
	double X0[100];
    double Y0[100];
	int i=0,j=0;
	int m=0;

	if(XEnd==XStart)
		{ 
			if((XStart<0&&YEnd>YStart)||(XStart>0&&YEnd<YStart))
				JX=2*(radius+fabs(XStart));
			else 
				{if((XStart<0&&YEnd<YStart)||(XStart>0&&YEnd>YStart))
			    JX=2*(radius-fabs(XStart));
				else 
					JX=4*(radius);}
	}
	else 
	{
		JX=fabs(XEnd-XStart);}
	if(YEnd==YStart)
		{if((YStart<0&&XEnd>XStart)||(YStart>0&&XEnd<YStart))
				 JY=2*(radius-fabs(YStart));
			else 
				{if((YStart<0&&XEnd<XStart)||(YStart>0&&XEnd>XStart))
			   JY=2*(radius+fabs(YStart));
				else 
					JY=4*(radius);}}
	else  
	{
		/*if(YEnd<YStart&&YStart<0)
		{if(XEnd<)
		}*/
		JY=fabs(YEnd-YStart);
	}
	/*pos p;
	p=get_criclesetcount(XStart,YStart,XEnd,YEnd,radius);
	JX=p.m_x;
	JY=p.m_y;*/
  /* if((XEnd-XStart)>0)
	{
	if((YEnd-YStart)>0)
	t=4;
	else t=3;
	}
	else
	{
		if((YEnd-YStart)>0)
	t=1;
	else t=2;
	}*/
	unsigned short t;
	X0[0]=x;Y0[0]=y;m++;

	while(1)
	{
	t=judgexy(x,y);
	if(JX!=0)
	{
		JRX=JRX+JVX;
		if(JRX>=64)//预设2的5次方
		{//x前进一个步长
			if(t==2||t==1)x--;
			else x++;
			JRX=JRX-64;
			i=1;
		    JX--;	
		}	
	
	}
	

	if(JY!=0)
	{
		JRY=JRY+JVY;
		if(JRY>=64)//预设2的5次方
		{//Y前进一个步长
			if(t==2||t==3)y--;
			else y++;
			JRY=JRY-64;
			j=1; 
			JY--;
		}
	
	}
	else{
	if((JY==0)&&(JX==0))
	  {
	    break;
	    }
	  }
	if(i==1||j==1)
	{
		X0[m]=x;
        Y0[m]=y;
		m++;
	}

	 if(i==1)
	    {
		 if(t==1||t==3)
		 JVY--;
		 else  JVY++;
		}
	 if(j==1) 
	 {
		 if(t==2||t==4)
		 JVX--;
		 else  JVX++;
		 }
	 j=0;
	i=0;
	}
	X0[m]=XEnd;Y0[m]=YEnd;m++;
	ofstream ofs;
  ofs.open("data/Results.txt",ios::out|ios::app);

  for(int i=0;i<m;i++)
  {ofs<<X0[i]<<" "<<Y0[i]<<endl;
  }
  ofs.close();

}