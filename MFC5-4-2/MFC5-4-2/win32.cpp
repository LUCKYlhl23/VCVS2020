#include"pch.h"
#include"win32.h"
#include"math.h"

float FAC::convert(float deg)
{
	float rad;
	rad = deg / atan(1.0);
	return rad;
}
