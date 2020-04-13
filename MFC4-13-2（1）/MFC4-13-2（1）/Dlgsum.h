#pragma once


// Dlgsum 对话框

class Dlgsum : public CDialogEx
{
	DECLARE_DYNAMIC(Dlgsum)

public:
	Dlgsum(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Dlgsum();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double add1;
	afx_msg void OnEnChangeEdit2();
	double add2;
	double addsum;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};
