#pragma once
#include"add_heaer.h"
void get_manner(string line,inf *line1,int lenth)
{
	smatch results; 
	string temp;
	string manner="(G9[0|1])";//设置目标
	regex pattern(manner);//生成regex类的对象
	//cout<<regex_search(line,results,pattern)<<endl;
	if(regex_search(line,results,pattern))
	{
		line1[lenth].m_manner=results[0];
		//cout<<line1[lenth].m_manner<<endl;
		
	}
	else
	{//等于上次的编程方式
		if(lenth>0)
			line1[lenth].m_manner=line1[lenth-1].m_manner;
	}

}