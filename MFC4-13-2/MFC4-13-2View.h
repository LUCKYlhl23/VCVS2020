
// MFC4-13-2View.h: CMFC4132View 类的接口
//

#pragma once


class CMFC4132View : public CView
{
protected: // 仅从序列化创建
	CMFC4132View() noexcept;
	DECLARE_DYNCREATE(CMFC4132View)

// 特性
public:
	CMFC4132Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4132View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC4-13-2View.cpp 中的调试版本
inline CMFC4132Doc* CMFC4132View::GetDocument() const
   { return reinterpret_cast<CMFC4132Doc*>(m_pDocument); }
#endif

