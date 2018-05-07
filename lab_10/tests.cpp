#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.h"
#include "doctest.h"



TEST_CASE("MinutesSinceMidnight"){
  cout << "Testing MinutesSinceMidnight" << endl;
  CHECK(minutesSinceMidnight({10,30})==630);
  CHECK(minutesSinceMidnight({0,30})==30);
}


TEST_CASE("minutesUntil"){
  cout << "Testing MinutesUntil" << endl;
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


TEST_CASE("addMinutes"){
  cout << "Testing addMinutes" << endl;
  Time ans = addMinutes({8, 10}, 75);
  CHECK(ans.h == 9);
  CHECK(ans.m == 25);
  ans = addMinutes({10, 10}, 60);
  CHECK(ans.h == 11);
  CHECK(ans.m == 10);
  ans = addMinutes({10, 10}, 50);
  CHECK(ans.h == 11);
  CHECK(ans.m == 0);
  ans = addMinutes({2, 10}, 20);
  CHECK(ans.h == 2);
  CHECK(ans.m == 30);
  ans = addMinutes({3, 50}, 20);
  CHECK(ans.h == 4);
  CHECK(ans.m == 10);

}


TEST_CASE("TimeSlotString"){
  cout << "Testing TimeSlotString" << endl;
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  CHECK(TimeSlotString(morning) == "Back to the Future COMEDY (116) [starts at 9:15, ends by 11:11]");
  CHECK(TimeSlotString(daytime) == "Black Panther ACTION (134) [starts at 12:15, ends by 14:29]");
  CHECK(TimeSlotString(evening) == "Black Panther ACTION (134) [starts at 16:45, ends by 18:59]");
}


TEST_CASE("ScheduleAfter"){
  cout << "Testing Schedule After" << endl;
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  CHECK(TimeSlotString(scheduleAfter(evening, movie2)) == "Black Panther ACTION (134) [starts at 18:59, ends by 21:13]");
  CHECK(TimeSlotString(scheduleAfter(morning, movie2)) == "Black Panther ACTION (134) [starts at 11:11, ends by 13:25]");
}

TEST_CASE("Overlap"){
  cout << "Testing Overlap" << endl;
  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};
  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};
  TimeSlot test = {movie2, {11,10}};
  CHECK(timeOverlap(morning, test) == 1);
  CHECK(timeOverlap(daytime, test) == 1);
  CHECK(timeOverlap(evening, test) == 0);
}
