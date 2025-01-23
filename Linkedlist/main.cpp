#include <iostream>
#include "node.h"
#include "student.h"
#include <iomanip>

using namespace std;


void print(Node* n) {
  cout << n->getStudent()->getfName() << " " << n->getStudent()->getlName() << ", ";
  cout << fixed;
  cout << n->getStudent()->getID() << ", " << setprecision(2) << n->getStudent()->getGPA() << endl;
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
    if (newNode->getStudent()->getID() > head->getNext()->getStudent()->getID()){
      add(head->getNext(), newNode);
    }
    else {
      newNode->setNext(head->getNext());
      head->setNext(newNode);
    }
    return;
  }
}

void deleteN(Node* head, int dinput){
  if (dinput == head->getNext()->getStudent()->getID()){
    head->setNext(head->getNext()->getNext());
  }
  else {
    deleteN(head->getNext(), dinput);
  }
}

float average(Node* head, int* aCount) {
  if (head != nullptr){
    head->getStudent()->getGPA();
    (*aCount)++;
    return head->getStudent()->getGPA() + average(head->getNext(), aCount);
  }
  return 0;
}

int main(){

  Node* head = NULL;
  int choice = 0;
  bool done = false;
  int dinput = 0;
  int count = 0;

  while(done == false) {
    cout << endl << "What do you want to do?" << endl << "Add - 1,  Print - 2, Delete - 3, Average - 4, Quit - 5" << endl;
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
      if (head == nullptr){
	head = new Node(new Student());
      }
      else {
	Node* n = new Node(new Student());
	if (n->getStudent()->getID() < head->getStudent()->getID()) {
	  n->setNext(head);
	  head = n;
	}
	else {
	  add(head, n);
	}
      }	  
    }
    else if (choice == 2) {
      print(head);
    }
    else if (choice == 3) {
      cout << "Who do you want to delete? Enter their ID#..." << endl;
      cin >> dinput;
      if (head != NULL){
	if (dinput == head->getStudent()->getID()) {
	  head = head->getNext();
	}
	else {
	  deleteN(head, dinput);
	}
      }
      else {
	cout << "There is no list to delete from." << endl;
      }
    }
    else if (choice == 4) {
      int* aCount = &count;
      cout << fixed;
      cout << setprecision(3) << average(head, aCount)/(*aCount);
    }
    else if (choice == 5) {
      done = true;
    }
  }
  
  return 0;
}
