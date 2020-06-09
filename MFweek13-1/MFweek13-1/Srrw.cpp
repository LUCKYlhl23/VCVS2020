// Srrw.cpp : 实现文件
//

#include "stdafx.h"
#include "MFweek13-1.h"
#include "Srrw.h"
#include "afxdialogex.h"
#include"MFweek13-1Doc.h"
#include"MFweek13-1View.h"

// Srrw 对话框

IMPLEMENT_DYNAMIC(Srrw, CDialogEx)

Srrw::Srrw(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	isok = _T("E:\\ABCPicture\\图像文件\\");
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


// Srrw 消息处理程序


void Srrw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CString filename, s;
	//GetDlgItemText(IDC_EDIT1, s); // 第一个是编辑控件的ID
	filename = isok ;
	//dc.TextOutW(200, 300, filename);
	draw_pic(filename);				   // TODO: 在此处添加消息处理程序代码
									   //Invalidate();					
					   // 不为绘图消息调用 CDialogEx::OnPaint()
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

