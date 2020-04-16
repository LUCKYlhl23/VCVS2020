
// MFC4-14-3View.h: CMFC4143View 类的接口
//

#pragma once


class CMFC4143View : public CView
{
protected: // 仅从序列化创建
	CMFC4143View() noexcept;
	DECLARE_DYNCREATE(CMFC4143View)

// 特性
public:
	CMFC4143Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4143View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // MFC4-14-3View.cpp 中的调试版本
inline CMFC4143Doc* CMFC4143View::GetDocument() const
   { return reinterpret_cast<CMFC4143Doc*>(m_pDocument); }
#endif

