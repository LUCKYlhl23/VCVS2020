// MyDialog.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-20-3.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, left(0)
	, right(0)
	, top(0)
	, bottom(0)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, left);
	DDX_Text(pDX, IDC_EDIT2, right);
	DDX_Text(pDX, IDC_EDIT3, top);
	DDX_Text(pDX, IDC_EDIT4, bottom);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &MyDialog::OnEnChangeEdit1)
	//(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}





void MyDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int l, t, r, b;
	l = left;
	t = top;
	r = right;
	b = bottom;
	CRect re(l, t, r, b);
	GetDC()->Ellipse(re);
}
