
// MFC3-24-3View.cpp: CMFC3243View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-24-3.h"
#endif

#include "MFC3-24-3Doc.h"
#include "MFC3-24-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3243View

IMPLEMENT_DYNCREATE(CMFC3243View, CView)

BEGIN_MESSAGE_MAP(CMFC3243View, CView)
	ON_COMMAND(ID_STLine, &CMFC3243View::OnStline)
	ON_COMMAND(ID_DRect, &CMFC3243View::OnDrect)
	ON_COMMAND(ID_DOVal, &CMFC3243View::OnDoval)
	
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC3243View 构造/析构

CMFC3243View::CMFC3243View() noexcept
{
	// TODO: 在此处添加构造代码
	m_nd = 0;
	m_pt = 0;
}

CMFC3243View::~CMFC3243View()
{
}

BOOL CMFC3243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3243View 绘图

void CMFC3243View::OnDraw(CDC* pDC)
{
	CMFC3243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3243View 诊断

#ifdef _DEBUG
void CMFC3243View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3243Doc* CMFC3243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3243Doc)));
	return (CMFC3243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3243View 消息处理程序


void CMFC3243View::OnStline()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 1;
}


void CMFC3243View::OnDrect()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 2;
}


void CMFC3243View::OnDoval()
{
	// TODO: 在此添加命令处理程序代码
	m_nd = 3;
}



void CMFC3243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt = point;

	CView::OnLButtonDown(nFlags, point);
}


void CMFC3243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	switch (m_nd)
	{
		case 1:
			dc.MoveTo(m_pt);
			dc.LineTo(point);
			break;
		case 2:
			dc.Rectangle(CRect(m_pt, point));
			break;
		case 3:
			dc.Ellipse(CRect(m_pt, point));
			break;
			
			break;
	}
	CView::OnLButtonUp(nFlags, point);
}
