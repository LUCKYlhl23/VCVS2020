
// MFC4-20-5View.cpp: CMFC4205View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-20-5.h"
#endif

#include "MFC4-20-5Doc.h"
#include "MFC4-20-5View.h"
#include"MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4205View

IMPLEMENT_DYNCREATE(CMFC4205View, CView)

BEGIN_MESSAGE_MAP(CMFC4205View, CView)
	ON_COMMAND(ID_OnPutOut, &CMFC4205View::OnOnputout)
END_MESSAGE_MAP()

// CMFC4205View 构造/析构

CMFC4205View::CMFC4205View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.left = 100;
	rect.bottom = 500;
	rect.right = 300;
	rect.top = 200;
}

CMFC4205View::~CMFC4205View()
{
}

BOOL CMFC4205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4205View 绘图

void CMFC4205View::OnDraw(CDC* /*pDC*/)
{
	CMFC4205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetDC()->Ellipse(rect.left, rect.top, rect.right, rect.bottom);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4205View 诊断

#ifdef _DEBUG
void CMFC4205View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4205Doc* CMFC4205View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4205Doc)));
	return (CMFC4205Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4205View 消息处理程序


void CMFC4205View::OnOnputout()
{
	CClientDC dc(this);
	CRect rc;
	GetClientRect(&rc);

	MyDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		CBrush brush;
		int corlor = RGB(dlg.r, dlg.g, dlg.b);
		brush.CreateSolidBrush(corlor);
		dc.SelectObject(&brush);
		dc.Ellipse(rect.left, rect.top, rect.right, rect.bottom);
	}
	// TODO: 在此添加命令处理程序代码
}
