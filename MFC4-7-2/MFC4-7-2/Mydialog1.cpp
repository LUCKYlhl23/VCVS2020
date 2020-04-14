// Mydialog1.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-7-2.h"
#include "Mydialog1.h"
#include "afxdialogex.h"


// Mydialog1 对话框

IMPLEMENT_DYNAMIC(Mydialog1, CDialogEx)

Mydialog1::Mydialog1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s1(_T(""))
	, s2(_T(""))
{

}

Mydialog1::~Mydialog1()
{
}

void Mydialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT2, s2);
}


BEGIN_MESSAGE_MAP(Mydialog1, CDialogEx)
	ON_BN_CLICKED(IDOK, &Mydialog1::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &Mydialog1::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Mydialog1::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydialog1::OnBnClickedButton1)
END_MESSAGE_MAP()


// Mydialog1 消息处理程序


void Mydialog1::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Mydialog1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	CString s3;
	s3.Format(_T(""));
	s1 = s3;
	s2 = s1;
	s3 = s2;
	// TODO:  在此添加控件通知处理程序代码
}


void Mydialog1::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Mydialog1::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);//和下面是对度称的别丢了
	CString s3;
	s3 = s1;
	s1 = s2;
	s2 = s3;
	UpdateData(false);
}
