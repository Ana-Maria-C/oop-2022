#include "Canvas.h"
#include<cstdio>
#include<cmath>
void Canvas::DrawCircle( int &x, int &y, int ray, char ch)
{
	Clear();
	x = this->width / 2;
	y = this->height / 2;
	this->matrix[x][y] = ch;
	for(int i=0;i<this->width;i++)
		for (int j = 0; j < this->height; j++)
		{
			double d;
			d = sqrt((x - i) * (x - i) + (y - j) * (y - j));
			if (abs(d - ray) < 1)
				this ->matrix[i][j] = ch;
		}
}

void Canvas::FillCircle(int &x, int &y, int ray, char ch)
{
	x = this->width / 2;
	y = this->height / 2;
	this->matrix[x][y] = ch;
	for (int i = 0; i < this->width; i++)
		for (int j = 0; j < this->height; j++)
		{
			double d;
			d = sqrt((x - i) * (x - i) + (y - j) * (y - j));
			if (d<ray)
				this->matrix[i][j] = ch;
		}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	Clear();
	for (int j = left; j <= right; j++)
	{
		this->matrix[top][j] = ch;
		this->matrix[bottom][j] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		this->matrix[i][left] = ch;
		this->matrix[i][right] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top+1; i < bottom; i++)
		for (int j = left+1; j < right; j++)
			this->matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	Clear();
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	Clear();
	if (x1 > x2)
	{
		int aux = x1;
		x1 = x2;
		x2 = aux;
		aux = y1;
		y1 = y2;
		y2 = aux;
	}
	if(x1<x2-2)
		for (int i = x1; i <= x2; i++)
		{
			int j;
			j = (y2 - y1) * (i - x1) / (x2 - x1) + y1;
			this->matrix[i][j] = ch;
		}
	else
	{
		if (y1 > y2)
		{
			int aux = x1;
			x1 = x2;
			x2 = aux;
			aux = y1;
			y1 = y2;
			y2 = aux;
		}
		for (int j = y1; j <= y2; j++)
		{
			int i;
			i = (x2 - x1) * (j - y1) / (y2 - y1) + x1;
			this->matrix[i][j] = ch;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++)
			printf("%c", this->matrix[i][j]);
		printf("\n");
	}
}

void Canvas::Clear()
{
	memset(matrix, ' ', sizeof(matrix));
}




