
// MFC3-24-2View.cpp: CMFC3242View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-24-2.h"
#endif

#include "MFC3-24-2Doc.h"
#include "MFC3-24-2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3242View

IMPLEMENT_DYNCREATE(CMFC3242View, CView)

BEGIN_MESSAGE_MAP(CMFC3242View, CView)
END_MESSAGE_MAP()

// CMFC3242View 构造/析构

CMFC3242View::CMFC3242View() noexcept
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m_Bitmap.LoadBitmapW(IDB_BITMAP2);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;

}

CMFC3242View::~CMFC3242View()
{
}

BOOL CMFC3242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3242View 绘图

void CMFC3242View::OnDraw(CDC* pDC)
{
	CMFC3242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
}


// CMFC3242View 诊断

#ifdef _DEBUG
void CMFC3242View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3242Doc* CMFC3242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3242Doc)));
	return (CMFC3242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3242View 消息处理程序
