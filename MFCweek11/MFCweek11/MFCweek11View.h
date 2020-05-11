
// MFCweek11View.h : CMFCweek11View ��Ľӿ�
//

#pragma once

class CMFCweek11Set;

class CMFCweek11View : public CRecordView
{
protected: // �������л�����
	CMFCweek11View();
	DECLARE_DYNCREATE(CMFCweek11View)

public:
	enum{ IDD = IDD_MFCWEEK11_FORM };
	CMFCweek11Set* m_pSet;

// ����
public:
	CMFCweek11Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMFCweek11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString snumber;
	CString age;
	CString telephone;
};

#ifndef _DEBUG  // MFCweek11View.cpp �еĵ��԰汾
inline CMFCweek11Doc* CMFCweek11View::GetDocument() const
   { return reinterpret_cast<CMFCweek11Doc*>(m_pDocument); }
#endif

