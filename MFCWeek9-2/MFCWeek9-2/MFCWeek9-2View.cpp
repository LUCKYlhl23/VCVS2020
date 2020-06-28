
// MFCWeek9-2View.cpp: CMFCWeek92View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCWeek9-2.h"
#endif

#include "MFCWeek9-2Doc.h"
#include "MFCWeek9-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWeek92View

IMPLEMENT_DYNCREATE(CMFCWeek92View, CView)

BEGIN_MESSAGE_MAP(CMFCWeek92View, CView)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCWeek92View 构造/析构

CMFCWeek92View::CMFCWeek92View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCWeek92View::~CMFCWeek92View()
{
	flag = false;

}

BOOL CMFCWeek92View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCWeek92View 绘图

void CMFCWeek92View::OnDraw(CDC* pDC)
{
	CMFCWeek92Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->ca.GetCount(); i++)
	{
		pDC->Ellipse(pDoc->ca[i]);//Invalidate();
	}
	if(flag)
		pDC->Ellipse(crect);
	
		// TODO: 在此处为本机数据添加绘制代码
}


// CMFCWeek92View 诊断

#ifdef _DEBUG
void CMFCWeek92View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCWeek92View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCWeek92Doc* CMFCWeek92View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCWeek92Doc)));
	return (CMFCWeek92Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCWeek92View 消息处理程序


void CMFCWeek92View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ReleaseCapture();
	CMFCWeek92Doc* pDoc = GetDocument();
	flag = false;
	pDoc->ca.Add(crect);
	crect.right = point.x;
	crect.bottom = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CMFCWeek92View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	crect.right = point.x;
	crect.bottom = point.y;
	if(flag)
		Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFCWeek92View::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//GetCapture();
	flag = true;
	crect.left = point.x;
	crect.top = point.y;
	CView::OnMButtonDown(nFlags, point);
}
