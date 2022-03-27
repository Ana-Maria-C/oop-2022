#pragma once
class Number

{
	int base_;
	char* value_;

public:

	Number(const Number& num);
	
	Number(const char* value, int base); // where base is between 2 and 16

	~Number();


	// add operators and copy/move constructor
    friend void operator+=(Number& n1, int val);
	friend Number operator+(Number n1, Number n2);
	friend Number operator-(Number n1, Number n2);
	Number operator+=(Number n);
	Number operator=(int val);
	Number operator=(const char* sir);
	Number& operator--();
	Number operator--(int);
	char operator[] (int index);
	bool operator< (Number& n);
	bool operator> (Number& n);
	bool operator<= (Number& n);
	bool operator>= (Number& n);
	bool operator== (Number& n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	//int B_to_Ten(int number, int base);
	//int Ten_to_B(int number, int base);
	int  GetBase(); // returns the current base
	int  GetValue();

};
