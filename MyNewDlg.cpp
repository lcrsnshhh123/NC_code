// MyNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "InterpolationDemo.h"
#include "MyNewDlg.h"
#include "afxdialogex.h"
#include "GT_Move.h"
#include"add_heaer.h"
// CMyNewDlg 对话框

IMPLEMENT_DYNAMIC(CMyNewDlg, CDialogEx)

CMyNewDlg::CMyNewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyNewDlg::IDD, pParent)
{

}

CMyNewDlg::~CMyNewDlg()
{
}

void CMyNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyNewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyNewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyNewDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyNewDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyNewDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyNewDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK2, &CMyNewDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK3, &CMyNewDlg::OnBnClickedOk3)
END_MESSAGE_MAP()


// CMyNewDlg 消息处理程序


void CMyNewDlg::OnBnClickedOk()
{
	int t;
	string name[4]={"G00","G01","G02","G03"};
	
	if(tepnum<m_lenth)
	{
		//进行图像类型判断
		for (int j=0;j<4;j++)
		{if(m_line[tepnum].m_shape==name[j])
		t=j;
		}
		//执行某行代码
	    switch(t)
		{
		case 0:
			gotoG00(m_line,tepnum,G0num);
			break;
		case 1:
			gotoG01(m_line,tepnum,G0num);
			break;
		case 2:
			gotoG02(m_line,tepnum,G0num);
			break;
		case 3:
			gotoG03(m_line,tepnum,G0num);
			break;
		default:break;
		
		}
	}
	else
	{
		//输出信息已经完成插补图像
		 AfxMessageBox(_T("已经完成插补图像!"),MB_OKCANCEL);
		
	
	}
	
	
	
	
}


void CMyNewDlg::OnBnClickedButton4()
{
	// TODO: 工作台向上移动
	short rtn;
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();

	rtn=GT_Axis(2);GT_error(rtn);
	rtn=GT_ExOpt(65535);
	Home(-20000);
}


void CMyNewDlg::OnBnClickedButton5()
{
	// TODO: 工作台向下移动
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();

	short rtn;
	rtn=GT_Axis(2);GT_error(rtn);
	rtn=GT_ExOpt(65535);
	Home(20000);
}


void CMyNewDlg::OnBnClickedButton2()
{
	// TODO: 工作台向左移动
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();

	short rtn;
	rtn=GT_Axis(1);GT_error(rtn);
	rtn=GT_ExOpt(65535);
	Home(20000);
}


void CMyNewDlg::OnBnClickedButton3()
{
	// TODO: 工作台向右移动
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();
	short rtn;
	rtn=GT_Axis(1);GT_error(rtn);
	rtn=GT_ExOpt(65535);
	Home(-20000);
}

void CMyNewDlg::OnBnClickedOk2()
{
	// TODO: 刀架抬起
	short rtn;
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();
	rtn=GT_ExOpt(65535); //GT_error(rtn);
}

void CMyNewDlg::OnBnClickedOk3()
{
	// TODO: 刀架落下
	GTInitial();
	InputCfg();
	//AxisInitialSV();
	AxisInitialSG();
	MapAxis();
	short rtn;
	rtn=GT_ExOpt(0); //GT_error(rtn);
}
void CMyNewDlg::getm_line(inf *line,int lenth)
{
	for(int i=0;i<lenth;i++){
		this->m_line[i]=line[i];}

	m_lenth=lenth;
	G0num=0;
	tepnum=0;
}
