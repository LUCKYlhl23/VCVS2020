
// MFweek13-3.h : MFweek13-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFweek133App:
// �йش����ʵ�֣������ MFweek13-3.cpp
//

class CMFweek133App : public CWinApp
{
public:
	CMFweek133App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFweek133App theApp;
