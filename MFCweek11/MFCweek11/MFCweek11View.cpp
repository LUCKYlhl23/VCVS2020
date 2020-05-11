
// MFCweek11View.cpp : CMFCweek11View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCweek11.h"
#endif

#include "MFCweek11Set.h"
#include "MFCweek11Doc.h"
#include "MFCweek11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCweek11View

IMPLEMENT_DYNCREATE(CMFCweek11View, CRecordView)

BEGIN_MESSAGE_MAP(CMFCweek11View, CRecordView)
END_MESSAGE_MAP()

// CMFCweek11View ����/����

CMFCweek11View::CMFCweek11View()
	: CRecordView(CMFCweek11View::IDD)
	, ID(0)
	, name(_T(""))
	, snumber(_T(""))
	, age(_T(""))
	, telephone(_T(""))
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

CMFCweek11View::~CMFCweek11View()
{
}

void CMFCweek11View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL CMFCweek11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFCweek11View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFCweek11Set;
	CRecordView::OnInitialUpdate();

}


// CMFCweek11View ���

#ifdef _DEBUG
void CMFCweek11View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFCweek11View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFCweek11Doc* CMFCweek11View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCweek11Doc)));
	return (CMFCweek11Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCweek11View ���ݿ�֧��
CRecordset* CMFCweek11View::OnGetRecordset()
{
	return m_pSet;
}



// CMFCweek11View ��Ϣ�������
