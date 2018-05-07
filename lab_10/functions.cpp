#include <iostream>
#include "functions.h"

using namespace std;

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

string returnTime(Time time) {
    string ans = to_string(time.h);
    ans +=  ":";
    ans += to_string(time.m);
    return ans;
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
  Time start = ts.startTime;
  Movie m = ts.movie;
  string g;
  switch (m.genre) {
      case ACTION   : g = "ACTION"; break;
      case COMEDY   : g = "COMEDY"; break;
      case DRAMA    : g = "DRAMA";  break;
      case ROMANCE  : g = "ROMANCE"; break;
      case THRILLER : g = "THRILLER"; break;
  }
  return m.title + " " + g + " (" + to_string(m.duration) + ") " + "[starts at " + returnTime(ts.startTime) + ", ends by " + returnTime(addMinutes(start, m.duration)) + "]";
}


TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
  TimeSlot ans = ts;
  ans.movie = nextMovie;
  ans.startTime = addMinutes(ts.startTime, ts.movie.duration);
  return ans;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
  TimeSlot min = ts2;
  TimeSlot max = ts1;
  if (minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)){
    TimeSlot min = ts1;
    TimeSlot max = ts2;
  }
  int s_min = minutesSinceMidnight(min.startTime);
  int s_max = minutesSinceMidnight(max.startTime);
  int e_min = minutesSinceMidnight(addMinutes(min.startTime, min.movie.duration));
  int e_max = minutesSinceMidnight(addMinutes(max.startTime, max.movie.duration));
  return ((s_min < e_max) && (e_min > s_max));
}
