#include "Courses.h"

Course::Course(std::string courseName, int marks)
{
    this->courseName = courseName;
    this->marks = marks;
}

std::string Course::getCourseName() const
{
    return courseName;
}

int Course::getMarks() const
{
    return marks;
}