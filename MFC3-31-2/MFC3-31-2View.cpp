
// MFC3-31-2View.cpp: CMFC3312View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-31-2.h"
#endif

#include "MFC3-31-2Doc.h"
#include "MFC3-31-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3312View

IMPLEMENT_DYNCREATE(CMFC3312View, CView)

BEGIN_MESSAGE_MAP(CMFC3312View, CView)
	ON_WM_CHAR()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3312View 构造/析构

CMFC3312View::CMFC3312View() noexcept
{
	// TODO: 在此处添加构造代码
	m_s = "";
	pp.x = 0;
	pp.y = 0;
}

CMFC3312View::~CMFC3312View()
{
}

BOOL CMFC3312View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3312View 绘图

void CMFC3312View::OnDraw(CDC* /*pDC*/)
{
	CMFC3312Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3312View 诊断

#ifdef _DEBUG
void CMFC3312View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3312View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3312Doc* CMFC3312View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3312Doc)));
	return (CMFC3312Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3312View 消息处理程序

void CMFC3312View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	m_s.Empty();
	pp = point;
	CView::OnLButtonDown(nFlags, point);
}

void CMFC3312View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if (0x0d == nChar)
	{
		m_s.Empty();
		pp.y += tm.tmHeight;

	}
	else if (0x08 == nChar)
	{
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(pp.x, pp.y, m_s);
		m_s = m_s.Left(m_s.GetLength() - 1);
		dc.SetTextColor(clr);
	}
	else
	{
		m_s += (LPCTSTR)&nChar;
	}
	CSize sc = dc.GetTextExtent(m_s);
	CPoint pt;
	pt.x = pp.x + sc.cx;
	pt.y = pp.y;
	SetCaretPos(pt);
	dc.TextOutW(pp.x, pp.y, m_s);
	/*if (nChar == 13)//enter的字符码值是13
	{
		pp.x = 0;
		pp.y += 18;
		SetCaretPos(pp);
		ShowCaret();

	}
	else
	{
		CClientDC dc(this);
		HideCaret();
		dc.TextOutW(pp.x, pp.y, (LPCTSTR)&nChar);
		CSize size = dc.GetTextExtent((LPCTSTR)&nChar);
		pp.x += size.cx;
		SetCaretPos(pp);
		ShowCaret();

	}*/
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC3312View::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);
	CreateSolidCaret(pp.x, 18);
	SetCaretPos(pp);
	ShowCaret();
	// TODO: 在此处添加消息处理程序代码
}


