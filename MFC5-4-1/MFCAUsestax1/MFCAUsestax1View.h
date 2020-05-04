
// MFCAUsestax1View.h: CMFCAUsestax1View 类的接口
//

#pragma once


class CMFCAUsestax1View : public CView
{
protected: // 仅从序列化创建
	CMFCAUsestax1View() noexcept;
	DECLARE_DYNCREATE(CMFCAUsestax1View)

// 特性
public:
	CMFCAUsestax1Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCAUsestax1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCAUsestax1View.cpp 中的调试版本
inline CMFCAUsestax1Doc* CMFCAUsestax1View::GetDocument() const
   { return reinterpret_cast<CMFCAUsestax1Doc*>(m_pDocument); }
#endif

