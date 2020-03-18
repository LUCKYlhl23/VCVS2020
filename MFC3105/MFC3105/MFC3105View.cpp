
// MFC3105View.cpp: CMFC3105View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3105.h"
#endif

#include "MFC3105Doc.h"
#include "MFC3105View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3105View

IMPLEMENT_DYNCREATE(CMFC3105View, CView)

BEGIN_MESSAGE_MAP(CMFC3105View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3105View 构造/析构

CMFC3105View::CMFC3105View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3105View::~CMFC3105View()
{
}

BOOL CMFC3105View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3105View 绘图

void CMFC3105View::OnDraw(CDC* pDC)
{
	CMFC3105Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CClientDC dc(this);
	dc.Rectangle(100,0,200,300);
	dc.Rectangle(400,0,500,300);
	dc.Rectangle(600,0,700,300);
}


// CMFC3105View 诊断

#ifdef _DEBUG
void CMFC3105View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3105View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3105Doc* CMFC3105View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3105Doc)));
	return (CMFC3105Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3105View 消息处理程序


void CMFC3105View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CMFC3105Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("点击无效"));
	srand((unsigned)time(NULL));

	pDoc->a = rand() % 100;
	pDoc->b = rand() % +100;
	pDoc->c = pDoc->a + pDoc->b;
	if (point.x > 100 && point.x < 200 && point.y < 300){
		CString aa;
	aa.Format(_T("%d"), pDoc->a);
	dc.TextOutW(point.x,point.y,  aa);
	}
	else if (point.x > 400 && point.x < 500 && point.y < 300) {
		CString bb;
		bb.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, bb);
	}
	else if (point.x > 600 && point.x < 700 && point.y < 300) {
		CString cc;
		cc.Format(_T("%d"), pDoc->c);
		dc.TextOutW(point.x, point.y, cc);
	}
	else dc.TextOutW(230, 333, s);

	/*CClientDC dc(this);
	CMFC3105Doc* pDoc = GetDocument();
	CString s;
	int t1 = rand() % 100;
	s.Format(_T("%d"), t1);
	if (point.x > 100 && point.x < 200 && point.y < 300)
		dc.TextOutW(point.x, point.y, s);
		if (point.x > 400 && point.x < 500 && point.y < 300)
			dc.TextOutW(point.x, point.y, s);
			if (point.x > 600 && point.x < 700 && point.y < 300)
				dc.TextOutW(point.x, point.y, s);
			else { 
				s = "点击无效";
			dc.TextOutW(point.x, point.y, s);
			}
			*/
	CView::OnLButtonDown(nFlags, point);
}
