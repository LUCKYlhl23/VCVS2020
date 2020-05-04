// W32D.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "W32D.h"
#include"math.h"

// 这是导出变量的一个示例
W32D_API int nW32D=0;

// 这是导出函数的一个示例。
W32D_API int fnW32D(void)
{
    return 0;
}

W32D_API float convert(float deg)
{
	float rad;
	rad= deg / atan(1.0);
	return rad;
}

W32D_API int Getfac(int n)
{
	if (n == 1) return 1;
	else return Getfac(n-1)*n ;
}



// 这是已导出类的构造函数。
CW32D::CW32D()
{
    return;
}
