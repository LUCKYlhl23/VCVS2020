
// MFC3-2-4View.h: CMFC324View 类的接口
//

#pragma once


class CMFC324View : public CView
{
protected: // 仅从序列化创建
	CMFC324View() noexcept;
	DECLARE_DYNCREATE(CMFC324View)

// 特性
public:
	CMFC324Doc* GetDocument() const;

// 操作
public:
	int r, g, b;
	bool set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC324View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

#ifndef _DEBUG  // MFC3-2-4View.cpp 中的调试版本
inline CMFC324Doc* CMFC324View::GetDocument() const
   { return reinterpret_cast<CMFC324Doc*>(m_pDocument); }
#endif

