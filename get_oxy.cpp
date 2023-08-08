#pragma once
#include"add_heaer.h"
#include "stdafx.h"
#include "afxdialogex.h"
#include "MyNewDlg.h"
#include"resource.h"
void get_oxy(inf *m_line,int lenth,CDC * pControlDC,double Ptscale)
{

	string name[4]={"G00","G01","G02","G03"};
	int t;
	double EndPoint_x;double EndPoint_y;
	double StartPoint_x;double StartPoint_y;
	double x02;double y02;//顺圆圆心
	double x01;double y01;//逆圆圆
	double R;
	double x1;double y1;//圆上两点的绝对坐标
	double x2;double y2;
	double R2;double r2;
	double temp;
	CPen penc1;
	//double 	Ptscale=10;

	
	//存储目标点
	pos p[100]={0};
	

	for(int i=0;i<lenth;i++)
	{
		for (int j=0;j<4;j++)
		{if(m_line[i].m_shape==name[j])
		t=j;
		}
		//因需要进行相对坐标下的图形绘制，需要记录相对坐标系的原点坐标绝对值，G00，G01,G02，G03都需要记录
		//起点绝对坐标
		if(i==0){x1=0;y1=0;}
		else{
		if(m_line[i-1].m_manner=="G90")//绝对-》绝对
				{x1=m_line[i-1].m_x;y1=m_line[i-1].m_y;}
				else
				{x1=m_line[i-1].m_x+m_line[i-1].o_x/Ptscale;y1=m_line[i-1].m_y+m_line[i-1].o_y/Ptscale;}
		}
		//坐标点的参数显示
		/*if(i==0){
		show_point(pControlDC,i,x1,y1);
		}*/
		if(m_line[i].m_manner=="G90")
		{
			//cout<<"绝对编程";
			
			switch(t)
			{
			case 0:
				//cout<<"快速点定位"<<endl;
				
				m_line[i].o_x=x1*Ptscale;//相对坐标系的坐标原点绝对坐标
				m_line[i].o_y=y1*Ptscale;//相对坐标系中原点绝对坐标Y}
				x2=m_line[i].m_x;
				y2=m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				break;
			case 1:
				/*cout<<"直线绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"直线绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				
				
				m_line[i].o_x=x1*Ptscale;//相对坐标系的坐标原点绝对坐标
				m_line[i].o_y=y1*Ptscale;//相对坐标系中原点绝对坐标Y}
				x2=m_line[i].m_x;
				y2=m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				EndPoint_x=x2-x1;//相对坐标X
				EndPoint_y=y2-y1;//相对坐标Y		
				DrawLine(pControlDC,0,0,EndPoint_x,EndPoint_y,Ptscale,m_line[i].o_x,m_line[i].o_y);//画图程序
				break;


			case 2:
				/*cout<<"顺圆绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"R为"<<m_line[i].m_r
					<<"顺圆绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				 R2=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				 r2=sqrt((m_line[i].m_x-x1-m_line[i].m_i)*(m_line[i].m_x-x1-m_line[i].m_i)+(m_line[i].m_y-y1-m_line[i].m_k)*(m_line[i].m_y-y1-m_line[i].m_k));
				x2=m_line[i].m_x;y2=m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				if(R2==r2)//采用ik编程方式
				{
					R=R2;
					x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;//求出圆心绝对坐标
					m_line[i].o_x=x01*Ptscale;//相对坐标系的坐标圆心绝对坐标
				    m_line[i].o_y=y01*Ptscale;//相对坐标系中圆心绝对坐标Y
					//顺圆需要变换坐标
					temp=x1;
		             x1=x2;
		            x2=temp;
		            temp=y1;
		            y1=y2;
		             y2=temp;
					 //画笔
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				}
				else{//用R求画图
				//先求圆心
				R=m_line[i].m_r;
				DrawCircle(pControlDC,x1,y1,x2,y2,R,Ptscale,m_line[i].o_x,m_line[i].o_y,2);
				}
				
				break;



			case 3:
				/*cout<<"逆圆圆绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"R为"<<m_line[i].m_r
					<<"逆圆绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				//先求圆心
				
				 R2=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				 r2=sqrt((m_line[i].m_x-x1-m_line[i].m_i)*(m_line[i].m_x-x1-m_line[i].m_i)+(m_line[i].m_y-y1-m_line[i].m_k)*(m_line[i].m_y-y1-m_line[i].m_k));
				x2=m_line[i].m_x;y2=m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				if(R2==r2)//采用ik编程方式
				{
					R=R2;
					x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;//求出圆心绝对坐标
					m_line[i].o_x=x01*Ptscale;//相对坐标系的坐标圆心绝对坐标
				    m_line[i].o_y=y01*Ptscale;//相对坐标系中圆心绝对坐标Y
					//画笔
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				}
				else{//用R求画图
				//先求圆心
				R=m_line[i].m_r;
				DrawCircle(pControlDC,x1,y1,x2,y2,R,Ptscale,m_line[i].o_x,m_line[i].o_y,3);
				}
				
				
				break;
			
			}
		
		}
		else{
		//cout<<"相对编程";
		switch(t)
			{
			case 0:
				//cout<<"快速点定位"<<endl;
				
				
				m_line[i].o_x=x1*Ptscale;//相对坐标系的坐标原点绝对坐标
				m_line[i].o_y=y1*Ptscale;//相对坐标系中原点绝对坐标
				x2=x1+m_line[i].m_x;
				y2=y1+m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				break;
			case 1:
				/*cout<<"直线绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"直线绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				m_line[i].o_x=x1*Ptscale;//相对坐标系的坐标原点绝对坐标
				m_line[i].o_y=y1*Ptscale;//相对坐标系中原点绝对坐标
				x2=x1+m_line[i].m_x;
				y2=y1+m_line[i].m_y;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				EndPoint_x=m_line[i].m_x;//相对坐标X
				EndPoint_y=m_line[i].m_y;//相对坐标Y
				DrawLine(pControlDC,0,0,EndPoint_x,EndPoint_y,Ptscale,m_line[i].o_x,m_line[i].o_y);//画图程序
				break;
			case 2:
				/*cout<<"顺圆绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"R为"<<m_line[i].m_r
					<<"顺圆绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				x02=x1+m_line[i].m_i;y02=y1+m_line[i].m_k;
				R=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				x2=x02+m_line[i].m_x;y2=m_line[i].m_y+y02;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				m_line[i].o_x=x02*Ptscale;//相对坐标系的坐标圆心绝对坐标
				m_line[i].o_y=y02*Ptscale;//相对坐标系中圆心绝对坐标Y
					//顺圆需要变换坐标
					temp=x1;
		             x1=x2;
		            x2=temp;
		            temp=y1;
		            y1=y2;
		             y2=temp;
					 //画笔
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x02-R)*Ptscale,(y02+R)*Ptscale,(x02+R)*Ptscale,(y02-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
					break;
			case 3:
				/*cout<<"逆圆圆绘画起点X"<<m_line[i-1].m_x<<"起点Y"<<m_line[i-1].m_y
					<<"R为"<<m_line[i].m_r
					<<"逆圆绘画终点X"<<m_line[i].m_x<<"终点Y"<<m_line[i].m_y<<endl;*/
				x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;
				R=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				x2=x01+m_line[i].m_x;y2=m_line[i].m_y+y01;
				//坐标点的参数显示
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
			    m_line[i].o_x=x01*Ptscale;//相对坐标系的坐标圆心绝对坐标
				m_line[i].o_y=y01*Ptscale;//相对坐标系中圆心绝对坐标Y
				//画笔
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				break;
			
			}
		}
		
		}
		//生成txt文件，保存每个图像的坐标原点；
		//txt_oxy(m_line);
		//show_piont(pControlDC,p);
	}


