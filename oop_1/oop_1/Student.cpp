#include "Student.h"
#include <cstring>
void Student::SetName(char set_name)
{
	strcpy(name, set_name);
}

void Student::SetGrade_mat(float mat)
{
	grade_mat = mat;
}

void Student::SetGrade_eng(float eng)
{
	grade_eng = eng;
}

void Student::SetGrade_his(float his) 
{
	grade_eng = his;
}

void Student::SetAverage()
{
	average = (float)(grade_mat + grade_eng + grade_his);
}

 const char Student::GetName()
{
	return name;
}

const float Student::GetGrade_mat()
{
	return grade_mat;
}

const float Student::GetGrade_eng()
{
	return grade_eng;
}

const float Student::GetGrade_his()
{
	return grade_his;
}

const float Student::GetAverage()
{
	return average;
}

