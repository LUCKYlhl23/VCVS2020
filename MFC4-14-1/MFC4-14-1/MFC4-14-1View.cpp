
// MFC4-14-1View.cpp: CMFC4141View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-14-1.h"
#endif

#include "MFC4-14-1Doc.h"
#include "MFC4-14-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4141View

IMPLEMENT_DYNCREATE(CMFC4141View, CView)

BEGIN_MESSAGE_MAP(CMFC4141View, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CMFC4141View 构造/析构

CMFC4141View::CMFC4141View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4141View::~CMFC4141View()
{
}

BOOL CMFC4141View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4141View 绘图

void CMFC4141View::OnDraw(CDC* pDC)
{
	CMFC4141Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4141View 诊断

#ifdef _DEBUG
void CMFC4141View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4141View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4141Doc* CMFC4141View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4141Doc)));
	return (CMFC4141Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4141View 消息处理程序


void CMFC4141View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4141Doc* pDoc = GetDocument();
	CFileDialog dlg(true);
	int r = dlg.DoModal();
	CClientDC dc(this);
	if (r == IDOK)
	{
		pDoc->filename = dlg.GetPathName();
		dc.TextOutW(200, 400, pDoc->filename);
	}
	CView::OnLButtonDblClk(nFlags, point);
}
