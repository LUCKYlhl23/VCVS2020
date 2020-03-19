﻿
// MFC310.h: MFC310 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFC310App:
// 有关此类的实现，请参阅 MFC310.cpp
//

class CMFC310App : public CWinApp
{
public:
	CMFC310App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC310App theApp;
