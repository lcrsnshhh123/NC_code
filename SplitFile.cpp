#include "Interpolating.h"

void SplitFile(int startx,int starty,int EndPoint1_x,int EndPoint1_y,int i,const char *s)
{
    int hcount=gethcount("data/Results.txt");//获取行数
	//第一段数据的拆分

	//文件指针变量
	FILE *in_file1;
	FILE *out_file1;
	in_file1=fopen("data/CopyResults.txt", "r+");//打开一个用于更新的文件，可读取也可写入。该文件必须存在。
	out_file1=fopen(s, "w+");//创建一个用于读写的空文件。
	char buf1[1024];
	float x1,y1;
	for(int j=1;j<=hcount;j++)//寻找起点坐标
	{
		fgets(buf1, 1024, in_file1);
		sscanf(buf1, "%f %f",&x1,&y1);
		fprintf(out_file1,"%.2f %.2f\n",x1,y1);
		//这行代码使用 sscanf() 函数从 buf1 字符数组中解析数据，并将解析得到的两个浮点数（X 和 Y 坐标）保存到 x1 和 y1 变量中。
	    DelLineData("data/CopyResults.txt", j);//将已经输出的数据从copy文件删除
		if(x1==EndPoint1_x && y1==EndPoint1_y)//判断是否到达终点
		{
		  break;
		}
	}
	fclose(in_file1);
	fclose(out_file1);
	rm_BlankLine("data/CopyResults.txt");//删除空白行
}