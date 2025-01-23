#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  Node(Student*);
  ~Node();
  void setNext(Node* newnext);
  Node* getNext();
  char name[20];
  int gpa;
  Student* student;
  Node* next;
  Student* getStudent();
};

#endif
