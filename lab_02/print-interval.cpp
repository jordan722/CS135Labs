/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_02 Task B

This program will take an input from the user.
The user puts in an upper and lower limit. The
program then prints out all the numbers between
the upper and lower limit.
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
