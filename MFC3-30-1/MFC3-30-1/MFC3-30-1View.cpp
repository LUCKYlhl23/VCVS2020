
// MFC3-30-1View.cpp: CMFC3301View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC3-30-1.h"
#endif

#include "MFC3-30-1Doc.h"
#include "MFC3-30-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC3301View

IMPLEMENT_DYNCREATE(CMFC3301View, CView)

BEGIN_MESSAGE_MAP(CMFC3301View, CView)
	ON_COMMAND(ID_FILE_OPEN, &CMFC3301View::OnFileOpen)
END_MESSAGE_MAP()

// CMFC3301View 构造/析构

CMFC3301View::CMFC3301View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC3301View::~CMFC3301View()
{
}

BOOL CMFC3301View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC3301View 绘图

void CMFC3301View::OnDraw(CDC* pDC)
{
	CMFC3301Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}



// CMFC3301View 诊断

#ifdef _DEBUG
void CMFC3301View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC3301View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC3301Doc* CMFC3301View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC3301Doc)));
	return (CMFC3301Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC3301View 消息处理程序





void CMFC3301View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	
	if (r == IDOK)
	{
		CString filename = cfd.GetPathName();
		dc.TextOutW(200, 10, filename);
		CImage img;
		img.Load(filename);
		float h, w, sx, sy;
		{
		CRect rt;
		//GetDlgItem(IDC_STATIC)->
			GetClientRect(&rt);
			sx = (rt.Width() - img.GetWidth()) / 2;
			sy = (rt.Height() - img.GetHeight()) / 2;
	/*	float rt_ra = 1.0*rt.Width() / rt.Height();
		float img_ta = 1.0*img.GetWidth() / img.GetHeight();
		if (rt_ra > img_ta)
		{
			h = rt.Height();
			w = img_ta * h;
			sx = (rt.Width() - w) / 2;
			sy = 0;
		}
		else
		{
			w = rt.Width();
			h = w / img_ta;
			sx = 0;
			sy = (rt.Height() - h) / 2;
		}*/
		
		}
		img.Draw(dc.m_hDC, sx, sy,img.GetWidth(),img.GetHeight());
	}
}
