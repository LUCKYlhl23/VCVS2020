﻿
// MFC310-2View.cpp: CMFC3102View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC310-2.h"
#endif

#include "MFC310-2Doc.h"
#include "MFC310-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3102View

IMPLEMENT_DYNCREATE(CMFC3102View, CView)

BEGIN_MESSAGE_MAP(CMFC3102View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3102View 构造/析构

CMFC3102View::CMFC3102View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3102View::~CMFC3102View()
{
}

BOOL CMFC3102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3102View 绘图

void CMFC3102View::OnDraw(CDC* pDC)
{
	CMFC3102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3102View 诊断

#ifdef _DEBUG
void CMFC3102View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3102Doc* CMFC3102View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3102Doc)));
	return (CMFC3102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3102View 消息处理程序


void CMFC3102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	CMFC3102Doc* pDoc = GetDocument();
	int a = pDoc->A;
	int b = pDoc->B;
	s.Format(_T("A+B=%d"), a+b);
	dc.TextOutW(200,300,s);
	CView::OnLButtonDown(nFlags, point);
}
