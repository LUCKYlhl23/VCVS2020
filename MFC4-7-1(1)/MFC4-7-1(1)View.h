
// MFC4-7-1(1)View.h: CMFC4711View 类的接口
//

#pragma once


class CMFC4711View : public CView
{
protected: // 仅从序列化创建
	CMFC4711View() noexcept;
	DECLARE_DYNCREATE(CMFC4711View)

// 特性
public:
	CMFC4711Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4711View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC4-7-1(1)View.cpp 中的调试版本
inline CMFC4711Doc* CMFC4711View::GetDocument() const
   { return reinterpret_cast<CMFC4711Doc*>(m_pDocument); }
#endif

