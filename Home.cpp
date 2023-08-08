#include "GT_Move.h"

void Home (long pos)
{
	unsigned short status;
	long act1_pos;
	short rtn;
	rtn=GT_ClrSts();GT_error(rtn);     // ��״̬
	rtn=GT_CaptHome(); GT_error(rtn);  // ���ò���Home
	rtn=GT_PrflT(); GT_error(rtn);     // ������������
	rtn=GT_SetVel(1);GT_error(rtn);    // �����ٶ�Ϊ4����/��������
	rtn=GT_SetAcc(0.01);GT_error(rtn);    // ���ü��ٶ�Ϊ1
	rtn=GT_SetPos(pos);GT_error(rtn);  // ����Ŀ��λ��
	rtn=GT_Update();GT_error(rtn);     // ˢ�²���
	rtn=GT_GetSts(&status);GT_error(rtn);  // ��ȡ��״̬
	while(!(status&0x8))               // �ȴ�Home����
	{
		if((status & 0x400)!=0x400) return;         // ����˶�����ɡ���Homeδ����������
		rtn=GT_GetSts(&status);GT_error(rtn);  // ��ȡ��״̬
	}
	rtn=GT_GetCapt(&pos);GT_error(rtn); // ��ȡ����λ��
	rtn=GT_SetPos(pos);GT_error(rtn);   // ���ò���λ��ΪĿ��λ��
	rtn=GT_Update();GT_error(rtn);      // ˢ�²���
	rtn=GT_ClrSts();GT_error(rtn);      // ��״̬
	rtn=GT_GetSts(&status);GT_error(rtn);  // ��ȡ״ֵ̬
	while(status & 0x400)                   // �ȴ��˶����
	{
		rtn=GT_GetSts(&status);GT_error(rtn);  // ��ȡ״̬
	}
	rtn=GT_ZeroPos();GT_error(rtn);        // ����
}