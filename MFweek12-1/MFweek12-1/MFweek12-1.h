
// MFweek12-1.h : MFweek12-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFweek121App:
// �йش����ʵ�֣������ MFweek12-1.cpp
//

class CMFweek121App : public CWinAppEx
{
public:
	CMFweek121App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFweek121App theApp;
