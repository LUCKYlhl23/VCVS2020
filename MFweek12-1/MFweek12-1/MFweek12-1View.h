
// MFweek12-1View.h : CMFweek121View ��Ľӿ�
//

#pragma once

class CMFweek121Set;

class CMFweek121View : public CRecordView
{
protected: // �������л�����
	CMFweek121View();
	DECLARE_DYNCREATE(CMFweek121View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFWEEK121_FORM };
#endif
	CMFweek121Set* m_pSet;
	CString path;

// ����
public:
	CMFweek121Doc* GetDocument() const;

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
	virtual ~CMFweek121View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	void draw_pic(CString file);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // MFweek12-1View.cpp �еĵ��԰汾
inline CMFweek121Doc* CMFweek121View::GetDocument() const
   { return reinterpret_cast<CMFweek121Doc*>(m_pDocument); }
#endif

