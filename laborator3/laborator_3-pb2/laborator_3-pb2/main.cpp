#include "Canvas.h"
int main()
{
	Canvas C(50, 50);
	int x, y;
	C.DrawCircle(x, y, 10, 'o');
	C.FillCircle(x, y, 10, 'x');
	//C.DrawRect(10, 10, 20, 20, 'u');
	//C.FillRect(10, 10, 20, 20, 'a');
	//C.SetPoint(20, 20, 'Z');
	//C.DrawLine(5, 27, 8, 3, 'm');
	C.Print();

}