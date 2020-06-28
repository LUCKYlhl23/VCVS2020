
// MFCWeek9-2.h: MFCWeek9-2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMFCWeek92App:
// 有关此类的实现，请参阅 MFCWeek9-2.cpp
//

class CMFCWeek92App : public CWinApp
{
public:
	CMFCWeek92App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCWeek92App theApp;
