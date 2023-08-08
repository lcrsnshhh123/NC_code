#include "Interpolating.h"

void copyTxt(string srcFilename, string dstFilename)  
{  
	ifstream infile;  
	ofstream outfile;  
	string temp;  
	infile.open(srcFilename, ios::in);  //打开文件用于读取数据。如果文件不存在，则打开出错。
	outfile.open(dstFilename, ios::trunc | ios::out);  //打开文件，既可读取其内容，也可向其写入数据。如果文件本来就存在，则打开时清除原来的内容；如果文件不存在，则新建该文件。
	if (infile.good())  //infile打开成功
	{  
		while (!infile.eof())  
		{  
			/*
			第二种语法格式和第一种的区别在于，第一个版本是读到 \n 为止，
			第二个版本是读到 delim 字符为止。\n 或 delim 都不会被读入 buf，但会被从文件输入流缓冲区中取走。
			*/
			getline(infile, temp, '\n');  //读到temp中
			outfile << temp << '\n';  
		}  
	}  
	infile.close();  
	outfile.close();  

}