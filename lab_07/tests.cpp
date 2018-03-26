#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "ascii.h"
#include "doctest.h"



TEST_CASE("ShiftChar"){
  cout << "Testing shiftChar" << endl;
  CHECK(shiftChar('c', 2)=='e');
  CHECK(shiftChar('X', 27)=='Y');
  CHECK(shiftChar('g', 10)=='q');
  CHECK(shiftChar('e', 24)=='c');
}

TEST_CASE("encryptCaesar"){
  cout << "Testing encryptCaesar('Hello, World!', 10)" << endl;
  CHECK(encryptCaesar("Hello, World!", 10)=="Rovvy, Gybvn!");
}

TEST_CASE("Testing decryptCaesar"){
  cout << "Testing decryptCaesar('Rovvy, Gybvn!', 10)" << endl;
  CHECK(decryptCaesar("Rovvy, Gybvn!", 10)=="Hello, World!");
}

TEST_CASE("Testing encryptVigenere"){
  cout << "Testing encryptVigenere('Hello, World!', 'cake')" << endl;
  CHECK(encryptVigenere("Hello, World!", "cake")=="Jevpq, Wyvnd!");
}

TEST_CASE("Testing decryptVigenere"){
  cout << "decryptVigenere('Jevpq, Wyvnd!', 'cake')" << endl;
  CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake")=="Hello, World!");

}
