
// MFCwekk9Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCwekk9.h"
#include "MFCwekk9Dlg.h"
#include "afxdialogex.h"
#include"string"
#include"iostream"
#include"fstream"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
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


// CMFCwekk9Dlg 对话框



CMFCwekk9Dlg::CMFCwekk9Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCwekk9Dlg::IDD, pParent)
	, cc(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	i = 0;
}

void CMFCwekk9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LBox);
	DDX_Text(pDX, IDC_EDIT1, cc);
}

BEGIN_MESSAGE_MAP(CMFCwekk9Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCwekk9Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCwekk9Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCwekk9Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCwekk9Dlg::OnEnChangeEdit1)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDOK, &CMFCwekk9Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCwekk9Dlg 消息处理程序

BOOL CMFCwekk9Dlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCwekk9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCwekk9Dlg::OnPaint()
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
HCURSOR CMFCwekk9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCwekk9Dlg::OnLbnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
	//使其显示到编辑框中
	CString str;
	i = LBox.GetCurSel();
	LBox.GetText(i, str);
	UpdateData();
	cc = str;
	UpdateData(false);

}


void CMFCwekk9Dlg::OnBnClickedButton1()
{
	//对列表框进行修改
	CString str;
	UpdateData(true);
	str = cc;
	LBox.DeleteString(i);
	LBox.InsertString(i, str);
	UpdateData(false);

}


void CMFCwekk9Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog cfd(true);
	CString filename;
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		string s;
		ifstream ifs(filename);

		CClientDC dc(this);
		int x = 20, y = 20;
		while (ifs >> s)
		{
			//CListBox *listbox = (CListBox*)GetDlgItem(IDC_LIST1);

			LBox.AddString(CString(s.c_str()));
		}
	}
}


void CMFCwekk9Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void CMFCwekk9Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCwekk9Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCwekk9Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	this->UpdateData(true);
	CString cc1 = cc;
	LBox.DeleteString(i);
	LBox.InsertString(i, cc1);
	UpdateData(false);
	ofstream oo(_T("D:\\学生名单.txt"));
	for (int k = 0; k < LBox.GetCount(); k++)
	{
		LBox.GetText(k, cc);
		oo << CT2A(cc) << endl;
	}
	oo.close();

	CDialogEx::OnOK();
}
