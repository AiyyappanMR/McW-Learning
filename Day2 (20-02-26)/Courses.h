#ifndef COURSES_H
#define COURSES_H

#include <string>

class Course
{
    private:
        std::string courseName;
        int marks;
    public:
        Course(std::string courseName, int marks);
        std::string getCourseName() const;
        int getMarks() const;
};

#endif