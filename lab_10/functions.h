#pragma once
using namespace std;

struct Time {
    int h;
    int m;
};
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

struct Movie {
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

struct TimeSlot {
    Movie movie;     // what movie
    Time startTime;  // when it starts
};


void printTime(Time time);
string returnTime(Time time);
void printMovie(Movie mv);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);
string TimeSlotString(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);
