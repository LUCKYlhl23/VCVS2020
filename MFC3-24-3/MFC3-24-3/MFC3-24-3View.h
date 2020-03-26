
// MFC3-24-3View.h: CMFC3243View 类的接口
//

#pragma once


class CMFC3243View : public CView
{
protected: // 仅从序列化创建
	CMFC3243View() noexcept;
	DECLARE_DYNCREATE(CMFC3243View)

// 特性
public:
	CMFC3243Doc* GetDocument() const;

// 操作
public:
	CPoint m_pt;
	UINT m_nd;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3243View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStline();
	afx_msg void OnDrect();
	afx_msg void OnDoval();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3-24-3View.cpp 中的调试版本
inline CMFC3243Doc* CMFC3243View::GetDocument() const
   { return reinterpret_cast<CMFC3243Doc*>(m_pDocument); }
#endif

