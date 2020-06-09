#pragma once


// Srrw 对话框

class Srrw : public CDialogEx
{
	DECLARE_DYNAMIC(Srrw)

public:
	Srrw(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Srrw();
	CString isok;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void draw_pic(CString file);
};
