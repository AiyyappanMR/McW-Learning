#include <iostream>

class Student {  
    private:
        double cgpa;
    public:
        std::string name;
        int age;
        std::string department; 
        Student(std::string n, int a, std::string d, double c) {
            name = n;
            age = a;
            department = d;
            setCgpa(c);
        } 
        void setCgpa(double c) {
            if (c >= 0.0 && c <= 10.0) {
                cgpa = c;
            } 
            else {
                std::cout << "Invalid CGPA. Please enter a value between 0.0 and 10.0." << std::endl;
                cgpa = 0.0; 
            }
        }
        void displayInfo() {
            std::cout << "Student Information:" << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Department: " << department << std::endl;
            std::cout << "CGPA: " << cgpa << std::endl;
        }
};

int main(){

    Student s1("AiyyappanMR", 21, "Computer Science",11.0);
    s1.displayInfo();
    return 0;
}