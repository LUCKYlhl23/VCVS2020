
// MFC317-3.h: MFC317-3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFC3173App:
// 有关此类的实现，请参阅 MFC317-3.cpp
//

class CMFC3173App : public CWinApp
{
public:
	CMFC3173App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC3173App theApp;
