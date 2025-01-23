#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
public:
  Student();
  char name[31];
  float gpa = 4.00;
  float getGPA();
  char* getName();
};

#endif
