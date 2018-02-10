/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_02 Task D

This program uses a 60 element array to calculate
Fibonacci numbers. After calculating these 60
terms, the program will print them all out.
*/


#include <iostream>

using namespace std;

int main(){
  int fib[60];
  fib[0] = 0;
  cout << fib[0] << endl;
  fib [1] = 1;
  cout << fib[1] << endl;
  for(int i = 2; i < 60; i++){
    fib[i] = fib[i-1] + fib[i-2];
    cout << fib[i] << endl;
  }

  /*
  The numbers begin to become negative as the sequence
  approaches 2 billion because of number overflow. There
  is a certain point after 2 billion where the numbers
  wrap around back to negative numbers after becoming
  too large.
  */
}
