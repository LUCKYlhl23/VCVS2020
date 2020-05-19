
// MFweek12-1View.cpp : CMFweek121View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFweek121View ����/����

CMFweek121View::CMFweek121View()
	: CRecordView(IDD_MFWEEK121_FORM)
	
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("E:\\ABCPicture\\ͼ���ļ�\\");

}

CMFweek121View::~CMFweek121View()
{
}

void CMFweek121View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek121View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek121Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek121View ��ӡ

BOOL CMFweek121View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFweek121View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFweek121View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFweek121View ���

#ifdef _DEBUG
void CMFweek121View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek121View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek121Doc* CMFweek121View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek121Doc)));
	return (CMFweek121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek121View ���ݿ�֧��
CRecordset* CMFweek121View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek121View ��Ϣ�������


void CMFweek121View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFweek121View::OnRecordLast()
{
	// TODO: �ڴ���������������
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
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CRecordView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFweek121View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s); // ��һ���Ǳ༭�ؼ���ID
	filename = path + s;
	draw_pic(filename);				   // TODO: �ڴ˴������Ϣ����������
	//Invalidate();				   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}
