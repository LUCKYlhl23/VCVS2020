
// MFC3-24-1View.cpp: CMFC3241View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-24-1.h"
#endif

#include "MFC3-24-1Doc.h"
#include "MFC3-24-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3241View

IMPLEMENT_DYNCREATE(CMFC3241View, CView)

BEGIN_MESSAGE_MAP(CMFC3241View, CView)
	ON_COMMAND(ID_SHOWNAME, &CMFC3241View::OnShowname)
END_MESSAGE_MAP()

// CMFC3241View 构造/析构

CMFC3241View::CMFC3241View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3241View::~CMFC3241View()
{
}

BOOL CMFC3241View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3241View 绘图

void CMFC3241View::OnDraw(CDC* /*pDC*/)
{
	CMFC3241Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3241View 诊断

#ifdef _DEBUG
void CMFC3241View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3241View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3241Doc* CMFC3241View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3241Doc)));
	return (CMFC3241Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3241View 消息处理程序


void CMFC3241View::OnShowname()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString s;
	s.Format(_T("我的名字是梁慧琳"));
	dc.TextOutW(200, 200, s);
}
