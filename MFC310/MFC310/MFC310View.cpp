
// MFC310View.cpp: CMFC310View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC310.h"
#endif

#include "MFC310Doc.h"
#include "MFC310View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC310View

IMPLEMENT_DYNCREATE(CMFC310View, CView)

BEGIN_MESSAGE_MAP(CMFC310View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC310View 构造/析构

CMFC310View::CMFC310View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC310View::~CMFC310View()
{
}

BOOL CMFC310View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC310View 绘图

void CMFC310View::OnDraw(CDC* pDC)
{
	CMFC310Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC310View 诊断

#ifdef _DEBUG
void CMFC310View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC310View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC310Doc* CMFC310View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC310Doc)));
	return (CMFC310Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC310View 消息处理程序


void CMFC310View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s = "左键正被按下";
	dc.TextOutW(100, 200, s);


	CView::OnLButtonDown(nFlags, point);
}


void CMFC310View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s;
	s = "左键正在抬起";
	dc.TextOutW(100, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
