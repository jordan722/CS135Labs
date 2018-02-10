/*
Author: Jordan Yaqoob
Course: CSCI-136
Instructor: Zamansky
Assignment: Lab_02 Task C

This program will start with a premade array made
of all 1s. The program will take in an input that
contains the index of an element in an array and
replace the element with the value provided by
the user.
*/


#include <iostream>

using namespace std;

int main(){
  int myData[10];
  for(int i = 0; i < 10; i++){
    myData[i] = 1;
  }
  cout << "\n";
  int index;
  int value;
  do{
    for(int i = 0; i < 10; i++){
      cout << myData[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    cout << "Input index: ";
    cin >> index;
    cout << "Input value: ";
    cin >> value;
    cout << "\n";
    if(index < 10){
      myData[index] = value;
    }

  }while(index < 10);
  cout << "Index out of range. Exit." << endl;
}
