#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.h"
#include "doctest.h"



TEST_CASE("MinutesSinceMidnight"){
  cout << "MinutesSinceMidnight" << endl;
  CHECK(minutesSinceMidnight({10,30})==630);
  CHECK(minutesSinceMidnight({0,30})==30);
}


TEST_CASE("minutesUntil"){
  cout << "MinutesUntil" << endl;
  Time now;
  now.h = 9;
  now.m = 58;
  Time later;
  later.h = 9;
  later.m = 59;
  CHECK(minutesUntil(now,later)==1);
  now.h = 8;
  now.m = 58;
  later.h = 9;
  later.m = 59;
  CHECK(minutesUntil(now,later)==61);
  now.h = 9;
  now.m = 58;
  later.h = 10;
  later.m = 32;
  CHECK(minutesUntil(now,later)==34);
}
