CXX = g++
TARGET = app
OBJFILES = main.o Student.o Courses.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(OBJFILES) -o $(TARGET)

main.o: main.cpp Student.h Courses.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Student.o: Student.cpp Student.h Courses.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

Courses.o: Courses.cpp Courses.h
	$(CXX) $(CXXFLAGS) -c Courses.cpp

clean:
	del /Q $(OBJFILES) $(TARGET)