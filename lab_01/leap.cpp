/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab 01

This program takes in a year and returns whether
it is a leap year or a common year according to
the modern Gregorian calendar.
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Enter year: ";
    int year = 0;
    cin >> year;
    cout << "\n";
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
    cout << ans << endl;
}
