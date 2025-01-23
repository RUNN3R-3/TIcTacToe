#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;


void print(Node* n) {
  cout << n->getStudent()->getName() << endl << n->getStudent()->getGPA() << endl;
  if (n->getNext() != NULL) {
    print(n->getNext());
  }
}

void add(Node* head, Node* newNode){
  if (head->getNext() == nullptr){
    head->setNext(newNode);
    return;
  }
  else {
    add(head->getNext(), newNode);
    return;
  }
}


int main(){

  Node* head = NULL;
  int choice = 0;
  bool done = false;

  while(done == false) {
    cout << "What do you want to do?" << endl << "Add - 1,  Print - 2, Quit - 3" << endl;
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
      if (head == nullptr){
	head = new Node(new Student());
      }
      else {
	add(head, new Node(new Student()));
      }	  
    }
    else if (choice == 2) {
      print(head);
    }
    else if (choice == 3) {
      done = true;
    }
  }
  
  return 0;
}
