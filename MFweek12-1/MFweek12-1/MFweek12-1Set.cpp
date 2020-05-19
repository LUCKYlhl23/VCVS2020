
// MFweek12-1Set.cpp : CMFweek121Set ���ʵ��
//

#include "stdafx.h"
#include "MFweek12-1.h"
#include "MFweek12-1Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFweek121Set ʵ��

// ���������� 2020��5��18��, 20:19

IMPLEMENT_DYNAMIC(CMFweek121Set, CRecordset)

CMFweek121Set::CMFweek121Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFweek121Set::GetDefaultConnect()
{
	return _T("DSN=\x7167\x7247\x4fe1\x606f\x8868;DBQ=E:\\\x6570\x636e\x5e93mdb\\Database\x7167\x7247.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFweek121Set::GetDefaultSQL()
{
	return _T("[��Ƭ��Ϣ��]");
}

void CMFweek121Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFweek121Set ���

#ifdef _DEBUG
void CMFweek121Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFweek121Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

