#include<iostream>
#include<fstream>
#include<regex>
#include<string>
#include<cstdlib>
#include<deque>
using namespace std;
/*
*ɾ���ı��ļ��Ŀ���
*
*/
int rm_BlankLine(string file)
{
	fstream targetFile(file,fstream::in | fstream::out);
	string line;//��Ϊ��ȡ��ÿһ��
	string temp;//��Ϊ����ʹ��
	deque<string> noBlankLineQueue;//˫�����,ֻ�ڶ��׺Ͷ�β����ʱ���ܽϺ�
	//�ж��ļ��Ƿ��
	if(!targetFile){
		cerr << "Can't Open File!" << endl;
		return EXIT_FAILURE;        
	}
	//��¼�ļ���ʼλ��
	auto StartPos = targetFile.tellp();
	//ѭ����ȡ�ж��ļ��Ŀ��в��������
	while(getline(targetFile,line))
	{
		cout << targetFile.tellg() << endl;;    
		if(line.empty())
		{
			cout << "����Ϊ��" << endl; 
		}
		else
		{

			cout << "��һ���ǿ���" << endl;   
			noBlankLineQueue.push_back(line);
		}   
	}
	targetFile.close(); 
	//ʹ��ofstream���ٹر��ļ���Ϊ�����Դ�ļ�
	ofstream emptyFile(file);//�����ļ���
	emptyFile.close();
	//���´��ı��ļ�
	fstream target(file,fstream::out | fstream::in);
	if(!target){
		cerr << "Can't Open File" << endl;
	}
	//��ȡ���׺Ͷ�β
	auto begin = noBlankLineQueue.begin();
	auto end = noBlankLineQueue.end();
	//����˫������е�Ԫ��
	//��д���ļ�
	while(begin != end){
		temp = *begin;
		cout << temp << endl;
		target << temp << endl; 
		++begin;
	}
	target.close();
	return EXIT_SUCCESS;
}