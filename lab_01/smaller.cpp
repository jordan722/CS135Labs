/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab 01

This program compares two numbers and returns the smallest of the two.
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Enter the first number: ";
    int first = 0;
    cin >> first;
    int second = 0;
    cout << "Enter the second number: ";
    cin >> second;
    cout << "\n";
    int smaller = 0;
    if (first < second){
      smaller = first;
    }
    else {
      smaller = second;
    }
    cout << "The smaller of the two is " << smaller << endl;
}
