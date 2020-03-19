
// MFC3-17-1View.cpp: CMFC3171View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-17-1.h"
#endif

#include "MFC3-17-1Doc.h"
#include "MFC3-17-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3171View

IMPLEMENT_DYNCREATE(CMFC3171View, CView)

BEGIN_MESSAGE_MAP(CMFC3171View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3171View 构造/析构

CMFC3171View::CMFC3171View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3171View::~CMFC3171View()
{
}

BOOL CMFC3171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3171View 绘图

void CMFC3171View::OnDraw(CDC* pDC)
{
	CMFC3171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3171View 诊断

#ifdef _DEBUG
void CMFC3171View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3171Doc* CMFC3171View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3171Doc)));
	return (CMFC3171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3171View 消息处理程序


void CMFC3171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->x1 = point.x;
	pDoc->en = 1;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC3171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3171Doc* pDoc = GetDocument();
	CString s1;
	CString s2;
	CClientDC dc(this);
	if (pDoc->x2 > pDoc->x1)
	{
		s1.Format(_T("横向移动%d像素"), pDoc->x2 - pDoc->x1);
		dc.TextOutW(200, 200, s1);

	}
	if (pDoc->x2 <= pDoc->x1)
	{
		s1.Format(_T("横向移动%d像素"), pDoc->x1 - pDoc->x2);
		dc.TextOutW(200, 200, s1);

	}
	if (pDoc->en)
	{
		pDoc->count++;
	}
	s2.Format(_T("移动%d次"), pDoc->count);
	dc.TextOutW(240, 240, s2);
	CView::OnMouseMove(nFlags, point);
}


void CMFC3171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	CMFC3171Doc* pDoc = GetDocument();
	pDoc->x2 = point.x;
	pDoc->en = 0;
	CView::OnLButtonUp(nFlags, point);
}
