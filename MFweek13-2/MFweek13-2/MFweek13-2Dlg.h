
// MFweek13-2Dlg.h : ͷ�ļ�
//

#pragma once


// CMFweek132Dlg �Ի���
class CMFweek132Dlg : public CDialogEx
{
// ����
public:
	CMFweek132Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	CString finename;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFWEEK132_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	void draw_pic();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
