
// MFC309tView.cpp: CMFC309tView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC309t.h"
#endif

#include "MFC309tDoc.h"
#include "MFC309tView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC309tView

IMPLEMENT_DYNCREATE(CMFC309tView, CView)

BEGIN_MESSAGE_MAP(CMFC309tView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC309tView 构造/析构

CMFC309tView::CMFC309tView() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(300);
}

CMFC309tView::~CMFC309tView()
{
}

BOOL CMFC309tView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC309tView 绘图

void CMFC309tView::OnDraw(CDC* pDC)
{
	CMFC309tDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMFC309tView 诊断

#ifdef _DEBUG
void CMFC309tView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC309tView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC309tDoc* CMFC309tView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC309tDoc)));
	return (CMFC309tDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC309tView 消息处理程序


void CMFC309tView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int a = rand() % 50;
	int b = 50 + rand() % 50;
	CClientDC dc(this);
	CRect cr(point.x - a, point.y - b, point.x + a, point.y + b);
	ca.Add(cr);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
