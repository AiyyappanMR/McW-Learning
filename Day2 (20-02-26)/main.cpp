#include "Student.h"
#include "Courses.h"
#include <iostream>

int main()
{
    Student S1("AiyyappanMR", 2);
    Course SC1("RL", 90);
    Course SC2("DSA", 95);
    Course SC3("OS", 85);
    S1.addCourse(SC1);
    S1.addCourse(SC2);
    S1.addCourse(SC3);
    S1.displayInfo();
    return 0;
}

