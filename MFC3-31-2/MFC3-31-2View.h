﻿
// MFC3-31-2View.h: CMFC3312View 类的接口
//

#pragma once


class CMFC3312View : public CView
{
protected: // 仅从序列化创建
	CMFC3312View() noexcept;
	DECLARE_DYNCREATE(CMFC3312View)

// 特性
public:
	CMFC3312Doc* GetDocument() const;
	CString m_s;
	CPoint pp;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3312View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3-31-2View.cpp 中的调试版本
inline CMFC3312Doc* CMFC3312View::GetDocument() const
   { return reinterpret_cast<CMFC3312Doc*>(m_pDocument); }
#endif

