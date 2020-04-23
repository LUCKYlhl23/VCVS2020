
// MFC4-20-4View.cpp: CMFC4204View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-20-4.h"
#endif

#include "MFC4-20-4Doc.h"
#include "MFC4-20-4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4204View

IMPLEMENT_DYNCREATE(CMFC4204View, CView)

BEGIN_MESSAGE_MAP(CMFC4204View, CView)
	ON_COMMAND(ID_DRAWcircle, &CMFC4204View::OnDrawcircle)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC4204View 构造/析构

CMFC4204View::CMFC4204View() noexcept
{
	// TODO: 在此处添加构造代码
	rect.left = 100;
	rect.top = 200;
	rect.bottom = 350;
	rect.right = 400;
	set = true;
	mpoint = 0;
}

CMFC4204View::~CMFC4204View()
{
}

BOOL CMFC4204View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4204View 绘图

void CMFC4204View::OnDraw(CDC* pDC)
{
	CMFC4204Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//GetDC()->Ellipse(rect.left, rect.top, rect.right,rect.bottom );

	
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4204View 诊断

#ifdef _DEBUG
void CMFC4204View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4204View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4204Doc* CMFC4204View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4204Doc)));
	return (CMFC4204Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4204View 消息处理程序
void CMFC4204View::OnDrawcircle()
{
	// TODO: 在此添加命令处理程序代码
	GetDC()->Ellipse(rect.left, rect.top,  rect.right,rect.bottom);
	

}

void CMFC4204View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	set = true;
	CRect ct;
	//CClientDC dc(this);
	GetClientRect(&ct);
	if (set)
	{
		
		if (point.x>=rect.left&&point.y>=rect.top&&point.x<=rect.right&&point.y<=rect.bottom)
		{
			
			//CBrush *pbrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL));
			//CBrush *oldpbrush = dc.SelectObject(pbrush);
			CBrush br;
			CPen pen(PS_DASH, 0, RGB(128, 128, 128));
			br.CreateStockObject(NULL_BRUSH);
			dc.SelectObject(&pen);
			dc.SelectObject(&br);
			//CPen *oldpen = dc.SelectObject(&pen);
			dc.Rectangle(rect.left, rect.top,  rect.right,rect.bottom);
		
		}
	}
	CView::OnLButtonDown(nFlags, point);
}




