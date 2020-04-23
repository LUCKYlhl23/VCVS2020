
// MFC4-20-2View.h: CMFC4202View 类的接口
//

#pragma once


class CMFC4202View : public CView
{
protected: // 仅从序列化创建
	CMFC4202View() noexcept;
	DECLARE_DYNCREATE(CMFC4202View)

// 特性
public:
	CMFC4202Doc* GetDocument() const;

// 操作
public:
	int m_nd1, m_nd11, m_nd2, m_nd21, m_nd,m_nd0;
	CRect rect;
	bool set;
	
	
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4202View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4-20-2View.cpp 中的调试版本
inline CMFC4202Doc* CMFC4202View::GetDocument() const
   { return reinterpret_cast<CMFC4202Doc*>(m_pDocument); }
#endif

