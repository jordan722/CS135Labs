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
#include <string>
#include <locale>
using namespace std;

int main(){
  cout << "Please enter an integer: ";
  int inp;
  cin >> inp;
  while(cin.fail() || inp <= 0 || inp >= 100){
    cout << "Please re-enter: ";
    cin.clear();
    cin.ignore(256,'\n');
    cin >> inp;
  }
  cout << "\n";
  cout << "Number squared is " << inp*inp << endl;
}
