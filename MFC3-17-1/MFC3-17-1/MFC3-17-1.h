﻿
// MFC3-17-1.h: MFC3-17-1 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFC3171App:
// 有关此类的实现，请参阅 MFC3-17-1.cpp
//

class CMFC3171App : public CWinApp
{
public:
	CMFC3171App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC3171App theApp;