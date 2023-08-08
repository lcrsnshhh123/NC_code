#pragma once;
#include"Interpolating.h" 
struct inf
{string m_manner;
string m_shape;
double m_x;
double m_y;
double m_r;
double m_i;//圆心相对起点的x移动增量
double m_k;//圆心相对起点的y移动增量
double o_x;//相对坐标系的坐标原点绝对坐标X
double o_y;//相对坐标系的坐标原点绝对坐标Y
};
struct pos
{
double m_x;
double m_y;

};
struct trsl{
inf f[100];
CDC *pControlDC;
};