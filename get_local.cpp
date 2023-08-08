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
	    // cout << temp << endl;//得到目标字符串
		 for(int i=0;i<temp.length();i++)//从筛选完的字符串中筛选坐标
		 { if(temp[i]!=name[num])
		  {
		    temp1[len]=temp[i];//将字符串中除X的数字字符输入到字符数组中
		     len++;
		     }
		 }
	     iterStart = results[0].second;	//更新搜索起始位置,搜索剩下的字符串
}
		switch(num)//赋值
		{case 0:
			line1[lenth].m_x=stod(temp1);//z字符数组转为数字
		    //cout<<"x坐标"<<line1[lenth].m_x<<endl;
			break;
		case 1:
			line1[lenth].m_y=stod(temp1);//z字符数组转为数字
		   //cout<<"y坐标"<<line1[lenth].m_y<<endl;
			break;
		
		case 2:
			line1[lenth].m_r=stod(temp1);//z字符数组转为数字
		    //cout<<"r坐标"<<line1[lenth].m_r<<endl;
			break;
		case 3:
			line1[lenth].m_i=stod(temp1);//z字符数组转为数字
		    //cout<<"i坐标"<<line1[lenth].m_i<<endl;
			break;
		case 4:
			line1[lenth].m_k=stod(temp1);//z字符数组转为数字
		    //cout<<"i坐标"<<line1[lenth].m_i<<endl;
			break;
		default:break;
		}
	}
		
	else{/*空白行坐标:不进行点的位移，故绝对编程保持与上次坐标相同，相对编程保持相对位移为0*/
		if(lenth>0)
		{
		switch(num)//赋值
		{case 0:
		//if(line1[lenth-1].m_manner=="G90")//上一行为绝对编程
			line1[lenth].m_x=line1[lenth-1].m_x;//z字符数组转为数字
		//else line1[lenth].m_x=0;//上一行为相对编程
		    //cout<<"x坐标"<<line1[lenth].m_x<<endl;
			break;
		case 1:
			//if(line1[lenth-1].m_manner=="G90")//上一行为绝对编程
			   line1[lenth].m_y=line1[lenth-1].m_y;//z字符数组转为数字
			//else line1[lenth].m_y=0;//上一行为相对编程
		    //cout<<"y坐标"<<line1[lenth].m_y<<endl;
			break;
		
		case 2:
			//if(line1[lenth-1].m_manner=="G90")//上一行为绝对编程
			   line1[lenth].m_r=line1[lenth-1].m_r;//z字符数组转为数字
			//else line1[lenth].m_r=0;//上一行为相对编程
		    //cout<<"r坐标"<<line1[lenth].m_r<<endl;
			break;
		case 3:
			//if(line1[lenth-1].m_manner=="G90")//上一行为绝对编程
			   line1[lenth].m_i=line1[lenth-1].m_i;//z字符数组转为数字
			//else line1[lenth].m_i=0;//上一行为相对编程
		    //cout<<"i坐标"<<line1[lenth].m_i<<endl;
			break;
		case 4:
			//if(line1[lenth-1].m_manner=="G90")//上一行为绝对编程
			   line1[lenth].m_k=line1[lenth-1].m_k;//z字符数组转为数字
			//else line1[lenth].m_k=0;//上一行为相对编程
			break;
		default:break;
		}
		}
	}
	//y坐标获取

}