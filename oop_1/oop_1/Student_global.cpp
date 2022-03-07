#include<cstring>
#include "Student.h"
int Compare_name(Student A, Student B)
{
	return strcmp(A.GetName(), B.GetName());
}

int Compare_grade_mat(Student A, Student B)
{
	if (A.GetGrade_mat() > B.GetGrade_mat())
		return 1;
	if (A.GetGrade_mat() < B.GetGrade_mat())
		return -1;
	return 0;
}

int Compare_grade_eng(Student A, Student B)
{
	if (A.GetGrade_eng() > B.GetGrade_eng())
		return 1;
	if (A.GetGrade_eng() < B.GetGrade_eng())
		return -1;
	return 0;
}

int Compare_grade_his(Student A, Student B)
{
	if (A.GetGrade_his() > B.GetGrade_his())
		return 1;
	if (A.GetGrade_his() < B.GetGrade_his())
		return -1;
	return 0;
}

int Compare_grade_average(Student A, Student B)
{
	if (A.GetAverage() > B.GetAverage())
		return 1;
	if (A.GetAverage() < B.GetAverage())
		return -1;
	return 0;
}
