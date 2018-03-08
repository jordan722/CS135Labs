/*
Author: Jordan Yaqoob
Course: CSCI 136
Instructor: Zamansky
Assignment: Lab 3 - Pre-Lab
*/

#include <iostream>
using namespace std;
#include "numbers.h"

int main(){
  cout << isDivisible(100,25) << endl;
  cout << isDivisible(35,17) << endl;
  cout << "\n";

  cout << isPrime(2) << endl;
  cout << isPrime(3) << endl;
  cout << isPrime(35) << endl;
  cout << isPrime(17) << endl;
  cout << "\n";

  cout << nextPrime(14) << endl;
  cout << nextPrime(17) << endl;
  cout << "\n";

  cout << countPrimes(2,17) << endl;
  cout << countPrimes(2,3) << endl;
  cout << countPrimes(5,19) << endl;
  cout << "\n";

  cout << isTwinPrime(29) << endl;
  cout << isTwinPrime(23) << endl;
  cout << "\n";

  cout << nextTwinPrime(17) << endl;
  cout << nextTwinPrime(3) << endl;
  cout << "\n";

  cout << largestTwinPrime(5,18) << endl;
  cout << largestTwinPrime(1,31) << endl;
  cout << largestTwinPrime(14,16) << endl;
  cout << "\n";

}
