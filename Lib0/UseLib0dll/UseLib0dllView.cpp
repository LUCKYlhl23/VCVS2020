
// UseLib0dllView.cpp: CUseLib0dllView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UseLib0dll.h"
#endif

#include "UseLib0dllDoc.h"
#include "UseLib0dllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"win32.h"
#include"win32lDLL.h"
// CUseLib0dllView

IMPLEMENT_DYNCREATE(CUseLib0dllView, CView)

BEGIN_MESSAGE_MAP(CUseLib0dllView, CView)
END_MESSAGE_MAP()

// CUseLib0dllView 构造/析构

CUseLib0dllView::CUseLib0dllView() noexcept
{
	// TODO: 在此处添加构造代码

}

CUseLib0dllView::~CUseLib0dllView()
{
}

BOOL CUseLib0dllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUseLib0dllView 绘图

void CUseLib0dllView::OnDraw(CDC* pDC)
{
	CUseLib0dllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s=CString(pchar());
	pDC->TextOutW(200, 300, s);

	CString ss;
	ss.Format(_T("%d,这是从动态库返回的值"),GetInt());
	pDC->TextOutW(200, 400, ss);
	// TODO: 在此处为本机数据添加绘制代码
}


// CUseLib0dllView 诊断

#ifdef _DEBUG
void CUseLib0dllView::AssertValid() const
{
	CView::AssertValid();
}

void CUseLib0dllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUseLib0dllDoc* CUseLib0dllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUseLib0dllDoc)));
	return (CUseLib0dllDoc*)m_pDocument;
}
#endif //_DEBUG


// CUseLib0dllView 消息处理程序
