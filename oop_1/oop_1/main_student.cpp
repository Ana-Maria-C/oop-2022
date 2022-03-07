#include "Student.h"
#include <iostream>

int main() {
    Student A;
    A.SetName("Alin");
    A.SetGrade_mat(8.90);
    A.SetGrade_eng(6.38);
    A.SetGrade_his(10);
    Student B;
    B.SetName("Bianca");
    B.SetGrade_mat(5.50);
    B.SetGrade_eng(9.78);
    B.SetGrade_his(7.34);
    printf("%d  %d  %d  %d  %d",
        Compare_name(A, B),
        Compare_grade_mat(A, B),
        Compare_grade_eng(A, B),
        Compare_grade_his(A, B),
        Compare_grade_average(A, B));
    return 0;
}