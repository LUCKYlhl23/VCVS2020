// Mydialog.cpp: 实现文件
//

#include "pch.h"
#include "MFC4-14-2.h"
#include "Mydialog.h"
#include "afxdialogex.h"
#include"MFC4-14-2Doc.h"
#include"MFC4-14-2View.h"
// Mydialog 对话框

IMPLEMENT_DYNAMIC(Mydialog, CDialogEx)

Mydialog::Mydialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_show(_T(""))
{

}

Mydialog::~Mydialog()
{
}

void Mydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_show);
}


BEGIN_MESSAGE_MAP(Mydialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Mydialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Mydialog 消息处理程序


void Mydialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	/*UpdateData(true);
	CFileDialog dlg(true);
	dlg.DoModal();
	CString filename;
	filename = dlg.GetPathName();
	m_show
	UpdateData(false);*/
	//CMFC4142Doc* pDoc = GetDocument();
	//m_show=("%s", pDoc->filename);
	// TODO:  在此添加控件通知处理程序代码
}


BOOL Mydialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	CMFC4142Doc *pDoc = ((CMFC4142View *)((CFrameWnd *)AfxGetMainWnd())->GetActiveView())->GetDocument();
	UpdateData(true);
	m_show = ("%s", pDoc->filename);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
