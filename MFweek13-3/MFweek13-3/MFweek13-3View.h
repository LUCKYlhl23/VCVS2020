
// MFweek13-3View.h : CMFweek133View ��Ľӿ�
//

#pragma once

class CMFweek133Set;

class CMFweek133View : public CRecordView
{
protected: // �������л�����
	CMFweek133View();
	DECLARE_DYNCREATE(CMFweek133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFWEEK133_FORM };
#endif
	CMFweek133Set* m_pSet;

// ����
public:
	CMFweek133Doc* GetDocument() const;

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
	virtual ~CMFweek133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString yesok;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedADD();
	afx_msg void OnBnClickedReduce();
};

#ifndef _DEBUG  // MFweek13-3View.cpp �еĵ��԰汾
inline CMFweek133Doc* CMFweek133View::GetDocument() const
   { return reinterpret_cast<CMFweek133Doc*>(m_pDocument); }
#endif

