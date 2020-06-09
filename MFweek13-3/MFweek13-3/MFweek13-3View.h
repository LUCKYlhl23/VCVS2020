
// MFweek13-3View.h : CMFweek133View 类的接口
//

#pragma once

class CMFweek133Set;

class CMFweek133View : public CRecordView
{
protected: // 仅从序列化创建
	CMFweek133View();
	DECLARE_DYNCREATE(CMFweek133View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFWEEK133_FORM };
#endif
	CMFweek133Set* m_pSet;

// 特性
public:
	CMFweek133Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFweek133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString yesok;
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedADD();
	afx_msg void OnBnClickedReduce();
};

#ifndef _DEBUG  // MFweek13-3View.cpp 中的调试版本
inline CMFweek133Doc* CMFweek133View::GetDocument() const
   { return reinterpret_cast<CMFweek133Doc*>(m_pDocument); }
#endif

