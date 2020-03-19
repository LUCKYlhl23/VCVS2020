
// MFC309tView.h: CMFC309tView 类的接口
//

#pragma once


class CMFC309tView : public CView
{
protected: // 仅从序列化创建
	CMFC309tView() noexcept;
	DECLARE_DYNCREATE(CMFC309tView)

// 特性
public:
	CMFC309tDoc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect&>ca;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC309tView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC309tView.cpp 中的调试版本
inline CMFC309tDoc* CMFC309tView::GetDocument() const
   { return reinterpret_cast<CMFC309tDoc*>(m_pDocument); }
#endif

