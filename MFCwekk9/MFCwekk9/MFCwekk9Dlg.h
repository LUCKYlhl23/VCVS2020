
// MFCwekk9Dlg.h : 头文件
//

#pragma once


// CMFCwekk9Dlg 对话框
class CMFCwekk9Dlg : public CDialogEx
{
// 构造
public:
	CMFCwekk9Dlg(CWnd* pParent = NULL);	// 标准构造函数
	int i;
// 对话框数据
	enum { IDD = IDD_MFCWEKK9_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CListBox LBox;
	CString cc;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedOk();
};
