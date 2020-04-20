
// MFC4-20-1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFC4-20-1.h"
#include "MFC4-20-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC4201Dlg 对话框



CMFC4201Dlg::CMFC4201Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC4201_DIALOG, pParent)
	, t1(0)
	, t2(0)
	, t(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC4201Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, t1);
	DDX_Text(pDX, IDC_EDIT2, t2);
	DDX_Text(pDX, IDC_EDIT3, t);
}

BEGIN_MESSAGE_MAP(CMFC4201Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC4201Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC4201Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC4201Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC4201Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC4201Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC4201Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMFC4201Dlg 消息处理程序

BOOL CMFC4201Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC4201Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC4201Dlg::OnPaint()
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
HCURSOR CMFC4201Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC4201Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	t = t1 + t2;
	UpdateData(false);
}


void CMFC4201Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	t = t1 - t2;
	UpdateData(false);
}


void CMFC4201Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	t = t1 *t2;
	UpdateData(false);
}


void CMFC4201Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (t2 == 0)
	{
		MessageBox(_T("输入无效,请重新输入"));
	}
	t = t1 / t2;
	UpdateData(false);
}


void CMFC4201Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (t1 < 0)
	{
		MessageBox(_T("输入无效,请重新输入"));
	}
	t = sqrt(t1);
	if (t2)
	{
		MessageBox(_T("输入无效,请在前一个编辑框中输入"));
		t2 = 0;
	}

	UpdateData(false);
}


void CMFC4201Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	double a1, a2, a3;

	//a3 = a1 / a2;
	// = t1;
	if (t1 == 0)
	{
		MessageBox(_T("输入无效,0没有倒数"));
	}

	t = 1 / t1;
	if (t2)
	{
		MessageBox(_T("输入无效,请在前一个编辑框中输入"));
			t2 = 0;
	}
	UpdateData(false);
}
