// Dlgsum.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-13-2（1）.h"
#include "Dlgsum.h"
#include "afxdialogex.h"


// Dlgsum 对话框

IMPLEMENT_DYNAMIC(Dlgsum, CDialogEx)

Dlgsum::Dlgsum(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, add1(0)
	, add2(0)
	, addsum(0)
{

}

Dlgsum::~Dlgsum()
{
}

void Dlgsum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, add1);
	DDX_Text(pDX, IDC_EDIT2, add2);
	DDX_Text(pDX, IDC_EDIT3, addsum);
}


BEGIN_MESSAGE_MAP(Dlgsum, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Dlgsum::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &Dlgsum::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlgsum::OnBnClickedButton1)
END_MESSAGE_MAP()


// Dlgsum 消息处理程序


void Dlgsum::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Dlgsum::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CDialogEx::OnOK();
}


void Dlgsum::OnBnClickedButton1()
{
	UpdateData(true);//读取编辑框的值到关联的值变量中
	addsum = add1 + add2;//计算结果存到编辑框的关联变量中
	UpdateData(false);//将计算的结果显示到编辑框中
	// TODO: 在此添加控件通知处理程序代码
}
