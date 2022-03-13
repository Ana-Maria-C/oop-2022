#include "Math.h"
#include <stdarg.h>
int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return (int)(x + y);
}

int Math::Add(double x, double y, double z)
{
	return (int)(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return(int)(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return(int)(x * y * z);
}

int Math::Add(int count, ...)
{
    int* p = &count;
    int x, sum=0;
    va_list args;
    va_start(args, count);
    for (unsigned i = 0; i < count; i++) {
        x = va_arg(args, int);
		sum += x;
    }
    va_end(args);
	return sum;
}

char* Math::Add(const char* s, const char* t)
{
	if(!(s && t))
	return nullptr;
	s = new char;
	t = new char;
}
