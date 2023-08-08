#pragma once;
#include "stdafx.h"


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include<string.h>
#include<regex>
#include<cstdlib>
#include <iomanip>  //fixed and setprecision
#include <sstream>  //stringstream
#include<cmath>
#include<ctime>
using namespace std;
double pow(double,int);
void InsertPoint(double xCur,double yCur);
unsigned short Judge_Quadrant(double x, double y);
void 



(double step,double XStart,double YStart, double XEnd, double YEnd);
void PBP_Circle(double step, double XStart, double YStart, double XEnd,double YEnd, double radius, int bIsCW);
void scale(POINT *pt, int len,double sX,double sY);
void copyTxt(string srcFilename, string dstFilename);
int gethcount(char filename[100]);
void DrawLocalAxle(CDC* pDC,int rWidth,int rHeight);
void CircleCenter(double x1,double y1,double x2,double y2,double R,double &x01,double &y01,double &x02,double &y02);
void DrawCircle(CDC* pDC,double StartX,double StartY,double EndX,double EndY,double R,double Ptscale,double &TrPt_x,double &Trpt_y,int t);
//void DrawCircle(CDC* pDC,double StartX,double StartY,double EndX,double EndY,double R,double Ptscale,double TrPt_x,double Trpt_y);
void DrawLine(CDC* pDC,double StartX,double StartY,double EndX,double EndY, double Ptscale,double TrPt_x,double TrPt_y);
void DelLineData(char* fileName, int lineNum);
int rm_BlankLine(string file);
//void SplitFile(int EndPoint1_x,int EndPoint1_y,int EndPoint2_x,int EndPoint2_y,int EndPoint3_x,int EndPoint3_y);
void ShowTrack(CDC* pDC,char filename[100], double Ptscale,double TrPt_x,double TrPt_y);
void judge_cricle(double &x1,double &y1,double &x2,double &y2,double &x_big,double &y_big,double &x_small,double &y_small,double x01,double y01,double x02,double y02,int t);
void SplitFile(int startx,int starty,int EndPoint1_x,int EndPoint1_y,int i,const char *s);
//void SplitFile(int EndPoint1_x,int EndPoint1_y,int i,const char *s);

void DDA_line(double st,int n,double XS,double YS, double XE, double YE);
void DDA_circle(double step, double XStart, double YStart, double XEnd,double YEnd, double radius, int bIsCW);



