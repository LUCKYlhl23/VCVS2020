
// MFweek13-3Set.cpp : CMFweek133Set ���ʵ��
//

#include "stdafx.h"
#include "MFweek13-3.h"
#include "MFweek13-3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFweek133Set ʵ��

// ���������� 2020��6��8��, 19:47

IMPLEMENT_DYNAMIC(CMFweek133Set, CRecordset)

CMFweek133Set::CMFweek133Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = 0;
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CMFweek133Set::GetDefaultConnect()
{
	return _T("DSN=\x8bb0\x5f55\x96c6;DBQ=E:\\\x6570\x636e\x5e93MDB\\\x8bb0\x5f55\x96c6.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CMFweek133Set::GetDefaultSQL()
{
	return _T("[�������ݿ��¼��]");
}

void CMFweek133Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[�ֶ�1]"), m_1);

}
/////////////////////////////////////////////////////////////////////////////
// CMFweek133Set ���

#ifdef _DEBUG
void CMFweek133Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMFweek133Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

