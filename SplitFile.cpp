#include "Interpolating.h"

void SplitFile(int startx,int starty,int EndPoint1_x,int EndPoint1_y,int i,const char *s)
{
    int hcount=gethcount("data/Results.txt");//��ȡ����
	//��һ�����ݵĲ��

	//�ļ�ָ�����
	FILE *in_file1;
	FILE *out_file1;
	in_file1=fopen("data/CopyResults.txt", "r+");//��һ�����ڸ��µ��ļ����ɶ�ȡҲ��д�롣���ļ�������ڡ�
	out_file1=fopen(s, "w+");//����һ�����ڶ�д�Ŀ��ļ���
	char buf1[1024];
	float x1,y1;
	for(int j=1;j<=hcount;j++)//Ѱ���������
	{
		fgets(buf1, 1024, in_file1);
		sscanf(buf1, "%f %f",&x1,&y1);
		fprintf(out_file1,"%.2f %.2f\n",x1,y1);
		//���д���ʹ�� sscanf() ������ buf1 �ַ������н������ݣ����������õ���������������X �� Y ���꣩���浽 x1 �� y1 �����С�
	    DelLineData("data/CopyResults.txt", j);//���Ѿ���������ݴ�copy�ļ�ɾ��
		if(x1==EndPoint1_x && y1==EndPoint1_y)//�ж��Ƿ񵽴��յ�
		{
		  break;
		}
	}
	fclose(in_file1);
	fclose(out_file1);
	rm_BlankLine("data/CopyResults.txt");//ɾ���հ���
}