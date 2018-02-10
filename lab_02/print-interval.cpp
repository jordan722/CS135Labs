/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_02 Task A

This program will take an input from the user.
if the input is between 0 and 100 exclusive, the
program will return the square of the input. If
the input is not between 0 and 100, the program
will request the user to re-enter an input until
a valid input is inputted
*/


#include <iostream>

using namespace std;

int main(){
  cout << "Please enter L: ";
  int low;
  cin >> low;
  cout << "Please enter U: ";
  int up;
  cin >> up;
  cout << "\n";
  for(int i = low; i < up; i++){
    cout << i << " ";
  }
  cout << endl;
}
