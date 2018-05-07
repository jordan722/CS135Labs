#include <iostream>
#include "functions.h"

using namespace std;

int main(){
  Time now;
  now.h = 9;
  now.m = 58;
  Time later;
  later.h = 9;
  later.m = 59;
  cout << minutesSinceMidnight({10,30}) << endl;
  cout << minutesUntil(now, later) << endl;
  cout << minutesUntil({10,30}, {13,40}) << endl;
  Time time1 = addMinutes({8, 10}, 75);
  printTime(time1);
  cout << "" << endl;;



  Movie movie1 = {"Back to the Future", COMEDY, 116};
  Movie movie2 = {"Black Panther", ACTION, 134};

  TimeSlot morning = {movie1, {9, 15}};
  TimeSlot daytime = {movie2, {12, 15}};
  TimeSlot evening = {movie2, {16, 45}};

  cout << TimeSlotString(morning) << endl;

  TimeSlot next = scheduleAfter(morning, movie2);
  cout << TimeSlotString(next) << endl;

  cout << timeOverlap(morning, daytime) << endl;
}
