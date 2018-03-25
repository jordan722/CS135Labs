/*
Author: Jordan Yaqoob
Course: CSCI 136
Instructor: Zamansky
Assignment: Lab 7
*/

#include <iostream>
using namespace std;
#include "ascii.h"

int main(){
  string s = "Cat :3 Dog";
  testascii(s);
  cout << shiftChar('b', 2) << endl;
  cout << encryptCaesar("Hello, World!", 10) << endl;
  cout << encryptVigenere("Hello, World!", "cake") << endl;
  cout << decryptCaesar("Rovvy, Gybvn!", 10) << endl;
  cout << decryptVigenere("Jevpq, Wyvnd!", "cake") << endl;
}
