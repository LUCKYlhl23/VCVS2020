
// MFCweek11View.h : CMFCweek11View 类的接口
//

#pragma once

class CMFCweek11Set;

class CMFCweek11View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCweek11View();
	DECLARE_DYNCREATE(CMFCweek11View)

public:
	enum{ IDD = IDD_MFCWEEK11_FORM };
	CMFCweek11Set* m_pSet;

// 特性
public:
	CMFCweek11Doc* GetDocument() const;

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
	virtual ~CMFCweek11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	long ID;
	CString name;
	CString snumber;
	CString age;
	CString telephone;
};

#ifndef _DEBUG  // MFCweek11View.cpp 中的调试版本
inline CMFCweek11Doc* CMFCweek11View::GetDocument() const
   { return reinterpret_cast<CMFCweek11Doc*>(m_pDocument); }
#endif

