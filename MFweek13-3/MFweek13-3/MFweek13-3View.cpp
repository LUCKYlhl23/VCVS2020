
// MFweek13-3View.cpp : CMFweek133View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFweek13-3.h"
#endif

#include "MFweek13-3Set.h"
#include "MFweek13-3Doc.h"
#include "MFweek13-3View.h"
#include"ADD_DLG.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFweek133View

IMPLEMENT_DYNCREATE(CMFweek133View, CRecordView)

BEGIN_MESSAGE_MAP(CMFweek133View, CRecordView)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFweek133View::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFweek133View::OnBnClickedADD)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFweek133View::OnBnClickedReduce)
END_MESSAGE_MAP()

// CMFweek133View ����/����

CMFweek133View::CMFweek133View()
	: CRecordView(IDD_MFWEEK133_FORM)
	, yesok(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

CMFweek133View::~CMFweek133View()
{
}

void CMFweek133View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->m_1);
}

BOOL CMFweek133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void CMFweek133View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_MFweek133Set;
	CRecordView::OnInitialUpdate();

}


// CMFweek133View ���

#ifdef _DEBUG
void CMFweek133View::AssertValid() const
{
	CRecordView::AssertValid();
}

void CMFweek133View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

CMFweek133Doc* CMFweek133View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFweek133Doc)));
	return (CMFweek133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFweek133View ���ݿ�֧��
CRecordset* CMFweek133View::OnGetRecordset()
{
	return m_pSet;
}



// CMFweek133View ��Ϣ�������


void CMFweek133View::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_pSet->Delete();
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())
		m_pSet->MoveFirst();
	UpdateData(false);
	
}


void CMFweek133View::OnBnClickedADD()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->AddNew();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}


void CMFweek133View::OnBnClickedReduce()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//UpdateData(true);
	ADD_DLG adddlg;
	int r = adddlg.DoModal();
	if (r == IDOK)
	{
		long ii = adddlg.i;
		m_pSet->Edit();
		m_pSet->m_1 = ii;
		m_pSet->Update();
		UpdateData(false);
	}
}
