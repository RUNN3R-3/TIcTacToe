#include "student.h"
#include <iostream>

using namespace std;

Student::Student(){
  cout << "enter name..." << endl;
  cin.getline(name,30);
  cout << "enter gpa..." << endl;
  cin >> gpa;
  cin.ignore();
  
}

float Student::getGPA(){
  return gpa;
}

char* Student::getName(){
  return name;
}
