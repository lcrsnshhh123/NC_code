#pragma once
#include"add_heaer.h"
void get_shape(string line,inf *line1,int lenth)
{
	smatch results;
	string shape="(G00|G01|G02|G03)";
	regex sh(shape);
	//cout<<regex_search(line,results,sh)<<endl;//判断是否有
	if(regex_search(line,results,sh))
	{
		line1[lenth].m_shape=results[0];
		//cout<<line1[lenth].m_shape<<endl;
	}
	else
	{//等于上次的编程方式
		if(lenth>0)
			line1[lenth].m_shape=line1[lenth-1].m_shape;
	}

}