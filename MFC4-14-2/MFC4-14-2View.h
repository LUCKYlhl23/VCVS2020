
// MFC4-14-2View.h: CMFC4142View 类的接口
//

#pragma once


class CMFC4142View : public CView
{
protected: // 仅从序列化创建
	CMFC4142View() noexcept;
	DECLARE_DYNCREATE(CMFC4142View)

// 特性
public:
	CMFC4142Doc* GetDocument() const;
	
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC4142View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowdia();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC4-14-2View.cpp 中的调试版本
inline CMFC4142Doc* CMFC4142View::GetDocument() const
   { return reinterpret_cast<CMFC4142Doc*>(m_pDocument); }
#endif

