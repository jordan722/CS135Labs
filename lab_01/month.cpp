/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab 01

This program asks the user to input the year
and the month and prints the number of days
in that month (taking into account leap years)
*/

#include <iostream>
using namespace std;

string isLeap(int year) {
    string ans = "";
    if (year % 4 != 0){
      ans = "Common year";
    }
    else if (year % 100 != 0){
      ans = "Leap year";
    }
    else if (year % 400 != 0){
      ans = "Common year";
    }
    else {
      ans = "Leap year";
    }
    return ans;
}

int main(){
  cout << "Enter year: ";
  int year = 0;
  cin >> year;
  cout << "Enter month: ";
  int month = 0;
  cin >> month;
  cout << "\n";
  if (month == 2){
    if (isLeap(year) == "Leap year"){
      cout << "29 days" << endl;
    }
    else{
      cout << "28 days" << endl;
    }
  }
  else{
    if(month > 7){
      month = month % 7;
    }
    if(month % 2 == 1){
      cout << "31 days" << endl;
    }
    else{
      cout << "30 days" << endl;
    }
  }
}
