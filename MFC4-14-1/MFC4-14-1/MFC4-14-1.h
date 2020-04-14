
// MFC4-14-1.h: MFC4-14-1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFC4141App:
// 有关此类的实现，请参阅 MFC4-14-1.cpp
//

class CMFC4141App : public CWinApp
{
public:
	CMFC4141App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC4141App theApp;
