
// MFCWeek9-2View.h: CMFCWeek92View 类的接口
//

#pragma once


class CMFCWeek92View : public CView
{
protected: // 仅从序列化创建
	CMFCWeek92View() noexcept;
	DECLARE_DYNCREATE(CMFCWeek92View)

// 特性
public:
	CMFCWeek92Doc* GetDocument() const;
	bool flag;
// 操作
public:
	CRect crect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCWeek92View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCWeek9-2View.cpp 中的调试版本
inline CMFCWeek92Doc* CMFCWeek92View::GetDocument() const
   { return reinterpret_cast<CMFCWeek92Doc*>(m_pDocument); }
#endif

