
// MFC3-2-3View.cpp: CMFC323View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-2-3.h"
#endif

#include "MFC3-2-3Doc.h"
#include "MFC3-2-3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC323View

IMPLEMENT_DYNCREATE(CMFC323View, CView)

BEGIN_MESSAGE_MAP(CMFC323View, CView)
END_MESSAGE_MAP()

// CMFC323View 构造/析构

CMFC323View::CMFC323View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC323View::~CMFC323View()
{
}

BOOL CMFC323View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC323View 绘图

void CMFC323View::OnDraw(CDC* pDC)
{
	CMFC323Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;

	this->GetClientRect(rect);

	pDC->Ellipse(rect);
}


// CMFC323View 诊断

#ifdef _DEBUG
void CMFC323View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC323View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC323Doc* CMFC323View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC323Doc)));
	return (CMFC323Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC323View 消息处理程序
