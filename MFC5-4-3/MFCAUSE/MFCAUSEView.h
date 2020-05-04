
// MFCAUSEView.h: CMFCAUSEView 类的接口
//

#pragma once


class CMFCAUSEView : public CView
{
protected: // 仅从序列化创建
	CMFCAUSEView() noexcept;
	DECLARE_DYNCREATE(CMFCAUSEView)

// 特性
public:
	CMFCAUSEDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFCAUSEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCAUSEView.cpp 中的调试版本
inline CMFCAUSEDoc* CMFCAUSEView::GetDocument() const
   { return reinterpret_cast<CMFCAUSEDoc*>(m_pDocument); }
#endif

