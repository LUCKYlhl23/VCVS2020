#pragma once


// Srrw �Ի���

class Srrw : public CDialogEx
{
	DECLARE_DYNAMIC(Srrw)

public:
	Srrw(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Srrw();
	CString isok;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void draw_pic(CString file);
};
