// Srrw.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFweek13-1.h"
#include "Srrw.h"
#include "afxdialogex.h"
#include"MFweek13-1Doc.h"
#include"MFweek13-1View.h"

// Srrw �Ի���

IMPLEMENT_DYNAMIC(Srrw, CDialogEx)

Srrw::Srrw(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	isok = _T("E:\\ABCPicture\\ͼ���ļ�\\");
}

Srrw::~Srrw()
{
	
}

void Srrw::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Srrw, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Srrw ��Ϣ�������


void Srrw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString filename, s;
	//GetDlgItemText(IDC_EDIT1, s); // ��һ���Ǳ༭�ؼ���ID
	filename = isok ;
	//dc.TextOutW(200, 300, filename);
	draw_pic(filename);				   // TODO: �ڴ˴������Ϣ����������
									   //Invalidate();					
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
void Srrw::draw_pic(CString file)
{
	CImage img;
	img.Load(file);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	int sx, sy, w, h;
	CRect rect;
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_rat = 1.0*rect.Width() / rect.Height();
	float img_rat = 1.0*img.GetWidth() / img.GetHeight();
	if (rect_rat > img_rat)
	{
		h = rect.Height();
		w = img_rat*h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else
	{
		w = rect.Width();
		h = w / img_rat;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
	pDC->SetStretchBltMode(HALFTONE);
	img.Draw(pDC->m_hDC, sx, sy, w, h);
}

