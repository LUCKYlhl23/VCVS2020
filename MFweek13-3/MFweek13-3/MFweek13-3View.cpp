
// MFweek13-3View.cpp : CMFweek133View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFweek13-3.h"
#endif

#include "MFweek13-3Set.h"
#include "MFweek13-3Doc.h"
#include "MFweek13-3View.h"
#include"ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFweek133View

IMPLEMENT_DYNCREATE(CMFweek133View, CRecordView)

BEGIN_MESSAGE_MAP(CMFweek133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFweek133View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFweek133View::OnBnClickedADD)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFweek133View::OnBnClickedReduce)
END_MESSAGE_MAP()

// CMFweek133View 构造/析构

CMFweek133View::CMFweek133View()
	: CRecordView(IDD_MFWEEK133_FORM)
	, yesok(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

CMFweek133View::~CMFweek133View()
{
}

void CMFweek133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek133Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek133View 诊断

#ifdef _DEBUG
void CMFweek133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek133Doc* CMFweek133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek133Doc)));
	return (CMFweek133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek133View 数据库支持
CRecordset* CMFweek133View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek133View 消息处理程序


void CMFweek133View::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	
}


void CMFweek133View::OnBnClickedADD()
{
	// TODO: 在此添加控件通知处理程序代码
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFweek133View::OnBnClickedReduce()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(true);
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->Edit();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}
