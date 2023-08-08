#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int gethcount(char filename[100])
{
	fstream fin(filename,ios::in);
	if(!fin)
	{
		cerr<<"can not open file"<<endl;
		return -1;
	}
	char c;
	int lineCnt=0;
	while(fin.get(c))
	{	
		if(c=='\n')
			lineCnt++;
	}
	return lineCnt;
}