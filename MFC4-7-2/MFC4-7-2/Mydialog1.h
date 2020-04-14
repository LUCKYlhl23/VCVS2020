#pragma once


// Mydialog1 对话框

class Mydialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(Mydialog1)

public:
	Mydialog1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Mydialog1();

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
};
