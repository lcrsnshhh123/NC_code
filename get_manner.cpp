#pragma once
#include"add_heaer.h"
void get_manner(string line,inf *line1,int lenth)
{
	smatch results; 
	string temp;
	string manner="(G9[0|1])";//����Ŀ��
	regex pattern(manner);//����regex��Ķ���
	//cout<<regex_search(line,results,pattern)<<endl;
	if(regex_search(line,results,pattern))
	{
		line1[lenth].m_manner=results[0];
		//cout<<line1[lenth].m_manner<<endl;
		
	}
	else
	{//�����ϴεı�̷�ʽ
		if(lenth>0)
			line1[lenth].m_manner=line1[lenth-1].m_manner;
	}

}