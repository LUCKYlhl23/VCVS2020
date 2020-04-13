
// MFC4-13-2（1）View.cpp: CMFC41321View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC4-13-2（1）.h"
#endif

#include "MFC4-13-2（1）Doc.h"
#include "MFC4-13-2（1）View.h"
#include"Dlgsum.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC41321View

IMPLEMENT_DYNCREATE(CMFC41321View, CView)

BEGIN_MESSAGE_MAP(CMFC41321View, CView)
	ON_COMMAND(ID_Ontput, &CMFC41321View::OnOntput)
END_MESSAGE_MAP()

// CMFC41321View 构造/析构

CMFC41321View::CMFC41321View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFC41321View::~CMFC41321View()
{
}

BOOL CMFC41321View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC41321View 绘图

void CMFC41321View::OnDraw(CDC*pDC)
{
	CMFC41321Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFC41321View 诊断

#ifdef _DEBUG
void CMFC41321View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC41321View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC41321Doc* CMFC41321View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC41321Doc)));
	return (CMFC41321Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC41321View 消息处理程序


void CMFC41321View::OnOntput()
{
	// TODO: 在此添加命令处理程序代码
	Dlgsum dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		double Add1, Add2, Addsum;
		Add1 = dlg.add1;
		Add2 = dlg.add2;
		Addsum = dlg.addsum;
		UpdateData(true);//读取编辑框的值到关联的值变量中
		Addsum = Add1 + Add2;//计算结果存到编辑框的关联变量中
		UpdateData(false);//将计算的结果显示到编辑框中
	}
}
