
// MFCwekk9Dlg.h : ͷ�ļ�
//

#pragma once


// CMFCwekk9Dlg �Ի���
class CMFCwekk9Dlg : public CDialogEx
{
// ����
public:
	CMFCwekk9Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	int i;
// �Ի�������
	enum { IDD = IDD_MFCWEKK9_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
