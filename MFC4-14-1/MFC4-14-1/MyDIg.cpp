// MyDIg.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-14-1.h"
#include "MyDIg.h"
#include "afxdialogex.h"


// MyDIg 对话框

IMPLEMENT_DYNAMIC(MyDIg, CDialogEx)

MyDIg::MyDIg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDIg::~MyDIg()
{
}

void MyDIg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDIg, CDialogEx)
END_MESSAGE_MAP()


// MyDIg 消息处理程序
