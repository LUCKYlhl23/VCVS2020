
// MFCAUsestax1View.cpp: CMFCAUsestax1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCAUsestax1.h"
#endif

#include "MFCAUsestax1Doc.h"
#include "MFCAUsestax1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"

// CMFCAUsestax1View

IMPLEMENT_DYNCREATE(CMFCAUsestax1View, CView)

BEGIN_MESSAGE_MAP(CMFCAUsestax1View, CView)
END_MESSAGE_MAP()

// CMFCAUsestax1View 构造/析构

CMFCAUsestax1View::CMFCAUsestax1View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCAUsestax1View::~CMFCAUsestax1View()
{
}

BOOL CMFCAUsestax1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCAUsestax1View 绘图

void CMFCAUsestax1View::OnDraw(CDC* pDC)
{
	CMFCAUsestax1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("%d,这是从静态库中得到的factorial(5)的值"), factorial(5));
	pDC->TextOutW(200, 300, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCAUsestax1View 诊断

#ifdef _DEBUG
void CMFCAUsestax1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAUsestax1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAUsestax1Doc* CMFCAUsestax1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAUsestax1Doc)));
	return (CMFCAUsestax1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAUsestax1View 消息处理程序
