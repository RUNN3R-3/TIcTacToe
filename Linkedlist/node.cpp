#include "node.h"
#include "student.h"
#include <iostream>

using namespace std;


Node::Node(Student* student){
  this->student = student;
  next = nullptr;

}

Node::~Node(){
  delete student;
}

void Node::setNext(Node* n){
  next = n;
}

Node* Node::getNext(){
  return next;
}

Student* Node::getStudent(){
  return student;
}
