#include "Interpolating.h"

void copyTxt(string srcFilename, string dstFilename)  
{  
	ifstream infile;  
	ofstream outfile;  
	string temp;  
	infile.open(srcFilename, ios::in);  //���ļ����ڶ�ȡ���ݡ�����ļ������ڣ���򿪳���
	outfile.open(dstFilename, ios::trunc | ios::out);  //���ļ����ȿɶ�ȡ�����ݣ�Ҳ������д�����ݡ�����ļ������ʹ��ڣ����ʱ���ԭ�������ݣ�����ļ������ڣ����½����ļ���
	if (infile.good())  //infile�򿪳ɹ�
	{  
		while (!infile.eof())  
		{  
			/*
			�ڶ����﷨��ʽ�͵�һ�ֵ��������ڣ���һ���汾�Ƕ��� \n Ϊֹ��
			�ڶ����汾�Ƕ��� delim �ַ�Ϊֹ��\n �� delim �����ᱻ���� buf�����ᱻ���ļ���������������ȡ�ߡ�
			*/
			getline(infile, temp, '\n');  //����temp��
			outfile << temp << '\n';  
		}  
	}  
	infile.close();  
	outfile.close();  

}