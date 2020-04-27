
// MFC4-21-2View.cpp: CMFC4212View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-21-2.h"
#endif

#include "MFC4-21-2Doc.h"
#include "MFC4-21-2View.h"
#include"MyDlg.h"
#include"string"
#include"iostream"
#include"fstream"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC4212View

IMPLEMENT_DYNCREATE(CMFC4212View, CView)

BEGIN_MESSAGE_MAP(CMFC4212View, CView)
	
	ON_COMMAND(ID_FILE_OPEN, &CMFC4212View::OnFileOpen)
	ON_COMMAND(ID_POPOUT, &CMFC4212View::OnPopout)
END_MESSAGE_MAP()

// CMFC4212View 构造/析构

CMFC4212View::CMFC4212View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC4212View::~CMFC4212View()
{
}

BOOL CMFC4212View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC4212View 绘图

void CMFC4212View::OnDraw(CDC* pDC)
{
	CMFC4212Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC4212View 诊断

#ifdef _DEBUG
void CMFC4212View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC4212View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC4212Doc* CMFC4212View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC4212Doc)));
	return (CMFC4212Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC4212View 消息处理程序



void CMFC4212View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CMFC4212Doc* pDoc = GetDocument();
	if (r == IDOK)
	{
		pDoc->filename = cfd.GetPathName();
		string s;
		ifstream ifs(pDoc->filename);

		CClientDC dc(this);
		int x = 20, y = 20;
		while (ifs >> s)
		{
			pDoc->filename = CString(s.c_str());
			dc.TextOutW(x, y, CString(s.c_str()));
			y += 30;
		}

	}
}


void CMFC4212View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int r = dlg.DoModal();
	if (r == IDOK)
	{

	}
}
