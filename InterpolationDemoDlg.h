
// InterpolationDemoDlg.h : ͷ�ļ�
//

#pragma once
#include"inf.h"

// CInterpolationDemoDlg �Ի��� ��̳��� CDialogEx �࣬����һ���Ի����ࡣ
class CInterpolationDemoDlg : public CDialogEx
{
// ����
public:
	CInterpolationDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_INTERPOLATIONDEMO_DIALOG }; //�Ի������ԴIDΪ IDD_INTERPOLATIONDEMO_DIALOG������Դ�ļ��ж����˶Ի���Ĳ��ֺͿؼ���

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInterpolatingbutton();
	afx_msg void OnBnClickedShowpath();
	afx_msg void OnBnClickedTest();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedMovebutton();
	afx_msg void OnBnClickedNcbutton();
	//afx_msg trsl OnBnClickedNcbutton();
	inf m_line[100];//��һ������ 100 �� inf �ṹ������飬���ڴ洢��ֵ���ݡ�
	CDC * pControlDC;//��һ��ָ��CDC��Device Context����ָ�룬�����ڿؼ��ϻ���ͼ�Ρ�
	int lenth;//hangshu
	double 	Ptscale;//��һ��˫���ȸ���������ʾ��ֵ�ı�����
};
