
// MFC4-14-3View.cpp: CMFC4143View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-14-3.h"
#endif

#include "MFC4-14-3Doc.h"
#include "MFC4-14-3View.h"
#include"MyDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4143View

IMPLEMENT_DYNCREATE(CMFC4143View, CView)

BEGIN_MESSAGE_MAP(CMFC4143View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &CMFC4143View::OnPopout)
END_MESSAGE_MAP()

// CMFC4143View 构造/析构

CMFC4143View::CMFC4143View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4143View::~CMFC4143View()
{
}

BOOL CMFC4143View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4143View 绘图

void CMFC4143View::OnDraw(CDC* /*pDC*/)
{
	CMFC4143Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4143View 诊断

#ifdef _DEBUG
void CMFC4143View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4143View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4143Doc* CMFC4143View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4143Doc)));
	return (CMFC4143Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4143View 消息处理程序


void CMFC4143View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFC4143Doc* pDoc = GetDocument();
	CFileDialog dlg(true);
	int t = dlg.DoModal();
	if (t == IDOK)
	{	
		pDoc->filename = dlg.GetPathName();

	}
	
	CView::OnLButtonDblClk(nFlags, point);
}


void CMFC4143View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg mydlg;
	int r = mydlg.DoModal();
	if (r == IDOK)
	{

	}
}
