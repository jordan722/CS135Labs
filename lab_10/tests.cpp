#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.h"
#include "doctest.h"



TEST_CASE("MinutesSinceMidnight"){
  cout << "MinutesSinceMidnight" << endl;
  CHECK(minutesSinceMidnight({10,30})==630);
  CHECK(minutesSinceMidnight({0,30})==30);
}
