#include <iostream>
#include <cstring>
#include <array>
#include <fstream>

using namespace std;

//makes sure the heap is in format
void heapify( int arr[], int n, int i){

  //use the pic in phone to edit this 
  int parent = i / 2;

  if (arr[i] > arr[parent] && parent != 0) {
    swap(arr[i], arr[parent]);
    cout << arr[i] << " and " << arr[parent] << endl;
    heapify(arr, n, parent);
  }
  
}

void add(int arr[], int& n, int num){

  n++;
  arr[n - 1] = num;

  if (n > 2){
    heapify(arr, n, n - 1);
  }
}


void remove(int arr[], int& n){

  //sets first thing as last
  arr[1] = arr[n-1];
  
  for (int i = 1; i < n; i++) {
    heapify(arr, i, i-1);
  }
  
  n--;
  heapify(arr, n, n-1);
  
}

// run recursively through the arry deleteing everything as it goes
void removeAll(int arr[], int& n) {

  for (int i = 1; i < n; i++) {
    arr[i] = 0;
  }
  n = 1;
  
}

//the print function
void print(int arr[], int pos, int depth, int size){

  if (pos * 2 + 1 < size){
    print(arr, pos * 2 + 1, depth + 1, size);
  }

  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  
  cout << arr[pos] << endl;

  if (pos * 2 < size) {
    print(arr, pos * 2, depth + 1, size);
  }
  
}

//where the magic happens
int main(){

  //variables
  int input = 0;
  bool working = true;
  int arr[100];
  int n = 1;
  int num = 0;
  char answer[1];
  int amount = 0;


  while (working == true) {
    cout << endl << "Welcome to heap, choose an option" << endl;
    cout << "1 - ADD   2 - REMOVE ROOT  3 - REMOVE ALL   4 - PRINT   5 - QUIT   6 - GENERATOR" << endl;
    cin >> input;
    cout << "Working" << "." << "." << "." << "." << endl;

    //Add function
    if (input == 1){
      cout << "What number would you like to add?" << endl;
      cin >> num;
      add(arr, n, num);
    }
    //root remover
    else if (input == 2){
      remove(arr, n);
    }
    //deletes everyting
    else if (input == 3){
      cout << endl << "Do you really want to remove everything?" << endl;
      cout << "type y or n --- ";
      cin >> answer;
      if (strcmp(answer, "y") == 0) {
	removeAll(arr, n);
      }
    }
    //prints
    else if (input == 4){
      print(arr, 1, 0, n);
      cout << endl;
    }
    //end program
    else if (input == 5){
      cout << "Goodbye XD" << endl;
      working = false;
    }
    //Takes numbers from num.txt
    else if (input == 6){
      cout << "How many numbers do you want to enter?" << " -( ";
      cin >> amount;
      ifstream fin ("num.txt");
      for ( int c = 0; c < amount; c++) {
	int t;
	fin >> t;
	add(arr, n, t);
      }
      fin.close();
    }
  }
  
  return 0;
}
