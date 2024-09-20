#include <iostream>
#include <cstring>

using namespace std;

/*
  Palindrome
  By Ethan Chesire 

 */

int main()
{
  //variables and geting the inital word
  int count = 0;
  int length = -1;
  cout << "Write a word" <<endl;
  char input[80];
  char input2[20];
  char inex[20];
  cin.clear();
  cin.get(input, 80);

  cout << endl;

  //checking for bad characters
  for (int i = 0; input[i] != '\0' ; i++){
    if (input [i] >= 65 && input [i] <= 90) {
      length++;
      if (input[i] != '\0') {
	inex[length] = input[i] + 32;
      }
    }
    else if (input [i] >= 97 && input [i] <= 122) {
      length++;
      if (input[i] != '\0') {
	inex[length] = input[i];
      }
    }
    else if (input [i] >= 48 && input [i] <= 57) {
      length++;
      if (input[i] != '\0') {
        inex[length] = input[i];
      }
    }
  }

  //ending off and printing out filtered word
  length++;
  inex[length] = '\0';
  cout << "Filtered word - " << inex << endl;
  
  //array and moving characters across cstrings
  for (int i = 0; i < length; i++) {
    if (inex [i] != '\0') {
      input2[length - i - 1] = inex[i];
      count++;
      //cout << count << inex[i] << input2[length - i] << endl;
    }
  }

  //adds a null charcter at the end of the cstring
  input2[count] = '\0';
  cout << endl;
  
  //comparing to test if it is or not a palindrome
  if (strcmp(inex, input2) == 0) {
    cout << "Palindrome!" << endl;
  }
  else {
    cout << "It is not a palindrome" << endl;
  }

  //final phrases
  cout << "Your input - " << input << endl;
  cout << "Flipped char - " << input2 << endl;
  cout << "Length of word : " << length << endl;
  return 0;
}
