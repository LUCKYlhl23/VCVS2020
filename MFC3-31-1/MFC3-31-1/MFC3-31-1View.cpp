
// MFC3-31-1View.cpp: CMFC3311View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-31-1.h"
#endif

#include "MFC3-31-1Doc.h"
#include "MFC3-31-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3311View

IMPLEMENT_DYNCREATE(CMFC3311View, CView)

BEGIN_MESSAGE_MAP(CMFC3311View, CView)
	ON_WM_CHAR()
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFC3311View 构造/析构

CMFC3311View::CMFC3311View() noexcept
{
	// TODO: 在此处添加构造代码
	m_s = " ";
	m_p.x= 0;
	m_p.y = 0;
}

CMFC3311View::~CMFC3311View()
{
}

BOOL CMFC3311View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3311View 绘图

void CMFC3311View::OnDraw(CDC* pDC)
{
	CMFC3311Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC3311View 诊断

#ifdef _DEBUG
void CMFC3311View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3311View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3311Doc* CMFC3311View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3311Doc)));
	return (CMFC3311Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3311View 消息处理程序


void CMFC3311View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	

	//CRect c;
	//GetClientRect(&c);
	TEXTMETRIC txt;//当前输入字符
	if (nChar == 13)//enter的字符码值是13
	{
		m_p.x = 0;
		m_p.y += 18;
		SetCaretPos(m_p);
		ShowCaret();

	}
	else
	{
		CClientDC dc(this);
		HideCaret();
		dc.TextOutW(m_p.x, m_p.y, (LPCTSTR)&nChar);
		CSize size=dc.GetTextExtent((LPCTSTR)&nChar);
		m_p.x += size.cx;
		SetCaretPos(m_p);
		ShowCaret();

	}
	/*dc.GetTextMetrics(&txt);
	if (0x0d == nChar)
	{
		m_s.Empty();
		m_p.y += txt.tmHeight;
	}
	else if (0x08 == nChar) {
		//退格键的删除处理
		COLORREF clr = dc.SetTextColor(dc.GetBkColor());  //先将文本颜色设置为与客户区背景色相同
		dc.TextOut(m_p.x, m_p.y, m_s);  //将文本输出一次
		m_s = m_s.Left(m_s.GetLength() - 1);  //删除插入符之前的一个字符
		dc.SetTextColor(clr);  //再把文本的颜色设置为原来的颜色    
	}

	else
	{
		m_s += m_s;
	}
	 = dc.GetTextExtent(m_s);//找客户区的字符串显示的宽和高
	CPoint point;
	point.x = m_p.x + size.cx;//插入符的横坐标移到以输出的字符后面
	point.y = m_p.y;
	SetCaretPos(point);//设置坐标
	dc.TextOutW(m_p.x, m_p.y,m_s);*/
	CView::OnChar(nChar, nRepCnt, nFlags);
}


//void CMFC3311View::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	SetCaretPos(point);
//	m_s.Empty();
//	m_p = point;
//	CView::OnLButtonDown(nFlags, point);
//}
