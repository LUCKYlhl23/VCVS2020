
// UseLib0dllView.h: CUseLib0dllView 类的接口
//

#pragma once


class CUseLib0dllView : public CView
{
protected: // 仅从序列化创建
	CUseLib0dllView() noexcept;
	DECLARE_DYNCREATE(CUseLib0dllView)

// 特性
public:
	CUseLib0dllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CUseLib0dllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UseLib0dllView.cpp 中的调试版本
inline CUseLib0dllDoc* CUseLib0dllView::GetDocument() const
   { return reinterpret_cast<CUseLib0dllDoc*>(m_pDocument); }
#endif

