
// MFC3-31-1View.h: CMFC3311View 类的接口
//

#pragma once


class CMFC3311View : public CView
{
protected: // 仅从序列化创建
	CMFC3311View() noexcept;
	DECLARE_DYNCREATE(CMFC3311View)
	CString m_s ;
	CPoint m_p;
// 特性
public:
	CMFC3311Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3311View();
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
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC3-31-1View.cpp 中的调试版本
inline CMFC3311Doc* CMFC3311View::GetDocument() const
   { return reinterpret_cast<CMFC3311Doc*>(m_pDocument); }
#endif

