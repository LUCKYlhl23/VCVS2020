
// MFweek13-1View.h : CMFweek131View ��Ľӿ�
//

#pragma once

class CMFweek131Set;

class CMFweek131View : public CRecordView
{
protected: // �������л�����
	CMFweek131View();
	DECLARE_DYNCREATE(CMFweek131View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFWEEK131_FORM };
#endif
	CMFweek131Set* m_pSet;
	CString path;
// ����
public:
	CMFweek131Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFweek131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString name;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void draw_pic(CString file);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFweek13-1View.cpp �еĵ��԰汾
inline CMFweek131Doc* CMFweek131View::GetDocument() const
   { return reinterpret_cast<CMFweek131Doc*>(m_pDocument); }
#endif

