
// MFC317-3View.cpp: CMFC3173View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC317-3.h"
#endif

#include "MFC317-3Doc.h"
#include "MFC317-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3173View

IMPLEMENT_DYNCREATE(CMFC3173View, CView)

BEGIN_MESSAGE_MAP(CMFC3173View, CView)
	ON_WM_TIMER()
	
END_MESSAGE_MAP()

// CMFC3173View 构造/析构

CMFC3173View::CMFC3173View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;

}

CMFC3173View::~CMFC3173View()
{
}

BOOL CMFC3173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3173View 绘图

void CMFC3173View::OnDraw(CDC* pDC)
{
	CMFC3173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set)
	{
		
			SetTimer(1, rand() % 400 + 100,NULL);
		
		set = false;
	}
	pDC->Ellipse(pDoc->circle);
	// TODO: 在此处为本机数据添加绘制代码
	
}


// CMFC3173View 诊断

#ifdef _DEBUG
void CMFC3173View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3173Doc* CMFC3173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3173Doc)));
	return (CMFC3173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3173View 消息处理程序


void CMFC3173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC3173Doc* pDoc = GetDocument();
	CRect ct;//窗口
	this->GetClientRect(&ct);
	int i = nIDEvent;
	if (pDoc->di == 1 && pDoc->circle.bottom<=ct.bottom)
	{
		pDoc->circle.top += 50;
		pDoc->circle.bottom += 50;
		Invalidate();
	}
	else pDoc->di = 0;
	if (pDoc->di == 0 && pDoc->circle.top > 0)
	{
		pDoc->circle.top -= 50;
		pDoc->circle.bottom -= 50;
		Invalidate();
	}
	
	
	CView::OnTimer(nIDEvent);
}



