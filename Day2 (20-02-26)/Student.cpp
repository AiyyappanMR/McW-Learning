#include "Student.h"
#include <iostream>

Student::Student(std::string name, int rollNo)
{
    this->name = name;
    this->rollNo = rollNo;
}

void Student::addCourse(const Course& c)
{
    courses.push_back(c);
}

double Student::calculateGrade()
{
    if (courses.empty())
        return 0.0;

    int totalMarks = 0;
    for (const auto& course : courses)
    {
        totalMarks += course.getMarks();
    }
    double averageMarks = static_cast<double>(totalMarks) / courses.size();

    return averageMarks;
}

void Student::displayInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll No: " << rollNo << std::endl;
    std::cout << "Courses: " << std::endl;
    for (const auto& course : courses)
    {
        std::cout << "- " << course.getCourseName() << ": " << course.getMarks() << std::endl;
    }
    std::cout << "Average Grade: " << calculateGrade() << std::endl;
}