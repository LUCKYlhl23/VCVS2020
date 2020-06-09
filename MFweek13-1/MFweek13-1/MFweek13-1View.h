
// MFweek13-1View.h : CMFweek131View 类的接口
//

#pragma once

class CMFweek131Set;

class CMFweek131View : public CRecordView
{
protected: // 仅从序列化创建
	CMFweek131View();
	DECLARE_DYNCREATE(CMFweek131View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFWEEK131_FORM };
#endif
	CMFweek131Set* m_pSet;
	CString path;
// 特性
public:
	CMFweek131Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFweek131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // MFweek13-1View.cpp 中的调试版本
inline CMFweek131Doc* CMFweek131View::GetDocument() const
   { return reinterpret_cast<CMFweek131Doc*>(m_pDocument); }
#endif

