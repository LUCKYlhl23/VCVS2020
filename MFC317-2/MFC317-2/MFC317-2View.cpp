
// MFC317-2View.cpp: CMFC3172View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC317-2.h"
#endif

#include "MFC317-2Doc.h"
#include "MFC317-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3172View

IMPLEMENT_DYNCREATE(CMFC3172View, CView)

BEGIN_MESSAGE_MAP(CMFC3172View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3172View 构造/析构

CMFC3172View::CMFC3172View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3172View::~CMFC3172View()
{
}

BOOL CMFC3172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3172View 绘图

void CMFC3172View::OnDraw(CDC* pDC)
{
	CMFC3172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->crect);

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3172View 诊断

#ifdef _DEBUG
void CMFC3172View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3172Doc* CMFC3172View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3172Doc)));
	return (CMFC3172Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3172View 消息处理程序


void CMFC3172View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3172Doc* pDoc = GetDocument();
	CRect cr;
	GetClientRect(&cr);
	switch (nChar)
	{
	case VK_UP:
			if (pDoc->crect.top > 0)
			{
				pDoc->crect.top -= 7;
				pDoc->crect.bottom -= 7;
			}
			break;
	case VK_DOWN:
		if (pDoc->crect.bottom <= (cr.bottom -cr.top))
		{
			pDoc->crect.top += 7;
			pDoc->crect.bottom += 7;
		}
		break;
	case VK_LEFT:
		if (pDoc->crect.left > 0)
		{
			pDoc->crect.left -= 7;
			pDoc->crect.right -= 7;
		}
		break;
	case VK_RIGHT:
		if (pDoc->crect.right <= (cr.right- cr.left ))
		{
			pDoc->crect.left += 7;
			pDoc->crect.right += 7;
		}
		break;
	case VK_HOME:
		if(pDoc->crect.left > 0&&pDoc->crect.top > 0)
		{
			pDoc->crect.left -= 7;
			pDoc->crect.top -= 7;
			
		}break;
	case VK_END:
		if (pDoc->crect.bottom <= (cr.bottom - cr.top)&& pDoc->crect.right <= (cr.right - cr.left))
		{
			pDoc->crect.right+= 7;
			pDoc->crect.bottom += 7;

		}break;
		
	}InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC3172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFC3172Doc* pDoc = GetDocument();
	pDoc->crect.top = 100;
	pDoc->crect.bottom = 250;
	pDoc->crect.left = 70;
	pDoc->crect.right = 220;
	InvalidateRect(NULL,TRUE);
	CView::OnLButtonDown(nFlags, point);
}
