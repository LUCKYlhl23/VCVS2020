
// MFC4-20-2View.cpp: CMFC4202View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-20-2.h"
#endif

#include "MFC4-20-2Doc.h"
#include "MFC4-20-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4202View

IMPLEMENT_DYNCREATE(CMFC4202View, CView)

BEGIN_MESSAGE_MAP(CMFC4202View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC4202View 构造/析构

CMFC4202View::CMFC4202View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	m_nd =0;
	m_nd0=0 ;
	m_nd1= 0;
	m_nd11 = 0;
	m_nd2=0 ;
	m_nd21 = 0;
	
}

CMFC4202View::~CMFC4202View()
{
}

BOOL CMFC4202View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4202View 绘图

void CMFC4202View::OnDraw(CDC* pDC)
{
	CMFC4202Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		pDC->Ellipse(m_nd, m_nd0, m_nd1, m_nd11);
		
	}
	else
	{
		pDC->Ellipse(m_nd, m_nd0, m_nd2, m_nd21);
	
	}

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4202View 诊断

#ifdef _DEBUG
void CMFC4202View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4202View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4202Doc* CMFC4202View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4202Doc)));
	return (CMFC4202Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4202View 消息处理程序



void CMFC4202View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = true;
	m_nd = point.x ;
	m_nd0 = point.y ;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4202View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set = false;
	m_nd1 = point.x ;
	m_nd11 = point.y ;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CMFC4202View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_nd2 = point.x ;
	m_nd21 = point.y ;
	
	
	CView::OnMouseMove(nFlags, point);
}
