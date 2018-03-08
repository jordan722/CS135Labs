/*
Author: Jordan Yaqoob
Course: CSCI 136
Instructor: Zamansky
Assignment: Lab 5
*/

#include <iostream>
using namespace std;

bool isDivisible(int n, int d){
  return n%d == 0;
}

bool isPrime(int n){
  for(int i = 2; i < n; i++){
    if(isDivisible(n, i)){
      return false;
    }
  }
  return true;
}

int nextPrime(int n){
  int i = n+1;
  while(!isPrime(i)){
    i++;
  }
  return i;
}

int countPrimes(int a, int b){
  int primes = 0;
  for(int i = a; i <= b; i++){
    if(isPrime(i)){
      primes++;
    }
  }
  return primes;
}

bool isTwinPrime(int n){
  if(!isPrime(n)){
    return false;
  }
  return isPrime(n+2) || isPrime(n-2);
}

int nextTwinPrime(int n){
  int i = nextPrime(n);
  while(!isTwinPrime(i)){
    i = nextPrime(i);
  }
  return i;
}

int largestTwinPrime(int a, int b){
  int ans = -1;
  for(int i = a; i <= b; i++){
    if(isTwinPrime(i)){
      ans = i;
    }
  }
  return ans;
}
