// MyNewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "InterpolationDemo.h"
#include "MyNewDlg.h"
#include "afxdialogex.h"
#include "GT_Move.h"
#include"add_heaer.h"
// CMyNewDlg �Ի���

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


// CMyNewDlg ��Ϣ�������


void CMyNewDlg::OnBnClickedOk()
{
	int t;
	string name[4]={"G00","G01","G02","G03"};
	
	if(tepnum<m_lenth)
	{
		//����ͼ�������ж�
		for (int j=0;j<4;j++)
		{if(m_line[tepnum].m_shape==name[j])
		t=j;
		}
		//ִ��ĳ�д���
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
		//�����Ϣ�Ѿ���ɲ岹ͼ��
		 AfxMessageBox(_T("�Ѿ���ɲ岹ͼ��!"),MB_OKCANCEL);
		
	
	}
	
	
	
	
}


void CMyNewDlg::OnBnClickedButton4()
{
	// TODO: ����̨�����ƶ�
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
	// TODO: ����̨�����ƶ�
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
	// TODO: ����̨�����ƶ�
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
	// TODO: ����̨�����ƶ�
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
	// TODO: ����̧��
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
	// TODO: ��������
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
