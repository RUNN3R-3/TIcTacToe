#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student{
public:
  Student();
  char fname[31];
  char lname[31];
  float id;
  float gpa;
  float getGPA();
  float getID();
  char* getlName();
  char* getfName();
};

#endif
