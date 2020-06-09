
// MFweek13-1View.cpp : CMFweek131View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// CMFweek131View ����/����

CMFweek131View::CMFweek131View()
	: CRecordView(IDD_MFWEEK131_FORM)
	, name(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("E:\\ABCPicture\\ͼ���ļ�\\");

}

CMFweek131View::~CMFweek131View()
{
}

void CMFweek131View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek131View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek131Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek131View ��ӡ

BOOL CMFweek131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFweek131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFweek131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMFweek131View ���

#ifdef _DEBUG
void CMFweek131View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek131View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek131Doc* CMFweek131View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek131Doc)));
	return (CMFweek131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek131View ���ݿ�֧��
CRecordset* CMFweek131View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek131View ��Ϣ�������


void CMFweek131View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Srrw dia;
	CString filename, s;
	GetDlgItemText(IDC_EDIT1, s); // ��һ���Ǳ༭�ؼ���ID
	filename = path + s;
	dia.isok = filename;
	dia.DoModal();
}


void CMFweek131View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordPrev()
{
	// TODO: �ڴ���������������
    m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())
		m_pSet->MoveLast();
	UpdateData(false);
	Invalidate();
}


void CMFweek131View::OnRecordLast()
{
	// TODO: �ڴ���������������
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
	GetDlgItemText(IDC_EDIT1, s); // ��һ���Ǳ༭�ؼ���ID
	filename = path + s;
	draw_pic(filename);					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
}
