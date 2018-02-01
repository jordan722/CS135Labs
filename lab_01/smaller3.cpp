/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab 01

This program compares three numbers and returns the smallest of the three.
*/

#include <iostream>
using namespace std;

int main() {
    cout << "Enter the first number: ";
    int smallest = 0;
    cin >> smallest;
    int second = 0;
    cout << "Enter the second number: ";
    cin >> second;
    if (second < smallest){
      smallest = second;
    }
    cout << "Enter the third number: ";
    int third = 0;
    cin >> third;
    if (third < smallest){
      smallest = third;
    }
    cout << "\n";
    cout << "The smaller of the three is " << smallest << endl;
}
