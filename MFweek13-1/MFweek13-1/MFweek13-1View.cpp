
// MFweek13-1View.cpp : CMFweek131View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFweek13-1.h"
#endif

#include "MFweek13-1Set.h"
#include "MFweek13-1Doc.h"
#include "MFweek13-1View.h"
#include"Srrw.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include"iostream"
#include"string"
#include"fstream"
using namespace std;

// CMFweek131View

IMPLEMENT_DYNCREATE(CMFweek131View, CRecordView)

BEGIN_MESSAGE_MAP(CMFweek131View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFweek131View::OnBnClickedButton1)
	ON_COMMAND(ID_RECORD_FIRST, &CMFweek131View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFweek131View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFweek131View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFweek131View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFweek131View 构造/析构

CMFweek131View::CMFweek131View()
	: CRecordView(IDD_MFWEEK131_FORM)
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\ABCPicture\\图像文件\\");

}

CMFweek131View::~CMFweek131View()
{
}

void CMFweek131View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek131View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek131Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek131View 打印

BOOL CMFweek131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFweek131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFweek131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFweek131View 诊断

#ifdef _DEBUG
void CMFweek131View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek131View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek131Doc* CMFweek131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek131Doc)));
	return (CMFweek131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek131View 数据库支持
CRecordset* CMFweek131View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek131View 消息处理程序


void CMFweek131View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Srrw dia;
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s); // 第一个是编辑控件的ID
	filename = path + s;
	dia.isok = filename;
	dia.DoModal();
}


void CMFweek131View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
    m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}
void CMFweek131View::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_rat = 1.0*rect.Width() / rect.Height();
	float img_rat = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_rat > img_rat)
	{
		h = rect.Height();
		w = img_rat*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_rat;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}


void CMFweek131View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s); // 第一个是编辑控件的ID
	filename = path + s;
	draw_pic(filename);					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
}
