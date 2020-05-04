#include "win32.h"
#include "pch.h"



int factorial(int n)
{
	if (n < 0)
		return -1;
	if (n == 1)
		return 1;
	else {
		return n * factorial(n - 1);
	}
}
