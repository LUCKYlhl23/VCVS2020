
// MFweek12-1View.cpp : CMFweek121View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFweek12-1.h"
#endif

#include "MFweek12-1Set.h"
#include "MFweek12-1Doc.h"
#include "MFweek12-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFweek121View

IMPLEMENT_DYNCREATE(CMFweek121View, CRecordView)

BEGIN_MESSAGE_MAP(CMFweek121View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_RECORD_FIRST, &CMFweek121View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &CMFweek121View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &CMFweek121View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &CMFweek121View::OnRecordLast)
	ON_EN_CHANGE(IDC_EDIT1, &CMFweek121View::OnEnChangeEdit1)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMFweek121View 构造/析构

CMFweek121View::CMFweek121View()
	: CRecordView(IDD_MFWEEK121_FORM)
	
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("E:\\ABCPicture\\图像文件\\");

}

CMFweek121View::~CMFweek121View()
{
}

void CMFweek121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek121Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek121View 打印

BOOL CMFweek121View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFweek121View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFweek121View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFweek121View 诊断

#ifdef _DEBUG
void CMFweek121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek121Doc* CMFweek121View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek121Doc)));
	return (CMFweek121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek121View 数据库支持
CRecordset* CMFweek121View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek121View 消息处理程序


void CMFweek121View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}
void CMFweek121View::draw_pic(CString file)
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


void CMFweek121View::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CRecordView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFweek121View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s); // 第一个是编辑控件的ID
	filename = path + s;
	draw_pic(filename);				   // TODO: 在此处添加消息处理程序代码
	//Invalidate();				   // 不为绘图消息调用 CRecordView::OnPaint()
}
