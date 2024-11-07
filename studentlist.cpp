#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;
/*
  Student list - by: Ethan Chesire
  11/7/2024
  use one of the four commands to manuver and use this storage of student
  names, id's, and gpa's. You can add more students, delete the ones you
  dont want anymore, print out a list of all the students you have, or
  quit the program when your done. This project uses structs, vectors,
  passing by refrence, pointers, and many other things. ENJOY!!!
 */

//the structure for each student
struct Student {
  char fname[10];
  char lname[10];
  int id = 0;
  float gpa = 0.00;
  cout.percision(3);
  
};

void add(vector<Student*> &list);

int main() {
  //the vector
  vector<Student*> list;

  //variables
  int input;
  char option[10];
  bool done = false;

  //while loop to keep it all running for as long as you want
  while (done == false){
    cout << "Would you like to ADD or DELETE or PRINT or QUIT" << endl;
    cin >> option;
    //ADDing
    if (option[0] == 'A'){
      add(list);
    }
    //printing out all people using a for loop to go through the list
    else if (option[0] == 'P'){
      for (int i = 0; i < list.size(); i++){
	cout << list[i]->fname << " " << list[i]->lname << endl << list[i]->id << endl << list[i]->gpa << endl << "\n";
      }
    }
    //finds a student by there id and deletes all of that student
    else if (option[0] == 'D'){
      cout << "What is the student's id" << endl;
      cin >> input;
      for (int i = 0; i < list.size(); i++){
	if (list[i]->id == input){
	  list.erase( std::next(list.begin(),i));
	  i--;
	}
      }
    }
    //quits the while loop
    else if (option[0] == 'Q')
      done = true;
    else
      cout << "That is not an option";
  }

  return 0;
}

//Passes list by reference and creates a new student with the inputs you give
void add(vector<Student*> &list)  {

  struct Student* sptr = new Student();
  
  cout << "Enter first name -" << endl;
  cin >> sptr->fname;
  cout << "Enter last name -" << endl;
  cin >> sptr->lname;
  cout << "Enter ID # -" << endl;
  cin >> sptr->id;
  cout << "Enter GPA -" << endl;
  cin >> sptr->gpa;

  list.push_back(sptr);

  return;
}
