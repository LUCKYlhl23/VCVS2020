
// MFC4-7-1(1)View.cpp: CMFC4711View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-7-1(1).h"
#endif

#include "MFC4-7-1(1)Doc.h"
#include "MFC4-7-1(1)View.h"
#include"Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4711View

IMPLEMENT_DYNCREATE(CMFC4711View, CView)

BEGIN_MESSAGE_MAP(CMFC4711View, CView)
END_MESSAGE_MAP()

// CMFC4711View 构造/析构

CMFC4711View::CMFC4711View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4711View::~CMFC4711View()
{
}

BOOL CMFC4711View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4711View 绘图

void CMFC4711View::OnDraw(CDC* pDC)
{
	CMFC4711Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
CString s;
	Mydlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		
		
		
	}
	s.Format(_T("你已退出对话框"));
	pDC->TextOutW(200, 200, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4711View 诊断

#ifdef _DEBUG
void CMFC4711View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4711View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4711Doc* CMFC4711View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4711Doc)));
	return (CMFC4711Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4711View 消息处理程序
