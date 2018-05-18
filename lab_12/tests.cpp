#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "def.h"
#include "doctest.h"

using namespace std;


TEST_CASE("sumRange"){
  cout << "Testing sumRange" << endl;
  CHECK(sumRange(3,5) == 12);
  CHECK(sumRange(1,4) == 10);
  CHECK(sumRange(-2,10) == 52);
}

TEST_CASE("sumArray"){
  cout << "Testing sumArray" << endl;
  int size = 10;
  int *arr = new int[size]; // allocate array dynamically
  arr[0] = 12;
  arr[1] = 17;
  arr[2] = -5;
  arr[3] = 3;
  arr[4] = 7;
  arr[5] = -15;
  arr[6] = 27;
  arr[7] = 5;
  arr[8] = 13;
  arr[9] = -21;
  CHECK(sumArray(arr, size) == 43);
  CHECK(sumArray(arr,5) == 34);
  CHECK(sumArray(arr, 3) == 24);
}


TEST_CASE("isAlphanumeric"){
  cout << "Testing isAlphanumeric" << endl;
  CHECK(isAlphanumeric("ABCD") == true);
  CHECK(isAlphanumeric("AB234jfsdfCD") == true);
  CHECK(isAlphanumeric("sdvjfb2394423ndsjkf23") == true);
  CHECK(isAlphanumeric("A sdk 23 4") == false);
  CHECK(isAlphanumeric("sdf-dsf--dfs -df") == false);
}

TEST_CASE("nestedParens"){
  cout << "Testing nestedParens" << endl;
  CHECK(nestedParens("((()))") == true);
  CHECK(nestedParens("") == true);
  CHECK(nestedParens("(((") == false);
  CHECK(nestedParens("a(b)c") == false);
}

TEST_CASE("divisible"){
  cout << "Testing divisible" << endl;
  int prices [] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
  CHECK(divisible(prices, 9) == true);
  CHECK(divisible(prices, 2) == false);
}
