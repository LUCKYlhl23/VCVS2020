// Mydlg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-7-1(1).h"
#include "Mydlg.h"
#include "afxdialogex.h"


// Mydlg 对话框

IMPLEMENT_DYNAMIC(Mydlg, CDialogEx)

Mydlg::Mydlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Mydlg::~Mydlg()
{
}

void Mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Mydlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Mydlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// Mydlg 消息处理程序


void Mydlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
