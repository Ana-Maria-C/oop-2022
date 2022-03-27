#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include<cstring>
#include<cstdio>
#include <stdlib.h>

const char* Get_str_value(int n)
{
	int ok = 0;
	int aux = n;
	do
	{
		++ok;
		aux /= 10;
	} while (aux);
	char* sir = new char[ok];
	int i = 0;
	do
	{
		sir[i++] = n % 10 + '0';
		n /= 10;
	} while (n);
	sir[i] = '\0';
	_strrev(sir);
	return sir;
}
int B_to_Ten(int n_b, int b)
{
	int n_10 = 0;
	int p_b = 1;
	do
	{
		n_10 += (n_b % 10) * p_b;
		p_b *= b;
		n_b /= 10;
	} while (n_b);

	return n_10;
}

int Ten_to_B(int n_b, int b)
{
	int rez = 0;
	int p_ten = 1;
	do
	{
		rez += (n_b % b) * p_ten;
		p_ten *= 10;
		n_b /= b;
	} while (n_b);

	return rez;
}


void operator+=(Number& n1, int val)
{
	int n1_int = B_to_Ten(n1.GetValue(),n1.GetBase());
	int sum = n1_int + val;
	sum = Ten_to_B(sum, n1.GetBase());
	memcpy(n1.value_, Get_str_value(sum), strlen(Get_str_value(sum))+1);
}

Number operator+(Number n1, Number n2)
{
	int new_base;
	int n1_int = n1.GetValue();
	int n2_int = n2.GetValue();
	int new_value = n1_int + n2_int;
	if (n1.GetBase() > n2.GetBase())
		new_base = n1.GetBase();
	else
		new_base = n2.GetBase();
	new_value = Ten_to_B(new_value, new_base);
	int ok = 0;
	int aux = new_value;
	do
	{
		++ok;
		aux /= 10;
	} while (aux);
	char* new_value_str= new char[ok];
	memcpy(new_value_str, Get_str_value(new_value), strlen(Get_str_value(new_value))+1);
	Number R = Number(new_value_str, new_base);
		return R;
}
Number operator-(Number n1, Number n2)
{
	int new_base;
	int n1_int = n1.GetValue();
	int n2_int = n2.GetValue();
	int new_value = n1_int - n2_int;
	if (n1.GetBase() > n2.GetBase())
		new_base = n1.GetBase();
	else
		new_base = n2.GetBase();
	new_value = Ten_to_B(new_value, new_base);
	int ok = 0;
	int aux = new_value;
	do
	{
		++ok;
		aux /= 10;
	} while (aux);
	char* new_value_str = new char[ok];
	memcpy(new_value_str, Get_str_value(new_value), strlen(Get_str_value(new_value)) + 1);
	Number R = Number(new_value_str, new_base);
	return R;
}

Number& Number::operator--()
{
	strcpy(value_, value_ + 1);
	return (*this);
}
Number Number::operator--(int)
{
	value_[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}

int Number::GetValue()
{
	int value = 0;
	int n = strlen(this->value_);
	for (int i = 0; i < n; ++i)
	{
		value = value * 10 + (value_[i]-'0');
	}
	return value;
}


bool Number::operator==(Number & n2)
{
	int n1_int = B_to_Ten(this->GetValue(), this->GetBase());
	int n2_int = B_to_Ten(n2.GetValue(), n2.GetBase());
	if (n1_int == n2_int)
		return true;
	return false;
}

bool Number::operator<(Number & n2)
{
	int n1_int = B_to_Ten(this->GetValue(), this->GetBase());
	int n2_int = B_to_Ten(n2.GetValue(), n2.GetBase());
	if (n1_int < n2_int)
		return true;
	return false;
}

bool Number::operator>(Number & n2)
{
	int n1_int = B_to_Ten(this->GetValue(), this->GetBase());
	int n2_int = B_to_Ten(n2.GetValue(), n2.GetBase());
	if (n1_int > n2_int)
		return true;
	return false;
}

char Number::operator[](int index)
{
	return this->value_[index];
}

Number::Number(const Number& num)
{
	this->base_ = num.base_;
	this->value_ = num.value_;
}

Number::Number(const char* value, int base)
{
	this->value_ = new char[strlen(value) + 1];
	memcpy(this->value_, value, strlen(value)+1);
	this->base_ = base;
}

Number::~Number()
{
	delete this->value_;
	this->value_ = nullptr;
}

void Number::SwitchBase(int newBase)
{
	if (this->base_ != newBase)
	{
		int n = atoi(this->value_);
		int aux =B_to_Ten(n,this->base_);
		int rez = Ten_to_B(aux,newBase);
		//memcpy(this->value_, itoa(rez, this->value_,base_), strlen(itoa(rez, this->value_, base_)) + 1);
		
	}
}

Number Number::operator=(int val)
{
	this->base_ = 10;
	int ok = 0;
	int aux = val;
	do
	{
		++ok;
		aux /= 10;
	} while (aux);
	this->value_ = new char [ok];
	//char* new_value_str = new char[ok];
	memcpy(this->value_, Get_str_value(val), strlen(Get_str_value(val)) + 1);
	return (*this);
}

Number Number::operator=(const char* sir)
{
	int base = 0;
	for (int i = 0; i < strlen(sir); ++i)
	{
		if (sir[i] - '0' > base)
			base = sir[i] - '0';
	}
	memcpy(this->value_, sir, strlen(sir) + 1);
	return (*this);
}

Number Number::operator+=(Number n2)
{
	int new_value = B_to_Ten(this->GetValue(), this->GetBase()) + B_to_Ten(n2.GetValue(), n2.GetBase());
	new_value = Ten_to_B(new_value, this->GetBase());
	return (*this);
}

void Number::Print()
{
	printf("%s , %d ", this->value_, this->base_);
}


int Number::GetDigitsCount()
{
	int n_digit = strlen(this->value_);
	return n_digit;
}


int Number::GetBase()
{
	int ok = 2;
	int n = strlen(this->value_);
	for (int i = 0; i < n; ++i)
	{
		int cif = (this->value_[i]-'0');
		if (cif > ok)
			ok = cif;
	}
	++ok;
	return ok;
}



