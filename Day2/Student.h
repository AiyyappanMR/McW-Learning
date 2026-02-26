#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "Courses.h"

class Student
{
    private:
        std::vector<Course> courses;
    public:
        std::string name;
        int rollNo;
        Student(std::string name, int rollNo);
        void addCourse(const Course& c);
        double calculateGrade();
        void displayInfo();
};

#endif