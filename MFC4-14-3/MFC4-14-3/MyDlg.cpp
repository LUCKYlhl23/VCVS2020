// MyDlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-14-3.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include"MFC4-14-3Doc.h"
#include"MFC4-14-3View.h"
// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &MyDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码

}


BOOL MyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CMFC4143Doc *pDoc = ((CMFC4143View *)((CFrameWnd *)AfxGetMainWnd())->GetActiveView())->GetDocument();
	this->UpdateData(true);
	Lbox.AddString(pDoc->filename);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
