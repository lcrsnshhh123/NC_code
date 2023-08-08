
// InterpolationDemoDlg.cpp : 实现文件
#include "GT_Move.h"
#include "Interpolating.h"
#include "stdafx.h"
#include "InterpolationDemo.h"
#include "InterpolationDemoDlg.h"
#include "afxdialogex.h"
#include"add_heaer.h"
#include "MyNewDlg.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();//CAboutDlg 类有一个默认构造函数 CAboutDlg()，用于创建对话框对象。

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CInterpolationDemoDlg 对话框
//综合起来，这个构造函数通过调用 CDialogEx 类的构造函数来初始化对话框，加载并存储主框架图标资源，以便在后续的对话框绘制和显示中使用。
CInterpolationDemoDlg::CInterpolationDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInterpolationDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInterpolationDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CInterpolationDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(InterpolatingButton, &CInterpolationDemoDlg::OnBnClickedInterpolatingbutton)
	ON_BN_CLICKED(ShowPath, &CInterpolationDemoDlg::OnBnClickedShowpath)
	ON_BN_CLICKED(MoveButton, &CInterpolationDemoDlg::OnBnClickedMovebutton)
	ON_BN_CLICKED(IDC_NCBUTTON, &CInterpolationDemoDlg::OnBnClickedNcbutton)
//综合起来，这段代码定义了 CInterpolationDemoDlg 类的消息映射，将系统和按钮点击消息与类中相应的消息处理函数关联起来，
//从而实现对交互事件的响应和处理。当事件发生时，系统会自动调用对应的消息处理函数。
END_MESSAGE_MAP()


// CInterpolationDemoDlg 消息处理程序

//初始化对话框
BOOL CInterpolationDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//
void CInterpolationDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CInterpolationDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CInterpolationDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

FILE *fp;//文件指针
void CInterpolationDemoDlg::OnBnClickedInterpolatingbutton()
{
	// 大家把插补程序放到这里

	char fn[100]="data/Results.txt";
	if((fp=fopen(fn,"w"))==NULL)
	{
		printf("can't open file\n");
		exit(0);
	}

	PBP_Line(1,0,0,15,30);
	PBP_Line(1,0,0,15,-30);
	PBP_Line(1,0,0,-30,0);
	PBP_Circle(1,0,5,0,5,5,0); 

	/*DDA_line(1,5,0,0,15,30);
	DDA_line(1,5,0,0,15,-30);
	DDA_line(1,5,0,0,-30,0);*/
	//DDA_circle(1,0,5,5,0,5,0);
	
	/*DDA_circle(1,0,5,-5,0,5,0); 
	DDA_circle(1,-5,0,0,-5,5,0);
	DDA_circle(1,0,-5,5,0,5,0);
	DDA_circle(1,5,0,0,5,5,0);*/
	fclose(fp);
	AfxMessageBox(_T("生成轨迹成功！"),MB_OKCANCEL);//显示窗口
}

void CInterpolationDemoDlg::OnBnClickedShowpath()
{
	// TODO: 显示插补轨迹
	copyTxt("data/Results.txt","data/CopyResults.txt");  //拷贝备用程序；
	int n=0;
	string s1;
	string s2;
	string s3;string str;
	char temp0[100];
	stringstream ss;
	const char *s;
	ofstream ofs;
	char a[100];
	int z;
	double x1,x2,y1,y2;
	for(int j=0;j<lenth;j++)
	{
		
		if(m_line[j].m_shape!="G00")
		{
		n++;
		s1="data/Results"; 
		sprintf (a,"%d", n); //在a里面写个n
        s2=a;
		s3=".txt";
		str=s1+s2+s3;
		s=str.c_str();
		for( z=0;z<str.length();z++)
        temp0[z] =str[z];
        temp0[z] = '\0'; 
		//文件拆分，备份；//问题没有对应的点
		if(m_line[j-1].m_manner=="G90")//绝对-》绝对
				{x1=m_line[j-1].m_x-m_line[j].o_x/10;y1=m_line[j-1].m_y-m_line[j].o_y/10;}
				else
				{x1=m_line[j-1].m_x+m_line[j-1].o_x/Ptscale-m_line[j].o_x/10;y1=m_line[j-1].m_y+m_line[j-1].o_y/Ptscale-m_line[j].o_y/10;}
		if(m_line[j].m_manner=="G90")
		{x2=m_line[j].m_x-m_line[j].o_x/10;y2=m_line[j].m_y-m_line[j].o_y/10;}
		else
		{
		x2=m_line[j].m_x;y2=m_line[j].m_y;
		}
		//SplitFile(x2,y2,1,s);
		SplitFile(x1,y1,x2,y2,1,s);
		//对当前图形进行插补
		ShowTrack(pControlDC,temp0,Ptscale,m_line[j].o_x,m_line[j].o_y);
	   }
	}
	
		
		
		

}

/*
总结：这段代码实现了点击 "MoveButton" 按钮后创建并显示一个新的对话框 CMyNewDlg，并将 CInterpolationDemoDlg 类中的 m_line 数组和 lenth 变量传递给新对话框。
这样，新对话框就可以使用和处理 CInterpolationDemoDlg 类中的数据。
*/
void CInterpolationDemoDlg::OnBnClickedMovebutton()
{
	CMyNewDlg *pDlg=new CMyNewDlg;
	pDlg->Create(IDD_DIALOG1,this);
	pDlg->ShowWindow(SW_SHOW);
	pDlg->getm_line(m_line,lenth);
	
}




/*
综合起来，这段代码实现了从文件中读取 NC 代码，根据 NC 代码的内容绘制图形，并在对话框上显示绘制的图形。具体的绘图操作可能在 get_oxy 函数中实现。
*/
void CInterpolationDemoDlg::OnBnClickedNcbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	//结构体数组
	
	lenth=0;//hangshu
	memset(m_line,0,sizeof(m_line));//初始化结构体数组为0
	//打开文件
	ifstream ifs;
	ifs.open("NCdata/txt01.txt",ios::in);
	if(!ifs.is_open())
	{
		cout<<"erro open file."<<endl;
		return ;
	}
	smatch results; 
	string linenc;//行NC代码
	string manner="G9[0|1]|G0[0|1|2|3]|X|Y|R|I|K";//设置目标
	regex pattern(manner);//生成regex类的对象
	while(!ifs.eof())
	{ getline(ifs,linenc);
	std::cout<<linenc<<endl;//获得一行字符串
	if(regex_search(linenc,results,pattern))//判断当前句子中是否有关键字
	{
	//绝对|相对编程
	//get_manner(linenc,&line1);
	get_manner(linenc,m_line,lenth);
	//图像获取
	//get_shape(linenc,&line1);
	get_shape(linenc,m_line,lenth);
	//坐标获取0.X，1.Y，2.I，3.R 4,I 5,K
	//X坐标获取；
	//get_local(linenc,&line1,0);
	get_local(linenc,m_line,0,lenth);
	//Y坐标获取
	//get_local(linenc,&line1,1);
	get_local(linenc,m_line,1,lenth);
	//R坐标获取
	//get_local(linenc,&line1,3);
	get_local(linenc,m_line,2,lenth);
	//I坐标获取
	//get_local(linenc,&line1,2);
	get_local(linenc,m_line,3,lenth);
	//K坐标获取
	//get_local(linenc,&line1,2);
	get_local(linenc,m_line,4,lenth);
	lenth++;//行数加一
	}
	}
	ifs.clear();
	ifs.close();
	
	//设置绘图平面对象；
	CWnd * pWnd = GetDlgItem(IDC_DRAW);
	pControlDC = pWnd->GetDC();
	CRect rect;
	UpdateData(true);
	pWnd->GetWindowRect(&rect);
	//获取绘图控件的客户区域矩形大小（相对于屏幕坐标）。
	double RectWidth=rect.Width();
	double RectHeight=rect.Height();
	//设置绘图平面（将绘图背景置为黑色），并绘制坐标轴
	CBrush br;
	COLORREF cr=RGB(0,0,0);
	br.CreateSolidBrush(cr);
	pControlDC->SelectObject(&br);
	pControlDC->Rectangle(0, 0, RectWidth, RectHeight);
	br.DeleteObject();
	pControlDC->SetMapMode(MM_ISOTROPIC);
	pControlDC->SetWindowExt(RectWidth,RectHeight);        //设置窗口
	pControlDC->SetViewportExt(RectWidth,-RectHeight);     //x轴水平向右，y轴垂直向上
	pControlDC->SetViewportOrg(0,RectHeight);              //设置坐标系原点

    DrawLocalAxle(pControlDC,RectWidth,RectHeight);
	Ptscale=10;
	//获取每行的相对坐标系的原点并进行绘图
	get_oxy(m_line,lenth,pControlDC,Ptscale);
	//返回窗口对象
	
}
