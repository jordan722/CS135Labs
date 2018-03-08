#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "numbers.h"
#include "doctest.h"



TEST_CASE("Testing IsDivisble"){
  CHECK(isDivisible(100,25)==true);
  CHECK(isDivisible(35,17)==false);
}

TEST_CASE("Testing isPrime"){
  CHECK(isPrime(2)==true);
  CHECK(isPrime(3)==true);
  CHECK(isPrime(35)==false);
  CHECK(isPrime(17)==true);
}

TEST_CASE("Testing nextPrime"){
  CHECK(nextPrime(14)==17);
  CHECK(nextPrime(17)==19);
}

TEST_CASE("Testing countPrimes"){
  CHECK(countPrimes(2,17)==7);
  CHECK(countPrimes(2,3)==2);
  CHECK(countPrimes(5,19)==6);
}

TEST_CASE("Testing isTwinPrime"){
  CHECK(isTwinPrime(29)==true);
  CHECK(isTwinPrime(23)==false);
}

TEST_CASE("Testing nextTwinPrime"){
  CHECK(nextTwinPrime(17)==19);
  CHECK(nextTwinPrime(3)==5);
}

TEST_CASE("Testing largestTwinPrime"){
  CHECK(largestTwinPrime(5,18)==17);
  CHECK(largestTwinPrime(1,31)==31);
  CHECK(largestTwinPrime(14,16)==-1);
}
