
// MFCAUSEView.cpp: CMFCAUSEView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCAUSE.h"
#endif

#include "MFCAUSEDoc.h"
#include "MFCAUSEView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"

// CMFCAUSEView

IMPLEMENT_DYNCREATE(CMFCAUSEView, CView)

BEGIN_MESSAGE_MAP(CMFCAUSEView, CView)
END_MESSAGE_MAP()

// CMFCAUSEView 构造/析构

CMFCAUSEView::CMFCAUSEView() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCAUSEView::~CMFCAUSEView()
{
}

BOOL CMFCAUSEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCAUSEView 绘图

void CMFCAUSEView::OnDraw(CDC* pDC)
{
	CMFCAUSEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	FAC a1;
	float rad;
	rad = 30.0 / atan(1.0);
	s.Format(_T("%02f"),rad);
	pDC->TextOutW(200, 300, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCAUSEView 诊断

#ifdef _DEBUG
void CMFCAUSEView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAUSEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAUSEDoc* CMFCAUSEView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAUSEDoc)));
	return (CMFCAUSEDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAUSEView 消息处理程序
