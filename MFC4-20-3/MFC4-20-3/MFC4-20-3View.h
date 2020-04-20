
// MFC4-20-3View.h: CMFC4203View 类的接口
//

#pragma once


class CMFC4203View : public CView
{
protected: // 仅从序列化创建
	CMFC4203View() noexcept;
	DECLARE_DYNCREATE(CMFC4203View)

// 特性
public:
	CMFC4203Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4203View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowdialog();
};

#ifndef _DEBUG  // MFC4-20-3View.cpp 中的调试版本
inline CMFC4203Doc* CMFC4203View::GetDocument() const
   { return reinterpret_cast<CMFC4203Doc*>(m_pDocument); }
#endif

