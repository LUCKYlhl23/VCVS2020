
// MFCweek11.h : MFCweek11 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCweek11App:
// �йش����ʵ�֣������ MFCweek11.cpp
//

class CMFCweek11App : public CWinApp
{
public:
	CMFCweek11App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCweek11App theApp;
