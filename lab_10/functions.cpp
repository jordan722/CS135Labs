#include <iostream>
#include "labstructs.h"

using namespace std;

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

int minutesSinceMidnight(Time time){
  return time.h*60 + time.m;
}

int minutesUntil(Time earlier, Time later){
  return minutesSinceMidnight(later)-minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min){
  Time time1 = time0;
  while(min > 60){
    time1.h += 1;
    min -= 60;
  }
  time1.m += min;
  if(time1.m >= 60){
    time1.h += 1;
    time1.m -= 60;
  }
  return time1;
}

string TimeSlotString(TimeSlot ts){
  Movie movie = ts.movie;
  Time start = ts.startTime;
  string ans = "";
  ans += printMovie(movie);
}

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
}
