
// MFC4-13-2（1）View.h: CMFC41321View 类的接口
//

#pragma once


class CMFC41321View : public CView
{
protected: // 仅从序列化创建
	CMFC41321View() noexcept;
	DECLARE_DYNCREATE(CMFC41321View)

// 特性
public:
	CMFC41321Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC41321View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOntput();
};

#ifndef _DEBUG  // MFC4-13-2（1）View.cpp 中的调试版本
inline CMFC41321Doc* CMFC41321View::GetDocument() const
   { return reinterpret_cast<CMFC41321Doc*>(m_pDocument); }
#endif

