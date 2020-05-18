
// MFCweek11Set.cpp : CMFCweek11Set ���ʵ��
//

#include "stdafx.h"
#include "MFCweek11.h"
#include "MFCweek11Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCweek11Set ʵ��

// ���������� 2020��5��11��, 14:35

IMPLEMENT_DYNAMIC(CMFCweek11Set, CRecordset)

CMFCweek11Set::CMFCweek11Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û�������֤��
CString CMFCweek11Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x5e93\x5b66\x751f\x4fe1\x606f\x8868;DBQ=E:\\VC\x5b9e\x9a8c\x8bfe\x5b9e\x9a8c\\Database41.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFCweek11Set::GetDefaultSQL()
{
	return _T("[���ݿ�ѧ����Ϣ��]");
}

void CMFCweek11Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);

}
/////////////////////////////////////////////////////////////////////////////
// CMFCweek11Set ���

#ifdef _DEBUG
void CMFCweek11Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFCweek11Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
