#pragma once


// Mydialog 对话框

class Mydialog : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog)

public:
	Mydialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Mydialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString s1;
	CString s2;
	int t;
	afx_msg void OnBnClickedButton1();
};
