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
	double x02;double y02;//˳ԲԲ��
	double x01;double y01;//��ԲԲ
	double R;
	double x1;double y1;//Բ������ľ�������
	double x2;double y2;
	double R2;double r2;
	double temp;
	CPen penc1;
	//double 	Ptscale=10;

	
	//�洢Ŀ���
	pos p[100]={0};
	

	for(int i=0;i<lenth;i++)
	{
		for (int j=0;j<4;j++)
		{if(m_line[i].m_shape==name[j])
		t=j;
		}
		//����Ҫ������������µ�ͼ�λ��ƣ���Ҫ��¼�������ϵ��ԭ���������ֵ��G00��G01,G02��G03����Ҫ��¼
		//����������
		if(i==0){x1=0;y1=0;}
		else{
		if(m_line[i-1].m_manner=="G90")//����-������
				{x1=m_line[i-1].m_x;y1=m_line[i-1].m_y;}
				else
				{x1=m_line[i-1].m_x+m_line[i-1].o_x/Ptscale;y1=m_line[i-1].m_y+m_line[i-1].o_y/Ptscale;}
		}
		//�����Ĳ�����ʾ
		/*if(i==0){
		show_point(pControlDC,i,x1,y1);
		}*/
		if(m_line[i].m_manner=="G90")
		{
			//cout<<"���Ա��";
			
			switch(t)
			{
			case 0:
				//cout<<"���ٵ㶨λ"<<endl;
				
				m_line[i].o_x=x1*Ptscale;//�������ϵ������ԭ���������
				m_line[i].o_y=y1*Ptscale;//�������ϵ��ԭ���������Y}
				x2=m_line[i].m_x;
				y2=m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				break;
			case 1:
				/*cout<<"ֱ�߻滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"ֱ�߻滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				
				
				m_line[i].o_x=x1*Ptscale;//�������ϵ������ԭ���������
				m_line[i].o_y=y1*Ptscale;//�������ϵ��ԭ���������Y}
				x2=m_line[i].m_x;
				y2=m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				EndPoint_x=x2-x1;//�������X
				EndPoint_y=y2-y1;//�������Y		
				DrawLine(pControlDC,0,0,EndPoint_x,EndPoint_y,Ptscale,m_line[i].o_x,m_line[i].o_y);//��ͼ����
				break;


			case 2:
				/*cout<<"˳Բ�滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"RΪ"<<m_line[i].m_r
					<<"˳Բ�滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				 R2=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				 r2=sqrt((m_line[i].m_x-x1-m_line[i].m_i)*(m_line[i].m_x-x1-m_line[i].m_i)+(m_line[i].m_y-y1-m_line[i].m_k)*(m_line[i].m_y-y1-m_line[i].m_k));
				x2=m_line[i].m_x;y2=m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				if(R2==r2)//����ik��̷�ʽ
				{
					R=R2;
					x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;//���Բ�ľ�������
					m_line[i].o_x=x01*Ptscale;//�������ϵ������Բ�ľ�������
				    m_line[i].o_y=y01*Ptscale;//�������ϵ��Բ�ľ�������Y
					//˳Բ��Ҫ�任����
					temp=x1;
		             x1=x2;
		            x2=temp;
		            temp=y1;
		            y1=y2;
		             y2=temp;
					 //����
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				}
				else{//��R��ͼ
				//����Բ��
				R=m_line[i].m_r;
				DrawCircle(pControlDC,x1,y1,x2,y2,R,Ptscale,m_line[i].o_x,m_line[i].o_y,2);
				}
				
				break;



			case 3:
				/*cout<<"��ԲԲ�滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"RΪ"<<m_line[i].m_r
					<<"��Բ�滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				//����Բ��
				
				 R2=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				 r2=sqrt((m_line[i].m_x-x1-m_line[i].m_i)*(m_line[i].m_x-x1-m_line[i].m_i)+(m_line[i].m_y-y1-m_line[i].m_k)*(m_line[i].m_y-y1-m_line[i].m_k));
				x2=m_line[i].m_x;y2=m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				if(R2==r2)//����ik��̷�ʽ
				{
					R=R2;
					x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;//���Բ�ľ�������
					m_line[i].o_x=x01*Ptscale;//�������ϵ������Բ�ľ�������
				    m_line[i].o_y=y01*Ptscale;//�������ϵ��Բ�ľ�������Y
					//����
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				}
				else{//��R��ͼ
				//����Բ��
				R=m_line[i].m_r;
				DrawCircle(pControlDC,x1,y1,x2,y2,R,Ptscale,m_line[i].o_x,m_line[i].o_y,3);
				}
				
				
				break;
			
			}
		
		}
		else{
		//cout<<"��Ա��";
		switch(t)
			{
			case 0:
				//cout<<"���ٵ㶨λ"<<endl;
				
				
				m_line[i].o_x=x1*Ptscale;//�������ϵ������ԭ���������
				m_line[i].o_y=y1*Ptscale;//�������ϵ��ԭ���������
				x2=x1+m_line[i].m_x;
				y2=y1+m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				break;
			case 1:
				/*cout<<"ֱ�߻滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"ֱ�߻滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				m_line[i].o_x=x1*Ptscale;//�������ϵ������ԭ���������
				m_line[i].o_y=y1*Ptscale;//�������ϵ��ԭ���������
				x2=x1+m_line[i].m_x;
				y2=y1+m_line[i].m_y;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				EndPoint_x=m_line[i].m_x;//�������X
				EndPoint_y=m_line[i].m_y;//�������Y
				DrawLine(pControlDC,0,0,EndPoint_x,EndPoint_y,Ptscale,m_line[i].o_x,m_line[i].o_y);//��ͼ����
				break;
			case 2:
				/*cout<<"˳Բ�滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"RΪ"<<m_line[i].m_r
					<<"˳Բ�滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				x02=x1+m_line[i].m_i;y02=y1+m_line[i].m_k;
				R=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				x2=x02+m_line[i].m_x;y2=m_line[i].m_y+y02;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
				m_line[i].o_x=x02*Ptscale;//�������ϵ������Բ�ľ�������
				m_line[i].o_y=y02*Ptscale;//�������ϵ��Բ�ľ�������Y
					//˳Բ��Ҫ�任����
					temp=x1;
		             x1=x2;
		            x2=temp;
		            temp=y1;
		            y1=y2;
		             y2=temp;
					 //����
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x02-R)*Ptscale,(y02+R)*Ptscale,(x02+R)*Ptscale,(y02-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
					break;
			case 3:
				/*cout<<"��ԲԲ�滭���X"<<m_line[i-1].m_x<<"���Y"<<m_line[i-1].m_y
					<<"RΪ"<<m_line[i].m_r
					<<"��Բ�滭�յ�X"<<m_line[i].m_x<<"�յ�Y"<<m_line[i].m_y<<endl;*/
				x01=x1+m_line[i].m_i;y01=y1+m_line[i].m_k;
				R=sqrt(m_line[i].m_i*m_line[i].m_i+m_line[i].m_k*m_line[i].m_k);
				x2=x01+m_line[i].m_x;y2=m_line[i].m_y+y01;
				//�����Ĳ�����ʾ
				show_point(pControlDC,i,x2,y2,p);
				p[i].m_x=x2;p[i].m_y=y2;
			    m_line[i].o_x=x01*Ptscale;//�������ϵ������Բ�ľ�������
				m_line[i].o_y=y01*Ptscale;//�������ϵ��Բ�ľ�������Y
				//����
					
		            penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
		            pControlDC->SelectObject(&penc1);
                    pControlDC->Arc((x01-R)*Ptscale,(y01+R)*Ptscale,(x01+R)*Ptscale,(y01-R)*Ptscale,x1*Ptscale,y1*Ptscale,x2*Ptscale,y2*Ptscale);
		            penc1.DeleteObject();
				break;
			
			}
		}
		
		}
		//����txt�ļ�������ÿ��ͼ�������ԭ�㣻
		//txt_oxy(m_line);
		//show_piont(pControlDC,p);
	}


