// win32lDLL.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "win32lDLL.h"


// 这是导出变量的一个示例
WIN32LDLL_API int nwin32lDLL=0;

// 这是导出函数的一个示例。
WIN32LDLL_API int fnwin32lDLL(void)
{
    return 0;
}
WIN32LDLL_API int GetInt() {
	return 2020;
}
// 这是已导出类的构造函数。
Cwin32lDLL::Cwin32lDLL()
{
    return;
}
