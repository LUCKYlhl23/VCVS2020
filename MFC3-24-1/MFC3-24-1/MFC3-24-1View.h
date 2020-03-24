
// MFC3-24-1View.h: CMFC3241View 类的接口
//

#pragma once


class CMFC3241View : public CView
{
protected: // 仅从序列化创建
	CMFC3241View() noexcept;
	DECLARE_DYNCREATE(CMFC3241View)

// 特性
public:
	CMFC3241Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC3241View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowname();
};

#ifndef _DEBUG  // MFC3-24-1View.cpp 中的调试版本
inline CMFC3241Doc* CMFC3241View::GetDocument() const
   { return reinterpret_cast<CMFC3241Doc*>(m_pDocument); }
#endif

