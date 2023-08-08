#pragma once

#include "Resource.h"
// CMyNewDlg 对话框
#include"inf.h"
class CMyNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyNewDlg)

public:
	CMyNewDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyNewDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMThemeChangedRadio1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedOk3();
	void getm_line(inf *line,int lenth);
	inf m_line[100];
	int m_lenth;//hangshu
	int G0num;
	int tepnum;
};
