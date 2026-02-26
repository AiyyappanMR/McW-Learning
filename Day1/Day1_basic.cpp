#include <iostream>

int main(){
    std::string name = "AiyyappanRM";
    int age = 21;
    bool isMale = true;
    float height = 5.11;
    char temp = name[9];
    name[9] = name[10];
    name[10] = temp;        
    std::cout <<name.length() << std::endl;
    std::cout << name.find("a") << std::endl;
    std::cout << name.substr(1,4) << std::endl;
    std::cout << "There once was a man called " << name << " and his age is 21 and height is " << height << std::endl;

    std::cout << "Enter your department : ";
    std::string departmentName;
    std::getline(std::cin, departmentName);
    std::cout << "Your department is: " << departmentName << std::endl;
    
    std::cout <<"Enter your CGPA : ";
    float cgpa;
    std::cin >> cgpa;
    std::cout << "Your CGPA is: " << cgpa << std::endl;

    // Example using if statements
    std::cout << "Enter an integer to check if it is positive, negative or zero: ";
    int number;
    std::cin >> number;
    if (number > 0) {
        std::cout << "The number " << number << " is positive." << std::endl;
    } else if (number < 0) {
        std::cout << "The number " << number << " is negative." << std::endl;
    } else {
        std::cout << "The number is zero." << std::endl;
    }

    // Example using switch statement
    std::cout << "Enter a number between 1 and 5: ";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "You chose option 1." << std::endl;
            break;
        case 2:
            std::cout << "You chose option 2." << std::endl;
            break;
        case 3:
            std::cout << "You chose option 3." << std::endl;
            break;
        case 4:
            std::cout << "You chose option 4." << std::endl;
            break;
        case 5:
            std::cout << "You chose option 5." << std::endl;
            break;
        default:
            std::cout << "Invalid choice; please enter a number from 1 to 5." << std::endl;
            break;
    }

    // for loop - Calculate GPA for 4 semesters
    float totalMarks = 0;
    for (int semester = 1; semester <= 4; semester++) {
        float marks;
        std::cout << "Enter SGPA for semester " << semester << ": ";
        std::cin >> marks;
        totalMarks += marks;
    }
    std::cout << "Average SGPA across 4 semesters: " << totalMarks / 4 << std::endl;

    // while loop - Attendance tracker
    std::cout << "Enter total classes happened : ";
    int totalClasses;
    std::cin >> totalClasses;
    int classesAttended = 0;
    int day = 1;
    while (day <= totalClasses) {
        std::cout << "Did you attend class " << day << "? (1 for yes, 0 for no): ";
        int attended;
        std::cin >> attended;
        if (attended == 1) {
            classesAttended++;
        }
        day++;
    }
    float attendancePercentage = (static_cast<float>(classesAttended) / totalClasses) * 100;
    std::cout << "Your attendance: " << attendancePercentage << "%" << std::endl;

    // Array traversal 
    int arr[3][3]={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::cout << "2D Array elements: " << std::endl;
    for (int i = 0; i < 3; i++){
        for (int j =0; j<3; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // pointers eg
    int a = 10;
    int *ptr= &a;
    std::cout << "address of a: " << &a << "value of a: " << *ptr << std::endl;

    return 0;
}