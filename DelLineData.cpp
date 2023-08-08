#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string CharToStr(char * contentChar)
{
	string tempStr;
	for (int i=0;contentChar[i]!='\0';i++)
	{
		tempStr+=contentChar[i];
	}
	return tempStr;
}

void DelLineData(char* fileName, int lineNum)
{
	ifstream in;
	in.open(fileName);

	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	while(in.getline(lineData, sizeof(lineData)))
	{
		if (line == lineNum)
		{
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	//Ð´ÈëÎÄ¼þ
	ofstream out;
	out.open(fileName);
	out.flush();
	out<<strFileData;


	out.close();
}