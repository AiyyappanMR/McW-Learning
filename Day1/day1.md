# Day 1 - 19/02/26

Hey, starting my C++ journey today. Went through some basics and dipped into OOP. The codes were fun to mess with – one for basic stuff like variables and loops, another for a simple Student class. Here's what I picked up, with some syntax examples. I'll expand on my raw notes a bit, make 'em clearer, and toss in a few extra thoughts that popped up while thinking about this. Keeping it chill, like my brain dump.

## Basics from Day1_basic.cpp

Started with the fundamentals. C++ feels like a step up from simpler langs, but it's straightforward once you get the hang of includes and namespaces.

### #include Directive
- What is it? It's a preprocessor thing that pulls in external libraries (headers) so you can use stuff like `std::cout` or string functions without reinventing the wheel. Like importing modules in other langs.
- Examples: `#include <iostream>` for input/output, `#include <string>` for strings, or `#include <cmath>` for math funcs like sqrt or pow. Without it, the compiler freaks out 'cause it doesn't know what those are.
- My thought: Kinda like grabbing tools from a toolbox before starting a project. If you forget, you're stuck hammering with your fist.

### std:: vs using namespace std;
- `std::` is like a prefix for standard library stuff (e.g., `std::cout`, `std::string`). It's the safe way to avoid name clashes if you have your own vars named cout or whatever.
- `using namespace std;` lets you drop the `std::` everywhere, makes code cleaner but risky in big projects 'cause it dumps all std names into your global space.
- What happens without both? Compiler errors – it won't recognize cout, string, etc., as they're in the std namespace. You'd have to qualify everything with std:: or include the using directive.
- Extra thought: I like using `std::` for small scripts to be explicit, but `using namespace std;` saves typing in quick practices. Reminds me of Python's `from module import *` – handy but can bite you later.

### Input: getline vs cin
- `cin` is quick for single words or numbers, but it stops at spaces (e.g., `cin >> name;` grabs "Aiyyappan" but skips "MR" if input is "Aiyyappan MR").
- Use `getline` when you want the whole line, including spaces – perfect for sentences, full names, or department names.
- Syntax example:
  ```cpp
  std::string departmentName;
  std::cout << "Enter your department: ";
  std::getline(std::cin, departmentName);  // Reads "Computer Science Engineering" fully
  std::cout << "Your dept: " << departmentName << std::endl;
  ```
- vs cin:
  ```cpp
  std::string word;
  std::cin >> word;  // Only grabs up to first space
  ```
- My expansion: Noticed in the code how after cin for numbers, getline might act weird 'cause of leftover newlines. Gotta watch for that – maybe use `std::cin.ignore()` to clear the buffer. Similar to how in other langs, scanners can get tripped up on inputs.

### Variables and Data Types
- Played with string, int, bool, float, char. Strings have cool methods like `.length()`, `.find("char")`, `.substr(start, length)`.
- Example from code:
  ```cpp
  std::string name = "AiyyappanRM";
  char temp = name[9];  // 'R'
  name[9] = name[10];   // Swap chars
  name[10] = temp;
  std::cout << name.length() << std::endl;  // 11
  std::cout << name.find("a") << std::endl; // 1 (first 'a')
  std::cout << name.substr(1,4) << std::endl; // "iyya"
  ```
- Thought: Strings are mutable like in Python, but indexing is zero-based. Char swaps feel low-level, fun for puzzles.

### Control Structures
- If-else: Simple checks, like positive/negative/zero.
  ```cpp
  if (number > 0) { ... } else if (number < 0) { ... } else { ... }
  ```
- Switch: For multiple choices, better than chained ifs.
  ```cpp
  switch (choice) {
      case 1: std::cout << "Option 1"; break;
      default: std::cout << "Invalid"; break;
  }
  ```
- Loops:
  - For: Good for known iterations, like averaging SGPAs.
    ```cpp
    for (int i = 1; i <= 4; i++) { ... }
    ```
  - While: For unknown counts, like attendance tracker.
    ```cpp
    while (day <= totalClasses) { ... day++; }
    ```
- Extra: Do-while could be useful for menus (run at least once). Didn't code it yet, but syntax: `do { ... } while (condition);`

### Arrays
- 2D array traversal – like a matrix.
  ```cpp
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          std::cout << arr[i][j] << " ";
      }
      std::cout << std::endl;
  }
  ```
- Thought: Fixed size sucks compared to vectors, but good for grids like tic-tac-toe. Might try dynamic arrays later.

### Pointers
- `&` gets memory address, `*` dereferences to get/set value.
  ```cpp
  int a = 10;
  int *ptr = &a;  // ptr holds address of a
  std::cout << "Address: " << &a << ", Value: " << *ptr << std::endl;
  *ptr = 20;  // Changes a to 20
  ```
- My take: Feels hacky but powerful for efficiency. Like refs in other langs, but manual. Decode? Yeah, * "decodes" the address to the value. Avoid null pointers or you'll crash!

## OOP from Day1_oop.cpp

Jumped into classes. Feels like blueprints for objects.

### Classes and Objects
- Class: Defines structure with data (members) and funcs (methods).
- Public: Accessible anywhere.
- Private: Only inside class, use setters/getters.
- Constructor: Initializes object.
  ```cpp
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
          setCgpa(c);  // Uses setter for validation
      }
      void setCgpa(double c) {
          if (c >= 0.0 && c <= 10.0) cgpa = c;
          else { std::cout << "Invalid CGPA"; cgpa = 0.0; }
      }
      void displayInfo() { ... }  // Prints details
  };
  ```
- Creating object: `Student s1("AiyyappanMR", 21, "Computer Science", 11.0);` (Note: 11.0 triggers invalid msg).
- Thought: Encapsulation is cool – hide cgpa, validate it. Like protecting data from dumb inputs.

### Function Declaration vs Definition
- In C++, you can declare a func prototype first (e.g., `void displayInfo();`) and define it later. Helps with organization or forward refs.
- In class: Methods can be declared inside class, defined outside with `ClassName::methodName() { ... }`.
- My addition: Didn't do it in code, but useful for big files. Kinda like headers in JS modules.

## Overall Thoughts
- Main func is entry point, always returns int (0 for success).
- Compiled and ran both codes – OOP one showed invalid CGPA for 11.0, which is good validation.
- Next? Maybe inheritance or vectors. This feels like building blocks for bigger apps, like a student database.
- Pro tip to self: Always endl or \n for newlines, and include <string> for strings.

That's Day 1 wrapped. Felt productive! 🚀