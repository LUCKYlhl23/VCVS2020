
// MFweek13-1.h : MFweek13-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFweek131App:
// �йش����ʵ�֣������ MFweek13-1.cpp
//

class CMFweek131App : public CWinAppEx
{
public:
	CMFweek131App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFweek131App theApp;
