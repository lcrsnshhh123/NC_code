#pragma once;
#include"Interpolating.h" 
struct inf
{string m_manner;
string m_shape;
double m_x;
double m_y;
double m_r;
double m_i;//Բ���������x�ƶ�����
double m_k;//Բ���������y�ƶ�����
double o_x;//�������ϵ������ԭ���������X
double o_y;//�������ϵ������ԭ���������Y
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