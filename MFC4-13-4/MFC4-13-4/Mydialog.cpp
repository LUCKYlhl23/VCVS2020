// Mydialog.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-13-4.h"
#include "Mydialog.h"
#include "afxdialogex.h"


// Mydialog 对话框

IMPLEMENT_DYNAMIC(Mydialog, CDialogEx)

Mydialog::Mydialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, s2(_T(""))
	, t(0)
{

}

Mydialog::~Mydialog()
{
}

void Mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT3, s2);
	DDX_Text(pDX, IDC_EDIT2, t);
}


BEGIN_MESSAGE_MAP(Mydialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydialog 消息处理程序


void Mydialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString B;
	B.Format(_T("%d"), t);
	s2.Format(_T("%s%s"), s1, B);
	UpdateData(false);
}
