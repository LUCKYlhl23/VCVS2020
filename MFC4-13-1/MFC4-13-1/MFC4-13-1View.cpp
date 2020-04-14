﻿
// MFC4-13-1View.cpp: CMFC4131View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-13-1.h"
#endif

#include "MFC4-13-1Doc.h"
#include "MFC4-13-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4131View

IMPLEMENT_DYNCREATE(CMFC4131View, CView)

BEGIN_MESSAGE_MAP(CMFC4131View, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFC4131View 构造/析构

CMFC4131View::CMFC4131View() noexcept
{
	// TODO: 在此处添加构造代码
	
	mDown = false;
}

CMFC4131View::~CMFC4131View()
{
}

BOOL CMFC4131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4131View 绘图

void CMFC4131View::OnDraw(CDC* pDC)
{
	CMFC4131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4131View 诊断

#ifdef _DEBUG
void CMFC4131View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4131Doc* CMFC4131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4131Doc)));
	return (CMFC4131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4131View 消息处理程序


void CMFC4131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (mDown == true)
	{
		if(rect.PtInRect(point))//ptinrect,类CRect的成员函数，其作用是判断一个点是否在CRect中。
		{
			mMouse = point;
			Invalidate();
		}
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC4131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mDown = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC4131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mDown = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMFC4131View::OnPaint()
{
	CClientDC dc(this); 
	rect.top = mMouse.y - 15;
	rect.left = mMouse.x - 15;
	rect.bottom = rect.top + 50;
	rect.right = rect.left + 50;
	dc.Rectangle(&rect);			   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CView::OnPaint()
}
