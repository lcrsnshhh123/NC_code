#pragma once
#include"add_heaer.h"
void get_local(string line,inf *line1,int num,int lenth)
{
	smatch results;
	char name[5]={'X','Y','R','I','K'};
	string Str[5]={"X(-)?[0-9]+(.[0-9]+)?","Y(-)?[0-9]+(.[0-9]+)?","R(-)?[0-9]+(.[0-9]+)?","I(-)?[0-9]+(.[0-9]+)?","K(-)?[0-9]+(.[0-9]+)?"};//
	regex X(Str[num]);
	//cout<<regex_search(line,results,X)<<endl;
	char temp1[100]={0};
	int len=0;
	if(regex_search(line,X))
	{
		string::const_iterator iterStart = line.begin();
        string::const_iterator iterEnd = line.end();
        string temp;
        while (regex_search(iterStart, iterEnd, results,X))
{
	     temp = results[0];
	    // cout << temp << endl;//�õ�Ŀ���ַ���
		 for(int i=0;i<temp.length();i++)//��ɸѡ����ַ�����ɸѡ����
		 { if(temp[i]!=name[num])
		  {
		    temp1[len]=temp[i];//���ַ����г�X�������ַ����뵽�ַ�������
		     len++;
		     }
		 }
	     iterStart = results[0].second;	//����������ʼλ��,����ʣ�µ��ַ���
}
		switch(num)//��ֵ
		{case 0:
			line1[lenth].m_x=stod(temp1);//z�ַ�����תΪ����
		    //cout<<"x����"<<line1[lenth].m_x<<endl;
			break;
		case 1:
			line1[lenth].m_y=stod(temp1);//z�ַ�����תΪ����
		   //cout<<"y����"<<line1[lenth].m_y<<endl;
			break;
		
		case 2:
			line1[lenth].m_r=stod(temp1);//z�ַ�����תΪ����
		    //cout<<"r����"<<line1[lenth].m_r<<endl;
			break;
		case 3:
			line1[lenth].m_i=stod(temp1);//z�ַ�����תΪ����
		    //cout<<"i����"<<line1[lenth].m_i<<endl;
			break;
		case 4:
			line1[lenth].m_k=stod(temp1);//z�ַ�����תΪ����
		    //cout<<"i����"<<line1[lenth].m_i<<endl;
			break;
		default:break;
		}
	}
		
	else{/*�հ�������:�����е��λ�ƣ��ʾ��Ա�̱������ϴ�������ͬ����Ա�̱������λ��Ϊ0*/
		if(lenth>0)
		{
		switch(num)//��ֵ
		{case 0:
		//if(line1[lenth-1].m_manner=="G90")//��һ��Ϊ���Ա��
			line1[lenth].m_x=line1[lenth-1].m_x;//z�ַ�����תΪ����
		//else line1[lenth].m_x=0;//��һ��Ϊ��Ա��
		    //cout<<"x����"<<line1[lenth].m_x<<endl;
			break;
		case 1:
			//if(line1[lenth-1].m_manner=="G90")//��һ��Ϊ���Ա��
			   line1[lenth].m_y=line1[lenth-1].m_y;//z�ַ�����תΪ����
			//else line1[lenth].m_y=0;//��һ��Ϊ��Ա��
		    //cout<<"y����"<<line1[lenth].m_y<<endl;
			break;
		
		case 2:
			//if(line1[lenth-1].m_manner=="G90")//��һ��Ϊ���Ա��
			   line1[lenth].m_r=line1[lenth-1].m_r;//z�ַ�����תΪ����
			//else line1[lenth].m_r=0;//��һ��Ϊ��Ա��
		    //cout<<"r����"<<line1[lenth].m_r<<endl;
			break;
		case 3:
			//if(line1[lenth-1].m_manner=="G90")//��һ��Ϊ���Ա��
			   line1[lenth].m_i=line1[lenth-1].m_i;//z�ַ�����תΪ����
			//else line1[lenth].m_i=0;//��һ��Ϊ��Ա��
		    //cout<<"i����"<<line1[lenth].m_i<<endl;
			break;
		case 4:
			//if(line1[lenth-1].m_manner=="G90")//��һ��Ϊ���Ա��
			   line1[lenth].m_k=line1[lenth-1].m_k;//z�ַ�����תΪ����
			//else line1[lenth].m_k=0;//��һ��Ϊ��Ա��
			break;
		default:break;
		}
		}
	}
	//y�����ȡ

}