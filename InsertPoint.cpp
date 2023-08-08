#include "Interpolating.h"

void InsertPoint(double xCur,double yCur)
{
	extern FILE *fp;
	char ch=10;
	//printf("xCur=%.2f yCur=%.2f\n",xCur,yCur);
	fprintf(fp,"%.2f %.2f",xCur,yCur);
	fputc(ch,fp);
}