
// MFC3105View.h: CMFC3105View 类的接口
//

#pragma once


class CMFC3105View : public CView
{
protected: // 仅从序列化创建
	CMFC3105View() noexcept;
	DECLARE_DYNCREATE(CMFC3105View)

// 特性
public:
	CMFC3105Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3105View();
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

#ifndef _DEBUG  // MFC3105View.cpp 中的调试版本
inline CMFC3105Doc* CMFC3105View::GetDocument() const
   { return reinterpret_cast<CMFC3105Doc*>(m_pDocument); }
#endif

