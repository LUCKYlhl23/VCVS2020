
// MFCwekk9Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCwekk9.h"
#include "MFCwekk9Dlg.h"
#include "afxdialogex.h"
#include"string"
#include"iostream"
#include"fstream"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
	
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCwekk9Dlg �Ի���



CMFCwekk9Dlg::CMFCwekk9Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCwekk9Dlg::IDD, pParent)
	, cc(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	i = 0;
}

void CMFCwekk9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LBox);
	DDX_Text(pDX, IDC_EDIT1, cc);
}

BEGIN_MESSAGE_MAP(CMFCwekk9Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCwekk9Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCwekk9Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCwekk9Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCwekk9Dlg::OnEnChangeEdit1)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDOK, &CMFCwekk9Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMFCwekk9Dlg ��Ϣ�������

BOOL CMFCwekk9Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCwekk9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCwekk9Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCwekk9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCwekk9Dlg::OnLbnSelchangeList1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//ʹ����ʾ���༭����
	CString str;
	i = LBox.GetCurSel();
	LBox.GetText(i, str);
	UpdateData();
	cc = str;
	UpdateData(false);

}


void CMFCwekk9Dlg::OnBnClickedButton1()
{
	//���б������޸�
	CString str;
	UpdateData(true);
	str = cc;
	LBox.DeleteString(i);
	LBox.InsertString(i, str);
	UpdateData(false);

}


void CMFCwekk9Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog cfd(true);
	CString filename;
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		filename = cfd.GetPathName();
		string s;
		ifstream ifs(filename);

		CClientDC dc(this);
		int x = 20, y = 20;
		while (ifs >> s)
		{
			//CListBox *listbox = (CListBox*)GetDlgItem(IDC_LIST1);

			LBox.AddString(CString(s.c_str()));
		}
	}
}


void CMFCwekk9Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}


void CMFCwekk9Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMFCwekk9Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCwekk9Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	this->UpdateData(true);
	CString cc1 = cc;
	LBox.DeleteString(i);
	LBox.InsertString(i, cc1);
	UpdateData(false);
	ofstream oo(_T("D:\\ѧ������.txt"));
	for (int k = 0; k < LBox.GetCount(); k++)
	{
		LBox.GetText(k, cc);
		oo << CT2A(cc) << endl;
	}
	oo.close();

	CDialogEx::OnOK();
}
