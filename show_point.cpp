#pragma once;

#include"add_heaer.h"

void show_point(CDC* pDC,int i,double x2,double y2,pos *p)
{
	//���ʶ���
	CPen penc1;
	penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
	pDC->SelectObject(&penc1);
	char d='A'+i;
	string s1(1,d);
	string s2="(";
	string s3;
	stringstream ss;
    ss<<fixed<<setprecision(0)<<x2;//����4λС�������ȥ��fixed������4λ��Ч����
    s3=ss.str();
	string s4=",";
	stringstream ss1;
	string s5;
	ss1<<fixed<<setprecision(0)<<y2;
	s5=ss1.str();
	string s6=")";
	string str=s1+s2+s3+s4+s5+s6;
	CString str0;
		str0=str.c_str();

    for(int j=0;j<i;j++)
	{
	if(p[j].m_x==x2&&p[j].m_y==y2)
     {
		x2=x2;
		y2=y2+2;

      }
	}
    SetTextColor(*pDC, RGB(255, 170, 0));
    SetBkMode(*pDC, TRANSPARENT);
	pDC->TextOutW(x2*10,y2*10,str0);

}
	/*
	struct memery
	{
	double x;
	double y;
	int sum;
	int loc[100];
	
	}

	void show_point(CDC* pDC,pos *p)
	{
	//��������
	CPen penc1;
	penc1.CreatePen(PS_SOLID,2,RGB(255,0,255));
	pDC->SelectObject(&penc1);
	//�������ݣ�p�����߶ε��յ�
	int p_lenth=sizeof(p)/sizeof(p[0]);
	//������з���
	memery m[100]={0};
	int size=0;
	for(int i=0;i<p_lenth;i++)
	{
	 for(int j=0;j<=size;j++)
	  {
	  if(p[i].x==m[j].x&&p[i].y==m[j].y)
	 {
	 m[j].loc[ m[j].sum]=i;
	 m[j].sum++;
	 break;
	 }
	  else 
	  {
	  m[size].x=p[i].x;m[size].y=p[i].y;
	   m[size].loc[m[j].sum]=i; m[size].sum++;
	   size++;
	  }

	  }
	}
	
	//��ɵ����������	
	SetTextColor(*pDC, RGB(255, 170, 0));
    SetBkMode(*pDC, TRANSPARENT);
	CString str0;
	char mytype;
	string s1,sums;
	//���A,B,C,D,
	for(int z=0;z<size;z++)
	{
	x2=m[z].x;y2=m[z].y;
	for(int d=0;d<m[z].sum;d++)
	 {
	 mytype='A'+i;
	 s1=mytype+',';???
	 sum+=s1;
	 }
	 //��ã�x2,y2��
	string s2="(";
	string s3;
	stringstream ss;
    ss<<fixed<<setprecision(0)<<x2;//����4λС�������ȥ��fixed������4λ��Ч����
    s3=ss.str();
	string s4=",";
	stringstream ss1;
	string s5;
	ss1<<fixed<<setprecision(0)<<y2;
	s5=ss1.str();
	string s6=")";

	//�õ�str=A,B,C,(x2,y2)
	str=sum+s2+s3+s4+s5+s6;
	CString str0;
		str0=str.c_str();
   //�����
    pDC->TextOutW(x2*10,y2*10,str0);
	
	}

	
	
	
	
	
	}
	
	
	*/