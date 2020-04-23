
// MFC4-20-5View.h: CMFC4205View 类的接口
//

#pragma once


class CMFC4205View : public CView
{
protected: // 仅从序列化创建
	CMFC4205View() noexcept;
	DECLARE_DYNCREATE(CMFC4205View)

// 特性
public:
	CMFC4205Doc* GetDocument() const;

// 操作
public:
	CRect rect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4205View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnputout();
};

#ifndef _DEBUG  // MFC4-20-5View.cpp 中的调试版本
inline CMFC4205Doc* CMFC4205View::GetDocument() const
   { return reinterpret_cast<CMFC4205Doc*>(m_pDocument); }
#endif

