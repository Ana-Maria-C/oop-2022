#pragma once
class Student
{
	char name;
	float grade_mat;
	float grade_eng;
	float grade_his;
	float average;
public:
	void SetName(char set_name);
	void SetGrade_mat(float mat);
	void SetGrade_eng(float eng);
	void SetGrade_his(float his);
	void SetAverage();
	const char GetName();
	const float GetGrade_mat();
	const float GetGrade_eng();
	const float GetGrade_his();
	const float GetAverage();
	int  Compare_name(Student A, Student B);
	int  Compare_grade_mat(Student A, Student B);
	int  Compare_grade_eng(Student A, Student B);
	int  Compare_grade_his(Student A, Student B);
	int  Compare_grade_average(Student A, Student B);
};