#include "GT_Move.h"

//S-����ģʽ�˶�����
void SMotion()  
{
  short rtn;
  rtn=GT_PrflS();               GT_error(rtn);   // �����˶�ģʽΪS����ģʽ
  rtn=GT_SetJerk(0.00000002);   GT_error(rtn);   // �������Ӽ��ٶ�Ϊ0.00000002
  rtn=GT_SetMAcc(0.004);        GT_error(rtn);   // ���������ٶ�Ϊ0.004
  rtn=GT_SetVel(4);             GT_error(rtn);   // ����Ŀ���ٶ�Ϊ4
  rtn=GT_SetPos(80000);         GT_error(rtn);   // ����Ŀ��λ��Ϊ80000
  rtn=GT_Update();              GT_error(rtn);   // ˢ�²���
}