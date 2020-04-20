
// MFC4-20-3View.cpp: CMFC4203View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-20-3.h"
#endif

#include "MFC4-20-3Doc.h"
#include "MFC4-20-3View.h"
#include"MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4203View

IMPLEMENT_DYNCREATE(CMFC4203View, CView)

BEGIN_MESSAGE_MAP(CMFC4203View, CView)
	ON_COMMAND(ID_ShowDialog, &CMFC4203View::OnShowdialog)
END_MESSAGE_MAP()

// CMFC4203View 构造/析构

CMFC4203View::CMFC4203View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4203View::~CMFC4203View()
{
}

BOOL CMFC4203View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4203View 绘图

void CMFC4203View::OnDraw(CDC* /*pDC*/)
{
	CMFC4203Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4203View 诊断

#ifdef _DEBUG
void CMFC4203View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4203View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4203Doc* CMFC4203View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4203Doc)));
	return (CMFC4203Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4203View 消息处理程序


void CMFC4203View::OnShowdialog()
{
	// TODO: 在此添加命令处理程序代码
	MyDialog dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{
		double b, l, r, t;
		b = dlg.bottom;
		l = dlg.left;
		r = dlg.right;
		t = dlg.top;
		CRect re(l, t, r, b);
		GetDC()->Ellipse(re);
	}
}
