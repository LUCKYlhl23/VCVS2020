#include"pch.h"
#include"win32.h"


char a[] = "从静态库取得的字符串";
char *pchar()
{
	return a;
}

int F1::GetA() {
	return a + 1;
}