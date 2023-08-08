
// InterpolationDemoDlg.h : 头文件
//

#pragma once
#include"inf.h"

// CInterpolationDemoDlg 对话框 类继承自 CDialogEx 类，这是一个对话框类。
class CInterpolationDemoDlg : public CDialogEx
{
// 构造
public:
	CInterpolationDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_INTERPOLATIONDEMO_DIALOG }; //对话框的资源ID为 IDD_INTERPOLATIONDEMO_DIALOG，在资源文件中定义了对话框的布局和控件。

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	inf m_line[100];//是一个包含 100 个 inf 结构体的数组，用于存储插值数据。
	CDC * pControlDC;//是一个指向CDC（Device Context）的指针，用于在控件上绘制图形。
	int lenth;//hangshu
	double 	Ptscale;//是一个双精度浮点数，表示插值的比例。
};
