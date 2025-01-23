#include "student.h"
#include <iostream>

using namespace std;

Student::Student(){
  cout << "enter first name..." << endl;
  cin.getline(fname, 30);
  cout << "enter last name..." << endl;
  cin.getline(lname, 30);
  cout << "enter your student ID..." << endl;
  cin >> id;
  cin.ignore();
  cout << "enter gpa..." << endl;
  cin >> gpa;
  cin.ignore();
  
}

float Student::getGPA(){
  return gpa;
}

float Student::getID(){
  return id;
}

char* Student::getlName(){
  return lname;
}

char* Student::getfName(){
  return fname;
}
